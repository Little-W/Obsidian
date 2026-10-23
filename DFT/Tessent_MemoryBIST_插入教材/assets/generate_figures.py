#!/usr/bin/env python3
"""Original vector diagrams for the textbook. SVG uses system fonts only."""
from pathlib import Path
from html import escape
ROOT=Path(__file__).resolve().parent
INK='#17364d'; MUTED='#546b7b'; BLUE='#255f8b'; TEAL='#117c76'; GOLD='#ac6b23'; LINE='#cbd8e1'
PALE='#edf4f8'; GREEN='#eaf5f1'; AMBER='#fff4e4'; WHITE='#ffffff'
class Fig:
    def __init__(self,title,subtitle='',h=820):
        self.h=h; self.p=[f'<svg xmlns="http://www.w3.org/2000/svg" width="1440" height="{h}" viewBox="0 0 1440 {h}" role="img" aria-label="{escape(title)}">',
        '<defs><marker id="arr" markerWidth="10" markerHeight="10" refX="9" refY="4" orient="auto"><path d="M0,0 L9,4 L0,8" fill="'+MUTED+'"/></marker></defs>',
        '<style>text{font-family:"Noto Sans CJK SC","Microsoft YaHei",sans-serif;fill:'+INK+';} .mono{font-family:"DejaVu Sans Mono",monospace;}</style>',f'<rect width="1440" height="{h}" rx="18" fill="white"/>']
        self.text(42,54,title,34,weight=700)
        if subtitle:self.text(42,96,subtitle,22,color=MUTED)
        self.p.append('<path d="M42 117 H1398" stroke="'+LINE+'" stroke-width="2"/>')
    def text(self,x,y,s,size=25,anchor='start',color=INK,weight=400):
        self.p.append(f'<text x="{x}" y="{y}" font-size="{size}" text-anchor="{anchor}" font-weight="{weight}" style="fill:{color}">{escape(s)}</text>')
    def rect(self,x,y,w,h,fill=PALE,stroke=LINE,r=12):
        self.p.append(f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="{r}" fill="{fill}" stroke="{stroke}" stroke-width="2"/>')
    def box(self,x,y,w,h,title,body=(),fill=PALE):
        self.rect(x,y,w,h,fill)
        self.text(x+w/2,y+38,title,27,'middle',weight=700)
        for i,s in enumerate(body):self.text(x+w/2,y+76+i*31,s,22,'middle',MUTED)
    def path(self,d,dash=False):
        self.p.append(f'<path d="{d}" fill="none" stroke="{MUTED}" stroke-width="2.6" marker-end="url(#arr)"'+(' stroke-dasharray="8 6"' if dash else '')+'/>')
    def line(self,x1,y1,x2,y2):self.p.append(f'<path d="M{x1} {y1} L{x2} {y2}" stroke="{LINE}" stroke-width="1.5"/>')
    def foot(self,s):self.text(42,self.h-30,s,22,color=MUTED)
    def save(self,name):
        text=''.join(self.p)+'</svg>'; (ROOT/(name+'.svg')).write_text(text,encoding='utf-8')
        try:
            import cairosvg
            cairosvg.svg2png(bytestring=text.encode(),write_to=str(ROOT/(name+'.png')))
        except ImportError:pass

f=Fig('访问层、算法层与存储器接口','IJTAG 负责配置与结果访问；宏读写由相应的测试执行时钟驱动。',830)
f.box(45,320,205,125,'测试主设备',('ATE / 系统控制',))
f.box(310,320,230,125,'IJTAG / BAP',('配置、启动、状态',))
f.box(620,190,245,130,'Controller c1',('地址、算法、数据',))
f.box(620,500,245,130,'Controller c2',('地址、算法、数据',))
for y,name in [(160,'m0'),(330,'m1'),(520,'m2')]:
    f.box(935,y,230,115,'MemoryInterface',('接口 '+name+' / 比较',),GREEN)
    f.box(1230,y,165,115,'SRAM',('实例 '+name,),AMBER)
    f.path(f'M1165 {y+58} H1220')
f.path('M250 382 H300'); f.path('M540 382 H575 V255 H610'); f.path('M575 382 V565 H610')
f.path('M865 255 H900 V218 H925'); f.path('M900 255 V388 H925'); f.path('M865 565 H925')
f.box(310,685,855,85,'功能访问仍需保持正确',('测试关闭：功能路径生效；测试打开：接口接管宏端口。',),WHITE)
f.foot('原创结构示意；接口数量、比较器位置和测试访问结构由实际配置决定。')
f.save('01_architecture')

f=Fig('从设计输入到验证与物理实现','在 create_dft_specification 与 process_dft_specification 之间审查算法与分组。',830)
x=[45,395,745,1095];w=300
for i,(t,b) in enumerate([('1  读取设计与库',('RTL / TCD / 单元库',)),('2  时钟与规则',('时钟、模式、DRC',)),('3  创建配置',('自动分组 / 外部方案',)),('4  校验配置',('validate_only',))]):
 f.box(x[i],155,w,135,t,b)
 if i<3:f.path(f'M{x[i]+w} 222 H{x[i+1]-10}')
for i,(t,b) in enumerate([('8  综合与物理',('STA、功率、实际布线',)),('7  生成图形与仿真',('算法选择、完整地址',)),('6  提取访问描述',('extract_icl',)),('5  生成与插入',('测试 RTL / TSDB',))]):
 f.box(x[i],505,w,135,t,b,GREEN)
 if i>0:f.path(f'M{x[i]} 572 H{x[i-1]+w+10}')
f.path('M1245 290 V495')
f.box(535,345,480,100,'可选：初步 Macro Floorplan',('DEF 位置用于物理感知分组',),AMBER)
f.path('M895 345 V300',True)
f.text(45,733,'最终物理结果变化 → 重新评估位置、流水、时钟与分组',27,color=TEAL,weight=600)
f.foot('生成之前可以迭代规划；已经插入的候选实验应使用干净设计与独立 TSDB。')
f.save('02_flow')

f=Fig('三个不同层次的“步骤”','同一个词不代表同一个对象；不能用 March 元素数代替测试分组数。',800)
f.box(45,170,415,165,'Algorithm / Instruction',('M0：↑ w0','M1：↑ r0,w1；……','一个宏内部的操作序列'),PALE)
f.box(512,170,415,165,'Controller / Step',('Step 0：SRAM A + B','Step 1：SRAM C','每批接口执行所选完整算法'),GREEN)
f.box(980,170,415,165,'Patterns / TestStep',('一次配置和启动阶段','可以列出多个 Controller','决定本次实际执行安排'),AMBER)
f.path('M460 250 H502');f.path('M927 250 H970')
f.rect(120,430,1200,245,WHITE)
f.text(155,477,'例：TestStep(run_time_prog)',27,weight=700)
f.text(175,529,'Controller c1 → Step 0：A、B 同时运行六个 March 元素',27)
f.text(175,579,'Controller c1 → Step 1：C 运行六个 March 元素',27)
f.text(175,629,'Controller c2 → 可在同一图形阶段执行自己的步骤',27)
f.foot('DftSpecification 的 Step 通常为无名称 wrapper；Patterns 的 TestStep 可以有标识。')
f.save('03_levels')

f=Fig('自定义 March 算法的表达层次','Algorithm 改变访问编排；OperationSet 改变单次操作的周期与控制。',850)
ys=[155,315,475,635]
data=[('数学序列','↑(r0,w1)：在每个地址先读 0，再写 1',PALE),('Algorithm / MicroProgram','方向、数据选择、NextConditions、循环与边界',GREEN),('OperationSet / Operation / Cycle','Read、Write、ReadModifyWrite 的时钟周期与采样',AMBER),('Memory TCD 与真实宏端口','地址组织、控制极性、读延迟、写掩码与宏模型',PALE)]
for i,(title,body,color) in enumerate(data):
 f.box(180,ys[i],1080,120,title,(body,),color)
 if i<3:f.path(f'M720 {ys[i]+120} V{ys[i+1]-10}')
f.foot('优先复用已经验证的 OperationSet；换算法不等于需要重写宏时序。')
f.save('04_algorithm_layers')

f=Fig('四地址 March C−：每个元素都完整遍历','方框中的读写在同一地址完成；箭头表示地址推进顺序。',920)
xs=[285,565,845,1125]
for x,a in zip(xs,range(4)):f.text(x+105,164,'地址 '+str(a),25,'middle',weight=700)
ph=[('M0 ↑','w0',1),('M1 ↑','r0 → w1',1),('M2 ↑','r1 → w0',1),('M3 ↓','r0 → w1',-1),('M4 ↓','r1 → w0',-1),('M5 ↓','r0',-1)]
for k,(title,op,d) in enumerate(ph):
 y=195+k*105
 f.text(55,y+42,title,28,weight=700)
 for x in xs:
  f.rect(x,y,210,72,GREEN if d==1 else PALE)
  f.text(x+105,y+44,op,26,'middle')
 for i in range(3):
  if d==1:f.path(f'M{xs[i]+210} {y+36} H{xs[i+1]-10}')
  else:f.path(f'M{xs[i+1]} {y+36} H{xs[i]+220}')
f.text(55,865,'总操作数：4 × (1+2+2+2+2+1) = 40；不是 40 条微程序指令。',25,color=TEAL,weight=600)
f.save('05_march_trace')

f=Fig('硬编码与软可编程算法','两种方式都要在 Patterns 中确认本次执行选择。',800)
f.text(45,189,'硬编码',29,weight=700,color=BLUE)
f.text(45,451,'软可编程',29,weight=700,color=TEAL)
xs=[250,645,1040]
f.box(xs[0],145,350,150,'插入前读取 UDA',('算法 + 操作集合','确定硬件支持范围'),PALE)
f.box(xs[1],145,350,150,'生成控制器 RTL',('算法被固化到硬件','再综合与实现'),PALE)
f.box(xs[2],145,350,150,'测试时选择执行',('无需重新下载此算法','仍需配置与启动'),PALE)
f.box(xs[0],407,350,150,'插入前预留资源',('指令容量、操作与地址能力','资源不足不能后补硬件'),GREEN)
f.box(xs[1],407,350,150,'测试时装载微程序',('通过测试访问结构移入','计入 TCK 装载开销'),GREEN)
f.box(xs[2],407,350,150,'高速宏测试',('在已有能力范围内执行','完整地址与故障回归'),GREEN)
for y in (220,482):
 f.path(f'M600 {y} H635');f.path(f'M995 {y} H1030')
f.rect(250,630,1140,95,AMBER);f.text(820,673,'可修改“程序” ≠ 可添加任意新端口时序和硬件资源',27,'middle',GOLD,700)
f.text(820,707,'下载快慢与 SRAM 测试执行频率是不同问题。',23,'middle',MUTED)
f.foot('原创时间线；装载范围、复位行为与资源限制应以实际控制器配置为准。')
f.save('06_programmability')

f=Fig('Controller、Step 与全芯片并发','控制器内的步骤依次执行；不同控制器是否并行由测试计划决定。',850)
f.rect(45,155,650,490,PALE);f.text(370,202,'Controller c1',30,'middle',weight=700)
f.box(85,235,570,145,'Step 0',('SRAM A + SRAM B 同时执行','示例活动功率：60 mW'),GREEN)
f.path('M370 380 V420')
f.box(85,430,570,145,'Step 1',('SRAM C 单独执行','要等 Step 0 完成'),GREEN)
f.rect(745,155,650,490,PALE);f.text(1070,202,'Controller c2',30,'middle',weight=700)
f.box(785,235,570,145,'Step 0',('SRAM D + SRAM E 同时执行','示例活动功率：50 mW'),AMBER)
f.text(1070,487,'可与 c1 的某一步重叠',27,'middle',color=MUTED)
f.text(1070,533,'但必须检查芯片级预算',27,'middle',color=MUTED)
f.rect(170,690,1100,95,WHITE)
f.text(720,732,'每个 Step ≤ 60 mW，不代表总并发 ≤ 60 mW',29,'middle',GOLD,700)
f.text(720,769,'重叠时仅两个步骤的存储器部分就可能达到 60 + 50 = 110 mW。',24,'middle',MUTED)
f.foot('还应计入控制器、时钟网络与其他活动；数值仅用于说明层次差别。')
f.save('07_grouping_levels')

f=Fig('并行步骤的联合地址范围可能扩大','教学例：容量相同，但行与列选择数不相同。网格为缩略示意。',880)
f.text(350,165,'宏 A：128 行 × 4 列',28,'middle',weight=700)
f.text(1080,165,'宏 B：32 行 × 16 列',28,'middle',weight=700)
f.rect(100,195,500,210,GREEN,r=0);f.rect(830,195,500,210,PALE,r=0)
for k in range(1,4):f.line(100+k*125,195,100+k*125,405)
for k in range(1,8):f.line(100,195+k*26.25,600,195+k*26.25)
for k in range(1,16):f.line(830+k*31.25,195,830+k*31.25,405)
f.line(830,300,1330,300)
f.text(350,447,'512 字地址',27,'middle');f.text(1080,447,'512 字地址',27,'middle')
f.path('M350 460 V500 H620 V530');f.path('M1080 460 V500 H820 V530')
f.box(290,545,860,140,'共享范围：max(128,32) × max(4,16)',('= 128 × 16 = 2048 次地址计数位置',),AMBER)
f.text(720,747,'分别遍历：512 + 512 = 1024；联合范围反而更大。',28,'middle',color=TEAL,weight=700)
f.foot('具体是否发生、周期如何计算，要结合计数器、越界屏蔽和工具估算；不能一概用 max(Tᵢ)。')
f.save('08_dimensions')

f=Fig('把外部步骤方案变成可验证的配置','先保留已知正确的控制器与接口，再在其内部调整 Step。',880)
x=[45,540,1035];w=360
for xx,t,b in [(x[0],'1  工具导出基线',('完整 DftSpecification','实例属性与原有接口')),(x[1],'2  外部求解器',('贪心 / 小规模精确划分','输出 steps_plan.json')),(x[2],'3  保守配置改写',('移动整个 MemoryInterface','不丢失原有接口参数'))]:
 f.box(xx,165,w,160,t,b)
f.path('M405 245 H530');f.path('M900 245 H1025')
f.path('M1215 325 V475')
for xx,t,b in [(x[0],'6  比较实际结果',('地址轨迹、时间、面积','记录失败与无改善结果')),(x[1],'5  生成与验证',('插入硬件、生成图形','完整地址 / 故障检查')),(x[2],'4  新会话导入',('重新加载相同设计与库','validate_only 必须通过'))]:
 f.box(xx,485,w,160,t,b,GREEN)
f.path('M1035 565 H910');f.path('M540 565 H415')
f.rect(160,705,1120,100,AMBER)
f.text(720,747,'标签输入只限制边界；精确 Step 清单需要实际配置树和校验。',27,'middle',GOLD,700)
f.text(720,783,'离线编辑成功 ≠ Tessent 已接受 ≠ 硬件已验证',25,'middle',MUTED)
f.foot('合成示例配置不能直接替代真实工程导出的配置。')
f.save('09_external_optimizer')

f=Fig('验证证据必须对应具体对象','后一个层次不会因为前一个层次显示通过而自动完成。',920)
rows=[('操作级模型','地址与数据序列','符合抽象 March 定义'),('配置规则检查','库、对象与相容关系','所检配置可被工具接受'),('无故障 RTL 仿真','接口与生成逻辑','所测场景执行无误报'),('故障注入','明确的故障模型实例','这些故障被观察和报告'),('综合后与时序验证','映射逻辑、模式和时钟','指定条件下功能及时序'),('物理与功率分析','位置、寄生、活动与供电','实现的电气证据')]
f.text(100,167,'验证层次',26,weight=700);f.text(550,167,'检查对象',26,weight=700);f.text(1030,167,'可支持的结论',26,weight=700)
for i,(l,m,r) in enumerate(rows):
 y=195+i*100
 f.rect(45,y,1350,80,GREEN if i%2 else PALE)
 f.text(75,y+49,l,26,weight=600);f.text(510,y+49,m,25);f.text(980,y+49,r,25)
f.text(720,848,'资料包已运行：离线参考模型与配置编辑测试；商业 EDA 阶段未执行。',27,'middle',GOLD,700)
f.foot('通过的对象、地址范围、故障集合、版本和假设都应记录，不能合并成一个没有范围的 PASS。')
f.save('10_verification')
print('Generated 10 original diagrams.')
