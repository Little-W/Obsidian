#!/usr/bin/env python3
"""Train and export the CNN visual-scratch classifier."""

from __future__ import annotations

import argparse
import json
import os
import sys
from pathlib import Path
from typing import Sequence

os.environ.setdefault("CUDA_VISIBLE_DEVICES", "-1")
os.environ.setdefault("TF_ENABLE_ONEDNN_OPTS", "0")
os.environ.setdefault("TF_CPP_MIN_LOG_LEVEL", "3")

import keras
import numpy as np
import tensorflow as tf

SUPPORT_DIR = Path(__file__).resolve().parents[1] / "common"
sys.path.insert(0, str(SUPPORT_DIR))
import build_keras_example as support  # noqa: E402


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--model", required=True, type=Path)
    parser.add_argument("--fixture", required=True, type=Path)
    parser.add_argument("--report", required=True, type=Path)
    return parser.parse_args(argv)


def build_model() -> keras.Model:
    source = keras.Input(
        shape=(
            support.CNN_HEIGHT,
            support.CNN_WIDTH,
            support.CNN_CHANNELS,
        ),
        dtype="float32",
        name="inspection_image",
    )
    features = keras.layers.Conv2D(
        4,
        kernel_size=(3, 3),
        padding="valid",
        activation="relu",
        use_bias=True,
        kernel_constraint=keras.constraints.MaxNorm(max_value=1.5),
        bias_constraint=keras.constraints.MaxNorm(max_value=1.5),
        name="scratch_features",
    )(source)
    flattened = keras.layers.Flatten(name="flatten_features")(features)
    output = keras.layers.Dense(
        support.CNN_CLASSES,
        activation="tanh",
        kernel_constraint=keras.constraints.MaxNorm(max_value=2.5),
        bias_constraint=keras.constraints.MaxNorm(max_value=1.5),
        name="defect_scores",
    )(flattened)
    return keras.Model(
        source, output, name="visual_scratch_classifier"
    )


def train_model() -> tuple[
    keras.Model,
    dict[str, float | int],
    np.ndarray,
    np.ndarray,
    np.ndarray,
]:
    rng = np.random.default_rng(support.SEED)
    train_x, train_y = support.cnn_corpus(
        support.CNN_TRAIN_SAMPLES, rng, noise=0.12
    )
    test_x, test_y = support.cnn_corpus(
        support.CNN_TEST_SAMPLES, rng, noise=0.12
    )
    fixed_x, fixed_y = support.fixed_cnn_inputs()
    model = build_model()
    model.compile(
        optimizer=keras.optimizers.Adam(learning_rate=0.012),
        loss=keras.losses.SparseCategoricalCrossentropy(
            from_logits=True
        ),
        metrics=["accuracy"],
    )
    initial_loss, initial_accuracy = model.evaluate(
        train_x, train_y, verbose=0
    )
    model.fit(
        train_x,
        train_y,
        batch_size=48,
        epochs=support.CNN_EPOCHS,
        shuffle=False,
        verbose=0,
    )
    final_loss, final_accuracy = model.evaluate(
        train_x, train_y, verbose=0
    )
    test_loss, test_accuracy = model.evaluate(
        test_x, test_y, verbose=0
    )
    reference = np.asarray(
        model(fixed_x, training=False).numpy(), dtype=np.float32
    )
    fixed_prediction = np.argmax(reference, axis=1)
    fixed_accuracy = float(np.mean(fixed_prediction == fixed_y))
    metrics: dict[str, float | int] = {
        "training_samples": support.CNN_TRAIN_SAMPLES,
        "test_samples": support.CNN_TEST_SAMPLES,
        "epochs": support.CNN_EPOCHS,
        "initial_loss": float(initial_loss),
        "initial_accuracy": float(initial_accuracy),
        "final_loss": float(final_loss),
        "final_accuracy": float(final_accuracy),
        "test_loss": float(test_loss),
        "test_accuracy": float(test_accuracy),
        "fixed_accuracy": fixed_accuracy,
    }
    return model, metrics, fixed_x, fixed_y, reference


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    support.configure_determinism()
    model, metrics, inputs, labels, reference = train_model()
    support.save_model(model, args.model)
    support.atomic_write(
        args.fixture,
        support.fixture_header(
            "cnn",
            inputs,
            np.zeros_like(reference, dtype=np.float32),
            reference,
            metrics,
            labels,
        ),
    )
    report = {
        "format_version": 1,
        "kind": "cnn",
        "purpose": "visual_scratch_classification",
        "seed": support.SEED,
        "tensorflow_version": tf.__version__,
        "keras_version": keras.__version__,
        "model": args.model.name,
        "compiler_input": args.model.name,
        "tensor_dtype": "int8",
        "accumulator_dtype": "int32",
        "fraction_bits": support.FRACTION_BITS,
        "scale": float(support.SCALE),
        "metrics": metrics,
        "input_shape": list(inputs.shape),
        "output_shape": list(reference.shape),
        "software_assist": "none",
    }
    support.atomic_write(
        args.report,
        (
            json.dumps(
                report, indent=2, sort_keys=True, allow_nan=False
            )
            + "\n"
        ).encode("utf-8"),
    )
    print(
        f"kind=cnn tensorflow={tf.__version__} keras={keras.__version__} "
        f"model={args.model} input_shape={tuple(inputs.shape)} "
        f"output_shape={tuple(reference.shape)} metrics={metrics}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
