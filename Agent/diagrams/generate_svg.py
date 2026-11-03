#!/usr/bin/env python3
"""Generate eight editable SVG diagrams with explicit ports and orthogonal routes.

No SVG markers are used: arrowheads are fixed-size polygons whose tips coincide
with target ports. Coordinates, connections and text boxes are exported for QA.
Fonts remain ordinary editable text; no font binaries are embedded or distributed.
Run: python diagrams/generate_svg.py [--png]
"""
from __future__ import annotations
import argparse
import json
import math
from dataclasses import dataclass
from pathlib import Path
from xml.etree import ElementTree as ET

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / 'assets'
OUT.mkdir(parents=True, exist_ok=True)
NS = 'http://www.w3.org/2000/svg'
ET.register_namespace('', NS)
FONT = 'Noto Sans CJK SC, Microsoft YaHei, PingFang SC, sans-serif'
C = {
    'ink': '#18324B', 'muted': '#52677C', 'border': '#CED9E3',
    'rule': '#E2E9EF', 'blue': '#28649B', 'teal': '#197767',
    'amber': '#9B6419', 'red': '#A54350', 'gray': '#64778A',
    'blue_bg': '#EEF5FC', 'teal_bg': '#EAF6F1', 'amber_bg': '#FFF5E3',
    'red_bg': '#FCEDF0', 'gray_bg': '#F3F6F9', 'white': '#FFFFFF',
}
try:
    from PIL import ImageFont
except ImportError:
    ImageFont = None
_FONT_CACHE = {}

def text_width(text: str, size: float, bold: bool = False) -> float:
    if ImageFont:
        name = 'NotoSansCJK-Bold.ttc' if bold else 'NotoSansCJK-Regular.ttc'
        fp = Path('/usr/share/fonts/opentype/noto') / name
        if fp.exists():
            k = (str(fp), int(size * 4))
            if k not in _FONT_CACHE:
                _FONT_CACHE[k] = ImageFont.truetype(str(fp), k[1])
            return float(_FONT_CACHE[k].getlength(text)) / 4
    # Conservative fallback for geometry-only use outside this environment.
    return sum(size if ord(c) > 255 else size * .61 for c in text)

def sub(parent, tag, **attrs):
    return ET.SubElement(parent, f'{{{NS}}}{tag}', {
        k.replace('_', '-'): str(v) for k, v in attrs.items() if v is not None
    })

@dataclass
class Port:
    node: str
    side: str
    fraction: float
    x: float
    y: float
    kind: str = 'node'

@dataclass
class Node:
    id: str
    x: float
    y: float
    w: float
    h: float
    kind: str = 'node'
    parent: str | None = None
    def p(self, side: str, f: float = .5) -> Port:
        if not 0 <= f <= 1:
            raise ValueError(f'Port fraction outside [0, 1]: {self.id} {f}')
        if side == 'N': x, y = self.x+self.w*f, self.y
        elif side == 'S': x, y = self.x+self.w*f, self.y+self.h
        elif side == 'W': x, y = self.x, self.y+self.h*f
        elif side == 'E': x, y = self.x+self.w, self.y+self.h*f
        else: raise ValueError(side)
        return Port(self.id, side, f, x, y, self.kind)

