"""Draw four original teaching figures for the FRAM research report.

These are qualitative diagrams, not measured data or copied publication figures.
Requires only Python 3 and the sibling diagram_common.py module.
"""

from diagram_common import SVG, C


def state_card(g, x, y, w, h, title, output, state, accent="blue",
               output_color="ink", state_color="ink"):
    g.rect(x, y, w, h, fill=accent + "_bg", stroke=accent, radius=12)
    g.text(x + 20, y + 40, title, size=28, fill=accent, weight=700)
    g.text(x + 20, y + 86, output, size=26, fill=output_color)
    g.text(x + 20, y + 128, state, size=26, fill=state_color)


def draw_march_restore_escape():
    g = SVG(
        "fig05_march_restore_escape.svg",
        "图5　March C− 中被后续写入掩盖的恢复故障",
        "教学模型：显式写入正常；读1返回正确值1，却使内部持久状态变为0。",
        height=1000,
    )

    g.rect(54, 158, 1292, 315, fill="gray_bg", stroke="line")
    g.text(80, 204, "A　March C− 的局部序列：r1 → w0", size=29, weight=700)
    card_y, card_h, card_w = 232, 170, 260
    positions = (80, 400, 720, 1040)
    state_card(g, positions[0], card_y, card_w, card_h,
               "初态", "已成功写入1", "持久状态：1")
    state_card(g, positions[1], card_y, card_w, card_h,
               "r1：读并比较", "返回1：比较通过", "持久状态：0",
               accent="red", output_color="teal", state_color="red")
    state_card(g, positions[2], card_y, card_w, card_h,
               "w0：合法写入", "写入目标值0", "持久状态：0")
    state_card(g, positions[3], card_y, card_w, card_h,
               "后续 r0", "返回0：比较通过", "持久状态：0",
               accent="teal", output_color="teal")
    for x in positions[:-1]:
        g.arrow(x + card_w + 10, 317, x + 320 - 10, 317)
    g.text(80, 445, "读后的隐藏状态错误，被下一次合法写0覆盖；该模型可通过完整 March C−。",
           size=26, fill="muted")

    g.rect(54, 495, 1292, 315, fill="gray_bg", stroke="line")
    g.text(80, 541, "B　连续观察读：w1 → r1 → r1", size=29, weight=700)
    xs = (80, 520, 960)
    state_card(g, xs[0], 568, 340, 168,
               "w1：初始化", "写入目标值1", "持久状态：1")
    state_card(g, xs[1], 568, 340, 168,
               "第一次 r1", "返回1：比较通过", "持久状态：0",
               accent="orange", output_color="teal", state_color="red")
    state_card(g, xs[2], 568, 340, 168,
               "第二次 r1", "返回0：与期望1不符", "检出隐藏状态变化",
               accent="red", output_color="red", state_color="red")
    for x in xs[:-1]:
        g.arrow(x + 350, 652, x + 430, 652)
    g.text(80, 782, "中间不插入显式写入，第二次读即可观察第一次读留下的错误。", size=26)

    g.rect(54, 834, 1292, 73, fill="blue_bg", stroke="none")
    g.text(80, 878, "适用范围：本例只证明特定恢复故障的可观察性，不代表连续读覆盖全部 FRAM 故障。",
           size=25)
    g.footer("来源：[19] 读故障原语与 March 定义；局部反例为本文构造。",
             "教学状态模型；不是硅实测数据，也不是完整故障覆盖证明。")
    return g.save()


