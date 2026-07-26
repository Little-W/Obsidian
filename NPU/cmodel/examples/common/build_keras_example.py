#!/usr/bin/env python3
"""Train one deterministic Keras example and emit NPU test inputs.

RNN, GRU, and LSTM examples emit an unrolled cell graph whose matrix,
addition, and activation work is compiled for the NPU.  GRU and LSTM keep
their state products in the host runner because the current device vector
multiply command produces INT32 while the following cell input is INT8.

The CNN example is compiled directly from its saved Keras model.
"""

from __future__ import annotations

import argparse
import json
import math
import os
import struct
from pathlib import Path
from typing import Any, Iterable, Sequence

os.environ.setdefault("CUDA_VISIBLE_DEVICES", "-1")
os.environ.setdefault("TF_ENABLE_ONEDNN_OPTS", "0")
os.environ.setdefault("TF_CPP_MIN_LOG_LEVEL", "3")

import keras
import numpy as np
import tensorflow as tf


SEED = 20260726
FRACTION_BITS = 5
SCALE = np.float32(2.0**-FRACTION_BITS)
STEPS = 4
FEATURES = 3
UNITS = 3
RECURRENT_TRAIN_SAMPLES = 128
RECURRENT_TEST_SAMPLES = 48
RECURRENT_FIXED_SAMPLES = 3
RECURRENT_EPOCHS = 120
CNN_HEIGHT = 6
CNN_WIDTH = 6
CNN_CHANNELS = 1
CNN_CLASSES = 3
CNN_TRAIN_SAMPLES = 720
CNN_TEST_SAMPLES = 180
CNN_FIXED_SAMPLES = 6
CNN_EPOCHS = 45

KIND_CODES = {
    "rnn": 1,
    "gru": 2,
    "lstm": 3,
    "cnn": 4,
}

KIND_MSE_LIMITS = {
    "rnn": np.float32(0.09),
    "gru": np.float32(0.10),
    "lstm": np.float32(0.14),
}


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--kind", required=True, choices=tuple(KIND_CODES)
    )
    parser.add_argument("--model", required=True, type=Path)
    parser.add_argument("--graph", type=Path)
    parser.add_argument("--fixture", required=True, type=Path)
    parser.add_argument("--report", required=True, type=Path)
    return parser.parse_args(argv)


def configure_determinism() -> None:
    keras.utils.set_random_seed(SEED)
    tf.config.experimental.enable_op_determinism()
    tf.config.threading.set_inter_op_parallelism_threads(1)
    tf.config.threading.set_intra_op_parallelism_threads(1)


