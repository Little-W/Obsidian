#!/usr/bin/env python3
"""Generate editable Chinese diagrams 05, 10, 11 and 12 for the agent framework report.

Dependencies: matplotlib. A CJK TrueType font is required; PyMuPDF can supply
its bundled fallback when the report font is absent. SVG text stays as text.
Run this file from any working directory. Outputs are placed in ../figures/.
"""
from pathlib import Path
import os
import tempfile

os.environ.setdefault("MPLCONFIGDIR", str(Path(tempfile.gettempdir()) / "agent_report_mpl_cache"))
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib import font_manager
from matplotlib.patches import FancyBboxPatch, FancyArrowPatch, Circle
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
matplotlib.rcParams.update({
    "font.family": FONT.get_name(),
    "svg.fonttype": "none",
    "axes.unicode_minus": False,
    "savefig.facecolor": "white",
})

INK = "#183047"
BLUE = "#2864B4"
TEAL = "#11847B"
LIGHT = "#F3F6FA"
ORANGE = "#C97722"
MUTED = "#516579"
LINE = "#A6B7C8"
PALE_BLUE = "#EFF5FD"
PALE_TEAL = "#EDF8F5"
PALE_ORANGE = "#FFF5E9"


def canvas(w, h, title, subtitle):
    fig, ax = plt.subplots(figsize=(w / 100, h / 100), dpi=100)
    fig.subplots_adjust(0, 0, 1, 1)
    ax.set_xlim(0, w)
    ax.set_ylim(h, 0)
    ax.set_aspect("equal")
    ax.axis("off")
    ax.plot([60, 60], [42, 92], color=TEAL, lw=5, solid_capstyle="round")
    txt(ax, 85, 65, title, size=27, ha="left")
    txt(ax, 85, 118, subtitle, size=17, color=MUTED, ha="left")
    return fig, ax


def txt(ax, x, y, text, size=18, color=INK, ha="center", va="center", weight="normal", linespacing=1.45):
    return ax.text(x, y, text, fontproperties=FONT, fontsize=size, color=color,
                   ha=ha, va=va, weight=weight, linespacing=linespacing, zorder=5)


def box(ax, x, y, w, h, title, sub=None, face=LIGHT, edge=LINE, size=19, subsize=16,
        titlecolor=INK, radius=14, lw=1.8):
    ax.add_patch(FancyBboxPatch((x, y), w, h,
                              boxstyle=f"round,pad=0,rounding_size={radius}",
                              linewidth=lw, edgecolor=edge, facecolor=face, zorder=3))
    if sub is None:
        txt(ax, x + w / 2, y + h / 2, title, size=size, color=titlecolor)
    else:
        txt(ax, x + w / 2, y + h * 0.36, title, size=size, color=titlecolor)
        txt(ax, x + w / 2, y + h * 0.72, sub, size=subsize, color=MUTED)
    return (x, y, w, h)


def line(ax, points, color=BLUE, lw=2.4, dash=False, arrow=True):
    if arrow:
        codes = [MplPath.MOVETO] + [MplPath.LINETO] * (len(points) - 1)
        p = FancyArrowPatch(path=MplPath(points, codes), arrowstyle="<->" if arrow == "both" else "-|>",
                            mutation_scale=17, linewidth=lw,
                            linestyle="--" if dash else "-", color=color,
                            zorder=4, capstyle="round", joinstyle="round")
        ax.add_patch(p)
    else:
        xs, ys = zip(*points)
        ax.plot(xs, ys, color=color, lw=lw, ls="--" if dash else "-", zorder=4)


def save(fig, name):
    png_tmp = OUT / (f".{name}.{os.getpid()}.png")
    svg_tmp = OUT / (f".{name}.{os.getpid()}.svg")
    fig.savefig(png_tmp, dpi=100, format="png")
    fig.savefig(svg_tmp, format="svg")
    plt.close(fig)
    os.replace(png_tmp, OUT / (name + ".png"))
    os.replace(svg_tmp, OUT / (name + ".svg"))


