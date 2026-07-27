#!/usr/bin/env python3
"""Generate deterministic mixed-precision GEMM vectors for the DiP testbench.

The output is deliberately a numeric-only text stream.  SystemVerilog can read
every field with ``$fscanf(fd, "%d", value)``; line boundaries are provided for
human readability but have no parsing significance.

File format, version 1
======================

Header (one line)::

    version physical_n tile_count seed

Each tile starts with one metadata line::

    tile_id mode_bits lanes logical_n input_bits accumulator_bits output_bits

It is followed, without labels, by:

* ``logical_n`` rows of matrix A;
* ``logical_n`` rows of matrix B;
* ``logical_n`` rows of expected matrix C.

Every matrix row contains ``logical_n`` signed decimal elements.  The tile
metadata therefore completely describes how many values a reader must consume.
The modes use the following fixed mapping:

    int16: lanes=1, input=16, accumulator=64, output=32
    int8 : lanes=2, input= 8, accumulator=32, output=16
    int4 : lanes=4, input= 4, accumulator=16, output= 8

The logical square-matrix dimension is ``physical_n * lanes``.  During golden
GEMM evaluation, every addition is wrapped to the signed accumulator width.
The completed accumulator is then truncated to the signed output width.  This
models two's-complement RTL behavior without relying on host integer overflow.

Examples::

    # Write six tiles (two of every mode) for a physical 16x16 array.
    python3 gen_random_vectors.py -n 16 -t 2 -s 20250727 -o vectors.txt

    # Generate only INT8 and INT4 vectors on stdout.
    python3 gen_random_vectors.py -n 4 --modes int8 int4
"""

from __future__ import annotations

import argparse
import random
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, Sequence, TextIO


FORMAT_VERSION = 1
DEFAULT_SEED = 20250727


@dataclass(frozen=True)
class Mode:
    """Static arithmetic and spatial expansion parameters for one mode."""

    name: str
    input_bits: int
    lanes: int
    accumulator_bits: int
    output_bits: int


MODES = {
    "int16": Mode("int16", 16, 1, 64, 32),
    "int8": Mode("int8", 8, 2, 32, 16),
    "int4": Mode("int4", 4, 4, 16, 8),
}


def parse_int(text: str) -> int:
    """Accept ordinary decimal as well as convenient 0x/0o/0b CLI integers."""

    try:
        return int(text, 0)
    except ValueError as error:
        raise argparse.ArgumentTypeError(f"invalid integer: {text!r}") from error


def positive_int(text: str) -> int:
    value = parse_int(text)
    if value <= 0:
        raise argparse.ArgumentTypeError("value must be greater than zero")
    return value


def signed_wrap(value: int, width: int) -> int:
    """Return the low ``width`` bits interpreted as a signed integer."""

    modulus = 1 << width
    wrapped = value & (modulus - 1)
    if wrapped & (1 << (width - 1)):
        wrapped -= modulus
    return wrapped


def random_matrix(rng: random.Random, dimension: int, width: int) -> list[list[int]]:
    minimum = -(1 << (width - 1))
    maximum = (1 << (width - 1)) - 1
    return [
        [rng.randint(minimum, maximum) for _ in range(dimension)]
        for _ in range(dimension)
    ]


def inject_corner_values(
    matrix: list[list[int]], width: int, rotation: int
) -> None:
    """Insert distinct signed boundary cases while retaining random contents."""

    dimension = len(matrix)
    capacity = dimension * dimension
    corners = (-(1 << (width - 1)), (1 << (width - 1)) - 1, -1, 0, 1)
    for index, value in enumerate(corners[:capacity]):
        linear_index = (rotation + index) % capacity
        row, column = divmod(linear_index, dimension)
        matrix[row][column] = value


