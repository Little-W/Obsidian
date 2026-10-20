#!/usr/bin/env python3
"""Build offline reading pages. Requires Mistune 3.x, Node.js, and mathjax-full 3.x.

The Markdown remains the editable source. Formulas are converted at build time;
no remote fonts, JavaScript libraries, or network requests are needed to read.
"""
from __future__ import annotations
from pathlib import Path
from urllib.parse import quote, urlsplit, unquote
import html
import json
import re
import shutil
import subprocess
import tempfile
try:
    import mistune
except ImportError as exc:
    raise SystemExit('HTML export requires: python -m pip install "mistune>=3,<4"') from exc
from document_support import ROOT, without_frontmatter, math_items

CSS = '''
:root {--ink:#18293c;--muted:#576979;--accent:#116d78;--line:#d8e1e7;--paper:#fff;--pale:#f3f7f9;--nav:#142d41}
*{box-sizing:border-box}html{scroll-behavior:smooth}body{margin:0;color:var(--ink);background:#f4f7fa;font-family:"Noto Sans CJK SC","Microsoft YaHei","PingFang SC",system-ui,sans-serif;font-size:17px;line-height:1.85;overflow-wrap:anywhere}
a{color:var(--accent);text-underline-offset:3px}a:hover{color:#954716}h1,h2,h3,h4{line-height:1.45;scroll-margin-top:24px}h1{font-size:34px;letter-spacing:.015em;margin:.35em 0 1em}h2{font-size:25px;border-top:1px solid var(--line);padding-top:26px;margin-top:42px}h3{font-size:20px;margin-top:30px}h4{font-size:18px}p{margin:16px 0}strong{font-weight:700}ul,ol{padding-left:1.7em}li{margin:6px 0}code{font-family:ui-monospace,"SFMono-Regular",Consolas,"Noto Sans Mono CJK SC",monospace;font-size:.9em;background:#edf2f5;padding:2px 5px;border-radius:4px}pre{padding:20px 24px;background:#172d3e;color:#f2f6fb;overflow-x:auto;border-radius:8px;line-height:1.8}pre code{background:none;padding:0;color:inherit;white-space:pre;font-size:15px}blockquote{margin:22px 0;border-left:4px solid #6eabb2;padding:2px 20px;background:#f1f7f8;color:#354f60}.table-wrap{overflow-x:auto;margin:24px 0;border:1px solid var(--line);border-radius:7px}table{width:100%;border-collapse:collapse;font-size:15px;line-height:1.75}th{background:#eaf1f5;text-align:left;color:#243f54}th,td{padding:12px 14px;border-bottom:1px solid var(--line);vertical-align:top;min-width:100px}tr:last-child td{border-bottom:0}tbody tr:nth-child(even){background:#fafcfd}main img{display:block;max-width:100%;height:auto;margin:26px auto;border:1px solid #e3e9ed;border-radius:10px;background:#fff}main .figure{margin:20px 0}hr{border:0;border-top:1px solid var(--line);margin:28px 0}.sidebar{position:fixed;top:0;bottom:0;left:0;width:284px;overflow-y:auto;background:var(--nav);color:#cbd9e3;padding:30px 20px}.brand{font-size:23px;font-weight:700;color:#fff}.subtitle{font-size:13px;color:#9fb8c9;line-height:1.7;margin:10px 0 20px}.sidebar a{display:block;color:#cfe0eb;text-decoration:none;padding:9px 12px;border-radius:5px;font-size:14px;line-height:1.7;margin:3px 0}.sidebar a:hover,.sidebar a.current{background:#24465c;color:#fff}.sidebar .home{color:#8dd3d7;font-weight:600;margin-bottom:15px}.reading{margin-left:284px;padding:44px 52px 70px}.paper{max-width:1120px;margin:0 auto;padding:44px 56px 64px;background:var(--paper);border:1px solid #e0e7ec;border-radius:12px;box-shadow:0 8px 36px #213d5010}.eyebrow{font-size:13px;letter-spacing:.12em;text-transform:uppercase;color:#467184;margin-bottom:15px}.footer{color:var(--muted);font-size:13px;border-top:1px solid var(--line);margin-top:38px;padding-top:20px}.footnotes{font-size:14px;color:#42576a}.footnote-ref{font-size:.76em}.math-display{overflow-x:auto;text-align:center;padding:10px 0;margin:12px 0}.math-inline{white-space:nowrap}mjx-container{display:inline-block;line-height:0;text-indent:0}mjx-container[display="true"]{display:block;text-align:center;margin:.6em 0}mjx-container svg{max-width:none;overflow:visible;min-width:0}.landing{max-width:1190px;margin:0 auto;padding:50px 32px 70px}.hero{padding:46px 50px;border-radius:14px;color:#edf5fa;background:linear-gradient(130deg,#142d41,#245968)}.hero h1{font-size:40px;margin:.25em 0 .45em}.hero p{max-width:820px;color:#d8e9f1}.hero .eyebrow{color:#a6dce0}.actions{display:flex;gap:14px;flex-wrap:wrap;margin-top:26px}.button{display:inline-block;padding:11px 19px;border-radius:6px;background:#f6fbfc;color:#164451;font-weight:700;text-decoration:none}.button.secondary{background:#ffffff16;color:#eef8fc;border:1px solid #ffffff60}.stats{font-size:15px;letter-spacing:.035em;color:#d1e7ee;margin-top:22px}.cards{display:grid;grid-template-columns:repeat(3,minmax(0,1fr));gap:18px;margin-top:28px}.card{display:block;text-decoration:none;background:white;color:var(--ink);padding:24px;border:1px solid var(--line);border-radius:9px}.card .number{font-size:13px;font-weight:700;color:#588d95;letter-spacing:.12em}.card h3{margin:12px 0;font-size:20px}.card p{font-size:14px;color:var(--muted);margin:0}.card:hover{border-color:#6fa6ad;box-shadow:0 5px 20px #1733440c}.section-label{margin-top:34px;font-size:21px}.gallery-item{padding:24px;margin:24px 0;background:white;border:1px solid var(--line);border-radius:10px}.gallery-item img{width:100%;max-width:1200px;height:auto;display:block;margin:auto}.gallery-item h2{font-size:21px;margin:0 0 20px;padding:0;border:0}.gallery-links{font-size:14px;margin-top:16px}.mobile-index{display:none}
@media(max-width:1100px){.sidebar{width:240px;padding:24px 14px}.reading{margin-left:240px;padding:28px 22px}.paper{padding:30px}.cards{grid-template-columns:repeat(2,minmax(0,1fr))}}
@media(max-width:760px){body{font-size:16px}.sidebar{position:static;width:auto;max-height:none;padding:22px}.sidebar nav{display:none}.sidebar:has(details[open]) nav{display:block}.sidebar .brand{font-size:21px}.subtitle{margin-bottom:4px}.mobile-index{display:block}.reading{margin:0;padding:14px}.paper{padding:24px 20px;border-radius:8px}h1{font-size:27px}h2{font-size:22px}h3{font-size:19px}th,td{padding:10px;min-width:110px}.landing{padding:18px 14px 35px}.hero{padding:28px 24px}.hero h1{font-size:30px}.cards{grid-template-columns:1fr}.math-display{max-width:100%}}
@media print{.sidebar,.mobile-index{display:none}.reading{margin:0;padding:0}.paper{border:0;box-shadow:none;padding:0}h2,h3{break-after:avoid}pre,table,img{break-inside:avoid}body{background:white}}
'''