def diagram05():
    fig, ax = canvas(2000, 1450, "05  外部作业在崩溃后的恢复方式",
                     "以持久化的尝试键定位同一次提交；已确认失败后的重跑创建新尝试。")
    txt(ax, 65, 175, "正常路径", size=18, color=BLUE, ha="left")
    xs = [65, 445, 825, 1205, 1585]
    labels = ["先持久化\n本次尝试键 key", "作业网关\nget_or_submit(key)",
              "获得并保存\njob_id", "查询作业状态\n等待完成", "保存执行结果\n继续后续阶段"]
    for i, (x, lab) in enumerate(zip(xs, labels)):
        box(ax, x, 215, 330, 125, lab, face=PALE_BLUE, edge=BLUE, size=19)
        if i:
            line(ax, [(xs[i-1] + 330, 277.5), (x, 277.5)])
    box(ax, 535, 400, 930, 112,
        "提交已成功，但返回 job_id 或写入检查点前崩溃",
        "外部作业可能仍在运行", face=PALE_ORANGE, edge=ORANGE, size=19, subsize=16)
    line(ax, [(610, 340), (610, 370), (1000, 370), (1000, 400)], color=ORANGE, dash=True)

    box(ax, 650, 582, 700, 125, "恢复时读取同一 key", "向作业网关查询持久作业登记",
        face=PALE_TEAL, edge=TEAL, size=20, subsize=18)
    line(ax, [(1000, 512), (1000, 582)], color=ORANGE)

    centers = [335, 1000, 1665]
    line(ax, [(1000, 707), (1000, 760)], color=TEAL, arrow=False)
    line(ax, [(335, 760), (1665, 760)], color=TEAL, arrow=False)
    for c in centers:
        line(ax, [(c, 760), (c, 850)], color=TEAL)
    # Edge labels sit beside, rather than on, their vertical branch.
    txt(ax, 378, 802, "已有对应作业", size=17, ha="left", color=TEAL)
    txt(ax, 1043, 802, "无作业且明确未执行", size=17, ha="left", color=TEAL)
    txt(ax, 1708, 802, "状态不明", size=17, ha="left", color=ORANGE)
    box(ax, 85, 850, 500, 145, "复用已有 job_id", "继续监控并收集结果", face=PALE_TEAL, edge=TEAL, size=20, subsize=18)
    box(ax, 750, 850, 500, 145, "以同一 key 提交", "网关执行去重检查", face=PALE_BLUE, edge=BLUE, size=20, subsize=18)
    box(ax, 1415, 850, 500, 145, "暂停自动提交", "核对登记与外部作业", face=PALE_ORANGE, edge=ORANGE, size=20, subsize=18)

    box(ax, 85, 1080, 1830, 255, "", face=LIGHT, edge=LINE)
    txt(ax, 120, 1120, "实现前提", size=19, ha="left", color=BLUE)
    txt(ax, 120, 1170, "• 同一次尝试的 key 跨恢复不变；登记 key 与 job_id 的对应关系。", size=18, ha="left")
    txt(ax, 120, 1225, "• 仅在旧作业已终止且允许重试时创建新 attempt；状态未知先核对。", size=18, ha="left")
    txt(ax, 120, 1280, "• 外部执行的去重能力需要由作业网关与执行端共同落实。", size=18, ha="left")
    txt(ax, 1000, 1395, "检查点恢复 ≠ 外部副作用恰好执行一次；状态不明时不能盲目重试。", size=18, color=ORANGE)
    save(fig, "05_recovery")


