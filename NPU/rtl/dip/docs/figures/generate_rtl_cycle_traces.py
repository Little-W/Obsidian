#!/usr/bin/env python3
"""Generate paper-style, cycle-separated DiP RTL illustrations.

Each frame represents the registered state immediately after one rising edge.
The example uses ARRAY_N=4 and continuous A-row input.  It therefore exposes
the overlap of data_q, product_q, logical_product_q, contribution_o, and
psum_q in every PE.
"""

from __future__ import annotations

import json
import subprocess
from dataclasses import dataclass
from pathlib import Path
from xml.sax.saxutils import escape


ARRAY_N = 4
FIRST_OUTPUT_EDGE = ARRAY_N + 3
CANVAS_W = 2560
CANVAS_H = 1840

PE_X0 = 105
PE_Y0 = 345
PE_W = 350
PE_H = 205
PE_X_STEP = 420
PE_Y_STEP = 300
DATA_PORT_DX = 80
PSUM_PORT_DX = 270
SIDEBAR_X = 1800


@dataclass(frozen=True)
class Mode:
    slug: str
    name: str
    mode_bits: str
    width: int
    lanes: int
    accumulator_bits: int
    output_bits: int
    contribution_desc: str
    output_desc: str

    @property
    def logical_n(self) -> int:
        return ARRAY_N * self.lanes

    @property
    def logical_products_per_pe(self) -> int:
        return self.lanes * self.lanes


MODES = (
    Mode(
        slug="int16",
        name="INT16",
        mode_bits="2'b00",
        width=16,
        lanes=1,
        accumulator_bits=64,
        output_bits=32,
        contribution_desc="1×64 bit",
        output_desc="4×INT32",
    ),
    Mode(
        slug="int8",
        name="INT8",
        mode_bits="2'b01",
        width=8,
        lanes=2,
        accumulator_bits=32,
        output_bits=16,
        contribution_desc="2×32 bit",
        output_desc="8×INT16",
    ),
    Mode(
        slug="int4",
        name="INT4",
        mode_bits="2'b10",
        width=4,
        lanes=4,
        accumulator_bits=16,
        output_bits=8,
        contribution_desc="4×16 bit",
        output_desc="16×INT8",
    ),
)


def signed_wrap(value: int, width: int) -> int:
    """Wrap an integer to a signed two's-complement value."""

    modulus = 1 << width
    wrapped = value & (modulus - 1)
    if wrapped & (1 << (width - 1)):
        wrapped -= modulus
    return wrapped


def a_value(mode: Mode, row: int, k_index: int) -> int:
    """Small deterministic values valid in every supported precision."""

    del mode
    return ((3 * row + k_index) % 7) - 3


def b_value(mode: Mode, k_index: int, column: int) -> int:
    """Small deterministic values valid in every supported precision."""

    del mode
    return ((2 * k_index + column) % 5) - 2


def data_word(mode: Mode, token: int, row: int, column: int) -> list[int]:
    """Return the packed data_q lanes held by one physical PE."""

    start = mode.lanes * (row + column)
    return [
        a_value(mode, token, (start + lane) % mode.logical_n)
        for lane in range(mode.lanes)
    ]


def q_lane(
    mode: Mode,
    token: int,
    row: int,
    column: int,
    out_lane: int,
) -> int:
    """Value captured by contribution_o for one output lane."""

    total = 0
    logical_column = mode.lanes * column + out_lane
    for k_lane in range(mode.lanes):
        k_index = (
            mode.lanes * (row + column) + k_lane + out_lane
        ) % mode.logical_n
        total += (
            a_value(mode, token, k_index)
            * b_value(mode, k_index, logical_column)
        )
    return signed_wrap(total, mode.accumulator_bits)


def logical_product_word(
    mode: Mode,
    token: int,
    row: int,
    column: int,
) -> list[int]:
    """Values captured in the active entries of logical_product_q."""

    result: list[int] = []
    for out_lane in range(mode.lanes):
        logical_column = mode.lanes * column + out_lane
        for k_lane in range(mode.lanes):
            k_index = (
                mode.lanes * (row + column) + k_lane + out_lane
            ) % mode.logical_n
            result.append(
                signed_wrap(
                    a_value(mode, token, k_index)
                    * b_value(mode, k_index, logical_column),
                    32,
                )
            )
    return result


