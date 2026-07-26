"""Keras 3 importer for dense models and a standard Transformer encoder.

Models without ``MultiHeadAttention`` are converted in memory to TensorFlow
Lite and use the common TFLite importer.  A Transformer encoder takes a direct
path so its self-attention remains one high-level ``MultiHeadAttention`` node
instead of becoming a large collection of framework implementation details.
"""

from __future__ import annotations

import math
from pathlib import Path
from typing import Any, Iterable, Sequence

import numpy as np

from .common import (
    DTYPE_LIMITS,
    FrontendError,
    FrontendOptions,
    GraphBuilder,
    fixed_shape,
)
from .tflite_frontend import load_tflite_buffer


def _flatten_tensors(value: Any) -> list[Any]:
    if isinstance(value, dict):
        result: list[Any] = []
        for key in sorted(value):
            result.extend(_flatten_tensors(value[key]))
        return result
    if isinstance(value, (list, tuple)):
        result = []
        for item in value:
            result.extend(_flatten_tensors(item))
        return result
    return [value]


def _single_output(layer: Any) -> Any:
    outputs = _flatten_tensors(layer.output)
    if len(outputs) != 1:
        raise FrontendError(
            f"Keras layer {layer.name!r} has {len(outputs)} outputs; "
            "the direct Transformer path requires one"
        )
    return outputs[0]


def _resolved_shape(
    tensor: Any,
    options: FrontendOptions,
    *,
    name: str,
    index: int = 0,
) -> tuple[int, ...]:
    return fixed_shape(
        tuple(tensor.shape),
        options=options,
        input_name=name,
        input_index=index,
    )


def _normalized_transformer_shape(
    shape: Sequence[int], *, location: str
) -> tuple[int, ...]:
    normalized = tuple(int(item) for item in shape)
    if len(normalized) == 3:
        if normalized[0] != 1:
            raise FrontendError(
                f"{location} has shape {list(normalized)}; the direct "
                "Transformer path currently requires batch size 1"
            )
        return normalized[1], normalized[2]
    if len(normalized) == 2:
        return normalized
    raise FrontendError(
        f"{location} has rank {len(normalized)}; the direct Transformer path "
        "requires [1, tokens, width] or [tokens, width]"
    )


def _activation_name(keras: Any, activation: Any) -> str:
    name = getattr(activation, "__name__", None)
    if isinstance(name, str) and name:
        return name
    serialized = keras.activations.serialize(activation)
    if isinstance(serialized, str):
        return serialized
    if isinstance(serialized, dict):
        class_name = serialized.get("class_name")
        config = serialized.get("config")
        if isinstance(config, str):
            return config
        if isinstance(class_name, str):
            return class_name
    raise FrontendError(f"cannot identify Keras activation {activation!r}")


def _check_fixed_range(
    values: Any,
    options: FrontendOptions,
    *,
    location: str,
) -> None:
    array = np.asarray(values, dtype=np.float64)
    if not np.all(np.isfinite(array)):
        raise FrontendError(f"{location} contains NaN or infinity")
    minimum, maximum = DTYPE_LIMITS[options.dtype]
    encoded = np.rint(array / options.scale)
    if np.any(encoded < minimum) or np.any(encoded > maximum):
        smallest = float(np.min(array))
        largest = float(np.max(array))
        raise FrontendError(
            f"{location} real-value range [{smallest}, {largest}] cannot be "
            f"stored as {options.dtype} with scale {options.scale}"
        )


def _layer_inputs(layer: Any) -> list[Any]:
    try:
        return _flatten_tensors(layer.input)
    except (AttributeError, ValueError) as error:
        raise FrontendError(
            f"Keras layer {layer.name!r} has multiple graph nodes or no "
            "connected input; shared multi-call layers are not supported by "
            "the direct Transformer path"
        ) from error


