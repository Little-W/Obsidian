#!/usr/bin/env python3
"""Conv2D lowering helpers for an NPU without a native convolution command.

The input activation uses NHWC order.  A Conv2D node is expanded into:

1. an optional DMA FILL for the padded im2col matrix;
2. one DMA COPY_ND for every kernel tap that reaches the input;
3. one Matrix GEMM whose linear output is already in NHWC order.

Kernel constants use [KH, KW, Cin, Cout] order.  Reshaping the first three
dimensions produces a row-major [KH * KW * Cin, Cout] matrix, which is then
passed to the compiler's shared Matrix-B tile packer.
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Any, Callable, Iterator, Mapping, Sequence


class ConvLoweringError(ValueError):
    """A Conv2D attribute or storage request cannot be lowered."""


_DTYPE_BITS = {
    "int4": 4,
    "int8": 8,
    "int16": 16,
    "int32": 32,
}

_MATRIX_INPUT_PAIRS = {
    ("int4", "int4"),
    ("int8", "int8"),
    ("int8", "int4"),
    ("int16", "int16"),
}


@dataclass(frozen=True)
class TensorPlacement:
    """Physical storage assigned by the upper compiler."""

    name: str
    addr: int
    region_bytes: int
    space: str
    dtype: str


@dataclass(frozen=True)
class Conv2DGeometry:
    """Checked Conv2D dimensions and attributes."""

    input_shape: tuple[int, int, int, int]
    kernel_shape: tuple[int, int, int, int]
    strides: tuple[int, int]
    dilations: tuple[int, int]
    padding: tuple[int, int, int, int]
    output_shape: tuple[int, int, int, int]

    @property
    def im2col_rows(self) -> int:
        batch, output_h, output_w, _ = self.output_shape
        return batch * output_h * output_w

    @property
    def im2col_columns(self) -> int:
        kernel_h, kernel_w, input_channels, _ = self.kernel_shape
        return kernel_h * kernel_w * input_channels

    @property
    def output_channels(self) -> int:
        return self.output_shape[3]

    @property
    def padded_shape(self) -> tuple[int, int, int, int]:
        batch, input_h, input_w, input_channels = self.input_shape
        pad_top, pad_bottom, pad_left, pad_right = self.padding
        return (
            batch,
            input_h + pad_top + pad_bottom,
            input_w + pad_left + pad_right,
            input_channels,
        )

    @property
    def im2col_shape(self) -> tuple[int, int]:
        return self.im2col_rows, self.im2col_columns

    @property
    def needs_fill(self) -> bool:
        return any(self.padding)


@dataclass(frozen=True)
class Im2ColTransfer:
    """One valid rectangular COPY_ND region for a fixed kernel tap."""

    kernel_y: int
    kernel_x: int
    src_element_offset: int
    dst_element_offset: int
    shape: tuple[int, int, int, int]
    src_stride_elements: tuple[int, int, int, int]
    dst_stride_elements: tuple[int, int, int, int]

    @property
    def kh(self) -> int:
        return self.kernel_y

    @property
    def kw(self) -> int:
        return self.kernel_x

    @property
    def src_start(self) -> int:
        return self.src_element_offset


@dataclass(frozen=True)
class Im2ColPlan:
    geometry: Conv2DGeometry
    transfers: tuple[Im2ColTransfer, ...]


@dataclass(frozen=True)
class ConvKernelMatrix:
    rows: int
    columns: int
    values: tuple[int, ...]


@dataclass(frozen=True)
class Conv2DLowering:
    geometry: Conv2DGeometry
    operations: tuple[Mapping[str, Any], ...]
    matrix_kernel: ConvKernelMatrix | None


Conv2DPlan = Conv2DGeometry


def _positive_shape(
    value: Sequence[int], count: int, location: str
) -> tuple[int, ...]:
    if isinstance(value, (str, bytes)) or len(value) != count:
        raise ConvLoweringError(f"{location} must contain {count} integers")
    result: list[int] = []
    for index, item in enumerate(value):
        if isinstance(item, bool) or not isinstance(item, int) or item <= 0:
            raise ConvLoweringError(
                f"{location}[{index}] must be a positive integer"
            )
        result.append(item)
    return tuple(result)


def _pair(value: Sequence[int], location: str) -> tuple[int, int]:
    first, second = _positive_shape(value, 2, location)
    return first, second


def _nonnegative(value: Any, location: str) -> int:
    if isinstance(value, bool) or not isinstance(value, int) or value < 0:
        raise ConvLoweringError(f"{location} must be a nonnegative integer")
    return value


def _explicit_padding(value: Any) -> tuple[int, int, int, int]:
    if isinstance(value, Mapping):
        required = ("top", "bottom", "left", "right")
        if set(value) != set(required):
            raise ConvLoweringError(
                "explicit padding object must contain top, bottom, left, right"
            )
        return tuple(_nonnegative(value[key], f"padding.{key}") for key in required)
    if isinstance(value, Sequence) and not isinstance(value, (str, bytes)):
        if len(value) == 4:
            return tuple(
                _nonnegative(item, f"padding[{index}]")
                for index, item in enumerate(value)
            )
        if len(value) == 2:
            height = value[0]
            width = value[1]
            if (
                isinstance(height, Sequence)
                and not isinstance(height, (str, bytes))
                and isinstance(width, Sequence)
                and not isinstance(width, (str, bytes))
                and len(height) == 2
                and len(width) == 2
            ):
                return (
                    _nonnegative(height[0], "padding[0][0]"),
                    _nonnegative(height[1], "padding[0][1]"),
                    _nonnegative(width[0], "padding[1][0]"),
                    _nonnegative(width[1], "padding[1][1]"),
                )
    raise ConvLoweringError(
        "padding must be VALID, SAME, [top,bottom,left,right], "
        "[[top,bottom],[left,right]], or an explicit padding object"
    )


def _output_extent(
    input_extent: int,
    effective_kernel: int,
    stride: int,
    before: int,
    after: int,
    location: str,
) -> int:
    numerator = input_extent + before + after - effective_kernel
    if numerator < 0:
        raise ConvLoweringError(f"{location} has no output position")
    return numerator // stride + 1


def infer_conv2d_geometry(
    input_shape: Sequence[int],
    kernel_shape: Sequence[int],
    *,
    strides: Sequence[int] = (1, 1),
    dilations: Sequence[int] = (1, 1),
    padding: str | Sequence[Any] | Mapping[str, int] = "VALID",
    groups: int = 1,
) -> Conv2DGeometry:
    """Check attributes and derive NHWC output dimensions."""

    batch, input_h, input_w, input_channels = _positive_shape(
        input_shape, 4, "input_shape"
    )
    kernel_h, kernel_w, kernel_channels, output_channels = _positive_shape(
        kernel_shape, 4, "kernel_shape"
    )
    stride_h, stride_w = _pair(strides, "strides")
    dilation_h, dilation_w = _pair(dilations, "dilations")
    if isinstance(groups, bool) or not isinstance(groups, int):
        raise ConvLoweringError("groups must be an integer")
    if groups != 1:
        raise ConvLoweringError("only groups=1 is supported")
    if kernel_channels != input_channels:
        raise ConvLoweringError(
            "kernel input channels must equal the NHWC input channels"
        )

    effective_h = (kernel_h - 1) * dilation_h + 1
    effective_w = (kernel_w - 1) * dilation_w + 1
    if isinstance(padding, str):
        mode = padding.upper()
        if mode == "VALID":
            pad_top = pad_bottom = pad_left = pad_right = 0
            output_h = _output_extent(
                input_h, effective_h, stride_h, 0, 0, "height"
            )
            output_w = _output_extent(
                input_w, effective_w, stride_w, 0, 0, "width"
            )
        elif mode == "SAME":
            output_h = (input_h + stride_h - 1) // stride_h
            output_w = (input_w + stride_w - 1) // stride_w
            total_h = max(
                (output_h - 1) * stride_h + effective_h - input_h, 0
            )
            total_w = max(
                (output_w - 1) * stride_w + effective_w - input_w, 0
            )
            pad_top = total_h // 2
            pad_bottom = total_h - pad_top
            pad_left = total_w // 2
            pad_right = total_w - pad_left
        else:
            raise ConvLoweringError("padding string must be VALID or SAME")
    else:
        pad_top, pad_bottom, pad_left, pad_right = _explicit_padding(padding)
        output_h = _output_extent(
            input_h,
            effective_h,
            stride_h,
            pad_top,
            pad_bottom,
            "height",
        )
        output_w = _output_extent(
            input_w,
            effective_w,
            stride_w,
            pad_left,
            pad_right,
            "width",
        )

    return Conv2DGeometry(
        input_shape=(batch, input_h, input_w, input_channels),
        kernel_shape=(
            kernel_h,
            kernel_w,
            kernel_channels,
            output_channels,
        ),
        strides=(stride_h, stride_w),
        dilations=(dilation_h, dilation_w),
        padding=(pad_top, pad_bottom, pad_left, pad_right),
        output_shape=(batch, output_h, output_w, output_channels),
    )


def infer_conv2d(
    input_shape: Sequence[int],
    kernel_shape: Sequence[int],
    attributes: Mapping[str, Any] | None = None,
) -> Conv2DPlan:
    """Upper-compiler API for a semantic Conv2D node."""

    fields = {} if attributes is None else dict(attributes)
    known = {"strides", "dilations", "padding", "groups", "data_format"}
    unknown = sorted(set(fields) - known)
    if unknown:
        raise ConvLoweringError(
            f"unsupported Conv2D attribute {unknown[0]!r}"
        )
    data_format = fields.get("data_format", "NHWC")
    if not isinstance(data_format, str) or data_format.upper() != "NHWC":
        raise ConvLoweringError("Conv2D data_format must be NHWC")
    return infer_conv2d_geometry(
        input_shape,
        kernel_shape,
        strides=fields.get("strides", (1, 1)),
        dilations=fields.get("dilations", (1, 1)),
        padding=fields.get("padding", "VALID"),
        groups=fields.get("groups", 1),
    )


def _ceil_div_signed(numerator: int, denominator: int) -> int:
    return -((-numerator) // denominator)


def plan_im2col(geometry: Conv2DGeometry) -> Im2ColPlan:
    """Create one strided COPY_ND region for every useful kernel tap."""

    batch, input_h, input_w, input_channels = geometry.input_shape
    kernel_h, kernel_w, _, _ = geometry.kernel_shape
    _, output_h, output_w, _ = geometry.output_shape
    stride_h, stride_w = geometry.strides
    dilation_h, dilation_w = geometry.dilations
    pad_top, _, pad_left, _ = geometry.padding
    columns = geometry.im2col_columns
    transfers: list[Im2ColTransfer] = []

    src_batch_stride = input_h * input_w * input_channels
    dst_batch_stride = output_h * output_w * columns
    for kernel_y in range(kernel_h):
        output_y_first = max(
            0,
            _ceil_div_signed(
                pad_top - kernel_y * dilation_h, stride_h
            ),
        )
        output_y_last = min(
            output_h - 1,
            (
                input_h
                - 1
                + pad_top
                - kernel_y * dilation_h
            )
            // stride_h,
        )
        if output_y_first > output_y_last:
            continue
        input_y_first = (
            output_y_first * stride_h
            - pad_top
            + kernel_y * dilation_h
        )
        for kernel_x in range(kernel_w):
            output_x_first = max(
                0,
                _ceil_div_signed(
                    pad_left - kernel_x * dilation_w, stride_w
                ),
            )
            output_x_last = min(
                output_w - 1,
                (
                    input_w
                    - 1
                    + pad_left
                    - kernel_x * dilation_w
                )
                // stride_w,
            )
            if output_x_first > output_x_last:
                continue
            input_x_first = (
                output_x_first * stride_w
                - pad_left
                + kernel_x * dilation_w
            )
            src_offset = (
                input_y_first * input_w + input_x_first
            ) * input_channels
            output_row = output_y_first * output_w + output_x_first
            tap_column = (
                kernel_y * kernel_w + kernel_x
            ) * input_channels
            dst_offset = output_row * columns + tap_column
            transfers.append(
                Im2ColTransfer(
                    kernel_y=kernel_y,
                    kernel_x=kernel_x,
                    src_element_offset=src_offset,
                    dst_element_offset=dst_offset,
                    shape=(
                        batch,
                        output_y_last - output_y_first + 1,
                        output_x_last - output_x_first + 1,
                        input_channels,
                    ),
                    src_stride_elements=(
                        src_batch_stride,
                        stride_h * input_w * input_channels,
                        stride_w * input_channels,
                        0,
                    ),
                    dst_stride_elements=(
                        dst_batch_stride,
                        output_w * columns,
                        columns,
                        0,
                    ),
                )
            )
    return Im2ColPlan(geometry=geometry, transfers=tuple(transfers))


def iter_im2col_taps(plan: Conv2DPlan) -> Iterator[Im2ColTransfer]:
    """Yield fixed-tap COPY_ND descriptions in kernel row-major order."""

    yield from plan_im2col(plan).transfers


def conv_kernel_to_matrix(
    values: Sequence[int], kernel_shape: Sequence[int]
) -> ConvKernelMatrix:
    """Reshape [KH, KW, Cin, Cout] into row-major [K, Cout]."""

    kernel_h, kernel_w, input_channels, output_channels = _positive_shape(
        kernel_shape, 4, "kernel_shape"
    )
    count = kernel_h * kernel_w * input_channels * output_channels
    if isinstance(values, (str, bytes)) or len(values) != count:
        raise ConvLoweringError(
            f"kernel constant has {len(values)} values; expected {count}"
        )
    checked: list[int] = []
    for index, value in enumerate(values):
        if isinstance(value, bool) or not isinstance(value, int):
            raise ConvLoweringError(
                f"kernel_values[{index}] must be an integer"
            )
        checked.append(value)
    return ConvKernelMatrix(
        rows=kernel_h * kernel_w * input_channels,
        columns=output_channels,
        values=tuple(checked),
    )


def pack_conv_kernel(
    values: Sequence[int],
    kernel_shape: Sequence[int],
    pack_matrix_b: Callable[[Sequence[int], int, int], Any],
) -> Any:
    """Pass the Conv2D kernel matrix to the shared Matrix-B tile packer."""

    if not callable(pack_matrix_b):
        raise ConvLoweringError("pack_matrix_b must be callable")
    matrix = conv_kernel_to_matrix(values, kernel_shape)
    return pack_matrix_b(matrix.values, matrix.rows, matrix.columns)


def _checked_placement(placement: TensorPlacement, location: str) -> None:
    if not placement.name:
        raise ConvLoweringError(f"{location}.name must not be empty")
    if (
        isinstance(placement.addr, bool)
        or not isinstance(placement.addr, int)
        or placement.addr < 0
    ):
        raise ConvLoweringError(f"{location}.addr must be nonnegative")
    if (
        isinstance(placement.region_bytes, bool)
        or not isinstance(placement.region_bytes, int)
        or placement.region_bytes <= 0
    ):
        raise ConvLoweringError(
            f"{location}.region_bytes must be positive"
        )
    if placement.space.lower() not in {"l1", "ddr"}:
        raise ConvLoweringError(f"{location}.space must be l1 or ddr")
    if placement.dtype.lower() not in _DTYPE_BITS:
        raise ConvLoweringError(f"{location}.dtype is not supported")


def storage_bytes(elements: int, dtype: str) -> int:
    """Return packed byte count for a nonnegative element count."""

    if isinstance(elements, bool) or not isinstance(elements, int) or elements < 0:
        raise ConvLoweringError("elements must be a nonnegative integer")
    normalized = dtype.lower()
    if normalized not in _DTYPE_BITS:
        raise ConvLoweringError(f"unsupported dtype {dtype!r}")
    bits = _DTYPE_BITS[normalized]
    return (elements * bits + 7) // 8


def _element_address(
    placement: TensorPlacement, element_offset: int
) -> tuple[int, int]:
    bits = _DTYPE_BITS[placement.dtype.lower()]
    bit_offset = element_offset * bits
    return placement.addr + bit_offset // 8, (bit_offset % 8) // 4


def _remaining_region(
    placement: TensorPlacement, adjusted_addr: int
) -> int:
    consumed = adjusted_addr - placement.addr
    if consumed < 0 or consumed >= placement.region_bytes:
        raise ConvLoweringError(
            f"{placement.name} element offset is outside its storage"
        )
    return placement.region_bytes - consumed


def _byte_strides(
    strides: Sequence[int], dtype: str, location: str
) -> list[int]:
    bits = _DTYPE_BITS[dtype.lower()]
    result: list[int] = []
    for index, stride in enumerate(strides):
        bit_stride = stride * bits
        if bit_stride % 8:
            raise ConvLoweringError(
                f"{location}[{index}] is not byte aligned"
            )
        result.append(bit_stride // 8)
    return result


def _inline_tensor(
    placement: TensorPlacement,
    addr: int | None = None,
    region_bytes: int | None = None,
) -> dict[str, Any]:
    return {
        "addr": placement.addr if addr is None else addr,
        "space": placement.space.lower(),
        "dtype": placement.dtype.lower(),
        "region_bytes": (
            placement.region_bytes if region_bytes is None else region_bytes
        ),
    }


def emit_im2col_dma_operations(
    name: str,
    plan: Im2ColPlan,
    input_tensor: TensorPlacement,
    im2col_tensor: TensorPlacement,
    *,
    initial_dependency: str | None = None,
    burst_beats: int = 16,
    max_outstanding: int = 8,
) -> tuple[dict[str, Any], ...]:
    """Materialize the im2col plan as assembler-ready DMA operations."""

    if not name:
        raise ConvLoweringError("name must not be empty")
    _checked_placement(input_tensor, "input_tensor")
    _checked_placement(im2col_tensor, "im2col_tensor")
    input_dtype = input_tensor.dtype.lower()
    if input_dtype != im2col_tensor.dtype.lower():
        raise ConvLoweringError(
            "input_tensor and im2col_tensor must use the same dtype"
        )
    if input_dtype == "int4" and plan.geometry.input_shape[3] % 2:
        raise ConvLoweringError(
            "INT4 Conv2D requires an even input channel count"
        )
    expected_input = storage_bytes(
        _product(plan.geometry.input_shape), input_dtype
    )
    expected_im2col = storage_bytes(
        plan.geometry.im2col_rows * plan.geometry.im2col_columns,
        input_dtype,
    )
    if input_tensor.region_bytes < expected_input:
        raise ConvLoweringError("input_tensor storage is too small")
    if im2col_tensor.region_bytes < expected_im2col:
        raise ConvLoweringError("im2col_tensor storage is too small")
    if not isinstance(burst_beats, int) or not 1 <= burst_beats <= 256:
        raise ConvLoweringError("burst_beats must be in 1..256")
    if (
        not isinstance(max_outstanding, int)
        or not 1 <= max_outstanding <= 255
    ):
        raise ConvLoweringError("max_outstanding must be in 1..255")

    operations: list[dict[str, Any]] = []
    previous = initial_dependency
    rows = plan.geometry.im2col_rows
    columns = plan.geometry.im2col_columns
    if plan.geometry.needs_fill:
        fill_name = f"{name}_fill"
        fill = {
            "name": fill_name,
            "engine": "dma",
            "opcode": "FILL",
            "descriptor": {
                "common": {
                    "dst": _inline_tensor(im2col_tensor),
                    "dst_dtype": input_dtype,
                },
                "dma": {
                    "rank": 2,
                    "shape": [rows, columns],
                    "src_stride_bytes": [0, 0],
                    "dst_stride_bytes": [
                        storage_bytes(columns, input_dtype),
                        0,
                    ],
                    "fill_value": 0,
                    "burst_beats": burst_beats,
                    "max_outstanding": max_outstanding,
                },
            },
        }
        if previous is not None:
            fill["depends_on"] = [previous]
        operations.append(fill)
        previous = fill_name

    for transfer in plan.transfers:
        src_addr, src_nibble = _element_address(
            input_tensor, transfer.src_element_offset
        )
        dst_addr, dst_nibble = _element_address(
            im2col_tensor, transfer.dst_element_offset
        )
        if dst_nibble != 0:
            raise ConvLoweringError(
                "DMA COPY_ND cannot start an INT4 destination at the high nibble"
            )
        copy_name = (
            f"{name}_tap_{transfer.kernel_y}_{transfer.kernel_x}"
        )
        copy = {
            "name": copy_name,
            "engine": "dma",
            "opcode": "COPY_ND",
            "descriptor": {
                "common": {
                    "src0": _inline_tensor(
                        input_tensor,
                        src_addr,
                        _remaining_region(input_tensor, src_addr),
                    ),
                    "dst": _inline_tensor(
                        im2col_tensor,
                        dst_addr,
                        _remaining_region(im2col_tensor, dst_addr),
                    ),
                },
                "dma": {
                    "rank": 4,
                    "shape": list(transfer.shape),
                    "src_stride_bytes": _byte_strides(
                        transfer.src_stride_elements,
                        input_dtype,
                        f"{copy_name}.src_stride_elements",
                    ),
                    "dst_stride_bytes": _byte_strides(
                        transfer.dst_stride_elements,
                        input_dtype,
                        f"{copy_name}.dst_stride_elements",
                    ),
                    "src_nibble": src_nibble,
                    "dst_nibble": dst_nibble,
                    "burst_beats": burst_beats,
                    "max_outstanding": max_outstanding,
                },
            },
        }
        if previous is not None:
            copy["depends_on"] = [previous]
        operations.append(copy)
        previous = copy_name
    if not operations:
        raise ConvLoweringError("im2col plan did not produce a DMA operation")
    return tuple(operations)


def emit_conv2d_operations(
    name: str,
    geometry: Conv2DGeometry,
    input_tensor: TensorPlacement,
    im2col_tensor: TensorPlacement,
    tiled_kernel_tensor: TensorPlacement,
    output_tensor: TensorPlacement,
    *,
    bias_tensor: TensorPlacement | None = None,
    requant_tensor: TensorPlacement | None = None,
    initial_dependency: str | None = None,
    burst_beats: int = 16,
    max_outstanding: int = 8,
) -> tuple[dict[str, Any], ...]:
    """Emit DMA im2col operations followed by a Matrix GEMM."""

    _checked_placement(tiled_kernel_tensor, "tiled_kernel_tensor")
    _checked_placement(output_tensor, "output_tensor")
    input_dtype = input_tensor.dtype.lower()
    kernel_dtype = tiled_kernel_tensor.dtype.lower()
    output_dtype = output_tensor.dtype.lower()
    if (input_dtype, kernel_dtype) not in _MATRIX_INPUT_PAIRS:
        raise ConvLoweringError(
            f"Matrix does not support {input_dtype} x {kernel_dtype}"
        )
    if (
        input_tensor.space.lower() != "l1"
        or im2col_tensor.space.lower() != "l1"
        or tiled_kernel_tensor.space.lower() != "l1"
        or output_tensor.space.lower() != "l1"
    ):
        raise ConvLoweringError(
            "Conv2D Matrix operands and result must be in L1"
        )

    rows = geometry.im2col_rows
    columns = geometry.im2col_columns
    output_channels = geometry.output_channels
    expected_output = storage_bytes(rows * output_channels, output_dtype)
    if output_tensor.region_bytes < expected_output:
        raise ConvLoweringError("output_tensor storage is too small")
    common: dict[str, Any] = {
        "src0": _inline_tensor(im2col_tensor),
        "src1": _inline_tensor(tiled_kernel_tensor),
        "dst": _inline_tensor(output_tensor),
        "round_mode": "nearest_even",
        "saturate_enable": True,
    }
    matrix: dict[str, Any] = {
        "m": rows,
        "n": output_channels,
        "k": columns,
        "batch_count": 1,
        "lda_bytes": storage_bytes(columns, input_dtype),
        "ldb_bytes": 0,
        "ldc_bytes": storage_bytes(output_channels, output_dtype),
        "final_output": True,
        "overflow_mode": "saturate",
    }
    if bias_tensor is not None:
        _checked_placement(bias_tensor, "bias_tensor")
        if bias_tensor.space.lower() != "l1" or bias_tensor.dtype.lower() != "int32":
            raise ConvLoweringError("bias_tensor must be INT32 in L1")
        if bias_tensor.region_bytes < output_channels * 4:
            raise ConvLoweringError("bias_tensor storage is too small")
        common["aux0"] = _inline_tensor(bias_tensor)
        matrix.update(
            {
                "bias_enable": True,
                "bias_count": output_channels,
                "bias_stride_bytes": 4,
            }
        )
    if output_dtype == "int32":
        if requant_tensor is not None:
            raise ConvLoweringError(
                "INT32 output must not provide a requant tensor"
            )
    else:
        if requant_tensor is None:
            raise ConvLoweringError(
                "non-INT32 output requires a requant tensor"
            )
        _checked_placement(requant_tensor, "requant_tensor")
        if (
            requant_tensor.space.lower() != "l1"
            or requant_tensor.dtype.lower() != "int32"
            or requant_tensor.region_bytes < 8
        ):
            raise ConvLoweringError(
                "requant_tensor must provide at least one 8-byte entry in L1"
            )
        common["aux1"] = _inline_tensor(requant_tensor)
        matrix.update(
            {
                "requant_enable": True,
                "requant_mode": 1,
                "requant_count": 1,
                "requant_entry_bytes": 8,
                "requant_region_bytes": requant_tensor.region_bytes,
            }
        )

    dma_operations = list(
        emit_im2col_dma_operations(
            f"{name}_im2col",
            plan_im2col(geometry),
            input_tensor,
            im2col_tensor,
            initial_dependency=initial_dependency,
            burst_beats=burst_beats,
            max_outstanding=max_outstanding,
        )
    )
    gemm_name = f"{name}_gemm"
    gemm = {
        "name": gemm_name,
        "engine": "matrix",
        "opcode": "GEMM",
        "depends_on": [dma_operations[-1]["name"]],
        "descriptor": {
            "common": common,
            "matrix": matrix,
        },
    }
    dma_operations.append(gemm)
    return tuple(dma_operations)


def lower_conv2d(
    name: str,
    input_shape: Sequence[int],
    kernel_shape: Sequence[int],
    input_tensor: TensorPlacement,
    im2col_tensor: TensorPlacement,
    tiled_kernel_tensor: TensorPlacement,
    output_tensor: TensorPlacement,
    *,
    strides: Sequence[int] = (1, 1),
    dilations: Sequence[int] = (1, 1),
    padding: str | Sequence[Any] | Mapping[str, int] = "VALID",
    groups: int = 1,
    kernel_values: Sequence[int] | None = None,
    bias_tensor: TensorPlacement | None = None,
    requant_tensor: TensorPlacement | None = None,
    initial_dependency: str | None = None,
) -> Conv2DLowering:
    """Convenience entry used by the upper compiler after storage assignment."""

    geometry = infer_conv2d_geometry(
        input_shape,
        kernel_shape,
        strides=strides,
        dilations=dilations,
        padding=padding,
        groups=groups,
    )
    matrix_kernel = (
        None
        if kernel_values is None
        else conv_kernel_to_matrix(kernel_values, kernel_shape)
    )
    operations = emit_conv2d_operations(
        name,
        geometry,
        input_tensor,
        im2col_tensor,
        tiled_kernel_tensor,
        output_tensor,
        bias_tensor=bias_tensor,
        requant_tensor=requant_tensor,
        initial_dependency=initial_dependency,
    )
    return Conv2DLowering(
        geometry=geometry,
        operations=operations,
        matrix_kernel=matrix_kernel,
    )


def _product(values: Sequence[int]) -> int:
    result = 1
    for value in values:
        result *= value
    return result
