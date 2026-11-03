"""Original, qualitative FeFET / FRAM DfT diagrams for the research report.

Only standard-library Python and the shared diagram_common primitives are used.
The window positions are illustrative coordinates, never fitted measurements.
"""
from diagram_common import SVG, C


def figure_windows():
    g = SVG(
        "fig10_fefet_windows.svg",
        "FeFET：窗口收窄与阈值共向漂移",
        "同一横轴标度的概念位置；LVT / HVT 不固定对应逻辑 0 / 1。",
        height=1000,
    )

    x_axis_start, x_axis_end, x_reference = 400, 1300, 940
    rows = [
        (180, "正常两态", "MW 作为比较基准", 660, 1140, "teal"),
        (385, "ACT：窗口收窄", "两阈值向内靠近", 830, 970, "blue"),
        (590, "TVS：共向负移", "MW 近似保持", 430, 910, "purple"),
    ]

    for y, title, description, x_low, x_high, accent in rows:
        axis_y = y + 115
        g.rect(52, y, 1296, 180, fill="gray_bg", stroke="line", radius=15)
        g.text(76, y + 47, title, size=30, weight=700, fill=accent)
        g.text(76, y + 91, description, size=24, fill="muted")
        g.text(76, y + 132, "LVT 低阈值；HVT 高阈值", size=21, fill="muted")

        # A position interval is shown rather than a fabricated distribution.
        g.rect(x_low, axis_y - 37, x_high - x_low, 18,
               fill=accent + "_bg", stroke=accent, radius=5, width=1.8)
        g.line(x_low, axis_y - 48, x_low, axis_y + 10, color=accent, width=3.2)
        g.line(x_high, axis_y - 48, x_high, axis_y + 10, color=accent, width=3.2)
        g.line(x_axis_start, axis_y, x_axis_end, axis_y,
               color="muted", width=2, arrow=True)
        g.circle(x_low, axis_y, 5, fill=accent)
        g.circle(x_high, axis_y, 5, fill=accent)
        g.text(x_low, axis_y + 43, "LVT", size=24,
               weight=700, fill=accent, anchor="middle")
        g.text(x_high, axis_y + 43, "HVT", size=24,
               weight=700, fill=accent, anchor="middle")
        g.text(x_axis_end, axis_y + 43, "Vth →", size=24,
               fill="muted", anchor="end")

        # Identical x coordinate for every row; the reference is not a fitted Vt.
        g.line(x_reference, axis_y - 69, x_reference, axis_y + 13,
               color="orange", width=2.7, dash="7 6")
        g.text(x_reference, axis_y - 84, "固定读参考", size=22,
               fill="orange", weight=700, anchor="middle")

    g.card(52, 806, 632, 105, "固定虚线：概念等效读参考",
           "真实判决基于 Iread 与 Iref 的比较", accent="orange", size=25)
    g.card(708, 806, 640, 105, "窗口宽度与中心位置需同时观察",
           "单独检查其中一项，可能漏掉另一类变化", accent="blue", size=24)
    g.footer(
        "来源：报告文献 [29]–[31]；据器件机理原创绘制。",
        "位置与间距仅作定性示意；并非实测分布，也不代表任一器件的规格。",
    )
    return g.save()


def test_step(g, x, y, w, label, operation, accent):
    g.rect(x, y, w, 110, fill="white", stroke=accent, radius=11, width=1.8)
    g.text(x + w / 2, y + 35, label, size=24,
           fill="muted", anchor="middle")
    g.text(x + w / 2, y + 84, operation, size=34,
           fill=accent, weight=700, anchor="middle")


