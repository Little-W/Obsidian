#!/usr/bin/env python3
"""Compile a high-level integer model graph and invoke the NPU assembler.

The model graph contains logical tensors and semantic operators.  It does not
contain device addresses, command identifiers, events, engine names, opcodes,
DMA records, or inline command fields.  This program derives those details and
emits a normalized low-level JSON IR for ``npu_assembler.py``.
"""

from __future__ import annotations

import argparse
import math
import re
import struct
import sys
from dataclasses import dataclass, field, replace
from pathlib import Path
from typing import Any, Iterable, Mapping, Sequence

sys.dont_write_bytecode = True

_HERE = Path(__file__).resolve().parent
if str(_HERE) not in sys.path:
    sys.path.insert(0, str(_HERE))

import npu_assembler
import conv_lowering
import model_artifacts
from frontends import (
    FrontendError,
    detect_format,
    load_framework_document,
    options_from_namespace,
)


MODEL_SCHEMA_VERSION = 1
DTYPE_BITS = {"int4": 4, "int8": 8, "int16": 16, "int32": 32}
DTYPE_LIMITS = {
    "int4": (-8, 7),
    "int8": (-128, 127),
    "int16": (-32768, 32767),
    "int32": (-(1 << 31), (1 << 31) - 1),
}
MAX_RANK = 5
CMD_FIFO_MAX_BURST_COMMANDS = 8


class ModelCompileError(ValueError):
    """A stable high-level graph or lowering error."""


@dataclass
class TensorInfo:
    name: str
    shape: tuple[int, ...]
    dtype: str
    kind: str
    data: tuple[int, ...] | None = None
    producer: str | None = None
    consumers: list[str] = field(default_factory=list)
    layout: str = "linear"
    storage_bytes: int = 0
    l1_addr: int | None = None
    ddr_addr: int | None = None
    alias_of: str | None = None
    storage_id: str | None = None
    allocation_bytes: int = 0
    reused_from: str | None = None
    first_task: int = 0
    last_task: int = 0


@dataclass
class OperatorInfo:
    name: str
    op_type: str
    inputs: tuple[str, ...]
    outputs: tuple[str, ...]
    attributes: dict[str, Any]
    source_index: int


@dataclass(frozen=True)
class TargetConfig:
    l1_base: int = 0x1000
    l1_bytes: int = 256 * 1024
    ddr_base: int = 0x20000
    ddr_bytes: int = 2 * 1024 * 1024
    mt: int = 8
    kt: int = 16
    nt: int = 8
    task_entries: int = 32


@dataclass
class VirtualTask:
    name: str
    engine: str
    opcode: str
    reads: tuple[str, ...]
    writes: tuple[str, ...]
    descriptor: dict[str, Any]
    flags: dict[str, Any] = field(default_factory=dict)
    extra_after: tuple[str, ...] = ()
    high_level_node: str = ""


@dataclass
class CompilationResult:
    source_name: str
    model_name: str
    tensors: dict[str, TensorInfo]
    operators: list[OperatorInfo]
    tasks: list[VirtualTask]
    low_ir: dict[str, Any]
    assembled_operations: list[npu_assembler.CompiledOperation]
    command_image: bytes
    constant_image: bytes
    runtime: dict[str, Any]


def fail(location: str, message: str) -> ModelCompileError:
    return ModelCompileError(f"{location}: {message}")


def as_object(value: Any, location: str) -> Mapping[str, Any]:
    if not isinstance(value, dict):
        raise fail(location, "must be a JSON object")
    return value


def as_list(value: Any, location: str) -> list[Any]:
    if not isinstance(value, list):
        raise fail(location, "must be a JSON array")
    return value


def as_name(value: Any, location: str) -> str:
    if not isinstance(value, str) or not value:
        raise fail(location, "must be a non-empty string")
    return value


def parse_int(
    value: Any,
    location: str,
    minimum: int | None = None,
    maximum: int | None = None,
) -> int:
    if isinstance(value, bool):
        raise fail(location, "boolean is not an integer here")
    if isinstance(value, int):
        result = value
    elif isinstance(value, str):
        try:
            result = int(value, 0)
        except ValueError as error:
            raise fail(location, f"invalid integer {value!r}") from error
    else:
        raise fail(location, "must be an integer")
    if minimum is not None and result < minimum:
        raise fail(location, f"value {result} is less than {minimum}")
    if maximum is not None and result > maximum:
        raise fail(location, f"value {result} is greater than {maximum}")
    return result


def parse_float(value: Any, location: str) -> float:
    if isinstance(value, bool) or not isinstance(value, (int, float)):
        raise fail(location, "must be a finite JSON number")
    result = float(value)
    if not math.isfinite(result):
        raise fail(location, "must be finite")
    return result


def float_bits(value: float) -> int:
    """Return an IEEE-754 binary32 encoding used during graph lowering."""

    return struct.unpack("<I", struct.pack("<f", float(value)))[0]


def align_up(value: int, alignment: int) -> int:
    if alignment <= 0 or alignment & (alignment - 1):
        raise ValueError("alignment must be a positive power of two")
    return (value + alignment - 1) & ~(alignment - 1)


def product(shape: Iterable[int]) -> int:
    result = 1
    for dimension in shape:
        result *= dimension
    return result


def dtype_storage_bytes(dtype: str, elements: int) -> int:
    if dtype not in DTYPE_BITS:
        raise ValueError(f"unknown dtype {dtype}")
    bits = DTYPE_BITS[dtype]
    return (elements * bits + 7) // 8


