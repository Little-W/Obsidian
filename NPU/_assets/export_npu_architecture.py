#!/usr/bin/env python3
"""Export explicitly-routed NPU Draw.io architecture figures to SVG/PNG.

Only the small rectangle/text/polyline subset used by the architecture figures
is supported. Draw.io is the editable source; this does not raster-edit exports.
"""
from __future__ import annotations
import argparse
import html
from pathlib import Path
import re
import subprocess
import xml.etree.ElementTree as ET
from PIL import ImageFont

ASSETS = Path(__file__).resolve().parent
SVG = 'http://www.w3.org/2000/svg'
ET.register_namespace('', SVG)
FONT_PATH = subprocess.check_output(['fc-match','-f','%{file}','Noto Sans CJK SC'],text=True).strip()

def sub(node, kind, **attrs):
    return ET.SubElement(node, '{'+SVG+'}'+kind, {k.replace('_','-'):str(v) for k,v in attrs.items()})

def style(cell):
    return dict(x.split('=',1) for x in cell.get('style','').split(';') if '=' in x)

def label(cell):
    value=cell.get('value','')
    for _ in range(2):value=html.unescape(value)
    value=re.sub(r'<br\s*/?>','\n',value)
    return re.sub(r'<[^>]*>','',value)

def wrapped(value, width, size):
    font=ImageFont.truetype(FONT_PATH,round(size))
    result=[]
    for line in value.splitlines():
        current=''
        for char in line:
            if current and font.getlength(current+char)>width:
                result.append(current);current=char
            else:current+=char
        result.append(current)
    return result

