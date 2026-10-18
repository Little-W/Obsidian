#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Fifteen precisely routed systems diagrams; synthetic values come from results.json."""
from svg_geometry import Figure

def flow(stem,title,subtitle,cards,notes,*,x=100,w=1000,pitch=270):
    d=Figure(stem,title,subtitle,220+len(cards)*pitch+160)
    for i,(t,b,c) in enumerate(cards):
        d.node(f'step{i}',x,220+i*pitch,w,t,b,accent=c,h=190,bs=32)
        if i:d.connect(f'sequence{i}',f'step{i-1}',f'step{i}',color='muted',meaning='上一阶段完成并满足条件后进入下一阶段')
    d.note(220+len(cards)*pitch+10,notes)
    return d

def s01(data):
    d=Figure('01_system','图 01  MBIST 系统的完整功能',
             '命令、期望信息、实际读值、故障信息和修复配置分别连接。',1750)
    d.node('manager',160,220,880,'顶层测试管理',['模式选择、启动与完成、正常访问协调'],h=160)
    d.node('execute',160,480,880,'算法执行与并发安排',['产生地址、命令、数据图案和等待周期'],accent='teal',h=160)
    d.connect('manager-execute','manager','execute',meaning='启动、模式与执行控制')
    d.node('interface',100,760,480,'存储器接口',['端口切换与时序适配'],h=160)
    d.node('expect',710,760,390,'期望信息对应',['保存并延迟期望信息'],h=160,bs=30)
    d.edge('execute-interface',d.port('execute','S',180/880),d.port('interface','N'),meaning='地址、读写命令与写入数据')
    d.edge('execute-expect',d.port('execute','S',745/880),d.port('expect','N'),meaning='本次读请求的期望信息')
    d.t(372,700,'命令与数据',size=30,color='blue')
    d.t(937,700,'期望信息',size=30,color='blue')
    d.node('array',100,1040,480,'存储阵列',['实际执行读写'],accent='teal',h=160)
    d.node('compare',710,1040,390,'结果比较',['逐位检查读数据'],h=160)
    d.connect('interface-array','interface','array',meaning='实际存储器接口信号')
    d.connect('expect-compare','expect','compare',meaning='按读延迟对应的期望值')
    d.edge('array-compare',d.port('array','E'),d.port('compare','W'),meaning='存储器的实际读出数据')
    d.t(645,1080,'读出',size=30,color='blue',anchor='middle')
    d.node('record',710,1320,390,'故障记录',['实例、地址与错误位','保存供诊断分析'],accent='red',h=210,bs=30)
    d.node('repair',100,1320,480,'冗余分析与修复',['选择备用资源并生成配置','配置生效后重新测试'],accent='orange',h=210,bs=30)
    d.connect('compare-record','compare','record',color='red',meaning='比较失败时记录故障信息')
    d.t(937,1260,'不一致',size=30,color='red')
    d.edge('record-repair',d.port('record','W'),d.port('repair','E'),color='orange',meaning='故障位置及错误位供冗余分析')
    d.t(645,1385,'故障',size=30,color='orange',anchor='middle')
    d.edge('repair-array',d.port('repair','N'),d.port('array','S'),color='orange',meaning='合法修复配置控制备用资源替换')
    d.t(372,1260,'修复配置',size=30,color='orange')
    d.note(1620,['时钟、电源、温度、故障记录容量与正常功能恢复需要共同检查。',
                 '顶层状态汇总、实际修复配置接口及复测控制信号从略。'])
    return d

def s02(data):
    d=Figure('02_group_levels','图 14  四种“组”回答不同问题',
             '四个概念分别说明相容性、硬件归属、同步执行和当前活动状态。',1360)
    cards=[('1  属性相容类别','哪些实例有机会共享测试硬件？','blue'),
           ('2  控制器共享组','哪些实例由同一个控制器管理？','teal'),
           ('3  同步测试步骤','哪些实例以相同操作进度执行？','orange'),
           ('4  芯片级执行集合','当前时刻，哪些测试任务实际在运行？','purple')]
    for i,(t,b,c) in enumerate(cards):d.node(f'level{i}',100,220+i*240,1000,t,[b],accent=c,h=185)
    d.note(1220,['这些是不同划分维度，不应画成固定的程序执行次序。',
                 '共享控制器不等于同时测试；同属一类也不代表必须放入同一组。'])
    return d

