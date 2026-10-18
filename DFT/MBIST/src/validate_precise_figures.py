#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Measure rendered text, validate ports/routes, and optionally export PNG.

Requires Playwright + Chromium. No OCR. No fonts are embedded or exported.
    python src/validate_precise_figures.py --png
    python src/validate_precise_figures.py --browser /path/to/chromium --png-scale 1.5

Checks: text/text; text/canvas; text/card padding; text/all borders and rules;
text/connectors and arrowhead envelopes; connector/node intersections;
source/target named ports, approach directions; connector/connector crossings.
Only explicitly shared junctions permit intersections between connections.
The checks validate drawing geometry, not electrical correctness or fault coverage.
"""
from __future__ import annotations
import argparse,json,math,shutil
from pathlib import Path
from itertools import combinations
from playwright.sync_api import sync_playwright
ROOT=Path(__file__).resolve().parents[1]
EPS=1e-6

def expand(b,g):return [b[0]-g,b[1]-g,b[2]+2*g,b[3]+2*g]
def overlap(a,b):return min(a[0]+a[2],b[0]+b[2])-max(a[0],b[0])>EPS and min(a[1]+a[3],b[1]+b[3])-max(a[1],b[1])>EPS
def same(a,b):return math.dist(a,b)<EPS

def seg_hits_rect(a,b,r):
    # Liang-Barsky clipping, including contact with the forbidden rectangle.
    x,y,w,h=r;dx=b[0]-a[0];dy=b[1]-a[1];lo,hi=0.,1.
    for p,q in [(-dx,a[0]-x),(dx,x+w-a[0]),(-dy,a[1]-y),(dy,y+h-a[1])]:
        if abs(p)<EPS:
            if q<0:return False
            continue
        t=q/p
        if p<0:lo=max(lo,t)
        else:hi=min(hi,t)
        if lo>hi+EPS:return False
    return True

def seg_intersection(a,b,c,d):
    # All connectors are orthogonal. Return point or ('overlap',) for shared span.
    av=abs(a[0]-b[0])<EPS;cv=abs(c[0]-d[0])<EPS
    if av!=cv:
        v1,v2,h1,h2=(a,b,c,d) if av else (c,d,a,b)
        p=(v1[0],h1[1])
        if min(v1[1],v2[1])-EPS<=p[1]<=max(v1[1],v2[1])+EPS and min(h1[0],h2[0])-EPS<=p[0]<=max(h1[0],h2[0])+EPS:return p
        return None
    axis=1 if av else 0;fixed=1-axis
    if abs(a[fixed]-c[fixed])>EPS:return None
    lo=max(min(a[axis],b[axis]),min(c[axis],d[axis]));hi=min(max(a[axis],b[axis]),max(c[axis],d[axis]))
    if hi<lo-EPS:return None
    if hi-lo>EPS:return ('overlap',)
    return (a[0],lo) if av else (lo,a[1])

def border(b):
    x,y,w,h=b;return [((x,y),(x+w,y)),((x+w,y),(x+w,y+h)),((x+w,y+h),(x,y+h)),((x,y+h),(x,y))]

def validate(v):
    issues=[];texts=v['texts'];boxes={b['id']:b for b in v['rects']};edges=v['connectors'];junctions={j['id']:(j['x'],j['y']) for j in v['junctions']}
    def bad(kind,**kw):issues.append({'kind':kind,**kw})
    for t in texts:
        r=t['box'];x,y,w,h=r
        if x<24 or y<24 or x+w>v['width']-24 or y+h>v['height']-24:bad('canvas_margin',text=t['text'],box=r)
        if t['size']<28:bad('small_text',text=t['text'],size=t['size'])
        if t['owner']:
            if t['owner'] not in boxes:bad('missing_text_owner',text=t['text'],owner=t['owner'])
            else:
                b=boxes[t['owner']]['box'];margin=min(x-b[0],y-b[1],b[0]+b[2]-x-w,b[1]+b[3]-y-h)
                if margin<t['padding']-.05:bad('owner_padding',text=t['text'],owner=t['owner'],actual=round(margin,2),required=t['padding'])
        for b in boxes.values():
            if b['stroke']=='none' or b['stroke_width']==0:continue
            # Six pixels between glyph bounds and every visible frame. Small grid
            # cells explicitly use four pixels; those cells contain single digits.
            gap=min(6,t['padding']) if b['id']==t['owner'] else 6
            if any(seg_hits_rect(a,c,expand(r,gap+b['stroke_width']/2)) for a,c in border(b['box'])):
                bad('text_frame_clearance',text=t['text'],frame=b['id'])
        for line in v['rules']:
            if any(seg_hits_rect(a,b,expand(r,6+line['width']/2)) for a,b in zip(line['points'],line['points'][1:])):bad('text_rule_clearance',text=t['text'],line=line['id'])
    for a,b in combinations(texts,2):
        if overlap(a['box'],b['box']):bad('text_overlap',a=a['text'],b=b['text'])
    for ed in edges:
        pts=ed['points'];attrs=ed['data'];eid=ed['id']
        if len(pts)<2:bad('zero_edge',edge=eid);continue
        for a,b in zip(pts,pts[1:]):
            if abs(a[0]-b[0])>EPS and abs(a[1]-b[1])>EPS:bad('diagonal_edge',edge=eid)
        for which,p,delta in [('source',pts[0],(pts[1][0]-pts[0][0],pts[1][1]-pts[0][1])),('target',pts[-1],(pts[-2][0]-pts[-1][0],pts[-2][1]-pts[-1][1]))]:
            node=attrs.get(which+'Node');side=attrs.get(which+'Side');jn=attrs.get(which+'Junction')
            if node:
                if node not in boxes:bad('missing_node',edge=eid,node=node);continue
                x,y,w,h=boxes[node]['box'];f=float(attrs[which+'Fraction'])
                expected={'N':(x+f*w,y),'S':(x+f*w,y+h),'W':(x,y+f*h),'E':(x+w,y+f*h)}[side]
                if not same(p,expected):bad('port_miss',edge=eid,endpoint=which,actual=p,expected=expected)
                normal={'N':(0,-1),'S':(0,1),'W':(-1,0),'E':(1,0)}[side]
                cross=normal[0]*delta[1]-normal[1]*delta[0];dot=normal[0]*delta[0]+normal[1]*delta[1]
                if abs(cross)>EPS or dot<=0:bad('wrong_approach',edge=eid,endpoint=which)
            elif jn:
                if jn not in junctions or not same(p,junctions[jn]):bad('junction_miss',edge=eid,endpoint=which)
            else:bad('unbound_endpoint',edge=eid,endpoint=which)
        for b in boxes.values():
            if b['kind']!='node':continue
            # Shrink the box infinitesimally so contact at the boundary is legal.
            inside=expand(b['box'],-.02)
            for a,c in zip(pts,pts[1:]):
                if seg_hits_rect(a,c,inside):bad('edge_through_node',edge=eid,node=b['id']);break
        for t in texts:
            forbid=expand(t['box'],10+ed['width']/2)
            if any(seg_hits_rect(a,b,forbid) for a,b in zip(pts,pts[1:])):bad('edge_text_clearance',edge=eid,text=t['text'])
            if ed['arrow']:
                end=pts[-1];prev=pts[-2];length=math.dist(end,prev);ux=(end[0]-prev[0])/length;uy=(end[1]-prev[1])/length
                tri=[end,(end[0]-14*ux+7*uy,end[1]-14*uy-7*ux),(end[0]-14*ux-7*uy,end[1]-14*uy+7*ux)]
                ar=[min(p[0] for p in tri),min(p[1] for p in tri),max(p[0] for p in tri)-min(p[0] for p in tri),max(p[1] for p in tri)-min(p[1] for p in tri)]
                if overlap(ar,expand(t['box'],10)):bad('arrowhead_text_clearance',edge=eid,text=t['text'])
    for a,b in combinations(edges,2):
        permitted=set()
        for aa in ['sourceJunction','targetJunction']:
            for bb in ['sourceJunction','targetJunction']:
                if a['data'].get(aa) and a['data'].get(aa)==b['data'].get(bb):permitted.add(tuple(junctions[a['data'][aa]]))
        for a1,a2 in zip(a['points'],a['points'][1:]):
            for b1,b2 in zip(b['points'],b['points'][1:]):
                hit=seg_intersection(a1,a2,b1,b2)
                if hit is not None and (hit==('overlap',) or not any(same(hit,p) for p in permitted)):
                    bad('unmarked_connector_intersection',a=a['id'],b=b['id'],position=hit)
    return issues

EXTRACT=r'''() => {
 const s=document.querySelector('svg'),v=s.viewBox.baseVal;
 const box=e=>{const b=e.getBBox();return [b.x,b.y,b.width,b.height]};
 const points=e=>Array.from(e.points).map(p=>[p.x,p.y]);
 return {width:v.width,height:v.height,
 texts:Array.from(s.querySelectorAll('text')).map(e=>({id:e.id,text:e.textContent,box:box(e),size:+e.getAttribute('font-size'),owner:e.dataset.owner||null,padding:+e.dataset.padding})),
 rects:Array.from(s.querySelectorAll('rect[data-kind]')).map(e=>({id:e.id,box:box(e),kind:e.dataset.kind,stroke:e.getAttribute('stroke'),stroke_width:+e.getAttribute('stroke-width')})),
 connectors:Array.from(s.querySelectorAll('[data-kind="connector"]')).map(e=>({id:e.id,points:points(e),width:+e.getAttribute('stroke-width'),arrow:!!e.getAttribute('marker-end'),data:{...e.dataset}})),
 rules:Array.from(s.querySelectorAll('polyline:not([data-kind="connector"])')).map(e=>({id:e.id,points:points(e),width:+e.getAttribute('stroke-width')})),
 junctions:Array.from(s.querySelectorAll('[data-kind="junction"]')).map(e=>({id:e.id,x:+e.getAttribute('cx'),y:+e.getAttribute('cy')})),
 raster_images:s.querySelectorAll('image').length,
 markers:Array.from(s.querySelectorAll('marker')).map(e=>({id:e.id,refX:e.getAttribute('refX')}))};
}'''

def main():
    p=argparse.ArgumentParser(description=__doc__,formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--browser',type=Path);p.add_argument('--png',action='store_true');p.add_argument('--png-scale',type=float,default=1.5)
    a=p.parse_args()
    if not .5<=a.png_scale<=4:p.error('--png-scale must lie within 0.5..4')
    report=[];measurements={}
    with sync_playwright() as play:
        kwargs={'headless':True,'args':['--no-sandbox']};exe=str(a.browser) if a.browser else shutil.which('chromium')
        if exe:kwargs['executable_path']=exe
        browser=play.chromium.launch(**kwargs)
        page=browser.new_page(device_scale_factor=a.png_scale)
        for path in sorted((ROOT/'assets').rglob('*.svg')):
            rel=str(path.relative_to(ROOT));xml=path.read_text(encoding='utf-8').split('?>',1)[-1]
            page.set_content('<!doctype html><meta charset="utf-8"><style>html,body{margin:0;padding:0}svg{display:block}</style>'+xml)
            page.evaluate('document.fonts.ready')
            v=page.evaluate(EXTRACT);issues=validate(v)
            if v['raster_images']:issues.append({'kind':'embedded_raster'})
            if any(float(m['refX'])!=14 for m in v['markers']):issues.append({'kind':'arrow_marker_tip_mismatch'})
            measurements[rel]=v
            if a.png:
                page.set_viewport_size({'width':int(v['width']),'height':int(v['height'])})
                dest=path.parent/'png'/path.with_suffix('.png').name;dest.parent.mkdir(exist_ok=True)
                page.locator('svg').screenshot(path=str(dest),animations='disabled')
            report.append({'file':rel,'text_objects':len(v['texts']),'connectors':len(v['connectors']),
                           'arrowheads':sum(bool(z['arrow']) for z in v['connectors']),'issues':issues})
            print(rel+': '+('PASS' if not issues else f'{len(issues)} ISSUES'))
            for issue in issues[:12]:print(' ',issue)
        font_info=page.evaluate('''() => ({noto:document.fonts.check('32px "Noto Sans CJK SC"'),userAgent:navigator.userAgent})''')
        browser.close()
    out={'method':'Browser SVG getBBox + exact port and segment geometry; no OCR',
         'font_environment':font_info,'minimum_connector_text_clearance_px':10,
         'minimum_frame_text_clearance_px':6,'small_grid_digit_frame_clearance_px':4,
         'note':'Checks concern geometry only. Semantic connections are manually reviewed against the illustrations.',
         'figures':len(report),'text_objects':sum(r['text_objects'] for r in report),
         'connectors':sum(r['connectors'] for r in report),'arrowheads':sum(r['arrowheads'] for r in report),
         'issue_count':sum(len(r['issues']) for r in report),'results':report}
    (ROOT/'checks/precise_geometry_validation.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    (ROOT/'checks/rendered_figure_geometry.json').write_text(json.dumps(measurements,ensure_ascii=False,separators=(',',':')),encoding='utf-8')
    print('TOTAL:',out['figures'],'figures;',out['text_objects'],'texts;',out['connectors'],'connections;',out['issue_count'],'issues')
    raise SystemExit(1 if out['issue_count'] else 0)
if __name__=='__main__':main()