def q_word(mode: Mode, token: int, row: int, column: int) -> list[int]:
    return [
        q_lane(mode, token, row, column, lane)
        for lane in range(mode.lanes)
    ]


def s_word(mode: Mode, token: int, row: int, column: int) -> list[int]:
    """Value captured by psum_q after accumulation through physical row."""

    result: list[int] = []
    for lane in range(mode.lanes):
        total = 0
        for source_row in range(row + 1):
            total = signed_wrap(
                total
                + q_lane(mode, token, source_row, column, lane),
                mode.accumulator_bits,
            )
        result.append(total)
    return result


def c_row(mode: Mode, token: int) -> list[int]:
    """Narrow the bottom psum_q exactly as dip_systolic_array does."""

    result: list[int] = []
    for column in range(ARRAY_N):
        for lane in range(mode.lanes):
            result.append(
                signed_wrap(
                    s_word(mode, token, ARRAY_N - 1, column)[lane],
                    mode.output_bits,
                )
            )
    return result


def packed_weight_words(mode: Mode, row: int, column: int) -> list[int]:
    """Return the final weight_q words in one PE, lane 0 in the low bits."""

    words: list[int] = []
    lane_mask = (1 << mode.width) - 1
    for k_lane in range(mode.lanes):
        packed = 0
        for out_lane in range(mode.lanes):
            logical_column = mode.lanes * column + out_lane
            k_index = (
                mode.lanes * (row + column) + k_lane + out_lane
            ) % mode.logical_n
            packed |= (
                b_value(mode, k_index, logical_column) & lane_mask
            ) << (out_lane * mode.width)
        words.append(packed)
    return words


def stage_token(mode: Mode, edge: int, row: int, offset: int) -> int | None:
    token = edge - row - offset
    if 0 <= token < mode.logical_n:
        return token
    return None


def valid_bits(mode: Mode, edge: int, offset: int) -> str:
    """Return [R3:R0], matching the labels printed in every frame."""

    return "".join(
        "1" if stage_token(mode, edge, row, offset) is not None else "0"
        for row in reversed(range(ARRAY_N))
    )


def fmt_vector(values: list[int], scalar_parentheses: bool = False) -> str:
    if len(values) == 1:
        return f"({values[0]})" if scalar_parentheses else str(values[0])
    return "[" + ",".join(str(value) for value in values) + "]"


def fmt_full_row(mode: Mode, token: int, row: int, stage: str) -> str:
    groups: list[str] = []
    for column in range(ARRAY_N):
        values = (
            q_word(mode, token, row, column)
            if stage == "Q"
            else s_word(mode, token, row, column)
        )
        groups.append(fmt_vector(values, scalar_parentheses=True))
    return " | ".join(groups)


def equation_text(mode: Mode) -> str:
    if mode.lanes == 1:
        return (
            "Q[R,C,0]=A[m,k]×B[k,C]，"
            f"k=(R+C) mod {mode.logical_n}"
        )
    return (
        f"Q[R,C,v]=Σu A[m,k]×B[k,{mode.lanes}C+v]，"
        f"k=({mode.lanes}(R+C)+u+v) mod {mode.logical_n}"
    )


def data_port(column: int) -> int:
    return PE_X0 + column * PE_X_STEP + DATA_PORT_DX


def psum_port(column: int) -> int:
    return PE_X0 + column * PE_X_STEP + PSUM_PORT_DX


def pe_x(column: int) -> int:
    return PE_X0 + column * PE_X_STEP


def pe_y(row: int) -> int:
    return PE_Y0 + row * PE_Y_STEP


def weight_text(mode: Mode, row: int, column: int) -> str:
    words = packed_weight_words(mode, row, column)
    width = 4
    return "weight_q=" + "/".join(f"{word:0{width}X}" for word in words)


def stage_line(
    label: str,
    token: int | None,
    value: str,
    css_class: str,
    x_pos: int,
    y_pos: int,
) -> str:
    if token is None:
        return (
            f'<text class="slot-off" x="{x_pos}" y="{y_pos}">'
            f"{label} —</text>"
        )
    return (
        f'<text class="{css_class}" x="{x_pos}" y="{y_pos}">'
        f"{label} m{token}: {escape(value)}</text>"
    )


