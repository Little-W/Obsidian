from pathlib import Path
import svgwrite
from svgwrite import cm

OUT=Path(__file__).resolve().parent.parent/'assets'; OUT.mkdir(parents=True,exist_ok=True)
NAVY='#152B43'; BLUE='#2365A2'; TEAL='#188671'; AMBER='#AD6C18'; RED='#B74D53'; MUTED='#64748B'; LINE='#8AA0B1'; BG='#FFFFFF'
PBLUE='#EAF3FC'; PTEAL='#E4F4EF'; PAMBER='#FFF4DB'; PRED='#FDEDEE'; PGRAY='#F1F5F9'; DARK='#34435A'
FONT="'Noto Sans CJK SC', 'Microsoft YaHei', sans-serif"

class Canvas:
 def __init__(self,name,w,h,title,sub):
  self.w,self.h=w,h; self.dw=svgwrite.Drawing(str(OUT/name),size=(f'{w}px',f'{h}px'),viewBox=f'0 0 {w} {h}')
  self.dw.add(self.dw.rect(insert=(0,0),size=(w,h),fill=BG))
  self.dw.add(self.dw.text(title,insert=(40,51),font_size=30,font_weight='bold',font_family=FONT,fill=NAVY))
  self.dw.add(self.dw.text(sub,insert=(42,86),font_size=17,font_family=FONT,fill=MUTED))
  self.dw.add(self.dw.line((40,105),(w-40,105),stroke='#E2E8F0',stroke_width=1.5))
  for key,color in [('gray',LINE),('blue',BLUE),('teal',TEAL),('amber',AMBER),('red',RED)]:
   m=self.dw.marker(insert=(8,4),size=(9,8),orient='auto',id=f'{name.replace(".","_")}_{key}')
   m.add(self.dw.path(d='M0,0 L8,4 L0,8 Z',fill=color))
   self.dw.defs.add(m)
  self.name=name
 def label(self,x,y,t,sz=16,color=MUTED,weight='normal',anchor=None):
  q=self.dw.text(t,insert=(x,y),font_size=sz,font_family=FONT,fill=color,font_weight=weight)
  if anchor:q['text-anchor']=anchor
  self.dw.add(q)
 def pill(self,x,y,text,fill=PGRAY,color=NAVY,w=None,h=32,sz=16):
  w=w or (len(text)*sz*.93+26); self.dw.add(self.dw.rect(insert=(x,y),size=(w,h),rx=13,fill=fill))
  self.label(x+w/2,y+h/2+sz/3,text,sz,color,'bold','middle'); return w
 def box(self,x,y,w,h,title,desc=None,fill=PBLUE,border=None,accent=None,center=False,ts=21,ds=16,rx=12):
  self.dw.add(self.dw.rect(insert=(x,y),size=(w,h),rx=rx,fill=fill,stroke=border or '#CCD9E5',stroke_width=1.3))
  if accent:self.dw.add(self.dw.rect(insert=(x,y+10),size=(5,h-20),rx=2,fill=accent))
  tx=x+w/2 if center else x+22;anchor='middle' if center else None
  self.label(tx,y+32,title,ts,NAVY,'bold',anchor)
  if desc:
   if isinstance(desc,str): desc=[desc]
   for i,line in enumerate(desc):self.label(tx,y+62+i*24,line,ds,DARK,'normal',anchor)
 def path(self,d,color='gray',width=2.6,dash=None,arrow=True,opacity=1):
  col={'gray':LINE,'blue':BLUE,'teal':TEAL,'amber':AMBER,'red':RED}.get(color,color)
  a=self.dw.path(d=d,fill='none',stroke=col,stroke_width=width,stroke_linecap='round',stroke_linejoin='round',opacity=opacity)
  if dash:a['stroke-dasharray']=dash
  if arrow:a['marker-end']=f'url(#{self.name.replace(".","_")}_{color if color in ("gray","blue","teal","amber","red") else "gray"})'
  self.dw.add(a)
 def line(self,x1,y1,x2,y2,color='gray',width=2.6,arrow=True,dash=None):self.path(f'M{x1},{y1} L{x2},{y2}',color,width,dash,arrow)
 def rect(self,x,y,w,h,fill=PGRAY,stroke='#D9E1EC',rx=10):
  self.dw.add(self.dw.rect(insert=(x,y),size=(w,h),rx=rx,fill=fill,stroke=stroke,stroke_width=1.2))
 def dot(self,x,y,r=5,color=BLUE):self.dw.add(self.dw.circle(center=(x,y),r=r,fill=color))
 def save(self):self.dw.save()

