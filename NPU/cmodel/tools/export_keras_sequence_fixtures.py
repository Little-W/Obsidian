#!/usr/bin/env python3
"""Export deterministic Transformer and recurrent-network C test vectors."""

from __future__ import annotations

import argparse
import hashlib
import os
from collections import OrderedDict
from dataclasses import dataclass
from pathlib import Path
from typing import Callable, Iterable, Sequence

os.environ.setdefault("CUDA_VISIBLE_DEVICES", "-1")
os.environ.setdefault("TF_ENABLE_ONEDNN_OPTS", "0")
os.environ.setdefault("TF_CPP_MIN_LOG_LEVEL", "3")

import keras
import numpy as np
import tensorflow as tf


SEED = 20260726
TRANSFORMER_BATCH = 2
TRANSFORMER_SEQUENCE = 4
TRANSFORMER_VOCAB = 8
TRANSFORMER_WIDTH = 4
TRANSFORMER_FFN = 6
TRANSFORMER_CLASSES = 3
RECURRENT_BATCH = 2
RECURRENT_STEPS = 4
RECURRENT_FEATURES = 3
RECURRENT_UNITS = 3
RECURRENT_TRAINING_SAMPLES = 32
TRAINING_STEPS = 240
TRANSFORMER_LEARNING_RATE = np.float32(0.08)
RECURRENT_LEARNING_RATE = np.float32(0.06)

TRANSFORMER_TOKEN_NAMES = (
    "pad",
    "good",
    "great",
    "bad",
    "awful",
    "what",
    "status",
    "now",
)
TRANSFORMER_CLASS_NAMES = (
    "positive_review",
    "negative_review",
    "information_request",
)

TFLITE_NOT_RUN = 0
TFLITE_STRICT_INT8 = 1
TFLITE_FALLBACK = 2
TFLITE_UNSUPPORTED = 3
TFLITE_MAX_ABS_ERROR_LIMITS = {
    "transformer": np.float32(1.5e-2),
    "simple_rnn": np.float32(6.1e-3),
    "gru": np.float32(4.5e-3),
    "lstm": np.float32(3.4e-3),
}


@dataclass(frozen=True)
class QuantizedTensor:
    values: np.ndarray
    scale: np.float32


@dataclass(frozen=True)
class Requant:
    multiplier: int
    shift: int


@dataclass(frozen=True)
class TFLiteReport:
    status: int
    quantized_tensors: int
    float_tensors: int
    max_abs_error: np.float32
    max_abs_error_limit: np.float32
    note: str


@dataclass(frozen=True)
class TrainingReport:
    steps: int
    initial_loss: np.float32
    final_loss: np.float32


@dataclass
class TransformerFixture:
    model: keras.Model
    representative: Callable[[], Iterable[list[np.ndarray]]]
    token_ids: np.ndarray
    position_ids: np.ndarray
    weights: OrderedDict[str, np.ndarray]
    biases: OrderedDict[str, np.ndarray]
    refs: OrderedDict[str, np.ndarray]
    dense_inputs: OrderedDict[str, str]
    training: TrainingReport
    fixed_labels: np.ndarray
    fixed_predictions: np.ndarray
    training_accuracy: np.float32
    fixed_accuracy: np.float32


@dataclass
class RecurrentFixture:
    name: str
    model: keras.Model
    representative: Callable[[], Iterable[list[np.ndarray]]]
    inputs: np.ndarray
    weights: OrderedDict[str, np.ndarray]
    refs: OrderedDict[str, np.ndarray]
    training: TrainingReport
    targets: np.ndarray
    application_mse: np.float32
    final_step_mse: np.float32
    history_baseline_mse: np.float32
    same_current_baseline_mse: np.float32


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Generate fixed Keras Transformer, SimpleRNN, GRU, and LSTM "
            "vectors for the C model."
        )
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=Path("tests/generated/keras_sequence_fixtures.h"),
    )
    parser.add_argument(
        "--check",
        action="store_true",
        help="verify that the output already matches without writing it",
    )
    parser.add_argument(
        "--skip-tflite",
        action="store_true",
        help="skip TFLite capability probes",
    )
    return parser.parse_args()


def configure_determinism() -> None:
    tf.keras.utils.set_random_seed(SEED)
    tf.config.experimental.enable_op_determinism()
    tf.config.threading.set_inter_op_parallelism_threads(1)
    tf.config.threading.set_intra_op_parallelism_threads(1)


def fixed_values(
    rng: np.random.Generator,
    shape: Sequence[int],
    steps: int = 64,
    denominator: int = 256,
) -> np.ndarray:
    values = rng.integers(
        -steps, steps + 1, size=tuple(shape), dtype=np.int32
    )
    return (values.astype(np.float32) / np.float32(denominator)).astype(
        np.float32
    )


def symmetric_scale(values: np.ndarray) -> np.float32:
    maximum = float(np.max(np.abs(values.astype(np.float32))))
    if maximum == 0.0:
        return np.float32(1.0)
    return np.float32(maximum / 127.0)


def quantize_int8(
    values: np.ndarray, scale: np.float32 | None = None
) -> QuantizedTensor:
    resolved = symmetric_scale(values) if scale is None else np.float32(scale)
    quantized = np.rint(
        values.astype(np.float64) / float(resolved)
    )
    quantized = np.clip(quantized, -127, 127).astype(np.int8)
    return QuantizedTensor(quantized, resolved)


def quantize_int32(values: np.ndarray, scale: np.float32) -> np.ndarray:
    if float(scale) <= 0.0 or not np.isfinite(scale):
        raise RuntimeError("invalid INT32 scale")
    quantized = np.rint(values.astype(np.float64) / float(scale))
    limits = np.iinfo(np.int32)
    if np.any(quantized < limits.min) or np.any(quantized > limits.max):
        raise RuntimeError("INT32 fixture overflow")
    return quantized.astype(np.int32)


def require_int8_range(name: str, values: np.ndarray) -> None:
    limits = np.iinfo(np.int8)
    if np.any(values < limits.min) or np.any(values > limits.max):
        minimum = int(np.min(values))
        maximum = int(np.max(values))
        raise RuntimeError(
            f"{name} needs [{minimum}, {maximum}], outside INT8"
        )


def choose_multiplier_shift(ratio: float) -> Requant:
    if not np.isfinite(ratio) or ratio <= 0.0:
        raise RuntimeError("invalid requant ratio")
    for shift in range(31, -1, -1):
        multiplier = int(round(ratio * float(1 << shift)))
        if 1 <= multiplier <= 0x7FFFFFFF:
            return Requant(multiplier, shift)
    raise RuntimeError("requant ratio cannot be represented")


def round_shift_nearest_even(
    values: np.ndarray, requant: Requant
) -> np.ndarray:
    products = values.astype(np.int64) * np.int64(requant.multiplier)
    if requant.shift == 0:
        return products
    magnitude = np.abs(products)
    quotient = magnitude >> np.int64(requant.shift)
    remainder = magnitude & np.int64((1 << requant.shift) - 1)
    half = np.int64(1 << (requant.shift - 1))
    increment = (remainder > half) | (
        (remainder == half) & ((quotient & 1) != 0)
    )
    rounded = quotient + increment.astype(np.int64)
    return np.where(products < 0, -rounded, rounded)


def float32_bits(values: np.ndarray) -> np.ndarray:
    return np.ascontiguousarray(values.astype(np.float32)).view(np.uint32)


def scalar_float32_bits(value: np.float32) -> int:
    return int(np.asarray([value], dtype=np.float32).view(np.uint32)[0])


def sigmoid(values: np.ndarray) -> np.ndarray:
    values64 = values.astype(np.float64)
    result = 1.0 / (1.0 + np.exp(-values64))
    return result.astype(np.float32)


def assert_close(
    name: str,
    actual: np.ndarray,
    expected: np.ndarray,
    tolerance: float = 4.0e-6,
) -> None:
    difference = float(
        np.max(
            np.abs(
                actual.astype(np.float64)
                - expected.astype(np.float64)
            )
        )
    )
    if difference > tolerance:
        raise RuntimeError(
            f"{name} reference differs from Keras by {difference:.9g}"
        )


def representative_one_input(
    values: np.ndarray,
) -> Callable[[], Iterable[list[np.ndarray]]]:
    def generate() -> Iterable[list[np.ndarray]]:
        for index in range(values.shape[0]):
            yield [values[index : index + 1].astype(np.float32)]

    return generate


def train_fixed_model(
    model: keras.Model,
    inputs: np.ndarray | Sequence[np.ndarray],
    targets: np.ndarray,
    loss: keras.losses.Loss,
    learning_rate: np.float32,
) -> TrainingReport:
    """Train one small deterministic full batch with Keras SGD updates."""

    initial = np.asarray(
        model(inputs, training=False).numpy(), dtype=np.float32
    )
    initial_loss = np.float32(loss(targets, initial).numpy())
    model.compile(
        optimizer=keras.optimizers.SGD(
            learning_rate=float(learning_rate)
        ),
        loss=loss,
        jit_compile=False,
    )
    for _ in range(TRAINING_STEPS):
        model.train_on_batch(inputs, targets)
    final = np.asarray(
        model(inputs, training=False).numpy(), dtype=np.float32
    )
    final_loss = np.float32(loss(targets, final).numpy())
    if not np.isfinite(initial_loss) or not np.isfinite(final_loss):
        raise RuntimeError("training produced a non-finite loss")
    if not final_loss < initial_loss:
        raise RuntimeError(
            "deterministic Keras training did not reduce the loss"
        )
    return TrainingReport(
        steps=TRAINING_STEPS,
        initial_loss=initial_loss,
        final_loss=final_loss,
    )


