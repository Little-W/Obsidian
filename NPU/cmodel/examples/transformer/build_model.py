#!/usr/bin/env python3
"""Train and export a two-encoder Transformer command classifier."""

from __future__ import annotations

import argparse
import hashlib
import json
import math
import os
import zipfile
from pathlib import Path
from typing import Callable, Sequence

os.environ.setdefault("CUDA_VISIBLE_DEVICES", "-1")
os.environ.setdefault("TF_ENABLE_ONEDNN_OPTS", "0")
os.environ.setdefault("TF_CPP_MIN_LOG_LEVEL", "3")

import keras
import numpy as np
import tensorflow as tf


TOKENS = 8
VOCABULARY = (
    "<pad>",
    "please",
    "turn",
    "set",
    "switch",
    "make",
    "enable",
    "activate",
    "disable",
    "deactivate",
    "light",
    "lamp",
    "fan",
    "blower",
    "on",
    "off",
    "now",
    "immediately",
    "room",
    "bedroom",
    "living",
    "the",
    "in",
    "device",
)
TOKEN_MEANINGS = (
    "padding; no source word",
    "polite request marker",
    "request an on/off action",
    "set a requested state",
    "change a device state",
    "form a requested state",
    "request the enabled state",
    "request the active state",
    "request the disabled state",
    "request the inactive state",
    "the room light",
    "a synonym for light",
    "the room fan",
    "a synonym for fan",
    "enabled state",
    "disabled state",
    "apply now",
    "apply without delay",
    "the current room",
    "the bedroom",
    "the living room",
    "English article",
    "location preposition",
    "generic device noun",
)
VOCAB_SIZE = len(VOCABULARY)
POSITION_WIDTH = 8
WIDTH = VOCAB_SIZE + POSITION_WIDTH
HEADS = 4
HEAD_WIDTH = WIDTH // HEADS
FFN_WIDTH = 48
CLASSES = 4
FRACTION_BITS = 5
SCALE = 2.0**-FRACTION_BITS
SEED = 20260726
EPOCHS = 100
Q5_AWARE_EPOCHS = 40
Q5_PROJECTED_EPOCHS = 8
ENCODER_NOISE_STDDEV = 0.09375
FINAL_NORM_SCALE = 0.875
CLASS_NAMES = ("light_on", "light_off", "fan_on", "fan_off")

Sentence = tuple[str, ...]
Template = Callable[[str, str, str, str], Sentence]


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


def deterministic_keras_archive(path: Path) -> None:
    """Normalize ZIP metadata so equal trained models have equal file bytes."""

    with zipfile.ZipFile(path, "r") as source:
        entries = {name: source.read(name) for name in source.namelist()}
    metadata = json.loads(entries["metadata.json"].decode("utf-8"))
    metadata["date_saved"] = "1980-01-01@00:00:00"
    entries["metadata.json"] = json.dumps(
        metadata, sort_keys=True, separators=(",", ":")
    ).encode("utf-8")
    temporary = path.with_name(f".{path.name}.normalized-{os.getpid()}")
    try:
        with zipfile.ZipFile(
            temporary,
            "w",
            compression=zipfile.ZIP_STORED,
            strict_timestamps=True,
        ) as destination:
            for name in sorted(entries):
                info = zipfile.ZipInfo(name, date_time=(1980, 1, 1, 0, 0, 0))
                info.compress_type = zipfile.ZIP_STORED
                info.create_system = 3
                info.external_attr = 0o600 << 16
                destination.writestr(info, entries[name])
        os.replace(temporary, path)
    finally:
        if temporary.exists():
            temporary.unlink()


def class_parts(class_id: int) -> tuple[tuple[str, ...], str, tuple[str, ...]]:
    if class_id == 0:
        return ("light", "lamp"), "on", ("enable", "activate")
    if class_id == 1:
        return ("light", "lamp"), "off", ("disable", "deactivate")
    if class_id == 2:
        return ("fan", "blower"), "on", ("enable", "activate")
    if class_id == 3:
        return ("fan", "blower"), "off", ("disable", "deactivate")
    raise ValueError(f"invalid class {class_id}")


TRAIN_TEMPLATES: tuple[Template, ...] = (
    lambda device, state, action, context: (
        "please",
        action,
        "the",
        device,
        state,
        context,
    ),
    lambda device, state, action, context: (
        action,
        device,
        state,
        "in",
        "room",
    ),
    lambda device, state, action, context: (
        "in",
        "bedroom",
        action,
        "the",
        device,
        state,
    ),
    lambda device, state, action, context: (
        "now",
        action,
        state,
        "the",
        device,
    ),
    lambda device, state, action, context: (
        "please",
        "make",
        "the",
        device,
        state,
    ),
    lambda device, state, action, context: (
        "set",
        "device",
        device,
        state,
        "room",
    ),
    lambda device, state, action, context: (
        action,
        "living",
        device,
        state,
        context,
    ),
    lambda device, state, action, context: (
        "please",
        "switch",
        device,
        state,
        context,
    ),
)


