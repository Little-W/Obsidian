from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def load_module(name: str, filename: str):
    spec = importlib.util.spec_from_file_location(name, ROOT / filename)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


conv = load_module("conv_lowering", "conv_lowering.py")
assembler = load_module("npu_assembler_for_conv", "npu_assembler.py")


class GeometryTests(unittest.TestCase):
    @staticmethod
    def execute_plan(plan, input_values):
        result = [0] * (plan.im2col_rows * plan.im2col_columns)
        for tap in conv.iter_im2col_taps(plan):
            for batch in range(tap.shape[0]):
                for output_y in range(tap.shape[1]):
                    for output_x in range(tap.shape[2]):
                        for channel in range(tap.shape[3]):
                            index = (batch, output_y, output_x, channel)
                            source = tap.src_element_offset + sum(
                                item
                                * (
                                    1
                                    if dimension == len(index) - 1
                                    else stride
                                )
                                for dimension, (item, stride) in enumerate(
                                    zip(index, tap.src_stride_elements)
                                )
                            )
                            target = tap.dst_element_offset + sum(
                                item
                                * (
                                    1
                                    if dimension == len(index) - 1
                                    else stride
                                )
                                for dimension, (item, stride) in enumerate(
                                    zip(index, tap.dst_stride_elements)
                                )
                            )
                            result[target] = input_values[source]
        return result

    @staticmethod
    def direct_im2col(plan, input_values):
        batch_count, input_h, input_w, channels = plan.input_shape
        kernel_h, kernel_w, _, _ = plan.kernel_shape
        _, output_h, output_w, _ = plan.output_shape
        stride_h, stride_w = plan.strides
        dilation_h, dilation_w = plan.dilations
        pad_top, _, pad_left, _ = plan.padding
        result = []
        for batch in range(batch_count):
            for output_y in range(output_h):
                for output_x in range(output_w):
                    for kernel_y in range(kernel_h):
                        input_y = (
                            output_y * stride_h
                            - pad_top
                            + kernel_y * dilation_h
                        )
                        for kernel_x in range(kernel_w):
                            input_x = (
                                output_x * stride_w
                                - pad_left
                                + kernel_x * dilation_w
                            )
                            for channel in range(channels):
                                if (
                                    0 <= input_y < input_h
                                    and 0 <= input_x < input_w
                                ):
                                    source = (
                                        (
                                            batch * input_h + input_y
                                        )
                                        * input_w
                                        + input_x
                                    ) * channels + channel
                                    result.append(input_values[source])
                                else:
                                    result.append(0)
        return result

    def test_valid_shape_and_tap_offsets(self) -> None:
        plan = conv.infer_conv2d(
            [1, 3, 3, 2],
            [2, 2, 2, 3],
            {
                "strides": [1, 1],
                "dilations": [1, 1],
                "padding": "VALID",
                "groups": 1,
                "data_format": "NHWC",
            },
        )
        self.assertEqual(plan.output_shape, (1, 2, 2, 3))
        self.assertEqual(plan.padded_shape, (1, 3, 3, 2))
        self.assertEqual(plan.im2col_shape, (4, 8))
        self.assertFalse(plan.needs_fill)

        taps = list(conv.iter_im2col_taps(plan))
        self.assertEqual(len(taps), 4)
        self.assertEqual(
            [
                (tap.kh, tap.kw, tap.src_start, tap.dst_element_offset)
                for tap in taps
            ],
            [
                (0, 0, 0, 0),
                (0, 1, 2, 2),
                (1, 0, 6, 4),
                (1, 1, 8, 6),
            ],
        )
        for tap in taps:
            self.assertEqual(tap.shape, (1, 2, 2, 2))
            self.assertEqual(tap.src_stride_elements, (18, 6, 2, 0))
            self.assertEqual(tap.dst_stride_elements, (32, 16, 8, 0))
        values = list(range(1, 19))
        self.assertEqual(
            self.execute_plan(plan, values),
            self.direct_im2col(plan, values),
        )

    def test_same_padding_stride_and_fill(self) -> None:
        plan = conv.infer_conv2d(
            [1, 3, 4, 2],
            [3, 3, 2, 4],
            {
                "strides": [2, 2],
                "dilations": [1, 1],
                "padding": "SAME",
            },
        )
        self.assertEqual(plan.padding, (1, 1, 0, 1))
        self.assertEqual(plan.output_shape, (1, 2, 2, 4))
        self.assertEqual(plan.padded_shape, (1, 5, 5, 2))
        self.assertEqual(plan.im2col_shape, (4, 18))
        self.assertTrue(plan.needs_fill)

        taps = {(tap.kh, tap.kw): tap for tap in conv.iter_im2col_taps(plan)}
        self.assertEqual(len(taps), 9)
        top_left = taps[(0, 0)]
        self.assertEqual(top_left.shape, (1, 1, 2, 2))
        self.assertEqual(top_left.src_element_offset, 8)
        self.assertEqual(top_left.dst_element_offset, 36)
        self.assertEqual(top_left.src_stride_elements, (24, 16, 4, 0))
        self.assertEqual(top_left.dst_stride_elements, (72, 36, 18, 0))
        values = list(range(1, 25))
        self.assertEqual(
            self.execute_plan(plan, values),
            self.direct_im2col(plan, values),
        )

    def test_explicit_padding_and_dilation(self) -> None:
        plan = conv.infer_conv2d(
            [2, 5, 6, 4],
            [2, 3, 4, 7],
            {
                "strides": [2, 1],
                "dilations": [2, 2],
                "padding": {
                    "top": 1,
                    "bottom": 2,
                    "left": 3,
                    "right": 1,
                },
            },
        )
        self.assertEqual(plan.padding, (1, 2, 3, 1))
        self.assertEqual(plan.output_shape, (2, 3, 6, 7))
        self.assertEqual(plan.im2col_shape, (36, 24))