class _KerasTransformerImporter:
    def __init__(
        self,
        model: Any,
        path: Path,
        options: FrontendOptions,
        keras: Any,
    ) -> None:
        self.model = model
        self.path = path
        self.options = options
        self.keras = keras
        self.builder = GraphBuilder(path.stem, "keras", path, options)
        self.aliases: dict[int, str] = {}
        self.original_input_shapes: list[tuple[int, ...]] = []

    def alias(self, tensor: Any, *, layer_name: str) -> str:
        try:
            return self.aliases[id(tensor)]
        except KeyError as error:
            raise FrontendError(
                f"Keras layer {layer_name!r} consumes a tensor that the "
                "direct Transformer path has not produced"
            ) from error

    def add_inputs(self) -> None:
        for index, tensor in enumerate(_flatten_tensors(self.model.inputs)):
            name = str(getattr(tensor, "name", f"input_{index}"))
            shape = _resolved_shape(
                tensor, self.options, name=name, index=index
            )
            normalized = _normalized_transformer_shape(
                shape, location=f"Keras input {name!r}"
            )
            current = self.builder.add_input(name, shape)
            if shape != normalized:
                current = self.builder.add_operator(
                    f"{name}_remove_unit_batch",
                    "Reshape",
                    [current],
                    [f"{name}_tokens"],
                    attributes={"shape": list(normalized)},
                    output_shapes=[normalized],
                )[0]
            self.aliases[id(tensor)] = current
            self.original_input_shapes.append(shape)

    def add_mha(self, layer: Any) -> None:
        input_tensors = _layer_inputs(layer)
        if len(input_tensors) not in (2, 3):
            raise FrontendError(
                f"MultiHeadAttention layer {layer.name!r} must receive query "
                "and value, with an optional key"
            )
        aliases = [self.alias(tensor, layer_name=layer.name) for tensor in input_tensors]
        if any(item != aliases[0] for item in aliases[1:]):
            raise FrontendError(
                f"MultiHeadAttention layer {layer.name!r} is not self-attention"
            )
        source = aliases[0]
        source_shape = self.builder.shapes[source]
        if len(source_shape) != 2:
            raise FrontendError(
                f"MultiHeadAttention layer {layer.name!r} input must normalize "
                "to [tokens, width]"
            )
        _, width = source_shape
        config = layer.get_config()
        heads = int(config["num_heads"])
        key_dim = int(config["key_dim"])
        value_dim = int(config.get("value_dim") or key_dim)
        if bool(config.get("use_bias", True)):
            raise FrontendError(
                f"MultiHeadAttention layer {layer.name!r} uses projection "
                "biases; the current high-level attention node has no bias "
                "inputs"
            )
        if heads <= 0 or key_dim <= 0 or value_dim <= 0:
            raise FrontendError(
                f"MultiHeadAttention layer {layer.name!r} has invalid head "
                "dimensions"
            )
        if heads * key_dim != width or heads * value_dim != width:
            raise FrontendError(
                f"MultiHeadAttention layer {layer.name!r} requires "
                "num_heads * key_dim == width and "
                "num_heads * value_dim == width"
            )
        attention_axes = config.get("attention_axes")
        if attention_axes not in (None, (1,), [1], 1):
            raise FrontendError(
                f"MultiHeadAttention layer {layer.name!r} uses attention_axes "
                f"{attention_axes!r}; only the token axis is supported"
            )
        try:
            query = np.asarray(layer._query_dense.kernel, dtype=np.float64)
            key = np.asarray(layer._key_dense.kernel, dtype=np.float64)
            value = np.asarray(layer._value_dense.kernel, dtype=np.float64)
            output = np.asarray(layer._output_dense.kernel, dtype=np.float64)
        except (AttributeError, TypeError, ValueError) as error:
            raise FrontendError(
                f"cannot read projection kernels from MultiHeadAttention "
                f"layer {layer.name!r}"
            ) from error
        expected_qkv = (width, heads, key_dim)
        if query.shape != expected_qkv or key.shape != expected_qkv:
            raise FrontendError(
                f"MultiHeadAttention layer {layer.name!r} query/key kernels "
                f"must have shape {list(expected_qkv)}"
            )
        expected_value = (width, heads, value_dim)
        if value.shape != expected_value:
            raise FrontendError(
                f"MultiHeadAttention layer {layer.name!r} value kernel must "
                f"have shape {list(expected_value)}"
            )
        if output.shape != (heads, value_dim, width):
            raise FrontendError(
                f"MultiHeadAttention layer {layer.name!r} output kernel must "
                f"have shape {[heads, value_dim, width]}"
            )
        for suffix, array in (
            ("query kernel", query),
            ("key kernel", key),
            ("value kernel", value),
            ("output kernel", output),
        ):
            _check_fixed_range(
                array,
                self.options,
                location=f"MultiHeadAttention layer {layer.name!r} {suffix}",
            )
        weights = [
            self.builder.add_constant(
                f"{layer.name}_{suffix}", array.reshape(width, width)
            )
            for suffix, array in (
                ("query_kernel", query),
                ("key_kernel", key),
                ("value_kernel", value),
                ("output_kernel", output),
            )
        ]
        output_tensor = _single_output(layer)
        high_output = self.builder.add_operator(
            layer.name,
            "MultiHeadAttention",
            [source, *weights],
            [f"{layer.name}_output"],
            attributes={
                "num_heads": heads,
                "projection_shift": self.options.fraction_bits,
                "score_shift": self.options.fraction_bits,
                "score_scale": (
                    self.builder.scale / math.sqrt(float(key_dim))
                ),
                "softmax_output_scale": self.builder.scale,
                "value_shift": self.options.fraction_bits,
                "output_shift": self.options.fraction_bits,
            },
            output_shapes=[source_shape],
        )[0]
        expected_output = _normalized_transformer_shape(
            _resolved_shape(
                output_tensor,
                self.options,
                name=f"{layer.name}_output",
            ),
            location=f"Keras layer {layer.name!r} output",
        )
        if self.builder.shapes[high_output] != expected_output:
            raise FrontendError(
                f"MultiHeadAttention layer {layer.name!r} output shape is "
                "not [tokens, width]"
            )
        self.aliases[id(output_tensor)] = high_output

    def add_add(self, layer: Any) -> None:
        input_tensors = _layer_inputs(layer)
        if len(input_tensors) != 2:
            raise FrontendError(
                f"Add layer {layer.name!r} must have exactly two inputs"
            )
        sources = [
            self.alias(tensor, layer_name=layer.name) for tensor in input_tensors
        ]
        shape = self.builder.shapes[sources[0]]
        if self.builder.shapes[sources[1]] != shape:
            raise FrontendError(
                f"Add layer {layer.name!r} inputs have different shapes"
            )
        output_tensor = _single_output(layer)
        output = self.builder.add_operator(
            layer.name,
            "Add",
            sources,
            [f"{layer.name}_output"],
            attributes={"scale": self.builder.scale},
            output_shapes=[shape],
        )[0]
        self.aliases[id(output_tensor)] = output

    def add_layer_norm(self, layer: Any) -> None:
        input_tensors = _layer_inputs(layer)
        if len(input_tensors) != 1:
            raise FrontendError(
                f"LayerNormalization layer {layer.name!r} must have one input"
            )
        source = self.alias(input_tensors[0], layer_name=layer.name)
        shape = self.builder.shapes[source]
        if len(shape) < 2:
            raise FrontendError(
                f"LayerNormalization layer {layer.name!r} input rank is too small"
            )
        axis_value = layer.axis
        axes = (
            tuple(int(item) for item in axis_value)
            if isinstance(axis_value, (list, tuple))
            else (int(axis_value),)
        )
        normalized_axes = tuple(
            axis + len(shape) if axis < 0 else axis for axis in axes
        )
        if normalized_axes != (len(shape) - 1,):
            raise FrontendError(
                f"LayerNormalization layer {layer.name!r} must normalize only "
                "the last axis"
            )
        width = shape[-1]
        gamma_values = (
            np.ones(width, dtype=np.float64)
            if layer.gamma is None
            else np.asarray(layer.gamma, dtype=np.float64).reshape(-1)
        )
        beta_values = (
            np.zeros(width, dtype=np.float64)
            if layer.beta is None
            else np.asarray(layer.beta, dtype=np.float64).reshape(-1)
        )
        if gamma_values.size != width or beta_values.size != width:
            raise FrontendError(
                f"LayerNormalization layer {layer.name!r} gamma and beta "
                f"must each contain {width} values"
            )
        _check_fixed_range(
            gamma_values,
            self.options,
            location=f"LayerNormalization layer {layer.name!r} gamma",
        )
        _check_fixed_range(
            beta_values,
            self.options,
            location=f"LayerNormalization layer {layer.name!r} beta",
        )
        gamma = self.builder.add_constant(
            f"{layer.name}_gamma", gamma_values
        )
        beta = self.builder.add_constant(f"{layer.name}_beta", beta_values)
        output_tensor = _single_output(layer)
        output = self.builder.add_operator(
            layer.name,
            "LayerNorm",
            [source, gamma, beta],
            [f"{layer.name}_output"],
            attributes={
                "axis": -1,
                "epsilon": float(layer.epsilon),
                "input_scale": self.builder.scale,
                "gamma_scale": self.builder.scale,
                "beta_scale": self.builder.scale,
                "output_scale": self.builder.scale,
            },
            output_shapes=[shape],
        )[0]
        self.aliases[id(output_tensor)] = output

    def add_dense(self, layer: Any) -> None:
        input_tensors = _layer_inputs(layer)
        if len(input_tensors) != 1:
            raise FrontendError(f"Dense layer {layer.name!r} must have one input")
        source = self.alias(input_tensors[0], layer_name=layer.name)
        kernel = np.asarray(layer.kernel, dtype=np.float64)
        bias = (
            None
            if layer.bias is None
            else np.asarray(layer.bias, dtype=np.float64)
        )
        _check_fixed_range(
            kernel,
            self.options,
            location=f"Dense layer {layer.name!r} kernel",
        )
        if bias is not None:
            _check_fixed_range(
                bias,
                self.options,
                location=f"Dense layer {layer.name!r} bias",
            )
        output_tensor = _single_output(layer)
        activation = _activation_name(self.keras, layer.activation)
        normalized = activation.lower().replace("_", "")
        linear_output_name = (
            f"{layer.name}_output"
            if normalized in ("linear", "identity")
            else f"{layer.name}_linear"
        )
        current = self.builder.add_linear(
            layer.name,
            source,
            kernel,
            bias,
            output_name=linear_output_name,
        )
        if normalized not in ("linear", "identity"):
            current = self.builder.add_activation(
                f"{layer.name}_{activation}",
                activation,
                current,
                output_name=f"{layer.name}_output",
            )
        expected = _normalized_transformer_shape(
            _resolved_shape(
                output_tensor,
                self.options,
                name=f"{layer.name}_output",
            ),
            location=f"Keras layer {layer.name!r} output",
        )
        if self.builder.shapes[current] != expected:
            raise FrontendError(
                f"Dense layer {layer.name!r} output shape does not match its "
                "kernel"
            )
        self.aliases[id(output_tensor)] = current

    def add_separate_activation(self, layer: Any) -> None:
        input_tensors = _layer_inputs(layer)
        if len(input_tensors) != 1:
            raise FrontendError(
                f"activation layer {layer.name!r} must have one input"
            )
        source = self.alias(input_tensors[0], layer_name=layer.name)
        if isinstance(layer, self.keras.layers.ReLU):
            if (
                layer.max_value is not None
                or float(layer.negative_slope) != 0.0
                or float(layer.threshold) != 0.0
            ):
                raise FrontendError(
                    f"ReLU layer {layer.name!r} uses clipping, slope, or "
                    "threshold settings that the NPU ReLU command does not "
                    "represent"
                )
            activation = "relu"
        elif isinstance(layer, self.keras.layers.Softmax):
            axis = layer.axis
            if axis not in (-1, len(self.builder.shapes[source]) - 1):
                raise FrontendError(
                    f"Softmax layer {layer.name!r} must use the last axis"
                )
            activation = "softmax"
        else:
            activation = _activation_name(self.keras, layer.activation)
        output_tensor = _single_output(layer)
        output = self.builder.add_activation(
            layer.name,
            activation,
            source,
            output_name=f"{layer.name}_output",
        )
        self.aliases[id(output_tensor)] = output

    def add_identity_layer(self, layer: Any) -> None:
        inputs = _layer_inputs(layer)
        if len(inputs) != 1:
            raise FrontendError(
                f"inference-only layer {layer.name!r} must have one input"
            )
        self.aliases[id(_single_output(layer))] = self.alias(
            inputs[0], layer_name=layer.name
        )

    def add_layers(self) -> None:
        for layer in self.model.layers:
            if isinstance(layer, self.keras.layers.InputLayer):
                continue
            if isinstance(layer, self.keras.layers.MultiHeadAttention):
                self.add_mha(layer)
            elif isinstance(layer, self.keras.layers.Add):
                self.add_add(layer)
            elif isinstance(layer, self.keras.layers.LayerNormalization):
                self.add_layer_norm(layer)
            elif isinstance(layer, self.keras.layers.Dense):
                self.add_dense(layer)
            elif isinstance(
                layer,
                (
                    self.keras.layers.Activation,
                    self.keras.layers.ReLU,
                    self.keras.layers.Softmax,
                ),
            ):
                self.add_separate_activation(layer)
            elif isinstance(
                layer,
                (
                    self.keras.layers.Dropout,
                    self.keras.layers.SpatialDropout1D,
                ),
            ):
                self.add_identity_layer(layer)
            else:
                raise FrontendError(
                    f"Keras Transformer layer {layer.name!r} has unsupported "
                    f"type {type(layer).__name__}"
                )

    def finish(self) -> dict[str, Any]:
        high_outputs: list[str] = []
        framework_outputs = _flatten_tensors(self.model.outputs)
        for index, tensor in enumerate(framework_outputs):
            current = self.alias(tensor, layer_name="model output")
            original_shape = _resolved_shape(
                tensor,
                self.options,
                name=str(getattr(tensor, "name", f"output_{index}")),
                index=index,
            )
            if self.builder.shapes[current] != original_shape:
                if math.prod(self.builder.shapes[current]) != math.prod(
                    original_shape
                ):
                    raise FrontendError(
                        f"Keras output {index} cannot be restored to shape "
                        f"{list(original_shape)}"
                    )
                current = self.builder.add_operator(
                    f"model_output_{index}_restore_batch",
                    "Reshape",
                    [current],
                    [f"model_output_{index}"],
                    attributes={"shape": list(original_shape)},
                    output_shapes=[original_shape],
                )[0]
            high_outputs.append(current)
        document = self.builder.finish(high_outputs)
        document["frontend"]["keras_import_path"] = (
            "direct_standard_transformer_encoder"
        )
        document["frontend"]["rank3_batch_handling"] = (
            "batch_one_tensor_is_reshaped_to_tokens_by_width"
        )
        return document

    def run(self) -> dict[str, Any]:
        self.add_inputs()
        self.add_layers()
        return self.finish()


