#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Ten deterministic March figures. Edit node positions/content here, then validate."""
from svg_geometry import Figure, W

CLASSIC=[('MATS',4),('MATS+',5),('MATS++',6),('March X',6),('March Y',8),
         ('March C−',10),('March C',11),('March AZ',13),('March LR',14),
         ('March MSS',18),('March SS',22),('March AB',22),('March RAW',26)]
COMPLEX=[('March C−',10),('March AZ (2025)',13),('March MSS',18),('March AB',22),
         ('March RAW',26),('MT-3CCF (2024)',37),('MT-4CCF (2024)',73),
         ('MT-NPSF (2025)',81),('MT-ENPSF (2025)',177)]

def m01():
    d=Figure('01_mbist结构','图 02  March 算法在 MBIST 中的执行位置',
             '每条连线只表示一种信息；期望信息与实际读数据分别到达比较单元。',1770)
    d.node('controller',80,220,1040,'测试控制器',['March 元素、地址方向、读写步骤与终止条件'])
    d.node('address',80,510,460,'地址与命令产生',['递增、递减或特殊地址','产生读写使能'],accent='teal')
    d.node('data',700,510,420,'测试数据产生',['全零、全一或数据图案','同时确定期望读值'],accent='teal')
    d.edge('control-address',d.port('controller','S',230/1040),d.port('address','N'),meaning='地址方向及读写步骤')
    d.edge('control-data',d.port('controller','S',830/1040),d.port('data','N'),meaning='数据图案与期望值规则')
    d.t(342,445,'地址与命令控制',size=30,color='blue')
    d.t(940,445,'图案控制',size=30,color='blue')
    d.node('memory',80,870,460,'待测存储器',['字线、位线和存储单元','实际执行读写'],accent='orange')
    d.node('expected',700,870,420,'期望信息延迟单元',['保存地址与期望值','匹配实际读取延迟'],accent='teal')
    d.connect('address-memory','address','memory',meaning='地址、读使能、写使能')
    d.t(342,795,'地址与命令',size=30,color='blue')
    d.connect('data-expected','data','expected',color='teal',meaning='期望值及其对应的有效信息')
    d.t(940,795,'期望信息',size=30,color='teal')
    d.edge('data-memory',d.port('data','W'),d.port('memory','E'),via=[(620,615),(620,975)],color='teal',meaning='实际写入数据')
    d.t(590,788,'写入',size=28,anchor='end',color='teal')
    d.t(590,830,'数据',size=28,anchor='end',color='teal')
    d.node('compare',80,1220,1040,'读出比较单元',['实际读数据与同一次读请求的期望值逐位比较'],accent='red')
    d.edge('memory-compare',d.port('memory','S'),d.port('compare','N',230/1040),meaning='实际读出数据')
    d.edge('expected-compare',d.port('expected','S'),d.port('compare','N',830/1040),color='teal',meaning='经过延迟对齐的期望信息')
    d.t(342,1150,'实际读出值',size=30,color='blue')
    d.t(940,1150,'对应期望值',size=30,color='teal')
    d.node('failure',80,1480,1040,'故障信息记录',['存储器、地址、步骤、错误数据位与实际读值'],accent='red')
    d.connect('compare-failure','compare','failure',color='red',meaning='比较不一致时写入故障记录')
    d.t(635,1430,'比较不一致',size=30,color='red')
    d.note(1705,['正常访问与测试访问的选择电路从略；箭头终点均为接收模块的连接点。'])
    return d

