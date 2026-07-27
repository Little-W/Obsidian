from __future__ import annotations

import json
import math
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest
from dataclasses import replace
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

import npu_assembler
import npu_model_compiler as compiler
import model_artifacts
from frontends import options_from_namespace


def add_model(dtype: str = "int8", columns: int = 4) -> dict:
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
            "dtype": "int8",
            "data": identity(width),
        }
        for name in ("wq", "wk", "wv", "wo")
    ]
    return {
        "schema_version": 1,
        "model": {"name": "attention"},
        "inputs": [
            {"name": "x", "shape": [tokens, width], "dtype": "int8"}
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


def int16_matmul_model() -> dict:
    return {
        "schema_version": 1,
        "model": {"name": "int16_matmul"},
        "inputs": [
            {"name": "x", "shape": [1, 2], "dtype": "int16"}
        ],
        "constants": [
            {
                "name": "weight",
                "shape": [2, 1],
                "dtype": "int16",
                "data": [-32768, 0x1234],
            }
        ],
        "operators": [
            {
                "name": "projection",
                "type": "MatMul",
                "inputs": ["x", "weight"],
                "outputs": ["y"],
            }
        ],
        "outputs": ["y"],
    }


class EndToEndCompilerTests(unittest.TestCase):
    def test_int16_cli_frontend_and_artifact_encoding(self) -> None:
        arguments = model_artifacts.parse_args(
            [
                "model.onnx",
                "--output-dir",
                "out",
                "--model-dtype",
                "int16",
                "--fraction-bits",
                "8",
            ]
        )
        options = options_from_namespace(arguments)
        self.assertEqual(options.dtype, "int16")
        self.assertEqual(options.fraction_bits, 8)
        self.assertEqual(options.scale, 1.0 / 256.0)

        result = compiler.compile_model_document(
            int16_matmul_model(), compiler.TargetConfig()
        )
        self.assertEqual(
            compiler.pack_integer_values(
                [-32768, -1, 0, 32767], "int16"
            ),
            b"\x00\x80\xff\xff\x00\x00\xff\x7f",
        )
        self.assertEqual(result.tensors["x"].storage_bytes, 4)
        self.assertEqual(result.tensors["y"].storage_bytes, 2)
        weight = result.tensors["weight"]
        weight_offset = (
            weight.ddr_addr - result.runtime["constant_base_ddr"]
        )
        self.assertEqual(
            result.constant_image[weight_offset : weight_offset + 2],
            b"\x00\x80",
        )
        self.assertEqual(
            result.constant_image[weight_offset + 16 : weight_offset + 18],
            b"\x34\x12",
        )
        projection = next(
            item
            for item in result.assembled_operations
            if item.name == "projection"
        )
        _low, high = struct.unpack("<QQ", projection.command)
        self.assertEqual((high >> 16) & 0x3, 3)
        self.assertEqual((projection.payload >> 5) & 0x3, 3)
        self.assertEqual(projection.payload & 0x1F, 0)
        package = model_artifacts.build_model_c_source(
            "int16_matmul", result
        ).decode("ascii")
        self.assertIn("4u, 3u", package)

    def test_high_level_add_reaches_cmd128(self) -> None:
        result = compiler.compile_model_document(
            add_model(), compiler.TargetConfig()
        )
        self.assertEqual(
            len(result.command_image),
            len(result.assembled_operations) * 16,
        )
        names = [item.name for item in result.assembled_operations]
        self.assertEqual(names[0], "__load_constants")
        self.assertEqual(names[-1], "__store_output_y__row_1")
        self.assertIn("sum", names)
        self.assertEqual(result.runtime["command_bits"], 128)
        self.assertEqual(result.runtime["inputs"][0]["name"], "x")
        self.assertEqual(result.runtime["outputs"][0]["name"], "y")

    def test_wide_vector_operation_is_split_by_row_and_feature(self) -> None:
        result = compiler.compile_model_document(
            add_model(columns=48), compiler.TargetConfig()
        )
        chunks = [
            item
            for item in result.assembled_operations
            if item.name.startswith("sum__rows_")
        ]
        self.assertEqual(
            [item.name for item in chunks],
            [
                "sum__rows_0_1__features_0_32",
                "sum__rows_0_1__features_32_16",
                "sum__rows_1_1__features_0_32",
                "sum__rows_1_1__features_32_16",
            ],
        )
        self.assertEqual(
            [((item.payload >> 11) & 0x1F) + 1 for item in chunks],
            [1, 1, 1, 1],
        )
        self.assertEqual(
            [((item.payload >> 6) & 0x1F) + 1 for item in chunks],
            [32, 16, 32, 16],
        )
        x_base = result.tensors["x"].l1_addr
        self.assertIsNotNone(x_base)
        self.assertEqual(
            [((item.payload >> 64) & 0xFFFF) << 4 for item in chunks],
            [
                x_base,
                x_base + 32,
                x_base + 48,
                x_base + 80,
            ],
        )
        all_operations = result.assembled_operations
        for current in chunks[1:]:
            current_index = all_operations.index(current)
            predecessor = all_operations[current_index - 1]
            self.assertEqual(predecessor.engine, "control")
            self.assertTrue(predecessor.name.startswith("__event_join_"))
            self.assertIn(predecessor.signal_event, current.wait_events)

    def test_matrix_rows_are_split_without_changing_k_or_n(self) -> None:
        document = {
            "schema_version": 1,
            "model": {"name": "matrix_rows"},
            "inputs": [
                {"name": "x", "shape": [65, 16], "dtype": "int8"}
            ],
            "constants": [
                {
                    "name": "weight",
                    "shape": [16, 8],
                    "dtype": "int8",
                    "data": [1] * (16 * 8),
                }
            ],
            "operators": [
                {
                    "name": "projection",
                    "type": "MatMul",
                    "inputs": ["x", "weight"],
                    "outputs": ["y"],
                }
            ],
            "outputs": ["y"],
        }
        result = compiler.compile_model_document(
            document, compiler.TargetConfig()
        )
        chunks = [
            operation
            for operation in result.assembled_operations
            if operation.name.startswith("projection__batch_")
        ]
        self.assertEqual(len(chunks), 2)
        self.assertEqual(
            [((item.payload >> 20) & 0x3F) + 1 for item in chunks],
            [64, 1],
        )
        self.assertEqual(
            [((item.payload >> 14) & 0x3F) + 1 for item in chunks],
            [8, 8],
        )
        self.assertEqual(
            [((item.payload >> 8) & 0x3F) + 1 for item in chunks],
            [16, 16],
        )
        x_base = result.tensors["x"].l1_addr
        y_base = result.tensors["y"].l1_addr
        self.assertEqual(
            [((item.payload >> 66) & 0x3FFF) << 6 for item in chunks],
            [x_base, x_base + 64 * 16],
        )
        self.assertEqual(
            [((item.payload >> 38) & 0x3FFF) << 6 for item in chunks],
            [y_base, y_base + 64 * 8],
        )

    def test_matrix_packed_b_axis_over_64_is_rejected(self) -> None:
        document = {
            "schema_version": 1,
            "model": {"name": "wide_matrix"},
            "inputs": [{"name": "x", "shape": [1, 8], "dtype": "int8"}],
            "constants": [
                {
                    "name": "weight",
                    "shape": [8, 65],
                    "dtype": "int8",
                    "data": [1] * (8 * 65),
                }
            ],
            "operators": [
                {
                    "name": "projection",
                    "type": "MatMul",
                    "inputs": ["x", "weight"],
                    "outputs": ["y"],
                }
            ],
            "outputs": ["y"],
        }
        with self.assertRaisesRegex(
            compiler.ModelCompileError,
            "packed-B stride field",
        ):
            compiler.compile_model_document(
                document, compiler.TargetConfig()
            )

    def test_complex_rows_and_elementwise_features_are_split(self) -> None:
        softmax_document = {
            "schema_version": 1,
            "model": {"name": "softmax_rows"},
            "inputs": [
                {"name": "x", "shape": [70, 16], "dtype": "int8"}
            ],
            "constants": [],
            "operators": [
                {
                    "name": "softmax",
                    "type": "Softmax",
                    "inputs": ["x"],
                    "outputs": ["y"],
                }
            ],
            "outputs": ["y"],
        }
        softmax_result = compiler.compile_model_document(
            softmax_document, compiler.TargetConfig()
        )
        softmax_chunks = [
            operation
            for operation in softmax_result.assembled_operations
            if operation.name.startswith("softmax__rows_")
        ]
        self.assertEqual(len(softmax_chunks), 3)
        self.assertEqual(
            [((item.payload >> 27) & 0x1F) + 1 for item in softmax_chunks],
            [32, 32, 6],
        )
        source_base = softmax_result.tensors["x"].l1_addr
        self.assertEqual(
            [((item.payload >> 64) & 0xFFFF) << 4 for item in softmax_chunks],
            [source_base, source_base + 32 * 16, source_base + 64 * 16],
        )

        activation_document = {
            "schema_version": 1,
            "model": {"name": "wide_activation"},
            "inputs": [
                {"name": "x", "shape": [1, 300], "dtype": "int8"}
            ],
            "constants": [],
            "operators": [
                {
                    "name": "gelu",
                    "type": "GELU",
                    "inputs": ["x"],
                    "outputs": ["y"],
                }
            ],
            "outputs": ["y"],
        }
        activation_result = compiler.compile_model_document(
            activation_document, compiler.TargetConfig()
        )
        activation_chunks = [
            operation
            for operation in activation_result.assembled_operations
            if operation.name.startswith("gelu__rows_")
        ]
        self.assertEqual(
            [((item.payload >> 19) & 0xFF) + 1 for item in activation_chunks],
            [256, 44],
        )

    def test_softmax_feature_length_over_256_is_rejected(self) -> None:
        document = {
            "schema_version": 1,
            "model": {"name": "wide_softmax"},
            "inputs": [
                {"name": "x", "shape": [1, 257], "dtype": "int8"}
            ],
            "constants": [],
            "operators": [
                {
                    "name": "softmax",
                    "type": "Softmax",
                    "inputs": ["x"],
                    "outputs": ["y"],
                }
            ],
            "outputs": ["y"],
        }
        with self.assertRaisesRegex(
            compiler.ModelCompileError,
            "feature axis would change the operation result",
        ):
            compiler.compile_model_document(
                document, compiler.TargetConfig()
            )

    def test_attention_48_tokens_splits_complex_rows(self) -> None:
        result = compiler.compile_model_document(
            attention_model(tokens=48, width=8),
            compiler.TargetConfig(),
        )
        softmax_chunks = [
            operation
            for operation in result.assembled_operations
            if operation.name.startswith("attention_softmax__rows_")
        ]
        self.assertEqual(len(softmax_chunks), 3)
        self.assertEqual(
            [((item.payload >> 27) & 0x1F) + 1 for item in softmax_chunks],
            [32, 32, 32],
        )
        self.assertEqual(
            [((item.payload >> 19) & 0xFF) + 1 for item in softmax_chunks],
            [48, 48, 48],
        )

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

    def test_attention_initializes_and_populates_matrix_b_tiles(self) -> None:
        tokens = 10
        width = 36
        heads = 2
        head_width = width // heads
        target = compiler.TargetConfig()
        result = compiler.compile_model_document(
            attention_model(tokens=tokens, width=width),
            target,
        )
        operation_list = result.low_ir["operations"]
        operations = {
            operation["name"]: operation for operation in operation_list
        }
        k_tiles = result.tensors["__attention_k_tiles"]
        v_tiles = result.tensors["__attention_v_tiles"]

        for kind, tensor in (("k", k_tiles), ("v", v_tiles)):
            fill = operations[f"attention_fill_{kind}_tiles"]
            self.assertEqual(fill["opcode"], "FILL")
            self.assertEqual(
                fill["fields"]["dma"]["shape"],
                [tensor.storage_bytes],
            )
            self.assertEqual(fill["fields"]["dma"]["fill_value"], 0)

        self.assertEqual(
            operations["attention_transpose_k_head_0"]["fields"]["common"][
                "dst"
            ]["addr"],
            result.tensors["__attention_k_transposed"].l1_addr,
        )
        self.assertEqual(
            operations["attention_qk"]["fields"]["common"]["src1"],
            "__attention_k_tiles",
        )
        self.assertEqual(
            operations["attention_attention_value"]["fields"]["common"][
                "src1"
            ],
            "__attention_v_tiles",
        )

        k_values = tuple(
            ((row * width + column) * 5 + 3) % 101 - 50
            for row in range(tokens)
            for column in range(width)
        )
        v_values = tuple(
            ((row * width + column) * 7 + 11) % 103 - 51
            for row in range(tokens)
            for column in range(width)
        )

        def reference_address(value: object) -> int:
            if isinstance(value, str):
                address = result.tensors[value].l1_addr
            else:
                self.assertIsInstance(value, dict)
                address = value["addr"]
            self.assertIsNotNone(address)
            return int(address)

        def execute_tile_setup(initial_byte: int) -> tuple[bytes, bytes]:
            memory = bytearray([initial_byte] * target.l1_bytes)
            for name, values in (
                ("__attention_k", k_values),
                ("__attention_v", v_values),
            ):
                address = result.tensors[name].l1_addr
                self.assertIsNotNone(address)
                memory[int(address) : int(address) + len(values)] = bytes(
                    value & 0xFF for value in values
                )

            for operation in operation_list:
                name = operation["name"]
                if name in (
                    "attention_fill_k_tiles",
                    "attention_fill_v_tiles",
                ):
                    fields = operation["fields"]
                    destination = reference_address(fields["common"]["dst"])
                    count = math.prod(fields["dma"]["shape"])
                    memory[destination : destination + count] = bytes(count)
                    continue
                if not name.startswith(
                    (
                        "attention_pack_k_head_",
                        "attention_transpose_k_head_",
                        "attention_pack_k_tile_",
                        "attention_split_k_tile_",
                        "attention_pack_v_head_",
                        "attention_pack_v_tile_",
                        "attention_split_v_tile_",
                    )
                ):
                    continue

                fields = operation["fields"]
                common = fields["common"]
                source = reference_address(common["src0"])
                destination = reference_address(common["dst"])
                dma = fields["dma"]
                if operation["opcode"] == "TRANSPOSE_2D":
                    rows, columns = dma["shape"]
                    for row in range(rows):
                        for column in range(columns):
                            memory[destination + column * rows + row] = (
                                memory[source + row * columns + column]
                            )
                    continue

                segment_count = dma["segment_count"]
                segment_bytes = dma["segment_bytes"]
                segment_stride = dma["segment_stride"]
                for segment in range(segment_count):
                    if operation["opcode"] == "PACK":
                        source_offset = segment * segment_stride
                        destination_offset = segment * segment_bytes
                    else:
                        self.assertEqual(operation["opcode"], "SPLIT")
                        source_offset = segment * segment_bytes
                        destination_offset = segment * segment_stride
                    memory[
                        destination + destination_offset :
                        destination + destination_offset + segment_bytes
                    ] = memory[
                        source + source_offset :
                        source + source_offset + segment_bytes
                    ]

            return (
                bytes(
                    memory[
                        int(k_tiles.l1_addr) :
                        int(k_tiles.l1_addr) + k_tiles.storage_bytes
                    ]
                ),
                bytes(
                    memory[
                        int(v_tiles.l1_addr) :
                        int(v_tiles.l1_addr) + v_tiles.storage_bytes
                    ]
                ),
            )

        actual_k, actual_v = execute_tile_setup(0xA5)
        self.assertEqual(
            (actual_k, actual_v),
            execute_tile_setup(0x5A),
        )

        k_head_bytes = compiler.tiled_matrix_bytes(
            head_width, tokens, "int8", target
        )
        v_head_bytes = compiler.tiled_matrix_bytes(
            tokens, head_width, "int8", target
        )
        for head in range(heads):
            expected_k = compiler.pack_matrix_b_values(
                tuple(
                    k_values[
                        token * width + head * head_width + feature
                    ]
                    for feature in range(head_width)
                    for token in range(tokens)
                ),
                head_width,
                tokens,
                "int8",
                target,
            )
            expected_v = compiler.pack_matrix_b_values(
                tuple(
                    v_values[
                        token * width + head * head_width + feature
                    ]
                    for token in range(tokens)
                    for feature in range(head_width)
                ),
                tokens,
                head_width,
                "int8",
                target,
            )
            self.assertEqual(
                actual_k[
                    head * k_head_bytes : (head + 1) * k_head_bytes
                ],
                expected_k,
            )
            self.assertEqual(
                actual_v[
                    head * v_head_bytes : (head + 1) * v_head_bytes
                ],
                expected_v,
            )

    def test_attention_non_power_of_two_scale_is_folded_into_q_and_k(
        self,
    ) -> None:
        document = attention_model(width=16)
        document["constants"][0]["data"] = [
            64 if row == column else 0
            for row in range(16)
            for column in range(16)
        ]
        document["constants"][1]["data"] = list(
            document["constants"][0]["data"]
        )
        attributes = document["operators"][0]["attributes"]
        attributes.update(
            {
                "projection_shift": 5,
                "score_shift": 5,
                "value_shift": 5,
                "output_shift": 5,
                "score_scale": 1.0 / math.sqrt(8.0),
            }
        )
        result = compiler.compile_model_document(
            document, compiler.TargetConfig()
        )
        operations = {
            operation["name"]: operation
            for operation in result.low_ir["operations"]
        }
        self.assertFalse(
            any("score_scale_" in name for name in operations)
        )
        softmax = operations["attention_softmax"]
        hardware_scale = softmax["fields"]["complex"]["src0_scale"]
        self.assertEqual(hardware_scale, 0.5)
        _, query_scale, key_scale = compiler.attention_score_scale_plan(
            attributes["score_scale"],
            "int8",
            "test.score_scale",
            query_values=document["constants"][0]["data"],
            key_values=document["constants"][1]["data"],
            width=16,
            heads=2,
            query_dtype="int8",
            key_dtype="int8",
        )
        self.assertIsNotNone(query_scale)
        self.assertIsNotNone(key_scale)
        self.assertAlmostEqual(
            query_scale * key_scale,
            attributes["score_scale"] / hardware_scale,
        )
        expected_query = compiler.scale_integer_values(
            document["constants"][0]["data"], query_scale, "int8"
        )
        expected_key = compiler.scale_integer_values(
            document["constants"][1]["data"], key_scale, "int8"
        )
        packed_query = compiler.pack_matrix_b_values(
            expected_query,
            16,
            16,
            "int8",
            compiler.TargetConfig(),
        )
        query = result.tensors["wq"]
        query_offset = (
            query.ddr_addr - result.runtime["constant_base_ddr"]
        )
        self.assertEqual(
            result.constant_image[
                query_offset : query_offset + len(packed_query)
            ],
            packed_query,
        )
        packed_key = compiler.pack_matrix_b_values(
            expected_key,
            16,
            16,
            "int8",
            compiler.TargetConfig(),
        )
        key = result.tensors["wk"]
        key_offset = key.ddr_addr - result.runtime["constant_base_ddr"]
        self.assertEqual(
            result.constant_image[
                key_offset : key_offset + len(packed_key)
            ],
            packed_key,
        )

    def test_conv2d_reaches_im2col_and_gemm_only(self) -> None:
        document = {
            "schema_version": 1,
            "model": {"name": "conv"},
            "inputs": [
                {"name": "x", "shape": [1, 3, 3, 2], "dtype": "int8"}
            ],
            "constants": [
                {
                    "name": "kernel",
                    "shape": [2, 2, 2, 3],
                    "dtype": "int8",
                    "data": [1] * 24,
                }
            ],
            "operators": [
                {
                    "name": "conv",
                    "type": "Conv2D",
                    "inputs": ["x", "kernel"],
                    "outputs": ["y"],
                    "attributes": {
                        "padding": "SAME",
                        "output_shift": 5,
                    },
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
        self.assertIn("COPY_1D", opcodes)
        self.assertIn("GEMM", opcodes)
        self.assertNotIn("COPY_ND", opcodes)
        self.assertFalse(any("CONV" in opcode.upper() for opcode in opcodes))
        gemm = next(
            operation
            for operation in result.assembled_operations
            if operation.engine == "matrix"
        )
        self.assertEqual(gemm.payload & 0x1F, 5)

    def test_relu_marks_unused_vector_scales_as_zero(self) -> None:
        document = {
            "schema_version": 1,
            "model": {"name": "relu"},
            "inputs": [
                {"name": "x", "shape": [2, 4], "dtype": "int8"}
            ],
            "constants": [],
            "operators": [
                {
                    "name": "relu",
                    "type": "ReLU",
                    "inputs": ["x"],
                    "outputs": ["y"],
                    "attributes": {"scale": 0.03125},
                }
            ],
            "outputs": ["y"],
        }
        result = compiler.compile_model_document(
            document, compiler.TargetConfig()
        )
        operation = next(
            item
            for item in result.low_ir["operations"]
            if item["name"] == "relu"
        )
        vector = operation["fields"]["vector"]
        self.assertEqual(vector["src1_scale_bits"], 0)
        self.assertEqual(vector["src2_scale_bits"], 0)

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
        load = next(
            item
            for item in result.low_ir["operations"]
            if item["name"] == "__load_input_x__row_0"
        )
        self.assertEqual(load["opcode"], "COPY_1D")
        self.assertEqual(load["fields"]["dma"]["shape"], [5])

    def test_command_batches_fit_fixed_fifo_bursts(self) -> None:
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
            "inputs": [{"name": "x", "shape": [1, 8], "dtype": "int8"}],
            "constants": [],
            "operators": operators,
            "outputs": [previous],
        }
        results = {}
        for task_entries in (1, 7, 8, 9, 32):
            with self.subTest(task_entries=task_entries):
                result = compiler.compile_model_document(
                    document,
                    compiler.TargetConfig(
                        task_entries=task_entries
                    ),
                )
                results[task_entries] = result
                batches = result.runtime["batches"]
                limit = min(task_entries, 8)
                self.assertTrue(batches)
                self.assertLessEqual(
                    max(len(batch) for batch in batches), limit
                )
                self.assertEqual(
                    sum(len(batch) for batch in batches),
                    result.runtime["command_count"],
                )
                self.assertEqual(
                    [item for batch in batches for item in batch],
                    list(range(result.runtime["command_count"])),
                )

        result = results[32]
        self.assertGreater(result.runtime["command_count"], 32)
        self.assertEqual(
            [len(batch) for batch in result.runtime["batches"]],
            [8, 8, 8, 8, 8, 3],
        )
        self.assertEqual(
            result.runtime["command_fifo_max_burst_commands"], 8
        )

        source = model_artifacts.build_model_c_source(
            "long_chain", result
        ).decode("ascii")
        offset = 0
        for batch in result.runtime["batches"]:
            self.assertIn(
                f"    {{{offset}u, {len(batch)}u, ",
                source,
            )
            offset += len(batch)
        self.assertEqual(
            len(result.runtime["batch_execution"]),
            len(result.runtime["batches"]),
        )
        self.assertFalse(
            result.runtime["batch_execution"][0]["host_sync_before"]
        )
        self.assertTrue(
            all(
                row["host_sync_after"]
                for row in result.runtime["batch_execution"]
            )
        )

        with tempfile.TemporaryDirectory() as temporary:
            source_path = Path(temporary) / "long_chain.json"
            source_path.write_text(
                json.dumps(document), encoding="utf-8"
            )
            manifest = json.loads(
                model_artifacts.build_model_manifest(
                    source_path,
                    result,
                    {"long_chain_model.c": source.encode("ascii")},
                ).decode("utf-8")
            )
        self.assertEqual(
            manifest["command_batches"], result.runtime["batches"]
        )
        self.assertLessEqual(
            max(
                len(batch)
                for batch in manifest["command_batches"]
            ),
            8,
        )
        self.assertEqual(
            manifest["batch_execution"],
            result.runtime["batch_execution"],
        )

    def test_dependency_events_are_reused_with_host_synchronized_rearm(self) -> None:
        operators = []
        previous = "x"
        for index in range(280):
            output = f"t{index}"
            operators.append(
                {
                    "name": f"relu{index}",
                    "type": "ReLU",
                    "inputs": [previous],
                    "outputs": [output],
                }
            )
            previous = output
        document = {
            "schema_version": 1,
            "model": {"name": "event_reuse"},
            "inputs": [{"name": "x", "shape": [1, 8], "dtype": "int8"}],
            "constants": [],
            "operators": operators,
            "outputs": [previous],
        }
        result = compiler.compile_model_document(
            document, compiler.TargetConfig()
        )
        rearms = [
            operation
            for operation in result.assembled_operations
            if operation.engine == "control"
            and operation.opcode
            == npu_assembler.OPCODES["control"]["EVENT_REARM"]
        ]
        self.assertTrue(rearms)
        rearm_ids = {operation.command_id for operation in rearms}
        rearm_batch_lengths = []
        for row in result.runtime["batch_execution"]:
            contains_rearm = any(
                command_id in rearm_ids
                for command_id in row["command_ids"]
            )
            self.assertEqual(row["contains_event_rearm"], contains_rearm)
            if contains_rearm:
                rearm_batch_lengths.append(len(row["command_ids"]))
                self.assertLessEqual(len(row["command_ids"]), 8)
                self.assertTrue(
                    all(
                        command_id in rearm_ids
                        for command_id in row["command_ids"]
                    )
                )
                self.assertTrue(row["host_sync_before"])
                self.assertTrue(row["host_sync_after"])
        self.assertGreater(max(rearm_batch_lengths), 1)
        self.assertLessEqual(len(result.runtime["batches"]), 45)
        self.assertEqual(result.low_ir["target"]["name"], "single-core")
        self.assertEqual(result.runtime["external_descriptor_bytes"], 0)

    def test_l1_storage_is_reused_after_last_consumer(self) -> None:
        document = {
            "schema_version": 1,
            "model": {"name": "reuse"},
            "inputs": [{"name": "x", "shape": [1, 8], "dtype": "int8"}],
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
        operations, commands = npu_assembler.compile_document(result.low_ir)
        self.assertEqual(len(operations), len(result.assembled_operations))
        self.assertEqual(commands, result.command_image)

    def test_cli_emits_default_c_model_package_and_check(self) -> None:
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
            ]
            self.assertEqual(compiler.main(arguments), 0)
            expected = {
                "model_model.h",
                "model_model.c",
                "model.manifest.json",
            }
            self.assertEqual(
                {path.name for path in output.iterdir()}, expected
            )
            header = (output / "model_model.h").read_text(encoding="ascii")
            c_source = (output / "model_model.c").read_text(
                encoding="ascii"
            )
            self.assertIn("model_model_config_t", header)
            self.assertIn("model_model_commands", header)
            self.assertNotIn("model_model_descriptors", header)
            self.assertIn("model_model_weights", header)
            self.assertIn("model_model_inputs", header)
            self.assertIn("model_model_outputs", header)
            self.assertIn("model_model_command_batches", header)
            self.assertIn("NPU_MODEL_ALIGN(16)", c_source)
            self.assertIn("NPU_MODEL_ALIGN(256)", c_source)

            manifest = json.loads(
                (output / "model.manifest.json").read_text(
                    encoding="utf-8"
                )
            )
            self.assertEqual(
                manifest["deployment_format"], "c-model-package-v1"
            )
            self.assertEqual(
                set(manifest["artifacts"]),
                {"model_model.c", "model_model.h"},
            )
            self.assertEqual(compiler.main(arguments + ["--check"]), 0)

            original = (output / "model_model.c").read_bytes()
            (output / "model_model.c").write_bytes(original + b"\n")
            with self.assertRaisesRegex(
                compiler.ModelCompileError, "artifact differs"
            ):
                compiler.main(arguments + ["--check"])

    def test_emit_raw_adds_debug_files(self) -> None:
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
                "--emit-raw",
            ]
            self.assertEqual(compiler.main(arguments), 0)
            expected = {
                "model_model.h",
                "model_model.c",
                "model.npuasm.json",
                "model.cmd.bin",
                "model.const.bin",
                "model.runtime.json",
                "model.manifest.json",
            }
            self.assertEqual(
                {path.name for path in output.iterdir()}, expected
            )
            manifest = json.loads(
                (output / "model.manifest.json").read_text(
                    encoding="utf-8"
                )
            )
            self.assertEqual(
                set(manifest["artifacts"]), expected - {"model.manifest.json"}
            )
            self.assertEqual(compiler.main(arguments + ["--check"]), 0)

    def test_generated_c_compiles_and_empty_weight_array_is_standard_c(
        self,
    ) -> None:
        compiler_path = shutil.which("cc")
        if compiler_path is None:
            self.skipTest("C compiler is unavailable")
        document = {
            "schema_version": 1,
            "model": {"name": "no_weights"},
            "inputs": [
                {"name": "x", "shape": [1, 8], "dtype": "int8"}
            ],
            "constants": [],
            "operators": [
                {
                    "name": "reshape",
                    "type": "Reshape",
                    "inputs": ["x"],
                    "outputs": ["y"],
                    "attributes": {"shape": [2, 4]},
                }
            ],
            "outputs": ["y"],
        }
        with tempfile.TemporaryDirectory() as temporary:
            base = Path(temporary)
            result = compiler.compile_model_document(
                document, compiler.TargetConfig()
            )
            empty_result = replace(result, constant_image=b"")
            header_path = base / "empty_model.h"
            source_path = base / "empty_model.c"
            header_path.write_bytes(
                model_artifacts.build_model_c_header(
                    "empty", empty_result
                )
            )
            source_path.write_bytes(
                model_artifacts.build_model_c_source(
                    "empty", empty_result
                )
            )
            header = header_path.read_text(encoding="ascii")
            c_source = source_path.read_text(encoding="ascii")
            self.assertIn("#define EMPTY_MODEL_WEIGHT_BYTES 0u", header)
            self.assertIn(
                "#define EMPTY_MODEL_WEIGHT_STORAGE_BYTES 1u", header
            )
            self.assertIn(
                "empty_model_weights[EMPTY_MODEL_WEIGHT_STORAGE_BYTES]",
                c_source,
            )
            subprocess.run(
                [
                    compiler_path,
                    "-std=c11",
                    "-Wall",
                    "-Wextra",
                    "-Werror",
                    "-c",
                    str(source_path),
                    "-o",
                    str(base / "empty_model.o"),
                ],
                check=True,
                capture_output=True,
                text=True,
            )

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

    def test_40_bit_ddr_top_range_compiles_and_is_exported(self) -> None:
        address_limit = 1 << 40
        target = compiler.TargetConfig(
            ddr_base=address_limit - 256,
            ddr_bytes=address_limit,
        )
        result = compiler.compile_model_document(add_model(), target)
        self.assertEqual(result.runtime["axi_addr_bits"], 40)
        self.assertEqual(result.runtime["ddr_base"], address_limit - 256)
        self.assertEqual(result.runtime["ddr_bytes"], address_limit)
        self.assertLessEqual(
            result.runtime["ddr_allocation_end"], address_limit
        )
        self.assertTrue(result.low_ir["target"]["gaddr_bases"])
        for tensor in result.tensors.values():
            if tensor.ddr_addr is None:
                continue
            self.assertLess(tensor.ddr_addr, address_limit)
            self.assertLessEqual(
                tensor.ddr_addr + tensor.storage_bytes,
                address_limit,
            )

        header = model_artifacts.build_model_c_header(
            "top_range", result
        ).decode("ascii")
        source = model_artifacts.build_model_c_source(
            "top_range", result
        ).decode("ascii")
        self.assertIn("#define TOP_RANGE_MODEL_AXI_ADDR_BITS 40u", header)
        selected_base = next(
            value
            for name, value in result.runtime["gaddr_bases"].items()
            if name != "zero" and value != 0
        )
        self.assertIn(f"UINT64_C(0x{selected_base:x})", source)

    def test_40_bit_target_and_allocation_overruns_are_rejected(self) -> None:
        address_limit = 1 << 40
        with self.assertRaisesRegex(
            compiler.ModelCompileError, r"ddr_base.*below 2\^40"
        ):
            compiler.compile_model_document(
                add_model(),
                compiler.TargetConfig(
                    ddr_base=address_limit,
                    ddr_bytes=address_limit,
                ),
            )
        with self.assertRaisesRegex(
            compiler.ModelCompileError, r"ddr_bytes.*at most 2\^40"
        ):
            compiler.compile_model_document(
                add_model(),
                compiler.TargetConfig(
                    ddr_bytes=address_limit + 1,
                ),
            )
        with self.assertRaisesRegex(
            compiler.ModelCompileError, "DDR allocation"
        ):
            compiler.compile_model_document(
                add_model(),
                compiler.TargetConfig(
                    ddr_base=address_limit - 128,
                    ddr_bytes=address_limit,
                ),
            )
        with self.assertRaisesRegex(
            compiler.ModelCompileError, "axi_addr_bits.*equal 40"
        ):
            compiler.compile_model_document(
                add_model(),
                compiler.TargetConfig(axi_addr_bits=48),
            )

    def test_model_artifact_rejects_bit40_binding(self) -> None:
        result = compiler.compile_model_document(
            add_model(), compiler.TargetConfig()
        )
        runtime = dict(result.runtime)
        runtime["inputs"] = [
            dict(result.runtime["inputs"][0], ddr_addr=1 << 40)
        ]
        invalid = replace(result, runtime=runtime)
        with self.assertRaisesRegex(ValueError, r"below 2\^40"):
            model_artifacts.build_model_c_header("invalid", invalid)

    def test_model_artifact_rejects_unaligned_global_base(self) -> None:
        result = compiler.compile_model_document(
            add_model(), compiler.TargetConfig()
        )
        runtime = dict(result.runtime)
        runtime["gaddr_bases"] = dict(result.runtime["gaddr_bases"])
        runtime["gaddr_bases"]["input"] = 1
        invalid = replace(result, runtime=runtime)
        with self.assertRaisesRegex(ValueError, r"aligned to 8 bytes"):
            model_artifacts.build_model_c_header("invalid", invalid)


if __name__ == "__main__":
    unittest.main()
