#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Deterministic, editable SVG geometry for the scan/ATPG handbook.

Python >= 3.10; generation uses the standard library only.
Connectors reference named ports; text is never converted to outlines.
Actual font metrics and all intersections are checked separately in Chromium.
No font files or external resources are embedded.
"""
from __future__ import annotations
from dataclasses import dataclass
import json
from pathlib import Path
import xml.etree.ElementTree as ET

NS='http://www.w3.org/2000/svg'
ET.register_namespace('',NS)
W=1200
FONT='"Noto Sans CJK SC", "Microsoft YaHei", "PingFang SC", "Source Han Sans SC", sans-serif'
SIZES={'title':48,'node':36,'body':32,'note':30,'minimum':28}
C={'ink':'#172D46','muted':'#4F6278','blue':'#1967A4','teal':'#118575',
   'orange':'#D97A16','red':'#B84051','purple':'#92517C','grid':'#DBE3EC',
   'paper':'#FFFFFF','pale':'#F3F7FB','pale_teal':'#F0F8F6','pale_orange':'#FFF6ED',
   'pale_red':'#FCF1F3','slate':'#738A9F','zero':'#EAF2FA'}
def col(s):return C.get(s,s)
def e(tag,attrs=None,text=None):
    z=ET.Element('{'+NS+'}'+tag,{k:str(v) for k,v in (attrs or {}).items()})
    if text is not None:z.text=str(text)
    return z

def rough_width(text,size):
    # Conservative character widths are only for wrapping. The export is measured
    # using getBBox in the actual browser; guessed metrics do not certify layout.
    return sum(1.02 if ord(c)>255 else .66 for c in text)*size

def wrap(text,max_width,size):
    if rough_width(text,size)<=max_width:return [text]
    out=[];buf=''
    for ch in text:
        if rough_width(buf+ch,size)>max_width and buf:
            out.append(buf);buf=''
        buf+=ch
    if buf:out.append(buf)
    return out

@dataclass(frozen=True)
class Port:
    node:str
    side:str
    fraction:float=.5
@dataclass
class Box:
    id:str;x:float;y:float;w:float;h:float;kind:str='node'
    def point(self,side,f=.5):
        if side=='N':return (self.x+f*self.w,self.y)
        if side=='S':return (self.x+f*self.w,self.y+self.h)
        if side=='W':return (self.x,self.y+f*self.h)
        if side=='E':return (self.x+self.w,self.y+f*self.h)
        raise ValueError(side)

class Figure:
    def __init__(self,stem,title,subtitle,height=1600):
        self.stem=stem;self.title=title;self.height=height
        self.root=e('svg',{'width':W,'height':height,'viewBox':f'0 0 {W} {height}',
                    'role':'img','aria-labelledby':'fig-title fig-description','version':'1.1',
                    'data-layout-version':'precise-ports-v2'})
        self.root.append(e('title',{'id':'fig-title'},title))
        self.root.append(e('desc',{'id':'fig-description'},subtitle))
        self.root.append(e('metadata',text=json.dumps({'layout':'named ports + orthogonal routes',
                'font_policy':'editable text; no embedded fonts','version':2},ensure_ascii=False)))
        defs=e('defs');self.root.append(defs)
        for k in ['blue','teal','orange','red','muted','slate','purple']:
            # Tip x=14 and reference x=14 are identical: no hand-tuned arrow gap.
            m=e('marker',{'id':'arrow-'+k,'viewBox':'0 0 14 14','refX':14,'refY':7,
               'markerWidth':14,'markerHeight':14,'orient':'auto','markerUnits':'userSpaceOnUse','overflow':'visible'})
            m.append(e('path',{'d':'M 0 0 L 14 7 L 0 14 Z','fill':col(k)}));defs.append(m)
        self.layers={}
        for name in ['background','shapes','connectors','text','junctions']:
            layer=e('g',{'id':'layer-'+name});self.layers[name]=layer;self.root.append(layer)
        self.bg=e('rect',{'width':W,'height':height,'fill':col('paper')});self.layers['background'].append(self.bg)
        self.boxes={};self.edges=[];self.texts=[];self.counter=0;self.bottom=0;self.junctions={}
        self.t(64,80,title,size=48,weight=700)
        lines=wrap(subtitle,1072,30)
        for i,s in enumerate(lines):self.t(64,145+i*44,s,size=30,color='muted')
        self.content_top=210+(len(lines)-1)*44

    def uid(self,prefix):
        self.counter+=1;return f'{prefix}-{self.counter:04d}'
    def add(self,layer,tag,attrs=None,text=None):
        z=e(tag,attrs,text);self.layers[layer].append(z);return z
    def t(self,x,y,text,size=32,color='ink',weight=400,anchor='start',owner=None,padding=12,id=None):
        tid=id or self.uid('text')
        a={'id':tid,'x':x,'y':y,'font-family':FONT,'font-size':size,'font-weight':weight,
           'fill':col(color),'text-anchor':anchor,'dominant-baseline':'central',
           'data-kind':'text','data-padding':padding}
        if owner:a['data-owner']=owner
        self.add('text','text',a,text)
        self.texts.append({'id':tid,'text':text,'owner':owner,'padding':padding})
        self.bottom=max(self.bottom,y+size*.8)
        return tid
    def lines(self,x,y,lines,gap=50,**kw):
        for i,s in enumerate(lines):self.t(x,y+i*gap,s,**kw)
    def rect(self,id,x,y,w,h,fill='paper',stroke='grid',radius=12,kind='node',stroke_width=2):
        if id in self.boxes:raise ValueError('Duplicate object id: '+id)
        b=Box(id,x,y,w,h,kind);self.boxes[id]=b
        self.add('shapes','rect',{'id':id,'x':x,'y':y,'width':w,'height':h,'rx':radius,
                   'fill':col(fill),'stroke':col(stroke),'stroke-width':stroke_width,
                   'data-kind':kind,'data-obstacle':'true' if kind=='node' else 'false'})
        self.bottom=max(self.bottom,y+h)
        return b
    def node(self,id,x,y,w,title,body=(),accent='blue',fill='paper',h=None,ts=36,bs=32):
        body=list(body)
        if h is None:h=110+len(body)*50 if body else 104
        b=self.rect(id,x,y,w,h,fill,accent,kind='node')
        if body:
            self.t(x+w/2,y+48,title,size=ts,color=accent,weight=700,anchor='middle',owner=id,padding=20)
            self.lines(x+w/2,y+106,body,gap=50,size=bs,color='ink',anchor='middle',owner=id,padding=20)
        else:self.t(x+w/2,y+h/2,title,size=ts,color=accent,weight=700,anchor='middle',owner=id,padding=20)
        return b
    def note(self,y,lines):
        for i,s in enumerate(lines):self.t(64,y+i*46,s,size=30,color='muted')
    def port(self,node,side,f=.5):
        if not 0<=f<=1:raise ValueError('Port fraction outside [0,1]')
        return Port(node,side,f)
    def point(self,ref):
        if isinstance(ref,Port):return self.boxes[ref.node].point(ref.side,ref.fraction)
        if isinstance(ref,str):return self.junctions[ref]
        return tuple(ref)
    def junction(self,id,x,y,color='blue',visible=True):
        if id in self.junctions:raise ValueError('Duplicate junction')
        self.junctions[id]=(x,y)
        self.add('junctions','circle',{'id':id,'cx':x,'cy':y,'r':4.5 if visible else 0,
                 'fill':col(color),'data-kind':'junction'})
        return id
    def edge(self,id,source,target,via=(),color='blue',arrow=True,dashed=False,meaning=''):
        pts=[self.point(source),*[tuple(p) for p in via],self.point(target)]
        pts=[p for i,p in enumerate(pts) if i==0 or p!=pts[i-1]]
        if len(pts)<2:raise ValueError(f'{id}: zero-length connection')
        for a,b in zip(pts,pts[1:]):
            if abs(a[0]-b[0])>1e-6 and abs(a[1]-b[1])>1e-6:
                raise ValueError(f'{id}: non-orthogonal segment {a} -> {b}')
        attrs={'id':id,'points':' '.join(f'{x:g},{y:g}' for x,y in pts),'fill':'none','stroke':col(color),
               'stroke-width':3,'stroke-linejoin':'round','stroke-linecap':'butt','data-kind':'connector',
               'data-meaning':meaning}
        for which,ref in [('source',source),('target',target)]:
            if isinstance(ref,Port):
                attrs[f'data-{which}-node']=ref.node;attrs[f'data-{which}-side']=ref.side
                attrs[f'data-{which}-fraction']=ref.fraction
            elif isinstance(ref,str):attrs[f'data-{which}-junction']=ref
            else:attrs[f'data-{which}-coordinate']=' '.join(map(str,ref))
        if arrow:attrs['marker-end']=f'url(#arrow-{color})'
        if dashed:attrs['stroke-dasharray']='10 8'
        self.add('connectors','polyline',attrs)
        self.edges.append({'id':id,'source':attrs.get('data-source-node',attrs.get('data-source-junction','coordinate')),
                           'target':attrs.get('data-target-node',attrs.get('data-target-junction','coordinate')),
                           'meaning':meaning,'points':pts,'arrow':arrow})
        self.bottom=max(self.bottom,max(y for _,y in pts))
    def connect(self,id,a,b,color='blue',**kw):
        self.edge(id,self.port(a,'S'),self.port(b,'N'),color=color,**kw)
    def rule(self,id,points,color='grid',width=2,dashed=False,kind='rule'):
        a={'id':id,'points':' '.join(f'{x:g},{y:g}' for x,y in points),'fill':'none','stroke':col(color),
           'stroke-width':width,'data-kind':kind}
        if dashed:a['stroke-dasharray']='6 6'
        self.add('shapes','polyline',a)
    def save(self,path):
        self.height=int(max(self.height,self.bottom+56))
        self.root.set('height',str(self.height));self.root.set('viewBox',f'0 0 {W} {self.height}');self.bg.set('height',str(self.height))
        ET.indent(self.root,space='  ')
        path=Path(path);path.parent.mkdir(parents=True,exist_ok=True)
        ET.ElementTree(self.root).write(path,encoding='utf-8',xml_declaration=True)
        return {'file':path.name,'title':self.title,'width':W,'height':self.height,
                'editable_text':True,'embedded_raster_images':0,'font_sizes_px':SIZES,
                'nodes':len([b for b in self.boxes.values() if b.kind=='node']),
                'text_objects':len(self.texts),'connections':len(self.edges),'connection_map':self.edges}
