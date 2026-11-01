#!/usr/bin/env python3
"""Draw four semantic projections of the same one-round review workflow.

Run: python3 diagrams_06_graph_models.py
Outputs: ../figures/06_graph_models.{svg,png}
All nodes, fields and event names are illustrative application design, not an SDK API.
"""
from __future__ import annotations

import os
os.environ.setdefault("MPLCONFIGDIR", "/tmp/agent_report_mpl")

import matplotlib.pyplot as plt
from matplotlib.patches import Polygon

from diagrams_01_04 import (
    NAVY, BLUE, TEAL, GRAY, ORANGE, MUTED, BORDER,
    LIGHTBLUE, LIGHTTEAL, LIGHTORANGE,
    text, rect, box, arrow, line, save,
)


def panel(ax, x, y, number, heading, subtitle):
    rect(ax, x, y, 820, 530, fill="white", edge=BORDER, radius=20, lw=1.6)
    rect(ax, x+22, y+20, 35, 35, fill=LIGHTTEAL, edge=TEAL, radius=9, lw=1.4)
    text(ax, x+39.5, y+37, number, 19, TEAL)
    text(ax, x+76, y+38, heading, 22, NAVY, ha="left")
    text(ax, x+26, y+77, subtitle, 16, MUTED, ha="left")
    ax.plot([x+26, x+794], [y+100, y+100], color=BORDER, lw=1)


def process(ax, x, y, w, h, label, *, accent=BLUE, fill=LIGHTBLUE, size=18):
    box(ax, x, y, w, h, label, fill=fill, edge=accent, title_size=size)


def artifact(ax, x, y, w, h, label, *, size=17):
    fold = 14
    points = [(x,y),(x+w-fold,y),(x+w,y+fold),(x+w,y+h),(x,y+h)]
    ax.add_patch(Polygon(points, closed=True, edgecolor=BORDER,
                         facecolor=GRAY, linewidth=1.8, zorder=2))
    line(ax, [(x+w-fold,y),(x+w-fold,y+fold),(x+w,y+fold)], color=BORDER, lw=1.3)
    text(ax, x+w/2, y+h/2, label, size, NAVY)


def event(ax, x, y, w, h, title, detail=None):
    rect(ax, x, y, w, h, fill=LIGHTTEAL, edge=TEAL, radius=h/2, lw=1.7)
    if detail:
        text(ax, x+w/2, y+h*0.36, title, 16.8, TEAL)
        text(ax, x+w/2, y+h*0.75, detail, 13.3, MUTED)
    else:
        text(ax, x+w/2, y+h/2, title, 16.5, TEAL)


def control_panel(ax, x, y):
    panel(ax, x, y, "1", "控制图：什么条件触发下一步", "实线箭头表示调度；黑色短条表示并行分发 / 汇合。")
    process(ax, x+28, y+232, 110, 70, "方案\n就绪", size=18)
    # A fork activates both checks in the same round.
    ax.plot([x+180,x+180], [y+177.5,y+352.5], color=NAVY, lw=6, zorder=4)
    arrow(ax, [(x+138,y+267),(x+175,y+267)])
    process(ax, x+235, y+145, 150, 65, "结构检查")
    process(ax, x+235, y+320, 150, 65, "规则检查")
    arrow(ax, [(x+184,y+177.5),(x+235,y+177.5)])
    arrow(ax, [(x+184,y+352.5),(x+235,y+352.5)])
    text(ax, x+180, y+127, "并行", 15, MUTED)
    # The all-success join consumes two completed check activations.
    ax.plot([x+437,x+437], [y+177.5,y+352.5], color=NAVY, lw=6, zorder=4)
    arrow(ax, [(x+385,y+177.5),(x+433,y+177.5)])
    arrow(ax, [(x+385,y+352.5),(x+433,y+352.5)])
    text(ax, x+437, y+127, "等两路", 15, MUTED)
    diamond = [(x+535,y+217),(x+589,y+267),(x+535,y+317),(x+481,y+267)]
    ax.add_patch(Polygon(diamond, closed=True, facecolor=LIGHTORANGE,
                         edgecolor=ORANGE, linewidth=1.8, zorder=2))
    text(ax, x+535, y+267, "通过？", 18, ORANGE)
    arrow(ax, [(x+441,y+267),(x+481,y+267)])
    process(ax, x+660, y+145, 128, 65, "已通过", accent=TEAL, fill=LIGHTTEAL)
    process(ax, x+660, y+320, 128, 65, "待修订", accent=ORANGE, fill=LIGHTORANGE)
    arrow(ax, [(x+589,y+267),(x+620,y+267),(x+620,y+177.5),(x+660,y+177.5)], color=TEAL)
    arrow(ax, [(x+589,y+267),(x+620,y+267),(x+620,y+352.5),(x+660,y+352.5)], color=ORANGE)
    text(ax, x+620, y+152, "是", 16, TEAL)
    text(ax, x+620, y+383, "否", 16, ORANGE)
    text(ax, x+410, y+444, "汇合按本轮成员等待；“未通过”仍是一项结果。", 17)
    text(ax, x+410, y+485, "节点异常、取消与超时需要另设错误出口。", 16, MUTED)