def transformer_training_corpus() -> tuple[np.ndarray, np.ndarray]:
    """Return a tiny semantic corpus for three-way short-text classification."""

    token_ids = np.asarray(
        [
            [1, 2, 0, 0],  # "good great"
            [2, 1, 0, 0],  # "great good"
            [1, 1, 2, 0],  # "good good great"
            [2, 2, 1, 7],  # "great great good now"
            [3, 4, 0, 0],  # "bad awful"
            [4, 3, 0, 0],  # "awful bad"
            [3, 3, 4, 0],  # "bad bad awful"
            [4, 4, 3, 7],  # "awful awful bad now"
            [5, 6, 0, 0],  # "what status"
            [5, 6, 7, 0],  # "what status now"
            [6, 5, 7, 0],  # "status what now"
            [5, 5, 6, 7],  # "what what status now"
        ],
        dtype=np.int32,
    )
    labels = np.repeat(np.arange(TRANSFORMER_CLASSES), 4).astype(
        np.int32
    )
    return token_ids, labels


def build_transformer() -> TransformerFixture:
    training_token_ids, training_labels = transformer_training_corpus()
    # These exact word orders are absent from the training corpus.  They test
    # whether the trained classifier recognizes a new same-class phrase.
    token_ids = np.asarray(
        [
            [2, 1, 1, 0],  # "great good good"
            [6, 6, 5, 7],  # "status status what now"
        ],
        dtype=np.int32,
    )
    fixed_labels = np.asarray([0, 2], dtype=np.int32)
    position_ids = np.tile(
        np.arange(TRANSFORMER_SEQUENCE, dtype=np.int32),
        (TRANSFORMER_BATCH, 1),
    )
    token_input = keras.Input(
        shape=(TRANSFORMER_SEQUENCE,),
        dtype="int32",
        name="token_ids",
    )
    position_input = keras.Input(
        shape=(TRANSFORMER_SEQUENCE,),
        dtype="int32",
        name="position_ids",
    )
    token_embedding = keras.layers.Embedding(
        TRANSFORMER_VOCAB,
        TRANSFORMER_WIDTH,
        name="token_embedding",
    )
    position_embedding = keras.layers.Embedding(
        TRANSFORMER_SEQUENCE,
        TRANSFORMER_WIDTH,
        name="position_embedding",
    )
    query_layer = keras.layers.Dense(
        TRANSFORMER_WIDTH, name="query"
    )
    key_layer = keras.layers.Dense(
        TRANSFORMER_WIDTH, name="key"
    )
    value_layer = keras.layers.Dense(
        TRANSFORMER_WIDTH, name="value"
    )
    attention_output_layer = keras.layers.Dense(
        TRANSFORMER_WIDTH, name="attention_output"
    )
    ffn_inner_layer = keras.layers.Dense(
        TRANSFORMER_FFN, activation="relu", name="ffn_inner"
    )
    ffn_output_layer = keras.layers.Dense(
        TRANSFORMER_WIDTH, name="ffn_output"
    )
    classifier_layer = keras.layers.Dense(
        TRANSFORMER_CLASSES, name="classifier"
    )

    token_value = token_embedding(token_input)
    position_value = position_embedding(position_input)
    combined = keras.layers.Add(name="embedding_add")(
        [token_value, position_value]
    )
    query = query_layer(combined)
    key = key_layer(combined)
    value = value_layer(combined)
    score = keras.layers.Dot(axes=(2, 2), name="attention_score")(
        [query, key]
    )
    score = keras.layers.Rescaling(
        scale=1.0 / np.sqrt(float(TRANSFORMER_WIDTH)),
        name="attention_scale",
    )(score)
    probability = keras.layers.Softmax(
        axis=-1, name="attention_probability"
    )(score)
    context = keras.layers.Dot(
        axes=(2, 1), name="attention_context"
    )([probability, value])
    attention_output = attention_output_layer(context)
    residual1 = keras.layers.Add(name="attention_residual")(
        [combined, attention_output]
    )
    ffn_inner = ffn_inner_layer(residual1)
    ffn_output = ffn_output_layer(ffn_inner)
    encoded = keras.layers.Add(name="ffn_residual")(
        [residual1, ffn_output]
    )
    pooled = keras.layers.GlobalAveragePooling1D(
        name="pool"
    )(encoded)
    logits = classifier_layer(pooled)

    model = keras.Model(
        [token_input, position_input],
        logits,
        name="fixture_transformer",
    )
    reference_model = keras.Model(
        [token_input, position_input],
        [
            token_value,
            position_value,
            combined,
            query,
            key,
            value,
            score,
            probability,
            context,
            attention_output,
            residual1,
            ffn_inner,
            ffn_output,
            encoded,
            pooled,
            logits,
        ],
        name="fixture_transformer_references",
    )

    rng = np.random.default_rng(SEED + 1)
    token_embedding.set_weights(
        [
            fixed_values(
                rng,
                (TRANSFORMER_VOCAB, TRANSFORMER_WIDTH),
                steps=96,
            )
        ]
    )
    position_embedding.set_weights(
        [
            fixed_values(
                rng,
                (TRANSFORMER_SEQUENCE, TRANSFORMER_WIDTH),
                steps=48,
            )
        ]
    )
    dense_layers = [
        query_layer,
        key_layer,
        value_layer,
        attention_output_layer,
        ffn_inner_layer,
        ffn_output_layer,
        classifier_layer,
    ]
    for layer in dense_layers:
        kernel_shape = tuple(int(value) for value in layer.kernel.shape)
        bias_shape = tuple(int(value) for value in layer.bias.shape)
        layer.set_weights(
            [
                fixed_values(rng, kernel_shape, steps=72),
                fixed_values(
                    rng, bias_shape, steps=24, denominator=512
                ),
            ]
        )

    training_position_ids = np.tile(
        np.arange(TRANSFORMER_SEQUENCE, dtype=np.int32),
        (training_token_ids.shape[0], 1),
    )
    training = train_fixed_model(
        model,
        [training_token_ids, training_position_ids],
        training_labels,
        keras.losses.SparseCategoricalCrossentropy(from_logits=True),
        TRANSFORMER_LEARNING_RATE,
    )
    training_logits = np.asarray(
        model(
            [training_token_ids, training_position_ids],
            training=False,
        ).numpy(),
        dtype=np.float32,
    )
    training_accuracy = np.float32(
        np.mean(
            np.argmax(training_logits, axis=1)
            == training_labels
        )
    )
    fixed_predictions = np.argmax(
        np.asarray(
            model(
                [token_ids, position_ids], training=False
            ).numpy(),
            dtype=np.float32,
        ),
        axis=1,
    ).astype(np.int32)
    fixed_accuracy = np.float32(
        np.mean(fixed_predictions == fixed_labels)
    )
    if not np.array_equal(fixed_predictions, fixed_labels):
        raise RuntimeError(
            "Transformer fixed texts were not classified correctly"
        )

    values = reference_model(
        [token_ids, position_ids], training=False
    )
    reference_names = [
        "token_embedding",
        "position_embedding",
        "embedding_sum",
        "query",
        "key",
        "value",
        "attention_score",
        "attention_probability",
        "attention_context",
        "attention_output",
        "attention_residual",
        "ffn_inner",
        "ffn_output",
        "encoded",
        "pooled",
        "logits",
    ]
    refs: OrderedDict[str, np.ndarray] = OrderedDict(
        (name, np.asarray(value.numpy(), dtype=np.float32))
        for name, value in zip(reference_names, values)
    )
    weights: OrderedDict[str, np.ndarray] = OrderedDict()
    biases: OrderedDict[str, np.ndarray] = OrderedDict()
    weights["token_embedding_weight"] = token_embedding.get_weights()[0]
    weights["position_embedding_weight"] = (
        position_embedding.get_weights()[0]
    )
    for layer in dense_layers:
        kernel, bias = layer.get_weights()
        weights[f"{layer.name}_kernel"] = kernel
        biases[f"{layer.name}_bias"] = bias
    dense_inputs: OrderedDict[str, str] = OrderedDict(
        [
            ("query", "embedding_sum"),
            ("key", "embedding_sum"),
            ("value", "embedding_sum"),
            ("attention_output", "attention_context"),
            ("ffn_inner", "attention_residual"),
            ("ffn_output", "ffn_inner"),
            ("classifier", "pooled"),
        ]
    )

    def representative() -> Iterable[list[np.ndarray]]:
        for index in range(TRANSFORMER_BATCH):
            # Keras 3.6 exports the two signature inputs to the converter in
            # reverse flatbuffer order even though model.inputs retains the
            # construction order.
            yield [
                position_ids[index : index + 1],
                token_ids[index : index + 1],
            ]

    return TransformerFixture(
        model=model,
        representative=representative,
        token_ids=token_ids,
        position_ids=position_ids,
        weights=weights,
        biases=biases,
        refs=refs,
        dense_inputs=dense_inputs,
        training=training,
        fixed_labels=fixed_labels,
        fixed_predictions=fixed_predictions,
        training_accuracy=training_accuracy,
        fixed_accuracy=fixed_accuracy,
    )


def recurrent_input() -> np.ndarray:
    """Two held-out histories with the same final device measurement."""

    return np.asarray(
        [
            [
                [0.53, 0.31, 0.24],
                [0.00, -0.19, -0.45],
                [-0.53, -0.57, -0.92],
                [0.30, 0.20, 0.25],
            ],
            [
                [-0.44, -0.04, -0.70],
                [0.11, 0.45, -0.06],
                [0.63, 0.76, 0.60],
                [0.30, 0.20, 0.25],
            ],
        ],
        dtype=np.float32,
    )