class KernelTests(unittest.TestCase):
    def test_kernel_reshape_uses_kh_kw_cin_cout_order(self) -> None:
        values = list(range(16))
        matrix = conv.conv_kernel_to_matrix(values, [2, 1, 2, 4])
        self.assertEqual(matrix.rows, 4)
        self.assertEqual(matrix.columns, 4)
        self.assertEqual(matrix.values, tuple(values))

        received = []

        def tile_packer(data, rows, columns):
            received.append((tuple(data), rows, columns))
            return b"packed"

        result = conv.pack_conv_kernel(
            values, [2, 1, 2, 4], tile_packer
        )
        self.assertEqual(result, b"packed")
        self.assertEqual(received, [(tuple(values), 4, 4)])


class OperationTests(unittest.TestCase):
    @staticmethod
    def placement(name, addr, size, dtype="int8"):
        return conv.TensorPlacement(name, addr, size, "l1", dtype)

    def test_valid_lowering_uses_copy_nd_and_gemm(self) -> None:
        geometry = conv.infer_conv2d(
            [1, 3, 3, 2], [2, 2, 2, 3], {"padding": "VALID"}
        )
        operations = conv.emit_conv2d_operations(
            "conv0",
            geometry,
            self.placement("input", 0x1000, 18),
            self.placement("im2col", 0x2000, 32),
            self.placement("kernel", 0x3000, 128),
            self.placement("output", 0x4000, 48, "int32"),
        )
        self.assertEqual(len(operations), 5)
        self.assertEqual(
            [operation["opcode"] for operation in operations],
            ["COPY_ND", "COPY_ND", "COPY_ND", "COPY_ND", "GEMM"],
        )
        self.assertEqual(
            [operation["engine"] for operation in operations],
            ["dma", "dma", "dma", "dma", "matrix"],
        )
        self.assertEqual(
            operations[-1]["descriptor"]["matrix"]["ldc_bytes"], 12
        )
        self.assertEqual(
            operations[-1]["descriptor"]["matrix"]["m"], 4
        )
        self.assertEqual(
            operations[-1]["descriptor"]["matrix"]["n"], 3
        )
        self.assertEqual(
            operations[-1]["descriptor"]["matrix"]["k"], 8
        )

        document = {
            "schema_version": 1,
            "target": {
                "command_format": "cmd128-v1",
                "descriptor_base": 0x100000,
                "mt": 8,
                "kt": 16,
                "nt": 8,
            },
            "tensors": {},
            "operations": list(operations),
        }
        compiled, commands, descriptors = assembler.compile_document(document)
        self.assertEqual(len(compiled), 5)
        self.assertEqual(len(commands), 5 * 16)
        self.assertEqual(len(descriptors), 5 * 256)

    def test_same_padding_emits_fill_before_taps(self) -> None:
        geometry = conv.infer_conv2d(
            [1, 3, 4, 2],
            [3, 3, 2, 4],
            {"padding": "SAME", "strides": [2, 2]},
        )
        operations = conv.emit_conv2d_operations(
            "conv1",
            geometry,
            self.placement("input", 0x1000, 24),
            self.placement("im2col", 0x2000, 72),
            self.placement("kernel", 0x3000, 256),
            self.placement("output", 0x4000, 64, "int32"),
        )
        self.assertEqual(operations[0]["opcode"], "FILL")
        self.assertEqual(
            operations[0]["descriptor"]["dma"]["shape"], [4, 18]
        )
        self.assertEqual(
            operations[0]["descriptor"]["dma"]["dst_stride_bytes"],
            [18, 0],
        )
        self.assertEqual(
            sum(operation["opcode"] == "COPY_ND" for operation in operations),
            9,
        )
        first_copy = operations[1]
        self.assertEqual(
            first_copy["descriptor"]["common"]["src0"]["addr"], 0x1008
        )
        self.assertEqual(
            first_copy["descriptor"]["common"]["dst"]["addr"], 0x2024
        )
        self.assertEqual(
            first_copy["descriptor"]["dma"]["shape"], [1, 1, 2, 2]
        )
        self.assertEqual(
            first_copy["descriptor"]["dma"]["src_stride_bytes"],
            [24, 16, 4, 0],
        )
        self.assertEqual(
            first_copy["descriptor"]["dma"]["dst_stride_bytes"],
            [72, 36, 18, 0],
        )
        for previous, current in zip(operations, operations[1:]):
            self.assertEqual(current["depends_on"], [previous["name"]])

    def test_no_native_convolution_opcode_is_emitted(self) -> None:
        geometry = conv.infer_conv2d(
            [1, 2, 2, 2], [1, 1, 2, 2], {}
        )
        operations = conv.emit_conv2d_operations(
            "conv_opcode_check",
            geometry,
            self.placement("input", 0x1000, 8),
            self.placement("im2col", 0x2000, 8),
            self.placement("kernel", 0x3000, 128),
            self.placement("output", 0x4000, 32, "int32"),
        )
        self.assertTrue(
            all(operation["engine"] in {"dma", "matrix"} for operation in operations)
        )
        self.assertTrue(
            all("CONV" not in str(operation["opcode"]).upper() for operation in operations)
        )
        self.assertTrue(
            all(
                "CONV" not in opcode_name
                for opcodes in assembler.OPCODES.values()
                for opcode_name in opcodes
            )
        )


class FailureTests(unittest.TestCase):
    def test_channel_mismatch_is_rejected(self) -> None:
        with self.assertRaisesRegex(
            conv.ConvLoweringError, "kernel input channels"
        ):
            conv.infer_conv2d([1, 3, 3, 4], [3, 3, 2, 8], {})

    def test_grouped_convolution_is_rejected(self) -> None:
        with self.assertRaisesRegex(conv.ConvLoweringError, "groups=1"):
            conv.infer_conv2d(
                [1, 3, 3, 4], [3, 3, 4, 8], {"groups": 2}
            )

    def test_int4_odd_channels_are_rejected(self) -> None:
        plan = conv.infer_conv2d(
            [1, 3, 3, 3], [2, 2, 3, 4], {"padding": "VALID"}
        )
        with self.assertRaisesRegex(
            conv.ConvLoweringError, "even input channel"
        ):
            conv.emit_im2col_dma_operations(
                "int4_conv",
                conv.plan_im2col(plan),
                conv.TensorPlacement("input", 0x1000, 14, "l1", "int4"),
                conv.TensorPlacement("im2col", 0x2000, 24, "l1", "int4"),
            )


if __name__ == "__main__":
    unittest.main()
