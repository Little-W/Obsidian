#!/usr/bin/env python3
"""Artifact, C-package, manifest, JSON I/O, and CLI support for model compile.

This module deliberately depends only on the assembler and on values supplied
by the high-level compiler.  Keeping graph analysis and operator lowering out
of this file avoids an import cycle while preserving ``npu_model_compiler`` as
the public entry point.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path
from typing import Any, Callable, Mapping, Sequence

sys.dont_write_bytecode = True

_HERE = Path(__file__).resolve().parent
if str(_HERE) not in sys.path:
    sys.path.insert(0, str(_HERE))

import npu_assembler


MAX_MODEL_RANK = 5


def _artifact_integer(value: Any, location: str) -> int:
    if isinstance(value, bool) or not isinstance(value, int):
        raise ValueError(f"{location} must be an integer")
    return value


def _check_global_region(
    address: Any,
    size: Any,
    location: str,
    address_limit: int,
) -> None:
    parsed_address = _artifact_integer(address, f"{location}.address")
    parsed_size = _artifact_integer(size, f"{location}.bytes")
    if parsed_address < 0 or parsed_address >= address_limit:
        raise ValueError(
            f"{location}.address must be below "
            f"2^{npu_assembler.AXI_ADDR_BITS}"
        )
    if parsed_size < 0:
        raise ValueError(f"{location}.bytes must be nonnegative")
    if parsed_size > address_limit - parsed_address:
        raise ValueError(
            f"{location} ends at 0x{parsed_address + parsed_size:x}, "
            f"outside the {npu_assembler.AXI_ADDR_BITS}-bit AXI "
            "address range"
        )


def validate_model_global_addresses(result: Any) -> None:
    runtime = result.runtime
    bits = _artifact_integer(
        runtime.get("axi_addr_bits"), "runtime.axi_addr_bits"
    )
    if bits != npu_assembler.AXI_ADDR_BITS:
        raise ValueError(
            "runtime.axi_addr_bits must equal "
            f"{npu_assembler.AXI_ADDR_BITS}"
        )
    address_limit = 1 << bits
    ddr_base = _artifact_integer(runtime.get("ddr_base"), "runtime.ddr_base")
    ddr_bytes = _artifact_integer(
        runtime.get("ddr_bytes"), "runtime.ddr_bytes"
    )
    allocation_end = _artifact_integer(
        runtime.get("ddr_allocation_end"),
        "runtime.ddr_allocation_end",
    )
    if ddr_base < 0 or ddr_base >= address_limit:
        raise ValueError(
            f"runtime.ddr_base must be below 2^{bits}"
        )
    if ddr_bytes <= ddr_base or ddr_bytes > address_limit:
        raise ValueError(
            f"runtime.ddr_bytes must be above ddr_base and at most 2^{bits}"
        )
    if allocation_end < ddr_base or allocation_end > ddr_bytes:
        raise ValueError(
            "runtime.ddr_allocation_end must be within the configured "
            "DDR range"
        )

    _check_global_region(
        runtime["constant_base_ddr"],
        runtime["constant_bytes"],
        "runtime.constants",
        address_limit,
    )
    for group_name in ("inputs", "outputs"):
        for index, binding in enumerate(runtime[group_name]):
            _check_global_region(
                binding["ddr_addr"],
                binding["bytes"],
                f"runtime.{group_name}[{index}]",
                address_limit,
            )
    for index, entry in enumerate(runtime.get("memory_plan", [])):
        if entry.get("ddr_addr") is None:
            continue
        _check_global_region(
            entry["ddr_addr"],
            entry["bytes"],
            f"runtime.memory_plan[{index}]",
            address_limit,
        )

    bases = runtime.get("gaddr_bases")
    if not isinstance(bases, dict):
        raise ValueError("runtime.gaddr_bases must be an object")
    expected_names = set(npu_assembler.GADDR_BASE_CODES)
    if set(bases) != expected_names:
        raise ValueError(
            "runtime.gaddr_bases must contain zero, input, weight, work, "
            "output, and kv"
        )
    for name in npu_assembler.GADDR_BASE_CODES:
        _check_global_region(
            bases[name],
            0,
            f"runtime.gaddr_bases.{name}",
            address_limit,
        )
        if int(bases[name]) & 0x7:
            raise ValueError(
                f"runtime.gaddr_bases.{name} must be aligned to 8 bytes"
            )


def sha256_bytes(content: bytes) -> str:
    return hashlib.sha256(content).hexdigest()


def canonical_json(value: Any) -> bytes:
    return (
        json.dumps(
            value,
            indent=2,
            sort_keys=True,
            ensure_ascii=True,
            allow_nan=False,
        )
        + "\n"
    ).encode("utf-8")


def c_identifier(value: str) -> str:
    result = "".join(
        character if character.isalnum() else "_" for character in value
    )
    if not result or result[0].isdigit():
        result = f"model_{result}"
    return result


def c_package_stem(value: str) -> str:
    """Return a readable C package name without a repeated model suffix."""

    return value if value.lower().endswith("_model") else f"{value}_model"


def c_string(value: str) -> str:
    return json.dumps(value, ensure_ascii=True)


def c_byte_array(content: bytes, name: str) -> str:
    return npu_assembler.c_array(content, name)


def _storage_count(logical_count: int) -> int:
    """Return a standard-C array extent for a possibly empty logical array."""

    return max(1, logical_count)


def _byte_initializer(content: bytes, *, indent: str = "    ") -> str:
    if not content:
        return f"{indent}0x00,"
    rows: list[str] = []
    for start in range(0, len(content), 12):
        values = ", ".join(
            f"0x{value:02x}" for value in content[start : start + 12]
        )
        rows.append(f"{indent}{values},")
    return "\n".join(rows)


def _command_rows(content: bytes) -> str:
    if len(content) % 16 != 0:
        raise ValueError(
            "The instruction image size must be an integer multiple of 16 bytes"
        )
    if not content:
        return "    {UINT64_C(0), UINT64_C(0)},"
    rows: list[str] = []
    for offset in range(0, len(content), 16):
        low, high = struct.unpack_from("<QQ", content, offset)
        rows.append(
            "    {"
            f"UINT64_C(0x{low:016x}), UINT64_C(0x{high:016x})"
            "},"
        )
    return "\n".join(rows)


def _binding_rows(
    values: Sequence[Mapping[str, Any]],
    *,
    max_rank: int,
) -> str:
    if not values:
        return "    {0},"
    rows: list[str] = []
    for value in values:
        value_shape = list(value["shape"])
        if len(value_shape) > max_rank:
            raise ValueError(
                f"tensor {value['name']!r} rank {len(value_shape)} "
                f"exceeds generated C rank limit {max_rank}"
            )
        shape = value_shape + [0] * (max_rank - len(value_shape))
        rows.append(
            "    {"
            + f"{c_string(str(value['name']))}, "
            + f"UINT64_C(0x{int(value['ddr_addr']):x}), "
            + f"UINT64_C(0x{int(value['l1_addr']):x}), "
            + f"{int(value['bytes'])}u, "
            + f"{npu_assembler.DTYPE_CODES[str(value['dtype'])]}u, "
            + f"{len(value_shape)}u, "
            + "{"
            + ", ".join(f"{int(item)}u" for item in shape)
            + "}},"
        )
    return "\n".join(rows)


def _operation_rows(values: Sequence[Mapping[str, Any]]) -> str:
    if not values:
        return "    {0},"
    return "\n".join(
        "    {"
        + f"{c_string(str(item['name']))}, "
        + f"{c_string(str(item['high_level_node']))}, "
        + f"{c_string(str(item['engine']))}, "
        + f"{c_string(str(item['opcode']))}, "
        + f"{int(item['command_id'])}u"
        + "},"
        for item in values
    )


def _batch_metadata(
    batches: Sequence[Sequence[int]],
    execution: Sequence[Mapping[str, Any]] | None = None,
) -> tuple[list[tuple[int, int, int, int, int]], list[int]]:
    rows: list[tuple[int, int, int, int, int]] = []
    command_ids: list[int] = []
    if execution is not None and len(execution) != len(batches):
        raise ValueError("batch execution metadata length mismatch")
    for index, batch in enumerate(batches):
        offset = len(command_ids)
        command_ids.extend(int(value) for value in batch)
        metadata = {} if execution is None else execution[index]
        rows.append(
            (
                offset,
                len(batch),
                int(bool(metadata.get("host_sync_before", index != 0))),
                int(bool(metadata.get("host_sync_after", True))),
                int(bool(metadata.get("contains_event_rearm", False))),
            )
        )
    return rows, command_ids


def build_model_c_header(
    stem: str,
    result: Any,
    *,
    max_rank: int = MAX_MODEL_RANK,
) -> bytes:
    validate_model_global_addresses(result)
    package_stem = c_package_stem(stem)
    symbol = c_identifier(package_stem)
    upper = symbol.upper()
    guard = f"NPU_COMPILED_MODEL_{upper}_H"
    inputs = result.runtime["inputs"]
    outputs = result.runtime["outputs"]
    operations = result.runtime["operations"]
    batches = result.runtime["batches"]
    batch_execution = result.runtime["batch_execution"]
    command_count = len(result.command_image) // 16
    weight_bytes = len(result.constant_image)
    _batch_rows, batch_ids = _batch_metadata(batches, batch_execution)
    content = (
        f"#ifndef {guard}\n#define {guard}\n\n"
        "#include <stdint.h>\n\n"
        "#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n"
        "typedef struct {\n"
        "    uint64_t low;\n"
        "    uint64_t high;\n"
        f"}} {symbol}_cmd128_t;\n\n"
        "typedef struct {\n"
        "    const char *name;\n"
        "    uint64_t ddr_addr;\n"
        "    uint64_t l1_addr;\n"
        "    uint32_t bytes;\n"
        "    uint8_t dtype;\n"
        "    uint8_t rank;\n"
        f"    uint32_t shape[{max_rank}];\n"
        f"}} {symbol}_binding_t;\n\n"
        "typedef struct {\n"
        "    const char *name;\n"
        "    const char *high_level_node;\n"
        "    const char *engine;\n"
        "    const char *opcode;\n"
        "    uint16_t command_id;\n"
        f"}} {symbol}_operation_t;\n\n"
        "typedef struct {\n"
        "    uint32_t command_id_offset;\n"
        "    uint32_t command_count;\n"
        "    uint8_t host_sync_before;\n"
        "    uint8_t host_sync_after;\n"
        "    uint8_t contains_event_rearm;\n"
        "    uint8_t reserved;\n"
        f"}} {symbol}_command_batch_t;\n\n"
        "typedef struct {\n"
        "    const char *model_name;\n"
        "    const char *command_format;\n"
        "    const "
        f"{symbol}_cmd128_t *commands;\n"
        "    uint32_t command_count;\n"
        "    const uint8_t *weights;\n"
        "    uint32_t weight_bytes;\n"
        "    uint64_t weight_base_ddr;\n"
        "    uint64_t weight_base_l1;\n"
        "    uint64_t gaddr_bases[6];\n"
        "    uint8_t axi_addr_bits;\n"
        f"    const {symbol}_binding_t *inputs;\n"
        "    uint32_t input_count;\n"
        f"    const {symbol}_binding_t *outputs;\n"
        "    uint32_t output_count;\n"
        f"    const {symbol}_operation_t *operations;\n"
        "    uint32_t operation_count;\n"
        f"    const {symbol}_command_batch_t *command_batches;\n"
        "    uint32_t command_batch_count;\n"
        "    const uint16_t *batch_command_ids;\n"
        "    uint32_t batch_command_id_count;\n"
        f"}} {symbol}_config_t;\n\n"
        f"#define {upper}_COMMAND_BITS 128u\n"
        f"#define {upper}_AXI_ADDR_BITS "
        f"{npu_assembler.AXI_ADDR_BITS}u\n"
        f"#define {upper}_COMMAND_COUNT {command_count}u\n"
        f"#define {upper}_COMMAND_STORAGE_COUNT "
        f"{_storage_count(command_count)}u\n"
        f"#define {upper}_WEIGHT_BYTES {weight_bytes}u\n"
        f"#define {upper}_WEIGHT_STORAGE_BYTES "
        f"{_storage_count(weight_bytes)}u\n"
        f"#define {upper}_WEIGHT_BASE_DDR "
        f"UINT64_C(0x{int(result.runtime['constant_base_ddr']):x})\n"
        f"#define {upper}_WEIGHT_BASE_L1 "
        f"UINT64_C(0x{int(result.runtime['constant_base_l1']):x})\n"
        f"#define {upper}_INPUT_COUNT {len(inputs)}u\n"
        f"#define {upper}_INPUT_STORAGE_COUNT "
        f"{_storage_count(len(inputs))}u\n"
        f"#define {upper}_OUTPUT_COUNT {len(outputs)}u\n"
        f"#define {upper}_OUTPUT_STORAGE_COUNT "
        f"{_storage_count(len(outputs))}u\n"
        f"#define {upper}_OPERATION_COUNT {len(operations)}u\n"
        f"#define {upper}_OPERATION_STORAGE_COUNT "
        f"{_storage_count(len(operations))}u\n"
        f"#define {upper}_COMMAND_BATCH_COUNT {len(batches)}u\n"
        f"#define {upper}_COMMAND_BATCH_STORAGE_COUNT "
        f"{_storage_count(len(batches))}u\n"
        f"#define {upper}_BATCH_COMMAND_ID_COUNT {len(batch_ids)}u\n"
        f"#define {upper}_BATCH_COMMAND_ID_STORAGE_COUNT "
        f"{_storage_count(len(batch_ids))}u\n\n"
        f"extern const {symbol}_cmd128_t {symbol}_commands"
        f"[{upper}_COMMAND_STORAGE_COUNT];\n"
        f"extern const uint8_t {symbol}_weights"
        f"[{upper}_WEIGHT_STORAGE_BYTES];\n"
        f"extern const {symbol}_binding_t {symbol}_inputs"
        f"[{upper}_INPUT_STORAGE_COUNT];\n"
        f"extern const {symbol}_binding_t {symbol}_outputs"
        f"[{upper}_OUTPUT_STORAGE_COUNT];\n"
        f"extern const {symbol}_operation_t {symbol}_operations"
        f"[{upper}_OPERATION_STORAGE_COUNT];\n"
        f"extern const {symbol}_command_batch_t {symbol}_command_batches"
        f"[{upper}_COMMAND_BATCH_STORAGE_COUNT];\n"
        f"extern const uint16_t {symbol}_batch_command_ids"
        f"[{upper}_BATCH_COMMAND_ID_STORAGE_COUNT];\n"
        f"extern const {symbol}_config_t {symbol}_config;\n\n"
        "#ifdef __cplusplus\n}\n#endif\n\n"
        + f"#endif /* {guard} */\n"
    )
    return content.encode("ascii")


def build_model_c_source(
    stem: str,
    result: Any,
    *,
    max_rank: int = MAX_MODEL_RANK,
) -> bytes:
    validate_model_global_addresses(result)
    package_stem = c_package_stem(stem)
    symbol = c_identifier(package_stem)
    upper = symbol.upper()
    inputs = result.runtime["inputs"]
    outputs = result.runtime["outputs"]
    operations = result.runtime["operations"]
    batches = result.runtime["batches"]
    batch_execution = result.runtime["batch_execution"]
    batch_rows, batch_ids = _batch_metadata(batches, batch_execution)
    gaddr_bases = [
        int(result.runtime["gaddr_bases"][name])
        for name, _selector in sorted(
            npu_assembler.GADDR_BASE_CODES.items(),
            key=lambda item: item[1],
        )
    ]
    gaddr_base_row = (
        "    {"
        + ", ".join(
            f"UINT64_C(0x{address:x})" for address in gaddr_bases
        )
        + "},\n"
    )
    command_batches = (
        "\n".join(
            (
                f"    {{{offset}u, {count}u, {sync_before}u, "
                f"{sync_after}u, {contains_rearm}u, 0u}},"
            )
            for (
                offset,
                count,
                sync_before,
                sync_after,
                contains_rearm,
            ) in batch_rows
        )
        if batch_rows
        else "    {0},"
    )
    batch_id_rows = (
        "    " + ", ".join(f"{value}u" for value in batch_ids) + ","
        if batch_ids
        else "    0u,"
    )
    header_name = f"{package_stem}.h"
    content = (
        f"#include {c_string(header_name)}\n\n"
        "#if defined(_MSC_VER)\n"
        "#define NPU_MODEL_ALIGN(bytes) __declspec(align(bytes))\n"
        "#elif defined(__GNUC__) || defined(__clang__)\n"
        "#define NPU_MODEL_ALIGN(bytes) "
        "__attribute__((aligned(bytes)))\n"
        "#else\n"
        "#define NPU_MODEL_ALIGN(bytes) _Alignas(bytes)\n"
        "#endif\n\n"
        f"NPU_MODEL_ALIGN(16) const {symbol}_cmd128_t {symbol}_commands"
        f"[{upper}_COMMAND_STORAGE_COUNT] = {{\n"
        + _command_rows(result.command_image)
        + "\n};\n\n"
        f"NPU_MODEL_ALIGN(256) const uint8_t {symbol}_weights"
        f"[{upper}_WEIGHT_STORAGE_BYTES] = {{\n"
        + _byte_initializer(result.constant_image)
        + "\n};\n\n"
        f"const {symbol}_binding_t {symbol}_inputs"
        f"[{upper}_INPUT_STORAGE_COUNT] = {{\n"
        + _binding_rows(inputs, max_rank=max_rank)
        + "\n};\n\n"
        f"const {symbol}_binding_t {symbol}_outputs"
        f"[{upper}_OUTPUT_STORAGE_COUNT] = {{\n"
        + _binding_rows(outputs, max_rank=max_rank)
        + "\n};\n\n"
        f"const {symbol}_operation_t {symbol}_operations"
        f"[{upper}_OPERATION_STORAGE_COUNT] = {{\n"
        + _operation_rows(operations)
        + "\n};\n\n"
        f"const {symbol}_command_batch_t {symbol}_command_batches"
        f"[{upper}_COMMAND_BATCH_STORAGE_COUNT] = {{\n"
        + command_batches
        + "\n};\n\n"
        f"const uint16_t {symbol}_batch_command_ids"
        f"[{upper}_BATCH_COMMAND_ID_STORAGE_COUNT] = {{\n"
        + batch_id_rows
        + "\n};\n\n"
        f"const {symbol}_config_t {symbol}_config = {{\n"
        f"    {c_string(str(result.model_name))},\n"
        f"    {c_string(str(result.runtime['command_format']))},\n"
        f"    {symbol}_commands,\n"
        f"    {upper}_COMMAND_COUNT,\n"
        f"    {symbol}_weights,\n"
        f"    {upper}_WEIGHT_BYTES,\n"
        f"    {upper}_WEIGHT_BASE_DDR,\n"
        f"    {upper}_WEIGHT_BASE_L1,\n"
        + gaddr_base_row
        + f"    {upper}_AXI_ADDR_BITS,\n"
        f"    {symbol}_inputs,\n"
        f"    {upper}_INPUT_COUNT,\n"
        f"    {symbol}_outputs,\n"
        f"    {upper}_OUTPUT_COUNT,\n"
        f"    {symbol}_operations,\n"
        f"    {upper}_OPERATION_COUNT,\n"
        f"    {symbol}_command_batches,\n"
        f"    {upper}_COMMAND_BATCH_COUNT,\n"
        f"    {symbol}_batch_command_ids,\n"
        f"    {upper}_BATCH_COMMAND_ID_COUNT,\n"
        "};\n"
    )
    return content.encode("ascii")


def build_model_manifest(
    source_path: Path,
    result: Any,
    file_contents: Mapping[str, bytes],
) -> bytes:
    validate_model_global_addresses(result)
    return canonical_json(
        {
            "artifact_version": 2,
            "model_name": result.model_name,
            "source": source_path.name,
            "source_sha256": sha256_bytes(source_path.read_bytes()),
            "deployment_format": "c-model-package-v1",
            "pipeline": [
                "high-level-model",
                "low-level-json-ir",
                "npu-assembler",
                "cmd128",
                "c-model-package",
            ],
            "command_format": npu_assembler.COMMAND_FORMAT,
            "axi_addr_bits": result.runtime["axi_addr_bits"],
            "gaddr_bases": result.runtime["gaddr_bases"],
            "ddr_base": result.runtime["ddr_base"],
            "ddr_bytes": result.runtime["ddr_bytes"],
            "ddr_allocation_end": result.runtime[
                "ddr_allocation_end"
            ],
            "command_count": len(result.assembled_operations),
            "external_descriptor_bytes": 0,
            "weight_bytes": len(result.constant_image),
            "command_batches": result.runtime["batches"],
            "batch_execution": result.runtime["batch_execution"],
            "artifacts": {
                name: {
                    "bytes": len(content),
                    "sha256": sha256_bytes(content),
                }
                for name, content in sorted(file_contents.items())
            },
            "high_level_operators": [
                {
                    "name": operator.name,
                    "type": operator.op_type,
                    "inputs": list(operator.inputs),
                    "outputs": list(operator.outputs),
                }
                for operator in result.operators
            ],
            "lowered_operations": result.runtime["operations"],
        }
    )


def output_artifacts(
    input_path: Path,
    target: Any,
    emit_raw: bool,
    *,
    load_document: Callable[[Path], Mapping[str, Any]],
    compile_document: Callable[..., Any],
    max_rank: int = MAX_MODEL_RANK,
) -> tuple[dict[str, bytes], Any]:
    document = load_document(input_path)
    result = compile_document(
        document, target, source_name=input_path.name
    )
    stem = input_path.stem
    package_stem = c_package_stem(stem)
    files: dict[str, bytes] = {
        f"{package_stem}.h": build_model_c_header(
            stem, result, max_rank=max_rank
        ),
        f"{package_stem}.c": build_model_c_source(
            stem, result, max_rank=max_rank
        ),
    }
    if emit_raw:
        files.update(
            {
                f"{stem}.npuasm.json": canonical_json(result.low_ir),
                f"{stem}.cmd.bin": result.command_image,
                f"{stem}.const.bin": result.constant_image,
                f"{stem}.runtime.json": canonical_json(result.runtime),
            }
        )
    files[f"{stem}.manifest.json"] = build_model_manifest(
        input_path, result, files
    )
    return files, result


def unique_object(
    pairs: list[tuple[str, Any]],
    *,
    error_type: type[Exception] = ValueError,
) -> dict[str, Any]:
    result: dict[str, Any] = {}
    for name, value in pairs:
        if name in result:
            raise error_type(f"duplicate JSON key {name!r}")
        result[name] = value
    return result


def load_json_document(
    path: Path,
    *,
    error_type: type[Exception] = ValueError,
) -> Mapping[str, Any]:
    try:
        value = json.loads(
            path.read_text(encoding="utf-8"),
            object_pairs_hook=lambda pairs: unique_object(
                pairs, error_type=error_type
            ),
        )
    except json.JSONDecodeError as error:
        raise error_type(
            f"{path}:{error.lineno}:{error.colno}: {error.msg}"
        ) from error
    if not isinstance(value, dict):
        raise error_type("document: must be a JSON object")
    return value


def parse_cli_int(value: str) -> int:
    try:
        return int(value, 0)
    except ValueError as error:
        raise argparse.ArgumentTypeError(
            f"invalid integer {value!r}"
        ) from error


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Compile Keras, PyTorch, TFLite, ONNX, or high-level JSON input "
            "through low-level JSON IR and the 128-bit instruction assembler, then "
            "generate a deployable C model package."
        )
    )
    parser.add_argument("input", type=Path, help="model file")
    parser.add_argument(
        "-o",
        "--output-dir",
        type=Path,
        required=True,
        help="artifact directory",
    )
    parser.add_argument(
        "--emit-raw",
        action="store_true",
        help=(
            "also emit low-level JSON IR and raw command, weight, and "
            "runtime files for debugging"
        ),
    )
    parser.add_argument(
        "--input-format",
        choices=("auto", "json", "keras", "pytorch", "tflite", "onnx"),
        default="auto",
        help="input format; auto uses the file suffix",
    )
    parser.add_argument(
        "--model-dtype",
        choices=("int4", "int8", "int16"),
        default="int8",
        help="integer tensor type used for imported framework models",
    )
    parser.add_argument(
        "--fraction-bits",
        type=int,
        default=6,
        help="fractional bits used for imported framework tensors",
    )
    parser.add_argument(
        "--batch-size",
        type=int,
        default=1,
        help="value used for a dynamic leading model dimension",
    )
    parser.add_argument(
        "--input-shape",
        action="append",
        default=[],
        metavar="NAME=D0,D1,...",
        help=(
            "replace one dynamic input shape; may be repeated, and a numeric "
            "NAME selects the input by zero-based order"
        ),
    )
    parser.add_argument(
        "--pytorch-format",
        choices=("auto", "torchscript", "exported"),
        default="auto",
        help="PyTorch container kind",
    )
    parser.add_argument(
        "--trust-model",
        action="store_true",
        help="permit deserialization of a trusted PyTorch model",
    )
    parser.add_argument(
        "--check",
        action="store_true",
        help="recompile and compare every requested artifact without writing",
    )
    parser.add_argument("--l1-base", type=parse_cli_int, default=0x1000)
    parser.add_argument(
        "--l1-bytes", type=parse_cli_int, default=256 * 1024
    )
    parser.add_argument("--ddr-base", type=parse_cli_int, default=0x20000)
    parser.add_argument(
        "--ddr-bytes", type=parse_cli_int, default=2 * 1024 * 1024
    )
    parser.add_argument("--mt", type=parse_cli_int, default=8)
    parser.add_argument("--kt", type=parse_cli_int, default=16)
    parser.add_argument("--nt", type=parse_cli_int, default=8)
    parser.add_argument("--task-entries", type=parse_cli_int, default=32)
    return parser.parse_args(argv)


def run_cli(
    argv: Sequence[str] | None,
    *,
    target_type: Callable[..., Any],
    output_artifacts_fn: Callable[
        [Path, Any, bool, argparse.Namespace],
        tuple[dict[str, bytes], Any],
    ],
    error_type: type[Exception],
) -> int:
    args = parse_args(argv)
    if not args.input.is_file():
        raise error_type(f"input is not a file: {args.input}")
    if args.output_dir.exists() and not args.output_dir.is_dir():
        raise error_type(
            f"output path is not a directory: {args.output_dir}"
        )
    target = target_type(
        l1_base=args.l1_base,
        l1_bytes=args.l1_bytes,
        ddr_base=args.ddr_base,
        ddr_bytes=args.ddr_bytes,
        axi_addr_bits=npu_assembler.AXI_ADDR_BITS,
        mt=args.mt,
        kt=args.kt,
        nt=args.nt,
        task_entries=args.task_entries,
    )
    files, result = output_artifacts_fn(
        args.input, target, args.emit_raw, args
    )
    if args.check:
        for name, content in files.items():
            path = args.output_dir / name
            if not path.is_file():
                raise error_type(f"missing artifact: {path}")
            if path.read_bytes() != content:
                raise error_type(f"artifact differs: {path}")
        action = "verified"
    else:
        args.output_dir.mkdir(parents=True, exist_ok=True)
        for name, content in files.items():
            npu_assembler.atomic_write(args.output_dir / name, content)
        action = "wrote"
    print(
        f"model={result.model_name} high_ops={len(result.operators)} "
        f"low_ops={len(result.assembled_operations)} "
        f"format={npu_assembler.COMMAND_FORMAT}"
    )
    for name, content in files.items():
        print(
            f"{action}={args.output_dir / name} bytes={len(content)} "
            f"sha256={sha256_bytes(content)}"
        )
    return 0
