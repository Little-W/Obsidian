from __future__ import annotations

import json
import os
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

import npu_assembler
import npu_model_compiler as compiler


def add_model(dtype: str = "int16", columns: int = 4) -> dict:
    return {
        "schema_version": 1,
        "model": {"name": f"add_{dtype}"},
        "inputs": [
            {"name": "x", "shape": [2, columns], "dtype": dtype}
        ],
        "constants": [
            {
                "name": "bias",
                "shape": [2, columns],
                "dtype": dtype,
                "data": [1] * (2 * columns),
            }
        ],
        "operators": [
            {
                "name": "sum",
                "type": "Add",
                "inputs": ["x", "bias"],
                "outputs": ["y"],
            }
        ],
        "outputs": ["y"],
    }


def identity(width: int) -> list[int]:
    return [
        1 if row == column else 0
        for row in range(width)
        for column in range(width)
    ]


def attention_model(tokens: int = 4, width: int = 8) -> dict:
    constants = [
        {
            "name": name,
            "shape": [width, width],
            "dtype": "int16",
            "data": identity(width),
        }
        for name in ("wq", "wk", "wv", "wo")
    ]
    return {
        "schema_version": 1,
        "model": {"name": "attention"},
        "inputs": [
            {"name": "x", "shape": [tokens, width], "dtype": "int16"}
        ],
        "constants": constants,
        "operators": [
            {
                "name": "attention",
                "type": "MultiHeadAttention",
                "inputs": ["x", "wq", "wk", "wv", "wo"],
                "outputs": ["y"],
                "attributes": {"num_heads": 2},
            }
        ],
        "outputs": ["y"],
    }


