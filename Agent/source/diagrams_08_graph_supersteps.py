#!/usr/bin/env python3
"""Editable SVG + PNG: graph super-step read/write visibility.

The example only merges pure diagnosis results. It does not depict external
transaction, side-effect rollback, or exactly-once execution guarantees.
"""
from __future__ import annotations

import os
import tempfile
from pathlib import Path

os.environ.setdefault("MPLCONFIGDIR", "/tmp/agent_report_mpl")

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib import font_manager
from matplotlib.patches import FancyArrowPatch, FancyBboxPatch
from matplotlib.path import Path as MplPath
from PIL import Image


ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "figures"
OUT.mkdir(parents=True, exist_ok=True)
FONT = Path(os.environ.get("AGENT_REPORT_CJK_FONT", "/tmp/agent_report_fonts/DroidSansFallback.ttf"))
if not FONT.exists():
    import fitz
    FONT.parent.mkdir(parents=True, exist_ok=True)
    FONT.write_bytes(fitz.Font("cjk").buffer)
font_manager.fontManager.addfont(str(FONT))
FONT_NAME = font_manager.FontProperties(fname=str(FONT)).get_name()
plt.rcParams.update({"font.family": FONT_NAME, "svg.fonttype": "none", "axes.unicode_minus": False})

NAVY = "#183047"
BLUE = "#2864B4"
TEAL = "#11847B"
ORANGE = "#C97722"
GRAY = "#F3F6FA"
BORDER = "#C7D3DF"
MUTED = "#556A7C"
LIGHTBLUE = "#EDF3FD"
LIGHTTEAL = "#ECF7F5"
LIGHTORANGE = "#FFF5E9"


def text(ax, x, y, value, size=18, color=NAVY, ha="center", spacing=1.35):
    ax.text(x, y, value, fontsize=size, color=color, ha=ha, va="center",
            fontfamily=FONT_NAME, linespacing=spacing, zorder=5)


def rect(ax, x, y, w, h, fill="white", edge=BORDER, radius=16):
    ax.add_patch(FancyBboxPatch((x, y), w, h,
                 boxstyle=f"round,pad=0,rounding_size={radius}",
                 facecolor=fill, edgecolor=edge, linewidth=1.9, zorder=2))


def node(ax, x, y, w, h, title, subtitle, fill="white", edge=BLUE):
    rect(ax, x, y, w, h, fill, edge)
    text(ax, x+w/2, y+h*0.36, title, 22, edge)
    text(ax, x+w/2, y+h*0.73, subtitle, 18, MUTED)


def line(ax, pts, color=NAVY):
    xs, ys = zip(*pts)
    ax.plot(xs, ys, color=color, linewidth=2.2, zorder=3)


def arrow(ax, pts, color=NAVY):
    path = MplPath(pts, [MplPath.MOVETO] + [MplPath.LINETO]*(len(pts)-1))
    ax.add_patch(FancyArrowPatch(path=path, arrowstyle="-|>", mutation_scale=20,
                                linewidth=2.2, color=color, zorder=3))


def main():
    fig = plt.figure(figsize=(16, 10), dpi=180, facecolor="white")
    ax = fig.add_axes([0, 0, 1, 1])
    ax.set_xlim(0, 1600)
    ax.set_ylim(1000, 0)
    ax.axis("off")
    text(ax, 65, 63, "Pregel：本阶段写入在下一阶段才可见", 27, ha="left")
    text(ax, 65, 116, "并行节点读取阶段开始的状态；阶段结束后，reducer 合并各节点返回的更新。",
         18, MUTED, ha="left")
    ax.plot([65, 1535], [153, 153], color=BORDER, linewidth=1.2)

    rect(ax, 65, 190, 1470, 475, GRAY, BORDER)
    text(ax, 95, 226, "super-step k", 23, BLUE, ha="left")
    text(ax, 1500, 226, "纯诊断示例：两个节点都只产生结果数据", 17, MUTED, ha="right")

    node(ax, 100, 360, 300, 160, "已提交状态 S(k)", "diagnoses = {}", LIGHTBLUE, BLUE)
    node(ax, 520, 290, 300, 110, "节点 A", "读取同一份 S(k)", "white", BLUE)
    node(ax, 520, 490, 300, 110, "节点 B", "读取同一份 S(k)", "white", BLUE)
    line(ax, [(400, 440), (455, 440)], BLUE)
    line(ax, [(455, 345), (455, 545)], BLUE)
    arrow(ax, [(455, 345), (520, 345)], BLUE)
    arrow(ax, [(455, 545), (520, 545)], BLUE)

    rect(ax, 500, 415, 340, 62, LIGHTORANGE, ORANGE, radius=12)
    text(ax, 670, 446, "即使 A 先完成\nB 也看不到 A 本阶段写入", 16, ORANGE)

    rect(ax, 960, 305, 220, 80, "white", BLUE)
    text(ax, 1070, 345, "{A: 诊断 A}", 18, BLUE)
    rect(ax, 960, 505, 220, 80, "white", BLUE)
    text(ax, 1070, 545, "{B: 诊断 B}", 18, BLUE)
    arrow(ax, [(820, 345), (960, 345)], BLUE)
    arrow(ax, [(820, 545), (960, 545)], BLUE)
    text(ax, 890, 314, "返回更新", 16, MUTED)
    text(ax, 890, 514, "返回更新", 16, MUTED)

    node(ax, 1280, 350, 220, 180, "阶段结束", "reducer 按键合并", LIGHTTEAL, TEAL)
    arrow(ax, [(1180, 345), (1230, 345), (1230, 400), (1280, 400)], TEAL)
    arrow(ax, [(1180, 545), (1230, 545), (1230, 480), (1280, 480)], TEAL)

    rect(ax, 65, 715, 1470, 190, LIGHTTEAL, BORDER)
    text(ax, 95, 750, "super-step k+1", 23, TEAL, ha="left")
    node(ax, 300, 785, 720, 100, "已合并状态 S(k+1)",
         "diagnoses = {A: 诊断 A, B: 诊断 B}", "white", TEAL)
    node(ax, 1160, 785, 320, 100, "汇总节点 C", "读取两个诊断结果", "white", TEAL)
    arrow(ax, [(1390, 530), (1390, 685), (660, 685), (660, 785)], TEAL)
    arrow(ax, [(1020, 835), (1160, 835)], TEAL)
    text(ax, 1090, 800, "下一阶段读取", 15, MUTED)

    text(ax, 65, 940,
         "此例仅合并无副作用的诊断数据；图状态同步不保证外部工具只执行一次。",
         17, MUTED, ha="left")
    text(ax, 65, 981, "设计归纳示意；具体框架行为以正文为准", 14, MUTED, ha="left")

    stem = "08_graph_supersteps"
    try:
        with tempfile.TemporaryDirectory(prefix=f".{stem}_", dir=OUT) as td:
            temporary = Path(td)
            svg = temporary / f"{stem}.svg"
            png = temporary / f"{stem}.png"
            fig.savefig(svg, format="svg", facecolor="white")
            fig.savefig(png, format="png", dpi=180, facecolor="white")
            with Image.open(png) as im:
                im.verify()
            os.replace(svg, OUT / svg.name)
            os.replace(png, OUT / png.name)
    finally:
        plt.close(fig)
    print(f"Saved {OUT / (stem + '.svg')}")
    print(f"Saved {OUT / (stem + '.png')}")


if __name__ == "__main__":
    main()
