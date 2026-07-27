#!/usr/bin/env python3
"""Build and optionally run the Transformer RTL test fixture."""

from __future__ import annotations

import argparse
import hashlib
import json
import subprocess
import sys
from pathlib import Path


SCRIPT_DIR = Path(__file__).resolve().parent
NPU_DIR = SCRIPT_DIR.parents[2]
COMPILER_DIR = NPU_DIR / "compiler"
sys.path.insert(0, str(COMPILER_DIR))

import npu_model_compiler as compiler  # noqa: E402


# These fixed vectors were independently checked with the NPU cycle C model.
MODEL_INPUT = (2, -1, 3, 0, -2, 4, 1, 3)
EXPECTED_SCORE = (4, -4, -4, 4)
EXPECTED_PROBABILITY = (4, 0, 0, 4)
EXPECTED_CONTEXT = MODEL_INPUT
EXPECTED_OUTPUT = (7, -8, 13, -14, -3, 4, 1, 5)
REQUIRED_LOWERED_OPERATIONS = {
    "attn_qk": ("matrix", "GEMM"),
    "attn_softmax": ("complex", "SOFTMAX"),
    "attn_attention_value": ("matrix", "GEMM"),
    "res1": ("vector", "ADD"),
    "norm1": ("complex", "NORM"),
    "ff1": ("matrix", "GEMM"),
    "gelu": ("complex", "ACT"),
    "ff2": ("matrix", "GEMM"),
    "res2": ("vector", "ADD"),
    "norm2": ("complex", "NORM"),
}


def byte_lines(values: bytes | tuple[int, ...]) -> str:
    return "".join(f"{int(value) & 0xff:02x}\n" for value in values)