def s03(data):
    d=Figure('03_controller_modes','图 03  控制器的三种执行方式',
             '示意时间条只解释执行关系；比较方案时必须固定硬件能力。',1580)
    specs=[('组内依次执行','A 完成后，B 才能开始','时间约为各成员测试时间之和','blue'),
           ('组内同步执行','A 与 B 接收同一操作进度','需兼容地址、数据和返回时序','teal'),
           ('共享管理，局部独立','A 与 B 各自保存执行进度','允许错开启动，但局部硬件更多','orange')]
    for i,(title,sub,note,c) in enumerate(specs):
        y=220+i*395;id=f'mode{i}'
        d.rect(id,80,y,1040,365,fill='pale',stroke=c,kind='group')
        d.t(112,y+46,title,size=36,weight=700,color=c,owner=id,padding=20)
        d.t(112,y+101,sub,size=32,owner=id,padding=20)
        if i==0:
            for j,(x,w,label) in enumerate([(280,320,'A'),(600,320,'B')]):
                bid=f'bar{i}-{j}';d.rect(bid,x,y+155,w,80,fill='zero',stroke=c,kind='bar',radius=4)
                d.t(x+w/2,y+195,label,size=34,weight=700,anchor='middle',owner=bid,padding=12)
        else:
            for j,label in enumerate(['A','B']):
                yy=y+152+j*76;x=280+(130 if i==2 and j else 0);w=620 if i==1 else 470
                d.t(224,yy+25,label,size=32,anchor='middle',owner=id,padding=20)
                d.rect(f'bar{i}-{j}',x,yy,w,50,fill='pale_teal' if i==1 else 'pale_orange',stroke=c,kind='bar',radius=4)
        d.t(112,y+320,note,size=30,color='muted',owner=id,padding=20)
    d.note(1475,['同步执行不一定只需“最长成员的时间”；物理地址循环不同会增加步骤。'])
    return d

def s04(data):
    d=Figure('04_constraints','图 16  两两关系与整个集合的约束',
             '局部相容或相邻成员合法，不能代替对整个分组的检查。',1260)
    d.node('limit',80,220,1040,'两两距离上限为 5',h=104)
    for id,x,title,pos in [('A',100,'A','x = 0'),('B',520,'B','x = 4'),('C',940,'C','x = 8')]:
        d.node(id,x,380,160,title,[pos],h=160,bs=30)
    d.edge('A-B',d.port('A','E'),d.port('B','W'),color='teal',arrow=False,meaning='A 与 B 的距离为 4，满足限制')
    d.edge('B-C',d.port('B','E'),d.port('C','W'),color='teal',arrow=False,meaning='B 与 C 的距离为 4，满足限制')
    d.t(390,414,'距离 4',size=30,color='teal',anchor='middle');d.t(810,414,'距离 4',size=30,color='teal',anchor='middle')
    d.edge('A-C',d.port('A','S'),d.port('C','S'),via=[(180,640),(1020,640)],color='red',arrow=False,meaning='A 与 C 的距离为 8，违反两两距离限制')
    d.t(600,696,'A 与 C 距离为 8，不能同组',size=36,color='red',weight=700,anchor='middle')
    d.node('power',80,790,1040,'功率还需要检查整个集合',['3 个任务各需 4 mW，总功率上限为 10 mW。',
                   '任意两个同时运行：8 mW，合法。','全部同时运行：12 mW，不合法。'],accent='orange',h=260)
    d.note(1130,['聚类之后仍要检查所有硬性限制。',
                 '冲突图能够表达两两关系，但不能单独表达所有资源总量约束。'])
    return d