def url_for(url: str) -> str:
    parsed = urlsplit(url)
    if parsed.scheme or url.startswith('//') or not parsed.path:
        return url
    path = unquote(parsed.path)
    if path.endswith('.md'):
        path = Path(path).with_suffix('.html').name
    elif path.startswith(('assets/', 'src/', 'checks/', 'examples/')):
        path = '../' + path
    elif path in ('阅读入口.html', '插图索引.html', '精确绘图检查.html'):
        path = '../' + path
    return quote(path, safe='/._-') + (('#' + parsed.fragment) if parsed.fragment else '')


class Renderer(mistune.HTMLRenderer):
    def heading(self, text: str, level: int, **attrs) -> str:
        anchor = html.unescape(re.sub('<[^>]*>', '', text))
        return f'<h{level} id="{html.escape(anchor, quote=True)}">{text}</h{level}>\n'

    def link(self, text: str, url: str, title=None) -> str:
        return super().link(text, url_for(url), title)

    def image(self, text: str, url: str, title=None) -> str:
        image = super().image(text, url_for(url), title)
        target = html.escape(url_for(url), quote=True)
        return f'<a href="{target}" target="_blank" rel="noopener" title="打开原生插图">{image}</a>' 

    def table(self, text: str) -> str:
        return '<div class="table-wrap"><table>\n' + text + '</table></div>\n'