# Fig 1: layered architecture
c=Canvas('01_总体架构.svg',1660,1040,'图 1  平台总体架构','统一 Web/桌面工作区；LangGraph.js 作为唯一可执行工作流引擎，团队调度与工程工具受统一运行控制。')
c.pill(52,132,'交互与设计层',PBLUE,BLUE,w=178)
for x,t,d in [(50,'项目工作区',['项目 / 模型 / 工具']), (375,'Agent 团队设计',['角色 / 权限 / 协作']), (700,'Workflow 编辑',['任务 / 分支 / Gate']), (1025,'Chat 与审批',['对话 / 任务干预']), (1350,'运行观测',['执行图 / 证据'])]:
 c.box(x,183,260,105,t,d,PBLUE,accent=BLUE,ts=20)
c.path('M180 288 V326 H1480 V345', 'blue',2.4)
c.path('M505 288 V326','blue',2.4,arrow=False)
c.path('M830 288 V326','blue',2.4,arrow=False)
c.path('M1155 288 V326','blue',2.4,arrow=False)
c.path('M1480 288 V326','blue',2.4,arrow=False)
c.box(285,346,1090,100,'Studio API / 事件总线 / 身份与项目权限',['工作流版本管理 · 任务与会话服务 · 命令/审批 · 事件重放 · 调用审计'],PGRAY,accent=LINE,center=True,ts=23,ds=17)
c.pill(52,470,'工作流与团队运行层',PTEAL,TEAL,w=216)
c.line(830,446,830,529,'teal')
for x,t,desc in [(50,'Schema + Graph Compiler',['类型校验 / 图编译']), (460,'Task Scheduler',['依赖 / 并行 / 资源配额']), (870,'LangGraph Runtime',['Checkpoint / Subgraph / Interrupt']), (1280,'Agent Team Runtime',['Planner / 协作 / 审核'])]:
 c.box(x,535,330,126,t,desc,PTEAL,accent=TEAL,ts=19,ds=17)
c.path('M830 530 V508 H215 V535','teal',2,arrow=False)
c.path('M830 508 H625 V535','teal',2,arrow=False)
c.path('M830 508 H1035 V535','teal',2,arrow=False)
c.path('M830 508 H1445 V535','teal',2,arrow=False)
c.pill(52,698,'持久化与外部能力层',PAMBER,AMBER,w=228)
c.path('M830 661 V724 H1650','gray',2,arrow=False)
for x,t,desc in [(48,'项目与任务数据库',['配置、任务、运行索引']), (375,'状态与检查点',['线程恢复、状态快照']), (702,'Workspace / Artifacts',['源码、日志、报告、哈希']), (1029,'Model / Skills',['模型网关、上下文策略']), (1356,'MCP / EDA Tools',['仿真、综合、ATPG'])]:
 c.box(x,770,270,128,t,desc,PAMBER,accent=AMBER,ts=19,ds=16)
 for cx in [x+135]:c.line(cx,724,cx,764,'gray')
c.box(528,937,604,64,'Langfuse / OpenTelemetry（可选）',['仅负责观测；缺失时不影响任务运行'],PGRAY,center=True,ts=18,ds=15)
c.path('M830 898 V931','gray',2,dash='6,6')
c.save()

