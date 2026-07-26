"""Shared fixed-point graph builder for framework model frontends."""

from __future__ import annotations

import math
import re
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Iterable, Mapping, Sequence

import numpy as np


DTYPE_LIMITS = {
    "int4": (-8, 7),
    "int8": (-128, 127),
    "int16": (-32768, 32767),
    "int32": (-2147483648, 2147483647),
}


class FrontendError(ValueError):
    """Framework import or normalization error."""


@dataclass(frozen=True)
class FrontendOptions:
    """Options shared by all framework importers."""

    input_format: str = "auto"
    dtype: str = "int8"
    fraction_bits: int = 6
    batch_size: int = 1
    input_shapes: Mapping[str, tuple[int, ...]] = field(default_factory=dict)
    trust_model: bool = False
    pytorch_format: str = "auto"

    def __post_init__(self) -> None:
        if self.dtype not in ("int4", "int8", "int16"):
            raise FrontendError(
                "framework import supports int4, int8, or int16 model data"
            )
        if self.fraction_bits < 0 or self.fraction_bits > 30:
            raise FrontendError("fraction_bits must be in 0..30")
        if self.batch_size <= 0:
            raise FrontendError("batch_size must be positive")
        minimum, maximum = DTYPE_LIMITS[self.dtype]
        if (1 << self.fraction_bits) > max(abs(minimum), abs(maximum)):
            raise FrontendError(
                f"fraction_bits={self.fraction_bits} leaves no integer range "
                f"for {self.dtype}"
            )

    @property
    def scale(self) -> float:
        return math.ldexp(1.0, -self.fraction_bits)


def clean_name(value: str, fallback: str = "tensor") -> str:
    """Return a stable high-level IR identifier."""

    text = re.sub(r"[^0-9A-Za-z_]+", "_", value).strip("_")
    if not text:
        text = fallback
    if text[0].isdigit():
        text = f"n_{text}"
    return text


def parse_input_shapes(values: Sequence[str] | None) -> dict[str, tuple[int, ...]]:
    """Parse repeatable NAME=D0,D1 or D0,D1 command-line values."""

    result: dict[str, tuple[int, ...]] = {}
    for index, value in enumerate(values or ()):
        if "=" in value:
            name, dimensions_text = value.split("=", 1)
            name = name.strip()
            if not name:
                raise FrontendError(f"input shape {value!r} has an empty name")
        else:
            name = str(index)
            dimensions_text = value
        try:
            dimensions = tuple(
                int(item.strip(), 0)
                for item in dimensions_text.split(",")
                if item.strip()
            )
        except ValueError as error:
            raise FrontendError(
                f"input shape {value!r} contains a non-integer dimension"
            ) from error
        if not dimensions or any(item <= 0 for item in dimensions):
            raise FrontendError(
                f"input shape {value!r} must contain positive dimensions"
            )
        if name in result:
            raise FrontendError(f"input shape {name!r} is specified twice")
        result[name] = dimensions
    return result


def fixed_shape(
    raw_shape: Iterable[Any],
    *,
    options: FrontendOptions,
    input_name: str,
    input_index: int,
) -> tuple[int, ...]:
    """Resolve a framework shape to positive static dimensions."""

    override = options.input_shapes.get(input_name)
    if override is None:
        override = options.input_shapes.get(clean_name(input_name))
    if override is None:
        override = options.input_shapes.get(str(input_index))
    if override is not None:
        return tuple(override)
    result: list[int] = []
    for dimension_index, value in enumerate(raw_shape):
        if hasattr(value, "value"):
            value = value.value
        if value is None or int(value) < 0:
            if dimension_index == 0:
                result.append(options.batch_size)
            else:
                raise FrontendError(
                    f"input {input_name!r} has a dynamic dimension at "
                    f"index {dimension_index}; use --input-shape"
                )
        else:
            parsed = int(value)
            if parsed <= 0:
                raise FrontendError(
                    f"input {input_name!r} has invalid dimension {parsed}"
                )
            result.append(parsed)
    if not result:
        raise FrontendError(f"input {input_name!r} has an empty shape")
    return tuple(result)


