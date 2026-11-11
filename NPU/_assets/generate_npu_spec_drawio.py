#!/usr/bin/env python3
"""Generate editable draw.io sources for the NPU hardware design specification.

The generated files deliberately contain only design-level names.  They are
uncompressed mxGraph documents so reviewers can edit every box, connector and
waveform in draw.io without depending on this script.
"""

from __future__ import annotations

import argparse
import html
import json
import pathlib
import uuid
import xml.etree.ElementTree as ET


ASSET_DIR = pathlib.Path(__file__).resolve().parent
FONT = "Noto Sans CJK SC"
ONLY_NAMES: set[str] | None = None

COLORS = {
    "ink": "#17324D",
    "muted": "#475569",
    "line": "#64748B",
    "grid": "#CBD5E1",
    "blue": "#2563EB",
    "blue_fill": "#DBEAFE",
    "cyan": "#0891B2",
    "cyan_fill": "#CFFAFE",
    "teal": "#0F766E",
    "teal_fill": "#CCFBF1",
    "green": "#059669",
    "green_fill": "#D1FAE5",
    "amber": "#D97706",
    "amber_fill": "#FEF3C7",
    "purple": "#7C3AED",
    "purple_fill": "#F3E8FF",
    "red": "#DC2626",
    "red_fill": "#FEE2E2",
    "gray_fill": "#F8FAFC",
    "white": "#FFFFFF",
}


def _label(title: str, detail: str | None = None) -> str:
    title_html = html.escape(title).replace("\n", "<br>")
    if not detail:
        return f"<b>{title_html}</b>"
    detail_html = html.escape(detail).replace("\n", "<br>")
    return f"<b>{title_html}</b><br><font color=\"{COLORS['muted']}\">{detail_html}</font>"


class Drawio:
    def __init__(self, name: str, title: str, width: int = 1600, height: int = 900):
        self.name = name
        self.title = title
        self.width = width
        self.height = height
        self._next = 2
        self.mxfile = ET.Element(
            "mxfile",
            host="Electron",
            agent="NPU design specification",
            version="31.3.2",
            compressed="false",
        )
        diagram = ET.SubElement(
            self.mxfile, "diagram", id=uuid.uuid4().hex[:12], name="Page-1"
        )
        self.model = ET.SubElement(
            diagram,
            "mxGraphModel",
            dx="1600",
            dy="900",
            grid="1",
            gridSize="10",
            guides="1",
            tooltips="1",
            connect="1",
            arrows="1",
            fold="1",
            page="1",
            pageScale="1",
            pageWidth=str(width),
            pageHeight=str(height),
            background="#FFFFFF",
            math="1",
            shadow="0",
        )
        self.root = ET.SubElement(self.model, "root")
        ET.SubElement(self.root, "mxCell", id="0")
        ET.SubElement(self.root, "mxCell", id="1", parent="0")
        self.text(title, 40, 14, width - 80, 52, size=30, bold=True, color=COLORS["ink"])

    def _id(self, prefix: str = "c") -> str:
        value = f"{prefix}{self._next}"
        self._next += 1
        return value

    def vertex(
        self,
        value: str,
        x: float,
        y: float,
        w: float,
        h: float,
        *,
        fill: str = COLORS["white"],
        stroke: str = COLORS["line"],
        size: int = 14,
        rounded: int = 1,
        bold: bool = False,
        parent: str = "1",
        align: str = "center",
        valign: str = "middle",
        font_color: str = COLORS["ink"],
        stroke_width: float = 1.5,
        extra: str = "",
    ) -> str:
        # 规范图在文档中会按页面宽度缩放。18 pt 是所有可见文字的
        # 硬性下限，避免辅助说明和接口名称在缩放后难以辨认。
        size = max(size, 18)
        cell_id = self._id("v")
        if bold and not value.lstrip().startswith("<b>"):
            value = f"<b>{value}</b>"
        style = (
            f"rounded={rounded};whiteSpace=wrap;html=1;fillColor={fill};"
            f"strokeColor={stroke};strokeWidth={stroke_width};fontFamily={FONT};"
            f"fontSize={size};fontColor={font_color};align={align};"
            f"fontStyle=1;verticalAlign={valign};spacing=8;arcSize=12;{extra}"
        )
        cell = ET.SubElement(
            self.root,
            "mxCell",
            id=cell_id,
            value=value,
            style=style,
            vertex="1",
            parent=parent,
        )
        ET.SubElement(
            cell,
            "mxGeometry",
            x=str(x),
            y=str(y),
            width=str(w),
            height=str(h),
            **{"as": "geometry"},
        )
        return cell_id

    def text(
        self,
        value: str,
        x: float,
        y: float,
        w: float,
        h: float,
        *,
        size: int = 13,
        bold: bool = False,
        color: str = COLORS["muted"],
        align: str = "left",
    ) -> str:
        if bold:
            value = f"<b>{html.escape(value)}</b>"
        else:
            value = html.escape(value)
        return self.vertex(
            value,
            x,
            y,
            w,
            h,
            fill="none",
            stroke="none",
            size=size,
            rounded=0,
            align=align,
            stroke_width=0,
            extra=f"fontColor={color};spacing=0;",
        )

    def container(
        self,
        title: str,
        x: float,
        y: float,
        w: float,
        h: float,
        *,
        fill: str = COLORS["gray_fill"],
        stroke: str = COLORS["grid"],
        size: int = 16,
    ) -> str:
        return self.vertex(
            f"<b>{html.escape(title)}</b>",
            x,
            y,
            w,
            h,
            fill=fill,
            stroke=stroke,
            size=size,
            rounded=1,
            align="left",
            valign="top",
            stroke_width=1.6,
            # Large hierarchy containers use a restrained corner radius so the
            # section title stays inside the straight-edge safe region instead
            # of entering the rounded-corner envelope.
            extra="arcSize=4;spacingTop=12;spacingLeft=24;container=1;collapsible=0;",
        )

    def edge(
        self,
        source: str,
        target: str,
        value: str = "",
        *,
        color: str = COLORS["blue"],
        dashed: bool = False,
        both: bool = False,
        width: float = 1.8,
        waypoints: list[tuple[float, float]] | None = None,
        exit_x: float | None = None,
        exit_y: float | None = None,
        entry_x: float | None = None,
        entry_y: float | None = None,
        font_size: int = 12,
        label_x: float = 0,
        label_y: float = 0,
        straight: bool = False,
    ) -> str:
        font_size = max(font_size, 18)
        cell_id = self._id("e")
        edge_style = (
            "edgeStyle=none;rounded=0;"
            if straight
            else "edgeStyle=orthogonalEdgeStyle;rounded=0;orthogonalLoop=1;jettySize=18;"
        )
        style = (
            f"{edge_style}html=1;"
            f"strokeColor={color};strokeWidth={width};fontFamily={FONT};fontSize={font_size};"
            f"fontColor={COLORS['muted']};labelBackgroundColor={COLORS['white']};"
            "endArrow=block;endFill=1;"
        )
        if both:
            style += "startArrow=block;startFill=1;"
        if dashed:
            style += "dashed=1;dashPattern=5 4;"
        if exit_x is not None:
            style += f"exitX={exit_x};exitY={exit_y};exitDx=0;exitDy=0;"
        if entry_x is not None:
            style += f"entryX={entry_x};entryY={entry_y};entryDx=0;entryDy=0;"
        cell = ET.SubElement(
            self.root,
            "mxCell",
            id=cell_id,
            value=html.escape(value),
            style=style,
            edge="1",
            parent="1",
            source=source,
            target=target,
        )
        geom = ET.SubElement(cell, "mxGeometry", relative="1", x=str(label_x), y=str(label_y), **{"as": "geometry"})
        if waypoints:
            arr = ET.SubElement(geom, "Array", **{"as": "points"})
            for px, py in waypoints:
                ET.SubElement(arr, "mxPoint", x=str(px), y=str(py))
        return cell_id

    def segment(
        self,
        points: list[tuple[float, float]],
        *,
        color: str = COLORS["blue"],
        width: float = 2.2,
        dashed: bool = False,
        arrow: bool = False,
        curved: bool = False,
    ) -> str:
        cell_id = self._id("s")
        curve_style = (
            "edgeStyle=none;rounded=1;curved=1;"
            if curved else "edgeStyle=none;rounded=0;curved=0;"
        )
        style = (
            f"{curve_style}html=1;strokeColor={color};strokeWidth={width};"
            f"endArrow={'block' if arrow else 'none'};endFill=1;"
        )
        if dashed:
            style += "dashed=1;dashPattern=4 4;"
        cell = ET.SubElement(
            self.root, "mxCell", id=cell_id, style=style, edge="1", parent="1"
        )
        geom = ET.SubElement(cell, "mxGeometry", relative="1", **{"as": "geometry"})
        ET.SubElement(geom, "mxPoint", x=str(points[0][0]), y=str(points[0][1]), **{"as": "sourcePoint"})
        if len(points) > 2:
            arr = ET.SubElement(geom, "Array", **{"as": "points"})
            for px, py in points[1:-1]:
                ET.SubElement(arr, "mxPoint", x=str(px), y=str(py))
        ET.SubElement(geom, "mxPoint", x=str(points[-1][0]), y=str(points[-1][1]), **{"as": "targetPoint"})
        return cell_id

    def write(self) -> pathlib.Path | None:
        if ONLY_NAMES is not None and self.name not in ONLY_NAMES:
            return None
        ET.indent(self.mxfile, space="  ")
        path = ASSET_DIR / f"{self.name}.drawio"
        ET.ElementTree(self.mxfile).write(path, encoding="utf-8", xml_declaration=True)
        return path


def architecture(name: str, title: str, groups: list[dict], edges: list[tuple]) -> None:
    d = Drawio(name, title, 1600, 920)
    node_ids: dict[str, str] = {}
    node_boxes: dict[str, tuple[float, float, float, float]] = {}
    for group in groups:
        d.container(group["title"], *group["box"], fill=group.get("fill", COLORS["gray_fill"]), stroke=group.get("stroke", COLORS["grid"]))
        for node in group["nodes"]:
            nid, label, detail, box, kind = node
            palette = {
                "control": (COLORS["blue_fill"], COLORS["blue"]),
                "memory": (COLORS["purple_fill"], COLORS["purple"]),
                "compute": (COLORS["amber_fill"], COLORS["amber"]),
                "system": (COLORS["teal_fill"], COLORS["teal"]),
                "status": (COLORS["green_fill"], COLORS["green"]),
                "neutral": (COLORS["white"], COLORS["line"]),
            }[kind]
            node_ids[nid] = d.vertex(_label(label, detail), *box, fill=palette[0], stroke=palette[1], size=13)
            node_boxes[nid] = box
    for edge in edges:
        src, dst, label, color_name, *flags = edge
        sx, sy, sw, sh = node_boxes[src]
        tx, ty, tw, th = node_boxes[dst]
        dx = (tx + tw / 2) - (sx + sw / 2)
        dy = (ty + th / 2) - (sy + sh / 2)
        if abs(dx) >= abs(dy):
            ex, ey = ((1, 0.5) if dx >= 0 else (0, 0.5))
            ix, iy = ((0, 0.5) if dx >= 0 else (1, 0.5))
        else:
            ex, ey = ((0.5, 1) if dy >= 0 else (0.5, 0))
            ix, iy = ((0.5, 0) if dy >= 0 else (0.5, 1))
        d.edge(node_ids[src], node_ids[dst], "", color=COLORS[color_name], both="both" in flags, dashed="dashed" in flags, exit_x=ex, exit_y=ey, entry_x=ix, entry_y=iy)
    d.text("蓝：命令与控制    青：系统接口    紫：数据与存储    橙：计算通路    绿：状态与完成", 50, 870, 1400, 24, size=12)
    d.write()


def module_diagram(name: str, title: str, inputs: list[tuple], modules: list[tuple], outputs: list[tuple], links: list[tuple]) -> None:
    """Draw every logical connection in an independent routing lane.

    Repeating a block in multiple lanes means that different interfaces of the
    same logical block are being shown.  The lane form is intentional: it keeps
    every arrow visually independent, which is more important in a normative
    specification than a compact but ambiguous graph.
    """
    node_info = {item[0]: item[1:] for item in inputs + modules + outputs}
    row_h = 118
    height = 150 + len(links) * row_h + 80
    d = Drawio(name, title, 1600, height)
    d.text("接口关系", 48, 78, 190, 40, size=13, bold=True, color=COLORS["ink"])
    d.text("发起方", 290, 78, 400, 40, size=13, bold=True, color=COLORS["ink"], align="center")
    d.text("接收方", 1010, 78, 400, 40, size=13, bold=True, color=COLORS["ink"], align="center")
    palette = {
        "control": (COLORS["blue_fill"], COLORS["blue"]),
        "memory": (COLORS["purple_fill"], COLORS["purple"]),
        "compute": (COLORS["amber_fill"], COLORS["amber"]),
        "system": (COLORS["teal_fill"], COLORS["teal"]),
        "status": (COLORS["green_fill"], COLORS["green"]),
        "neutral": (COLORS["white"], COLORS["line"]),
    }
    for idx, link in enumerate(links):
        src, dst, relation, color_name, *flags = link
        sy = 118 + idx * row_h
        src_title, src_detail, src_kind = node_info[src]
        dst_title, dst_detail, dst_kind = node_info[dst]
        d.vertex(
            _label(relation, "双向请求与返回" if "both" in flags else "单向传递"),
            45, sy, 205, 94,
            fill=COLORS["gray_fill"], stroke=COLORS["grid"], size=12,
        )
        src_id = d.vertex(_label(src_title, src_detail), 290, sy, 400, 94,
                          fill=palette[src_kind][0], stroke=palette[src_kind][1], size=12)
        dst_id = d.vertex(_label(dst_title, dst_detail), 1010, sy, 400, 94,
                          fill=palette[dst_kind][0], stroke=palette[dst_kind][1], size=12)
        d.edge(src_id, dst_id, "", color=COLORS[color_name], both="both" in flags,
               dashed="dashed" in flags, exit_x=1, exit_y=0.5, entry_x=0, entry_y=0.5,
               width=2.2)
    d.text("每行独立表示一项逻辑连接；同名方框表示同一模块的不同接口。", 45, height - 48, 1460, 40, size=12)
    d.write()