def page(title: str, content: str, sidebar: str, stylesheet: str = 'book.css') -> str:
    return f'''<!doctype html>
<html lang="zh-CN"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>{html.escape(title)} · 扫描链与 ATPG 设计</title><link rel="stylesheet" href="{stylesheet}"></head>
<body>{sidebar}<div class="reading"><main class="paper"><div class="eyebrow">SCAN · ATPG · 设计原理</div>{content}<div class="footer">资料检索截止：2026-10-17。此页为 Markdown 的离线阅读副本；编辑后需重新生成。图示、算例模型与论文证据范围分别说明。</div></main></div></body></html>'''


def main() -> None:
    node = shutil.which('node')
    if not node: raise SystemExit('HTML export needs Node.js and mathjax-full 3.x.')
    manifest=json.loads((ROOT/'checks/book_manifest.json').read_text(encoding='utf-8'))
    docs=[(name,(ROOT/name).read_text(encoding='utf-8')) for name in manifest['files'].values()]
    docs.append(('README.md',(ROOT/'README.md').read_text(encoding='utf-8')))
    unique={}
    for name,text in docs:
        for item in math_items(text,name):unique.setdefault((item['tex'],item['display']),len(unique))
    expressions=[{'tex':tex,'display':display} for tex,display in unique]
    with tempfile.TemporaryDirectory(prefix='scan_atpg_html_') as tmp:
        src,dst=Path(tmp)/'input.json',Path(tmp)/'output.json'
        src.write_text(json.dumps(expressions,ensure_ascii=False),encoding='utf-8')
        subprocess.run([node,str(ROOT/'src/render_math.js'),str(src),str(dst)],check=True)
        rendered=json.loads(dst.read_text(encoding='utf-8'))
    html_dir=ROOT/'html';html_dir.mkdir(exist_ok=True)
    (html_dir/'book.css').write_text(CSS,encoding='utf-8')
    md=mistune.create_markdown(renderer=Renderer(escape=False),plugins=['table','footnotes','url'])
    report=[]
    for name,raw in docs:
        text=without_frontmatter(raw);fragments={}
        for item in reversed(list(math_items(text,name))):
            idx=unique[(item['tex'],item['display'])];marker=f'SCANMATHPLACEHOLDER{len(fragments):06d}END'
            fragment=rendered[idx]['html']
            if item['display']:
                fragment='<div class="math-display">'+fragment+'</div>';replacement='\n\n'+marker+'\n\n'
            else:
                fragment='<span class="math-inline">'+fragment+'</span>';replacement=marker
            fragments[marker]=(fragment,item['display']);text=text[:item['start']]+replacement+text[item['end']:]
        content=md(text)
        for marker,(fragment,display) in fragments.items():
            if display:content=content.replace('<p>'+marker+'</p>',fragment)
            content=content.replace(marker,fragment)
        current=name.split('_')[0]
        nav=''.join(f'<a class="{"current" if key==current else ""}" href="{quote(Path(value).with_suffix(".html").name)}">{key} · {html.escape(manifest["titles"][key])}</a>' for key,value in manifest['files'].items())
        sidebar='<aside class="sidebar"><div class="brand">扫描链与 ATPG</div><div class="subtitle">从内部状态访问到制造测试<br>硬件 · 算法 · 质量 · 验证</div><a class="home" href="../阅读入口.html">← 资料库首页</a><details class="mobile-index"><summary>展开文档目录</summary></details><nav>'+nav+'</nav></aside>'
        title=manifest['titles'].get(current,'使用说明');out=html_dir/Path(name).with_suffix('.html').name
        out.write_text(page(title,content,sidebar),encoding='utf-8')
        report.append({'source':name,'html':str(out.relative_to(ROOT)),'math_count':len(fragments)})
    descriptions={
      '00':'测试路径、职责边界与硬件、算法、诊断的阅读组织。',
      '01':'扫描触发器、四位串行移位、加载与捕获，以及严格的位序约定。',
      '02':'全扫描和部分扫描、链平衡、跨时钟连接及物理重排。',
      '03':'片上时钟控制、LOC 与 LOS、复位和高速测试中的保持要求。',
      '04':'JTAG、既有调试模块、测试访问与大容量扫描数据传输。',
      '05':'固定、转换、桥接和单元内部缺陷，覆盖率分母与质量。',
      '06':'激活、传播、输入反推、D 算法、PODEM、FAN 与学习决策。',
      '07':'双电路 SAT 编码、故障模拟、不可测试证明和最小测试集合。',
      '08':'线性解压缩、编码冲突、X 的三种含义和响应压缩混叠。',
      '09':'移位与捕获活动、填充选择、峰值约束和运行期间测试。',
      '10':'控制点和观察点原理，硬件、可编码性与覆盖率的联合代价。',
      '11':'失败记录、扫描结构故障、逻辑候选和诊断信息丢失。',
      '12':'工具输入、规则检查、仿真与制造转换。',
      '13':'按改变的设计层分析 2024—2026 年工作，逐项区分证据范围。',
      '14':'32 故障、SAT 回归、扫描位序、线性压缩与可修改算例程序。',
      '90':'24 项原始来源，列出全文、摘要、议程和厂商资料的用途。'}
    def cards(keys):
        return '<div class="cards">'+''.join(f'<a class="card" href="html/{quote(Path(manifest["files"][k]).with_suffix(".html").name)}"><div class="number">{k} / SCAN &amp; ATPG</div><h3>{html.escape(manifest["titles"][k])}</h3><p>{descriptions[k]}</p></a>' for k in keys)+'</div>'
    overview=quote(Path(manifest['files']['00']).with_suffix('.html').name)
    landing=f'''<!doctype html><html lang="zh-CN"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><title>扫描链与 ATPG 设计 · 阅读入口</title><link rel="stylesheet" href="html/book.css"></head><body><main class="landing"><section class="hero"><div class="eyebrow">Architecture-oriented handbook · Companion to MBIST</div><h1>扫描链与 ATPG 设计</h1><p>从内部状态的装入与读出出发，说明故障激活、逻辑传播、测试压缩和制造执行之间的关系，并以可运行算例核对原理。</p><div class="actions"><a class="button" href="html/{overview}">从总体架构开始</a><a class="button secondary" href="插图索引.html">查看全部插图</a><a class="button secondary" href="精确绘图检查.html">连接点与避让检查</a><a class="button secondary" href="html/README.html">文件与源码说明</a></div><div class="stats">16 份文档 · 19 张可编辑插图 · 24 项参考资料 · 算例源码与执行记录</div></section><h2 class="section-label">总体架构与设计专题</h2>{cards([k for k in manifest['order'] if int(k)<=12])}<h2 class="section-label">研究分析、算例与参考资料</h2>{cards(['13','14','90'])}<div class="footer">检索截止 2026-10-17。此入口、全部专题页、公式和插图均可离线打开。Markdown 是编辑版本，HTML 是阅读副本。算例数值不是商业工具或硅测量结果；论文证据范围见正文。保留完整目录以保持文档链接有效。</div></main></body></html>'''
    (ROOT/'阅读入口.html').write_text(landing,encoding='utf-8')
    figures=json.loads((ROOT/'assets/figures_manifest.json').read_text(encoding='utf-8'))['figures']
    gallery='<h1>19 张可编辑技术插图</h1><p><a href="阅读入口.html">← 返回阅读入口</a> · <a href="精确绘图检查.html">查看连接点与文字避让</a> · 原生文字、方框与连接线，源码位于 src。</p>'
    for item in figures:
        svg='assets/'+item['file'];png='assets/png/'+Path(item['file']).with_suffix('.png').name
        gallery+=f'<section class="gallery-item"><h2>{html.escape(item["title"])}</h2><img src="{quote(svg)}" alt="{html.escape(item["title"])}"><div class="gallery-links"><a href="{quote(svg)}">SVG</a> · <a href="{quote(png)}">PNG</a></div></section>'
    (ROOT/'插图索引.html').write_text('<!doctype html><html lang="zh-CN"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><title>扫描链与 ATPG 插图索引</title><link rel="stylesheet" href="html/book.css"></head><body><main class="landing">'+gallery+'</main></body></html>',encoding='utf-8')
    (ROOT/'checks/html_export.json').write_text(json.dumps({'offline':True,'pages':report,'unique_rendered_math':len(rendered),'total_math':sum(x['math_count'] for x in report)},ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(f'Built {len(report)} document pages, one reading entrance, and {len(figures)}-figure gallery.')

if __name__=='__main__':main()
