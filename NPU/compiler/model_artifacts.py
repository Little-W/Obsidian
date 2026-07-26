#!/usr/bin/env python3
"""Artifact, C-header, manifest, JSON I/O, and CLI support for model compile.

This module deliberately depends only on the assembler and on values supplied
by the high-level compiler.  Keeping graph analysis and operator lowering out
of this file avoids an import cycle while preserving ``npu_model_compiler`` as
the public entry point.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path
from typing import Any, Callable, Mapping, Sequence

sys.dont_write_bytecode = True

_HERE = Path(__file__).resolve().parent
if str(_HERE) not in sys.path:
    sys.path.insert(0, str(_HERE))

import npu_assembler


MAX_MODEL_RANK = 5


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


def c_string(value: str) -> str:
    return json.dumps(value, ensure_ascii=True)


def c_byte_array(content: bytes, name: str) -> str:
    return npu_assembler.c_array(content, name)


def build_model_c_header(
    stem: str,
    result: Any,
    *,
    max_rank: int = MAX_MODEL_RANK,
) -> bytes:
    symbol = c_identifier(stem)
    upper = symbol.upper()
    guard = f"NPU_COMPILED_MODEL_{upper}_H"
    inputs = result.runtime["inputs"]
    outputs = result.runtime["outputs"]
    operations = result.runtime["operations"]
    batches = result.runtime["batches"]

    def binding_rows(values: Sequence[Mapping[str, Any]]) -> str:
        rows: list[str] = []
        for value in values:
            shape = list(value["shape"]) + [0] * (
                max_rank - len(value["shape"])
            )
            rows.append(
                "    {"
                + f"{c_string(str(value['name']))}, "
                + f"UINT64_C(0x{int(value['ddr_addr']):x}), "
                + f"UINT64_C(0x{int(value['l1_addr']):x}), "
                + f"{int(value['bytes'])}u, "
                + f"{npu_assembler.DTYPE_CODES[str(value['dtype'])]}u, "
                + f"{len(value['shape'])}u, "
                + "{"
                + ", ".join(f"{int(item)}u" for item in shape)
                + "}},"
            )
        return "\n".join(rows)

    operation_rows = "\n".join(
        "    {"
        + f"{c_string(str(item['name']))}, "
        + f"{c_string(str(item['high_level_node']))}, "
        + f"{int(item['command_id'])}u"
        + "},"
        for item in operations
    )
    batch_offsets = [0]
    batch_ids: list[int] = []
    for batch in batches:
        batch_ids.extend(int(value) for value in batch)
        batch_offsets.append(len(batch_ids))
    batch_offset_text = ", ".join(f"{value}u" for value in batch_offsets)
    batch_id_text = ", ".join(f"{value}u" for value in batch_ids)
    content = (
        f"#ifndef {guard}\n#define {guard}\n\n"
        "#include <stdint.h>\n\n"
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
        "    uint16_t command_id;\n"
        f"}} {symbol}_operation_t;\n\n"
        f"#define {upper}_COMMAND_BITS 128u\n"
        f"#define {upper}_COMMAND_COUNT {len(operations)}u\n"
        f"#define {upper}_DESCRIPTOR_BASE "
        f"UINT64_C(0x{int(result.runtime['descriptor_base']):x})\n"
        f"#define {upper}_CONSTANT_BASE_DDR "
        f"UINT64_C(0x{int(result.runtime['constant_base_ddr']):x})\n"
        f"#define {upper}_CONSTANT_BASE_L1 "
        f"UINT64_C(0x{int(result.runtime['constant_base_l1']):x})\n"
        f"#define {upper}_INPUT_COUNT {len(inputs)}u\n"
        f"#define {upper}_OUTPUT_COUNT {len(outputs)}u\n"
        f"#define {upper}_BATCH_COUNT {len(batches)}u\n\n"
        + c_byte_array(result.command_image, f"{symbol}_commands")
        + "\n"
        + c_byte_array(result.descriptor_image, f"{symbol}_descriptors")
        + "\n"
        + c_byte_array(result.constant_image, f"{symbol}_constants")
        + "\n"
        + f"static const {symbol}_binding_t {symbol}_inputs[] = {{\n"
        + binding_rows(inputs)
        + "\n};\n\n"
        + f"static const {symbol}_binding_t {symbol}_outputs[] = {{\n"
        + binding_rows(outputs)
        + "\n};\n\n"
        + f"static const {symbol}_operation_t {symbol}_operations[] = {{\n"
        + operation_rows
        + "\n};\n\n"
        + f"static const uint16_t {symbol}_batch_offsets[] = {{"
        + batch_offset_text
        + "};\n"
        + f"static const uint16_t {symbol}_batch_command_ids[] = {{"
        + batch_id_text
        + "};\n\n"
        + f"#endif /* {guard} */\n"
    )
    return content.encode("ascii")


def build_model_manifest(
    source_path: Path,
    result: Any,
    file_contents: Mapping[str, bytes],
) -> bytes:
    return canonical_json(
        {
            "artifact_version": 1,
            "model_name": result.model_name,
            "source": source_path.name,
            "source_sha256": sha256_bytes(source_path.read_bytes()),
            "pipeline": [
                "high-level-model",
                "low-level-json-ir",
                "npu-assembler",
                "cmd128",
            ],
            "command_format": "cmd128-v1",
            "command_count": len(result.assembled_operations),
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
    emit_c_header: bool,
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
    files: dict[str, bytes] = {
        f"{stem}.npuasm.json": canonical_json(result.low_ir),
        f"{stem}.cmd.bin": result.command_image,
        f"{stem}.desc.bin": result.descriptor_image,
        f"{stem}.const.bin": result.constant_image,
        f"{stem}.runtime.json": canonical_json(result.runtime),
    }
    if emit_c_header:
        files[f"{stem}.npu.h"] = build_model_c_header(
            stem, result, max_rank=max_rank
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
            "Compile a high-level integer model graph, emit low-level JSON "
            "IR, and invoke the CMD128 NPU assembler."
        )
    )
    parser.add_argument("input", type=Path, help="high-level model JSON")
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
        help="emit commands, Descriptors, constants and runtime metadata in C",
    )
    parser.add_argument(
        "--check",
        action="store_true",
        help="recompile and compare every requested artifact without writing",
    )
    parser.add_argument(
        "--descriptor-base", type=parse_cli_int, default=0x10000
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
        [Path, Any, bool], tuple[dict[str, bytes], Any]
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
        descriptor_base=args.descriptor_base,
        l1_base=args.l1_base,
        l1_bytes=args.l1_bytes,
        ddr_base=args.ddr_base,
        ddr_bytes=args.ddr_bytes,
        mt=args.mt,
        kt=args.kt,
        nt=args.nt,
        task_entries=args.task_entries,
    )
    files, result = output_artifacts_fn(
        args.input, target, args.emit_c_header
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
        f"low_ops={len(result.assembled_operations)} format=cmd128-v1"
    )
    for name, content in files.items():
        print(
            f"{action}={args.output_dir / name} bytes={len(content)} "
            f"sha256={sha256_bytes(content)}"
        )
    return 0