def s05(data):
    d=Figure('05_group_example','图 19  六个存储器的分组算例',
             '坐标与功率均为教学设定，不代表实际芯片测量。',1320)
    d.node('rules',80,220,1040,'明确硬件能力和资源规则',['组内依次执行；每组最多 3 个实例。',
                '两两距离不超过 6；不同属性类别不能同组。'],h=210)
    d.rect('S1',80,490,500,370,fill='pale',stroke='blue',kind='group')
    d.t(330,542,'S1：四个实例',size=36,weight=700,anchor='middle',owner='S1',padding=24)
    for i,(label,pos) in enumerate([('A',0),('B',2),('C',4),('D',6)]):
        x=110+(i%2)*230;y=605+(i//2)*115
        d.node(label,x,y,200,f'{label} · x = {pos}',accent='blue',h=84,ts=30)
    d.rect('S2',640,490,480,370,fill='pale_teal',stroke='teal',kind='group')
    d.t(880,542,'S2：两个实例',size=36,weight=700,anchor='middle',owner='S2',padding=24)
    for i,(label,pos) in enumerate([('E',14),('F',16)]):d.node(label,670+i*225,630,195,label,[f'x = {pos}'],accent='teal',h=160,bs=30)
    d.node('solution',80,930,1040,'一种最少控制器方案',['控制器 0：A、C、D；控制器 1：B。','控制器 2：E、F。'],accent='orange',h=210)
    d.note(1220,['S1 至少需要 2 组，S2 至少需要 1 组，因此总组数下界为 3。',
                 '存在合法的 3 组方案，说明该例的最少组数确实为 3。'])
    return d

def s06(data):
    d=Figure('06_schedule','图 20  同样三个组，测试时间可以不同',
             '整数时间教学模型：一种在 17 μs 内完成的最优安排。',1330)
    runs=data['serial_controller_scheduling']['best_among_minimum_count_partitions']['runs']
    x0=280;scale=47
    for k in range(3):
        y=285+k*150
        d.t(80,y+43,f'控制器 {k}',size=32,weight=700)
        d.rect(f'lane{k}',x0,y,17*scale,86,fill='pale',stroke='grid',radius=0,kind='group')
    for i,r in enumerate(runs):
        y=285+r['controller']*150;x=x0+r['start']*scale;w=(r['end']-r['start'])*scale
        c=['blue','teal','orange'][r['controller']];id='run'+str(i)
        d.rect(id,x,y,w,86,fill=['zero','pale_teal','pale_orange'][r['controller']],stroke=c,kind='bar',radius=0)
        d.t(x+w/2,y+43,r['memory'],size=38,weight=700,anchor='middle',color=c,owner=id,padding=14)
    d.rule('time-axis',[(x0,745),(x0+17*scale,745)],color='muted')
    for t in [0,4,8,12,17]:
        x=x0+t*scale;d.rule('tick'+str(t),[(x,745),(x,756)],color='muted');d.t(x,793,str(t),size=30,anchor='middle',color='muted')
    d.t(1079,850,'时间 / μs',size=30,anchor='end',color='muted')
    d.node('constraints',80,925,1040,'每个时间区间都满足约束',['同时最多 2 个活动控制器。','活动功率最高为 8 mW；同组任务不重叠。'],accent='teal',h=210)
    d.note(1215,['另一种三组方案 {A,B,C}、{D}、{E,F} 至少需要 19 μs。',
                 '控制器数量相同，不代表测试完成时间相同。'])
    return d

def s07(data):
    return flow('07_power_flow','图 15  从粗略指标到电气验证','模型越接近实际执行，所需输入与验证条件也越完整。',[
        ('早期相对指标',['容量、端口、宏类型与库信息摘要'],'blue'),
        ('命令与阶段能量',['读写、数据图案、时钟、接口及比较活动'],'teal'),
        ('时间相关功率曲线',['实际命令次序、门级活动和宏功率模型'],'orange'),
        ('电源网络与温度检查',['物理位置、封装、供电和散热结构'],'purple')],
        ['相对指标不是瓦特；平均功率不能代替局部峰值功率。'])

def s08(data):
    d=Figure('08_phase_power','图 18  利用互补的阶段功率',
             '教学例子：总功率上限为 8 mW；两个任务可同时在 6 μs 内结束。',1830)
    x0=260;sx=137;sy=22
    profiles=[('任务 A',[(0,2,6),(2,6,2)],'blue','zero'),
              ('任务 B',[(0,4,2),(4,6,6)],'teal','pale_teal'),
              ('功率之和',[(0,2,8),(2,4,4),(4,6,8)],'orange','pale_orange')]
    for i,(label,parts,c,fill) in enumerate(profiles):
        y=220+i*390;bottom=y+245
        d.t(80,y+28,label,size=34,weight=700,color=c)
        d.t(80,y+82,'单位：mW',size=30,color='muted')
        for j,(a,b,p) in enumerate(parts):
            d.rect(f'phase{i}-{j}',x0+a*sx,bottom-p*sy,(b-a)*sx,p*sy,fill=fill,stroke=c,kind='bar',radius=0)
            d.t(x0+(a+b)/2*sx,bottom-p*sy-32,str(p),size=32,weight=700,color=c,anchor='middle')
        d.rule('axis'+str(i),[(x0,bottom),(x0+6*sx,bottom)],color='muted')
        for t in [0,2,4,6]:
            x=x0+t*sx;d.rule(f'tick{i}-{t}',[(x,bottom),(x,bottom+10)],color='muted');d.t(x,bottom+45,str(t),size=28,anchor='middle',color='muted')
        d.t(x0+6*sx,bottom+100,'时间 / μs',size=30,anchor='end',color='muted')
    d.node('summary',80,1420,1040,'顺序执行 12 μs → 重叠执行 6 μs',['两种安排的任务总能量均为 40 nJ。',
           '节省的是测试时间，不是把任务能量减半。'],accent='orange',h=210)
    d.note(1705,['图中忽略背景功率和启动开销；条形高度与标注数值一致。',
                 '启动瞬间合法仍不够，还需要检查所有后续阶段的总功率。'])
    return d

def s09(data):
    d=Figure('09_thermal','图 17  三维芯片的局部温度约束','全局功率相同，活动的位置不同，局部温度仍可能不同。',1360)
    for i,cx in enumerate([320,880]):
        c='red' if i==0 else 'teal';d.t(cx,242,'垂直集中活动' if i==0 else '分散或错开活动',size=34,color=c,anchor='middle',weight=700)
        for layer in range(3):
            x=cx-240;y=315+layer*195;id=f'layer{i}-{layer}'
            d.rect(id,x,y,480,145,fill='pale',stroke='grid',kind='group')
            d.t(x+24,y+43,f'层 {layer+1}',size=30,color='muted',owner=id,padding=20)
            for k in range(3):
                active=k==1 if i==0 else k==layer;bid=f'bank{i}-{layer}-{k}'
                bx=x+135+k*105;by=y+30
                d.rect(bid,bx,by,82,88,fill=('pale_red' if i==0 else 'pale_teal') if active else 'paper',stroke=c if active else 'grid',kind='cell',radius=6)
                if active:d.t(bx+41,by+44,'开',size=30,color=c,anchor='middle',owner=bid,padding=12)
    d.node('history',80,985,1040,'温度具有历史状态',['刚结束高功率测试的区域，不能视为已经冷却。',
          '活动单元数量只是近似，还需要检查热模型。'],accent='orange',h=210)
    d.note(1280,['示意图不是温度仿真结果，也不表示实际温度数值。'])
    return d

def s10(data):
    d=Figure('10_adaptive','图 21  自适应测试的条件与返回路径',
             '根据观测选择动作，但不能把“暂未发现失败”当作“全部通过”。',1850)
    d.node('execute',120,220,960,'执行下一项已验证测试',['保持规定的操作次序、时钟与观察条件'],h=160)
    d.node('observe',120,480,960,'检查结果与完成进度',['已经失败，或尚未发现失败'],accent='teal',h=160)
    d.connect('execute-observe','execute','observe',meaning='完成该项测试后评估结果')
    d.junction('branch',600,710)
    d.edge('observe-branch',d.port('observe','S'),'branch',arrow=False,meaning='结果分支的公共连接点')
    d.node('failure',80,830,480,'失败处理',['需要诊断：继续收集信息','允许修复：分析后复测','无需诊断：可结束筛选'],accent='red',h=260,bs=30)
    d.node('complete',680,830,440,'检查完成条件',['必要测试是否全部完成？','未完成：继续执行测试','已完成：进入结果判定'],accent='teal',h=260,bs=30)
    d.edge('branch-failure','branch',d.port('failure','N'),via=[(320,710)],color='red',meaning='已观察到测试失败')
    d.edge('branch-complete','branch',d.port('complete','N'),via=[(900,710)],color='teal',meaning='尚未发现失败，仍需检查完成条件')
    d.t(285,773,'已发现失败',size=30,color='red',anchor='end')
    d.t(935,773,'未发现失败',size=30,color='teal')
    d.edge('continue',d.port('complete','E'),d.port('execute','E'),via=[(1160,960),(1160,300)],color='orange',meaning='必要测试未完成时返回，禁止提前宣布通过')
    d.t(1115,428,'未完成：返回',size=30,color='orange',anchor='end')
    d.node('decision',680,1210,440,'按既定规则判定',accent='teal',h=104,ts=34)
    d.connect('complete-decision','complete','decision',color='teal',meaning='仅在全部必要测试完成后判定')
    d.t(935,1150,'已完成',size=30,color='teal')
    d.node('allowed',80,1390,1040,'可以自适应调整的动作',['调整已验证测试块的次序和合法启动时刻。',
          '选择附加诊断，或者使用可用的空闲时间。','提前停止筛选、提前结束分析、提前宣布通过是不同决策。'],accent='orange',h=260,bs=30)
    d.note(1735,['失败处理不是“直接通过”的路径；修复之后仍需要规定的复测。'])
    return d

def s11(data):
    return flow('11_online','图 22  保留数据的短测试过程','下图为正常完成路径；每一步满足条件后才能进入下一步。',[
        ('获得许可并隔离正常访问',['等待已接受事务完成，阻止新的冲突访问。'],'blue'),
        ('保存并保护原数据',['暂存位置、地址和数据本身都必须可靠。'],'teal'),
        ('执行规定的测试片段',['保持必要的操作次序和时间关系。'],'orange'),
        ('恢复数据并检查',['不仅写回原数据，还需要处理恢复失败。'],'teal'),
        ('释放接口并更新测试进度',['检查最长占用时间与最长未测试时间。'],'blue')],
        ['发生异常时进入明确的处理状态，不能跳到最后一步报告成功。',
         '非破坏性测试仍会占用接口，也不能在任意位置中断。'])

def s12(data):
    d=Figure('12_diagnosis','图 04  正确定位需要响应时间对应',
             '读取延迟为两拍时，返回地址不等于当前正在发出的地址。',1420)
    rows=[('周期','当前发出的请求','返回结果及对应地址'),('t','读取地址 17','地址 17 的结果尚未返回'),
          ('t + 1','读取地址 18','地址 17 的结果尚未返回'),('t + 2','读取地址 19','地址 17 的数据返回')]
    widths=[170,350,520]
    for r,row in enumerate(rows):
        x=80;y=250+r*110
        for c,txt in enumerate(row):
            id=f'table-{r}-{c}';d.rect(id,x,y,widths[c],110,fill='zero' if r==0 else 'paper',stroke='grid',radius=0,kind='cell')
            d.t(x+widths[c]/2,y+55,txt,size=28 if r==0 else 30,weight=700 if r==0 else 400,anchor='middle',owner=id,padding=20);x+=widths[c]
    d.node('expected',80,785,1040,'随请求保存的期望信息',['逻辑地址、期望数据、操作阶段和有效信号。','这些信息与返回数据共同进入比较和故障记录。'],accent='teal',h=210)
    d.node('record',80,1110,1040,'正确的失败记录应关联地址 17',['记录当前地址 19，会导致后续修复选择错误。','仅验证 fail = 1，不足以证明诊断结果正确。'],accent='orange',h=210)
    d.connect('expected-record','expected','record',color='teal',meaning='用返回请求的地址而非当前请求地址生成故障记录')
    d.note(1390,['例子假设接口可以每拍接受一个读请求，并在两拍后返回结果。'])
    return d

def s13(data):
    d=Figure('13_repair','图 24  备用行列的选择反例',
             '故障最多的一行，不一定应当优先消耗唯一的备用行。',1410)
    d.t(600,235,'可用资源：1 条备用行 + 2 条备用列',size=36,weight=700,anchor='middle')
    x0=220;y0=370;cell=140;faults={tuple(p) for p in data['repair']['faults']}
    for c in range(3):d.t(x0+(c+.5)*cell,313,f'列 {c}',size=32,anchor='middle',color='teal' if c<2 else 'ink')
    for r in range(3):
        d.t(170,y0+(r+.5)*cell,f'行 {r}',size=32,anchor='end',color='orange' if r==2 else 'ink')
        for c in range(3):
            x=x0+c*cell;y=y0+r*cell
            d.rect(f'cell{r}-{c}',x,y,cell,cell,fill='pale_orange' if r==2 else 'pale_teal' if c<2 else 'paper',stroke='grid',radius=0,kind='cell')
            if (r,c) in faults:
                d.rule(f'x{r}-{c}-a',[(x+48,y+48),(x+92,y+92)],color='red',width=7,kind='symbol')
                d.rule(f'x{r}-{c}-b',[(x+92,y+48),(x+48,y+92)],color='red',width=7,kind='symbol')
    d.node('exact',760,370,360,'精确解',['替换行 2','替换列 0、1'],accent='teal',h=210,bs=30)
    d.node('greedy',760,630,360,'贪心反例',['相同数量时优先选行','先耗尽唯一备用行'],accent='red',h=210,bs=28)
    d.node('explain',80,950,1040,'先选行 0，会发生什么？',['剩下故障位置 (1,0)、(1,1)、(2,2)。',
          '这时需要 3 条备用列，但实际只剩 2 条。','不是阵列不可修复，而是这次选择方法失败。'],accent='orange',h=260)
    d.note(1290,['红叉表示已知故障；着色行列表示一种可行替换方案。',
                 '行与列的备用资源数量必须分别限制。'])
    return d

def s14(data):
    d=Figure('14_fault_buffers','图 23  故障信息也会限制并发',
             '实线为故障信息流；虚线为结构检查；实心点表示相连。',1540)
    for i,title in enumerate(['存储体 A','存储体 B']):
        x=80+560*i
        d.node(f'memory{i}',x,220,480,title,['局部比较产生故障记录'],h=160)
        d.node(f'buffer{i}',x,500,480,'局部顺序存储',['缓冲地址与错误数据位'],accent='teal',h=160)
        d.connect(f'local{i}',f'memory{i}',f'buffer{i}',meaning='该存储体的故障记录进入其局部缓冲')
    d.junction('merge',600,760)
    d.edge('buffer0-merge',d.port('buffer0','S'),'merge',via=[(320,760)],arrow=False,meaning='局部缓冲 A 交给共享分析')
    d.edge('buffer1-merge',d.port('buffer1','S'),'merge',via=[(880,760)],arrow=False,meaning='局部缓冲 B 交给共享分析')
    d.node('analysis',80,860,1040,'共享分类与冗余分析',['判断重复故障、维护候选资源并生成修复决策'],accent='orange',h=180)
    d.edge('merge-analysis','merge',d.port('analysis','N'),color='orange',meaning='明确合并后的故障信息流')
    d.node('capacity',80,1170,1040,'检查记录容量与吞吐率',['记录溢出不能被误认为“没有故障”。',
          '若通过暂停消除拥塞，必须确认暂停不改变故障触发条件。'],accent='red',h=210,bs=30)
    d.connect('analysis-capacity','analysis','capacity',color='red',dashed=True,meaning='检查关系：不是额外的数据处理硬件级')
    d.t(635,1105,'结构检查',size=30,color='red')
    d.note(1465,['共享分析单元的带宽可能限制允许同时测试的存储器数量。'])
    return d

def s15(data):
    cards=[('输入核查与实例清单',['宏描述、时钟电源、接口、修复资源与物理位置'],'blue'),
           ('分组与调度优化',['明确硬件能力，保留满足约束的候选方案'],'teal'),
           ('厂商工具适配与实际插入',['按已安装工具版本，生成受支持的配置'],'orange'),
           ('功能、故障与时间检查',['比较实际结构、地址覆盖与故障定位结果'],'blue'),
           ('物理、功率与温度验证',['不满足要求时，修正模型并重新求解'],'purple')]
    d=flow('15_flow','图 25  优化方案怎样进入实际工具','优化器提出结构，工具生成硬件，独立检查确认结果。',cards,
           ['教学 JSON 不是厂商原生命令；未实际运行工具，就不能声称工具通过。'],x=100,w=960,pitch=270)
    d.edge('revise',d.port('step4','E'),d.port('step1','E'),via=[(1160,1395),(1160,585)],color='orange',meaning='物理、电气结果不满足要求时返回分组与调度优化')
    d.t(1105,975,'修正',size=28,color='orange',anchor='middle')
    d.t(1105,1025,'重算',size=28,color='orange',anchor='middle')
    return d

BUILDERS=[s01,s02,s03,s04,s05,s06,s07,s08,s09,s10,s11,s12,s13,s14,s15]