def state_diagram(name: str, title: str, states: list[tuple], transitions: list[tuple], width: int = 1600, height: int = 900) -> None:
    """Draw one transition per lane so labels and arrows can never collide."""
    state_info = {item[0]: (item[1], item[2], item[7]) for item in states}
    row_h = 108
    canvas_h = 150 + len(transitions) * row_h + 75
    d = Drawio(name, title, 1600, canvas_h)
    d.text("源状态", 65, 78, 350, 28, size=13, bold=True, color=COLORS["ink"], align="center")
    d.text("转移条件", 520, 78, 500, 28, size=13, bold=True, color=COLORS["ink"], align="center")
    d.text("目标状态", 1160, 78, 350, 28, size=13, bold=True, color=COLORS["ink"], align="center")
    palette = {
        "normal": (COLORS["blue_fill"], COLORS["blue"]),
        "wait": (COLORS["amber_fill"], COLORS["amber"]),
        "done": (COLORS["green_fill"], COLORS["green"]),
        "error": (COLORS["red_fill"], COLORS["red"]),
        "memory": (COLORS["purple_fill"], COLORS["purple"]),
    }

    def state_vertex(key: str, x: float, y: float) -> str:
        label, detail, kind = state_info[key]
        if kind == "initial":
            return d.vertex("", x + 155, y + 21, 28, 28, fill=COLORS["ink"], stroke=COLORS["ink"], rounded=1, extra="ellipse;")
        if kind == "final":
            return d.vertex("", x + 153, y + 19, 32, 32, fill=COLORS["white"], stroke=COLORS["ink"], rounded=1, stroke_width=2.4, extra="ellipse;shape=doubleEllipse;")
        fill, stroke = palette[kind]
        return d.vertex(_label(label, detail), x, y, 350, 70, fill=fill, stroke=stroke, size=12, rounded=1, extra="arcSize=18;")

    for idx, transition in enumerate(transitions):
        src, dst, condition, *_ = transition
        y = 118 + idx * row_h
        src_id = state_vertex(src, 65, y)
        dst_id = state_vertex(dst, 1160, y)
        d.text(condition, 515, y + 5, 505, 26, size=12, color=COLORS["ink"], align="center")
        d.edge(src_id, dst_id, "", color=COLORS["blue"], exit_x=1, exit_y=0.72,
               entry_x=0, entry_y=0.72, width=2.2)
    d.text("每行独立表示一条状态转移；条件位于箭头上方的专用标注区，未满足时保持源状态。", 45, canvas_h - 46, 1500, 24, size=12)
    d.write()


def wave_diagram(name: str, title: str, signals: list[tuple[str, list[str]]], annotations: list[tuple[int, int, str, str]] | None = None) -> None:
    cycles = max(len(values) for _, values in signals)
    width = max(1200, 360 + cycles * 130)
    height = 150 + (len(signals) + 1) * 68 + 110
    d = Drawio(name, title, width, height)

    def digital_wave(values: list[str]) -> str:
        out: list[str] = []
        previous = None
        for value in values:
            if value == previous:
                out.append(".")
            else:
                out.append(value)
                previous = value
        return "".join(out)

    wave_signals: list[dict] = [{"name": "clk", "wave": "p" + "." * (cycles - 1)}]
    for label, values in signals:
        if all(value in {"0", "1", "x"} for value in values):
            wave_signals.append({"name": label, "wave": digital_wave(values)})
            continue
        wave: list[str] = []
        data: list[str] = []
        previous: str | None = None
        for value in values:
            if value in {"", "."}:
                if previous is None:
                    wave.append("x")
                    previous = ""
                elif previous == "":
                    wave.append(".")
                else:
                    wave.append("x")
                    previous = ""
            elif value == previous:
                wave.append(".")
            else:
                wave.append("=")
                data.append(value)
                previous = value
        wave_signals.append({"name": label, "wave": "".join(wave), "data": data})

    foot = "；".join(item[2] for item in (annotations or []))
    source = {
        "signal": wave_signals,
        "head": {"text": title, "tick": 0},
        "foot": {"text": foot},
        "config": {"hscale": 2},
    }
    cell = ET.SubElement(
        d.root,
        "mxCell",
        id=d._id("w"),
        value=json.dumps(source, ensure_ascii=False, separators=(",", ":")),
        style=(
            "shape=mxgraph.wavedrom.abstract.timing;shadow=0;dashed=0;align=left;"
            "strokeWidth=1;labelBackgroundColor=#ffffff;noLabel=1;imageAspect=1;"
        ),
        vertex="1",
        parent="1",
    )
    ET.SubElement(cell, "mxGeometry", x="35", y="78", width=str(width - 70), height=str(height - 110), **{"as": "geometry"})
    d.write()


def lane_diagram(name: str, title: str, lanes: list[tuple[str, list[tuple[str, str, str]], bool]]) -> None:
    """Draw independent horizontal paths with no shared connector segments."""
    row_h = 142
    height = 140 + len(lanes) * row_h + 70
    d = Drawio(name, title, 1600, height)
    palette = {
        "control": (COLORS["blue_fill"], COLORS["blue"]),
        "memory": (COLORS["purple_fill"], COLORS["purple"]),
        "compute": (COLORS["amber_fill"], COLORS["amber"]),
        "system": (COLORS["teal_fill"], COLORS["teal"]),
        "status": (COLORS["green_fill"], COLORS["green"]),
    }
    for row, (lane_name, nodes, bidirectional) in enumerate(lanes):
        y = 105 + row * row_h
        d.vertex(_label(lane_name), 35, y, 190, 100, fill=COLORS["gray_fill"], stroke=COLORS["grid"], size=12)
        area_x, area_w, gap = 270, 1280, 34
        node_w = (area_w - gap * (len(nodes) - 1)) / len(nodes)
        ids: list[str] = []
        for col, (node_title, detail, kind) in enumerate(nodes):
            x = area_x + col * (node_w + gap)
            fill, stroke = palette[kind]
            ids.append(d.vertex(_label(node_title, detail), x, y, node_w, 100,
                                fill=fill, stroke=stroke, size=12))
        for src, dst in zip(ids, ids[1:]):
            d.edge(src, dst, "", color=COLORS["purple"] if bidirectional else COLORS["blue"],
                   both=bidirectional, exit_x=1, exit_y=0.5, entry_x=0, entry_y=0.5, width=2.2)
    d.text("各行使用独立走线通道；同名方框表示同一模块的不同接口。", 45, height - 45, 1500, 24, size=12)
    d.write()


def task_flow_diagram(
    name: str,
    title: str,
    nodes: list[tuple[str, str, str, tuple[int, int, int, int], str]],
    links: list[tuple[str, str, str]],
    *,
    width: int = 1600,
    height: int = 700,
) -> None:
    """Draw a model-task flow with large boxes and dedicated connectors."""
    d = Drawio(name, title, width, height)
    palette = {
        "control": (COLORS["blue_fill"], COLORS["blue"]),
        "memory": (COLORS["purple_fill"], COLORS["purple"]),
        "compute": (COLORS["amber_fill"], COLORS["amber"]),
        "system": (COLORS["teal_fill"], COLORS["teal"]),
        "status": (COLORS["green_fill"], COLORS["green"]),
    }
    ids: dict[str, str] = {}
    boxes: dict[str, tuple[int, int, int, int]] = {}
    for key, node_title, detail, box, kind in nodes:
        fill, stroke = palette[kind]
        ids[key] = d.vertex(
            _label(node_title, detail),
            *box,
            fill=fill,
            stroke=stroke,
            size=16,
            bold=True,
            stroke_width=2.0,
        )
        boxes[key] = box
    for src, dst, color_name in links:
        sx, sy, sw, sh = boxes[src]
        tx, ty, tw, th = boxes[dst]
        dx = (tx + tw / 2) - (sx + sw / 2)
        dy = (ty + th / 2) - (sy + sh / 2)
        if abs(dx) >= abs(dy):
            exit_x, exit_y = ((1, 0.5) if dx > 0 else (0, 0.5))
            entry_x, entry_y = ((0, 0.5) if dx > 0 else (1, 0.5))
        else:
            exit_x, exit_y = ((0.5, 1) if dy > 0 else (0.5, 0))
            entry_x, entry_y = ((0.5, 0) if dy > 0 else (0.5, 1))
        d.edge(
            ids[src],
            ids[dst],
            "",
            color=COLORS[color_name],
            exit_x=exit_x,
            exit_y=exit_y,
            entry_x=entry_x,
            entry_y=entry_y,
            width=2.6,
        )
    d.write()


def generate_model_task_flows() -> None:
    task_flow_diagram(
        "npu_transformer_task_flow",
        "Transformer Encoder Block 基础任务流程",
        [
            ("ddr", "系统存储", "整数输入与权重", (55, 125, 260, 105), "memory"),
            ("load", "DMA 装载", "连续范围进入 L1BUF", (410, 125, 260, 105), "compute"),
            ("norm", "Complex Norm", "LayerNorm 或 RMSNorm", (765, 125, 260, 105), "compute"),
            ("matrix", "Matrix", "QKV 或 FFN 矩阵任务", (1120, 125, 300, 105), "compute"),
            ("layout", "DMA 布局整理", "Transpose、Pack 或 Split", (1120, 350, 300, 105), "compute"),
            ("cpu", "CPU / Runtime", "掩码、块表与软件步骤", (1120, 535, 300, 105), "system"),
            ("post", "Vector / Complex", "残差、激活或重缩放", (765, 350, 260, 105), "compute"),
            ("linear", "Matrix", "线性投影或下一层", (410, 350, 260, 105), "compute"),
            ("store", "DMA 输出", "写回或供下一任务读取", (55, 350, 260, 105), "memory"),
        ],
        [
            ("ddr", "load", "purple"),
            ("load", "norm", "blue"),
            ("norm", "matrix", "blue"),
            ("matrix", "layout", "purple"),
            ("layout", "cpu", "teal"),
            ("matrix", "post", "blue"),
            ("post", "linear", "blue"),
            ("linear", "store", "purple"),
        ],
        height=700,
    )
    task_flow_diagram(
        "npu_lstm_task_flow",
        "LSTM 单时间步基础任务流程",
        [
            ("input", "输入与前一状态", "xₜ、hₜ₋₁、cₜ₋₁", (55, 125, 280, 105), "memory"),
            ("load", "DMA 预取", "输入与权重进入 L1BUF", (430, 125, 280, 105), "compute"),
            ("matrix", "Matrix", "四门融合矩阵乘", (805, 125, 280, 105), "compute"),
            ("act", "Complex", "Sigmoid 与 Tanh", (1180, 125, 280, 105), "compute"),
            ("update", "Vector / Complex", "更新 cₜ 与 hₜ", (1180, 365, 280, 105), "compute"),
            ("state", "L1BUF 状态区", "保存 hₜ 与 cₜ", (805, 365, 280, 105), "memory"),
            ("next", "下一时间步", "Event 确认状态写入完成", (430, 365, 280, 105), "status"),
        ],
        [
            ("input", "load", "purple"),
            ("load", "matrix", "blue"),
            ("matrix", "act", "blue"),
            ("act", "update", "blue"),
            ("update", "state", "purple"),
            ("state", "next", "green"),
        ],
        height=570,
    )
    task_flow_diagram(
        "npu_rnn_gru_task_flow",
        "RNN 与 GRU 单时间步基础任务流程",
        [
            ("input", "输入与前一状态", "xₜ 与 hₜ₋₁", (55, 125, 280, 105), "memory"),
            ("load", "DMA 预取", "输入与权重进入 L1BUF", (430, 125, 280, 105), "compute"),
            ("matrix", "Matrix", "RNN 仿射项或 GRU 门计算", (805, 125, 280, 105), "compute"),
            ("act", "Vector / Complex", "激活与逐元素状态更新", (1180, 125, 280, 105), "compute"),
            ("state", "L1BUF 状态区", "保存 hₜ", (1180, 365, 280, 105), "memory"),
            ("next", "下一时间步", "Event 确认状态写入完成", (805, 365, 280, 105), "status"),
        ],
        [
            ("input", "load", "purple"),
            ("load", "matrix", "blue"),
            ("matrix", "act", "blue"),
            ("act", "state", "purple"),
            ("state", "next", "green"),
        ],
        height=570,
    )


def system_architecture_diagram() -> None:
    d = Drawio('npu_system_architecture', 'NPU 与系统控制、DDR 和中断的连接', 1500, 1360)
    ids = {}
    def box(key,title,detail,x,y,w,h,kind='blue'):
        ids[key]=d.vertex(_label(title,detail),x,y,w,h,fill=COLORS[kind+'_fill'],stroke=COLORS[kind],size=24)
    d.container('SoC 外部系统',60,100,1380,440,size=22)
    d.container('NPU 子系统',390,600,1050,610,fill='#F8FBFF',stroke=COLORS['blue'],size=24)
    box('plic','PLIC / CPU 中断处理','读取 NPU 状态，软件清除保持位',85,170,270,130,'green')
    box('cpu','主控 CPU','配置、启动、采样和终端',600,170,300,130,'teal')
    box('ddr','系统存储 / DDR','静态程序、描述符、权重、KV',1050,170,320,130,'purple')
    box('fabric','SoC AXI Fabric','CPU 访问 NPU Slave；NPU Master 访问系统存储',450,410,950,100,'teal')
    box('slave','64-bit AXI Slave','CMD、CSR、控制和 Host L1 窗口',450,680,400,130)
    box('master','64-bit AXI Master','DMA、程序取指、描述符装载',1000,680,400,130,'purple')
    box('core','NPU Core','CFE、取指与描述符、调度和执行集群\n四物理 PE；共享 Complex FMA；1 MiB L1\n当前默认 4 bank；各配置能力分别检查',450,970,950,200)
    box('eth','板级 Ethernet RX','解析头，提供 DMA 旁带命令',60,1080,260,110,'amber')
    for source,target,x,sy,ty in [('cpu','fabric',750,300,410),('ddr','fabric',1210,300,410)]:
        d.edge(ids[source],ids[target],both=True,color=COLORS['teal' if source=='cpu' else 'purple'],width=3,exit_x=.5,exit_y=1,entry_x=(x-450)/950,entry_y=0,straight=True)
    for key,x in [('slave',650),('master',1200)]:
        d.edge(ids['fabric'],ids[key],both=True,color=COLORS['blue' if key=='slave' else 'purple'],width=3,exit_x=(x-450)/950,exit_y=1,entry_x=.5,entry_y=0,straight=True)
        d.edge(ids[key],ids['core'],both=True,color=COLORS['blue' if key=='slave' else 'purple'],width=3,exit_x=.5,exit_y=1,entry_x=(x-450)/950,entry_y=0,straight=True)
    d.edge(ids['core'],ids['plic'],color=COLORS['green'],width=3,exit_x=0,exit_y=.25,entry_x=.5,entry_y=1,waypoints=[(220,1020)])
    d.text('IRQ 电平\nSoC 合并\n送 PLIC',60,690,140,100,size=21,bold=True,color=COLORS['green'])
    d.edge(ids['eth'],ids['core'],color=COLORS['amber'],width=3,exit_x=1,exit_y=.5,entry_x=0,entry_y=.825,straight=True)
    d.text('蓝：命令与配置　紫：系统存储　绿：保持型中断　橙：RX 数据与旁带控制',70,1270,1360,45,size=23,bold=True,align='center')
    d.write()