def dequantize_array(
    values: Any,
    scales: Sequence[float] | np.ndarray | None = None,
    zero_points: Sequence[int] | np.ndarray | None = None,
    axis: int = 0,
) -> np.ndarray:
    """Convert a framework tensor to real-valued float64 data."""

    array = np.asarray(values)
    if scales is None or len(scales) == 0:
        return array.astype(np.float64)
    scale_array = np.asarray(scales, dtype=np.float64)
    zero_array = np.asarray(
        zero_points if zero_points is not None else np.zeros_like(scale_array),
        dtype=np.float64,
    )
    if scale_array.size == 1:
        return (
            array.astype(np.float64) - float(zero_array.reshape(-1)[0])
        ) * float(scale_array.reshape(-1)[0])
    if axis < 0:
        axis += array.ndim
    if axis < 0 or axis >= array.ndim or scale_array.size != array.shape[axis]:
        raise FrontendError("per-axis scale does not match the tensor shape")
    shape = [1] * array.ndim
    shape[axis] = scale_array.size
    return (
        array.astype(np.float64) - zero_array.reshape(shape)
    ) * scale_array.reshape(shape)


class GraphBuilder:
    """Build the compiler's framework-neutral high-level JSON document."""

    def __init__(
        self,
        model_name: str,
        source_format: str,
        source_path: Path,
        options: FrontendOptions,
    ) -> None:
        self.model_name = clean_name(model_name, "framework_model")
        self.source_format = source_format
        self.source_path = source_path
        self.options = options
        self.inputs: list[dict[str, Any]] = []
        self.constants: list[dict[str, Any]] = []
        self.operators: list[dict[str, Any]] = []
        self.outputs: list[str] = []
        self.shapes: dict[str, tuple[int, ...]] = {}
        self._names: set[str] = set()

    @property
    def scale(self) -> float:
        return self.options.scale

    def unique(self, value: str, fallback: str = "tensor") -> str:
        base = clean_name(value, fallback)
        candidate = base
        index = 1
        while candidate in self._names:
            candidate = f"{base}_{index}"
            index += 1
        self._names.add(candidate)
        return candidate

    def add_input(self, name: str, shape: Sequence[int]) -> str:
        tensor = self.unique(name, "input")
        normalized = tuple(int(item) for item in shape)
        self.inputs.append(
            {
                "name": tensor,
                "shape": list(normalized),
                "dtype": self.options.dtype,
                "scale": self.scale,
            }
        )
        self.shapes[tensor] = normalized
        return tensor

    def quantize(
        self,
        values: Any,
        *,
        dtype: str | None = None,
        scale: float | None = None,
    ) -> np.ndarray:
        target_dtype = dtype or self.options.dtype
        target_scale = self.scale if scale is None else float(scale)
        if not math.isfinite(target_scale) or target_scale <= 0.0:
            raise FrontendError("constant scale must be finite and positive")
        minimum, maximum = DTYPE_LIMITS[target_dtype]
        array = np.asarray(values, dtype=np.float64)
        if not np.all(np.isfinite(array)):
            raise FrontendError("constant contains NaN or infinity")
        rounded = np.rint(array / target_scale)
        if np.any(rounded < minimum) or np.any(rounded > maximum):
            smallest = float(np.min(array))
            largest = float(np.max(array))
            raise FrontendError(
                f"constant real-value range [{smallest}, {largest}] cannot "
                f"be stored as {target_dtype} with scale {target_scale}"
            )
        return rounded.astype(np.int64)

    def add_constant(
        self,
        name: str,
        values: Any,
        *,
        dtype: str | None = None,
        scale: float | None = None,
    ) -> str:
        array = np.asarray(values)
        if array.ndim == 0:
            array = array.reshape((1,))
        target_dtype = dtype or self.options.dtype
        target_scale = self.scale if scale is None else float(scale)
        quantized = self.quantize(
            array, dtype=target_dtype, scale=target_scale
        )
        tensor = self.unique(name, "constant")
        self.constants.append(
            {
                "name": tensor,
                "shape": list(array.shape),
                "dtype": target_dtype,
                "scale": target_scale,
                "data": [int(item) for item in quantized.reshape(-1)],
            }
        )
        self.shapes[tensor] = tuple(int(item) for item in array.shape)
        return tensor

    def add_operator(
        self,
        name: str,
        op_type: str,
        inputs: Sequence[str],
        outputs: Sequence[str],
        *,
        attributes: Mapping[str, Any] | None = None,
        output_shapes: Sequence[Sequence[int]] | None = None,
    ) -> tuple[str, ...]:
        operator = self.unique(name, "operator")
        output_names = tuple(self.unique(item, "tensor") for item in outputs)
        self.operators.append(
            {
                "name": operator,
                "type": op_type,
                "inputs": list(inputs),
                "outputs": list(output_names),
                "attributes": dict(attributes or {}),
            }
        )
        if output_shapes is not None:
            if len(output_shapes) != len(output_names):
                raise FrontendError("operator output shape count does not match")
            for output, shape in zip(output_names, output_shapes):
                self.shapes[output] = tuple(int(item) for item in shape)
        return output_names

    def add_linear(
        self,
        name: str,
        source: str,
        kernel: Any,
        bias: Any | None,
        *,
        output_name: str,
    ) -> str:
        source_shape = self.shapes[source]
        matrix = np.asarray(kernel, dtype=np.float64)
        if matrix.ndim != 2 or matrix.shape[0] != source_shape[-1]:
            raise FrontendError(
                f"{name}: linear kernel must be "
                f"[{source_shape[-1]}, output_features]"
            )
        prefix = source_shape[:-1]
        rows = math.prod(prefix) if prefix else 1
        width = source_shape[-1]
        columns = int(matrix.shape[1])
        current = source
        if len(source_shape) != 2:
            current = self.add_operator(
                f"{name}_flatten",
                "Reshape",
                [current],
                [f"{name}_flat_input"],
                attributes={"shape": [rows, width]},
                output_shapes=[(rows, width)],
            )[0]
        weight = self.add_constant(f"{name}_weight", matrix)
        current = self.add_operator(
            f"{name}_matmul",
            "MatMul",
            [current, weight],
            [f"{name}_matmul_output"],
            attributes={
                "output_shift": self.options.fraction_bits,
                "output_dtype": self.options.dtype,
            },
            output_shapes=[(rows, columns)],
        )[0]
        if bias is not None:
            bias_array = np.asarray(bias, dtype=np.float64).reshape(-1)
            if bias_array.size != columns:
                raise FrontendError(
                    f"{name}: bias must contain {columns} values"
                )
            bias_tensor = self.add_constant(f"{name}_bias", bias_array)
            current = self.add_operator(
                f"{name}_bias_add",
                "Add",
                [current, bias_tensor],
                [f"{name}_biased"],
                attributes={"scale": self.scale},
                output_shapes=[(rows, columns)],
            )[0]
        final_shape = prefix + (columns,)
        if len(source_shape) != 2:
            current = self.add_operator(
                f"{name}_restore",
                "Reshape",
                [current],
                [output_name],
                attributes={"shape": list(final_shape)},
                output_shapes=[final_shape],
            )[0]
        elif current != output_name:
            current = self.add_operator(
                f"{name}_output",
                "Reshape",
                [current],
                [output_name],
                attributes={"shape": list(final_shape)},
                output_shapes=[final_shape],
            )[0]
        return current

    def add_activation(
        self,
        name: str,
        function: str,
        source: str,
        *,
        output_name: str,
        axis: int = -1,
    ) -> str:
        normalized = function.lower().replace("_", "")
        op_type = {
            "linear": "Identity",
            "identity": "Identity",
            "relu": "ReLU",
            "gelu": "GELU",
            "sigmoid": "Sigmoid",
            "tanh": "Tanh",
            "silu": "SiLU",
            "swish": "SiLU",
            "softmax": "Softmax",
        }.get(normalized)
        if op_type is None:
            raise FrontendError(f"{name}: unsupported activation {function!r}")
        if op_type == "Identity":
            return self.add_operator(
                name,
                "Reshape",
                [source],
                [output_name],
                attributes={"shape": list(self.shapes[source])},
                output_shapes=[self.shapes[source]],
            )[0]
        attributes: dict[str, Any] = {}
        if op_type == "Softmax":
            attributes["axis"] = axis
        if op_type in ("GELU", "Sigmoid", "Tanh", "SiLU", "Softmax"):
            attributes.update(
                {
                    "input_scale": self.scale,
                    "output_scale": self.scale,
                }
            )
        else:
            attributes["scale"] = self.scale
        return self.add_operator(
            name,
            op_type,
            [source],
            [output_name],
            attributes=attributes,
            output_shapes=[self.shapes[source]],
        )[0]

    def finish(self, outputs: Sequence[str]) -> dict[str, Any]:
        if not outputs:
            raise FrontendError("framework model has no outputs")
        self.outputs = list(outputs)
        return {
            "schema_version": 1,
            "model": {
                "name": self.model_name,
                "source_format": self.source_format,
            },
            "frontend": {
                "source_format": self.source_format,
                "source_file": self.source_path.name,
                "model_dtype": self.options.dtype,
                "fraction_bits": self.options.fraction_bits,
                "scale": self.scale,
                "input_encoding": "signed_fixed_point",
            },
            "inputs": self.inputs,
            "constants": self.constants,
            "operators": self.operators,
            "outputs": self.outputs,
        }