def draw_pund():
    g = SVG(
        "fig06_pund.svg",
        "图6　PUND 脉冲与切换电荷提取",
        "先将极化预置为负态；P／U 与 N／D 分别采用匹配的同极性脉冲。",
        height=1060,
    )
    g.rect(54, 158, 1292, 454, fill="gray_bg", stroke="line")
    g.text(80, 203, "施加电压示意", size=28, weight=700)

    baseline, amp = 385, 95
    # The curve is a schematic input voltage, not a measured current trace.
    g.line(108, baseline, 1304, baseline, color="line", width=1.8, dash="7 6")
    g.arrow(108, 499, 108, 265)
    g.text(91, baseline - amp + 9, "+V", size=22, anchor="end", fill="muted")
    g.text(91, baseline + 9, "0", size=22, anchor="end", fill="muted")
    g.text(91, baseline + amp + 9, "−V", size=22, anchor="end", fill="muted")

    pulses = [
        (138, 298, -1, "负向预置", "建立负态", "初态控制", "purple"),
        (378, 538, 1, "P", "负 → 正", "切换响应", "blue"),
        (618, 778, 1, "U", "正 → 正", "非切换响应", "teal"),
        (858, 1018, -1, "N", "正 → 负", "切换响应", "blue"),
        (1098, 1258, -1, "D", "负 → 负", "非切换响应", "teal"),
    ]
    previous = 108
    for start, end, sign, name, transition, role, color in pulses:
        mid = (start + end) / 2
        level = baseline - sign * amp
        g.line(previous, baseline, start, baseline, color="ink", width=3)
        g.polyline([(start, baseline), (start, level),
                    (end, level), (end, baseline)], color=color, width=4)
        g.text(mid, 248, name, size=29 if len(name) < 2 else 27,
               anchor="middle", weight=700, fill=color)
        g.text(mid, 540, transition, size=26, anchor="middle")
        g.text(mid, 582, role, size=24, anchor="middle", fill=color)
        previous = end
    g.line(previous, baseline, 1304, baseline, color="ink", width=3, arrow=True)
    g.text(1304, 432, "时间", size=24, anchor="end", fill="muted")

    g.rect(54, 636, 628, 193, fill="blue_bg", stroke="line")
    g.text(80, 680, "正向差分：P − U", size=29, weight=700, fill="blue")
    g.text(80, 733, "Qsw,+ ≈ ∫ [IP(t) − IU(t)] dt", size=29)
    g.text(80, 785, "同极性配对，扣除可比的非切换分量。", size=25)

    g.rect(710, 636, 636, 193, fill="teal_bg", stroke="line")
    g.text(736, 680, "负向差分：N − D", size=29, weight=700, fill="teal")
    g.text(736, 733, "Qsw,− ≈ ∫ [IN(t) − ID(t)] dt", size=29)
    g.text(736, 785, "电流与电荷采用一致的方向和符号约定。", size=25)

    g.rect(54, 852, 1292, 111, fill="orange_bg", stroke="none")
    g.text(80, 893, "配对条件：幅值、脉宽、间隔和初态可比；陷阱、漏电与回切会影响理想抵消。",
           size=25)
    g.text(80, 935, "本图只画输入电压，不绘制假定的实测电流；切换电荷仍须由仪器测量和校准。",
           size=25, fill="muted")
    g.footer("来源：[11][12] PUND、瞬态测量及非理想影响；波形为本文原创定性示意。",
             "理想脉冲与极化方向示意；间隔、幅度及切换过程不代表器件规格。")
    return g.save()


def retention_lane(g, y, label, wait):
    g.text(80, y + 35, label, size=29, weight=700, fill="blue")
    g.text(80, y + 78, "独立恢复组", size=25, fill="muted")
    g.rect(295, y, 210, 106, fill="blue_bg", stroke="blue")
    g.text(400, y + 37, "最后写／恢复", size=26, anchor="middle", weight=700)
    g.text(400, y + 81, "独立起算 t = 0", size=24, anchor="middle")
    g.arrow(527, y + 54, 1007, y + 54)
    g.text(767, y + 20, "无访问等待 " + wait, size=27, anchor="middle")
    g.rect(1030, y, 270, 106, fill="teal_bg", stroke="teal")
    g.text(1165, y + 38, "目标时刻 " + wait, size=27, anchor="middle", weight=700)
    g.text(1165, y + 80, "捕获首次感测结果", size=25, anchor="middle")


def draw_retention_first_read():
    g = SVG(
        "fig07_retention_first_read.svg",
        "图7　保持测试的首次读应按物理恢复组定义",
        "图中假设：读一个字节会恢复整行；读其余字节需再次激活，且不保留整行首读快照。",
        height=1100,
    )
    g.rect(54, 158, 1292, 400, fill="gray_bg", stroke="line")
    g.text(80, 202, "不同等待点使用独立组，首读前不访问同一恢复组中的其他地址。",
           size=28, weight=700)
    retention_lane(g, 238, "组 A", "t₁")
    retention_lane(g, 386, "组 B", "t₂")
    g.text(80, 534, "t₂ > t₁；两组预循环、背景、温度和其他历史匹配，时间轴长度仅作示意。",
           size=25, fill="muted")

    g.rect(54, 581, 1292, 329, fill="gray_bg", stroke="line")
    g.text(80, 625, "首读字节 a，可同时改写同一恢复组内其余字节的物理状态", size=28, weight=700)
    # Four word/byte addresses represent one physical restore group.
    for i, address in enumerate("abcd"):
        x = 80 + i * 190
        color = "teal" if i == 0 else "orange"
        g.rect(x, 652, 175, 107, fill=color + "_bg", stroke=color)
        g.text(x + 87.5, 694, "字节 " + address, size=28, anchor="middle", weight=700)
        g.text(x + 87.5, 736, "首读观测" if i == 0 else "已被恢复",
               size=25, anchor="middle", fill=color)
    g.arrow(839, 706, 896, 706)
    g.rect(914, 651, 386, 181, fill="red_bg", stroke="red")
    g.text(938, 692, "下一次激活并读 b", size=28, weight=700, fill="red")
    g.text(938, 742, "反映恢复后的状态", size=27)
    g.text(938, 787, "原始等待历史已被改变", size=26)
    g.text(80, 811, "a—d 属于同一物理恢复组。", size=27)
    g.text(80, 861, "软件第一次读取 b，不等于 b 的物理状态从未被访问干预。", size=26)

    g.rect(54, 932, 1292, 69, fill="blue_bg", stroke="none")
    g.text(80, 976, "例外：首激活若已锁存整行原始感测数据，后续仅输出该快照，可保留各字节首读结果。",
           size=25)
    g.footer("来源：[4] 共享行的读／恢复范围；独立分组与首读观测为本文工程设计。",
             "仅示意所标假设下的恢复组；具体激活范围与行快照行为须按目标宏核实。")
    return g.save()