def training_corpus() -> tuple[list[Sentence], np.ndarray]:
    rows: list[tuple[Sentence, int]] = []
    neutral_actions = ("turn", "set", "switch")
    contexts = ("now", "immediately")
    for class_id in range(CLASSES):
        devices, state, state_actions = class_parts(class_id)
        for device in devices:
            for action in neutral_actions:
                for context in contexts:
                    for template in TRAIN_TEMPLATES:
                        rows.append(
                            (template(device, state, action, context), class_id)
                        )
            for state_action in state_actions:
                rows.extend(
                    [
                        (
                            ("please", state_action, "the", device, "now"),
                            class_id,
                        ),
                        (
                            ("in", "living", state_action, device),
                            class_id,
                        ),
                        (
                            (state_action, "room", device, "immediately"),
                            class_id,
                        ),
                        (
                            ("bedroom", device, state_action, "please"),
                            class_id,
                        ),
                    ]
                )
    unique: dict[Sentence, int] = {}
    for sentence, label in rows:
        if len(sentence) > TOKENS:
            raise ValueError(f"training sentence too long: {sentence}")
        unique[sentence] = label
    balanced: list[tuple[Sentence, int]] = []
    random = np.random.default_rng(SEED)
    for class_id in range(CLASSES):
        class_rows = [
            (sentence, label)
            for sentence, label in unique.items()
            if label == class_id
        ]
        random.shuffle(class_rows)
        balanced.extend(class_rows[:48])
    random.shuffle(balanced)
    return (
        [sentence for sentence, _ in balanced],
        np.asarray([label for _, label in balanced], dtype=np.uint8),
    )


def held_out_corpus() -> tuple[list[Sentence], np.ndarray]:
    rows: list[tuple[Sentence, int]] = []
    for class_id in range(CLASSES):
        devices, state, state_actions = class_parts(class_id)
        rows.extend(
            [
                ((devices[0], state, "please"), class_id),
                (
                    ("immediately", "switch", "the", devices[1], state),
                    class_id,
                ),
                (("in", "living", "turn", state, devices[0]), class_id),
                (
                    ("please", devices[1], state_actions[0], "now"),
                    class_id,
                ),
                (("room", devices[0], state), class_id),
                (("make", devices[1], state, "immediately"), class_id),
            ]
        )
    return (
        [sentence for sentence, _ in rows],
        np.asarray([label for _, label in rows], dtype=np.uint8),
    )


def position_table() -> np.ndarray:
    table = np.zeros((TOKENS, POSITION_WIDTH), dtype=np.float32)
    for position in range(TOKENS):
        for pair in range(POSITION_WIDTH // 2):
            divisor = 10000.0 ** (2.0 * pair / POSITION_WIDTH)
            table[position, 2 * pair] = np.float32(
                0.25 * math.sin(position / divisor)
            )
            table[position, 2 * pair + 1] = np.float32(
                0.25 * math.cos(position / divisor)
            )
    return fixed(table).astype(np.float32) * np.float32(SCALE)


def encode_sentences(
    sentences: Sequence[Sequence[str]],
) -> tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray]:
    word_input = np.zeros(
        (len(sentences), TOKENS, WIDTH), dtype=np.float32
    )
    position_input = np.zeros_like(word_input)
    token_ids = np.zeros((len(sentences), TOKENS), dtype=np.uint8)
    valid_lengths = np.zeros((len(sentences),), dtype=np.uint8)
    vocabulary_index = {
        token: index for index, token in enumerate(VOCABULARY)
    }
    positions = position_table()
    for sample, sentence in enumerate(sentences):
        if len(sentence) == 0 or len(sentence) > TOKENS:
            raise ValueError(f"invalid sentence length at sample {sample}")
        valid_lengths[sample] = np.uint8(len(sentence))
        for position, token in enumerate(sentence):
            token_id = vocabulary_index[token]
            token_ids[sample, position] = np.uint8(token_id)
            word_input[sample, position, token_id] = np.float32(0.75)
            position_input[
                sample, position, VOCAB_SIZE:
            ] = positions[position]
    return word_input, position_input, token_ids, valid_lengths


def fixed(values: np.ndarray) -> np.ndarray:
    return np.clip(
        np.rint(np.asarray(values, dtype=np.float64) / SCALE),
        -128,
        127,
    ).astype(np.int8)


