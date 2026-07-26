from __future__ import annotations

import os
import sys
import tempfile
import unittest
from pathlib import Path

import numpy as np


os.environ.setdefault("CUDA_VISIBLE_DEVICES", "-1")
os.environ.setdefault("TF_CPP_MIN_LOG_LEVEL", "2")
os.environ.setdefault("TF_NUM_INTEROP_THREADS", "1")
os.environ.setdefault("TF_NUM_INTRAOP_THREADS", "1")

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

import npu_model_compiler as compiler
from frontends.common import FrontendError, FrontendOptions
from frontends.keras_frontend import load_keras
from frontends.tflite_frontend import (
    _check_runtime_encoding,
    _check_fixed_range,
    _decode_constant,
    load_tflite,
)


try:
    import keras
    import tensorflow as tf
except ImportError:
    keras = None
    tf = None


@unittest.skipIf(
    keras is None or tf is None,
    "TensorFlow 2.18 and Keras 3 are required",
)
class KerasTFLiteFrontendTests(unittest.TestCase):
    def options(self) -> FrontendOptions:
        return FrontendOptions(dtype="int16", fraction_bits=8, batch_size=1)

    def dense_model(self):
        source = keras.Input(batch_size=1, shape=(4,), name="features")
        output = keras.layers.Dense(
            3,
            activation="relu",
            kernel_initializer=keras.initializers.Constant(
                [
                    [0.25, -0.5, 0.125],
                    [0.5, 0.25, -0.25],
                    [-0.125, 0.375, 0.5],
                    [0.75, -0.25, 0.25],
                ]
            ),
            bias_initializer=keras.initializers.Constant([0.1, -0.2, 0.3]),
            name="prediction",
        )(source)
        return keras.Model(source, output, name="dense_application")

    def test_real_tflite_dense_reaches_cmd128(self) -> None:
        model = self.dense_model()
        content = tf.lite.TFLiteConverter.from_keras_model(model).convert()
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "dense.tflite"
            path.write_bytes(content)
            document = load_tflite(path, self.options())
            output = Path(directory) / "tflite-c-package"
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
            self.assertTrue((output / "dense_model.h").is_file())
            self.assertTrue((output / "dense_model.c").is_file())
            self.assertTrue((output / "dense.manifest.json").is_file())
        operator_types = [item["type"] for item in document["operators"]]
        self.assertIn("MatMul", operator_types)
        self.assertIn("Add", operator_types)
        self.assertIn("ReLU", operator_types)
        result = compiler.compile_model_document(
            document, compiler.TargetConfig(), source_name="dense.tflite"
        )
        self.assertGreater(len(result.command_image), 0)
        self.assertEqual(len(result.command_image) % 16, 0)
        self.assertEqual(result.runtime["command_bits"], 128)

    def test_real_keras_dense_uses_tflite_path(self) -> None:
        model = self.dense_model()
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "dense.keras"
            model.save(path)
            document = load_keras(path, self.options())
            output = Path(directory) / "keras-c-package"
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
            self.assertTrue((output / "dense_model.h").is_file())
            self.assertTrue((output / "dense_model.c").is_file())
            self.assertTrue((output / "dense.manifest.json").is_file())
        self.assertEqual(
            document["frontend"]["keras_import_path"],
            "in_memory_tflite",
        )
        result = compiler.compile_model_document(
            document, compiler.TargetConfig(), source_name="dense.keras"
        )
        self.assertGreater(len(result.command_image), 0)

    def test_real_tflite_conv2d_uses_hwio_kernel_and_compiles(self) -> None:
        source = keras.Input(
            batch_size=1, shape=(4, 4, 2), name="image"
        )
        output = keras.layers.Conv2D(
            3,
            kernel_size=3,
            padding="same",
            activation="relu",
            kernel_initializer=keras.initializers.Constant(0.0625),
            bias_initializer=keras.initializers.Constant([0.1, 0.0, -0.1]),
            name="feature_extractor",
        )(source)
        model = keras.Model(source, output)
        content = tf.lite.TFLiteConverter.from_keras_model(model).convert()
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "conv.tflite"
            path.write_bytes(content)
            document = load_tflite(path, self.options())
        conv = next(
            item for item in document["operators"] if item["type"] == "Conv2D"
        )
        kernel_name = conv["inputs"][1]
        kernel = next(
            item
            for item in document["constants"]
            if item["name"] == kernel_name
        )
        self.assertEqual(kernel["shape"], [3, 3, 2, 3])
        self.assertEqual(conv["attributes"]["data_format"], "NHWC")
        result = compiler.compile_model_document(
            document, compiler.TargetConfig(), source_name="conv.tflite"
        )
        self.assertGreater(len(result.command_image), 0)

    def test_real_tflite_tensor_operator_sequence_compiles(self) -> None:
        class TensorOperators(tf.Module):
            @tf.function(
                input_signature=[
                    tf.TensorSpec(shape=(2, 3), dtype=tf.float32, name="x")
                ]
            )
            def __call__(self, source):
                value = source + tf.constant(0.125, dtype=tf.float32)
                value = tf.nn.gelu(value, approximate=False)
                value = tf.math.sigmoid(value)
                value = tf.math.tanh(value)
                value = tf.nn.softmax(value, axis=-1)
                value = tf.reshape(value, (3, 2))
                value = tf.transpose(value, (1, 0))
                return tf.concat((value, value), axis=-1)

        module = TensorOperators()
        concrete = module.__call__.get_concrete_function()
        converter = tf.lite.TFLiteConverter.from_concrete_functions(
            [concrete], module
        )
        content = converter.convert()
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "tensor_ops.tflite"
            path.write_bytes(content)
            document = load_tflite(path, self.options())
        operator_types = [item["type"] for item in document["operators"]]
        for required in (
            "Add",
            "GELU",
            "Sigmoid",
            "Tanh",
            "Softmax",
            "Reshape",
            "Transpose",
            "Concat",
        ):
            self.assertIn(required, operator_types)
        result = compiler.compile_model_document(
            document,
            compiler.TargetConfig(),
            source_name="tensor_ops.tflite",
        )
        self.assertGreater(len(result.command_image), 0)

    def test_real_keras_transformer_encoder_direct_path_compiles(self) -> None:
        source = keras.Input(
            batch_size=1, shape=(4, 8), name="token_features"
        )
        attention = keras.layers.MultiHeadAttention(
            num_heads=2,
            key_dim=4,
            value_dim=4,
            use_bias=False,
            dropout=0.0,
            name="self_attention",
        )(source, source)
        residual1 = keras.layers.Add(name="attention_residual")(
            [source, attention]
        )
        normalized1 = keras.layers.LayerNormalization(
            axis=-1, epsilon=1e-3, name="attention_norm"
        )(residual1)
        hidden = keras.layers.Dense(
            16, activation="gelu", name="ffn_expand"
        )(normalized1)
        contracted = keras.layers.Dense(
            8, activation="linear", name="ffn_contract"
        )(hidden)
        residual2 = keras.layers.Add(name="ffn_residual")(
            [normalized1, contracted]
        )
        output = keras.layers.LayerNormalization(
            axis=-1, epsilon=1e-3, name="ffn_norm"
        )(residual2)
        model = keras.Model(source, output, name="transformer_encoder")
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "transformer.keras"
            model.save(path)
            document = load_keras(path, self.options())
        self.assertEqual(
            document["frontend"]["keras_import_path"],
            "direct_standard_transformer_encoder",
        )
        operator_types = [item["type"] for item in document["operators"]]
        self.assertEqual(operator_types.count("MultiHeadAttention"), 1)
        self.assertEqual(operator_types.count("LayerNorm"), 2)
        self.assertGreaterEqual(operator_types.count("MatMul"), 2)
        attention_node = next(
            item
            for item in document["operators"]
            if item["type"] == "MultiHeadAttention"
        )
        self.assertEqual(attention_node["attributes"]["num_heads"], 2)
        self.assertEqual(attention_node["attributes"]["projection_shift"], 8)
        self.assertEqual(attention_node["attributes"]["score_shift"], 8)
        self.assertEqual(attention_node["attributes"]["value_shift"], 8)
        self.assertEqual(attention_node["attributes"]["output_shift"], 8)
        self.assertAlmostEqual(
            attention_node["attributes"]["score_scale"],
            1.0 / (256.0 * 2.0),
        )
        result = compiler.compile_model_document(
            document,
            compiler.TargetConfig(),
            source_name="transformer.keras",
        )
        self.assertGreater(len(result.command_image), 0)
        self.assertEqual(len(result.command_image) % 16, 0)
        self.assertTrue(
            any(
                item.name == "self_attention_q_projection"
                for item in result.assembled_operations
            )
        )

    def test_per_axis_constant_scale_and_zero_point_are_applied(self) -> None:
        detail = {
            "name": "per_axis_weight",
            "quantization_parameters": {
                "scales": np.asarray([0.5, 0.25], dtype=np.float32),
                "zero_points": np.asarray([1, -2], dtype=np.int32),
                "quantized_dimension": 0,
            },
        }
        values = np.asarray([[1, 3], [-2, 2]], dtype=np.int8)
        decoded = _decode_constant(values, detail)
        np.testing.assert_allclose(
            decoded,
            np.asarray([[0.0, 1.0], [0.0, 1.0]], dtype=np.float64),
        )

    def test_runtime_nonzero_zero_point_is_rejected(self) -> None:
        detail = {
            "name": "asymmetric_activation",
            "quantization_parameters": {
                "scales": np.asarray([0.125], dtype=np.float32),
                "zero_points": np.asarray([-3], dtype=np.int32),
                "quantized_dimension": 0,
            },
        }
        with self.assertRaisesRegex(FrontendError, "zero point -3"):
            _check_runtime_encoding(detail)

    def test_constant_outside_selected_fixed_range_is_rejected(self) -> None:
        with self.assertRaisesRegex(FrontendError, "cannot be stored"):
            _check_fixed_range(
                np.asarray([1000.0], dtype=np.float32),
                dtype="int16",
                scale=1.0 / 256.0,
                location="test constant",
            )


if __name__ == "__main__":
    unittest.main()
