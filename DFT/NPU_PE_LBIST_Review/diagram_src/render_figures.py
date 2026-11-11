#!/usr/bin/env python3
"""Generate original, editable engineering SVGs and PNGs for the LBIST review.
Dependencies: Python 3.10+, cairosvg. No external images or font files required.
Run from any directory. Chinese rendering requires an installed CJK font.
"""
from pathlib import Path
from html import escape
import json
import cairosvg

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'figures'
OUT.mkdir(exist_ok=True)
C = dict(ink='#142b43', muted='#54677a', border='#b9c8d6', bg='#ffffff',
         pale='#f4f7fb', blue='#2563a6', bluebg='#edf4fc', teal='#157a73',
         tealbg='#eaf7f3', orange='#b76414', orangebg='#fff4e6',
         red='#ae3346', redbg='#fff0f1', purple='#6c52a3', purplebg='#f3effb')
FONT = 'Noto Sans CJK SC, Noto Sans CJK JP, WenQuanYi Zen Hei, sans-serif'
manifest = []
class Fig:
    def __init__(self, name, title, sub, w=1600, h=960):
        self.name, self.title, self.w, self.h = name,title,w,h
        self.e = [f'<svg xmlns="http://www.w3.org/2000/svg" width="{w}" height="{h}" viewBox="0 0 {w} {h}">',
                  '<defs>']
        for k in ['ink','blue','teal','orange','red','muted','purple']:
            self.e.append(f'<marker id="arr_{k}" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="8" markerHeight="8" orient="auto-start-reverse"><path d="M0,0 L10,5 L0,10 z" fill="{C[k]}"/></marker>')
        self.e += ['</defs>',f'<rect width="{w}" height="{h}" fill="white"/>']
        self.text(54,60,title,36,weight=700)
        self.text(54,104,sub,22,color='muted')
        self.line([(54,129),(w-54,129)],color='border',width=2)
    def text(self,x,y,txt,size=24,color='ink',anchor='start',weight=400):
        self.e.append(f'<text x="{x}" y="{y}" font-family="{FONT}" font-size="{size}" font-weight="{weight}" fill="{C.get(color,color)}" text-anchor="{anchor}">{escape(str(txt))}</text>')
    def lines(self,x,y,ls,size=24,color='ink',anchor='start',gap=35,weight=400):
        for i,l in enumerate(ls): self.text(x,y+i*gap,l,size,color,anchor,weight)
    def box(self,x,y,w,h,ls,kind='blue',size=24,dashed=False,round=14):
        fill=C.get(kind+'bg',C['pale']); stroke=C.get(kind,C['border'])
        ds=' stroke-dasharray="10 7"' if dashed else ''
        self.e.append(f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="{round}" fill="{fill}" stroke="{stroke}" stroke-width="2"{ds}/>')
        ls=ls if isinstance(ls,list) else [ls]
        gap=size*1.45; first=y+h/2-(len(ls)-1)*gap/2+size*.35
        self.lines(x+w/2,first,ls,size,anchor='middle',gap=gap)
    def panel(self,x,y,w,h,title,kind='blue'):
        self.e.append(f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="18" fill="{C["pale"]}" stroke="{C["border"]}" stroke-width="2"/>')
        self.text(x+24,y+42,title,27,color=kind,weight=700)
    def line(self,pts,color='ink',width=3,arrow=False,dash=False):
        ps=' '.join(f'{x},{y}' for x,y in pts)
        end=f' marker-end="url(#arr_{color})"' if arrow else ''
        ds=' stroke-dasharray="9 7"' if dash else ''
        self.e.append(f'<polyline points="{ps}" fill="none" stroke="{C.get(color,color)}" stroke-width="{width}" stroke-linejoin="round" stroke-linecap="round"{end}{ds}/>')
    def dot(self,x,y,color='ink',r=5):
        self.e.append(f'<circle cx="{x}" cy="{y}" r="{r}" fill="{C[color]}"/>')
    def band(self,x,y,w,h,txt,kind='teal',size=24): self.box(x,y,w,h,txt,kind,size)
    def finish(self):
        self.line([(54,self.h-64),(self.w-54,self.h-64)],color='border',width=1.5)
        self.text(54,self.h-29,'本报告原创示意 · 非论文原图 · 示例配置不代表实测结果',19,'muted')
        self.text(self.w-54,self.h-29,self.name.split('_')[0],19,'muted','end')
        self.e.append('</svg>'); svg='\n'.join(self.e)
        (OUT/(self.name+'.svg')).write_text(svg,encoding='utf-8')
        cairosvg.svg2png(bytestring=svg.encode(),write_to=str(OUT/(self.name+'.png')),output_width=self.w)
        manifest.append(dict(id=self.name,title=self.title,width=self.w,height=self.h))

# 01 — classification
f=Fig('01_scope','图 1  PE 测试研究的分类与比较范围','测试通路、测试目的与自测试能力是不同维度，不能仅凭论文标题归类。',1600,1010)
f.panel(55,170,1490,275,'A  结构故障测试：明确网表、故障清单和测试条件','blue')
for x,w,txt in [(85,430,['扫描式 LBIST','PRPG → 扫描链 → 捕获 → MISR']), (585,430,['功能通路结构测试','利用现有寄存器送入 ATPG 向量']), (1085,430,['少量扫描 + 功能通路','提高难控状态的可控性与可观测性'])]:
    f.box(x,250,w,140,txt,'blue',23)
f.panel(55,475,1490,250,'B  运行期间检查：减少推理暂停，覆盖目标可能更窄','teal')
for x,txt in [(85,['专用短测试序列','权重块之间插入已知输入']), (585,['ABFT / 校验和','正常计算同时检查算术关系']), (1085,['定位与恢复','识别 PE / 列并隔离或重计算'])]:
    f.box(x,550,430,125,txt,'teal',23)
f.band(85,765,1430,85,'DFT 测试架构 ≠ 自主 LBIST；在线检测 ≠ 全部门级故障覆盖。','orange',27)
f.text(800,900,'SRAM / 寄存器堆通常另设 MBIST；本报告重点是 PE 的触发器、MAC、控制和互连。',23,'muted','middle')
f.finish()

# 02 — PE dataflow
f=Fig('02_pe_ws_os','图 2  WS 与 OS 的 Reg + MAC 结构及测试关注点','代表性寄存器级示意；真实 PE 的流水级、旁路和寄存器位置应以 RTL 为准。',1800,1200)
for y,title in [(165,'WS：权重保存在本地，部分和向下传递'),(665,'OS：部分和保存在本地，累加器构成反馈')]:
    f.panel(50,y,1700,425,title)
# WS nodes
f.box(210,290,180,85,['A_reg','输入 / 转发'],'blue',23)
f.box(525,400,200,85,['W_reg','load / hold'],'teal',23)
f.box(535,285,180,95,['乘法器','a × w'],'blue',24)
f.box(875,285,180,95,['加法器','+ p_in'],'blue',24)
f.box(1215,285,210,95,['P_reg','捕获 / 转发'],'blue',24)
f.line([(90,332),(210,332)],'blue',arrow=True); f.text(90,310,'a_in',23)
f.line([(390,332),(535,332)],'blue',arrow=True)
f.line([(625,400),(625,380)],'teal',arrow=True)
f.line([(715,332),(875,332)],'blue',arrow=True)
f.line([(1055,332),(1215,332)],'blue',arrow=True)
f.line([(1425,332),(1640,332)],'blue',arrow=True); f.text(1510,309,'p_out',23)
f.line([(965,240),(965,285)],'blue',arrow=True); f.text(965,224,'p_in',23,anchor='middle')
f.line([(300,290),(300,250),(465,250)],'blue',arrow=True);f.text(360,233,'a_out',22)
f.line([(470,442),(525,442)],'teal',arrow=True);f.text(450,480,'w_load',21,anchor='middle')
f.lines(875,452,['测试关键：独立设置 a、w、p_in','确保 W_reg 与 P_reg 可控、响应可见'],24,gap=40)
f.band(90,520,1620,48,'可选观察点：P_reg 输入或输出；量化 / 饱和之前观察有助于避免错误掩盖。','orange',22)
# OS
f.box(210,800,180,85,['A_reg','输入 / 转发'],'blue',23)
f.box(525,910,200,85,['W_reg','输入 / 转发'],'teal',23)
f.box(535,795,180,95,['乘法器','a × w'],'blue',24)
f.box(875,795,180,95,['加法器','+ acc'],'blue',24)
f.box(1215,795,210,95,['ACC_reg','clear / hold'],'blue',24)
f.line([(90,842),(210,842)],'blue',arrow=True);f.text(90,820,'a_in',23)
f.line([(390,842),(535,842)],'blue',arrow=True)
f.line([(625,910),(625,890)],'teal',arrow=True)
f.line([(715,842),(875,842)],'blue',arrow=True)
f.line([(1055,842),(1215,842)],'blue',arrow=True)
f.line([(1425,842),(1640,842)],'blue',arrow=True);f.text(1510,820,'result',23)
f.line([(1470,842),(1470,960),(965,960),(965,890)],'purple',arrow=True);f.dot(1470,842,'blue')
f.text(1120,1006,'累加反馈：acc(t+1) = acc(t) + a(t)w(t)',23,'purple','middle')
f.line([(470,952),(525,952)],'teal',arrow=True);f.text(450,991,'w_in',21,anchor='middle')
f.band(90,1030,1620,48,'测试关键：初始化 acc、检查保持与清零、控制反馈路径，并避免不同周期的错误相消。','orange',22)
f.finish()

# 03 — array
f=Fig('03_array_observation','图 3  4 × 4 WS 阵列中的测试传播与定位','蓝色：激活水平传递；绿色：部分和竖直传递；橙色：故障响应的可能传播路径。',1600,1120)
xs=[340,590,840,1090];ys=[250,420,590,760];bw,bh=170,95
for r,y in enumerate(ys):
    f.text(75,y+55,f'a[{r}]',25)
    f.line([(155,y+48),(xs[0],y+48)],'blue',arrow=True)
    for c,x in enumerate(xs):
        kind='red' if (r,c)==(1,2) else 'blue'
        f.box(x,y,bw,bh,[f'PE({r},{c})','本地 W_reg'],kind,23)
        if c<3:f.line([(x+bw,y+48),(xs[c+1],y+48)],'blue',arrow=True)
for c,x in enumerate(xs):
    xc=x+85;f.text(xc,200,f'p_top[{c}]',24,'teal','middle')
    f.line([(xc,210),(xc,ys[0])],'teal',arrow=True)
    for r in range(3):
        col='orange' if c==2 and r>=1 else 'teal'
        f.line([(xc,ys[r]+bh),(xc,ys[r+1])],col,arrow=True)
    f.line([(xc,855),(xc,910)],'orange' if c==2 else 'teal',arrow=True)
    f.box(x-10,910,190,70,[f'列输出 y[{c}]'],'orange' if c==2 else 'teal',22)
f.lines(1300,465,['例：PE(1,2)','出现计算错误'],23,'red',gap=36)
f.text(800,1011,'仅比较 y[2] 可发现该列异常；确定行号还需要隔离、编码向量或额外观察点。',24,'muted','middle')
f.finish()

# 04 scan lbist architecture
f=Fig('04_scan_lbist','图 4  扫描式 LBIST 的基本组织','扫描移位和功能捕获是两个阶段；图中功能环路与串行测试通路分开表示。',1700,1050)
f.box(65,390,220,130,['共享 PRPG','LFSR / 重播种'],'orange',24)
f.box(350,390,210,130,['相位扩展','扫描输入'],'orange',24)
f.line([(285,455),(350,455)],'orange',arrow=True)
f.panel(635,180,520,620,'PE 阵列：多个扫描分组')
for i,y in enumerate([290,455,620]):
    f.box(670,y,190,85,['扫描触发器','Reg / Control'],'blue',22)
    f.box(920,y,195,85,['组合逻辑','MUL + ADD'],'blue',22)
    f.line([(860,y+42),(920,y+42)],'blue',arrow=True)
    f.line([(1017,y),(1017,y-30),(765,y-30),(765,y)],'blue',arrow=True)
    f.line([(560,[420,455,490][i]),([600,620,580][i],[420,455,490][i]),([600,620,580][i],y+42),(670,y+42)],'orange',arrow=True)
# scan outputs through lower taps not arithmetic outputs
f.line([(765,375),(765,402),(1220,402),(1220,527),(1260,527)],'orange',arrow=True)
f.line([(765,540),(765,567),(1260,567)],'orange',arrow=True)
f.line([(765,705),(765,732),(1220,732),(1220,607),(1260,607)],'orange',arrow=True)
f.box(1260,507,210,120,['响应压缩','MISR / 屏蔽'],'orange',24)
f.line([(1365,627),(1365,720)],'orange',arrow=True)
f.box(1240,720,250,80,['签名与参考值比较'],'teal',23)
f.text(1290,443,'scan_out',22,'orange')
f.text(1290,475,'各通道独立',20,'orange')
f.box(100,850,360,90,['BIST 控制器 + 受控测试时钟'],'purple',23)
f.line([(460,895),(500,895),(500,815),(895,815),(895,800)],'purple',arrow=True,dash=True)
f.lines(520,864,['控制 scan_en、移位计数、捕获脉冲和 MISR_en','ATPG 确定性补充向量可通过重播种或压缩存储加入'],23,'muted',gap=42)
f.finish()

# 05 partial scan functional path
f=Fig('05_partial_scan','图 5  功能通路与选择性扫描的组合','概念化结构：A/W 通过既有通路加载，难以直接设置的 P 状态保留选择性扫描。',1700,980)
f.box(55,250,290,120,['片上向量 / ATPG 向量','或外部测试数据'],'orange',24)
f.box(55,570,290,100,['扫描输入','P 状态控制'],'purple',24)
f.panel(430,190,790,600,'一个被测 PE 及其响应捕获位置')
f.box(475,300,210,90,['A_reg / W_reg','功能加载'],'blue',24)
f.box(775,300,230,90,['MAC 组合逻辑'],'blue',25)
f.box(775,570,230,95,['P_reg','选择性扫描'],'purple',24)
f.line([(345,310),(400,310),(400,345),(475,345)],'orange',arrow=True)
f.line([(685,345),(775,345)],'blue',arrow=True)
f.line([(345,620),(775,620)],'purple',arrow=True)
f.line([(890,570),(890,390)],'purple',arrow=True)
f.line([(1005,345),(1300,345)],'blue',arrow=True)
f.box(1300,280,325,135,['后继 PE 或末端捕获寄存器','观察响应'],'teal',23)
f.line([(1462,415),(1462,570)],'teal',arrow=True)
f.box(1300,570,325,100,['比较 / 压缩 / 故障标记'],'teal',23)
f.text(890,475,'可控的部分和',22,'purple','middle')
f.lines(475,720,['减少扫描连接，不等于取消结构 ATPG。','A/W 转发寄存器与控制信号仍需独立测试。'],23,'muted',gap=38)
f.band(80,835,1540,60,'相邻 PE 比较只能检查差异；公共激励错误、相同故障响应仍需要独立参考检查。','orange',24)
f.finish()

#06 TDM schedule
f=Fig('06_partition_schedule','图 6  子阵列划分与受功耗限制的测试安排','示意性调度，不是任何论文的实测功耗或最优方案。',1700,1000)
f.panel(55,180,640,655,'阵列分成 4 个可独立控制的测试组')
for x,y,n,k in [(95,260,'Tile 0','orange'),(390,260,'Tile 1','blue'),(95,500,'Tile 2','blue'),(390,500,'Tile 3','blue')]:
    f.box(x,y,260,200,[n,'PE × PE','局部响应收集'],k,25)
f.text(375,772,'同一组内广播；组间错开高翻转阶段',22,'muted','middle')
f.panel(745,180,900,655,'示例：测试窗口内仅一个组执行高活动阶段')
colxs=[930,1090,1250,1410]
for i,x in enumerate(colxs):f.text(x+65,270,f'窗口 {i}',23,'muted','middle')
for r in range(4):
    y=325+r*105;f.text(790,y+44,f'Tile {r}',24)
    for c,x in enumerate(colxs): f.box(x,y,130,70,'测试' if r==c else '保持','orange' if r==c else 'blue',23)
f.text(1195,795,'是否允许其他组同时移位，取决于真实功耗预算。',22,'muted','middle')
f.band(75,865,1550,62,'比较总测试时间时，应计入加载、移位、捕获、排空、结果读取及状态恢复。','teal',25)
f.finish()

#07 masking and aliasing
f=Fig('07_masking_aliasing','图 7  故障被激活，并不保证最终签名出错','需要分别评估内部可检测性、输出可观测性与压缩造成的漏检。',1700,1100)
xs=[55,365,675,985,1295]; labels=[['内部故障','必须被激活'],['算术传播','可能相消'],['截断 / 饱和','可能掩盖'],['空间压缩','可能抵消'],['MISR 签名','仍可能别名']]
for x,ls in zip(xs,labels):f.box(x,205,280,130,ls,'blue',24)
for i in range(4):f.line([(xs[i]+280,270),(xs[i+1],270)],'blue',arrow=True)
f.panel(55,410,770,430,'例 A：空间 XOR 抵消','red')
f.box(95,500,235,95,['响应误差 Δy₀ = e'],'red',23)
f.box(95,670,235,95,['响应误差 Δy₁ = e'],'red',23)
f.box(420,585,120,90,['XOR'],'orange',24)
f.line([(330,548),(380,548),(380,630),(420,630)],'red',arrow=True)
f.line([(330,717),(380,717),(380,630)],'red')
f.line([(540,630),(610,630)],'orange',arrow=True)
f.box(610,585,170,90,['e ⊕ e = 0'],'teal',24)
f.text(440,806,'错误已在 MISR 之前丢失；加宽 MISR 无法补救。',22,'muted','middle')
f.panel(875,410,770,430,'例 B：只比较相邻 PE','red')
f.box(915,500,280,95,['PE 0：同样的错误结果'],'red',22)
f.box(915,670,280,95,['PE 1：同样的错误结果'],'red',22)
f.box(1290,585,270,90,['相等 → 误判通过'],'orange',24)
f.line([(1195,548),(1240,548),(1240,630),(1290,630)],'red',arrow=True)
f.line([(1195,717),(1240,717),(1240,630)],'red')
f.text(1260,806,'需要可信参考、分组观察或重复独立检查。',22,'muted','middle')
f.band(80,900,1540,90,['P_alias ≈ 2⁻ᵐ 只在相应随机性假设下成立。','它不是确定性相关故障的保证，更不是未激活故障的检测概率。'],'purple',24)
f.finish()

#08 runtime/cumulative
f=Fig('08_online_vs_structural','图 8  四个在线向量与完整结构测试不是同一覆盖目标','以权重块之间插入短检查为概念示例；不绘制未经测量的覆盖率曲线。',1700,1000)
f.panel(55,190,1590,290,'运行期间：检查随 W₀、W₁、W₂ 等不同权重块重复')
blocks=[(90,280,250,['加载 W₀','4 向量检查'],'orange'),(380,280,210,['计算块 0'],'blue'),(630,280,250,['加载 W₁','4 向量检查'],'orange'),(920,280,210,['计算块 1'],'blue'),(1170,280,250,['加载 W₂','4 向量检查'],'orange')]
for x,y,w,ls,k in blocks:f.box(x,y,w,125,ls,k,24)
for i in range(len(blocks)-1):
    x,y,w,_,_=blocks[i];xn=blocks[i+1][0];f.line([(x+w,y+62),(xn,y+62)],'blue',arrow=True)
f.text(1490,350,'…',36,anchor='middle')
f.panel(55,525,1590,275,'专门结构测试：主动控制 A、W、P 与控制状态')
f.box(90,615,350,110,['寄存器与控制测试','clear / hold / load'],'purple',24)
f.box(530,615,450,110,['随机 + 确定性向量','补足乘法器等难测逻辑'],'orange',24)
f.box(1070,615,500,110,['按统一故障清单评价','stuck-at / transition 分开'],'teal',24)
f.line([(440,670),(530,670)],'blue',arrow=True);f.line([(980,670),(1070,670)],'blue',arrow=True)
f.band(90,850,1520,70,'跨多个权重块的累计检出率，不能写成“一次四向量测试的覆盖率”。','red',27)
f.finish()

#09 proposed architecture
f=Fig('09_hybrid_architecture','图 9  面向 Reg + MAC 的混合式 Tile-LBIST 建议','本报告提出的待验证架构，不是已实现电路，也不是特定论文的原图。',1800,1200)
f.box(60,200,330,155,['全局测试控制器','配置 / 分组 / 超时','安全进入与退出'],'purple',25)
f.box(60,440,330,145,['PRPG + 重播种','定向向量 / ATPG 补充'],'orange',25)
f.box(60,730,330,135,['参考签名 / 测试配置','模式与序列版本绑定'],'teal',24)
f.panel(470,190,850,735,'Tile：例如 4 × 4 或 8 × 8 PEs')
f.box(510,285,330,110,['激励选择与分发','正常 / 自测试'],'orange',25)
f.box(510,470,330,160,['PE 阵列','A/W/P 寄存器 + MAC','控制与相邻连接'],'blue',25)
f.box(915,280,345,115,['可选：局部扫描 / 测试点','处理难控、难观测状态'],'purple',23)
f.box(915,495,345,125,['分组观察 / 选择器','避免过早全阵列 XOR'],'teal',25)
f.box(915,740,345,105,['Tile MISR / 原始响应模式'],'teal',23)
f.line([(390,510),(450,510),(450,340),(510,340)],'orange',arrow=True)
f.line([(675,395),(675,470)],'orange',arrow=True)
f.line([(840,550),(915,550)],'teal',arrow=True)
f.line([(1087,620),(1087,740)],'teal',arrow=True)
f.line([(1087,395),(1087,440),(760,440),(760,470)],'purple',arrow=True,dash=True)
f.box(1390,470,335,155,['比对与故障状态','PASS / FAIL / TIMEOUT','Tile / 行列诊断'],'teal',24)
f.line([(1260,792),(1350,792),(1350,550),(1390,550)],'teal',arrow=True)
f.line([(390,795),(430,795),(430,970),(1557,970),(1557,625)],'teal',arrow=True)
f.line([(390,265),(430,265),(430,170),(1557,170),(1557,470)],'purple',arrow=True,dash=True)
f.text(1430,220,'模式控制 / 状态',22,'purple')
f.lines(510,720,['观察点优先放在截断、','饱和与激活函数之前。','诊断时可重跑失败组。'],23,'muted',gap=42)
f.band(60,1030,1670,85,'共享发生器节省复制成本；局部观察改善可观测性。实际收益必须由同网表故障仿真与 PPA 验证。','orange',25)
f.finish()

#10 FSM
f=Fig('10_bist_lifecycle','图 10  自测试进入、执行与退出流程','在线测试必须处理未完成事务和状态恢复；超时与测试失败要分别上报。',1700,1110)
# serpentine straight paths with reserved connectors
nodes=[(90,210,'请求测试 / 检查许可','purple'),(620,210,'停止接收新事务','blue'),(1150,210,'排空在途计算','blue'),
       (1150,430,'保存必要状态','blue'),(620,430,'初始化寄存器和签名','orange'),(90,430,'加载测试配置 / 种子','orange'),
       (90,650,'执行激励 + 收集响应','orange'),(620,650,'排空测试流水并比对','teal'),(1150,650,'通过 / 失败 / 超时','teal')]
for x,y,t,k in nodes:f.box(x,y,400,110,t,k,25)
for a,b in [(0,1),(1,2),(3,4),(4,5),(6,7),(7,8)]:
    x,y,_,_=nodes[a];xx,yy,_,_=nodes[b]
    if xx>x:f.line([(x+400,y+55),(xx,y+55)],'blue',arrow=True)
    else:f.line([(x,y+55),(xx+400,y+55)],'blue',arrow=True)
f.line([(1350,320),(1350,430)],'blue',arrow=True)
f.line([(290,540),(290,650)],'blue',arrow=True)
f.box(900,870,650,110,['可选定位 → 恢复 / 隔离 → 上报 → 返回'],'teal',24)
f.line([(1350,760),(1350,870)],'teal',arrow=True)
f.box(90,870,660,110,['终止规则：每个状态都有周期预算与异常出口'],'red',24)
f.text(850,1030,'上电测试通常无需保存业务状态；空闲期测试也不能默认内部寄存器无有效内容。',24,'muted','middle')
f.finish()

#11 timing
f=Fig('11_timing','图 11  两类测试时序：LOC 与功能响应有效控制','时序仅用于说明事件关系；不是完整门级测试协议，波形不按比例。',1800,1180)
f.panel(55,175,1690,390,'A  Launch-on-Capture：扫描装入状态后，使用两个功能脉冲')
x0=340;cw=150
for i,t in enumerate(['移位末段','稳定窗口','Launch','Capture','读出准备','移位读出']):f.text(x0+i*cw+cw/2,270,t,22,'muted','middle')
# general wave step
def wave(y,vals,col='blue'):
    pts=[]
    for i,v in enumerate(vals):
        yy=y-45 if v else y
        if i==0:pts.append((x0,yy))
        else:pts.append((x0+i*cw,yy))
        pts.append((x0+(i+1)*cw,yy))
    f.line(pts,col,3)
f.text(95,340,'scan_en',25);wave(345,[1,0,0,0,0,1],'purple')
f.text(95,440,'测试时钟',25)
# pulses per selected slot
pts=[(x0,445)]
for i in range(6):
    s=x0+i*cw
    if i in [0,2,3,5]:pts += [(s+35,445),(s+35,395),(s+85,395),(s+85,445)]
    pts.append((s+cw,445))
f.line(pts,'blue',3)
f.text(1390,340,'功能模式',24,'purple')
f.lines(1390,400,['Launch 产生转换','Capture 捕获响应'],23,'blue',gap=38)
f.text(920,517,'两次功能脉冲间隔由目标测试频率决定；RTL 翻转并不等于通过时序故障测试。',23,'muted','middle')
f.panel(55,605,1690,455,'B  功能路径 BIST：示例流水延迟 L = 2，不存在反压')
xx=390;step=170
for i in range(6):f.text(xx+i*step+step/2,710,f'周期 {i}',23,'muted','middle')
rows=[('accept_test',['1','1','1','0','0','0'],'orange'),('out_valid',['0','0','1','1','1','0'],'teal'),('MISR_en',['0','0','1','1','1','0'],'teal')]
for j,(name,vals,k) in enumerate(rows):
    y=760+j*85;f.text(90,y+36,name,25)
    for i,v in enumerate(vals):f.box(xx+i*step,y,135,55,v,k if v=='1' else 'blue',24)
f.text(915,1030,'PRPG 在接受激励时前进；MISR 仅在对应有效结果到达时更新。反压存在时必须按实际事务对齐。',23,'muted','middle')
f.finish()

#12 experimental validation
f=Fig('12_validation','图 12  可复现的验证流程与分层结果','先建立单 PE 故障基准，再验证阵列传播、压缩、定位与测试开销。',1700,1160)
f.box(70,205,400,130,['参数化 RTL + 正确参考模型','WS / OS；INT8 / W4A8'],'blue',25)
f.box(650,205,400,130,['综合后的实际网表','统一库、约束和故障清单'],'blue',25)
f.line([(470,270),(650,270)],'blue',arrow=True)
f.box(1230,205,390,130,['全扫描 ATPG 基准','SA 与 transition 分开'],'purple',24)
f.line([(1050,270),(1230,270)],'blue',arrow=True)
f.box(70,465,400,145,['RTL 验证','功能 / 协议 / 状态机','寄存器级故障：单独统计'],'blue',24)
f.box(650,465,400,145,['结构故障仿真','逐故障 / 逐模式检查','先看原始响应，再看签名'],'orange',24)
f.box(1230,465,390,145,['时序与物理评估','双向量测试 / 目标频率','面积、时序与活动数据'],'orange',24)
f.line([(270,335),(270,465)],'blue',arrow=True)
f.line([(850,335),(850,465)],'blue',arrow=True)
f.line([(1425,335),(1425,465)],'purple',arrow=True)
f.box(70,760,1550,165,['分项结果：Reg / MUL / ADD / Control / Inter-PE / DFT 本身','检出、未检出、证明不可测、ATPG 未解决、被屏蔽故障分别记录','同时记录：测试周期、附加面积、时序变化、诊断成功率与实际功耗估计条件'],'teal',25)
for x in [270,850,1425]:f.line([(x,610),(x,760)],'teal',arrow=True)
f.band(90,980,1510,72,'未运行故障仿真与实现流程之前，只能报告设计假设与预期，不能填写覆盖率或 PPA 实测值。','red',25)
f.finish()

(OUT/'manifest.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2),encoding='utf-8')
print(f'Generated {len(manifest)} SVG and PNG figures in {OUT}')
