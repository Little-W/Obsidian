"""Four original qualitative FRAM teaching figures.

Run with Python 3.  Uses only the standard library and diagram_common.py.
No source-paper artwork or measured data are reproduced.
"""

import math

from diagram_common import SVG, C, linspace


def capacitor(g, x, y_top, y_bottom, half_width=40, color="teal"):
    """A two-terminal capacitor: callers draw leads to the plate centers."""
    g.line(x-half_width, y_top, x+half_width, y_top, color, 5)
    g.line(x-half_width, y_bottom, x+half_width, y_bottom, color, 5)


def access_nmos(g, x, y, gate_x, wl_x, color="ink"):
    """Simplified MOS switch, drain (x,y), source (x,y+60), gate isolated.

    x is the external drain/source lead x coordinate; the channel is 45 px left.
    The gate sits another 30 px left and never touches the channel.
    """
    channel_x = x-45
    g.line(channel_x, y, channel_x, y+60, color, 4)
    g.line(channel_x, y, x, y, color, 3)
    g.line(channel_x, y+60, x, y+60, color, 3)
    g.line(gate_x, y, gate_x, y+60, color, 3)
    g.line(wl_x, y+30, gate_x, y+30, color, 3)


def centered_box(g, x, y, w, h, title, body=None, accent="blue"):
    g.rect(x, y, w, h, fill=accent+"_bg", stroke="line", radius=13)
    if body is None:
        g.text(x+w/2, y+h/2+9, title, size=27, weight=700,
               fill=accent, anchor="middle")
    else:
        g.text(x+w/2, y+36, title, size=27, weight=700,
               fill=accent, anchor="middle")
        g.text(x+w/2, y+72, body, size=24, anchor="middle")


def fig01():
    g = SVG(
        "fig01_cell_read_restore.svg",
        "图1  电容型 FRAM：单元连接与读后恢复",
        "1T1C 简化电路及典型读操作；铁电电容的物理翻转与接口逻辑错误分开描述。",
        height=1040,
    )
    g.rect(52, 160, 560, 570, fill="gray_bg", stroke="line", radius=16)
    g.rect(640, 160, 708, 570, fill="white", stroke="line", radius=16)
    g.text(80, 204, "1T1C：一个访问管 + 一个铁电电容", size=27, weight=700)
    g.text(668, 204, "一次外部读包含判决与内部恢复", size=28, weight=700)

    # Exact circuit nodes and connections.  The gate is isolated from the channel.
    g.text(350, 253, "位线 BL", size=27, weight=700, anchor="middle", fill="blue")
    g.line(350, 268, 350, 310, "blue", 3)
    access_nmos(g, 350, 310, 275, 110)
    g.text(112, 311, "字线 WL", size=26, fill="blue")
    g.text(397, 348, "访问管", size=26)
    g.text(397, 378, "栅极与沟道隔离", size=20, fill="muted")
    g.line(350, 370, 350, 480, "ink", 3)
    g.circle(350, 425, 5, "ink")
    g.text(377, 434, "存储节点", size=25)
    capacitor(g, 350, 480, 530)
    g.arrow(350, 490, 350, 520, "teal", 2.5)
    g.text(372, 513, "P", size=25, fill="teal", weight=700)
    g.text(410, 498, "FeCAP", size=26, fill="teal", weight=700)
    g.text(410, 531, "铁电电容", size=25)
    g.line(350, 530, 350, 625, "ink", 3)
    g.line(118, 625, 552, 625, "teal", 4)
    g.circle(350, 625, 6, "teal")
    g.text(120, 661, "板线 PL：提供电容端激励", size=26, fill="teal")
    g.text(80, 703, "圆点表示接点；导线交接关系按图中节点定义。", size=20, fill="muted")

    # Read operation and two separate results.  The fork is outside all boxes.
    centered_box(g, 676, 239, 636, 94, "感测", "相同读脉冲 → 切换 / 非切换电荷", "blue")
    g.arrow(994, 337, 994, 374)
    centered_box(g, 676, 380, 636, 94, "判决", "与参考电平或互补存储支路比较", "purple")
    g.line(994, 478, 994, 496, "muted", 2.5)
    g.line(821, 496, 1167, 496, "muted", 2.5)
    g.arrow(821, 496, 821, 520)
    g.arrow(1167, 496, 1167, 520)
    centered_box(g, 676, 526, 290, 103, "当前读返回值", "先保存首次观测", "blue")
    centered_box(g, 1022, 526, 290, 103, "内部恢复", "按判决回写状态", "teal")
    g.text(994, 676, "返回值正确 ≠ 恢复后状态可靠", size=28, weight=700,
           fill="orange", anchor="middle")
    g.text(994, 710, "后续连读或延迟读可暴露恢复不足。", size=24, anchor="middle")

    g.card(52, 759, 632, 156, "正常翻转与故障分开", "感测时发生极化反转是正常机制。\n哪一极性编码为 0 或 1，由电路定义。",
           accent="blue", size=25)
    g.card(708, 759, 640, 156, "2T2C：互补存储，差分感测", "两个电容共同保存一个逻辑位。\n逻辑全 0 不代表所有电容同一极性。",
           accent="teal", size=25)
    g.footer("依据：报告参考文献 [1]、[2]、[7]；原始绘图。",
             "定性电路示意；未绘出感放、预充电、参考及电源保护，具体时序由宏定义。")
    return g.save()