def diagram11():
    fig, ax = canvas(1800, 1180, "11  DFT Agent 的建议分层",
                     "界面、流程定义、编排运行时与工具执行分别负责不同职责。")
    x, w, h = 80, 1050, 125
    ys = [180, 350, 520, 690, 860]
    layers = [
        ("界面：Qt 或 Web", "项目 · 流程 · 团队 · 聊天 · 运行轨迹", PALE_BLUE, BLUE),
        ("版本化 Flow 定义与静态检查", "输入输出约束 · 分支条件 · 循环上限 · 工具权限", LIGHT, LINE),
        ("TypeScript 编排运行时", "调度节点 · 派发团队 · 合并结果 · 暂停与恢复", PALE_TEAL, TEAL),
        ("TypeScript 工具适配与作业网关", "参数校验 · 去重 · job_id · 取消 · 资源配额", LIGHT, LINE),
        ("EDA 进程与 C++ 算法工具", "执行任务，产生日志、报告和工程制品", PALE_BLUE, BLUE),
    ]
    for i, (title, sub, face, edge) in enumerate(layers):
        box(ax, x, ys[i], w, h, title, sub, face=face, edge=edge, size=21, subsize=18)
        if i:
            line(ax, [(x+w/2, ys[i-1]+h), (x+w/2, ys[i])])

    box(ax, 1250, 332, 465, 540, "", face=LIGHT, edge=LINE)
    txt(ax, 1482.5, 378, "持久化支撑服务", size=21, color=BLUE)
    box(ax, 1280, 428, 405, 95, "状态与检查点", face="white", edge=LINE, size=19)
    box(ax, 1280, 558, 405, 95, "事件与运行记录", face="white", edge=LINE, size=19)
    box(ax, 1280, 688, 405, 95, "版本化制品与日志", face="white", edge=LINE, size=19)
    txt(ax, 1482.5, 829, "大文件通过引用传递", size=17, color=MUTED)
    line(ax, [(1130, 580), (1250, 580)], color=TEAL, arrow="both")
    txt(ax, 1190, 540, "读写", size=16, color=TEAL)
    txt(ax, 900, 1070, "界面展示执行状态，后端运行时负责调度；可部署为本地服务或远程服务。", size=18, color=MUTED)
    txt(ax, 900, 1120, "这是面向当前工程约束的建议架构，具体持久化与调度实现可按规模选择。", size=16, color=MUTED)
    save(fig, "11_dft_architecture")


def diagram12():
    fig, ax = canvas(2000, 1500, "12  EDA 作业的流程组织与团队诊断",
                     "主流程以工具结果验收；可并行的专家只读分析同一版本的证据，修复集中提交。")
    x, w, h = 90, 600, 120
    ys = [180, 340, 500, 660, 820]
    main = [
        ("输入与环境检查", "确认工程、工具与执行条件"),
        ("生成并校验 Tcl", "检查语法、参数和引用文件"),
        ("提交 EDA 作业", "记录操作键与 job_id"),
        ("解析运行报告", "提取退出状态、错误和指标"),
        ("程序验收", "检查输出存在、状态与质量条件"),
    ]
    for i, (title, sub) in enumerate(main):
        box(ax, x, ys[i], w, h, title, sub, face=PALE_BLUE if i != 4 else PALE_TEAL,
            edge=BLUE if i != 4 else TEAL, size=21, subsize=17)
        if i:
            line(ax, [(390, ys[i-1]+h), (390, ys[i])])
    box(ax, 90, 1030, 600, 125, "达标后交付", "报告与版本化工程制品", face=PALE_TEAL, edge=TEAL, size=21, subsize=18)
    line(ax, [(390, 940), (390, 1030)], color=TEAL)
    txt(ax, 435, 984, "通过", size=17, color=TEAL, ha="left")

    # Read-only diagnostic team; parallel fan-out and merge are explicit.
    box(ax, 970, 350, 920, 550, "", face=LIGHT, edge=LINE)
    txt(ax, 1430, 397, "失败后的团队诊断", size=21, color=BLUE)
    txt(ax, 1430, 439, "读取同一版本的证据；独立分析，可并行", size=16, color=MUTED)
    line(ax, [(690, 880), (850, 880), (850, 397), (970, 397)], color=ORANGE)
    txt(ax, 747, 844, "未达标", size=17, color=ORANGE)

    cx = [1145, 1430, 1715]
    line(ax, [(1430, 464), (1430, 478)], color=BLUE, arrow=False)
    line(ax, [(1145, 478), (1715, 478)], color=BLUE, arrow=False)
    labs = [("日志审阅", "首个有效错误"), ("约束审阅", "输入与运行条件"), ("覆盖率分析", "未达标的项目")]
    for c, (title, sub) in zip(cx, labs):
        line(ax, [(c, 478), (c, 510)], color=BLUE)
        box(ax, c-125, 510, 250, 130, title, sub, face="white", edge=BLUE, size=19, subsize=16)
        line(ax, [(c, 640), (c, 687)], color=BLUE, arrow=False)
    line(ax, [(1145, 687), (1715, 687)], color=BLUE, arrow=False)
    line(ax, [(1430, 687), (1430, 735)], color=BLUE)
    box(ax, 1130, 735, 600, 125, "汇总一份修复提案", "明确修改对象、依据与预期结果", face=PALE_BLUE, edge=BLUE, size=21, subsize=17)

    line(ax, [(1430, 860), (1430, 960)], color=BLUE)
    box(ax, 1130, 960, 600, 120, "预算检查", "次数与时长是否仍允许继续", face=PALE_ORANGE, edge=ORANGE, size=21, subsize=18)

    line(ax, [(1430, 1080), (1430, 1120), (1265, 1120), (1265, 1170)], color=TEAL)
    txt(ax, 1390, 1147, "允许修复", size=16, color=TEAL)
    box(ax, 1000, 1170, 530, 130, "隔离工作区应用提案", "重跑受影响阶段并重新验收", face=PALE_TEAL, edge=TEAL, size=20, subsize=17)

    line(ax, [(1730, 1020), (1765, 1020), (1765, 1170)], color=ORANGE)
    txt(ax, 1845, 1108, "预算耗尽", size=16, color=ORANGE)
    box(ax, 1590, 1170, 350, 130, "输出阻塞证据", "失败原因与已尝试动作", face=PALE_ORANGE, edge=ORANGE, size=20, subsize=16)

    # The repair return is routed outside the main column, avoiding all branches.
    line(ax, [(1265, 1300), (1265, 1360), (40, 1360), (40, 400), (90, 400)], color=TEAL)
    txt(ax, 682, 1395, "只重跑受影响阶段；保留输入版本与新制品版本", size=17, color=TEAL)
    txt(ax, 1000, 1450, "这是 Agent 对 EDA 作业的组织方式，不代表某款商业工具的固定执行顺序。", size=17, color=MUTED)
    save(fig, "12_dft_flow")


