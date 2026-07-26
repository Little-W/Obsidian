"""ONNX frontend for the framework-neutral NPU model graph."""

from __future__ import annotations

import math
from pathlib import Path
from typing import Any, Iterable, Mapping, Sequence

import numpy as np

from .common import (
    FrontendError,
    FrontendOptions,
    GraphBuilder,
    fixed_shape,
)


def _attributes(node: Any, onnx: Any) -> dict[str, Any]:
    return {
        attribute.name: onnx.helper.get_attribute_value(attribute)
        for attribute in node.attribute
    }


def _shape_from_value_info(value_info: Any) -> tuple[int | None, ...]:
    tensor_type = value_info.type.tensor_type
    if not tensor_type.HasField("shape"):
        return ()
    result: list[int | None] = []
    for dimension in tensor_type.shape.dim:
        if dimension.HasField("dim_value") and dimension.dim_value > 0:
            result.append(int(dimension.dim_value))
        else:
            result.append(None)
    return tuple(result)


def _resolved_reshape(
    source_shape: Sequence[int],
    requested: Iterable[int],
    *,
    location: str,
) -> tuple[int, ...]:
    result = [int(value) for value in requested]
    inferred: int | None = None
    for index, value in enumerate(result):
        if value == 0:
            if index >= len(source_shape):
                raise FrontendError(
                    f"{location}: zero dimension has no input dimension"
                )
            result[index] = int(source_shape[index])
        elif value == -1:
            if inferred is not None:
                raise FrontendError(
                    f"{location}: more than one inferred dimension"
                )
            inferred = index
        elif value < -1:
            raise FrontendError(
                f"{location}: invalid reshape dimension {value}"
            )
    source_elements = math.prod(source_shape)
    known = math.prod(value for value in result if value != -1)
    if inferred is not None:
        if known <= 0 or source_elements % known:
            raise FrontendError(
                f"{location}: inferred dimension is not integral"
            )
        result[inferred] = source_elements // known
    if any(value <= 0 for value in result):
        raise FrontendError(f"{location}: dimensions must be positive")
    if math.prod(result) != source_elements:
        raise FrontendError(f"{location}: element count changes")
    return tuple(result)


def _broadcast_shape(
    left: Sequence[int],
    right: Sequence[int],
    *,
    location: str,
) -> tuple[int, ...]:
    try:
        return tuple(int(value) for value in np.broadcast_shapes(left, right))
    except ValueError as error:
        raise FrontendError(
            f"{location}: input shapes cannot be broadcast"
        ) from error


def _require_constant(
    name: str,
    constants: Mapping[str, np.ndarray],
    *,
    location: str,
) -> np.ndarray:
    if name not in constants:
        raise FrontendError(
            f"{location}: tensor {name!r} must be a stored constant"
        )
    return np.asarray(constants[name])


