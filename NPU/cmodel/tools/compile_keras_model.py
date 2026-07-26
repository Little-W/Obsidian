#!/usr/bin/env python3
"""Compile one known application model into Keras and TFLite artifacts.

This command is intentionally limited to the four deterministic application
models defined by ``export_keras_sequence_fixtures.py``.  It is not a general
Keras graph compiler.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import sys
from pathlib import Path
from typing import Any, Sequence


sys.dont_write_bytecode = True

MODEL_CHOICES = ("transformer", "simple_rnn", "rnn", "gru", "lstm", "all")
MODEL_ORDER = ("transformer", "simple_rnn", "gru", "lstm")
DEFAULT_OUTPUT_DIR = Path("build/model-compiler")


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Compile the repository's deterministic Transformer, SimpleRNN, "
            "GRU, or LSTM application model. Each selected model is saved as "
            "a Keras archive and runnable TFLite file, accompanied by a JSON "
            "manifest."
        ),
        epilog=(
            "Examples:\n"
            "  python tools/compile_keras_model.py --model transformer\n"
            "  python tools/compile_keras_model.py --model rnn "
            "--output-dir /tmp/rnn-build\n"
            "  python tools/compile_keras_model.py --model gru "
            "--output /tmp/device-gru.json\n"
            "  python tools/compile_keras_model.py --model all --check"
        ),
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument(
        "--model",
        required=True,
        choices=MODEL_CHOICES,
        help=(
            "known model to compile; rnn is an alias for simple_rnn, and all "
            "compiles all four models"
        ),
    )
    destination = parser.add_mutually_exclusive_group()
    destination.add_argument(
        "--output",
        type=Path,
        help=(
            "JSON manifest path; sibling artifact names are derived from its "
            "stem (the suffix must be .json)"
        ),
    )
    destination.add_argument(
        "--output-dir",
        type=Path,
        help=(
            "artifact directory; default file names use the normalized model "
            "name"
        ),
    )
    parser.add_argument(
        "--check",
        action="store_true",
        help=(
            "rebuild in memory and verify existing artifacts without writing "
            "files"
        ),
    )
    args = parser.parse_args(argv)
    if args.output is not None and args.output.suffix.lower() != ".json":
        parser.error("--output must name a .json manifest")
    return args


def normalized_selection(requested: str) -> tuple[str, ...]:
    if requested == "all":
        return MODEL_ORDER
    if requested == "rnn":
        return ("simple_rnn",)
    return (requested,)


def resolve_manifest_path(
    args: argparse.Namespace, normalized: tuple[str, ...]
) -> Path:
    if args.output is not None:
        return args.output
    directory = (
        args.output_dir
        if args.output_dir is not None
        else DEFAULT_OUTPUT_DIR
    )
    if directory.exists() and not directory.is_dir():
        raise SystemExit(f"output directory is not a directory: {directory}")
    bundle_name = "all" if len(normalized) > 1 else normalized[0]
    return directory / f"{bundle_name}.json"


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def float_value(value: Any) -> float:
    return float(value)


def tensor_shape(value: Any) -> list[int | None]:
    return [
        None if dimension is None else int(dimension)
        for dimension in tuple(value.shape)
    ]


def keras_tensor_metadata(value: Any) -> dict[str, Any]:
    return {
        "name": str(value.name),
        "shape": tensor_shape(value),
        "dtype": str(value.dtype),
    }


def tflite_tensor_metadata(detail: dict[str, Any]) -> dict[str, Any]:
    import numpy as np

    parameters = detail["quantization_parameters"]
    scales = np.asarray(parameters["scales"], dtype=np.float32)
    zero_points = np.asarray(
        parameters["zero_points"], dtype=np.int64
    )
    return {
        "name": str(detail["name"]),
        "shape": [
            int(value) for value in np.asarray(detail["shape"]).tolist()
        ],
        "shape_signature": [
            int(value)
            for value in np.asarray(
                detail["shape_signature"]
            ).tolist()
        ],
        "dtype": np.dtype(detail["dtype"]).name,
        "scales": [float(value) for value in scales.tolist()],
        "zero_points": [int(value) for value in zero_points.tolist()],
        "axis": int(parameters["quantized_dimension"]),
    }


def tflite_io_metadata(
    exporter: Any, content: bytes
) -> tuple[list[dict[str, Any]], list[dict[str, Any]]]:
    interpreter = exporter.tf.lite.Interpreter(model_content=content)
    interpreter.allocate_tensors()
    inputs = [
        tflite_tensor_metadata(detail)
        for detail in interpreter.get_input_details()
    ]
    outputs = [
        tflite_tensor_metadata(detail)
        for detail in interpreter.get_output_details()
    ]
    return inputs, outputs


def build_selected_fixtures(
    exporter: Any, names: tuple[str, ...]
) -> dict[str, Any]:
    result: dict[str, Any] = {}
    if "transformer" in names:
        result["transformer"] = exporter.build_transformer()
    recurrent_names = [
        name for name in names if name != "transformer"
    ]
    if recurrent_names:
        fixed_input = exporter.recurrent_input()
        training_input, training_target = (
            exporter.recurrent_training_corpus()
        )
        builders = {
            "simple_rnn": exporter.build_simple_rnn,
            "gru": exporter.build_gru,
            "lstm": exporter.build_lstm,
        }
        for name in recurrent_names:
            result[name] = builders[name](
                fixed_input, training_input, training_target
            )
    return result


def fixture_inference_data(
    exporter: Any, name: str, fixture: Any
) -> tuple[dict[str, Any], Any, Any]:
    import numpy as np

    if name == "transformer":
        named_inputs = {
            "token_ids": fixture.token_ids,
            "position_ids": fixture.position_ids,
        }
        model_inputs: Any = [
            fixture.token_ids,
            fixture.position_ids,
        ]
        expected = np.asarray(
            fixture.model(model_inputs, training=False).numpy(),
            dtype=np.float32,
        )

        def validate(output: Any) -> None:
            exporter.require_transformer_predictions(
                output, fixture.fixed_labels
            )

        return named_inputs, expected, validate

    named_inputs = {"sequence": fixture.inputs}
    expected = np.asarray(
        fixture.model(fixture.inputs, training=False).numpy(),
        dtype=np.float32,
    )

    def validate(output: Any) -> None:
        exporter.require_recurrent_history_response(
            output, name, fixture.targets
        )

    return named_inputs, expected, validate


def compile_tflite(
    exporter: Any, name: str, fixture: Any
) -> tuple[bytes, Any, dict[str, Any]]:
    named_inputs, expected, validator = fixture_inference_data(
        exporter, name, fixture
    )
    report = exporter.probe_tflite(
        name,
        fixture.model,
        fixture.representative,
        named_inputs,
        expected,
        exporter.TFLITE_MAX_ABS_ERROR_LIMITS[name],
        False,
        validator,
    )
    if report.status == exporter.TFLITE_STRICT_INT8:
        strict = True
    elif report.status == exporter.TFLITE_FALLBACK:
        strict = False
    else:
        raise RuntimeError(
            f"{name} did not produce a runnable TFLite artifact: "
            f"{report.note}"
        )
    content = exporter.converter_for(
        fixture.model, fixture.representative, strict=strict
    ).convert()
    quantized, floating = exporter.interpreter_inventory(content)
    error = exporter.tflite_max_abs_error(
        content, named_inputs, expected, validator
    )
    if float(error) > float(report.max_abs_error_limit):
        raise RuntimeError(
            f"{name} saved TFLite error {float(error):.9g} exceeds "
            f"{float(report.max_abs_error_limit):.9g}"
        )
    if (
        quantized != report.quantized_tensors
        or floating != report.float_tensors
    ):
        raise RuntimeError(
            f"{name} repeated TFLite conversion changed tensor inventory"
        )
    inputs, outputs = tflite_io_metadata(exporter, content)
    metadata = {
        "status": int(report.status),
        "conversion": (
            "strict_builtin_int8"
            if strict
            else "builtin_or_select_tf_ops_fallback"
        ),
        "quantized_tensors": int(quantized),
        "float_tensors": int(floating),
        "max_abs_error": float(error),
        "max_abs_error_limit": float(report.max_abs_error_limit),
        "note": str(report.note),
        "inputs": inputs,
        "outputs": outputs,
    }
    return content, report, metadata


def model_metrics(
    exporter: Any, name: str, fixture: Any
) -> dict[str, Any]:
    import numpy as np

    if name == "transformer":
        logits = np.asarray(
            fixture.model(
                [fixture.token_ids, fixture.position_ids],
                training=False,
            ).numpy(),
            dtype=np.float32,
        )
        texts = [
            " ".join(
                exporter.TRANSFORMER_TOKEN_NAMES[int(token)]
                for token in row
                if int(token) != 0
            )
            for row in fixture.token_ids
        ]
        return {
            "task": "short_text_classification",
            "training_steps": int(fixture.training.steps),
            "training_cross_entropy_initial": float_value(
                fixture.training.initial_loss
            ),
            "training_cross_entropy_final": float_value(
                fixture.training.final_loss
            ),
            "training_accuracy": float_value(
                fixture.training_accuracy
            ),
            "fixed_accuracy": float_value(fixture.fixed_accuracy),
            "class_names": list(exporter.TRANSFORMER_CLASS_NAMES),
            "token_names": list(exporter.TRANSFORMER_TOKEN_NAMES),
            "fixed_texts": texts,
            "token_ids": fixture.token_ids.tolist(),
            "position_ids": fixture.position_ids.tolist(),
            "true_classes": fixture.fixed_labels.tolist(),
            "predicted_classes": fixture.fixed_predictions.tolist(),
            "keras_logits": logits.tolist(),
        }
    prediction = np.asarray(
        fixture.model(fixture.inputs, training=False).numpy(),
        dtype=np.float32,
    )
    return {
        "task": "device_telemetry_time_dependent_regression",
        "training_steps": int(fixture.training.steps),
        "training_mse_initial": float_value(
            fixture.training.initial_loss
        ),
        "training_mse_final": float_value(
            fixture.training.final_loss
        ),
        "application_mse": float_value(fixture.application_mse),
        "final_step_mse": float_value(fixture.final_step_mse),
        "history_baseline_mse": float_value(
            fixture.history_baseline_mse
        ),
        "same_current_baseline_mse": float_value(
            fixture.same_current_baseline_mse
        ),
        "accuracy": None,
        "accuracy_note": "not applicable to regression",
        "input_feature_names": [
            "normalized_current_temperature",
            "normalized_current_load",
            "daily_phase_sine",
        ],
        "output_names": [
            "smoothed_next_temperature",
            "smoothed_next_load",
            "next_temperature_trend",
        ],
        "fixed_input": fixture.inputs.tolist(),
        "target": fixture.targets.tolist(),
        "keras_prediction": prediction.tolist(),
    }


def model_file_paths(
    manifest_path: Path, names: tuple[str, ...]
) -> dict[str, dict[str, Path]]:
    stem = manifest_path.stem
    result: dict[str, dict[str, Path]] = {}
    for name in names:
        prefix = stem if len(names) == 1 else f"{stem}_{name}"
        result[name] = {
            "keras": manifest_path.with_name(f"{prefix}.keras"),
            "tflite": manifest_path.with_name(f"{prefix}.tflite"),
        }
    return result


def atomic_write_bytes(path: Path, content: bytes) -> None:
    temporary = path.with_name(f".{path.name}.tmp-{os.getpid()}")
    try:
        temporary.write_bytes(content)
        os.replace(temporary, path)
    finally:
        if temporary.exists():
            temporary.unlink()


def save_keras_model(model: Any, path: Path) -> None:
    temporary = path.with_name(
        f".{path.stem}.tmp-{os.getpid()}.keras"
    )
    try:
        model.save(temporary, overwrite=True)
        os.replace(temporary, path)
    finally:
        if temporary.exists():
            temporary.unlink()


def verify_keras_model(
    exporter: Any, path: Path, name: str, fixture: Any
) -> None:
    import numpy as np

    loaded = exporter.keras.models.load_model(path, compile=False)
    if len(loaded.weights) != len(fixture.model.weights):
        raise RuntimeError(f"Keras weight count differs: {path}")
    for index, (actual, expected) in enumerate(
        zip(loaded.get_weights(), fixture.model.get_weights())
    ):
        if not np.array_equal(actual, expected):
            raise RuntimeError(
                f"Keras weight {index} differs: {path}"
            )
    if name == "transformer":
        inputs: Any = [fixture.token_ids, fixture.position_ids]
    else:
        inputs = fixture.inputs
    actual_output = np.asarray(
        loaded(inputs, training=False).numpy(), dtype=np.float32
    )
    expected_output = np.asarray(
        fixture.model(inputs, training=False).numpy(), dtype=np.float32
    )
    if not np.array_equal(actual_output, expected_output):
        difference = float(
            np.max(
                np.abs(
                    actual_output.astype(np.float64)
                    - expected_output.astype(np.float64)
                )
            )
        )
        raise RuntimeError(
            f"Keras output differs by {difference:.9g}: {path}"
        )


def build_manifest(
    exporter: Any,
    requested: str,
    names: tuple[str, ...],
    fixtures: dict[str, Any],
    tflite_metadata: dict[str, dict[str, Any]],
    file_paths: dict[str, dict[str, Path]],
) -> dict[str, Any]:
    models: list[dict[str, Any]] = []
    for name in names:
        paths = file_paths[name]
        fixture = fixtures[name]
        models.append(
            {
                "name": name,
                "keras": {
                    "file": paths["keras"].name,
                    "sha256": sha256_file(paths["keras"]),
                    "inputs": [
                        keras_tensor_metadata(value)
                        for value in fixture.model.inputs
                    ],
                    "outputs": [
                        keras_tensor_metadata(value)
                        for value in fixture.model.outputs
                    ],
                },
                "tflite": {
                    "file": paths["tflite"].name,
                    "sha256": sha256_file(paths["tflite"]),
                    **tflite_metadata[name],
                },
                "metrics": model_metrics(exporter, name, fixture),
            }
        )
    return {
        "format_version": 1,
        "compiler_scope": (
            "known deterministic application models in "
            "export_keras_sequence_fixtures.py"
        ),
        "requested_model": requested,
        "compiled_models": list(names),
        "seed": int(exporter.SEED),
        "tensorflow_version": str(exporter.tf.__version__),
        "keras_version": str(exporter.keras.__version__),
        "c_inference_fixture": {
            "generated_by_this_command": False,
            "canonical_path": (
                "tests/generated/keras_sequence_fixtures.h"
            ),
            "note": (
                "The C runner uses the separately generated checked-in "
                "fixture header."
            ),
        },
        "models": models,
    }


def verify_existing_tflite(
    exporter: Any,
    path: Path,
    name: str,
    fixture: Any,
    expected_report: Any,
) -> dict[str, Any]:
    content = path.read_bytes()
    named_inputs, expected, validator = fixture_inference_data(
        exporter, name, fixture
    )
    quantized, floating = exporter.interpreter_inventory(content)
    error = exporter.tflite_max_abs_error(
        content, named_inputs, expected, validator
    )
    if float(error) > float(expected_report.max_abs_error_limit):
        raise RuntimeError(
            f"existing TFLite artifact exceeds error limit: {path}"
        )
    inputs, outputs = tflite_io_metadata(exporter, content)
    return {
        "status": int(expected_report.status),
        "conversion": (
            "strict_builtin_int8"
            if expected_report.status == exporter.TFLITE_STRICT_INT8
            else "builtin_or_select_tf_ops_fallback"
        ),
        "quantized_tensors": int(quantized),
        "float_tensors": int(floating),
        "max_abs_error": float(error),
        "max_abs_error_limit": float(
            expected_report.max_abs_error_limit
        ),
        "note": str(expected_report.note),
        "inputs": inputs,
        "outputs": outputs,
    }


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    names = normalized_selection(args.model)
    manifest_path = resolve_manifest_path(args, names)
    if manifest_path.exists() and manifest_path.is_dir():
        raise SystemExit(
            f"manifest path is a directory: {manifest_path}"
        )

    tool_directory = Path(__file__).resolve().parent
    sys.path.insert(0, str(tool_directory))
    import export_keras_sequence_fixtures as exporter

    exporter.configure_determinism()
    fixtures = build_selected_fixtures(exporter, names)
    reports: dict[str, Any] = {}
    tflite_content: dict[str, bytes] = {}
    generated_tflite_metadata: dict[str, dict[str, Any]] = {}
    for name in names:
        content, report, metadata = compile_tflite(
            exporter, name, fixtures[name]
        )
        reports[name] = report
        tflite_content[name] = content
        generated_tflite_metadata[name] = metadata
    artifact_tflite_metadata = generated_tflite_metadata

    file_paths = model_file_paths(manifest_path, names)

    expected_paths = [manifest_path]
    for paths in file_paths.values():
        expected_paths.extend([paths["keras"], paths["tflite"]])

    if args.check:
        missing = [path for path in expected_paths if not path.is_file()]
        if missing:
            raise SystemExit(
                "missing compiled artifact(s): "
                + ", ".join(str(path) for path in missing)
            )
        checked_tflite_metadata: dict[str, dict[str, Any]] = {}
        for name in names:
            verify_keras_model(
                exporter,
                file_paths[name]["keras"],
                name,
                fixtures[name],
            )
            checked_tflite_metadata[name] = verify_existing_tflite(
                exporter,
                file_paths[name]["tflite"],
                name,
                fixtures[name],
                reports[name],
            )
        artifact_tflite_metadata = checked_tflite_metadata
        expected_manifest = build_manifest(
            exporter,
            args.model,
            names,
            fixtures,
            checked_tflite_metadata,
            file_paths,
        )
        current_manifest = json.loads(
            manifest_path.read_text(encoding="utf-8")
        )
        if current_manifest != expected_manifest:
            raise SystemExit(f"manifest differs: {manifest_path}")
    else:
        manifest_path.parent.mkdir(parents=True, exist_ok=True)
        for name in names:
            save_keras_model(
                fixtures[name].model, file_paths[name]["keras"]
            )
            atomic_write_bytes(
                file_paths[name]["tflite"], tflite_content[name]
            )
        manifest = build_manifest(
            exporter,
            args.model,
            names,
            fixtures,
            generated_tflite_metadata,
            file_paths,
        )
        manifest_content = (
            json.dumps(
                manifest,
                indent=2,
                sort_keys=True,
                ensure_ascii=True,
                allow_nan=False,
            )
            + "\n"
        ).encode("utf-8")
        atomic_write_bytes(manifest_path, manifest_content)

    action = "verified" if args.check else "wrote"
    print(
        f"TensorFlow={exporter.tf.__version__} "
        f"Keras={exporter.keras.__version__}"
    )
    print(f"models={','.join(names)}")
    for path in expected_paths:
        print(f"{action}={path} sha256={sha256_file(path)}")
    for name in names:
        metadata = artifact_tflite_metadata[name]
        print(
            f"{name}: tflite_status={metadata['status']} "
            f"max_abs_error="
            f"{metadata['max_abs_error']:.9g} "
            f"max_abs_error_limit="
            f"{metadata['max_abs_error_limit']:.9g}"
        )
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, RuntimeError, ValueError) as error:
        raise SystemExit(f"model compiler failed: {error}") from error