class Canvas:
    def __init__(self, slug: str, num: int, w: int, h: int, title: str, subtitle: str):
        self.slug, self.num, self.w, self.h = slug, num, w, h
        self.nodes = {}
        self.edges = []
        self.texts = []
        self.s = ET.Element(f'{{{NS}}}svg', {
            'width': str(w), 'height': str(h), 'viewBox': f'0 0 {w} {h}',
            'role': 'img', 'aria-labelledby': 'title description',
        })
        sub(self.s, 'title', id='title').text = f'图 {num}  {title}'
        sub(self.s, 'desc', id='description').text = subtitle
        self.bg = sub(self.s, 'g', id='background')
        self.shapes = sub(self.s, 'g', id='nodes')
        self.lines = sub(self.s, 'g', id='connections')
        self.labels = sub(self.s, 'g', id='labels', font_family=FONT)
        self.rect(0, 0, w, h, 'white', stroke='none', layer=self.bg, rx=0)
        self.text(48, 64, f'{num:02d}', 25, 'blue', bold=True)
        self.text(112, 64, title, 34, 'ink', bold=True)
        self.text(48, 105, subtitle, 19, 'muted')
        sub(self.bg, 'line', x1=48, y1=128, x2=w-48, y2=128,
            stroke=C['rule'], stroke_width=1.5)
    def color(self, color): return C.get(color, color)
    def rect(self, x, y, w, h, fill='gray_bg', stroke='border', rx=12, layer=None):
        return sub(layer if layer is not None else self.shapes, 'rect',
            x=x, y=y, width=w, height=h, rx=rx,
            fill=self.color(fill), stroke=self.color(stroke), stroke_width=1.4)
    def text(self, x, y, text, size=20, color='ink', bold=False, anchor='start', owner=None):
        e=sub(self.labels, 'text', x=x, y=y, font_size=size,
              fill=self.color(color), font_weight=700 if bold else 400, text_anchor=anchor)
        e.text=text
        width=text_width(text, size, bold)
        left=x-(width/2 if anchor=='middle' else width if anchor=='end' else 0)
        self.texts.append({'text':text,'box':[left,y-size*.88,width,size*1.12],
                           'owner':owner,'fontSize':size})
        return e
    def label(self, x, y, text, color='muted', size=18, anchor='middle'):
        return self.text(x,y,text,size,color,anchor=anchor)
    def panel(self, id, x, y, w, h, title=None, subtitle=None, fill='white'):
        n=Node(id,x,y,w,h,'panel')
        self.nodes[id]=n
        self.rect(x,y,w,h,fill,layer=self.bg)
        if title: self.text(x+24,y+38,title,24,'ink',True)
        if subtitle: self.text(x+24,y+70,subtitle,18,'muted')
        return n
    def node(self, id, x,y,w,h,title,desc=(),tone='blue',center=False,ts=23,ds=19,parent=None):
        n=Node(id,x,y,w,h,'node',parent)
        if id in self.nodes: raise ValueError(f'duplicate node {id}')
        self.nodes[id]=n
        g=sub(self.shapes,'g',id=id)
        sub(g,'title').text=title + ('；'+'；'.join(desc) if desc else '')
        sub(g,'rect',x=x,y=y,width=w,height=h,rx=12,
            fill=C[tone+'_bg'],stroke=C['border'],stroke_width=1.5)
        # Restrained left accent, entirely inside the shape.
        sub(g,'rect',x=x+1,y=y+17,width=4,height=max(12,h-34),rx=2,
            fill=C[tone],stroke='none')
        tx=x+w/2 if center else x+22
        anc='middle' if center else 'start'
        baseline=y+36 if h>=100 else y+31
        self.text(tx,baseline,title,ts,'ink',True,anc,id)
        for i,line in enumerate(desc):
            self.text(tx,baseline+31+i*27,line,ds,'muted',False,anc,id)
        return n
    def bar(self,id,x,y,w,h=10,parent=None):
        n=Node(id,x,y,w,h,'bar',parent);self.nodes[id]=n
        self.rect(x,y,w,h,'ink','ink',rx=4)
        return n
    def edge(self, source:Port, target:Port, via=(), color='blue', dashed=False,
             arrow=True, relation='', id=None, allow_cross=False):
        pts=[(float(source.x),float(source.y))]+[(float(x),float(y)) for x,y in via]+[(float(target.x),float(target.y))]
        clean=[]
        for p in pts:
            if not clean or p!=clean[-1]: clean.append(p)
        pts=clean
        if len(pts)<2: raise ValueError('zero length connection')
        for a,b in zip(pts,pts[1:]):
            if abs(a[0]-b[0])>1e-6 and abs(a[1]-b[1])>1e-6:
                raise ValueError(f'Non-orthogonal edge: {source.node}->{target.node}: {a} {b}')
        eid=id or f'e{len(self.edges)+1:02d}'
        g=sub(self.lines,'g',id=eid,**{'data-source':source.node,'data-target':target.node})
        sub(g,'title').text=relation or f'{source.node} → {target.node}'
        shaft=list(pts)
        if arrow:
            a,b=pts[-2:]
            dx,dy=b[0]-a[0],b[1]-a[1]
            length=math.hypot(dx,dy)
            if length<19: raise ValueError(f'Final segment too short: {eid}')
            ux,uy=dx/length,dy/length
            # Fixed user-space arrowhead: 12 px long by 11 px wide.
            base=(b[0]-12*ux,b[1]-12*uy)
            shaft[-1]=base
            head=[b,(base[0]-5.5*uy,base[1]+5.5*ux),(base[0]+5.5*uy,base[1]-5.5*ux)]
        sub(g,'polyline',points=' '.join(f'{x:g},{y:g}' for x,y in shaft),fill='none',
            stroke=C[color],stroke_width=2.6,stroke_linejoin='round',stroke_linecap='round',
            stroke_dasharray='7 6' if dashed else None)
        if arrow: sub(g,'polygon',points=' '.join(f'{x:g},{y:g}' for x,y in head),fill=C[color])
        self.edges.append({'id':eid,'source':vars(source),'target':vars(target),'points':pts,
                           'color':color,'dashed':dashed,'arrow':arrow,'relation':relation,
                           'allowCross':allow_cross})
    def note(self,x,y,w,lines,tone='gray',size=19):
        h=28*len(lines)+28
        self.rect(x,y,w,h,tone+'_bg',stroke='none',rx=10,layer=self.bg)
        for i,t in enumerate(lines):self.text(x+20,y+30+28*i,t,size,'muted')
    def footer(self, text, extra=None):
        y=self.h-54
        sub(self.bg,'line',x1=48,y1=y-26,x2=self.w-48,y2=y-26,stroke=C['rule'],stroke_width=1.3)
        self.text(48,y,text,18,'muted')
        if extra:self.text(self.w-48,y,extra,16,'muted',anchor='end')
    def save(self):
        ET.indent(self.s,space='  ')
        ET.ElementTree(self.s).write(OUT/f'{self.slug}.svg',encoding='utf-8',xml_declaration=True)
        return {'file':f'{self.slug}.svg','number':self.num,'width':self.w,'height':self.h,
                'nodes':[vars(n) for n in self.nodes.values()], 'edges':self.edges,'texts':self.texts}

all_figures=[]

