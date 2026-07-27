#!/usr/bin/env python3
"""Generate paper-style, register-accurate DiP cycle snapshots."""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True)
class Mode:
    filename: str
    name: str
    mode_bits: str
    width: int
    lanes: int
    logical_n: int
    pe_products: int
    array_products: int
    contribution: str
    accumulator: str
    output_word: str
    output_elements: int
    equation: str
    selection: str


MODES = (
    Mode(
        filename="rtl_cycle_trace_int16.svg",
        name="INT16",
        mode_bits="2'b00",
        width=16,
        lanes=1,
        logical_n=4,
        pe_products=1,
        array_products=16,
        contribution="1×64 bit",
        accumulator="1×64 bit",
        output_word="1×INT32",
        output_elements=4,
        equation="Q[R,C,0] = A[m,k] × B[k,C]，k=(R+C) mod 4",
        selection="u=v=0；每个 PE 只读取本地 data_q。",
    ),
    Mode(
        filename="rtl_cycle_trace_int8.svg",
        name="INT8",
        mode_bits="2'b01",
        width=8,
        lanes=2,
        logical_n=8,
        pe_products=4,
        array_products=64,
        contribution="2×32 bit",
        accumulator="2×32 bit",
        output_word="2×INT16",
        output_elements=8,
        equation="Q[R,C,v] = Σ(u=0..1) A[m,k] × B[k,2C+v]，k=(2(R+C)+u+v) mod 8",
        selection="每个 PE 形成 4 个 8×8 乘法；(u,v)=(1,1) 读取同行右邻。",
    ),
    Mode(
        filename="rtl_cycle_trace_int4.svg",
        name="INT4",
        mode_bits="2'b10",
        width=4,
        lanes=4,
        logical_n=16,
        pe_products=16,
        array_products=256,
        contribution="4×16 bit",
        accumulator="4×16 bit",
        output_word="4×INT8",
        output_elements=16,
        equation="Q[R,C,v] = Σ(u=0..3) A[m,k] × B[k,4C+v]，k=(4(R+C)+u+v) mod 16",
        selection="每个 PE 形成 16 个 4×4 乘法；u+v≥4 的 6 项读取同行右邻。",
    ),
)


PANEL_POSITIONS = (
    (40, 390),
    (590, 390),
    (1140, 390),
    (1690, 390),
    (315, 800),
    (865, 800),
    (1415, 800),
)

STAGES = (
    ("D", "stage-d"),
    ("M", "stage-m"),
    ("Q", "stage-q"),
    ("S", "stage-s"),
)


def data_word(mode: Mode, row: int, column: int) -> str:
    start = (mode.lanes * (row + column)) % mode.logical_n
    indices = [(start + lane) % mode.logical_n for lane in range(mode.lanes)]
    if mode.lanes == 1:
        return f"A{indices[0]}"
    if mode.lanes == 2:
        return f"[A{indices[0]},A{indices[1]}]"
    return f"A{indices[0]}…A{indices[-1]}"


def stage_for(edge: int, row: int) -> str | None:
    offset = edge - row
    if 0 <= offset < len(STAGES):
        return STAGES[offset][0]
    return None


def cell(mode: Mode, edge: int, row: int, column: int, x_pos: int, y_pos: int) -> str:
    stage = stage_for(edge, row)
    if stage is None:
        return (
            f'<rect class="idle" x="{x_pos}" y="{y_pos}" width="98" height="54"/>'
            f'<text class="weight" x="{x_pos + 49}" y="{y_pos + 33}">W[{row},{column}]</text>'
        )

    stage_class = dict(STAGES)[stage]
    if stage == "D":
        line_1 = data_word(mode, row, column)
        line_2 = "data_q"
    elif stage == "M":
        line_1 = f"M[{row},{column}]"
        line_2 = "16 radix"
    elif stage == "Q":
        line_1 = f"Q[{row},{column}]"
        line_2 = mode.contribution
    else:
        line_1 = f"S[{row},{column}]"
        line_2 = f"Σ row 0…{row}"

    return (
        f'<rect class="{stage_class}" x="{x_pos}" y="{y_pos}" width="98" height="54"/>'
        f'<text class="cellmain" x="{x_pos + 49}" y="{y_pos + 23}">{line_1}</text>'
        f'<text class="cellsub" x="{x_pos + 49}" y="{y_pos + 43}">{line_2}</text>'
    )