def diagram10():
    fig, ax = canvas(1800, 1250, "10  工作流、团队与可靠执行的设计趋势",
                     "按官方公开材料整理；截至 2026 年 11 月 1 日。")
    rows = [
        ("2024.12", "Anthropic：归纳工作流与 Agent 的组合模式", "明确预定义控制路径、动态决策、并行分工与迭代验证。", BLUE),
        ("2025.10", "Microsoft：整合 AutoGen 与 Semantic Kernel", "统一团队协作、工作流编排和工程能力。", TEAL),
        ("2026.04", "MAF 1.0 与 Claude Managed Agents：强化可靠执行", "图工作流稳定化；会话日志、运行循环与执行环境分离。", BLUE),
        ("2026.07", "Crew Studio：把智能体团队嵌入 Flow 步骤", "单 Agent、团队和条件路由共同组成应用流程。", TEAL),
        ("2026.08", "ADK TypeScript 2.0：引入图工作流运行时", "Agent、工具与函数成为图节点，支持更明确的执行控制。", BLUE),
        ("2026.10", "AAIF：扩展技能、模型接口与执行环境项目", "共同基础设施继续发展；跨产品协作接口受到重视。", TEAL),
    ]
    y0, gap, card_h = 180, 165, 130
    mids = [y0 + i*gap + card_h/2 for i in range(len(rows))]
    line(ax, [(280, mids[0]), (280, mids[-1])], color=LINE, lw=3, arrow=False)
    for i, (date, title, sub, color) in enumerate(rows):
        y = y0 + i*gap
        ax.add_patch(Circle((280, y+card_h/2), 10, facecolor=color, edgecolor="white", lw=2, zorder=4))
        txt(ax, 235, y+card_h/2, date, size=19, ha="right", color=color)
        line(ax, [(290, y+card_h/2), (355, y+card_h/2)], color=LINE, arrow=False)
        box(ax, 355, y, 1335, card_h, title, sub,
            face=PALE_BLUE if i%2 == 0 else PALE_TEAL, edge=color, size=20, subsize=17)
    txt(ax, 900, 1200, "官方发布说明设计投入方向；不等于市场占有率或性能优势。", size=18, color=ORANGE)
    save(fig, "10_trends")


if __name__ == "__main__":
    diagram05()
    diagram10()
    diagram11()
    diagram12()
    for name in ["05_recovery", "10_trends", "11_dft_architecture", "12_dft_flow"]:
        print(OUT / (name + ".png"))