# Fig 2: four graph layers
c=Canvas('02_四层图模型.svg',1650,800,'图 2  四种图模型及其关联','角色关系、流程定义、任务依赖和运行视图有不同的含义；以统一标识关联，不将所有边解释为控制流。')
columns=[(40,'角色协作图','谁有权做什么',['角色模板 · 角色实例','分配 / 汇报 / 反馈','授权关系，不直接执行'],PBLUE,BLUE),
 (452,'Workflow 图','何时执行什么',['步骤 / 条件 / 并行','子图 / Gate / 退出','可编译的控制规则'],PTEAL,TEAL),
 (864,'任务依赖图','具体交付如何分工',['任务实例 · 模块实例','前置条件 / 产物依赖','动态展开后可并行'],PAMBER,AMBER),
 (1276,'运行执行图','实际发生了什么',['Thread / Run / NodeRun','状态 / 事件 / 审批','可回放、可追溯'],PGRAY,LINE)]
for x,title,subtitle,desc,fill,accent in columns:
 c.box(x,168,334,150,title,[subtitle],fill,accent=accent,center=True,ts=25,ds=18)
 c.rect(x,350,334,180,fill)
 for i,s in enumerate(desc): c.label(x+24,392+i*43,'• '+s,19,NAVY)
 c.rect(x,570,334,90,PGRAY)
 c.label(x+167,606,{'角色协作图':'可复用团队模板','Workflow 图':'不可变发布版本','任务依赖图':'受控任务计划版本','运行执行图':'事件记录与检查点'}[title],17,NAVY,'bold','middle')
 c.label(x+167,633,'通过稳定 ID 对应',16,MUTED,anchor='middle')
for x in [389,801,1213]:
 c.path(f'M{x},424 L{x+43},424','blue',3)
 c.label(x+20,405,'关联',14,BLUE,'bold','middle')
c.rect(223,702,1205,63,PBLUE)
c.label(825,743,'统一上下文：Project → WorkflowVersion → TeamInstance → TaskInstance → Thread / Run / Event / Artifact',18,NAVY,'bold','middle')
c.save()

# Fig 3: team collaboration
c=Canvas('03_团队角色协作.svg',1690,860,'图 3  团队角色及协作授权','Leader 调度专业角色；交付、退回与验收明确区分。角色数量可按工作量扩展为多个执行实例。')
c.box(665,145,360,118,'Leader / Supervisor',['需求分解 · 派工 · 冲突协调','进度监督 · 升级处理'],PBLUE,accent=BLUE,center=True,ts=24,ds=17)
c.path('M845 263 V327 H1505','blue',3,arrow=False)
c.path('M845 327 H175','blue',3,arrow=False)
roles=[(50,'Architect',['规格与模块契约','行为模型、设计评审']), (385,'RTL Engineer ×N',['模块 RTL 与单元测试','模块工作区独占写入']), (720,'Verification ×M',['独立测试与问题定位','提交验收证据']), (1055,'Integration',['SoC 集成与软件运行','接口、时钟、外设验证']), (1390,'EDA / DFT',['综合、扫描、ATPG','工具运行和报告'])]
for x,title,desc in roles:
 c.line(x+125,327,x+125,388,'blue',2.5)
 c.box(x,395,250,130,title,desc,PTEAL,accent=TEAL,center=True,ts=19,ds=15)
c.label(1060,304,'任务派发（带范围、交付与预算）',16,BLUE,'bold','middle')
c.path('M635 455 H713','teal',3)
c.label(673,439,'交付',15,TEAL,'bold','middle')
c.path('M720 505 H640 V555 H560 V531','amber',2.7)
c.label(632,567,'缺陷反馈 / 返工',15,AMBER,'bold','middle')
c.box(465,632,760,105,'独立验收节点（Gate）',['检查交付物 → 运行真实工具 → 核对证据 → 通过 / 拒绝 / 人工审批'],PAMBER,accent=AMBER,center=True,ts=23,ds=18)
c.path('M845 525 V625','amber',2.8)
c.rect(195,784,1300,47,PGRAY)
c.label(845,814,'团队通信边只传任务和报告；是否解锁后续任务，由 Scheduler 按验收状态及依赖规则决定。',18,NAVY,anchor='middle')
c.save()

