#!/usr/bin/env python3
"""Generate editable Graphviz DOT and SVG/PNG counterparts for the Chinese manual.
Requires graphviz 'dot'. No network required.
"""
from pathlib import Path
import subprocess

OUT = Path(__file__).resolve().parent.parent / '插图'
DOT = OUT / '源码_DOT'
DOT.mkdir(parents=True, exist_ok=True)
PFX = '''digraph G {
  graph [rankdir=LR, bgcolor="transparent", pad=0.24, margin=0.05,
         nodesep=0.42, ranksep=0.62, splines=polyline,
         fontname="Noto Sans CJK SC", fontsize=16];
  node [shape=box, style="rounded,filled", fillcolor="#F3F7FC", color="#446786",
        fontname="Noto Sans CJK SC", fontsize=14, fontcolor="#18334B", penwidth=1.2,
        margin="0.20,0.14"];
  edge [color="#567C9C", arrowsize=0.75, penwidth=1.25,
        fontname="Noto Sans CJK SC", fontsize=11, fontcolor="#39566E"];
'''
figures = {
 '01_验证方法': ''' simulation [label="RTL 仿真\\n给定激励 → 一条执行轨迹", fillcolor="#E5F3E8", color="#41976C"];
 formal [label="形式验证\\n合法输入与初态 → 状态空间搜索", fillcolor="#E6EEFC", color="#4C73B8"];
 spec [label="设计规格与接口约束",fillcolor="#FFF1E1",color="#CB9154"];
 score [label="发现缺陷 / 证明规则 / 发现未覆盖条件",fillcolor="#F4EFFA", color="#8063AF"];
 spec -> simulation; spec -> formal; simulation -> score; formal -> score;
''',
 '02_证明流程': ''' rtl [label="RTL / 状态转移模型"];
 env [label="环境假设 + 时钟复位"];
 sva [label="SVA 断言与覆盖目标"];
 solver [label="求解引擎\\nSAT · 归纳 · PDR · 抽象",fillcolor="#E8EEFC",color="#5371B5"];
 pass [label="Proven\\n检查前提与空洞性",fillcolor="#E4F4EA",color="#4A8F63"];
 fail [label="Falsified\\n分析反例和合法性",fillcolor="#FBE8E6",color="#BF6556"];
 unk [label="Inconclusive\\n分析难点 / 调整策略",fillcolor="#FFF3DE",color="#C28F36"];
 rtl -> solver; env -> solver; sva -> solver;
 solver -> pass; solver -> fail; solver -> unk;
''',
 '03_应用布局': ''' core [label="VC Formal 公共平台\\n编译 · 约束 · 属性 · 求解 · 报告",fillcolor="#DDEAFF",color="#4D72B4"];
 p [label="功能与属性\\nFPV / AEP / FCA"];
 s [label="结构与变化\\nCC / FXP / SEQ"];
 r [label="专项应用\\nFRV / FTA / FuSa"];
 h [label="高级场景\\nFSV / DPV / FLP"];
 core -> p; core -> s; core -> r; core -> h;
''',
 '04_执行流程': ''' spec [label="解读规格\\n定义责任与合法输入"];
 model [label="编译 RTL + SVA\\n时钟 / 复位 / 初始状态"];
 setup [label="检查模型与约束\\n核对属性列表"];
 run [label="求解断言与覆盖目标",fillcolor="#E5EEFC",color="#567CC1"];
 debug [label="解释反例 / 未完成\\n修正规格、RTL 或环境"];
 release [label="回归与交付\\n记录版本、报告和豁免",fillcolor="#E4F5EB",color="#4A9969"];
 spec -> model -> setup -> run -> debug -> release;
 debug -> model [style=dashed, constraint=false, label="需要修改时"];
''',
 '05_SVA时序': ''' node [shape=record, style="filled", margin=0.2];
 t0 [label="{第 0 拍|req=1|触发}",fillcolor="#E6EEFC"];
 t1 [label="{第 1 拍|ack 可为 1|响应窗口}"];
 t2 [label="{第 2 拍|ack 可为 1|响应窗口}"];
 t3 [label="{第 3 拍|ack 可为 1|最后期限}",fillcolor="#FFF0DF"];
 t0 -> t1 -> t2 -> t3;
''',
 '06_FPV工作流程': ''' rtl [label="DUT RTL"];
 sv [label="SVA / bind / AIP"];
 formal [label="FPV 形式环境\\n时钟、复位、假设",fillcolor="#DCEBFF",color="#577BBA"];
 solve [label="check_fv"];
 assert [label="assert：Proven / Falsified / Inconclusive",fillcolor="#F3EFFC"];
 cover [label="cover：Covered / Uncoverable",fillcolor="#E6F5EB"];
 rtl -> formal; sv -> formal; formal -> solve; solve -> assert; solve -> cover;
''',
 '07_FXP传播': ''' src [label="未知值来源\\n未复位 / 未驱动 / X 赋值",fillcolor="#FFE5E2",color="#C45C57"];
 comb [label="组合选择逻辑\\n有效位 / 选择信号"];
 flop [label="控制或数据寄存器"];
 observe [label="关键观察点\\n是否传播到输出？",fillcolor="#FFF1D8",color="#C68D45"];
 src -> comb -> flop -> observe;
''',
 '08_FXP排查': ''' fail [label="不允许的 X 到达观察点",fillcolor="#FCE5E3",color="#BE625A"];
 trace [label="检查传播路径与时钟周期"];
 orig [label="辨别 X 来源\\n初始化 / 显式 X / 越界 / 黑盒"];
 assume [label="审查复位与约束真实性"];
 fix [label="修改 RTL 或有效位屏蔽\\n重新回归",fillcolor="#E5F3E8",color="#42936A"];
 fail -> trace -> orig -> assume -> fix;
''',
 '09_CC连接': ''' a [label="输入源 A"];
 b [label="输入源 B"];
 mux [label="受 sel 控制的多路选择器",fillcolor="#DCEAFE",color="#577FBC"];
 y [label="目的端口 Y\\nsel=0 → A\\nsel=1 → B",fillcolor="#E7F5E8",color="#4E9C70"];
 a -> mux [label="sel = 0"]; b -> mux [label="sel = 1"]; mux -> y;
''',
 '10_SEQ比较': ''' spec [label="参考 RTL (Spec)"];
 impl [label="实现 RTL (Impl)"];
 align [label="输入约束 / 初态 / 对应关系",fillcolor="#FFF0DC",color="#C78F4A"];
 compare [label="顺序等价检查\\n状态和输出关系",fillcolor="#E4EDFE",color="#5C7CBC"];
 result [label="Equivalent / 反例 / 未完成",fillcolor="#E6F3E9",color="#4E976A"];
 spec -> compare; impl -> compare; align -> compare; compare -> result;
''',
 '11_FTA故障': ''' rtl [label="原设计 + 形式属性"];
 fault [label="故障/RTL 修改注入",fillcolor="#FCE6E0",color="#BC685C"];
 solve [label="形式检错分析",fillcolor="#E5EEFE",color="#537AB9"];
 detected [label="被属性检出",fillcolor="#E4F3E8",color="#4D9168"];
 missed [label="未检出 / 未完成\\n补充规则或复核限制",fillcolor="#FFF1DC",color="#BE8D43"];
 rtl -> solve; fault -> solve; solve -> detected; solve -> missed;
''',
 '12_FSV信息流': ''' secret [label="安全源 Secret",fillcolor="#FFE3E3",color="#BE6464"];
 secure [label="可信处理与访问控制",fillcolor="#EBEEFC",color="#6678B7"];
 public [label="公开输出 Public",fillcolor="#E5F4EB",color="#51946A"];
 policy [label="安全信息流规则\\n禁止未经授权传播",fillcolor="#FFF0DF",color="#BF8D45"];
 secret -> secure; secure -> public [label="仅允许规定输出"]; policy -> secure [style=dashed];
''',
 '13_DPV阶段': ''' spec [label="C/C++ 参考事务\\nphase 1 输入 → phase 1 结果"];
 impl [label="RTL 流水线\\nphase 1 输入 → phase 2 计算 → phase 3 输出"];
 map [label="输入阶段对应 + 输出阶段对应",fillcolor="#E9EEFC",color="#5A78BA"];
 proof [label="事务结果一致性证明",fillcolor="#E2F3E8",color="#51946A"];
 spec -> map; impl -> map; map -> proof;
''',
 '14_FLP电源域': ''' a [label="可关断电源域 PD_A\\n功能信号 data",fillcolor="#F6E9E1",color="#C18A60"];
 iso [label="隔离单元 ISO\\n关断时钳位为零",fillcolor="#FFF0DF",color="#C18E47"];
 aon [label="始终供电域 PD_AON\\n下游控制逻辑",fillcolor="#E4F4EC",color="#51956F"];
 upf [label="UPF 电源意图\\n电源状态、隔离条件",fillcolor="#E8EEFF",color="#5A78B3"];
 a -> iso -> aon; upf -> iso [style=dashed];
''',
 '15_调试决策': ''' result [label="形式检查结果",fillcolor="#E5EEFC",color="#597CB9"];
 fail [label="Falsified\\n核对反例合法性",fillcolor="#FCE9E6",color="#C17869"];
 pass [label="Proven\\n审查假设与空洞性",fillcolor="#E5F4E9",color="#559C76"];
 inc [label="Inconclusive（未完成）\\n拆分属性、补充不变量\\n调整性能与资源",fillcolor="#FFF2DF",color="#C69348"];
 result -> fail; result -> pass; result -> inc;
'''
}
for stem, body in figures.items():
    source = PFX + body + '\n}\n'
    d = DOT / (stem + '.dot')
    d.write_text(source, encoding='utf-8')
    for fmt in ['svg', 'png']:
        args = ['dot', '-T' + fmt, str(d), '-o', str(OUT / f'{stem}.{fmt}')]
        if fmt == 'png': args.insert(1, '-Gdpi=180')
        subprocess.run(args, check=True)
print(f'generated {len(figures)} graphs, {len(figures)*3} files')