def golden_gemm(
    a_matrix: Sequence[Sequence[int]],
    b_matrix: Sequence[Sequence[int]],
    accumulator_bits: int,
    output_bits: int,
) -> list[list[int]]:
    dimension = len(a_matrix)
    result = [[0 for _ in range(dimension)] for _ in range(dimension)]

    for row in range(dimension):
        for column in range(dimension):
            accumulator = 0
            for k_index in range(dimension):
                product = a_matrix[row][k_index] * b_matrix[k_index][column]
                accumulator = signed_wrap(
                    accumulator + product, accumulator_bits
                )
            result[row][column] = signed_wrap(accumulator, output_bits)

    return result


def write_matrix(stream: TextIO, matrix: Iterable[Iterable[int]]) -> None:
    for row in matrix:
        stream.write(" ".join(str(value) for value in row))
        stream.write("\n")


def write_vectors(
    stream: TextIO,
    physical_n: int,
    tiles_per_mode: int,
    seed: int,
    mode_names: Sequence[str],
    inject_corners: bool,
) -> None:
    tile_count = tiles_per_mode * len(mode_names)
    stream.write(f"{FORMAT_VERSION} {physical_n} {tile_count} {seed}\n")

    rng = random.Random(seed)
    tile_id = 0
    for mode_name in mode_names:
        mode = MODES[mode_name]
        logical_n = physical_n * mode.lanes

        for mode_tile_index in range(tiles_per_mode):
            a_matrix = random_matrix(rng, logical_n, mode.input_bits)
            b_matrix = random_matrix(rng, logical_n, mode.input_bits)

            if inject_corners:
                rotation = mode_tile_index * len(a_matrix)
                inject_corner_values(a_matrix, mode.input_bits, rotation)
                inject_corner_values(
                    b_matrix, mode.input_bits, rotation + len(a_matrix) // 2
                )

            c_matrix = golden_gemm(
                a_matrix,
                b_matrix,
                mode.accumulator_bits,
                mode.output_bits,
            )

            stream.write(
                f"{tile_id} {mode.input_bits} {mode.lanes} {logical_n} "
                f"{mode.input_bits} {mode.accumulator_bits} "
                f"{mode.output_bits}\n"
            )
            write_matrix(stream, a_matrix)
            write_matrix(stream, b_matrix)
            write_matrix(stream, c_matrix)
            tile_id += 1


def build_argument_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Generate deterministic INT16/INT8/INT4 GEMM vectors for a "
            "multi-precision DiP array."
        )
    )
    parser.add_argument(
        "-n",
        "--array-n",
        type=positive_int,
        default=16,
        help="physical square-array dimension (default: 16)",
    )
    parser.add_argument(
        "-t",
        "--tiles-per-mode",
        type=positive_int,
        default=2,
        help="number of random tiles generated for each selected mode (default: 2)",
    )
    parser.add_argument(
        "-s",
        "--seed",
        type=parse_int,
        default=DEFAULT_SEED,
        help=f"deterministic PRNG seed (default: {DEFAULT_SEED})",
    )
    parser.add_argument(
        "--modes",
        nargs="+",
        choices=tuple(MODES),
        default=list(MODES),
        help="modes to emit, in the requested order (default: all modes)",
    )
    parser.add_argument(
        "--no-corners",
        action="store_true",
        help="do not replace a few random inputs with signed corner values",
    )
    parser.add_argument(
        "-o",
        "--output",
        default="-",
        help="output path, or '-' for stdout (default: stdout)",
    )
    return parser


def main(argv: Sequence[str] | None = None) -> int:
    arguments = build_argument_parser().parse_args(argv)

    if arguments.output == "-":
        write_vectors(
            sys.stdout,
            arguments.array_n,
            arguments.tiles_per_mode,
            arguments.seed,
            arguments.modes,
            not arguments.no_corners,
        )
        return 0

    output_path = Path(arguments.output)
    with output_path.open("w", encoding="ascii", newline="\n") as stream:
        write_vectors(
            stream,
            arguments.array_n,
            arguments.tiles_per_mode,
            arguments.seed,
            arguments.modes,
            not arguments.no_corners,
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