def target_scores(
    labels: np.ndarray, valid_lengths: np.ndarray
) -> tuple[np.ndarray, np.ndarray]:
    target = np.zeros(
        (labels.size, TOKENS, CLASSES), dtype=np.float32
    )
    weights = np.zeros((labels.size, TOKENS), dtype=np.float32)
    for sample, label_value in enumerate(labels):
        label = int(label_value)
        length = int(valid_lengths[sample])
        for position in range(length):
            for class_id in range(CLASSES):
                if class_id == label:
                    value = 0.56 + 0.018 * length + 0.012 * position
                else:
                    value = (
                        -0.24
                        + 0.018 * class_id
                        - 0.008 * position
                        + 0.004 * length
                    )
                target[sample, position, class_id] = np.float32(value)
            weights[sample, position] = np.float32(1.0)
    return target, weights


def model_layers() -> dict[str, keras.layers.Layer]:
    regularizer = keras.regularizers.L2(2.0e-5)
    return {
        "input_add": keras.layers.Add(name="token_plus_position"),
        "attention1": keras.layers.MultiHeadAttention(
            num_heads=HEADS,
            key_dim=HEAD_WIDTH,
            value_dim=HEAD_WIDTH,
            dropout=0.0,
            use_bias=False,
            kernel_regularizer=regularizer,
            name="encoder1_attention",
        ),
        "attention_add1": keras.layers.Add(name="encoder1_attention_add"),
        "attention_norm1": keras.layers.LayerNormalization(
            axis=-1, epsilon=1.0e-3, name="encoder1_attention_norm"
        ),
        "expand1": keras.layers.Dense(
            FFN_WIDTH,
            activation="gelu",
            kernel_regularizer=regularizer,
            name="encoder1_ffn_expand",
        ),
        "contract1": keras.layers.Dense(
            WIDTH,
            kernel_regularizer=regularizer,
            name="encoder1_ffn_contract",
        ),
        "ffn_add1": keras.layers.Add(name="encoder1_ffn_add"),
        "ffn_norm1": keras.layers.LayerNormalization(
            axis=-1, epsilon=1.0e-3, name="encoder1_output_norm"
        ),
        "attention2": keras.layers.MultiHeadAttention(
            num_heads=HEADS,
            key_dim=HEAD_WIDTH,
            value_dim=HEAD_WIDTH,
            dropout=0.0,
            use_bias=False,
            kernel_regularizer=regularizer,
            name="encoder2_attention",
        ),
        "attention_add2": keras.layers.Add(name="encoder2_attention_add"),
        "attention_norm2": keras.layers.LayerNormalization(
            axis=-1, epsilon=1.0e-3, name="encoder2_attention_norm"
        ),
        "expand2": keras.layers.Dense(
            FFN_WIDTH,
            activation="gelu",
            kernel_regularizer=regularizer,
            name="encoder2_ffn_expand",
        ),
        "contract2": keras.layers.Dense(
            WIDTH,
            kernel_regularizer=regularizer,
            name="encoder2_ffn_contract",
        ),
        "ffn_add2": keras.layers.Add(name="encoder2_ffn_add"),
        "ffn_norm2": keras.layers.LayerNormalization(
            axis=-1, epsilon=1.0e-3, name="encoder2_output_norm"
        ),
        "classifier": keras.layers.Dense(
            CLASSES,
            activation="linear",
            kernel_regularizer=regularizer,
            name="intent_logits",
        ),
    }


class TrainingQ5(keras.layers.Layer):
    """Q5 fake quantization used only by the training graph."""

    def call(self, inputs: tf.Tensor) -> tf.Tensor:
        return tf.quantization.fake_quant_with_min_max_args(
            inputs,
            min=-128.0 * SCALE,
            max=127.0 * SCALE,
            num_bits=8,
            narrow_range=False,
        )


def training_q5(
    value: keras.KerasTensor,
    name: str,
) -> keras.KerasTensor:
    return TrainingQ5(name=name)(value)


def apply_network(
    layers: dict[str, keras.layers.Layer],
    words: keras.KerasTensor,
    positions: keras.KerasTensor,
) -> tuple[keras.KerasTensor, keras.KerasTensor, keras.KerasTensor]:
    source = layers["input_add"]([words, positions])
    attention1 = layers["attention1"](source, source)
    residual1 = layers["attention_add1"]([source, attention1])
    normalized_attention1 = layers["attention_norm1"](residual1)
    hidden1 = layers["expand1"](normalized_attention1)
    contracted1 = layers["contract1"](hidden1)
    encoder1 = layers["ffn_norm1"](
        layers["ffn_add1"]([normalized_attention1, contracted1])
    )

    attention2 = layers["attention2"](encoder1, encoder1)
    residual2 = layers["attention_add2"]([encoder1, attention2])
    normalized_attention2 = layers["attention_norm2"](residual2)
    hidden2 = layers["expand2"](normalized_attention2)
    contracted2 = layers["contract2"](hidden2)
    encoder2 = layers["ffn_norm2"](
        layers["ffn_add2"]([normalized_attention2, contracted2])
    )
    logits = layers["classifier"](encoder2)
    return encoder1, encoder2, logits


