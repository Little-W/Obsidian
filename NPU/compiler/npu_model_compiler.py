#!/usr/bin/env python3
"""Compile a high-level integer model graph and invoke the NPU assembler.

The model graph contains logical tensors and semantic operators.  It does not
contain device addresses, command identifiers, events, engine names, opcodes,
DMA records, or Descriptor fields.  This program derives those details and
emits a normalized low-level JSON IR for ``npu_assembler.py``.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import math
import os
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Iterable, Mapping, Sequence

sys.dont_write_bytecode = True

_HERE = Path(__file__).resolve().parent
if str(_HERE) not in sys.path:
    sys.path.insert(0, str(_HERE))

import npu_assembler


MODEL_SCHEMA_VERSION = 1
DTYPE_BITS = {"int4": 4, "int8": 8, "int16": 16, "int32": 32}
DTYPE_LIMITS = {
    "int4": (-8, 7),
    "int8": (-128, 127),
    "int16": (-32768, 32767),
    "int32": (-(1 << 31), (1 << 31) - 1),
}
MAX_RANK = 5


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
    descriptor_base: int = 0x10000
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
    descriptor_image: bytes
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
    if len(input_shape) != 4 or len(kernel_shape) != 4:
        raise fail(location, "Conv2D requires NHWC input and KH,KW,Cin,Cout kernel")
    batches, height, width, channels = input_shape
    kernel_h, kernel_w, kernel_channels, output_channels = kernel_shape
    if channels != kernel_channels:
        raise fail(location, "input channels do not match kernel Cin")
    groups = parse_int(attributes.get("groups", 1), f"{location}.groups", 1)
    if groups != 1:
        raise fail(location, "Conv2D currently supports groups=1")
    stride_h, stride_w = pair(
        attributes.get("strides"), f"{location}.strides"
    )
    dilation_h, dilation_w = pair(
        attributes.get("dilations"), f"{location}.dilations"
    )
    effective_h = (kernel_h - 1) * dilation_h + 1
    effective_w = (kernel_w - 1) * dilation_w + 1
    padding = attributes.get("padding", "valid")
    if isinstance(padding, str):
        mode = padding.lower()
        if mode == "valid":
            pads = (0, 0, 0, 0)
            out_h = (height - effective_h) // stride_h + 1
            out_w = (width - effective_w) // stride_w + 1
        elif mode == "same":
            out_h = (height + stride_h - 1) // stride_h
            out_w = (width + stride_w - 1) // stride_w
            total_h = max(0, (out_h - 1) * stride_h + effective_h - height)
            total_w = max(0, (out_w - 1) * stride_w + effective_w - width)
            pads = (
                total_h // 2,
                total_h - total_h // 2,
                total_w // 2,
                total_w - total_w // 2,
            )
        else:
            raise fail(f"{location}.padding", "use VALID, SAME or four integers")
    else:
        raw = as_list(padding, f"{location}.padding")
        if len(raw) != 4:
            raise fail(f"{location}.padding", "must contain top,bottom,left,right")
        pads = tuple(
            parse_int(item, f"{location}.padding[{index}]", 0, 0xFFFF)
            for index, item in enumerate(raw)
        )
        out_h = (
            height + pads[0] + pads[1] - effective_h
        ) // stride_h + 1
        out_w = (
            width + pads[2] + pads[3] - effective_w
        ) // stride_w + 1
    if out_h <= 0 or out_w <= 0:
        raise fail(location, "kernel, dilation and padding produce an empty output")
    attributes["_strides"] = [stride_h, stride_w]
    attributes["_dilations"] = [dilation_h, dilation_w]
    attributes["_pads"] = list(pads)
    return (batches, out_h, out_w, output_channels), pads


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
            if left.shape == right.shape:
                shape = left.shape
            elif product(left.shape) == 1:
                shape = right.shape
            elif product(right.shape) == 1:
                shape = left.shape
            else:
                raise fail(location, "Add supports equal shapes or one scalar")
            output_dtype = left.dtype
            output_shapes = [shape]
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