def recurrent_forecast_targets(inputs: np.ndarray) -> np.ndarray:
    """Create history-dependent next-step device forecasts.

    Input features are normalized current device temperature, load, and a
    daily-cycle sine value.  Each output step contains the smoothed next
    temperature, smoothed next load, and temperature trend.  The previous
    target state is used recursively, so no target is a pointwise transform
    of the current input.
    """

    values = np.asarray(inputs, dtype=np.float32)
    previous_temperature = np.zeros(values.shape[0], dtype=np.float32)
    previous_load = np.zeros(values.shape[0], dtype=np.float32)
    previous_trend = np.zeros(values.shape[0], dtype=np.float32)
    result = np.empty(
        (values.shape[0], RECURRENT_STEPS, RECURRENT_UNITS),
        dtype=np.float32,
    )
    for step in range(RECURRENT_STEPS):
        current_temperature = values[:, step, 0]
        current_load = values[:, step, 1]
        periodic = values[:, step, 2]
        next_temperature = (
            np.float32(0.52) * previous_temperature
            + np.float32(0.30) * current_temperature
            + np.float32(0.12) * current_load
            + np.float32(0.06) * periodic
        ).astype(np.float32)
        next_load = (
            np.float32(0.48) * previous_load
            + np.float32(0.38) * current_load
            + np.float32(0.14) * periodic
        ).astype(np.float32)
        next_trend = (
            np.float32(0.55) * previous_trend
            + np.float32(0.45)
            * (next_temperature - previous_temperature)
        ).astype(np.float32)
        result[:, step, 0] = next_temperature
        result[:, step, 1] = next_load
        result[:, step, 2] = next_trend
        previous_temperature = next_temperature
        previous_load = next_load
        previous_trend = next_trend
    return result


def recurrent_training_corpus() -> tuple[np.ndarray, np.ndarray]:
    """Generate deterministic device telemetry without external files."""

    sample_count = RECURRENT_TRAINING_SAMPLES
    sample = np.arange(sample_count, dtype=np.float32)[:, None]
    step = np.arange(RECURRENT_STEPS, dtype=np.float32)[None, :]
    phase = (
        np.float32(0.37) * sample + np.float32(0.83) * step
    )
    periodic = np.sin(
        np.float32(0.29) * sample + np.float32(0.71) * step
    )
    load = (
        np.float32(0.62) * np.sin(phase)
        + np.float32(0.18) * np.cos(np.float32(0.23) * sample)
    )
    temperature = (
        np.float32(0.46)
        * np.sin(phase - np.float32(0.55))
        + np.float32(0.32) * load
        + np.float32(0.10) * periodic
    )
    generated = np.stack(
        [
            np.clip(temperature, -0.95, 0.95),
            np.clip(load, -0.95, 0.95),
            periodic,
        ],
        axis=2,
    ).astype(np.float32)
    fixed = recurrent_input()
    if any(
        np.array_equal(candidate, held_out)
        for candidate in generated
        for held_out in fixed
    ):
        raise RuntimeError(
            "a recurrent evaluation sequence appears in the training corpus"
        )
    return generated, recurrent_forecast_targets(generated)


def require_recurrent_history_response(
    prediction: np.ndarray,
    name: str,
    targets: np.ndarray,
) -> None:
    """Require history-sensitive, correctly associated held-out forecasts."""

    values = np.asarray(prediction, dtype=np.float32)
    expected = np.asarray(targets, dtype=np.float32)
    expected_shape = (
        RECURRENT_BATCH,
        RECURRENT_STEPS,
        RECURRENT_UNITS,
    )
    if values.shape != expected_shape or expected.shape != expected_shape:
        raise RuntimeError(
            f"{name} application tensors must both have shape "
            f"{expected_shape}"
        )
    last_difference = np.abs(
        values[0, -1, :].astype(np.float64)
        - values[1, -1, :].astype(np.float64)
    )
    if float(np.max(last_difference)) <= 5.0e-3:
        raise RuntimeError(
            f"{name} ignored the different histories of the fixed sequences"
        )
    own_error = float(
        np.mean(
            np.square(
                values[:, -1, :].astype(np.float64)
                - expected[:, -1, :].astype(np.float64)
            )
        )
    )
    swapped_error = float(
        np.mean(
            np.square(
                values[:, -1, :].astype(np.float64)
                - expected[::-1, -1, :].astype(np.float64)
            )
        )
    )
    if not own_error < swapped_error:
        raise RuntimeError(
            f"{name} associated a held-out forecast with the wrong history"
        )
    shared_prediction = np.mean(
        expected[:, -1, :].astype(np.float64),
        axis=0,
        keepdims=True,
    )
    same_current_baseline = float(
        np.mean(
            np.square(
                shared_prediction
                - expected[:, -1, :].astype(np.float64)
            )
        )
    )
    if not own_error < same_current_baseline:
        raise RuntimeError(
            f"{name} did not beat the best shared final-step prediction"
        )


def recurrent_application_mse(
    model: keras.Model,
    inputs: np.ndarray,
    targets: np.ndarray,
) -> tuple[np.float32, np.float32]:
    prediction = np.asarray(
        model(inputs, training=False).numpy(), dtype=np.float32
    )
    require_recurrent_history_response(
        prediction, model.name, targets
    )
    application_mse = np.float32(
        np.mean(
            np.square(
                prediction.astype(np.float64)
                - targets.astype(np.float64)
            )
        )
    )
    final_step_mse = np.float32(
        np.mean(
            np.square(
                prediction[:, -1, :].astype(np.float64)
                - targets[:, -1, :].astype(np.float64)
            )
        )
    )
    return application_mse, final_step_mse


def recurrent_history_baseline_mse(targets: np.ndarray) -> np.float32:
    """MSE when the last known target is reused for the next prediction."""

    baseline = np.zeros_like(targets, dtype=np.float32)
    baseline[:, 1:, :] = targets[:, :-1, :]
    return np.float32(
        np.mean(
            np.square(
                baseline.astype(np.float64)
                - targets.astype(np.float64)
            )
        )
    )


def recurrent_same_current_baseline_mse(
    targets: np.ndarray,
) -> np.float32:
    """Best final-step MSE for one shared output on both fixed samples."""

    final_targets = np.asarray(targets, dtype=np.float32)[:, -1, :]
    shared_prediction = np.mean(
        final_targets.astype(np.float64), axis=0, keepdims=True
    )
    return np.float32(
        np.mean(
            np.square(
                shared_prediction
                - final_targets.astype(np.float64)
            )
        )
    )


def build_simple_rnn(
    inputs: np.ndarray,
    training_inputs: np.ndarray,
    training_targets: np.ndarray,
) -> RecurrentFixture:
    source = keras.Input(
        shape=(RECURRENT_STEPS, RECURRENT_FEATURES),
        dtype="float32",
        name="sequence",
    )
    layer = keras.layers.SimpleRNN(
        RECURRENT_UNITS,
        activation="tanh",
        use_bias=True,
        return_sequences=True,
        name="simple_rnn",
    )
    output = layer(source)
    model = keras.Model(source, output, name="fixture_simple_rnn")
    rng = np.random.default_rng(SEED + 2)
    layer.set_weights(
        [
            fixed_values(
                rng, (RECURRENT_FEATURES, RECURRENT_UNITS), steps=80
            ),
            fixed_values(
                rng, (RECURRENT_UNITS, RECURRENT_UNITS), steps=64
            ),
            fixed_values(
                rng,
                (RECURRENT_UNITS,),
                steps=24,
                denominator=512,
            ),
        ]
    )
    training = train_fixed_model(
        model,
        training_inputs,
        training_targets,
        keras.losses.MeanSquaredError(),
        RECURRENT_LEARNING_RATE,
    )
    targets = recurrent_forecast_targets(inputs)
    application_mse, final_step_mse = recurrent_application_mse(
        model, inputs, targets
    )
    history_baseline_mse = recurrent_history_baseline_mse(targets)
    same_current_baseline_mse = (
        recurrent_same_current_baseline_mse(targets)
    )
    if not application_mse < history_baseline_mse:
        raise RuntimeError(
            "SimpleRNN application MSE did not beat history baseline"
        )
    kernel, recurrent_kernel, bias = layer.get_weights()
    hidden = np.zeros(
        (RECURRENT_BATCH, RECURRENT_UNITS), dtype=np.float32
    )
    preactivation = []
    hidden_sequence = []
    for step in range(RECURRENT_STEPS):
        pre = (
            inputs[:, step, :] @ kernel
            + hidden @ recurrent_kernel
            + bias
        ).astype(np.float32)
        hidden = np.tanh(pre).astype(np.float32)
        preactivation.append(pre)
        hidden_sequence.append(hidden.copy())
    refs: OrderedDict[str, np.ndarray] = OrderedDict()
    refs["preactivation"] = np.stack(preactivation, axis=1)
    refs["hidden"] = np.stack(hidden_sequence, axis=1)
    keras_output = np.asarray(
        model(inputs, training=False).numpy(), dtype=np.float32
    )
    assert_close("SimpleRNN", keras_output, refs["hidden"])
    weights: OrderedDict[str, np.ndarray] = OrderedDict(
        [
            ("kernel", kernel),
            ("recurrent_kernel", recurrent_kernel),
            ("bias", bias),
        ]
    )
    return RecurrentFixture(
        name="simple_rnn",
        model=model,
        representative=representative_one_input(inputs),
        inputs=inputs,
        weights=weights,
        refs=refs,
        training=training,
        targets=targets,
        application_mse=application_mse,
        final_step_mse=final_step_mse,
        history_baseline_mse=history_baseline_mse,
        same_current_baseline_mse=same_current_baseline_mse,
    )


