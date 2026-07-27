from __future__ import annotations

import importlib.util
import json
import struct
import sys
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location(
    "npu_assembler", ROOT / "npu_assembler.py"
)
assert SPEC is not None and SPEC.loader is not None
npu_assembler = importlib.util.module_from_spec(SPEC)
sys.modules[SPEC.name] = npu_assembler
SPEC.loader.exec_module(npu_assembler)


class CommandTests(unittest.TestCase):
    def test_exact_cmd128_encoding(self) -> None:
        payload = 0xABCD_0123456789ABCDEF
        encoded = npu_assembler.encode_command128(
            payload=payload,
            command_id=0x345,
            opcode=27,
            dtype=3,
            flags=0xB,
            timeout_class=2,
            wait0=0x23,
            wait1=0x56,
            signal=0x89,
        )
        low, high = struct.unpack("<QQ", encoded)
        self.assertEqual(low, 0x0123456789ABCDEF)
        self.assertEqual(
            high,
            0xABCD
            | (3 << 16)
            | (2 << 18)
            | (0xB << 20)
            | (0x89 << 24)
            | (0x56 << 32)
            | (0x23 << 40)
            | (0x345 << 48)
            | (27 << 58),
        )

    def test_event_generation_and_command_ranges_are_rejected(self) -> None:
        with self.assertRaisesRegex(npu_assembler.CompileError, "generation 0"):
            npu_assembler.encode_command128(
                0,
                1,
                0,
                1,
                0,
                0,
                {"id": 3, "generation": 1},
                "none",
                "none",
            )
        with self.assertRaisesRegex(npu_assembler.CompileError, "0..1023"):
            npu_assembler.encode_command128(
                0, 1024, 0, 1, 0, 0, "none", "none", "none"
            )
        with self.assertRaisesRegex(npu_assembler.CompileError, "0..32"):
            npu_assembler.encode_command128(
                0, 1, 33, 1, 0, 0, "none", "none", "none"
            )