def _load_model(path: Path) -> tuple[Any, Any]:
    try:
        import keras
    except ImportError as error:
        raise FrontendError(
            "Keras 3.6 and TensorFlow 2.18 are required to import this model"
        ) from error
    try:
        model = keras.saving.load_model(
            path, compile=False, safe_mode=True
        )
    except Exception as error:
        raise FrontendError(
            f"cannot safely load Keras model {path}: {error}"
        ) from error
    return keras, model


def _contains_attention(model: Any, keras: Any) -> bool:
    return any(
        isinstance(layer, keras.layers.MultiHeadAttention)
        for layer in model.layers
    )


def _convert_to_tflite(model: Any, path: Path) -> bytes:
    try:
        import tensorflow as tf
    except ImportError as error:
        raise FrontendError(
            "TensorFlow 2.18 is required for the Keras generic import path"
        ) from error
    try:
        converter = tf.lite.TFLiteConverter.from_keras_model(model)
        return bytes(converter.convert())
    except Exception as error:
        raise FrontendError(
            f"cannot convert Keras model {path.name!r} to the supported "
            f"TFLite operator subset: {error}"
        ) from error


def load_keras(path: Path, options: FrontendOptions) -> dict[str, Any]:
    """Safely load Keras and produce the compiler's high-level document."""

    path = Path(path)
    keras, model = _load_model(path)
    if _contains_attention(model, keras):
        return _KerasTransformerImporter(
            model, path, options, keras
        ).run()
    content = _convert_to_tflite(model, path)
    document = load_tflite_buffer(
        content, path, options, source_format="keras"
    )
    document["frontend"]["keras_import_path"] = "in_memory_tflite"
    return document


__all__ = ["load_keras"]