def pe_cell(mode: Mode, edge: int, row: int, column: int) -> str:
    x_pos = pe_x(column)
    y_pos = pe_y(row)

    token_d = stage_token(mode, edge, row, 0)
    token_m = stage_token(mode, edge, row, 1)
    token_lp = stage_token(mode, edge, row, 2)
    token_q = stage_token(mode, edge, row, 3)
    token_s = stage_token(mode, edge, row, 4)

    d_value = (
        fmt_vector(data_word(mode, token_d, row, column))
        if token_d is not None
        else ""
    )
    m_value = "16×8-bit product_q"
    if token_lp is None:
        lp_value_text = ""
    elif mode.logical_products_per_pe <= 4:
        lp_value_text = fmt_vector(
            logical_product_word(mode, token_lp, row, column)
        )
    else:
        lp_value_text = "16×INT32 logical products"
    q_value_text = (
        fmt_vector(q_word(mode, token_q, row, column))
        if token_q is not None
        else ""
    )
    s_value_text = (
        fmt_vector(s_word(mode, token_s, row, column))
        if token_s is not None
        else ""
    )

    return f"""
  <g>
    <rect class="pe" x="{x_pos}" y="{y_pos}" width="{PE_W}" height="{PE_H}"/>
    <text class="pe-name" x="{x_pos + 18}" y="{y_pos + 27}">PE({row},{column})</text>
    <text class="weight" x="{x_pos + PE_W - 18}" y="{y_pos + 27}" text-anchor="end">W({row},{column})</text>
    <text class="weight-bits" x="{x_pos + PE_W / 2:.1f}" y="{y_pos + 49}">{weight_text(mode, row, column)}</text>
    <line class="pe-rule" x1="{x_pos + 12}" y1="{y_pos + 60}" x2="{x_pos + PE_W - 12}" y2="{y_pos + 60}"/>
    {stage_line("D", token_d, d_value, "stage-d", x_pos + 18, y_pos + 83)}
    {stage_line("M", token_m, m_value, "stage-m", x_pos + 18, y_pos + 108)}
    {stage_line("LP", token_lp, lp_value_text, "stage-lp", x_pos + 18, y_pos + 133)}
    {stage_line("Q", token_q, q_value_text, "stage-q", x_pos + 18, y_pos + 158)}
    {stage_line("S", token_s, s_value_text, "stage-s", x_pos + 18, y_pos + 186)}
  </g>"""


def data_arrows(mode: Mode, edge: int) -> str:
    arrows: list[str] = []

    token_top = stage_token(mode, edge, 0, 0)
    if token_top is not None:
        for column in range(ARRAY_N):
            x_pos = data_port(column)
            word = fmt_vector(data_word(mode, token_top, 0, column))
            arrows.append(
                f'<path class="data-arrow" d="M{x_pos} {PE_Y0 - 56}V{PE_Y0 - 6}" '
                'marker-end="url(#arrow-data)"/>'
            )
            arrows.append(
                f'<text class="data-label" x="{x_pos}" y="{PE_Y0 - 66}">'
                f"m{token_top} {escape(word)}</text>"
            )

    for row in range(1, ARRAY_N):
        token = stage_token(mode, edge, row, 0)
        if token is None:
            continue

        source_y = pe_y(row - 1) + PE_H
        target_y = pe_y(row) - 6
        for target_column in range(ARRAY_N - 1):
            source_column = target_column + 1
            arrows.append(
                f'<path class="data-arrow" '
                f'd="M{data_port(source_column)} {source_y + 4}'
                f'L{data_port(target_column)} {target_y}" '
                'marker-end="url(#arrow-data)"/>'
            )

        wrap_source_x = data_port(0)
        wrap_target_x = data_port(ARRAY_N - 1)
        middle_y = source_y + 48
        arrows.append(
            f'<path class="data-arrow" '
            f'd="M{wrap_source_x} {source_y + 4} '
            f'C1715 {source_y + 8},1715 {target_y - 8},'
            f'{wrap_target_x} {target_y}" '
            'marker-end="url(#arrow-data)"/>'
        )
        arrows.append(
            f'<text class="move-label" x="1775" y="{middle_y + 22}">'
            f"m{token} C0→C3</text>"
        )

    return "\n  ".join(arrows)