def figure_tests():
    g = SVG(
        "fig11_fefet_tests.svg",
        "FeFET 专用测试的执行段与参考比较",
        "三条已核验序列仅针对论文给定的器件模型与故障范围，不能替代完整存储器测试。",
        height=1100,
    )
    cards = [
        dict(x=52, title="March-SAP", author="Wang 等 · ITC 2024", count="3N",
             topic="SAP：局部畴不能正常翻转", second="⇕ (w0, r0)", accent="blue",
             lines="每个地址先写 0，再读 0\n目标：原模型中的 EtD",
             reference="按相关 U 态选择参考"),
        dict(x=492, title="ACT 专用段", author="Yuan 等 · ASP-DAC 2025", count="2N",
             topic="ACT：异常俘获缩小窗口", second="⇕ (r1)", accent="teal",
             lines="写 1 后读出并比较\nU 态可造成数字测试逃逸",
             reference="U / 1 分界"),
        dict(x=932, title="March-TVS", author="Wang 等 · ITC 2025", count="3N",
             topic="TVS：两阈值共向漂移", second="⇕ (w0, r0)", accent="purple",
             lines="每个地址先写 0，再读 0\n范围：论文中的负向 TVS",
             reference="U / 0 分界"),
    ]
    for c in cards:
        x, w, accent = c["x"], 416, c["accent"]
        g.rect(x, 170, w, 620, fill=accent + "_bg", stroke="line", radius=16)
        g.text(x + 24, 215, c["title"], size=29, weight=700, fill=accent)
        g.tag(x + w - 97, 183, c["count"], color=accent, w=73)
        g.text(x + 24, 253, c["author"], size=22, fill="muted")
        g.text(x + 24, 292, c["topic"], size=24, fill="ink")

        test_step(g, x + 24, 317, w - 48, "第 1 段 · 全地址遍历", "⇕ (w1)", accent)
        g.arrow(x + w / 2, 435, x + w / 2, 463, color=accent)
        test_step(g, x + 24, 473, w - 48, "第 2 段 · 全地址遍历", c["second"], accent)
        g.text(x + 24, 624, c["lines"], size=24, linespacing=1.5)
        g.line(x + 24, 683, x + w - 24, 683, color="line", width=1.4)
        g.text(x + 24, 719, "模拟测试参考", size=23, fill="muted")
        g.text(x + 24, 759, c["reference"], size=27, weight=700, fill=accent)

    g.rect(52, 814, 1296, 187, fill="gray_bg", stroke="line", radius=14)
    g.text(76, 852, "U 是模拟弱裕量区，不等于 Verilog X", size=28, weight=700)
    g.text(76, 894, "普通读出仍可能返回期望值；可调参考用于增加模拟可观察性。", size=26)
    g.text(76, 936, "每段完成全部地址后，再执行下一段；⇕ 不限定地址递增或递减方向。", size=25)
    g.text(76, 978, "EtD：普通读写可确定检出。N 为被测单元数；操作计数不等于端到端测试时间。", size=23,
           fill="muted")
    g.footer(
        "来源：报告文献 [29] SAP、[30] ACT、[31] TVS；3N / 2N / 3N 按原文序列计数。",
        "参考测试的覆盖结论依赖器件模型、校准与工况，不能推广为所有 FeFET / FRAM 故障均被覆盖。",
    )
    return g.save()


def block(g, x, y, w, h, title, lines, accent="blue", title_size=28, body_size=25):
    g.rect(x, y, w, h, fill=accent + "_bg", stroke=accent, radius=13, width=1.6)
    g.text(x + 20, y + 40, title, size=title_size, weight=700, fill=accent)
    g.text(x + 20, y + 83, lines, size=body_size, linespacing=1.5)