# 01 — architecture: explicit APIs, return path, one runtime.
c=Canvas('01_总体架构',1,1600,1210,'平台总体架构','界面提交定义与操作；LangGraph.js 执行工作流；工具、持久化和观测各有独立职责。')
ui=c.node('ui',430,172,710,112,'统一工作区', ['项目管理 · Team Designer · Workflow Editor · Chat · Run Inspector'],center=True,ds=18)
api=c.node('api',430,360,710,108,'Studio API 与项目服务',['配置 / 版本 / 会话 / 审批 / 权限 / 运行事件'],tone='gray',center=True)
compiler=c.node('compiler',430,548,710,108,'定义校验与图编译',['版本化 Schema → 检查引用与连接规则 → 编译可执行 Graph'],center=True,ds=18)
runtime=c.node('runtime',430,742,710,148,'LangGraph.js 运行核心',['Graph 内调用 Agent、Task Scheduler 与 Gate', '状态更新 · 条件路由 · 子图 · interrupt / resume'],tone='teal',center=True,ds=18)
tools=c.node('tools',48,742,310,148,'模型与工具适配',['Model / MCP / EDA','真实进程、权限与预算'],tone='teal',ts=23,ds=19)
store=c.node('storage',1212,360,340,172,'本地持久化',['项目 / 版本 / 任务 / 事件','Thread / Checkpoint','产物索引与执行账本'],tone='gray')
obs=c.node('observability',1212,742,340,148,'观测服务（可选）',['本地 Run Events','Langfuse / OpenTelemetry'],tone='gray',ts=23,ds=18)
art=c.node('workspace',430,1010,710,108,'工程工作区与证据',['源码、镜像、日志、波形及报告；状态中保存引用与摘要'],tone='amber',center=True)
c.edge(ui.p('S',.30),api.p('N',.30),relation='用户操作通过 API 提交')
c.label(660,326,'操作请求',anchor='start')
c.edge(api.p('N',.73),ui.p('S',.73),color='teal',relation='服务端返回已提交运行事件')
c.label(965,326,'状态 / 事件',color='teal',anchor='start')
c.edge(api.p('S'),compiler.p('N'),relation='校验并固定发布版本')
c.label(807,512,'校验并固定版本',anchor='start')
c.edge(compiler.p('S'),runtime.p('N'),relation='传入编译后的固定版本 Graph')
c.label(807,704,'启动固定版本',anchor='start')
c.edge(runtime.p('W',.30),tools.p('E',.30),relation='运行核心请求模型或工具')
c.label(394,774,'调用',size=17)
c.edge(tools.p('E',.73),runtime.p('W',.73),color='teal',relation='工具适配返回真实执行结果')
c.label(394,837,'结果',color='teal',size=17)
c.edge(api.p('E',.5),store.p('W',54/172),relation='项目服务写入配置与运行记录')
c.label(1176,402,'配置',size=17)
c.edge(runtime.p('N',.90),store.p('S'),via=[(1069,698),(1382,698)],relation='Checkpoint 与执行状态持久化请求')
c.label(1225,680,'Checkpoint / 状态读写',size=18)
c.edge(runtime.p('E',.30),obs.p('W',.30),color='gray',dashed=True,relation='可选观测事件投递，不阻塞核心执行')
c.label(1176,774,'事件',color='gray',size=17)
c.edge(runtime.p('S'),art.p('N'),color='amber',relation='登记实际产物与工具证据')
c.label(807,953,'登记产物与工具证据',color='amber',anchor='start')
c.footer('实线：按标注方向发起调用或返回结果。虚线：可选观测事件。持久化框表示逻辑能力，不要求使用同一张表。')
all_figures.append(c.save())

# 02 — four independent views; cross-view references are NOT control edges.
c=Canvas('02_四层图模型',2,1600,1060,'四种图视图与统一标识','团队授权、流程控制、任务依赖、运行事实分别展示；视图之间的引用不代表执行先后。')
p1=c.panel('team_panel',48,168,710,316,'角色协作图','定义谁可以委派、提交、反馈；不直接启动任务。')
p2=c.panel('flow_panel',842,168,710,316,'流程定义图','定义步骤、分支、并行、验收和退出规则。')
p3=c.panel('task_panel',48,634,710,316,'任务依赖图','具体交付任务的前置关系；依赖子图保持 DAG。')
p4=c.panel('run_panel',842,634,710,316,'运行执行图','从真实运行事件生成只读视图，不再编辑控制规则。')
lead=c.node('leader',88,306,190,80,'Leader',center=True,parent='team_panel',ts=22)
rtl=c.node('rtl_role',470,274,240,78,'RTL 角色',tone='teal',center=True,parent='team_panel',ts=22)
dv=c.node('dv_role',470,392,240,68,'验证角色',tone='amber',center=True,parent='team_panel',ts=22)
c.edge(lead.p('E',.30),rtl.p('W'),via=[(372,330),(372,313)],relation='授权 Leader 向 RTL 角色分配任务')
c.edge(lead.p('E',.80),dv.p('W'),via=[(344,370),(344,426)],relation='授权 Leader 向验证角色分配任务')
c.label(393,300,'委派',size=17)
c.label(393,411,'委派',size=17)
fn=[]
for id,x,t,tone in [('start',878,'阶段 A','blue'),('step',1113,'阶段 B','teal'),('gate',1348,'验收 Gate','amber')]:
    fn.append(c.node(id,x,325,168,82,t,center=True,tone=tone,ts=21,parent='flow_panel'))