def export(name):
    tree=ET.parse(ASSETS/(name+'.drawio'));model=tree.find('.//mxGraphModel')
    width=float(model.get('pageWidth'));height=float(model.get('pageHeight'))
    cells=list(model.findall('./root/mxCell')); boxes={}
    root=ET.Element('{'+SVG+'}svg',viewBox=f'0 0 {width:g} {height:g}',width=f'{width:g}',height=f'{height:g}')
    sub(root,'rect',x=0,y=0,width=width,height=height,fill='white')
    defs=sub(root,'defs')
    for color in ['#2563EB','#7C3AED','#059669','#D97706','#0F766E']:
        marker=sub(defs,'marker',id='arrow'+color[1:],markerWidth=20,markerHeight=14,refX=20,refY=7,markerUnits='userSpaceOnUse',orient='auto-start-reverse')
        sub(marker,'path',d='M0,0 L20,7 L0,14 Z',fill=color)
    for cell in cells:
        if cell.get('vertex')!='1':continue
        g=cell.find('mxGeometry');boxes[cell.get('id')]=tuple(float(g.get(k,0)) for k in ['x','y','width','height'])
    def render_vertex(cell):
        st=style(cell);x,y,w,h=boxes[cell.get('id')];value=label(cell);size=float(st.get('fontSize',18))
        fill=st.get('fillColor','none');stroke=st.get('strokeColor','none')
        if fill!='none' or stroke!='none':
            sub(root,'rect',x=x,y=y,width=w,height=h,rx=14 if st.get('rounded')=='1' else 0,fill=fill,stroke=stroke,stroke_width=st.get('strokeWidth',1.5))
        if not value:return
        is_container=st.get('container')=='1';lines=wrapped(value,w-(48 if is_container else 32),size)
        spacing=size*1.45;total=size+(len(lines)-1)*spacing
        if total>h-12:raise ValueError(f'{name}: text exceeds box: {value}')
        left=st.get('align')=='left';top=st.get('verticalAlign')=='top'
        tx=x+(24 if is_container else 12) if left else x+w/2
        start=y+34 if top else y+(h-total)/2+size
        node=sub(root,'text',x=tx,y=start,fill=st.get('fontColor','#17324D'),font_family='Noto Sans CJK SC',font_size=size,font_weight=600,text_anchor='start' if left else 'middle')
        for i,line in enumerate(lines):sub(node,'tspan',x=tx,y=start+i*spacing).text=line
    # Containers are behind all connections and visible module nodes.
    for cell in cells:
        if cell.get('vertex')=='1' and style(cell).get('container')=='1':render_vertex(cell)
    paths=[]
    for cell in cells:
        if cell.get('edge')!='1':continue
        st=style(cell);sx,sy,sw,sh=boxes[cell.get('source')];tx,ty,tw,th=boxes[cell.get('target')]
        points=[(sx+float(st.get('exitX',.5))*sw,sy+float(st.get('exitY',.5))*sh)]
        for point in cell.findall('./mxGeometry/Array/mxPoint'):points.append((float(point.get('x')),float(point.get('y'))))
        points.append((tx+float(st.get('entryX',.5))*tw,ty+float(st.get('entryY',.5))*th))
        color=st.get('strokeColor','#2563EB');path=' '.join(('M' if i==0 else 'L')+f'{x:g},{y:g}' for i,(x,y) in enumerate(points))
        attrs={'d':path,'fill':'none','stroke':color,'stroke_width':st.get('strokeWidth',3),'marker_end':'url(#arrow'+color[1:]+')'}
        if st.get('startArrow')=='block':attrs['marker_start']='url(#arrow'+color[1:]+')'
        if st.get('dashed')=='1':attrs['stroke_dasharray']='8 5'
        sub(root,'path',**attrs);paths.append({'source':cell.get('source'),'target':cell.get('target'),'points':points})
    for cell in cells:
        if cell.get('vertex')=='1' and style(cell).get('container')!='1':render_vertex(cell)
    # Ensure a source-target line never passes through another module rectangle.
    for item in paths:
        for key,(x,y,w,h) in boxes.items():
            cell=next(c for c in cells if c.get('id')==key);st=style(cell)
            if key in [item['source'],item['target']] or st.get('container')=='1':continue
            for (ax,ay),(bx,by) in zip(item['points'],item['points'][1:]):
                if ax==bx and x<ax<x+w and max(min(ay,by),y)<min(max(ay,by),y+h):raise ValueError(f'{name}: line crosses {label(cell)}')
                if ay==by and y<ay<y+h and max(min(ax,bx),x)<min(max(ax,bx),x+w):raise ValueError(f'{name}: line crosses {label(cell)}')
    # All connectors use independent orthogonal corridors; reject intersections.
    for i, first in enumerate(paths):
        for second in paths[i+1:]:
            for (ax,ay),(bx,by) in zip(first['points'],first['points'][1:]):
                for (cx,cy),(dx,dy) in zip(second['points'],second['points'][1:]):
                    ah=abs(ay-by)<1e-6; av=abs(ax-bx)<1e-6
                    ch=abs(cy-dy)<1e-6; cv=abs(cx-dx)<1e-6
                    hit=False
                    if ah and ch and abs(ay-cy)<1e-6:
                        hit=max(min(ax,bx),min(cx,dx))<min(max(ax,bx),max(cx,dx))-1e-6
                    elif av and cv and abs(ax-cx)<1e-6:
                        hit=max(min(ay,by),min(cy,dy))<min(max(ay,by),max(cy,dy))-1e-6
                    elif ah and cv:
                        hit=min(ax,bx)+1e-6<cx<max(ax,bx)-1e-6 and min(cy,dy)+1e-6<ay<max(cy,dy)-1e-6
                    elif av and ch:
                        hit=min(cx,dx)+1e-6<ax<max(cx,dx)-1e-6 and min(ay,by)+1e-6<cy<max(ay,by)-1e-6
                    if hit:raise ValueError(f'{name}: connectors intersect')
    out=ASSETS/(name+'.svg');ET.indent(root);ET.ElementTree(root).write(out,encoding='utf-8',xml_declaration=True)
    subprocess.run(['inkscape',str(out),'--export-type=png','--export-filename='+str(ASSETS/(name+'.png')),'--export-width=1800'],check=True,stdout=subprocess.DEVNULL,stderr=subprocess.PIPE)
    print(name+': editable source exported; module intersection check passed')

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('names',nargs='+');args=parser.parse_args()
    for name in args.names:export(name)

if __name__=='__main__':main()