def logical_tensor_bytes(shape: tuple[int, ...], dtype: str) -> int:
    if dtype == "int4":
        return product(shape[:-1]) * ((shape[-1] + 1) // 2)
    return dtype_storage_bytes(dtype, product(shape))


def normalize_dtype(value: Any, location: str) -> str:
    if not isinstance(value, str):
        raise fail(location, "must be an integer dtype name")
    result = value.lower()
    if result not in DTYPE_BITS:
        raise fail(
            location,
            "supported dtypes are int4, int8, int16 and int32",
        )
    return result


def normalize_shape(value: Any, location: str) -> tuple[int, ...]:
    raw = as_list(value, location)
    if not raw or len(raw) > MAX_RANK:
        raise fail(location, f"rank must be in 1..{MAX_RANK}")
    return tuple(
        parse_int(item, f"{location}[{index}]", 1, 0xFFFFFFFF)
        for index, item in enumerate(raw)
    )


def flatten_values(value: Any, location: str) -> list[int]:
    result: list[int] = []

    def visit(item: Any, item_location: str) -> None:
        if isinstance(item, list):
            for index, child in enumerate(item):
                visit(child, f"{item_location}[{index}]")
            return
        if isinstance(item, bool) or not isinstance(item, int):
            raise fail(item_location, "constant data must contain integers")
        result.append(item)

    visit(value, location)
    return result


def named_records(value: Any, location: str) -> list[Mapping[str, Any]]:
    if value is None:
        return []
    if isinstance(value, list):
        return [
            as_object(item, f"{location}[{index}]")
            for index, item in enumerate(value)
        ]
    source = as_object(value, location)
    result: list[Mapping[str, Any]] = []
    for name, item in source.items():
        record = dict(as_object(item, f"{location}.{name}"))
        if "name" in record and record["name"] != name:
            raise fail(f"{location}.{name}.name", "does not match object key")
        record["name"] = name
        result.append(record)
    return result


def pair(value: Any, location: str, default: int = 1) -> tuple[int, int]:
    if value is None:
        return (default, default)
    if isinstance(value, int) and not isinstance(value, bool):
        item = parse_int(value, location, 1, 0xFFFF)
        return (item, item)
    raw = as_list(value, location)
    if len(raw) != 2:
        raise fail(location, "must contain two positive integers")
    return (
        parse_int(raw[0], f"{location}[0]", 1, 0xFFFF),
        parse_int(raw[1], f"{location}[1]", 1, 0xFFFF),
    )


def normalize_axis(value: Any, rank: int, location: str) -> int:
    axis = parse_int(value, location, -rank, rank - 1)
    return axis if axis >= 0 else rank + axis


def parse_tensor_declarations(
    document: Mapping[str, Any],
) -> tuple[dict[str, TensorInfo], dict[str, tuple[tuple[int, ...], str]]]:
    tensors: dict[str, TensorInfo] = {}
    declarations: dict[str, tuple[tuple[int, ...], str]] = {}

    for kind, field_name in (("input", "inputs"), ("constant", "constants")):
        for index, record in enumerate(
            named_records(document.get(field_name, []), field_name)
        ):
            location = f"{field_name}[{index}]"
            name = as_name(record.get("name"), f"{location}.name")
            if name in tensors:
                raise fail(f"{location}.name", f"duplicate tensor {name!r}")
            shape = normalize_shape(record.get("shape"), f"{location}.shape")
            dtype = normalize_dtype(record.get("dtype"), f"{location}.dtype")
            data: tuple[int, ...] | None = None
            if kind == "constant":
                if "data" not in record:
                    raise fail(f"{location}.data", "constant data is required")
                flattened = flatten_values(record["data"], f"{location}.data")
                if len(flattened) != product(shape):
                    raise fail(
                        f"{location}.data",
                        f"contains {len(flattened)} values; expected "
                        f"{product(shape)}",
                    )
                minimum, maximum = DTYPE_LIMITS[dtype]
                for value_index, item in enumerate(flattened):
                    if item < minimum or item > maximum:
                        raise fail(
                            f"{location}.data[{value_index}]",
                            f"value {item} is outside {dtype} range",
                        )
                data = tuple(flattened)
            tensor = TensorInfo(
                name=name,
                shape=shape,
                dtype=dtype,
                kind=kind,
                data=data,
                storage_bytes=logical_tensor_bytes(shape, dtype),
            )
            tensors[name] = tensor

    for index, record in enumerate(
        named_records(document.get("tensors", []), "tensors")
    ):
        location = f"tensors[{index}]"
        name = as_name(record.get("name"), f"{location}.name")
        if name in tensors or name in declarations:
            raise fail(f"{location}.name", f"duplicate tensor {name!r}")
        shape = normalize_shape(record.get("shape"), f"{location}.shape")
        dtype = normalize_dtype(record.get("dtype"), f"{location}.dtype")
        declarations[name] = (shape, dtype)
    return tensors, declarations


def parse_operators(document: Mapping[str, Any]) -> list[OperatorInfo]:
    source = as_list(document.get("operators"), "operators")
    if not source:
        raise fail("operators", "at least one operator is required")
    result: list[OperatorInfo] = []
    names: set[str] = set()
    for index, item in enumerate(source):
        location = f"operators[{index}]"
        record = as_object(item, location)
        name = as_name(record.get("name"), f"{location}.name")
        if name in names:
            raise fail(f"{location}.name", f"duplicate operator {name!r}")
        names.add(name)
        op_type = as_name(record.get("type"), f"{location}.type")
        inputs = tuple(
            as_name(value, f"{location}.inputs[{input_index}]")
            for input_index, value in enumerate(
                as_list(record.get("inputs"), f"{location}.inputs")
            )
        )
        outputs = tuple(
            as_name(value, f"{location}.outputs[{output_index}]")
            for output_index, value in enumerate(
                as_list(record.get("outputs"), f"{location}.outputs")
            )
        )
        if not outputs:
            raise fail(f"{location}.outputs", "must not be empty")
        attributes = dict(
            as_object(record.get("attributes", {}), f"{location}.attributes")
        )
        result.append(
            OperatorInfo(
                name=name,
                op_type=op_type,
                inputs=inputs,
                outputs=outputs,
                attributes=attributes,
                source_index=index,
            )
        )
    return result


def stable_topological_sort(
    tensors: Mapping[str, TensorInfo],
    operators: list[OperatorInfo],
) -> list[OperatorInfo]:
    producer: dict[str, int] = {}
    initial = set(tensors)
    for index, operator in enumerate(operators):
        for output in operator.outputs:
            if output in initial or output in producer:
                raise fail(
                    f"operators[{operator.source_index}].outputs",
                    f"tensor {output!r} has more than one producer",
                )
            producer[output] = index

    successors: list[list[int]] = [[] for _ in operators]
    indegree = [0 for _ in operators]
    for index, operator in enumerate(operators):
        dependencies: set[int] = set()
        for input_index, name in enumerate(operator.inputs):
            if name in initial:
                continue
            if name not in producer:
                raise fail(
                    f"operators[{operator.source_index}].inputs[{input_index}]",
                    f"unknown tensor {name!r}",
                )
            dependency = producer[name]
            if dependency == index:
                raise fail(
                    f"operators[{operator.source_index}]",
                    "operator reads its own output",
                )
            dependencies.add(dependency)
        indegree[index] = len(dependencies)
        for dependency in dependencies:
            successors[dependency].append(index)

    ready = [index for index, degree in enumerate(indegree) if degree == 0]
    ordered: list[OperatorInfo] = []
    while ready:
        ready.sort(key=lambda item: operators[item].source_index)
        current = ready.pop(0)
        ordered.append(operators[current])
        for successor in successors[current]:
            indegree[successor] -= 1
            if indegree[successor] == 0:
                ready.append(successor)
    if len(ordered) != len(operators):
        cyclic = [
            operators[index].name
            for index, degree in enumerate(indegree)
            if degree != 0
        ]
        raise fail("operators", f"graph contains a cycle involving {cyclic}")
    return ordered


def require_count(
    operator: OperatorInfo,
    inputs: int,
    outputs: int = 1,
) -> None:
    if len(operator.inputs) != inputs or len(operator.outputs) != outputs:
        raise fail(
            f"operator {operator.name}",
            f"{operator.op_type} requires {inputs} inputs and "
            f"{outputs} outputs",
        )


def declared_output(
    name: str,
    shape: tuple[int, ...],
    dtype: str,
    declarations: Mapping[str, tuple[tuple[int, ...], str]],
    operator: OperatorInfo,
) -> TensorInfo:
    if name in declarations:
        declared_shape, declared_dtype = declarations[name]
        if declared_shape != shape:
            raise fail(
                f"operator {operator.name}",
                f"output {name!r} shape is {shape}, declaration is "
                f"{declared_shape}",
            )
        if declared_dtype != dtype:
            raise fail(
                f"operator {operator.name}",
                f"output {name!r} dtype is {dtype}, declaration is "
                f"{declared_dtype}",
            )
    return TensorInfo(
        name=name,
        shape=shape,
        dtype=dtype,
        kind="intermediate",
        producer=operator.name,
        storage_bytes=logical_tensor_bytes(shape, dtype),
    )


def conv_output_shape(
    input_shape: tuple[int, ...],
    kernel_shape: tuple[int, ...],
    attributes: dict[str, Any],
    location: str,
) -> tuple[tuple[int, ...], tuple[int, int, int, int]]:
    try:
        geometry = conv_lowering.infer_conv2d(
            input_shape,
            kernel_shape,
            {
                key: value
                for key, value in attributes.items()
                if key
                in {
                    "strides",
                    "dilations",
                    "padding",
                    "groups",
                    "data_format",
                }
            },
        )
    except conv_lowering.ConvLoweringError as error:
        raise fail(location, str(error)) from error
    attributes["_strides"] = list(geometry.strides)
    attributes["_dilations"] = list(geometry.dilations)
    attributes["_pads"] = list(geometry.padding)
    return geometry.output_shape, geometry.padding


def infer_graph(
    tensors: dict[str, TensorInfo],
    declarations: Mapping[str, tuple[tuple[int, ...], str]],
    operators: list[OperatorInfo],
) -> None:
    for operator in operators:
        location = f"operator {operator.name}"
        inputs = [tensors[name] for name in operator.inputs]
        kind = operator.op_type.lower()
        output_shapes: list[tuple[int, ...]]
        output_dtype: str

        if kind in ("matmul", "linear"):
            require_count(operator, 2)
            left, right = inputs
            if len(left.shape) != 2 or len(right.shape) != 2:
                raise fail(location, "MatMul currently requires two rank-2 tensors")
            if left.shape[1] != right.shape[0]:
                raise fail(location, "MatMul K dimensions do not match")
            if left.dtype != right.dtype:
                raise fail(location, "Matrix inputs must use the same dtype")
            output_dtype = normalize_dtype(
                operator.attributes.get("output_dtype", left.dtype),
                f"{location}.output_dtype",
            )
            output_shapes = [(left.shape[0], right.shape[1])]
        elif kind == "add":
            require_count(operator, 2)
            left, right = inputs
            if left.dtype != right.dtype:
                raise fail(location, "Add inputs must use the same dtype")

            def is_feature_shape(
                candidate: tuple[int, ...],
                full: tuple[int, ...],
            ) -> bool:
                return (
                    len(full) >= 2
                    and candidate != full
                    and candidate[-1] == full[-1]
                    and product(candidate) == full[-1]
                )

            if left.shape == right.shape:
                shape = left.shape
            elif product(left.shape) == 1:
                shape = right.shape
            elif product(right.shape) == 1:
                shape = left.shape
            elif is_feature_shape(left.shape, right.shape):
                shape = right.shape
            elif is_feature_shape(right.shape, left.shape):
                shape = left.shape
            else:
                raise fail(
                    location,
                    "Add supports equal shapes, one scalar, or a feature "
                    "vector matching the last dimension",
                )
            output_dtype = left.dtype
            output_shapes = [shape]
        elif kind in ("relu", "sigmoid", "tanh", "silu"):
            require_count(operator, 1)
            output_dtype = inputs[0].dtype
            output_shapes = [inputs[0].shape]
        elif kind in ("softmax", "gelu"):
            require_count(operator, 1)
            source = inputs[0]
            axis = normalize_axis(
                operator.attributes.get("axis", -1),
                len(source.shape),
                f"{location}.axis",
            )
            if axis != len(source.shape) - 1:
                raise fail(location, f"{operator.op_type} supports the last axis")
            output_dtype = source.dtype
            output_shapes = [source.shape]
        elif kind == "layernorm":
            require_count(operator, 3)
            source, gamma, beta = inputs
            if len(source.shape) < 2:
                raise fail(location, "LayerNorm input rank must be at least 2")
            axis = normalize_axis(
                operator.attributes.get("axis", -1),
                len(source.shape),
                f"{location}.axis",
            )
            if axis != len(source.shape) - 1:
                raise fail(location, "LayerNorm supports the last axis")
            expected = (source.shape[-1],)
            if gamma.shape != expected or beta.shape != expected:
                raise fail(location, "gamma and beta must match the last dimension")
            if source.dtype != gamma.dtype or source.dtype != beta.dtype:
                raise fail(location, "LayerNorm tensors must use the same dtype")
            output_dtype = source.dtype
            output_shapes = [source.shape]
        elif kind == "reshape":
            require_count(operator, 1)
            raw_shape = as_list(
                operator.attributes.get("shape"), f"{location}.shape"
            )
            inferred_index: int | None = None
            shape_values: list[int] = []
            for index, item in enumerate(raw_shape):
                value = parse_int(item, f"{location}.shape[{index}]", -1)
                if value == -1:
                    if inferred_index is not None:
                        raise fail(location, "Reshape permits one inferred dimension")
                    inferred_index = index
                    shape_values.append(1)
                elif value == 0:
                    raise fail(location, "Reshape dimensions must not be zero")
                else:
                    shape_values.append(value)
            source_elements = product(inputs[0].shape)
            fixed = product(shape_values)
            if inferred_index is not None:
                if fixed == 0 or source_elements % fixed:
                    raise fail(location, "Reshape inferred dimension is not integral")
                shape_values[inferred_index] = source_elements // fixed
            if product(shape_values) != source_elements:
                raise fail(location, "Reshape changes the element count")
            output_dtype = inputs[0].dtype
            output_shapes = [tuple(shape_values)]
        elif kind == "transpose":
            require_count(operator, 1)
            source = inputs[0]
            raw = as_list(operator.attributes.get("perm"), f"{location}.perm")
            perm = tuple(
                parse_int(item, f"{location}.perm[{index}]", 0, len(source.shape) - 1)
                for index, item in enumerate(raw)
            )
            if len(perm) != len(source.shape) or sorted(perm) != list(
                range(len(source.shape))
            ):
                raise fail(location, "Transpose perm must contain every axis once")
            operator.attributes["_perm"] = list(perm)
            output_dtype = source.dtype
            output_shapes = [tuple(source.shape[index] for index in perm)]
        elif kind == "concat":
            if len(inputs) < 2:
                raise fail(location, "Concat requires at least two inputs")
            require_count(operator, len(inputs))
            rank = len(inputs[0].shape)
            axis = normalize_axis(
                operator.attributes.get("axis", -1),
                rank,
                f"{location}.axis",
            )
            if any(item.dtype != inputs[0].dtype for item in inputs):
                raise fail(location, "Concat inputs must use the same dtype")
            dimensions = list(inputs[0].shape)
            dimensions[axis] = 0
            for item in inputs:
                if len(item.shape) != rank:
                    raise fail(location, "Concat input ranks do not match")
                for dimension in range(rank):
                    if dimension != axis and item.shape[dimension] != inputs[0].shape[dimension]:
                        raise fail(location, "Concat non-axis dimensions do not match")
                dimensions[axis] += item.shape[axis]
            operator.attributes["_axis"] = axis
            output_dtype = inputs[0].dtype
            output_shapes = [tuple(dimensions)]
        elif kind == "multiheadattention":
            require_count(operator, 5)
            source, weight_q, weight_k, weight_v, weight_o = inputs
            if len(source.shape) != 2:
                raise fail(location, "MultiHeadAttention input must be [tokens,width]")
            tokens, width = source.shape
            expected = (width, width)
            for weight in (weight_q, weight_k, weight_v, weight_o):
                if weight.shape != expected:
                    raise fail(location, "all attention weights must be [width,width]")
                if weight.dtype != source.dtype:
                    raise fail(location, "attention tensors must use the same dtype")
            heads = parse_int(
                operator.attributes.get("num_heads"),
                f"{location}.num_heads",
                1,
                255,
            )
            if width % heads:
                raise fail(location, "width must be divisible by num_heads")
            operator.attributes["_head_width"] = width // heads
            operator.attributes["_tokens"] = tokens
            output_dtype = source.dtype
            output_shapes = [source.shape]
        elif kind == "conv2d":
            if len(inputs) not in (2, 3):
                raise fail(location, "Conv2D requires input, kernel and optional bias")
            require_count(operator, len(inputs))
            source, kernel = inputs[:2]
            if source.dtype != kernel.dtype:
                raise fail(location, "Conv2D input and kernel must use the same dtype")
            shape, _ = conv_output_shape(
                source.shape, kernel.shape, operator.attributes, location
            )
            if source.dtype == "int4" and source.shape[-1] % 2:
                raise fail(location, "INT4 Conv2D requires an even Cin")
            if len(inputs) == 3:
                bias = inputs[2]
                if bias.shape != (shape[-1],) or bias.dtype != "int32":
                    raise fail(location, "Conv2D bias must be INT32 with shape [Cout]")
            output_dtype = normalize_dtype(
                operator.attributes.get("output_dtype", source.dtype),
                f"{location}.output_dtype",
            )
            output_shapes = [shape]
        else:
            raise fail(location, f"unsupported operator type {operator.op_type!r}")

        if len(output_shapes) != len(operator.outputs):
            raise fail(location, "internal output count error")
        for name, shape in zip(operator.outputs, output_shapes):
            tensors[name] = declared_output(
                name, shape, output_dtype, declarations, operator
            )
        for source in inputs:
            source.consumers.append(operator.name)


def parse_model_document(
    document: Mapping[str, Any],
) -> tuple[str, dict[str, TensorInfo], list[OperatorInfo], tuple[str, ...]]:
    version = parse_int(
        document.get("schema_version"),
        "schema_version",
        MODEL_SCHEMA_VERSION,
        MODEL_SCHEMA_VERSION,
    )
    if version != MODEL_SCHEMA_VERSION:
        raise fail("schema_version", f"unsupported version {version}")
    model = as_object(document.get("model"), "model")
    model_name = as_name(model.get("name"), "model.name")
    tensors, declarations = parse_tensor_declarations(document)
    operators = stable_topological_sort(tensors, parse_operators(document))
    infer_graph(tensors, declarations, operators)
    outputs = tuple(
        as_name(value, f"outputs[{index}]")
        for index, value in enumerate(as_list(document.get("outputs"), "outputs"))
    )
    if not outputs:
        raise fail("outputs", "at least one model output is required")
    for index, name in enumerate(outputs):
        if name not in tensors:
            raise fail(f"outputs[{index}]", f"unknown tensor {name!r}")
        tensors[name].kind = "output"
    unused = set(declarations) - set(tensors)
    if unused:
        raise fail("tensors", f"unused declarations: {sorted(unused)}")
    return model_name, tensors, operators, outputs


def pack_integer_values(values: Sequence[int], dtype: str) -> bytes:
    """Pack signed integer values in the device's little-endian order."""

    if dtype == "int4":
        result = bytearray((len(values) + 1) // 2)
        for index, value in enumerate(values):
            nibble = value & 0xF
            if index & 1:
                result[index // 2] |= nibble << 4
            else:
                result[index // 2] = nibble
        return bytes(result)
    if dtype == "int8":
        return bytes(value & 0xFF for value in values)
    if dtype == "int16":
        return b"".join(struct.pack("<h", value) for value in values)
    if dtype == "int32":
        return b"".join(struct.pack("<i", value) for value in values)
    raise ValueError(f"unsupported dtype {dtype}")


def pack_linear_tensor_values(
    values: Sequence[int],
    shape: tuple[int, ...],
    dtype: str,
) -> bytes:
    if len(values) != product(shape):
        raise ValueError("linear tensor value count does not match shape")
    if dtype != "int4":
        return pack_integer_values(values, dtype)
    columns = shape[-1]
    rows = product(shape[:-1])
    row_bytes = (columns + 1) // 2
    result = bytearray(rows * row_bytes)
    for row in range(rows):
        for column in range(columns):
            value = values[row * columns + column] & 0xF
            offset = row * row_bytes + column // 2
            if column & 1:
                result[offset] |= value << 4
            else:
                result[offset] |= value
    return bytes(result)


def pack_matrix_b_values(
    values: Sequence[int],
    rows: int,
    columns: int,
    dtype: str,
    target: TargetConfig,
) -> bytes:
    """Pack a row-major KxN matrix into the Matrix-B tile order."""

    if len(values) != rows * columns:
        raise ValueError("Matrix-B value count does not match shape")
    k_tiles = (rows + target.kt - 1) // target.kt
    n_tiles = (columns + target.nt - 1) // target.nt
    padded = [0] * (
        k_tiles * n_tiles * target.kt * target.nt
    )
    for row in range(rows):
        for column in range(columns):
            k_outer = row // target.kt
            n_outer = column // target.nt
            k_inner = row % target.kt
            n_inner = column % target.nt
            packed_index = (
                (
                    (
                        k_outer * n_tiles + n_outer
                    )
                    * target.kt
                    + k_inner
                )
                * target.nt
                + n_inner
            )
            padded[packed_index] = values[row * columns + column]
    return pack_integer_values(padded, dtype)


class ConstantArena:
    """Compile-time constant bytes with identical DDR/L1 relative offsets."""

    def __init__(self, target: TargetConfig) -> None:
        self.target = target
        self.image = bytearray()
        self.entries: dict[str, tuple[int, int, str, str]] = {}

    def add_bytes(
        self,
        name: str,
        content: bytes,
        dtype: str,
        layout: str,
        alignment: int,
    ) -> int:
        if name in self.entries:
            old_offset, old_bytes, old_dtype, old_layout = self.entries[name]
            if (
                old_bytes != len(content)
                or old_dtype != dtype
                or old_layout != layout
                or bytes(self.image[old_offset : old_offset + old_bytes])
                != content
            ):
                raise fail("constants", f"incompatible uses of {name!r}")
            return old_offset
        offset = align_up(len(self.image), alignment)
        if offset > len(self.image):
            self.image.extend(b"\0" * (offset - len(self.image)))
        self.image.extend(content)
        self.entries[name] = (offset, len(content), dtype, layout)
        return offset

    def add_linear(self, tensor: TensorInfo) -> int:
        if tensor.data is None:
            raise ValueError("constant data is absent")
        return self.add_bytes(
            tensor.name,
            pack_linear_tensor_values(
                tensor.data, tensor.shape, tensor.dtype
            ),
            tensor.dtype,
            "linear",
            64,
        )

    def add_matrix_b(
        self,
        tensor: TensorInfo,
        rows: int,
        columns: int,
        values: Sequence[int] | None = None,
    ) -> int:
        source = tensor.data if values is None else tuple(values)
        if source is None:
            raise ValueError("constant data is absent")
        content = pack_matrix_b_values(
            source,
            rows,
            columns,
            tensor.dtype,
            self.target,
        )
        return self.add_bytes(
            tensor.name,
            content,
            tensor.dtype,
            f"matrix_b:{rows}x{columns}",
            256,
        )

    def add_requant(self, shift: int) -> str:
        checked = parse_int(shift, "requant shift", 0, 31)
        name = f"__requant_shift_{checked}"
        self.add_bytes(
            name,
            struct.pack("<IB3x", 1, checked),
            "int32",
            "requant",
            8,
        )
        return name

    def finalize(self) -> bytes:
        final_bytes = align_up(len(self.image), 64)
        if final_bytes > len(self.image):
            self.image.extend(b"\0" * (final_bytes - len(self.image)))
        return bytes(self.image)


def matrix_constant_requirements(
    tensors: Mapping[str, TensorInfo],
    operators: Sequence[OperatorInfo],
) -> dict[str, tuple[int, int, tuple[int, ...] | None]]:
    requirements: dict[str, tuple[int, int, tuple[int, ...] | None]] = {}

    def require(
        name: str,
        rows: int,
        columns: int,
        values: tuple[int, ...] | None = None,
    ) -> None:
        tensor = tensors[name]
        if tensor.kind != "constant":
            raise fail(
                "operators",
                f"Matrix B tensor {name!r} must be a compile-time constant",
            )
        request = (rows, columns, values)
        previous = requirements.get(name)
        if previous is not None and previous != request:
            raise fail(
                "operators",
                f"constant {name!r} is used with incompatible Matrix "
                "shapes or compile-time scaling",
            )
        requirements[name] = request

    for operator in operators:
        kind = operator.op_type.lower()
        if kind in ("matmul", "linear"):
            weight = tensors[operator.inputs[1]]
            require(weight.name, weight.shape[0], weight.shape[1])
        elif kind == "multiheadattention":
            query_name = operator.inputs[1]
            key_name = operator.inputs[2]
            query = tensors[query_name]
            key = tensors[key_name]
            score_scale = parse_float(
                operator.attributes.get("score_scale", 1.0),
                f"operator {operator.name}.score_scale",
            )
            heads = parse_int(
                operator.attributes.get("num_heads"),
                f"operator {operator.name}.num_heads",
                1,
            )
            (
                _softmax_scale,
                query_weight_scale,
                key_weight_scale,
            ) = attention_score_scale_plan(
                score_scale,
                tensors[operator.inputs[0]].dtype,
                f"operator {operator.name}.score_scale",
                query_values=query.data,
                key_values=key.data,
                width=query.shape[0],
                heads=heads,
                query_dtype=query.dtype,
                key_dtype=key.dtype,
            )
            for name, tensor, projection_weight_scale in (
                (query_name, query, query_weight_scale),
                (key_name, key, key_weight_scale),
            ):
                values = (
                    None
                    if projection_weight_scale is None
                    else scale_integer_values(
                        tensor.data or (),
                        projection_weight_scale,
                        tensor.dtype,
                    )
                )
                require(
                    name,
                    tensor.shape[0],
                    tensor.shape[1],
                    values,
                )
            for name in operator.inputs[3:5]:
                weight = tensors[name]
                require(name, weight.shape[0], weight.shape[1])
        elif kind == "conv2d":
            kernel = tensors[operator.inputs[1]]
            if kernel.data is None:
                raise fail(
                    f"operator {operator.name}",
                    "Conv2D kernel must be a constant",
                )
            matrix = conv_lowering.conv_kernel_to_matrix(
                kernel.data, kernel.shape
            )
            require(
                kernel.name,
                matrix.rows,
                matrix.columns,
                matrix.values,
            )
    return requirements


class AddressAllocator:
    def __init__(self, cursor: int, limit: int, location: str) -> None:
        self.cursor = cursor
        self.limit = limit
        self.location = location

    def allocate(self, size: int, alignment: int = 64) -> int:
        if size <= 0:
            raise fail(self.location, "cannot allocate an empty region")
        address = align_up(self.cursor, alignment)
        end = address + size
        if end < address or end > self.limit:
            raise fail(
                self.location,
                f"need 0x{size:x} bytes at 0x{address:x}, "
                f"limit is 0x{self.limit:x}",
            )
        self.cursor = end
        return address


def validate_target(target: TargetConfig) -> None:
    for name, value in (
        ("l1_base", target.l1_base),
        ("l1_bytes", target.l1_bytes),
        ("ddr_base", target.ddr_base),
        ("ddr_bytes", target.ddr_bytes),
    ):
        if value < 0:
            raise fail(f"target.{name}", "must be nonnegative")
    if target.l1_base >= target.l1_bytes:
        raise fail("target.l1_base", "must be below the L1 capacity")
    if target.ddr_base >= target.ddr_bytes:
        raise fail("target.ddr_base", "must be below the DDR capacity")
    for name, value in (
        ("mt", target.mt),
        ("kt", target.kt),
        ("nt", target.nt),
    ):
        if value <= 0 or value > 255:
            raise fail(f"target.{name}", "must be in 1..255")
    if target.task_entries <= 0 or target.task_entries > 4096:
        raise fail("target.task_entries", "must be in 1..4096")


def prepare_constant_arena(
    tensors: dict[str, TensorInfo],
    operators: Sequence[OperatorInfo],
    target: TargetConfig,
) -> tuple[ConstantArena, dict[int, str]]:
    arena = ConstantArena(target)
    matrix_requirements = matrix_constant_requirements(tensors, operators)
    for tensor in tensors.values():
        if tensor.kind != "constant":
            continue
        if tensor.name in matrix_requirements:
            rows, columns, values = matrix_requirements[tensor.name]
            arena.add_matrix_b(tensor, rows, columns, values)
            tensor.layout = "matrix_b"
        else:
            arena.add_linear(tensor)
            tensor.layout = "linear"
    requant_by_shift: dict[int, str] = {}
    shifts = {0}
    for operator in operators:
        kind = operator.op_type.lower()
        if kind == "multiheadattention":
            for field_name, default in (
                ("projection_shift", 0),
                ("score_shift", 0),
                ("value_shift", 2),
                ("output_shift", 0),
            ):
                shifts.add(
                    parse_int(
                        operator.attributes.get(field_name, default),
                        f"operator {operator.name}.{field_name}",
                        0,
                        31,
                    )
                )
        elif kind in ("matmul", "linear", "conv2d"):
            shifts.add(
                parse_int(
                    operator.attributes.get("output_shift", 0),
                    f"operator {operator.name}.output_shift",
                    0,
                    31,
                )
            )
    for shift in shifts:
        requant_by_shift[shift] = arena.add_requant(shift)
    return arena, requant_by_shift


@dataclass
class ReusableBlock:
    addr: int
    capacity: int
    storage_id: str
    previous_tensor: str


def allocate_high_level_l1(
    tensors: dict[str, TensorInfo],
    operators: Sequence[OperatorInfo],
    allocator: AddressAllocator,
) -> None:
    operator_index = {
        operator.name: index for index, operator in enumerate(operators)
    }
    candidates: list[TensorInfo] = []
    for tensor in tensors.values():
        if tensor.kind == "constant":
            continue
        tensor.storage_bytes = logical_tensor_bytes(
            tensor.shape, tensor.dtype
        )
        if tensor.kind == "input":
            first = -1
        elif tensor.producer is not None:
            first = operator_index[tensor.producer]
        else:
            first = 0
        consumer_indices = [
            operator_index[name]
            for name in tensor.consumers
            if name in operator_index
        ]
        last = max(consumer_indices, default=first)
        if tensor.kind == "output":
            last = len(operators)
        tensor.first_task = first
        tensor.last_task = last
        candidates.append(tensor)

    active: list[tuple[int, ReusableBlock]] = []
    free_blocks: list[ReusableBlock] = []
    next_storage_id = 0
    candidates.sort(
        key=lambda tensor: (tensor.first_task, tensor.name)
    )
    for tensor in candidates:
        still_active: list[tuple[int, ReusableBlock]] = []
        for last, block in active:
            if last < tensor.first_task:
                free_blocks.append(block)
            else:
                still_active.append((last, block))
        active = still_active
        fitting = [
            block
            for block in free_blocks
            if block.capacity >= tensor.storage_bytes
        ]
        if fitting:
            block = min(fitting, key=lambda item: item.capacity)
            free_blocks.remove(block)
            tensor.l1_addr = block.addr
            tensor.storage_id = block.storage_id
            tensor.allocation_bytes = block.capacity
            tensor.reused_from = block.previous_tensor
        else:
            address = allocator.allocate(tensor.storage_bytes, 64)
            block = ReusableBlock(
                addr=address,
                capacity=tensor.storage_bytes,
                storage_id=f"l1:{next_storage_id}",
                previous_tensor=tensor.name,
            )
            next_storage_id += 1
            tensor.l1_addr = address
            tensor.storage_id = block.storage_id
            tensor.allocation_bytes = block.capacity
        active.append(
            (
                tensor.last_task,
                ReusableBlock(
                    addr=block.addr,
                    capacity=block.capacity,
                    storage_id=block.storage_id,
                    previous_tensor=tensor.name,
                ),
            )
        )


def allocate_model_storage(
    tensors: dict[str, TensorInfo],
    operators: Sequence[OperatorInfo],
    outputs: Sequence[str],
    target: TargetConfig,
    arena: ConstantArena,
) -> tuple[AddressAllocator, AddressAllocator, bytes]:
    constant_image = arena.finalize()
    l1_allocator = AddressAllocator(
        align_up(target.l1_base, 256), target.l1_bytes, "L1 allocation"
    )
    ddr_allocator = AddressAllocator(
        align_up(target.ddr_base, 256), target.ddr_bytes, "DDR allocation"
    )
    constant_l1_base = l1_allocator.allocate(len(constant_image), 256)
    constant_ddr_base = ddr_allocator.allocate(len(constant_image), 256)

    for name, (offset, size, _dtype, layout) in arena.entries.items():
        if name in tensors:
            tensor = tensors[name]
        else:
            tensor = TensorInfo(
                name=name,
                shape=(size,),
                dtype="int32",
                kind="constant",
                storage_bytes=size,
            )
            tensors[name] = tensor
        tensor.l1_addr = constant_l1_base + offset
        tensor.ddr_addr = constant_ddr_base + offset
        tensor.storage_bytes = size
        tensor.allocation_bytes = size
        tensor.storage_id = f"constant:{name}"
        tensor.layout = layout

    allocate_high_level_l1(tensors, operators, l1_allocator)
    for tensor in list(tensors.values()):
        if tensor.kind == "input":
            tensor.ddr_addr = ddr_allocator.allocate(
                tensor.storage_bytes, 64
            )

    for name in outputs:
        tensor = tensors[name]
        tensor.ddr_addr = ddr_allocator.allocate(tensor.storage_bytes, 64)
    return l1_allocator, ddr_allocator, constant_image


def element_bytes(dtype: str, count: int = 1) -> int:
    bits = DTYPE_BITS[dtype] * count
    if bits % 8:
        raise fail("layout", f"{dtype} row is not byte aligned")
    return bits // 8


def element_byte_offset(index: int, dtype: str) -> int:
    bits = DTYPE_BITS[dtype] * index
    if bits % 8:
        raise fail("layout", "element offset is not byte aligned")
    return bits // 8


def add_internal_tensor(
    tensors: dict[str, TensorInfo],
    allocator: AddressAllocator,
    name: str,
    shape: tuple[int, ...],
    dtype: str,
    *,
    storage_bytes: int | None = None,
    alignment: int = 64,
    layout: str = "linear",
) -> TensorInfo:
    if name in tensors:
        raise fail("lowering", f"internal tensor name collision {name!r}")
    size = (
        logical_tensor_bytes(shape, dtype)
        if storage_bytes is None
        else storage_bytes
    )
    tensor = TensorInfo(
        name=name,
        shape=shape,
        dtype=dtype,
        kind="internal",
        layout=layout,
        storage_bytes=size,
        l1_addr=allocator.allocate(size, alignment),
        storage_id=f"internal:{name}",
        allocation_bytes=size,
    )
    tensors[name] = tensor
    return tensor


def tensor_reference(tensor: TensorInfo, space: str = "l1") -> dict[str, Any]:
    address = tensor.l1_addr if space == "l1" else tensor.ddr_addr
    if address is None:
        raise fail("lowering", f"tensor {tensor.name!r} has no {space} address")
    return {
        "addr": address,
        "space": space,
        "dtype": tensor.dtype,
        "region_bytes": tensor.storage_bytes,
    }


def vector_dimensions(shape: tuple[int, ...]) -> tuple[int, int]:
    return product(shape[:-1]) if len(shape) > 1 else 1, shape[-1]


def contiguous_tensor_strides(
    shape: tuple[int, ...], dtype: str
) -> list[int]:
    if len(shape) == 1:
        return [0]
    row_bytes = logical_tensor_bytes((shape[-1],), dtype)
    strides = [0] * len(shape)
    multiplier = 1
    for dimension in range(len(shape) - 2, -1, -1):
        strides[dimension] = multiplier * row_bytes
        multiplier *= shape[dimension]
    return strides


def make_matrix_task(
    name: str,
    source: TensorInfo,
    weight: TensorInfo,
    destination: TensorInfo,
    requant: TensorInfo | None,
    *,
    m: int,
    n: int,
    k: int,
    batch_count: int = 1,
    a_batch_stride: int = 0,
    b_batch_stride: int = 0,
    c_batch_stride: int = 0,
    bias: TensorInfo | None = None,
    high_level_node: str,
) -> VirtualTask:
    common: dict[str, Any] = {
        "src0": source.name,
        "src1": weight.name,
        "dst": destination.name,
        "round_mode": "nearest_even",
        "saturate_enable": destination.dtype != "int32",
    }
    matrix: dict[str, Any] = {
        "m": m,
        "n": n,
        "k": k,
        "batch_count": batch_count,
        "lda_bytes": element_bytes(source.dtype, k),
        "ldc_bytes": element_bytes(destination.dtype, n),
        "a_batch_stride_bytes": a_batch_stride,
        "b_batch_stride_bytes": b_batch_stride,
        "c_batch_stride_bytes": c_batch_stride,
        "final_output": True,
        "overflow_mode": "saturate",
        "b_int4": source.dtype == "int8" and weight.dtype == "int4",
    }
    if weight.dtype != source.dtype and not (
        source.dtype == "int8" and weight.dtype == "int4"
    ):
        raise fail(
            f"operator {high_level_node}",
            "matrix B must match A, except INT8 A may use INT4 B",
        )
    reads = [source.name, weight.name]
    if bias is not None:
        if (
            bias.l1_addr is None
            or bias.l1_addr == 0
            or bias.l1_addr >= 256 * 1024
        ):
            raise fail(
                f"operator {high_level_node}",
                "matrix bias must use a nonzero, 64-byte-aligned L1 "
                "address below 256 KiB",
            )
        common["aux0"] = bias.name
        matrix.update(
            {
                "bias_enable": True,
                "bias_count": n,
                "bias_stride_bytes": 4,
            }
        )
        reads.append(bias.name)
    if destination.dtype != "int32":
        if requant is None:
            raise fail("lowering", f"{name} needs integer rescale metadata")
        match = re.search(r"(?:shift_|rq)([0-9]+)$", requant.name)
        if match is None:
            raise fail(
                "lowering",
                f"{name} has unsupported rescale metadata {requant.name!r}",
            )
        try:
            inline_shift = int(match.group(1))
        except ValueError as error:
            raise fail(
                "lowering",
                f"{name} has an invalid rescale shift name",
            ) from error
        common["aux1"] = requant.name
        matrix.update(
            {
                "requant_enable": True,
                "requant_mode": 1,
                "requant_shift": inline_shift,
                "requant_count": 1,
                "requant_entry_bytes": 8,
                "requant_region_bytes": requant.storage_bytes,
            }
        )
        reads.append(requant.name)
    return VirtualTask(
        name=name,
        engine="matrix",
        opcode="BMM" if batch_count > 1 else "GEMM",
        reads=tuple(reads),
        writes=(destination.name,),
        descriptor={"common": common, "matrix": matrix},
        high_level_node=high_level_node,
    )


def tiled_matrix_bytes(
    rows: int,
    columns: int,
    dtype: str,
    target: TargetConfig,
) -> int:
    elements = (
        ((rows + target.kt - 1) // target.kt)
        * ((columns + target.nt - 1) // target.nt)
        * target.kt
        * target.nt
    )
    return dtype_storage_bytes(dtype, elements)


def make_dma_copy_task(
    name: str,
    source: TensorInfo,
    destination: TensorInfo,
    *,
    source_space: str = "l1",
    destination_space: str = "l1",
    high_level_node: str = "",
    flags: Mapping[str, Any] | None = None,
) -> VirtualTask:
    elements = product(source.shape)
    if elements != product(destination.shape):
        raise fail("lowering", f"{name} source and destination sizes differ")
    return VirtualTask(
        name=name,
        engine="dma",
        opcode="COPY_1D",
        reads=(source.name,),
        writes=(destination.name,),
        descriptor={
            "common": {
                "src0": tensor_reference(source, source_space),
                "dst": tensor_reference(destination, destination_space),
            },
            "dma": {
                "rank": 1,
                "shape": [elements],
                "src_stride_bytes": [0],
                "dst_stride_bytes": [0],
                "burst_beats": 16,
                "max_outstanding": 8,
            },
        },
        flags={} if flags is None else dict(flags),
        high_level_node=high_level_node,
    )


def attention_score_scale_plan(
    score_scale: float,
    dtype: str,
    location: str,
    *,
    query_values: Sequence[int] | None = None,
    key_values: Sequence[int] | None = None,
    width: int | None = None,
    heads: int = 1,
    query_dtype: str | None = None,
    key_dtype: str | None = None,
) -> tuple[float, float | None, float | None]:
    """Represent an attention score scale with inline power-of-two fields.

    A directly representable value needs no weight change.  Otherwise the
    compiler folds the square root of the non-power-of-two factor into both
    query and key projection weights, then gives SOFTMAX an exact power-of-two
    input scale.  Symmetric scaling reduces constant re-encoding error and
    avoids rounding the complete score matrix a second time immediately
    before SOFTMAX.
    """

    if not math.isfinite(score_scale) or score_scale <= 0.0:
        raise fail(location, "must be finite and positive")
    for exponent in range(-8, 8):
        candidate = math.ldexp(1.0, exponent)
        if math.isclose(
            score_scale,
            candidate,
            rel_tol=0.0,
            abs_tol=candidate * 1.0e-7,
        ):
            return candidate, None, None
    if dtype not in ("int4", "int8", "int16"):
        raise fail(
            location,
            "non-power-of-two attention scale requires INT4, INT8, or INT16",
        )
    exponent = max(-8, min(7, math.ceil(math.log2(score_scale))))
    softmax_scale = math.ldexp(1.0, exponent)
    weight_scale = score_scale / softmax_scale
    if not (0.0 < weight_scale <= 1.0):
        raise fail(
            location,
            "cannot be represented by query-weight scaling and the inline "
            "SOFTMAX scale",
        )
    symmetric_scale = math.sqrt(weight_scale)
    if (
        query_values is None
        or key_values is None
        or width is None
    ):
        return softmax_scale, symmetric_scale, symmetric_scale
    if width <= 0 or heads <= 0 or width % heads:
        raise fail(location, "attention width must be divisible by head count")
    expected_values = width * width
    if (
        len(query_values) != expected_values
        or len(key_values) != expected_values
    ):
        raise fail(location, "query and key weights must both be width × width")
    query_kind = dtype if query_dtype is None else query_dtype
    key_kind = dtype if key_dtype is None else key_dtype
    best: tuple[tuple[float, int, float, float], float, float] | None = None
    seen: set[tuple[tuple[int, ...], tuple[int, ...]]] = set()
    for step in range(-64, 65):
        ratio = math.pow(2.0, step / 256.0)
        query_scale = symmetric_scale * ratio
        key_scale = symmetric_scale / ratio
        if query_scale > 1.0 or key_scale > 1.0:
            continue
        scaled_query = scale_integer_values(
            query_values, query_scale, query_kind
        )
        scaled_key = scale_integer_values(
            key_values, key_scale, key_kind
        )
        encoded_pair = (scaled_query, scaled_key)
        if encoded_pair in seen:
            continue
        seen.add(encoded_pair)
        squared_error = 0.0
        squared_reference = 0.0
        maximum_error = 0.0
        head_width = width // heads
        for head in range(heads):
            head_start = head * head_width
            head_end = head_start + head_width
            for query_row in range(width):
                query_base = query_row * width
                for key_row in range(width):
                    key_base = key_row * width
                    original_dot = 0
                    encoded_dot = 0
                    for column in range(head_start, head_end):
                        original_dot += (
                            query_values[query_base + column]
                            * key_values[key_base + column]
                        )
                        encoded_dot += (
                            scaled_query[query_base + column]
                            * scaled_key[key_base + column]
                        )
                    reference_dot = weight_scale * original_dot
                    error = encoded_dot - reference_dot
                    squared_error += error * error
                    squared_reference += reference_dot * reference_dot
                    maximum_error = max(maximum_error, abs(error))
        normalized_error = squared_error / max(squared_reference, 1.0)
        lost_nonzero = sum(
            1
            for original, encoded in zip(query_values, scaled_query)
            if original != 0 and encoded == 0
        ) + sum(
            1
            for original, encoded in zip(key_values, scaled_key)
            if original != 0 and encoded == 0
        )
        score = (
            normalized_error,
            lost_nonzero,
            maximum_error,
            abs(step),
        )
        candidate = (score, query_scale, key_scale)
        if best is None or candidate < best:
            best = candidate
    if best is None:
        raise fail(location, "cannot choose query and key constant scales")
    return softmax_scale, best[1], best[2]


def scale_integer_values(
    values: Sequence[int],
    scale: float,
    dtype: str,
) -> tuple[int, ...]:
    """Scale integer constants with nearest-even rounding and saturation."""

    minimum, maximum = DTYPE_LIMITS[dtype]
    return tuple(
        max(minimum, min(maximum, int(round(value * scale))))
        for value in values
    )


def lower_multi_head_attention(
    operator: OperatorInfo,
    tensors: dict[str, TensorInfo],
    allocator: AddressAllocator,
    target: TargetConfig,
    requant_by_shift: Mapping[int, str],
) -> list[VirtualTask]:
    source = tensors[operator.inputs[0]]
    weight_q, weight_k, weight_v, weight_o = (
        tensors[name] for name in operator.inputs[1:5]
    )
    output = tensors[operator.outputs[0]]
    tokens, width = source.shape
    heads = parse_int(
        operator.attributes.get("num_heads"),
        f"operator {operator.name}.num_heads",
        1,
        255,
    )
    head_width = width // heads
    dtype = source.dtype
    if dtype == "int4" and (
        width % 2 or head_width % 2 or tokens % 2
    ):
        raise fail(
            f"operator {operator.name}",
            "INT4 attention requires even width, head width and token count",
        )
    prefix = f"__{operator.name}"
    q = add_internal_tensor(
        tensors, allocator, f"{prefix}_q", source.shape, dtype
    )
    k = add_internal_tensor(
        tensors, allocator, f"{prefix}_k", source.shape, dtype
    )
    v = add_internal_tensor(
        tensors, allocator, f"{prefix}_v", source.shape, dtype
    )
    q_heads = add_internal_tensor(
        tensors,
        allocator,
        f"{prefix}_q_heads",
        (heads, tokens, head_width),
        dtype,
    )
    k_head_bytes = tiled_matrix_bytes(
        head_width, tokens, dtype, target
    )
    k_tiles = add_internal_tensor(
        tensors,
        allocator,
        f"{prefix}_k_tiles",
        (heads, head_width, tokens),
        dtype,
        storage_bytes=heads * k_head_bytes,
        alignment=256,
        layout="matrix_b",
    )
    v_head_bytes = tiled_matrix_bytes(
        tokens, head_width, dtype, target
    )
    v_tiles = add_internal_tensor(
        tensors,
        allocator,
        f"{prefix}_v_tiles",
        (heads, tokens, head_width),
        dtype,
        storage_bytes=heads * v_head_bytes,
        alignment=256,
        layout="matrix_b",
    )
    scores = add_internal_tensor(
        tensors,
        allocator,
        f"{prefix}_scores",
        (heads, tokens, tokens),
        dtype,
    )
    probabilities = add_internal_tensor(
        tensors,
        allocator,
        f"{prefix}_probabilities",
        (heads, tokens, tokens),
        dtype,
    )
    attention_heads = add_internal_tensor(
        tensors,
        allocator,
        f"{prefix}_attention_heads",
        (heads, tokens, head_width),
        dtype,
    )
    concatenated = add_internal_tensor(
        tensors,
        allocator,
        f"{prefix}_concatenated",
        (tokens, width),
        dtype,
    )
    projection_shift = parse_int(
        operator.attributes.get("projection_shift", 0),
        f"operator {operator.name}.projection_shift",
        0,
        31,
    )
    score_shift = parse_int(
        operator.attributes.get("score_shift", 0),
        f"operator {operator.name}.score_shift",
        0,
        31,
    )
    value_shift = parse_int(
        operator.attributes.get("value_shift", 2),
        f"operator {operator.name}.value_shift",
        0,
        31,
    )
    output_shift = parse_int(
        operator.attributes.get("output_shift", 0),
        f"operator {operator.name}.output_shift",
        0,
        31,
    )
    projection_requant = tensors[requant_by_shift[projection_shift]]
    score_requant = tensors[requant_by_shift[score_shift]]
    value_requant = tensors[requant_by_shift[value_shift]]
    output_requant = tensors[requant_by_shift[output_shift]]
    tasks: list[VirtualTask] = [
        make_matrix_task(
            f"{operator.name}_q_projection",
            source,
            weight_q,
            q,
            projection_requant,
            m=tokens,
            n=width,
            k=width,
            high_level_node=operator.name,
        ),
        make_matrix_task(
            f"{operator.name}_k_projection",
            source,
            weight_k,
            k,
            projection_requant,
            m=tokens,
            n=width,
            k=width,
            high_level_node=operator.name,
        ),
        make_matrix_task(
            f"{operator.name}_v_projection",
            source,
            weight_v,
            v,
            projection_requant,
            m=tokens,
            n=width,
            k=width,
            high_level_node=operator.name,
        ),
    ]

    element_size = element_bytes(dtype)
    head_row_bytes = element_bytes(dtype, head_width)
    full_row_bytes = element_bytes(dtype, width)
    token_row_bytes = element_bytes(dtype, tokens)
    q_previous: str | None = None
    k_previous: str | None = None
    v_previous: str | None = None
    for head in range(heads):
        q_name = f"{operator.name}_pack_q_head_{head}"
        q_task = VirtualTask(
            name=q_name,
            engine="dma",
            opcode="PACK",
            reads=(q.name,),
            writes=(q_heads.name,),
            descriptor={
                "common": {
                    "src0": {
                        "addr": q.l1_addr + head * head_row_bytes,
                        "space": "l1",
                        "dtype": dtype,
                        "region_bytes": (
                            q.storage_bytes - head * head_row_bytes
                        ),
                    },
                    "dst": {
                        "addr": (
                            q_heads.l1_addr
                            + head * tokens * head_row_bytes
                        ),
                        "space": "l1",
                        "dtype": dtype,
                        "region_bytes": tokens * head_row_bytes,
                    },
                },
                "dma": {
                    "rank": 1,
                    "shape": [tokens],
                    "src_stride_bytes": [0],
                    "dst_stride_bytes": [0],
                    "segment_count": tokens,
                    "segment_bytes": head_row_bytes,
                    "segment_stride": full_row_bytes,
                    "burst_beats": 16,
                    "max_outstanding": 8,
                },
            },
            extra_after=() if q_previous is None else (q_previous,),
            high_level_node=operator.name,
        )
        tasks.append(q_task)
        q_previous = q_name

        k_name = f"{operator.name}_transpose_k_head_{head}"
        k_task = VirtualTask(
            name=k_name,
            engine="dma",
            opcode="TRANSPOSE_2D",
            reads=(k.name,),
            writes=(k_tiles.name,),
            descriptor={
                "common": {
                    "src0": {
                        "addr": k.l1_addr + head * head_row_bytes,
                        "space": "l1",
                        "dtype": dtype,
                        "region_bytes": (
                            k.storage_bytes - head * head_row_bytes
                        ),
                    },
                    "dst": {
                        "addr": k_tiles.l1_addr + head * k_head_bytes,
                        "space": "l1",
                        "dtype": dtype,
                        "region_bytes": k_head_bytes,
                    },
                },
                "dma": {
                    "rank": 2,
                    "shape": [tokens, head_width],
                    "src_stride_bytes": [full_row_bytes, 0],
                    "dst_stride_bytes": [
                        element_bytes(dtype, target.nt),
                        0,
                    ],
                    "burst_beats": 16,
                    "max_outstanding": 8,
                },
            },
            extra_after=() if k_previous is None else (k_previous,),
            high_level_node=operator.name,
        )
        tasks.append(k_task)
        k_previous = k_name

        v_name = f"{operator.name}_tile_v_head_{head}"
        v_task = VirtualTask(
            name=v_name,
            engine="dma",
            opcode="COPY_ND",
            reads=(v.name,),
            writes=(v_tiles.name,),
            descriptor={
                "common": {
                    "src0": {
                        "addr": v.l1_addr + head * head_row_bytes,
                        "space": "l1",
                        "dtype": dtype,
                        "region_bytes": (
                            v.storage_bytes - head * head_row_bytes
                        ),
                    },
                    "dst": {
                        "addr": v_tiles.l1_addr + head * v_head_bytes,
                        "space": "l1",
                        "dtype": dtype,
                        "region_bytes": v_head_bytes,
                    },
                },
                "dma": {
                    "rank": 2,
                    "shape": [tokens, head_width],
                    "src_stride_bytes": [full_row_bytes, 0],
                    "dst_stride_bytes": [
                        element_bytes(dtype, target.nt),
                        0,
                    ],
                    "burst_beats": 16,
                    "max_outstanding": 8,
                },
            },
            extra_after=() if v_previous is None else (v_previous,),
            high_level_node=operator.name,
        )
        tasks.append(v_task)
        v_previous = v_name

    qk = make_matrix_task(
        f"{operator.name}_qk",
        q_heads,
        k_tiles,
        scores,
        score_requant,
        m=tokens,
        n=tokens,
        k=head_width,
        batch_count=heads,
        a_batch_stride=tokens * head_row_bytes,
        b_batch_stride=k_head_bytes,
        c_batch_stride=tokens * token_row_bytes,
        high_level_node=operator.name,
    )
    qk.extra_after = tuple(
        name for name in (q_previous, k_previous) if name is not None
    )
    tasks.append(qk)

    rows = heads * tokens
    requested_score_scale = parse_float(
        operator.attributes.get("score_scale", 1.0),
        f"operator {operator.name}.score_scale",
    )
    (
        softmax_input_scale,
        _query_weight_scale,
        _key_weight_scale,
    ) = attention_score_scale_plan(
        requested_score_scale,
        dtype,
        f"operator {operator.name}.score_scale",
    )

    softmax_scale = parse_float(
        operator.attributes.get("softmax_output_scale", 0.25),
        f"operator {operator.name}.softmax_output_scale",
    )
    tasks.append(
        VirtualTask(
            name=f"{operator.name}_softmax",
            engine="complex",
            opcode="SOFTMAX",
            reads=(scores.name,),
            writes=(probabilities.name,),
            descriptor={
                "common": {
                    "src0": scores.name,
                    "dst": probabilities.name,
                    "round_mode": "nearest_even",
                    "saturate_enable": True,
                    "scale_mode": "per_tensor",
                    "internal_fp32_enable": True,
                },
                "complex": {
                    "rows": rows,
                    "length": tokens,
                    "valid_length": tokens,
                    "function": "softmax",
                    "src0_row_stride_bytes": token_row_bytes,
                    "dst_row_stride_bytes": token_row_bytes,
                    "src0_scale": softmax_input_scale,
                    "src1_scale": 0.0,
                    "src2_scale": 0.0,
                    "dst_scale": softmax_scale,
                    "epsilon": 0.0,
                    "input_clip_min": -16.0,
                    "input_clip_max": 16.0,
                    "scratch_request_elems": tokens,
                },
            },
            high_level_node=operator.name,
        )
    )
    attention_value = make_matrix_task(
        f"{operator.name}_attention_value",
        probabilities,
        v_tiles,
        attention_heads,
        value_requant,
        m=tokens,
        n=head_width,
        k=tokens,
        batch_count=heads,
        a_batch_stride=tokens * token_row_bytes,
        b_batch_stride=v_head_bytes,
        c_batch_stride=tokens * head_row_bytes,
        high_level_node=operator.name,
    )
    if v_previous is not None:
        attention_value.extra_after = (v_previous,)
    tasks.append(attention_value)

    concat_previous: str | None = None
    for head in range(heads):
        concat_name = f"{operator.name}_concat_head_{head}"
        concat = VirtualTask(
            name=concat_name,
            engine="dma",
            opcode="SPLIT",
            reads=(attention_heads.name,),
            writes=(concatenated.name,),
            descriptor={
                "common": {
                    "src0": {
                        "addr": (
                            attention_heads.l1_addr
                            + head * tokens * head_row_bytes
                        ),
                        "space": "l1",
                        "dtype": dtype,
                        "region_bytes": tokens * head_row_bytes,
                    },
                    "dst": {
                        "addr": concatenated.l1_addr + head * head_row_bytes,
                        "space": "l1",
                        "dtype": dtype,
                        "region_bytes": (
                            concatenated.storage_bytes
                            - head * head_row_bytes
                        ),
                    },
                },
                "dma": {
                    "rank": 1,
                    "shape": [tokens],
                    "src_stride_bytes": [0],
                    "dst_stride_bytes": [0],
                    "segment_count": tokens,
                    "segment_bytes": head_row_bytes,
                    "segment_stride": full_row_bytes,
                    "burst_beats": 16,
                    "max_outstanding": 8,
                },
            },
            extra_after=(
                (concat_previous,) if concat_previous is not None else ()
            ),
            high_level_node=operator.name,
        )
        tasks.append(concat)
        concat_previous = concat_name

    projection = make_matrix_task(
        f"{operator.name}_output_projection",
        concatenated,
        weight_o,
        output,
        output_requant,
        m=tokens,
        n=width,
        k=width,
        high_level_node=operator.name,
    )
    if concat_previous is not None:
        projection.extra_after = (concat_previous,)
    tasks.append(projection)
    return tasks


def lower_conv2d_operator(
    operator: OperatorInfo,
    tensors: dict[str, TensorInfo],
    allocator: AddressAllocator,
    target: TargetConfig,
    requant_by_shift: Mapping[int, str],
) -> list[VirtualTask]:
    source = tensors[operator.inputs[0]]
    kernel = tensors[operator.inputs[1]]
    output = tensors[operator.outputs[0]]
    bias = tensors[operator.inputs[2]] if len(operator.inputs) == 3 else None
    try:
        geometry = conv_lowering.infer_conv2d(
            source.shape,
            kernel.shape,
            {
                key: value
                for key, value in operator.attributes.items()
                if key
                in {
                    "strides",
                    "dilations",
                    "padding",
                    "groups",
                    "data_format",
                }
            },
        )
    except conv_lowering.ConvLoweringError as error:
        raise fail(f"operator {operator.name}", str(error)) from error
    im2col = add_internal_tensor(
        tensors,
        allocator,
        f"__{operator.name}_im2col",
        geometry.im2col_shape,
        source.dtype,
    )
    shift = parse_int(
        operator.attributes.get("output_shift", 0),
        f"operator {operator.name}.output_shift",
        0,
        31,
    )
    requant = None if output.dtype == "int32" else tensors[requant_by_shift[shift]]

    def placement(tensor: TensorInfo) -> conv_lowering.TensorPlacement:
        if tensor.l1_addr is None:
            raise fail("lowering", f"{tensor.name} has no L1 address")
        return conv_lowering.TensorPlacement(
            name=tensor.name,
            addr=tensor.l1_addr,
            region_bytes=tensor.storage_bytes,
            space="l1",
            dtype=tensor.dtype,
        )

    try:
        lowered = conv_lowering.lower_conv2d(
            operator.name,
            source.shape,
            kernel.shape,
            placement(source),
            placement(im2col),
            placement(kernel),
            placement(output),
            strides=geometry.strides,
            dilations=geometry.dilations,
            padding=geometry.padding,
            groups=1,
            kernel_values=kernel.data,
            bias_tensor=None if bias is None else placement(bias),
            requant_tensor=None if requant is None else placement(requant),
        )
    except conv_lowering.ConvLoweringError as error:
        raise fail(f"operator {operator.name}", str(error)) from error

    result: list[VirtualTask] = []
    for raw in lowered.operations:
        engine = str(raw["engine"])
        opcode = str(raw["opcode"])
        descriptor = dict(raw["descriptor"])
        if opcode == "FILL":
            reads: tuple[str, ...] = ()
            writes = (im2col.name,)
        elif engine == "dma":
            reads = (source.name,)
            writes = (im2col.name,)
        else:
            matrix_fields = dict(
                as_object(
                    descriptor.get("matrix", {}),
                    f"operator {operator.name}.matrix",
                )
            )
            matrix_fields["requant_shift"] = (
                0 if output.dtype == "int32" else shift
            )
            descriptor["matrix"] = matrix_fields
            values = [im2col.name, kernel.name]
            if bias is not None:
                values.append(bias.name)
            if requant is not None:
                values.append(requant.name)
            reads = tuple(values)
            writes = (output.name,)
        result.append(
            VirtualTask(
                name=str(raw["name"]),
                engine=engine,
                opcode=opcode,
                reads=reads,
                writes=writes,
                descriptor=descriptor,
                extra_after=tuple(raw.get("depends_on", [])),
                high_level_node=operator.name,
            )
        )
    if any(task.opcode.upper().startswith("CONV") for task in result):
        raise fail(
            f"operator {operator.name}",
            "Conv2D lowering emitted an unsupported convolution opcode",
        )
    return result


def lower_simple_operator(
    operator: OperatorInfo,
    tensors: dict[str, TensorInfo],
    allocator: AddressAllocator,
    target: TargetConfig,
    requant_by_shift: Mapping[int, str],
) -> list[VirtualTask]:
    kind = operator.op_type.lower()
    sources = [tensors[name] for name in operator.inputs]
    destination = tensors[operator.outputs[0]]

    if kind in ("matmul", "linear"):
        left, right = sources
        shift = parse_int(
            operator.attributes.get("output_shift", 0),
            f"operator {operator.name}.output_shift",
            0,
            31,
        )
        return [
            make_matrix_task(
                operator.name,
                left,
                right,
                destination,
                (
                    None
                    if destination.dtype == "int32"
                    else tensors[requant_by_shift[shift]]
                ),
                m=left.shape[0],
                n=right.shape[1],
                k=left.shape[1],
                high_level_node=operator.name,
            )
        ]

    if kind == "add":
        left, right = sources
        scalar: int | None = None
        feature = False
        if product(left.shape) == 1 and left.data is not None:
            scalar = left.data[0]
            left, right = right, left
        elif product(right.shape) == 1 and right.data is not None:
            scalar = right.data[0]
        elif (
            left.shape != destination.shape
            and left.shape[-1] == destination.shape[-1]
            and product(left.shape) == destination.shape[-1]
        ):
            left, right = right, left
            feature = True
        elif (
            right.shape != destination.shape
            and right.shape[-1] == destination.shape[-1]
            and product(right.shape) == destination.shape[-1]
        ):
            feature = True
        rows, length = vector_dimensions(destination.shape)
        element_stride = 0 if destination.dtype == "int4" else element_bytes(
            destination.dtype
        )
        row_stride = logical_tensor_bytes(
            (destination.shape[-1],), destination.dtype
        )
        common: dict[str, Any] = {
            "src0": left.name,
            "dst": destination.name,
            "saturate_enable": True,
            "scale_mode": "per_tensor",
        }
        vector: dict[str, Any] = {
            "rows": rows,
            "length": length,
            "valid_length": length,
            "src0_elem_stride_bytes": element_stride,
            "src0_row_stride_bytes": row_stride,
            "dst_elem_stride_bytes": element_stride,
            "dst_row_stride_bytes": row_stride,
            "src2_scale_bits": 0,
        }
        reads = [left.name]
        if scalar is None:
            common["src1"] = right.name
            vector.update(
                {
                    "src1_elem_stride_bytes": element_stride,
                    "src1_row_stride_bytes": (
                        logical_tensor_bytes(
                            (destination.shape[-1],), destination.dtype
                        )
                        if feature
                        else row_stride
                    ),
                }
            )
            if feature:
                vector["broadcast1"] = "feature"
            reads.append(right.name)
        else:
            common["src1"] = right.name
            vector["broadcast1"] = "scalar"
            vector["src1_elem_stride_bytes"] = element_stride
            vector["src1_row_stride_bytes"] = 0
            reads.append(right.name)
        if "scale" in operator.attributes:
            scale = parse_float(
                operator.attributes["scale"],
                f"operator {operator.name}.scale",
            )
            if scale <= 0.0:
                raise fail(
                    f"operator {operator.name}.scale",
                    "must be positive",
                )
            bits = float_bits(scale)
            vector["src0_scale_bits"] = bits
            vector["src1_scale_bits"] = bits
            vector["dst_scale_bits"] = bits
        return [
            VirtualTask(
                name=operator.name,
                engine="vector",
                opcode="ADD",
                reads=tuple(reads),
                writes=(destination.name,),
                descriptor={"common": common, "vector": vector},
                high_level_node=operator.name,
            )
        ]

    if kind == "relu":
        source = sources[0]
        rows, length = vector_dimensions(source.shape)
        element_stride = 0 if source.dtype == "int4" else element_bytes(
            source.dtype
        )
        row_stride = logical_tensor_bytes((length,), source.dtype)
        vector: dict[str, Any] = {
            "rows": rows,
            "length": length,
            "valid_length": length,
            "src0_elem_stride_bytes": element_stride,
            "src0_row_stride_bytes": row_stride,
            "dst_elem_stride_bytes": element_stride,
            "dst_row_stride_bytes": row_stride,
            "src1_scale_bits": 0,
            "src2_scale_bits": 0,
        }
        if "scale" in operator.attributes:
            scale = parse_float(
                operator.attributes["scale"],
                f"operator {operator.name}.scale",
            )
            if scale <= 0.0:
                raise fail(
                    f"operator {operator.name}.scale",
                    "must be positive",
                )
            bits = float_bits(scale)
            vector["src0_scale_bits"] = bits
            vector["dst_scale_bits"] = bits
        return [
            VirtualTask(
                name=operator.name,
                engine="vector",
                opcode="RELU",
                reads=(source.name,),
                writes=(destination.name,),
                descriptor={
                    "common": {
                        "src0": source.name,
                        "dst": destination.name,
                        "saturate_enable": True,
                        "scale_mode": "per_tensor",
                    },
                    "vector": vector,
                },
                high_level_node=operator.name,
            )
        ]

    if kind in (
        "softmax",
        "gelu",
        "sigmoid",
        "tanh",
        "silu",
        "layernorm",
    ):
        source = sources[0]
        rows, length = vector_dimensions(source.shape)
        row_stride = logical_tensor_bytes((length,), source.dtype)
        function = {
            "softmax": "softmax",
            "gelu": "gelu",
            "sigmoid": "sigmoid",
            "tanh": "tanh",
            "silu": "silu",
            "layernorm": "layernorm",
        }[kind]
        common: dict[str, Any] = {
            "src0": source.name,
            "dst": destination.name,
            "round_mode": "nearest_even",
            "saturate_enable": True,
            "scale_mode": "per_tensor",
            "internal_fp32_enable": True,
        }
        reads = [source.name]
        if kind == "layernorm":
            common["src1"] = sources[1].name
            common["src2"] = sources[2].name
            reads.extend((sources[1].name, sources[2].name))
        complex_fields = {
            "rows": rows,
            "length": length,
            "valid_length": length,
            "function": function,
            "src0_row_stride_bytes": row_stride,
            "src1_row_stride_bytes": 0,
            "src2_row_stride_bytes": 0,
            "dst_row_stride_bytes": row_stride,
            "src0_scale": parse_float(
                operator.attributes.get("input_scale", 1.0),
                f"operator {operator.name}.input_scale",
            ),
            "src1_scale": (
                parse_float(
                    operator.attributes.get("gamma_scale", 1.0),
                    f"operator {operator.name}.gamma_scale",
                )
                if kind == "layernorm"
                else 0.0
            ),
            "src2_scale": (
                parse_float(
                    operator.attributes.get("beta_scale", 1.0),
                    f"operator {operator.name}.beta_scale",
                )
                if kind == "layernorm"
                else 0.0
            ),
            "dst_scale": parse_float(
                operator.attributes.get("output_scale", 1.0),
                f"operator {operator.name}.output_scale",
            ),
            "epsilon": (
                parse_float(
                    operator.attributes.get("epsilon", 1e-5),
                    f"operator {operator.name}.epsilon",
                )
                if kind == "layernorm"
                else 0.0
            ),
            "input_clip_min": (
                0.0
                if kind == "layernorm"
                else parse_float(
                    operator.attributes.get("clip_min", -16.0),
                    f"operator {operator.name}.clip_min",
                )
            ),
            "input_clip_max": (
                0.0
                if kind == "layernorm"
                else parse_float(
                    operator.attributes.get("clip_max", 16.0),
                    f"operator {operator.name}.clip_max",
                )
            ),
            "scratch_request_elems": (
                length if kind in ("softmax", "layernorm") else 0
            ),
        }
        return [
            VirtualTask(
                name=operator.name,
                engine="complex",
                opcode="SOFTMAX" if kind == "softmax" else (
                    "NORM" if kind == "layernorm" else "ACT"
                ),
                reads=tuple(reads),
                writes=(destination.name,),
                descriptor={
                    "common": common,
                    "complex": complex_fields,
                },
                high_level_node=operator.name,
            )
        ]

    if kind == "reshape":
        source = sources[0]
        if source.dtype == "int4" and (
            source.shape[-1] % 2 or destination.shape[-1] % 2
        ):
            raise fail(
                f"operator {operator.name}",
                "INT4 Reshape requires byte-aligned source and destination rows",
            )
        return [
            make_dma_copy_task(
                operator.name,
                source,
                destination,
                high_level_node=operator.name,
            )
        ]

    if kind == "transpose":
        source = sources[0]
        perm = tuple(operator.attributes["_perm"])
        if len(source.shape) != 2 or perm != (1, 0):
            raise fail(
                f"operator {operator.name}",
                "device Transpose currently supports rank-2 perm [1,0]",
            )
        source_row = logical_tensor_bytes((source.shape[1],), source.dtype)
        destination_row = logical_tensor_bytes(
            (source.shape[0],), source.dtype
        )
        return [
            VirtualTask(
                name=operator.name,
                engine="dma",
                opcode="TRANSPOSE_2D",
                reads=(source.name,),
                writes=(destination.name,),
                descriptor={
                    "common": {
                        "src0": source.name,
                        "dst": destination.name,
                    },
                    "dma": {
                        "rank": 2,
                        "shape": list(source.shape),
                        "src_stride_bytes": [source_row, 0],
                        "dst_stride_bytes": [destination_row, 0],
                        "burst_beats": 16,
                        "max_outstanding": 8,
                    },
                },
                high_level_node=operator.name,
            )
        ]

    if kind == "concat":
        axis = int(operator.attributes["_axis"])
        if axis != len(destination.shape) - 1:
            raise fail(
                f"operator {operator.name}",
                "device Concat currently supports the last axis",
            )
        rows = product(destination.shape[:-1])
        destination_row = logical_tensor_bytes(
            (destination.shape[-1],), destination.dtype
        )
        result: list[VirtualTask] = []
        column_offset = 0
        previous: str | None = None
        for index, source in enumerate(sources):
            source_row = logical_tensor_bytes(
                (source.shape[-1],), source.dtype
            )
            destination_offset = element_byte_offset(
                column_offset, destination.dtype
            )
            name = f"{operator.name}_part_{index}"
            result.append(
                VirtualTask(
                    name=name,
                    engine="dma",
                    opcode="COPY_ND",
                    reads=(source.name,),
                    writes=(destination.name,),
                    descriptor={
                        "common": {
                            "src0": source.name,
                            "dst": {
                                "addr": destination.l1_addr
                                + destination_offset,
                                "space": "l1",
                                "dtype": destination.dtype,
                                "region_bytes": (
                                    destination.storage_bytes
                                    - destination_offset
                                ),
                            },
                        },
                        "dma": {
                            "rank": 2,
                            "shape": [rows, source.shape[-1]],
                            "src_stride_bytes": [source_row, 0],
                            "dst_stride_bytes": [destination_row, 0],
                            "burst_beats": 16,
                            "max_outstanding": 8,
                        },
                    },
                    extra_after=() if previous is None else (previous,),
                    high_level_node=operator.name,
                )
            )
            previous = name
            column_offset += source.shape[-1]
        return result

    if kind == "multiheadattention":
        return lower_multi_head_attention(
            operator, tensors, allocator, target, requant_by_shift
        )
    if kind == "conv2d":
        return lower_conv2d_operator(
            operator, tensors, allocator, target, requant_by_shift
        )
    raise fail(
        f"operator {operator.name}",
        f"lowering is not implemented for {operator.op_type}",
    )


def constant_block_bases(
    tensors: Mapping[str, TensorInfo],
    arena: ConstantArena,
) -> tuple[int, int]:
    for name, (offset, _size, _dtype, _layout) in arena.entries.items():
        tensor = tensors[name]
        assert tensor.l1_addr is not None and tensor.ddr_addr is not None
        return tensor.l1_addr - offset, tensor.ddr_addr - offset
    raise fail("constants", "constant arena has no entries")


def lower_model_tasks(
    tensors: dict[str, TensorInfo],
    operators: Sequence[OperatorInfo],
    outputs: Sequence[str],
    allocator: AddressAllocator,
    target: TargetConfig,
    arena: ConstantArena,
    constant_image: bytes,
    requant_by_shift: Mapping[int, str],
) -> list[VirtualTask]:
    constant_l1, constant_ddr = constant_block_bases(tensors, arena)
    constant_names = tuple(arena.entries)
    tasks: list[VirtualTask] = [
        VirtualTask(
            name="__load_constants",
            engine="dma",
            opcode="COPY_1D",
            reads=("__constant_image_ddr",),
            writes=constant_names,
            descriptor={
                "common": {
                    "src0": {
                        "addr": constant_ddr,
                        "space": "ddr",
                        "dtype": "int8",
                        "region_bytes": len(constant_image),
                    },
                    "dst": {
                        "addr": constant_l1,
                        "space": "l1",
                        "dtype": "int8",
                        "region_bytes": len(constant_image),
                    },
                },
                "dma": {
                    "rank": 1,
                    "shape": [len(constant_image)],
                    "src_stride_bytes": [0],
                    "dst_stride_bytes": [0],
                    "burst_beats": 16,
                    "max_outstanding": 8,
                },
            },
            high_level_node="__runtime",
        )
    ]
    for tensor in list(tensors.values()):
        if tensor.kind != "input":
            continue
        if tensor.ddr_addr is None:
            raise fail("lowering", f"input {tensor.name} has no DDR address")
        tasks.append(
            VirtualTask(
                name=f"__load_input_{tensor.name}",
                engine="dma",
                opcode="COPY_1D" if len(tensor.shape) == 1 else "COPY_ND",
                reads=(f"__host_{tensor.name}",),
                writes=(tensor.name,),
                descriptor={
                    "common": {
                        "src0": tensor_reference(tensor, "ddr"),
                        "dst": tensor_reference(tensor, "l1"),
                    },
                    "dma": {
                        "rank": len(tensor.shape),
                        "shape": list(tensor.shape),
                        "src_stride_bytes": contiguous_tensor_strides(
                            tensor.shape, tensor.dtype
                        ),
                        "dst_stride_bytes": contiguous_tensor_strides(
                            tensor.shape, tensor.dtype
                        ),
                        "burst_beats": 16,
                        "max_outstanding": 8,
                    },
                },
                high_level_node="__runtime",
            )
        )
    for operator in operators:
        tasks.extend(
            lower_simple_operator(
                operator, tensors, allocator, target, requant_by_shift
            )
        )
    for index, name in enumerate(outputs):
        tensor = tensors[name]
        if tensor.ddr_addr is None:
            raise fail("lowering", f"output {name} has no DDR address")
        tasks.append(
            VirtualTask(
                name=f"__store_output_{name}",
                engine="dma",
                opcode="COPY_1D" if len(tensor.shape) == 1 else "COPY_ND",
                reads=(name,),
                writes=(f"__host_{name}",),
                descriptor={
                    "common": {
                        "src0": tensor_reference(tensor, "l1"),
                        "dst": tensor_reference(tensor, "ddr"),
                    },
                    "dma": {
                        "rank": len(tensor.shape),
                        "shape": list(tensor.shape),
                        "src_stride_bytes": contiguous_tensor_strides(
                            tensor.shape, tensor.dtype
                        ),
                        "dst_stride_bytes": contiguous_tensor_strides(
                            tensor.shape, tensor.dtype
                        ),
                        "burst_beats": 16,
                        "max_outstanding": 8,
                    },
                },
                flags={
                    "irq_on_success": index == len(outputs) - 1,
                    "irq_on_error": index == len(outputs) - 1,
                },
                high_level_node="__runtime",
            )
        )
    return tasks


def storage_root(name: str, tensors: Mapping[str, TensorInfo]) -> str:
    visited: set[str] = set()
    current = name
    while current in tensors and tensors[current].alias_of is not None:
        if current in visited:
            raise fail("lowering", f"alias cycle involving {name!r}")
        visited.add(current)
        alias = tensors[current].alias_of
        assert alias is not None
        current = alias
    if current in tensors and tensors[current].storage_id is not None:
        return f"storage:{tensors[current].storage_id}"
    return current


def task_dependencies(
    tasks: Sequence[VirtualTask],
    tensors: Mapping[str, TensorInfo],
) -> dict[str, tuple[str, ...]]:
    names: set[str] = set()
    dependencies: dict[str, tuple[str, ...]] = {}
    last_writer: dict[str, str] = {}
    readers: dict[str, set[str]] = {}
    for task in tasks:
        if task.name in names:
            raise fail("lowering", f"duplicate task name {task.name!r}")
        names.add(task.name)
        ordered: list[str] = []

        def add_dependency(name: str | None) -> None:
            if name is not None and name != task.name and name not in ordered:
                ordered.append(name)

        for name in task.extra_after:
            if name not in names:
                raise fail(
                    f"task {task.name}",
                    f"extra dependency {name!r} is not an earlier task",
                )
            add_dependency(name)
        read_roots = {
            storage_root(name, tensors) for name in task.reads
        }
        write_roots = {
            storage_root(name, tensors) for name in task.writes
        }
        # Tensor names are converted to storage identifiers above.  Iterating a
        # set directly would make dependency order depend on Python's hash seed,
        # which in turn changes EVENT_JOIN placement and the emitted binaries.
        for root in sorted(read_roots | write_roots):
            add_dependency(last_writer.get(root))
        for root in sorted(write_roots):
            for reader in sorted(readers.get(root, set())):
                add_dependency(reader)

        dependencies[task.name] = tuple(ordered)
        for root in sorted(write_roots):
            last_writer[root] = task.name
            readers[root] = set()
        for root in sorted(read_roots - write_roots):
            readers.setdefault(root, set()).add(task.name)
    return dependencies


def expand_dependency_joins(
    tasks: Sequence[VirtualTask],
    dependencies: Mapping[str, tuple[str, ...]],
) -> tuple[list[VirtualTask], dict[str, tuple[str, ...]]]:
    expanded: list[VirtualTask] = []
    result_dependencies: dict[str, tuple[str, ...]] = {}
    used_names = {task.name for task in tasks}
    join_index = 0
    for task in tasks:
        values = list(dependencies[task.name])
        while len(values) > 2:
            first = values.pop(0)
            second = values.pop(0)
            while True:
                join_name = f"__event_join_{join_index}"
                join_index += 1
                if join_name not in used_names:
                    break
            used_names.add(join_name)
            join = VirtualTask(
                name=join_name,
                engine="control",
                opcode="EVENT_JOIN",
                reads=(),
                writes=(),
                descriptor={},
                high_level_node="__scheduler",
            )
            expanded.append(join)
            result_dependencies[join_name] = (first, second)
            values.insert(0, join_name)
        expanded.append(task)
        result_dependencies[task.name] = tuple(values)
    return expanded, result_dependencies


def event_object(event_id: int) -> dict[str, int]:
    return {"id": event_id, "generation": 0}


def _task_tensor_reference(
    value: Any,
    tensors: Mapping[str, TensorInfo],
    location: str,
) -> dict[str, Any]:
    if isinstance(value, str):
        if value not in tensors:
            raise fail(location, f"unknown tensor {value!r}")
        return tensor_reference(tensors[value], "l1")
    record = dict(as_object(value, location))
    if "addr" not in record or "dtype" not in record:
        raise fail(location, "tensor reference needs addr and dtype")
    record.setdefault("space", "l1")
    return record


def _outer_indices(shape: Sequence[int]) -> Iterable[tuple[int, ...]]:
    count = product(shape)
    for linear in range(count):
        remainder = linear
        result = [0] * len(shape)
        for axis in range(len(shape) - 1, -1, -1):
            result[axis] = remainder % shape[axis]
            remainder //= shape[axis]
        yield tuple(result)


def expand_inline_dma_copy_nd(
    task: VirtualTask,
    tensors: Mapping[str, TensorInfo],
) -> list[VirtualTask]:
    """Split a strided COPY_ND into compact COPY_1D row operations."""

    dma = as_object(task.descriptor.get("dma", {}), f"task {task.name}.dma")
    shape = tuple(
        parse_int(value, f"task {task.name}.shape[{index}]", 1, 0xFFFFFFFF)
        for index, value in enumerate(as_list(dma.get("shape"), f"task {task.name}.shape"))
    )
    rank = parse_int(dma.get("rank", len(shape)), f"task {task.name}.rank", 1, 5)
    if rank != len(shape):
        raise fail(f"task {task.name}.rank", "must equal the shape rank")
    if rank == 1:
        return [task]
    src_strides = tuple(
        parse_int(value, f"task {task.name}.src_stride_bytes[{index}]", 0)
        for index, value in enumerate(
            as_list(dma.get("src_stride_bytes"), f"task {task.name}.src_stride_bytes")
        )
    )
    dst_strides = tuple(
        parse_int(value, f"task {task.name}.dst_stride_bytes[{index}]", 0)
        for index, value in enumerate(
            as_list(dma.get("dst_stride_bytes"), f"task {task.name}.dst_stride_bytes")
        )
    )
    if len(src_strides) != rank or len(dst_strides) != rank:
        raise fail(
            f"task {task.name}",
            "COPY_ND stride arrays must have one entry per dimension",
        )
    common = as_object(task.descriptor.get("common", {}), f"task {task.name}.common")
    source = _task_tensor_reference(
        common.get("src0"), tensors, f"task {task.name}.src0"
    )
    destination = _task_tensor_reference(
        common.get("dst"), tensors, f"task {task.name}.dst"
    )
    if source["dtype"] != destination["dtype"]:
        raise fail(
            f"task {task.name}",
            "strided COPY_ND with dtype conversion must be lowered explicitly",
        )
    result: list[VirtualTask] = []
    previous: str | None = None
    for row_index, indices in enumerate(_outer_indices(shape[:-1])):
        source_offset = sum(
            index * src_strides[axis] for axis, index in enumerate(indices)
        )
        destination_offset = sum(
            index * dst_strides[axis] for axis, index in enumerate(indices)
        )
        name = f"{task.name}__row_{row_index}"
        source_ref = dict(source)
        destination_ref = dict(destination)
        source_ref["addr"] = int(source["addr"]) + source_offset
        destination_ref["addr"] = int(destination["addr"]) + destination_offset
        row_dma = {
            "rank": 1,
            "shape": [shape[-1]],
            "src_stride_bytes": [0],
            "dst_stride_bytes": [0],
            "src_nibble": dma.get("src_nibble", 0),
            "dst_nibble": dma.get("dst_nibble", 0),
        }
        dependencies = task.extra_after if previous is None else (previous,)
        result.append(
            VirtualTask(
                name=name,
                engine="dma",
                opcode="COPY_1D",
                reads=task.reads,
                writes=task.writes,
                descriptor={
                    "common": {"src0": source_ref, "dst": destination_ref},
                    "dma": row_dma,
                },
                flags=task.flags if row_index == product(shape[:-1]) - 1 else {},
                extra_after=dependencies,
                high_level_node=task.high_level_node,
            )
        )
        previous = name
    return result


def _vector_chunk_reference(
    value: Any,
    tensors: Mapping[str, TensorInfo],
    *,
    broadcast: str,
    row: int,
    feature: int,
    full_length: int,
    location: str,
) -> dict[str, Any]:
    reference = _task_tensor_reference(value, tensors, location)
    dtype = str(reference["dtype"]).lower()
    if dtype not in DTYPE_BITS:
        raise fail(f"{location}.dtype", "must be an integer NPU dtype")
    if broadcast == "none":
        element_offset = row * full_length + feature
    elif broadcast == "scalar":
        element_offset = 0
    elif broadcast == "row":
        element_offset = row
    elif broadcast == "feature":
        element_offset = feature
    else:
        raise fail(location, f"unsupported vector broadcast {broadcast!r}")
    bit_offset = element_offset * DTYPE_BITS[dtype]
    if bit_offset % 8:
        raise fail(
            location,
            "vector chunk begins in the middle of a byte",
        )
    byte_offset = bit_offset // 8
    reference["addr"] = int(reference["addr"]) + byte_offset
    if int(reference["addr"]) & 0xF:
        raise fail(
            f"{location}.addr",
            "vector chunk address must remain 16-byte aligned",
        )
    if "region_bytes" in reference:
        reference["region_bytes"] = max(
            0, int(reference["region_bytes"]) - byte_offset
        )
    return reference


def expand_inline_vector_task(
    task: VirtualTask,
    tensors: Mapping[str, TensorInfo],
) -> list[VirtualTask]:
    """Split oversized vector work into addressable inline chunks."""

    vector = dict(
        as_object(task.descriptor.get("vector", {}), f"task {task.name}.vector")
    )
    rows = parse_int(vector.get("rows"), f"task {task.name}.rows", 1)
    length = parse_int(vector.get("length"), f"task {task.name}.length", 1)
    if rows <= 32 and length <= 32:
        return [task]
    common = dict(
        as_object(task.descriptor.get("common", {}), f"task {task.name}.common")
    )
    if length > 32:
        row_ranges = [(row, 1) for row in range(rows)]
        feature_ranges = [
            (feature, min(32, length - feature))
            for feature in range(0, length, 32)
        ]
    else:
        row_ranges = [
            (row, min(32, rows - row))
            for row in range(0, rows, 32)
        ]
        feature_ranges = [(0, length)]

    result: list[VirtualTask] = []
    previous: str | None = None
    for row_start, row_count in row_ranges:
        for feature_start, feature_count in feature_ranges:
            chunk_common = dict(common)
            for key, default_broadcast in (
                ("src0", "none"),
                ("src1", "none"),
                ("src2", "none"),
                ("dst", "none"),
            ):
                if key not in common:
                    continue
                broadcast = (
                    "none"
                    if key == "dst"
                    else str(
                        vector.get(
                            f"broadcast{key[-1]}",
                            default_broadcast,
                        )
                    ).lower()
                )
                chunk_common[key] = _vector_chunk_reference(
                    common[key],
                    tensors,
                    broadcast=broadcast,
                    row=row_start,
                    feature=feature_start,
                    full_length=length,
                    location=f"task {task.name}.{key}",
                )
            if "aux0" in common:
                chunk_common["aux0"] = _vector_chunk_reference(
                    common["aux0"],
                    tensors,
                    broadcast="none",
                    row=row_start,
                    feature=feature_start,
                    full_length=length,
                    location=f"task {task.name}.aux0",
                )
            chunk_vector = {
                key: value
                for key, value in vector.items()
                if not key.endswith("_stride_bytes")
            }
            chunk_vector["rows"] = row_count
            chunk_vector["length"] = feature_count
            chunk_vector["valid_length"] = feature_count
            name = (
                f"{task.name}__rows_{row_start}_{row_count}"
                f"__features_{feature_start}_{feature_count}"
            )
            dependencies = task.extra_after if previous is None else (previous,)
            result.append(
                VirtualTask(
                    name=name,
                    engine="vector",
                    opcode=task.opcode,
                    reads=task.reads,
                    writes=task.writes,
                    descriptor={
                        "common": chunk_common,
                        "vector": chunk_vector,
                    },
                    flags=(
                        task.flags
                        if (
                            row_start,
                            row_count,
                            feature_start,
                            feature_count,
                        )
                        == (
                            row_ranges[-1][0],
                            row_ranges[-1][1],
                            feature_ranges[-1][0],
                            feature_ranges[-1][1],
                        )
                        else {}
                    ),
                    extra_after=dependencies,
                    high_level_node=task.high_level_node,
                )
            )
            previous = name
    return result


def _offset_inline_reference(
    value: Any,
    tensors: Mapping[str, TensorInfo],
    *,
    element_offset: int,
    alignment: int,
    location: str,
) -> dict[str, Any]:
    reference = _task_tensor_reference(value, tensors, location)
    dtype = str(reference["dtype"]).lower()
    bit_offset = element_offset * DTYPE_BITS[dtype]
    if bit_offset % 8:
        raise fail(location, "chunk begins in the middle of a byte")
    byte_offset = bit_offset // 8
    reference["addr"] = int(reference["addr"]) + byte_offset
    if int(reference["addr"]) % alignment:
        raise fail(
            f"{location}.addr",
            f"chunk address must remain {alignment}-byte aligned",
        )
    if "region_bytes" in reference:
        reference["region_bytes"] = max(
            0, int(reference["region_bytes"]) - byte_offset
        )
    return reference


def expand_inline_complex_task(
    task: VirtualTask,
    tensors: Mapping[str, TensorInfo],
) -> list[VirtualTask]:
    """Split Complex work only where each chunk is mathematically independent."""

    fields = dict(
        as_object(
            task.descriptor.get("complex", {}),
            f"task {task.name}.complex",
        )
    )
    rows = parse_int(fields.get("rows"), f"task {task.name}.rows", 1)
    length = parse_int(fields.get("length"), f"task {task.name}.length", 1)
    if rows <= 32 and length <= 256:
        return [task]
    if length > 256 and task.opcode not in ("ACT", "ADD_RESCALE"):
        raise fail(
            f"task {task.name}.length",
            f"{task.opcode} length {length} exceeds 256; splitting the "
            "feature axis would change the operation result",
        )
    common = dict(
        as_object(task.descriptor.get("common", {}), f"task {task.name}.common")
    )
    if length > 256:
        row_ranges = [(row, 1) for row in range(rows)]
        feature_ranges = [
            (feature, min(256, length - feature))
            for feature in range(0, length, 256)
        ]
    else:
        row_ranges = [
            (row, min(32, rows - row))
            for row in range(0, rows, 32)
        ]
        feature_ranges = [(0, length)]

    result: list[VirtualTask] = []
    previous: str | None = None
    for row_start, row_count in row_ranges:
        for feature_start, feature_count in feature_ranges:
            chunk_common = dict(common)
            source_offset = row_start * length + feature_start
            for key in ("src0", "dst"):
                if key in common:
                    chunk_common[key] = _offset_inline_reference(
                        common[key],
                        tensors,
                        element_offset=source_offset,
                        alignment=16,
                        location=f"task {task.name}.{key}",
                    )
            if task.opcode == "ADD_RESCALE" and "src1" in common:
                chunk_common["src1"] = _offset_inline_reference(
                    common["src1"],
                    tensors,
                    element_offset=source_offset,
                    alignment=16,
                    location=f"task {task.name}.src1",
                )
            elif task.opcode == "SOFTMAX" and "aux0" in common:
                mask_mode = str(fields.get("mask_mode", "none")).lower()
                if mask_mode == "boolean":
                    mask_offset = source_offset
                elif mask_mode == "valid_length":
                    mask_offset = row_start
                else:
                    mask_offset = 0
                chunk_common["aux0"] = _offset_inline_reference(
                    common["aux0"],
                    tensors,
                    element_offset=mask_offset,
                    alignment=16,
                    location=f"task {task.name}.aux0",
                )
            if task.opcode == "STAT" and "dst" in common:
                chunk_common["dst"] = _offset_inline_reference(
                    common["dst"],
                    tensors,
                    element_offset=row_start,
                    alignment=16,
                    location=f"task {task.name}.dst",
                )
            chunk_fields = dict(fields)
            chunk_fields["rows"] = row_count
            chunk_fields["length"] = feature_count
            chunk_fields["valid_length"] = feature_count
            name = (
                f"{task.name}__rows_{row_start}_{row_count}"
                f"__features_{feature_start}_{feature_count}"
            )
            is_last = (
                row_start,
                row_count,
                feature_start,
                feature_count,
            ) == (
                row_ranges[-1][0],
                row_ranges[-1][1],
                feature_ranges[-1][0],
                feature_ranges[-1][1],
            )
            result.append(
                VirtualTask(
                    name=name,
                    engine="complex",
                    opcode=task.opcode,
                    reads=task.reads,
                    writes=task.writes,
                    descriptor={
                        "common": chunk_common,
                        "complex": chunk_fields,
                    },
                    flags=task.flags if is_last else {},
                    extra_after=(
                        task.extra_after if previous is None else (previous,)
                    ),
                    high_level_node=task.high_level_node,
                )
            )
            previous = name
    return result


def _matrix_b_batch_elements(
    k: int,
    n: int,
    target: TargetConfig,
) -> int:
    return (
        ((k + target.kt - 1) // target.kt)
        * ((n + target.nt - 1) // target.nt)
        * target.kt
        * target.nt
    )


def expand_inline_matrix_task(
    task: VirtualTask,
    tensors: Mapping[str, TensorInfo],
    target: TargetConfig,
) -> list[VirtualTask]:
    """Split Matrix M rows and BMM batches without changing packed-B layout."""

    fields = dict(
        as_object(
            task.descriptor.get("matrix", {}),
            f"task {task.name}.matrix",
        )
    )
    m = parse_int(fields.get("m"), f"task {task.name}.m", 1)
    n = parse_int(fields.get("n"), f"task {task.name}.n", 1)
    k = parse_int(fields.get("k", 1), f"task {task.name}.k", 1)
    batch_count = parse_int(
        fields.get("batch_count", 1),
        f"task {task.name}.batch_count",
        1,
    )
    if n > 64 or k > 64:
        dimension = "N" if n > 64 else "K"
        value = n if n > 64 else k
        raise fail(
            f"task {task.name}.{dimension.lower()}",
            f"Matrix {dimension}={value} exceeds 64; the inline command has "
            "no packed-B stride field, so this axis cannot be split safely",
        )
    if m <= 64 and batch_count <= 64:
        return [task]
    common = dict(
        as_object(task.descriptor.get("common", {}), f"task {task.name}.common")
    )
    source = common.get("src0")
    weight = common.get("src1")
    destination = common.get("dst")
    if task.opcode != "GEMM_ZERO" and (source is None or weight is None):
        raise fail(f"task {task.name}", "Matrix source and weight are required")
    if destination is None:
        raise fail(f"task {task.name}.dst", "Matrix destination is required")

    if batch_count > 1 and m <= 64:
        batch_ranges = [
            (batch, min(64, batch_count - batch))
            for batch in range(0, batch_count, 64)
        ]
        row_ranges = [(0, m)]
    elif batch_count > 1:
        batch_ranges = [(batch, 1) for batch in range(batch_count)]
        row_ranges = [
            (row, min(64, m - row))
            for row in range(0, m, 64)
        ]
    else:
        batch_ranges = [(0, 1)]
        row_ranges = [
            (row, min(64, m - row))
            for row in range(0, m, 64)
        ]

    b_batch_elements = _matrix_b_batch_elements(k, n, target)
    result: list[VirtualTask] = []
    previous: str | None = None
    for batch_start, batch_chunk in batch_ranges:
        for row_start, row_count in row_ranges:
            chunk_common = dict(common)
            if source is not None:
                chunk_common["src0"] = _offset_inline_reference(
                    source,
                    tensors,
                    element_offset=batch_start * m * k + row_start * k,
                    alignment=64,
                    location=f"task {task.name}.src0",
                )
            if weight is not None:
                chunk_common["src1"] = _offset_inline_reference(
                    weight,
                    tensors,
                    element_offset=batch_start * b_batch_elements,
                    alignment=64,
                    location=f"task {task.name}.src1",
                )
            chunk_common["dst"] = _offset_inline_reference(
                destination,
                tensors,
                element_offset=batch_start * m * n + row_start * n,
                alignment=64,
                location=f"task {task.name}.dst",
            )
            chunk_fields = dict(fields)
            chunk_fields["m"] = row_count
            chunk_fields["batch_count"] = batch_chunk
            opcode = task.opcode
            if batch_count > 1 and batch_chunk == 1:
                opcode = "GEMM"
            name = (
                f"{task.name}__batch_{batch_start}_{batch_chunk}"
                f"__rows_{row_start}_{row_count}"
            )
            is_last = (
                batch_start,
                batch_chunk,
                row_start,
                row_count,
            ) == (
                batch_ranges[-1][0],
                batch_ranges[-1][1],
                row_ranges[-1][0],
                row_ranges[-1][1],
            )
            result.append(
                VirtualTask(
                    name=name,
                    engine="matrix",
                    opcode=opcode,
                    reads=task.reads,
                    writes=task.writes,
                    descriptor={
                        "common": chunk_common,
                        "matrix": chunk_fields,
                    },
                    flags=task.flags if is_last else {},
                    extra_after=(
                        task.extra_after if previous is None else (previous,)
                    ),
                    high_level_node=task.high_level_node,
                )
            )
            previous = name
    return result


def expand_inline_tasks(
    tasks: Sequence[VirtualTask],
    tensors: Mapping[str, TensorInfo],
    target: TargetConfig,
) -> list[VirtualTask]:
    result: list[VirtualTask] = []
    final_name: dict[str, str] = {}
    for task in tasks:
        rewritten = replace(
            task,
            extra_after=tuple(
                final_name.get(dependency, dependency)
                for dependency in task.extra_after
            ),
        )
        if rewritten.engine == "dma" and rewritten.opcode == "COPY_ND":
            emitted = expand_inline_dma_copy_nd(rewritten, tensors)
        elif rewritten.engine == "matrix":
            emitted = expand_inline_matrix_task(rewritten, tensors, target)
        elif rewritten.engine == "vector":
            emitted = expand_inline_vector_task(rewritten, tensors)
        elif rewritten.engine == "complex":
            emitted = expand_inline_complex_task(rewritten, tensors)
        else:
            emitted = [rewritten]
        result.extend(emitted)
        final_name[task.name] = emitted[-1].name
    return result


def build_low_ir(
    tensors: Mapping[str, TensorInfo],
    tasks: Sequence[VirtualTask],
    target: TargetConfig,
) -> tuple[dict[str, Any], list[VirtualTask]]:
    inline_tasks = expand_inline_tasks(tasks, tensors, target)
    base_dependencies = task_dependencies(inline_tasks, tensors)
    expanded, dependencies = expand_dependency_joins(
        inline_tasks, base_dependencies
    )
    used_as_dependency = {
        dependency
        for values in dependencies.values()
        for dependency in values
    }
    remaining_event_producers = [0] * (len(expanded) + 1)
    for index in range(len(expanded) - 1, -1, -1):
        remaining_event_producers[index] = (
            remaining_event_producers[index + 1]
            + (1 if expanded[index].name in used_as_dependency else 0)
        )
    task_index = {
        task.name: index for index, task in enumerate(expanded)
    }
    last_consumer: dict[str, int] = {
        name: max(
            index
            for index, task in enumerate(expanded)
            if name in dependencies[task.name]
        )
        for name in used_as_dependency
    }
    event_by_task: dict[str, dict[str, int]] = {}
    rearm_before: dict[int, list[int]] = {}
    active_events: list[tuple[int, int]] = []
    reusable_events: list[int] = []
    rearmed_events: list[int] = []
    next_unused_event = 0
    for index, task in enumerate(expanded):
        still_active: list[tuple[int, int]] = []
        for end_index, event_id in active_events:
            if end_index < index:
                reusable_events.append(event_id)
            else:
                still_active.append((end_index, event_id))
        active_events = still_active
        reusable_events.sort()
        if task.name not in used_as_dependency:
            continue
        if next_unused_event <= npu_assembler.MAX_EVENT_ID:
            event_id = next_unused_event
            next_unused_event += 1
        else:
            if not rearmed_events and reusable_events:
                group_size = min(
                    CMD_FIFO_MAX_BURST_COMMANDS,
                    len(reusable_events),
                    remaining_event_producers[index],
                )
                rearm_before[index] = reusable_events[:group_size]
                rearmed_events.extend(reusable_events[:group_size])
                del reusable_events[:group_size]
            if not rearmed_events:
                raise fail(
                    "scheduler",
                    "more than 255 dependency events are live at the same time",
                )
            event_id = rearmed_events.pop(0)
        event_by_task[task.name] = event_object(event_id)
        active_events.append((last_consumer[task.name], event_id))

    scheduled: list[VirtualTask] = []
    scheduled_dependencies: dict[str, tuple[str, ...]] = {}
    forced_signal: dict[str, dict[str, int]] = {}
    used_names = set(task_index)
    rearm_index = 0
    for index, task in enumerate(expanded):
        for event_id in rearm_before.get(index, []):
            while True:
                rearm_name = f"__event_rearm_{rearm_index}"
                rearm_index += 1
                if rearm_name not in used_names:
                    break
            used_names.add(rearm_name)
            rearm_task = VirtualTask(
                name=rearm_name,
                engine="control",
                opcode="EVENT_REARM",
                reads=(),
                writes=(),
                descriptor={"control": {}},
                high_level_node="__scheduler",
            )
            scheduled.append(rearm_task)
            scheduled_dependencies[rearm_name] = ()
            forced_signal[rearm_name] = event_object(event_id)
        scheduled.append(task)
        scheduled_dependencies[task.name] = dependencies[task.name]

    if len(scheduled) > npu_assembler.MAX_COMMAND_ID + 1:
        raise fail("scheduler", "program has too many commands")

    low_tensors: dict[str, Any] = {}
    for tensor in tensors.values():
        if tensor.l1_addr is None:
            continue
        low_tensors[tensor.name] = {
            "addr": tensor.l1_addr,
            "space": "l1",
            "dtype": tensor.dtype,
            "region_bytes": tensor.storage_bytes,
        }

    operations: list[dict[str, Any]] = []
    for command_id, task in enumerate(scheduled):
        waits = [
            event_by_task[name]
            for name in scheduled_dependencies[task.name]
        ]
        signal: dict[str, int] | str = forced_signal.get(
            task.name, event_by_task.get(task.name, "none")
        )
        fields = dict(task.descriptor)
        if task.engine == "control" and task.opcode == "EVENT_JOIN":
            if len(waits) != 2 or isinstance(signal, str):
                raise fail("scheduler", "EVENT_JOIN fields are incomplete")
            fields = {
                "control": {
                    "join_mode": 0,
                }
            }
        operation: dict[str, Any] = {
            "name": task.name,
            "command_id": command_id,
            "engine": task.engine,
            "opcode": task.opcode,
            "wait_events": waits,
            "signal_event": signal,
            "user_tag": command_id,
            "fields": fields,
        }
        if task.flags:
            operation["flags"] = task.flags
        operations.append(operation)

    low_ir = {
        "schema_version": 1,
        "target": {
            "name": "single-core-v2",
            "command_format": npu_assembler.COMMAND_FORMAT,
            "mt": target.mt,
            "kt": target.kt,
            "nt": target.nt,
        },
        "tensors": low_tensors,
        "operations": operations,
    }
    return low_ir, scheduled


def sha256_bytes(content: bytes) -> str:
    return model_artifacts.sha256_bytes(content)


def canonical_json(value: Any) -> bytes:
    return model_artifacts.canonical_json(value)


def runtime_metadata(
    model_name: str,
    tensors: Mapping[str, TensorInfo],
    outputs: Sequence[str],
    tasks: Sequence[VirtualTask],
    assembled: Sequence[npu_assembler.CompiledOperation],
    target: TargetConfig,
    arena: ConstantArena,
    constant_image: bytes,
) -> dict[str, Any]:
    l1_base, ddr_base = constant_block_bases(tensors, arena)
    command_by_name = {
        operation.name: operation.command_id for operation in assembled
    }
    inputs = [
        tensor
        for tensor in tensors.values()
        if tensor.kind == "input"
    ]
    bindings = lambda values: [
        {
            "name": tensor.name,
            "ddr_addr": tensor.ddr_addr,
            "l1_addr": tensor.l1_addr,
            "shape": list(tensor.shape),
            "dtype": tensor.dtype,
            "bytes": tensor.storage_bytes,
        }
        for tensor in values
    ]
    command_batch_limit = min(
        target.task_entries, CMD_FIFO_MAX_BURST_COMMANDS
    )
    batches: list[list[int]] = []
    current_batch: list[int] = []
    current_batch_is_rearm: bool | None = None

    def finish_batch() -> None:
        nonlocal current_batch_is_rearm
        if current_batch:
            batches.append(list(current_batch))
            current_batch.clear()
        current_batch_is_rearm = None

    for operation in assembled:
        is_rearm = (
            operation.engine == "control"
            and operation.opcode
            == npu_assembler.OPCODES["control"]["EVENT_REARM"]
        )
        if (
            current_batch
            and current_batch_is_rearm is not None
            and is_rearm != current_batch_is_rearm
        ):
            finish_batch()
        if not current_batch:
            current_batch_is_rearm = is_rearm
        current_batch.append(operation.command_id)
        if len(current_batch) == command_batch_limit:
            finish_batch()
    finish_batch()
    batch_execution = [
        {
            "command_ids": batch,
            "host_sync_before": index != 0,
            "host_sync_after": True,
            "contains_event_rearm": any(
                assembled[command_id].engine == "control"
                and assembled[command_id].opcode
                == npu_assembler.OPCODES["control"]["EVENT_REARM"]
                for command_id in batch
            ),
        }
        for index, batch in enumerate(batches)
    ]
    return {
        "runtime_version": 1,
        "model_name": model_name,
        "command_format": npu_assembler.COMMAND_FORMAT,
        "command_bits": 128,
        "command_count": len(assembled),
        "external_descriptor_bytes": 0,
        "constant_base_ddr": ddr_base,
        "constant_base_l1": l1_base,
        "constant_bytes": len(constant_image),
        "constant_sha256": sha256_bytes(constant_image),
        "task_entries": target.task_entries,
        "command_fifo_max_burst_commands": CMD_FIFO_MAX_BURST_COMMANDS,
        "batches": batches,
        "batch_execution": batch_execution,
        "inputs": bindings(inputs),
        "outputs": bindings([tensors[name] for name in outputs]),
        "operations": [
            {
                "name": task.name,
                "command_id": command_by_name[task.name],
                "high_level_node": task.high_level_node,
                "engine": task.engine,
                "opcode": task.opcode,
            }
            for task in tasks
        ],
        "memory_plan": [
            {
                "name": tensor.name,
                "kind": tensor.kind,
                "shape": list(tensor.shape),
                "dtype": tensor.dtype,
                "layout": tensor.layout,
                "bytes": tensor.storage_bytes,
                "allocation_bytes": tensor.allocation_bytes,
                "l1_addr": tensor.l1_addr,
                "ddr_addr": tensor.ddr_addr,
                "alias_of": tensor.alias_of,
                "storage_id": tensor.storage_id,
                "reused_from": tensor.reused_from,
            }
            for tensor in tensors.values()
            if tensor.l1_addr is not None
        ],
    }


def compile_model_document(
    document: Mapping[str, Any],
    target: TargetConfig,
    *,
    source_name: str = "model.json",
) -> CompilationResult:
    validate_target(target)
    model_name, tensors, operators, outputs = parse_model_document(document)
    arena, requant_by_shift = prepare_constant_arena(
        tensors, operators, target
    )
    allocator, _ddr_allocator, constant_image = allocate_model_storage(
        tensors, operators, outputs, target, arena
    )
    tasks = lower_model_tasks(
        tensors,
        operators,
        outputs,
        allocator,
        target,
        arena,
        constant_image,
        requant_by_shift,
    )
    low_ir, expanded_tasks = build_low_ir(tensors, tasks, target)
    assembled, command_image = npu_assembler.compile_document(low_ir)
    runtime = runtime_metadata(
        model_name,
        tensors,
        outputs,
        expanded_tasks,
        assembled,
        target,
        arena,
        constant_image,
    )
    runtime["command_bytes"] = len(command_image)
    runtime["command_sha256"] = sha256_bytes(command_image)
    return CompilationResult(
        source_name=source_name,
        model_name=model_name,
        tensors=tensors,
        operators=operators,
        tasks=expanded_tasks,
        low_ir=low_ir,
        assembled_operations=assembled,
        command_image=command_image,
        constant_image=constant_image,
        runtime=runtime,
    )


def c_identifier(value: str) -> str:
    return model_artifacts.c_identifier(value)


def c_string(value: str) -> str:
    return model_artifacts.c_string(value)


def c_byte_array(content: bytes, name: str) -> str:
    return model_artifacts.c_byte_array(content, name)


def build_model_c_header(
    stem: str,
    result: CompilationResult,
) -> bytes:
    return model_artifacts.build_model_c_header(
        stem, result, max_rank=MAX_RANK
    )


def build_model_manifest(
    source_path: Path,
    result: CompilationResult,
    file_contents: Mapping[str, bytes],
) -> bytes:
    return model_artifacts.build_model_manifest(
        source_path, result, file_contents
    )


def output_artifacts(
    input_path: Path,
    target: TargetConfig,
    emit_raw: bool,
    cli_options: argparse.Namespace | None = None,
) -> tuple[dict[str, bytes], CompilationResult]:
    requested_format = (
        "auto"
        if cli_options is None
        else str(cli_options.input_format)
    )
    model_format = detect_format(input_path, requested_format)
    document_holder: dict[str, Mapping[str, Any]] = {}

    if model_format == "json":
        loader = load_json_document
    else:
        if cli_options is None:
            raise ModelCompileError(
                "framework model import requires frontend options"
            )
        frontend_options = options_from_namespace(cli_options)

        def loader(path: Path) -> Mapping[str, Any]:
            document = load_framework_document(path, frontend_options)
            document_holder["document"] = document
            return document

    def compile_with_source_metadata(
        document: Mapping[str, Any],
        configuration: TargetConfig,
        *,
        source_name: str,
    ) -> CompilationResult:
        result = compile_model_document(
            document, configuration, source_name=source_name
        )
        frontend = document.get("frontend")
        if isinstance(frontend, dict):
            result.runtime["frontend"] = dict(frontend)
        return result

    files, result = model_artifacts.output_artifacts(
        input_path,
        target,
        emit_raw,
        load_document=loader,
        compile_document=compile_with_source_metadata,
        max_rank=MAX_RANK,
    )
    if emit_raw and "document" in document_holder:
        files.pop(f"{input_path.stem}.manifest.json")
        files[f"{input_path.stem}.model.json"] = canonical_json(
            document_holder["document"]
        )
        files[f"{input_path.stem}.manifest.json"] = build_model_manifest(
            input_path, result, files
        )
    return files, result


def unique_object(pairs: list[tuple[str, Any]]) -> dict[str, Any]:
    return model_artifacts.unique_object(
        pairs, error_type=ModelCompileError
    )


def load_json_document(path: Path) -> Mapping[str, Any]:
    return model_artifacts.load_json_document(
        path, error_type=ModelCompileError
    )


def parse_cli_int(value: str) -> int:
    return model_artifacts.parse_cli_int(value)


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    return model_artifacts.parse_args(argv)


def main(argv: Sequence[str] | None = None) -> int:
    return model_artifacts.run_cli(
        argv,
        target_type=TargetConfig,
        output_artifacts_fn=output_artifacts,
        error_type=ModelCompileError,
    )


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (
        ModelCompileError,
        FrontendError,
        npu_assembler.CompileError,
        conv_lowering.ConvLoweringError,
        OSError,
    ) as error:
        raise SystemExit(f"NPU model compiler failed: {error}") from error
