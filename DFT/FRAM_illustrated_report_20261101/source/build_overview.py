"""Build the overview sheet from the figure manifest."""
from pathlib import Path
import json
from PIL import Image, ImageDraw, ImageFont
from diagram_common import ROOT
def main():
    info=json.loads((ROOT/"source/figures.json").read_text())
    fontpath=ROOT/"assets/fonts/NotoSansCJKsc-Regular.otf"
    title=ImageFont.truetype(str(fontpath),48)
    body=ImageFont.truetype(str(fontpath),24)
    small=ImageFont.truetype(str(fontpath),21)
    w,h=1840,170+((len(info)+2)//3)*495+70
    out=Image.new("RGB",(w,h),"#F1F5FA")
    d=ImageDraw.Draw(out)
    d.rectangle((0,0,w,12),fill="#2366B0")
    d.text((48,40),f"FRAM 故障、建模与测试｜{len(info)}幅插图总览",font=title,fill="#172C45")
    d.text((50,112),"完整报告附可编辑SVG、2800像素PNG与绘图源码；图中曲线均为定性示意。",font=body,fill="#52667C")
    for i,f in enumerate(info):
        col,row=i%3,i//3
        x=35+col*600;y=170+row*495
        d.rounded_rectangle((x,y,x+570,y+470),radius=15,fill="white",outline="#CBD7E3",width=2)
        im=Image.open(ROOT/"figures/png"/(f["stem"]+".png")).convert("RGB")
        im.thumbnail((538,413),Image.Resampling.LANCZOS)
        out.paste(im,(x+(570-im.width)//2,y+14))
        text=f'图{f["number"]}  '+f["title"]
        if d.textlength(text,font=body)>535:
            d.text((x+18,y+421),text,font=small,fill="#172C45")
        else:d.text((x+18,y+421),text,font=body,fill="#172C45")
    d.text((48,h-55),"2026年11月1日  ·  图号与正文一致  ·  全套均为本文原创示意图",font=small,fill="#52667C")
    p=ROOT/"插图总览.png";out.save(p,optimize=True);print(p)
if __name__=="__main__":main()