def complete_read(g, x, y, title):
    g.text(x + 170, y - 24, title, size=28, anchor="middle", weight=700)
    g.rect(x, y, 340, 127, fill="blue_bg", stroke="blue")
    g.line(x + 170, y + 18, x + 170, y + 109, color="line", width=2)
    g.text(x + 85, y + 48, "感测", size=29, anchor="middle", weight=700, fill="blue")
    g.text(x + 255, y + 48, "恢复", size=29, anchor="middle", weight=700, fill="blue")
    g.text(x + 85, y + 94, "取得输出", size=25, anchor="middle")
    g.text(x + 255, y + 94, "回写状态", size=25, anchor="middle")


def draw_rad_timing():
    g = SVG(
        "fig08_rad_timing.svg",
        "图8　RAD 的空闲间隔位于完整读操作之间",
        "一次完整读包括感测和内部恢复；终点裕量在规定间隔后的首次读中捕获。",
        height=1100,
    )
    g.rect(54, 158, 1292, 323, fill="gray_bg", stroke="line")
    g.text(80, 201, "应力阶段：完整读结束后，再开始计时空闲间隔", size=29, weight=700)
    complete_read(g, 100, 262, "第 j 次完整读")
    complete_read(g, 940, 262, "第 j + 1 次完整读")
    g.arrow(461, 325, 919, 325)
    g.text(690, 289, "空闲 gapⱼ", size=30, anchor="middle", weight=700, fill="orange")
    g.text(690, 370, "从前次恢复完成开始", size=25, anchor="middle", fill="muted")
    g.text(80, 446, "感测与恢复之间遵守宏规定的内部时序，RAD 扫描不在两者之间插入外部等待。",
           size=25)

    g.rect(54, 505, 1292, 343, fill="gray_bg", stroke="line")
    g.text(80, 550, "终点测量：规定 gap 后的首次读，同时捕获目标裕量", size=29, weight=700)

    g.rect(80, 595, 302, 157, fill="blue_bg", stroke="blue")
    g.text(231, 638, "最后一次应力读", size=28, anchor="middle", weight=700)
    g.text(231, 687, "感测 + 恢复", size=28, anchor="middle")
    g.text(231, 727, "完整结束", size=25, anchor="middle", fill="teal")
    g.arrow(404, 670, 875, 670)
    g.text(639, 625, "终点等待 gap_end", size=28, anchor="middle", fill="orange", weight=700)
    g.text(639, 716, "保持规定温度、电压与背景", size=24, anchor="middle", fill="muted")

    g.rect(900, 588, 400, 181, fill="teal_bg", stroke="teal")
    g.text(926, 630, "终点首次读", size=29, weight=700, fill="teal")
    g.text(926, 679, "在感测时捕获裕量", size=28)
    g.text(926, 726, "随后按规定完成恢复", size=26)
    g.text(80, 814, "若先恢复再立即测量，得到的将是恢复后的近零间隔状态。", size=26, fill="muted")

    g.rect(54, 873, 1292, 119, fill="orange_bg", stroke="none")
    g.text(80, 916, "参考扫描的每一点都需匹配历史：使用独立样本，或重建规定应力与等待。", size=25)
    g.text(80, 960, "记录总时间、实际访问次数和额外观测读；区分“次数固定”与“时长固定”的试验。",
           size=25)
    g.footer("来源：[15] RAD 机理研究；此时序为本文工程测试框架，不是论文原始 March 算法。",
             "定性时序示意；脉宽和间隔不按比例，内部完成条件须遵守目标宏规格。")
    return g.save()


if __name__ == "__main__":
    for draw in (draw_march_restore_escape, draw_pund,
                 draw_retention_first_read, draw_rad_timing):
        print(draw())
