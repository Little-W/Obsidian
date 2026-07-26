"""Trusted PyTorch model frontend implemented through an ONNX graph."""

from __future__ import annotations

import tempfile
from pathlib import Path
from typing import Any, Sequence

from .common import FrontendError, FrontendOptions, fixed_shape
from .onnx_frontend import normalize_onnx_model


def _torchscript_input_shapes(
    module: Any,
    options: FrontendOptions,
) -> tuple[list[str], list[tuple[int, ...]]]:
    values = [
        value
        for value in module.graph.inputs()
        if getattr(value.type(), "kind", lambda: "")() == "TensorType"
    ]
    names: list[str] = []
    shapes: list[tuple[int, ...]] = []
    for index, value in enumerate(values):
        name = value.debugName() or f"input_{index}"
        tensor_type = value.type()
        raw_shape: Sequence[int | None] | None = None
        if hasattr(tensor_type, "sizes"):
            raw_shape = tensor_type.sizes()
        if raw_shape is None:
            override = (
                options.input_shapes.get(name)
                or options.input_shapes.get(str(index))
            )
            if override is None:
                raise FrontendError(
                    f"PyTorch input {name!r} has no stored shape; "
                    "use --input-shape"
                )
            raw_shape = override
        shapes.append(
            fixed_shape(
                raw_shape,
                options=options,
                input_name=name,
                input_index=index,
            )
        )
        names.append(name)
    if not shapes:
        raise FrontendError("PyTorch model has no tensor inputs")
    return names, shapes


def _exported_program_input_shapes(
    program: Any,
    options: FrontendOptions,
) -> tuple[list[str], list[tuple[int, ...]]]:
    names: list[str] = []
    shapes: list[tuple[int, ...]] = []
    graph = program.graph_module.graph
    input_index = 0
    for node in graph.nodes:
        if node.op != "placeholder":
            continue
        value = node.meta.get("val")
        if value is None or not hasattr(value, "shape"):
            continue
        name = str(node.name)
        shape = fixed_shape(
            tuple(value.shape),
            options=options,
            input_name=name,
            input_index=input_index,
        )
        names.append(name)
        shapes.append(shape)
        input_index += 1
    if not shapes:
        raise FrontendError(
            "exported PyTorch program has no usable tensor inputs"
        )
    return names, shapes


def _load_trusted_model(
    path: Path,
    options: FrontendOptions,
    torch: Any,
) -> tuple[Any, list[str], list[tuple[int, ...]]]:
    requested = options.pytorch_format
    suffix = path.suffix.lower()
    exported = requested == "exported" or (
        requested == "auto" and suffix == ".pt2"
    )
    if exported:
        export_api = getattr(torch, "export", None)
        if export_api is None or not hasattr(export_api, "load"):
            raise FrontendError(
                "this PyTorch version cannot load .pt2 programs"
            )
        try:
            program = export_api.load(str(path))
        except Exception as error:
            raise FrontendError(
                f"cannot load exported PyTorch program {path}: {error}"
            ) from error
        names, shapes = _exported_program_input_shapes(program, options)
        return program.module(), names, shapes

    try:
        module = torch.jit.load(str(path), map_location="cpu")
    except Exception as error:
        raise FrontendError(
            "PyTorch input must be a saved TorchScript module or a .pt2 "
            "ExportedProgram. A state_dict contains parameters but no "
            f"executable graph. Load failed: {error}"
        ) from error
    names, shapes = _torchscript_input_shapes(module, options)
    return module, names, shapes


def load_pytorch(path: Path, options: FrontendOptions) -> dict[str, Any]:
    """Load a trusted PyTorch graph and normalize it through ONNX."""

    if not options.trust_model:
        raise FrontendError(
            "PyTorch deserialization may execute serialized code; pass "
            "--trust-model only for a model from a trusted source"
        )
    try:
        import onnx
        import torch
    except ImportError as error:
        raise FrontendError(
            "PyTorch import requires both torch and onnx in the active "
            "environment"
        ) from error

    module, input_names, input_shapes = _load_trusted_model(
        path, options, torch
    )
    if hasattr(module, "eval"):
        module.eval()
    dummy_inputs = tuple(
        torch.zeros(shape, dtype=torch.float32, device="cpu")
        for shape in input_shapes
    )
    output_names = ["output_0"]
    try:
        with tempfile.TemporaryDirectory(prefix="npu_torch_onnx_") as temp:
            onnx_path = Path(temp) / "model.onnx"
            with torch.no_grad():
                torch.onnx.export(
                    module,
                    dummy_inputs if len(dummy_inputs) != 1 else dummy_inputs[0],
                    str(onnx_path),
                    export_params=True,
                    opset_version=17,
                    do_constant_folding=True,
                    input_names=input_names,
                    output_names=output_names,
                    dynamic_axes=None,
                    dynamo=False,
                )
            model = onnx.load(str(onnx_path), load_external_data=True)
    except Exception as error:
        raise FrontendError(
            f"cannot export PyTorch graph to ONNX: {error}"
        ) from error
    return normalize_onnx_model(
        model, path, options, source_format="pytorch"
    )


__all__ = ["load_pytorch"]
