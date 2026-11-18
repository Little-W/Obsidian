#!/usr/bin/env python3
"""Generate editable figures for fault observation and sequence synthesis."""
from pathlib import Path
import json
from svg_geometry import Figure

ROOT = Path(__file__).resolve().parents[1]


def observation():
    d = Figure('01_fault_observation', '图 26  激励操作与观测读取',
               '教学模型：DRDF0 在读取 0 时返回 0，随后把内部状态改成 1。', 1450)
    columns = [(200,'操作'),(460,'理想读值'),(720,'实际读值'),(990,'故障内部值')]
    for x,title in columns:
        d.t(x,245,title,size=32,weight=700,anchor='middle')
    rows = [('w0','不读取','不读取','0'),('第一次 r0','0','0','1'),('第二次 r0','0','1','1')]
    for i,row in enumerate(rows):
        y = 290+i*125
        node = f'trace-{i}'
        d.rect(node,70,y,1060,100,fill='pale_red' if i==2 else 'pale',stroke='red' if i==2 else 'grid')
        for (x,_),value in zip(columns,row):
            d.t(x,y+50,value,size=32,anchor='middle',owner=node,padding=20,color='red' if i==2 else 'ink')
    d.note(700,['第一次读取激活故障；第二次读取把内部异常转成可比较的错误。',
                '在观测之前写回正确数值，会改变此例的检测结果。'])
    d.t(70,865,'两个耦合反转的执行顺序',size=38,weight=700)
    d.node('masked',70,930,1060,'末尾读取',
           ['v = 0；激励 a 后 v = 1；激励 b 后 v = 0',
            '最后读取 v 返回 0，两个反转相互抵消。'],accent='orange',h=210)
    d.node('observed',70,1190,1060,'在两次激励之间读取',
           ['v = 0；激励 a 后立即执行 r0(v)',
            '实际返回 1，在再次激励之前发现异常。'],accent='teal',h=210)
    return d


def euler():
    d = Figure('02_euler_sequence', '图 27  欧拉回路与逐边读取',
               '状态为 (a,b)；每条有向边表示一个单元的翻转写入。', 1530)
    d.node('q00',170,300,260,'00',h=120,ts=44)
    d.node('q10',770,300,260,'10',h=120,ts=44)
    d.node('q01',170,760,260,'01',h=120,ts=44)
    d.node('q11',770,760,260,'11',h=120,ts=44)
    # Separate ports keep the two directions of each adjacency unambiguous.
    d.edge('e1',d.port('q00','E',1/3),d.port('q10','W',1/3),meaning='1: w1(a)')
    d.edge('e8',d.port('q10','W',2/3),d.port('q00','E',2/3),color='orange',meaning='8: w0(a)')
    d.edge('e2',d.port('q10','S',.25),d.port('q11','N',.25),meaning='2: w1(b)')
    d.edge('e7',d.port('q11','N',.75),d.port('q10','S',.75),color='orange',meaning='7: w0(b)')
    d.edge('e3',d.port('q11','W',1/3),d.port('q01','E',1/3),meaning='3: w0(a)')
    d.edge('e6',d.port('q01','E',2/3),d.port('q11','W',2/3),color='orange',meaning='6: w1(a)')
    d.edge('e4',d.port('q01','N',.25),d.port('q00','S',.25),meaning='4: w0(b)')
    d.edge('e5',d.port('q00','S',.75),d.port('q01','N',.75),color='orange',meaning='5: w1(b)')
    d.t(600,285,'1：w1(a)',size=30,anchor='middle',color='blue')
    d.t(600,435,'8：w0(a)',size=30,anchor='middle',color='orange')
    d.t(600,745,'3：w0(a)',size=30,anchor='middle',color='blue')
    d.t(600,925,'6：w1(a)',size=30,anchor='middle',color='orange')
    d.t(205,555,'4',size=34,anchor='end',color='blue')
    d.t(385,625,'5',size=34,color='orange')
    d.t(805,555,'2',size=34,anchor='end',color='blue')
    d.t(985,625,'7',size=34,color='orange')
    d.t(600,535,'每经过一条边',size=32,anchor='middle',weight=700)
    d.t(600,590,'读取 a 与 b',size=32,anchor='middle',weight=700)
    d.t(600,645,'再执行下一条写入',size=30,anchor='middle')
    d.node('path',70,1000,1060,'完整状态顺序',
           ['00 → 10 → 11 → 01 → 00',
            '00 → 01 → 11 → 10 → 00'],accent='teal',h=210)
    d.note(1280,['相邻两行共享中间的 00；8 条有向边各经过一次。',
                 '初始化 2 次写入；每边 1 次写入与 2 次读取，共 26 次访问。',
                 '边的覆盖检查与故障读取检查分别执行。',
                 '数字 1 至 8 对应正文的完整操作表。'])
    return d