def psum_arrows(mode: Mode, edge: int) -> str:
    arrows: list[str] = []
    top_token = stage_token(mode, edge, 0, 4)
    if top_token is not None:
        for column in range(ARRAY_N):
            x_pos = psum_port(column)
            q_text = fmt_vector(q_word(mode, top_token, 0, column))
            label = f"0+Q m{top_token}={q_text}"
            label_width = max(92, len(label) * 8)
            arrows.append(
                f'<path class="psum-arrow" d="M{x_pos} {PE_Y0 - 56}V{PE_Y0 - 6}" '
                'marker-end="url(#arrow-psum)"/>'
            )
            arrows.append(
                f'<rect class="label-bg" x="{x_pos - label_width / 2:.1f}" '
                f'y="{PE_Y0 - 88}" width="{label_width}" height="23"/>'
            )
            arrows.append(
                f'<text class="psum-label centered" x="{x_pos}" '
                f'y="{PE_Y0 - 71}">{escape(label)}</text>'
            )

    for row in range(1, ARRAY_N):
        token = stage_token(mode, edge, row, 4)
        if token is None:
            continue
        source_y = pe_y(row - 1) + PE_H
        target_y = pe_y(row) - 6
        for column in range(ARRAY_N):
            x_pos = psum_port(column)
            value_text = fmt_vector(
                s_word(mode, token, row - 1, column)
            )
            label = f"S m{token}={value_text}"
            label_width = max(86, len(label) * 8)
            arrows.append(
                f'<path class="psum-arrow" d="M{x_pos} {source_y + 4}V{target_y}" '
                'marker-end="url(#arrow-psum)"/>'
            )
            arrows.append(
                f'<rect class="label-bg" x="{x_pos + 8}" '
                f'y="{source_y + 29}" width="{label_width}" height="24"/>'
            )
            arrows.append(
                f'<text class="psum-label" x="{x_pos + 14}" '
                f'y="{source_y + 47}">{escape(label)}</text>'
            )
    return "\n  ".join(arrows)


def output_area(mode: Mode, edge: int) -> str:
    token = stage_token(mode, edge, ARRAY_N - 1, 4)
    if token is None:
        return """
  <line class="output-idle" x1="105" y1="1570" x2="1690" y2="1570"/>
  <text class="output-idle-text" x="897" y="1605">c_row_valid_o=0；c_row_o 当前不可采样</text>"""

    pieces: list[str] = []
    output_y = pe_y(ARRAY_N - 1) + PE_H
    for column in range(ARRAY_N):
        x_pos = psum_port(column)
        word = s_word(mode, token, ARRAY_N - 1, column)
        narrowed = [
            signed_wrap(value, mode.output_bits)
            for value in word
        ]
        pieces.append(
            f'<path class="output-arrow" d="M{x_pos} {output_y + 4}V1528" '
            'marker-end="url(#arrow-output)"/>'
        )
        pieces.append(
            f'<rect class="output-word" x="{pe_x(column) + 18}" y="1538" '
            f'width="{PE_W - 36}" height="82"/>'
        )
        pieces.append(
            f'<text class="output-word-title" x="{pe_x(column) + PE_W / 2:.1f}" '
            f'y="1560">physical word {column}</text>'
        )
        pieces.append(
            f'<text class="output-accum-value" x="{pe_x(column) + PE_W / 2:.1f}" '
            f'y="1585">acc={escape(fmt_vector(word))}</text>'
        )
        pieces.append(
            f'<text class="output-word-value" x="{pe_x(column) + PE_W / 2:.1f}" '
            f'y="1608">C={escape(fmt_vector(narrowed))}</text>'
        )

    pieces.append(
        f'<text class="output-valid" x="897" y="1650">'
        f"c_row_valid_o=1；输出逻辑行 m={token}</text>"
    )
    pieces.append(
        f'<text class="output-row" x="897" y="1684">'
        f"C[{token},:]={escape(fmt_vector(c_row(mode, token)))}</text>"
    )
    return "\n  ".join(pieces)