def loop_points(cx, cy, sx=130, sy=126, shift=0.0, amplitude=1.0):
    e = linspace(-1.05, 1.05, 140)
    ascending = [(cx+sx*(v+shift), cy-sy*amplitude*math.tanh(4.5*(v-0.29))) for v in e]
    descending = [(cx+sx*(v+shift), cy-sy*amplitude*math.tanh(4.5*(v+0.29))) for v in reversed(e)]
    return ascending+descending+[ascending[0]]


def hysteresis_axes(g, cx, cy, xmin_offset=165, xmax_offset=177):
    g.arrow(cx-xmin_offset, cy, cx+xmax_offset, cy, "muted", 1.6)
    g.arrow(cx, cy+155, cx, cy-158, "muted", 1.6)
    g.text(cx+xmax_offset-3, cy+32, "E", size=26, fill="muted", anchor="end")
    g.text(cx+13, cy-150, "P", size=26, fill="muted")
    g.text(cx-13, cy+27, "0", size=21, fill="muted", anchor="end")


def legend(g, x, y, text, color, dash=None):
    g.line(x, y-8, x+54, y-8, color, 3, dash=dash)
    g.text(x+69, y, text, size=23, fill=color)


def fig03_hysteresis():
    g = SVG(
        "fig03_hysteresis_mechanisms.svg",
        "图3  极化回线中的三类变化",
        "P 为铁电极化，E 为电场；形状用于区分现象，不代表某种材料的实测特性。",
        height=970,
    )
    panels = [(52, 416), (492, 416), (932, 416)]
    for x, w in panels:
        g.rect(x, 164, w, 524, fill="white", stroke="line", radius=16)
    titles = ["正常极化回线", "印记：回线横向偏移", "可切换幅度降低"]
    subtitles = ["双向切换与剩余极化", "两方向的切换难度不对称", "疲劳或未充分翻转等原因"]
    centers = [260, 700, 1140]
    for (x, _), title, subtitle, cx in zip(panels, titles, subtitles, centers):
        g.text(x+24, 205, title, size=28, weight=700)
        g.text(x+24, 244, subtitle, size=24, fill="muted")
        hysteresis_axes(g, cx, 439)

    g.polyline(loop_points(260, 439), color="blue", width=4)
    legend(g, 80, 642, "初始响应", "blue")

    g.polyline(loop_points(700, 439), color="line", width=3, dash="8 6")
    g.polyline(loop_points(700, 439, shift=0.245), color="orange", width=4)
    g.line(700, 607, 732, 607, "orange", 2.5, arrow=True)
    g.text(816, 614, "E_bias ≠ 0", size=22, fill="orange", anchor="middle")
    legend(g, 520, 652, "印记后", "orange")
    legend(g, 712, 652, "初始", "muted", dash="8 6")

    g.polyline(loop_points(1140, 439), color="line", width=3, dash="8 6")
    g.polyline(loop_points(1140, 439, amplitude=0.57), color="red", width=4)
    legend(g, 960, 617, "较小的可切换幅度", "red")
    legend(g, 960, 654, "初始响应", "muted", dash="8 6")

    g.rect(52, 713, 1296, 144, fill="gray_bg", stroke="none", radius=14)
    g.text(80, 756, "相似的回线变化可能来自不同原因，需结合脉宽、温度、延迟与循环历史。",
           size=27, weight=700)
    g.text(80, 800, "幅度下降图只表示现象：区分材料退化与脉冲不足，还需要独立的受控实验。",
           size=25)
    g.text(80, 838, "回线拟合描述当前响应；寿命预测另需经过标定的退化模型。",
           size=25, fill="muted")
    g.footer("依据：报告参考文献 [10]、[13]、[20]、[25]—[28]；数学曲线为原始定性绘制。",
             "纯定性示意，非实测曲线；不表示所有疲劳均为幅度缩小，也不表示印记必然不可恢复。")
    return g.save()


