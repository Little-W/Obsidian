from __future__ import annotations

import copy
import importlib.util
import sys
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))
SPEC = importlib.util.spec_from_file_location(
    "npu_model_compiler", ROOT / "npu_model_compiler.py"
)
assert SPEC is not None and SPEC.loader is not None
npu_model_compiler = importlib.util.module_from_spec(SPEC)
sys.modules[SPEC.name] = npu_model_compiler
SPEC.loader.exec_module(npu_model_compiler)


def base_graph(dtype: str = "int8") -> dict:
    return {
        "schema_version": 1,
        "model": {"name": "validation_graph"},
        "inputs": [{"name": "x", "shape": [2, 4], "dtype": dtype}],
        "constants": [
            {
                "name": "weight",
                "shape": [4, 3],
                "dtype": dtype,
                "data": [1] * 12,
            }
        ],
        "tensors": [
            {"name": "projected", "shape": [2, 3], "dtype": dtype},
            {"name": "output", "shape": [2, 3], "dtype": dtype},
        ],
        "operators": [
            {
                "name": "activation",
                "type": "GELU",
                "inputs": ["projected"],
                "outputs": ["output"],
            },
            {
                "name": "projection",
                "type": "MatMul",
                "inputs": ["x", "weight"],
                "outputs": ["projected"],
            },
        ],
        "outputs": ["output"],
    }


