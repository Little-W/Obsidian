"""Resource-dependent research routes proposed for the FRAM report.

This is an original planning diagram, not a measured ranking or a claim of
technology-independent coverage. Uses the common SVG primitives only.
"""
from diagram_common import SVG, C


def route_card(g, x, y, title, body, accent, w=348):
    g.rect(x, y, w, 142, fill="white", stroke=accent, radius=12, width=1.8)
    g.text(x + 20, y + 41, title, size=27, weight=700, fill=accent)
    g.text(x + 20, y + 83, body, size=24, linespacing=1.5)


def draw():
    g = SVG(
        "fig14_research_routes.svg",
        "图14　按资源划分的研究路线",
        "资源决定可证实的结论；先明确可控制与可观察的量，再选择方法与验证层级。",
        height=1100,
    )
    columns = (76, 526, 976)
    routes = [
        dict(
            y=180, accent="teal",
            titles=("① 数字接口 + FPGA", "首次读／恢复组记录", "历史与间隔测试"),
            bodies=(
                "正常读写／等待／重复\n记录实际访问时刻",
                "保留首次结果与访问时刻\n恢复组须注明依据",
                "初态／等待／访问模式\n观察外部可见错误",
            ),
            output="产出：功能接口上的时序错误与历史效应；不据此推断全部宏内机制。",
        ),
        dict(
            y=405, accent="blue",
            titles=("② RTL + 电路模型", "带时间的故障原语", "有界测试序列生成"),
            bodies=(
                "可控制波形与缺陷注入\n模型参数须有标定依据",
                "显式记录初态与操作历史\n保留模拟或逻辑观测量",
                "限制长度／等待／参考档位\n回到电路中复核反例",
            ),
            output="产出：给定模型与搜索范围内的覆盖；不等同于硅上故障覆盖。",
        ),
        dict(
            y=630, accent="purple",
            titles=("③ 宏内 DfT + 硅样本", "参考校准／联合缺陷", "拓扑与跨批次验证"),
            bodies=(
                "可调参考与内部观测\n独立器件／芯片／批次",
                "同时检查逃逸与误拒\n联合模型须有物理依据",
                "保留实际邻接与共享结构\n用未参与拟合的样本检验",
            ),
            output="产出：所测结构与工况内的实验结论；推广范围由样本和校准证据限定。",
        ),
    ]

    for row in routes:
        y, accent = row["y"], row["accent"]
        g.rect(52, y - 15, 1296, 212, fill=accent + "_bg", stroke="line", radius=15)
        for x, title, body in zip(columns, row["titles"], row["bodies"]):
            route_card(g, x, y, title, body, accent)
        g.arrow(columns[0] + 358, y + 72, columns[1] - 10, y + 72,
                color=accent, width=2.8)
        g.arrow(columns[1] + 358, y + 72, columns[2] - 10, y + 72,
                color=accent, width=2.8)
        g.text(76, y + 175, row["output"], size=24, fill="ink")

    g.rect(52, 854, 1296, 148, fill="gray_bg", stroke="line", radius=15)
    g.text(76, 890, "共同评价", size=28, weight=700)
    g.text(1323, 890, "覆盖与成本须同时报告", size=23, fill="muted", anchor="end")
    for x, text in zip((76, 394, 712, 1030),
                       ("检出／误杀", "实际测试时间", "额外测试应力", "独立样本验证")):
        g.rect(x, 906, 294, 55, fill="white", stroke="line", radius=9)
        g.text(x + 147, 943, text, size=25, weight=700,
               fill=C["blue"], anchor="middle")
    g.text(76, 991, "误杀指合格样本被误拒；测试开销和附加应力应与缺陷检出一起衡量。",
           size=22, fill="muted")
    g.footer(
        "来源：本文研究方向建议；方法背景参见报告文献 [29]–[36]、[41]。",
        "研究路线不承诺脱离器件、接口、模型和样本条件的统一覆盖率。",
    )
    return g.save()


if __name__ == "__main__":
    print(draw())
