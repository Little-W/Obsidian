"""Figure 05: effective read reference and read margins; conceptual only."""
from diagram_common import SVG, C, axis, linspace
import math

def plot_margin(g, x, y, weak=False):
    w,h=560,260
    axis(g,x,y,w,h,"位线电压","相对分布（示意）")
    ref=x+280
    g.line(ref,y+4,ref,y-h+6,"ink",2.2,dash="8 7")
    g.text(ref,y-h-22,"有效参考 R",size=24,anchor="middle")
    mu0,mu1=(200,365) if weak else (140,430)
    sigma=43 if weak else 33
    for mu,color in [(mu0,"blue"),(mu1,"teal")]:
        pts=[]
        for u in linspace(6,550,180):
            a=math.exp(-0.5*((u-mu)/sigma)**2)
            pts.append((x+u,y-190*a))
        g.polyline(pts,color,3.5)
        g.circle(x+mu,y,5,color)
    g.text(x+mu0,y+38,"V₀",size=25,anchor="middle",fill="blue")
    g.text(x+mu1,y+38,"V₁",size=25,anchor="middle",fill="teal")
    ay=y-225
    g.line(x+mu0,ay,ref,ay,"blue",3)
    g.line(x+mu0,ay-7,x+mu0,ay+7,"blue",2)
    g.line(ref,ay-7,ref,ay+7,"blue",2)
    g.text((x+mu0+ref)/2,ay-14,"M₀",size=25,anchor="middle",fill="blue")
    ay2=y-158
    g.line(ref,ay2,x+mu1,ay2,"teal",3)
    g.line(ref,ay2-7,ref,ay2+7,"teal",2)
    g.line(x+mu1,ay2-7,x+mu1,ay2+7,"teal",2)
    g.text((ref+x+mu1)/2,ay2-14,"M₁",size=25,anchor="middle",fill="teal")

def main():
    g=SVG("fig02_read_margin.svg","读裕量同时取决于存储信号与有效参考","同样返回正确数字值的单元，可能具有不同的抗噪声与保持余量。",height=920)
    g.rect(44,157,642,490,fill="gray_bg",stroke="line",radius=16)
    g.rect(714,157,642,490,fill="gray_bg",stroke="line",radius=16)
    g.tag(68,176,"裕量较充分",color="blue",w=180)
    g.tag(738,176,"裕量减小",color="orange",w=170)
    plot_margin(g,87,535,False)
    plot_margin(g,757,535,True)
    g.text(84,611,"两态信号与有效参考保留较大间隔",size=25)
    g.text(754,611,"状态分布靠近参考；尾部可能先出错",size=25)
    g.card(53,680,408,138,"有效参考","R = VREF + VOS",accent="purple",size=28)
    g.card(496,680,408,138,"按本图判决约定","M₀ = R − V₀",accent="blue",size=28)
    g.card(939,680,408,138,"按本图判决约定","M₁ = V₁ − R",accent="teal",size=28)
    g.footer("依据报告第2.3节；参考文献 [7]、[13]。","定性分布示意；不含实测参数。正负偏移按文中的逻辑判决约定定义。")
    print(g.save())
if __name__=="__main__":main()

