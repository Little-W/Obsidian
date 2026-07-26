#!/usr/bin/env python3
"""Real-file tests for the ONNX and trusted PyTorch frontends."""

from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path

import numpy as np


COMPILER_DIR = Path(__file__).resolve().parents[1]
if str(COMPILER_DIR) not in sys.path:
    sys.path.insert(0, str(COMPILER_DIR))

import npu_model_compiler as compiler
from frontends import FrontendOptions, load_framework_document


class OnnxFrontendTests(unittest.TestCase):
    def _write_model(self, path: Path) -> None:
        import onnx
        from onnx import TensorProto, helper, numpy_helper

        weight = np.asarray(
            [
                [0.25, -0.5, 0.75, 0.125],
                [0.5, 0.25, -0.25, 0.375],
                [-0.75, 0.5, 0.25, -0.125],
            ],
            dtype=np.float32,
        )
        bias = np.asarray([0.125, -0.25, 0.375, 0.5], dtype=np.float32)
        graph = helper.make_graph(
            [
                helper.make_node("MatMul", ["input", "weight"], ["mm"]),
                helper.make_node("Add", ["mm", "bias"], ["biased"]),
                helper.make_node("Relu", ["biased"], ["activated"]),
                helper.make_node(
                    "Softmax", ["activated"], ["output"], axis=-1
                ),
            ],
            "dense_classifier",
            [
                helper.make_tensor_value_info(
                    "input", TensorProto.FLOAT, [1, 3]
                )
            ],
            [
                helper.make_tensor_value_info(
                    "output", TensorProto.FLOAT, [1, 4]
                )
            ],
            [
                numpy_helper.from_array(weight, "weight"),
                numpy_helper.from_array(bias, "bias"),
            ],
        )
        model = helper.make_model(
            graph,
            opset_imports=[helper.make_opsetid("", 17)],
            producer_name="npu_frontend_test",
        )
        onnx.save(model, str(path))

    def test_real_onnx_compiles_to_cmd128(self) -> None:
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / "classifier.onnx"
            self._write_model(path)
            options = FrontendOptions(dtype="int16", fraction_bits=8)
            document = load_framework_document(path, options)
            result = compiler.compile_model_document(
                document,
                compiler.TargetConfig(),
                source_name=path.name,
            )
            self.assertEqual(document["frontend"]["source_format"], "onnx")
            self.assertEqual(len(result.command_image) % 16, 0)
            self.assertGreater(len(result.assembled_operations), 0)
            self.assertIn("RELU", {task.opcode for task in result.tasks})
            output = Path(temp) / "onnx-c-package"
            self.assertEqual(
                compiler.main(
                    [
                        str(path),
                        "--output-dir",
                        str(output),
                        "--model-dtype",
                        "int16",
                        "--fraction-bits",
                        "8",
                    ]
                ),
                0,
            )
            self.assertTrue((output / "classifier_model.h").is_file())
            self.assertTrue((output / "classifier_model.c").is_file())
            self.assertTrue((output / "classifier.manifest.json").is_file())


class PytorchFrontendTests(unittest.TestCase):
    def test_real_torchscript_compiles_to_cmd128(self) -> None:
        try:
            import torch
        except ImportError as error:
            self.skipTest(str(error))

        class Classifier(torch.nn.Module):
            def __init__(self) -> None:
                super().__init__()
                self.linear = torch.nn.Linear(3, 4)

            def forward(self, value: torch.Tensor) -> torch.Tensor:
                return torch.softmax(torch.relu(self.linear(value)), dim=-1)

        torch.manual_seed(7)
        model = Classifier().eval()
        traced = torch.jit.trace(model, torch.zeros((1, 3)))
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / "classifier.torchscript"
            torch.jit.save(traced, str(path))
            options = FrontendOptions(
                dtype="int16",
                fraction_bits=8,
                trust_model=True,
                input_shapes={"0": (1, 3)},
            )
            document = load_framework_document(path, options)
            result = compiler.compile_model_document(
                document,
                compiler.TargetConfig(),
                source_name=path.name,
            )
            self.assertEqual(
                document["frontend"]["source_format"], "pytorch"
            )
            self.assertEqual(len(result.command_image) % 16, 0)
            self.assertGreater(len(result.assembled_operations), 0)
            output = Path(temp) / "torch-c-package"
            self.assertEqual(
                compiler.main(
                    [
                        str(path),
                        "--output-dir",
                        str(output),
                        "--trust-model",
                        "--pytorch-format",
                        "torchscript",
                        "--model-dtype",
                        "int16",
                        "--fraction-bits",
                        "8",
                    ]
                ),
                0,
            )
            self.assertTrue((output / "classifier_model.h").is_file())
            self.assertTrue((output / "classifier_model.c").is_file())
            self.assertTrue((output / "classifier.manifest.json").is_file())

    def test_pytorch_requires_explicit_trust(self) -> None:
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / "untrusted.pt"
            path.write_bytes(b"not a model")
            with self.assertRaisesRegex(ValueError, "trust-model"):
                load_framework_document(path, FrontendOptions())


if __name__ == "__main__":
    unittest.main()
