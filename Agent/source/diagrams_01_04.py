#!/usr/bin/env python3
"""Generate editable SVG and high-resolution PNG diagrams for the report.

Run from any directory:
    python3 diagrams_01_04.py

Outputs are written to ../figures/. SVG keeps native text elements.
The default CJK font path can be overridden with AGENT_REPORT_CJK_FONT.
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
from matplotlib.patches import FancyBboxPatch, FancyArrowPatch
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
plt.rcParams.update({
    "font.family": FONT_NAME,
    "font.size": 18,
    "svg.fonttype": "none",
    "axes.unicode_minus": False,
})

NAVY = "#183047"
BLUE = "#2864B4"
TEAL = "#11847B"
GRAY = "#F3F6FA"
ORANGE = "#C97722"
MUTED = "#556A7C"
BORDER = "#C7D3DF"
LIGHTBLUE = "#EDF3FD"
LIGHTTEAL = "#ECF7F5"
LIGHTORANGE = "#FFF5E9"


def canvas(title: str, subtitle: str):
    fig = plt.figure(figsize=(16, 10), dpi=180, facecolor="white")
    ax = fig.add_axes([0, 0, 1, 1])
    ax.set_xlim(0, 1600)
    ax.set_ylim(1000, 0)
    ax.axis("off")
    text(ax, 65, 65, title, 27, NAVY, ha="left")
    text(ax, 65, 121, subtitle, 18, MUTED, ha="left")
    ax.plot([65, 1535], [153, 153], color=BORDER, lw=1.2)
    text(ax, 65, 966, "设计归纳示意；具体框架行为以正文为准", 14, MUTED, ha="left")
    return fig, ax


def text(ax, x, y, value, size=18, color=NAVY, *, ha="center", va="center", weight="normal", linespacing=1.45):
    return ax.text(x, y, value, fontsize=size, color=color, ha=ha, va=va,
                   fontfamily=FONT_NAME, weight=weight, linespacing=linespacing,
                   zorder=5)


def rect(ax, x, y, w, h, *, fill="white", edge=BORDER, radius=18, lw=1.8):
    patch = FancyBboxPatch((x, y), w, h,
                          boxstyle=f"round,pad=0,rounding_size={radius}",
                          linewidth=lw, edgecolor=edge, facecolor=fill,
                          zorder=2)
    ax.add_patch(patch)
    return patch


def box(ax, x, y, w, h, title, subtitle=None, *, fill="white", edge=BORDER,
        title_color=NAVY, title_size=21, sub_size=17):
    rect(ax, x, y, w, h, fill=fill, edge=edge)
    if subtitle is None:
        text(ax, x+w/2, y+h/2, title, title_size, title_color)
    else:
        text(ax, x+w/2, y+h*0.36, title, title_size, title_color)
        text(ax, x+w/2, y+h*0.73, subtitle, sub_size, MUTED)


def arrow(ax, pts, *, color=NAVY, lw=2.2, dashed=False):
    path = MplPath(pts, [MplPath.MOVETO] + [MplPath.LINETO] * (len(pts)-1))
    patch = FancyArrowPatch(path=path, arrowstyle="-|>", mutation_scale=20,
                            linewidth=lw, color=color,
                            linestyle="--" if dashed else "-", zorder=3)
    ax.add_patch(patch)
    return patch


def line(ax, pts, *, color=NAVY, lw=2.2):
    xs, ys = zip(*pts)
    ax.plot(xs, ys, color=color, lw=lw, solid_capstyle="round", zorder=3)


def save(fig, stem):
    # Render to a private temporary directory first, so other readers never
    # observe an incomplete PNG while the final artifact is being generated.
    try:
        with tempfile.TemporaryDirectory(prefix=f".{stem}_", dir=OUT) as temp_dir:
            temp_root = Path(temp_dir)
            temp_svg = temp_root / f"{stem}.svg"
            temp_png = temp_root / f"{stem}.png"
            fig.savefig(temp_svg, format="svg", facecolor="white")
            fig.savefig(temp_png, format="png", dpi=180, facecolor="white")
            with Image.open(temp_png) as rendered:
                rendered.verify()
            os.replace(temp_svg, OUT / f"{stem}.svg")
            os.replace(temp_png, OUT / f"{stem}.png")
    finally:
        plt.close(fig)


def diagram_01():
    fig, ax = canvas("Flow 与团队是两个独立设计维度",
                     "控制方式决定谁选择下一步；团队规模决定有多少独立 Agent 参与。")
    text(ax, 560, 195, "单个 Agent", 23, BLUE)
    text(ax, 1180, 195, "多个 Agent", 23, TEAL)
    text(ax, 135, 370, "明确规则\n主导调度", 22, BLUE)
    text(ax, 135, 660, "模型动态\n决定下一步", 22, TEAL)

    cards = [
        (270, 245, LIGHTBLUE, BLUE, "规则流程 + 单 Agent", "由程序规定步骤与失败路径", "校验脚本、Agent 诊断、程序验收"),
        (890, 245, LIGHTBLUE, BLUE, "规则流程 + 多 Agent", "由程序安排分工、并发与汇合", "多个专家分别分析，程序汇总"),
        (270, 535, LIGHTTEAL, TEAL, "动态执行 + 单 Agent", "Agent 根据结果选择下一项工具", "一个执行循环，按需调用工具"),
        (890, 535, LIGHTTEAL, TEAL, "动态执行 + 多 Agent", "协调者按任务选择专家与委派方式", "动态拆分任务，受预算与权限约束"),
    ]
    for x, y, fill, accent, title, first, second in cards:
        rect(ax, x, y, 580, 250, fill=fill, edge=accent, lw=2.2)
        text(ax, x+290, y+52, title, 22, accent)
        ax.plot([x+35, x+545], [y+95, y+95], color=BORDER, lw=1.1, zorder=4)
        text(ax, x+290, y+139, first, 19)
        text(ax, x+290, y+195, second, 18, MUTED)

    rect(ax, 270, 835, 1200, 80, fill=GRAY, edge=BORDER)
    text(ax, 870, 875, "一个 Flow 可以包含团队节点；同一团队也可以采用明确的执行规则。", 21)
    save(fig, "01_flow_team")


def diagram_02():
    fig, ax = canvas("三种团队模式具有不同的控制与返回行为",
                     "箭头表示控制或结果传递；委派、移交和并行汇合需要分别定义。")
    for x, accent in ((50, BLUE), (560, TEAL), (1070, BLUE)):
        rect(ax, x, 185, 480, 710, fill=GRAY, edge=BORDER)
        ax.plot([x+25, x+455], [285, 285], color=accent, lw=2.3)

    text(ax, 290, 227, "Agent 作为工具", 23, BLUE)
    text(ax, 290, 263, "委派后返回调用者", 17, MUTED)
    box(ax, 130, 330, 320, 100, "经理 Agent", "选择子任务", edge=BLUE, fill=LIGHTBLUE)
    box(ax, 130, 500, 320, 100, "Worker Agent", "执行明确的子任务", edge=BLUE)
    box(ax, 130, 670, 320, 100, "经理继续处理", "检查结果并决定下一步", edge=BLUE, fill=LIGHTBLUE)
    arrow(ax, [(290, 430), (290, 500)], color=BLUE)
    text(ax, 345, 465, "调用", 17, BLUE, ha="left")
    arrow(ax, [(290, 600), (290, 670)], color=BLUE)
    text(ax, 345, 635, "返回结果", 17, BLUE, ha="left")
    text(ax, 290, 835, "经理保留主任务控制权", 18)

    text(ax, 800, 227, "Handoff 移交", 23, TEAL)
    text(ax, 800, 263, "转交后续处理权", 17, MUTED)
    box(ax, 640, 350, 320, 110, "主处理者 A", "识别适合的接手者", edge=TEAL, fill=LIGHTTEAL)
    box(ax, 640, 625, 320, 120, "主处理者 B", "继续处理并完成任务", edge=TEAL, fill=LIGHTTEAL)
    arrow(ax, [(800, 460), (800, 625)], color=TEAL)
    text(ax, 828, 543, "移交", 18, TEAL, ha="left")
    text(ax, 800, 802, "不隐含自动返回 A", 19)
    text(ax, 800, 845, "返回必须另设控制规则", 17, MUTED)

    text(ax, 1310, 227, "并行专家", 23, BLUE)
    text(ax, 1310, 263, "分片执行与结果汇合", 17, MUTED)
    box(ax, 1160, 325, 300, 85, "任务数据", edge=BLUE, fill=LIGHTBLUE)
    line(ax, [(1310, 410), (1310, 440), (1185, 440)])
    line(ax, [(1310, 440), (1435, 440)])
    arrow(ax, [(1185, 440), (1185, 505)])
    arrow(ax, [(1435, 440), (1435, 505)])
    text(ax, 1150, 478, "分片 1", 16, MUTED, ha="right")
    text(ax, 1470, 478, "分片 2", 16, MUTED, ha="left")
    box(ax, 1095, 505, 180, 100, "专家 1", edge=BLUE, title_size=20)
    box(ax, 1345, 505, 180, 100, "专家 2", edge=BLUE, title_size=20)
    line(ax, [(1185, 605), (1185, 665), (1310, 665)])
    line(ax, [(1435, 605), (1435, 665), (1310, 665)])
    text(ax, 1148, 635, "结果 1", 16, MUTED, ha="right")
    text(ax, 1472, 635, "结果 2", 16, MUTED, ha="left")
    arrow(ax, [(1310, 665), (1310, 710)])
    box(ax, 1140, 710, 340, 90, "程序汇总 / 验收", edge=TEAL, fill=LIGHTTEAL, title_size=21)
    text(ax, 1310, 852, "按输入契约收集结果与证据", 17)
    save(fig, "02_team_patterns")


def diagram_03():
    fig, ax = canvas("推荐架构：明确外层流程，局部使用受控团队",
                     "程序管理阶段与验收条件；Agent 负责需要判断、规划和修复的局部任务。")
    box(ax, 80, 220, 300, 120, "输入与环境校验", "工程、工具与前置条件", edge=BLUE, fill=LIGHTBLUE)
    box(ax, 520, 220, 420, 120, "任务子流程", "确定步骤 + Agent 节点", edge=BLUE, fill=LIGHTBLUE)
    box(ax, 1110, 220, 360, 120, "程序验收", "检查真实报告与阈值", edge=TEAL, fill=LIGHTTEAL)
    arrow(ax, [(380, 280), (520, 280)], color=BLUE)
    arrow(ax, [(940, 280), (1110, 280)], color=BLUE)

    rect(ax, 250, 500, 800, 275, fill=GRAY, edge=TEAL, lw=2.3)
    text(ax, 650, 542, "受控局部团队（示例）", 23, TEAL)
    box(ax, 290, 590, 210, 100, "规划", "确定修复范围", edge=TEAL, title_size=21, sub_size=16)
    box(ax, 545, 590, 210, 100, "专家执行", "调用允许的工具", edge=TEAL, title_size=21, sub_size=16)
    box(ax, 800, 590, 210, 100, "证据检查", "返回结果与依据", edge=TEAL, title_size=21, sub_size=16)
    arrow(ax, [(500, 640), (545, 640)], color=TEAL)
    arrow(ax, [(755, 640), (800, 640)], color=TEAL)
    text(ax, 650, 737, "限制迭代轮数、工具范围、运行时间与成本", 18, MUTED)

    arrow(ax, [(1290, 340), (1290, 640), (1050, 640)], color=ORANGE)
    text(ax, 1320, 472, "未达标", 20, ORANGE, ha="left")
    text(ax, 1320, 515, "进入局部修复", 17, MUTED, ha="left")
    arrow(ax, [(730, 500), (730, 340)], color=TEAL)
    text(ax, 700, 403, "修复后重跑\n受影响的步骤", 18, TEAL, ha="right")

    box(ax, 1110, 815, 320, 95, "交付已验证制品", edge=TEAL, fill=LIGHTTEAL, title_size=22)
    arrow(ax, [(1470, 280), (1530, 280), (1530, 862.5), (1430, 862.5)], color=TEAL)
    text(ax, 1500, 740, "达标", 20, TEAL, ha="right")

    arrow(ax, [(650, 775), (650, 835)], color=ORANGE)
    rect(ax, 250, 835, 800, 75, fill=LIGHTORANGE, edge=ORANGE)
    text(ax, 650, 872, "预算耗尽：暂停并报告已知问题", 21, ORANGE)
    save(fig, "03_hybrid_execution")


def entity(ax, x, y, w, h, name, fields, accent):
    rect(ax, x, y, w, h, edge=accent, fill="white", lw=2)
    text(ax, x+w/2, y+42, name, 23, accent)
    ax.plot([x+24, x+w-24], [y+76, y+76], color=BORDER, lw=1.0, zorder=4)
    text(ax, x+w/2, y+80+(h-80)/2, fields, 18, NAVY, linespacing=1.5)


def diagram_04():
    fig, ax = canvas("五类实体分离设计定义与实际运行",
                     "角色、团队和流程可以复用；每次运行固定定义版本，并记录结果文件与证据。")
    rect(ax, 45, 175, 1510, 410, fill=GRAY, edge=BORDER)
    text(ax, 75, 208, "设计态：可版本化定义", 20, BLUE, ha="left")
    entity(ax, 80, 250, 400, 220, "AgentSpec", "角色与目标\n工具与权限\n输入 / 输出约束", BLUE)
    entity(ax, 600, 250, 400, 220, "TeamSpec", "成员引用\n协作方式与预算\n委派 / 移交规则", TEAL)
    entity(ax, 1120, 250, 400, 220, "FlowSpec", "节点与后继条件\n状态结构与版本\n验收与失败路径", BLUE)
    arrow(ax, [(600, 360), (480, 360)], color=TEAL)
    text(ax, 540, 318, "成员", 17, TEAL)
    arrow(ax, [(1120, 360), (1000, 360)], color=BLUE)
    text(ax, 1060, 318, "调用", 17, BLUE)
    arrow(ax, [(1210, 470), (1210, 525), (280, 525), (280, 470)], color=BLUE)
    text(ax, 745, 558, "Flow 节点也可直接调用单个 Agent", 18, BLUE)

    rect(ax, 45, 620, 1510, 295, fill=LIGHTTEAL, edge=BORDER)
    text(ax, 75, 651, "运行态：一次具体执行", 20, TEAL, ha="left")
    entity(ax, 100, 690, 520, 190, "Artifact", "文件位置与内容 hash\n来源步骤、报告与证据", TEAL)
    entity(ax, 850, 690, 520, 190, "RunState", "固定 flowVersion\n当前步骤、预算与 checkpoint", TEAL)
    arrow(ax, [(850, 785), (620, 785)], color=TEAL)
    text(ax, 735, 743, "产出 / 引用", 18, TEAL)
    arrow(ax, [(1450, 470), (1450, 785), (1370, 785)], color=BLUE)
    text(ax, 1415, 603, "固定版本创建运行", 17, BLUE, ha="right")
    save(fig, "04_data_model")


if __name__ == "__main__":
    diagram_01()
    diagram_02()
    diagram_03()
    diagram_04()
    for legacy_suffix in ("png", "svg"):
        (OUT / f"03_hybrid_architecture.{legacy_suffix}").unlink(missing_ok=True)
    print(f"Saved 4 editable SVG files and 4 PNG files to {OUT}")