def fig04_models():
    g = SVG(
        "fig04_model_layers.svg",
        "图4  物理状态、电路响应与功能故障的连接",
        "读出的返回值与操作后的内部状态分别保存，再由候选测试和实物证据检验模型。",
        height=1100,
    )
    g.rect(52, 164, 1296, 94, fill="gray_bg", stroke="line", radius=14)
    g.text(80, 201, "输入：实际操作波形、温度与历史", size=28, weight=700)
    g.text(80, 238, "读 / 写 / 恢复 · 等待间隔 · 脉宽和电压 · 预循环与累计应力", size=25)
    g.arrow(475, 263, 475, 299)

    g.card(90, 305, 770, 130, "第一层：物理状态与缺陷", "极化畴、陷阱电荷、印记偏置、可切换比例",
           accent="blue", size=26)
    g.arrow(475, 440, 475, 474)
    g.card(90, 480, 770, 130, "第二层：单元和阵列电路", "电容端波形、位线信号、参考、感放与恢复",
           accent="teal", size=26)

    # Branching outputs, all joining segments in the gaps between cards.
    g.line(475, 615, 475, 639, "muted", 2.5)
    g.line(265, 639, 685, 639, "muted", 2.5)
    g.arrow(265, 639, 265, 664)
    g.arrow(685, 639, 685, 664)
    centered_box(g, 90, 670, 350, 75, "本次读返回值 R", accent="blue")
    centered_box(g, 510, 670, 350, 75, "操作后状态 F", accent="teal")
    g.line(265, 750, 265, 775, "muted", 2.5)
    g.line(685, 750, 685, 775, "muted", 2.5)
    g.line(265, 775, 685, 775, "muted", 2.5)
    g.arrow(475, 775, 475, 799)
    g.card(90, 805, 770, 130, "第三层：功能故障原语 〈S / F / R〉",
           "操作历史 S、最终状态 F 与返回值 R 分别定义",
           accent="purple", size=26)

    g.card(940, 305, 380, 185, "标定数据", "器件电测与电路波形\n参考偏移与读裕量\n已知条件与初始状态",
           accent="orange", size=25)
    g.arrow(935, 372, 866, 372, "orange", 2.5)
    g.text(900, 347, "提取参数", size=19, fill="orange", anchor="middle")

    g.card(940, 715, 380, 220, "候选测试与验证", "故障仿真 + 实物复测\n比较首次异常与状态\n保留未解释的样本\n用独立数据检验模型",
           accent="purple", size=25)
    g.arrow(866, 870, 934, 870, "purple", 2.5)
    # Calibration feedback stays above the cards and along the outer margin.
    g.path("M 1325 825 L 1341 825 L 1341 290 L 700 290 L 700 299",
           color="purple", width=2.5, dash="8 5", arrow=True)
    g.text(1095, 282, "反馈：修正参数与遗漏机理", size=20,
           fill="purple", anchor="middle")

    g.text(90, 986, "模型能复现回线，不等于已经证明全部故障覆盖；每层都需要相应证据。",
           size=26, weight=700)
    g.footer("依据：报告参考文献 [19]—[31]；分层结构为本文综合设计。",
             "定性模型流程；箭头表示数据或校准关系，不代表某一工具的固定实现。")
    return g.save()


def ground(g, x, y, color="muted"):
    g.line(x, y-18, x, y, color, 2.3)
    g.line(x-18, y, x+18, y, color, 2.3)
    g.line(x-12, y+7, x+12, y+7, color, 2.3)
    g.line(x-6, y+14, x+6, y+14, color, 2.3)