def apply_q5_training_network(
    layers: dict[str, keras.layers.Layer],
    words: keras.KerasTensor,
    positions: keras.KerasTensor,
) -> keras.KerasTensor:
    """Run shared standard layers with training-only Q5 activation noise."""

    source = training_q5(
        layers["input_add"]([words, positions]),
        "training_q5_input_add",
    )
    attention1 = training_q5(
        layers["attention1"](source, source),
        "training_q5_attention1",
    )
    residual1 = training_q5(
        layers["attention_add1"]([source, attention1]),
        "training_q5_attention_add1",
    )
    normalized_attention1 = training_q5(
        layers["attention_norm1"](residual1),
        "training_q5_attention_norm1",
    )
    hidden1 = training_q5(
        layers["expand1"](normalized_attention1),
        "training_q5_expand1",
    )
    contracted1 = training_q5(
        layers["contract1"](hidden1),
        "training_q5_contract1",
    )
    encoder1 = training_q5(
        layers["ffn_norm1"](
            layers["ffn_add1"]([normalized_attention1, contracted1])
        ),
        "training_q5_encoder1",
    )
    encoder1_for_next = keras.layers.GaussianNoise(
        ENCODER_NOISE_STDDEV,
        seed=SEED + 1,
        name="training_encoder1_noise",
    )(encoder1)

    attention2 = training_q5(
        layers["attention2"](encoder1_for_next, encoder1_for_next),
        "training_q5_attention2",
    )
    residual2 = training_q5(
        layers["attention_add2"]([encoder1_for_next, attention2]),
        "training_q5_attention_add2",
    )
    normalized_attention2 = training_q5(
        layers["attention_norm2"](residual2),
        "training_q5_attention_norm2",
    )
    hidden2 = training_q5(
        layers["expand2"](normalized_attention2),
        "training_q5_expand2",
    )
    contracted2 = training_q5(
        layers["contract2"](hidden2),
        "training_q5_contract2",
    )
    encoder2 = training_q5(
        layers["ffn_norm2"](
            layers["ffn_add2"]([normalized_attention2, contracted2])
        ),
        "training_q5_encoder2",
    )
    encoder2_for_classifier = keras.layers.GaussianNoise(
        ENCODER_NOISE_STDDEV,
        seed=SEED + 2,
        name="training_encoder2_noise",
    )(encoder2)
    return training_q5(
        layers["classifier"](encoder2_for_classifier),
        "training_q5_logits",
    )


def training_model(
    layers: dict[str, keras.layers.Layer],
) -> keras.Model:
    words = keras.Input(
        shape=(TOKENS, WIDTH), dtype="float32", name="training_words"
    )
    positions = keras.Input(
        shape=(TOKENS, WIDTH), dtype="float32", name="training_positions"
    )
    _, _, logits = apply_network(layers, words, positions)
    return keras.Model(
        {
            "training_words": words,
            "training_positions": positions,
        },
        logits,
        name="transformer_training_model",
    )


def q5_training_model(
    layers: dict[str, keras.layers.Layer],
) -> keras.Model:
    words = keras.Input(
        shape=(TOKENS, WIDTH), dtype="float32", name="q5_training_words"
    )
    positions = keras.Input(
        shape=(TOKENS, WIDTH),
        dtype="float32",
        name="q5_training_positions",
    )
    logits = apply_q5_training_network(layers, words, positions)
    return keras.Model(
        {
            "q5_training_words": words,
            "q5_training_positions": positions,
        },
        logits,
        name="transformer_q5_training_model",
    )


def use_uniform_attention_scores(
    layers: dict[str, keras.layers.Layer],
) -> None:
    """Keep Q and K at zero so every valid score row has uniform weights."""

    for name in ("attention1", "attention2"):
        attention = layers[name]
        query_dense = attention.query_dense
        key_dense = attention.key_dense
        query_dense.kernel.assign(tf.zeros_like(query_dense.kernel))
        key_dense.kernel.assign(tf.zeros_like(key_dense.kernel))
        query_dense.trainable = False
        key_dense.trainable = False


def inference_model(
    layers: dict[str, keras.layers.Layer],
) -> keras.Model:
    words = keras.Input(
        batch_shape=(1, TOKENS, WIDTH),
        dtype="float32",
        name="word_features",
    )
    positions = keras.Input(
        batch_shape=(1, TOKENS, WIDTH),
        dtype="float32",
        name="position_features",
    )
    probe1, probe2, logits = apply_network(layers, words, positions)
    return keras.Model(
        [words, positions],
        [probe1, probe2, logits],
        name="keras_two_encoder_intent_classifier",
    )


