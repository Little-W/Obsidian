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
        encoded = npu_assembler.encode_command128(
            descriptor_addr=0x123400,
            command_id=0x345,
            engine=2,
            opcode=0x42,
            header_flags=0x155,
            wait0=0x123,
            wait1=0x456,
            signal=0x789,
        )
        low, high = struct.unpack("<QQ", encoded)
        self.assertEqual(low, 0x2345000000123400)
        self.assertEqual(
            high,
            (1 << 56)
            | (0x789 << 44)
            | (0x456 << 32)
            | (0x123 << 20)
            | (0x155 << 8)
            | 0x42,
        )

    def test_reserved_header_flags_are_rejected(self) -> None:
        with self.assertRaises(npu_assembler.CompileError):
            npu_assembler.encode_command128(
                0x1000, 1, 1, 0x20, 0x400, 0xFFF, 0xFFF, 0xFFF
            )


class AssemblerTests(unittest.TestCase):
    def test_example_int16_and_dependency(self) -> None:
        document = json.loads(
            (ROOT / "examples" / "int16_regression.json").read_text(
                encoding="utf-8"
            )
        )
        operations, commands, descriptors = npu_assembler.compile_document(
            document
        )
        self.assertEqual(len(operations), 2)
        self.assertEqual(len(commands), 32)
        self.assertEqual(len(descriptors), 512)
        self.assertEqual(operations[0].descriptor_addr, 0x100000)
        self.assertEqual(operations[1].descriptor_addr, 0x100100)
        self.assertEqual(operations[0].signal_event, 0)
        self.assertEqual(operations[1].wait_events, (0, 0xFFF))
        dma_numeric = struct.unpack_from("<I", descriptors, 0x38)[0]
        matrix_numeric = struct.unpack_from("<I", descriptors, 0x100 + 0x38)[0]
        self.assertEqual(dma_numeric & 0x3, 3)
        self.assertEqual((dma_numeric >> 6) & 0x3, 3)
        self.assertEqual(matrix_numeric & 0x3, 3)
        self.assertEqual((matrix_numeric >> 2) & 0x3, 3)
        self.assertEqual((matrix_numeric >> 6) & 0x3, 3)

    def test_artifacts_and_check_are_deterministic(self) -> None:
        source = ROOT / "examples" / "int16_regression.json"
        with tempfile.TemporaryDirectory() as temporary:
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
            after = {
                path.name: path.read_bytes()
                for path in output.iterdir()
                if path.is_file()
            }
            self.assertEqual(before, after)

    def test_forward_dependency_is_rejected(self) -> None:
        document = {
            "schema_version": 1,
            "target": {"descriptor_base": "0x1000"},
            "tensors": {},
            "operations": [
                {
                    "name": "first",
                    "engine": "control",
                    "opcode": "NOP",
                    "depends_on": ["later"],
                    "descriptor": {},
                },
                {
                    "name": "later",
                    "engine": "control",
                    "opcode": "NOP",
                    "descriptor": {},
                },
            ],
        }
        with self.assertRaisesRegex(
            npu_assembler.CompileError, "earlier operation"
        ):
            npu_assembler.compile_document(document)


if __name__ == "__main__":
    unittest.main()