def command_storage_architecture_diagram() -> None:
    d=Drawio('npu_command_storage_architecture','命令入口、程序预取与描述符装载',1400,1370)
    ids={}
    def box(key,title,detail,x,y,kind='blue',h=150):
        ids[key]=d.vertex(_label(title,detail),x,y,420,h,fill=COLORS[kind+'_fill'],stroke=COLORS[kind],size=24)
    d.container('NPU 命令与系统控制',70,100,1260,1180,fill='#F8FBFF',stroke=COLORS['blue'],size=24)
    box('axi','AXI Slave Frontend','主控命令 beat / CSR / 查询',120,180)
    box('lsc','LSC','保持型状态、程序配置与启动',860,180,'green')
    box('cfe','CFE 命令前端','AXI / Sequencer 共用入口\n两拍检查、ID 去重与 FIFO',120,500)
    box('seq','Program Sequencer','八命令预取 / 两批缓冲 / 屏障',860,500)
    box('desc','外部描述符装载器','缓存与续接模板；展开紧凑内联',120,820,'purple',170)
    box('mif','共享 MIF / AXI Master','程序、描述符与 DMA 请求仲裁',860,820,'purple',170)
    box('scheduler','TaskScheduler','接纳命令及记录，等待和派发',120,1130,h=120)
    box('ddr','SoC 存储返回','DDR 静态程序和只读描述符',860,1130,'purple',120)
    for a,b,color,both in [('axi','lsc','green',True),('seq','cfe','blue',False),('desc','mif','purple',True)]:
        if a=='seq':d.edge(ids[a],ids[b],color=COLORS[color],width=3,exit_x=0,exit_y=.5,entry_x=1,entry_y=.5,straight=True)
        else:d.edge(ids[a],ids[b],color=COLORS[color],both=both,width=3,exit_x=1,exit_y=.5,entry_x=0,entry_y=.5,straight=True)
    for a,b,col,both in [('axi','cfe','blue',False),('lsc','seq','green',False),('cfe','desc','blue',False),('seq','mif','purple',True),('desc','scheduler','blue',False),('mif','ddr','purple',True)]:
        d.edge(ids[a],ids[b],color=COLORS[col],both=both,width=3,exit_x=.5,exit_y=1,entry_x=.5,entry_y=0,straight=True)
    d.text('图示为配置、取指和描述符数据方向；任务完成、ACK 与引擎连接另见执行图及端口表。',65,1300,1270,42,size=22,bold=True,align='center')
    d.write()


def npu_core_architecture_diagram() -> None:
    d=Drawio('npu_internal_architecture','NPU 执行集群与片上访存结构',1760,1340)
    ids={}
    def box(key,title,detail,x,y,w,h,kind='amber'):
        ids[key]=d.vertex(_label(title,detail),x,y,w,h,fill=COLORS[kind+'_fill'],stroke=COLORS[kind],size=24)
    d.container('NPU Core',70,100,1620,1160,fill='#F8FBFF',stroke=COLORS['blue'],size=24)
    box('sched','TaskScheduler','四类逻辑任务接口；事件依赖、任务 RAM、完成记录与 ACK',130,170,1480,140,'blue')
    d.container('',100,420,1540,440,fill='#FFFBEB',stroke=COLORS['amber'],size=24)
    d.text('执行引擎',1060,440,140,35,size=23,bold=True)
    box('dma','DMA / Layout Engine','连续搬运与类型转换\nL1 本地复制独立写口\nEthernet 旁带 RX',130,490,380,320)
    box('matrix','Matrix / Vector 包装','Direct / Scalar / Vector MUL-FMA\n共享四个物理 PE，每 PE 八个 4×8 乘法叶\nVector 轻量 ALU 独立，乘法需仲裁\n16 个逻辑 lane 按模式分 phase 执行',560,490,500,320)
    box('complex','Complex Engine','可裁剪 stream / legacy 路径\n两个逻辑 FMA 请求入口经仲裁\n共享一个物理 mixed-FMA word 流水\n普通 L1 与独立写回端口',1110,490,500,320)
    box('mif','MIF / AXI Master','DMA、程序和描述符共同使用\n默认八项读环，单写上下文\n读写可重叠，返回有归属',130,1010,380,210,'purple')
    box('l1','L1BUF 与七客户端 fabric','1 MiB，默认四个 64-bit 1R1W bank，可选 4 / 8 / 16 bank\n普通端口：Host / DMA / MV×2 / Complex / 本地复制写 / Complex 写\nDirect 面板：读载荷 2048 bit，写载荷 1024 bit，分阶段收集',560,1010,1050,210,'purple')
    for key,span,positions in [('dma',(130,380),(210,410)),('matrix',(560,500),(625,745,875,995)),('complex',(1110,500),(1210,1510))]:
        for i,x in enumerate(positions):
            reverse=i%2==1
            d.edge(ids[key] if reverse else ids['sched'],ids['sched'] if reverse else ids[key],color=COLORS['green' if reverse else 'blue'],width=3,exit_x=(x-span[0])/span[1] if reverse else (x-130)/1480,exit_y=0 if reverse else 1,entry_x=(x-130)/1480 if reverse else (x-span[0])/span[1],entry_y=1 if reverse else 0,straight=True)
    d.edge(ids['dma'],ids['mif'],both=True,color=COLORS['purple'],width=3,exit_x=.4,exit_y=1,entry_x=.4,entry_y=0,straight=True)
    d.edge(ids['dma'],ids['l1'],both=True,color=COLORS['purple'],width=3,exit_x=330/380,exit_y=1,entry_x=50/1050,entry_y=0,waypoints=[(460,920),(610,920)])
    for key,x,sx in [('matrix',750,560),('matrix',1000,560),('complex',1280,1110),('complex',1530,1110)]:
        d.edge(ids[key],ids['l1'],both=True,color=COLORS['purple'],width=3,exit_x=(x-sx)/500,exit_y=1,entry_x=(x-560)/1050,entry_y=0,straight=True)
    d.text('蓝：任务派发　绿：完成返回　紫：访存请求与响应；端口容量不等于单拍实际计算并行度。',100,1280,1540,42,size=23,bold=True,align='center')
    d.write()


def numeric_flow_diagram() -> None:
    d=Drawio('npu_int_fp_int_flow','整数主干、显式浮点流与结果写回',1800,1070)
    ids={}
    def box(key,title,detail,x,y,w,h,kind='blue'):
        ids[key]=d.vertex(_label(title,detail),x,y,w,h,fill=COLORS[kind+'_fill'],stroke=COLORS[kind],size=24)
    box('i','整数编码与打包权重','A8 / W4；其他模式由配置决定',70,160,320,180,'purple')
    box('matrix','Matrix 整数阵列与组缩放','整数部分和、零点校正、公共指数宽累加\n整行输出尺度、最终一次 RNE 和饱和',560,160,650,180,'amber')
    box('o','整数主干输出','INT8 / INT16 / INT32\n附带明确的数值尺度',1450,160,280,180,'purple')
    box('profile','静态参数与动态状态','权重尺度、zero point 与配置不随 token 重编\nA8 / 输出行统计通过状态区发布',560,410,650,150,'green')
    box('f','显式浮点位型','binary32 使用 INT32 容器\npacked binary16 使用格式标志',70,720,320,190,'purple')
    box('complex','Complex 流与共享 FMA','转换、乘加、归约、非线性与统计\n按指令控制 FP16 / FP32；私有行 RAM\n一个物理字流水，逻辑请求排队',560,720,650,190,'amber')
    box('q','按指令格式写回','浮点位型或整数编码\n转换与量化次序明确',1450,720,280,190,'purple')
    for a,b in [('i','matrix'),('matrix','o'),('f','complex'),('complex','q')]:d.edge(ids[a],ids[b],width=3,color=COLORS['purple'],exit_x=1,exit_y=.5,entry_x=0,entry_y=.5,straight=True)
    d.edge(ids['profile'],ids['matrix'],width=3,color=COLORS['green'],exit_x=.5,exit_y=0,entry_x=.5,entry_y=1,straight=True)
    d.text('原始浮点位型不等于 signed INT32 数值；RNE、缩放、bias 与饱和均按具体操作定义。',90,985,1620,42,size=23,bold=True,align='center')
    d.write()


def l1_banked_storage_diagram() -> None:
    d=Drawio('npu_l1_banked_storage_architecture','L1BUF：七路普通客户端、分段面板与 1R1W bank',1700,1370)
    ids={}
    def box(key,title,detail,x,y,w,h,kind='blue'):
        ids[key]=d.vertex(_label(title,detail),x,y,w,h,fill=COLORS[kind+'_fill'],stroke=COLORS[kind],size=24)
    d.container('执行集群访问接口',60,100,1580,290,size=24)
    box('ordinary','七路普通客户端','Host、DMA、Matrix/Vector ×2、Complex\nDMA 复制写、Complex 独立写',100,175,700,170)
    box('panel','Direct 面板接口','A/B 读，C 读写，B-only 与紧凑 A\n读结果 32×64 bit；写载荷 16×64 bit',900,175,700,170,'amber')
    box('queues','各客户端独立顺序队列','2 项待执行请求；3 项响应信用\n同步返回级、短响应存储和写提交指示',100,510,700,170)
    box('gather','面板分段与收集流水','先检查完整范围，再逐 bank 段访问\n四 bank：独立最终响应寄存器',900,510,700,170,'amber')
    box('arb','逐 bank 读写仲裁与冲突处理','普通读写分别轮转；相同行读写串行\n默认四 bank：面板段保留参与 bank 的读写两方向',100,830,1500,170,'purple')
    for key,x in [('ordinary',450),('panel',1250)]:
        target='queues' if key=='ordinary' else 'gather'
        d.edge(ids[key],ids[target],both=True,color=COLORS['blue' if key=='ordinary' else 'amber'],width=3,exit_x=.5,exit_y=1,entry_x=.5,entry_y=0,straight=True)
        d.edge(ids[target],ids['arb'],both=True,color=COLORS['purple'],width=3,exit_x=.5,exit_y=1,entry_x=(x-100)/1500,entry_y=0,straight=True)
    for i in range(4):
        x=100+i*390;cx=x+165
        box('bank'+str(i),'Bank '+str(i),'64-bit 1R1W\n32768 word；256 KiB',x,1130,330,160,'teal')
        d.edge(ids['arb'],ids['bank'+str(i)],both=True,color=COLORS['purple'],width=3,exit_x=(cx-100)/1500,exit_y=1,entry_x=.5,entry_y=0,straight=True)
    d.text('默认总容量 1 MiB；支持 4 / 8 / 16 bank。宽面板是分段结果，不增加物理 RAM 端口。',80,1310,1540,45,size=23,bold=True,align='center')
    d.write()


def mif_burst_architecture_diagram() -> None:
    d=Drawio('npu_mif_burst_architecture','MIF：三类请求、读事务环与独立写上下文',1700,1740)
    ids={}
    def box(key,title,detail,x,y,w,h,kind='blue'):
        ids[key]=d.vertex(_label(title,detail),x,y,w,h,fill=COLORS[kind+'_fill'],stroke=COLORS[kind],size=24)
    for key,x,title,detail in [('dma',80,'DMA','数据读写'),('prog',620,'Program Sequencer','静态程序 burst 预取'),('desc',1160,'描述符装载器','缓存未命中读取')]:
        box(key,title,detail,x,130,440,140)
    box('arb1','第一级窗口仲裁','DMA / 程序；等待程序时限制 DMA 读窗口',80,400,980,140)
    box('arb2','第二级请求仲裁与返回归属','控制请求流 / 描述符；整段返回后再切换请求源',80,680,1520,150)
    for key,cx in [('dma',300),('prog',840)]:
        d.edge(ids[key],ids['arb1'],both=True,color=COLORS['blue'],width=3,exit_x=.5,exit_y=1,entry_x=(cx-80)/980,entry_y=0,straight=True)
    d.edge(ids['arb1'],ids['arb2'],both=True,color=COLORS['blue'],width=3,exit_x=.5,exit_y=1,entry_x=490/1520,entry_y=0,straight=True)
    d.edge(ids['desc'],ids['arb2'],both=True,color=COLORS['blue'],width=3,exit_x=.5,exit_y=1,entry_x=1300/1520,entry_y=0,straight=True)
    box('fifo','两项请求 FIFO','129-bit 请求记录；隔离 ready 组合路径',80,950,1520,130)
    d.edge(ids['arb2'],ids['fifo'],color=COLORS['blue'],width=3,exit_x=.5,exit_y=1,entry_x=.5,entry_y=0,straight=True)
    ids['master']=d.container('',60,1170,1580,460,size=24)
    d.text('AXI MIF Master',650,1190,400,50,size=24,bold=True,align='center')
    d.edge(ids['master'],ids['arb2'],color=COLORS['green'],width=3,exit_x=0,exit_y=.6,entry_x=0,entry_y=.5,waypoints=[(20,1446),(20,755)])
    box('read','默认八项有序读事务环','ARID=0，1～256 beat / burst\nR 检查、两项返回队列；读响应优先',100,1280,700,210,'purple')
    box('write','一个独立写上下文','AWLEN=0；AW / W 分别握手\n等待 B 后返回；可与活动读流重叠',900,1280,700,210,'amber')
    for key,cx,kind in [('read',450,'purple'),('write',1250,'amber')]:
        d.edge(ids['fifo'],ids[key],color=COLORS[kind],width=3,exit_x=(cx-80)/1520,exit_y=1,entry_x=.5,entry_y=0,straight=True)
    d.text('AXI AR / R',180,1530,540,50,size=24,bold=True,color=COLORS['purple'],align='center')
    d.text('AXI AW / W / B',980,1530,540,50,size=24,bold=True,color=COLORS['amber'],align='center')
    d.text('请求 FIFO 只用于发出方向；响应由 Master 直接回到仲裁器并按已保存的归属交付。',70,1670,1560,45,size=23,bold=True,align='center')
    d.write()


