"""TensorFlow Lite importer for the NPU high-level model document.

The importer reconstructs real-valued operator semantics, then stores model
data with the signed fixed-point format selected by ``FrontendOptions``.
TensorFlow Lite constants may use one scale for the whole tensor or one scale
per channel.  Both cases are decoded with their zero points before the common
fixed-point encoder is applied.

Runtime tensors are more restrictive.  The current NPU document uses one
signed scale for a complete tensor and has no zero-point field.  A TensorFlow
Lite runtime tensor with per-axis scales or a nonzero zero point is therefore
rejected explicitly.
"""

from __future__ import annotations

import math
from pathlib import Path
from typing import Any, Callable, Mapping, Sequence

import numpy as np

from .common import (
    DTYPE_LIMITS,
    FrontendError,
    FrontendOptions,
    GraphBuilder,
    dequantize_array,
    fixed_shape,
)


def _check_fixed_range(
    values: Any,
    *,
    dtype: str,
    scale: float,
    location: str,
) -> None:
    array = np.asarray(values, dtype=np.float64)
    if not np.all(np.isfinite(array)):
        raise FrontendError(f"{location} contains NaN or infinity")
    minimum, maximum = DTYPE_LIMITS[dtype]
    encoded = np.rint(array / float(scale))
    if np.any(encoded < minimum) or np.any(encoded > maximum):
        smallest = float(np.min(array))
        largest = float(np.max(array))
        raise FrontendError(
            f"{location} real-value range [{smallest}, {largest}] cannot be "
            f"stored as {dtype} with scale {scale}"
        )


def _as_indices(value: Any) -> tuple[int, ...]:
    array = np.asarray(value, dtype=np.int64).reshape(-1)
    return tuple(int(item) for item in array)


def _tensor_shape(detail: Mapping[str, Any]) -> tuple[int, ...]:
    return tuple(int(item) for item in np.asarray(detail["shape"]).reshape(-1))


def _quantization_fields(
    detail: Mapping[str, Any],
) -> tuple[np.ndarray, np.ndarray, int]:
    parameters = detail.get("quantization_parameters") or {}
    scales = np.asarray(parameters.get("scales", ()), dtype=np.float64).reshape(-1)
    zero_points = np.asarray(
        parameters.get("zero_points", ()), dtype=np.int64
    ).reshape(-1)
    axis = int(parameters.get("quantized_dimension", 0))
    if scales.size == 0:
        return scales, zero_points, axis
    if not np.all(np.isfinite(scales)) or np.any(scales <= 0.0):
        raise FrontendError(
            f"tensor {detail.get('name', '<unnamed>')!r} has an invalid scale"
        )
    if zero_points.size == 0:
        zero_points = np.zeros(scales.size, dtype=np.int64)
    elif zero_points.size == 1 and scales.size > 1:
        zero_points = np.repeat(zero_points, scales.size)
    elif zero_points.size != scales.size:
        raise FrontendError(
            f"tensor {detail.get('name', '<unnamed>')!r} has "
            "different scale and zero-point counts"
        )
    return scales, zero_points, axis


def _decode_constant(values: Any, detail: Mapping[str, Any]) -> np.ndarray:
    """Decode a TFLite constant, including per-axis scale and zero point."""

    scales, zero_points, axis = _quantization_fields(detail)
    if scales.size == 0:
        return np.asarray(values, dtype=np.float64)
    return dequantize_array(values, scales, zero_points, axis)


def _check_runtime_encoding(detail: Mapping[str, Any]) -> None:
    """Reject runtime encodings the single-scale signed IR cannot describe."""

    scales, zero_points, _ = _quantization_fields(detail)
    if scales.size > 1:
        raise FrontendError(
            f"runtime tensor {detail.get('name', '<unnamed>')!r} uses "
            "per-axis scales; the NPU model format requires one tensor scale"
        )
    if zero_points.size and int(zero_points[0]) != 0:
        raise FrontendError(
            f"runtime tensor {detail.get('name', '<unnamed>')!r} has "
            f"zero point {int(zero_points[0])}; the NPU model format uses "
            "signed data with zero represented by integer 0"
        )