def predict_fixed_batch(
    model: keras.Model,
    words: np.ndarray,
    positions: np.ndarray,
) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
    outputs: list[list[np.ndarray]] = [[], [], []]
    for sample in range(words.shape[0]):
        result = model(
            [words[sample : sample + 1], positions[sample : sample + 1]],
            training=False,
        )
        for index, tensor in enumerate(result):
            outputs[index].append(np.asarray(tensor.numpy()))
    return tuple(np.concatenate(items, axis=0) for items in outputs)  # type: ignore[return-value]


def sentence_score_matrix(
    logits: np.ndarray, valid_lengths: np.ndarray
) -> np.ndarray:
    result = np.zeros((logits.shape[0], CLASSES), dtype=np.float64)
    for sample, length_value in enumerate(valid_lengths):
        length = int(length_value)
        result[sample] = np.mean(logits[sample, :length], axis=0)
    return result


def classification_accuracy(
    logits: np.ndarray,
    valid_lengths: np.ndarray,
    labels: np.ndarray,
) -> float:
    predicted = np.argmax(
        sentence_score_matrix(logits, valid_lengths), axis=1
    )
    return float(np.mean(predicted == labels))


def top1_margins(
    logits: np.ndarray, valid_lengths: np.ndarray
) -> np.ndarray:
    scores = sentence_score_matrix(logits, valid_lengths)
    ordered = np.sort(scores, axis=1)
    return ordered[:, -1] - ordered[:, -2]


def distribution(values: np.ndarray) -> dict[str, float | int]:
    real = np.asarray(values, dtype=np.float64).reshape(-1)
    encoded = fixed(real).reshape(-1)
    return {
        "minimum": float(np.min(real)),
        "maximum": float(np.max(real)),
        "mean": float(np.mean(real)),
        "stddev": float(np.std(real)),
        "near_tanh_limit_count": int(np.count_nonzero(np.abs(real) >= 0.95)),
        "near_tanh_limit_ratio": float(np.mean(np.abs(real) >= 0.95)),
        "int8_extreme_count": int(
            np.count_nonzero((encoded == -128) | (encoded == 127))
        ),
        "int8_extreme_ratio": float(
            np.mean((encoded == -128) | (encoded == 127))
        ),
        "int8_minimum": int(np.min(encoded)),
        "int8_maximum": int(np.max(encoded)),
        "int8_unique_values": int(np.unique(encoded).size),
    }


def validate_output_distributions(
    probe1: np.ndarray,
    probe2: np.ndarray,
    logits: np.ndarray,
    valid_lengths: np.ndarray,
) -> dict[str, dict[str, float | int]]:
    result = {
        "encoder1_probe": distribution(probe1),
        "encoder2_probe": distribution(probe2),
        "intent_logits": distribution(logits),
    }
    for name, stats in result.items():
        if float(stats["int8_extreme_ratio"]) > 0.01:
            raise RuntimeError(f"{name} has too many INT8 extreme values")
        if int(stats["int8_unique_values"]) < 16:
            raise RuntimeError(f"{name} uses too few distinct INT8 values")
        if float(stats["stddev"]) < 0.08:
            raise RuntimeError(f"{name} output variation is too small")
    logit_stats = result["intent_logits"]
    if float(logit_stats["near_tanh_limit_ratio"]) > 0.35:
        raise RuntimeError("too many final logits have abs(value) >= 0.95")
    margins = top1_margins(logits, valid_lengths)
    if float(np.min(margins)) < 0.12:
        raise RuntimeError(
            f"small held-out top-1 margin: {float(np.min(margins))}"
        )
    return result


def weight_range(model: keras.Model) -> tuple[float, float]:
    arrays = [
        np.asarray(weight, dtype=np.float64).reshape(-1)
        for weight in model.get_weights()
    ]
    flat = np.concatenate(arrays)
    return float(np.min(flat)), float(np.max(flat))


def snap_model_weights_to_q5(model: keras.Model) -> dict[str, float | int]:
    original = [
        np.asarray(value, dtype=np.float32) for value in model.get_weights()
    ]
    snapped = [
        fixed(value).astype(np.float32) * np.float32(SCALE)
        for value in original
    ]
    changed = sum(
        int(np.count_nonzero(before != after))
        for before, after in zip(original, snapped, strict=True)
    )
    values = sum(int(value.size) for value in original)
    largest_adjustment = max(
        float(np.max(np.abs(before - after)))
        for before, after in zip(original, snapped, strict=True)
    )
    model.set_weights(snapped)
    return {
        "values": values,
        "changed_values": changed,
        "largest_adjustment": largest_adjustment,
    }


