"""Build deterministic block schedules for large matrix products.

The schedule groups row blocks and column blocks.  For each group it walks the
K blocks and emits the Cartesian product

    A[row, k] @ B[k, column] -> C[row, column]

This order lets an implementation load each A block once per K step and use it
for every column block in the group.  Each B block is likewise shared by every
row block in the group.
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Iterable


INSTRUCTION_DIMENSION_LIMIT = 64


class MatrixScheduleError(ValueError):
    """A matrix schedule cannot be represented by the requested block sizes."""


@dataclass(frozen=True)
class AxisBlock:
    """A half-open interval on one matrix axis."""

    index: int
    start: int
    size: int

    @property
    def stop(self) -> int:
        return self.start + self.size


@dataclass(frozen=True)
class ProductStep:
    """One A block times one B block, added to one output block."""

    reduction: AxisBlock
    row: AxisBlock
    column: AxisBlock
    row_slot: int
    column_slot: int
    first_reduction: bool
    last_reduction: bool
    a_use_count: int
    b_use_count: int


@dataclass(frozen=True)
class ReductionStep:
    """Loads and products belonging to one K block inside an output group."""

    reduction: AxisBlock
    rows: tuple[AxisBlock, ...]
    columns: tuple[AxisBlock, ...]
    products: tuple[ProductStep, ...]


@dataclass(frozen=True)
class OutputGroup:
    """A group of R row blocks and W column blocks."""

    index: int
    rows: tuple[AxisBlock, ...]
    columns: tuple[AxisBlock, ...]
    reductions: tuple[ReductionStep, ...]

    @property
    def output_block_count(self) -> int:
        return len(self.rows) * len(self.columns)


@dataclass(frozen=True)
class MatrixSchedulePlan:
    """Complete block schedule for C[M,N] = A[M,K] @ B[K,N]."""

    m: int
    n: int
    k: int
    block_m: int
    block_n: int
    block_k: int
    row_group_blocks: int
    column_group_blocks: int
    row_blocks: tuple[AxisBlock, ...]
    column_blocks: tuple[AxisBlock, ...]
    reduction_blocks: tuple[AxisBlock, ...]
    groups: tuple[OutputGroup, ...]

    @property
    def product_count(self) -> int:
        return (
            len(self.row_blocks)
            * len(self.column_blocks)
            * len(self.reduction_blocks)
        )

    def products(self) -> Iterable[ProductStep]:
        for group in self.groups:
            for reduction in group.reductions:
                yield from reduction.products


def _positive(value: int, name: str) -> int:
    if isinstance(value, bool) or not isinstance(value, int) or value <= 0:
        raise MatrixScheduleError(f"{name} must be a positive integer")
    return value


def _axis_blocks(length: int, block_size: int) -> tuple[AxisBlock, ...]:
    return tuple(
        AxisBlock(
            index=index,
            start=start,
            size=min(block_size, length - start),
        )
        for index, start in enumerate(range(0, length, block_size))
    )


def _chunks(
    values: tuple[AxisBlock, ...], count: int
) -> Iterable[tuple[AxisBlock, ...]]:
    for start in range(0, len(values), count):
        yield values[start : start + count]


def build_matrix_schedule(
    m: int,
    n: int,
    k: int,
    *,
    block_m: int = INSTRUCTION_DIMENSION_LIMIT,
    block_n: int = INSTRUCTION_DIMENSION_LIMIT,
    block_k: int = INSTRUCTION_DIMENSION_LIMIT,
    row_group_blocks: int = 1,
    column_group_blocks: int = 1,
    mt: int = 1,
    nt: int = 1,
    kt: int = 1,
) -> MatrixSchedulePlan:
    """Return an output-group and K-block schedule.

    Full-size blocks begin at hardware-tile aligned positions.  Tail blocks
    may be shorter.  Every emitted product stays within the instruction's
    64-element M, N, and K fields.
    """

    m = _positive(m, "m")
    n = _positive(n, "n")
    k = _positive(k, "k")
    block_m = _positive(block_m, "block_m")
    block_n = _positive(block_n, "block_n")
    block_k = _positive(block_k, "block_k")
    row_group_blocks = _positive(
        row_group_blocks, "row_group_blocks"
    )
    column_group_blocks = _positive(
        column_group_blocks, "column_group_blocks"
    )
    mt = _positive(mt, "mt")
    nt = _positive(nt, "nt")
    kt = _positive(kt, "kt")

    for name, value in (
        ("block_m", block_m),
        ("block_n", block_n),
        ("block_k", block_k),
    ):
        if value > INSTRUCTION_DIMENSION_LIMIT:
            raise MatrixScheduleError(
                f"{name} must be at most {INSTRUCTION_DIMENSION_LIMIT}"
            )
    for name, block_size, hardware_tile in (
        ("block_m", block_m, mt),
        ("block_n", block_n, nt),
        ("block_k", block_k, kt),
    ):
        if block_size % hardware_tile:
            raise MatrixScheduleError(
                f"{name} must be divisible by its hardware tile size "
                f"{hardware_tile}"
            )

    row_blocks = _axis_blocks(m, block_m)
    column_blocks = _axis_blocks(n, block_n)
    reduction_blocks = _axis_blocks(k, block_k)
    groups: list[OutputGroup] = []
    group_index = 0
    for rows in _chunks(row_blocks, row_group_blocks):
        for columns in _chunks(column_blocks, column_group_blocks):
            reduction_steps: list[ReductionStep] = []
            for reduction_index, reduction in enumerate(reduction_blocks):
                products = tuple(
                    ProductStep(
                        reduction=reduction,
                        row=row,
                        column=column,
                        row_slot=row_slot,
                        column_slot=column_slot,
                        first_reduction=reduction_index == 0,
                        last_reduction=(
                            reduction_index == len(reduction_blocks) - 1
                        ),
                        a_use_count=len(columns),
                        b_use_count=len(rows),
                    )
                    for column_slot, column in enumerate(columns)
                    for row_slot, row in enumerate(rows)
                )
                reduction_steps.append(
                    ReductionStep(
                        reduction=reduction,
                        rows=rows,
                        columns=columns,
                        products=products,
                    )
                )
            groups.append(
                OutputGroup(
                    index=group_index,
                    rows=rows,
                    columns=columns,
                    reductions=tuple(reduction_steps),
                )
            )
            group_index += 1

    return MatrixSchedulePlan(
        m=m,
        n=n,
        k=k,
        block_m=block_m,
        block_n=block_n,
        block_k=block_k,
        row_group_blocks=row_group_blocks,
        column_group_blocks=column_group_blocks,
        row_blocks=row_blocks,
        column_blocks=column_blocks,
        reduction_blocks=reduction_blocks,
        groups=tuple(groups),
    )