def generate_architectures() -> None:
    system_architecture_diagram()
    npu_core_architecture_diagram()
    command_storage_architecture_diagram()
    numeric_flow_diagram()
    l1_banked_storage_diagram()
    mif_burst_architecture_diagram()


def matrix_vector_submodule_diagram() -> None:
    d = Drawio("npu_matrix_vector_submodules", "矩阵与向量执行单元的共享计算结构", 1700, 1110)
    ids = {}
    d.container("Matrix / Vector 执行域", 45, 95, 1610, 930, fill="#F8FBFF", stroke=COLORS["blue"], size=24)

    def box(key, title, detail, x, y, w, h, kind="compute"):
        palette = {"system": "teal", "status": "green", "memory": "purple",
                   "control": "blue", "compute": "amber"}[kind]
        ids[key] = d.vertex(_label(title, detail), x, y, w, h,
                            fill=COLORS[palette + "_fill"], stroke=COLORS[palette], size=21)

    box("mtask", "Matrix 任务接口", "GEMM / BMM / Direct 等命令", 95, 150, 440, 120, "system")
    box("vtask", "Vector 任务接口", "逐元素操作、MUL / FMA", 1165, 150, 440, 120, "system")
    box("matrix", "Matrix Engine 路由", "Direct 为主；Scalar 为可选兼容路径", 95, 335, 440, 145, "control")
    box("vector", "Vector Engine", "轻量 ALU 独立执行；MUL / FMA 请求共享阵列", 1165, 335, 440, 145, "control")
    box("direct", "Direct Matrix Array", "面板控制、A/B 根操作数与输出管理", 95, 565, 440, 155)
    box("scalar", "Scalar Matrix 路径", "可选 GEMM/BMM 控制与部分和状态", 630, 565, 440, 155)
    box("valupath", "Vector 轻量 ALU", "ADD / SUB / MAX / MIN / CMP / SELECT / CLAMP / RELU", 1165, 565, 440, 155)
    box("array", "共享可重构 PE 阵列", "4 个物理 PE；每 PE 8 个 4×8 乘法叶\n逻辑 step 分四相位；A/B 各有深度 2 FIFO", 540, 790, 620, 155)
    box("memory", "Matrix / Vector L1 请求 fabric", "两路普通 L1 请求选择、旁路和响应归属\nDirect 面板另走分阶段面板接口", 95, 820, 390, 135, "memory")
    box("l1", "L1BUF", "七个普通客户端与独立 Direct 面板通路", 1220, 820, 380, 135, "memory")

    d.edge(ids["mtask"], ids["matrix"], color=COLORS["blue"], width=3, exit_x=.5, exit_y=1, entry_x=.5, entry_y=0, straight=True)
    d.edge(ids["vtask"], ids["vector"], color=COLORS["blue"], width=3, exit_x=.5, exit_y=1, entry_x=.5, entry_y=0, straight=True)
    d.edge(ids["matrix"], ids["direct"], color=COLORS["blue"], width=3, exit_x=.5, exit_y=1, entry_x=.5, entry_y=0, straight=True)
    d.edge(ids["matrix"], ids["scalar"], color=COLORS["blue"], width=3, exit_x=1, exit_y=.75, entry_x=.5, entry_y=0, waypoints=[(560, 500), (850, 500)])
    d.edge(ids["vector"], ids["valupath"], color=COLORS["blue"], width=3, exit_x=.5, exit_y=1, entry_x=.5, entry_y=0, straight=True)
    d.edge(ids["direct"], ids["array"], color=COLORS["amber"], width=3, both=True, exit_x=1, exit_y=.85, entry_x=0, entry_y=.25, waypoints=[(555, 700), (555, 830)])
    d.edge(ids["scalar"], ids["array"], color=COLORS["amber"], width=3, both=True, exit_x=.5, exit_y=1, entry_x=.5, entry_y=0, straight=True)
    d.edge(ids["vector"], ids["array"], color=COLORS["amber"], width=3, both=True, exit_x=0, exit_y=.85, entry_x=1, entry_y=.25, waypoints=[(1140, 500), (1140, 830)])
    d.edge(ids["direct"], ids["memory"], color=COLORS["purple"], width=3, both=True, exit_x=.25, exit_y=1, entry_x=.5, entry_y=0, waypoints=[(205, 760), (290, 760)])
    d.edge(ids["scalar"], ids["memory"], color=COLORS["purple"], width=3, both=True, exit_x=0, exit_y=.85, entry_x=1, entry_y=.5, waypoints=[(590, 700), (540, 700), (540, 890)])
    d.edge(ids["valupath"], ids["memory"], color=COLORS["purple"], width=3, both=True, exit_x=1, exit_y=.8, entry_x=1, entry_y=.8, waypoints=[(1630, 680), (1630, 960), (520, 960), (520, 910)])
    d.edge(ids["memory"], ids["l1"], color=COLORS["purple"], width=3, both=True, exit_x=1, exit_y=1, entry_x=1, entry_y=.5, waypoints=[(600, 990), (1645, 990), (1645, 887)])
    d.text("MUL / FMA 由 Direct、Scalar 与 Vector 竞争同一阵列；Vector 普通 ALU 不占用 PE。", 80, 1045, 1540, 35, size=22, bold=True, align="center")
    d.write()


def complex_submodule_diagram() -> None:
    d = Drawio("npu_complex_submodules", "Complex 算子、共享算术与存储连接", 1700, 1040)
    ids = {}
    d.container("Complex Engine", 45, 95, 1610, 850, fill="#F8FBFF", stroke=COLORS["blue"], size=24)

    def box(key, title, detail, x, y, w, h, kind="compute"):
        palette = {"system": "teal", "status": "green", "memory": "purple",
                   "control": "blue", "compute": "amber"}[kind]
        ids[key] = d.vertex(_label(title, detail), x, y, w, h,
                            fill=COLORS[palette + "_fill"], stroke=COLORS[palette], size=21)

    box("task", "Complex Task Context", "opcode、地址、形状、dtype 与静态参数", 620, 145, 460, 120, "system")
    box("router", "任务路由与单任务上下文", "按 opcode 选择 Legacy 控制器或连续流算子", 620, 320, 460, 140, "control")
    box("legacy", "Legacy 数值控制路径", "ACT / Softmax / Norm 与兼容逐步控制", 105, 515, 470, 150, "control")
    box("streams", "连续流算子", "RoPE、Dynamic A8、FP32 MAC/SUM、在线 Softmax/PV、MIXED_FMA", 1125, 515, 470, 150)
    box("arith", "Arithmetic Fabric + 双逻辑请求 FIFO", "每个 owner 两项；按 tag 归属结果\n两个逻辑入口仲裁到单个算术流水", 600, 710, 500, 130)
    box("fma", "单个物理 mixed-FMA word 流水", "FP32 处理单元素；FP16 每 word 四组顺序处理", 600, 850, 500, 90)

    d.edge(ids["task"], ids["router"], color=COLORS["blue"], width=3, exit_x=.5, exit_y=1, entry_x=.5, entry_y=0, straight=True)
    d.edge(ids["router"], ids["legacy"], color=COLORS["blue"], width=3, exit_x=0, exit_y=.85, entry_x=.5, entry_y=0, waypoints=[(590, 460), (340, 460)])
    d.edge(ids["router"], ids["streams"], color=COLORS["blue"], width=3, exit_x=1, exit_y=.85, entry_x=.5, entry_y=0, waypoints=[(1110, 460), (1360, 460)])
    d.edge(ids["legacy"], ids["arith"], color=COLORS["amber"], width=3, both=True, exit_x=1, exit_y=.65, entry_x=0, entry_y=.35, waypoints=[(590, 620), (590, 770)])
    d.edge(ids["streams"], ids["arith"], color=COLORS["amber"], width=3, both=True, exit_x=0, exit_y=.65, entry_x=1, entry_y=.35, waypoints=[(1110, 620), (1110, 770)])
    d.edge(ids["arith"], ids["fma"], color=COLORS["amber"], width=3, both=True, exit_x=.5, exit_y=1, entry_x=.5, entry_y=0, straight=True)
    d.text("两路请求用于缓冲客户端并发；共享算术资源的数量为一个，FP16 word 的四个 half 依次处理。L1 与同步行 RAM 接口见正文端口表。", 70, 970, 1560, 35, size=22, bold=True, align="center")
    d.write()


