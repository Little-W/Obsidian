#!/usr/bin/env python3
"""Editable SVG diagrams for MBIST Chapter 06; optional PNG rendering.
No font files are embedded or distributed. All geometry/text is generated here.
Usage: python3 code/draw_figures.py [--svg-only]
"""
from __future__ import annotations
import argparse
import html
import json
import math
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'assets/grouping'
INK='#18324A'; MUTED='#53697C'; BLUE='#245C91'; TEAL='#168679'; ORANGE='#C47921'; RED='#B14A49'
PALE='#EEF4F8'; LINE='#CAD6E0'; WHITE='#FFFFFF'; BG='#F8FAFC'
COLORS=[BLUE,TEAL,ORANGE,'#7B64A8','#427E9C','#8C7148']
FONT="'Noto Sans CJK SC','Microsoft YaHei','PingFang SC',sans-serif"

def esc(x): return html.escape(str(x),quote=True)

class Canvas:
    def __init__(self,number,title,subtitle='',h=680):
        self.w=1400;self.h=h;self.number=number;self.items=[]
        self.items.append(f'<svg xmlns="http://www.w3.org/2000/svg" width="1400" height="{h}" viewBox="0 0 1400 {h}" role="img" aria-labelledby="title desc">')
        self.items.append(f'<title id="title">图06-{number:02d} {esc(title)}</title><desc id="desc">{esc(subtitle)}</desc>')
        self.items.append(f'<defs><marker id="arrow" viewBox="0 0 12 12" refX="10" refY="6" markerWidth="9" markerHeight="9" orient="auto-start-reverse"><path d="M1,1 L11,6 L1,11 Z" fill="{MUTED}"/></marker></defs>')
        self.rect(0,0,1400,h,WHITE,WHITE,0)
        self.rect(40,35,7,42,TEAL,TEAL,0)
        self.text(65,68,f'{number:02d}  {title}',size=33,weight=700)
        if subtitle:self.text(65,110,subtitle,size=22,color=MUTED)
        self.line(40,132,1360,132,color=LINE,width=1)
    def rect(self,x,y,w,h,fill=PALE,stroke=LINE,r=12,sw=1.5,opacity=None,dash=None):
        at=f' fill-opacity="{opacity}"' if opacity is not None else ''
        if dash:at+=f' stroke-dasharray="{dash}"'
        self.items.append(f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="{r}" fill="{fill}" stroke="{stroke}" stroke-width="{sw}"{at}/>')
    def circle(self,x,y,r,fill=WHITE,stroke=BLUE,sw=2.5):
        self.items.append(f'<circle cx="{x}" cy="{y}" r="{r}" fill="{fill}" stroke="{stroke}" stroke-width="{sw}"/>')
    def text(self,x,y,text,size=24,color=INK,anchor='start',weight=400):
        # y is baseline. Explicit separate lines keep labels safely editable.
        for j,t in enumerate(str(text).split('\n')):
            self.items.append(f'<text x="{x}" y="{y+j*size*1.45}" font-family="{FONT}" font-size="{size}" fill="{color}" text-anchor="{anchor}" font-weight="{weight}">{esc(t)}</text>')
    def line(self,x1,y1,x2,y2,color=MUTED,width=2,dash=None,arrow=False):
        ext=f' stroke-dasharray="{dash}"' if dash else ''
        if arrow:ext+=' marker-end="url(#arrow)"'
        self.items.append(f'<line x1="{x1}" y1="{y1}" x2="{x2}" y2="{y2}" stroke="{color}" stroke-width="{width}"{ext}/>')
    def path(self,points,color=MUTED,width=2.5,arrow=False,dash=None,fill='none'):
        d='M '+' L '.join(f'{x},{y}' for x,y in points)
        ext=' marker-end="url(#arrow)"' if arrow else ''
        if dash:ext+=f' stroke-dasharray="{dash}"'
        self.items.append(f'<path d="{d}" fill="{fill}" stroke="{color}" stroke-width="{width}" stroke-linejoin="round"{ext}/>')
    def polygon(self,points,fill=PALE,stroke=LINE,opacity=1):
        self.items.append(f'<polygon points="'+ ' '.join(f'{x},{y}' for x,y in points)+f'" fill="{fill}" fill-opacity="{opacity}" stroke="{stroke}" stroke-width="2"/>')
    def box(self,x,y,w,h,title,body='',color=BLUE):
        self.rect(x,y,w,h,WHITE,LINE)
        self.rect(x,y,w,7,color,color,0)
        self.text(x+22,y+47,title,size=26,color=color,weight=700)
        if body:self.text(x+22,y+90,body,size=22)
    def node(self,x,y,label,color=BLUE,r=31,sub=None):
        self.circle(x,y,r,WHITE,color)
        self.text(x,y+9,label,size=26,color=color,anchor='middle',weight=700)
        if sub:self.text(x,y+r+29,sub,size=20,anchor='middle',color=MUTED)
    def chip(self,x,y,label,w=82,color=BLUE):
        self.rect(x,y,w,48,color,color,r=8)
        self.text(x+w/2,y+33,label,size=24,color=WHITE,anchor='middle',weight=600)
    def foot(self,text):
        self.line(40,self.h-64,1360,self.h-64,color=LINE,width=1)
        self.text(55,self.h-27,text,size=21,color=MUTED)
    def save(self,name,png=True):
        OUT.mkdir(parents=True,exist_ok=True)
        data='\n'.join(self.items+['</svg>'])
        path=OUT/(name+'.svg');path.write_text(data,encoding='utf-8')
        if png:
            import cairosvg
            cairosvg.svg2png(bytestring=data.encode(),write_to=str(OUT/(name+'.png')),scale=1.5)

def groupbar(c,x,y,members,powers,width=480,label='',color=BLUE):
    if label:c.text(x,y-15,label,size=23,color=color,weight=600)
    c.rect(x,y,width,62,WHITE,LINE,r=6)
    pos=x
    for mid,p in zip(members,powers):
        w=width*p/10
        c.rect(pos,y,w,62,color,WHITE,r=0,sw=2)
        c.text(pos+w/2,y+40,f'{mid} · {p}',size=23,color=WHITE,anchor='middle',weight=600)
        pos+=w
    c.text(x+width+15,y+40,f'{sum(powers)}/10',size=23,color=color,weight=700)


def f01(png):
    c=Canvas(1,'四种分组概念对应不同决策','同一控制器管理的成员，不一定在同一时刻活动。',h=690)
    for x,title,body,col in [
        (40,'属性相容类别','同一测试接口\n允许的时钟关系\n允许的算法组合',BLUE),
        (380,'控制器共享组','Ctrl 0：A、B、C\nCtrl 1：D、E、F\n确定硬件归属',TEAL),
        (720,'同步测试步骤','Ctrl 0：先 A/B 后 C\nCtrl 1：先 D/E 后 F\n确定组内执行方式',ORANGE),
        (1060,'芯片级活动集合','当前：A、B、D、E\n下一阶段：C、F\n检查全局资源',BLUE)]:
        c.box(x,190,300,280,title,body,col)
    for x in [340,680,1020]:c.line(x+7,330,x+32,330,arrow=True)
    c.text(700,535,'属性相容  ≠  必须同组  ≠  必须同时测试',size=29,anchor='middle',weight=700,color=TEAL)
    c.foot('结构示意；图中成员和执行步骤不绑定后文十二实例用例。')
    c.save('01_group_levels',png)

def f02(png):
    c=Canvas(2,'十二实例统一用例','每组最多3个实例；功率不超过10 mW；HPWL不超过300 μm。')
    for off,ids,xbase in [(50,'ABCDEF',0),(740,'GHIJKL',1400)]:
        c.rect(off,165,610,385,BG,LINE)
        c.text(off+25,205,'左侧区域' if xbase==0 else '右侧区域',size=26,color=BLUE,weight=700)
        for k,mid in enumerate(ids):
            x=off+110+(k%3)*195;y=285+(k//3)*150
            p=4 if k<2 else 3;t=100 if k<2 else 60
            c.node(x,y,mid,color=BLUE if p==4 else TEAL)
            c.text(x,y+64,f'{p} mW · {t} μs',size=21,anchor='middle')
            c.text(x,y+91,f'({xbase+(k%3)*100}, {(k//3)*100})',size=20,anchor='middle',color=MUTED)
    c.foot('两个面板分别放大显示；坐标单位为 μm。全部数据均为自拟用例，不是芯片实测。')
    c.save('02_demo_layout',png)

def f03(png):
    c=Canvas(4,'相同成员，不同执行模型','A：4 mW × 100 μs；C：3 mW × 60 μs。',h=720)
    x0=260;scale=5.1
    for y,label,segments,energy in [
        (200,'逐块串行',[(0,100,4,'A',BLUE),(100,60,3,'C',TEAL)],'580 nJ'),
        (365,'同步且提前关停',[(0,60,7,'A+C',BLUE),(60,40,4,'A',TEAL)],'580 nJ'),
        (530,'整组最坏值预留',[(0,100,7,'预留 7 mW',ORANGE)],'700 nJ 上界')]:
        c.text(60,y+20,label,size=24,weight=600)
        c.line(x0,y+75,x0+160*scale,y+75,color=LINE)
        for start,d,p,l,col in segments:
            h=p*12;c.rect(x0+start*scale,y+75-h,d*scale,h,col,WHITE,0)
            c.text(x0+(start+d/2)*scale,y+75-h/2+8,l,size=23,color=WHITE,anchor='middle',weight=700)
        for t in [0,60,100,160]:
            c.line(x0+t*scale,y+75,x0+t*scale,y+83,color=MUTED)
            c.text(x0+t*scale,y+109,str(t),size=20,anchor='middle',color=MUTED)
        c.text(1125,y+20,energy,size=24,color=BLUE,weight=700)
    c.foot('横轴为 μs；柱高表示 mW。固定预算乘整组时间，是保守能量上界，不是实测能量。')
    c.save('04_execution_modes',png)

def f04(png):
    c=Canvas(3,'功率评估的四个层次','模型越接近实现，所需输入也越完整；早期相对指标不等于真实瞬时功率。')
    items=[('早期相对指标','容量、位宽、端口\n库表摘要','用途：快速筛选'),('命令能量模型','读写次数、图案\n单次访问能量','用途：能量与阶段预算'),('活动相关分析','VCD／SAIF\n网表、宏功率模型','用途：估计功率曲线'),('电源与温度分析','供电网络、封装\n位置、热模型','用途：检查局部风险')]
    for k,(title,body,foot) in enumerate(items):
        x=40+k*340;c.box(x,210,300,255,title,body,COLORS[k]);c.text(x+20,430,foot,size=21,color=MUTED)
        if k<3:c.line(x+307,335,x+332,335,arrow=True)
    c.text(700,540,'黑盒 SRAM 也需要正确的宏功率模型',size=28,anchor='middle',weight=700)
    c.foot('平均活动率会丢失时间变化；检查窗口应与电压下降或温度现象的时间尺度相匹配。')
    c.save('03_power_flow',png)

def f05(png):
    c=Canvas(5,'两两可行，不代表整组可行','集合容量和全组几何条件，必须在每次加入或合并后重新检查。')
    c.box(50,175,610,365,'功率反例','每个实例 4 mW；组预算 10 mW',BLUE)
    for x,m in [(160,'A'),(350,'B'),(540,'C')]:c.node(x,335,m,sub='4 mW')
    c.text(355,450,'任意两个：8 ≤ 10',size=27,color=TEAL,anchor='middle',weight=600)
    c.text(355,495,'三个同时：12 > 10',size=27,color=RED,anchor='middle',weight=600)
    c.box(740,175,610,365,'几何反例','最大两两距离要求 ≤ 5',TEAL)
    for x,m,coord in [(835,'A','0'),(1045,'B','4'),(1255,'C','8')]:c.node(x,335,m,sub=f'x={coord}')
    c.line(870,335,1010,335,color=TEAL);c.line(1080,335,1220,335,color=TEAL)
    c.text(1045,450,'A-B 与 B-C：都为 4',size=27,color=TEAL,anchor='middle')
    c.text(1045,495,'整组 A-C：8 > 5',size=27,color=RED,anchor='middle',weight=600)
    c.foot('没有冲突边或存在连续近邻，都不能代替对整组功率、人数和跨度的检查。')
    c.save('05_constraints',png)

def f06(png):
    c=Canvas(6,'三种几何指标并不相同','四点示例：(0,100)、(100,0)、(200,100)、(100,200)，单位 μm。')
    panels=[(45,'最大曼哈顿距离','D1 = 200 μm'),(505,'外接矩形半周长','HPWL = 400 μm'),(965,'到中心的距离','R = 100 μm')]
    for j,(x,title,result) in enumerate(panels):
        c.rect(x,180,390,365,BG,LINE);c.text(x+195,225,title,size=26,anchor='middle',weight=600)
        cx=x+195;cy=365;pts=[(cx-100,cy),(cx,cy-100),(cx+100,cy),(cx,cy+100)]
        if j==1:c.rect(cx-100,cy-100,200,200,'none',ORANGE,r=0,sw=3,dash='8 6')
        if j==2:
            c.polygon(pts,PALE,TEAL);c.circle(cx,cy,15,TEAL,TEAL);c.text(cx+24,cy+8,'c',size=25,color=TEAL)
            for a,b in pts:c.line(cx,cy,a,b,color=TEAL,dash='5 5')
        if j==0:c.path([pts[0],(cx-100,cy-100),pts[1]],color=BLUE,width=4)
        for a,b in pts:c.circle(a,b,9,WHITE,BLUE)
        c.text(cx,515,result,size=26,anchor='middle',color=COLORS[j],weight=700)
    c.foot('控制器中心还需满足实际可放置区域；HPWL只是几何近似，不是全部测试信号总线长。')
    c.save('06_geometry_metrics',png)

def f07(png):
    c=Canvas(7,'容量碎片导致额外控制器','同样的六个实例：4、4、3、3、3、3 mW；每组预算10 mW。',h=710)
    c.text(60,185,'首次适合：3组',size=28,color=BLUE,weight=700)
    for k,(ids,p) in enumerate([('AB',[4,4]),('CDE',[3,3,3]),('F',[3])]):
        groupbar(c,60,235+k*115,list(ids),p,width=480,label=f'G{k+1}',color=BLUE)
    c.text(760,185,'重新组合：2组',size=28,color=TEAL,weight=700)
    for k,(ids,p) in enumerate([('ADE',[4,3,3]),('BCF',[4,3,3])]):
        groupbar(c,760,235+k*115,list(ids),p,width=480,label=f'G{k+1}',color=TEAL)
    c.text(1000,535,'保留 4+3+3 的组合机会',size=27,anchor='middle',color=TEAL,weight=600)
    c.foot('空白部分表示未用功率容量；降序排列不能保证消除所有资源碎片。')
    c.save('07_bin_packing',png)

def f08(png):
    c=Canvas(8,'HPWL贪心的局部选择','从A开始；每一步在合法候选中选择合并后HPWL最小者。')
    cards=[(50,'1  初始种子','G={A}\n功率 4 mW\nHPWL 0 μm',BLUE),
           (395,'2  并列候选','加入B或D：100 μm\n按实例名选择B\nG={A,B}，8 mW',BLUE),
           (740,'3  停止本组','其余实例均为3 mW\n8+3 > 10\n不存在合法候选',ORANGE),
           (1085,'4  继续分组','{D,E,F}：9 mW\n{C}：3 mW\n左区共3组',TEAL)]
    for x,t,b,col in cards:c.box(x,220,265,275,t,b,col)
    for x in [315,660,1005]:c.line(x+12,355,x+65,355,arrow=True)
    c.foot('几何更紧凑不代表控制器更少；单例组HPWL为0，使纯几何目标偏好过度拆分。')
    c.save('08_geometry_greedy',png)

def f09(png):
    c=Canvas(9,'层次合并必须检查整个新组','直线上的三个实例相距100 μm；组内最大两两距离上限为120 μm。')
    for side,x,title in [('a',60,'最近点规则'),('b',770,'完整组检查')]:
        c.text(x+255,205,title,size=28,anchor='middle',weight=700,color=BLUE if side=='a' else TEAL)
        c.rect(x,250,510,175,BG,LINE)
        for k,m in enumerate('ABC'):c.node(x+65+k*190,325,m,sub=f'{k*100} μm')
        c.rect(x+20,260,290,150,'none',TEAL,r=10,sw=3)
        c.line(x+292,325,x+412,325,color=ORANGE,dash='5 5')
        c.text(x+255,455,'B-C最近距离 = 100 μm',size=24,anchor='middle')
        c.text(x+255,505,'合并后A-C = 200 μm',size=27,anchor='middle',color=RED,weight=600)
        c.text(x+255,555,'只看最近点会错误合并' if side=='a' else '拒绝合并，保留两组',size=25,anchor='middle',color=RED if side=='a' else TEAL)
    c.foot('受约束的层次合并：每一次组对合并都调用完整合法性函数，而非只比较最近点。')
    c.save('09_hierarchical',png)

def scatter6(c,x,y,labels,colors,scale=150):
    for k,m in enumerate(labels):
        c.node(x+(k%3)*scale,y+(k//3)*150,m,color=colors[k],r=29)

def f10(png):
    c=Canvas(10,'距离聚类之后仍需容量修复','初始中心位于(0,50)和(200,50) μm；并列实例先分到左簇。',h=700)
    c.rect(50,175,590,385,BG,LINE);c.rect(760,175,590,385,BG,LINE)
    c.text(345,215,'候选分配：左簇超限',size=27,anchor='middle',color=RED,weight=600)
    c.text(1055,215,'把B改分到右簇',size=27,anchor='middle',color=TEAL,weight=600)
    scatter6(c,175,290,'ABCDEF',[BLUE,BLUE,TEAL,BLUE,BLUE,TEAL],165)
    scatter6(c,885,290,'ABCDEF',[BLUE,TEAL,TEAL,BLUE,BLUE,TEAL],165)
    c.line(660,365,735,365,arrow=True)
    c.text(345,520,'ABDE：4个 / 14 mW',size=25,anchor='middle',color=RED)
    c.text(1055,520,'ADE 与 BCF：各3个 / 10 mW',size=24,anchor='middle',color=TEAL)
    c.foot('同色表示同一簇。修复后两组HPWL均为200 μm；簇中心并不自动是控制器合法位置。')
    c.save('10_kmeans_repair',png)

def f11(png):
    c=Canvas(11,'DBSCAN候选区域可能形成长链','ε=110 μm，minPts=2且邻域包含自身；最终组HPWL上限为200 μm。',h=720)
    c.rect(75,205,1250,155,PALE,BLUE)
    xs=[180+260*k for k in range(5)]
    for a,b in zip(xs,xs[1:]):c.line(a+32,280,b-32,280,color=BLUE,width=3)
    for k,x in enumerate(xs):c.node(x,280,chr(65+k),sub=f'{k*100} μm')
    c.text(700,185,'密度连通：一个候选簇，跨度400 μm',size=26,anchor='middle',color=BLUE,weight=600)
    c.text(700,410,'递归拆分并核验',size=24,anchor='middle',color=MUTED)
    c.line(700,425,700,457,arrow=True)
    c.rect(75,470,755,125,'#ECF6F3',TEAL);c.rect(855,470,470,125,'#FCF3E8',ORANGE)
    for k,x in enumerate(xs):c.node(x,525,chr(65+k),color=TEAL if k<3 else ORANGE)
    c.text(450,575,'A/B/C：跨度200 μm',size=23,anchor='middle',color=TEAL)
    c.text(1090,575,'D/E：跨度100 μm',size=23,anchor='middle',color=ORANGE)
    c.foot('密度聚类只生成候选区域。被标记为噪声的孤立宏也必须继续保留并完成测试。')
    c.save('11_dbscan',png)

def f12(png):
    c=Canvas(12,'区域切分与一般成员组合的区别','同样的六个实例，横向切分会留下一个功率超限的子区域。',h=720)
    c.rect(55,180,580,390,BG,LINE);c.rect(765,180,580,390,BG,LINE)
    c.text(345,220,'横向切分：仍需继续拆分',size=25,anchor='middle',color=ORANGE,weight=700)
    c.text(1055,220,'一般组合：两组均合法',size=25,anchor='middle',color=TEAL,weight=700)
    scatter6(c,175,300,'ABCDEF',[RED]*3+[BLUE]*3,165)
    c.line(80,375,610,375,color=ORANGE,width=3,dash='8 6')
    scatter6(c,885,300,'ABCDEF',[BLUE,TEAL,TEAL,BLUE,BLUE,TEAL],165)
    c.text(345,535,'ABC=11 mW；DEF=9 mW',size=24,anchor='middle',color=RED)
    c.text(1055,535,'ADE=10 mW；BCF=10 mW',size=24,anchor='middle',color=TEAL)
    c.foot('矩形划分便于空间组织，但限制了搜索范围；一般组合仍需检查实际HPWL与所有资源。')
    c.save('12_rectangle_split',png)

def f13(png):
    c=Canvas(13,'冲突图着色与存储器分组','边表示不能同组；颜色表示组号。这个独立用例每个实例4 mW，组上限8 mW。')
    cx=360;cy=360;r=180
    pts=[(cx+r*math.cos(-math.pi/2+k*2*math.pi/5),cy+r*math.sin(-math.pi/2+k*2*math.pi/5)) for k in range(5)]
    for k in range(5):c.line(*pts[k],*pts[(k+1)%5],width=3)
    cols=[BLUE,TEAL,BLUE,TEAL,ORANGE]
    for k,(x,y) in enumerate(pts):c.node(x,y,'ABCDE'[k],color=cols[k],r=35)
    for k,(names,col) in enumerate([('A、C',BLUE),('B、D',TEAL),('E',ORANGE)]):
        y=205+k*110;c.box(760,y,560,90,f'颜色{k+1}  →  分组 {{{names}}}','',col)
        c.text(1220,y+47,'8 mW' if k<2 else '4 mW',size=24,anchor='end',color=col)
    c.text(1030,560,'每次着色仍要检查整组资源',size=26,anchor='middle',weight=600)
    c.foot('饱和度是已着色邻居使用的不同颜色数；纯图着色不自动处理三个以上实例的总功率。')
    c.save('13_dsatur',png)

def f14(png):
    c=Canvas(14,'超图保护需要共同考虑的实例关系','超边可以连接多个实例；此图只演示割代价，成员容量另行假设可满足。',h=720)
    c.rect(60,210,580,170,'#EDF3F8',BLUE,r=28);c.rect(760,210,580,170,'#ECF6F3',TEAL,r=28)
    xs=[150,345,540,860,1055,1250]
    c.line(xs[2]+35,295,xs[3]-35,295,color=ORANGE,width=4)
    for x,m in zip(xs,'ABCDEF'):c.node(x,295,m,color=BLUE if m in 'ABC' else TEAL)
    c.text(345,190,'e1={A,B,C}，权重5',size=25,anchor='middle',color=BLUE)
    c.text(1055,190,'e3={D,E,F}，权重5',size=25,anchor='middle',color=TEAL)
    c.text(700,260,'e2：权重1',size=22,anchor='middle',color=ORANGE)
    c.box(60,445,570,140,'划分 ABD / CEF','三条超边均被切开：5+1+5=11',RED)
    c.box(770,445,570,140,'划分 ABC / DEF','只切开中间超边：代价=1',TEAL)
    c.line(650,515,745,515,arrow=True);c.text(700,425,'交换C与D',size=22,anchor='middle',color=MUTED)
    c.foot('亲近关系超图与禁止同组的冲突图含义不同；低割代价不能替代功率、人数和几何检查。')
    c.save('14_hypergraph',png)

def f15(png):
    c=Canvas(15,'窗口卷积首先产生候选区域','示例使用3×3全1窗口；窗口统计不是最终的合法存储器组。',h=700)
    a=[[0,0,0,0,0,0],[0,1,1,0,0,0],[0,1,1,1,0,0],[0,0,1,0,0,0],[0,0,0,0,1,0]]
    x0=80;y0=190;cell=76
    for row in range(5):
        for col in range(6):
            x=x0+col*cell;y=y0+row*cell
            c.rect(x,y,cell,cell,PALE if a[row][col] else WHITE,LINE,r=0)
            if a[row][col]:c.circle(x+cell/2,y+cell/2,14,BLUE,BLUE)
    c.rect(x0+cell,y0+cell,3*cell,3*cell,'none',ORANGE,r=0,sw=5)
    c.text(305,605,'橙色窗口包含6个实例',size=25,anchor='middle',color=ORANGE,weight=700)
    for k,(title,body,col) in enumerate([
        ('1  快速统计','数量得分=6；功率可另设一张网格',BLUE),
        ('2  选择合法成员','每组最多3个；仍需检查功率和相容性',TEAL),
        ('3  删除已分配实例','更新窗口得分；其他实例继续参与分组',ORANGE)]):
        c.box(720,180+k*145,620,117,title,body,col)
        if k<2:c.line(1030,303+k*145,1030,318+k*145,arrow=True)
    c.foot('矩形计数可由积分图加速；网格量化之后仍应使用原始坐标重新检查几何约束。')
    c.save('15_convolution',png)

def f16(png):
    c=Canvas(16,'局部重新分配修正早期选择','一次两换一，再把单例加入剩余容量，可以从三组变成两组。',h=700)
    cols=[(50,'初始分组',[('AB',8),('CDE',9),('F',3)],BLUE),
          (520,'B ↔ D/E',[('ADE',10),('BC',7),('F',3)],ORANGE),
          (990,'再把F加入BC',[('ADE',10),('BCF',10)],TEAL)]
    for x,title,groups,color in cols:
        c.text(x+175,210,title,size=28,anchor='middle',color=color,weight=700)
        for k,(members,p) in enumerate(groups):
            c.rect(x,250+k*95,350,70,WHITE,color)
            c.text(x+25,296+k*95,'{'+','.join(members)+'}',size=27,color=color,weight=600)
            c.text(x+325,296+k*95,f'{p} mW',size=25,anchor='end',color=color)
        c.text(x+175,570,f'{len(groups)} 个控制器组',size=26,anchor='middle',color=color,weight=700)
    c.line(425,380,495,380,arrow=True);c.line(895,380,965,380,arrow=True)
    c.foot('所有中间组均合法；只尝试把F直接塞入原有组，会错过这次改进。')
    c.save('16_local_repair',png)

def f17(png):
    c=Canvas(17,'模拟退火允许受控的暂时变差','只在候选已经满足硬性约束时，按 exp(−ΔJ/τ) 决定是否接受变差。')
    x0=110;y0=540;ww=710;hh=330
    for v in [0,.25,.5,.75,1]:
        y=y0-v*hh;c.line(x0,y,x0+ww,y,color=LINE,width=1);c.text(x0-18,y+7,f'{v:g}',size=21,anchor='end',color=MUTED)
    for d in range(6):c.text(x0+d/5*ww,y0+33,str(d),size=21,anchor='middle',color=MUTED)
    c.line(x0,y0,x0+ww+15,y0,arrow=True);c.line(x0,y0,x0,y0-hh-20,arrow=True)
    c.text(70,175,'接受概率',size=23);c.text(835,582,'ΔJ',size=24)
    for tau,col in [(5,BLUE),(.5,ORANGE)]:
        pts=[(x0+d/5*ww,y0-math.exp(-d/tau)*hh) for d in [k/30 for k in range(151)]]
        c.path(pts,color=col,width=4)
    c.box(950,205,380,145,'τ = 5','ΔJ=2 时，p≈0.670',BLUE)
    c.box(950,390,380,145,'τ = 0.5','ΔJ=2 时，p≈0.018',ORANGE)
    c.foot('τ是搜索参数，不是芯片温度；应保留历史最佳合法解，而不是只输出最后接受的解。')
    c.save('17_annealing',png)

def f18(png):
    c=Canvas(18,'排列编码与保序交叉','保留甲中的C/D片段，其余位置按乙中剩余实例的相对顺序补齐。',h=740)
    sequences=[('父本甲','ABCDEF',205),('父本乙','ADEBCF',310),('子代','AECDBF',450)]
    for title,seq,y in sequences:
        c.text(65,y+33,title,size=27,weight=600)
        for j,m in enumerate(seq):
            col=ORANGE if m in 'CD' and title!='父本乙' else BLUE if title=='父本甲' else TEAL
            c.chip(230+j*115,y,m,w=95,color=col)
    c.path([(1030,230),(1190,230),(1190,474),(965,474)],arrow=True,color=MUTED)
    c.text(1220,350,'保留片段\n避免重复',size=24,anchor='start',color=MUTED)
    c.line(560,514,560,550,arrow=True)
    c.box(220,565,430,100,'解码组1：A/E/C = 10 mW','',TEAL)
    c.box(730,565,430,100,'解码组2：D/B/F = 10 mW','',TEAL)
    c.foot('解码时执行完整合法性检查；组数减少不意味着几何代价同时最小。')
    c.save('18_genetic',png)

def f19(png):
    c=Canvas(19,'候选组覆盖与组数最优性证书','每个实例恰好被选中的一个候选组覆盖；必须说明候选集合是否完整。',h=720)
    cols=['AB','CDE','F','ADE','BCF'];rows=list('ABCDEF')
    x0=130;y0=255;cw=90;rh=45
    for j,g in enumerate(cols):
        if j>=3:c.rect(x0+j*cw-40,y0-58,cw,6*rh+80,'#ECF6F3',TEAL,r=0)
        c.text(x0+j*cw,y0-24,g,size=23,anchor='middle',color=TEAL if j>=3 else BLUE,weight=700)
    for i,m in enumerate(rows):
        c.text(60,y0+i*rh+8,m,size=25,weight=700)
        for j,g in enumerate(cols):
            if m in g:c.circle(x0+j*cw,y0+i*rh,8,TEAL if j>=3 else BLUE,TEAL if j>=3 else BLUE)
            else:c.text(x0+j*cw,y0+i*rh+6,'·',size=23,anchor='middle',color=LINE)
    c.text(350,580,'左区选择ADE与BCF，恰好覆盖A～F',size=23,anchor='middle',color=TEAL)
    c.box(760,190,575,145,'十二实例的组数下界','人数：ceil(12/3)=4\n功率：ceil(40/10)=4',BLUE)
    c.box(760,380,575,150,'找到合法的4组方案','可行值 = 下界 = 4\n因此，该模型下组数最优',TEAL)
    c.text(1047,585,'HPWL次目标另由完整求解核验',size=23,anchor='middle',color=MUTED)
    c.foot('只枚举部分候选时，求解器的“最优”只针对这部分候选；不能忽略候选生成范围。')
    c.save('19_exact_cover',png)

def timeline_axis(c,x,y,scale,end,ticks):
    c.line(x,y,x+end*scale+15,y,arrow=True,width=1.5)
    for t in ticks:
        c.line(x+t*scale,y,x+t*scale,y+7,color=MUTED)
        c.text(x+t*scale,y+31,str(t),size=20,anchor='middle',color=MUTED)

def f20(png):
    c=Canvas(20,'同一分组在不同全局功率预算下运行','四个组均为10 mW、100 μs；硬件最多同时执行两个控制器。',h=700)
    x=255;scale=2.25
    c.text(55,225,'预算20 mW',size=25,color=TEAL,weight=700)
    for lane,groups in [(0,[(0,'G1'),(100,'G3')]),(1,[(0,'G2'),(100,'G4')])]:
        y=195+lane*68
        for start,label in groups:
            c.rect(x+start*scale,y,100*scale,52,COLORS[lane],WHITE,r=5)
            c.text(x+(start+50)*scale,y+35,label,size=26,color=WHITE,anchor='middle',weight=700)
    timeline_axis(c,x,340,scale,400,[0,100,200,300,400])
    c.text(1235,260,'200 μs',size=28,anchor='middle',color=TEAL,weight=700)
    c.text(55,455,'预算15 mW',size=25,color=ORANGE,weight=700)
    for k in range(4):
        c.rect(x+k*100*scale,425,100*scale,65,ORANGE,WHITE,r=5)
        c.text(x+(k*100+50)*scale,467,f'G{k+1}',size=26,color=WHITE,anchor='middle',weight=700)
    timeline_axis(c,x,525,scale,400,[0,100,200,300,400])
    c.text(1235,465,'400 μs',size=28,anchor='middle',color=ORANGE,weight=700)
    c.foot('横轴为 μs；15 mW预算下任意两个10 mW的组都不能并发，硬件并发能力无法全部利用。')
    c.save('20_cp_schedule',png)

def f21(png):
    c=Canvas(21,'固定候选区域的整数最大流分配','源点到实例容量为1；实例只连接允许进入的候选组；候选组具有整数名额。',h=720)
    s=(100,350);ms=[(420,220),(420,350),(420,480)];gs=[(875,265),(875,445)];t=(1270,350)
    for p in ms:c.line(s[0]+34,s[1],p[0]-34,p[1],arrow=True)
    for i,j in [(0,0),(0,1),(1,0),(2,1)]:c.line(ms[i][0]+34,ms[i][1],gs[j][0]-44,gs[j][1],arrow=True)
    for p in gs:c.line(p[0]+44,p[1],t[0]-34,t[1],arrow=True)
    c.node(*s,'s');c.node(*t,'t')
    for i,p in enumerate(ms):c.node(*p,f'M{i+1}',r=34)
    for i,p in enumerate(gs):c.node(*p,f'C{i+1}',color=TEAL,r=44)
    c.text(1060,255,'容量1',size=24,color=TEAL,anchor='middle')
    c.text(1060,460,'容量2',size=24,color=TEAL,anchor='middle')
    c.text(700,580,'M1→C2，M2→C1，M3→C2：总流量3，全部分配成功',size=26,anchor='middle',color=TEAL,weight=600)
    c.foot('贪心若先选M1→C1，会阻塞M2；增广路可改派M1。不同功率的不可拆分实例不能直接套此模型。')
    c.save('21_flow',png)

def f22(png):
    c=Canvas(22,'从算法结果到真实MBIST实现','先生成与工具无关的成员及步骤清单，再使用经过核对的工具适配器。',h=760)
    nodes=[(60,190,'实例与约束','网表／模型／时钟\n初步宏坐标／功率预算',BLUE),
           (520,190,'分组求解器','贪心／聚类／图方法\n局部精确求解或全局模型',TEAL),
           (980,190,'独立合法性检查','完整覆盖／相容／人数\n几何／功率／执行结构',ORANGE),
           (980,450,'工具适配器','Controller + Step + Instance\n转换成目标工具的配置',BLUE),
           (520,450,'EDA规划与插入','核对实际成员及步骤\n生成控制器和接口电路',TEAL),
           (60,450,'实现结果评估','综合面积／测试模式时序\n真实活动、供电和温度',ORANGE)]
    for x,y,t,b,col in nodes:c.box(x,y,360,175,t,b,col)
    c.line(430,280,505,280,arrow=True);c.line(890,280,965,280,arrow=True)
    c.line(1160,378,1160,435,arrow=True)
    c.line(965,535,895,535,arrow=True);c.line(505,535,435,535,arrow=True)
    c.foot('外部分组数不等于工具最终生成的控制器数；必须核对工具计划，不能只检查脚本退出码。')
    c.save('22_integration',png)

def f23(png):
    a=json.loads((ROOT/'results/geometry_greedy.json').read_text());b=json.loads((ROOT/'results/exact_subset_dp.json').read_text())
    c=Canvas(23,'组数、几何与时间的取舍','同一数据与约束的实跑结果：HPWL几何贪心，对照完整子集动态规划。',h=790)
    for x,title,body,col in [(50,'控制器数量','6  →  4',TEAL),(510,'HPWL总和','600  →  800 μm',ORANGE),(970,'估计完成时间','220  →  200 μs',BLUE)]:
        c.box(x,180,380,135,title,'',col);c.text(x+190,282,body,size=31,anchor='middle',color=col,weight=700)
    for x,title,result,col in [(60,'几何贪心',a,BLUE),(770,'完整子集DP',b,TEAL)]:
        c.text(x,375,title,size=28,weight=700,color=col)
        for k,g in enumerate(result['groups']):
            c.text(x+15,420+k*44,'{'+','.join(g['members'])+'}',size=25,color=col,weight=600)
            c.text(x+530,420+k*44,f"{g['power_mw']} mW / {g['hpwl_um']} μm",size=23,anchor='end')
    c.foot('这里只验证自拟模型；更少组数不意味着HPWL总和更小，也没有实测面积或真实布线数据。')
    c.save('23_results',png)

def f24(png):
    c=Canvas(24,'六组和四组方案的事件驱动测试计划','每个任务代表一个同步组；采用固定组功率预算，最多两个控制器并发。',h=735)
    x=220;scale=4.6
    for y,name,title in [(220,'geometry_greedy','6组：220 μs'),(455,'exact_subset_dp','4组：200 μs')]:
        r=json.loads((ROOT/'results'/f'{name}.json').read_text())
        c.text(55,y-30,title,size=26,weight=700,color=BLUE if name.startswith('geometry') else TEAL)
        lane_end=[0,0]
        for e in r['schedule']:
            lane=next(i for i,v in enumerate(lane_end) if v<=e['start_us']);lane_end[lane]=e['end_us']
            group=r['groups'][e['group']];st=e['start_us'];dur=e['end_us']-st
            col=COLORS[lane]
            c.rect(x+st*scale,y+lane*65,dur*scale,55,col,WHITE,r=4)
            txt='/'.join(group['members'])
            c.text(x+(st+dur/2)*scale,y+lane*65+36,txt,size=24,color=WHITE,anchor='middle',weight=600)
        timeline_axis(c,x,y+140,scale,220,[0,100,160,200,220])
    c.foot('横轴为 μs；六组方案功率分段为16、18、6 mW，四组方案两轮都预留20 mW。')
    c.save('24_schedule_comparison',png)

def f25(png):
    c=Canvas(25,'三维芯片的局部温度约束','相同总功率下，垂直对齐的活动区域可能具有不同的热风险。',h=710)
    for y,label in [(185,'上层'),(330,'中层'),(475,'下层')]:
        c.polygon([(95,y+25),(520,y+25),(650,y-25),(225,y-25)],'#EDF3F8',BLUE)
        c.polygon([(95,y+25),(520,y+25),(520,y+65),(95,y+65)],'#DFEAF3',BLUE)
        c.polygon([(520,y+25),(650,y-25),(650,y+15),(520,y+65)],'#D5E3EF',BLUE)
        c.polygon([(285,y+25),(390,y+25),(520,y-25),(415,y-25)],'#EDC996',ORANGE)
        c.text(65,y+50,label,size=24,anchor='end',color=BLUE)
    c.line(395,235,395,310,color=ORANGE,width=3,arrow=True,dash='6 6')
    c.line(395,380,395,455,color=ORANGE,width=3,arrow=True,dash='6 6')
    c.box(795,180,545,120,'局部区域','全局功率合法，不等于所有区域安全',BLUE)
    c.box(795,350,545,120,'温度历史','当前温度受到先前活动和散热影响',TEAL)
    c.box(795,520,545,100,'验证条件','',ORANGE)
    c.text(815,592,'层间耦合、持续时间、冷却与模型误差',size=22)
    c.foot('橙色仅表示垂直对齐的示意活动区域；本图不是目标芯片的温度仿真或热安全证明。')
    c.save('25_thermal',png)

def f26(png):
    c=Canvas(26,'全局预算相同，局部压力可以不同','全局预算20 mW；左、右区域各自上限12 mW；每个组10 mW。',h=710)
    for x,title,bad in [(50,'同一区域同时启动两组',True),(760,'跨区域各启动一组',False)]:
        c.text(x+295,200,title,size=27,anchor='middle',color=RED if bad else TEAL,weight=700)
        for j,label in enumerate(['左侧区域','右侧区域']):
            xx=x+j*305;c.rect(xx,240,280,245,BG,LINE);c.text(xx+140,280,label,size=24,anchor='middle',color=BLUE)
            names=['G1','G2'] if bad and j==0 else [] if bad else ['G1'] if j==0 else ['G3']
            for k,n in enumerate(names):c.chip(xx+70,315+k*63,n+' 10',w=140,color=RED if bad else TEAL)
            power=20 if bad and j==0 else 0 if bad else 10
            c.text(xx+140,460,f'{power} mW '+('> 12' if power>12 else '≤ 12'),size=25,anchor='middle',color=RED if power>12 else TEAL,weight=700)
        c.text(x+295,540,'全局都是20 mW',size=27,anchor='middle',weight=700)
    c.foot('右侧方案下一轮运行G2/G4，仍可在200 μs完成；仅改变调度组合就能满足此例的局部预算。')
    c.save('26_local_power',png)


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--svg-only',action='store_true');args=ap.parse_args()
    for i in range(1,27):
        globals()[f'f{i:02d}'](not args.svg_only)
        print(f'figure {i:02d} complete')

if __name__=='__main__':main()