def build_gru(
    inputs: np.ndarray,
    training_inputs: np.ndarray,
    training_targets: np.ndarray,
) -> RecurrentFixture:
    source = keras.Input(
        shape=(RECURRENT_STEPS, RECURRENT_FEATURES),
        dtype="float32",
        name="sequence",
    )
    layer = keras.layers.GRU(
        RECURRENT_UNITS,
        activation="tanh",
        recurrent_activation="sigmoid",
        use_bias=True,
        reset_after=True,
        return_sequences=True,
        name="gru",
    )
    output = layer(source)
    model = keras.Model(source, output, name="fixture_gru")
    rng = np.random.default_rng(SEED + 3)
    layer.set_weights(
        [
            fixed_values(
                rng,
                (RECURRENT_FEATURES, 3 * RECURRENT_UNITS),
                steps=72,
            ),
            fixed_values(
                rng,
                (RECURRENT_UNITS, 3 * RECURRENT_UNITS),
                steps=64,
            ),
            fixed_values(
                rng,
                (2, 3 * RECURRENT_UNITS),
                steps=20,
                denominator=512,
            ),
        ]
    )
    training = train_fixed_model(
        model,
        training_inputs,
        training_targets,
        keras.losses.MeanSquaredError(),
        RECURRENT_LEARNING_RATE,
    )
    targets = recurrent_forecast_targets(inputs)
    application_mse, final_step_mse = recurrent_application_mse(
        model, inputs, targets
    )
    history_baseline_mse = recurrent_history_baseline_mse(targets)
    same_current_baseline_mse = (
        recurrent_same_current_baseline_mse(targets)
    )
    if not application_mse < history_baseline_mse:
        raise RuntimeError(
            "GRU application MSE did not beat history baseline"
        )
    kernel, recurrent_kernel, bias = layer.get_weights()
    input_bias = bias[0]
    recurrent_bias = bias[1]
    hidden = np.zeros(
        (RECURRENT_BATCH, RECURRENT_UNITS), dtype=np.float32
    )
    x_projection = []
    recurrent_projection = []
    update_sequence = []
    reset_sequence = []
    candidate_sequence = []
    hidden_sequence = []
    for step in range(RECURRENT_STEPS):
        projected_x = (
            inputs[:, step, :] @ kernel + input_bias
        ).astype(np.float32)
        projected_h = (
            hidden @ recurrent_kernel + recurrent_bias
        ).astype(np.float32)
        x_z, x_r, x_h = np.split(projected_x, 3, axis=1)
        h_z, h_r, h_h = np.split(projected_h, 3, axis=1)
        update = sigmoid(x_z + h_z)
        reset = sigmoid(x_r + h_r)
        candidate = np.tanh(x_h + reset * h_h).astype(np.float32)
        hidden = (
            update * hidden + (np.float32(1.0) - update) * candidate
        ).astype(np.float32)
        x_projection.append(projected_x)
        recurrent_projection.append(projected_h)
        update_sequence.append(update)
        reset_sequence.append(reset)
        candidate_sequence.append(candidate)
        hidden_sequence.append(hidden.copy())
    refs: OrderedDict[str, np.ndarray] = OrderedDict()
    refs["input_projection"] = np.stack(x_projection, axis=1)
    refs["recurrent_projection"] = np.stack(
        recurrent_projection, axis=1
    )
    refs["update_gate"] = np.stack(update_sequence, axis=1)
    refs["reset_gate"] = np.stack(reset_sequence, axis=1)
    refs["candidate"] = np.stack(candidate_sequence, axis=1)
    refs["hidden"] = np.stack(hidden_sequence, axis=1)
    keras_output = np.asarray(
        model(inputs, training=False).numpy(), dtype=np.float32
    )
    assert_close("GRU", keras_output, refs["hidden"])
    weights: OrderedDict[str, np.ndarray] = OrderedDict(
        [
            ("kernel", kernel),
            ("recurrent_kernel", recurrent_kernel),
            ("input_bias", input_bias),
            ("recurrent_bias", recurrent_bias),
        ]
    )
    return RecurrentFixture(
        name="gru",
        model=model,
        representative=representative_one_input(inputs),
        inputs=inputs,
        weights=weights,
        refs=refs,
        training=training,
        targets=targets,
        application_mse=application_mse,
        final_step_mse=final_step_mse,
        history_baseline_mse=history_baseline_mse,
        same_current_baseline_mse=same_current_baseline_mse,
    )


def build_lstm(
    inputs: np.ndarray,
    training_inputs: np.ndarray,
    training_targets: np.ndarray,
) -> RecurrentFixture:
    source = keras.Input(
        shape=(RECURRENT_STEPS, RECURRENT_FEATURES),
        dtype="float32",
        name="sequence",
    )
    layer = keras.layers.LSTM(
        RECURRENT_UNITS,
        activation="tanh",
        recurrent_activation="sigmoid",
        use_bias=True,
        return_sequences=True,
        name="lstm",
    )
    output = layer(source)
    model = keras.Model(source, output, name="fixture_lstm")
    rng = np.random.default_rng(SEED + 4)
    layer.set_weights(
        [
            fixed_values(
                rng,
                (RECURRENT_FEATURES, 4 * RECURRENT_UNITS),
                steps=72,
            ),
            fixed_values(
                rng,
                (RECURRENT_UNITS, 4 * RECURRENT_UNITS),
                steps=64,
            ),
            fixed_values(
                rng,
                (4 * RECURRENT_UNITS,),
                steps=20,
                denominator=512,
            ),
        ]
    )
    training = train_fixed_model(
        model,
        training_inputs,
        training_targets,
        keras.losses.MeanSquaredError(),
        RECURRENT_LEARNING_RATE,
    )
    targets = recurrent_forecast_targets(inputs)
    application_mse, final_step_mse = recurrent_application_mse(
        model, inputs, targets
    )
    history_baseline_mse = recurrent_history_baseline_mse(targets)
    same_current_baseline_mse = (
        recurrent_same_current_baseline_mse(targets)
    )
    if not application_mse < history_baseline_mse:
        raise RuntimeError(
            "LSTM application MSE "
            f"{float(application_mse):.9g} did not beat history baseline "
            f"{float(history_baseline_mse):.9g}"
        )
    kernel, recurrent_kernel, bias = layer.get_weights()
    hidden = np.zeros(
        (RECURRENT_BATCH, RECURRENT_UNITS), dtype=np.float32
    )
    cell = np.zeros_like(hidden)
    x_projection = []
    recurrent_projection = []
    preactivation = []
    input_gate = []
    forget_gate = []
    candidate_sequence = []
    output_gate = []
    cell_sequence = []
    hidden_sequence = []
    for step in range(RECURRENT_STEPS):
        projected_x = (inputs[:, step, :] @ kernel).astype(np.float32)
        projected_h = (hidden @ recurrent_kernel).astype(np.float32)
        pre = (projected_x + projected_h + bias).astype(np.float32)
        pre_i, pre_f, pre_c, pre_o = np.split(pre, 4, axis=1)
        gate_i = sigmoid(pre_i)
        gate_f = sigmoid(pre_f)
        candidate = np.tanh(pre_c).astype(np.float32)
        gate_o = sigmoid(pre_o)
        cell = (gate_f * cell + gate_i * candidate).astype(np.float32)
        hidden = (gate_o * np.tanh(cell)).astype(np.float32)
        x_projection.append(projected_x)
        recurrent_projection.append(projected_h)
        preactivation.append(pre)
        input_gate.append(gate_i)
        forget_gate.append(gate_f)
        candidate_sequence.append(candidate)
        output_gate.append(gate_o)
        cell_sequence.append(cell.copy())
        hidden_sequence.append(hidden.copy())
    refs: OrderedDict[str, np.ndarray] = OrderedDict()
    refs["input_projection"] = np.stack(x_projection, axis=1)
    refs["recurrent_projection"] = np.stack(
        recurrent_projection, axis=1
    )
    refs["preactivation"] = np.stack(preactivation, axis=1)
    refs["input_gate"] = np.stack(input_gate, axis=1)
    refs["forget_gate"] = np.stack(forget_gate, axis=1)
    refs["candidate"] = np.stack(candidate_sequence, axis=1)
    refs["output_gate"] = np.stack(output_gate, axis=1)
    refs["cell"] = np.stack(cell_sequence, axis=1)
    refs["hidden"] = np.stack(hidden_sequence, axis=1)
    keras_output = np.asarray(
        model(inputs, training=False).numpy(), dtype=np.float32
    )
    assert_close("LSTM", keras_output, refs["hidden"])
    weights: OrderedDict[str, np.ndarray] = OrderedDict(
        [
            ("kernel", kernel),
            ("recurrent_kernel", recurrent_kernel),
            ("bias", bias),
        ]
    )
    return RecurrentFixture(
        name="lstm",
        model=model,
        representative=representative_one_input(inputs),
        inputs=inputs,
        weights=weights,
        refs=refs,
        training=training,
        targets=targets,
        application_mse=application_mse,
        final_step_mse=final_step_mse,
        history_baseline_mse=history_baseline_mse,
        same_current_baseline_mse=same_current_baseline_mse,
    )


def converter_for(
    model: keras.Model,
    representative: Callable[[], Iterable[list[np.ndarray]]],
    strict: bool,
) -> tf.lite.TFLiteConverter:
    converter = tf.lite.TFLiteConverter.from_keras_model(model)
    converter.optimizations = [tf.lite.Optimize.DEFAULT]
    converter.representative_dataset = representative
    converter.experimental_enable_resource_variables = True
    if strict:
        converter.target_spec.supported_ops = [
            tf.lite.OpsSet.TFLITE_BUILTINS_INT8
        ]
        if all(value.dtype == "float32" for value in model.inputs):
            converter.inference_input_type = tf.int8
            converter.inference_output_type = tf.int8
    else:
        converter.target_spec.supported_ops = [
            tf.lite.OpsSet.TFLITE_BUILTINS,
            tf.lite.OpsSet.SELECT_TF_OPS,
        ]
        converter._experimental_lower_tensor_list_ops = False
    return converter


def interpreter_inventory(model_content: bytes) -> tuple[int, int]:
    interpreter = tf.lite.Interpreter(model_content=model_content)
    interpreter.allocate_tensors()
    quantized = 0
    floating = 0
    for detail in interpreter.get_tensor_details():
        scales = detail["quantization_parameters"]["scales"]
        if np.asarray(scales).size != 0 and np.any(
            np.asarray(scales) > 0.0
        ):
            quantized += 1
        if detail["dtype"] == np.float32:
            floating += 1
    return quantized, floating


