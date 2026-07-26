#!/usr/bin/env python3
"""Create a deterministic Keras Transformer and fixed-point test vectors."""

from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path
from typing import Sequence

import keras
import numpy as np
import tensorflow as tf


TOKENS = 4
WIDTH = 8
HEADS = 2
HEAD_WIDTH = WIDTH // HEADS
FFN_WIDTH = 16
FRACTION_BITS = 8
SCALE = 2.0**-FRACTION_BITS
SEED = 20260726


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--model", type=Path, required=True)
    parser.add_argument("--test-header", type=Path, required=True)
    parser.add_argument("--report", type=Path, required=True)
    return parser.parse_args(argv)


def atomic_write(path: Path, content: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(f".{path.name}.tmp-{os.getpid()}")
    try:
        temporary.write_bytes(content)
        os.replace(temporary, path)
    finally:
        if temporary.exists():
            temporary.unlink()


def transformer_model() -> keras.Model:
    source = keras.Input(
        batch_shape=(1, TOKENS, WIDTH),
        dtype="float32",
        name="token_features",
    )
    attention_layer = keras.layers.MultiHeadAttention(
        num_heads=HEADS,
        key_dim=HEAD_WIDTH,
        value_dim=HEAD_WIDTH,
        dropout=0.0,
        use_bias=False,
        name="self_attention",
    )
    attention = attention_layer(source, source)
    residual1 = keras.layers.Add(name="attention_residual")(
        [source, attention]
    )
    normalized1 = keras.layers.LayerNormalization(
        axis=-1,
        epsilon=1.0e-3,
        center=True,
        scale=True,
        name="norm1",
    )(residual1)
    expanded = keras.layers.Dense(
        FFN_WIDTH,
        activation="gelu",
        use_bias=True,
        name="ffn_expand",
    )(normalized1)
    contracted = keras.layers.Dense(
        WIDTH,
        use_bias=True,
        name="ffn_contract",
    )(expanded)
    residual2 = keras.layers.Add(name="ffn_residual")(
        [normalized1, contracted]
    )
    output = keras.layers.LayerNormalization(
        axis=-1,
        epsilon=1.0e-3,
        center=True,
        scale=True,
        name="norm2",
    )(residual2)
    model = keras.Model(source, output, name="keras_transformer_encoder")

    identity = np.eye(WIDTH, dtype=np.float32)
    query = identity.reshape(WIDTH, HEADS, HEAD_WIDTH)
    key = identity.reshape(WIDTH, HEADS, HEAD_WIDTH)
    value = identity.reshape(WIDTH, HEADS, HEAD_WIDTH)
    output_kernel = identity.reshape(HEADS, HEAD_WIDTH, WIDTH)
    attention_layer.set_weights([query, key, value, output_kernel])

    norm1 = model.get_layer("norm1")
    norm2 = model.get_layer("norm2")
    norm1.set_weights(
        [
            np.ones((WIDTH,), dtype=np.float32),
            np.zeros((WIDTH,), dtype=np.float32),
        ]
    )
    norm2.set_weights(
        [
            np.ones((WIDTH,), dtype=np.float32),
            np.zeros((WIDTH,), dtype=np.float32),
        ]
    )

    expand_kernel = np.zeros((WIDTH, FFN_WIDTH), dtype=np.float32)
    for feature in range(WIDTH):
        expand_kernel[feature, feature] = np.float32(0.75)
        expand_kernel[feature, feature + WIDTH] = np.float32(-0.5)
    expand_bias = np.asarray(
        [
            0.0625,
            -0.03125,
            0.046875,
            0.0,
            -0.0625,
            0.03125,
            -0.046875,
            0.015625,
        ]
        * 2,
        dtype=np.float32,
    )
    contract_kernel = np.zeros((FFN_WIDTH, WIDTH), dtype=np.float32)
    for feature in range(WIDTH):
        contract_kernel[feature, feature] = np.float32(0.625)
        contract_kernel[feature + WIDTH, feature] = np.float32(0.375)
    contract_bias = np.asarray(
        [
            -0.03125,
            0.015625,
            0.0,
            0.03125,
            -0.015625,
            0.046875,
            -0.046875,
            0.0625,
        ],
        dtype=np.float32,
    )
    model.get_layer("ffn_expand").set_weights(
        [expand_kernel, expand_bias]
    )
    model.get_layer("ffn_contract").set_weights(
        [contract_kernel, contract_bias]
    )
    return model


def test_input() -> np.ndarray:
    return np.asarray(
        [
            [
                [0.75, -0.25, 0.0, 0.5, -0.5, 0.25, 0.0, 0.125],
                [-0.25, 0.625, 0.25, 0.0, 0.375, -0.5, 0.125, 0.0],
                [0.0, 0.25, -0.625, 0.5, 0.125, 0.0, 0.75, -0.25],
                [0.5, 0.0, 0.25, -0.375, 0.0, 0.625, -0.25, 0.125],
            ]
        ],
        dtype=np.float32,
    )


def fixed(values: np.ndarray) -> np.ndarray:
    return np.clip(
        np.rint(np.asarray(values, dtype=np.float64) / SCALE),
        -32768,
        32767,
    ).astype(np.int16)


def c_i16_array(name: str, values: np.ndarray) -> str:
    flat = np.asarray(values, dtype=np.int16).reshape(-1)
    rows = []
    for start in range(0, flat.size, 8):
        rows.append(
            "    "
            + ", ".join(str(int(value)) for value in flat[start : start + 8])
            + ","
        )
    return (
        f"static const int16_t {name}[{flat.size}] = {{\n"
        + "\n".join(rows)
        + "\n};\n"
    )


def test_header(
    input_q: np.ndarray,
    expected_q: np.ndarray,
) -> bytes:
    content = (
        "#ifndef KERAS_TRANSFORMER_TEST_DATA_H\n"
        "#define KERAS_TRANSFORMER_TEST_DATA_H\n\n"
        "#include <stdint.h>\n\n"
        f"#define KT_TEST_TOKENS {TOKENS}u\n"
        f"#define KT_TEST_WIDTH {WIDTH}u\n"
        f"#define KT_TEST_FRACTION_BITS {FRACTION_BITS}u\n"
        "#define KT_TEST_ALLOWED_ABS_ERROR 2u\n\n"
        + c_i16_array("kt_test_input", input_q)
        + "\n"
        + c_i16_array("kt_test_expected", expected_q)
        + "\n#endif\n"
    )
    return content.encode("ascii")


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    keras.utils.set_random_seed(SEED)
    tf.config.experimental.enable_op_determinism()
    model = transformer_model()
    source = test_input()
    expected = np.asarray(model(source, training=False).numpy())
    input_q = fixed(source)
    expected_q = fixed(expected)

    args.model.parent.mkdir(parents=True, exist_ok=True)
    temporary_model = args.model.with_name(
        f".{args.model.stem}.tmp-{os.getpid()}.keras"
    )
    try:
        model.save(temporary_model, overwrite=True)
        os.replace(temporary_model, args.model)
    finally:
        if temporary_model.exists():
            temporary_model.unlink()
    atomic_write(args.test_header, test_header(input_q, expected_q))
    report = {
        "format_version": 1,
        "tensorflow_version": tf.__version__,
        "keras_version": keras.__version__,
        "torch_version": None,
        "model": args.model.name,
        "model_sha256": hashlib.sha256(args.model.read_bytes()).hexdigest(),
        "shape": [1, TOKENS, WIDTH],
        "fraction_bits": FRACTION_BITS,
        "scale": SCALE,
        "input_float": source.tolist(),
        "input_int16": input_q.tolist(),
        "keras_output_float": expected.tolist(),
        "keras_output_int16": expected_q.tolist(),
    }
    try:
        import torch

        report["torch_version"] = torch.__version__
        report["torch_cuda_version"] = torch.version.cuda
        report["torch_cuda_available"] = bool(torch.cuda.is_available())
    except ImportError:
        report["torch_cuda_version"] = None
        report["torch_cuda_available"] = False
    atomic_write(
        args.report,
        (json.dumps(report, indent=2, sort_keys=True) + "\n").encode("utf-8"),
    )
    print(
        f"model={args.model} keras={keras.__version__} "
        f"tensorflow={tf.__version__} input_shape={tuple(source.shape)} "
        f"output_shape={tuple(expected.shape)}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