def atomic_write(path: Path, content: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(f".{path.name}.tmp-{os.getpid()}")
    try:
        temporary.write_bytes(content)
        os.replace(temporary, path)
    finally:
        if temporary.exists():
            temporary.unlink()


def save_model(model: keras.Model, path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(
        f".{path.stem}.tmp-{os.getpid()}.keras"
    )
    try:
        model.save(temporary, overwrite=True)
        os.replace(temporary, path)
    finally:
        if temporary.exists():
            temporary.unlink()


def float_bits(value: float) -> int:
    return struct.unpack("<I", struct.pack("<f", float(value)))[0]


def float_array_bits(values: np.ndarray) -> np.ndarray:
    return np.ascontiguousarray(
        np.asarray(values, dtype=np.float32)
    ).view(np.uint32)


def encode_int8(values: np.ndarray) -> np.ndarray:
    encoded = np.rint(
        np.asarray(values, dtype=np.float64) / float(SCALE)
    )
    if np.any(encoded < -128) or np.any(encoded > 127):
        minimum = float(np.min(values))
        maximum = float(np.max(values))
        raise RuntimeError(
            f"INT8 fixed-point range exceeded by [{minimum}, {maximum}]"
        )
    return encoded.astype(np.int8)


def c_array(
    name: str,
    c_type: str,
    values: Iterable[int],
    columns: int,
) -> str:
    flat = [int(value) for value in values]
    rows = [f"static const {c_type} {name}[{len(flat)}] = {{"]
    for start in range(0, len(flat), columns):
        group = ", ".join(
            str(value) for value in flat[start : start + columns]
        )
        rows.append(f"    {group},")
    rows.append("};")
    return "\n".join(rows)


def recurrent_targets(values: np.ndarray) -> np.ndarray:
    result = np.zeros_like(values, dtype=np.float32)
    for sample in range(values.shape[0]):
        state = np.zeros((UNITS,), dtype=np.float32)
        for step in range(STEPS):
            temperature, load, phase = values[sample, step]
            state = np.asarray(
                [
                    0.58 * state[0]
                    + 0.28 * temperature
                    + 0.12 * load
                    - 0.08 * phase,
                    0.46 * state[1]
                    - 0.10 * temperature
                    + 0.40 * load
                    + 0.07 * phase,
                    0.34 * state[2]
                    + 0.22 * (temperature - load)
                    + 0.24 * phase,
                ],
                dtype=np.float32,
            )
            result[sample, step] = state
    return result


def recurrent_corpus(
    count: int, rng: np.random.Generator
) -> tuple[np.ndarray, np.ndarray]:
    values = rng.uniform(
        -0.85, 0.85, size=(count, STEPS, FEATURES)
    ).astype(np.float32)
    return values, recurrent_targets(values)


def fixed_recurrent_inputs() -> np.ndarray:
    return np.asarray(
        [
            [
                [-0.70, 0.20, -0.50],
                [-0.35, 0.55, -0.10],
                [0.10, 0.35, 0.30],
                [0.45, 0.10, 0.65],
            ],
            [
                [0.65, -0.55, 0.45],
                [0.30, -0.25, 0.10],
                [-0.15, 0.20, -0.35],
                [0.45, 0.10, 0.65],
            ],
            [
                [-0.20, -0.65, 0.70],
                [0.15, -0.30, 0.40],
                [0.55, 0.15, -0.20],
                [-0.40, 0.60, 0.05],
            ],
        ],
        dtype=np.float32,
    )


def recurrent_model(kind: str) -> keras.Model:
    source = keras.Input(
        shape=(STEPS, FEATURES),
        dtype="float32",
        name="telemetry_sequence",
    )
    common: dict[str, Any] = {
        "units": UNITS,
        "return_sequences": True,
        "activation": "tanh",
        "use_bias": True,
        "kernel_initializer": keras.initializers.GlorotUniform(
            seed=SEED + 1
        ),
        "recurrent_initializer": keras.initializers.Orthogonal(
            seed=SEED + 2
        ),
        "bias_initializer": "zeros",
    }
    if kind == "rnn":
        layer = keras.layers.SimpleRNN(name="telemetry_rnn", **common)
    elif kind == "gru":
        layer = keras.layers.GRU(
            name="telemetry_gru",
            reset_after=True,
            recurrent_activation="sigmoid",
            **common,
        )
    elif kind == "lstm":
        layer = keras.layers.LSTM(
            name="telemetry_lstm",
            recurrent_activation="sigmoid",
            unit_forget_bias=False,
            **common,
        )
    else:
        raise ValueError(kind)
    output = layer(source)
    return keras.Model(source, output, name=f"{kind}_telemetry_forecast")


def train_recurrent(
    kind: str, rng: np.random.Generator
) -> tuple[keras.Model, dict[str, Any], np.ndarray, np.ndarray, np.ndarray]:
    train_x, train_y = recurrent_corpus(RECURRENT_TRAIN_SAMPLES, rng)
    test_x, test_y = recurrent_corpus(RECURRENT_TEST_SAMPLES, rng)
    fixed_x = fixed_recurrent_inputs()
    fixed_y = recurrent_targets(fixed_x)
    model = recurrent_model(kind)
    model.compile(
        optimizer=keras.optimizers.Adam(learning_rate=0.018),
        loss="mse",
    )
    initial_loss = float(model.evaluate(train_x, train_y, verbose=0))
    model.fit(
        train_x,
        train_y,
        batch_size=16,
        epochs=RECURRENT_EPOCHS,
        shuffle=False,
        verbose=0,
    )
    final_loss = float(model.evaluate(train_x, train_y, verbose=0))
    test_loss = float(model.evaluate(test_x, test_y, verbose=0))
    fixed_reference = np.asarray(
        model(fixed_x, training=False).numpy(), dtype=np.float32
    )
    fixed_mse = float(
        np.mean(
            (
                fixed_reference.astype(np.float64)
                - fixed_y.astype(np.float64)
            )
            ** 2
        )
    )
    metrics = {
        "training_samples": RECURRENT_TRAIN_SAMPLES,
        "test_samples": RECURRENT_TEST_SAMPLES,
        "epochs": RECURRENT_EPOCHS,
        "initial_mse": initial_loss,
        "final_mse": final_loss,
        "test_mse": test_loss,
        "fixed_mse": fixed_mse,
    }
    return model, metrics, fixed_x, fixed_y, fixed_reference


def add_constant(
    constants: list[dict[str, Any]],
    name: str,
    values: np.ndarray,
) -> str:
    encoded = encode_int8(np.asarray(values, dtype=np.float32))
    constants.append(
        {
            "name": name,
            "shape": list(encoded.shape),
            "dtype": "int8",
            "data": [int(value) for value in encoded.reshape(-1)],
        }
    )
    return name


def add_operator(
    operators: list[dict[str, Any]],
    name: str,
    op_type: str,
    inputs: Sequence[str],
    output: str,
    attributes: dict[str, Any] | None = None,
) -> str:
    operators.append(
        {
            "name": name,
            "type": op_type,
            "inputs": list(inputs),
            "outputs": [output],
            "attributes": {} if attributes is None else attributes,
        }
    )
    return output


def add_projection(
    constants: list[dict[str, Any]],
    operators: list[dict[str, Any]],
    prefix: str,
    source: str,
    kernel: np.ndarray,
    bias: np.ndarray | None = None,
) -> str:
    weight = add_constant(constants, f"{prefix}_weight", kernel)
    current = add_operator(
        operators,
        f"{prefix}_matmul",
        "MatMul",
        [source, weight],
        f"{prefix}_matmul_output",
        {"output_dtype": "int8", "output_shift": FRACTION_BITS},
    )
    if bias is not None:
        bias_name = add_constant(
            constants, f"{prefix}_bias", bias.reshape(-1)
        )
        current = add_operator(
            operators,
            f"{prefix}_bias_add",
            "Add",
            [current, bias_name],
            f"{prefix}_biased",
            {"scale": float(SCALE)},
        )
    return current


def add_gate(
    constants: list[dict[str, Any]],
    operators: list[dict[str, Any]],
    prefix: str,
    x_kernel: np.ndarray,
    h_kernel: np.ndarray,
    x_bias: np.ndarray | None,
    h_bias: np.ndarray | None,
    activation: str | None,
) -> str:
    x_value = add_projection(
        constants,
        operators,
        f"{prefix}_input",
        "x",
        x_kernel,
        x_bias,
    )
    h_value = add_projection(
        constants,
        operators,
        f"{prefix}_recurrent",
        "h_prev",
        h_kernel,
        h_bias,
    )
    summed = add_operator(
        operators,
        f"{prefix}_sum",
        "Add",
        [x_value, h_value],
        f"{prefix}_preactivation",
        {"scale": float(SCALE)},
    )
    if activation is None:
        return summed
    return add_operator(
        operators,
        f"{prefix}_{activation.lower()}",
        activation,
        [summed],
        prefix,
        {
            "axis": -1,
            "input_scale": float(SCALE),
            "output_scale": float(SCALE),
        },
    )


def recurrent_graph(kind: str, model: keras.Model) -> dict[str, Any]:
    layer = model.layers[1]
    constants: list[dict[str, Any]] = []
    operators: list[dict[str, Any]] = []
    outputs: list[str] = []
    weights = [
        np.asarray(value, dtype=np.float32)
        for value in layer.get_weights()
    ]
    if kind == "rnn":
        kernel, recurrent, bias = weights
        outputs.append(
            add_gate(
                constants,
                operators,
                "h",
                kernel,
                recurrent,
                bias,
                None,
                "Tanh",
            )
        )
    elif kind == "gru":
        kernel, recurrent, bias = weights
        input_bias, recurrent_bias = bias
        for index, gate in enumerate(("z", "r")):
            gate_slice = slice(index * UNITS, (index + 1) * UNITS)
            outputs.append(
                add_gate(
                    constants,
                    operators,
                    gate,
                    kernel[:, gate_slice],
                    recurrent[:, gate_slice],
                    input_bias[gate_slice],
                    recurrent_bias[gate_slice],
                    "Sigmoid",
                )
            )
        candidate_slice = slice(2 * UNITS, 3 * UNITS)
        outputs.append(
            add_projection(
                constants,
                operators,
                "x_h",
                "x",
                kernel[:, candidate_slice],
                input_bias[candidate_slice],
            )
        )
        outputs.append(
            add_projection(
                constants,
                operators,
                "recurrent_h",
                "h_prev",
                recurrent[:, candidate_slice],
                recurrent_bias[candidate_slice],
            )
        )
    elif kind == "lstm":
        kernel, recurrent, bias = weights
        for index, (gate, activation) in enumerate(
            (
                ("i", "Sigmoid"),
                ("f", "Sigmoid"),
                ("g", "Tanh"),
                ("o", "Sigmoid"),
            )
        ):
            gate_slice = slice(index * UNITS, (index + 1) * UNITS)
            outputs.append(
                add_gate(
                    constants,
                    operators,
                    gate,
                    kernel[:, gate_slice],
                    recurrent[:, gate_slice],
                    bias[gate_slice],
                    None,
                    activation,
                )
            )
    else:
        raise ValueError(kind)
    return {
        "schema_version": 1,
        "model": {"name": f"{kind}_keras_cell_accelerator"},
        "inputs": [
            {"name": "x", "shape": [1, FEATURES], "dtype": "int8"},
            {
                "name": "h_prev",
                "shape": [1, UNITS],
                "dtype": "int8",
            },
        ],
        "constants": constants,
        "tensors": [],
        "operators": operators,
        "outputs": outputs,
        "software_assist": {
            "kind": (
                "none"
                if kind == "rnn"
                else "fp32_gate_products_and_state_update"
            ),
            "state_is_reencoded_as": "int8_q5",
        },
    }


def draw_pattern(
    class_id: int,
    rng: np.random.Generator,
    *,
    noise: float,
) -> np.ndarray:
    image = rng.uniform(
        0.0, noise, size=(CNN_HEIGHT, CNN_WIDTH)
    ).astype(np.float32)
    intensity = np.float32(rng.uniform(0.72, 1.0))
    if class_id == 0:
        column = int(rng.integers(1, CNN_WIDTH - 1))
        image[:, column] += intensity
    elif class_id == 1:
        row = int(rng.integers(1, CNN_HEIGHT - 1))
        image[row, :] += intensity
    elif class_id == 2:
        anti = bool(rng.integers(0, 2))
        for index in range(CNN_HEIGHT):
            column = CNN_WIDTH - 1 - index if anti else index
            image[index, column] += intensity
    else:
        raise ValueError(class_id)
    return np.clip(image, 0.0, 1.0)[..., np.newaxis]


def cnn_corpus(
    count: int,
    rng: np.random.Generator,
    *,
    noise: float,
) -> tuple[np.ndarray, np.ndarray]:
    images = np.empty(
        (count, CNN_HEIGHT, CNN_WIDTH, CNN_CHANNELS),
        dtype=np.float32,
    )
    labels = np.empty((count,), dtype=np.int32)
    for index in range(count):
        label = index % CNN_CLASSES
        images[index] = draw_pattern(label, rng, noise=noise)
        labels[index] = label
    order = rng.permutation(count)
    return images[order], labels[order]


def fixed_cnn_inputs() -> tuple[np.ndarray, np.ndarray]:
    rng = np.random.default_rng(SEED + 91)
    images = []
    labels = []
    for class_id in range(CNN_CLASSES):
        for _ in range(2):
            images.append(draw_pattern(class_id, rng, noise=0.035))
            labels.append(class_id)
    return (
        np.asarray(images, dtype=np.float32),
        np.asarray(labels, dtype=np.int32),
    )


def cnn_model() -> keras.Model:
    source = keras.Input(
        shape=(CNN_HEIGHT, CNN_WIDTH, CNN_CHANNELS),
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
    logits = keras.layers.Dense(
        CNN_CLASSES,
        activation="tanh",
        kernel_constraint=keras.constraints.MaxNorm(max_value=2.5),
        bias_constraint=keras.constraints.MaxNorm(max_value=1.5),
        name="defect_scores",
    )(flattened)
    return keras.Model(source, logits, name="visual_scratch_classifier")


def train_cnn(
    rng: np.random.Generator,
) -> tuple[
    keras.Model,
    dict[str, Any],
    np.ndarray,
    np.ndarray,
    np.ndarray,
]:
    train_x, train_y = cnn_corpus(
        CNN_TRAIN_SAMPLES, rng, noise=0.12
    )
    test_x, test_y = cnn_corpus(
        CNN_TEST_SAMPLES, rng, noise=0.12
    )
    fixed_x, fixed_y = fixed_cnn_inputs()
    model = cnn_model()
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
        epochs=CNN_EPOCHS,
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
    metrics = {
        "training_samples": CNN_TRAIN_SAMPLES,
        "test_samples": CNN_TEST_SAMPLES,
        "epochs": CNN_EPOCHS,
        "initial_loss": float(initial_loss),
        "initial_accuracy": float(initial_accuracy),
        "final_loss": float(final_loss),
        "final_accuracy": float(final_accuracy),
        "test_loss": float(test_loss),
        "test_accuracy": float(test_accuracy),
        "fixed_accuracy": fixed_accuracy,
    }
    return model, metrics, fixed_x, fixed_y, reference


def fixture_header(
    kind: str,
    inputs: np.ndarray,
    targets: np.ndarray,
    reference: np.ndarray,
    metrics: dict[str, Any],
    labels: np.ndarray | None = None,
) -> bytes:
    if kind == "cnn":
        sample_count = CNN_FIXED_SAMPLES
        steps = 1
        input_features = CNN_HEIGHT * CNN_WIDTH * CNN_CHANNELS
        output_features = CNN_CLASSES
        height = CNN_HEIGHT
        width = CNN_WIDTH
        channels = CNN_CHANNELS
        target_values = np.zeros(
            (sample_count, output_features), dtype=np.float32
        )
        classification_min_correct = sample_count
        c_mse_limit = np.float32(0.0)
    else:
        sample_count = RECURRENT_FIXED_SAMPLES
        steps = STEPS
        input_features = FEATURES
        output_features = UNITS
        height = width = channels = 0
        target_values = targets
        classification_min_correct = 0
        c_mse_limit = KIND_MSE_LIMITS[kind]
    input_q = encode_int8(inputs)
    label_values = (
        np.asarray(labels, dtype=np.uint8)
        if labels is not None
        else np.zeros((sample_count,), dtype=np.uint8)
    )
    sections = [
        "#ifndef NPU_KERAS_EXAMPLE_FIXTURE_H",
        "#define NPU_KERAS_EXAMPLE_FIXTURE_H",
        "",
        "#include <stdint.h>",
        "",
        "#define EXAMPLE_KIND_RNN 1u",
        "#define EXAMPLE_KIND_GRU 2u",
        "#define EXAMPLE_KIND_LSTM 3u",
        "#define EXAMPLE_KIND_CNN 4u",
        f"#define EXAMPLE_MODEL_KIND {KIND_CODES[kind]}u",
        f'#define EXAMPLE_MODEL_NAME "{kind}"',
        f"#define EXAMPLE_SAMPLE_COUNT {sample_count}u",
        f"#define EXAMPLE_STEPS {steps}u",
        f"#define EXAMPLE_INPUT_FEATURES {input_features}u",
        f"#define EXAMPLE_OUTPUT_FEATURES {output_features}u",
        f"#define EXAMPLE_IMAGE_HEIGHT {height}u",
        f"#define EXAMPLE_IMAGE_WIDTH {width}u",
        f"#define EXAMPLE_IMAGE_CHANNELS {channels}u",
        f"#define EXAMPLE_FRACTION_BITS {FRACTION_BITS}u",
        (
            "#define EXAMPLE_SCALE_F32_BITS "
            f"UINT32_C({float_bits(float(SCALE))})"
        ),
        (
            "#define EXAMPLE_TRAIN_INITIAL_F32_BITS "
            f"UINT32_C({float_bits(float(metrics.get('initial_mse', metrics.get('initial_loss', 0.0))))})"
        ),
        (
            "#define EXAMPLE_TRAIN_FINAL_F32_BITS "
            f"UINT32_C({float_bits(float(metrics.get('final_mse', metrics.get('final_loss', 0.0))))})"
        ),
        (
            "#define EXAMPLE_FRAMEWORK_METRIC_F32_BITS "
            f"UINT32_C({float_bits(float(metrics.get('fixed_mse', metrics.get('fixed_accuracy', 0.0))))})"
        ),
        (
            "#define EXAMPLE_C_MSE_LIMIT_F32_BITS "
            f"UINT32_C({float_bits(float(c_mse_limit))})"
        ),
        (
            "#define EXAMPLE_CLASSIFICATION_MIN_CORRECT "
            f"{classification_min_correct}u"
        ),
        "",
        c_array(
            "example_input_int8",
            "int8_t",
            input_q.reshape(-1),
            18,
        ),
        "",
        c_array(
            "example_input_f32_bits",
            "uint32_t",
            float_array_bits(inputs).reshape(-1),
            8,
        ),
        "",
        c_array(
            "example_target_f32_bits",
            "uint32_t",
            float_array_bits(target_values).reshape(-1),
            8,
        ),
        "",
        c_array(
            "example_keras_output_f32_bits",
            "uint32_t",
            float_array_bits(reference).reshape(-1),
            8,
        ),
        "",
        c_array(
            "example_label",
            "uint8_t",
            label_values.reshape(-1),
            12,
        ),
        "",
        "#endif",
        "",
    ]
    return "\n".join(sections).encode("ascii")


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    configure_determinism()
    rng = np.random.default_rng(SEED)
    if args.kind == "cnn":
        model, metrics, inputs, labels, reference = train_cnn(rng)
        targets = np.zeros_like(reference, dtype=np.float32)
        graph = None
    else:
        model, metrics, inputs, targets, reference = train_recurrent(
            args.kind, rng
        )
        labels = None
        graph = recurrent_graph(args.kind, model)

    save_model(model, args.model)
    if graph is not None:
        if args.graph is None:
            raise RuntimeError("--graph is required for recurrent models")
        atomic_write(
            args.graph,
            (
                json.dumps(
                    graph,
                    indent=2,
                    sort_keys=True,
                    allow_nan=False,
                )
                + "\n"
            ).encode("utf-8"),
        )
    atomic_write(
        args.fixture,
        fixture_header(
            args.kind,
            inputs,
            targets,
            reference,
            metrics,
            labels,
        ),
    )
    report = {
        "format_version": 1,
        "kind": args.kind,
        "purpose": (
            "visual_scratch_classification"
            if args.kind == "cnn"
            else "time_dependent_device_telemetry_regression"
        ),
        "seed": SEED,
        "tensorflow_version": tf.__version__,
        "keras_version": keras.__version__,
        "model": args.model.name,
        "compiler_input": (
            args.model.name
            if args.kind == "cnn"
            else str(args.graph.name)
        ),
        "tensor_dtype": "int8",
        "accumulator_dtype": "int32",
        "fraction_bits": FRACTION_BITS,
        "scale": float(SCALE),
        "metrics": metrics,
        "input_shape": list(inputs.shape),
        "output_shape": list(reference.shape),
        "software_assist": (
            "none"
            if args.kind in ("rnn", "cnn")
            else "fp32_gate_products_and_state_update_then_int8_reencode"
        ),
    }
    atomic_write(
        args.report,
        (
            json.dumps(
                report,
                indent=2,
                sort_keys=True,
                allow_nan=False,
            )
            + "\n"
        ).encode("utf-8"),
    )
    print(
        f"kind={args.kind} tensorflow={tf.__version__} "
        f"keras={keras.__version__} model={args.model} "
        f"input_shape={tuple(inputs.shape)} "
        f"output_shape={tuple(reference.shape)} metrics={metrics}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