def _option_object(
    operator: Any,
    option_class: type,
    expected_type: int,
    *,
    op_name: str,
) -> Any:
    actual_type = int(operator.BuiltinOptionsType())
    if actual_type != int(expected_type):
        raise FrontendError(
            f"{op_name} has options type {actual_type}, expected "
            f"{int(expected_type)}"
        )
    table = operator.BuiltinOptions()
    if table is None:
        raise FrontendError(f"{op_name} is missing builtin options")
    result = option_class()
    result.Init(table.Bytes, table.Pos)
    return result


def _enum_name(enum_class: type, value: int, fallback: str) -> str:
    for name, item in vars(enum_class).items():
        if not name.startswith("_") and isinstance(item, int) and item == value:
            return name
    return f"{fallback}_{value}"


def _operator_name(model: Any, operator: Any, schema: Any) -> str:
    opcode = model.OperatorCodes(int(operator.OpcodeIndex()))
    if opcode is None:
        raise FrontendError("TFLite operator references a missing opcode")
    builtin = max(
        int(opcode.BuiltinCode()), int(opcode.DeprecatedBuiltinCode())
    )
    if builtin == int(schema.BuiltinOperator.CUSTOM):
        custom = opcode.CustomCode()
        if isinstance(custom, bytes):
            custom = custom.decode("utf-8", errors="replace")
        raise FrontendError(f"custom TFLite operator {custom!r} is unsupported")
    return _enum_name(schema.BuiltinOperator, builtin, "BUILTIN")


def _fused_activation_name(value: int, schema: Any) -> str | None:
    name = _enum_name(schema.ActivationFunctionType, int(value), "ACTIVATION")
    if name == "NONE":
        return None
    if name == "RELU":
        return "relu"
    raise FrontendError(
        f"fused TFLite activation {name} is unsupported; only NONE and RELU "
        "can be represented by the current operator set"
    )


def _schema_model(content: bytes) -> tuple[Any, Any, Any]:
    try:
        from tensorflow.lite.python import schema_py_generated as schema
    except ImportError as error:
        raise FrontendError(
            "TensorFlow 2.18 is required to import a TFLite model"
        ) from error
    try:
        model = schema.Model.GetRootAsModel(bytearray(content), 0)
    except Exception as error:
        raise FrontendError("the input is not a valid TFLite flatbuffer") from error
    if int(model.SubgraphsLength()) != 1:
        raise FrontendError("only a TFLite model with one subgraph is supported")
    subgraph = model.Subgraphs(0)
    if subgraph is None:
        raise FrontendError("the TFLite model has no primary subgraph")
    return schema, model, subgraph


def _interpreter(
    content: bytes,
    options: FrontendOptions,
) -> tuple[Any, dict[int, Mapping[str, Any]]]:
    try:
        import tensorflow as tf
    except ImportError as error:
        raise FrontendError(
            "TensorFlow 2.18 is required to import a TFLite model"
        ) from error
    resolver = tf.lite.experimental.OpResolverType.BUILTIN_WITHOUT_DEFAULT_DELEGATES
    try:
        interpreter = tf.lite.Interpreter(
            model_content=content,
            experimental_preserve_all_tensors=True,
            experimental_op_resolver_type=resolver,
        )
        for input_index, detail in enumerate(interpreter.get_input_details()):
            signature = detail.get("shape_signature")
            raw_shape = (
                signature
                if signature is not None and len(signature)
                else detail["shape"]
            )
            shape = fixed_shape(
                raw_shape,
                options=options,
                input_name=str(detail["name"]),
                input_index=input_index,
            )
            interpreter.resize_tensor_input(
                int(detail["index"]), list(shape), strict=False
            )
        interpreter.allocate_tensors()
    except FrontendError:
        raise
    except Exception as error:
        raise FrontendError(f"TFLite interpreter setup failed: {error}") from error
    details = {
        int(detail["index"]): detail for detail in interpreter.get_tensor_details()
    }
    return interpreter, details


def _flatbuffer_indices(operator: Any, field: str) -> tuple[int, ...]:
    length = int(getattr(operator, f"{field}Length")())
    getter = getattr(operator, field)
    return tuple(int(getter(index)) for index in range(length))