c.edge(fn[0].p('E'),fn[1].p('W'),relation='阶段 A 完成后进入阶段 B')
c.edge(fn[1].p('E'),fn[2].p('W'),relation='阶段 B 提交后进入独立验收')
c.label(1197,453,'箭头 = 允许的控制转移',size=18)
contract=c.node('contract',88,773,190,80,'接口契约',center=True,parent='task_panel',ts=22)
t1=c.node('rtl_task',470,741,240,78,'CPU RTL 任务',center=True,tone='teal',parent='task_panel',ts=21)
t2=c.node('sw_task',470,859,240,68,'软件启动任务',center=True,tone='teal',parent='task_panel',ts=21)
c.edge(contract.p('E',.30),t1.p('W'),via=[(372,797),(372,780)],relation='CPU RTL 任务依赖接口契约')
c.edge(contract.p('E',.80),t2.p('W'),via=[(344,837),(344,893)],relation='软件启动任务依赖接口契约')
c.label(393,765,'依赖',size=17)
c.label(393,878,'依赖',size=17)
rn=[]
for id,x,t,tone in [('run',878,'任务开始','blue'),('tool',1113,'工具返回','teal'),('decision',1348,'验收事件','amber')]:
    rn.append(c.node(id,x,791,168,82,t,center=True,tone=tone,ts=21,parent='run_panel'))
c.edge(rn[0].p('E'),rn[1].p('W'),color='gray',relation='事件记录显示工具运行已结束')
c.edge(rn[1].p('E'),rn[2].p('W'),color='gray',relation='后续出现独立验收事件')
c.label(1197,919,'箭头 = 已发生事件的先后',size=18)
ids=c.node('identities',48,534,1504,50,'Project · WorkflowVersion · TeamInstance · TaskId · ThreadId / RunId · ArtifactId',tone='gray',center=True,ts=20)
for p, side in [(p1,'S'),(p2,'S')]:
    c.edge(p.p(side),ids.p('N',(p.x+p.w/2-48)/1504),color='gray',dashed=True,arrow=False,relation='通过稳定标识引用，无执行方向')
for p in [p3,p4]:
    c.edge(ids.p('S',(p.x+p.w/2-48)/1504),p.p('N'),color='gray',dashed=True,arrow=False,relation='通过稳定标识引用，无执行方向')
c.footer('框内箭头按各自视图解释；连接标识条的虚线无箭头，只表示对象引用，不能编译为 Workflow 控制边。')
all_figures.append(c.save())

# 03 — authority and actual acceptance are deliberately separate panels.
c=Canvas('03_团队角色协作',3,1600,1090,'团队角色与交付协作','左侧定义授权，右侧展示一次任务交付；独立验收通过后，调度器才释放下游依赖。')
left=c.panel('authority',48,168,560,812,'A  角色授权','模板规定职责与权限，不表示固定执行次序。')
right=c.panel('execution',652,168,900,812,'B  一次任务的交付协议','派工、交付、验收、返工各有明确方向。')
lead=c.node('leader',180,294,300,110,'Leader / Supervisor',['任务规划 · 委派 · 升级'],center=True,parent='authority',ts=23,ds=18)
worker=c.node('worker_role',80,520,222,112,'专业执行角色',['RTL / 软件 / EDA'],tone='teal',center=True,parent='authority',ts=22,ds=18)
review=c.node('review_role',354,520,222,112,'独立验证角色',['验证 / 审核 / Gate'],tone='amber',center=True,parent='authority',ts=22,ds=18)
c.edge(lead.p('S',.25),worker.p('N'),via=[(255,458),(191,458)],relation='Leader 被授权向专业执行角色派工')
c.edge(lead.p('S',.75),review.p('N'),via=[(405,458),(465,458)],relation='Leader 被授权向独立验证角色派工')
c.label(328,493,'委派权限',size=18)
c.note(80,693,496,['每个角色可生成多个独立成员实例。','关键验收不由同一执行者自我批准。','文件范围、工具授权、预算由运行时强制检查。'],size=18)
c.note(80,837,496,['协作消息本身不解锁任务。','是否可执行仍由流程、依赖与资源决定。'],tone='blue',size=18)
s=c.node('scheduler',700,294,304,110,'Task Scheduler',['依赖满足后派工'],center=True,parent='execution',ts=23,ds=19)
a=c.node('member',1200,294,304,110,'专业 Agent',['按任务契约执行'],tone='teal',center=True,parent='execution',ts=23)
g=c.node('reviewer_gate',1200,574,304,126,'独立验收 Gate',['真实证据 + 审核规则','通过 / 返工 / 阻塞'],tone='amber',center=True,parent='execution',ts=23,ds=18)
accepted=c.node('accepted',700,574,304,126,'登记 Accepted',['固定产物版本','保留验收记录'],tone='teal',center=True,parent='execution',ts=23,ds=18)
nextn=c.node('next_task',700,824,304,110,'下游任务进入 Ready',['再检查权限与资源'],center=True,parent='execution',ts=21,ds=18)
blocked=c.node('blocked',1200,824,304,110,'阻塞并升级处理',['证据不足或预算耗尽'],tone='red',center=True,parent='execution',ts=21,ds=18)
c.edge(s.p('E'),a.p('W'),relation='1. 调度器派发满足依赖的任务')
c.label(1102,334,'1  派工',size=18)
c.edge(a.p('S',.35),g.p('N',.35),color='teal',relation='2. 提交产物与真实工具证据')
c.label(1325,479,'2  交付',color='teal',anchor='start',size=18)
c.edge(g.p('N',.80),a.p('S',.80),color='amber',dashed=True,relation='可修复且预算允许时退回同一任务执行者')
c.label(1460,533,'返工',color='amber',anchor='start',size=18)
c.edge(g.p('W',.42),accepted.p('E',.42),color='teal',relation='3. 验收通过后登记任务接受状态')
c.label(1102,612,'3  验收通过',color='teal',size=18)
c.edge(accepted.p('S'),nextn.p('N'),color='teal',relation='4. 已验收任务释放下游依赖')
c.label(872,770,'4  释放依赖',color='teal',anchor='start',size=18)
c.edge(g.p('S'),blocked.p('N'),color='red',relation='无法自动修复时阻塞并通知 Leader 或人工')
c.label(1374,770,'不可自动修复',color='red',anchor='start',size=18)
c.footer('蓝线：授权或派工（以面板标题为准）。绿线：交付与通过。橙色虚线：有界返工。红线：阻塞升级。')
all_figures.append(c.save())

