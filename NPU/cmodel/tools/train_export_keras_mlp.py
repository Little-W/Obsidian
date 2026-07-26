#!/usr/bin/env python3
"""Train a small Keras MLP and export deterministic integer C-model vectors."""

from __future__ import annotations

import argparse
import hashlib
import os
from pathlib import Path
from typing import Iterable

os.environ.setdefault("CUDA_VISIBLE_DEVICES", "-1")
os.environ.setdefault("TF_ENABLE_ONEDNN_OPTS", "0")
os.environ.setdefault("TF_CPP_MIN_LOG_LEVEL", "3")

import keras
import numpy as np
import tensorflow as tf


SEED = 20260726
INPUT_DIM = 4
HIDDEN_DIM = 8
OUTPUT_DIM = 3
MT = 8
KT = 16
NT = 8


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--output",
        type=Path,
        default=Path("tests/generated/keras_mlp_fixture.h"),
    )
    parser.add_argument("--model-output", type=Path)
    parser.add_argument("--epochs", type=int, default=50)
    parser.add_argument("--train-samples", type=int, default=3072)
    parser.add_argument("--test-samples", type=int, default=768)
    parser.add_argument("--samples-per-class", type=int, default=24)
    return parser.parse_args()


def make_dataset(count: int, rng: np.random.Generator) -> tuple[np.ndarray, np.ndarray]:
    features = rng.uniform(-1.0, 1.0, size=(count, INPUT_DIM)).astype(np.float32)
    teacher_weight = np.asarray(
        [
            [2.4, -1.1, 0.2],
            [-1.2, 2.2, 0.3],
            [0.4, -0.8, 2.5],
            [1.1, 0.8, -1.6],
        ],
        dtype=np.float32,
    )
    teacher_bias = np.asarray([0.15, -0.10, 0.05], dtype=np.float32)
    labels = np.argmax(features @ teacher_weight + teacher_bias, axis=1)
    return features, labels.astype(np.int32)


def symmetric_scale(values: np.ndarray) -> float:
    maximum = float(np.max(np.abs(values)))
    return maximum / 127.0 if maximum != 0.0 else 1.0


def quantize_int8(values: np.ndarray, scale: float) -> np.ndarray:
    quantized = np.rint(values.astype(np.float64) / scale)
    return np.clip(quantized, -127, 127).astype(np.int8)


def quantize_bias(values: np.ndarray, scale: float) -> np.ndarray:
    quantized = np.rint(values.astype(np.float64) / scale)
    minimum = np.iinfo(np.int32).min
    maximum = np.iinfo(np.int32).max
    if np.any(quantized < minimum) or np.any(quantized > maximum):
        raise RuntimeError("bias does not fit INT32")
    return quantized.astype(np.int32)


def choose_multiplier_shift(ratio: float) -> tuple[int, int]:
    if not np.isfinite(ratio) or ratio <= 0.0:
        raise RuntimeError("invalid requant ratio")
    for shift in range(31, -1, -1):
        multiplier = int(round(ratio * float(1 << shift)))
        if 1 <= multiplier <= 0x7FFFFFFF:
            return multiplier, shift
    raise RuntimeError("requant ratio cannot be represented")


def round_shift_nearest_even(values: np.ndarray, multiplier: int, shift: int) -> np.ndarray:
    products = values.astype(np.int64) * np.int64(multiplier)
    if shift == 0:
        return products
    magnitude = np.abs(products)
    quotient = magnitude >> np.int64(shift)
    remainder = magnitude & np.int64((1 << shift) - 1)
    half = np.int64(1 << (shift - 1))
    increment = (remainder > half) | ((remainder == half) & ((quotient & 1) != 0))
    rounded = quotient + increment.astype(np.int64)
    return np.where(products < 0, -rounded, rounded)