def panel(mode: Mode, edge: int, x_pos: int, y_pos: int) -> str:
    stage_names = []
    for row in range(4):
        stage = stage_for(edge, row)
        if stage is not None:
            stage_names.append(f"{stage}{row}")
    active_summary = " + ".join(stage_names) if stage_names else "排空"

    rows = []
    for row in range(4):
        row_y = y_pos + 82 + 61 * row
        rows.append(
            f'<text class="rowlabel" x="{x_pos + 50}" y="{row_y + 32}">'
            f'<tspan x="{x_pos + 50}" dy="-8">row {row}</tspan>'
            f'<tspan class="rowweight" x="{x_pos + 50}" dy="20">W 保持</tspan>'
            f"</text>"
        )
        for column in range(4):
            cell_x = x_pos + 92 + 102 * column
            rows.append(cell(mode, edge, row, column, cell_x, row_y))

    output = ""
    if edge == 6:
        output = f"""
    <path class="gather" d="M{x_pos + 141} {y_pos + 319}V{y_pos + 329} M{x_pos + 243} {y_pos + 319}V{y_pos + 329} M{x_pos + 345} {y_pos + 319}V{y_pos + 329} M{x_pos + 447} {y_pos + 319}V{y_pos + 329} M{x_pos + 141} {y_pos + 329}H{x_pos + 447}"/>
    <path class="outarrow" d="M{x_pos + 294} {y_pos + 329}V{y_pos + 342}" marker-end="url(#arrow-out)"/>
    <rect class="output" x="{x_pos + 32}" y="{y_pos + 345}" width="446" height="48"/>
    <text class="outputtext" x="{x_pos + 255}" y="{y_pos + 366}">c_row_valid_o=1</text>
    <text class="outputsub" x="{x_pos + 255}" y="{y_pos + 386}">{mode.output_elements} 个结果：4 个物理 word × {mode.output_word}</text>"""
    else:
        if edge <= 2:
            note = "D 下一拍：C0←C1，C1←C2，C2←C3，C3←C0"
            note_class = "movehint"
        elif edge == 3:
            note = "D 已到最后物理行；M、Q、S 继续"
            note_class = "next"
        else:
            note = "同一 A 行继续进入下一拍"
            note_class = "next"
        output = (
            f'<text class="{note_class}" x="{x_pos + 255}" y="{y_pos + 370}">'
            f"{note}"
            "</text>"
        )

    return f"""
  <g>
    <rect class="panel" x="{x_pos}" y="{y_pos}" width="510" height="400"/>
    <rect class="panelhead" x="{x_pos}" y="{y_pos}" width="510" height="64"/>
    <text class="paneltitle" x="{x_pos + 255}" y="{y_pos + 28}">e{edge}</text>
    <text class="panelsub" x="{x_pos + 255}" y="{y_pos + 52}">{active_summary}</text>
    {''.join(rows)}
    {output}
  </g>"""


def transitions() -> str:
    arrows = []
    for left_index in range(3):
        x_start = PANEL_POSITIONS[left_index][0] + 510
        x_end = PANEL_POSITIONS[left_index + 1][0] - 4
        arrows.append(
            f'<path class="step" d="M{x_start} 590H{x_end}" '
            'marker-end="url(#arrow-step)"/>'
        )
    for left_index in range(4, 6):
        x_start = PANEL_POSITIONS[left_index][0] + 510
        x_end = PANEL_POSITIONS[left_index + 1][0] - 4
        arrows.append(
            f'<path class="step" d="M{x_start} 1000H{x_end}" '
            'marker-end="url(#arrow-step)"/>'
        )
    arrows.append(
        '<path class="step" d="M2200 748V795H829" '
        'marker-end="url(#arrow-step)"/>'
    )
    return "\n  ".join(arrows)


