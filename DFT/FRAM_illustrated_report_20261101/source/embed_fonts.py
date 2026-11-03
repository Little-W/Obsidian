"""Subset the bundled OFL font and embed a portable font in every SVG.
Requires fontTools (pip install fonttools). WOFF uses the standard zlib encoder.
"""
from pathlib import Path
from xml.etree import ElementTree as ET
from io import BytesIO
import base64,re
from fontTools import subset
from fontTools.ttLib import TTFont
from diagram_common import ROOT

def make_subset(text, family, stem, otf=False):
    source=ROOT/"assets/fonts/NotoSansCJKsc-Regular.otf"
    font=TTFont(source)
    options=subset.Options()
    options.name_IDs=["*"];options.name_languages=["*"]
    engine=subset.Subsetter(options=options)
    engine.populate(text=text)
    engine.subset(font)
    ps=family.replace(" ","")+"-Regular"
    names={1:family,2:"Regular",3:family+" Regular 20261101",4:family+" Regular",6:ps,16:family,17:"Regular"}
    for record in font["name"].names:
        if record.nameID in names:
            try:record.string=names[record.nameID].encode(record.getEncoding())
            except UnicodeEncodeError:record.string=names[record.nameID].encode("utf-16-be")
    if "CFF " in font:
        font["CFF "].cff.fontNames=[ps]
        top=font["CFF "].cff.topDictIndex[0]
        top.FamilyName=family;top.FullName=family+" Regular"
    dest=ROOT/"assets/fonts"
    if otf:
        font.flavor=None;font.save(dest/(stem+".otf"))
    font.flavor="woff";font.save(dest/(stem+".woff"))
    return (dest/(stem+".woff")).read_bytes()

def main():
    svgs=sorted((ROOT/"figures/svg").glob("*.svg"))
    cleaned=[re.sub(r'<style id="fram-embedded-font">.*?</style>',"",p.read_text(),flags=re.S) for p in svgs]
    chars="".join("".join(ET.fromstring(s).itertext()) for s in cleaned)+"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ±−→⇕∫≈"
    data=make_subset(chars,"FRAM Diagram Sans","FRAMDiagramSans-Regular",otf=True)
    encoded=base64.b64encode(data).decode()
    css="<style id=\"fram-embedded-font\">@font-face{font-family:'FRAM Diagram Sans';font-style:normal;font-weight:400;src:url(data:font/woff;base64,"+encoded+") format('woff');}</style>"
    for p in svgs:
        s=p.read_text()
        s=re.sub(r'<style id="fram-embedded-font">.*?</style>',"",s,flags=re.S)
        s=s.replace("</desc>","</desc>"+css,1)
        p.write_text(s)
    report_path=ROOT/"FRAM_特殊故障与测试算法调研_20261101.md"
    base_path=ROOT.parent/"FRAM_特殊故障与测试算法调研_20261101.md"
    text=(report_path if report_path.exists() else base_path).read_text()+chars
    report=make_subset(text,"FRAM Report Sans","FRAMReportSans-Regular")
    print("Embedded font into",len(svgs),"SVG files;",len(data),"diagram font bytes;",len(report),"report font bytes")
if __name__=="__main__":main()