def tflite_detail_qparam(
    detail: dict[str, object],
) -> tuple[np.float32, int]:
    parameters = detail["quantization_parameters"]
    scales = np.asarray(parameters["scales"], dtype=np.float32)
    zero_points = np.asarray(
        parameters["zero_points"], dtype=np.int64
    )
    if scales.size != 1 or zero_points.size != 1:
        raise RuntimeError(
            f"{detail['name']} needs one per-tensor scale and zero point"
        )
    scale = np.float32(scales[0])
    zero_point = int(zero_points[0])
    if not np.isfinite(scale) or float(scale) <= 0.0:
        raise RuntimeError(f"{detail['name']} has an invalid scale")
    return scale, zero_point


def tflite_input_value(
    detail: dict[str, object],
    named_inputs: dict[str, np.ndarray],
) -> np.ndarray:
    detail_name = str(detail["name"])
    matches = [
        (len(name), name, values)
        for name, values in named_inputs.items()
        if name in detail_name
    ]
    if not matches and len(named_inputs) == 1:
        return next(iter(named_inputs.values()))
    if not matches:
        raise RuntimeError(
            f"cannot associate TFLite input {detail_name}"
        )
    matches.sort(key=lambda item: item[0], reverse=True)
    if len(matches) > 1 and matches[0][0] == matches[1][0]:
        raise RuntimeError(
            f"ambiguous TFLite input name {detail_name}"
        )
    return matches[0][2]


def prepare_tflite_input(
    values: np.ndarray,
    detail: dict[str, object],
) -> np.ndarray:
    source = np.asarray(values)
    target_dtype = np.dtype(detail["dtype"])
    if np.issubdtype(target_dtype, np.floating):
        return np.ascontiguousarray(source.astype(target_dtype))
    if not np.issubdtype(target_dtype, np.integer):
        raise RuntimeError(
            f"unsupported TFLite input dtype {target_dtype}"
        )

    parameters = detail["quantization_parameters"]
    scales = np.asarray(parameters["scales"], dtype=np.float32)
    if np.issubdtype(source.dtype, np.floating):
        scale, zero_point = tflite_detail_qparam(detail)
        converted = np.rint(
            source.astype(np.float64) / float(scale)
            + float(zero_point)
        )
    elif scales.size != 0 and np.any(scales > 0.0):
        scale, zero_point = tflite_detail_qparam(detail)
        converted = np.rint(
            source.astype(np.float64) / float(scale)
            + float(zero_point)
        )
    else:
        converted = source.astype(np.float64)
    limits = np.iinfo(target_dtype)
    if np.any(converted < limits.min) or np.any(
        converted > limits.max
    ):
        raise RuntimeError(
            f"TFLite input {detail['name']} is outside {target_dtype}"
        )
    return np.ascontiguousarray(converted.astype(target_dtype))


def dequantize_tflite_output(
    values: np.ndarray,
    detail: dict[str, object],
) -> np.ndarray:
    source = np.asarray(values)
    source_dtype = np.dtype(detail["dtype"])
    if np.issubdtype(source_dtype, np.floating):
        return source.astype(np.float32)
    if not np.issubdtype(source_dtype, np.integer):
        raise RuntimeError(
            f"unsupported TFLite output dtype {source_dtype}"
        )
    scale, zero_point = tflite_detail_qparam(detail)
    return (
        (source.astype(np.float32) - np.float32(zero_point))
        * scale
    ).astype(np.float32)


def tflite_max_abs_error(
    model_content: bytes,
    named_inputs: dict[str, np.ndarray],
    keras_expected: np.ndarray,
    output_validator: Callable[[np.ndarray], None] | None = None,
) -> np.float32:
    interpreter = tf.lite.Interpreter(model_content=model_content)
    input_details = interpreter.get_input_details()
    for detail in input_details:
        values = tflite_input_value(detail, named_inputs)
        if tuple(int(value) for value in detail["shape"]) != values.shape:
            interpreter.resize_tensor_input(
                int(detail["index"]), values.shape, strict=True
            )
    interpreter.allocate_tensors()
    for detail in interpreter.get_input_details():
        values = tflite_input_value(detail, named_inputs)
        interpreter.set_tensor(
            int(detail["index"]),
            prepare_tflite_input(values, detail),
        )
    interpreter.invoke()
    output_details = interpreter.get_output_details()
    if len(output_details) != 1:
        raise RuntimeError("fixture model must have one TFLite output")
    output_detail = output_details[0]
    actual = dequantize_tflite_output(
        interpreter.get_tensor(int(output_detail["index"])),
        output_detail,
    )
    expected = np.asarray(keras_expected, dtype=np.float32)
    if actual.shape != expected.shape:
        raise RuntimeError(
            "TFLite output shape differs from the Keras output"
        )
    if output_validator is not None:
        output_validator(actual)
    error = float(
        np.max(
            np.abs(
                actual.astype(np.float64)
                - expected.astype(np.float64)
            )
        )
    )
    if not np.isfinite(error) or error < 0.0:
        raise RuntimeError("TFLite inference produced an invalid error")
    return np.float32(error)


def exception_note(error: Exception) -> str:
    text = str(error).lower()
    if "tensorlist" in text or "tensor list" in text:
        return (
            "strict integer conversion needs TensorList lowering; "
            "the fallback may retain Select TF Ops"
        )
    if "fully_quantize" in text or "integer" in text:
        return (
            "strict integer conversion rejected at least one operator; "
            "the fallback may contain floating tensors"
        )
    return (
        "the TensorFlow 2.18 converter rejected this model; "
        "manual symmetric parameters remain available"
    )


def require_transformer_predictions(
    logits: np.ndarray,
    expected_labels: np.ndarray,
) -> None:
    predictions = np.argmax(logits, axis=1).astype(np.int32)
    if not np.array_equal(predictions, expected_labels):
        raise RuntimeError(
            "TFLite Transformer fixed-text classes differ from labels"
        )


def probe_tflite(
    name: str,
    model: keras.Model,
    representative: Callable[[], Iterable[list[np.ndarray]]],
    named_inputs: dict[str, np.ndarray],
    keras_expected: np.ndarray,
    max_abs_error_limit: np.float32,
    skip: bool,
    output_validator: Callable[[np.ndarray], None] | None = None,
) -> TFLiteReport:
    if skip:
        return TFLiteReport(
            TFLITE_NOT_RUN,
            0,
            0,
            np.float32(np.nan),
            max_abs_error_limit,
            "probe skipped by command-line option",
        )
    strict_error: Exception | None = None
    try:
        content = converter_for(
            model, representative, strict=True
        ).convert()
    except Exception as error:
        strict_error = error
    else:
        quantized, floating = interpreter_inventory(content)
        max_abs_error = tflite_max_abs_error(
            content,
            named_inputs,
            keras_expected,
            output_validator,
        )
        if float(max_abs_error) > float(max_abs_error_limit):
            raise RuntimeError(
                f"{name} TFLite max_abs_error "
                f"{float(max_abs_error):.9g} exceeds "
                f"{float(max_abs_error_limit):.9g}"
            )
        return TFLiteReport(
            TFLITE_STRICT_INT8,
            quantized,
            floating,
            max_abs_error,
            max_abs_error_limit,
            "strict built-in integer conversion succeeded",
        )
    try:
        content = converter_for(
            model, representative, strict=False
        ).convert()
    except Exception:
        return TFLiteReport(
            TFLITE_UNSUPPORTED,
            0,
            0,
            np.float32(np.nan),
            max_abs_error_limit,
            exception_note(strict_error),
        )
    else:
        quantized, floating = interpreter_inventory(content)
        max_abs_error = tflite_max_abs_error(
            content,
            named_inputs,
            keras_expected,
            output_validator,
        )
        if float(max_abs_error) > float(max_abs_error_limit):
            raise RuntimeError(
                f"{name} TFLite max_abs_error "
                f"{float(max_abs_error):.9g} exceeds "
                f"{float(max_abs_error_limit):.9g}"
            )
        return TFLiteReport(
            TFLITE_FALLBACK,
            quantized,
            floating,
            max_abs_error,
            max_abs_error_limit,
            exception_note(strict_error),
        )


def c_value(c_type: str, value: int) -> str:
    if c_type == "uint32_t":
        return f"UINT32_C(0x{value & 0xFFFFFFFF:08x})"
    if c_type == "uint64_t":
        return f"UINT64_C(0x{value & 0xFFFFFFFFFFFFFFFF:016x})"
    return str(value)


def render_array(
    name: str,
    c_type: str,
    values: np.ndarray,
    columns: int,
) -> str:
    flattened = np.asarray(values).reshape(-1)
    rendered = [c_value(c_type, int(value)) for value in flattened]
    lines = [f"static const {c_type} {name}[{len(rendered)}] = {{"]
    for start in range(0, len(rendered), columns):
        group = ", ".join(rendered[start : start + columns])
        suffix = "," if start + columns < len(rendered) else ""
        lines.append(f"    {group}{suffix}")
    lines.append("};")
    return "\n".join(lines)


def render_initializer_macro(
    name: str,
    c_type: str,
    values: np.ndarray,
    columns: int,
) -> str:
    """Render values as a reusable preprocessor initializer fragment."""

    flattened = np.asarray(values).reshape(-1)
    rendered = [c_value(c_type, int(value)) for value in flattened]
    lines = [f"#define {name} \\"]
    for start in range(0, len(rendered), columns):
        group = ", ".join(rendered[start : start + columns])
        has_more = start + columns < len(rendered)
        comma = "," if has_more else ""
        continuation = " \\" if has_more else ""
        lines.append(f"    {group}{comma}{continuation}")
    return "\n".join(lines)