class EndToEndCompilerTests(unittest.TestCase):
    def test_high_level_add_reaches_cmd128(self) -> None:
        result = compiler.compile_model_document(
            add_model(), compiler.TargetConfig()
        )
        self.assertEqual(len(result.command_image), 4 * 16)
        self.assertEqual(
            [item.name for item in result.assembled_operations],
            [
                "__load_constants",
                "__load_input_x",
                "sum",
                "__store_output_y",
            ],
        )
        self.assertEqual(result.runtime["command_bits"], 128)
        self.assertEqual(result.runtime["inputs"][0]["name"], "x")
        self.assertEqual(result.runtime["outputs"][0]["name"], "y")

    def test_attention_is_expanded_without_device_fields_in_source(self) -> None:
        document = attention_model()
        source_text = json.dumps(document)
        for forbidden in (
            "descriptor",
            "command_id",
            "wait_events",
            "signal_event",
            '"engine"',
            '"opcode"',
            '"addr"',
        ):
            self.assertNotIn(forbidden, source_text)
        result = compiler.compile_model_document(
            document, compiler.TargetConfig()
        )
        names = [item.name for item in result.assembled_operations]
        self.assertIn("attention_q_projection", names)
        self.assertIn("attention_qk", names)
        self.assertIn("attention_softmax", names)
        self.assertIn("attention_attention_value", names)
        self.assertIn("attention_output_projection", names)
        self.assertTrue(any(name.startswith("__event_join_") for name in names))

    def test_conv2d_reaches_im2col_and_gemm_only(self) -> None:
        document = {
            "schema_version": 1,
            "model": {"name": "conv"},
            "inputs": [
                {"name": "x", "shape": [1, 3, 3, 2], "dtype": "int16"}
            ],
            "constants": [
                {
                    "name": "kernel",
                    "shape": [2, 2, 2, 3],
                    "dtype": "int16",
                    "data": [1] * 24,
                }
            ],
            "operators": [
                {
                    "name": "conv",
                    "type": "Conv2D",
                    "inputs": ["x", "kernel"],
                    "outputs": ["y"],
                    "attributes": {"padding": "SAME"},
                }
            ],
            "outputs": ["y"],
        }
        result = compiler.compile_model_document(
            document, compiler.TargetConfig()
        )
        low = result.low_ir["operations"]
        opcodes = [str(item["opcode"]) for item in low]
        self.assertIn("FILL", opcodes)
        self.assertIn("COPY_ND", opcodes)
        self.assertIn("GEMM", opcodes)
        self.assertFalse(any("CONV" in opcode.upper() for opcode in opcodes))

    def test_int4_odd_rows_keep_per_row_padding(self) -> None:
        result = compiler.compile_model_document(
            add_model("int4", 5), compiler.TargetConfig()
        )
        bias = result.tensors["bias"]
        self.assertEqual(bias.storage_bytes, 6)
        self.assertEqual(
            result.constant_image[
                bias.ddr_addr - result.runtime["constant_base_ddr"] :
                bias.ddr_addr - result.runtime["constant_base_ddr"] + 6
            ],
            bytes([0x11, 0x11, 0x01, 0x11, 0x11, 0x01]),
        )
        load = result.low_ir["operations"][1]
        self.assertEqual(load["opcode"], "COPY_ND")
        self.assertEqual(
            load["descriptor"]["dma"]["src_stride_bytes"], [3, 0]
        )

    def test_more_than_task_table_entries_produces_batches(self) -> None:
        operators = []
        previous = "x"
        for index in range(40):
            output = f"t{index}"
            operators.append(
                {
                    "name": f"gelu{index}",
                    "type": "GELU",
                    "inputs": [previous],
                    "outputs": [output],
                }
            )
            previous = output
        document = {
            "schema_version": 1,
            "model": {"name": "long_chain"},
            "inputs": [{"name": "x", "shape": [1, 8], "dtype": "int16"}],
            "constants": [],
            "operators": operators,
            "outputs": [previous],
        }
        result = compiler.compile_model_document(
            document, compiler.TargetConfig(task_entries=32)
        )
        self.assertGreater(result.runtime["command_count"], 32)
        self.assertEqual([len(batch) for batch in result.runtime["batches"]], [32, 11])

    def test_l1_storage_is_reused_after_last_consumer(self) -> None:
        document = {
            "schema_version": 1,
            "model": {"name": "reuse"},
            "inputs": [{"name": "x", "shape": [1, 8], "dtype": "int16"}],
            "constants": [],
            "operators": [
                {
                    "name": "g0",
                    "type": "GELU",
                    "inputs": ["x"],
                    "outputs": ["a"],
                },
                {
                    "name": "g1",
                    "type": "GELU",
                    "inputs": ["a"],
                    "outputs": ["b"],
                },
                {
                    "name": "g2",
                    "type": "GELU",
                    "inputs": ["b"],
                    "outputs": ["y"],
                },
            ],
            "outputs": ["y"],
        }
        result = compiler.compile_model_document(
            document, compiler.TargetConfig()
        )
        reused = [
            tensor
            for tensor in result.tensors.values()
            if tensor.reused_from is not None
        ]
        self.assertTrue(reused)
        for tensor in reused:
            previous = result.tensors[tensor.reused_from]
            self.assertEqual(tensor.l1_addr, previous.l1_addr)
            self.assertEqual(tensor.storage_id, previous.storage_id)

    def test_two_stage_assembly_is_identical(self) -> None:
        result = compiler.compile_model_document(
            attention_model(), compiler.TargetConfig()
        )
        operations, commands, descriptors = npu_assembler.compile_document(
            result.low_ir
        )
        self.assertEqual(len(operations), len(result.assembled_operations))
        self.assertEqual(commands, result.command_image)
        self.assertEqual(descriptors, result.descriptor_image)

    def test_cli_artifacts_and_check(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            base = Path(temporary)
            source = base / "model.json"
            output = base / "out"
            source.write_text(
                json.dumps(add_model(), indent=2), encoding="utf-8"
            )
            arguments = [
                str(source),
                "--output-dir",
                str(output),
                "--emit-c-header",
            ]
            self.assertEqual(compiler.main(arguments), 0)
            expected = {
                "model.npuasm.json",
                "model.cmd.bin",
                "model.desc.bin",
                "model.const.bin",
                "model.runtime.json",
                "model.manifest.json",
                "model.npu.h",
            }
            self.assertEqual(
                {path.name for path in output.iterdir()}, expected
            )
            self.assertEqual(compiler.main(arguments + ["--check"]), 0)

    def test_cli_is_stable_across_python_hash_seeds(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            base = Path(temporary)
            source = base / "model.json"
            first = base / "first"
            second = base / "second"
            source.write_text(
                json.dumps(attention_model(), indent=2), encoding="utf-8"
            )
            for seed, output in (("1", first), ("987654", second)):
                environment = dict(os.environ)
                environment["PYTHONHASHSEED"] = seed
                subprocess.run(
                    [
                        sys.executable,
                        str(ROOT / "npu_model_compiler.py"),
                        str(source),
                        "--output-dir",
                        str(output),
                        "--emit-c-header",
                    ],
                    check=True,
                    capture_output=True,
                    text=True,
                    env=environment,
                )
            self.assertEqual(
                {path.name for path in first.iterdir()},
                {path.name for path in second.iterdir()},
            )
            for first_path in first.iterdir():
                self.assertEqual(
                    first_path.read_bytes(),
                    (second / first_path.name).read_bytes(),
                    first_path.name,
                )

    def test_memory_capacity_error_is_reported(self) -> None:
        with self.assertRaisesRegex(
            compiler.ModelCompileError, "L1 allocation"
        ):
            compiler.compile_model_document(
                attention_model(),
                compiler.TargetConfig(l1_bytes=0x1200),
            )


if __name__ == "__main__":
    unittest.main()