def compile_fixture(model_path: Path, output_dir: Path) -> dict[str, object]:
    document = json.loads(model_path.read_text(encoding="utf-8"))
    result = compiler.compile_model_document(
        document,
        compiler.TargetConfig(task_entries=8),
        source_name=str(model_path),
    )
    if result.runtime["command_format"] != "cmd128":
        raise RuntimeError("fixture requires the cmd128 command format")
    operations = {item.name: item for item in result.assembled_operations}
    for name, (engine, opcode_name) in REQUIRED_LOWERED_OPERATIONS.items():
        if name not in operations:
            raise RuntimeError(f"missing lowered operation {name}")
        operation = operations[name]
        expected_opcode = compiler.npu_assembler.OPCODES[engine][opcode_name]
        if operation.engine != engine or operation.opcode != expected_opcode:
            raise RuntimeError(
                f"{name} was lowered as {operation.engine}/{operation.opcode}"
            )

    batches = result.runtime["batch_execution"]
    flattened_ids: list[int] = []
    for batch in batches:
        command_ids = [int(value) for value in batch["command_ids"]]
        if not 1 <= len(command_ids) <= 8:
            raise RuntimeError("each RTL command burst must contain 1..8 commands")
        flattened_ids.extend(command_ids)
    expected_ids = [
        int(operation.command_id)
        for operation in result.assembled_operations
    ]
    if flattened_ids != expected_ids:
        raise RuntimeError("compiler batches are not in command-image order")

    runtime_inputs = result.runtime["inputs"]
    runtime_outputs = result.runtime["outputs"]
    if len(runtime_inputs) != 1 or len(runtime_outputs) != 1:
        raise RuntimeError("fixture requires one input and one output")
    input_binding = runtime_inputs[0]
    output_binding = runtime_outputs[0]
    if int(input_binding["bytes"]) != len(MODEL_INPUT):
        raise RuntimeError("input fixture size does not match the compiled graph")
    if int(output_binding["bytes"]) != len(EXPECTED_OUTPUT):
        raise RuntimeError("output fixture size does not match the compiled graph")

    score_tensor = result.tensors["__attn_scores"]
    probability_tensor = result.tensors["__attn_probabilities"]
    context_tensor = result.tensors["__attn_attention_heads"]
    if (
        score_tensor.l1_addr is None
        or probability_tensor.l1_addr is None
        or context_tensor.l1_addr is None
    ):
        raise RuntimeError("attention intermediate tensor has no L1 address")

    output_dir.mkdir(parents=True, exist_ok=True)
    command_path = output_dir / "commands.hex"
    weight_path = output_dir / "weights.hex"
    input_path = output_dir / "input.hex"
    expected_path = output_dir / "expected.hex"
    score_path = output_dir / "expected_score.hex"
    probability_path = output_dir / "expected_probability.hex"
    context_path = output_dir / "expected_context.hex"
    batch_path = output_dir / "batches.hex"

    command_path.write_text(
        "".join(
            f"{int.from_bytes(operation.command, 'little'):032x}\n"
            for operation in result.assembled_operations
        ),
        encoding="ascii",
    )
    weight_path.write_text(byte_lines(result.constant_image), encoding="ascii")
    input_path.write_text(byte_lines(MODEL_INPUT), encoding="ascii")
    expected_path.write_text(byte_lines(EXPECTED_OUTPUT), encoding="ascii")
    score_path.write_text(byte_lines(EXPECTED_SCORE), encoding="ascii")
    probability_path.write_text(
        byte_lines(EXPECTED_PROBABILITY), encoding="ascii"
    )
    context_path.write_text(byte_lines(EXPECTED_CONTEXT), encoding="ascii")
    batch_path.write_text(
        byte_lines(tuple(len(batch["command_ids"]) for batch in batches)),
        encoding="ascii",
    )

    manifest: dict[str, object] = {
        "fixture_version": 1,
        "model": result.model_name,
        "command_format": result.runtime["command_format"],
        "command_count": len(result.assembled_operations),
        "command_sha256": hashlib.sha256(result.command_image).hexdigest(),
        "batch_count": len(batches),
        "batch_sizes": [len(batch["command_ids"]) for batch in batches],
        "weight_bytes": len(result.constant_image),
        "weight_sha256": hashlib.sha256(result.constant_image).hexdigest(),
        "weight_ddr_addr": int(result.runtime["constant_base_ddr"]),
        "input": {
            "ddr_addr": int(input_binding["ddr_addr"]),
            "bytes": int(input_binding["bytes"]),
            "values": list(MODEL_INPUT),
        },
        "output": {
            "ddr_addr": int(output_binding["ddr_addr"]),
            "bytes": int(output_binding["bytes"]),
            "expected": list(EXPECTED_OUTPUT),
        },
        "attention_score": {
            "l1_addr": int(score_tensor.l1_addr),
            "bytes": len(EXPECTED_SCORE),
            "expected": list(EXPECTED_SCORE),
        },
        "attention_probability": {
            "l1_addr": int(probability_tensor.l1_addr),
            "bytes": len(EXPECTED_PROBABILITY),
            "expected": list(EXPECTED_PROBABILITY),
        },
        "attention_context": {
            "l1_addr": int(context_tensor.l1_addr),
            "bytes": len(EXPECTED_CONTEXT),
            "expected": list(EXPECTED_CONTEXT),
        },
        "required_lowered_operations": sorted(REQUIRED_LOWERED_OPERATIONS),
    }
    manifest_path = output_dir / "manifest.json"
    manifest_path.write_text(
        json.dumps(manifest, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
    )
    return {
        "manifest": manifest,
        "manifest_path": manifest_path,
        "command_path": command_path,
        "weight_path": weight_path,
        "input_path": input_path,
        "expected_path": expected_path,
        "score_path": score_path,
        "probability_path": probability_path,
        "context_path": context_path,
        "batch_path": batch_path,
    }


def run_simulator(binary: Path, artifacts: dict[str, object]) -> None:
    manifest = artifacts["manifest"]
    assert isinstance(manifest, dict)
    input_info = manifest["input"]
    output_info = manifest["output"]
    score_info = manifest["attention_score"]
    probability_info = manifest["attention_probability"]
    context_info = manifest["attention_context"]
    assert isinstance(input_info, dict)
    assert isinstance(output_info, dict)
    assert isinstance(score_info, dict)
    assert isinstance(probability_info, dict)
    assert isinstance(context_info, dict)
    arguments = [
        str(binary.resolve()),
        f"+COMMAND_HEX={Path(artifacts['command_path']).resolve()}",
        f"+COMMAND_COUNT={manifest['command_count']}",
        f"+BATCH_HEX={Path(artifacts['batch_path']).resolve()}",
        f"+BATCH_COUNT={manifest['batch_count']}",
        f"+WEIGHT_HEX={Path(artifacts['weight_path']).resolve()}",
        f"+WEIGHT_BYTES={manifest['weight_bytes']}",
        f"+WEIGHT_DDR={manifest['weight_ddr_addr']}",
        f"+INPUT_HEX={Path(artifacts['input_path']).resolve()}",
        f"+INPUT_BYTES={input_info['bytes']}",
        f"+INPUT_DDR={input_info['ddr_addr']}",
        f"+EXPECTED_HEX={Path(artifacts['expected_path']).resolve()}",
        f"+OUTPUT_BYTES={output_info['bytes']}",
        f"+OUTPUT_DDR={output_info['ddr_addr']}",
        f"+SCORE_HEX={Path(artifacts['score_path']).resolve()}",
        f"+SCORE_BYTES={score_info['bytes']}",
        f"+SCORE_L1={score_info['l1_addr']}",
        (
            "+PROBABILITY_HEX="
            f"{Path(artifacts['probability_path']).resolve()}"
        ),
        f"+PROBABILITY_BYTES={probability_info['bytes']}",
        f"+PROBABILITY_L1={probability_info['l1_addr']}",
        f"+CONTEXT_HEX={Path(artifacts['context_path']).resolve()}",
        f"+CONTEXT_BYTES={context_info['bytes']}",
        f"+CONTEXT_L1={context_info['l1_addr']}",
    ]
    subprocess.run(arguments, check=True)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--model",
        type=Path,
        default=SCRIPT_DIR / "transformer_e2e_model.json",
    )
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--run", type=Path)
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    artifacts = compile_fixture(args.model, args.output_dir)
    manifest = artifacts["manifest"]
    assert isinstance(manifest, dict)
    print(
        "fixture="
        f"{manifest['model']} commands={manifest['command_count']} "
        f"batches={manifest['batch_count']} "
        f"weights={manifest['weight_bytes']}",
        flush=True,
    )
    print(f"manifest={artifacts['manifest_path']}", flush=True)
    if args.run is not None:
        run_simulator(args.run, artifacts)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
