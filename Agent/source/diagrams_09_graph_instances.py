#!/usr/bin/env python3
"""Draw the reusable workflow graph and one unfolded execution (illustrative).

The SVG preserves editable text. Requires matplotlib and a CJK font; PyMuPDF
provides a bundled fallback if the configured font is unavailable.
"""
from pathlib import Path
import os
import tempfile

os.environ.setdefault("MPLCONFIGDIR", str(Path(tempfile.gettempdir()) / "agent_report_mpl_cache"))
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib import font_manager
from matplotlib.patches import FancyBboxPatch, FancyArrowPatch
from matplotlib.path import Path as MplPath

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "figures"
OUT.mkdir(parents=True, exist_ok=True)
font_path = Path(os.environ.get("AGENT_REPORT_CJK_FONT", "/tmp/agent_report_fonts/DroidSansFallback.ttf"))
if not font_path.exists():
    import fitz
    font_path = Path(tempfile.gettempdir()) / "agent_report_cjk_fallback.ttf"
    font_path.write_bytes(fitz.Font("cjk").buffer)
font_manager.fontManager.addfont(str(font_path))
FONT = font_manager.FontProperties(fname=str(font_path))
matplotlib.rcParams.update({"font.family": FONT.get_name(), "svg.fonttype": "none", "axes.unicode_minus": False})

INK, BLUE, TEAL = "#183047", "#2864B4", "#11847B"
LIGHT, ORANGE, MUTED, LINE = "#F3F6FA", "#C97722", "#516579", "#A6B7C8"
PALE_BLUE, PALE_TEAL, PALE_ORANGE = "#EFF5FD", "#EDF8F5", "#FFF5E9"


def text(ax, x, y, s, size=18, color=INK, ha="center", va="center"):
    ax.text(x, y, s, fontsize=size, fontproperties=FONT, color=color,
            ha=ha, va=va, linespacing=1.5, zorder=5)


def box(ax, x, y, w, h, title, sub="", color=BLUE, fill=PALE_BLUE, size=21, subsize=17):
    ax.add_patch(FancyBboxPatch((x, y), w, h, boxstyle="round,pad=0,rounding_size=14",
                              linewidth=1.8, edgecolor=color, facecolor=fill, zorder=3))
    if sub:
        text(ax, x+w/2, y+h*0.29, title, size=size, color=INK)
        text(ax, x+w/2, y+h*0.70, sub, size=subsize, color=MUTED)
    else:
        text(ax, x+w/2, y+h/2, title, size=size, color=INK)


def arrow(ax, pts, color=BLUE):
    p = MplPath(pts, [MplPath.MOVETO] + [MplPath.LINETO]*(len(pts)-1))
    ax.add_patch(FancyArrowPatch(path=p, arrowstyle="-|>", mutation_scale=17,
                               color=color, lw=2.4, capstyle="round", joinstyle="round", zorder=4))


def main():
    fig, ax = plt.subplots(figsize=(20, 13), dpi=100)
    fig.subplots_adjust(0, 0, 1, 1)
    ax.set_xlim(0, 2000)
    ax.set_ylim(1300, 0)
    ax.set_aspect("equal")
    ax.axis("off")
    ax.plot([60, 60], [42, 92], color=TEAL, lw=5, solid_capstyle="round")
    text(ax, 85, 65, "09  设计图与运行展开图", size=27, ha="left")
    text(ax, 85, 118, "同一节点可以在一次运行中被多次调用；右侧为结构示意，不是实测轨迹。", size=17, color=MUTED, ha="left")
    text(ax, 510, 205, "设计图：可复用的流程模板", size=22, color=BLUE)
    text(ax, 1495, 205, "运行展开图：示例中的调用实例", size=22, color=TEAL)
    ax.plot([1000, 1000], [180, 1100], color=LINE, lw=1.4)

    # Template: one check node can be revisited by a business loop.
    box(ax, 180, 310, 330, 150, "检查", "node_id = check")
    box(ax, 180, 565, 330, 150, "修复", "node_id = repair", color=TEAL, fill=PALE_TEAL)
    box(ax, 640, 310, 280, 150, "完成", "成功出口", color=TEAL, fill=PALE_TEAL)
    box(ax, 640, 565, 280, 150, "报告阻塞", "预算耗尽出口", color=ORANGE, fill=PALE_ORANGE)

    arrow(ax, [(510, 350), (640, 350)], color=TEAL)
    text(ax, 575, 317, "通过", size=17, color=TEAL)
    arrow(ax, [(345, 460), (345, 565)], color=ORANGE)
    text(ax, 385, 512, "未通过且\n预算允许", size=17, color=ORANGE, ha="left")
    arrow(ax, [(510, 420), (575, 420), (575, 640), (640, 640)], color=ORANGE)
    text(ax, 645, 512, "未通过且\n预算耗尽", size=17, color=ORANGE)
    arrow(ax, [(180, 640), (120, 640), (120, 385), (180, 385)], color=TEAL)
    text(ax, 76, 510, "复查", size=17, color=TEAL)

    box(ax, 110, 825, 820, 250, "", color=LINE, fill=LIGHT)
    text(ax, 145, 867, "业务循环重复调用同一个节点", size=20, color=BLUE, ha="left")
    text(ax, 145, 930, "• 模板中的 node_id 保持不变。", size=18, ha="left")
    text(ax, 145, 987, "• 再次检查会创建新的调用实例。", size=18, ha="left")
    text(ax, 145, 1040, "• 条件分支决定本次运行经过哪些节点。", size=18, ha="left")

    # Execution: an example in which the first check fails and the second passes.
    box(ax, 1170, 300, 650, 140, "检查 #1：未通过",
        "node_id = check\nnode_instance_id = check@1", subsize=17)
    box(ax, 1170, 510, 650, 140, "修复 #1",
        "node_id = repair\nnode_instance_id = repair@1", color=TEAL, fill=PALE_TEAL, subsize=17)
    box(ax, 1170, 720, 650, 140, "检查 #2：通过",
        "node_id = check\nnode_instance_id = check@2", subsize=17)
    box(ax, 1170, 930, 650, 140, "完成", "本次运行结束", color=TEAL, fill=PALE_TEAL, subsize=18)
    arrow(ax, [(1495, 440), (1495, 510)], color=ORANGE)
    text(ax, 1540, 475, "未通过且预算允许", size=17, color=ORANGE, ha="left")
    arrow(ax, [(1495, 650), (1495, 720)], color=TEAL)
    text(ax, 1540, 685, "再次调用 check", size=17, color=TEAL, ha="left")
    arrow(ax, [(1495, 860), (1495, 930)], color=TEAL)
    text(ax, 1540, 895, "通过", size=17, color=TEAL, ha="left")

    text(ax, 1000, 1170, "两次检查的 node_id 相同，node_instance_id 不同；业务循环展开后可以按调用实例追踪。", size=19, color=INK)
    text(ax, 1000, 1230, "check@1 / check@2 为示意标识；实际系统还需绑定 run_id 与流程版本。", size=17, color=MUTED)
    name = "09_graph_instances"
    for ext in ("png", "svg"):
        tmp = OUT / f".{name}.{os.getpid()}.{ext}"
        fig.savefig(tmp, format=ext, dpi=100, facecolor="white")
        os.replace(tmp, OUT / f"{name}.{ext}")
    plt.close(fig)


if __name__ == "__main__":
    main()
