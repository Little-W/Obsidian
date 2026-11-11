"""Generate editable SVG + matching high-resolution PNG figures.

Usage: python draw_figures.py --font /path/to/a/CJK-font.ttf
Requires Pillow. Geometry is shared by SVG and PNG; no automatic edge routing.
"""
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont
import argparse, html, math, json

P = argparse.ArgumentParser()
P.add_argument('--font', default=None, help='Path to CJK TTF; omit to use PyMuPDF built-in CJK font')
P.add_argument('--out', default=str(Path(__file__).resolve().parents[1] / 'figures'))
A = P.parse_args()
if A.font is None:
    import tempfile, fitz
    _tmpfont = tempfile.NamedTemporaryFile(suffix='.ttf', delete=False)
    _tmpfont.write(fitz.Font('cjk').buffer); _tmpfont.close()
    A.font = _tmpfont.name
OUT = Path(A.out); OUT.mkdir(parents=True, exist_ok=True)
S = 2
C = dict(ink='#142B45', muted='#56677D', blue='#2963AE', bluefill='#EDF4FD', teal='#168578', tealfill='#EDF9F5', amber='#A36612', amberfill='#FFF5E5', red='#AE414A', redfill='#FFF0F2', line='#8193A9', pale='#F6F8FB', white='#FFFFFF')
FONTS = {}
def font(n):
    if n not in FONTS: FONTS[n] = ImageFont.truetype(A.font, round(n*S))
    return FONTS[n]
def esc(x): return html.escape(str(x))

