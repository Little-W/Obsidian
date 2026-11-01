#!/usr/bin/env python3
"""Draw structured XOR/AND/OR branch-and-join semantics; all data are examples."""
from pathlib import Path
import os
import tempfile

os.environ.setdefault("MPLCONFIGDIR", str(Path(tempfile.gettempdir()) / "agent_report_mpl_cache"))
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib import font_manager
from matplotlib.patches import FancyBboxPatch, FancyArrowPatch, Polygon
from matplotlib.path import Path as MplPath

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "figures"
OUT.mkdir(exist_ok=True)
font_path = Path(os.environ.get("AGENT_REPORT_CJK_FONT", "/tmp/agent_report_fonts/DroidSansFallback.ttf"))
if not font_path.exists():
    import fitz
    font_path = Path(tempfile.gettempdir()) / "agent_report_cjk_fallback.ttf"
    font_path.write_bytes(fitz.Font("cjk").buffer)
font_manager.fontManager.addfont(str(font_path))
FONT = font_manager.FontProperties(fname=str(font_path))
matplotlib.rcParams.update({"font.family": FONT.get_name(), "svg.fonttype": "none", "axes.unicode_minus": False})

INK, BLUE, TEAL = "#183047", "#2864B4", "#11847B"
MUTED, LINE, ORANGE = "#516579", "#A6B7C8", "#C97722"
PALE, PTEAL, PORANGE = "#F3F6FA", "#EDF8F5", "#FFF5E9"

def text(ax, x, y, value, size=18, color=INK, ha="center", va="center"):
    ax.text(x, y, value, fontproperties=FONT, fontsize=size, color=color,
            ha=ha, va=va, linespacing=1.5, zorder=6)

def box(ax, x, y, w, h, value, color=TEAL, face=PTEAL, size=18):
    ax.add_patch(FancyBboxPatch((x,y), w,h, boxstyle="round,pad=0,rounding_size=14",
                              facecolor=face, edgecolor=color, linewidth=1.8, zorder=3))
    text(ax,x+w/2,y+h/2,value,size,color if color != LINE else MUTED)

def arrow(ax, pts, color=TEAL, dash=False, head=True):
    path = MplPath(pts,[MplPath.MOVETO]+[MplPath.LINETO]*(len(pts)-1))
    ax.add_patch(FancyArrowPatch(path=path,arrowstyle="-|>" if head else "-", mutation_scale=17,
                                linewidth=2.3, linestyle="--" if dash else "-",color=color,zorder=4))

def gateway(ax, x,y, label, color=TEAL):
    ax.add_patch(Polygon([(x,y-43),(x+57,y),(x,y+43),(x-57,y)],closed=True,
                        facecolor="white",edgecolor=color,linewidth=2,zorder=3))
    text(ax,x,y,label,21,color)

def row(ax, y, name, rule, foot, kind):
    box(ax,55,y,1890,380,"",color=LINE,face="white")
    text(ax,90,y+48,name,24,BLUE,ha="left")
    text(ax,90,y+120,rule,18,MUTED,ha="left")
    text(ax,90,y+275,foot,17,ORANGE if kind=="OR" else MUTED,ha="left")
    center=y+205
    gateway(ax,585,center,kind)
    gateway(ax,1310,center,kind)
    positions = [center-70,center+70] if kind!="OR" else [center-105,center,center+105]
    labels = ["A 已完成", "B 未激活"] if kind=="XOR" else (["A 已完成","B 运行中"] if kind=="AND" else ["A 已完成","B 未激活","C 运行中"])
    selected = [True,False] if kind=="XOR" else ([True,True] if kind=="AND" else [True,False,True])
    for yy,lab,active in sorted(zip(positions,labels,selected), key=lambda item: item[2]):
        color = TEAL if active else LINE
        face = PTEAL if active else PALE
        box(ax,825,yy-34,250,68,lab,color=color,face=face,size=19)
        # Dedicated orthogonal lanes keep arrows clear of labels and node borders.
        arrow(ax,[(642,center),(715,center),(715,yy),(825,yy)],color,dash=not active)
        arrow(ax,[(1075,yy),(1185,yy),(1185,center),(1253,center)],color,dash=not active)
    if kind=="XOR":
        result="A 到达即可继续\n不等待 B"
        color=TEAL
    elif kind=="AND":
        result="等待 A 和 B\nB 尚未完成，继续等待"
        color=ORANGE
    else:
        result="本次集合 {A, C}\n等待 C，不等待 B"
        color=ORANGE
    arrow(ax,[(1367,center),(1480,center)],color=color,dash=True,head=False)
    text(ax,1680,center-88,"当前汇合状态",16,MUTED)
    box(ax,1480,center-63,400,126,result,color=color,face=PTEAL if kind=="XOR" else PORANGE,size=18)
    text(ax,585,y+330,"分支",17,MUTED)
    text(ax,1310,y+330,"汇合",17,MUTED)

def main():
    fig,ax=plt.subplots(figsize=(20,16),dpi=100)
    fig.subplots_adjust(0,0,1,1)
    ax.set_xlim(0,2000); ax.set_ylim(1600,0); ax.set_aspect("equal"); ax.axis("off")
    ax.plot([60,60],[42,92],color=TEAL,lw=5,solid_capstyle="round")
    text(ax,85,65,"07  分支与汇合：三种连线相似、语义不同的情况",27,ha="left")
    text(ax,85,118,"结构化分支示例；实线表示本次已激活路径，灰色虚线表示未激活路径。",17,MUTED,ha="left")
    row(ax,175,"XOR：选择一条路径","激活：A 或 B\n本次选择 A。","汇合不作全分支同步。\n这一轮只有一个分支会到达。","XOR")
    row(ax,605,"AND：并发执行全部路径","激活：A 和 B\n本次两条路径都启动。","汇合等待全部指定输入。\n还须定义失败、取消、超时。","AND")
    row(ax,1035,"OR：执行所有满足条件的路径","激活：满足条件的子集\n本次选中 A、C。","汇合范围来自本次选择。\n不能把未选 B 算作未完成。","OR")
    text(ax,1000,1480,"运行时需保存：分支批次、已激活成员、各成员终态、汇合是否已触发。",20,BLUE)
    text(ax,1000,1532,"OR 图仅表示配对的结构化分支；任意 BPMN 图的包容汇合还需判断是否仍有路径能够到达。",17,MUTED)
    for ext in ("png","svg"):
        tmp=OUT/f".07_graph_joins.{os.getpid()}.{ext}"
        fig.savefig(tmp,format=ext,dpi=100,facecolor="white")
        os.replace(tmp,OUT/f"07_graph_joins.{ext}")
    plt.close(fig)
    print(OUT/"07_graph_joins.png")

if __name__=="__main__":
    main()