def search():
    d = Figure('03_sequence_search', '图 28  故障仿真驱动的序列搜索',
               '同一故障集合用于评价候选；完整结果另用独立遍历检查。', 1740)
    d.node('spec',80,230,1040,'故障集合与控制器限制',
           ['初始状态、激励历史、时间条件、读出规则'],accent='blue',h=170)
    d.node('candidate',80,560,440,'生成候选序列',
           ['读写步骤与地址方向','保留合法初始化'],accent='teal',h=220,ts=34)
    d.node('simulate',680,560,440,'逐操作故障仿真',
           ['更新单元与历史状态','逐次比较读出值'],accent='teal',h=220,ts=34)
    d.node('update',80,1050,440,'产生下一个候选',
           ['变异、交换或删减','修复期望值与顺序'],accent='orange',h=220,ts=34)
    d.node('score',680,1050,440,'比较候选质量',
           ['优先减少未检出故障','再减少操作数与成本'],accent='orange',h=220,ts=34)
    d.node('check',80,1470,1040,'独立执行最终序列',
           ['遍历初始状态、地址关系与指定故障，记录最早错误读取'],accent='blue',h=180,ts=36)
    d.edge('spec-candidate',d.port('spec','S',220/1040),d.port('candidate','N'),meaning='候选语法、初始化和执行限制')
    d.edge('spec-simulate',d.port('spec','S',820/1040),d.port('simulate','N'),meaning='故障模型和检测条件')
    d.edge('candidate-simulate',d.port('candidate','E'),d.port('simulate','W'),color='teal',meaning='执行候选序列')
    d.edge('simulate-score',d.port('simulate','S'),d.port('score','N'),color='teal',meaning='检出集合、长度与成本')
    d.edge('score-update',d.port('score','W'),d.port('update','E'),color='orange',meaning='按照搜索规则接受或拒绝')
    d.edge('update-candidate',d.port('update','N'),d.port('candidate','S'),color='orange',meaning='形成下一轮候选')
    d.edge('score-check',d.port('score','S'),d.port('check','N',820/1040),meaning='选取达到停止条件的最佳候选')
    d.t(600,615,'执行',size=30,anchor='middle',color='teal')
    d.t(600,1105,'选择',size=30,anchor='middle',color='orange')
    d.t(335,915,'继续搜索',size=30,color='orange')
    d.t(935,915,'检测结果',size=30,color='teal')
    d.t(935,1385,'停止条件',size=30,color='blue')
    d.note(1695,['教学搜索同时输出随机种子、终止条件、实际结果与独立检查结果。'])
    return d


def main():
    dest=ROOT/'assets/research'
    figures=[fn() for fn in (observation,euler,search)]
    records=[figure.save(dest/(figure.stem+'.svg')) for figure in figures]
    (dest/'figures_manifest.json').write_text(json.dumps(records,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'figures':len(records),'directory':str(dest)},ensure_ascii=False))


if __name__ == '__main__':
    main()