class _Importer:
    def __init__(
        self,
        content: bytes,
        source_path: Path,
        options: FrontendOptions,
        source_format: str,
    ) -> None:
        self.content = content
        self.source_path = source_path
        self.options = options
        self.source_format = source_format
        self.schema, self.model, self.subgraph = _schema_model(content)
        self.interpreter, self.details = _interpreter(content, options)
        self.builder = GraphBuilder(
            source_path.stem, source_format, source_path, options
        )
        self.aliases: dict[int, str] = {}
        self.constants: dict[tuple[int, str], str] = {}
        self.constant_indices = self._constant_indices()
        self.input_indices = set(_as_indices(self.subgraph.InputsAsNumpy()))
        self.output_indices = tuple(_as_indices(self.subgraph.OutputsAsNumpy()))
        self.source_encodings: list[dict[str, Any]] = []

    def _constant_indices(self) -> set[int]:
        result: set[int] = set()
        for tensor_index in range(int(self.subgraph.TensorsLength())):
            tensor = self.subgraph.Tensors(tensor_index)
            if tensor is None:
                continue
            buffer = self.model.Buffers(int(tensor.Buffer()))
            if buffer is not None and int(buffer.DataLength()) > 0:
                result.add(tensor_index)
        return result

    def detail(self, index: int) -> Mapping[str, Any]:
        try:
            return self.details[index]
        except KeyError as error:
            raise FrontendError(f"TFLite tensor index {index} is missing") from error

    def real_constant(self, index: int) -> np.ndarray:
        if index not in self.constant_indices:
            raise FrontendError(f"TFLite tensor {index} is not a constant")
        try:
            values = self.interpreter.get_tensor(index)
        except Exception as error:
            raise FrontendError(
                f"cannot read TFLite constant tensor {index}: {error}"
            ) from error
        return _decode_constant(values, self.detail(index))

    def constant(
        self,
        index: int,
        *,
        role: str = "value",
        transform: Callable[[np.ndarray], np.ndarray] | None = None,
        dtype: str | None = None,
        scale: float | None = None,
    ) -> str:
        key = (index, role)
        cached = self.constants.get(key)
        if cached is not None:
            return cached
        values = self.real_constant(index)
        if transform is not None:
            values = transform(values)
        target_dtype = dtype or self.options.dtype
        target_scale = self.builder.scale if scale is None else float(scale)
        _check_fixed_range(
            values,
            dtype=target_dtype,
            scale=target_scale,
            location=f"TFLite constant tensor {index}",
        )
        name = f"{self.detail(index).get('name', f'tensor_{index}')}_{role}"
        tensor = self.builder.add_constant(
            name, values, dtype=dtype, scale=scale
        )
        self.constants[key] = tensor
        return tensor

    def value(self, index: int) -> str:
        if index < 0:
            raise FrontendError("an optional TFLite tensor is unexpectedly absent")
        if index in self.aliases:
            return self.aliases[index]
        if index in self.constant_indices:
            return self.constant(index)
        raise FrontendError(
            f"TFLite tensor {index} is used before it is produced"
        )

    def output_shape(self, index: int) -> tuple[int, ...]:
        shape = _tensor_shape(self.detail(index))
        if not shape or any(item <= 0 for item in shape):
            raise FrontendError(
                f"TFLite output tensor {index} does not have a static shape"
            )
        return shape

    def output_label(self, index: int, suffix: str = "output") -> str:
        return f"{self.detail(index).get('name', f'tensor_{index}')}_{suffix}"

    def add_inputs(self) -> None:
        interpreter_inputs = {
            int(detail["index"]): detail
            for detail in self.interpreter.get_input_details()
        }
        for input_index, tensor_index in enumerate(
            _as_indices(self.subgraph.InputsAsNumpy())
        ):
            if tensor_index not in interpreter_inputs:
                raise FrontendError(
                    f"TFLite input tensor {tensor_index} is missing from "
                    "interpreter metadata"
                )
            detail = interpreter_inputs[tensor_index]
            _check_runtime_encoding(detail)
            shape = fixed_shape(
                detail["shape"],
                options=self.options,
                input_name=str(detail["name"]),
                input_index=input_index,
            )
            self.aliases[tensor_index] = self.builder.add_input(
                str(detail["name"]), shape
            )
            scales, zero_points, axis = _quantization_fields(detail)
            self.source_encodings.append(
                {
                    "name": str(detail["name"]),
                    "shape": list(shape),
                    "scales": [float(item) for item in scales],
                    "zero_points": [int(item) for item in zero_points],
                    "axis": axis,
                }
            )

    def apply_fused(
        self,
        base_name: str,
        function: str | None,
        source: str,
        output_index: int,
    ) -> str:
        if function is None:
            return source
        return self.builder.add_activation(
            f"{base_name}_{function}",
            function,
            source,
            output_name=self.output_label(output_index, function),
        )

    def import_fully_connected(
        self,
        op_index: int,
        operator: Any,
        inputs: tuple[int, ...],
        outputs: tuple[int, ...],
    ) -> None:
        if len(inputs) not in (2, 3) or len(outputs) != 1:
            raise FrontendError(
                f"FULLY_CONNECTED operator {op_index} requires 2 or 3 inputs "
                "and one output"
            )
        options = _option_object(
            operator,
            self.schema.FullyConnectedOptions,
            self.schema.BuiltinOptions.FullyConnectedOptions,
            op_name=f"FULLY_CONNECTED operator {op_index}",
        )
        if int(options.WeightsFormat()) != int(
            self.schema.FullyConnectedOptionsWeightsFormat.DEFAULT
        ):
            raise FrontendError(
                f"FULLY_CONNECTED operator {op_index} uses an unsupported "
                "weight format"
            )
        source = self.value(inputs[0])
        weight_values = self.real_constant(inputs[1])
        if weight_values.ndim != 2:
            raise FrontendError(
                f"FULLY_CONNECTED operator {op_index} weight must be rank 2"
            )
        kernel = np.transpose(weight_values, (1, 0))
        bias = None
        if len(inputs) == 3 and inputs[2] >= 0:
            bias = self.real_constant(inputs[2]).reshape(-1)
        _check_fixed_range(
            kernel,
            dtype=self.options.dtype,
            scale=self.builder.scale,
            location=f"FULLY_CONNECTED operator {op_index} weight",
        )
        if bias is not None:
            _check_fixed_range(
                bias,
                dtype=self.options.dtype,
                scale=self.builder.scale,
                location=f"FULLY_CONNECTED operator {op_index} bias",
            )
        output_shape = self.output_shape(outputs[0])
        expected_shape = (
            self.builder.shapes[source][:-1] + (int(kernel.shape[1]),)
        )
        linear_name = self.output_label(outputs[0], "linear")
        current = self.builder.add_linear(
            f"tflite_fc_{op_index}",
            source,
            kernel,
            bias,
            output_name=linear_name,
        )
        if expected_shape != output_shape:
            if math.prod(expected_shape) != math.prod(output_shape):
                raise FrontendError(
                    f"FULLY_CONNECTED operator {op_index} output shape "
                    "does not match its input and weight"
                )
            current = self.builder.add_operator(
                f"tflite_fc_{op_index}_reshape",
                "Reshape",
                [current],
                [self.output_label(outputs[0], "reshaped")],
                attributes={"shape": list(output_shape)},
                output_shapes=[output_shape],
            )[0]
        fused = _fused_activation_name(
            int(options.FusedActivationFunction()), self.schema
        )
        current = self.apply_fused(
            f"tflite_fc_{op_index}", fused, current, outputs[0]
        )
        self.aliases[outputs[0]] = current

    def import_add(
        self,
        op_index: int,
        operator: Any,
        inputs: tuple[int, ...],
        outputs: tuple[int, ...],
    ) -> None:
        if len(inputs) != 2 or len(outputs) != 1:
            raise FrontendError(
                f"ADD operator {op_index} requires two inputs and one output"
            )
        options = _option_object(
            operator,
            self.schema.AddOptions,
            self.schema.BuiltinOptions.AddOptions,
            op_name=f"ADD operator {op_index}",
        )
        output_shape = self.output_shape(outputs[0])
        current = self.builder.add_operator(
            f"tflite_add_{op_index}",
            "Add",
            [self.value(inputs[0]), self.value(inputs[1])],
            [self.output_label(outputs[0], "sum")],
            attributes={"scale": self.builder.scale},
            output_shapes=[output_shape],
        )[0]
        fused = _fused_activation_name(
            int(options.FusedActivationFunction()), self.schema
        )
        current = self.apply_fused(
            f"tflite_add_{op_index}", fused, current, outputs[0]
        )
        self.aliases[outputs[0]] = current

    def import_activation(
        self,
        op_index: int,
        op_name: str,
        operator: Any,
        inputs: tuple[int, ...],
        outputs: tuple[int, ...],
    ) -> None:
        if len(inputs) != 1 or len(outputs) != 1:
            raise FrontendError(
                f"{op_name} operator {op_index} requires one input and one output"
            )
        function = {
            "RELU": "relu",
            "GELU": "gelu",
            "LOGISTIC": "sigmoid",
            "TANH": "tanh",
        }[op_name]
        if op_name == "GELU":
            options = _option_object(
                operator,
                self.schema.GeluOptions,
                self.schema.BuiltinOptions.GeluOptions,
                op_name=f"GELU operator {op_index}",
            )
            if bool(options.Approximate()):
                raise FrontendError(
                    f"GELU operator {op_index} requests the approximate "
                    "formula, which the NPU GELU command does not select"
                )
        current = self.builder.add_activation(
            f"tflite_{op_name.lower()}_{op_index}",
            function,
            self.value(inputs[0]),
            output_name=self.output_label(outputs[0], function),
        )
        self.aliases[outputs[0]] = current

    def import_softmax(
        self,
        op_index: int,
        operator: Any,
        inputs: tuple[int, ...],
        outputs: tuple[int, ...],
    ) -> None:
        if len(inputs) != 1 or len(outputs) != 1:
            raise FrontendError(
                f"SOFTMAX operator {op_index} requires one input and one output"
            )
        options = _option_object(
            operator,
            self.schema.SoftmaxOptions,
            self.schema.BuiltinOptions.SoftmaxOptions,
            op_name=f"SOFTMAX operator {op_index}",
        )
        beta = float(options.Beta())
        if not math.isfinite(beta) or beta <= 0.0:
            raise FrontendError(
                f"SOFTMAX operator {op_index} has invalid beta {beta}"
            )
        source = self.value(inputs[0])
        output = self.builder.add_operator(
            f"tflite_softmax_{op_index}",
            "Softmax",
            [source],
            [self.output_label(outputs[0], "softmax")],
            attributes={
                "axis": -1,
                "input_scale": self.builder.scale * beta,
                "output_scale": self.builder.scale,
            },
            output_shapes=[self.output_shape(outputs[0])],
        )[0]
        self.aliases[outputs[0]] = output

    def import_reshape(
        self,
        op_index: int,
        inputs: tuple[int, ...],
        outputs: tuple[int, ...],
    ) -> None:
        if len(inputs) not in (1, 2) or len(outputs) != 1:
            raise FrontendError(
                f"RESHAPE operator {op_index} requires one data input, an "
                "optional shape input, and one output"
            )
        shape = self.output_shape(outputs[0])
        if len(inputs) == 2:
            requested = tuple(
                int(item) for item in self.real_constant(inputs[1]).reshape(-1)
            )
            resolved = list(requested)
            negative = [index for index, item in enumerate(resolved) if item == -1]
            if len(negative) > 1 or any(item == 0 or item < -1 for item in resolved):
                raise FrontendError(
                    f"RESHAPE operator {op_index} has an invalid shape tensor"
                )
            if negative:
                resolved[negative[0]] = shape[negative[0]]
            if tuple(resolved) != shape:
                raise FrontendError(
                    f"RESHAPE operator {op_index} shape tensor does not match "
                    "the interpreter output shape"
                )
        output = self.builder.add_operator(
            f"tflite_reshape_{op_index}",
            "Reshape",
            [self.value(inputs[0])],
            [self.output_label(outputs[0], "reshaped")],
            attributes={"shape": list(shape)},
            output_shapes=[shape],
        )[0]
        self.aliases[outputs[0]] = output

    def import_transpose(
        self,
        op_index: int,
        inputs: tuple[int, ...],
        outputs: tuple[int, ...],
    ) -> None:
        if len(inputs) != 2 or len(outputs) != 1:
            raise FrontendError(
                f"TRANSPOSE operator {op_index} requires data, perm, and one output"
            )
        perm = tuple(
            int(item) for item in self.real_constant(inputs[1]).reshape(-1)
        )
        if perm != (1, 0):
            raise FrontendError(
                f"TRANSPOSE operator {op_index} uses perm {list(perm)}; "
                "the current device supports only rank-2 perm [1, 0]"
            )
        output = self.builder.add_operator(
            f"tflite_transpose_{op_index}",
            "Transpose",
            [self.value(inputs[0])],
            [self.output_label(outputs[0], "transposed")],
            attributes={"perm": list(perm)},
            output_shapes=[self.output_shape(outputs[0])],
        )[0]
        self.aliases[outputs[0]] = output

    def import_concat(
        self,
        op_index: int,
        operator: Any,
        inputs: tuple[int, ...],
        outputs: tuple[int, ...],
    ) -> None:
        if len(inputs) < 2 or len(outputs) != 1:
            raise FrontendError(
                f"CONCATENATION operator {op_index} requires at least two "
                "inputs and one output"
            )
        options = _option_object(
            operator,
            self.schema.ConcatenationOptions,
            self.schema.BuiltinOptions.ConcatenationOptions,
            op_name=f"CONCATENATION operator {op_index}",
        )
        rank = len(self.builder.shapes[self.value(inputs[0])])
        axis = int(options.Axis())
        if axis < 0:
            axis += rank
        if axis != rank - 1:
            raise FrontendError(
                f"CONCATENATION operator {op_index} uses axis {axis}; "
                "the current device supports the last axis"
            )
        current = self.builder.add_operator(
            f"tflite_concat_{op_index}",
            "Concat",
            [self.value(index) for index in inputs],
            [self.output_label(outputs[0], "concatenated")],
            attributes={"axis": axis},
            output_shapes=[self.output_shape(outputs[0])],
        )[0]
        fused = _fused_activation_name(
            int(options.FusedActivationFunction()), self.schema
        )
        current = self.apply_fused(
            f"tflite_concat_{op_index}", fused, current, outputs[0]
        )
        self.aliases[outputs[0]] = current

    def import_conv2d(
        self,
        op_index: int,
        operator: Any,
        inputs: tuple[int, ...],
        outputs: tuple[int, ...],
    ) -> None:
        if len(inputs) not in (2, 3) or len(outputs) != 1:
            raise FrontendError(
                f"CONV_2D operator {op_index} requires input, filter, optional "
                "bias, and one output"
            )
        options = _option_object(
            operator,
            self.schema.Conv2DOptions,
            self.schema.BuiltinOptions.Conv2DOptions,
            op_name=f"CONV_2D operator {op_index}",
        )
        source = self.value(inputs[0])
        source_shape = self.builder.shapes[source]
        if len(source_shape) != 4:
            raise FrontendError(
                f"CONV_2D operator {op_index} input must use NHWC rank 4"
            )
        raw_filter = self.real_constant(inputs[1])
        if raw_filter.ndim != 4:
            raise FrontendError(
                f"CONV_2D operator {op_index} filter must use OHWI rank 4"
            )
        if int(raw_filter.shape[3]) != int(source_shape[3]):
            raise FrontendError(
                f"CONV_2D operator {op_index} is grouped or has a filter "
                "channel count different from the NHWC input"
            )
        kernel = self.constant(
            inputs[1],
            role="hwio_kernel",
            transform=lambda value: np.transpose(value, (1, 2, 3, 0)),
        )
        high_inputs = [source, kernel]
        if len(inputs) == 3 and inputs[2] >= 0:
            bias = self.constant(
                inputs[2],
                role="accumulator_bias",
                transform=lambda value: value.reshape(-1),
                dtype="int32",
                scale=self.builder.scale * self.builder.scale,
            )
            high_inputs.append(bias)
        padding_value = int(options.Padding())
        if padding_value == int(self.schema.Padding.SAME):
            padding = "SAME"
        elif padding_value == int(self.schema.Padding.VALID):
            padding = "VALID"
        else:
            raise FrontendError(
                f"CONV_2D operator {op_index} has unknown padding "
                f"value {padding_value}"
            )
        current = self.builder.add_operator(
            f"tflite_conv2d_{op_index}",
            "Conv2D",
            high_inputs,
            [self.output_label(outputs[0], "convolution")],
            attributes={
                "strides": [int(options.StrideH()), int(options.StrideW())],
                "dilations": [
                    int(options.DilationHFactor()),
                    int(options.DilationWFactor()),
                ],
                "padding": padding,
                "data_format": "NHWC",
                "groups": 1,
                "output_shift": self.options.fraction_bits,
                "output_dtype": self.options.dtype,
            },
            output_shapes=[self.output_shape(outputs[0])],
        )[0]
        fused = _fused_activation_name(
            int(options.FusedActivationFunction()), self.schema
        )
        current = self.apply_fused(
            f"tflite_conv2d_{op_index}", fused, current, outputs[0]
        )
        self.aliases[outputs[0]] = current

    def import_representation_change(
        self,
        op_index: int,
        op_name: str,
        inputs: tuple[int, ...],
        outputs: tuple[int, ...],
    ) -> None:
        if len(inputs) != 1 or len(outputs) != 1:
            raise FrontendError(
                f"{op_name} operator {op_index} requires one input and one output"
            )
        input_detail = self.detail(inputs[0])
        output_detail = self.detail(outputs[0])
        if inputs[0] not in self.constant_indices:
            _check_runtime_encoding(input_detail)
            _check_runtime_encoding(output_detail)
        source = self.value(inputs[0])
        if self.builder.shapes[source] != self.output_shape(outputs[0]):
            source = self.builder.add_operator(
                f"tflite_{op_name.lower()}_{op_index}",
                "Reshape",
                [source],
                [self.output_label(outputs[0], "representation")],
                attributes={"shape": list(self.output_shape(outputs[0]))},
                output_shapes=[self.output_shape(outputs[0])],
            )[0]
        self.aliases[outputs[0]] = source

    def import_operators(self) -> None:
        for op_index in range(int(self.subgraph.OperatorsLength())):
            operator = self.subgraph.Operators(op_index)
            if operator is None:
                raise FrontendError(f"TFLite operator {op_index} is missing")
            op_name = _operator_name(self.model, operator, self.schema)
            inputs = _flatbuffer_indices(operator, "Inputs")
            outputs = _flatbuffer_indices(operator, "Outputs")
            for tensor_index in inputs:
                if (
                    tensor_index >= 0
                    and tensor_index not in self.constant_indices
                    and tensor_index in self.details
                ):
                    _check_runtime_encoding(self.detail(tensor_index))
            for tensor_index in outputs:
                if tensor_index >= 0:
                    _check_runtime_encoding(self.detail(tensor_index))
            if op_name == "FULLY_CONNECTED":
                self.import_fully_connected(op_index, operator, inputs, outputs)
            elif op_name == "ADD":
                self.import_add(op_index, operator, inputs, outputs)
            elif op_name in ("RELU", "GELU", "LOGISTIC", "TANH"):
                self.import_activation(
                    op_index, op_name, operator, inputs, outputs
                )
            elif op_name == "SOFTMAX":
                self.import_softmax(op_index, operator, inputs, outputs)
            elif op_name == "RESHAPE":
                self.import_reshape(op_index, inputs, outputs)
            elif op_name == "TRANSPOSE":
                self.import_transpose(op_index, inputs, outputs)
            elif op_name == "CONCATENATION":
                self.import_concat(op_index, operator, inputs, outputs)
            elif op_name == "CONV_2D":
                self.import_conv2d(op_index, operator, inputs, outputs)
            elif op_name in ("QUANTIZE", "DEQUANTIZE"):
                self.import_representation_change(
                    op_index, op_name, inputs, outputs
                )
            else:
                raise FrontendError(
                    f"TFLite operator {op_index} ({op_name}) is unsupported"
                )

    def finish(self) -> dict[str, Any]:
        outputs: list[str] = []
        for tensor_index in self.output_indices:
            outputs.append(self.value(tensor_index))
        document = self.builder.finish(outputs)
        document["frontend"]["source_input_encoding"] = self.source_encodings
        document["frontend"]["constant_scale_handling"] = (
            "decode_scale_and_zero_point_then_encode_signed_fixed_point"
        )
        return document

    def run(self) -> dict[str, Any]:
        self.add_inputs()
        self.import_operators()
        return self.finish()


def load_tflite_buffer(
    content: bytes,
    source_path: Path,
    options: FrontendOptions,
    *,
    source_format: str = "tflite",
) -> dict[str, Any]:
    """Import one in-memory TFLite flatbuffer."""

    if not content:
        raise FrontendError(f"{source_path} is empty")
    return _Importer(
        bytes(content), Path(source_path), options, source_format
    ).run()


def load_tflite(path: Path, options: FrontendOptions) -> dict[str, Any]:
    """Import a ``.tflite`` file into the compiler's high-level document."""

    path = Path(path)
    try:
        content = path.read_bytes()
    except OSError as error:
        raise FrontendError(f"cannot read TFLite model {path}: {error}") from error
    return load_tflite_buffer(content, path, options)


__all__ = [
    "load_tflite",
    "load_tflite_buffer",
]