class AssemblerTests(unittest.TestCase):
    @staticmethod
    def example(name: str) -> dict:
        return json.loads(
            (ROOT / "examples" / name).read_text(encoding="utf-8")
        )

    def test_example_int8_fields_are_at_exact_bit_positions(self) -> None:
        operations, commands = npu_assembler.compile_document(
            self.example("int8_regression.json")
        )
        self.assertEqual(len(operations), 2)
        self.assertEqual(len(commands), 32)
        dma = operations[0]
        expected_dma = (
            (0x08200000 << 52)
            | (0x00001000 << 24)
            | (64 << 4)
            | (1 << 2)
        )
        self.assertEqual(dma.opcode, 5)
        self.assertEqual(dma.payload, expected_dma)
        self.assertEqual(dma.signal_event, 0)
        matrix = operations[1]
        expected_matrix = (
            (0x40 << 66)
            | (0x80 << 52)
            | (0xC0 << 38)
            | (7 << 20)
            | (7 << 14)
            | (7 << 8)
            | (1 << 5)
        )
        self.assertEqual(matrix.opcode, 12)
        self.assertEqual(matrix.payload, expected_matrix)
        self.assertEqual(matrix.wait_events, (0, npu_assembler.EVENT_NONE))
        _low, high = struct.unpack("<QQ", matrix.command)
        self.assertEqual((high >> 16) & 0x3, 1)
        self.assertEqual((high >> 58) & 0x3F, 12)
        self.assertEqual((high >> 63) & 0x1, 0)

    def test_example_int16_header_and_matrix_dtype_fields(self) -> None:
        operations, commands = npu_assembler.compile_document(
            self.example("int16_regression.json")
        )
        self.assertEqual(len(commands), 32)
        for operation in operations:
            _low, high = struct.unpack("<QQ", operation.command)
            self.assertEqual((high >> 16) & 0x3, 3)
        matrix = operations[1]
        self.assertEqual((matrix.payload >> 5) & 0x3, 3)
        self.assertEqual(matrix.payload & 0x1F, 0)

    def test_control_event_rearm_uses_signal_field(self) -> None:
        document = {
            "schema_version": 1,
            "target": {"command_format": npu_assembler.COMMAND_FORMAT},
            "tensors": {},
            "operations": [
                {
                    "name": "produce",
                    "engine": "control",
                    "opcode": "EVENT_SIGNAL",
                    "signal_event": 17,
                    "fields": {"control": {}},
                },
                {
                    "name": "rearm",
                    "engine": "control",
                    "opcode": "EVENT_REARM",
                    "signal_event": 17,
                    "fields": {"control": {}},
                }
            ],
        }
        operations, _commands = npu_assembler.compile_document(document)
        _low, high = struct.unpack("<QQ", operations[1].command)
        self.assertEqual((high >> 24) & 0xFF, 17)
        self.assertEqual((high >> 32) & 0xFFFF, 0xFFFF)
        document["operations"][1]["wait_events"] = [3]
        with self.assertRaisesRegex(npu_assembler.CompileError, "has no waits"):
            npu_assembler.compile_document(document)

    def test_event_id_reuse_requires_rearm(self) -> None:
        document = {
            "schema_version": 1,
            "target": {"command_format": npu_assembler.COMMAND_FORMAT},
            "tensors": {},
            "operations": [
                {
                    "name": "first",
                    "engine": "control",
                    "opcode": "EVENT_SIGNAL",
                    "signal_event": 7,
                    "fields": {"control": {}},
                },
                {
                    "name": "rearm",
                    "engine": "control",
                    "opcode": "EVENT_REARM",
                    "signal_event": 7,
                    "fields": {"control": {}},
                },
                {
                    "name": "second",
                    "engine": "control",
                    "opcode": "EVENT_SIGNAL",
                    "signal_event": 7,
                    "fields": {"control": {}},
                },
            ],
        }
        operations, _commands = npu_assembler.compile_document(document)
        self.assertEqual(
            [operation.signal_event for operation in operations],
            [7, 7, 7],
        )
        del document["operations"][1]
        with self.assertRaisesRegex(
            npu_assembler.CompileError, "needs EVENT_REARM"
        ):
            npu_assembler.compile_document(document)

    def test_matrix_direct_shift_bias_and_int4_b_fields(self) -> None:
        document = {
            "schema_version": 1,
            "target": {"command_format": npu_assembler.COMMAND_FORMAT},
            "tensors": {
                "a": {"addr": 0x1000, "space": "l1", "dtype": "int8"},
                "b": {"addr": 0x2000, "space": "l1", "dtype": "int4"},
                "c": {"addr": 0x3000, "space": "l1", "dtype": "int8"},
                "bias": {
                    "addr": 0x4000,
                    "space": "l1",
                    "dtype": "int32",
                },
            },
            "operations": [
                {
                    "name": "gemm",
                    "engine": "matrix",
                    "opcode": "GEMM",
                    "fields": {
                        "common": {
                            "src0": "a",
                            "src1": "b",
                            "dst": "c",
                            "aux0": "bias",
                        },
                        "matrix": {
                            "m": 2,
                            "n": 3,
                            "k": 4,
                            "b_int4": True,
                            "bias_enable": True,
                            "requant_shift": 31,
                        },
                    },
                },
                {
                    "name": "bmm",
                    "engine": "matrix",
                    "opcode": "BMM",
                    "fields": {
                        "common": {
                            "src0": "a",
                            "src1": "b",
                            "dst": "c",
                        },
                        "matrix": {
                            "batch_count": 5,
                            "m": 6,
                            "n": 7,
                            "k": 8,
                            "b_int4": True,
                            "requant_shift": 5,
                        },
                    },
                },
            ],
        }
        operations, _commands = npu_assembler.compile_document(document)
        gemm = operations[0].payload
        self.assertEqual((gemm >> 26) & 0xFFF, 0x100)
        self.assertEqual((gemm >> 20) & 0x3F, 1)
        self.assertEqual((gemm >> 14) & 0x3F, 2)
        self.assertEqual((gemm >> 8) & 0x3F, 3)
        self.assertEqual((gemm >> 7) & 0x1, 1)
        self.assertEqual((gemm >> 5) & 0x3, 1)
        self.assertEqual(gemm & 0x1F, 31)
        bmm = operations[1].payload
        self.assertEqual((bmm >> 32) & 0x3F, 4)
        self.assertEqual((bmm >> 26) & 0x3F, 5)
        self.assertEqual((bmm >> 20) & 0x3F, 6)
        self.assertEqual((bmm >> 14) & 0x3F, 7)
        self.assertEqual((bmm >> 13) & 0x1, 1)
        self.assertEqual((bmm >> 11) & 0x3, 1)
        self.assertEqual((bmm >> 6) & 0x1F, 5)
        self.assertEqual(bmm & 0x3F, 0)

    def test_vector_and_complex_payloads(self) -> None:
        document = {
            "schema_version": 1,
            "target": {"command_format": npu_assembler.COMMAND_FORMAT},
            "tensors": {
                "a": {"addr": 0x1000, "space": "l1", "dtype": "int8"},
                "b": {"addr": 0x1100, "space": "l1", "dtype": "int8"},
                "c": {"addr": 0x1200, "space": "l1", "dtype": "int8"},
                "d": {"addr": 0x1300, "space": "l1", "dtype": "int8"},
            },
            "operations": [
                {
                    "name": "add",
                    "engine": "vector",
                    "opcode": "ADD",
                    "fields": {
                        "common": {"src0": "a", "src1": "b", "dst": "c"},
                        "vector": {
                            "rows": 3,
                            "length": 7,
                            "broadcast1": "feature",
                        },
                    },
                },
                {
                    "name": "gelu",
                    "engine": "complex",
                    "opcode": "ACT",
                    "fields": {
                        "common": {"src0": "c", "dst": "d"},
                        "complex": {
                            "rows": 3,
                            "length": 7,
                            "function": "gelu",
                            "src0_scale": 0.25,
                            "dst_scale": 0.125,
                            "input_clip_min": -8.0,
                            "input_clip_max": 8.0,
                        },
                    },
                },
            ],
        }
        operations, _commands = npu_assembler.compile_document(document)
        vector = operations[0].payload
        self.assertEqual((vector >> 64) & 0xFFFF, 0x100)
        self.assertEqual((vector >> 48) & 0xFFFF, 0x110)
        self.assertEqual((vector >> 16) & 0xFFFF, 0x120)
        self.assertEqual((vector >> 11) & 0x1F, 2)
        self.assertEqual((vector >> 6) & 0x1F, 6)
        self.assertEqual((vector >> 2) & 0x3, 3)
        complex_payload = operations[1].payload
        meta = complex_payload & ((1 << 19) - 1)
        self.assertEqual((meta >> 17) & 0x3, 2)
        self.assertEqual((meta >> 13) & 0xF, 0xE)
        self.assertEqual((meta >> 9) & 0xF, 0xD)
        self.assertEqual((meta >> 5) & 0x3, 1)

    def test_norm_layout_and_size_limits_are_checked(self) -> None:
        document = {
            "schema_version": 1,
            "target": {"command_format": npu_assembler.COMMAND_FORMAT},
            "tensors": {
                "x": {"addr": 0x1000, "space": "l1", "dtype": "int16"},
                "gamma": {"addr": 0x2000, "space": "l1", "dtype": "int16"},
                "beta": {"addr": 0x2040, "space": "l1", "dtype": "int16"},
                "y": {"addr": 0x3000, "space": "l1", "dtype": "int16"},
            },
            "operations": [
                {
                    "name": "norm",
                    "engine": "complex",
                    "opcode": "NORM",
                    "fields": {
                        "common": {
                            "src0": "x",
                            "src1": "gamma",
                            "src2": "beta",
                            "dst": "y",
                        },
                        "complex": {
                            "rows": 2,
                            "length": 16,
                            "function": "layernorm",
                            "epsilon": 1.0e-5,
                            "src0_scale": 1.0,
                            "src1_scale": 1.0,
                            "dst_scale": 1.0,
                        },
                    },
                }
            ],
        }
        operations, _commands = npu_assembler.compile_document(document)
        self.assertEqual((operations[0].payload >> 48) & 0xFFFF, 0x200)
        document["tensors"]["beta"]["addr"] = 0x2050
        with self.assertRaisesRegex(npu_assembler.CompileError, "next 64-byte"):
            npu_assembler.compile_document(document)
        document["tensors"]["beta"]["addr"] = 0x2040
        document["operations"][0]["fields"]["complex"]["length"] = 257
        with self.assertRaisesRegex(npu_assembler.CompileError, "1..256"):
            npu_assembler.compile_document(document)

    def test_p1_opcode_slots_and_add_rescale_slot_are_preserved(self) -> None:
        document = {
            "schema_version": 1,
            "target": {"command_format": npu_assembler.COMMAND_FORMAT},
            "tensors": {
                "x": {"addr": 0x1000, "space": "l1", "dtype": "int8"},
                "aux": {"addr": 0x1100, "space": "l1", "dtype": "int8"},
                "y": {"addr": 0x1200, "space": "l1", "dtype": "int8"},
            },
            "operations": [
                {
                    "name": "rope",
                    "engine": "complex",
                    "opcode": "ROPE",
                    "fields": {
                        "common": {"src0": "x", "src1": "aux", "dst": "y"},
                        "complex": {
                            "rows": 1,
                            "length": 8,
                            "p1_meta": 0x12345,
                        },
                    },
                },
                {
                    "name": "recip",
                    "engine": "complex",
                    "opcode": "RECIP",
                    "fields": {
                        "common": {"src0": "x", "dst": "y"},
                        "complex": {
                            "rows": 1,
                            "length": 8,
                            "p1_meta": 0,
                        },
                    },
                },
                {
                    "name": "rescale",
                    "engine": "complex",
                    "opcode": "ADD_RESCALE",
                    "fields": {
                        "common": {"src0": "x", "src1": "aux", "dst": "y"},
                        "complex": {
                            "rows": 1,
                            "length": 8,
                            "src0_scale": 1.0,
                            "src1_scale": 1.0,
                            "dst_scale": 1.0,
                        },
                    },
                },
            ],
        }
        operations, _commands = npu_assembler.compile_document(document)
        self.assertEqual(
            [operation.opcode for operation in operations],
            [29, 31, 32],
        )
        for operation, expected in zip(operations, (29, 31, 32)):
            _low, high = struct.unpack("<QQ", operation.command)
            self.assertEqual((high >> 58) & 0x3F, expected)

    def test_gather_nd_has_an_inline_p1_payload(self) -> None:
        document = {
            "schema_version": 1,
            "target": {
                "command_format": npu_assembler.COMMAND_FORMAT,
                "gaddr_bases": {"weight": 0x200000},
            },
            "tensors": {
                "source": {
                    "addr": 0x200100,
                    "space": "ddr",
                    "base_select": "weight",
                    "dtype": "int8",
                },
                "index": {
                    "addr": 0x1000,
                    "space": "l1",
                    "dtype": "int32",
                },
                "destination": {
                    "addr": 0x2000,
                    "space": "l1",
                    "dtype": "int8",
                },
            },
            "operations": [
                {
                    "name": "gather",
                    "engine": "dma",
                    "opcode": "GATHER_ND",
                    "fields": {
                        "common": {
                            "src0": "source",
                            "aux0": "index",
                            "dst": "destination",
                        },
                        "dma": {
                            "block_count": 3,
                            "block_bytes": 64,
                        },
                    },
                }
            ],
        }
        operations, _commands = npu_assembler.compile_document(document)
        gather = operations[0]
        expected_payload = (
            (0x0A000100 << 52)
            | (0x100 << 36)
            | (0x200 << 20)
            | (2 << 12)
            | 63
        )
        self.assertEqual(gather.opcode, 11)
        self.assertEqual(gather.engine_opcode, 0x28)
        self.assertEqual(gather.payload, expected_payload)
        _low, high = struct.unpack("<QQ", gather.command)
        self.assertEqual((high >> 58) & 0x3F, 11)

        document["tensors"]["source"]["space"] = "l1"
        with self.assertRaisesRegex(
            npu_assembler.CompileError, "source must use ddr"
        ):
            npu_assembler.compile_document(document)

    def test_matrix_shift_and_dimensions_are_checked(self) -> None:
        document = self.example("int8_regression.json")
        matrix = document["operations"][1]["fields"]["matrix"]
        matrix["requant_shift"] = 5
        operations, _commands = npu_assembler.compile_document(document)
        self.assertEqual(operations[1].payload & 0x1F, 5)
        matrix["requant_shift"] = 32
        with self.assertRaisesRegex(npu_assembler.CompileError, "0..31"):
            npu_assembler.compile_document(document)
        matrix["requant_shift"] = 0
        matrix["m"] = 65
        with self.assertRaisesRegex(npu_assembler.CompileError, "1..64"):
            npu_assembler.compile_document(document)

    def test_external_descriptor_input_is_rejected(self) -> None:
        document = self.example("int8_regression.json")
        operation = document["operations"][0]
        operation["descriptor"] = operation.pop("fields")
        with self.assertRaisesRegex(npu_assembler.CompileError, "fields object"):
            npu_assembler.compile_document(document)

    def test_artifacts_have_no_descriptor_file_and_check_is_stable(self) -> None:
        for source_name in ("int8_regression.json", "int16_regression.json"):
            with self.subTest(source=source_name), tempfile.TemporaryDirectory() as temporary:
                source = ROOT / "examples" / source_name
                output = Path(temporary)
                self.assertEqual(
                    npu_assembler.main(
                        [
                            str(source),
                            "--output-dir",
                            str(output),
                            "--emit-c-header",
                        ]
                    ),
                    0,
                )
                before = {
                    path.name: path.read_bytes()
                    for path in output.iterdir()
                    if path.is_file()
                }
                self.assertFalse(any(name.endswith(".desc.bin") for name in before))
                self.assertEqual(
                    npu_assembler.main(
                        [
                            str(source),
                            "--output-dir",
                            str(output),
                            "--emit-c-header",
                            "--check",
                        ]
                    ),
                    0,
                )
                self.assertEqual(
                    before,
                    {
                        path.name: path.read_bytes()
                        for path in output.iterdir()
                        if path.is_file()
                    },
                )

    def test_forward_dependency_is_rejected(self) -> None:
        document = {
            "schema_version": 1,
            "target": {"command_format": npu_assembler.COMMAND_FORMAT},
            "tensors": {},
            "operations": [
                {
                    "name": "first",
                    "engine": "control",
                    "opcode": "NOP",
                    "depends_on": ["later"],
                    "fields": {"control": {}},
                },
                {
                    "name": "later",
                    "engine": "control",
                    "opcode": "NOP",
                    "fields": {"control": {}},
                },
            ],
        }
        with self.assertRaisesRegex(npu_assembler.CompileError, "earlier operation"):
            npu_assembler.compile_document(document)


if __name__ == "__main__":
    unittest.main()
