#!/usr/bin/env python3
"""Deliberately corrupt measured geometry to test that layout checks detect errors.
Run validate_precise_figures.py first. These tests never modify the actual SVGs.
"""
import copy,json
from pathlib import Path
from validate_precise_figures import validate,ROOT

def main():
    data=json.loads((ROOT/'checks/rendered_figure_geometry.json').read_text())
    base=data['assets/01_architecture.svg']
    rows=[]
    def trial(name,expected,fn):
        v=copy.deepcopy(base);fn(v);kinds={i['kind'] for i in validate(v)}
        passed=expected in kinds;rows.append({'test':name,'expected_detection':expected,'passed':passed})
        if not passed:raise AssertionError((name,expected,kinds))
    assert validate(base)==[]
    trial('箭头终点偏离连接点','port_miss',lambda v:v['connectors'][0]['points'][-1].__setitem__(0,v['connectors'][0]['points'][-1][0]+8))
    def place_text_on_edge(v):
        e=v['connectors'][0];a,b=e['points'][0],e['points'][1]
        t=v['texts'][0];t['box']=[(a[0]+b[0])/2-30,(a[1]+b[1])/2-15,60,30]
    trial('文字进入连接线区域','edge_text_clearance',place_text_on_edge)
    def touch_frame(v):
        t=next(t for t in v['texts'] if t['owner'])
        b=next(b for b in v['rects'] if b['id']==t['owner'])['box']
        t['box'][1]=b[1]-t['box'][3]/2
    trial('文字骑在外框上','text_frame_clearance',touch_frame)
    trial('文字没有足够内边距','owner_padding',touch_frame)
    def insert_obstacle(v):
        e=v['connectors'][0];a,b=e['points'][0],e['points'][1]
        v['rects'].append({'id':'intentional-obstacle','box':[(a[0]+b[0])/2-40,(a[1]+b[1])/2-20,80,40],
                          'kind':'node','stroke':'none','stroke_width':0})
    trial('连接线穿过无关模块','edge_through_node',insert_obstacle)
    def duplicate_edge(v):
        z=copy.deepcopy(v['connectors'][0]);z['id']='intentional-overlap';v['connectors'].append(z)
    trial('未标明的连接线重叠','unmarked_connector_intersection',duplicate_edge)
    trial('连接线方向与指定端口相反','wrong_approach',lambda v:v['connectors'][0]['data'].__setitem__('sourceSide','N'))
    def detach(v):
        for k in ['targetNode','targetSide','targetFraction']:v['connectors'][0]['data'].pop(k,None)
    trial('连接线失去目标模块','unbound_endpoint',detach)
    trial('两个文字对象相交','text_overlap',lambda v:v['texts'][1].__setitem__('box',v['texts'][0]['box'][:]))
    trial('文字越过画布安全区','canvas_margin',lambda v:v['texts'][0]['box'].__setitem__(0,-20))
    trial('字号低于要求','small_text',lambda v:v['texts'][0].__setitem__('size',20))
    out={'scope':'Negative tests on copied measured geometry, not edited deliverable figures.',
         'tests':len(rows),'passed':all(r['passed'] for r in rows),'results':rows}
    (ROOT/'checks/geometry_checker_selftests.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(out,ensure_ascii=False,indent=2))
if __name__=='__main__':main()