def data_panel(ax, x, y):
    panel(ax, x, y, "2", "数据依赖图：哪些产物成为输入", "箭头传递值的依赖；折角纸张是产物，蓝色方框是计算。")
    artifact(ax, x+315, y+120, 190, 59, "方案 v_i", size=19)
    process(ax, x+74, y+224, 175, 62, "结构检查")
    process(ax, x+571, y+224, 175, 62, "规则检查")
    arrow(ax, [(x+355,y+179),(x+355,y+200),(x+161.5,y+200),(x+161.5,y+224)], color=TEAL)
    arrow(ax, [(x+465,y+179),(x+465,y+200),(x+658.5,y+200),(x+658.5,y+224)], color=TEAL)
    text(ax, x+247, y+181, "planRef", 15, TEAL)
    text(ax, x+574, y+181, "planRef", 15, TEAL)
    artifact(ax, x+74, y+332, 175, 55, "shapeResult", size=16.5)
    artifact(ax, x+571, y+332, 175, 55, "rulesResult", size=16.5)
    arrow(ax, [(x+161.5,y+286),(x+161.5,y+332)], color=TEAL)
    arrow(ax, [(x+658.5,y+286),(x+658.5,y+332)], color=TEAL)
    process(ax, x+325, y+405, 170, 65, "判定\n输出 verdict", size=17)
    arrow(ax, [(x+161.5,y+387),(x+161.5,y+437.5),(x+325,y+437.5)], color=TEAL)
    arrow(ax, [(x+658.5,y+387),(x+658.5,y+437.5),(x+495,y+437.5)], color=TEAL)
    text(ax, x+410, y+369, "两类必需输入", 16, MUTED)
    text(ax, x+410, y+504, "只表达本轮输入依赖；pass / revise 是判定的输出。", 16, MUTED)


def state_panel(ax, x, y):
    panel(ax, x, y, "3", "共享状态图：读写状态，边负责触发", "同一方案被两项检查读取；各自写入独立结果字段。")
    process(ax, x+63, y+123, 170, 65, "结构检查")
    process(ax, x+587, y+123, 170, 65, "规则检查")
    # Control dependencies run along the inner sides, separate from state I/O.
    line(ax, [(x+233,y+155.5),(x+285,y+155.5),(x+285,y+222),(x+320,y+222)])
    line(ax, [(x+587,y+155.5),(x+535,y+155.5),(x+535,y+222),(x+500,y+222)])
    ax.plot([x+320,x+500], [y+222,y+222], color=NAVY, lw=6, zorder=4)
    text(ax, x+410, y+183, "两项完成才触发", 16, NAVY)
    process(ax, x+325, y+251, 170, 64, "判定")
    arrow(ax, [(x+410,y+226),(x+410,y+251)])
    # A state store is not an executing step and is not connected by control edges.
    rect(ax, x+74, y+389, 672, 84, fill=GRAY, edge=BORDER, radius=12, lw=1.7)
    text(ax, x+410, y+412, "共享 state", 17.5, NAVY)
    text(ax, x+410, y+447, "planRef   ·   checks.shape   ·   checks.rules   ·   verdict", 15.5, MUTED)
    # Reads point from state to a process; writes point from a process to state.
    arrow(ax, [(x+101,y+389),(x+101,y+188)], color=TEAL, dashed=True)
    arrow(ax, [(x+200,y+188),(x+200,y+389)], color=BLUE)
    text(ax, x+80, y+291, "读\nplan", 14.5, TEAL, ha="right")
    text(ax, x+220, y+291, "写\nshape", 14.5, BLUE, ha="left")
    arrow(ax, [(x+620,y+188),(x+620,y+389)], color=BLUE)
    arrow(ax, [(x+719,y+389),(x+719,y+188)], color=TEAL, dashed=True)
    text(ax, x+600, y+291, "写\nrules", 14.5, BLUE, ha="right")
    text(ax, x+739, y+291, "读\nplan", 14.5, TEAL, ha="left")
    arrow(ax, [(x+377,y+389),(x+377,y+315)], color=TEAL, dashed=True)
    arrow(ax, [(x+443,y+315),(x+443,y+389)], color=BLUE)
    text(ax, x+356, y+351, "读 checks", 14, TEAL, ha="right")
    text(ax, x+464, y+351, "写 verdict", 14, BLUE, ha="left")
    text(ax, x+410, y+504, "虚线青色：读；蓝色：写。并发合并规则必须显式定义。", 15.5, MUTED)