class Fig:
    def __init__(self, name, title, subtitle, w=1600, h=1060):
        self.name,self.w,self.h=name,w,h
        self.im=Image.new('RGB',(w*S,h*S),'white'); self.d=ImageDraw.Draw(self.im)
        self.svg=[f'<svg xmlns="http://www.w3.org/2000/svg" width="{w}" height="{h}" viewBox="0 0 {w} {h}">', '<rect width="100%" height="100%" fill="white"/>']
        self.nodes=[];self.edges=[];self.text_bounds=[]
        self.rect(0,0,w,12,C['blue'],C['blue'],0)
        self.text(54,55,title,38,C['ink'],anchor='left')
        self.text(54,108,subtitle,23,C['muted'],anchor='left')
    def rect(self,x,y,w,h,fill=C['white'],stroke=C['line'],r=16,width=2):
        self.d.rounded_rectangle((x*S,y*S,(x+w)*S,(y+h)*S), radius=r*S, fill=fill, outline=stroke, width=max(1,width*S))
        self.svg.append(f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="{r}" fill="{fill}" stroke="{stroke}" stroke-width="{width}"/>')
    def text(self,x,y,txt,size=26,color=C['ink'],anchor='mid'):
        # y denotes the vertical midpoint, in both renderings.
        a={'mid':'mm','left':'lm','right':'rm'}[anchor]
        self.d.text((x*S,y*S),txt,font=font(size),fill=color,anchor=a)
        ta={'mid':'middle','left':'start','right':'end'}[anchor]
        self.svg.append(f'<text x="{x}" y="{y}" fill="{color}" font-size="{size}" font-family="Noto Sans CJK SC,Microsoft YaHei,PingFang SC,Arial,sans-serif" text-anchor="{ta}" dominant-baseline="central">{esc(txt)}</text>')
        b=self.d.textbbox((x*S,y*S),txt,font=font(size),anchor=a)
        self.text_bounds.append((tuple(v/S for v in b),txt))
    def box(self,id,x,y,w,h,title,lines=(),kind='blue'):
        fill=C.get(kind+'fill',C['pale']); color=C.get(kind,C['line'])
        self.rect(x,y,w,h,fill,color)
        if lines:
            self.text(x+w/2,y+34,title,29,C['ink'])
            for j,l in enumerate(lines): self.text(x+w/2,y+76+j*32,l,23,C['muted'])
        else: self.text(x+w/2,y+h/2,title,29,C['ink'])
        self.nodes.append(dict(id=id,x=x,y=y,w=w,h=h))
        return (x,y,w,h)
    def arrow(self,pts,color=C['blue'],dashed=False,label=None,lpos=None):
        # All routes are specified explicitly and terminate on a box boundary.
        self.edges.append(dict(points=pts,dashed=dashed))
        p=[(round(x*S),round(y*S)) for x,y in pts]
        if dashed:
            for (x1,y1),(x2,y2) in zip(p,p[1:]):
                dx,dy=x2-x1,y2-y1; L=math.hypot(dx,dy)
                for q in range(0,int(L),26):
                    e=min(q+15,L)
                    self.d.line((x1+dx*q/L,y1+dy*q/L,x1+dx*e/L,y1+dy*e/L),fill=color,width=5)
        else:self.d.line(p,fill=color,width=5,joint='curve')
        (x0,y0),(x1,y1)=pts[-2:];ang=math.atan2(y1-y0,x1-x0)
        tip=[(x1,y1),(x1-15*math.cos(ang)+6*math.sin(ang),y1-15*math.sin(ang)-6*math.cos(ang)),(x1-15*math.cos(ang)-6*math.sin(ang),y1-15*math.sin(ang)+6*math.cos(ang))]
        self.d.polygon([(x*S,y*S) for x,y in tip],fill=color)
        dash=' stroke-dasharray="9 7"' if dashed else ''
        self.svg.append(f'<polyline points="'+ ' '.join(f'{x},{y}' for x,y in pts)+f'" fill="none" stroke="{color}" stroke-width="2.5" stroke-linejoin="round"{dash}/>')
        self.svg.append('<polygon points="'+' '.join(f'{x},{y}' for x,y in tip)+f'" fill="{color}"/>')
        if label:
            x,y=lpos;tw=self.d.textlength(label,font=font(22))/S
            self.rect(x-tw/2-9,y-17,tw+18,34,C['white'],C['white'],5,1)
            self.text(x,y,label,22,color)
    def note(self,y,lines):
        for j,l in enumerate(lines):self.text(56,y+j*31,l,22,C['muted'],anchor='left')
    def save(self):
        self.text(self.w-42,self.h-28,'EDA Agent 研究报告 · 2026-11-03 · 作者绘制',18,C['muted'],anchor='right')
        self.svg.append('</svg>');(OUT/(self.name+'.svg')).write_text('\n'.join(self.svg),encoding='utf-8')
        self.im.save(OUT/(self.name+'.png'))
        # Detect actual overlaps of routed line interiors with unrelated nodes.
        issues=[]
        for ei,e in enumerate(self.edges):
            for p,q in zip(e['points'],e['points'][1:]):
                if p[0]!=q[0] and p[1]!=q[1]: continue
                for n in self.nodes:
                    x,y,w,h=n['x'],n['y'],n['w'],n['h']; eps=2
                    if p[0]==q[0]: hit=x+eps<p[0]<x+w-eps and max(min(p[1],q[1]),y+eps)<min(max(p[1],q[1]),y+h-eps)
                    else: hit=y+eps<p[1]<y+h-eps and max(min(p[0],q[0]),x+eps)<min(max(p[0],q[0]),x+w-eps)
                    if hit: issues.append({'edge':ei,'node':n['id']})
        for b,t in self.text_bounds:
            if b[0]<8 or b[1]<10 or b[2]>self.w-8 or b[3]>self.h-8: issues.append({'text_outside_canvas':t,'bbox':b})
        return {'file':self.name,'width':self.w,'height':self.h,'geometry_issues':issues,'nodes':len(self.nodes),'edges':len(self.edges)}

audit=[]

f=Fig('01_research_landscape','研究版图：从生成结果到验收工程结果','本报告的分析分类；各类方法并存，不代表统一的行业成熟度等级。',h=1030)
rows=[('领域知识与接口','ChipNeMo / SWE-agent','文档检索、脚本、有限编辑','知识准确性 / API 与执行证据'),('EDA 工具编排','ChatEDA / EDAid','计划、调用、候选比较','任务成功 / 脚本语义 / 成本'),('数字功能验证','UVM² / HAVEN / AssertLLM','测试计划、激励、断言、调试','规格覆盖 / 缺陷检出 / 独立检查'),('DFT 与测试','DFTAgent / VeriRAG / TESLA','测试准备、可测性修复、分析','功能等价 / 测试规则 / 故障仿真'),('RTL 与物理优化','ChipMEM / ORFS-agent / Dr. RTL','候选变换、参数搜索、经验复用','等价 / 物理约束 / PPA / 总成本'),('可执行流程与平台','AgentSPEX / OpenHands','状态、并行、恢复、上下文','可追溯 / 可恢复 / 可复现')]
xs=[55,340,750,1160];ws=[270,395,395,385]
for x,w,t in zip(xs,ws,['任务方向','代表研究','主要产物','关键验收对象']):f.rect(x,155,w,55,C['ink'],C['ink'],8);f.text(x+w/2,182,t,24,'white')
for k,row in enumerate(rows):
    y=230+k*113
    for j,(x,w,t) in enumerate(zip(xs,ws,row)):
        f.rect(x,y,w,93,C['bluefill'] if k%2==0 else C['pale'],C['white'],8)
        size=25 if j==0 else 21
        # Deliberately split dense cells for stable line lengths.
        if j in (1,3) and len(t)>26:
            seg=t.split(' / ');mid=max(1,len(seg)//2);ll=[' / '.join(seg[:mid]),' / '.join(seg[mid:])]
            for n,l in enumerate(ll):f.text(x+w/2,y+32+n*31,l,size,C['ink'])
        else:f.text(x+w/2,y+46,t,size,C['ink'])
f.note(948,['“生成正确解释”“运行成功”“工程验收通过”是不同事件，评价时应分别记录。']);audit.append(f.save())

f=Fig('02_controlled_architecture','受控图流程与智能体团队的分工','图执行器控制顺序、资源与状态；智能体提出计划或变更；验收节点读取可复核证据。',h=1150)
f.box('contract',350,165,900,112,'固定工程契约',['规格版本 / 工具与工艺版本 / 时钟与模式 / 验收集合'],kind='teal')
f.box('graph',350,330,900,125,'图执行器',['依赖、并行、预算、失败分类、恢复、分支与合并'],kind='blue')
f.arrow([(800,277),(800,330)])
for id,x,t,ls in [('plan',70,'计划与诊断 Agent',['读取摘要和失败证据','输出候选任务或修复假设']),('write',575,'实现与优化 Agent',['在独立候选目录工作','输出变更与预期影响']),('review',1080,'独立审查 Agent',['读取规格与实际工具结果','提出可执行的反例检查'])]:
    f.box(id,x,520,450,140,t,ls)
for x in [295,800,1305]:f.arrow([(x if x==800 else (430 if x==295 else 1170),455),(x if x==800 else (430 if x==295 else 1170),485),(x,485),(x,520)])
f.box('tools',350,735,900,115,'确定工具与结构化证据',['仿真 / 形式 / ATPG / 故障仿真 / 布局布线 / STA'],kind='teal')
for x in [295,800,1305]:f.arrow([(x,660),(x,700),(800 if x==800 else (430 if x==295 else 1170),700),(800 if x==800 else (430 if x==295 else 1170),735)])
f.box('gate',350,905,900,112,'独立验收节点',['结果绑定候选哈希；全部必需检查有效通过后才接纳'],kind='teal');f.arrow([(800,850),(800,905)])
f.note(1065,['审查意见可以触发检查；验收权由既定规则执行。模型多数票不能替代工具证明。']);audit.append(f.save())

f=Fig('03_verification_workflow','功能验证：规格驱动的双路径与反例反馈','实现与检查分别追溯到固定规格；修改检查集合需要单独审查。',h=1250)
f.box('spec',430,160,740,110,'规格与接口契约',['时序行为 / 复位 / 协议 / 异常条件'],kind='teal')
f.box('impl',100,335,560,130,'实现路径',['RTL / 修复候选','独立目录与版本'])
f.box('check',940,335,560,130,'验证路径',['需求表 / 参考模型 / 激励 / SVA','独立于候选的验收集合'],kind='teal')
f.arrow([(600,270),(600,300),(380,300),(380,335)])
f.arrow([(1000,270),(1000,300),(1220,300),(1220,335)])
f.box('run',430,540,740,125,'编译、仿真与形式检查',['回归、差分比对、断言、可达性与空真检查'],kind='teal')
f.arrow([(380,465),(380,500),(600,500),(600,540)])
f.arrow([(1220,465),(1220,500),(1000,500),(1000,540)])
f.box('assess',430,735,740,120,'需求与证据核对',['缺陷检出 + 规格覆盖 + 检查有效性'],kind='teal')
f.arrow([(800,665),(800,735)])
f.box('result',430,920,740,100,'接纳候选并保留验证证据',[],kind='teal')
f.arrow([(800,855),(800,920)],label='全部必需检查通过',lpos=(800,886))
f.box('debug',40,735,295,150,'失败诊断',['失败轨迹与类型','区分 DUT / 验证环境'],kind='amber')
f.arrow([(430,795),(335,795)],color=C['amber'],label='失败',lpos=(383,774))
f.arrow([(185,735),(185,660),(55,660),(55,400),(100,400)],color=C['amber'],dashed=True,label='DUT 修复',lpos=(170,640))
f.arrow([(185,885),(185,1050),(1545,1050),(1545,400),(1500,400)],color=C['amber'],dashed=True,label='环境或验证资产问题：独立审查后修复',lpos=(800,1050))
f.note(1130,['覆盖项未命中时补充激励；若需修改 checker、assumption 或 waiver，走独立变更审查。','禁止通过删除失败测试、弱化断言或自行删减覆盖分母来验收候选。']);audit.append(f.save())

f=Fig('04_dft_workflow','DFT：功能模式与测试模式分别验收','以下是建议工程流程；步骤顺序按工具、设计类型与 DFT 方案实例化。',h=1350)
f.box('input',390,160,820,110,'固定输入与 DFT 契约',['RTL / 库 / 时钟复位 / 测试模式 / 故障模型'],kind='teal')
f.box('base',390,325,820,110,'建立可复现基线',['导入、约束检查、初始 DFT 规则与故障统计'])
f.arrow([(800,270),(800,325)])
f.box('patch',390,490,820,110,'提出并执行 DFT 变更',['脚本修复 / 可测性修复 / 扫描与测试结构插入'])
f.arrow([(800,435),(800,490)])
f.box('lec',140,675,590,110,'功能模式检查',['功能等价 / 原有回归保持'],kind='teal')
f.box('drc',870,675,590,110,'测试模式检查',['DFT 规则 / 扫描连通 / 模式控制'],kind='teal')
f.arrow([(600,600),(600,635),(435,635),(435,675)])
f.arrow([(1000,600),(1000,635),(1165,635),(1165,675)])
f.box('atpg',390,855,820,110,'ATPG 与独立结果复核',['向量有效性 / 故障仿真 / 故障全集与分类变化'],kind='teal')
f.arrow([(435,785),(435,820),(600,820),(600,855)])
f.arrow([(1165,785),(1165,820),(1000,820),(1000,855)])
f.text(800,820,'两类检查均通过后执行',22,C['teal'])
f.box('accept',390,1050,820,110,'接纳通过约束的候选',['覆盖、向量数、测试时间、功能时序与结构代价'],kind='teal')
f.arrow([(800,965),(800,1050)],label='必需检查有效通过',lpos=(800,1007))
f.arrow([(390,910),(70,910),(70,545),(390,545)],color=C['amber'],dashed=True,label='诊断与受限重试',lpos=(225,930))
f.note(1220,['LEC 在约定的功能模式下进行；它不证明扫描移位或捕获过程正确。','MBIST 还需验证算法执行、故障注入、地址覆盖与测试控制接口，不能由 ATPG 覆盖率替代。']);audit.append(f.save())

f=Fig('05_backend_workflow','后端优化：先满足约束，再比较设计质量','候选基于同一基准设计，使用相同工艺、约束集合与评价方式。',h=1280)
f.box('fixed',365,160,870,110,'冻结比较条件',['功能 / SDC / 模式角点 / 工具与工艺 / 预算与随机种子'],kind='teal')
f.box('proposal',365,320,870,115,'计划与候选探索',['RTL 变换、综合选项、布局参数或 ECO 策略'])
f.arrow([(800,270),(800,320)])
f.box('cheap',365,490,870,110,'分级预检',['语法、合法性、等价检查、初步综合与约束完整性'],kind='teal')
f.arrow([(800,435),(800,490)])
f.box('full',365,655,870,115,'完整物理评价',['布局布线 / 提取 / 多模式多角点 STA / 功耗与 DRC'],kind='teal')
f.arrow([(800,600),(800,655)])
f.box('gate',365,825,870,115,'独立硬门槛',['等价有效、约束未弱化、各必需角点满足、数据完整'],kind='teal')
f.arrow([(800,770),(800,825)])
f.box('pareto',365,1000,870,112,'保留满足约束的 Pareto 候选',['比较功耗、性能、面积；记录全部运行成本'],kind='teal')
f.arrow([(800,940),(800,1000)],label='通过',lpos=(800,970))
f.arrow([(365,880),(85,880),(85,377),(365,377)],color=C['amber'],dashed=True,label='失败 / 新证据',lpos=(217,903))
f.arrow([(1235,1056),(1495,1056),(1495,377),(1235,377)],color=C['amber'],dashed=True,label='预算内继续探索',lpos=(1360,1125))
f.note(1190,['改大时钟周期、增加无依据 false path 或删除角点会改变问题，不能计为原任务优化成功。']);audit.append(f.save())

f=Fig('06_cross_check','交叉检验的关键：证据独立性与互补性','角色数量、模型数量、检验方法数量是三个不同的维度。',h=1040)
f.box('weak',55,165,705,180,'相关性较强的复核',['同一模型、同一上下文重复评价','同源生成的 DUT 与 testbench 互相配合','多数票只反映一致程度'],kind='amber')
f.box('strong',840,165,705,180,'可以增加独立证据的复核',['固定规格 + 隔离的参考模型或保留测试','仿真 + 形式 + 变异 / 故障注入','约束审计 + 原始工具结果重算'],kind='teal')
headers=['对象','检查方法 A','检查方法 B','两者仍需核实']
xs=[55,355,755,1155];ws=[285,385,385,390]
for x,w,t in zip(xs,ws,headers):f.rect(x,405,w,58,C['ink'],C['ink'],8);f.text(x+w/2,434,t,24,'white')
data=[['RTL 功能','差分仿真 / 保留测试','性质证明 / 反例定位','参考模型与假设是否正确'],['验证环境','需求到检查项的追溯','变异测试 / 缺陷注入','是否只测试已知简单错误'],['DFT 变更','功能模式等价','扫描检查 / 故障仿真','测试模型与分母是否一致'],['后端候选','同条件 PPA 与 MCMM','约束审计 / 独立重算','角点、活动率与规则是否完整']]
for k,row in enumerate(data):
    for x,w,t in zip(xs,ws,row):
        y=485+k*106;f.rect(x,y,w,88,C['pale'],C['white'],8);f.text(x+w/2,y+44,t,22,C['ink'])
f.note(955,['多种检查结果发生冲突时，应调查模型、约束和覆盖差异；不以多数票抵消失败证据。']);audit.append(f.save())

f=Fig('07_execution_states','执行状态：完成调用与完成验收分别记录','状态由执行器和证据驱动；模型的“已完成”文字不能直接触发接纳。',h=1180)
f.box('ready',460,165,680,100,'就绪 READY',['依赖与前置条件满足'])
f.box('running',460,325,680,100,'执行 RUNNING',['job_id / 超时 / 心跳 / 资源记录'])
f.arrow([(800,265),(800,325)])
f.box('produced',460,490,680,100,'产物已生成 PRODUCED',['退出码与产物存在性已检查'])
f.arrow([(800,425),(800,490)])
f.box('validate',460,655,680,110,'检查 VALIDATING',['绑定同一输入、候选与验收集合'],kind='teal')
f.arrow([(800,590),(800,655)])
f.box('accepted',460,930,680,100,'接纳 ACCEPTED',['所有必需检查有效通过'],kind='teal')
f.arrow([(800,765),(800,930)],label='通过',lpos=(800,835))
f.box('failed',50,655,300,130,'失败 FAILED',['明确的违例或反例','按类别修复'],kind='red')
f.arrow([(460,710),(350,710)],color=C['red'])
f.box('unknown',1250,655,300,155,'未判定',['INCONCLUSIVE','超时 / 证据不全','保持未通过状态'],kind='amber')
f.arrow([(1140,710),(1250,710)],color=C['amber'])
f.box('blocked',1250,325,300,130,'阻塞 BLOCKED',['许可 / 文件 / 环境','交由运行环境处理'],kind='amber')
f.arrow([(1140,375),(1250,375)],color=C['amber'])
f.arrow([(200,655),(200,215),(460,215)],color=C['amber'],dashed=True,label='新候选且预算允许',lpos=(232,300))
f.arrow([(460,375),(395,375),(395,615),(305,615),(305,655)],color=C['red'],label='执行错误',lpos=(345,595))
f.note(1060,['图中省略：阻塞解除后重新检查前置条件，再返回 READY；证据不足进入受限诊断。','重试需新信息或明确的暂态故障；预算耗尽后停止该分支，并保留已验收版本。']);audit.append(f.save())

f=Fig('08_memory_workflow','经验复用：通过验证的做法与失败记录分别保存','经验用于提出下一次候选；旧经验不能替代当前版本的重新验证。',h=1190)
f.box('run',70,165,680,115,'当前运行与证据',['候选、工具版本、输入哈希、命令、结果'])
f.box('applicable',900,165,620,115,'新任务与适用条件',['工具 / 版本 / 工艺 / 设计结构 / 目标'],kind='teal')
f.box('passed',70,365,310,165,'验证成功经验',['前提 + 操作步骤','验证方法与适用范围','来源证据'],kind='teal')
f.box('failed',440,365,310,165,'失败与统计记录',['错误类别 / 尝试次数','环境故障独立计数','禁止转成成功技能'],kind='amber')
f.arrow([(230,280),(230,365)]);f.arrow([(590,280),(590,365)],color=C['amber'])
f.box('store',70,615,680,130,'版本化经验库',['成功与失败保留不同类型；失效、过时记录可撤回'],kind='teal')
f.arrow([(225,530),(225,615)]);f.arrow([(595,530),(595,615)],color=C['amber'])
f.box('retrieve',900,615,620,130,'过滤与检索',['先匹配适用条件，再按相关度取少量证据'],kind='teal')
f.arrow([(1210,280),(1210,615)]);f.arrow([(750,680),(900,680)])
f.box('candidate',900,900,620,115,'生成候选并重新验证',['记录命中经验及它对本次决策的影响'])
f.arrow([(1210,745),(1210,900)])
f.note(1090,['评测时固定初始经验库；冷启动、只读经验与在线积累分别报告，防止任务间信息泄漏。']);audit.append(f.save())

f=Fig('09_evaluation_design','可靠性评测：比较机制，并统计全部代价','模型、任务、工具与预算固定；每组使用相同独立验收器。',h=1090)
cols=[(60,'A 固定脚本',['健壮解析与错误检查','任务适用范围明确']), (440,'B 单 Agent',['同样工具与检索','固定总预算']), (820,'C 单 Agent + 图',['确定分支与停止条件','上下文按任务裁剪']), (1200,'D 图流程 + 团队',['角色隔离与候选并行','独立交叉检验'])]
for x,t,ls in cols:f.box(t,x,175,340,170,t,ls,kind='blue')
f.box('suite',230,430,1140,140,'相同任务矩阵与扰动集',['正常 / 未见设计 / 未见版本 / 文件错误 / 复位极性 / 工具超时 / 约束诱导','按工程分组切分；对每项任务重复运行'],kind='teal')
for x,_,_ in cols:f.arrow([(x+170,345),(x+170,390),(max(300,min(x+170,1300)),390),(max(300,min(x+170,1300)),430)])
f.box('eval',230,660,1140,130,'固定的独立评价与统计',['正确完成率、错误接纳率、缺陷检出率、总工具小时、延迟、人工介入'],kind='teal');f.arrow([(800,570),(800,660)])
f.box('ablate',230,875,1140,110,'逐项消融：反馈 / 多角色 / 独立检查 / 经验 / 上下文裁剪',['报告每次尝试与最终结果；保留失败任务和预算耗尽的任务'],kind='amber');f.arrow([(800,790),(800,875)])
audit.append(f.save())

f=Fig('10_mbist_scope','MBIST 方向：把算法求解与 Agent 决策分别验证','建议研究方案；不表示已有论文或本项目已经实现。',h=1140)
f.box('spec',420,160,760,115,'存储器与故障契约',['接口 / 时钟 / 功率 / 几何条件 / 目标故障模型'],kind='teal')
f.box('agent',80,350,650,140,'Agent 负责组织与解释',['选择合法候选与工具配置','根据失败证据安排下一轮'])
f.box('solver',870,350,650,140,'专用算法与求解器',['分组、容量约束、时序与功耗求解','返回可独立检查的解或证书'],kind='teal')
f.arrow([(600,275),(600,310),(405,310),(405,350)])
f.arrow([(1000,275),(1000,310),(1195,310),(1195,350)])
f.arrow([(730,420),(870,420)],label='候选配置',lpos=(800,397))
f.box('test',420,575,760,145,'独立核验与故障注入',['逐组重算合法性；核对求解下界或可行性','检查 March 操作、故障检出与控制器行为'],kind='teal')
f.arrow([(405,490),(405,535),(600,535),(600,575)])
f.arrow([(1195,490),(1195,535),(1000,535),(1000,575)])
f.box('out',420,810,760,120,'通过后输出测试配置与证据',['算法适用范围、控制器代价、测试时间与功耗'],kind='teal')
f.arrow([(800,720),(800,810)],label='通过',lpos=(800,765))
f.arrow([(420,640),(55,640),(55,420),(80,420)],color=C['amber'],dashed=True)
f.note(1010,['Agent 文字解释不是数学最优性证书；March 算法检出能力依赖明确的故障模型。']);audit.append(f.save())

(OUT.parent/'figure_source'/'geometry_audit.json').write_text(json.dumps(audit,ensure_ascii=False,indent=2))
issues=[x for x in audit if x['geometry_issues']]
print(json.dumps({'figures':len(audit),'issues':issues},ensure_ascii=False,indent=2))

if '_tmpfont' in globals(): Path(_tmpfont.name).unlink(missing_ok=True)