def fig09():
    g = SVG(
        "fig09_half_select.svg",
        "图9  共享板线与半选单元的等效连接",
        "以单电容支路说明电压来源：未被数字选中的单元，也可能承受板线耦合与累积应力。",
        height=1100,
    )
    g.rect(52, 164, 1296, 531, fill="white", stroke="line", radius=16)
    g.rect(76, 218, 578, 384, fill="blue_bg", stroke="none", radius=14)
    g.rect(746, 218, 578, 384, fill="orange_bg", stroke="none", radius=14)
    g.text(80, 205, "选中支路：主动控制端电压", size=28, fill="blue", weight=700)
    g.text(750, 205, "半选支路：节点电位可能浮置", size=28, fill="orange", weight=700)

    # Selected branch.
    g.text(350, 261, "BL：受驱动", size=26, fill="blue", weight=700, anchor="middle")
    g.line(350, 277, 350, 335, "blue", 3)
    access_nmos(g, 350, 335, 275, 110)
    g.text(112, 335, "WL = 1", size=27, fill="blue")
    g.line(350, 395, 350, 490, "ink", 3)
    g.circle(350, 432, 5, "ink")
    g.text(378, 440, "V_SN ≈ V_BL", size=25)
    capacitor(g, 350, 490, 522, color="teal")
    g.text(424, 500, "−", size=25, fill="teal")
    g.text(424, 532, "+", size=25, fill="teal")
    g.text(457, 519, "V_FE", size=24, fill="teal")
    g.line(350, 522, 350, 632, "ink", 3)
    g.text(98, 565, "驱动、访问管与时序\n共同决定电容端电压。", size=23)

    # Half-selected branch; capacitor-side node is not the external BL.
    g.text(1025, 261, "BL：浮置或弱约束", size=26, fill="orange", weight=700, anchor="middle")
    g.circle(1025, 278, 5, fill="white", stroke="orange", width=2.5)
    g.line(1025, 284, 1025, 335, "orange", 3)
    access_nmos(g, 1025, 335, 950, 790)
    g.text(792, 335, "WL = 0", size=27, fill="orange")
    g.line(1025, 395, 1025, 490, "ink", 3)
    g.circle(1025, 432, 5, "ink")
    g.text(795, 441, "V_SN：可能浮置", size=25)
    capacitor(g, 1025, 490, 522, color="teal")
    g.text(950, 500, "−", size=25, fill="teal", anchor="middle")
    g.text(950, 532, "+", size=25, fill="teal", anchor="middle")
    g.text(875, 519, "V_FE", size=24, fill="teal", anchor="middle")
    g.line(1025, 522, 1025, 632, "ink", 3)
    # Equivalent parasitic charge-sharing branch from the floating storage node.
    g.line(1025, 432, 1175, 432, "muted", 2.3)
    g.line(1175, 432, 1175, 472, "muted", 2.3)
    capacitor(g, 1175, 472, 490, half_width=24, color="muted")
    g.line(1175, 490, 1175, 524, "muted", 2.3)
    ground(g, 1175, 542)
    g.text(1211, 488, "寄生", size=23, fill="muted")
    g.text(1211, 518, "电容", size=23, fill="muted")
    g.text(774, 565, "节点受板线耦合影响，\n实际电场随之变化。", size=23)

    # Shared PL below the isolated branches, with explicit junction dots.
    g.line(110, 632, 1263, 632, "teal", 4)
    g.circle(350, 632, 6, "teal")
    g.circle(1025, 632, 6, "teal")
    g.text(700, 671, "共享板线 PL：重复脉冲作用于两条支路", size=28,
           fill="teal", weight=700, anchor="middle")

    g.rect(52, 718, 1296, 165, fill="gray_bg", stroke="none", radius=14)
    g.text(80, 760, "先确定电容两端的真实电位", size=28, weight=700)
    g.text(80, 807, "V_FE = V_PL − V_SN", size=31, fill="blue", weight=700)
    g.text(700, 807, "选通且压降小时：V_FE ≈ V_PL − V_BL", size=26)
    g.text(80, 853, "半选关断时不能直接用外部 BL 代替 V_SN；电荷共享、漏电与寄生需要进入模型。",
           size=25)

    g.rect(52, 905, 1296, 100, fill="purple_bg", stroke="none", radius=14)
    g.text(80, 946, "2T2C 提示：逻辑 0 由两条支路的互补极性编码，不是所有电容同一极性。",
           size=27, weight=700, fill="purple")
    g.text(80, 982, "本图省略完整差分支路与外围电路，不复原某篇论文的阵列连接或版图。", size=24)
    g.footer("依据：报告参考文献 [2]、[7]、[17]；连接与节点分析为原始定性示意。",
             "V_SN 表示电容侧存储节点；实际半选偏置、寄生与物理作用范围须由目标宏确认。")
    return g.save()


def main():
    for build in (fig01, fig03_hysteresis, fig04_models, fig09):
        print(build())


if __name__ == "__main__":
    main()