def generate_modules() -> None:
    module_diagram("npu_axi_slave_frontend_submodules", "AXI 从设备前端子模块连接", [
        ("axi", "64-bit AXI 从接口", "AW / W / B / AR / R", "system")], [
        ("wr", "写通道接收", "地址、数据和属性检查", "control"),
        ("dec", "地址与功能译码", "命令 / 控制 / L1 窗口", "control"),
        ("rsp", "写响应保持", "按事务返回响应", "status"),
        ("rd", "读通道处理", "地址检查与返回保持", "control"),
        ("cmd", "命令分拍出口", "起始、结束与接收结果", "control"),
        ("ctl", "控制访问出口", "寄存器请求与响应", "status"),
        ("l1w", "L1 外部窗口出口", "64-bit 单拍访问", "memory")], [
        ("cfe", "命令前端", "完整指令接收", "control"),
        ("lsc", "系统控制", "配置与状态", "status"),
        ("l1", "L1BUF 子系统", "外部访问端口", "memory")], [
        ("axi","wr","AW / W","teal"),("axi","rd","AR","teal"),("wr","dec","写请求","blue"),
        ("dec","rsp","写状态","green"),("rsp","axi","B","teal"),("rd","axi","R","teal"),
        ("dec","cmd","命令窗口","blue"),("dec","ctl","控制窗口","green"),("dec","l1w","L1 窗口","purple"),
        ("cmd","cfe","64-bit 分拍","blue"),("ctl","lsc","请求 / 响应","green","both"),("l1w","l1","请求 / 响应","purple","both")])

    module_diagram("npu_cfe_submodules", "命令前端子模块连接", [
        ("in", "命令分拍", "64-bit 数据与起止标志", "system")], [
        ("asm", "分拍组合", "低字与高字次序检查", "control"),
        ("timer", "分拍等待计时", "高字等待上限 32 周期", "control"),
        ("check", "固定字段检查", "操作码与本地编号", "control"),
        ("lookup", "编号占用查询", "任务表与接纳项", "status"),
        ("fifo", "完整指令队列", "深度 8；寄存队首", "memory"),
        ("resp", "接收结果保持", "状态、编号和剩余空间", "status")], [
        ("desc", "外部描述符装载器", "普通/内联直通；外部记录查缓存或读 DDR", "memory"),
        ("ts", "任务调度器", "命令、descriptor 状态与地址快照", "control"),
        ("out", "接收结果接口", "64-bit 结果", "status")], [
        ("in","asm","valid / ready","blue"),("asm","timer","低字有效","blue"),("timer","check","收到高字","blue"),
        ("check","lookup","固定字段合法","blue"),("lookup","fifo","编号空闲","blue"),("fifo","desc","完整指令","blue"),
        ("desc","ts","命令与展开上下文","blue"),
        ("check","resp","检查结果","green"),("lookup","resp","查询结果","green"),("resp","out","valid / ready","green")])

    module_diagram("npu_task_scheduler_submodules", "任务调度器子模块连接", [
        ("cmd", "完整指令入口", "128-bit 指令", "system"),
        ("ctl_in", "软件控制请求", "查询 / 等待 / 栅栏 / 确认", "system")], [
        ("admit", "命令接纳", "基地址快照与静态检查", "control"),
        ("event", "事件表", "事件状态与代次", "status"),
        ("task", "任务表", "状态、依赖与完成信息", "memory"),
        ("wait", "等待条件检查", "逐项检查事件条件", "control"),
        ("scan", "就绪任务选择", "逐项扫描与提交次序", "control"),
        ("snap", "发射快照", "指令、基址与任务编号", "control"),
        ("decode", "共享任务展开", "形成执行单元任务信息", "control"),
        ("stage", "分类发射暂存", "DMA / Matrix / Vector / Complex", "memory"),
        ("done", "完成接收与发布", "终态、事件和通知", "status")], [
        ("eng", "四类执行接口", "任务与完成消息", "compute"),
        ("lsc", "系统控制", "完成通知与控制结果", "status")], [
        ("cmd","admit","ready / valid","blue"),("admit","task","建立表项","blue"),("admit","event","事件引用","green"),
        ("event","wait","事件状态","green"),("task","wait","等待任务","blue"),("wait","scan","就绪候选","blue"),
        ("task","scan","状态与次序","blue"),("scan","snap","获选任务","blue"),("snap","decode","发射快照","blue"),
        ("decode","stage","分类任务","blue"),("stage","eng","任务","blue"),("eng","done","完成","green"),
        ("done","task","更新终态","green"),("done","event","发布事件","green"),("ctl_in","task","控制访问","teal"),
        ("done","lsc","完成通知","green")])

    module_diagram("npu_dma_submodules", "DMA 与布局转换子模块连接", [
        ("task", "DMA 任务", "操作、地址、形状与格式", "system")], [
        ("ctrl", "DMA 控制器", "状态、访问次序与完成", "control"),
        ("dp", "DMA 数据通路", "地址游标、形状与格式转换", "compute"),
        ("shape", "形状计算", "串行乘法与范围检查", "control"),
        ("convert", "数据转换", "符号扩展、饱和与写掩码", "compute"),
        ("fast", "整拍快速通路", "对齐复制；1～16 个读拍", "memory")], [
        ("l1", "L1BUF 子系统", "64-bit 请求与响应", "memory"),
        ("mif", "系统存储接口", "全局地址请求与响应", "memory"),
        ("done", "任务完成", "状态、错误地址与进度", "status")], [
        ("task","ctrl","任务握手","blue"),("ctrl","dp","阶段控制","blue"),("dp","ctrl","进度 / 检查","green"),
        ("dp","shape","形状参数","blue","both"),("dp","convert","元素数据","amber","both"),("dp","fast","快速条件","purple"),
        ("dp","l1","普通访问","purple","both"),("dp","mif","普通访问","purple","both"),("fast","mif","多拍读取","purple","both"),
        ("ctrl","done","完成消息","green")])

    module_diagram("npu_l1buf_submodules", "L1BUF 子系统子模块连接", [
        ("clients", "普通客户端", "外部窗口 / DMA / 矩阵向量 / 复杂数学", "system"),
        ("panel", "Direct 面板端口", "32 路读 / 16 路写是逻辑载荷；按 bank 分段收集", "compute")], [
        ("arb", "普通请求仲裁", "轮询；每周期最多接收一项", "control"),
        ("req", "请求寄存与地址译码", "bank、row 和越界检查", "control"),
        ("rsp", "逐客户端响应保持", "读数据、写确认与状态", "status"),
        ("pctrl", "面板访问控制", "优先于新的普通请求", "control"),
        ("banks", "多 bank 存储体", "默认 4 bank；可设 4 / 8 / 16；每 bank 64-bit 1R1W", "memory")], [
        ("clients_o", "普通响应", "按请求次序返回客户端", "status"),
        ("panel_o", "面板响应", "各 lane 数据与状态", "status")], [
        ("clients","arb","64-bit 请求","purple"),("arb","req","获选请求","blue"),("req","banks","端口 0","purple"),
        ("banks","rsp","同步读数据","purple"),("rsp","clients_o","响应","green"),("panel","pctrl","面板请求","amber"),
        ("pctrl","banks","端口 0 / 1","purple"),("banks","pctrl","面板读返回","purple"),("pctrl","panel_o","面板响应","green")])

    matrix_vector_submodule_diagram()
    module_diagram("npu_vector_submodules", "整数向量通路子模块连接", [
        ("task", "向量任务", "操作、地址、形状与数据格式", "system")], [
        ("ctrl", "向量控制器", "字段检查、游标与读算写状态", "control"),
        ("dp", "向量数据通路", "操作数、掩码、结果与写回", "compute"),
        ("pipe", "整数执行流水", "加减、比较、选择、裁剪与 ReLU", "compute"),
        ("mul", "连续乘法整理", "INT8 八对 / INT16 四对打包", "compute")], [
        ("mem", "内部存储通路", "L1 请求与响应", "memory"),
        ("mac", "Matrix 共享 PE 接口", "MUL / FMA ready-valid 请求与返回", "compute"),
        ("done", "向量完成", "状态、地址与进度", "status")], [
        ("task","ctrl","任务握手","blue"),("ctrl","dp","阶段控制","blue"),("dp","ctrl","访存与计算状态","green"),
        ("dp","pipe","整数操作","amber","both"),("dp","mul","连续乘法数据","amber","both"),("dp","mem","64-bit L1","purple","both"),
        ("mul","mac","MUL","amber","both"),("dp","mac","FMA","amber","both"),("ctrl","done","完成消息","green")])

    complex_submodule_diagram()
    module_diagram("npu_mif_submodules", "系统存储接口子模块连接", [
        ("dma", "DMA 全局存储请求", "物理地址、读写和多拍长度", "system")], [
        ("check", "请求地址检查", "对齐、范围、长度与 4 KiB 边界", "control"),
        ("fsm", "AXI 通道控制", "AR / R / AW / W / B", "control"),
        ("rq", "读响应队列", "深度 2；隔离返回暂停", "memory"),
        ("err", "首错保存", "地址、状态和事务阶段", "status")], [
        ("axi", "64-bit AXI 主接口", "连接 SoC AXI 互连", "memory"),
        ("rsp", "DMA 响应", "读数据、写确认与状态", "status")], [
        ("dma","check","请求","blue"),("check","fsm","合法请求","blue"),("check","err","检查错误","red"),
        ("fsm","axi","AXI 通道","purple","both"),("fsm","rq","读返回","purple"),("rq","rsp","读响应","green"),
        ("fsm","rsp","写响应","green"),("fsm","err","总线错误","red")])

    module_diagram("npu_lsc_crg_wdt_submodules", "系统控制、时钟复位与看门狗子模块连接", [
        ("ctl", "控制访问", "配置、状态与控制请求", "system"),
        ("soc", "SoC 电源与时钟控制", "复位、时钟与电源状态", "system")], [
        ("lsc", "系统控制器", "配置、状态、中断和首错", "status"),
        ("crg", "时钟复位控制", "复位同步释放与时钟使能", "control"),
        ("wdt", "前进看门狗", "活动监测与超时请求", "control"),
        ("irq", "中断状态", "完成、错误与超时汇总", "status")], [
        ("ts", "任务调度器", "完成通知与运行控制", "control"),
        ("eng", "执行与存储模块", "空闲、进度、错误、时钟和复位", "compute"),
        ("out", "SoC 控制接口", "中断和电源时钟请求", "status")], [
        ("ctl","lsc","64-bit 控制","teal","both"),("lsc","crg","启动 / 停止 / 软复位","green"),
        ("wdt","lsc","超时","red"),("lsc","irq","完成与错误","green"),("lsc","ts","控制 / 完成","blue","both"),
        ("eng","wdt","活动与进度","amber"),("crg","eng","时钟与复位","green"),("soc","crg","外部状态","teal"),
        ("irq","out","中断","green"),("crg","out","电源时钟请求","green")])


def generate_states() -> None:
    state_diagram("npu_task_lifecycle_state", "任务表项生命周期", [
        ("i","","",100,210,0,0,"initial"),("free","FREE","表项可分配",190,175,180,90,"normal"),
        ("wait","WAIT_EVENT","等待事件与前序任务",450,175,220,90,"wait"),("ready","READY","满足发射条件",760,175,190,90,"normal"),
        ("run","RUNNING","执行单元已接收",1040,175,200,90,"normal"),("ok","SUCCESS","正确完成",1320,110,190,80,"done"),
        ("err","ERROR","检查或执行失败",1320,265,190,80,"error")], [
        ("i","free","复位完成"),("free","wait","接纳命令"),("wait","ready","依赖满足"),("ready","run","任务握手"),
        ("run","ok","status = SUCCESS"),("run","err","status ≠ SUCCESS"),("wait","err","静态检查失败"),
        ("ok","free","软件确认"),("err","free","软件确认")], 1600, 480)

    state_diagram("npu_cfe_state_machine", "命令前端状态机", [
        ("i","","",45,180,0,0,"initial"),("idle","IDLE","等待低 64-bit 分拍",100,145,180,80,"normal"),
        ("high","WAIT_HIGH","等待高分拍；最多 32 周期",360,145,210,80,"wait"),("check","CHECK","组合指令并检查固定字段",650,145,210,80,"normal"),
        ("lookup","LOOKUP","查询任务编号是否空闲",940,145,210,80,"normal"),("enqueue","ENQUEUE","完整指令写入队列",1230,145,190,80,"normal"),
        ("error","REJECT","形成拒绝结果",795,365,180,80,"error"),("resp","RESPOND","保持接收结果",1235,365,180,80,"done")], [
        ("i","idle","复位完成"),("idle","high","低分拍有效"),("high","check","高分拍有效"),("check","lookup","固定字段合法"),
        ("lookup","enqueue","编号空闲且有空间"),("idle","error","低分拍标志错误", {"label_x": -0.72, "label_y": -10}),("high","error","标志错误或超时", {"label_x": -0.72, "label_y": -10}),
        ("check","error","固定字段非法", {"label_x": -0.62, "label_y": -10}),("lookup","error","编号占用或无空间", {"label_x": -0.62, "label_y": -10}),("error","resp","拒绝结果就绪"),
        ("enqueue","resp","接收结果就绪"),("resp","idle","结果握手")], 1500, 570)

    state_diagram("npu_dma_state_machine", "DMA 与布局转换主状态机", [
        ("i","","",45,180,0,0,"initial"),("idle","IDLE","等待任务",100,145,150,80,"normal"),
        ("check","CHECK","操作与格式检查",315,145,170,80,"normal"),("shape","SHAPE","形状乘积计算",550,145,170,80,"normal"),
        ("region","REGION_CHECK","源、目的区域检查",785,145,190,80,"normal"),("init","CURSOR_INIT","地址与游标初始化",1040,145,190,80,"normal"),
        ("prep","PREP","当前项与快速条件",1295,145,180,80,"normal"),("read","READ","发出读并接收返回",1295,350,180,80,"memory"),
        ("convert","CONVERT","可选数据格式转换",1015,350,200,80,"normal"),("write","WRITE","发出写并等待确认",740,350,190,80,"memory"),
        ("advance","ADVANCE","推进元素、维度或分段",460,350,200,80,"normal"),("drain","BURST_DRAIN","错误后排空剩余读返回",1015,540,200,80,"error"),
        ("done","DONE","保持完成消息",190,350,160,80,"done")], [
        ("i","idle","复位完成"),("idle","check","任务握手"),("check","shape","普通搬运任务"),("check","prep","分段任务"),
        ("shape","region","形状合法"),("region","init","区域合法"),("init","prep","游标就绪"),("prep","read","需要读取"),
        ("prep","write","填充操作"),("read","convert","普通元素返回"),("read","write","整拍数据返回"),("convert","write","转换完成"),
        ("write","advance","写响应成功"),("advance","prep","仍有数据"),("advance","done","全部完成"),("read","drain","多拍读中发生错误"),
        ("drain","done","剩余返回已接收"),("check","done","检查失败"),("region","done","区域非法"),("write","done","写响应失败"),
        ("done","idle","完成握手")], 1600, 720)

    state_diagram("npu_direct_matrix_state_machine", "直接矩阵阵列控制状态机", [
        ("i","","",45,180,0,0,"initial"),("idle","IDLE","等待直接矩阵任务",110,145,180,80,"normal"),
        ("setup","TILE_SETUP","清零累加器并发出首个面板读",365,145,220,80,"normal"),("wait","PANEL_WAIT","等待首个 A/B 面板",660,145,190,80,"wait"),
        ("compute","COMPUTE","连续发射 K 组并预取下一面板",925,145,230,80,"normal"),("drain","COMPUTE_DRAIN","等待最后乘积完成累加",1230,145,220,80,"wait"),
        ("prep","OUT_PREP","形成首个输出列对",1230,355,220,80,"normal"),("store","OUT_STORE","逐拍写出 8 个列对",925,355,230,80,"memory"),
        ("outwait","OUT_WAIT","等待最后写响应",660,355,190,80,"wait"),("done","DONE","保持完成消息",365,355,180,80,"done")], [
        ("i","idle","复位完成"),("idle","setup","任务握手"),("setup","wait","首个读请求已接受"),("wait","compute","面板返回成功"),
        ("compute","compute","下一 K 组；面板可用"),("compute","drain","最后 K 组已发射"),("drain","prep","累加流水排空"),
        ("prep","store","输出寄存器有效"),("store","store","下一输出列对"),("store","outwait","最后列对请求已接受"),
        ("outwait","setup","还有输出 tile"),("outwait","done","全部 tile 完成"),("done","idle","完成握手")], 1600, 610)

    state_diagram("npu_scalar_matrix_state_machine", "标量矩阵控制状态机", [
        ("i","","",45,175,0,0,"initial"),("idle","IDLE","等待矩阵任务",95,140,150,80,"normal"),
        ("check","CHECK","操作、形状与格式检查",300,140,185,80,"normal"),("addr","ADDRESS","输出与 A/B 地址分阶段形成",550,140,210,80,"normal"),
        ("read","READ_OPERANDS","依次读取 A、B 与可选输入",830,140,220,80,"memory"),("mac","MAC","请求 Scalar Matrix MAC 并累加",1120,140,200,80,"normal"),
        ("post","POSTPROCESS","偏置、缩放、舍入与裁剪",1120,350,200,80,"normal"),("write","WRITE","写出一个 C 元素",830,350,220,80,"memory"),
        ("next","ADVANCE","推进 K、列、行或批次",550,350,210,80,"normal"),("done","DONE","保持完成消息",300,350,185,80,"done")], [
        ("i","idle","复位完成"),("idle","check","任务握手"),("check","addr","字段合法"),("check","done","检查失败"),
        ("addr","read","地址合法"),("read","mac","A/B 已就绪"),("mac","addr","还有 K 元素"),("mac","post","K 累加完成"),
        ("read","post","可选输入读取完成"),("post","write","写回数据有效"),("write","next","写响应成功"),("next","addr","还有输出元素"),
        ("next","done","全部完成"),("done","idle","完成握手")], 1450, 610)

    state_diagram("npu_vector_state_machine", "整数向量控制状态机", [
        ("i","","",40,165,0,0,"initial"),("idle","IDLE","等待向量任务",95,130,150,80,"normal"),
        ("check","CHECK","格式、形状和操作检查",300,130,190,80,"normal"),("addr","ADDRESS","形成并检查元素地址",560,130,200,80,"normal"),
        ("read","READ","读取掩码与源操作数",830,130,200,80,"memory"),("exec","EXECUTE","整数流水或向量乘法单元",1100,130,210,80,"normal"),
        ("write","WRITE","写回结果并等待响应",1100,345,210,80,"memory"),("advance","ADVANCE","推进元素或行",830,345,200,80,"normal"),
        ("fastread","FAST_READ","整拍读取两个输入",560,515,200,80,"memory"),("fastmul","FAST_MUL","分组请求向量乘法单元",830,515,200,80,"normal"),
        ("fastwrite","FAST_WRITE","成对写回 INT32 结果",1100,515,210,80,"memory"),("done","DONE","保持完成消息",300,345,190,80,"done")], [
        ("i","idle","复位完成"),("idle","check","任务握手"),("check","addr","通用路径"),("check","fastread","连续乘法快速路径"),
        ("check","done","检查失败"),("addr","read","地址合法"),("read","exec","操作数就绪"),("exec","write","结果有效"),
        ("write","advance","写响应成功"),("advance","addr","还有元素"),("advance","done","全部完成"),("fastread","fastmul","两个输入拍就绪"),
        ("fastmul","fastmul","还有分组"),("fastmul","fastwrite","全部乘积返回"),("fastwrite","fastwrite","下一输出对"),
        ("fastwrite","fastread","下一输入拍或下一行"),("fastwrite","done","最后输出对完成"),("done","idle","完成握手")], 1450, 720)

    state_diagram("npu_complex_state_machine", "复杂数学执行单元主状态机", [
        ("i","","",40,165,0,0,"initial"),("idle","IDLE","等待复杂数学任务",95,130,160,80,"normal"),
        ("check","CHECK","操作、scale、形状与地址检查",320,130,210,80,"normal"),("row","ROW_INIT","初始化当前行统计状态",600,130,200,80,"normal"),
        ("begin","ELEMENT_BEGIN","形成元素地址与掩码条件",870,130,220,80,"normal"),("read","READ","读取掩码与源操作数",1160,130,200,80,"memory"),
        ("compute","COMPUTE","统计更新或发起整数到 FP32",1160,350,200,80,"normal"),("math","MATH","顺序数学请求与响应",870,350,220,80,"wait"),
        ("f2i","F2I_PIPE","舍入、符号、零点与裁剪",600,350,200,80,"normal"),("write","WRITE","写出整数结果",320,350,210,80,"memory"),
        ("advance","ADVANCE","推进元素、行或计算阶段",600,550,200,80,"normal"),("done","DONE","保持完成消息",95,350,160,80,"done")], [
        ("i","idle","复位完成"),("idle","check","任务握手"),("check","row","字段合法"),("check","done","检查失败"),
        ("row","begin","当前行就绪"),("begin","read","需要源数据"),("begin","advance","掩码跳过"),("read","compute","源数据就绪"),
        ("compute","advance","整数统计更新"),("compute","math","需要 FP32 计算"),("math","f2i","输出需转为整数"),
        ("math","advance","只更新内部统计量"),("f2i","write","整数结果有效"),("write","advance","写响应成功"),
        ("advance","begin","同一阶段还有元素"),("advance","row","下一行"),("advance","done","全部阶段完成"),("done","idle","完成握手")], 1450, 740)

    state_diagram("npu_mif_state_machine", "系统存储接口状态机", [
        ("i","","",55,185,0,0,"initial"),("idle","IDLE","等待 DMA 请求并检查地址",120,145,210,90,"normal"),
        ("ar","READ_ADDR","保持 AR 通道字段",430,85,190,85,"memory"),("r","READ_DATA","接收一个 R 返回拍",720,85,190,85,"memory"),
        ("wr","WRITE_ISSUE","独立保持 AW 与 W",430,295,190,85,"memory"),("b","WRITE_RESP","等待 B 通道响应",720,295,190,85,"memory"),
        ("resp","INTERNAL_RESP","保持 DMA 响应与首错信息",1040,145,230,90,"done")], [
        ("i","idle","复位完成"),("idle","ar","合法读请求"),("ar","r","AR 握手"),("r","resp","R 握手"),
        ("idle","wr","合法写请求"),("wr","b","AW 与 W 均已握手"),("b","resp","B 握手"),("idle","resp","地址检查失败"),
        ("resp","r","多拍读仍有返回"),("resp","idle","响应握手且事务结束")], 1400, 520)


