#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Build an offline drawing inspection page with switchable geometry overlays.
Run generate_figures.py and validate_precise_figures.py first.
The overlays are separate review assets, never substituted into the handbook.
"""
from pathlib import Path
import json,html,re,xml.etree.ElementTree as ET
from urllib.parse import quote
ROOT=Path(__file__).resolve().parents[1]
NS='http://www.w3.org/2000/svg';ET.register_namespace('',NS)
def tag(t,a):return ET.Element('{'+NS+'}'+t,{k:str(v) for k,v in a.items()})

def main():
    m=json.loads((ROOT/'checks/rendered_figure_geometry.json').read_text())
    report=json.loads((ROOT/'checks/precise_geometry_validation.json').read_text())
    figs=[];edges=[]
    data=json.loads((ROOT/'assets/figures_manifest.json').read_text())
    for item in data['figures']:
        rel=f'assets/{item["file"]}';v=m[rel]
        original=ET.parse(ROOT/rel);g=tag('g',{'id':'review-only-overlay','pointer-events':'none'})
        original.getroot().append(g)
        for t in v['texts']:
            x,y,w,h=t['box']
            # Orange: exact getBBox. Pale wider area: 10px text exclusion.
            g.append(tag('rect',{'x':x-10,'y':y-10,'width':w+20,'height':h+20,'fill':'#E8951C','fill-opacity':.035,
                      'stroke':'#D47B10','stroke-opacity':.5,'stroke-width':.8,'stroke-dasharray':'4 4'}))
            g.append(tag('rect',{'x':x,'y':y,'width':w,'height':h,'fill':'none','stroke':'#E08617','stroke-width':1}))
        pts=set()
        for ed in v['connectors']:
            for p in [ed['points'][0],ed['points'][-1]]:pts.add(tuple(p))
        for x,y in pts:g.append(tag('circle',{'cx':x,'cy':y,'r':7,'fill':'none','stroke':'#079CAE','stroke-width':2}))
        dest=ROOT/'checks/layout_debug'/item['file'];dest.parent.mkdir(parents=True,exist_ok=True)
        ET.indent(original,space='  ');original.write(dest,encoding='utf-8',xml_declaration=True)
        n=int(re.search(r'图\s*(\d+)',item['title'])[1]);rows=''
        for ed in item['connection_map']:
            edges.append({'figure':item['title'],'file':rel,**ed})
            rows+='<tr>'+''.join('<td>'+html.escape(str(ed[k]))+'</td>' for k in ['id','source','target','meaning'])+'</tr>'
        details=f'<details><summary>查看 {len(item["connection_map"])} 条连接的起点、终点与含义</summary><div class="scroll"><table><thead><tr><th>连接编号</th><th>起点</th><th>终点</th><th>含义</th></tr></thead><tbody>{rows}</tbody></table></div></details>' if rows else '<p>本图没有模块连接箭头；仅包含图表、矩阵或概念分项。</p>'
        normal=quote(rel);debug=quote(str(dest.relative_to(ROOT)));png=quote(f'assets/png/{Path(item["file"]).stem}.png')
        figs.append((n,f'<section id="figure-{n}"><h2>{html.escape(item["title"])}</h2><p><a href="{normal}">打开原生 SVG</a> · <a href="{png}">打开 PNG</a></p><img src="{normal}" data-normal="{normal}" data-debug="{debug}" alt="{html.escape(item["title"])}">{details}</section>'))
    doc='''<!doctype html><html lang="zh-CN"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><title>扫描链与 ATPG 插图精确几何检查</title>
<style>body{margin:0;background:#edf2f6;color:#172d46;font-family:"Noto Sans CJK SC","Microsoft YaHei",sans-serif;font-size:17px;line-height:1.8}main{max-width:1240px;margin:auto;padding:24px}header,section{padding:26px;background:white;border:1px solid #d6e0e7;border-radius:10px;margin:22px 0}h1{font-size:32px}h2{font-size:25px}img{display:block;width:100%;height:auto}a{color:#1967a4}.toolbar{position:sticky;top:0;padding:15px 24px;background:#fff;box-shadow:0 2px 12px #172d4620;z-index:2}.scroll{overflow-x:auto}table{border-collapse:collapse;font-size:14px;min-width:650px}td,th{padding:10px;border:1px solid #dbe3ec;text-align:left}summary{cursor:pointer;padding:16px;background:#f3f7fb}code{overflow-wrap:anywhere}button{font-size:17px;padding:8px 16px;background:#1967a4;color:#fff;border:0;border-radius:6px;cursor:pointer}nav{display:flex;gap:15px;flex-wrap:wrap}@media(max-width:600px){main{padding:10px}header,section{padding:14px}h1{font-size:26px}h2{font-size:22px}}</style></head><body>
<div class="toolbar"><button id="toggle" type="button" aria-pressed="false">显示连接点与文字避让区域</button></div><main><header><h1>扫描链与 ATPG 插图精确几何检查</h1>
<p><a href="阅读入口.html">返回文档阅读入口</a> · <a href="checks/precise_geometry_validation.json">机器可读检查结果</a></p>
<p>''' + f'{report["figures"]} 张图、{report["text_objects"]} 个文字对象、{report["connectors"]} 条连接（其中 {report["arrowheads"]} 条带箭头）。当前检查问题数：{report["issue_count"]}。' + '''</p>
<p>橙色实框是浏览器实际测量的文字矩形；橙色虚框是向外扩展 10 像素的文字避让区域；青色圆圈是连线起止位置。检查图与正文插图分开保存，不会把辅助框带入正文。</p>
<p>几何检查包括端点、进入方向、文字和边框、箭头尖端、路径穿过模块，以及没有明确连接点的交叉。当前字体环境为 Noto Sans CJK SC。换用其他字体或修改文字以后，应重新检查；没有附带字体文件。</p><nav>'''+''.join(f'<a href="#figure-{n}">图 {n:02d}</a>' for n,_ in sorted(figs))+'''</nav></header>'''+''.join(t for _,t in sorted(figs))+'''
</main><script>let debug=false;document.getElementById('toggle').addEventListener('click',()=>{debug=!debug;document.querySelectorAll('img[data-normal]').forEach(i=>i.src=debug?i.dataset.debug:i.dataset.normal);const b=document.getElementById('toggle');b.textContent=debug?'隐藏辅助检查区域':'显示连接点与文字避让区域';b.setAttribute('aria-pressed',String(debug));});</script></body></html>'''
    (ROOT/'精确绘图检查.html').write_text(doc,encoding='utf-8')
    (ROOT/'checks/connector_map.json').write_text(json.dumps(edges,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    lines=['# 精确绘图检查记录','',f'共 {report["figures"]} 张图，{report["text_objects"]} 个文字对象，{report["connectors"]} 条连接（{report["arrowheads"]} 条带箭头）。问题数：{report["issue_count"]}。','',
           '使用 Chromium 的 SVG getBBox 测量当前字体文字，不使用 OCR。文字与连接线、箭头尖端至少保留 10 像素；普通边框与文字至少保留 6 像素，小型数据矩阵的单个数字采用 4 像素检查范围。卡片内部文字通常另设 20 像素内边距。','',
           '节点连接点从矩形位置和边计算，箭头尖端与标记参考坐标重合。所有连接采用水平或垂直线段；分支与合并只允许在明确标记的连接点相交。','',
           '| 文件 | 文字对象 | 连接 | 箭头 | 问题 |','|---|---:|---:|---:|---:|']
    for r in report['results']:lines.append(f'| `{r["file"]}` | {r["text_objects"]} | {r["connectors"]} | {r["arrowheads"]} | {len(r["issues"])} |')
    lines+=['','布局规则只验证几何，不能代替扫描电路、算法覆盖或物理实现验证。修改字体或图形后应重新检查。']
    (ROOT/'checks/精确绘图检查记录.md').write_text('\n'.join(lines)+'\n',encoding='utf-8')
    print('Built offline inspection page and separate geometry overlays.')
if __name__=='__main__':main()