def tile_weight(weight: np.ndarray) -> np.ndarray:
    k, n = weight.shape
    k_tiles = (k + KT - 1) // KT
    n_tiles = (n + NT - 1) // NT
    tiled = np.zeros(k_tiles * n_tiles * KT * NT, dtype=np.int8)
    for inner in range(k):
        for column in range(n):
            linear = (
                ((((inner // KT) * n_tiles + column // NT) * KT + inner % KT) * NT)
                + column % NT
            )
            tiled[linear] = weight[inner, column]
    return tiled


def select_balanced(
    features: np.ndarray, labels: np.ndarray, samples_per_class: int
) -> tuple[np.ndarray, np.ndarray]:
    selected: list[int] = []
    for class_id in range(OUTPUT_DIM):
        indices = np.flatnonzero(labels == class_id)
        if indices.size < samples_per_class:
            raise RuntimeError("test set does not contain enough examples")
        selected.extend(indices[:samples_per_class].tolist())
    order = np.asarray(selected, dtype=np.int64)
    return features[order], labels[order]


def render_array(name: str, c_type: str, values: Iterable[int], columns: int) -> str:
    flattened = [int(value) for value in values]
    lines = [f"static const {c_type} {name}[{len(flattened)}] = {{"]
    for start in range(0, len(flattened), columns):
        group = ", ".join(str(value) for value in flattened[start : start + columns])
        suffix = "," if start + columns < len(flattened) else ""
        lines.append(f"    {group}{suffix}")
    lines.append("};")
    return "\n".join(lines)


def build_header(
    input_q: np.ndarray,
    weight1_tiled: np.ndarray,
    bias1_q: np.ndarray,
    multiplier1: int,
    shift1: int,
    hidden_q: np.ndarray,
    weight2_tiled: np.ndarray,
    bias2_q: np.ndarray,
    logits_q: np.ndarray,
    labels: np.ndarray,
    keras_class: np.ndarray,
    integer_class: np.ndarray,
) -> str:
    sample_count = input_q.shape[0]
    float_correct = int(np.count_nonzero(keras_class == labels))
    integer_correct = int(np.count_nonzero(integer_class == labels))
    agreement = int(np.count_nonzero(integer_class == keras_class))
    sections = [
        "/* Generated by tools/train_export_keras_mlp.py with TensorFlow 2.18. */",
        "#ifndef KERAS_MLP_FIXTURE_H",
        "#define KERAS_MLP_FIXTURE_H",
        "",
        "#include <stdint.h>",
        "",
        f"#define KERAS_NPU_SAMPLE_COUNT {sample_count}u",
        f"#define KERAS_NPU_INPUT_DIM {INPUT_DIM}u",
        f"#define KERAS_NPU_HIDDEN_DIM {HIDDEN_DIM}u",
        f"#define KERAS_NPU_OUTPUT_DIM {OUTPUT_DIM}u",
        f"#define KERAS_NPU_FLOAT_CORRECT {float_correct}u",
        f"#define KERAS_NPU_INTEGER_CORRECT {integer_correct}u",
        f"#define KERAS_NPU_CLASS_AGREEMENT {agreement}u",
        f"#define KERAS_NPU_LAYER1_MULTIPLIER UINT32_C({multiplier1})",
        f"#define KERAS_NPU_LAYER1_SHIFT {shift1}",
        "",
        render_array("keras_npu_input", "int8_t", input_q.ravel(), 16),
        "",
        render_array(
            "keras_npu_layer1_weight_tiled", "int8_t", weight1_tiled.ravel(), 16
        ),
        "",
        render_array("keras_npu_layer1_bias", "int32_t", bias1_q.ravel(), 8),
        "",
        render_array("keras_npu_layer1_expected", "int8_t", hidden_q.ravel(), 16),
        "",
        render_array(
            "keras_npu_layer2_weight_tiled", "int8_t", weight2_tiled.ravel(), 16
        ),
        "",
        render_array("keras_npu_layer2_bias", "int32_t", bias2_q.ravel(), 8),
        "",
        render_array("keras_npu_logits_expected", "int32_t", logits_q.ravel(), 6),
        "",
        render_array("keras_npu_label", "uint8_t", labels.ravel(), 18),
        "",
        render_array("keras_npu_float_class", "uint8_t", keras_class.ravel(), 18),
        "",
        render_array("keras_npu_integer_class", "uint8_t", integer_class.ravel(), 18),
        "",
        "#endif",
        "",
    ]
    return "\n".join(sections)


def main() -> None:
    args = parse_args()
    if args.epochs <= 0 or args.samples_per_class <= 0:
        raise SystemExit("epochs and samples-per-class must be positive")

    tf.keras.utils.set_random_seed(SEED)
    tf.config.experimental.enable_op_determinism()
    tf.config.threading.set_inter_op_parallelism_threads(1)
    tf.config.threading.set_intra_op_parallelism_threads(1)
    rng = np.random.default_rng(SEED)
    train_x, train_y = make_dataset(args.train_samples, rng)
    test_x, test_y = make_dataset(args.test_samples, rng)

    model = keras.Sequential(
        [
            keras.layers.Input(shape=(INPUT_DIM,), dtype="float32"),
            keras.layers.Dense(HIDDEN_DIM, activation="relu"),
            keras.layers.Dense(OUTPUT_DIM),
        ],
        name="npu_integer_mlp",
    )
    model.compile(
        optimizer=keras.optimizers.Adam(learning_rate=0.012),
        loss=keras.losses.SparseCategoricalCrossentropy(from_logits=True),
        metrics=["accuracy"],
    )
    model.fit(
        train_x,
        train_y,
        batch_size=128,
        epochs=args.epochs,
        shuffle=False,
        verbose=0,
    )

    test_loss, test_accuracy = model.evaluate(test_x, test_y, verbose=0)
    fixture_x, fixture_y = select_balanced(test_x, test_y, args.samples_per_class)
    float_logits = model.predict(fixture_x, verbose=0)
    keras_class = np.argmax(float_logits, axis=1).astype(np.uint8)

    hidden_model = keras.Model(model.inputs[0], model.layers[0].output)
    calibration_hidden = hidden_model.predict(train_x, verbose=0)
    weight1, bias1 = model.layers[0].get_weights()
    weight2, bias2 = model.layers[1].get_weights()

    input_scale = symmetric_scale(train_x)
    weight1_scale = symmetric_scale(weight1)
    hidden_scale = symmetric_scale(calibration_hidden)
    weight2_scale = symmetric_scale(weight2)

    input_q = quantize_int8(fixture_x, input_scale)
    weight1_q = quantize_int8(weight1, weight1_scale)
    bias1_q = quantize_bias(bias1, input_scale * weight1_scale)
    multiplier1, shift1 = choose_multiplier_shift(
        input_scale * weight1_scale / hidden_scale
    )
    accumulator1 = (
        input_q.astype(np.int64) @ weight1_q.astype(np.int64)
        + bias1_q.astype(np.int64)
    )
    accumulator1 = np.maximum(accumulator1, 0)
    hidden_q = round_shift_nearest_even(accumulator1, multiplier1, shift1)
    hidden_q = np.clip(hidden_q, -128, 127).astype(np.int8)

    weight2_q = quantize_int8(weight2, weight2_scale)
    bias2_q = quantize_bias(bias2, hidden_scale * weight2_scale)
    logits64 = (
        hidden_q.astype(np.int64) @ weight2_q.astype(np.int64)
        + bias2_q.astype(np.int64)
    )
    if np.any(logits64 < np.iinfo(np.int32).min) or np.any(
        logits64 > np.iinfo(np.int32).max
    ):
        raise RuntimeError("layer 2 output does not fit INT32")
    logits_q = logits64.astype(np.int32)
    integer_class = np.argmax(logits_q, axis=1).astype(np.uint8)

    fixture_float_accuracy = float(np.mean(keras_class == fixture_y))
    fixture_integer_accuracy = float(np.mean(integer_class == fixture_y))
    class_agreement = float(np.mean(integer_class == keras_class))
    if test_accuracy < 0.94:
        raise RuntimeError(f"Keras test accuracy is too low: {test_accuracy:.4f}")
    if fixture_integer_accuracy < 0.90 or class_agreement < 0.90:
        raise RuntimeError(
            "integer fixture quality is too low: "
            f"accuracy={fixture_integer_accuracy:.4f}, agreement={class_agreement:.4f}"
        )

    header = build_header(
        input_q,
        tile_weight(weight1_q),
        bias1_q,
        multiplier1,
        shift1,
        hidden_q,
        tile_weight(weight2_q),
        bias2_q,
        logits_q,
        fixture_y.astype(np.uint8),
        keras_class,
        integer_class,
    )
    args.output.parent.mkdir(parents=True, exist_ok=True)
    previous = args.output.read_text(encoding="utf-8") if args.output.exists() else None
    if previous != header:
        args.output.write_text(header, encoding="utf-8")
    if args.model_output is not None:
        args.model_output.parent.mkdir(parents=True, exist_ok=True)
        model.save(args.model_output)

    digest = hashlib.sha256(header.encode("utf-8")).hexdigest()
    print(f"TensorFlow={tf.__version__} Keras={keras.__version__}")
    print(f"test_loss={test_loss:.6f} test_accuracy={test_accuracy:.6f}")
    print(
        "fixture_float_accuracy="
        f"{fixture_float_accuracy:.6f} fixture_integer_accuracy="
        f"{fixture_integer_accuracy:.6f} class_agreement={class_agreement:.6f}"
    )
    print(
        f"input_scale={input_scale:.10g} weight1_scale={weight1_scale:.10g} "
        f"hidden_scale={hidden_scale:.10g} weight2_scale={weight2_scale:.10g}"
    )
    print(f"layer1_multiplier={multiplier1} layer1_shift={shift1}")
    print(f"fixture={args.output} sha256={digest}")


if __name__ == "__main__":
    main()