def fsm_topology(
    name: str,
    title: str,
    width: int,
    height: int,
    states: list[tuple],
    transitions: list[dict],
    *,
    regions: list[tuple] | None = None,
) -> None:
    """Draw a UML-style state topology with deterministic connector routing."""
    d = Drawio(name, title, width, height)
    boxes: dict[str, tuple[float, float, float, float]] = {}
    if regions:
        for region_title, x, y, w, h in regions:
            d.container(region_title, x, y, w, h, fill="#F8FAFC", stroke=COLORS["grid"], size=14)
    palette = {
        "normal": (COLORS["blue_fill"], COLORS["blue"]),
        "wait": (COLORS["amber_fill"], COLORS["amber"]),
        "done": (COLORS["green_fill"], COLORS["green"]),
        "error": (COLORS["red_fill"], COLORS["red"]),
        "memory": (COLORS["purple_fill"], COLORS["purple"]),
    }
    for item in states:
        key, label, detail, x, y, w, h, kind = item
        if kind == "initial":
            boxes[key] = (x, y, w, h)
            d.vertex("", x, y, w, h, fill=COLORS["ink"], stroke=COLORS["ink"], rounded=1, extra="ellipse;")
        elif kind == "choice":
            boxes[key] = (x, y, w, h)
            d.vertex("", x, y, w, h, fill=COLORS["white"], stroke=COLORS["blue"], rounded=0,
                     stroke_width=2.0, extra="shape=rhombus;perimeter=rhombusPerimeter;")
        elif kind == "junction":
            boxes[key] = (x, y, w, h)
            d.vertex("", x, y, w, h, fill=COLORS["blue"], stroke=COLORS["blue"], rounded=1, extra="ellipse;")
        elif kind == "final":
            boxes[key] = (x, y, w, h)
            d.vertex("", x, y, w, h, fill=COLORS["white"], stroke=COLORS["ink"], rounded=1,
                     stroke_width=2.4, extra="ellipse;shape=doubleEllipse;")
        else:
            h = max(h, 100)
            boxes[key] = (x, y, w, h)
            fill, stroke = palette[kind]
            d.vertex(_label(label, detail), x, y, w, h, fill=fill, stroke=stroke,
                     size=22, rounded=1, extra="arcSize=18;spacing=5;")

    def anchor(key: str, side: str, offset: float = 0.5) -> tuple[float, float]:
        x, y, w, h = boxes[key]
        if side == "left":
            return (x, y + h * offset)
        if side == "right":
            return (x + w, y + h * offset)
        if side == "top":
            return (x + w * offset, y)
        if side == "bottom":
            return (x + w * offset, y + h)
        raise ValueError(side)

    for transition in transitions:
        start = anchor(transition["src"], transition.get("src_side", "right"), transition.get("src_offset", 0.5))
        end = anchor(transition["dst"], transition.get("dst_side", "left"), transition.get("dst_offset", 0.5))
        points = [start, *transition.get("waypoints", []), end]
        d.segment(points, color=COLORS[transition.get("color", "blue")], width=2.5,
                  dashed=transition.get("dashed", False), arrow=True, curved=True)
        if transition.get("label") and transition.get("label_box"):
            lx, ly, lw, lh = transition["label_box"]
            d.text(transition["label"], lx, ly, lw, max(lh, 32), size=18, bold=True, color=COLORS["ink"], align="center")
    d.write()