# Fig 4 Task FSM
c=Canvas('04_任务执行状态机.svg',1690,830,'图 4  单项任务的状态机','状态迁移由运行时与验收服务控制；模型文本本身不能让任务从“执行中”直接进入“已验收”。')
states=[(38,'已创建','Created',PGRAY),(308,'可执行','Ready',PBLUE),(578,'已领取','Claimed',PBLUE),(848,'执行中','Running',PTEAL),(1118,'待验收','Review',PAMBER),(1388,'已通过','Accepted',PTEAL)]
for x,t,en,fill in states:
 c.box(x,230,234,126,t,[en],fill,center=True,ts=24,ds=17)
for i in range(5):
 x=states[i][0]+234; c.line(x+5,292,states[i+1][0]-8,292,'blue',2.7)
c.label(833,206,'正常推进',17,BLUE,'bold','middle')
c.box(820,505,280,116,'待修复 / Rework',['保留证据与原始缺陷','返工次数受预算约束'],PAMBER,accent=AMBER,center=True,ts=22,ds=16)
c.path('M1235 356 V458 H960 V499','amber',3)
c.label(1105,445,'审核拒绝且可修复',16,AMBER)
c.path('M900 505 V420 H965 V363','amber',3)
c.label(758,407,'修复后重新提交',16,AMBER)
c.box(1220,625,340,115,'阻塞 / 需要人工决策',['外部工具故障、预算耗尽','或涉及不可自动处理的风险'],PRED,accent=RED,center=True,ts=21,ds=17)
c.path('M1100 560 H1170 V682 H1214','red',2.7)
c.path('M1235 458 H1400 V619','red',2.6)
c.label(1433,470,'无可接受证据',16,RED,'bold')
c.rect(115,670,950,80,PGRAY)
c.label(145,705,'失败不等于可以无限重试：',19,NAVY,'bold')
c.label(145,734,'按错误类别、尝试次数、成本预算、修改范围决定下一步。',17,DARK)
c.save()

# Fig 5 SOC example
c=Canvas('05_RV32IMAC_团队示例.svg',1730,1195,'图 5  RV32IMAC 五级流水 SoC 的团队工作流','示意任务范围：CPU、RAM、UART、裸机软件；架构阶段统一定义接口，开发可并行，集成以实际 RTL 仿真为准。')
c.box(660,150,410,124,'架构与 SPEC（Architect）',['RV32IMAC / 五级流水 / 接口契约','内存布局、工具与验证标准由团队制定'],PBLUE,accent=BLUE,center=True,ts=22,ds=17)
c.path('M865 274 V339 H1645','blue',3,arrow=False)
c.path('M865 339 H205','blue',3,arrow=False)
cols=[(50,'CPU / RTL',['五级流水、冒险处理','IMAC 指令支持'], 'CPU 模块验证',['指令集、分支、异常','真实波形与日志']),
 (465,'RAM / RTL',['指令与数据访问接口','仿真加载与存储'], '存储接口验证',['读写、对齐、异常','边界测试']),
 (880,'UART / RTL',['MMIO 寄存器与收发','可供仿真观测'], 'UART 模块验证',['发送/接收、状态寄存器','实际仿真验证']),
 (1295,'裸机软件',['startup / linker','C 测试程序、UART 驱动'], '软件构建验证',['交叉编译 ELF','链接与加载检查'])]
for x,t,desc,review,rdesc in cols:
 c.line(x+180,339,x+180,386,'blue',2.7)
 c.box(x,392,360,132,t,desc,PTEAL,accent=TEAL,center=True,ts=22,ds=18)
 c.line(x+180,524,x+180,594,'teal',2.6)
 c.box(x,600,360,127,review,rdesc,PAMBER,accent=AMBER,center=True,ts=20,ds=17)
 c.path(f'M{x+180} 727 V788','gray',2.3,arrow=False)
c.path('M230 788 H1475','gray',2.6,arrow=False)
c.path('M865 788 V844','teal',3)
c.box(565,850,600,117,'SoC 集成与系统验证',['运行 C → ELF → RAM 加载 → RTL 仿真','检查 UART 输出、退出状态、测试结果'],PBLUE,accent=BLUE,center=True,ts=22,ds=17)
c.line(865,967,865,1027,'teal',3)
c.box(565,1033,600,113,'验收与交付',['指令集 / 流水线 / 外设 / 软件测试全部通过','归档 RTL、源码、日志、结果与风险'],PTEAL,accent=TEAL,center=True,ts=23,ds=17)
c.label(865,808,'各支路必须有可验证的交付证据，全部通过后解锁系统级验证',16,MUTED,anchor='middle')
c.save()