def event_panel(ax, x, y):
    panel(ax, x, y, "4", "事件图：谁生产、谁消费", "胶囊是带类型的事件，方框是处理器；箭头表示事件流。")
    event(ax, x+309, y+119, 202, 53, "PlanReady", "planRef")
    process(ax, x+77, y+219, 175, 60, "结构检查")
    process(ax, x+568, y+219, 175, 60, "规则检查")
    arrow(ax, [(x+350,y+172),(x+350,y+192),(x+164.5,y+192),(x+164.5,y+219)], color=TEAL)
    arrow(ax, [(x+470,y+172),(x+470,y+192),(x+655.5,y+192),(x+655.5,y+219)], color=TEAL)
    text(ax, x+246, y+173, "消费", 14.5, TEAL)
    text(ax, x+574, y+173, "消费", 14.5, TEAL)
    event(ax, x+58, y+324, 213, 53, "ShapeChecked", "shapeResult")
    event(ax, x+549, y+324, 213, 53, "RulesChecked", "rulesResult")
    arrow(ax, [(x+164.5,y+279),(x+164.5,y+324)], color=TEAL)
    arrow(ax, [(x+655.5,y+279),(x+655.5,y+324)], color=TEAL)
    text(ax, x+199, y+303, "生产", 14, TEAL, ha="left")
    text(ax, x+621, y+303, "生产", 14, TEAL, ha="right")
    process(ax, x+300, y+396, 220, 61, "同轮收齐后判定", size=17)
    arrow(ax, [(x+164.5,y+377),(x+164.5,y+426.5),(x+300,y+426.5)], color=TEAL)
    arrow(ax, [(x+655.5,y+377),(x+655.5,y+426.5),(x+520,y+426.5)], color=TEAL)
    event(ax, x+583, y+456, 179, 36, "VerdictReady")
    arrow(ax, [(x+520,y+442),(x+555,y+442),(x+555,y+474),(x+583,y+474)], color=TEAL)
    text(ax, x+410, y+505, "用 (runId, round) 关联；按 eventId 去重，设聚合超时。", 15.5, MUTED)


def main():
    fig = plt.figure(figsize=(18, 14.5), dpi=180, facecolor="white")
    ax = fig.add_axes([0, 0, 1, 1])
    ax.set_xlim(0, 1800)
    ax.set_ylim(1450, 0)
    ax.axis("off")
    text(ax, 55, 60, "同一流程的四种图语义", 30, NAVY, ha="left")
    text(ax, 55, 117, "同一轮“方案双检后判定”：分别突出触发、输入、状态和事件；四种视图可以组合使用。", 19, MUTED, ha="left")
    ax.plot([55,1745], [151,151], color=BORDER, lw=1.2)
    control_panel(ax, 55, 180)
    data_panel(ax, 925, 180)
    state_panel(ax, 55, 755)
    event_panel(ax, 925, 755)
    rect(ax, 55, 1320, 1690, 64, fill=LIGHTTEAL, edge=TEAL, radius=14, lw=1.3)
    text(ax, 900, 1352, "可执行图必须约定：激活条件、数据绑定、汇合规则、状态更新与终止条件。", 22, TEAL)
    text(ax, 55, 1420, "设计归纳示意；图中字段与事件名为示例，并非某一 SDK 的固定 API。", 15, MUTED, ha="left")
    save(fig, "06_graph_models")


if __name__ == "__main__":
    main()