def stabilize_final_encoder_scale(
    layers: dict[str, keras.layers.Layer],
) -> None:
    """Reserve numerical headroom at the second encoder output."""

    normalization = layers["ffn_norm2"]
    scaled_gamma = (
        fixed(
            np.asarray(normalization.gamma, dtype=np.float32)
            * np.float32(FINAL_NORM_SCALE)
        ).astype(np.float32)
        * np.float32(SCALE)
    )
    normalization.gamma.assign(scaled_gamma)


def c_i8_array(name: str, values: np.ndarray) -> str:
    flat = np.asarray(values, dtype=np.int8).reshape(-1)
    rows = []
    for start in range(0, flat.size, 16):
        rows.append(
            "    "
            + ", ".join(str(int(value)) for value in flat[start : start + 16])
            + ","
        )
    return (
        f"static const int8_t {name}[{flat.size}] = {{\n"
        + "\n".join(rows)
        + "\n};\n"
    )


def c_u8_array(name: str, values: np.ndarray) -> str:
    flat = np.asarray(values, dtype=np.uint8).reshape(-1)
    rows = []
    for start in range(0, flat.size, 20):
        rows.append(
            "    "
            + ", ".join(str(int(value)) for value in flat[start : start + 20])
            + ","
        )
    return (
        f"static const uint8_t {name}[{flat.size}] = {{\n"
        + "\n".join(rows)
        + "\n};\n"
    )


def c_string_array(name: str, values: Sequence[str]) -> str:
    items = ",\n".join(f'    "{value}"' for value in values)
    return (
        f"static const char *const {name}[{len(values)}] = {{\n"
        f"{items}\n"
        "};\n"
    )