# Fig6 evidence and provenance
c=Canvas('06_交付物与验收证据.svg',1680,815,'图 6  交付物、证据及版本继承','Agent 的自述只是一种报告；工具记录、文件哈希与独立校验共同构成可审查的任务验收证据。')
steps=[(50,'任务与输入契约',['Spec 版本 / 验收标准','目标文件与允许修改范围'],PBLUE,BLUE),
 (380,'隔离工作区',['Agent 编码 / 执行工具','保存源代码、命令和日志'],PTEAL,TEAL),
 (710,'证据采集',['退出码 / 工具版本 / 时间','报告文件 / 结果指标 / 哈希'],PAMBER,AMBER),
 (1040,'独立审核',['自动校验规则 + Review Agent','可要求人工确认'],PAMBER,AMBER),
 (1370,'可发布交付',['固定版本 / 来源记录','解锁下游任务'],PTEAL,TEAL)]
for x,t,desc,fill,accent in steps:
 c.box(x,230,260,156,t,desc,fill,accent=accent,ts=21,ds=17)
for i in range(4): c.line(steps[i][0]+260+9,302,steps[i+1][0]-13,302,'blue',2.7)
c.rect(110,470,1450,100,PGRAY)
c.label(142,513,'EvidenceRecord',22,NAVY,'bold')
c.label(142,548,'{ taskId, artifactIds, command, exitCode, toolVersion, logPath, sha256, metrics, reviewer, decision }',19,DARK)
c.path('M840 387 V464','amber',2.4)
c.box(330,648,1020,109,'上游变更 → 下游受影响任务标记为“需要重新验证”',['根据输入 Artifact 的版本及哈希追踪影响范围；旧结果保留，但不能继续作为新版本的有效证据。'],PRED,accent=RED,center=True,ts=21,ds=17)
c.path('M1500 387 V605 H840 V642','red',2.5)
c.save()

# Fig7 sequence diagram
c=Canvas('07_执行与暂停恢复时序.svg',1740,1040,'图 7  运行、验收、暂停及恢复的典型时序','运行事件先持久化，再推送 UI；人审中断和工具执行副作用使用独立的执行记录与幂等约束。')
xs=[125,410,695,980,1265,1560];labels=['用户 / GUI','Scheduler','专业 Agent','MCP / EDA','Reviewer / Gate','DB / Checkpoint']
for x,txt in zip(xs,labels):
 c.rect(x-109,146,218,67,PBLUE)
 c.label(x,189,txt,19,NAVY,'bold','middle')
 c.path(f'M{x} 213 V1000','gray',1.3,dash='5,8',arrow=False)

def msg(x1,x2,y,label,color='blue'):
 col=BLUE if color=='blue' else TEAL if color=='teal' else AMBER if color=='amber' else RED
 c.path(f'M{x1} {y} H{x2-13 if x2>x1 else x2+13}',color,2.6)
 c.label((x1+x2)/2,y-12,label,17,col,'bold','middle')
msg(xs[0],xs[1],267,'启动 Workflow / Task')
msg(xs[1],xs[5],331,'写入 Run、任务版本')
msg(xs[1],xs[2],395,'领取满足依赖的任务')
msg(xs[2],xs[3],459,'工具执行请求（权限检查）')
msg(xs[3],xs[5],523,'保存日志、结果及幂等 ID')
msg(xs[3],xs[2],587,'返回工具结果','teal')
msg(xs[2],xs[4],651,'提交交付物和证据','teal')
msg(xs[4],xs[5],715,'记录审核结果','amber')
msg(xs[4],xs[1],779,'拒绝 / 通过 / 人审','amber')
msg(xs[1],xs[0],843,'待审批时暂停并通知','amber')
msg(xs[0],xs[1],907,'批准后 Resume（同一 Thread）','teal')
msg(xs[1],xs[5],971,'提交状态变化与新事件','teal')
c.save()