def s_write_lines(mode: Mode, edge: int) -> str:
    lines: list[str] = []
    y_pos = 875
    for row in range(ARRAY_N):
        token = stage_token(mode, edge, row, 4)
        if token is None:
            continue
        source = "0" if row == 0 else f"S(m{token},R{row - 1})@e{edge - 1}"
        lines.append(
            f'<text class="side-mono" x="{SIDEBAR_X + 30}" y="{y_pos}">'
            f"R{row}: S(m{token})=Q(m{token})+{source}</text>"
        )
        lines.append(
            f'<text class="side-value" x="{SIDEBAR_X + 48}" y="{y_pos + 25}">'
            f"{escape(fmt_full_row(mode, token, row, 'S'))}</text>"
        )
        y_pos += 65
    if not lines:
        lines.append(
            f'<text class="side-muted" x="{SIDEBAR_X + 30}" y="{y_pos}">'
            "本上升沿没有 psum_q 写入</text>"
        )
    return "\n  ".join(lines)


def sidebar(mode: Mode, edge: int) -> str:
    accepted = f"A 行 m={edge}" if edge < mode.logical_n else "无新 A 行"
    output_token = stage_token(mode, edge, ARRAY_N - 1, 4)
    output_status = (
        f"1，逻辑行 m={output_token}"
        if output_token is not None
        else "0"
    )

    return f"""
  <line class="divider" x1="{SIDEBAR_X}" y1="285" x2="{SIDEBAR_X}" y2="1695"/>
  <text class="side-title" x="{SIDEBAR_X + 30}" y="330">本周期寄存状态</text>
  <text class="side-text" x="{SIDEBAR_X + 30}" y="370">接收：{accepted}</text>
  <text class="side-text" x="{SIDEBAR_X + 30}" y="400">weight_valid_i={'1（最终装载拍）' if edge == 0 else '0'}</text>
  <text class="side-text" x="{SIDEBAR_X + 30}" y="430">data_valid_i={1 if edge < mode.logical_n else 0}</text>

  <text class="side-subtitle" x="{SIDEBAR_X + 30}" y="485">上升沿后 valid [R3:R0]</text>
  <text class="side-mono" x="{SIDEBAR_X + 30}" y="520">D / data_q          {valid_bits(mode, edge, 0)}</text>
  <text class="side-mono" x="{SIDEBAR_X + 30}" y="550">M / product_q       {valid_bits(mode, edge, 1)}</text>
  <text class="side-mono" x="{SIDEBAR_X + 30}" y="580">LP / logical_product_q {valid_bits(mode, edge, 2)}</text>
  <text class="side-mono" x="{SIDEBAR_X + 30}" y="610">Q / contribution_o  {valid_bits(mode, edge, 3)}</text>
  <text class="side-mono" x="{SIDEBAR_X + 30}" y="640">S / psum_q          {valid_bits(mode, edge, 4)}</text>

  <text class="side-subtitle" x="{SIDEBAR_X + 30}" y="690">token 编号</text>
  <text class="side-mono" x="{SIDEBAR_X + 30}" y="725">mD=e-R　mM=e-R-1</text>
  <text class="side-mono" x="{SIDEBAR_X + 30}" y="755">mLP=e-R-2　mQ=e-R-3</text>
  <text class="side-mono" x="{SIDEBAR_X + 30}" y="785">mS=e-R-4</text>
  <text class="side-text" x="{SIDEBAR_X + 30}" y="818">五组使能与五组 valid 同形。</text>

  <text class="side-subtitle" x="{SIDEBAR_X + 30}" y="850">本上升沿写入的部分和</text>
  {s_write_lines(mode, edge)}

  <text class="side-subtitle" x="{SIDEBAR_X + 30}" y="1200">输出端口</text>
  <text class="side-text" x="{SIDEBAR_X + 30}" y="1238">c_row_valid_o={output_status}</text>
  <text class="side-text" x="{SIDEBAR_X + 30}" y="1270">输出格式：{mode.output_desc}</text>
  <text class="side-text" x="{SIDEBAR_X + 30}" y="1302">每段截取 psum_q 的低 {mode.output_bits} bit。</text>
  <text class="side-text" x="{SIDEBAR_X + 30}" y="1334">c_accum_row_o 将有效段符号扩展到 64 bit。</text>

  <text class="side-subtitle" x="{SIDEBAR_X + 30}" y="1385">数值例子</text>
  <text class="side-mono" x="{SIDEBAR_X + 30}" y="1423">A[m,k]=((3m+k) mod 7)-3</text>
  <text class="side-mono" x="{SIDEBAR_X + 30}" y="1453">B[k,j]=((2k+j) mod 5)-2</text>
  <text class="side-text" x="{SIDEBAR_X + 30}" y="1490">A、B 元素均在 INT4 可表示范围内。</text>
  <text class="side-text" x="{SIDEBAR_X + 30}" y="1525">LP、Q、S 和 C 为脚本按 RTL 公式计算的值。</text>
"""