class HeaderWriter:
    def __init__(self) -> None:
        self.sections: list[str] = []

    def add(self, text: str = "") -> None:
        self.sections.append(text)

    def add_qparam(self, name: str, scale: np.float32) -> None:
        bits = scalar_float32_bits(scale)
        self.add(
            f"static const ksf_qparam_t {name}_qparam = "
            f"{{UINT32_C(0x{bits:08x}), INT32_C(0)}};"
        )

    def add_requant(self, name: str, requant: Requant) -> None:
        self.add(
            f"static const ksf_requant_t {name}_requant = "
            f"{{INT32_C({requant.multiplier}), "
            f"{requant.shift}u, {{0u, 0u, 0u}}}};"
        )

    def add_float_reference(
        self, name: str, values: np.ndarray
    ) -> QuantizedTensor:
        array = np.asarray(values, dtype=np.float32)
        quantized = quantize_int8(array)
        shape = " x ".join(str(value) for value in array.shape)
        self.add(f"/* {name}: shape {shape}. */")
        self.add_qparam(name, quantized.scale)
        self.add(
            render_array(
                f"{name}_f32_bits",
                "uint32_t",
                float32_bits(array),
                6,
            )
        )
        self.add(
            render_array(
                f"{name}_q",
                "int8_t",
                quantized.values,
                16,
            )
        )
        return quantized

    def add_weight(
        self, name: str, values: np.ndarray
    ) -> QuantizedTensor:
        array = np.asarray(values, dtype=np.float32)
        quantized = quantize_int8(array)
        shape = " x ".join(str(value) for value in array.shape)
        self.add(f"/* {name}: shape {shape}. */")
        self.add_qparam(name, quantized.scale)
        self.add(
            render_array(
                f"{name}_f32_bits",
                "uint32_t",
                float32_bits(array),
                6,
            )
        )
        self.add(
            render_array(
                f"{name}_q", "int8_t", quantized.values, 16
            )
        )
        return quantized

    def finish(self) -> str:
        return "\n\n".join(self.sections) + "\n"


def emit_tflite_report(
    writer: HeaderWriter,
    prefix: str,
    report: TFLiteReport,
) -> None:
    upper = prefix.upper()
    writer.add(
        f"/* {prefix}: {report.note}. */\n"
        f"#define KSF_{upper}_TFLITE_STATUS {report.status}u\n"
        f"#define KSF_{upper}_TFLITE_QUANTIZED_TENSORS "
        f"{report.quantized_tensors}u\n"
        f"#define KSF_{upper}_TFLITE_FLOAT_TENSORS "
        f"{report.float_tensors}u\n"
        f"#define KSF_{upper}_TFLITE_MAX_ABS_ERROR_F32_BITS "
        f"UINT32_C(0x{scalar_float32_bits(report.max_abs_error):08x})\n"
        f"#define KSF_{upper}_TFLITE_MAX_ABS_ERROR_LIMIT_F32_BITS "
        f"UINT32_C(0x"
        f"{scalar_float32_bits(report.max_abs_error_limit):08x})"
    )


def emit_training_report(
    writer: HeaderWriter,
    prefix: str,
    report: TrainingReport,
) -> None:
    upper = prefix.upper()
    writer.add(
        f"/* {prefix}: deterministic full-batch Keras SGD training. */\n"
        f"#define KSF_{upper}_TRAIN_STEPS {report.steps}u\n"
        f"#define KSF_{upper}_TRAIN_INITIAL_LOSS_F32_BITS "
        f"UINT32_C(0x{scalar_float32_bits(report.initial_loss):08x})\n"
        f"#define KSF_{upper}_TRAIN_FINAL_LOSS_F32_BITS "
        f"UINT32_C(0x{scalar_float32_bits(report.final_loss):08x})"
    )


def emit_transformer(
    writer: HeaderWriter,
    fixture: TransformerFixture,
    report: TFLiteReport,
) -> None:
    writer.add(
        "/* Transformer short-text classifier: positive review, negative "
        "review, or information request.\n"
        " * The training corpus uses semantic words rather than arbitrary "
        "integer patterns.\n"
        " * The network contains token and position embeddings, one attention "
        "head, two residual adds, and a two-layer FFN.\n"
        " * Attention is softmax((Q * transpose(K)) / sqrt(4)) * V.\n"
        " * Tensor storage order is batch, sequence, feature. */"
    )
    emit_tflite_report(writer, "transformer", report)
    emit_training_report(
        writer, "transformer", fixture.training
    )
    writer.add(
        "#define KSF_TRANSFORMER_TRAIN_ACCURACY_F32_BITS "
        f"UINT32_C(0x"
        f"{scalar_float32_bits(fixture.training_accuracy):08x})\n"
        "#define KSF_TRANSFORMER_FIXED_ACCURACY_F32_BITS "
        f"UINT32_C(0x"
        f"{scalar_float32_bits(fixture.fixed_accuracy):08x})\n"
        "#define KSF_TRANSFORMER_FIXED_SAMPLE_0_TEXT "
        "\"great good good\"\n"
        "#define KSF_TRANSFORMER_FIXED_SAMPLE_0_TRUE_CLASS 0u\n"
        f"#define KSF_TRANSFORMER_FIXED_SAMPLE_0_PREDICTED_CLASS "
        f"{int(fixture.fixed_predictions[0])}u\n"
        "#define KSF_TRANSFORMER_FIXED_SAMPLE_1_TEXT "
        "\"status status what now\"\n"
        "#define KSF_TRANSFORMER_FIXED_SAMPLE_1_TRUE_CLASS 2u\n"
        f"#define KSF_TRANSFORMER_FIXED_SAMPLE_1_PREDICTED_CLASS "
        f"{int(fixture.fixed_predictions[1])}u"
    )
    writer.add(
        render_initializer_macro(
            "KSF_TRANSFORMER_FIXED_TRUE_CLASSES_INITIALIZER",
            "uint8_t",
            fixture.fixed_labels.astype(np.uint8),
            8,
        )
    )
    writer.add(
        render_initializer_macro(
            "KSF_TRANSFORMER_FIXED_PREDICTED_CLASSES_INITIALIZER",
            "uint8_t",
            fixture.fixed_predictions.astype(np.uint8),
            8,
        )
    )
    writer.add(
        render_array(
            "ksf_transformer_token_ids",
            "uint8_t",
            fixture.token_ids.astype(np.uint8),
            8,
        )
    )
    writer.add(
        render_array(
            "ksf_transformer_position_ids",
            "uint8_t",
            fixture.position_ids.astype(np.uint8),
            8,
        )
    )
    weight_q: dict[str, QuantizedTensor] = {}
    for name, values in fixture.weights.items():
        weight_q[name] = writer.add_weight(
            f"ksf_transformer_{name}", values
        )
    ref_q: dict[str, QuantizedTensor] = {}
    for name, values in fixture.refs.items():
        ref_q[name] = writer.add_float_reference(
            f"ksf_transformer_{name}", values
        )

    for layer, input_name in fixture.dense_inputs.items():
        kernel_name = f"{layer}_kernel"
        bias_name = f"{layer}_bias"
        input_scale = ref_q[input_name].scale
        kernel_scale = weight_q[kernel_name].scale
        output_scale = ref_q[
            "logits" if layer == "classifier" else layer
        ].scale
        bias_scale = np.float32(input_scale * kernel_scale)
        bias_q = quantize_int32(
            fixture.biases[bias_name], bias_scale
        )
        writer.add(
            f"/* ksf_transformer_{bias_name}: product-scale INT32 bias. */"
        )
        writer.add_qparam(
            f"ksf_transformer_{bias_name}", bias_scale
        )
        writer.add(
            render_array(
                f"ksf_transformer_{bias_name}_q",
                "int32_t",
                bias_q,
                8,
            )
        )
        requant = choose_multiplier_shift(
            float(bias_scale) / float(output_scale)
        )
        writer.add_requant(
            f"ksf_transformer_{layer}", requant
        )
        accumulator = (
            ref_q[input_name].values.astype(np.int64)
            @ weight_q[kernel_name].values.astype(np.int64)
            + bias_q.astype(np.int64)
        )
        if layer == "ffn_inner":
            accumulator = np.maximum(accumulator, 0)
        limits = np.iinfo(np.int32)
        if np.any(accumulator < limits.min) or np.any(
            accumulator > limits.max
        ):
            raise RuntimeError(
                f"Transformer {layer} accumulator overflow"
            )
        writer.add(
            render_array(
                f"ksf_transformer_{layer}_accum_i32",
                "int32_t",
                accumulator.astype(np.int32),
                8,
            )
        )
        integer_output = round_shift_nearest_even(
            accumulator, requant
        )
        integer_output = np.clip(
            integer_output, -128, 127
        ).astype(np.int8)
        writer.add(
            render_array(
                f"ksf_transformer_{layer}_integer_q",
                "int8_t",
                integer_output,
                16,
            )
        )

    score_requant = choose_multiplier_shift(
        float(ref_q["query"].scale)
        * float(ref_q["key"].scale)
        / float(ref_q["attention_score"].scale)
        / np.sqrt(float(TRANSFORMER_WIDTH))
    )
    writer.add_requant(
        "ksf_transformer_attention_score", score_requant
    )
    context_requant = choose_multiplier_shift(
        float(ref_q["attention_probability"].scale)
        * float(ref_q["value"].scale)
        / float(ref_q["attention_context"].scale)
    )
    writer.add_requant(
        "ksf_transformer_attention_context", context_requant
    )
    for name, source, destination in [
        ("attention_residual_input", "embedding_sum", "attention_residual"),
        (
            "attention_residual_branch",
            "attention_output",
            "attention_residual",
        ),
        ("ffn_residual_input", "attention_residual", "encoded"),
        ("ffn_residual_branch", "ffn_output", "encoded"),
    ]:
        writer.add_requant(
            f"ksf_transformer_{name}",
            choose_multiplier_shift(
                float(ref_q[source].scale)
                / float(ref_q[destination].scale)
            ),
        )


