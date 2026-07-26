#!/usr/bin/env python3
"""Assemble normalized NPU JSON IR into deterministic device artifacts.

The input is a documented low-level model IR. Framework frontends may lower
supported graphs into this IR. This command does not claim to import every
Keras, PyTorch, ONNX, or TFLite graph.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import struct
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping, Sequence

sys.dont_write_bytecode = True

SCHEMA_VERSION = 1
COMMAND_FORMAT = "cmd128-v1"
HEADER_VERSION = 1
EVENT_NONE = 0xFFF
MAX_EVENT_ID = 254
MAX_COMMAND_ID = 0xFFF

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
DESCRIPTOR_BYTES = {
    "control": 64,
    "dma": 256,
    "matrix": 256,
    "vector": 192,
    "complex": 256,
}
DTYPE_CODES = {"int4": 0, "int8": 1, "int32": 2, "int16": 3}
SPACE_CODES = {"l1": 0, "ddr": 1}
ROUND_CODES = {
    "nearest_even": 0,
    "to_zero": 1,
    "to_pos_inf": 2,
    "to_neg_inf": 3,
}
OVERFLOW_CODES = {"saturate": 0, "error": 1, "wrap": 2}
DMA_CONVERT_CODES = {
    "none": 0,
    "sign_extend": 1,
    "saturate_narrow": 2,
    "pack_int4": 3,
}
BROADCAST_CODES = {"none": 0, "scalar": 1, "row": 2, "feature": 3}
COMPARE_CODES = {"eq": 0, "ne": 1, "lt": 2, "le": 3, "gt": 4, "ge": 5}
FUNCTION_CODES = {
    "sigmoid": 0,
    "tanh": 1,
    "gelu": 2,
    "silu": 3,
    "softmax": 4,
    "layernorm": 5,
    "rmsnorm": 6,
    "stat_sum": 7,
    "stat_max": 8,
    "stat_sumsq": 9,
    "reciprocal": 10,
    "reciprocal_sqrt": 11,
    "add_rescale": 12,
}
MASK_CODES = {"none": 0, "boolean": 1, "causal": 2, "valid_length": 3}
SCALE_CODES = {"none": 0, "per_tensor": 1, "per_row": 2, "per_feature": 3}


class CompileError(ValueError):
    """Input or lowering error with a stable location."""


@dataclass(frozen=True)
class Artifact:
    path: Path
    content: bytes


@dataclass(frozen=True)
class CompiledOperation:
    name: str
    command_id: int
    engine: str
    opcode: int
    descriptor_addr: int
    descriptor_offset: int
    descriptor: bytes
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
    minimum = -(1 << (bits - 1))
    maximum = (1 << (bits - 1)) - 1
    if isinstance(value, bool) or not isinstance(value, int):
        raise fail(location, "must be a signed JSON integer")
    if value < minimum or value > maximum:
        raise fail(location, f"value is outside signed {bits}-bit range")
    return value


def parse_float(value: Any, location: str) -> float:
    if isinstance(value, bool) or not isinstance(value, (int, float)):
        raise fail(location, "must be a finite JSON number")
    result = float(value)
    if not (-float("inf") < result < float("inf")):
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


def align_up(value: int, alignment: int) -> int:
    return (value + alignment - 1) & ~(alignment - 1)


def put_u8(data: bytearray, offset: int, value: Any, location: str) -> None:
    if offset < 0 or offset >= len(data):
        raise fail(location, "field does not fit in Descriptor")
    data[offset] = parse_int(value, location, 0, 0xFF)


def put_u16(data: bytearray, offset: int, value: Any, location: str) -> None:
    if offset < 0 or offset + 2 > len(data):
        raise fail(location, "field does not fit in Descriptor")
    struct.pack_into("<H", data, offset, parse_int(value, location, 0, 0xFFFF))


def put_u32(data: bytearray, offset: int, value: Any, location: str) -> None:
    if offset < 0 or offset + 4 > len(data):
        raise fail(location, "field does not fit in Descriptor")
    struct.pack_into(
        "<I", data, offset, parse_int(value, location, 0, 0xFFFFFFFF)
    )


def put_i32(data: bytearray, offset: int, value: Any, location: str) -> None:
    if offset < 0 or offset + 4 > len(data):
        raise fail(location, "field does not fit in Descriptor")
    struct.pack_into("<i", data, offset, parse_signed(value, location))


def put_u64(data: bytearray, offset: int, value: Any, location: str) -> None:
    if offset < 0 or offset + 8 > len(data):
        raise fail(location, "field does not fit in Descriptor")
    struct.pack_into(
        "<Q",
        data,
        offset,
        parse_int(value, location, 0, 0xFFFFFFFFFFFFFFFF),
    )


def put_f32(data: bytearray, offset: int, value: Any, location: str) -> None:
    if offset < 0 or offset + 4 > len(data):
        raise fail(location, "field does not fit in Descriptor")
    struct.pack_into("<f", data, offset, parse_float(value, location))


def bool_bit(fields: Mapping[str, Any], name: str, bit: int) -> int:
    value = fields.get(name, False)
    if not isinstance(value, bool):
        raise fail(name, "must be true or false")
    return (1 << bit) if value else 0


def parse_event(value: Any, location: str) -> int:
    if value is None or value == "none":
        return EVENT_NONE
    if isinstance(value, int) and not isinstance(value, bool):
        return parse_int(value, location, 0, EVENT_NONE)
    event = object_value(value, location)
    event_id = parse_int(event.get("id"), f"{location}.id", 0, MAX_EVENT_ID)
    generation = parse_int(
        event.get("generation", 0), f"{location}.generation", 0, 15
    )
    return (generation << 8) | event_id


def event_to_json(raw: int) -> dict[str, int] | None:
    if raw == EVENT_NONE:
        return None
    return {"id": raw & 0xFF, "generation": (raw >> 8) & 0xF}


def encode_command128(
    descriptor_addr: int,
    command_id: int,
    engine: int,
    opcode: int,
    header_flags: int,
    wait0: int,
    wait1: int,
    signal: int,
) -> bytes:
    descriptor_addr = parse_int(
        descriptor_addr, "descriptor_addr", 0, (1 << 48) - 1
    )
    if descriptor_addr & 0x3F:
        raise fail("descriptor_addr", "must be 64-byte aligned")
    command_id = parse_int(command_id, "command_id", 0, MAX_COMMAND_ID)
    engine = parse_int(engine, "engine", 0, 15)
    opcode = parse_int(opcode, "opcode", 0, 0xFF)
    header_flags = parse_int(header_flags, "header_flags", 0, 0xFFF)
    if header_flags & 0xC00:
        raise fail("header_flags", "bits 11:10 are reserved")
    wait0 = parse_event(wait0, "wait0")
    wait1 = parse_event(wait1, "wait1")
    signal = parse_event(signal, "signal")
    if signal != EVENT_NONE and signal in (wait0, wait1):
        raise fail("signal", "cannot equal a wait event")
    low = descriptor_addr | (command_id << 48) | (engine << 60)
    high = (
        opcode
        | (header_flags << 8)
        | (wait0 << 20)
        | (wait1 << 32)
        | (signal << 44)
        | (HEADER_VERSION << 56)
    )
    return struct.pack("<QQ", low, high)


def header_flags(fields: Mapping[str, Any], location: str) -> int:
    if "raw" in fields:
        result = parse_int(fields["raw"], f"{location}.raw", 0, 0x3FF)
        if result & (1 << 5):
            raise fail(
                f"{location}.raw",
                "the baseline profile does not advertise Descriptor CRC",
            )
        return result
    result = 0
    for name, bit in (
        ("irq_on_success", 0),
        ("irq_on_error", 1),
        ("strict_numeric", 2),
        ("trace_enable", 3),
        ("ordered", 4),
        ("descriptor_crc", 5),
    ):
        value = fields.get(name, False)
        if not isinstance(value, bool):
            raise fail(f"{location}.{name}", "must be true or false")
        if value:
            result |= 1 << bit
    if result & (1 << 5):
        raise fail(
            f"{location}.descriptor_crc",
            "the baseline profile does not advertise Descriptor CRC",
        )
    timeout = parse_int(
        fields.get("timeout_class", 0),
        f"{location}.timeout_class",
        0,
        15,
    )
    return result | (timeout << 6)


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


def tensor_address(tensor: Mapping[str, Any], location: str) -> int:
    if not tensor:
        return 0
    return parse_int(tensor.get("addr"), f"{location}.addr", 0, (1 << 48) - 1)


def tensor_dtype(
    tensor: Mapping[str, Any],
    fallback: Any,
    location: str,
) -> int:
    return enum_value(
        DTYPE_CODES, tensor.get("dtype", fallback), f"{location}.dtype"
    )


def compile_common(
    descriptor: bytearray,
    engine: str,
    operation: Mapping[str, Any],
    tensors: Mapping[str, Mapping[str, Any]],
    location: str,
) -> dict[str, Mapping[str, Any]]:
    descriptor_object = object_value(
        operation.get("descriptor", {}), f"{location}.descriptor"
    )
    common = object_value(
        descriptor_object.get("common", {}),
        f"{location}.descriptor.common",
    )
    refs: dict[str, Mapping[str, Any]] = {}
    names = ("src0", "src1", "src2", "dst", "aux0", "aux1")
    for name in names:
        refs[name] = resolve_tensor(
            common.get(name), tensors, f"{location}.descriptor.common.{name}"
        )

    put_u8(descriptor, 0x00, 1, f"{location}.desc_version")
    put_u8(descriptor, 0x01, ENGINE_CODES[engine], f"{location}.desc_type")
    put_u16(descriptor, 0x02, len(descriptor), f"{location}.desc_bytes")

    op_flags = parse_int(
        common.get("op_flags", 0),
        f"{location}.descriptor.common.op_flags",
        0,
        0xFFFFFFFF,
    )
    for index, name in enumerate(names):
        tensor = refs[name]
        space = tensor.get("space", "l1") if tensor else "l1"
        if not isinstance(space, str):
            raise fail(f"{location}.{name}.space", "must be a string")
        if tensor and space.lower() == "ddr":
            op_flags |= 1 << index
    op_flags |= bool_bit(common, "allow_inplace", 6)
    op_flags |= bool_bit(common, "allow_partial_dest", 7)
    put_u32(descriptor, 0x04, op_flags, f"{location}.op_flags")

    for offset, name in (
        (0x08, "src0"),
        (0x10, "src1"),
        (0x18, "src2"),
        (0x20, "dst"),
        (0x28, "aux0"),
        (0x30, "aux1"),
    ):
        address_key = f"{name}_addr"
        value = (
            common[address_key]
            if address_key in common
            else tensor_address(refs[name], f"{location}.{name}")
        )
        put_u64(descriptor, offset, value, f"{location}.{address_key}")

    dtype_default = common.get("dtype", "int4")
    numeric_cfg = 0
    for shift, name in ((0, "src0"), (2, "src1"), (4, "src2"), (6, "dst")):
        explicit = common.get(f"{name}_dtype", dtype_default)
        numeric_cfg |= tensor_dtype(refs[name], explicit, f"{location}.{name}") << shift
    numeric_cfg |= enum_value(
        ROUND_CODES,
        common.get("round_mode", "nearest_even"),
        f"{location}.round_mode",
    ) << 10
    numeric_cfg |= bool_bit(common, "saturate_enable", 12)
    numeric_cfg |= enum_value(
        SCALE_CODES,
        common.get("scale_mode", "none"),
        f"{location}.scale_mode",
    ) << 13
    numeric_cfg |= bool_bit(common, "zero_point_enable", 15)
    numeric_cfg |= bool_bit(common, "internal_fp32_enable", 16)
    put_u32(descriptor, 0x38, numeric_cfg, f"{location}.numeric_cfg")
    put_u32(
        descriptor,
        0x3C,
        operation.get("user_tag", 0),
        f"{location}.user_tag",
    )
    return refs


def padded_array(value: Any, count: int, location: str) -> list[int]:
    source = list_value(value, location)
    if len(source) > count:
        raise fail(location, f"supports at most {count} values")
    result = [
        parse_int(item, f"{location}[{index}]", 0, 0xFFFFFFFF)
        for index, item in enumerate(source)
    ]
    return result + [0] * (count - len(result))


def encode_control(
    data: bytearray,
    fields: Mapping[str, Any],
    location: str,
) -> None:
    if not fields:
        return
    put_u64(
        data, 0x08, parse_event(fields.get("event0"), f"{location}.event0"), f"{location}.event0"
    )
    put_u64(
        data, 0x10, parse_event(fields.get("event1"), f"{location}.event1"), f"{location}.event1"
    )
    put_u64(
        data, 0x20, parse_event(fields.get("target"), f"{location}.target"), f"{location}.target"
    )
    put_u64(
        data,
        0x28,
        parse_int(fields.get("engine_mask", 0), f"{location}.engine_mask", 0, 0xF),
        f"{location}.engine_mask",
    )
    join_mode = parse_int(
        fields.get("join_mode", 0), f"{location}.join_mode", 0, 2
    )
    current = struct.unpack_from("<I", data, 0x04)[0]
    put_u32(data, 0x04, current | (join_mode << 8), f"{location}.join_mode")


def encode_dma(
    data: bytearray,
    fields: Mapping[str, Any],
    refs: Mapping[str, Mapping[str, Any]],
    location: str,
) -> None:
    shape = padded_array(fields.get("shape", []), 5, f"{location}.shape")
    inferred_rank = len([value for value in shape if value != 0])
    rank = parse_int(
        fields.get("rank", inferred_rank), f"{location}.rank", 1, 5
    )
    src_strides = padded_array(
        fields.get("src_stride_bytes", [0] * rank),
        5,
        f"{location}.src_stride_bytes",
    )
    dst_strides = padded_array(
        fields.get("dst_stride_bytes", [0] * rank),
        5,
        f"{location}.dst_stride_bytes",
    )
    src_space = fields.get("src_space", refs["src0"].get("space", "l1"))
    dst_space = fields.get("dst_space", refs["dst"].get("space", "l1"))
    put_u8(data, 0x40, rank, f"{location}.rank")
    put_u8(
        data,
        0x41,
        enum_value(SPACE_CODES, src_space, f"{location}.src_space"),
        f"{location}.src_space",
    )
    put_u8(
        data,
        0x42,
        enum_value(SPACE_CODES, dst_space, f"{location}.dst_space"),
        f"{location}.dst_space",
    )
    put_u8(
        data,
        0x43,
        enum_value(
            DMA_CONVERT_CODES,
            fields.get("convert_mode", "none"),
            f"{location}.convert_mode",
        ),
        f"{location}.convert_mode",
    )
    burst = parse_int(
        fields.get("burst_beats", 16), f"{location}.burst_beats", 1, 256
    )
    put_u8(data, 0x44, burst - 1, f"{location}.burst_beats")
    put_u8(
        data, 0x45, fields.get("max_outstanding", 16), f"{location}.max_outstanding"
    )
    put_u8(data, 0x46, fields.get("src_nibble", 0), f"{location}.src_nibble")
    put_u8(data, 0x47, fields.get("dst_nibble", 0), f"{location}.dst_nibble")
    for index in range(5):
        put_u32(data, 0x48 + index * 4, shape[index], f"{location}.shape[{index}]")
        put_u32(
            data,
            0x60 + index * 4,
            src_strides[index],
            f"{location}.src_stride_bytes[{index}]",
        )
        put_u32(
            data,
            0x78 + index * 4,
            dst_strides[index],
            f"{location}.dst_stride_bytes[{index}]",
        )
    put_u64(data, 0x90, fields.get("fill_value", 0), f"{location}.fill_value")
    put_u64(
        data,
        0x98,
        fields.get("src_region_bytes", refs["src0"].get("region_bytes", 0)),
        f"{location}.src_region_bytes",
    )
    put_u64(
        data,
        0xA0,
        fields.get("dst_region_bytes", refs["dst"].get("region_bytes", 0)),
        f"{location}.dst_region_bytes",
    )
    put_u16(
        data, 0xA8, fields.get("segment_count", 0), f"{location}.segment_count"
    )
    put_u16(
        data, 0xAA, fields.get("segment_bytes", 0), f"{location}.segment_bytes"
    )
    put_u32(
        data, 0xAC, fields.get("segment_stride", 0), f"{location}.segment_stride"
    )


def last_tile(size: int, tile: int) -> int:
    return 0 if size == 0 else ((size - 1) % tile) + 1


def encode_matrix(
    data: bytearray,
    fields: Mapping[str, Any],
    target: Mapping[str, Any],
    location: str,
) -> None:
    m = parse_int(fields.get("m"), f"{location}.m", 0, 0xFFFFFFFF)
    n = parse_int(fields.get("n"), f"{location}.n", 0, 0xFFFFFFFF)
    k = parse_int(fields.get("k"), f"{location}.k", 0, 0xFFFFFFFF)
    mt = parse_int(target.get("mt", 8), "target.mt", 1, 255)
    kt = parse_int(target.get("kt", 16), "target.kt", 1, 255)
    nt = parse_int(target.get("nt", 8), "target.nt", 1, 255)
    values = (
        (0x40, m, "m"),
        (0x44, n, "n"),
        (0x48, k, "k"),
        (0x4C, fields.get("batch_count", 1), "batch_count"),
        (0x50, fields.get("last_tile_valid_m", last_tile(m, mt)), "last_tile_valid_m"),
        (0x54, fields.get("last_tile_valid_n", last_tile(n, nt)), "last_tile_valid_n"),
        (0x58, fields.get("last_tile_valid_k", last_tile(k, kt)), "last_tile_valid_k"),
    )
    for offset, value, name in values:
        put_u32(data, offset, value, f"{location}.{name}")
    flags = 0
    for name, bit in (
        ("transpose_a", 0),
        ("transpose_b", 1),
        ("bias_enable", 2),
        ("residual_enable", 3),
        ("relu_enable", 4),
        ("requant_enable", 5),
        ("accum_from_src2", 6),
        ("final_output", 7),
    ):
        flags |= bool_bit(fields, name, bit)
    put_u32(data, 0x5C, flags, f"{location}.flags")
    for offset, name in (
        (0x60, "lda_bytes"),
        (0x64, "ldb_bytes"),
        (0x68, "ldc_bytes"),
        (0x6C, "bias_stride_bytes"),
    ):
        put_u32(data, offset, fields.get(name, 0), f"{location}.{name}")
    for offset, name in (
        (0x70, "a_batch_stride_bytes"),
        (0x78, "b_batch_stride_bytes"),
        (0x80, "c_batch_stride_bytes"),
        (0x88, "src2_batch_stride_bytes"),
    ):
        put_u64(data, offset, fields.get(name, 0), f"{location}.{name}")
    numeric_cfg = struct.unpack_from("<I", data, 0x38)[0]
    a_dtype = numeric_cfg & 0x3
    b_dtype = (numeric_cfg >> 2) & 0x3
    c_dtype = (numeric_cfg >> 6) & 0x3
    # The C language reference model uses distinct layout codes for INT16:
    # 5 for a linear tensor and 6 for a KT-by-NT tiled Matrix-B tensor.
    linear_pack = {0: 1, 1: 0, 2: 4, 3: 5}
    tiled_pack = {0: 3, 1: 2, 2: 4, 3: 6}
    a_pack = parse_int(
        fields.get("a_pack_format", linear_pack[a_dtype]),
        f"{location}.a_pack_format",
        0,
        0xFF,
    )
    b_pack = parse_int(
        fields.get("b_pack_format", tiled_pack[b_dtype]),
        f"{location}.b_pack_format",
        0,
        0xFF,
    )
    c_pack = parse_int(
        fields.get("c_pack_format", linear_pack[c_dtype]),
        f"{location}.c_pack_format",
        0,
        0xFF,
    )
    for name, value, expected, dtype_code in (
        ("a_pack_format", a_pack, linear_pack[a_dtype], a_dtype),
        ("b_pack_format", b_pack, tiled_pack[b_dtype], b_dtype),
        ("c_pack_format", c_pack, linear_pack[c_dtype], c_dtype),
    ):
        if value != expected:
            raise fail(
                f"{location}.{name}",
                f"pack-format code {value} does not match dtype code "
                f"{dtype_code}",
            )
    put_u8(
        data,
        0x90,
        a_pack,
        f"{location}.a_pack_format",
    )
    put_u8(
        data,
        0x91,
        b_pack,
        f"{location}.b_pack_format",
    )
    put_u8(
        data,
        0x92,
        c_pack,
        f"{location}.c_pack_format",
    )
    put_u8(
        data,
        0x93,
        fields.get("pack_version", 0),
        f"{location}.pack_version",
    )
    put_u8(
        data,
        0x94,
        enum_value(
            OVERFLOW_CODES,
            fields.get("overflow_mode", "saturate"),
            f"{location}.overflow_mode",
        ),
        f"{location}.overflow_mode",
    )
    put_u8(
        data,
        0x95,
        1 if fields.get("relu_enable", False) else 0,
        f"{location}.activation_mode",
    )
    put_i32(
        data, 0x98, fields.get("output_zero_point", 0), f"{location}.output_zero_point"
    )
    put_u32(
        data, 0x9C, fields.get("requant_count", 0), f"{location}.requant_count"
    )
    put_u32(data, 0xA0, fields.get("bias_count", 0), f"{location}.bias_count")
    put_u8(data, 0xA4, fields.get("requant_mode", 0), f"{location}.requant_mode")
    put_u8(data, 0xA5, fields.get("residual_mode", 0), f"{location}.residual_mode")
    put_u8(
        data, 0xA6, fields.get("requant_entry_bytes", 8), f"{location}.requant_entry_bytes"
    )
    put_u32(
        data,
        0xA8,
        fields.get("requant_region_bytes", 0),
        f"{location}.requant_region_bytes",
    )


def encode_vector(
    data: bytearray,
    fields: Mapping[str, Any],
    location: str,
) -> None:
    for offset, name, default in (
        (0x40, "rows", None),
        (0x44, "length", None),
        (0x48, "valid_length", 0),
    ):
        value = fields.get(name, default)
        if value is None:
            raise fail(f"{location}.{name}", "is required")
        put_u32(data, offset, value, f"{location}.{name}")
    flags = 0
    for name, bit in (
        ("mask_enable", 0),
        ("mask_false_keep_dst", 1),
        ("src1_from_scalar0", 2),
        ("src2_from_scalar1", 3),
    ):
        flags |= bool_bit(fields, name, bit)
    put_u32(data, 0x4C, flags, f"{location}.flags")
    for offset, name in (
        (0x50, "src0_elem_stride_bytes"),
        (0x54, "src0_row_stride_bytes"),
        (0x58, "src1_elem_stride_bytes"),
        (0x5C, "src1_row_stride_bytes"),
        (0x60, "src2_elem_stride_bytes"),
        (0x64, "src2_row_stride_bytes"),
        (0x68, "dst_elem_stride_bytes"),
        (0x6C, "dst_row_stride_bytes"),
    ):
        put_u32(data, offset, fields.get(name, 0), f"{location}.{name}")
    put_i32(data, 0x70, fields.get("scalar0", 0), f"{location}.scalar0")
    put_i32(data, 0x74, fields.get("scalar1", 0), f"{location}.scalar1")
    broadcast = 0
    for shift, name in ((0, "broadcast0"), (2, "broadcast1"), (4, "broadcast2")):
        broadcast |= enum_value(
            BROADCAST_CODES,
            fields.get(name, "none"),
            f"{location}.{name}",
        ) << shift
    put_u8(data, 0x78, broadcast, f"{location}.broadcast")
    put_u8(
        data,
        0x79,
        enum_value(
            COMPARE_CODES,
            fields.get("compare_mode", "eq"),
            f"{location}.compare_mode",
        ),
        f"{location}.compare_mode",
    )
    put_u8(
        data,
        0x7A,
        enum_value(
            OVERFLOW_CODES,
            fields.get("overflow_mode", "saturate"),
            f"{location}.overflow_mode",
        ),
        f"{location}.overflow_mode",
    )
    put_u8(data, 0x7B, fields.get("mask_mode", 0), f"{location}.mask_mode")
    for offset, name in (
        (0x7C, "src0_nibble"),
        (0x7D, "src1_nibble"),
        (0x7E, "dst_nibble"),
        (0x7F, "src2_nibble"),
    ):
        put_u8(data, offset, fields.get(name, 0), f"{location}.{name}")
    for offset, name, default in (
        (0x80, "src0_scale_bits", 0x3F800000),
        (0x84, "src1_scale_bits", 0x3F800000),
        (0x88, "src2_scale_bits", 0x3F800000),
        (0x8C, "dst_scale_bits", 0x3F800000),
        (0x90, "mask_elem_stride_bytes", 0),
        (0x94, "mask_row_stride_bytes", 0),
    ):
        put_u32(data, offset, fields.get(name, default), f"{location}.{name}")


def encode_complex(
    data: bytearray,
    fields: Mapping[str, Any],
    location: str,
) -> None:
    for offset, name, default in (
        (0x40, "rows", None),
        (0x44, "length", None),
        (0x48, "valid_length", 0),
    ):
        value = fields.get(name, default)
        if value is None:
            raise fail(f"{location}.{name}", "is required")
        put_u32(data, offset, value, f"{location}.{name}")
    put_u32(
        data,
        0x4C,
        enum_value(
            FUNCTION_CODES, fields.get("function"), f"{location}.function"
        ),
        f"{location}.function",
    )
    for offset, name in (
        (0x50, "src0_row_stride_bytes"),
        (0x54, "src1_row_stride_bytes"),
        (0x58, "src2_row_stride_bytes"),
        (0x5C, "dst_row_stride_bytes"),
    ):
        put_u32(data, offset, fields.get(name, 0), f"{location}.{name}")
    put_u64(data, 0x60, fields.get("mask_addr", 0), f"{location}.mask_addr")
    put_u32(
        data,
        0x68,
        fields.get("mask_row_stride_bytes", 0),
        f"{location}.mask_row_stride_bytes",
    )
    put_u32(
        data,
        0x6C,
        enum_value(
            MASK_CODES, fields.get("mask_mode", "none"), f"{location}.mask_mode"
        ),
        f"{location}.mask_mode",
    )
    for offset, name, default in (
        (0x70, "src0_scale", 1.0),
        (0x74, "src1_scale", 1.0),
        (0x78, "src2_scale", 1.0),
        (0x7C, "dst_scale", 1.0),
    ):
        put_f32(data, offset, fields.get(name, default), f"{location}.{name}")
    for offset, name in (
        (0x80, "src0_zero_point"),
        (0x84, "src1_zero_point"),
        (0x88, "src2_zero_point"),
        (0x8C, "dst_zero_point"),
    ):
        put_i32(data, offset, fields.get(name, 0), f"{location}.{name}")
    put_f32(data, 0x90, fields.get("epsilon", 1e-5), f"{location}.epsilon")
    put_f32(
        data, 0x94, fields.get("input_clip_min", -16.0), f"{location}.input_clip_min"
    )
    put_f32(
        data, 0x98, fields.get("input_clip_max", 16.0), f"{location}.input_clip_max"
    )
    put_u8(data, 0x9C, fields.get("approx_mode", 0), f"{location}.approx_mode")
    put_u8(
        data,
        0x9D,
        enum_value(
            OVERFLOW_CODES,
            fields.get("overflow_mode", "saturate"),
            f"{location}.overflow_mode",
        ),
        f"{location}.overflow_mode",
    )
    put_u8(
        data, 0x9E, fields.get("all_mask_mode", 0), f"{location}.all_mask_mode"
    )
    put_u8(data, 0x9F, fields.get("stats_mode", 0), f"{location}.stats_mode")
    put_u32(data, 0xA0, fields.get("rotary_dim", 0), f"{location}.rotary_dim")
    put_u32(data, 0xA4, fields.get("position_base", 0), f"{location}.position_base")
    put_u32(data, 0xA8, fields.get("position_step", 0), f"{location}.position_step")
    put_u8(data, 0xAC, fields.get("pair_mode", 0), f"{location}.pair_mode")
    put_u32(
        data,
        0xB0,
        fields.get("scratch_request_elems", 0),
        f"{location}.scratch_request_elems",
    )
    put_u32(
        data,
        0xB4,
        fields.get("query_position_base", 0),
        f"{location}.query_position_base",
    )
    put_u32(
        data,
        0xB8,
        fields.get("key_position_base", 0),
        f"{location}.key_position_base",
    )
    put_u32(
        data,
        0xBC,
        fields.get("query_position_step", 0),
        f"{location}.query_position_step",
    )
    put_u64(
        data,
        0xC0,
        fields.get("valid_length_addr", 0),
        f"{location}.valid_length_addr",
    )
    put_u32(
        data,
        0xC8,
        fields.get("valid_length_stride_bytes", 0),
        f"{location}.valid_length_stride_bytes",
    )


def encode_descriptor(
    operation: Mapping[str, Any],
    engine: str,
    tensors: Mapping[str, Mapping[str, Any]],
    target: Mapping[str, Any],
    location: str,
) -> bytes:
    descriptor_object = object_value(
        operation.get("descriptor", {}), f"{location}.descriptor"
    )
    size = DESCRIPTOR_BYTES[engine]
    raw_hex = descriptor_object.get("raw_hex")
    if raw_hex is not None:
        if not isinstance(raw_hex, str):
            raise fail(
                f"{location}.descriptor.raw_hex",
                "must be a hexadecimal string",
            )
        try:
            raw = bytes.fromhex(raw_hex)
        except ValueError as error:
            raise fail(
                f"{location}.descriptor.raw_hex",
                "contains invalid hexadecimal data",
            ) from error
        if len(raw) != size:
            raise fail(
                f"{location}.descriptor.raw_hex",
                f"must contain exactly {size} bytes",
            )
        return raw

    data = bytearray(size)
    refs = compile_common(data, engine, operation, tensors, location)
    fields = object_value(
        descriptor_object.get(engine, {}),
        f"{location}.descriptor.{engine}",
    )
    if engine == "control":
        encode_control(data, fields, f"{location}.descriptor.control")
    elif engine == "dma":
        encode_dma(data, fields, refs, f"{location}.descriptor.dma")
    elif engine == "matrix":
        encode_matrix(data, fields, target, f"{location}.descriptor.matrix")
    elif engine == "vector":
        encode_vector(data, fields, f"{location}.descriptor.vector")
    elif engine == "complex":
        encode_complex(data, fields, f"{location}.descriptor.complex")
    return bytes(data)


def normalize_tensors(
    document: Mapping[str, Any],
) -> dict[str, Mapping[str, Any]]:
    source = object_value(document.get("tensors", {}), "tensors")
    result: dict[str, Mapping[str, Any]] = {}
    for name, value in source.items():
        if not isinstance(name, str) or not name:
            raise fail("tensors", "tensor names must be non-empty strings")
        tensor = object_value(value, f"tensors.{name}")
        address = tensor_address(tensor, f"tensors.{name}")
        space = tensor.get("space", "l1")
        enum_value(SPACE_CODES, space, f"tensors.{name}.space")
        enum_value(DTYPE_CODES, tensor.get("dtype"), f"tensors.{name}.dtype")
        if isinstance(space, str) and space.lower() == "l1" and address >= (1 << 24):
            raise fail(f"tensors.{name}.addr", "L1 address uses at most 24 bits")
        if "region_bytes" in tensor:
            parse_int(
                tensor["region_bytes"],
                f"tensors.{name}.region_bytes",
                0,
                0xFFFFFFFFFFFFFFFF,
            )
        result[name] = tensor
    return result


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
        raw = list_value(
            operation.get("depends_on", []),
            f"operations[{index}].depends_on",
        )
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
            values.append(dependency)
            if dependency not in needed:
                needed.append(dependency)
        if len(values) > 2:
            raise fail(
                f"operations[{index}].depends_on",
                "hardware CMD supports at most two direct dependencies",
            )
        dependencies[name] = values

    signal_by_name: dict[str, int] = {}
    used_events: set[int] = set()
    for index, operation in enumerate(operations):
        name = str(operation["name"])
        if "signal_event" in operation:
            event = parse_event(
                operation["signal_event"],
                f"operations[{index}].signal_event",
            )
            signal_by_name[name] = event
            if event != EVENT_NONE:
                if event in used_events:
                    raise fail(
                        f"operations[{index}].signal_event",
                        "event reference is already produced by another operation",
                    )
                used_events.add(event)

    next_event_id = 0
    for name in needed:
        if name in signal_by_name and signal_by_name[name] != EVENT_NONE:
            continue
        while next_event_id in used_events:
            next_event_id += 1
        if next_event_id > MAX_EVENT_ID:
            raise fail("operations", "not enough event IDs")
        signal_by_name[name] = next_event_id
        used_events.add(next_event_id)
        next_event_id += 1

    waits: dict[str, tuple[int, int]] = {}
    for index, operation in enumerate(operations):
        name = str(operation["name"])
        if "wait_events" in operation and dependencies[name]:
            raise fail(
                f"operations[{index}]",
                "use either depends_on or wait_events, not both",
            )
        if "wait_events" in operation:
            raw = list_value(
                operation["wait_events"],
                f"operations[{index}].wait_events",
            )
            if len(raw) > 2:
                raise fail(
                    f"operations[{index}].wait_events",
                    "supports at most two events",
                )
            parsed = [
                parse_event(
                    value,
                    f"operations[{index}].wait_events[{event_index}]",
                )
                for event_index, value in enumerate(raw)
            ]
        else:
            parsed = [
                signal_by_name[dependency]
                for dependency in dependencies[name]
            ]
        parsed += [EVENT_NONE] * (2 - len(parsed))
        waits[name] = (parsed[0], parsed[1])
        signal_by_name.setdefault(name, EVENT_NONE)
    return signal_by_name, waits


def compile_document(
    document: Mapping[str, Any],
) -> tuple[list[CompiledOperation], bytes, bytes]:
    schema = parse_int(document.get("schema_version"), "schema_version", 1, 1)
    if schema != SCHEMA_VERSION:
        raise fail("schema_version", f"unsupported version {schema}")
    target = object_value(document.get("target", {}), "target")
    if target.get("command_format", COMMAND_FORMAT) != COMMAND_FORMAT:
        raise fail("target.command_format", f"must be {COMMAND_FORMAT!r}")
    descriptor_base = parse_int(
        target.get("descriptor_base"),
        "target.descriptor_base",
        0,
        (1 << 48) - 1,
    )
    if descriptor_base & 0x3F:
        raise fail("target.descriptor_base", "must be 64-byte aligned")
    tensors = normalize_tensors(document)
    raw_operations = list_value(document.get("operations"), "operations")
    operations = [
        object_value(value, f"operations[{index}]")
        for index, value in enumerate(raw_operations)
    ]
    signals, waits = allocate_dependency_events(operations)

    command_ids: set[int] = set()
    compiled: list[CompiledOperation] = []
    descriptor_image = bytearray()
    command_image = bytearray()
    for index, operation in enumerate(operations):
        location = f"operations[{index}]"
        name = str(operation["name"])
        engine_value = operation.get("engine")
        if not isinstance(engine_value, str):
            raise fail(f"{location}.engine", "must be a string")
        engine = engine_value.lower()
        if engine not in ENGINE_CODES:
            raise fail(
                f"{location}.engine",
                f"unsupported engine {engine_value!r}",
            )
        opcode_value = operation.get("opcode")
        if isinstance(opcode_value, int) and not isinstance(opcode_value, bool):
            opcode = parse_int(opcode_value, f"{location}.opcode", 0, 0xFF)
        elif isinstance(opcode_value, str):
            opcode_name = opcode_value.upper()
            if opcode_name not in OPCODES[engine]:
                raise fail(
                    f"{location}.opcode",
                    f"use one of {', '.join(OPCODES[engine])}",
                )
            opcode = OPCODES[engine][opcode_name]
        else:
            raise fail(
                f"{location}.opcode",
                "must be an opcode name or integer",
            )
        command_id = parse_int(
            operation.get("command_id", index),
            f"{location}.command_id",
            0,
            MAX_COMMAND_ID,
        )
        if command_id in command_ids:
            raise fail(f"{location}.command_id", "duplicate command ID")
        command_ids.add(command_id)

        descriptor_offset = align_up(len(descriptor_image), 64)
        if descriptor_offset > len(descriptor_image):
            descriptor_image.extend(
                b"\0" * (descriptor_offset - len(descriptor_image))
            )
        descriptor = encode_descriptor(
            operation, engine, tensors, target, location
        )
        descriptor_addr = descriptor_base + descriptor_offset
        if descriptor_addr + len(descriptor) > (1 << 48):
            raise fail(
                location,
                "Descriptor image exceeds 48-bit address range",
            )
        descriptor_image.extend(descriptor)
        flags = header_flags(
            object_value(operation.get("flags", {}), f"{location}.flags"),
            f"{location}.flags",
        )
        signal = signals[name]
        wait0, wait1 = waits[name]
        command = encode_command128(
            descriptor_addr,
            command_id,
            ENGINE_CODES[engine],
            opcode,
            flags,
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
                opcode=opcode,
                descriptor_addr=descriptor_addr,
                descriptor_offset=descriptor_offset,
                descriptor=descriptor,
                command=command,
                wait_events=(wait0, wait1),
                signal_event=signal,
                user_tag=parse_int(
                    operation.get("user_tag", 0),
                    f"{location}.user_tag",
                    0,
                    0xFFFFFFFF,
                ),
            )
        )
    return compiled, bytes(command_image), bytes(descriptor_image)


def sha256_bytes(content: bytes) -> str:
    return hashlib.sha256(content).hexdigest()


def build_output_manifest(
    source_path: Path,
    source_document: Mapping[str, Any],
    operations: list[CompiledOperation],
    command_name: str,
    descriptor_name: str,
    command_image: bytes,
    descriptor_image: bytes,
) -> bytes:
    output = {
        "artifact_version": 1,
        "source": source_path.name,
        "source_sha256": sha256_bytes(source_path.read_bytes()),
        "target": source_document["target"],
        "command_format": COMMAND_FORMAT,
        "command_record_bytes": 16,
        "command_count": len(operations),
        "command_file": command_name,
        "command_sha256": sha256_bytes(command_image),
        "descriptor_file": descriptor_name,
        "descriptor_bytes": len(descriptor_image),
        "descriptor_sha256": sha256_bytes(descriptor_image),
        "operations": [
            {
                "name": operation.name,
                "command_id": operation.command_id,
                "engine": operation.engine,
                "opcode": operation.opcode,
                "descriptor_addr": f"0x{operation.descriptor_addr:012x}",
                "descriptor_offset": operation.descriptor_offset,
                "descriptor_bytes": len(operation.descriptor),
                "wait_events": [
                    event_to_json(operation.wait_events[0]),
                    event_to_json(operation.wait_events[1]),
                ],
                "signal_event": event_to_json(operation.signal_event),
                "user_tag": operation.user_tag,
                "command_low": (
                    f"0x{struct.unpack_from('<Q', operation.command, 0)[0]:016x}"
                ),
                "command_high": (
                    f"0x{struct.unpack_from('<Q', operation.command, 8)[0]:016x}"
                ),
            }
            for operation in operations
        ],
    }
    return (
        json.dumps(
            output,
            indent=2,
            sort_keys=True,
            ensure_ascii=True,
            allow_nan=False,
        )
        + "\n"
    ).encode("utf-8")


def c_array(content: bytes, name: str) -> str:
    lines = []
    for start in range(0, len(content), 12):
        values = ", ".join(
            f"0x{value:02x}" for value in content[start : start + 12]
        )
        lines.append(f"    {values},")
    return (
        f"static const unsigned char {name}[] = {{\n"
        + "\n".join(lines)
        + "\n};\n"
        + f"static const unsigned long {name}_bytes = {len(content)}ul;\n"
    )


def build_c_header(
    stem: str,
    command_image: bytes,
    descriptor_image: bytes,
) -> bytes:
    symbol = "".join(
        character if character.isalnum() else "_" for character in stem
    )
    if not symbol or symbol[0].isdigit():
        symbol = f"model_{symbol}"
    guard = f"NPU_MODEL_{symbol.upper()}_H"
    content = (
        f"#ifndef {guard}\n#define {guard}\n\n"
        + c_array(command_image, f"{symbol}_commands")
        + "\n"
        + c_array(descriptor_image, f"{symbol}_descriptors")
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
        raise CompileError(
            f"{input_path}:{error.lineno}:{error.colno}: {error.msg}"
        ) from error
    document = object_value(value, "document")
    operations, command_image, descriptor_image = compile_document(document)
    stem = input_path.stem
    command_name = f"{stem}.cmd.bin"
    descriptor_name = f"{stem}.desc.bin"
    artifacts = [
        Artifact(output_dir / command_name, command_image),
        Artifact(output_dir / descriptor_name, descriptor_image),
        Artifact(
            output_dir / f"{stem}.manifest.json",
            build_output_manifest(
                input_path,
                document,
                operations,
                command_name,
                descriptor_name,
                command_image,
                descriptor_image,
            ),
        ),
    ]
    if emit_c_header:
        artifacts.append(
            Artifact(
                output_dir / f"{stem}.npu.h",
                build_c_header(stem, command_image, descriptor_image),
            )
        )
    return artifacts, operations


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Assemble normalized NPU JSON IR into a 128-bit command stream, "
            "Descriptor image, and artifact manifest."
        )
    )
    parser.add_argument("input", type=Path, help="normalized model JSON file")
    parser.add_argument(
        "-o",
        "--output-dir",
        type=Path,
        required=True,
        help="artifact directory",
    )
    parser.add_argument(
        "--emit-c-header",
        action="store_true",
        help="also emit commands and Descriptors as C byte arrays",
    )
    parser.add_argument(
        "--check",
        action="store_true",
        help="verify that every requested artifact already matches",
    )
    return parser.parse_args(argv)


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    if not args.input.is_file():
        raise CompileError(f"input is not a file: {args.input}")
    if args.output_dir.exists() and not args.output_dir.is_dir():
        raise CompileError(
            f"output path is not a directory: {args.output_dir}"
        )
    artifacts, operations = output_artifacts(
        args.input, args.output_dir, args.emit_c_header
    )
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