# 04 — normal state path + bounded rework; exception behavior is a separate matrix.
c=Canvas('04_任务执行状态机',4,1760,1220,'任务状态与有界返工','任务和执行尝试分开记录；验收失败后重新排队，不允许直接跳到“执行中”或“已通过”。')
c.text(48,184,'A  正常路径与可修复的验收失败',24,'ink',True)
xs=[48,340,632,924,1216,1508]
labels=[('created','已创建','Created','gray'),('ready','可执行','Ready','blue'),('claimed','已领取','Claimed','blue'),('running','执行中','Running','teal'),('review','待验收','Review','amber'),('accepted','已通过','Accepted','teal')]
ns=[]
for x,(id,title,en,tone) in zip(xs,labels):
    ns.append(c.node(id,x,254,204,114,title,[en],tone=tone,center=True,ts=24,ds=19))
for i,label in enumerate(['依赖满足','领取','启动','提交','验收通过']):
    c.edge(ns[i].p('E'),ns[i+1].p('W'),color='teal' if i==4 else 'blue',relation=label)
    c.label((ns[i].x+ns[i].w+ns[i+1].x)/2,294,label,color='teal' if i==4 else 'muted',size=17)
r=c.node('rework',1216,540,320,120,'待修复 / Rework',['保留缺陷、日志和旧 Attempt','返工次数与修改范围受限'],tone='amber',center=True,ts=23,ds=18)
c.edge(ns[4].p('S'),r.p('N',102/320),color='amber',relation='审核拒绝，且可修复、预算充足')
c.label(1340,460,'可修复、预算充足',color='amber',anchor='start',size=18)
c.edge(r.p('W'),ns[1].p('S'),via=[(442,600)],color='amber',dashed=True,relation='新建 Attempt，重新检查前置条件并进入 Ready')
c.label(814,579,'新建 Attempt → 重新排队 → 再次领取',color='amber',size=19)
c.note(48,636,1060,['Accepted 必须有可核验的交付物、工具记录和独立验收。','模型报告、工具退出码为 0，都不能单独替代工程验收。'],size=19)
# Three independent exception cards avoid false blanket state transitions.
c.text(48,759,'B  异常状态的进入与恢复规则',24,'ink',True)
c.text(48,795,'以下规则作用于适用的非终态；不把所有异常统一画成“直接恢复执行”。',19,'muted')
for id,x,title,desc,tone in [
    ('human',48,'等待人工 / Waiting Human',['触发：当前阶段要求人工决策。','批准：恢复被暂停阶段的检查。','拒绝：按规则返工、阻塞或取消。','不能因批准而绕过后续验收。'],'amber'),
    ('blocked',632,'已阻塞 / Blocked',['触发：外部故障、预算或权限问题。','解除后先核对执行账本与产物。','可恢复：从安全暂停点继续。','需重试：新建 Attempt 后回到 Ready。'],'red'),
    ('cancelled',1216,'已取消 / Cancelled',['触发：用户停止或明确终止策略。','确认进程与资源已妥善处理。','本次运行终止，不自动恢复。','再次执行需显式创建新的运行。'],'gray'),
]:
    c.node(id,x,834,496,224,title,desc,tone=tone,ts=23,ds=19)
c.footer('上图箭头只表示 A 部分的状态转移；B 部分说明异常恢复条件。旧 Attempt 与已接受的历史证据均不可覆盖。')
all_figures.append(c.save())

# 05 — provenance chain; upstream change is a separate triggering event.
c=Canvas('05_交付物与验收证据',5,1760,1200,'交付物、验收证据与版本变更','正常交付与输入变更是两类不同事件；旧证据保留，但不自动证明新版本仍然有效。')
c.text(48,184,'A  正常交付与独立验收',24,'ink',True)
steps=[('input',48,'任务输入契约',['Spec 与输入版本','验收标准与修改范围'],'blue'),
       ('execute',392,'真实工具执行',['隔离工作区与授权','采集源码、命令、日志'],'teal'),
       ('evidence',736,'证据登记',['退出码 / 工具版本','产物哈希 / 检查结果'],'amber'),
       ('review',1080,'独立验收',['自动检查 + Review','必要时等待人工'],'amber'),
       ('release',1424,'接受并发布',['保存固定产物版本','释放下游依赖'],'teal')]