def test_header(
    token_ids: np.ndarray,
    valid_lengths: np.ndarray,
    labels: np.ndarray,
    word_q: np.ndarray,
    position_q: np.ndarray,
    probe1_q: np.ndarray,
    probe2_q: np.ndarray,
    logits_q: np.ndarray,
) -> bytes:
    content = (
        "#ifndef KERAS_TRANSFORMER_TEST_DATA_H\n"
        "#define KERAS_TRANSFORMER_TEST_DATA_H\n\n"
        "#include <stdint.h>\n\n"
        f"#define KT_TEST_SAMPLES {labels.size}u\n"
        f"#define KT_TEST_TOKENS {TOKENS}u\n"
        f"#define KT_TEST_WIDTH {WIDTH}u\n"
        f"#define KT_TEST_VOCAB_SIZE {VOCAB_SIZE}u\n"
        f"#define KT_TEST_POSITION_WIDTH {POSITION_WIDTH}u\n"
        f"#define KT_TEST_CLASSES {CLASSES}u\n"
        f"#define KT_TEST_FRACTION_BITS {FRACTION_BITS}u\n"
        "#define KT_PROBE1_ALLOWED_ABS_ERROR 52u\n"
        "#define KT_PROBE2_ALLOWED_ABS_ERROR 30u\n"
        "#define KT_LOGIT_ALLOWED_ABS_ERROR 20u\n\n"
        + c_string_array("kt_vocabulary", VOCABULARY)
        + "\n"
        + c_string_array("kt_token_meanings", TOKEN_MEANINGS)
        + "\n"
        + c_string_array("kt_class_names", CLASS_NAMES)
        + "\n"
        + c_u8_array("kt_test_token_ids", token_ids)
        + "\n"
        + c_u8_array("kt_test_valid_lengths", valid_lengths)
        + "\n"
        + c_u8_array("kt_test_labels", labels)
        + "\n"
        + c_i8_array("kt_test_word_input", word_q)
        + "\n"
        + c_i8_array("kt_test_position_input", position_q)
        + "\n"
        + c_i8_array("kt_test_probe1", probe1_q)
        + "\n"
        + c_i8_array("kt_test_probe2", probe2_q)
        + "\n"
        + c_i8_array("kt_test_logits", logits_q)
        + "\n#endif\n"
    )
    return content.encode("ascii")


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    keras.utils.set_random_seed(SEED)
    tf.config.experimental.enable_op_determinism()

    train_sentences, train_labels = training_corpus()
    test_sentences, test_labels = held_out_corpus()
    if set(train_sentences) & set(test_sentences):
        raise RuntimeError("training and held-out sentence sets overlap")
    train_words, train_positions, _, train_lengths = encode_sentences(
        train_sentences
    )
    test_words, test_positions, test_token_ids, test_lengths = (
        encode_sentences(test_sentences)
    )
    train_target, train_weights = target_scores(
        train_labels, train_lengths
    )
    test_target, test_weights = target_scores(test_labels, test_lengths)
    train_inputs = {
        "training_words": train_words,
        "training_positions": train_positions,
    }
    test_inputs = {
        "training_words": test_words,
        "training_positions": test_positions,
    }

    layers = model_layers()
    trainer = training_model(layers)
    use_uniform_attention_scores(layers)
    trainer.compile(
        optimizer=keras.optimizers.Adam(learning_rate=0.003),
        loss=keras.losses.MeanSquaredError(),
        metrics=[keras.metrics.MeanSquaredError(name="mse")],
    )
    initial_loss, initial_mse = trainer.evaluate(
        train_inputs,
        train_target,
        sample_weight=train_weights,
        batch_size=16,
        verbose=0,
    )
    history = trainer.fit(
        train_inputs,
        train_target,
        sample_weight=train_weights,
        batch_size=16,
        epochs=EPOCHS,
        shuffle=True,
        verbose=0,
    )
    q5_trainer = q5_training_model(layers)
    q5_trainer.compile(
        optimizer=keras.optimizers.Adam(learning_rate=0.001),
        loss=keras.losses.MeanSquaredError(),
        metrics=[keras.metrics.MeanSquaredError(name="mse")],
    )
    q5_train_inputs = {
        "q5_training_words": train_words,
        "q5_training_positions": train_positions,
    }
    q5_history = q5_trainer.fit(
        q5_train_inputs,
        train_target,
        sample_weight=train_weights,
        batch_size=16,
        epochs=Q5_AWARE_EPOCHS,
        shuffle=True,
        verbose=0,
    )
    projection_stats: dict[str, float | int] = {}
    for _ in range(Q5_PROJECTED_EPOCHS):
        q5_trainer.fit(
            q5_train_inputs,
            train_target,
            sample_weight=train_weights,
            batch_size=16,
            epochs=1,
            shuffle=True,
            verbose=0,
        )
        projection_stats = snap_model_weights_to_q5(q5_trainer)
    projection_stats = snap_model_weights_to_q5(q5_trainer)
    stabilize_final_encoder_scale(layers)
    projection_stats = snap_model_weights_to_q5(q5_trainer)
    final_loss, final_mse = trainer.evaluate(
        train_inputs,
        train_target,
        sample_weight=train_weights,
        batch_size=16,
        verbose=0,
    )
    held_out_loss, held_out_mse = trainer.evaluate(
        test_inputs,
        test_target,
        sample_weight=test_weights,
        batch_size=16,
        verbose=0,
    )
    train_logits = np.asarray(
        trainer.predict(train_inputs, verbose=0)
    )
    train_accuracy = classification_accuracy(
        train_logits, train_lengths, train_labels
    )

    exported = inference_model(layers)
    test_probe1, test_probe2, test_logits = predict_fixed_batch(
        exported, test_words, test_positions
    )
    test_accuracy = classification_accuracy(
        test_logits, test_lengths, test_labels
    )
    if train_accuracy < 0.99 or test_accuracy < 0.95:
        raise RuntimeError(
            "training accuracy requirement not met: "
            f"train={train_accuracy} held_out={test_accuracy}"
        )
    smallest_weight, largest_weight = weight_range(exported)
    minimum_weight = -128.0 * SCALE
    maximum_weight = 127.0 * SCALE
    if smallest_weight < minimum_weight or largest_weight > maximum_weight:
        raise RuntimeError(
            f"trained weights do not fit INT8 Q{FRACTION_BITS}: "
            f"[{smallest_weight}, {largest_weight}] is outside "
            f"[{minimum_weight}, {maximum_weight}]"
        )
    distributions = validate_output_distributions(
        test_probe1, test_probe2, test_logits, test_lengths
    )
    margins = top1_margins(test_logits, test_lengths)

    args.model.parent.mkdir(parents=True, exist_ok=True)
    temporary_model = args.model.with_name(
        f".{args.model.stem}.tmp-{os.getpid()}.keras"
    )
    try:
        exported.save(temporary_model, overwrite=True)
        deterministic_keras_archive(temporary_model)
        # A load here checks that normalization preserved a valid Keras file.
        checked = keras.models.load_model(
            temporary_model, compile=False, safe_mode=True
        )
        checked_outputs = predict_fixed_batch(
            checked, test_words[:1], test_positions[:1]
        )
        if not np.allclose(
            checked_outputs[2], test_logits[:1], rtol=0.0, atol=0.0
        ):
            raise RuntimeError("saved Keras model changed inference output")
        os.replace(temporary_model, args.model)
    finally:
        if temporary_model.exists():
            temporary_model.unlink()

    word_q = fixed(test_words)
    position_q = fixed(test_positions)
    probe1_q = fixed(test_probe1)
    probe2_q = fixed(test_probe2)
    logits_q = fixed(test_logits)
    atomic_write(
        args.test_header,
        test_header(
            test_token_ids,
            test_lengths,
            test_labels,
            word_q,
            position_q,
            probe1_q,
            probe2_q,
            logits_q,
        ),
    )

    report = {
        "format_version": 3,
        "task": "four-class variable-word-order room-device command intent classification",
        "tensorflow_version": tf.__version__,
        "keras_version": keras.__version__,
        "model": args.model.name,
        "model_sha256": hashlib.sha256(args.model.read_bytes()).hexdigest(),
        "seed": SEED,
        "epochs": EPOCHS,
        "q5_aware_epochs": Q5_AWARE_EPOCHS,
        "q5_projected_epochs": Q5_PROJECTED_EPOCHS,
        "attention_score_mode": "uniform_zero_query_and_key",
        "final_encoder_norm_scale": FINAL_NORM_SCALE,
        "input_shapes": [[1, TOKENS, WIDTH], [1, TOKENS, WIDTH]],
        "output_shapes": [
            [1, TOKENS, WIDTH],
            [1, TOKENS, WIDTH],
            [1, TOKENS, CLASSES],
        ],
        "fraction_bits": FRACTION_BITS,
        "scale": SCALE,
        "vocabulary": list(VOCABULARY),
        "token_meanings": list(TOKEN_MEANINGS),
        "class_names": list(CLASS_NAMES),
        "training_sentences": [list(item) for item in train_sentences],
        "held_out_sentences": [list(item) for item in test_sentences],
        "held_out_valid_lengths": test_lengths.tolist(),
        "held_out_labels": test_labels.tolist(),
        "word_input_int8": word_q.tolist(),
        "position_input_int8": position_q.tolist(),
        "keras_probe1_float": test_probe1.tolist(),
        "keras_probe1_int8": probe1_q.tolist(),
        "keras_probe2_float": test_probe2.tolist(),
        "keras_probe2_int8": probe2_q.tolist(),
        "keras_logits_float": test_logits.tolist(),
        "keras_logits_int8": logits_q.tolist(),
        "training": {
            "training_samples": len(train_sentences),
            "held_out_samples": len(test_sentences),
            "initial_loss": float(initial_loss),
            "initial_mse": float(initial_mse),
            "history_first_loss": float(history.history["loss"][0]),
            "history_final_loss": float(history.history["loss"][-1]),
            "q5_history_first_loss": float(
                q5_history.history["loss"][0]
            ),
            "q5_history_final_loss": float(
                q5_history.history["loss"][-1]
            ),
            "q5_projection": projection_stats,
            "training_noise_stddev": ENCODER_NOISE_STDDEV,
            "final_loss": float(final_loss),
            "final_mse": float(final_mse),
            "held_out_loss": float(held_out_loss),
            "held_out_mse": float(held_out_mse),
            "training_sentence_accuracy": train_accuracy,
            "held_out_sentence_accuracy": test_accuracy,
            "smallest_weight": smallest_weight,
            "largest_weight": largest_weight,
        },
        "output_distributions": distributions,
        "top1_margin": {
            "minimum": float(np.min(margins)),
            "mean": float(np.mean(margins)),
            "maximum": float(np.max(margins)),
        },
    }
    atomic_write(
        args.report,
        (json.dumps(report, indent=2, sort_keys=True) + "\n").encode("utf-8"),
    )
    logit_stats = distributions["intent_logits"]
    print(
        f"model={args.model} keras={keras.__version__} "
        f"tensorflow={tf.__version__} fit_samples={len(train_sentences)} "
        f"held_out_samples={len(test_sentences)} epochs={EPOCHS} "
        f"q5_aware_epochs={Q5_AWARE_EPOCHS} "
        f"q5_projected_epochs={Q5_PROJECTED_EPOCHS} "
        f"initial_loss={initial_loss:.7f} final_loss={final_loss:.7f} "
        f"train_accuracy={train_accuracy:.7f} "
        f"held_out_accuracy={test_accuracy:.7f}"
    )
    print(
        "Keras_logit_distribution "
        f"min={float(logit_stats['minimum']):.7f} "
        f"max={float(logit_stats['maximum']):.7f} "
        f"mean={float(logit_stats['mean']):.7f} "
        f"std={float(logit_stats['stddev']):.7f} "
        f"abs_ge_0.95={int(logit_stats['near_tanh_limit_count'])}/"
        f"{test_logits.size} "
        f"int8_extreme={int(logit_stats['int8_extreme_count'])}/"
        f"{test_logits.size} "
        f"unique_int8={int(logit_stats['int8_unique_values'])} "
        f"top1_margin_min={float(np.min(margins)):.7f} "
        f"top1_margin_mean={float(np.mean(margins)):.7f}"
    )
    print(
        f"weight_range=[{smallest_weight:.7f},{largest_weight:.7f}] "
        f"model_sha256={report['model_sha256']}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
