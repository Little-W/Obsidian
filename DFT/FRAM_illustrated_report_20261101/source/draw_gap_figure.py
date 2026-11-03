"""Original qualitative evidence-scope diagram for the FRAM report.

This figure separates demonstrated results from conclusions that require their
own verification. It does not claim that any research direction is unexplored.
"""

import sys

sys.dont_write_bytecode = True

from diagram_common import SVG


def draw_evidence_gaps():
    g = SVG(
        "fig13_evidence_gaps.svg",
        "图13　已有证据与仍需单独验证的问题",
        "已有结果不能自动支持更大范围的结论；应针对新增条件设计独立检验。",
        height=1040,
    )

    columns = [
        (54, 400, "已有结果", "blue"),
        (476, 445, "尚需单独验证", "orange"),
        (943, 403, "可实施检验", "teal"),
    ]
    for x, width, heading, color in columns:
        g.rect(x, 158, width, 70, fill=color, stroke="none", radius=12)
        g.text(x + 24, 204, heading, size=29, weight=700, fill="white")

    rows = [
        (
            ("回线或脉冲拟合", "在选定条件下复现响应"),
            ("失效行为与历史泛化", "失效条件下的预测能力\n不同访问历史下的适用性"),
            ("独立波形与历史验证", "使用未参与拟合的数据\n对比响应及首次失败轨迹"),
        ),
        (
            ("单一缺陷可检", "已定义实例能够被检出"),
            ("联合缺陷与误剔除", "多个参数共同变化时的表现\n正常样本被判故障的概率"),
            ("参数组合＋正常样本", "组合缺陷与无缺陷对照\n同时统计漏检和误剔除"),
        ),
        (
            ("单元模型或局部电路", "已描述单元与邻近响应"),
            ("物理组与阵列可观察性", "共享线路与恢复范围的影响\n首激活原始数据的保留能力"),
            ("共享行首读＋拓扑测试", "核实恢复组与板线关系\n对比首读、快照与重读"),
        ),
        (
            ("指定条件下通过", "给定温度、时间和样本"),
            ("跨工况与批次可靠性", "不同温度及使用历史的结果\n其他批次与长期终点的表现"),
            ("留出样本＋加速模型", "独立样本评估预测误差\n核验加速机制与外推范围"),
        ),
    ]

    for row_index, cells in enumerate(rows):
        y = 244 + 166 * row_index
        for (x, width, _heading, color), (title, body) in zip(columns, cells):
            g.rect(x, y, width, 150, fill=color + "_bg", stroke="line", radius=12)
            g.text(x + 24, y + 42, title, size=28, weight=700, fill=color)
            g.text(x + 24, y + 87, body, size=26, linespacing=1.42)

    g.rect(54, 913, 1292, 39, fill="gray_bg", stroke="none", radius=8)
    g.text(78, 941,
           "这里列出证据的推断范围；相关方向可能已有研究，仍须核验具体模型、条件和评价范围。",
           size=24, fill="muted")
    g.footer(
        "来源：[4][8][15]—[19][37]；检验安排为本文提出的研究建议。",
        "原创定性归纳；不表示领域无人研究，也不把未取得全文等同于论文缺少相关内容。",
    )
    return g.save()


if __name__ == "__main__":
    print(draw_evidence_gaps())