nodes=[]
for id,x,t,d,tone in steps:nodes.append(c.node(id,x,244,288,154,t,d,tone=tone,ts=22,ds=18))
for i in range(4):c.edge(nodes[i].p('E'),nodes[i+1].p('W'),color='teal' if i==3 else 'blue',relation=f'{steps[i][2]} → {steps[i+1][2]}')
record=c.node('record',556,508,648,174,'EvidenceRecord（记录内容展开）',[
    'taskId · attemptId · artifactId · inputVersion',
    'command · cwd · exitCode · toolVersion · logHash',
    'checks[] · reviewer · decision · timestamps'
],tone='gray',center=True,ts=23,ds=19)
c.edge(nodes[2].p('S'),record.p('N'),color='gray',dashed=True,arrow=False,relation='展示证据记录字段，不增加执行步骤')
c.label(902,462,'字段展开',color='gray',anchor='start',size=18)
c.note(48,526,440,['缺失记录应标为 missing / unknown。','不得由模型编造工具版本、日志或哈希。'],tone='amber',size=18)
c.note(1272,526,440,['退出码为 0 ≠ 工程验收通过。','拒绝时生成 Issue，按有界返工处理。'],tone='amber',size=18)
c.text(48,782,'B  输入版本发生变化时',24,'ink',True)
c.text(48,818,'这是独立的变更事件，不是“每次交付完成后必须执行”的步骤。',19,'muted')
changes=[('change',48,330,'输入 Artifact 改变',['版本或内容哈希变化'],'red'),
         ('impact',492,330,'查找受影响任务',['沿已登记的输入依赖追踪'],'amber'),
         ('revalidate',936,330,'生成重新验证计划',['旧结果标记为非当前有效'],'amber'),
         ('new_decision',1380,332,'形成新版验收记录',['实际重新执行并独立验收'],'teal')]
cn=[]
for id,x,w,t,d,tone in changes:cn.append(c.node(id,x,876,w,126,t,d,tone=tone,ts=22,ds=18))
for a,b in zip(cn,cn[1:]):c.edge(a.p('E'),b.p('W'),color='amber',relation=f'{a.id} → {b.id}')
c.footer('实线：产物与验收流转。无箭头虚线：记录内容展开。历史证据保留，新版本需要独立的有效性判断。')
all_figures.append(c.save())

# 06 — sequence diagram: endpoints are the actual lifelines, not offsets.
c=Canvas('06_执行与暂停恢复时序',6,1760,2040,'人工审批、真实工具执行与恢复时序','先保存状态和事件，再通知界面；恢复时核对执行账本，防止重复执行外部命令。')
actors=[('gui',128,'用户 / GUI'),('service',424,'运行服务'),('graph',720,'LangGraph'),('db',1016,'持久化层'),('tool',1312,'工具进程'),('gate',1608,'验收服务')]
actor_x={id:x for id,x,t in actors}
for id,x,t in actors:
    c.node(id,x-120,170,240,70,t,center=True,ts=23)
    sub(c.bg,'line',x1=x,y1=240,x2=x,y2=1900,stroke=C['border'],stroke_width=1.4,stroke_dasharray='5 7')

def msg(a,b,y,text,reply=False,tone='blue'):
    p=Port(a,'L',0,actor_x[a],y,'lifeline');q=Port(b,'L',0,actor_x[b],y,'lifeline')
    c.edge(p,q,color=tone,dashed=reply,relation=text,allow_cross=True)
    c.label((actor_x[a]+actor_x[b])/2,y-13,text,color=tone,size=18)

rows=[
 ('gui','service','启动：固定版本与任务',False,'blue'),
 ('service','db','登记版本、任务与 Run',False,'blue'),
 ('service','graph','执行（thread_id）',False,'blue'),
 ('graph','db','保存中断状态 / Checkpoint',False,'amber'),
 ('graph','service','interrupt：等待人工',True,'amber'),
 ('service','db','提交待审批事件',False,'amber'),
 ('service','gui','推送审批请求',True,'amber'),
 ('gui','service','批准（同一 thread_id）',False,'teal'),
 ('service','db','记录审批决定与权限校验',False,'teal'),
 ('service','graph','Command({ resume })',False,'teal'),
 ('graph','db','查询 operationId 账本',False,'blue'),
 ('db','graph','未执行；允许本次调用',True,'gray'),
 ('graph','service','提交已授权工具请求',False,'blue'),
 ('service','db','核对并登记 operationId / started',False,'blue'),
 ('service','tool','启动受控工具进程',False,'blue'),
 ('tool','service','完成：退出码、日志与产物',True,'teal'),
 ('service','db','写入真实结果与执行记录',False,'teal'),
 ('service','graph','返回工具结果引用',True,'teal'),
 ('graph','gate','请求独立验收',False,'blue'),
 ('gate','graph','判定与证据引用',True,'teal'),
 ('graph','db','保存阶段状态 / Checkpoint',False,'teal'),
 ('graph','service','返回阶段结果',True,'teal'),
 ('service','db','提交可重放运行事件',False,'teal'),
 ('service','gui','推送已提交状态',True,'teal'),
]
y=294
for i,row in enumerate(rows):
    if i==7:
        c.rect(48,y-24,1664,42,'amber_bg',stroke='none',rx=6,layer=c.bg)
        c.label(880,y+4,'暂停区间：待批准的工具命令尚未执行',color='amber',size=19)
        y+=80
    msg(row[0],row[1],y,row[2],row[3],row[4])
    y+=64