# fig8 UI wireframe
c=Canvas('08_工作区交互界面.svg',1750,1130,'图 8  统一工作区的主要交互区域','同一项目内切换角色、流程和会话；Chat、Flow 与 Run 使用同一运行记录，而不是三个相互独立的页面。')
c.rect(40,135,1670,64,PGRAY)
c.label(70,177,'Agent Studio',25,NAVY,'bold')
c.pill(360,149,'Project: RV32IMAC-SoC',PBLUE,BLUE,w=315,sz=18)
c.pill(695,149,'Workflow v12 · 已发布',PTEAL,TEAL,w=300,sz=17)
c.pill(1270,149,'运行',PTEAL,TEAL,w=95)
c.pill(1380,149,'暂停',PAMBER,AMBER,w=95)
c.pill(1495,149,'保存',PGRAY,NAVY,w=95)
# left sidebar
c.rect(40,213,295,847,PGRAY)
for i,(name,items) in enumerate([('Projects',['RV32IMAC-SoC','DFT-Automation']),('Agents',['Leader','Architect','RTL / DV / Software']),('Flows',['SoC Integration','Module Verification']),('Runs',['Run #1248（进行中）','Run #1247（已完成）'])]):
 y=247+i*196
 c.label(65,y,name,20,NAVY,'bold')
 for j,s in enumerate(items):c.label(78,y+46+j*37,'·  '+s,17,DARK)
# flow and inspector
c.rect(349,213,966,528,PBLUE)
c.label(376,254,'Flow / Team Canvas',22,NAVY,'bold')
for x,y,w,t,fill in [(680,289,270,'Leader / Planner',PBLUE),(418,403,260,'RTL Development',PTEAL),(765,403,260,'Verification',PAMBER),(590,571,290,'System Gate',PAMBER)]:
 c.box(x,y,w,84,t,fill=fill,center=True,ts=18)
c.line(815,373,548,397,'blue');c.line(815,373,895,397,'blue')
c.path('M678 445 H759','teal');c.path('M765 473 H684','amber')
c.path('M895 487 V531 H735 V566','gray')
c.label(698,458,'提交',15,TEAL,'bold');c.label(714,492,'反馈',15,AMBER,'bold')
c.rect(1327,213,383,528,PGRAY)
c.label(1351,253,'Inspector',22,NAVY,'bold')
for i,(k,v) in enumerate([('Selected Node','Verification'),('Assigned Role','Verification Engineer'),('Review Mode','Independent'),('Tools','Verilator / Test Runner'),('Max Attempts','2'),('Output','Evidence + Decision')]):
 y=291+i*66;c.label(1351,y,k,16,MUTED);c.label(1351,y+27,v,18,NAVY,'bold')
# lower: Chat and Runtime
c.rect(349,755,966,305,'#F9FBFE')
c.label(376,795,'Chat / Team Discussion',22,NAVY,'bold')
c.rect(379,825,830,62,PBLUE)
c.label(399,863,'用户：启动 C 程序回归并汇报 UART 输出和失败用例。',18,NAVY)
c.rect(405,906,835,72,PTEAL)
c.label(424,946,'Leader：已完成分工；当前正在等待 SoC 回归报告。',18,NAVY)
c.rect(390,995,890,47,PGRAY)
c.label(409,1025,'输入消息 / 发送至所选 Agent / 附加文件',17,MUTED)
c.rect(1327,755,383,305,PGRAY)
c.label(1351,795,'Run / Trace',22,NAVY,'bold')
for i,(left,right) in enumerate([('Task 17','Running'),('CPU Test','Passed'),('UART Test','Passed'),('SoC Sim','Pending')]):
 y=833+i*50;c.label(1352,y,left,18,DARK);c.label(1660,y,right,17,TEAL if right=='Passed' else AMBER if right=='Pending' else BLUE,'bold','end')
c.save()
print('generated',len(list(OUT.glob('*.svg'))),'SVG')