def emit_recurrent(
    writer: HeaderWriter,
    fixture: RecurrentFixture,
    report: TFLiteReport,
) -> None:
    prefix = f"ksf_{fixture.name}"
    if fixture.name == "simple_rnn":
        writer.add(
            "/* SimpleRNN device forecast. Kernel columns are hidden units;\n"
            " * each step computes tanh(x * kernel + h * recurrent + bias).\n"
            " * Hidden units 0, 1, and 2 directly hold the three continuous\n"
            " * application forecasts described by KSF_RECURRENT_OUTPUT_*.\n"
            " * This direct output retains the 3-unit recurrent-layer test. */"
        )
    elif fixture.name == "gru":
        writer.add(
            "/* GRU device forecast. Kernel columns are z, r, h and\n"
            " * reset_after is enabled. h = z * h_prev + (1-z) * candidate.\n"
            " * Hidden units 0, 1, and 2 directly hold the three continuous\n"
            " * application forecasts described by KSF_RECURRENT_OUTPUT_*.\n"
            " * This direct output retains the 3-unit recurrent-layer test. */\n"
            "#define KSF_GRU_GATE_Z_OFFSET 0u\n"
            "#define KSF_GRU_GATE_R_OFFSET 3u\n"
            "#define KSF_GRU_GATE_H_OFFSET 6u\n"
            "#define KSF_GRU_RESET_AFTER 1u"
        )
    elif fixture.name == "lstm":
        writer.add(
            "/* LSTM device forecast. Kernel columns are i, f, c, o.\n"
            " * Hidden units 0, 1, and 2 directly hold the three continuous\n"
            " * application forecasts described by KSF_RECURRENT_OUTPUT_*.\n"
            " * This direct output retains the 3-unit recurrent-layer test. */\n"
            "#define KSF_LSTM_GATE_I_OFFSET 0u\n"
            "#define KSF_LSTM_GATE_F_OFFSET 3u\n"
            "#define KSF_LSTM_GATE_C_OFFSET 6u\n"
            "#define KSF_LSTM_GATE_O_OFFSET 9u"
        )
    else:
        raise RuntimeError(f"unknown recurrent fixture {fixture.name}")
    emit_tflite_report(writer, fixture.name, report)
    emit_training_report(writer, fixture.name, fixture.training)
    upper = fixture.name.upper()
    writer.add(
        f"#define KSF_{upper}_APPLICATION_MSE_F32_BITS "
        f"UINT32_C(0x"
        f"{scalar_float32_bits(fixture.application_mse):08x})\n"
        f"#define KSF_{upper}_FINAL_STEP_MSE_F32_BITS "
        f"UINT32_C(0x"
        f"{scalar_float32_bits(fixture.final_step_mse):08x})\n"
        f"#define KSF_{upper}_HISTORY_BASELINE_MSE_F32_BITS "
        f"UINT32_C(0x"
        f"{scalar_float32_bits(fixture.history_baseline_mse):08x})"
    )
    input_q = writer.add_float_reference(
        f"{prefix}_input", fixture.inputs
    )
    weight_q: dict[str, QuantizedTensor] = {}
    bias_values: dict[str, np.ndarray] = {}
    for name, values in fixture.weights.items():
        if "bias" in name:
            bias_values[name] = values
        else:
            weight_q[name] = writer.add_weight(
                f"{prefix}_{name}", values
            )
    ref_q: dict[str, QuantizedTensor] = {}
    for name, values in fixture.refs.items():
        ref_q[name] = writer.add_float_reference(
            f"{prefix}_{name}", values
        )
    writer.add(
        f"/* Forecast is the recurrent hidden sequence for this 3-unit "
        f"application model. */\n"
        f"#define {prefix}_forecast_f32_bits "
        f"{prefix}_hidden_f32_bits\n"
        f"#define {prefix}_forecast_qparam {prefix}_hidden_qparam\n"
        f"#define {prefix}_forecast_q {prefix}_hidden_q"
    )

    previous_hidden = np.zeros(
        (
            RECURRENT_BATCH,
            RECURRENT_STEPS,
            RECURRENT_UNITS,
        ),
        dtype=np.int8,
    )
    previous_hidden[:, 1:, :] = ref_q["hidden"].values[:, :-1, :]
    input_accumulator = (
        input_q.values.astype(np.int64)
        @ weight_q["kernel"].values.astype(np.int64)
    )
    recurrent_accumulator = (
        previous_hidden.astype(np.int64)
        @ weight_q["recurrent_kernel"].values.astype(np.int64)
    )
    limits = np.iinfo(np.int32)
    for name, accumulator in [
        ("input_projection", input_accumulator),
        ("recurrent_projection", recurrent_accumulator),
    ]:
        if np.any(accumulator < limits.min) or np.any(
            accumulator > limits.max
        ):
            raise RuntimeError(
                f"{fixture.name} {name} accumulator overflow"
            )
        writer.add(
            render_array(
                f"{prefix}_{name}_accum_i32",
                "int32_t",
                accumulator.astype(np.int32),
                8,
            )
        )

    if fixture.name == "simple_rnn":
        target_scale = ref_q["preactivation"].scale
        input_requant = choose_multiplier_shift(
            float(input_q.scale)
            * float(weight_q["kernel"].scale)
            / float(target_scale)
        )
        writer.add_requant(
            f"{prefix}_input_projection",
            input_requant,
        )
        recurrent_requant = choose_multiplier_shift(
            float(ref_q["hidden"].scale)
            * float(weight_q["recurrent_kernel"].scale)
            / float(target_scale)
        )
        writer.add_requant(
            f"{prefix}_recurrent_projection",
            recurrent_requant,
        )
        writer.add_qparam(f"{prefix}_bias", target_scale)
        bias_q = quantize_int32(
            bias_values["bias"], target_scale
        )
        require_int8_range(f"{fixture.name} bias", bias_q)
        writer.add(
            render_array(
                f"{prefix}_bias_q",
                "int32_t",
                bias_q,
                8,
            )
        )
    elif fixture.name == "gru":
        input_target = ref_q["input_projection"].scale
        recurrent_target = ref_q["recurrent_projection"].scale
        input_requant = choose_multiplier_shift(
            float(input_q.scale)
            * float(weight_q["kernel"].scale)
            / float(input_target)
        )
        writer.add_requant(
            f"{prefix}_input_projection",
            input_requant,
        )
        recurrent_requant = choose_multiplier_shift(
            float(ref_q["hidden"].scale)
            * float(weight_q["recurrent_kernel"].scale)
            / float(recurrent_target)
        )
        writer.add_requant(
            f"{prefix}_recurrent_projection",
            recurrent_requant,
        )
        recurrent_bias_q = None
        input_bias_q = None
        for name, target_scale in [
            ("input_bias", input_target),
            ("recurrent_bias", recurrent_target),
        ]:
            writer.add_qparam(f"{prefix}_{name}", target_scale)
            current_bias_q = quantize_int32(
                bias_values[name], target_scale
            )
            require_int8_range(
                f"{fixture.name} {name}", current_bias_q
            )
            if name == "input_bias":
                input_bias_q = current_bias_q
            else:
                recurrent_bias_q = current_bias_q
            writer.add(
                render_array(
                    f"{prefix}_{name}_q",
                    "int32_t",
                    current_bias_q,
                    8,
                )
            )
    elif fixture.name == "lstm":
        target_scale = ref_q["preactivation"].scale
        input_requant = choose_multiplier_shift(
            float(input_q.scale)
            * float(weight_q["kernel"].scale)
            / float(target_scale)
        )
        writer.add_requant(
            f"{prefix}_input_projection",
            input_requant,
        )
        recurrent_requant = choose_multiplier_shift(
            float(ref_q["hidden"].scale)
            * float(weight_q["recurrent_kernel"].scale)
            / float(target_scale)
        )
        writer.add_requant(
            f"{prefix}_recurrent_projection",
            recurrent_requant,
        )
        writer.add_qparam(f"{prefix}_bias", target_scale)
        bias_q = quantize_int32(
            bias_values["bias"], target_scale
        )
        require_int8_range(f"{fixture.name} bias", bias_q)
        writer.add(
            render_array(
                f"{prefix}_bias_q",
                "int32_t",
                bias_q,
                8,
            )
        )
    else:
        raise RuntimeError(f"unknown recurrent fixture {fixture.name}")

    input_integer = np.clip(
        round_shift_nearest_even(
            input_accumulator, input_requant
        ),
        -128,
        127,
    ).astype(np.int8)
    recurrent_integer = np.clip(
        round_shift_nearest_even(
            recurrent_accumulator, recurrent_requant
        ),
        -128,
        127,
    ).astype(np.int8)
    writer.add(
        render_array(
            f"{prefix}_input_projection_integer_q",
            "int8_t",
            input_integer,
            16,
        )
    )
    writer.add(
        render_array(
            f"{prefix}_recurrent_projection_integer_q",
            "int8_t",
            recurrent_integer,
            16,
        )
    )


