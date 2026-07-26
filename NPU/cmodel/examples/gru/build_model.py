#!/usr/bin/env python3
"""Train and export the GRU telemetry regression model."""

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
    parser.add_argument("--graph", required=True, type=Path)
    parser.add_argument("--fixture", required=True, type=Path)
    parser.add_argument("--report", required=True, type=Path)
    return parser.parse_args(argv)


def build_model() -> keras.Model:
    source = keras.Input(
        shape=(support.STEPS, support.FEATURES),
        dtype="float32",
        name="telemetry_sequence",
    )
    output = keras.layers.GRU(
        support.UNITS,
        return_sequences=True,
        activation="tanh",
        recurrent_activation="sigmoid",
        reset_after=True,
        use_bias=True,
        kernel_initializer=keras.initializers.GlorotUniform(
            seed=support.SEED + 1
        ),
        recurrent_initializer=keras.initializers.Orthogonal(
            seed=support.SEED + 2
        ),
        bias_initializer="zeros",
        name="telemetry_gru",
    )(source)
    return keras.Model(source, output, name="gru_telemetry_forecast")


def train_model() -> tuple[
    keras.Model,
    dict[str, float | int],
    np.ndarray,
    np.ndarray,
    np.ndarray,
]:
    rng = np.random.default_rng(support.SEED)
    train_x, train_y = support.recurrent_corpus(
        support.RECURRENT_TRAIN_SAMPLES, rng
    )
    test_x, test_y = support.recurrent_corpus(
        support.RECURRENT_TEST_SAMPLES, rng
    )
    fixed_x = support.fixed_recurrent_inputs()
    fixed_y = support.recurrent_targets(fixed_x)
    model = build_model()
    model.compile(
        optimizer=keras.optimizers.Adam(learning_rate=0.018),
        loss="mse",
    )
    initial_mse = float(model.evaluate(train_x, train_y, verbose=0))
    model.fit(
        train_x,
        train_y,
        batch_size=16,
        epochs=support.RECURRENT_EPOCHS,
        shuffle=False,
        verbose=0,
    )
    final_mse = float(model.evaluate(train_x, train_y, verbose=0))
    test_mse = float(model.evaluate(test_x, test_y, verbose=0))
    reference = np.asarray(
        model(fixed_x, training=False).numpy(), dtype=np.float32
    )
    fixed_mse = float(
        np.mean(
            (
                reference.astype(np.float64)
                - fixed_y.astype(np.float64)
            )
            ** 2
        )
    )
    metrics: dict[str, float | int] = {
        "training_samples": support.RECURRENT_TRAIN_SAMPLES,
        "test_samples": support.RECURRENT_TEST_SAMPLES,
        "epochs": support.RECURRENT_EPOCHS,
        "initial_mse": initial_mse,
        "final_mse": final_mse,
        "test_mse": test_mse,
        "fixed_mse": fixed_mse,
    }
    return model, metrics, fixed_x, fixed_y, reference


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    support.configure_determinism()
    model, metrics, inputs, targets, reference = train_model()
    support.save_model(model, args.model)
    support.atomic_write(
        args.graph,
        (
            json.dumps(
                support.recurrent_graph("gru", model),
                indent=2,
                sort_keys=True,
                allow_nan=False,
            )
            + "\n"
        ).encode("utf-8"),
    )
    support.atomic_write(
        args.fixture,
        support.fixture_header(
            "gru", inputs, targets, reference, metrics
        ),
    )
    report = {
        "format_version": 1,
        "kind": "gru",
        "purpose": "time_dependent_device_telemetry_regression",
        "seed": support.SEED,
        "tensorflow_version": tf.__version__,
        "keras_version": keras.__version__,
        "model": args.model.name,
        "compiler_input": args.graph.name,
        "tensor_dtype": "int8",
        "accumulator_dtype": "int32",
        "fraction_bits": support.FRACTION_BITS,
        "scale": float(support.SCALE),
        "metrics": metrics,
        "input_shape": list(inputs.shape),
        "output_shape": list(reference.shape),
        "software_assist": (
            "fp32_gate_products_and_state_update_then_int8_reencode"
        ),
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
        f"kind=gru tensorflow={tf.__version__} keras={keras.__version__} "
        f"model={args.model} input_shape={tuple(inputs.shape)} "
        f"output_shape={tuple(reference.shape)} metrics={metrics}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