c.note(48,1922,1664,['实线为请求，虚线为返回；箭头尖端严格落在接收方生命线上。图中仅展示审批通过且工具尚未执行的分支。'],size=18)
all_figures.append(c.save())

# 07 — explicit fork/join, isolated local feedback loops, no dangling buses.
c=Canvas('07_RV32IMAC_团队示例',7,1760,1640,'RV32IMAC SoC：软硬件团队工作流','CPU、RAM、UART 与裸机软件在冻结接口后并行开发；最终以真实 RTL 仿真运行 C 程序为验收依据。')
a=c.node('architecture',560,174,640,118,'架构与接口契约（Architect）',['RV32IMAC · 五级流水 · 模块接口 · 软件运行目标','Memory Map、CSR / 异常方案和验收标准由团队确定'],center=True,ts=24,ds=19)
g=c.node('architecture_gate',560,370,640,104,'架构评审 Gate',['接口与验收条件确认后，才允许并行开发'],tone='amber',center=True,ts=24,ds=19)
c.edge(a.p('S'),g.p('N'),relation='提交架构与接口契约进行评审')
c.label(904,339,'评审',anchor='start',size=19)
fork=c.bar('fork',174,550,1412,10)
c.edge(g.p('S'),fork.p('N'),relation='架构评审通过，进入并行区域')
c.label(904,520,'通过后拆分',anchor='start',size=19)
branches=[
 ('cpu',48,'CPU RTL 开发',['IF / ID / EX / MEM / WB','冒险、前递与 IMAC 指令'],'CPU 独立验证',['指令、分支、访存与流水线','真实测试、波形与结果']),
 ('ram',472,'RAM 开发',['程序、数据与栈存储','访问接口与镜像加载'],'RAM 独立验证',['读写、对齐与访问异常','验证指定输入版本']),
 ('uart',896,'UART 开发',['MMIO 寄存器与串口收发','软件可访问的状态与数据'],'UART 独立验证',['寄存器、发送与接收','实际信号与输出检查']),
 ('software',1320,'裸机软件开发',['startup / linker / UART 驱动','C 测试与程序镜像'],'软件构建验证',['真实交叉编译与链接','ELF、镜像与启动检查'])
]
checks=[]
for key,x,title,desc,vt,vd in branches:
    dev=c.node(key+'_dev',x,646,392,142,title,desc,tone='teal',center=True,ts=24,ds=19)
    check=c.node(key+'_check',x,928,392,142,vt,vd,tone='amber',center=True,ts=23,ds=19)
    cx=x+196
    c.edge(fork.p('S',(cx-174)/1412),dev.p('N'),relation=f'启动 {title}')
    c.edge(dev.p('S',.32),check.p('N',.32),color='teal',relation=f'{title}提交指定版本给独立验证')
    c.label(x+144,849,'提交',color='teal',anchor='start',size=18)
    c.edge(check.p('N',.77),dev.p('S',.77),color='amber',dashed=True,relation=f'{vt}未通过且预算允许，返回同支路开发')
    c.label(x+322,895,'返工',color='amber',anchor='start',size=18)
    checks.append(check)
join=c.bar('join',174,1170,1412,10)
for check in checks:
    cx=check.x+check.w/2
    c.edge(check.p('S'),join.p('N',(cx-174)/1412),color='teal',relation='该分支所有必需校验通过后到达 AND 汇合')
    c.label(cx+19,1127,'通过',color='teal',anchor='start',size=18)
c.label(880,1152,'AND：全部必需分支通过',color='teal',size=19)
soc=c.node('soc_test',560,1248,640,116,'SoC 集成与系统验证',['C → ELF / 镜像 → RAM 加载 → RTL 仿真','自动检查 UART 输出、退出状态与测试结果'],center=True,ts=24,ds=19)
delivery=c.node('delivery',560,1442,640,110,'独立交付验收',['固定源码、工具版本、日志、产物哈希与未解决风险'],tone='teal',center=True,ts=24,ds=19)
c.edge(join.p('S'),soc.p('N'),color='teal',relation='全部必需支路通过后解锁系统级验证')
c.edge(soc.p('S'),delivery.p('N'),color='teal',relation='真实系统回归通过后进行独立交付验收')
c.label(904,1403,'系统回归通过',color='teal',anchor='start',size=19)
c.footer('横条是显式并行拆分 / AND 汇合；橙色虚线仅回到本支路。系统失败由 Issue 定位责任任务后重新验证。')
all_figures.append(c.save())

