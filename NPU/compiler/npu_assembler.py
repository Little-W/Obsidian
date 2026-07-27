#!/usr/bin/env python3
"""Assemble the NPU low-level JSON IR into 128-bit instruction records.

Every executable parameter is encoded in the 128-bit command.  The assembler
therefore emits a command image and metadata, but never emits a separate
Descriptor image.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import math
import os
import struct
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping, Sequence

sys.dont_write_bytecode = True

SCHEMA_VERSION = 1
COMMAND_FORMAT = "cmd128"
EVENT_NONE = 0xFF
MAX_EVENT_ID = 0xFE
MAX_COMMAND_ID = 0x3FF
PAYLOAD_BITS = 80
AXI_ADDR_BITS = 40
AXI_ADDR_LIMIT = 1 << AXI_ADDR_BITS

ENGINE_CODES = {"control": 0, "dma": 1, "matrix": 2, "vector": 3, "complex": 4}
OPCODES = {
    "control": {
        "NOP": 0x00,
        "EVENT_SIGNAL": 0x01,
        "EVENT_REARM": 0x02,
        "EVENT_JOIN": 0x03,
        "GLOBAL_FENCE": 0x04,
    },
    "dma": {
        "COPY_1D": 0x20,
        "COPY_ND": 0x21,
        "FILL": 0x22,
        "TRANSPOSE_2D": 0x23,
        "PACK": 0x24,
        "SPLIT": 0x25,
        "GATHER_ND": 0x28,
    },
    "matrix": {
        "GEMM": 0x40,
        "BMM": 0x41,
        "GEMM_ACCUM": 0x42,
        "GEMM_ZERO": 0x43,
    },
    "vector": {
        "ADD": 0x60,
        "SUB": 0x61,
        "MUL": 0x62,
        "FMA": 0x63,
        "MAX": 0x64,
        "MIN": 0x65,
        "CMP": 0x66,
        "SELECT": 0x67,
        "CLAMP": 0x68,
        "RELU": 0x69,
    },
    "complex": {
        "ACT": 0x80,
        "SOFTMAX": 0x81,
        "NORM": 0x82,
        "ROPE": 0x83,
        "STAT": 0x84,
        "RECIP": 0x85,
        "ADD_RESCALE": 0x86,
    },
}

_OPCODE_NAMES = (
    ("control", "NOP"),
    ("control", "EVENT_SIGNAL"),
    ("control", "EVENT_REARM"),
    ("control", "EVENT_JOIN"),
    ("control", "GLOBAL_FENCE"),
    ("dma", "COPY_1D"),
    ("dma", "COPY_ND"),
    ("dma", "FILL"),
    ("dma", "TRANSPOSE_2D"),
    ("dma", "PACK"),
    ("dma", "SPLIT"),
    ("dma", "GATHER_ND"),
    ("matrix", "GEMM"),
    ("matrix", "BMM"),
    ("matrix", "GEMM_ACCUM"),
    ("matrix", "GEMM_ZERO"),
    ("vector", "ADD"),
    ("vector", "SUB"),
    ("vector", "MUL"),
    ("vector", "FMA"),
    ("vector", "MAX"),
    ("vector", "MIN"),
    ("vector", "CMP"),
    ("vector", "SELECT"),
    ("vector", "CLAMP"),
    ("vector", "RELU"),
    ("complex", "ACT"),
    ("complex", "SOFTMAX"),
    ("complex", "NORM"),
    ("complex", "ROPE"),
    ("complex", "STAT"),
    ("complex", "RECIP"),
    ("complex", "ADD_RESCALE"),
)
OPCODE_FIELDS = {
    pair: opcode for opcode, pair in enumerate(_OPCODE_NAMES)
}

DTYPE_CODES = {"int4": 0, "int8": 1, "int32": 2, "int16": 3}
DTYPE_BITS = {"int4": 4, "int8": 8, "int32": 32, "int16": 16}
BROADCAST_CODES = {"none": 0, "scalar": 1, "row": 2, "feature": 3}
COMPARE_CODES = {"eq": 0, "ne": 1, "lt": 2, "le": 3, "gt": 4, "ge": 5}
MASK_CODES = {"none": 0, "boolean": 1, "causal": 2, "valid_length": 3}
GADDR_BASE_CODES = {
    "zero": 0,
    "input": 1,
    "weight": 2,
    "work": 3,
    "output": 4,
    "kv": 5,
}
EPSILON_PROFILES = {1.0e-5: 0, 1.0e-6: 1, 1.0e-3: 2, 1.0e-4: 3}
CLIP_PROFILES = {
    (-16.0, 16.0): 0,
    (-8.0, 8.0): 1,
    (-4.0, 4.0): 2,
    (-2.0, 2.0): 3,
}
ACT_FUNCTION_CODES = {"sigmoid": 0, "tanh": 1, "gelu": 2, "silu": 3}
STAT_FUNCTION_CODES = {"stat_sum": 0, "stat_max": 1, "stat_sumsq": 2}


class CompileError(ValueError):
    """Low-level IR or inline encoding error with a stable location."""


@dataclass(frozen=True)
class Artifact:
    path: Path
    content: bytes


@dataclass(frozen=True)
class CompiledOperation:
    name: str
    command_id: int
    engine: str
    engine_opcode: int
    opcode: int
    payload: int
    command: bytes
    wait_events: tuple[int, int]
    signal_event: int
    user_tag: int


def fail(location: str, message: str) -> CompileError:
    return CompileError(f"{location}: {message}")


def object_value(value: Any, location: str) -> Mapping[str, Any]:
    if not isinstance(value, dict):
        raise fail(location, "must be a JSON object")
    return value


def list_value(value: Any, location: str) -> list[Any]:
    if not isinstance(value, list):
        raise fail(location, "must be a JSON array")
    return value


def parse_int(
    value: Any,
    location: str,
    minimum: int = 0,
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
        raise fail(location, "must be an integer or 0x-prefixed string")
    if result < minimum or (maximum is not None and result > maximum):
        upper = "" if maximum is None else f"..{maximum}"
        raise fail(location, f"value {result} is outside {minimum}{upper}")
    return result


def parse_signed(value: Any, location: str, bits: int = 32) -> int:
    if isinstance(value, bool) or not isinstance(value, int):
        raise fail(location, "must be a signed JSON integer")
    minimum = -(1 << (bits - 1))
    maximum = (1 << (bits - 1)) - 1
    if value < minimum or value > maximum:
        raise fail(location, f"value is outside signed {bits}-bit range")
    return value


def parse_float(value: Any, location: str) -> float:
    if isinstance(value, bool) or not isinstance(value, (int, float)):
        raise fail(location, "must be a finite JSON number")
    result = float(value)
    if not math.isfinite(result):
        raise fail(location, "must be finite")
    return result


def enum_value(table: Mapping[str, int], value: Any, location: str) -> int:
    if not isinstance(value, str):
        raise fail(location, "must be a string")
    key = value.lower()
    if key not in table:
        raise fail(
            location,
            f"unsupported value {value!r}; use {', '.join(sorted(table))}",
        )
    return table[key]


def dtype_name(value: Any, location: str) -> str:
    if not isinstance(value, str) or value.lower() not in DTYPE_CODES:
        raise fail(location, "use int4, int8, int16, or int32")
    return value.lower()


def pack_field(payload: int, value: int, lsb: int, width: int, location: str) -> int:
    value = parse_int(value, location, 0, (1 << width) - 1)
    mask = ((1 << width) - 1) << lsb
    if payload & mask:
        raise fail(location, "overlaps an already encoded payload field")
    return payload | (value << lsb)


def parse_event(value: Any, location: str) -> int:
    if value is None or value == "none":
        return EVENT_NONE
    if isinstance(value, int) and not isinstance(value, bool):
        if value == EVENT_NONE:
            return EVENT_NONE
        return parse_int(value, location, 0, MAX_EVENT_ID)
    event = object_value(value, location)
    event_id = parse_int(event.get("id"), f"{location}.id", 0, MAX_EVENT_ID)
    generation = parse_int(
        event.get("generation", 0), f"{location}.generation", 0, 15
    )
    if generation != 0:
        raise fail(
            f"{location}.generation",
            "The instruction carries an 8-bit event ID and requires generation 0",
        )
    return event_id


def event_to_json(raw: int) -> dict[str, int] | None:
    return None if raw == EVENT_NONE else {"id": raw, "generation": 0}


def header_flags(fields: Mapping[str, Any], location: str) -> tuple[int, int]:
    unsupported = set(fields) - {
        "irq_on_success",
        "irq_on_error",
        "strict_numeric",
        "ordered",
        "timeout_class",
    }
    if unsupported:
        raise fail(
            location,
            "The instruction flag object does not support "
            + ", ".join(sorted(unsupported)),
        )
    packed = 0
    for name, bit in (
        ("irq_on_success", 3),
        ("irq_on_error", 2),
        ("strict_numeric", 1),
        ("ordered", 0),
    ):
        value = fields.get(name, False)
        if not isinstance(value, bool):
            raise fail(f"{location}.{name}", "must be true or false")
        if value:
            packed |= 1 << bit
    timeout = parse_int(
        fields.get("timeout_class", 0), f"{location}.timeout_class", 0, 3
    )
    return packed, timeout


def encode_command128(
    payload: int,
    command_id: int,
    opcode: int,
    dtype: int,
    flags: int,
    timeout_class: int,
    wait0: int,
    wait1: int,
    signal: int,
) -> bytes:
    payload = parse_int(payload, "payload", 0, (1 << PAYLOAD_BITS) - 1)
    command_id = parse_int(command_id, "command_id", 0, MAX_COMMAND_ID)
    opcode = parse_int(opcode, "opcode", 0, 0x20)
    dtype = parse_int(dtype, "dtype", 0, 3)
    flags = parse_int(flags, "flags", 0, 0xF)
    timeout_class = parse_int(timeout_class, "timeout_class", 0, 3)
    wait0 = parse_event(wait0, "wait0")
    wait1 = parse_event(wait1, "wait1")
    signal = parse_event(signal, "signal")
    if signal != EVENT_NONE and signal in (wait0, wait1):
        raise fail("signal", "cannot equal a wait event")
    low = payload & ((1 << 64) - 1)
    high = (
        ((payload >> 64) & 0xFFFF)
        | (dtype << 16)
        | (timeout_class << 18)
        | (flags << 20)
        | (signal << 24)
        | (wait1 << 32)
        | (wait0 << 40)
        | (command_id << 48)
        | (opcode << 58)
    )
    return struct.pack("<QQ", low, high)


def target_axi_addr_bits(target: Mapping[str, Any]) -> int:
    return parse_int(
        target.get("axi_addr_bits", AXI_ADDR_BITS),
        "target.axi_addr_bits",
        AXI_ADDR_BITS,
        AXI_ADDR_BITS,
    )


def validate_tensor_address(
    tensor: Mapping[str, Any],
    target: Mapping[str, Any],
    location: str,
) -> None:
    address = tensor_addr(tensor, location)
    space = str(tensor.get("space", "l1")).lower()
    if space != "ddr":
        return
    address_limit = 1 << target_axi_addr_bits(target)
    if address >= address_limit:
        raise fail(
            f"{location}.addr",
            f"must be below 2^{AXI_ADDR_BITS}",
        )
    if "region_bytes" not in tensor:
        return
    region_bytes = parse_int(
        tensor["region_bytes"],
        f"{location}.region_bytes",
        0,
        address_limit,
    )
    if region_bytes > address_limit - address:
        raise fail(
            f"{location}.region_bytes",
            f"region ending at 0x{address + region_bytes:x} "
            f"exceeds the {AXI_ADDR_BITS}-bit AXI address range",
        )


def normalize_tensors(
    document: Mapping[str, Any],
    target: Mapping[str, Any],
) -> dict[str, Mapping[str, Any]]:
    source = object_value(document.get("tensors", {}), "tensors")
    result: dict[str, Mapping[str, Any]] = {}
    for name, value in source.items():
        if not isinstance(name, str) or not name:
            raise fail("tensors", "tensor names must be non-empty strings")
        tensor = object_value(value, f"tensors.{name}")
        parse_int(tensor.get("addr"), f"tensors.{name}.addr", 0, (1 << 48) - 1)
        space = tensor.get("space", "l1")
        if not isinstance(space, str) or space.lower() not in ("l1", "ddr"):
            raise fail(f"tensors.{name}.space", "use l1 or ddr")
        dtype_name(tensor.get("dtype"), f"tensors.{name}.dtype")
        if "region_bytes" in tensor:
            parse_int(
                tensor["region_bytes"],
                f"tensors.{name}.region_bytes",
                0,
                (1 << 48) - 1,
            )
        validate_tensor_address(tensor, target, f"tensors.{name}")
        result[name] = tensor
    return result


def resolve_tensor(
    value: Any,
    tensors: Mapping[str, Mapping[str, Any]],
    location: str,
) -> Mapping[str, Any]:
    if value is None:
        return {}
    if isinstance(value, str):
        if value not in tensors:
            raise fail(location, f"unknown tensor {value!r}")
        return tensors[value]
    return object_value(value, location)


def tensor_addr(tensor: Mapping[str, Any], location: str) -> int:
    if not tensor:
        return 0
    return parse_int(tensor.get("addr"), f"{location}.addr", 0, (1 << 48) - 1)


def tensor_dtype(
    tensor: Mapping[str, Any], fallback: Any, location: str
) -> str:
    return dtype_name(tensor.get("dtype", fallback), f"{location}.dtype")


def operation_fields(
    operation: Mapping[str, Any], engine: str, location: str
) -> tuple[Mapping[str, Any], Mapping[str, Any]]:
    if "descriptor" in operation:
        raise fail(
            f"{location}.descriptor",
            "The instruction uses the fields object; external Descriptor input is not accepted",
        )
    fields = object_value(operation.get("fields", {}), f"{location}.fields")
    common = object_value(fields.get("common", {}), f"{location}.fields.common")
    engine_fields = object_value(
        fields.get(engine, {}), f"{location}.fields.{engine}"
    )
    extra = set(fields) - {"common", engine}
    if extra:
        raise fail(
            f"{location}.fields",
            "unexpected field groups: " + ", ".join(sorted(extra)),
        )
    return common, engine_fields


def gaddr_bases(target: Mapping[str, Any]) -> dict[int, int]:
    address_limit = 1 << target_axi_addr_bits(target)
    raw = object_value(target.get("gaddr_bases", {}), "target.gaddr_bases")
    result = {index: 0 for index in range(6)}
    for name, value in raw.items():
        if isinstance(name, str) and name.lower() in GADDR_BASE_CODES:
            selector = GADDR_BASE_CODES[name.lower()]
        else:
            selector = parse_int(name, f"target.gaddr_bases.{name}", 0, 5)
        base = parse_int(
            value,
            f"target.gaddr_bases.{name}",
            0,
            address_limit - 1,
        )
        if base & 0x7:
            raise fail(
                f"target.gaddr_bases.{name}",
                "must be aligned to 8 bytes",
            )
        result[selector] = base
    return result


def encode_aref(
    tensor: Mapping[str, Any],
    target: Mapping[str, Any],
    location: str,
) -> int:
    if not tensor:
        raise fail(location, "tensor reference is required")
    address = tensor_addr(tensor, location)
    space = str(tensor.get("space", "l1")).lower()
    if space == "l1":
        if address > 0xFFFFF:
            raise fail(
                f"{location}.addr",
                "L1 AREF uses a 20-bit byte address",
            )
        return address
    if space != "ddr":
        raise fail(f"{location}.space", "use l1 or ddr")
    validate_tensor_address(tensor, target, location)
    bases = gaddr_bases(target)
    selector_value = tensor.get("base_select")
    if selector_value is None:
        candidates = [
            selector
            for selector, base in bases.items()
            if address >= base and address - base <= 0xFFFFFF
        ]
        if not candidates:
            raise fail(
                f"{location}.addr",
                "address needs a configured GADDR base with a 24-bit offset",
            )
        selector = min(candidates, key=lambda item: address - bases[item])
    elif isinstance(selector_value, str):
        selector = enum_value(
            GADDR_BASE_CODES, selector_value, f"{location}.base_select"
        )
    else:
        selector = parse_int(
            selector_value, f"{location}.base_select", 0, 5
        )
    base = bases[selector]
    if address < base or address - base > 0xFFFFFF:
        raise fail(
            f"{location}.addr",
            f"does not fit the 24-bit offset for GADDR base {selector}",
        )
    return (1 << 27) | (selector << 24) | (address - base)


def encode_lref(
    tensor: Mapping[str, Any], shift: int, width: int, location: str
) -> int:
    if not tensor:
        return 0
    if str(tensor.get("space", "l1")).lower() != "l1":
        raise fail(f"{location}.space", "this operand must reside in L1")
    address = tensor_addr(tensor, location)
    alignment = 1 << shift
    if address & (alignment - 1):
        raise fail(
            f"{location}.addr",
            f"must be aligned to {alignment} bytes for this inline field",
        )
    reference = address >> shift
    if reference >= (1 << width):
        raise fail(
            f"{location}.addr",
            f"does not fit the {width}-bit L1 reference",
        )
    return reference


def positive_product(values: Sequence[Any], location: str) -> int:
    result = 1
    if not values:
        raise fail(location, "must contain at least one dimension")
    for index, value in enumerate(values):
        result *= parse_int(value, f"{location}[{index}]", 1, 0xFFFFFFFF)
        if result > 0xFFFFFFFF:
            raise fail(location, "element count exceeds 32 bits")
    return result


def power2_exponent(value: Any, location: str) -> int:
    number = parse_float(value, location)
    if number <= 0.0:
        raise fail(location, "must be a positive power of two")
    exponent = int(round(math.log2(number)))
    if exponent < -8 or exponent > 7 or number != math.ldexp(1.0, exponent):
        raise fail(location, "must equal 2^e with e in -8..7")
    return exponent & 0xF


def epsilon_profile(value: Any, location: str) -> int:
    number = parse_float(value, location)
    for candidate, profile in EPSILON_PROFILES.items():
        if math.isclose(number, candidate, rel_tol=0.0, abs_tol=candidate * 1e-7):
            return profile
    raise fail(location, "use 1e-5, 1e-6, 1e-3, or 1e-4")


def encode_control_payload(
    opcode_name: str, fields: Mapping[str, Any], location: str
) -> int:
    payload = 0
    engine_mask = parse_int(
        fields.get("engine_mask", 0), f"{location}.engine_mask", 0, 0xF
    )
    join_mode = parse_int(
        fields.get("join_mode", 0), f"{location}.join_mode", 0, 1
    )
    if opcode_name != "GLOBAL_FENCE" and engine_mask != 0:
        raise fail(f"{location}.engine_mask", "is only used by GLOBAL_FENCE")
    if opcode_name == "GLOBAL_FENCE" and engine_mask == 0:
        raise fail(f"{location}.engine_mask", "must select at least one engine")
    if opcode_name != "EVENT_JOIN" and join_mode != 0:
        raise fail(f"{location}.join_mode", "is only used by EVENT_JOIN")
    payload = pack_field(payload, engine_mask, 76, 4, f"{location}.engine_mask")
    payload = pack_field(payload, join_mode, 75, 1, f"{location}.join_mode")
    return payload


def encode_dma_payload(
    opcode_name: str,
    common: Mapping[str, Any],
    fields: Mapping[str, Any],
    tensors: Mapping[str, Mapping[str, Any]],
    target: Mapping[str, Any],
    location: str,
) -> tuple[int, int]:
    source = resolve_tensor(common.get("src0"), tensors, f"{location}.src0")
    destination = resolve_tensor(common.get("dst"), tensors, f"{location}.dst")
    source_dtype = tensor_dtype(
        source, common.get("src0_dtype", common.get("dtype", "int8")),
        f"{location}.src0",
    )
    destination_dtype = tensor_dtype(
        destination,
        common.get("dst_dtype", source_dtype),
        f"{location}.dst",
    )
    payload = 0
    if opcode_name == "FILL":
        destination_ref = encode_aref(destination, target, f"{location}.dst")
        shape = list_value(fields.get("shape", []), f"{location}.shape")
        count = parse_int(
            fields.get("count", positive_product(shape, f"{location}.shape")),
            f"{location}.count",
            1,
            (1 << 20) - 1,
        )
        raw_fill = fields.get("fill_value", 0)
        if isinstance(raw_fill, int) and not isinstance(raw_fill, bool) and raw_fill < 0:
            fill = parse_signed(raw_fill, f"{location}.fill_value", 32) & 0xFFFFFFFF
        else:
            fill = parse_int(raw_fill, f"{location}.fill_value", 0, 0xFFFFFFFF)
        payload = pack_field(payload, destination_ref, 52, 28, f"{location}.dst")
        payload = pack_field(payload, count, 32, 20, f"{location}.count")
        payload = pack_field(payload, fill, 0, 32, f"{location}.fill_value")
        return payload, DTYPE_CODES[destination_dtype]

    if opcode_name == "GATHER_ND":
        index_value = common.get("aux0")
        if index_value is None:
            index_value = common.get("src1")
        index = resolve_tensor(index_value, tensors, f"{location}.index")
        if not source:
            raise fail(f"{location}.src0", "tensor reference is required")
        if not index:
            raise fail(f"{location}.index", "tensor reference is required")
        if not destination:
            raise fail(f"{location}.dst", "tensor reference is required")
        if str(source.get("space", "l1")).lower() != "ddr":
            raise fail(f"{location}.src0.space", "GATHER_ND source must use ddr")
        if str(destination.get("space", "l1")).lower() != "l1":
            raise fail(f"{location}.dst.space", "GATHER_ND destination must use l1")
        if tensor_dtype(index, "int32", f"{location}.index") != "int32":
            raise fail(f"{location}.index.dtype", "GATHER_ND index must be int32")
        if destination_dtype != source_dtype:
            raise fail(
                f"{location}.dst.dtype",
                "GATHER_ND source and destination dtypes must match",
            )
        source_ref = encode_aref(source, target, f"{location}.src0")
        index_ref = encode_lref(index, 4, 16, f"{location}.index")
        destination_ref = encode_lref(
            destination, 4, 16, f"{location}.dst"
        )
        block_count = parse_int(
            fields.get("block_count"),
            f"{location}.block_count",
            1,
            256,
        )
        block_bytes = parse_int(
            fields.get("block_bytes"),
            f"{location}.block_bytes",
            1,
            4096,
        )
        payload = pack_field(
            payload, source_ref, 52, 28, f"{location}.src0"
        )
        payload = pack_field(
            payload, index_ref, 36, 16, f"{location}.index"
        )
        payload = pack_field(
            payload, destination_ref, 20, 16, f"{location}.dst"
        )
        payload = pack_field(
            payload,
            block_count - 1,
            12,
            8,
            f"{location}.block_count",
        )
        payload = pack_field(
            payload,
            block_bytes - 1,
            0,
            12,
            f"{location}.block_bytes",
        )
        return payload, DTYPE_CODES[source_dtype]

    source_ref = encode_aref(source, target, f"{location}.src0")
    destination_ref = encode_aref(destination, target, f"{location}.dst")
    payload = pack_field(payload, source_ref, 52, 28, f"{location}.src0")
    payload = pack_field(payload, destination_ref, 24, 28, f"{location}.dst")

    if opcode_name in ("COPY_1D", "COPY_ND"):
        shape = list_value(fields.get("shape", []), f"{location}.shape")
        count = parse_int(
            fields.get("count", positive_product(shape, f"{location}.shape")),
            f"{location}.count",
            1,
            (1 << 20) - 1,
        )
        if opcode_name == "COPY_ND":
            rank = parse_int(
                fields.get("rank", len(shape)), f"{location}.rank", 1, 5
            )
            if rank != len(shape):
                raise fail(f"{location}.rank", "must equal the shape rank")
            for key, value_dtype in (
                ("src_stride_bytes", source_dtype),
                ("dst_stride_bytes", destination_dtype),
            ):
                strides = list_value(fields.get(key, []), f"{location}.{key}")
                if strides and len(strides) != rank:
                    raise fail(
                        f"{location}.{key}", "must have one entry per dimension"
                    )
                if strides:
                    expected = [0] * rank
                    row_bytes = (
                        parse_int(shape[-1], f"{location}.shape[-1]", 1)
                        * DTYPE_BITS[value_dtype]
                        + 7
                    ) // 8
                    multiplier = 1
                    for axis in range(rank - 2, -1, -1):
                        expected[axis] = multiplier * row_bytes
                        multiplier *= parse_int(
                            shape[axis], f"{location}.shape[{axis}]", 1
                        )
                    parsed = [
                        parse_int(
                            item, f"{location}.{key}[{axis}]", 0, 0xFFFFFFFF
                        )
                        for axis, item in enumerate(strides)
                    ]
                    if parsed != expected:
                        raise fail(
                            f"{location}.{key}",
                            "The COPY_ND instruction accepts contiguous tensors only; "
                            "split strided rows into COPY_1D operations",
                        )
        payload = pack_field(payload, count, 4, 20, f"{location}.count")
        payload = pack_field(
            payload, DTYPE_CODES[destination_dtype], 2, 2, f"{location}.dst_dtype"
        )
        payload = pack_field(
            payload,
            parse_int(fields.get("src_nibble", 0), f"{location}.src_nibble", 0, 1),
            1,
            1,
            f"{location}.src_nibble",
        )
        destination_nibble = parse_int(
            fields.get("dst_nibble", 0),
            f"{location}.dst_nibble",
            0,
            1,
        )
        if destination_nibble:
            raise fail(
                f"{location}.dst_nibble",
                "must be zero for COPY instructions",
            )
        payload = pack_field(
            payload,
            destination_nibble,
            0,
            1,
            f"{location}.dst_nibble",
        )
    elif opcode_name == "TRANSPOSE_2D":
        shape = list_value(fields.get("shape"), f"{location}.shape")
        if len(shape) != 2:
            raise fail(f"{location}.shape", "must contain rows and columns")
        rows = parse_int(shape[0], f"{location}.shape[0]", 1, 0xFF)
        columns = parse_int(shape[1], f"{location}.shape[1]", 1, 0xFF)
        if destination_dtype != source_dtype:
            raise fail(f"{location}.dst_dtype", "transpose requires equal dtypes")
        payload = pack_field(payload, rows, 16, 8, f"{location}.rows")
        payload = pack_field(payload, columns, 8, 8, f"{location}.columns")
        payload = pack_field(
            payload, DTYPE_CODES[destination_dtype], 6, 2, f"{location}.dst_dtype"
        )
        payload = pack_field(
            payload,
            parse_int(fields.get("src_nibble", 0), f"{location}.src_nibble", 0, 1),
            5,
            1,
            f"{location}.src_nibble",
        )
        destination_nibble = parse_int(
            fields.get("dst_nibble", 0),
            f"{location}.dst_nibble",
            0,
            1,
        )
        if destination_nibble:
            raise fail(
                f"{location}.dst_nibble",
                "must be zero for TRANSPOSE_2D",
            )
        payload = pack_field(
            payload,
            destination_nibble,
            4,
            1,
            f"{location}.dst_nibble",
        )
    elif opcode_name in ("PACK", "SPLIT"):
        segment_values: dict[str, int] = {}
        for name, lsb in (
            ("segment_count", 16),
            ("segment_bytes", 8),
            ("segment_stride", 0),
        ):
            minimum = 1
            value = parse_int(fields.get(name), f"{location}.{name}", minimum, 0xFF)
            segment_values[name] = value
            payload = pack_field(payload, value, lsb, 8, f"{location}.{name}")
        if segment_values["segment_stride"] < segment_values["segment_bytes"]:
            raise fail(
                f"{location}.segment_stride",
                "must be at least segment_bytes",
            )
        if destination_dtype != source_dtype:
            raise fail(f"{location}.dst_dtype", "PACK/SPLIT requires equal dtypes")
    return payload, DTYPE_CODES[source_dtype]


def requant_shift(
    fields: Mapping[str, Any],
    common: Mapping[str, Any],
    location: str,
) -> int:
    value = fields.get("requant_shift", fields.get("output_shift"))
    if value is None:
        aux = common.get("aux1")
        if isinstance(aux, str) and aux.startswith("__requant_shift_"):
            try:
                value = int(aux.rsplit("_", 1)[1])
            except ValueError:
                value = None
    if value is None:
        value = 0
    return parse_int(value, f"{location}.requant_shift", 0, 31)


def reject_true(fields: Mapping[str, Any], names: Sequence[str], location: str) -> None:
    for name in names:
        value = fields.get(name, False)
        if not isinstance(value, bool):
            raise fail(f"{location}.{name}", "must be true or false")
        if value:
            raise fail(f"{location}.{name}", "is not encoded by this opcode")


def encode_matrix_payload(
    opcode_name: str,
    common: Mapping[str, Any],
    fields: Mapping[str, Any],
    tensors: Mapping[str, Mapping[str, Any]],
    location: str,
) -> tuple[int, int]:
    a = resolve_tensor(common.get("src0"), tensors, f"{location}.src0")
    b = resolve_tensor(common.get("src1"), tensors, f"{location}.src1")
    c = resolve_tensor(common.get("dst"), tensors, f"{location}.dst")
    bias = resolve_tensor(common.get("aux0"), tensors, f"{location}.aux0")
    zero_accumulator = opcode_name == "GEMM_ZERO"
    if not c:
        raise fail(f"{location}.dst", "tensor reference is required")
    if zero_accumulator:
        if a:
            raise fail(f"{location}.src0", "GEMM_ZERO requires A reference 0")
        if b:
            raise fail(f"{location}.src1", "GEMM_ZERO requires B reference 0")
        if bias:
            raise fail(f"{location}.aux0", "GEMM_ZERO requires bias reference 0")
    elif not a or not b:
        raise fail(f"{location}", "matrix A and B tensor references are required")
    a_dtype = tensor_dtype(
        a, common.get("src0_dtype", common.get("dtype", "int8")), f"{location}.src0"
    )
    b_dtype = tensor_dtype(b, common.get("src1_dtype", a_dtype), f"{location}.src1")
    c_dtype = tensor_dtype(c, common.get("dst_dtype", a_dtype), f"{location}.dst")
    inferred_b_int4 = a_dtype == "int8" and b_dtype == "int4"
    if not inferred_b_int4 and b_dtype != a_dtype:
        raise fail(
            f"{location}.src1.dtype",
            "B must match A, except INT8 A may use INT4 B",
        )
    requested_b_int4 = fields.get("b_int4", inferred_b_int4)
    if not isinstance(requested_b_int4, bool):
        raise fail(f"{location}.b_int4", "must be true or false")
    if requested_b_int4 != inferred_b_int4:
        raise fail(
            f"{location}.b_int4",
            "must agree with the A and B tensor dtypes",
        )
    b_int4 = 1 if requested_b_int4 else 0
    if a_dtype != "int8" and b_int4 != 0:
        raise fail(f"{location}.b_int4", "requires INT8 A")
    if bias and tensor_dtype(bias, "int32", f"{location}.aux0") != "int32":
        raise fail(f"{location}.aux0.dtype", "matrix bias must be INT32")
    if "bias_enable" in fields:
        bias_enable = fields["bias_enable"]
        if not isinstance(bias_enable, bool):
            raise fail(f"{location}.bias_enable", "must be true or false")
        if bias_enable != bool(bias):
            raise fail(
                f"{location}.bias_enable",
                "must agree with the presence of common.aux0",
            )
    reject_true(
        fields,
        ("transpose_a", "transpose_b", "residual_enable", "relu_enable"),
        location,
    )
    a_ref = encode_lref(a, 6, 14, f"{location}.src0")
    b_ref = encode_lref(b, 6, 14, f"{location}.src1")
    c_ref = encode_lref(c, 6, 14, f"{location}.dst")
    payload = 0
    payload = pack_field(payload, a_ref, 66, 14, f"{location}.src0")
    payload = pack_field(payload, b_ref, 52, 14, f"{location}.src1")
    payload = pack_field(payload, c_ref, 38, 14, f"{location}.dst")
    if opcode_name == "BMM":
        if bias:
            raise fail(f"{location}.aux0", "BMM payload has no bias field")
        batch = parse_int(fields.get("batch_count", 1), f"{location}.batch_count", 1, 64)
        m = parse_int(fields.get("m"), f"{location}.m", 1, 64)
        n = parse_int(fields.get("n"), f"{location}.n", 1, 64)
        k = parse_int(fields.get("k"), f"{location}.k", 1, 64)
        shift = requant_shift(fields, common, location)
        if c_dtype == "int32" and shift != 0:
            raise fail(f"{location}.requant_shift", "INT32 output requires shift 0")
        for value, lsb, name in (
            (batch - 1, 32, "batch_count"),
            (m - 1, 26, "m"),
            (n - 1, 20, "n"),
            (k - 1, 14, "k"),
        ):
            payload = pack_field(payload, value, lsb, 6, f"{location}.{name}")
        payload = pack_field(payload, b_int4, 13, 1, f"{location}.b_int4")
        payload = pack_field(
            payload, DTYPE_CODES[c_dtype], 11, 2, f"{location}.c_dtype"
        )
        payload = pack_field(payload, shift, 6, 5, f"{location}.requant_shift")
    else:
        m = parse_int(fields.get("m"), f"{location}.m", 1, 64)
        n = parse_int(fields.get("n"), f"{location}.n", 1, 64)
        k_default = 1 if opcode_name == "GEMM_ZERO" else None
        k = parse_int(fields.get("k", k_default), f"{location}.k", 1, 64)
        bias_ref = encode_lref(bias, 6, 12, f"{location}.aux0")
        if bias and bias_ref == 0:
            raise fail(
                f"{location}.aux0.addr",
                "bias reference 0 means no bias; place bias at a nonzero L1 address",
            )
        shift = requant_shift(fields, common, location)
        if c_dtype == "int32" and shift != 0:
            raise fail(f"{location}.requant_shift", "INT32 output requires shift 0")
        if zero_accumulator:
            if k != 1:
                raise fail(f"{location}.k", "GEMM_ZERO requires encoded K field 0")
            if b_int4 != 0:
                raise fail(f"{location}.b_int4", "GEMM_ZERO requires b_int4 0")
            if shift != 0:
                raise fail(
                    f"{location}.requant_shift",
                    "GEMM_ZERO requires requant_shift 0",
                )
        payload = pack_field(payload, bias_ref, 26, 12, f"{location}.aux0")
        for value, lsb, name in (
            (m - 1, 20, "m"),
            (n - 1, 14, "n"),
            (k - 1, 8, "k"),
        ):
            payload = pack_field(payload, value, lsb, 6, f"{location}.{name}")
        payload = pack_field(payload, b_int4, 7, 1, f"{location}.b_int4")
        payload = pack_field(
            payload, DTYPE_CODES[c_dtype], 5, 2, f"{location}.c_dtype"
        )
        payload = pack_field(payload, shift, 0, 5, f"{location}.requant_shift")
    return payload, DTYPE_CODES[a_dtype]


def broadcast_value(fields: Mapping[str, Any], name: str, location: str) -> int:
    return enum_value(
        BROADCAST_CODES, fields.get(name, "none"), f"{location}.{name}"
    )


def encode_vector_payload(
    opcode_name: str,
    common: Mapping[str, Any],
    fields: Mapping[str, Any],
    tensors: Mapping[str, Mapping[str, Any]],
    location: str,
) -> tuple[int, int]:
    src0 = resolve_tensor(common.get("src0"), tensors, f"{location}.src0")
    src1 = resolve_tensor(common.get("src1"), tensors, f"{location}.src1")
    src2 = resolve_tensor(common.get("src2"), tensors, f"{location}.src2")
    dst = resolve_tensor(common.get("dst"), tensors, f"{location}.dst")
    dtype = tensor_dtype(
        src0, common.get("src0_dtype", common.get("dtype", "int8")), f"{location}.src0"
    )
    for tensor, name in ((src1, "src1"), (src2, "src2")):
        if tensor and tensor_dtype(tensor, dtype, f"{location}.{name}") != dtype:
            if not (opcode_name == "FMA" and name == "src2" and
                    tensor_dtype(tensor, dtype, f"{location}.{name}") == "int32"):
                raise fail(f"{location}.{name}.dtype", "does not match the opcode")
    expected_dst = "int32" if opcode_name in ("MUL", "FMA") else (
        "int8" if opcode_name == "CMP" else dtype
    )
    if tensor_dtype(dst, expected_dst, f"{location}.dst") != expected_dst:
        raise fail(f"{location}.dst.dtype", f"must be {expected_dst}")
    rows = parse_int(fields.get("rows"), f"{location}.rows", 1, 32)
    length = parse_int(fields.get("length"), f"{location}.length", 1, 32)
    broadcasts = [
        broadcast_value(fields, name, location)
        for name in ("broadcast0", "broadcast1", "broadcast2")
    ]
    if fields.get("src1_from_scalar0", False) or fields.get("src2_from_scalar1", False):
        raise fail(location, "scalar arithmetic must be lowered before inline assembly")
    src0_raw = encode_lref(src0, 4, 16, f"{location}.src0")
    src1_raw = encode_lref(src1, 4, 16, f"{location}.src1")
    src2_raw = encode_lref(src2, 4, 16, f"{location}.src2")
    if opcode_name == "RELU":
        if src1_raw or src2_raw:
            raise fail(location, "RELU only accepts src0 and dst")
    elif opcode_name == "CMP":
        mode = enum_value(
            COMPARE_CODES, fields.get("compare_mode", "eq"), f"{location}.compare_mode"
        )
        src2_raw = mode << 13
        broadcasts[2] = 0
    elif opcode_name == "SELECT":
        mask = resolve_tensor(
            common.get("aux0", common.get("src2")), tensors, f"{location}.mask"
        )
        src2_raw = encode_lref(mask, 4, 16, f"{location}.mask")
        broadcasts[2] = 0
    elif opcode_name == "CLAMP":
        src1_raw = parse_signed(
            fields.get("clamp_min", fields.get("scalar0")),
            f"{location}.clamp_min",
            16,
        ) & 0xFFFF
        src2_raw = parse_signed(
            fields.get("clamp_max", fields.get("scalar1")),
            f"{location}.clamp_max",
            16,
        ) & 0xFFFF
        broadcasts[2] = 0
    elif opcode_name == "FMA":
        if not src1 or not src2:
            raise fail(location, "FMA requires src1 and src2")
    else:
        if opcode_name != "RELU" and not src1:
            raise fail(f"{location}.src1", f"{opcode_name} requires src1")
        if opcode_name not in ("FMA",) and src2_raw:
            raise fail(f"{location}.src2", f"{opcode_name} has no src2 operand")
    payload = 0
    for value, lsb, width, name in (
        (src0_raw, 64, 16, "src0"),
        (src1_raw, 48, 16, "src1"),
        (src2_raw, 32, 16, "src2"),
        (encode_lref(dst, 4, 16, f"{location}.dst"), 16, 16, "dst"),
        (rows - 1, 11, 5, "rows"),
        (length - 1, 6, 5, "length"),
        (broadcasts[0], 4, 2, "broadcast0"),
        (broadcasts[1], 2, 2, "broadcast1"),
        (broadcasts[2], 0, 2, "broadcast2"),
    ):
        payload = pack_field(payload, value, lsb, width, f"{location}.{name}")
    return payload, DTYPE_CODES[dtype]


def encode_complex_payload(
    opcode_name: str,
    common: Mapping[str, Any],
    fields: Mapping[str, Any],
    tensors: Mapping[str, Mapping[str, Any]],
    location: str,
) -> tuple[int, int]:
    src0 = resolve_tensor(common.get("src0"), tensors, f"{location}.src0")
    dst = resolve_tensor(common.get("dst"), tensors, f"{location}.dst")
    source_dtype = tensor_dtype(
        src0, common.get("src0_dtype", common.get("dtype", "int8")), f"{location}.src0"
    )
    destination_dtype = tensor_dtype(
        dst, common.get("dst_dtype", source_dtype), f"{location}.dst"
    )
    rows = parse_int(fields.get("rows"), f"{location}.rows", 1, 32)
    length = parse_int(fields.get("length"), f"{location}.length", 1, 256)
    src_ref = encode_lref(src0, 4, 16, f"{location}.src0")
    dst_ref = encode_lref(dst, 4, 16, f"{location}.dst")
    aux_ref = 0
    meta = 0
    if opcode_name == "ACT":
        function = enum_value(
            ACT_FUNCTION_CODES, fields.get("function"), f"{location}.function"
        )
        source_exp = power2_exponent(
            fields.get("src0_scale", 1.0), f"{location}.src0_scale"
        )
        destination_exp = power2_exponent(
            fields.get("dst_scale", 1.0), f"{location}.dst_scale"
        )
        clip_pair = (
            parse_float(fields.get("input_clip_min", -16.0), f"{location}.input_clip_min"),
            parse_float(fields.get("input_clip_max", 16.0), f"{location}.input_clip_max"),
        )
        if clip_pair not in CLIP_PROFILES:
            raise fail(location, "activation clip must be ±16, ±8, ±4, or ±2")
        meta = (
            (function << 17)
            | (source_exp << 13)
            | (destination_exp << 9)
            | (DTYPE_CODES[destination_dtype] << 7)
            | (CLIP_PROFILES[clip_pair] << 5)
        )
    elif opcode_name == "SOFTMAX":
        mask_mode = enum_value(
            MASK_CODES, fields.get("mask_mode", "none"), f"{location}.mask_mode"
        )
        if mask_mode == MASK_CODES["causal"]:
            raise fail(f"{location}.mask_mode", "causal mode must be lowered before assembly")
        if mask_mode != MASK_CODES["none"]:
            aux_value = common.get("aux0")
            if aux_value is None and fields.get("mask_addr", 0):
                aux_value = {
                    "addr": fields["mask_addr"],
                    "space": "l1",
                    "dtype": "int8" if mask_mode == 1 else "int32",
                }
            aux = resolve_tensor(aux_value, tensors, f"{location}.aux0")
            aux_ref = encode_lref(aux, 4, 16, f"{location}.aux0")
        all_mask = parse_int(
            fields.get("all_mask_mode", 0), f"{location}.all_mask_mode", 0, 1
        )
        meta = (
            (mask_mode << 17)
            | (all_mask << 16)
            | (power2_exponent(fields.get("src0_scale", 1.0), f"{location}.src0_scale") << 12)
            | (power2_exponent(fields.get("dst_scale", 1.0), f"{location}.dst_scale") << 8)
            | (DTYPE_CODES[destination_dtype] << 6)
        )
    elif opcode_name == "NORM":
        function = str(fields.get("function", "layernorm")).lower()
        if function not in ("layernorm", "rmsnorm"):
            raise fail(f"{location}.function", "use layernorm or rmsnorm")
        gamma = resolve_tensor(common.get("src1"), tensors, f"{location}.src1")
        aux_ref = encode_lref(gamma, 4, 16, f"{location}.src1")
        parameter_dtype = tensor_dtype(gamma, source_dtype, f"{location}.src1")
        if parameter_dtype != source_dtype:
            raise fail(f"{location}.src1.dtype", "must match src0 dtype")
        if function == "layernorm":
            beta = resolve_tensor(common.get("src2"), tensors, f"{location}.src2")
            parameter_bytes = (length * DTYPE_BITS[source_dtype] + 7) // 8
            expected_beta = tensor_addr(gamma, f"{location}.src1")
            expected_beta = (expected_beta + parameter_bytes + 63) & ~63
            if tensor_addr(beta, f"{location}.src2") != expected_beta:
                raise fail(
                    f"{location}.src2.addr",
                    "LayerNorm beta must follow gamma at the next 64-byte address",
                )
        meta = (
            ((1 if function == "rmsnorm" else 0) << 18)
            | (epsilon_profile(fields.get("epsilon", 1.0e-5), f"{location}.epsilon") << 16)
            | (power2_exponent(fields.get("src0_scale", 1.0), f"{location}.src0_scale") << 12)
            | (power2_exponent(fields.get("src1_scale", 1.0), f"{location}.src1_scale") << 8)
            | (power2_exponent(fields.get("dst_scale", 1.0), f"{location}.dst_scale") << 4)
            | (DTYPE_CODES[destination_dtype] << 2)
        )
    elif opcode_name in ("ROPE", "RECIP"):
        aux_value = common.get("src1", common.get("aux0"))
        if aux_value is not None:
            aux = resolve_tensor(aux_value, tensors, f"{location}.aux")
            aux_ref = encode_lref(aux, 4, 16, f"{location}.aux")
        if "p1_meta" not in fields:
            raise fail(
                f"{location}.p1_meta",
                f"{opcode_name} is a P1 opcode and requires its 19-bit P1 metadata",
            )
        meta = parse_int(
            fields["p1_meta"], f"{location}.p1_meta", 0, (1 << 19) - 1
        )
    elif opcode_name == "STAT":
        function = enum_value(
            STAT_FUNCTION_CODES, fields.get("function"), f"{location}.function"
        )
        if destination_dtype != "int32":
            raise fail(f"{location}.dst.dtype", "STAT output must be int32")
        meta = function << 17
    elif opcode_name == "ADD_RESCALE":
        src1 = resolve_tensor(common.get("src1"), tensors, f"{location}.src1")
        aux_ref = encode_lref(src1, 4, 16, f"{location}.src1")
        if tensor_dtype(src1, source_dtype, f"{location}.src1") != source_dtype:
            raise fail(f"{location}.src1.dtype", "must match src0 dtype")
        meta = (
            (power2_exponent(fields.get("src0_scale", 1.0), f"{location}.src0_scale") << 15)
            | (power2_exponent(fields.get("src1_scale", 1.0), f"{location}.src1_scale") << 11)
            | (power2_exponent(fields.get("dst_scale", 1.0), f"{location}.dst_scale") << 7)
            | (DTYPE_CODES[destination_dtype] << 5)
        )
    payload = 0
    for value, lsb, width, name in (
        (src_ref, 64, 16, "src0"),
        (aux_ref, 48, 16, "aux"),
        (dst_ref, 32, 16, "dst"),
        (rows - 1, 27, 5, "rows"),
        (length - 1, 19, 8, "length"),
        (meta, 0, 19, "meta"),
    ):
        payload = pack_field(payload, value, lsb, width, f"{location}.{name}")
    return payload, DTYPE_CODES[source_dtype]


def allocate_dependency_events(
    operations: list[Mapping[str, Any]],
) -> tuple[dict[str, int], dict[str, tuple[int, int]]]:
    names: dict[str, int] = {}
    for index, operation in enumerate(operations):
        name = operation.get("name")
        if not isinstance(name, str) or not name:
            raise fail(f"operations[{index}].name", "must be a non-empty string")
        if name in names:
            raise fail(f"operations[{index}].name", f"duplicate name {name!r}")
        names[name] = index
    needed: list[str] = []
    dependencies: dict[str, list[str]] = {}
    for index, operation in enumerate(operations):
        name = str(operation["name"])
        raw = list_value(operation.get("depends_on", []), f"operations[{index}].depends_on")
        values: list[str] = []
        for dep_index, dependency in enumerate(raw):
            if not isinstance(dependency, str) or dependency not in names:
                raise fail(
                    f"operations[{index}].depends_on[{dep_index}]",
                    "must name an existing operation",
                )
            if names[dependency] >= index:
                raise fail(
                    f"operations[{index}].depends_on[{dep_index}]",
                    "must name an earlier operation",
                )
            dependency_operation = operations[names[dependency]]
            if (
                str(dependency_operation.get("engine", "")).lower()
                == "control"
                and str(dependency_operation.get("opcode", "")).upper()
                == "EVENT_REARM"
            ):
                raise fail(
                    f"operations[{index}].depends_on[{dep_index}]",
                    "EVENT_REARM does not produce a dependency event",
                )
            values.append(dependency)
            if dependency not in needed:
                needed.append(dependency)
        if len(values) > 2:
            raise fail(
                f"operations[{index}].depends_on",
                "Each instruction supports at most two direct dependencies",
            )
        dependencies[name] = values
    signal_by_name: dict[str, int] = {}
    used_events: set[int] = set()
    produced_events: set[int] = set()
    rearmed_events: set[int] = set()
    for index, operation in enumerate(operations):
        name = str(operation["name"])
        if "signal_event" in operation:
            event = parse_event(operation["signal_event"], f"operations[{index}].signal_event")
            signal_by_name[name] = event
            if event != EVENT_NONE:
                engine = str(operation.get("engine", "")).lower()
                opcode = str(operation.get("opcode", "")).upper()
                if engine == "control" and opcode == "EVENT_REARM":
                    if event not in produced_events:
                        raise fail(
                            f"operations[{index}].signal_event",
                            "EVENT_REARM requires an earlier producer of this event ID",
                        )
                    if event in rearmed_events:
                        raise fail(
                            f"operations[{index}].signal_event",
                            "event ID was already rearmed and has no new producer",
                        )
                    rearmed_events.add(event)
                    used_events.add(event)
                    continue
                if event in produced_events and event not in rearmed_events:
                    raise fail(
                        f"operations[{index}].signal_event",
                        "event ID needs EVENT_REARM before another producer",
                    )
                produced_events.add(event)
                rearmed_events.discard(event)
                used_events.add(event)
    next_event = 0
    for name in needed:
        if signal_by_name.get(name, EVENT_NONE) != EVENT_NONE:
            continue
        while next_event in used_events:
            next_event += 1
        if next_event > MAX_EVENT_ID:
            raise fail("operations", "not enough event IDs")
        signal_by_name[name] = next_event
        used_events.add(next_event)
        next_event += 1
    waits: dict[str, tuple[int, int]] = {}
    for index, operation in enumerate(operations):
        name = str(operation["name"])
        if "wait_events" in operation and dependencies[name]:
            raise fail(f"operations[{index}]", "use either depends_on or wait_events")
        if "wait_events" in operation:
            raw = list_value(operation["wait_events"], f"operations[{index}].wait_events")
            if len(raw) > 2:
                raise fail(f"operations[{index}].wait_events", "supports at most two events")
            parsed = [
                parse_event(value, f"operations[{index}].wait_events[{event_index}]")
                for event_index, value in enumerate(raw)
            ]
        else:
            parsed = [signal_by_name[dependency] for dependency in dependencies[name]]
        parsed += [EVENT_NONE] * (2 - len(parsed))
        waits[name] = (parsed[0], parsed[1])
        signal_by_name.setdefault(name, EVENT_NONE)
    return signal_by_name, waits


def compile_document(
    document: Mapping[str, Any],
) -> tuple[list[CompiledOperation], bytes]:
    schema = parse_int(document.get("schema_version"), "schema_version", 1, 1)
    if schema != SCHEMA_VERSION:
        raise fail("schema_version", f"unsupported version {schema}")
    target = object_value(document.get("target", {}), "target")
    if target.get("command_format", COMMAND_FORMAT) != COMMAND_FORMAT:
        raise fail("target.command_format", f"must be {COMMAND_FORMAT!r}")
    target_axi_addr_bits(target)
    gaddr_bases(target)
    tensors = normalize_tensors(document, target)
    raw_operations = list_value(document.get("operations"), "operations")
    operations = [
        object_value(value, f"operations[{index}]")
        for index, value in enumerate(raw_operations)
    ]
    signals, waits = allocate_dependency_events(operations)
    command_ids: set[int] = set()
    compiled: list[CompiledOperation] = []
    command_image = bytearray()
    for index, operation in enumerate(operations):
        location = f"operations[{index}]"
        name = str(operation["name"])
        engine_value = operation.get("engine")
        if not isinstance(engine_value, str) or engine_value.lower() not in ENGINE_CODES:
            raise fail(f"{location}.engine", "use control, dma, matrix, vector, or complex")
        engine = engine_value.lower()
        opcode_value = operation.get("opcode")
        if not isinstance(opcode_value, str):
            raise fail(f"{location}.opcode", "the instruction requires an opcode name")
        opcode_name = opcode_value.upper()
        if opcode_name not in OPCODES[engine]:
            raise fail(
                f"{location}.opcode", f"use one of {', '.join(OPCODES[engine])}"
            )
        opcode = OPCODE_FIELDS[(engine, opcode_name)]
        command_id = parse_int(
            operation.get("command_id", index),
            f"{location}.command_id",
            0,
            MAX_COMMAND_ID,
        )
        if command_id in command_ids:
            raise fail(f"{location}.command_id", "duplicate command ID")
        command_ids.add(command_id)
        common, engine_fields = operation_fields(operation, engine, location)
        if engine == "control":
            payload = encode_control_payload(
                opcode_name, engine_fields, f"{location}.fields.control"
            )
            dtype = DTYPE_CODES["int8"]
        elif engine == "dma":
            payload, dtype = encode_dma_payload(
                opcode_name,
                common,
                engine_fields,
                tensors,
                target,
                f"{location}.fields.dma",
            )
        elif engine == "matrix":
            payload, dtype = encode_matrix_payload(
                opcode_name,
                common,
                engine_fields,
                tensors,
                f"{location}.fields.matrix",
            )
        elif engine == "vector":
            payload, dtype = encode_vector_payload(
                opcode_name,
                common,
                engine_fields,
                tensors,
                f"{location}.fields.vector",
            )
        else:
            payload, dtype = encode_complex_payload(
                opcode_name,
                common,
                engine_fields,
                tensors,
                f"{location}.fields.complex",
            )
        flags, timeout = header_flags(
            object_value(operation.get("flags", {}), f"{location}.flags"),
            f"{location}.flags",
        )
        signal = signals[name]
        wait0, wait1 = waits[name]
        if engine == "control":
            if opcode_name == "NOP" and (
                wait0 != EVENT_NONE or wait1 != EVENT_NONE or signal != EVENT_NONE
            ):
                raise fail(location, "NOP cannot carry wait or signal events")
            if opcode_name == "EVENT_JOIN" and (
                wait0 == EVENT_NONE or wait1 == EVENT_NONE or signal == EVENT_NONE
            ):
                raise fail(
                    location,
                    "EVENT_JOIN requires wait0, wait1, and signal event IDs",
                )
            if opcode_name in ("EVENT_SIGNAL", "EVENT_REARM") and (
                signal == EVENT_NONE
            ):
                raise fail(location, f"{opcode_name} requires signal_event")
            if opcode_name == "EVENT_REARM" and (
                wait0 != EVENT_NONE or wait1 != EVENT_NONE
            ):
                raise fail(
                    location,
                    "EVENT_REARM carries its event ID in signal_event and has no waits",
                )
        command = encode_command128(
            payload,
            command_id,
            opcode,
            dtype,
            flags,
            timeout,
            wait0,
            wait1,
            signal,
        )
        command_image.extend(command)
        compiled.append(
            CompiledOperation(
                name=name,
                command_id=command_id,
                engine=engine,
                engine_opcode=OPCODES[engine][opcode_name],
                opcode=opcode,
                payload=payload,
                command=command,
                wait_events=(wait0, wait1),
                signal_event=signal,
                user_tag=parse_int(
                    operation.get("user_tag", command_id),
                    f"{location}.user_tag",
                    0,
                    0xFFFFFFFF,
                ),
            )
        )
    return compiled, bytes(command_image)


def sha256_bytes(content: bytes) -> str:
    return hashlib.sha256(content).hexdigest()


def build_output_manifest(
    source_path: Path,
    source_document: Mapping[str, Any],
    operations: list[CompiledOperation],
    command_name: str,
    command_image: bytes,
) -> bytes:
    target = dict(source_document["target"])
    target.setdefault("axi_addr_bits", AXI_ADDR_BITS)
    output = {
        "artifact_version": 2,
        "source": source_path.name,
        "source_sha256": sha256_bytes(source_path.read_bytes()),
        "target": target,
        "command_format": COMMAND_FORMAT,
        "command_record_bytes": 16,
        "command_count": len(operations),
        "command_file": command_name,
        "command_sha256": sha256_bytes(command_image),
        "external_descriptor_bytes": 0,
        "operations": [
            {
                "name": operation.name,
                "command_id": operation.command_id,
                "engine": operation.engine,
                "engine_opcode": operation.engine_opcode,
                "opcode": operation.opcode,
                "payload": f"0x{operation.payload:020x}",
                "wait_events": [
                    event_to_json(operation.wait_events[0]),
                    event_to_json(operation.wait_events[1]),
                ],
                "signal_event": event_to_json(operation.signal_event),
                "user_tag": operation.user_tag,
                "command_low": f"0x{struct.unpack_from('<Q', operation.command, 0)[0]:016x}",
                "command_high": f"0x{struct.unpack_from('<Q', operation.command, 8)[0]:016x}",
            }
            for operation in operations
        ],
    }
    return (
        json.dumps(output, indent=2, sort_keys=True, ensure_ascii=True, allow_nan=False)
        + "\n"
    ).encode("utf-8")


def c_array(content: bytes, name: str) -> str:
    lines = []
    for start in range(0, len(content), 12):
        values = ", ".join(f"0x{value:02x}" for value in content[start : start + 12])
        lines.append(f"    {values},")
    if not lines:
        lines.append("    0x00,")
    return (
        f"static const unsigned char {name}[] = {{\n"
        + "\n".join(lines)
        + "\n};\n"
        + f"static const unsigned long {name}_bytes = {len(content)}ul;\n"
    )


def build_c_header(stem: str, command_image: bytes) -> bytes:
    symbol = "".join(character if character.isalnum() else "_" for character in stem)
    if not symbol or symbol[0].isdigit():
        symbol = f"model_{symbol}"
    guard = f"NPU_MODEL_{symbol.upper()}_H"
    content = (
        f"#ifndef {guard}\n#define {guard}\n\n"
        + c_array(command_image, f"{symbol}_commands")
        + f"\n#endif /* {guard} */\n"
    )
    return content.encode("ascii")


def atomic_write(path: Path, content: bytes) -> None:
    temporary = path.with_name(f".{path.name}.tmp-{os.getpid()}")
    try:
        temporary.write_bytes(content)
        os.replace(temporary, path)
    finally:
        if temporary.exists():
            temporary.unlink()


def output_artifacts(
    input_path: Path,
    output_dir: Path,
    emit_c_header: bool,
) -> tuple[list[Artifact], list[CompiledOperation]]:
    try:
        value = json.loads(input_path.read_text(encoding="utf-8"))
    except json.JSONDecodeError as error:
        raise CompileError(f"{input_path}:{error.lineno}:{error.colno}: {error.msg}") from error
    document = object_value(value, "document")
    operations, command_image = compile_document(document)
    stem = input_path.stem
    command_name = f"{stem}.cmd.bin"
    artifacts = [
        Artifact(output_dir / command_name, command_image),
        Artifact(
            output_dir / f"{stem}.manifest.json",
            build_output_manifest(
                input_path, document, operations, command_name, command_image
            ),
        ),
    ]
    if emit_c_header:
        artifacts.append(
            Artifact(output_dir / f"{stem}.npu.h", build_c_header(stem, command_image))
        )
    return artifacts, operations


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Assemble the NPU low-level JSON IR into an inline 128-bit instruction stream "
            "and artifact metadata."
        )
    )
    parser.add_argument("input", type=Path, help="low-level JSON IR file")
    parser.add_argument("-o", "--output-dir", type=Path, required=True)
    parser.add_argument(
        "--emit-c-header", action="store_true", help="also emit the command byte array"
    )
    parser.add_argument(
        "--check", action="store_true", help="compare requested artifacts without writing"
    )
    return parser.parse_args(argv)


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    if not args.input.is_file():
        raise CompileError(f"input is not a file: {args.input}")
    if args.output_dir.exists() and not args.output_dir.is_dir():
        raise CompileError(f"output path is not a directory: {args.output_dir}")
    artifacts, operations = output_artifacts(args.input, args.output_dir, args.emit_c_header)
    if args.check:
        for artifact in artifacts:
            if not artifact.path.is_file():
                raise CompileError(f"missing artifact: {artifact.path}")
            if artifact.path.read_bytes() != artifact.content:
                raise CompileError(f"artifact differs: {artifact.path}")
        action = "verified"
    else:
        args.output_dir.mkdir(parents=True, exist_ok=True)
        for artifact in artifacts:
            atomic_write(artifact.path, artifact.content)
        action = "wrote"
    print(f"format={COMMAND_FORMAT} operations={len(operations)}")
    for artifact in artifacts:
        print(
            f"{action}={artifact.path} bytes={len(artifact.content)} "
            f"sha256={sha256_bytes(artifact.content)}"
        )
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (CompileError, OSError) as error:
        raise SystemExit(f"NPU assembler failed: {error}") from error