def generate_state_topologies() -> None:
    fsm_topology("npu_task_lifecycle_state", "任务表项生命周期", 1600, 620, [
        ("i", "", "", 45, 190, 28, 28, "initial"),
        ("free", "FREE", "表项可分配", 120, 160, 190, 88, "normal"),
        ("wait", "WAIT_EVENT", "等待事件与前序任务", 390, 160, 220, 88, "wait"),
        ("ready", "READY", "满足发射条件", 700, 160, 190, 88, "normal"),
        ("run", "RUNNING", "执行单元已接收", 980, 160, 200, 88, "normal"),
        ("ok", "SUCCESS", "正确完成", 1310, 95, 190, 82, "done"),
        ("err", "ERROR", "检查或执行失败", 1310, 285, 190, 82, "error"),
    ], [
        {"src":"i","dst":"free","label":"[复位释放]","label_box":(74,145,95,24)},
        {"src":"free","dst":"wait","label":"command_accept","label_box":(310,128,80,24)},
        {"src":"wait","dst":"ready","label":"[dependencies_done]","label_box":(610,128,90,24)},
        {"src":"ready","dst":"run","label":"task_valid && task_ready","label_box":(888,128,95,24)},
        {"src":"run","dst":"ok","src_offset":0.32,"dst_offset":0.65,"label":"done [status=SUCCESS]","label_box":(1175,92,140,24)},
        {"src":"run","dst":"err","src_offset":0.72,"dst_offset":0.35,"label":"done [status!=SUCCESS]","label_box":(1178,300,135,24)},
        {"src":"ok","dst":"free","src_side":"top","dst_side":"top","waypoints":[(1405,58),(215,58)],"label":"software_ack","label_box":(745,28,110,24),"color":"green"},
        {"src":"err","dst":"free","src_side":"bottom","dst_side":"bottom","waypoints":[(1405,455),(215,455)],"label":"software_ack","label_box":(745,462,110,24),"color":"red"},
    ])

    fsm_topology("npu_cfe_state_machine", "命令前端状态机", 1600, 790, [
        ("i","","",35,170,26,26,"initial"),
        ("idle","IDLE","等待低 64-bit 分拍",100,140,180,84,"normal"),
        ("high","WAIT_HIGH","等待高分拍；最多 32 周期",360,140,200,84,"wait"),
        ("check","CHECK","组合指令并检查固定字段",640,140,210,84,"normal"),
        ("lookup","LOOKUP","查询任务编号是否空闲",930,140,210,84,"normal"),
        ("enqueue","ENQUEUE","完整指令写入队列",1220,140,190,84,"normal"),
        ("reject","REJECT","形成拒绝结果",470,430,620,88,"error"),
        ("resp","RESPOND","保持接收结果",1220,430,190,88,"done"),
    ], [
        {"src":"i","dst":"idle","label":"[复位释放]","label_box":(48,125,90,22)},
        {"src":"idle","dst":"high","label":"beat_accept [first]","label_box":(278,108,82,22)},
        {"src":"high","dst":"check","label":"beat_accept [last]","label_box":(558,108,82,22)},
        {"src":"check","dst":"lookup","label":"[fixed_fields_legal]","label_box":(846,108,88,22)},
        {"src":"lookup","dst":"enqueue","label":"[id_free && fifo_space]","label_box":(1135,108,88,22)},
        {"src":"idle","dst":"reject","src_side":"bottom","dst_side":"top","src_offset":0.35,"dst_offset":0.08,"waypoints":[(163,330),(330,330),(330,410),(520,410)],"label":"[首拍标志非法]","label_box":(180,295,130,22),"color":"red"},
        {"src":"high","dst":"reject","src_side":"bottom","dst_side":"top","src_offset":0.4,"dst_offset":0.35,"waypoints":[(440,360),(687,360)],"label":"[标志非法 || timeout]","label_box":(475,325,170,22),"color":"red"},
        {"src":"check","dst":"reject","src_side":"bottom","dst_side":"top","src_offset":0.5,"dst_offset":0.58,"waypoints":[(745,385),(830,385)],"label":"[固定字段非法]","label_box":(720,350,135,22),"color":"red"},
        {"src":"lookup","dst":"reject","src_side":"bottom","dst_side":"top","src_offset":0.62,"dst_offset":0.86,"waypoints":[(1060,410),(1003,410)],"label":"[编号占用 || fifo_full]","label_box":(1090,360,170,22),"color":"red"},
        {"src":"reject","dst":"resp","label":"reject_result_ready","label_box":(1088,397,132,22),"color":"red"},
        {"src":"enqueue","dst":"resp","src_side":"bottom","dst_side":"top","label":"accept_result_ready","label_box":(1388,302,140,22),"color":"green"},
        {"src":"resp","dst":"idle","src_side":"bottom","dst_side":"bottom","dst_offset":0.1,"waypoints":[(1315,650),(118,650)],"label":"result_valid && result_ready","label_box":(700,657,180,22)},
    ])

    fsm_topology("npu_dma_state_machine", "DMA 与布局转换主状态机", 1800, 990, [
        ("i","","",45,175,26,26,"initial"),("idle","IDLE","等待任务",105,145,150,82,"normal"),
        ("check","CHECK","操作与格式检查",320,145,170,82,"normal"),("shape","SHAPE","形状乘积计算",555,145,170,82,"normal"),
        ("region","REGION_CHECK","源、目的区域检查",790,145,190,82,"normal"),("init","CURSOR_INIT","地址与游标初始化",1045,145,190,82,"normal"),
        ("prep","PREP","当前项与快速条件",1300,145,180,82,"normal"),("read","READ","发出读并接收返回",1300,385,180,82,"memory"),
        ("convert","CONVERT","可选数据格式转换",1045,385,190,82,"normal"),("write","WRITE","发出写并等待确认",790,385,190,82,"memory"),
        ("advance","ADVANCE","推进元素、维度或分段",535,385,200,82,"normal"),("done","DONE","保持完成消息",270,385,180,82,"done"),
        ("drain","BURST_DRAIN","错误后排空剩余读返回",1045,625,190,82,"error"),
    ], [
        {"src":"i","dst":"idle","label":"[复位释放]","label_box":(55,130,85,22)},
        {"src":"idle","dst":"check","label":"task_valid && task_ready","label_box":(250,112,92,22)},
        {"src":"check","dst":"shape","label":"[普通搬运]","label_box":(487,112,68,22)},
        {"src":"shape","dst":"region","label":"[shape_legal]","label_box":(722,112,68,22)},
        {"src":"region","dst":"init","label":"[region_legal]","label_box":(977,112,70,22)},
        {"src":"init","dst":"prep","label":"cursor_ready","label_box":(1232,112,70,22)},
        {"src":"check","dst":"prep","src_side":"top","dst_side":"top","waypoints":[(405,75),(1390,75)],"label":"[分段任务]","label_box":(845,42,95,22)},
        {"src":"prep","dst":"read","src_side":"bottom","dst_side":"top","src_offset":0.75,"dst_offset":0.75,"label":"[need_read]","label_box":(1450,286,90,22)},
        {"src":"prep","dst":"write","src_side":"bottom","dst_side":"top","src_offset":0.25,"dst_offset":0.75,"waypoints":[(1345,300),(932,300)],"label":"[fill_operation]","label_box":(1080,266,105,22)},
        {"src":"read","dst":"convert","src_side":"left","dst_side":"right","label":"[element_return]","label_box":(1235,352,68,22)},
        {"src":"convert","dst":"write","src_side":"left","dst_side":"right","label":"convert_done","label_box":(978,352,70,22)},
        {"src":"write","dst":"advance","src_side":"left","dst_side":"right","label":"write_rsp [OK]","label_box":(728,352,62,22)},
        {"src":"advance","dst":"done","src_side":"left","dst_side":"right","label":"[all_done]","label_box":(450,352,82,22)},
        {"src":"advance","dst":"prep","src_side":"bottom","dst_side":"bottom","dst_offset":0.25,"waypoints":[(635,555),(1345,555)],"label":"[remaining]","label_box":(970,522,90,22)},
        {"src":"read","dst":"drain","src_side":"right","dst_side":"right","waypoints":[(1570,426),(1570,666)],"label":"[burst_error]","label_box":(1560,535,105,22),"color":"red"},
        {"src":"drain","dst":"done","src_side":"left","dst_side":"bottom","waypoints":[(900,666),(900,800),(360,800)],"label":"[剩余返回已接收]","label_box":(590,765,180,22),"color":"red"},
        {"src":"done","dst":"idle","src_side":"left","dst_side":"bottom","dst_offset":0.3,"waypoints":[(45,426),(45,270),(150,270)],"label":"done_valid && done_ready","label_box":(42,292,125,22),"color":"green"},
    ])

    fsm_topology("npu_direct_matrix_state_machine", "直接矩阵阵列控制状态机", 2050, 820, [
        ("i","","",40,165,26,26,"initial"),("idle","IDLE","等待直接矩阵任务",95,135,175,82,"normal"),
        ("setup","TILE_SETUP","清累加器并准备首个面板",330,135,210,82,"normal"),("accum","ACCUM_LOAD","读取并装入 8 个 C 列对",610,135,210,82,"memory"),
        ("prime","PANEL_PRIME","发出首个 A/B 面板读",890,135,200,82,"normal"),("wait","PANEL_WAIT","等待首个 A/B 面板",1160,135,190,82,"wait"),
        ("compute","COMPUTE","连续发射 K 组并预取下一面板",1420,135,230,82,"normal"),("drain","COMPUTE_DRAIN","等待最后乘积完成累加",1420,420,230,82,"wait"),
        ("prep","OUT_PREP","形成首个输出列对",1160,420,190,82,"normal"),("store","OUT_STORE","逐拍写出 8 个列对",890,420,200,82,"memory"),
        ("outwait","OUT_WAIT","等待最后写响应",610,420,210,82,"wait"),("done","DONE","保持完成消息",330,420,180,82,"done"),
    ], [
        {"src":"i","dst":"idle","label":"[复位释放]","label_box":(48,120,75,22)},
        {"src":"idle","dst":"setup","label":"task handshake","label_box":(270,103,72,22)},
        {"src":"setup","dst":"accum","label":"[accumulate_c]","label_box":(540,103,72,22)},
        {"src":"setup","dst":"prime","src_side":"top","dst_side":"top","waypoints":[(435,75),(990,75)],"label":"[!accumulate_c]","label_box":(665,42,105,22)},
        {"src":"accum","dst":"prime","label":"[all_c_pairs_loaded]","label_box":(820,103,72,22)},
        {"src":"prime","dst":"wait","label":"panel_req accepted","label_box":(1090,103,72,22)},
        {"src":"wait","dst":"compute","label":"panel_rsp [OK]","label_box":(1350,103,72,22)},
        {"src":"compute","dst":"drain","src_side":"bottom","dst_side":"top","label":"[last_k_issued]","label_box":(1648,292,105,22)},
        {"src":"drain","dst":"prep","src_side":"left","dst_side":"right","label":"pipeline_empty","label_box":(1350,388,72,22)},
        {"src":"prep","dst":"store","src_side":"left","dst_side":"right","label":"output_valid","label_box":(1090,388,72,22)},
        {"src":"store","dst":"outwait","src_side":"left","dst_side":"right","label":"[last_pair_issued]","label_box":(820,388,72,22)},
        {"src":"outwait","dst":"done","src_side":"left","dst_side":"right","label":"last_rsp [OK]","label_box":(510,388,100,22)},
        {"src":"done","dst":"idle","src_side":"bottom","dst_side":"bottom","waypoints":[(420,680),(182,680)],"label":"done handshake","label_box":(235,647,105,22),"color":"green"},
        {"src":"compute","dst":"compute","src_side":"bottom","dst_side":"bottom","src_offset":0.3,"dst_offset":0.7,"waypoints":[(1489,300),(1581,300)],"label":"[more_k && panel_ready]","label_box":(1470,307,130,22)},
        {"src":"store","dst":"store","src_side":"bottom","dst_side":"bottom","src_offset":0.7,"dst_offset":0.3,"waypoints":[(1030,555),(950,555)],"label":"[more_output_pairs]","label_box":(920,562,140,22)},
    ])

    fsm_topology("npu_scalar_matrix_state_machine", "标量矩阵控制状态机", 1700, 740, [
        ("i","","",38,165,26,26,"initial"),("idle","IDLE","等待矩阵任务",95,135,160,82,"normal"),
        ("check","CHECK","操作、形状与格式检查",320,135,190,82,"normal"),("addr","ADDRESS","分阶段形成输出与 A/B 地址",575,135,210,82,"normal"),
        ("read","READ_OPERANDS","依次读取 A、B 与可选输入",850,135,210,82,"memory"),("mac","MAC","请求 Scalar Matrix MAC 并累加",1125,135,190,82,"normal"),
        ("post","POSTPROCESS","偏置、缩放、舍入与裁剪",1125,405,190,82,"normal"),("write","WRITE","写出一个 C 元素",850,405,210,82,"memory"),
        ("next","ADVANCE","推进 K、列、行或批次",575,405,210,82,"normal"),("done","DONE","保持完成消息",320,405,190,82,"done"),
    ], [
        {"src":"i","dst":"idle","label":"[复位释放]","label_box":(45,120,70,22)},
        {"src":"idle","dst":"check","label":"task handshake","label_box":(255,103,65,22)},
        {"src":"check","dst":"addr","label":"[descriptor_legal]","label_box":(510,103,70,22)},
        {"src":"addr","dst":"read","label":"[address_legal]","label_box":(784,103,70,22)},
        {"src":"read","dst":"mac","label":"operands_ready","label_box":(1058,103,68,22)},
        {"src":"mac","dst":"post","src_side":"bottom","dst_side":"top","label":"[k_done]","label_box":(1315,292,90,22)},
        {"src":"mac","dst":"addr","src_side":"top","dst_side":"top","src_offset":0.25,"dst_offset":0.75,"waypoints":[(1173,75),(733,75)],"label":"[more_k]","label_box":(900,42,80,22)},
        {"src":"post","dst":"write","src_side":"left","dst_side":"right","label":"result_valid","label_box":(1060,373,65,22)},
        {"src":"write","dst":"next","src_side":"left","dst_side":"right","label":"write_rsp [OK]","label_box":(785,373,65,22)},
        {"src":"next","dst":"done","src_side":"left","dst_side":"right","label":"[all_done]","label_box":(510,373,65,22)},
        {"src":"next","dst":"addr","src_side":"top","dst_side":"bottom","src_offset":0.5,"dst_offset":0.5,"label":"[more_output]","label_box":(700,292,105,22)},
        {"src":"check","dst":"done","src_side":"bottom","dst_side":"top","waypoints":[(415,315),(415,315)],"label":"[descriptor_error]","label_box":(438,278,125,22),"color":"red"},
        {"src":"done","dst":"idle","src_side":"bottom","dst_side":"bottom","waypoints":[(415,600),(175,600)],"label":"done handshake","label_box":(230,567,105,22),"color":"green"},
    ])

    fsm_topology("npu_vector_state_machine", "整数向量控制状态机", 1800, 930, [
        ("i","","",40,175,26,26,"initial"),("idle","IDLE","等待向量任务",95,145,160,82,"normal"),("check","CHECK","格式、形状和操作检查",320,145,200,82,"normal"),
        ("choice","","",585,165,42,42,"choice"),("addr","ADDRESS","形成并检查元素地址",700,100,190,82,"normal"),("read","READ","读取掩码与源操作数",950,100,190,82,"memory"),("exec","EXECUTE","整数流水或 Vector Multiply Unit",1200,100,200,82,"normal"),
        ("write","WRITE","写回结果并等待响应",1450,100,190,82,"memory"),("advance","ADVANCE","推进元素或行",1450,350,190,82,"normal"),("done","DONE","保持完成消息",1200,350,200,82,"done"),
        ("fastread","FAST_READ","整拍读取两个输入",700,560,190,82,"memory"),("fastmul","FAST_MUL","分组请求 Vector Multiply Unit",950,560,190,82,"normal"),("fastwrite","FAST_WRITE","成对写回 INT32 结果",1200,560,200,82,"memory"),
        ("err","ERROR","形成描述符错误完成消息",330,400,200,82,"error"),
    ], [
        {"src":"i","dst":"idle","label":"[复位释放]","label_box":(46,130,72,22)},
        {"src":"idle","dst":"check","label":"task handshake","label_box":(255,112,65,22)},
        {"src":"check","dst":"choice","label":"[descriptor_legal]","label_box":(520,112,65,22)},
        {"src":"choice","dst":"addr","src_side":"right","dst_side":"left","label":"[general_path]","label_box":(625,70,85,22)},
        {"src":"addr","dst":"read","label":"[address_legal]","label_box":(888,67,65,22)},
        {"src":"read","dst":"exec","label":"operands_ready","label_box":(1138,67,65,22)},
        {"src":"exec","dst":"write","label":"result_valid","label_box":(1398,67,55,22)},
        {"src":"write","dst":"advance","src_side":"bottom","dst_side":"top","label":"write_rsp [OK]","label_box":(1640,250,105,22)},
        {"src":"advance","dst":"done","src_side":"left","dst_side":"right","label":"[all_done]","label_box":(1400,317,50,22)},
        {"src":"advance","dst":"addr","src_side":"top","dst_side":"bottom","src_offset":0.25,"dst_offset":0.75,"waypoints":[(1498,270),(843,270)],"label":"[more_elements]","label_box":(1130,237,100,22)},
        {"src":"choice","dst":"fastread","src_side":"bottom","dst_side":"top","waypoints":[(606,470),(795,470)],"label":"[continuous_mul]","label_box":(625,437,120,22)},
        {"src":"fastread","dst":"fastmul","label":"two_beats_ready","label_box":(888,527,65,22)},
        {"src":"fastmul","dst":"fastwrite","label":"all_products_ready","label_box":(1138,527,65,22)},
        {"src":"fastwrite","dst":"done","src_side":"top","dst_side":"bottom","src_offset":0.75,"dst_offset":0.75,"waypoints":[(1350,485),(1350,485)],"label":"[last_pair]","label_box":(1235,455,95,22)},
        {"src":"fastwrite","dst":"fastread","src_side":"bottom","dst_side":"bottom","waypoints":[(1300,720),(795,720)],"label":"[more_input]","label_box":(1010,687,90,22)},
        {"src":"check","dst":"err","src_side":"bottom","dst_side":"top","label":"[descriptor_error]","label_box":(330,292,130,22),"color":"red"},
        {"src":"err","dst":"idle","src_side":"left","dst_side":"bottom","waypoints":[(270,500),(175,500)],"label":"error handshake","label_box":(100,420,125,22),"color":"red"},
        {"src":"done","dst":"idle","src_side":"bottom","dst_side":"bottom","src_offset":1.0,"dst_offset":0.7,"waypoints":[(1500,520),(1500,850),(100,850)],"label":"done handshake","label_box":(620,817,125,22),"color":"green"},
    ])

    fsm_topology("npu_complex_state_machine", "复杂数学执行单元主状态机", 1950, 900, [
        ("i","","",40,175,26,26,"initial"),("idle","IDLE","等待复杂数学任务",95,145,170,82,"normal"),("check","CHECK","操作、scale、形状与地址检查",330,145,215,82,"normal"),
        ("row","ROW_INIT","初始化当前行统计状态",610,145,200,82,"normal"),("begin","ELEMENT_BEGIN","形成元素地址与掩码条件",875,145,220,82,"normal"),("read","READ","读取掩码与源操作数",1160,145,200,82,"memory"),
        ("compute","COMPUTE","统计更新或启动整数到 FP32",1430,145,210,82,"normal"),("math","MATH","顺序数学请求与响应",1430,405,210,82,"wait"),("f2i","F2I_PIPE","舍入、符号、零点与裁剪",1160,405,200,82,"normal"),
        ("write","WRITE","写出整数结果",875,405,220,82,"memory"),("advance","ADVANCE","推进元素、行或计算阶段",610,405,200,82,"normal"),("done","DONE","保持完成消息",330,405,215,82,"done"),
    ], [
        {"src":"i","dst":"idle","label":"[复位释放]","label_box":(47,130,72,22)},
        {"src":"idle","dst":"check","label":"task handshake","label_box":(265,112,68,22)},
        {"src":"check","dst":"row","label":"[descriptor_legal]","label_box":(545,112,65,22)},
        {"src":"row","dst":"begin","label":"row_ready","label_box":(810,112,65,22)},
        {"src":"begin","dst":"read","label":"[source_required]","label_box":(1095,112,65,22)},
        {"src":"read","dst":"compute","label":"source_ready","label_box":(1360,112,68,22)},
        {"src":"compute","dst":"math","src_side":"bottom","dst_side":"top","label":"[fp32_required]","label_box":(1640,292,115,22)},
        {"src":"math","dst":"f2i","src_side":"left","dst_side":"right","label":"[integer_output]","label_box":(1360,372,68,22)},
        {"src":"f2i","dst":"write","src_side":"left","dst_side":"right","label":"result_valid","label_box":(1095,372,65,22)},
        {"src":"write","dst":"advance","src_side":"left","dst_side":"right","label":"write_rsp [OK]","label_box":(810,372,65,22)},
        {"src":"advance","dst":"done","src_side":"left","dst_side":"right","label":"[all_stages_done]","label_box":(545,372,70,22)},
        {"src":"begin","dst":"advance","src_side":"bottom","dst_side":"top","src_offset":0.25,"dst_offset":0.75,"waypoints":[(930,315),(760,315)],"label":"[mask_skip]","label_box":(790,282,95,22)},
        {"src":"compute","dst":"advance","src_side":"right","dst_side":"bottom","src_offset":0.6,"dst_offset":0.2,"waypoints":[(1690,194),(1690,600),(650,600)],"label":"[statistics_only]","label_box":(1030,567,120,22)},
        {"src":"advance","dst":"begin","src_side":"left","dst_side":"top","src_offset":0.8,"dst_offset":0.5,"waypoints":[(570,471),(570,720),(1880,720),(1880,75),(985,75)],"label":"[more_elements]","label_box":(1160,687,110,22)},
        {"src":"advance","dst":"row","src_side":"top","dst_side":"bottom","src_offset":0.35,"dst_offset":0.35,"waypoints":[(680,300),(680,300)],"label":"[next_row]","label_box":(585,270,90,22)},
        {"src":"check","dst":"done","src_side":"bottom","dst_side":"top","label":"[descriptor_error]","label_box":(300,292,120,22),"color":"red"},
        {"src":"done","dst":"idle","src_side":"bottom","dst_side":"bottom","waypoints":[(438,810),(180,810)],"label":"done handshake","label_box":(235,777,110,22),"color":"green"},
    ])

    fsm_topology("npu_mif_state_machine", "系统存储接口状态机", 1600, 760, [
        ("i","","",45,185,26,26,"initial"),("idle","IDLE","等待 DMA 请求并检查地址",105,150,220,88,"normal"),("choice","","",390,172,44,44,"choice"),
        ("ar","READ_ADDR","保持 AR 通道字段",520,85,190,82,"memory"),("r","READ_DATA","接收一个 R 返回拍",790,85,190,82,"memory"),
        ("wr","WRITE_ISSUE","独立保持 AW 与 W",520,315,190,82,"memory"),("b","WRITE_RESP","等待 B 通道响应",790,315,190,82,"memory"),
        ("resp","INTERNAL_RESP","保持 DMA 响应与首错信息",1080,150,230,88,"done"),
    ], [
        {"src":"i","dst":"idle","label":"[复位释放]","label_box":(52,140,78,22)},
        {"src":"idle","dst":"choice","label":"req_valid && req_ready","label_box":(325,118,65,22)},
        {"src":"choice","dst":"ar","src_side":"top","dst_side":"left","waypoints":[(412,126),(470,126)],"label":"[legal_read]","label_box":(425,82,92,22)},
        {"src":"ar","dst":"r","label":"ARVALID && ARREADY","label_box":(708,52,84,22)},
        {"src":"r","dst":"resp","src_offset":0.7,"dst_offset":0.3,"label":"RVALID && RREADY","label_box":(975,112,120,22)},
        {"src":"choice","dst":"wr","src_side":"right","dst_side":"left","src_offset":0.8,"waypoints":[(475,270),(475,365)],"label":"[legal_write]","label_box":(490,238,115,22)},
        {"src":"wr","dst":"b","label":"AW_done && W_done","label_box":(708,282,84,22)},
        {"src":"b","dst":"resp","src_offset":0.3,"dst_offset":0.7,"label":"BVALID && BREADY","label_box":(985,392,110,22)},
        {"src":"choice","dst":"resp","src_side":"bottom","dst_side":"bottom","dst_offset":0.74,"waypoints":[(300,550),(1250,550)],"label":"[address_error]","label_box":(760,557,130,22),"color":"red"},
        {"src":"resp","dst":"r","src_side":"top","dst_side":"bottom","src_offset":0.3,"dst_offset":0.7,"waypoints":[(1149,55),(923,55)],"label":"[more_read_beats]","label_box":(982,8,145,22)},
        {"src":"resp","dst":"idle","src_side":"right","dst_side":"bottom","waypoints":[(1480,194),(1480,630),(215,630)],"label":"rsp_valid && rsp_ready && transaction_done","label_box":(620,637,270,22),"color":"green"},
    ])