def figure_mbist():
    g = SVG(
        "fig12_mbist_architecture.svg",
        "FRAM MBIST / DfT 的可配置架构",
        "工程建议：数字序列、首次失败记录、访问历史和可选宏内控制分别组织。",
        height=1100,
    )
    x_left, x_mid, x_right, w = 76, 526, 976, 348
    g.rect(52, 167, 1296, 244, fill="white", stroke="blue", radius=15, width=1.8)
    g.text(76, 206, "正常接口可控制", size=26, weight=700, fill="blue")
    g.text(1309, 206, "先执行与确认访问，再推进测试步骤", size=22,
           fill="muted", anchor="end")
    block(g, x_left, 235, w, 145, "可配置序列器",
          "March／保持／扰动段\n等待与重复计数", accent="blue")
    block(g, x_mid, 235, w, 145, "地址与数据发生器",
          "方向／范围／数据背景\n保留期望数据", accent="blue", title_size=27)
    block(g, x_right, 235, w, 145, "正常接口适配",
          "握手／完成／超时\n确保访问到达存储宏", accent="blue")
    g.arrow(x_left + w + 10, 308, x_mid - 10, 308)
    g.text(475, 289, "操作", size=23, fill="muted", anchor="middle")
    g.arrow(x_mid + w + 10, 308, x_right - 10, 308)
    g.text(925, 289, "请求", size=23, fill="muted", anchor="middle")

    # A simple U-shaped data path keeps all arrows separated.
    block(g, x_left, 450, w, 190, "首次失败捕获",
          "地址／读值／期望值\n步骤／时间／当前工况\n保留首次读结果", accent="red", body_size=24)
    block(g, x_mid, 450, w, 190, "读出比较",
          "实际值与期望值比较\n记录不匹配及有效性\n可配置停止或继续", accent="teal", body_size=24)
    block(g, x_right, 450, w, 190, "FRAM 存储宏",
          "正常地址／数据／控制\n内部感测与数据恢复\n可选宏内测试端口", accent="blue", body_size=24)

    g.arrow(x_mid + w / 2, 388, x_mid + w / 2, 440)
    g.text(x_mid + w / 2 + 17, 428, "期望值", size=23, fill="muted")
    g.arrow(x_right + w / 2, 388, x_right + w / 2, 440)
    g.text(x_right + w / 2 + 17, 428, "正常访问", size=23, fill="muted")

    g.arrow(x_right - 10, 546, x_mid + w + 10, 546)
    g.text(925, 529, "实际值", size=23, fill="muted", anchor="middle")
    g.arrow(x_mid - 10, 546, x_left + w + 10, 546)
    g.text(475, 529, "不匹配", size=23, fill="muted", anchor="middle")

    block(g, x_left, 725, w, 190, "执行历史与结果",
          "访问／翻转估计计数\n循环次数与等待时间\n合并首失败和工况", accent="gray", body_size=24)
    block(g, x_mid, 725, w, 190, "温度／电源协同",
          "外部仪器或片上监测\n记录温度与电源条件\n与测试段同步", accent="orange", body_size=24)
    block(g, x_right, 725, w, 190, "宏内 DfT（可选）",
          "读参考／恢复脉宽\n采样时刻／内部观测\n需要独立校准", accent="purple", body_size=24)

    g.arrow(x_left + w / 2, 650, x_left + w / 2, 715)
    g.text(x_left + w / 2 + 17, 692, "记录", size=23, fill="muted")
    g.arrow(x_right + w / 2, 715, x_right + w / 2, 650, color="purple")
    g.text(x_right + w / 2 + 17, 689, "仅宏支持时", size=22, fill="purple")

    # Environmental control reaches the macro below the read-data lane.
    g.polyline([(x_mid + w / 2, 715), (x_mid + w / 2, 680),
                (930, 680), (930, 603), (966, 603)],
               color="orange", width=2.5, arrow=True)
    g.text(822, 669, "温度／电源", size=22, fill="orange", anchor="middle")

    g.text(76, 959, "总线控制与宏内测试能力应分别声明；没有内部端口时，不假定可修改读参考或恢复时序。",
           size=25, fill="ink")
    g.text(76, 997, "执行历史应由序列器同步更新，并与首次失败记录使用同一测试步骤编号。",
           size=23, fill="muted")
    g.footer(
        "来源：本文第 8 章工程建议；可调参考测试思想参见报告文献 [29]–[31]。",
        "架构仅示意功能分工；具体接口、内部可观察性与温度电源控制能力取决于被测宏。",
    )
    return g.save()


if __name__ == "__main__":
    # Reuse the shared neutral palette without modifying diagram_common.py.
    C.setdefault("gray", C["muted"])
    for result in (figure_windows(), figure_tests(), figure_mbist()):
        print(result)