def svg_for(mode: Mode) -> str:
    panels = "\n".join(
        panel(mode, edge, *PANEL_POSITIONS[edge]) for edge in range(7)
    )
    return f"""<svg xmlns="http://www.w3.org/2000/svg" width="2240" height="1310" viewBox="0 0 2240 1310" role="img" aria-labelledby="title desc">
  <title id="title">{mode.name} 模式逐拍数据分布</title>
  <desc id="desc">在 4×4 物理阵列实例中，以七个连续阵列快照展示首个 A 行从输入寄存器、基础乘积、局部贡献、部分和到输出端口有效的过程。</desc>
  <defs>
    <style>
      .title {{ font: 700 31px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #0f172a; }}
      .h2 {{ font: 700 20px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #0f172a; text-anchor: middle; }}
      .label {{ font: 700 16px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #334155; text-anchor: middle; }}
      .small {{ font: 700 14px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #475569; text-anchor: middle; }}
      .left {{ text-anchor: start; }}
      .mono {{ font: 700 14px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #0f172a; text-anchor: middle; }}
      .summary {{ fill: #eff6ff; stroke: #93c5fd; stroke-width: 1.6; rx: 12; }}
      .formula {{ fill: #fff7ed; stroke: #fdba74; stroke-width: 1.6; rx: 12; }}
      .legend {{ fill: #f8fafc; stroke: #cbd5e1; stroke-width: 1.4; rx: 10; }}
      .panel {{ fill: #ffffff; stroke: #94a3b8; stroke-width: 1.6; rx: 12; }}
      .panelhead {{ fill: #f8fafc; stroke: #94a3b8; stroke-width: 1.4; rx: 12; }}
      .paneltitle {{ font: 700 21px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #0f172a; text-anchor: middle; }}
      .panelsub {{ font: 700 13px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #475569; text-anchor: middle; }}
      .rowlabel {{ font: 700 13px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #334155; text-anchor: middle; }}
      .rowweight {{ font-size: 12px; fill: #92400e; }}
      .idle {{ fill: #f8fafc; stroke: #cbd5e1; stroke-width: 1.2; rx: 7; }}
      .stage-d {{ fill: #dbeafe; stroke: #2563eb; stroke-width: 1.7; rx: 7; }}
      .stage-m {{ fill: #ffedd5; stroke: #d97706; stroke-width: 1.7; rx: 7; }}
      .stage-q {{ fill: #fef3c7; stroke: #ca8a04; stroke-width: 1.7; rx: 7; }}
      .stage-s {{ fill: #ede9fe; stroke: #7c3aed; stroke-width: 1.7; rx: 7; }}
      .weight {{ font: 700 12px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #64748b; text-anchor: middle; }}
      .cellmain {{ font: 700 12px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #0f172a; text-anchor: middle; }}
      .cellsub {{ font: 700 12px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #475569; text-anchor: middle; }}
      .next {{ font: 700 12px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #64748b; text-anchor: middle; }}
      .movehint {{ font: 700 12px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #2563eb; text-anchor: middle; }}
      .step {{ fill: none; stroke: #64748b; stroke-width: 2.2; }}
      .outarrow {{ fill: none; stroke: #7c3aed; stroke-width: 2.5; }}
      .gather {{ fill: none; stroke: #7c3aed; stroke-width: 2; }}
      .output {{ fill: #f0fdf4; stroke: #059669; stroke-width: 1.7; rx: 8; }}
      .outputtext {{ font: 700 14px "JetBrains Mono", "DejaVu Sans Mono", monospace; fill: #065f46; text-anchor: middle; }}
      .outputsub {{ font: 700 11px "Noto Sans CJK SC", "Microsoft YaHei", sans-serif; fill: #047857; text-anchor: middle; }}
    </style>
    <marker id="arrow-step" markerWidth="10" markerHeight="10" refX="8" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#64748b"/>
    </marker>
    <marker id="arrow-out" markerWidth="10" markerHeight="10" refX="8" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#7c3aed"/>
    </marker>
  </defs>

  <rect width="2240" height="1310" fill="#ffffff"/>
  <text x="40" y="48" class="title">{mode.name}：4×4 物理阵列中首个 A 行的逐拍数据分布</text>
  <text x="40" y="80" class="small left">该图使用当前 RTL 的真实寄存器次序；e0 同拍接收最终预处理权重行和 A[0,:]，e6 上升沿后输出端口首次有效。</text>

  <rect class="summary" x="40" y="105" width="2160" height="82"/>
  <text x="400" y="137" class="h2">{mode.name} 配置</text>
  <text x="400" y="166" class="mono">ARRAY_N=4　mode_i={mode.mode_bits}　w={mode.width}　lanes={mode.lanes}　L={mode.logical_n}</text>
  <text x="1120" y="137" class="h2">并行工作量</text>
  <text x="1120" y="166" class="mono">{mode.pe_products} 逻辑乘法/PE/周期　{mode.array_products} 逻辑乘法/阵列/周期</text>
  <text x="1840" y="137" class="h2">局部贡献、部分和与输出</text>
  <text x="1840" y="166" class="mono">Q={mode.contribution}　S={mode.accumulator}　C word={mode.output_word}</text>

  <rect class="formula" x="40" y="205" width="2160" height="86"/>
  <text x="1120" y="236" class="mono">{mode.equation}</text>
  <text x="1120" y="264" class="mono">S[R,C,v] = Q[R,C,v] + (R=0 ? 0 : S[R-1,C,v])</text>
  <text x="1120" y="285" class="small">{mode.selection}</text>

  <rect class="legend" x="40" y="310" width="2160" height="60"/>
  <text x="105" y="346" class="label">颜色</text>
  <rect class="stage-d" x="180" y="324" width="68" height="32"/><text x="214" y="345" class="mono">D</text><text x="265" y="345" class="small left">data_q 与 packed A</text>
  <rect class="stage-m" x="590" y="324" width="68" height="32"/><text x="624" y="345" class="mono">M</text><text x="675" y="345" class="small left">product_q：16 个基础乘积</text>
  <rect class="stage-q" x="1110" y="324" width="68" height="32"/><text x="1144" y="345" class="mono">Q</text><text x="1195" y="345" class="small left">contribution_o</text>
  <rect class="stage-s" x="1560" y="324" width="68" height="32"/><text x="1594" y="345" class="mono">S</text><text x="1645" y="345" class="small left">psum_q；已累计到当前物理行</text>

  {transitions()}
  {panels}

  <text x="40" y="1230" class="small left">蓝色 D 每拍进入下一物理行，并循环左移一个 16-bit 物理字；橙色 M、黄色 Q、紫色 S 分别表示同一 A 行在三级算术流水中的三个寄存结果。</text>
  <text x="40" y="1255" class="small left">灰色单元表示本上升沿没有属于该 A 行的有效 D、M、Q 或 S；寄存器可保留旧位值，但相应 valid 为 0。</text>
  <text x="40" y="1280" class="small left">通式为 e_first=e(N+2)。本图 N=4，所以 e6 首次输出；默认 N=16 时同一过程继续到 e18。</text>
</svg>
"""


def main() -> None:
    output_dir = Path(__file__).resolve().parent
    for mode in MODES:
        (output_dir / mode.filename).write_text(svg_for(mode), encoding="utf-8")


if __name__ == "__main__":
    main()