def m02():
    d=Figure('02故障模型','图 05  常见存储器故障模型',
             '现象示例只帮助理解；正式测试还需要规定地址、时序与观察条件。',1370)
    data=[('固定值故障',['单元只能保持为 0','写入 1 也无法改变'],['写 1 → 读取仍为 0'],'red'),
          ('状态转换故障',['从 0 写成 1 的','状态转换失败'],['0 → 写 1 → 仍为 0'],'orange'),
          ('读出破坏故障',['读取操作改变了','内部存储内容'],['存储 1 → 读取','内部内容变为 0'],'red'),
          ('写入干扰故障',['再次写入相同数值','却破坏了原有内容'],['0 → 再写 0 → 读出 1'],'orange'),
          ('耦合故障',['一个单元的动作','影响另一个单元'],['激励单元变化','受害单元发生异常'],'teal'),
          ('数据保持故障',['保持一段时间后','存储内容发生丢失'],['写 1 → 等待 Δt','读取却得到 0'],'blue')]
    for i,(title,body,ops,color) in enumerate(data):
        x=80+(i%2)*560;y=220+(i//2)*350;id=f'fault-{i}'
        d.node(id,x,y,480,title,body,accent=color,h=325)
        d.lines(x+240,y+231,ops,gap=44,size=30,color=color,anchor='middle',owner=id,padding=20)
    d.note(1315,['这些例子不是完整的故障原型集合；不同故障可能需要不同测试算法。'])
    return d

def m03():
    d=Figure('03_March_C负序列','图 07  March C− 的六次完整地址遍历',
             '同一地址完成该阶段的全部读写操作之后，才访问下一个地址。',1440)
    xs=[135,320,690,1050]
    for x,t in zip(xs,['阶段','地址方向','逐地址读写操作','操作数']):d.t(x,239,t,size=30,weight=700,anchor='middle')
    rows=[('M0','任意方向','w0','全零','1N','blue'),('M1','递增 ↑','r0 → w1','全一','2N','teal'),
          ('M2','递增 ↑','r1 → w0','全零','2N','teal'),('M3','递减 ↓','r0 → w1','全一','2N','orange'),
          ('M4','递减 ↓','r1 → w0','全零','2N','orange'),('M5','任意方向','r0','全零','1N','blue')]
    for i,(m,di,ops,st,n,c) in enumerate(rows):
        y=285+i*156;id=f'row-{i}'
        d.rect(id,70,y,1060,136,fill='pale',stroke=c)
        for j,t in [(0,m),(1,di),(3,n)]:d.t(xs[j],y+68,t,size=34 if j!=1 else 32,color=c if j==1 else 'ink',weight=700 if j!=1 else 400,anchor='middle',owner=id,padding=20)
        d.t(xs[2],y+46,ops,size=38,weight=700,anchor='middle',owner=id,padding=15)
        d.t(xs[2],y+101,'结束后：'+st,size=28,color='muted',anchor='middle',owner=id,padding=12)
    d.t(600,1280,'总操作次数：(1 + 2 + 2 + 2 + 2 + 1) × N = 10N',size=34,weight=700,anchor='middle')
    d.note(1363,['10N 是读写操作次数；实际时钟周期还要考虑读延迟、切换和等待。'])
    return d

def m04():
    d=Figure('04耦合故障时序','图 06  耦合故障：先激励，再观察',
             '示例：A 从 0 写成 1 时，错误地把 B 从 0 改成 1。',1640)
    d.node('aggressor',80,230,410,'激励单元 A',['0 → 写 1 → 1'],accent='blue',h=160)
    d.node('victim',710,230,410,'受害单元 B',['期望 0，实际变为 1'],accent='teal',h=160,bs=30)
    d.edge('coupling',d.port('aggressor','E'),d.port('victim','W'),color='red',meaning='故障导致的异常影响，不是正常数据连线')
    d.t(600,270,'错误耦合',size=30,color='red',anchor='middle')
    steps=[('1  将 B 写为 0','准备受害单元的初始状态。'),('2  将 A 写为 0','准备激励单元的初始状态。'),
           ('3  将 A 从 0 写成 1','执行可能触发耦合故障的操作。'),('4  读取 B，并与 0 比较','若实际读到 1，本次比较就能够发现异常。')]
    for i,(title,b) in enumerate(steps):
        d.node(f'step{i}',140,510+i*235,920,title,[b],accent='red' if i==3 else 'orange',h=158,bs=30)
        if i:d.connect(f'order{i}',f'step{i-1}',f'step{i}',color='muted',meaning='同一测试示例中的操作先后次序')
    d.note(1480,['读取 B 之前，不应先向 B 写入正确值，否则错误可能被消除。',
                 '其他耦合故障需要不同的初始状态、操作以及地址先后次序。'])
    return d

def bars(stem,title,subtitle,data,xmax,ticks,left,row_gap):
    axis=230+len(data)*row_gap+30;d=Figure(stem,title,subtitle,axis+245)
    right=1010;scale=(right-left)/xmax
    d.t(1110,210,'次数',size=28,color='muted',anchor='middle')
    for i,(name,value) in enumerate(data):
        y=274+i*row_gap;c='blue' if value<=11 else 'teal' if value<=18 else 'orange' if value<=26 else 'purple'
        d.t(left-28,y,name,size=32,anchor='end')
        d.rect(f'bar{i}',left,y-20,value*scale,40,fill=c,stroke='none',radius=3,kind='bar')
        d.t(1110,y,f'{value}N',size=32,weight=700,anchor='middle',color=c)
    d.rule('axis',[(left,axis),(right,axis)],color='muted')
    for k in ticks:
        x=left+k*scale;d.rule(f'tick{k}',[(x,axis),(x,axis+10)],color='muted');d.t(x,axis+41,str(k),size=28,color='muted',anchor='middle')
    d.t((left+right)/2,axis+98,'操作次数系数',size=32,anchor='middle')
    d.note(axis+161,['实际操作次数 = 系数 × N；图中不包含保持等待及额外接口开销。',
                     '比较故障覆盖能力时，必须同时核对故障集合与具体操作序列。'])
    return d

def m05():return bars('05经典算法长度','图 08  经典 March 算法的操作长度','只比较代表版本的读写操作次数，不把操作长度当作故障覆盖率。',CLASSIC,30,range(0,31,5),320,67)

def m06():
    d=Figure('06存储器数据图案','图 11  数据图案与相邻单元状态',
             '8 × 8 单元示意；每个格子内的数字表示该单元存储的数据。',1650)
    patterns=[('全零','所有单元写入 0',lambda r,c:0),('棋盘图案','上下、左右相邻值交替',lambda r,c:(r+c)%2),
              ('行条纹','相邻两行的数据值交替',lambda r,c:r%2),('列条纹','相邻两列的数据值交替',lambda r,c:c%2)]
    for i,(title,caption,fn) in enumerate(patterns):
        gx=80+(i%2)*560;gy=285+(i//2)*650;cell=60
        d.t(gx+240,gy-53,title,size=36,weight=700,anchor='middle')
        for r in range(8):
            for c in range(8):
                bit=fn(r,c);id=f'p{i}-r{r}-c{c}'
                d.rect(id,gx+c*cell,gy+r*cell,cell,cell,fill='blue' if bit else 'zero',stroke='paper',radius=0,kind='cell',stroke_width=1.4)
                d.t(gx+(c+.5)*cell,gy+(r+.5)*cell,str(bit),size=30,color='paper' if bit else 'ink',anchor='middle',owner=id,padding=4)
        d.t(gx+240,gy+530,caption,size=30,color='muted',anchor='middle')
    d.note(1570,['邻近故障测试需要遵循真实的物理行列；逻辑地址相邻不等于物理相邻。'])
    return d

def m07():
    d=Figure('07五单元邻近故障','图 10  五单元邻近图案敏感故障',
             '四个方向的箭头表示对中心单元的影响，不是程序执行次序。',1540)
    for id,x,y,title,c in [('top',450,250,'上方单元','blue'),('left',80,520,'左侧单元','blue'),
                         ('center',450,520,'中心单元','orange'),('right',820,520,'右侧单元','blue'),('bottom',450,790,'下方单元','blue')]:
        d.node(id,x,y,300,title,accent=c,h=140)
    for a,b,sa,sb in [('top','center','S','N'),('left','center','E','W'),('right','center','W','E'),('bottom','center','N','S')]:
        d.edge(a+'-influence',d.port(a,sa),d.port(b,sb),color='orange',meaning='相邻单元状态对中心单元行为的影响')
    d.t(600,1020,'四个邻近单元：2⁴ = 16 种二进制状态组合',size=34,weight=700,anchor='middle')
    d.node('condition',80,1120,1040,'故障触发与观察',['周围单元保持指定状态时，对中心单元执行有关读写操作。',
           '单一全零或全一图案，不能遍历所有要求的邻近状态。'],accent='red',bs=30)
    d.note(1430,['图中为最邻近四单元示例；完整测试条件仍由目标故障模型决定。'])
    return d

def m08():
    d=Figure('08算法选择流程','图 13  March 算法的选择与验证',
             '先确定电路结构与故障目标，再比较候选方案的覆盖能力和实现代价。',1660)
    d.node('structure',100,220,1000,'确定存储器结构',['类型、端口、物理行列和读写时序'])
    d.node('faults',100,480,1000,'建立需要检测的故障集合',['单存储单元、耦合、读写干扰、动态及邻近图案'],accent='teal')
    d.connect('structure-faults','structure','faults',meaning='根据电路结构确定故障建模条件')
    d.rect('candidates',100,740,1000,520,fill='pale',stroke='orange',kind='node')
    d.t(600,790,'形成候选方案：下列方向可以组合',size=36,weight=700,color='orange',anchor='middle',owner='candidates',padding=24)
    choices=[('基础筛查或时间受限','March C− / MATS++'),('增强静态与动态检测','March MSS / SS / AB / RAW / AZ'),('特殊结构定制','地址译码器 / 多端口 / 存储器内部计算')]
    for i,(title,body) in enumerate(choices):
        id=f'choice{i}';y=850+i*130
        d.rect(id,140,y,920,112,fill='paper',stroke='grid',kind='group')
        d.t(172,y+35,title,size=30,weight=700,owner=id,padding=10)
        d.t(172,y+82,body,size=28,color='muted',owner=id,padding=8)
    d.connect('faults-candidates','faults','candidates',color='orange',meaning='按故障目标形成候选算法集合')
    d.node('verify',100,1380,1000,'故障仿真与硬件测量',['比较覆盖率、操作数、时序、控制器面积与功率'],accent='teal',bs=30)
    d.connect('candidates-verify','candidates','verify',color='teal',meaning='验证候选算法，不把候选项误画为串行测试步骤')
    d.note(1610,['最终覆盖结论必须限定于实际验证的故障集合及电气条件。'])
    return d

def m09():
    d=Figure('09动态故障时序','图 09  动态故障与连续读取历史',
             '操作历史可能改变后续读取结果；这里不表示所有动态故障都由读取触发。',1410)
    steps=[('初始化',['将单元写为 1','建立已知初始状态'],'blue'),
           ('第一次读取',['r1：读出 1，比较通过','内部可能开始累积变化'],'blue'),
           ('再次读取',['r1：仍读出 1，比较通过','连续操作可能达到缺陷触发条件'],'blue'),
           ('检测读出',['r1：期望为 1，实际读到 0','比较失败，异常得到观察'],'red')]
    for i,(title,body,c) in enumerate(steps):
        d.node(f'step{i}',140,220+i*265,920,title,body,accent=c,h=210)
        if i:d.connect('history'+str(i),f'step{i-1}',f'step{i}',color='muted',meaning='在规定时间条件下连续执行')
    d.note(1290,['重复次数、地址关系和操作间隔，必须由目标缺陷的触发条件确定。'])
    return d

def m10():return bars('10复杂算法长度','图 12  从通用测试到复杂故障：长度比较','各算法面向不同故障集合；这一图不能直接作为故障覆盖率排名。',COMPLEX,190,range(0,176,25),410,82)

BUILDERS=[m01,m02,m03,m04,m05,m06,m07,m08,m09,m10]
