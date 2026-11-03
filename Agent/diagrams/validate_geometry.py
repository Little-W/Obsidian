#!/usr/bin/env python3
"""Validate endpoints, routing, box clearance, text clearance and unintended crossings.

The geometry file is generated from the same definitions as the editable SVG.
This verifies geometrical constraints, not the truth of workflow business rules.
"""
from pathlib import Path
import json, math, sys
ROOT=Path(__file__).resolve().parent.parent
figures=json.loads((ROOT/'diagrams/geometry.json').read_text(encoding='utf-8'))
EPS=1e-5

def hit(a,b,r,pad=0):
    x,y,w,h=r;x-=pad;y-=pad;w+=pad*2;h+=pad*2
    if abs(a[0]-b[0])<EPS:
        return x+EPS<a[0]<x+w-EPS and max(min(a[1],b[1]),y)<min(max(a[1],b[1]),y+h)-EPS
    return y+EPS<a[1]<y+h-EPS and max(min(a[0],b[0]),x)<min(max(a[0],b[0]),x+w)-EPS

def crossing(a,b,c,d):
    av=abs(a[0]-b[0])<EPS;cv=abs(c[0]-d[0])<EPS
    if av==cv:return None
    if not av:a,b,c,d=c,d,a,b
    x,y=a[0],c[1]
    if min(a[1],b[1])+EPS<y<max(a[1],b[1])-EPS and min(c[0],d[0])+EPS<x<max(c[0],d[0])-EPS:
        return x,y
    return None

report={'figures':[],'checks':['port attachment','arrow direction','orthogonal routes','node clearance','text clearance','unintended edge crossing','text bounds','text overlap']}
for f in figures:
    errors=[]
    nodes={n['id']:n for n in f['nodes']}
    for t in f['texts']:
        x,y,w,h=t['box']
        if x<-1 or y<-1 or x+w>f['width']+1 or y+h>f['height']+1:
            errors.append(f'Text outside canvas: {t["text"]}')
        if t['owner']:
            n=nodes[t['owner']]
            if x<n['x']+9 or x+w>n['x']+n['w']-9 or y<n['y']+7 or y+h>n['y']+n['h']-6:
                errors.append(f'Text outside node {n["id"]}: {t["text"]}')
    for i,a in enumerate(f['texts']):
        ax,ay,aw,ah=a['box']
        for b in f['texts'][i+1:]:
            bx,by,bw,bh=b['box']
            ix=min(ax+aw,bx+bw)-max(ax,bx)
            iy=min(ay+ah,by+bh)-max(ay,by)
            if ix>1 and iy>1:errors.append(f'Text overlap: {a["text"]} / {b["text"]}')
    for e in f['edges']:
        points=e['points'];sp,tp=e['source'],e['target']
        for p,endpoint in [(sp,points[0]),(tp,points[-1])]:
            if math.dist((p['x'],p['y']),endpoint)>EPS:errors.append(f'{e["id"]}: detached endpoint')
        if e['arrow'] and tp['kind']!='lifeline':
            a,b=points[-2:];d=(b[0]-a[0],b[1]-a[1]);expected={'N':(0,1),'S':(0,-1),'W':(1,0),'E':(-1,0)}[tp['side']]
            if d[0]*expected[0]+d[1]*expected[1]<=0:errors.append(f'{e["id"]}: wrong arrow orientation')
        if sp['kind']!='lifeline':
            a,b=points[:2];d=(b[0]-a[0],b[1]-a[1]);expected={'N':(0,-1),'S':(0,1),'W':(-1,0),'E':(1,0)}[sp['side']]
            if d[0]*expected[0]+d[1]*expected[1]<=0:errors.append(f'{e["id"]}: wrong outgoing direction')
        for a,b in zip(points,points[1:]):
            if abs(a[0]-b[0])>EPS and abs(a[1]-b[1])>EPS:errors.append(f'{e["id"]}: diagonal route')
            for n in f['nodes']:
                if n['kind']=='panel':continue
                if n['id'] in (sp['node'],tp['node']):
                    if hit(a,b,(n['x'],n['y'],n['w'],n['h']),pad=-.2):errors.append(f'{e["id"]}: passes inside endpoint node {n["id"]}')
                elif hit(a,b,(n['x'],n['y'],n['w'],n['h']),pad=2):
                    errors.append(f'{e["id"]}: passes through unrelated node {n["id"]}')
            for t in f['texts']:
                if hit(a,b,t['box'],pad=3):errors.append(f'{e["id"]}: intersects text {t["text"]}')
    for i,e in enumerate(f['edges']):
        for e2 in f['edges'][i+1:]:
            if e['allowCross'] or e2['allowCross']:continue
            for a,b in zip(e['points'],e['points'][1:]):
                for cc,dd in zip(e2['points'],e2['points'][1:]):
                    xy=crossing(a,b,cc,dd)
                    if xy:errors.append(f'{e["id"]}/{e2["id"]}: unplanned crossing at {xy}')
    errors=sorted(set(errors))
    report['figures'].append({'file':f['file'],'connections':len(f['edges']),'errors':errors})
report['connectionCount']=sum(r['connections'] for r in report['figures'])
report['errorCount']=sum(len(r['errors']) for r in report['figures'])
(ROOT/'diagrams'/'geometry_check.json').write_text(json.dumps(report,ensure_ascii=False,indent=2),encoding='utf-8')
print(f"{len(figures)} diagrams, {report['connectionCount']} connections, {report['errorCount']} issues")
for f in report['figures']:
    if f['errors']:
        print('\n'+f['file'])
        for e in f['errors']:print(' - '+e)
sys.exit(1 if report['errorCount'] else 0)