# 08 — wireframe: a real workflow, not a mixed leader/task graph.
c=Canvas('08_工作区交互界面',8,1760,1220,'统一工作区与图形交互','布局与运行状态均为目标设计示意；Team、Workflow 和 Run 分开编辑或查看，Chat 共享同一任务上下文。')
c.rect(48,164,1664,68,'gray_bg')
c.text(70,207,'Agent Studio',25,'ink',True)
c.text(310,205,'RV32IMAC-SoC',22,'ink',True)
c.text(600,205,'Workflow v12 · 已发布',20,'teal',True)
for x,txt,tone in [(1240,'运行','teal'),(1370,'暂停','amber'),(1500,'保存','blue')]:
    c.rect(x,180,112,36,tone+'_bg',stroke='none',rx=8)
    c.text(x+56,205,txt,19,tone,True,'middle')
sidebar=c.panel('sidebar',48,248,250,864,fill='gray_bg')
for y,t,items in [(290,'项目',['RV32IMAC-SoC','DFT-Automation']), (464,'团队与角色',['Leader / Architect','RTL / DV / Software']), (638,'流程与会话',['SoC Workflow','模块验证模板','Chat Sessions']), (848,'运行与产物',['运行历史','Evidence / Artifacts','工具与模型设置'])]:
    c.text(70,y,t,22,'ink',True)
    for i,it in enumerate(items):c.text(78,y+41+i*36,it,18,'muted')
flow=c.panel('canvas',316,248,1000,548,fill='white')
c.text(340,286,'Workflow',22,'blue',True)
c.text(512,286,'Team',20,'muted')
c.text(614,286,'Run',20,'muted')
c.text(1288,286,'固定版本 · 图形编辑',18,'muted',anchor='end')
n1=c.node('spec',370,358,216,86,'规格确认',center=True,ts=23,parent='canvas')
n2=c.node('dev',710,358,216,86,'并行开发',tone='teal',center=True,ts=23,parent='canvas')
n3=c.node('gate',1050,358,216,86,'独立验收',tone='amber',center=True,ts=23,parent='canvas')
n4=c.node('regression',1050,626,216,86,'系统回归',center=True,ts=23,parent='canvas')
n5=c.node('release',710,626,216,86,'发布交付',tone='teal',center=True,ts=23,parent='canvas')
c.edge(n1.p('E'),n2.p('W'),relation='规格确认后开始并行开发')
c.edge(n2.p('E'),n3.p('W'),relation='开发提交到独立验收')
c.edge(n3.p('S',.70),n4.p('N',.70),color='teal',relation='验收通过后开始系统回归')
c.label(1220,550,'通过',color='teal',anchor='start',size=18)
c.edge(n3.p('S',.25),n2.p('S'),via=[(1104,530),(818,530)],color='amber',dashed=True,relation='验收失败且预算允许时退回开发')
c.label(959,510,'失败：有限返工',color='amber',size=18)
c.edge(n4.p('W'),n5.p('E'),color='teal',relation='系统回归通过后发布交付')
c.label(988,653,'通过',color='teal',size=18)
c.text(340,765,'选中：独立验收  ·  图中的边只表示工作流控制，不表示成员上下级关系。',18,'muted')
ins=c.panel('inspector',1332,248,380,548,'Inspector',fill='gray_bg')
for i,(key,val) in enumerate([('节点类型','Gate / 独立验收'),('负责角色','Verification Engineer'),('输入','产物版本 + 工具证据'),('工具','Verilator / Test Runner'),('失败处理','最多 2 次，再升级'),('输出','Evidence + Decision')]):
    y=334+i*72
    c.text(1354,y,key,17,'muted')
    c.text(1354,y+28,val,19,'ink',True)
chat=c.panel('chat',316,814,1000,298,'Chat / 团队讨论',fill='white')
c.rect(342,884,866,60,'blue_bg',stroke='none',rx=10)
c.text(362,921,'用户：启动 C 程序回归，检查 UART 输出并列出失败用例。',19,'ink')
c.rect(390,960,890,60,'teal_bg',stroke='none',rx=10)
c.text(410,997,'Leader：已创建验证任务；测试是否通过需等待真实工具结果。',19,'ink')
c.rect(342,1040,938,48,'gray_bg',stroke='none',rx=9)
c.text(362,1071,'发送至所选 Agent · 附加文件 · 当前 Thread / Task',18,'muted')
runs=c.panel('runs',1332,814,380,298,'Run / 证据',fill='gray_bg')
for i,(k,v) in enumerate([('Task 17','运行中'),('CPU 校验','已验收'),('UART 校验','已验收'),('系统回归','等待中')]):
    y=904+i*46
    c.text(1354,y,k,19,'muted')
    c.text(1688,y,v,19,'amber' if v=='等待中' else 'teal',True,'end')
c.footer('交互要点：选择节点看契约，选择边看条件，选择运行看证据。正在运行的版本不会被画布修改直接覆盖。')
all_figures.append(c.save())

(ROOT/'diagrams'/'geometry.json').write_text(json.dumps(all_figures,ensure_ascii=False,indent=2),encoding='utf-8')

def render_pngs():
    try: import cairosvg
    except ImportError as exc: raise SystemExit('PNG export requires cairosvg: pip install cairosvg') from exc
    for f in all_figures:
        cairosvg.svg2png(url=str(OUT/f['file']),write_to=str(OUT/f['file'].replace('.svg','.png')),scale=1.5)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--png',action='store_true',help='Also render PNG previews with CairoSVG')
    args=p.parse_args()
    if args.png: render_pngs()
    print(f'Generated {len(all_figures)} SVG diagrams and the geometry manifest.')