def svg_for(mode: Mode, edge: int) -> str:
    pe_cells = "\n".join(
        pe_cell(mode, edge, row, column)
        for row in range(ARRAY_N)
        for column in range(ARRAY_N)
    )
    row_labels = "\n".join(
        f'<text class="row-label" x="55" y="{pe_y(row) + PE_H / 2:.1f}">R{row}</text>'
        for row in range(ARRAY_N)
    )
    column_labels = "\n".join(
        f'<text class="column-label" x="{pe_x(column) + PE_W / 2:.1f}" y="300">C{column}</text>'
        for column in range(ARRAY_N)
    )

    return f"""<svg xmlns="http://www.w3.org/2000/svg" width="{CANVAS_W}" height="{CANVAS_H}" viewBox="0 0 {CANVAS_W} {CANVAS_H}" role="img" aria-labelledby="title desc">
  <title id="title">{mode.name} Cycle {edge} DiP RTL 寄存状态</title>
  <desc id="desc">四乘四物理阵列在上升沿 e{edge} 之后的完整有效寄存状态，显示数据移动、四级算术寄存、同列部分和与输出端口。</desc>
  <defs>
    <style>
      .title {{ font: 700 34px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #111827; }}
      .subtitle {{ font: 700 17px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #374151; }}
      .config {{ font: 700 15px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #111827; }}
      .cycle {{ font: 700 29px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #111827; text-anchor: middle; }}
      .pe {{ fill: #f8f8f8; stroke: #111111; stroke-width: 3.2; }}
      .pe-name {{ font: 700 17px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #111111; }}
      .weight {{ font: 700 16px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #111111; }}
      .weight-bits {{ font: 700 12px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #111111; text-anchor: middle; }}
      .pe-rule {{ stroke: #a3a3a3; stroke-width: 1.2; }}
      .stage-d {{ font: 700 15px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #0077bd; }}
      .stage-m {{ font: 700 13px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #4b5563; }}
      .stage-lp {{ font: 700 13px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #5b5563; }}
      .stage-q {{ font: 700 15px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #153e75; }}
      .stage-s {{ font: 700 16px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #092f6e; }}
      .slot-off {{ font: 700 14px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #c7c7c7; }}
      .row-label, .column-label {{ font: 700 19px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #111827; text-anchor: middle; }}
      .data-arrow {{ fill: none; stroke: #0077bd; stroke-width: 4; }}
      .data-label {{ font: 700 13px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #0077bd; text-anchor: middle; }}
      .move-label {{ font: 700 12px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #0077bd; text-anchor: end; }}
      .psum-arrow {{ fill: none; stroke: #666666; stroke-width: 4; }}
      .psum-label {{ font: 700 12px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #4b5563; }}
      .centered {{ text-anchor: middle; }}
      .label-bg {{ fill: #ffffff; opacity: 0.94; }}
      .output-arrow {{ fill: none; stroke: #555555; stroke-width: 4; }}
      .output-word {{ fill: #ffffff; stroke: #0b2f6b; stroke-width: 2.2; }}
      .output-word-title {{ font: 700 13px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #111827; text-anchor: middle; }}
      .output-accum-value {{ font: 700 13px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #374151; text-anchor: middle; }}
      .output-word-value {{ font: 700 16px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #0b2f6b; text-anchor: middle; }}
      .output-valid {{ font: 700 20px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #0b2f6b; text-anchor: middle; }}
      .output-row {{ font: 700 18px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #0b2f6b; text-anchor: middle; }}
      .output-idle {{ stroke: #c7c7c7; stroke-width: 2; }}
      .output-idle-text {{ font: 700 17px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #9ca3af; text-anchor: middle; }}
      .divider {{ stroke: #111111; stroke-width: 1.8; }}
      .side-title {{ font: 700 25px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #111827; }}
      .side-subtitle {{ font: 700 18px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #111827; }}
      .side-text {{ font: 700 15px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #374151; }}
      .side-mono {{ font: 700 14px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #1f2937; }}
      .side-value {{ font: 700 12px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #0b2f6b; }}
      .side-muted {{ font: 700 15px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #9ca3af; }}
      .note {{ font: 700 14px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #4b5563; }}
    </style>
    <marker id="arrow-data" markerWidth="10" markerHeight="10" refX="8" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#0077bd"/>
    </marker>
    <marker id="arrow-psum" markerWidth="10" markerHeight="10" refX="8" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#666666"/>
    </marker>
    <marker id="arrow-output" markerWidth="10" markerHeight="10" refX="8" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#555555"/>
    </marker>
  </defs>

  <rect width="{CANVAS_W}" height="{CANVAS_H}" fill="#ffffff"/>
  <text class="title" x="50" y="55">{mode.name} DiP：Cycle {edge}（e{edge} 上升沿后）</text>
  <text class="subtitle" x="50" y="92">每个 PE 同时显示有效的 data_q、product_q、logical_product_q、contribution_o 与 psum_q；A 行连续输入。</text>
  <line x1="50" y1="115" x2="2505" y2="115" stroke="#111111" stroke-width="1.5"/>
  <text class="config" x="50" y="150">ARRAY_N=4　mode_i={mode.mode_bits}　w={mode.width}　lanes={mode.lanes}　L={mode.logical_n}</text>
  <text class="config" x="50" y="180">M=16×8-bit　LP={mode.logical_products_per_pe}×INT32　Q/S={mode.contribution_desc}　C={mode.output_desc}</text>
  <text class="config" x="50" y="210">{equation_text(mode)}</text>
  <text class="subtitle" x="50" y="250">蓝色：packed A；灰色：同列部分和；深蓝色：局部贡献、部分和与输出。PE 框显示 e{edge} 后寄存值；箭头显示该上升沿读取的沿前值。</text>

  {column_labels}
  {row_labels}
  {data_arrows(mode, edge)}
  {psum_arrows(mode, edge)}
  {pe_cells}
  {output_area(mode, edge)}
  {sidebar(mode, edge)}

  <text class="note" x="50" y="1740">灰色竖箭头表示本上升沿读取上一物理行保存的 S；读取不会清除源 PE 的 psum_q。</text>
  <text class="note" x="50" y="1770">PE 框内只列出 valid=1 的 D/M/LP/Q/S；Q 是 contribution_o 的触发器输出，不是组合中间值。</text>
  <text class="note" x="50" y="1800">Cycle 7 首次得到完整输出行；默认 ARRAY_N=16 时首行在 e19 上升沿后有效。</text>
  <text class="cycle" x="897" y="1810">Cycle {edge}</text>
</svg>
"""


