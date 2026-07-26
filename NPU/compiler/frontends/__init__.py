"""Direct framework model importers for the NPU high-level compiler."""

from __future__ import annotations

from pathlib import Path
from typing import Any, Mapping

from .common import FrontendError, FrontendOptions, parse_input_shapes


FORMAT_SUFFIXES = {
    ".json": "json",
    ".keras": "keras",
    ".h5": "keras",
    ".hdf5": "keras",
    ".tflite": "tflite",
    ".onnx": "onnx",
    ".pt": "pytorch",
    ".pth": "pytorch",
    ".pt2": "pytorch",
    ".ts": "pytorch",
    ".torchscript": "pytorch",
}


def detect_format(path: Path, requested: str = "auto") -> str:
    if requested != "auto":
        return requested
    suffix = path.suffix.lower()
    if suffix not in FORMAT_SUFFIXES:
        raise FrontendError(
            f"cannot infer model format from {path.name!r}; "
            "use --input-format"
        )
    return FORMAT_SUFFIXES[suffix]


def options_from_namespace(namespace: Any) -> FrontendOptions:
    return FrontendOptions(
        input_format=str(namespace.input_format),
        dtype=str(namespace.model_dtype).lower(),
        fraction_bits=int(namespace.fraction_bits),
        batch_size=int(namespace.batch_size),
        input_shapes=parse_input_shapes(namespace.input_shape),
        trust_model=bool(namespace.trust_model),
        pytorch_format=str(namespace.pytorch_format),
    )


def load_framework_document(
    path: Path,
    options: FrontendOptions,
) -> Mapping[str, Any]:
    model_format = detect_format(path, options.input_format)
    if model_format == "keras":
        from .keras_frontend import load_keras

        return load_keras(path, options)
    if model_format == "tflite":
        from .tflite_frontend import load_tflite

        return load_tflite(path, options)
    if model_format == "onnx":
        from .onnx_frontend import load_onnx

        return load_onnx(path, options)
    if model_format == "pytorch":
        from .pytorch_frontend import load_pytorch

        return load_pytorch(path, options)
    raise FrontendError(f"{model_format!r} is not a framework model format")


__all__ = [
    "FrontendError",
    "FrontendOptions",
    "detect_format",
    "load_framework_document",
    "options_from_namespace",
]
