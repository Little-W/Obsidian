#!/usr/bin/env python3
"""Editable technical illustrations. Named ports; deterministic orthogonal routes.
Run browser geometry validation after any text/font/position changes.
All figures are independent educational diagrams, not copies of paper figures.
"""
from pathlib import Path
import json
from svg_geometry import Figure,wrap
ROOT=Path(__file__).resolve().parents[1]
FIGS=[]
def start(n,stem,title,sub,h): return Figure(f'{n:02d}_{stem}',f'图{n}  {title}',sub,h)
def save(f): FIGS.append(f.save(ROOT/'assets'/f'{f.stem}.svg'))
def chain(f,rows,x=200,w=800,y=240,gap=90):
    prev=None
    for i,(title,body) in enumerate(rows):
        node=f'n{i}';b=f.node(node,x,y,w,title,body)
        if prev:f.connect(f'e{i}',prev,node,meaning='从上一阶段进入下一阶段')
        prev=node;y+=b.h+gap
    return y

def main():
    f=start(1,'architecture','扫描测试的完整架构','ATPG 在设计计算机上生成向量；芯片执行扫描协议。',1880)
    y=chain(f,[('设计输入', ['门级电路、单元库、故障模型、时钟与模式']),('扫描与辅助结构插入',['扫描触发器、链连接、压缩、测试点、OCC']),('ATPG 与故障模拟',['生成可施加的向量，并核查实际检测集合']),('自动测试设备与芯片',['装入状态 → 捕获响应 → 卸出并比较']),('失败记录与诊断',['解释失败位置；必要时追加测试与物理检查'])],x=160,w=880)
    f.note(y,['扫描硬件、生成算法、制造执行和诊断是不同职责。','MBIST 是存储器测试的配套结构，不被内部扫描链直接替代。']);save(f)

    f=start(2,'scan_cell','多路选择式扫描触发器','SE 选择数据来源；CLK 决定何时保存，不是同一个信号。',1270)
    f.node('func',70,250,300,'功能输入 D',h=130)
    f.node('si',70,500,300,'串行输入 SI',h=130)
    f.node('mux',510,375,280,'选择器',['SE=0：D','SE=1：SI'],h=270,bs=30)
    f.node('ff',910,410,220,'触发器',['保存 Q'],h=200,ts=32,bs=30)
    f.edge('functional',f.port('func','E'),f.port('mux','W',.25),via=[(440,315),(440,442.5)],meaning='功能数据进入选择器的功能输入')
    f.edge('scan_data',f.port('si','E'),f.port('mux','W',.75),via=[(440,565),(440,577.5)],meaning='串行数据进入选择器的扫描输入')
    f.edge('selected_data',f.port('mux','E'),f.port('ff','W'),meaning='选择后的数据接入触发器 D 端')
    f.node('se',510,850,280,'扫描使能 SE',h=130,ts=32)
    f.node('clk',910,850,220,'时钟 CLK',h=130,ts=32)
    f.edge('mode',f.port('se','N'),f.port('mux','S'),color='orange',dashed=True,meaning='SE 为选择控制，不是数据')
    f.edge('clock',f.port('clk','N'),f.port('ff','S'),color='teal',dashed=True,meaning='触发器由有效时钟沿保存所选数据')
    f.note(1100,['实线：数据方向。虚线：选择控制或时钟。','复位与真实标准单元内部电路在此概念图中省略。']);save(f)

    f=start(3,'four_chain','四级扫描链与位序','Q0 靠近串行输入；每个有效沿同时读取所有旧状态。',1170)
    f.node('si',80,240,200,'SI',h=110)
    for i,x in enumerate([80,360,640,920]):f.node(f'q{i}',x,500,200,f'Q{i}',h=120)
    f.connect('input','si','q0',meaning='最先接收串行输入的扫描触发器是 Q0')
    for i in range(3):f.edge(f'shift{i}',f.port(f'q{i}','E'),f.port(f'q{i+1}','W'),meaning=f'Q{i} 的旧值移入 Q{i+1}')
    f.node('so',920,780,200,'SO',h=110)
    f.connect('output','q3','so',meaning='沿前读取旧 Q3 作为串行输出')
    f.lines(80,805,['最终目标：[1,1,0,1]','输入次序： 1 → 0 → 1 → 1'],gap=64,size=34)
    f.note(1010,['不能依次用刚更新的 Q0、Q1 更新后面的触发器。','实际芯片由同一有效沿使各级同时取样。']);save(f)

    f=start(4,'shift_capture','装入、捕获与重叠卸出','每次捕获后的结果仍需完整读出，最后一条也不例外。',1620)
    chain(f,[('第一次装入',['SE=1；输入向量 1 的扫描状态']),('捕获向量 1',['SE=0；按规定功能脉冲保存响应']),('卸出 1，同时装入 2',['SE=1；一端输出旧响应，另一端输入新状态']),('捕获向量 2',['SE=0；保存第二次响应']),('最后一次卸出',['即使没有下一条向量，也必须完成响应比较'])],x=150,w=900,gap=85)
    save(f)

    f=start(5,'chain_balance','最长链决定理想移位长度','六条链合计 1200 个触发器；固定向量数和时钟比较。',1530)
    f.t(64,240,'未平衡：最长链 350',size=36,weight=700)
    values=[350,250,200,150,150,100]
    for i,v in enumerate(values):
        y=325+i*80;f.t(80,y,f'链 {i}',size=30);f.rect(f'unbal{i}',230,y-23,v*2,46,fill='zero',stroke='none',kind='bar',radius=4);f.t(250+v*2,y,str(v),size=30)
    f.t(64,850,'平衡后：最长链 200',size=36,weight=700)
    for i in range(6):
        y=935+i*80;f.t(80,y,f'链 {i}',size=30);f.rect(f'bal{i}',230,y-23,400,46,fill='pale_teal',stroke='none',kind='bar',radius=4);f.t(650,y,'200',size=30)
    f.note(1450,['未平衡时，理想移位周期比平衡方案多 75%。','这个例子未计入布线、压缩、捕获与功率限制。']);save(f)

    f=start(6,'launch_capture','LOC 与 LOS 的关键区别','示意图不按真实时间比例；脉冲间隔需符合实际测试协议。',1870)
    for off,kind,desc in [(0,'LOC','最后移位不是发起；第一个功能脉冲发起'),(830,'LOS','最后移位发起；随后切换 SE，再捕获')]:
        f.t(64,240+off,kind+'：'+desc,size=32,weight=700)
        titles=['装入初始状态','功能脉冲：发起','功能脉冲：捕获'] if kind=='LOC' else ['最后移位：发起','切换扫描使能','功能脉冲：捕获']
        for i,x in enumerate([70,450,830]):f.node(f'{kind}{i}',x,325+off,300,titles[i],h=130,ts=30)
        for i in range(2):f.edge(f'{kind}-step{i}',f.port(f'{kind}{i}','E'),f.port(f'{kind}{i+1}','W'),meaning=titles[i]+'之后才执行'+titles[i+1])
        f.t(85,580+off,'SE',size=32);f.t(85,715+off,'CLK',size=32)
        f.rule(kind+'-se',[(300,560+off),(560 if kind=='LOC' else 700,560+off),(560 if kind=='LOC' else 700,605+off),(1120,605+off)],color='orange',width=4)
        ticks=[400,700,1000] if kind=='LOC' else [400,1000]
        pts=[(300,740+off)]
        for x in ticks:pts += [(x,740+off),(x,685+off),(x+30,685+off),(x+30,740+off)]
        pts +=[(1120,740+off)];f.rule(kind+'-clk',pts,color='teal',width=4)
        for x,label in zip(ticks,['末次移位','发起','捕获'] if kind=='LOC' else ['移位发起','捕获']):f.t(x+15,795+off,label,size=30,anchor='middle')
    f.note(1750,['LOC 的第二状态由正常状态转移产生，不可任意独立赋值。','LOS 对扫描使能切换与相邻脉冲的控制提出不同要求。']);save(f)

    f=start(7,'hold_lockup','扫描保持时间与锁存器','示例：两个上升沿触发器之间采用低电平透明锁存器。',1430)
    f.node('src',90,260,400,'源触发器',['上升沿更新 Q'],h=200)
    f.node('lat',710,260,400,'锁存器',['高电平保持','低电平允许传递'],h=250)
    f.edge('source-data',f.port('src','E'),f.port('lat','W',.4),meaning='源触发器的新数据先进入锁存器')
    f.node('dst',710,730,400,'目的触发器',['下一个合法沿取样'],h=200)
    f.connect('latch-output','lat','dst',meaning='锁存器隔离过早到达的数据')
    f.node('explain',90,700,470,'为什么有效',['给过早的新数据增加隔离','极性与时钟关系必须核实'],h=250,bs=30,accent='orange')
    f.node('formula',90,1100,1020,'同沿扫描路径的保持条件',['最短数据延迟 ≥ 时钟偏斜 + 保持时间 + 不确定性'],h=200,ts=34,bs=30,accent='teal')
    f.note(1360,['锁存器不是任意异步时钟之间的同步器。']);save(f)

    f=start(8,'access','控制配置与扫描数据分开','图中是可选的概念架构，不代表某个厂商产品逐门实现。',1700)
    f.t(300,245,'配置与时钟控制',size=36,anchor='middle',weight=700)
    f.t(900,245,'大量扫描数据',size=36,anchor='middle',weight=700)
    left=[('TAP / 授权选择',['选择制造或调试访问']),('模式寄存器',['模式、复位与屏蔽配置']),('核级控制与 OCC',['生成受控捕获时钟'])]
    right=[('数据通道',['独立引脚或数据网络']),('输入解压缩器',['种子转成扫描激励']),('内部扫描链',['移位并按协议捕获']),('响应压缩与卸出',['保留周期与核的对应'])]
    for i,(t,b) in enumerate(left):f.node(f'l{i}',70,330+340*i,460,t,b,h=210)
    for i,(t,b) in enumerate(right):f.node(f'r{i}',670,330+340*i,460,t,b,h=210)
    for i in range(2):f.connect(f'ctrl{i}',f'l{i}',f'l{i+1}',color='orange',meaning='向下配置核级测试控制')
    for i in range(3):f.connect(f'data{i}',f'r{i}',f'r{i+1}',meaning='扫描数据按规定处理并传输')
    f.edge('clock-control',f.port('l2','E'),f.port('r2','W'),color='orange',dashed=True,meaning='控制器向核内扫描逻辑提供模式和受控时钟，非数据直连')
    f.note(1660,['JTAG 可以只负责配置，不必传送全部高带宽扫描数据。']);save(f)

    f=start(9,'fault_models','故障模型与观察条件','模型覆盖不等于覆盖全部物理缺陷。',1510)
    y=240
    for i,(title,body) in enumerate([
        ('固定故障',['使正常值与固定值不同，再把差异传播到输出。']),
        ('转换与路径延迟',['初始化 → 发起转换 → 在规定时间捕获。']),
        ('桥接、开路与单元内部缺陷',['模型可能需要电气条件、历史状态和单元级分析。']),
        ('未知值与不可观察情况',['先核查测试模式和屏蔽；不能直接删除故障目标。'])]):
        f.node(f'm{i}',90,y,1020,title,body,h=220,ts=36,bs=32);y+=280
    f.note(y+20,['超时或达到回溯限制，仅表示尚未获得结论。']);save(f)

    f=start(10,'fault_propagation','激活 n1 固定零并观察差异','a=b=1 激活目标；通过 c=0 的 OR 路径观察，也可利用 z。',1770)
    f.node('a',80,280,250,'a = 1',h=100)
    f.node('b',870,280,250,'b = 1',h=100)
    f.node('n1',450,450,300,'n1 = AND',['正常 1','故障 0'],h=210,bs=30)
    f.edge('a-input',f.port('a','E'),f.port('n1','N',.25),via=[(525,330)],meaning='a=1 是激活 n1/sa0 的必要条件')
    f.edge('b-input',f.port('b','W'),f.port('n1','N',.75),via=[(675,330)],meaning='b=1 是激活 n1/sa0 的必要条件')
    f.junction('n1-fanout',600,710)
    f.edge('n1-stem',f.port('n1','S'),'n1-fanout',arrow=False,meaning='n1 同时驱动 n2 与 z')
    f.node('n2',450,800,300,'n2 = OR',['c 取 0'],h=160,bs=30)
    f.node('z',900,775,230,'z = AND',['d = 1','可以观察'],h=210,ts=30,bs=28)
    f.edge('to-or','n1-fanout',f.port('n2','N'),meaning='差异进入 OR 的一个输入')
    f.edge('to-z','n1-fanout',f.port('z','N'),via=[(1015,710)],meaning='同一个 n1 干线也驱动 z 的一个输入')
    f.node('c',80,830,250,'c = 0',h=100)
    f.edge('c-input',f.port('c','E'),f.port('n2','W'),meaning='c=0 避免 OR 门遮蔽 n1 的差异')
    f.node('y',450,1150,300,'y = XOR',['可以观察'],h=160,bs=30)
    f.connect('or-to-y','n2','y',meaning='OR 的差异继续进入 XOR')
    f.node('d',80,1180,250,'d = 0 或 1',h=100,ts=30)
    f.junction('d-fanout',390,1230,color='teal')
    f.edge('d-stem',f.port('d','E'),'d-fanout',arrow=False,color='teal',meaning='d 是两个门共用的输入，不是独立变量')
    f.edge('d-to-y','d-fanout',f.port('y','W'),color='teal',meaning='XOR 的确定输入不会遮蔽差异')
    f.edge('d-to-z','d-fanout',f.port('z','E'),via=[(390,1460),(1160,1460),(1160,880)],color='teal',meaning='d 同时接 z 的第二输入；d=1 时 z 也能观察')
    f.note(1570,['测试立方体 110X 的两种补全均能检测 n1/sa0。','当 c=1 遮蔽上方路径时，仍可令 d=1 从 z 观察。','圆点表示真实分支；两处出现的 d 必须是同一个值。']);save(f)

    f=start(11,'search','ATPG 搜索与结果判定','选择目标、决定输入与逻辑验证分别进行。',2040)
    for id,y,t,b in [('fault',240,'选择目标故障',['规定模型、方向与合法测试条件']),('goal',590,'建立激活与传播目标',['选择故障需要的值和观察路径']),('decide',940,'决定输入并进行逻辑推导',['维持共享变量一致性，检查冲突']),('check',1290,'是否已经观察到真实差异',['未成功：继续或回溯；成功：保留向量'])]:f.node(id,250,y,700,t,b,h=210,bs=30)
    for a,b in [('fault','goal'),('goal','decide'),('decide','check')]:f.connect(a+'-'+b,a,b,meaning='按目标逐步约束并检验电路')
    f.node('backtrack',250,1680,340,'未成功',['撤销或另选输入'],h=180,ts=32,bs=28,accent='orange')
    f.node('detected',610,1680,340,'成功',['独立故障模拟'],h=180,ts=32,bs=28,accent='teal')
    f.edge('retry',f.port('check','S',.25),f.port('backtrack','N'),via=[(425,1590),(420,1590)],color='orange',meaning='未发现有效检测时继续搜索或回溯')
    f.edge('success',f.port('check','S',.75),f.port('detected','N'),via=[(775,1590),(780,1590)],color='teal',meaning='观察到正常与故障差异后保存并验证')
    f.edge('loop',f.port('backtrack','W'),f.port('decide','W'),via=[(130,1770),(130,1045)],color='orange',meaning='还有合法分支时尝试另一项输入决定')
    f.note(1940,['穷尽全部合法分支，才可能证明当前模型不可测试。','达到时间或回溯限制必须单列，不得当作不可测试。']);save(f)

    f=start(12,'sat_miter','SAT 的正常与故障双电路','同一组输入进入两份模型；只在指定位置注入故障。',1620)
    f.node('input',400,240,400,'共同输入 x',['加上合法模式限制'],h=190)
    f.junction('split',600,510)
    f.edge('shared',f.port('input','S'),'split',arrow=False,meaning='正常与故障模型共享相同输入变量')
    f.node('good',70,650,460,'正常电路 C(x)',['每个门满足正常关系'],h=210)
    f.node('bad',670,650,460,'故障电路 Cf(x)',['只替换指定故障位置'],h=210,accent='orange')
    f.edge('good-input','split',f.port('good','N'),via=[(300,510)],meaning='共同输入进入正常模型')
    f.edge('bad-input','split',f.port('bad','N'),via=[(900,510)],meaning='共同输入进入故障模型')
    f.node('compare',400,1120,400,'比较可观察输出',['逐位 XOR，再做 OR'],h=190,bs=30)
    f.edge('good-output',f.port('good','S'),f.port('compare','N',.25),via=[(300,1010),(500,1010)],meaning='正常输出参与逐位比较')
    f.edge('bad-output',f.port('bad','S'),f.port('compare','N',.75),via=[(900,1010),(700,1010)],color='orange',meaning='故障输出参与逐位比较')
    f.node('require',400,1450,400,'要求至少一位不同',h=110,ts=32)
    f.connect('detection','compare','require',meaning='差异条件为真就是一个故障检测向量');save(f)

    f=start(13,'compression','输入解压缩与响应压缩','编码约束和错误混叠是两端不同的正确性问题。',1640)
    y=chain(f,[('外部输入变量或种子',['少量传输数据，不是任意大向量的无损压缩']),('输入解压缩器',['根据连接关系生成多条链的输入位']),('并行扫描链',['链内移位；按真实协议捕获响应']),('响应压缩器',['减少输出数据，同时可能出现未知值与错误抵消']),('外部比较或片上签名检查',['必须使用相同压缩状态、周期和屏蔽规则'])],x=120,w=960,gap=80)
    save(f)

    f=start(14,'unknowns','两种 X 的意义完全不同','输入自由位可以优化；未知响应可能破坏可观察性。',1370)
    f.node('cube',80,260,1040,'输入立方体：110X',['X 表示还可以选择 0 或 1','验证补全 1100 与 1101 都保留目标故障检测'],h=280,accent='teal')
    f.node('unknown',80,690,1040,'捕获响应：10X1',['X 表示当前模型无法确定真实返回值','进入 XOR 压缩可能污染其他观察信息'],h=280,accent='orange')
    f.note(1130,['屏蔽未知响应会同时减少某些错误的可观察性。','不能把真实失败位随意标记为 X 来提高报告数字。','输入未规定位与响应未知值必须在程序与报告中分开。']);save(f)

    f=start(15,'power','移位与捕获的不同电气风险','活动次数只是一种代理，不能直接当作瓦特或实际压降。',1520)
    y=chain(f,[('大量移位周期',['链和功能逻辑可能持续翻转','关注累计能量、平均功率与温升']),('短时间高速捕获',['许多节点同时变化，时间窗口短','关注瞬时电流与局部电源电压下降']),('卸出与下一向量装入',['响应比较与下一状态准备重叠','向量排序和 X 填充改变活动分布'])],x=150,w=900,gap=100)
    f.node('limit',80,y+20,1040,'并发核必须逐阶段检查',['数据通道、捕获时钟、局部电气与全局功率同时受限'],h=210,ts=36,bs=30,accent='orange')
    f.note(y+315,['降低移位频率并不能自动修复同沿保持时间违例。']);save(f)

    f=start(16,'testpoints','控制点与观察点','新增硬件必须保持功能模式正确，并重新计算代价。',1700)
    f.t(64,240,'控制点：改变测试时的可控制性',size=36,weight=700)
    f.node('function',70,340,300,'功能信号',h=130)
    f.node('control',450,340,300,'测试选择器',h=130,ts=34)
    f.node('downstream',830,340,300,'后续逻辑',h=130)
    f.edge('functional',f.port('function','E'),f.port('control','W'),meaning='正常信号进入控制点')
    f.edge('controlled',f.port('control','E'),f.port('downstream','W'),meaning='功能模式透明传递，测试模式按设计控制')
    f.node('test',450,640,300,'测试控制',h=120)
    f.edge('test-select',f.port('test','N'),f.port('control','S'),color='orange',dashed=True,meaning='测试控制决定是否强制或选择内部节点')
    f.t(64,900,'观察点：在错误被遮蔽之前保存',size=36,weight=700)
    f.node('internal',70,1010,400,'内部响应',h=150)
    f.node('normal',730,1010,400,'原后续逻辑',h=150)
    f.junction('observe',600,1085,color='teal')
    f.edge('original',f.port('internal','E'),'observe',arrow=False,color='teal',meaning='原功能连接产生观察分支')
    f.edge('normal-flow','observe',f.port('normal','W'),color='teal',meaning='原来的功能数据继续传递')
    f.node('observer',400,1380,400,'扫描观察寄存器',['新增或按规则复用'],h=190)
    f.edge('capture-observe','observe',f.port('observer','N'),color='teal',meaning='分支提供额外观察，需检查新增扇出与捕获规则')
    f.note(1660,['减少新增触发器不等于没有选择器、布线或时序代价。']);save(f)

    f=start(17,'diagnosis','检测与唯一定位并不相同','32 个故障都能检测，不代表 32 个故障都有不同响应。',1610)
    y=chain(f,[('保存准确失败信息',['模式、链版本、向量、周期、通道、期望与实际值']),('先核查扫描和协议',['链顺序、复位、时钟或比较窗口错误也会报失败']),('匹配相同条件下的故障字典',['只能保留能够解释观测结果的候选']),('必要时增加诊断向量',['选择能分开候选响应的条件，不只是最多检测'])],x=100,w=1000,gap=85)
    f.node('classes',100,y+10,1000,'本卷穷举例子',['完整双输出响应：18 类','每条向量只留失败标志：16 类'],h=230,accent='orange')
    save(f)

    f=start(18,'validation','从设计到制造的检查顺序','任何结构或协议变化都要判断哪些已有验证结果失效。',2150)
    chain(f,[('输入版本与模式核对',['门级电路、库、时钟、复位、电源与故障清单']),('功能与扫描结构验证',['正常功能等价；实际链序与移位行为正确']),('捕获与时序检查',['OCC、门控、复位；建立与保持时间']),('ATPG 与独立故障模拟',['向量可施加；覆盖分母和未检测类别清楚']),('测试格式与无故障回放',['首条装入、重叠卸出、末次卸出和比较窗口']),('制造执行与诊断',['保留条件和版本；根据真实失败收集进一步证据'])],x=120,w=960,gap=80)
    save(f)

    f=start(19,'research_layers','近期研究改变的不是同一层','比较结果之前，先固定故障、结构、资源与评价指标。',1760)
    rows=[('硬件与逻辑结构',['LITE：资源复用；测试点与扫描选择','链重排与 E-ATPG：结构或表示的选择']),('生成与搜索',['SmartATPG / InF-ATPG：学习搜索决策','PastATPG：部分赋值；DEFT：连续优化']),('评估与执行',['故障模拟的并行与事件处理','压缩配置、数据传输和功率限制']),('工具工作流',['代理解释报告并提出实验','确定性工具验证，受控采纳修改'])]
    for i,(t,b) in enumerate(rows):f.node(f'layer{i}',90,245+i*340,1020,t,b,h=250,bs=32,accent=['blue','teal','orange','purple'][i])
    f.note(1660,['减少回溯 ≠ 同比减少运行时间 ≠ 缩短芯片测试时间。']);save(f)

    (ROOT/'assets/figures_manifest.json').write_text(json.dumps({'figures':FIGS,'count':len(FIGS)},ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print('Generated',len(FIGS),'editable SVG figures.')
if __name__=='__main__':main()