def build_header(
    transformer: TransformerFixture,
    recurrent: Sequence[RecurrentFixture],
    reports: dict[str, TFLiteReport],
) -> str:
    writer = HeaderWriter()
    writer.add(
        "/* Generated by tools/export_keras_sequence_fixtures.py.\n"
        " * TensorFlow 2.18 and Keras 3.6 are the reference environment.\n"
        " * All *_f32_bits arrays contain exact IEEE-754 binary32 bits.\n"
        " * All integer tensors use symmetric INT8 with zero point 0.\n"
        " * Sigmoid, tanh, softmax, and attention scaling remain FP32\n"
        " * checkpoints between integer input and output tensors.\n"
        " * TFLite status 1 means strict built-in integer conversion;\n"
        " * status 2 means a built-in or Select TF Ops fallback;\n"
        " * status 3 means conversion was unavailable; status 0 was skipped.\n"
        " */"
    )
    writer.add(
        "#ifndef KERAS_SEQUENCE_FIXTURES_H\n"
        "#define KERAS_SEQUENCE_FIXTURES_H\n\n"
        "#include <stdint.h>"
    )
    writer.add(
        "#define KSF_SEED UINT32_C(20260726)\n"
        "#define KSF_TRANSFORMER_BATCH 2u\n"
        "#define KSF_TRANSFORMER_SEQUENCE 4u\n"
        "#define KSF_TRANSFORMER_VOCAB 8u\n"
        "#define KSF_TRANSFORMER_WIDTH 4u\n"
        "#define KSF_TRANSFORMER_FFN 6u\n"
        "#define KSF_TRANSFORMER_CLASSES 3u\n"
        "#define KSF_RECURRENT_BATCH 2u\n"
        "#define KSF_RECURRENT_STEPS 4u\n"
        "#define KSF_RECURRENT_FEATURES 3u\n"
        "#define KSF_RECURRENT_UNITS 3u\n"
        f"#define KSF_RECURRENT_TRAINING_SAMPLE_COUNT "
        f"{RECURRENT_TRAINING_SAMPLES}u\n"
        "#define KSF_RECURRENT_FIXED_SAMPLE_COUNT 2u"
    )
    writer.add(
        "/* Short-text vocabulary. Token 0 pads unused positions. */\n"
        "#define KSF_TRANSFORMER_TOKEN_PAD 0u\n"
        "#define KSF_TRANSFORMER_TOKEN_GOOD 1u\n"
        "#define KSF_TRANSFORMER_TOKEN_GREAT 2u\n"
        "#define KSF_TRANSFORMER_TOKEN_BAD 3u\n"
        "#define KSF_TRANSFORMER_TOKEN_AWFUL 4u\n"
        "#define KSF_TRANSFORMER_TOKEN_WHAT 5u\n"
        "#define KSF_TRANSFORMER_TOKEN_STATUS 6u\n"
        "#define KSF_TRANSFORMER_TOKEN_NOW 7u\n"
        "#define KSF_TRANSFORMER_CLASS_POSITIVE_REVIEW 0u\n"
        "#define KSF_TRANSFORMER_CLASS_NEGATIVE_REVIEW 1u\n"
        "#define KSF_TRANSFORMER_CLASS_INFORMATION_REQUEST 2u\n"
        "#define KSF_TRANSFORMER_TRAINING_SAMPLE_COUNT 12u"
    )
    for index, name in enumerate(TRANSFORMER_TOKEN_NAMES):
        writer.add(
            f"#define KSF_TRANSFORMER_TOKEN_{index}_TEXT \"{name}\""
        )
    for index, name in enumerate(TRANSFORMER_CLASS_NAMES):
        writer.add(
            f"#define KSF_TRANSFORMER_CLASS_{index}_NAME \"{name}\""
        )
    writer.add(
        "/* Device-telemetry regression task.\n"
        " * Input 0: normalized current temperature, C = 60 + 20 * input.\n"
        " * Input 1: normalized current load, percent = 50 + 50 * input.\n"
        " * Input 2: sine of the daily operating phase.\n"
        " * Output 0: normalized smoothed next temperature.\n"
        " * Output 1: normalized smoothed next load.\n"
        " * Output 2: normalized next temperature trend.\n"
        " * The target starts with previous state (0, 0, 0), then uses:\n"
        " * T_next = 0.52*T_prev + 0.30*T_now + 0.12*L_now + 0.06*P_now;\n"
        " * L_next = 0.48*L_prev + 0.38*L_now + 0.14*P_now;\n"
        " * D_next = 0.55*D_prev + 0.45*(T_next - T_prev).\n"
        " */\n"
        "#define KSF_RECURRENT_FEATURE_0_NAME "
        "\"normalized_current_temperature\"\n"
        "#define KSF_RECURRENT_FEATURE_1_NAME "
        "\"normalized_current_load\"\n"
        "#define KSF_RECURRENT_FEATURE_2_NAME \"daily_phase_sine\"\n"
        "#define KSF_RECURRENT_OUTPUT_0_NAME "
        "\"smoothed_next_temperature\"\n"
        "#define KSF_RECURRENT_OUTPUT_1_NAME "
        "\"smoothed_next_load\"\n"
        "#define KSF_RECURRENT_OUTPUT_2_NAME "
        "\"next_temperature_trend\"\n"
        "#define KSF_RECURRENT_TEMPERATURE_BASE_C_F32_BITS "
        f"UINT32_C(0x{scalar_float32_bits(np.float32(60.0)):08x})\n"
        "#define KSF_RECURRENT_TEMPERATURE_SCALE_C_F32_BITS "
        f"UINT32_C(0x{scalar_float32_bits(np.float32(20.0)):08x})\n"
        "#define KSF_RECURRENT_LOAD_BASE_PERCENT_F32_BITS "
        f"UINT32_C(0x{scalar_float32_bits(np.float32(50.0)):08x})\n"
        "#define KSF_RECURRENT_LOAD_SCALE_PERCENT_F32_BITS "
        f"UINT32_C(0x{scalar_float32_bits(np.float32(50.0)):08x})"
    )
    target = recurrent[0].targets
    for fixture in recurrent[1:]:
        if not np.array_equal(fixture.targets, target):
            raise RuntimeError("recurrent application targets differ")
    same_current_baseline_mse = (
        recurrent_same_current_baseline_mse(target)
    )
    for fixture in recurrent:
        if (
            fixture.same_current_baseline_mse
            != same_current_baseline_mse
        ):
            raise RuntimeError(
                "recurrent same-current baselines differ"
            )
    writer.add(
        "#define KSF_RECURRENT_SAME_CURRENT_BASELINE_MSE_F32_BITS "
        f"UINT32_C(0x"
        f"{scalar_float32_bits(same_current_baseline_mse):08x})"
    )
    writer.add(
        "/* Exact batch, step, output regression targets as binary32 bits. */"
    )
    writer.add(
        render_initializer_macro(
            "KSF_RECURRENT_APPLICATION_TARGET_F32_BITS_INITIALIZER",
            "uint32_t",
            float32_bits(target),
            6,
        )
    )
    writer.add(
        "typedef struct {\n"
        "    uint32_t scale_bits;\n"
        "    int32_t zero_point;\n"
        "} ksf_qparam_t;\n\n"
        "typedef struct {\n"
        "    int32_t multiplier;\n"
        "    uint8_t right_shift;\n"
        "    uint8_t reserved[3];\n"
        "} ksf_requant_t;"
    )
    emit_transformer(
        writer, transformer, reports["transformer"]
    )
    for fixture in recurrent:
        emit_recurrent(writer, fixture, reports[fixture.name])
    writer.add("#endif")
    return writer.finish()


def main() -> None:
    args = parse_args()
    configure_determinism()
    transformer = build_transformer()
    sequence = recurrent_input()
    recurrent_training_inputs, recurrent_training_targets = (
        recurrent_training_corpus()
    )
    recurrent = [
        build_simple_rnn(
            sequence,
            recurrent_training_inputs,
            recurrent_training_targets,
        ),
        build_gru(
            sequence,
            recurrent_training_inputs,
            recurrent_training_targets,
        ),
        build_lstm(
            sequence,
            recurrent_training_inputs,
            recurrent_training_targets,
        ),
    ]
    reports = {
        "transformer": probe_tflite(
            "transformer",
            transformer.model,
            transformer.representative,
            {
                "token_ids": transformer.token_ids,
                "position_ids": transformer.position_ids,
            },
            np.asarray(
                transformer.model(
                    [
                        transformer.token_ids,
                        transformer.position_ids,
                    ],
                    training=False,
                ).numpy(),
                dtype=np.float32,
            ),
            TFLITE_MAX_ABS_ERROR_LIMITS["transformer"],
            args.skip_tflite,
            lambda output: require_transformer_predictions(
                output, transformer.fixed_labels
            ),
        )
    }
    for fixture in recurrent:
        reports[fixture.name] = probe_tflite(
            fixture.name,
            fixture.model,
            fixture.representative,
            {"sequence": fixture.inputs},
            np.asarray(
                fixture.model(
                    fixture.inputs, training=False
                ).numpy(),
                dtype=np.float32,
            ),
            TFLITE_MAX_ABS_ERROR_LIMITS[fixture.name],
            args.skip_tflite,
            lambda output, name=fixture.name, targets=fixture.targets: (
                require_recurrent_history_response(
                    output, name, targets
                )
            ),
        )
    header = build_header(transformer, recurrent, reports)
    digest = hashlib.sha256(header.encode("utf-8")).hexdigest()
    if args.check:
        if not args.output.exists():
            raise SystemExit(f"missing generated file: {args.output}")
        current = args.output.read_text(encoding="utf-8")
        if current != header:
            raise SystemExit(
                f"generated file differs: {args.output}"
            )
    else:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        current = (
            args.output.read_text(encoding="utf-8")
            if args.output.exists()
            else None
        )
        if current != header:
            args.output.write_text(header, encoding="utf-8")
    print(f"TensorFlow={tf.__version__} Keras={keras.__version__}")
    for name, report in reports.items():
        print(
            f"{name}: tflite_status={report.status} "
            f"quantized_tensors={report.quantized_tensors} "
            f"float_tensors={report.float_tensors} "
            f"max_abs_error={float(report.max_abs_error):.9g} "
            f"max_abs_error_limit="
            f"{float(report.max_abs_error_limit):.9g} "
            f"note={report.note}"
        )
    print(
        "transformer: "
        f"train_cross_entropy_initial="
        f"{float(transformer.training.initial_loss):.9g} "
        f"train_cross_entropy_final="
        f"{float(transformer.training.final_loss):.9g} "
        f"train_accuracy={float(transformer.training_accuracy):.9g} "
        f"fixed_accuracy={float(transformer.fixed_accuracy):.9g} "
        f"fixed_true={transformer.fixed_labels.tolist()} "
        f"fixed_predicted={transformer.fixed_predictions.tolist()}"
    )
    for fixture in recurrent:
        print(
            f"{fixture.name}: "
            f"train_mse_initial="
            f"{float(fixture.training.initial_loss):.9g} "
            f"train_mse_final={float(fixture.training.final_loss):.9g} "
            f"application_mse={float(fixture.application_mse):.9g} "
            f"final_step_mse={float(fixture.final_step_mse):.9g} "
            f"history_baseline_mse="
            f"{float(fixture.history_baseline_mse):.9g} "
            f"same_current_baseline_mse="
            f"{float(fixture.same_current_baseline_mse):.9g}"
        )
    print(f"header_sha256={digest}")


if __name__ == "__main__":
    main()