def verify_model(mode: Mode) -> None:
    """Check LP, Q, bottom S, and the first-output schedule."""

    for token in range(mode.logical_n):
        for row in range(ARRAY_N):
            for column in range(ARRAY_N):
                products = logical_product_word(
                    mode, token, row, column
                )
                for out_lane in range(mode.lanes):
                    start = out_lane * mode.lanes
                    reduced = signed_wrap(
                        sum(products[start:start + mode.lanes]),
                        mode.accumulator_bits,
                    )
                    expected_q = q_lane(
                        mode, token, row, column, out_lane
                    )
                    if reduced != expected_q:
                        raise RuntimeError(
                            f"{mode.name} LP/Q mismatch for token "
                            f"{token}, PE({row},{column}), lane "
                            f"{out_lane}: {reduced} != {expected_q}"
                        )

        expected = []
        for column in range(mode.logical_n):
            total = 0
            for k_index in range(mode.logical_n):
                total = signed_wrap(
                    total
                    + a_value(mode, token, k_index)
                    * b_value(mode, k_index, column),
                    mode.accumulator_bits,
                )
            expected.append(signed_wrap(total, mode.output_bits))
        if c_row(mode, token) != expected:
            raise RuntimeError(
                f"{mode.name} model mismatch for token {token}: "
                f"{c_row(mode, token)} != {expected}"
            )

    for edge in range(FIRST_OUTPUT_EDGE):
        if stage_token(mode, edge, ARRAY_N - 1, 4) is not None:
            raise RuntimeError(
                f"{mode.name} produced an output before e"
                f"{FIRST_OUTPUT_EDGE}"
            )
    if stage_token(
        mode, FIRST_OUTPUT_EDGE, ARRAY_N - 1, 4
    ) != 0:
        raise RuntimeError(
            f"{mode.name} first output is not token 0 at "
            f"e{FIRST_OUTPUT_EDGE}"
        )