def normalize_onnx_model(
    model: Any,
    source_path: Path,
    options: FrontendOptions,
    *,
    source_format: str = "onnx",
) -> dict[str, Any]:
    """Convert a loaded ONNX ModelProto to the common high-level document."""

    try:
        import onnx
        from onnx import numpy_helper
    except ImportError as error:
        raise FrontendError(
            "ONNX import requires the onnx package in the active environment"
        ) from error

    try:
        onnx.checker.check_model(model)
        model = onnx.shape_inference.infer_shapes(model)
    except Exception as error:
        raise FrontendError(f"invalid ONNX model: {error}") from error

    graph = model.graph
    model_name = graph.name or source_path.stem
    builder = GraphBuilder(model_name, source_format, source_path, options)
    constants: dict[str, np.ndarray] = {
        initializer.name: numpy_helper.to_array(initializer)
        for initializer in graph.initializer
    }
    shapes: dict[str, tuple[int | None, ...]] = {}
    for value_info in (
        list(graph.input) + list(graph.value_info) + list(graph.output)
    ):
        shapes[value_info.name] = _shape_from_value_info(value_info)

    aliases: dict[str, str] = {}
    initializer_names = set(constants)
    input_index = 0
    for value_info in graph.input:
        if value_info.name in initializer_names:
            continue
        raw_shape = _shape_from_value_info(value_info)
        shape = fixed_shape(
            raw_shape,
            options=options,
            input_name=value_info.name,
            input_index=input_index,
        )
        aliases[value_info.name] = builder.add_input(
            value_info.name or f"input_{input_index}", shape
        )
        input_index += 1
    if not aliases:
        raise FrontendError("ONNX model has no runtime inputs")

    def source(name: str, location: str) -> str:
        if name in aliases:
            return aliases[name]
        if name in constants:
            tensor = builder.add_constant(name, constants[name])
            aliases[name] = tensor
            return tensor
        raise FrontendError(f"{location}: unknown tensor {name!r}")

    def output_shape(raw_name: str) -> tuple[int, ...] | None:
        raw = shapes.get(raw_name, ())
        if not raw or any(value is None or value <= 0 for value in raw):
            return None
        return tuple(int(value) for value in raw)

    for node_index, node in enumerate(graph.node):
        kind = str(node.op_type)
        lower = kind.lower()
        location = node.name or f"{kind}_{node_index}"
        attributes = _attributes(node, onnx)
        outputs = [value for value in node.output if value]
        if not outputs:
            raise FrontendError(f"{location}: node has no output")

        if lower == "constant":
            if len(outputs) != 1 or "value" not in attributes:
                raise FrontendError(
                    f"{location}: Constant requires one tensor value"
                )
            constants[outputs[0]] = numpy_helper.to_array(
                attributes["value"]
            )
            continue

        if lower in ("matmul", "gemm"):
            if len(outputs) != 1:
                raise FrontendError(
                    f"{location}: {kind} requires one output"
                )
            if len(node.input) < 2:
                raise FrontendError(
                    f"{location}: {kind} requires two inputs"
                )
            left = source(node.input[0], location)
            bias: np.ndarray | None = None
            if lower == "matmul":
                kernel = _require_constant(
                    node.input[1], constants, location=location
                )
            else:
                if int(attributes.get("transA", 0)) != 0:
                    raise FrontendError(
                        f"{location}: Gemm transA is not supported"
                    )
                kernel = _require_constant(
                    node.input[1], constants, location=location
                ).astype(np.float64)
                if int(attributes.get("transB", 0)) != 0:
                    kernel = kernel.T
                kernel = kernel * float(attributes.get("alpha", 1.0))
                if len(node.input) >= 3 and node.input[2]:
                    bias = (
                        _require_constant(
                            node.input[2], constants, location=location
                        ).astype(np.float64)
                        * float(attributes.get("beta", 1.0))
                    )
            result = builder.add_linear(
                location,
                left,
                np.asarray(kernel, dtype=np.float64),
                bias,
                output_name=outputs[0],
            )
            aliases[outputs[0]] = result
            continue

        if lower == "add":
            if len(node.input) != 2 or len(outputs) != 1:
                raise FrontendError(
                    f"{location}: Add requires two inputs and one output"
                )
            left = source(node.input[0], location)
            right = source(node.input[1], location)
            shape = _broadcast_shape(
                builder.shapes[left],
                builder.shapes[right],
                location=location,
            )
            result = builder.add_operator(
                location,
                "Add",
                [left, right],
                outputs,
                attributes={"scale": builder.scale},
                output_shapes=[shape],
            )[0]
            aliases[outputs[0]] = result
            continue

        activation = {
            "relu": "relu",
            "gelu": "gelu",
            "sigmoid": "sigmoid",
            "tanh": "tanh",
            "silu": "silu",
            "softmax": "softmax",
        }.get(lower)
        if activation is not None:
            if len(node.input) != 1 or len(outputs) != 1:
                raise FrontendError(
                    f"{location}: {kind} requires one input and one output"
                )
            input_tensor = source(node.input[0], location)
            result = builder.add_activation(
                location,
                activation,
                input_tensor,
                output_name=outputs[0],
                axis=int(attributes.get("axis", -1)),
            )
            aliases[outputs[0]] = result
            continue

        if lower in ("identity", "reshape", "flatten", "squeeze", "unsqueeze"):
            if not node.input or len(outputs) != 1:
                raise FrontendError(
                    f"{location}: {kind} requires an input and one output"
                )
            input_tensor = source(node.input[0], location)
            source_shape = builder.shapes[input_tensor]
            if lower == "identity":
                target_shape = source_shape
            elif lower == "reshape":
                if len(node.input) < 2:
                    raise FrontendError(
                        f"{location}: Reshape requires a shape tensor"
                    )
                requested = _require_constant(
                    node.input[1], constants, location=location
                ).reshape(-1)
                target_shape = _resolved_reshape(
                    source_shape, requested, location=location
                )
            elif lower == "flatten":
                axis = int(attributes.get("axis", 1))
                if axis < 0:
                    axis += len(source_shape)
                if axis < 0 or axis > len(source_shape):
                    raise FrontendError(
                        f"{location}: Flatten axis is invalid"
                    )
                target_shape = (
                    math.prod(source_shape[:axis]),
                    math.prod(source_shape[axis:]),
                )
            else:
                target_shape = output_shape(outputs[0])
                if target_shape is None:
                    raise FrontendError(
                        f"{location}: {kind} needs a static inferred shape"
                    )
                if math.prod(target_shape) != math.prod(source_shape):
                    raise FrontendError(
                        f"{location}: {kind} changes the element count"
                    )
            result = builder.add_operator(
                location,
                "Reshape",
                [input_tensor],
                outputs,
                attributes={"shape": list(target_shape)},
                output_shapes=[target_shape],
            )[0]
            aliases[outputs[0]] = result
            continue

        if lower == "transpose":
            if len(node.input) != 1 or len(outputs) != 1:
                raise FrontendError(
                    f"{location}: Transpose requires one input and one output"
                )
            input_tensor = source(node.input[0], location)
            input_shape = builder.shapes[input_tensor]
            perm = tuple(
                int(value)
                for value in attributes.get(
                    "perm", tuple(reversed(range(len(input_shape))))
                )
            )
            if len(input_shape) != 2 or perm != (1, 0):
                raise FrontendError(
                    f"{location}: this NPU revision supports only "
                    "rank-2 Transpose [1,0]"
                )
            target_shape = tuple(input_shape[index] for index in perm)
            result = builder.add_operator(
                location,
                "Transpose",
                [input_tensor],
                outputs,
                attributes={"perm": list(perm)},
                output_shapes=[target_shape],
            )[0]
            aliases[outputs[0]] = result
            continue

        if lower == "concat":
            if len(node.input) < 2 or len(outputs) != 1:
                raise FrontendError(
                    f"{location}: Concat requires at least two inputs"
                )
            inputs = [source(name, location) for name in node.input]
            rank = len(builder.shapes[inputs[0]])
            axis = int(attributes.get("axis", 0))
            if axis < 0:
                axis += rank
            if axis != rank - 1:
                raise FrontendError(
                    f"{location}: this NPU revision supports Concat "
                    "on the last axis"
                )
            target = list(builder.shapes[inputs[0]])
            target[axis] = sum(builder.shapes[item][axis] for item in inputs)
            result = builder.add_operator(
                location,
                "Concat",
                inputs,
                outputs,
                attributes={"axis": axis},
                output_shapes=[tuple(target)],
            )[0]
            aliases[outputs[0]] = result
            continue

        if lower == "layernormalization":
            if len(node.input) < 2 or len(outputs) < 1:
                raise FrontendError(
                    f"{location}: LayerNormalization inputs are incomplete"
                )
            input_tensor = source(node.input[0], location)
            input_shape = builder.shapes[input_tensor]
            axis = int(attributes.get("axis", -1))
            if axis < 0:
                axis += len(input_shape)
            if axis != len(input_shape) - 1:
                raise FrontendError(
                    f"{location}: LayerNormalization must use the last axis"
                )
            gamma_values = _require_constant(
                node.input[1], constants, location=location
            )
            if len(node.input) >= 3 and node.input[2]:
                beta_values = _require_constant(
                    node.input[2], constants, location=location
                )
            else:
                beta_values = np.zeros_like(gamma_values)
            gamma = builder.add_constant(
                f"{location}_gamma", gamma_values
            )
            beta = builder.add_constant(f"{location}_beta", beta_values)
            result = builder.add_operator(
                location,
                "LayerNorm",
                [input_tensor, gamma, beta],
                [outputs[0]],
                attributes={
                    "axis": -1,
                    "epsilon": float(attributes.get("epsilon", 1e-5)),
                    "input_scale": builder.scale,
                    "gamma_scale": builder.scale,
                    "beta_scale": builder.scale,
                    "output_scale": builder.scale,
                },
                output_shapes=[input_shape],
            )[0]
            aliases[outputs[0]] = result
            if any(value for value in outputs[1:]):
                raise FrontendError(
                    f"{location}: saved mean and inverse deviation outputs "
                    "are not supported"
                )
            continue

        if lower == "conv":
            raise FrontendError(
                f"{location}: ONNX Conv stores data as NCHW, while this "
                "NPU compiler currently accepts NHWC Conv2D; export from "
                "Keras/TFLite or convert the layout before compilation"
            )

        raise FrontendError(
            f"{location}: unsupported ONNX operator {kind!r}"
        )

    graph_outputs: list[str] = []
    for value_info in graph.output:
        if value_info.name not in aliases:
            raise FrontendError(
                f"ONNX output {value_info.name!r} has no supported producer"
            )
        graph_outputs.append(aliases[value_info.name])
    return builder.finish(graph_outputs)


def load_onnx(path: Path, options: FrontendOptions) -> dict[str, Any]:
    """Load an ONNX file and return the common high-level document."""

    try:
        import onnx
    except ImportError as error:
        raise FrontendError(
            "ONNX import requires the onnx package in the active environment"
        ) from error
    try:
        model = onnx.load(str(path), load_external_data=True)
    except Exception as error:
        raise FrontendError(f"cannot load ONNX model {path}: {error}") from error
    return normalize_onnx_model(model, path, options)


__all__ = ["load_onnx", "normalize_onnx_model"]