def generate_waves() -> None:
    wave_diagram("npu_ready_valid_timing", "ready / valid 基本握手时序", [
        ("valid", ["0","1","1","1","0"]),("ready", ["0","0","0","1","1"]),
        ("payload", [".","P","P","P","."]),("transfer", [".",".",".","ACCEPT","."])], [(1,3,"valid 为 1 且 ready 为 0 时，payload 必须保持不变","green")])
    wave_diagram("npu_command_submit_timing", "128-bit 指令提交时序", [
        ("AWVALID", ["0","1","1","0","0","0"]),("AWREADY", ["0","0","1","1","1","1"]),
        ("WVALID", ["0","1","1","1","1","0"]),("WREADY", ["0","1","1","0","1","1"]),
        ("WDATA", [".","LOW 64b","HIGH 64b","HIGH 64b","HIGH 64b","."]),("WLAST", ["0","0","1","1","1","0"]),
        ("BVALID", ["0","0","0","0","0","1"])], [(1,4,"写数据暂停期间，高分拍及 WLAST 保持不变","green")])
    wave_diagram("npu_cfe_command_timing", "命令前端接收与转交时序", [
        ("beat_valid", ["1","1","0","0","0","0","0"]),("beat_data", ["BEAT_LO","BEAT_HI",".",".",".",".","."]),
        ("state", ["IDLE","WAIT_HI","CHECK","LOOKUP","ENQ","RESP","IDLE"]),
        ("task_cmd_valid", ["0","0","0","0","0","1","1"]),("task_cmd_ready", ["1","1","1","1","1","0","1"]),
        ("accept_rsp", [".",".",".",".",".","VALID","DONE"])], [(0,1,"两个 64-bit 分拍组成一条 128-bit 指令","blue"),(5,6,"输出暂停时完整指令保持不变","green")])
    wave_diagram("npu_scheduler_timing", "任务调度与完成时序", [
        ("command", ["ACCEPT",".",".",".",".",".",".","."]),("task_state", ["ADMIT","WAIT","READY","READY","RUN","RUN","DONE","FREE"]),
        ("engine_valid", ["0","0","1","1","0","0","0","0"]),("engine_ready", ["0","0","0","1","1","1","1","1"]),
        ("done_valid", ["0","0","0","0","0","1","1","0"]),("done_ready", ["1","1","1","1","1","0","1","1"]),
        ("notify", ["0","0","0","0","0","0","1","0"]),("software_ack", [".",".",".",".",".",".",".","ACK"])], [(2,3,"发射暂停期间任务信息保持不变","blue"),(5,6,"完成暂停期间完成信息保持不变","green")])
    wave_diagram("npu_dma_read_timing", "DMA：系统存储读取并写入 L1BUF", [
        ("memory_req", ["VALID",".",".",".",".","."]),("memory_rsp_valid", ["0","0","1","1","0","0"]),
        ("memory_rsp_ready", ["1","1","0","1","1","1"]),("l1_write_valid", ["0","0","0","1","1","0"]),
        ("l1_write_ready", ["1","1","1","0","1","1"]),("progress", [".",".",".",".","+8 B","."])], [(2,3,"系统存储返回在暂停期间保持","purple"),(3,4,"L1 写请求在暂停期间保持","green")])
    wave_diagram("npu_l1_read_timing", "L1BUF 普通端口读时序", [
        ("req_valid", ["0","1","1","0","0"]),("req_ready", ["0","0","1","1","1"]),("req_payload", [".","R","R",".","."]),
        ("bank_read", [".",".","ISSUE",".","."]),("rsp_valid", ["0","0","0","1","1"]),("rsp_ready", ["1","1","1","0","1"]),
        ("rsp_data", [".",".",".","D","D"])], [(1,2,"请求暂停期间地址保持","blue"),(3,4,"响应暂停期间数据与状态保持","green")])
    wave_diagram("npu_l1_write_timing", "L1BUF 普通端口写时序", [
        ("req_valid", ["0","1","1","0","0"]),("req_ready", ["0","0","1","1","1"]),("write_data", [".","D / strobe","D / strobe",".","."]),
        ("bank_write", [".",".","COMMIT",".","."]),("rsp_valid", ["0","0","0","1","1"]),("rsp_ready", ["1","1","1","0","1"])], [(1,2,"请求暂停期间地址、数据和字节写使能保持","blue"),(3,4,"写响应保持至接收方接受","green")])
    wave_diagram("npu_mif_read_timing", "系统存储接口 AXI 读时序", [
        ("ARVALID", ["0","1","1","0","0","0"]),("ARREADY", ["0","0","1","1","1","1"]),
        ("RVALID", ["0","0","0","1","1","0"]),("RREADY", ["1","1","1","0","1","1"]),
        ("RDATA / RLAST", [".",".",".","D / L","D / L","."]),("internal_rsp", [".",".",".",".","VALID","."])], [(1,2,"AR 暂停期间地址与属性保持","blue"),(3,4,"R 暂停期间数据、状态和末拍标志保持","purple")])
    wave_diagram("npu_mif_write_timing", "系统存储接口 AXI 写时序", [
        ("AWVALID", ["0","1","1","0","0","0"]),("AWREADY", ["0","0","1","1","1","1"]),
        ("WVALID", ["0","1","1","1","0","0"]),("WREADY", ["0","1","1","0","1","1"]),
        ("BVALID", ["0","0","0","0","1","1"]),("BREADY", ["1","1","1","1","0","1"]),
        ("internal_rsp", [".",".",".",".",".","DONE"])], [(1,3,"AW 与 W 可在不同周期握手；未完成通道保持有效","blue"),(4,5,"B 响应保持至内部接口接受","green")])
    wave_diagram("npu_power_up_timing", "上电与初始化时序", [
        ("power_good", ["0","1","1","1","1","1"]),("reset_n", ["0","0","0","1","1","1"]),
        ("clock_enable", ["0","0","1","1","1","1"]),("core_reset_n", ["0","0","0","0","1","1"]),
        ("accept_command", ["0","0","0","0","0","1"])], [(1,2,"电源稳定后允许时钟运行","teal"),(3,4,"外部复位解除后同步释放内部复位","green")])
    wave_diagram("npu_soft_reset_timing", "受控软复位时序", [
        ("accept_command", ["1","0","0","0","0","1"]),("core_idle", ["0","0","1","1","1","1"]),
        ("soft_reset_req", ["0","1","1","0","0","0"]),("functional_reset_n", ["1","1","0","0","1","1"]),
        ("reset_done", ["0","0","0","0","1","1"])], [(0,2,"先停止接收并等待活动事务结束","blue"),(2,4,"功能模块复位并同步释放","green")])
    wave_diagram("npu_power_down_timing", "断电准备时序", [
        ("stop_request", ["0","1","1","1","1","1"]),("accept_command", ["1","0","0","0","0","0"]),
        ("core_idle", ["0","0","0","1","1","1"]),("clock_enable", ["1","1","1","1","0","0"]),
        ("power_request", ["1","1","1","1","1","0"])], [(1,3,"停止接收后等待命令队列、任务和存储事务排空","blue"),(3,5,"空闲确认后依次关闭时钟与电源请求","teal")])
    wave_diagram("npu_task_pipeline_timing", "任务提交、依赖发射与完成时序", [
        ("GEMM command", ["ACCEPT",".",".",".",".",".",".","."]),("GEMM task", [".","READY","RUN","RUN","DONE",".",".","."]),
        ("activation command", [".","ACCEPT",".",".",".",".",".","."]),("activation task", [".","WAIT","WAIT","WAIT","READY","RUN","DONE","."]),
        ("event", ["FREE","PENDING","PENDING","PENDING","SUCCESS","SUCCESS","SUCCESS","."]),("completion", [".",".",".",".","GEMM",".","ACT","."])], [(1,4,"依赖任务通过事件等待矩阵任务完成","blue"),(4,6,"事件发布后允许复杂激活任务发射","green")])
    wave_diagram("npu_complex_element_timing", "复杂数学元素计算与写回时序", [
        ("task_state", ["READ","START","MATH","MATH","NORM","WRITE","NEXT"]),
        ("l1_rsp_valid", ["1","0","0","0","0","0","0"]),
        ("math_req_valid", ["0","1","1","0","0","0","0"]),
        ("math_req_ready", ["1","0","1","1","1","1","1"]),
        ("math_rsp_valid", ["0","0","0","1","0","0","0"]),
        ("l1_write_valid", ["0","0","0","0","0","1","0"]),
        ("progress", [".",".",".",".",".","+element","."])],
        [(1,2,"数学请求在暂停期间保持操作数和函数编号","blue"),(3,5,"数学返回经整数转换后才允许写回","green")])
    wave_diagram("npu_lstm_step_timing", "LSTM 单时间步任务依赖时序", [
        ("input_matrix", ["RUN","DONE",".",".",".",".",".","."]),
        ("state_matrix", ["RUN","RUN","DONE",".",".",".",".","."]),
        ("gate_sum", ["WAIT","WAIT","READY","RUN","DONE",".",".","."]),
        ("gate_activation", ["WAIT","WAIT","WAIT","WAIT","READY","RUN","DONE","."]),
        ("state_update", ["WAIT","WAIT","WAIT","WAIT","WAIT","WAIT","READY","DONE"]),
        ("event_release", [".","E0","E1",".","E2",".","E3","E4"])],
        [(0,2,"输入矩阵与状态矩阵可并行执行","blue"),(2,7,"门值求和、激活和状态更新按事件关系依次发射","green")])
    wave_diagram("npu_error_propagation_timing", "任务错误传播时序", [
        ("producer state", ["RUN","RUN","ERROR","ERROR","ERROR"]),("event state", ["PENDING","PENDING","ERROR","ERROR","ERROR"]),
        ("dependent state", ["WAIT","WAIT","WAIT","ERROR","ERROR"]),("dependent issue", ["0","0","0","0","0"]),
        ("completion notify", [".",".","SRC_ERR","DEP_ERR","."])], [(2,3,"失败事件使等待任务直接进入错误终态，不向执行单元发射","red")])


def main() -> None:
    global ONLY_NAMES
    parser = argparse.ArgumentParser()
    parser.add_argument("--group", choices=["all", "architecture", "module", "state", "wave"], default="all")
    parser.add_argument("--only", nargs="+", metavar="NAME", help="仅生成指定名称的图源")
    args = parser.parse_args()
    ONLY_NAMES = set(args.only) if args.only else None
    if args.group in {"all", "architecture"}:
        generate_architectures()
        generate_model_task_flows()
    if args.group in {"all", "module"}:
        generate_modules()
    if args.group in {"all", "state"}:
        generate_state_topologies()
    if args.group in {"all", "wave"}:
        generate_waves()


if __name__ == "__main__":
    main()