def render_png(svg_path: Path, png_path: Path) -> None:
    subprocess.run(
        [
            "inkscape",
            str(svg_path),
            "--export-type=png",
            f"--export-filename={png_path}",
        ],
        check=True,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )


def write_manifest(mode: Mode, output_dir: Path, files: list[str]) -> None:
    cycles = []
    for edge in range(FIRST_OUTPUT_EDGE + 1):
        output_token = stage_token(mode, edge, ARRAY_N - 1, 4)
        cycles.append(
            {
                "edge": edge,
                "accepted_a_row": edge if edge < mode.logical_n else None,
                "valid_r3_to_r0": {
                    "data_q": valid_bits(mode, edge, 0),
                    "product_q": valid_bits(mode, edge, 1),
                    "logical_product_q": valid_bits(mode, edge, 2),
                    "contribution_o": valid_bits(mode, edge, 3),
                    "psum_q": valid_bits(mode, edge, 4),
                },
                "c_row_valid": output_token is not None,
                "c_row_index": output_token,
                "c_row": (
                    c_row(mode, output_token)
                    if output_token is not None
                    else None
                ),
            }
        )

    manifest = {
        "mode": mode.name,
        "mode_bits": mode.mode_bits,
        "array_n": ARRAY_N,
        "logical_n": mode.logical_n,
        "lanes": mode.lanes,
        "input_width": mode.width,
        "accumulator_width_per_lane": mode.accumulator_bits,
        "output_width_per_lane": mode.output_bits,
        "first_a_edge": 0,
        "first_output_edge": FIRST_OUTPUT_EDGE,
        "last_generated_edge": FIRST_OUTPUT_EDGE,
        "input_schedule": "one A row per edge, starting at e0",
        "example": {
            "A": "A[m,k]=((3*m+k) mod 7)-3",
            "B": "B[k,j]=((2*k+j) mod 5)-2",
        },
        "png_files": files,
        "cycles": cycles,
    }
    (output_dir / "trace_manifest.json").write_text(
        json.dumps(manifest, ensure_ascii=False, indent=2) + "\n",
        encoding="utf-8",
    )


def main() -> None:
    root = Path(__file__).resolve().parent / "cycle_traces"
    root.mkdir(parents=True, exist_ok=True)

    for mode in MODES:
        verify_model(mode)
        output_dir = root / f"{mode.slug}_n04"
        output_dir.mkdir(parents=True, exist_ok=True)
        png_files: list[str] = []

        for edge in range(FIRST_OUTPUT_EDGE + 1):
            stem = f"dip_{mode.slug}_n04_compute_e{edge:03d}_post"
            svg_path = output_dir / f"{stem}.svg"
            png_path = output_dir / f"{stem}.png"
            svg_path.write_text(svg_for(mode, edge), encoding="utf-8")
            render_png(svg_path, png_path)
            png_files.append(png_path.name)

        write_manifest(mode, output_dir, png_files)
        print(
            f"{mode.name}: generated {len(png_files)} cycle-separated PNGs "
            f"in {output_dir}"
        )


if __name__ == "__main__":
    main()
