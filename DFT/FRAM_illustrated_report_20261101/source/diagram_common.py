"""Shared SVG primitives for the FRAM illustrated report.
All figures are qualitative original teaching diagrams, unless explicitly noted.
Python 3 standard library only. Coordinates use a 1400 px-wide design canvas.
"""
from pathlib import Path
from html import escape
import math
import re

ROOT = Path(__file__).resolve().parents[1]
SVG_DIR = ROOT / "figures" / "svg"
PNG_DIR = ROOT / "figures" / "png"
C = {
    "ink": "#172C45", "muted": "#52667C", "line": "#CBD7E3",
    "blue": "#2366B0", "blue_bg": "#EDF4FC",
    "teal": "#137D79", "teal_bg": "#E9F6F3",
    "orange": "#B56A13", "orange_bg": "#FFF3E4",
    "red": "#B64B53", "red_bg": "#FCEEF0",
    "purple": "#7250A3", "purple_bg": "#F4EFFA",
    "gray_bg": "#F4F7FA", "white": "#FFFFFF",
}
FONT = "FRAM Diagram Sans,Noto Sans CJK SC,Source Han Sans SC,Noto Sans SC,Microsoft YaHei,sans-serif"

class SVG:
    def __init__(self, filename, title, subtitle="", height=900, width=1400):
        if not re.match(r"图\s*\d+", title):
            m = re.match(r"fig(\d+)", filename)
            if m: title = f"图{int(m.group(1))}　{title}"
        self.filename, self.w, self.h = filename, width, height
        self.parts = [
            f'<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" width="{width}" height="{height}" viewBox="0 0 {width} {height}" role="img">',
            f'<title>{escape(title)}</title><desc>{escape(subtitle)}</desc>',
            '<defs><marker id="arrow-ink" markerWidth="10" markerHeight="10" refX="8" refY="5" orient="auto-start-reverse" markerUnits="userSpaceOnUse"><path d="M 0 1 L 8 5 L 0 9 Z" fill="#52667C"/></marker></defs>',
            f'<rect width="{width}" height="{height}" fill="#FFFFFF"/>',
            f'<rect x="0" y="0" width="{width}" height="10" fill="{C["blue"]}"/>',
        ]
        self.text(52, 65, title, size=39, weight=700)
        if subtitle: self.text(54, 108, subtitle, size=21, fill=C["muted"])
        self.line(52, 132, width-52, 132, color=C["line"], width=1.5)
    def add(self, raw): self.parts.append(raw)
    def rect(self, x, y, w, h, fill="white", stroke="line", radius=12, width=1.5, dash=None):
        f=C.get(fill,fill); s=C.get(stroke,stroke)
        d=f' stroke-dasharray="{dash}"' if dash else ""
        self.add(f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="{radius}" fill="{f}" stroke="{s}" stroke-width="{width}"{d}/>')
    def text(self,x,y,value,size=26,fill=None,weight=400,anchor="start",linespacing=1.42):
        fill=C.get(fill,fill) if fill else C["ink"]
        lines=str(value).split("\n")
        spans="".join(f'<tspan x="{x}" dy="{0 if i==0 else size*linespacing}">{escape(line)}</tspan>' for i,line in enumerate(lines))
        self.add(f'<text x="{x}" y="{y}" font-family="{FONT}" font-size="{size}" font-weight="{weight}" fill="{fill}" text-anchor="{anchor}">{spans}</text>')
    def line(self,x1,y1,x2,y2,color="line",width=2,dash=None,arrow=False):
        d=f' stroke-dasharray="{dash}"' if dash else ""
        a=' marker-end="url(#arrow-ink)"' if arrow else ""
        self.add(f'<line x1="{x1}" y1="{y1}" x2="{x2}" y2="{y2}" stroke="{C.get(color,color)}" stroke-width="{width}"{d}{a}/>')
    def path(self,d,color="ink",width=2.5,fill="none",dash=None,arrow=False):
        a=' marker-end="url(#arrow-ink)"' if arrow else ""
        ds=f' stroke-dasharray="{dash}"' if dash else ""
        self.add(f'<path d="{d}" stroke="{C.get(color,color)}" fill="{C.get(fill,fill)}" stroke-width="{width}" stroke-linecap="round" stroke-linejoin="round"{ds}{a}/>')
    def polyline(self,points,color="ink",width=2.5,dash=None,arrow=False):
        d="M "+" L ".join(f"{x:.2f} {y:.2f}" for x,y in points)
        self.path(d,color,width,dash=dash,arrow=arrow)
    def circle(self,x,y,r=5,fill="ink",stroke="none",width=1):
        self.add(f'<circle cx="{x}" cy="{y}" r="{r}" fill="{C.get(fill,fill)}" stroke="{C.get(stroke,stroke)}" stroke-width="{width}"/>')
    def card(self,x,y,w,h,title,body="",accent="blue",size=25):
        self.rect(x,y,w,h,fill=accent+"_bg",stroke="line",radius=14)
        self.rect(x,y,7,h,fill=accent,stroke="none",radius=3)
        self.text(x+24,y+40,title,size=size+2,weight=700,fill=accent)
        if body: self.text(x+24,y+81,body,size=size)
    def tag(self,x,y,label,color="blue",w=None):
        w=w or max(88, len(label)*22+26)
        self.rect(x,y,w,40,fill=color+"_bg",stroke="none",radius=20)
        self.text(x+w/2,y+28,label,size=21,fill=color,weight=700,anchor="middle")
    def arrow(self,x1,y1,x2,y2,color="muted",width=2.5):
        self.line(x1,y1,x2,y2,color,width,arrow=True)
    def footer(self,source, note="定性示意；非实测曲线，比例与时序不代表器件规格。"):
        self.line(52,self.h-75,self.w-52,self.h-75,color="line",width=1)
        self.text(54,self.h-47,note,size=19,fill="muted")
        self.text(54,self.h-19,source,size=18,fill="muted")
    def save(self):
        SVG_DIR.mkdir(parents=True,exist_ok=True)
        path=SVG_DIR/self.filename
        path.write_text("\n".join(self.parts)+"\n</svg>\n",encoding="utf-8")
        return path

def linspace(a,b,n=120):
    return [a+(b-a)*i/(n-1) for i in range(n)]

def axis(g,x,y,w,h,xlabel="",ylabel="",xmin=None,xmax=None):
    g.line(x,y,x+w,y,"muted",2,arrow=True)
    g.line(x,y,x,y-h,"muted",2,arrow=True)
    if xlabel:g.text(x+w,y+37,xlabel,size=23,anchor="end",fill="muted")
    if ylabel:g.text(x,y-h-18,ylabel,size=23,fill="muted")