class ModelGraphValidationTests(unittest.TestCase):
    def test_topological_sort_is_derived_from_tensor_flow(self) -> None:
        _, tensors, operators, outputs = (
            npu_model_compiler.parse_model_document(base_graph())
        )
        self.assertEqual(
            [operator.name for operator in operators],
            ["projection", "activation"],
        )
        self.assertEqual(tensors["projected"].shape, (2, 3))
        self.assertEqual(outputs, ("output",))

    def test_unknown_tensor_is_rejected(self) -> None:
        graph = base_graph()
        graph["operators"][1]["inputs"][0] = "missing"
        with self.assertRaisesRegex(
            npu_model_compiler.ModelCompileError, "unknown tensor"
        ):
            npu_model_compiler.parse_model_document(graph)

    def test_cycle_is_rejected(self) -> None:
        graph = base_graph()
        graph["constants"] = []
        graph["operators"] = [
            {
                "name": "first",
                "type": "Add",
                "inputs": ["x", "second_value"],
                "outputs": ["first_value"],
            },
            {
                "name": "second",
                "type": "Add",
                "inputs": ["x", "first_value"],
                "outputs": ["second_value"],
            },
        ]
        graph["tensors"] = [
            {"name": "first_value", "shape": [2, 4], "dtype": "int8"},
            {"name": "second_value", "shape": [2, 4], "dtype": "int8"},
        ]
        graph["outputs"] = ["first_value"]
        with self.assertRaisesRegex(
            npu_model_compiler.ModelCompileError, "cycle"
        ):
            npu_model_compiler.parse_model_document(graph)

    def test_declared_shape_error_is_rejected(self) -> None:
        graph = base_graph()
        graph["tensors"][0]["shape"] = [3, 3]
        with self.assertRaisesRegex(
            npu_model_compiler.ModelCompileError, "declaration"
        ):
            npu_model_compiler.parse_model_document(graph)

    def test_all_integer_dtypes_are_accepted_for_elementwise_graph(self) -> None:
        for dtype in ("int4", "int8", "int16", "int32"):
            with self.subTest(dtype=dtype):
                graph = {
                    "schema_version": 1,
                    "model": {"name": f"gelu_{dtype}"},
                    "inputs": [
                        {"name": "x", "shape": [2, 4], "dtype": dtype}
                    ],
                    "tensors": [
                        {
                            "name": "output",
                            "shape": [2, 4],
                            "dtype": dtype,
                        }
                    ],
                    "operators": [
                        {
                            "name": "gelu",
                            "type": "GELU",
                            "inputs": ["x"],
                            "outputs": ["output"],
                        }
                    ],
                    "outputs": ["output"],
                }
                _, tensors, _, _ = (
                    npu_model_compiler.parse_model_document(
                        copy.deepcopy(graph)
                    )
                )
                self.assertEqual(tensors["output"].dtype, dtype)

    @staticmethod
    def tensor(
        name: str,
        shape: tuple[int, ...],
        address: int,
        *,
        kind: str = "intermediate",
        dtype: str = "int8",
        storage_bytes: int | None = None,
    ):
        return npu_model_compiler.TensorInfo(
            name=name,
            shape=shape,
            dtype=dtype,
            kind=kind,
            storage_bytes=(
                npu_model_compiler.logical_tensor_bytes(shape, dtype)
                if storage_bytes is None
                else storage_bytes
            ),
            l1_addr=address,
        )

    def lower_complex(self, kind: str):
        source = self.tensor("source", (2, 4), 0x1000)
        output = self.tensor("output", (2, 4), 0x1100)
        tensors = {"source": source, "output": output}
        inputs = ["source"]
        if kind == "layernorm":
            tensors["gamma"] = self.tensor(
                "gamma", (4,), 0x1200, kind="constant"
            )
            tensors["beta"] = self.tensor(
                "beta", (4,), 0x1300, kind="constant"
            )
            inputs.extend(("gamma", "beta"))
        operator = npu_model_compiler.OperatorInfo(
            name=f"test_{kind}",
            op_type=kind,
            inputs=tuple(inputs),
            outputs=("output",),
            attributes={},
            source_index=0,
        )
        tasks = npu_model_compiler.lower_simple_operator(
            operator,
            tensors,
            npu_model_compiler.AddressAllocator(
                0x2000, 0x10000, "test L1"
            ),
            npu_model_compiler.TargetConfig(),
            {},
        )
        self.assertEqual(len(tasks), 1)
        return tasks[0].descriptor["complex"]

    def test_unused_complex_inputs_have_zero_scales(self) -> None:
        for kind in ("softmax", "gelu"):
            with self.subTest(kind=kind):
                fields = self.lower_complex(kind)
                self.assertEqual(fields["src1_scale"], 0.0)
                self.assertEqual(fields["src2_scale"], 0.0)
                self.assertEqual(fields["epsilon"], 0.0)

    def test_layernorm_has_zero_clip_fields(self) -> None:
        fields = self.lower_complex("layernorm")
        self.assertEqual(fields["input_clip_min"], 0.0)
        self.assertEqual(fields["input_clip_max"], 0.0)
        self.assertGreater(fields["src1_scale"], 0.0)
        self.assertGreater(fields["src2_scale"], 0.0)
        self.assertGreater(fields["epsilon"], 0.0)

    def test_attention_softmax_has_zero_unused_scales(self) -> None:
        tensors = {
            "x": self.tensor("x", (2, 8), 0x1000, kind="input"),
            "wq": self.tensor(
                "wq", (8, 8), 0x2000, kind="constant", storage_bytes=256
            ),
            "wk": self.tensor(
                "wk", (8, 8), 0x2100, kind="constant", storage_bytes=256
            ),
            "wv": self.tensor(
                "wv", (8, 8), 0x2200, kind="constant", storage_bytes=256
            ),
            "wo": self.tensor(
                "wo", (8, 8), 0x2300, kind="constant", storage_bytes=256
            ),
            "output": self.tensor("output", (2, 8), 0x3000),
            "rq0": self.tensor(
                "rq0", (8,), 0x3100, kind="constant", dtype="int8"
            ),
            "rq2": self.tensor(
                "rq2", (8,), 0x3200, kind="constant", dtype="int8"
            ),
        }
        operator = npu_model_compiler.OperatorInfo(
            name="attention",
            op_type="MultiHeadAttention",
            inputs=("x", "wq", "wk", "wv", "wo"),
            outputs=("output",),
            attributes={
                "num_heads": 2,
                "_head_width": 4,
                "_tokens": 2,
            },
            source_index=0,
        )
        tasks = npu_model_compiler.lower_multi_head_attention(
            operator,
            tensors,
            npu_model_compiler.AddressAllocator(
                0x4000, 0x100000, "test L1"
            ),
            npu_model_compiler.TargetConfig(),
            {0: "rq0", 2: "rq2"},
        )
        softmax = next(
            task for task in tasks if task.name == "attention_softmax"
        )
        fields = softmax.descriptor["complex"]
        self.assertEqual(fields["src1_scale"], 0.0)
        self.assertEqual(fields["src2_scale"], 0.0)

    def test_add_clears_unused_src2_scale(self) -> None:
        tensors = {
            "left": self.tensor("left", (2, 4), 0x1000),
            "right": self.tensor("right", (2, 4), 0x1100),
            "output": self.tensor("output", (2, 4), 0x1200),
        }
        operator = npu_model_compiler.OperatorInfo(
            name="residual_add",
            op_type="Add",
            inputs=("left", "right"),
            outputs=("output",),
            attributes={},
            source_index=0,
        )
        task = npu_model_compiler.lower_simple_operator(
            operator,
            tensors,
            npu_model_compiler.AddressAllocator(
                0x2000, 0x10000, "test L1"
            ),
            npu_model_compiler.TargetConfig(),
            {},
        )[0]
        self.assertEqual(
            task.descriptor["vector"]["src2_scale_bits"], 0
        )

    def test_scalar_add_uses_scalar_flag_without_broadcast_field(self) -> None:
        tensors = {
            "source": self.tensor("source", (2, 4), 0x1000),
            "scalar": npu_model_compiler.TensorInfo(
                name="scalar",
                shape=(1,),
                dtype="int8",
                kind="constant",
                data=(2,),
                storage_bytes=1,
                l1_addr=0x1100,
            ),
            "output": self.tensor("output", (2, 4), 0x1200),
        }
        operator = npu_model_compiler.OperatorInfo(
            name="scalar_add",
            op_type="Add",
            inputs=("source", "scalar"),
            outputs=("output",),
            attributes={},
            source_index=0,
        )
        task = npu_model_compiler.lower_simple_operator(
            operator,
            tensors,
            npu_model_compiler.AddressAllocator(
                0x2000, 0x10000, "test L1"
            ),
            npu_model_compiler.TargetConfig(),
            {},
        )[0]
        vector = task.descriptor["vector"]
        self.assertTrue(vector["src1_from_scalar0"])
        self.assertNotIn("broadcast1", vector)
        self.assertEqual(vector["src2_scale_bits"], 0)


if __name__ == "__main__":
    unittest.main()
