#!/usr/bin/env python3
"""Build a fully offline HTML reading edition. Fonts are not bundled.
Dependencies: markdown-it-py, Pygments, beautifulsoup4, matplotlib.
"""
from __future__ import annotations
import base64
import hashlib
import html
import io
import re
from pathlib import Path
from bs4 import BeautifulSoup
from markdown_it import MarkdownIt
from pygments import highlight
from pygments.formatters import HtmlFormatter
from pygments.lexers import get_lexer_by_name, TextLexer
import matplotlib
matplotlib.use('Agg')
from matplotlib.mathtext import math_to_image
from matplotlib.font_manager import FontProperties

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'Tessent_MemoryBIST_插入教材.md'
TARGET = ROOT / 'Tessent_MemoryBIST_插入教材_离线阅读.html'

def anchor(s: str) -> str:
    return 'sec-' + hashlib.sha1(s.strip().encode()).hexdigest()[:12]

def code_highlight(code: str, lang: str, attrs: str = '') -> str:
    try:
        lexer = get_lexer_by_name(lang or 'text')
    except Exception:
        lexer = TextLexer()
    inner = highlight(code, lexer, HtmlFormatter(nowrap=True))
    return ('<pre class="code-block" data-language="'+html.escape(lang or 'text')+'">'
            '<code>'+inner+'</code></pre>')

def formula(latex: str, index: int) -> str:
    buf = io.BytesIO()
    math_to_image('$'+latex.strip()+'$', buf, format='svg',
                  prop=FontProperties(size=17), dpi=150)
    svg = buf.getvalue()
    encoded = base64.b64encode(svg).decode()
    return ('<div class="math-display" role="math" aria-label="'+html.escape(latex,quote=True)+'">'
            '<img alt="'+html.escape(latex,quote=True)+'" src="data:image/svg+xml;base64,'+encoded+'"></div>')

text = SOURCE.read_text(encoding='utf-8')
text = re.sub(r'\A---\n.*?\n---\n', '', text, count=1, flags=re.S)
text = re.sub(r'\n## 目录\n.*?\n---\n', '\n---\n', text, count=1, flags=re.S)
text = re.sub(r'\[\[#([^]|]+)\|([^]]+)\]\]', lambda m: '['+m[2]+'](#'+anchor(m[1])+')', text)
# Only display blocks outside fenced code are treated as mathematical content.
parts = re.split(r'(```.*?```)', text, flags=re.S)
count = [0]
def math_replace(m: re.Match) -> str:
    count[0] += 1
    return '\n'+formula(m[1], count[0])+'\n'
for i in range(0, len(parts), 2):
    parts[i] = re.sub(r'^\$\$\s*\n(.*?)\n\$\$\s*$', math_replace, parts[i], flags=re.S|re.M)
text = ''.join(parts)
md = MarkdownIt('commonmark', {'html': True, 'highlight': code_highlight, 'typographer': False})
md.enable('table')
body = BeautifulSoup(md.render(text), 'html.parser')
# Inline original SVG figures as data URLs: no folder dependency in the reading edition.
figure_count = 0
for img in body.find_all('img'):
    src = img.get('src','')
    if src.startswith('assets/'):
        path = ROOT / src
        if not path.is_file():
            raise FileNotFoundError(path)
        img['src'] = 'data:image/svg+xml;base64,'+base64.b64encode(path.read_bytes()).decode()
        img['loading'] = 'eager'
        wrap = body.new_tag('figure', attrs={'class':'illustration'})
        img.wrap(wrap)
        cap = body.new_tag('figcaption'); cap.string = img.get('alt',''); wrap.append(cap)
        figure_count += 1
for table in body.find_all('table'):
    wrap = body.new_tag('div', attrs={'class':'table-wrap'}); table.wrap(wrap)
nav=[]
for h in body.find_all(['h1','h2','h3']):
    label=h.get_text(' ',strip=True); h['id']=anchor(label)
    if h.name=='h2' and (re.match(r'^\d+\.',label) or label.startswith('附录') or label.startswith('参考资料')):
        nav.append('<a href="#'+h['id']+'">'+html.escape(label)+'</a>')
# Bare reference URLs become optional clickable sources; all book content remains offline.
for node in list(body.find_all(string=True)):
    if node.parent.name in {'a','code','pre','script','style'} or node.find_parent(['pre','code']):
        continue
    s=str(node)
    if 'https://' not in s: continue
    chunks=re.split(r'(https://[^\s<>]+)',s)
    if len(chunks)==1: continue
    for k,chunk in enumerate(chunks):
        if k%2:
            a=body.new_tag('a',href=chunk);a.string=chunk;a['rel']='noopener';a['target']='_blank';node.insert_before(a)
        else: node.insert_before(chunk)
    node.extract()
css = r'''
:root{--ink:#18334b;--body:#243849;--muted:#647889;--line:#dce5ea;--teal:#147f81;--paper:#fff;--side:#f0f5f7}
*{box-sizing:border-box}html{scroll-behavior:smooth;scroll-padding-top:30px}body{margin:0;background:#f7f9fb;color:var(--body);font-family:"Noto Sans CJK SC","Source Han Sans SC","Microsoft YaHei",system-ui,sans-serif;font-size:17px;line-height:1.87}
a{color:#0c7482;text-decoration:none}a:hover{text-decoration:underline}button{font:inherit}#sidebar{position:fixed;inset:0 auto 0 0;width:295px;background:var(--side);border-right:1px solid var(--line);padding:30px 20px 24px 25px;overflow:auto;z-index:5}.brand{letter-spacing:2px;font-size:12px;font-weight:700;color:var(--teal)}.nav-title{font-size:23px;font-weight:800;line-height:1.5;color:var(--ink);margin:12px 0}.nav-note{font-size:12px;line-height:1.7;color:var(--muted);margin:0 0 20px}nav a{display:block;color:#405969;padding:6px 7px;font-size:13px;line-height:1.55;border-left:2px solid transparent;margin:2px 0}nav a:hover,nav a.current{background:#e1ecee;color:#096c70;border-left-color:var(--teal);text-decoration:none}#main{margin-left:295px;padding:26px 38px 70px;max-width:1450px}.document{background:var(--paper);border:1px solid #e1e8ed;border-radius:10px;padding:40px 46px;box-shadow:0 8px 30px #17354b08;min-width:0}.edition{font-size:12px;letter-spacing:1.2px;color:var(--teal);font-weight:700;display:flex;justify-content:space-between;border-bottom:1px solid var(--line);padding-bottom:14px;margin-bottom:25px}.edition span:last-child{color:var(--muted);font-weight:400;letter-spacing:0}h1{font-size:35px;line-height:1.45;letter-spacing:-.7px;color:var(--ink);margin:0 0 16px}h2{font-size:27px;color:var(--ink);margin:58px 0 20px;line-height:1.5;padding-top:8px;border-bottom:2px solid #d7e9e9;padding-bottom:12px}h1+h2{font-size:20px;font-weight:500;color:var(--muted);border:0;margin:0 0 30px;padding:0}h3{font-size:21px;line-height:1.65;color:#155164;margin:32px 0 12px}p{margin:13px 0}strong{font-weight:700;color:#183d53}hr{border:0;height:1px;background:#e5ebef;margin:36px 0}ul,ol{padding-left:25px}li{margin:5px 0}blockquote{border-left:4px solid var(--teal);background:#f0f7f7;margin:24px 0;padding:10px 22px;color:#325a69}.table-wrap{overflow-x:auto;margin:23px 0;border:1px solid var(--line);border-radius:7px}table{width:100%;border-collapse:collapse;font-size:14px;line-height:1.8;min-width:540px}th,td{text-align:left;border-bottom:1px solid var(--line);padding:11px 13px;vertical-align:top}th{background:#eaf1f5;color:#1d4c61;font-weight:700}tbody tr:nth-child(even){background:#f8fafb}tbody tr:last-child td{border-bottom:0}code{font-family:"DejaVu Sans Mono","Liberation Mono",monospace;font-size:.84em;background:#eef3f5;padding:2px 5px;border-radius:4px;overflow-wrap:anywhere}pre{position:relative;overflow-x:auto;max-width:100%;font-size:13px;line-height:1.75;background:#f3f6f8;border:1px solid #dce5ec;border-radius:8px;padding:39px 19px 19px;margin:22px 0;tab-size:4}pre::before{content:attr(data-language);position:absolute;left:18px;top:8px;font-family:system-ui;font-size:11px;font-weight:700;letter-spacing:1px;color:#6b8191;text-transform:uppercase}pre code{font-size:inherit;background:transparent;padding:0;border:0;white-space:pre;overflow-wrap:normal}figure.illustration{margin:28px 0;border:1px solid #e2e8ed;border-radius:9px;overflow:hidden;background:#fff}figure img{display:block;width:100%;height:auto}figcaption{font-size:12px;line-height:1.65;color:#5e7586;padding:10px 15px;background:#f5f8fa;border-top:1px solid #e5ebef}.math-display{text-align:center;padding:23px 12px;overflow:auto;background:#fafcfd;border-radius:7px;margin:24px 0}.math-display img{max-width:100%;height:auto;min-width:0}article a{overflow-wrap:anywhere}.footer{font-size:12px;color:#6b8090;text-align:center;margin:26px 0}.mobile-head{display:none}.copy{position:absolute;right:10px;top:5px;font-size:11px;padding:3px 8px;border:1px solid #ccd9e1;border-radius:4px;background:#fff;color:#526c7d;cursor:pointer}.copy:hover{background:#e7f0f3}.badge{padding:4px 8px;border:1px solid #c9e0e0;border-radius:4px;display:inline-block;color:#13787a;font-size:11px;line-height:1.5;margin-top:6px}
@media(min-width:1600px){#main{margin-right:auto;margin-left:calc((100vw - 1480px)/2 + 295px)}#sidebar{padding-left:28px}}
@media(max-width:1100px){#sidebar{width:250px}#main{margin-left:250px;padding:20px}.document{padding:30px 28px}h1{font-size:30px}h2{font-size:24px}}
@media(max-width:850px){#sidebar{display:none}#main{margin:0;padding:12px}.document{padding:25px 20px;border-radius:5px}body{font-size:16px}h1{font-size:27px}h2{font-size:23px;margin-top:40px}.edition{font-size:10px}.edition span:last-child{max-width:45%;text-align:right}.mobile-head{display:block;padding:10px 0;font-size:12px;color:#5a7384}table{font-size:13px}pre{font-size:12px}.math-display{padding:20px 0}}
@media print{#sidebar,.copy,.mobile-head{display:none}#main{margin:0;padding:0;max-width:none}.document{border:0;box-shadow:none;padding:0}body{font-size:10.5pt;background:white;line-height:1.65}h1{font-size:26pt}h2{font-size:18pt;page-break-before:always}h1+h2{page-break-before:auto}h3{font-size:13pt}pre{white-space:pre-wrap;overflow-wrap:anywhere;overflow:visible;font-size:8pt}pre code{white-space:pre-wrap}figure,.math-display{break-inside:avoid}th,td{font-size:9pt;padding:6px}table{min-width:0}thead{display:table-header-group}.table-wrap{overflow:visible}a{color:inherit}}
'''
css += '\n' + HtmlFormatter(style='friendly').get_style_defs('pre') + '\npre .err{border:0;background:transparent}article{overflow-wrap:anywhere}'
js = r'''
(()=>{
for (const pre of document.querySelectorAll('pre.code-block')) {
 const btn=document.createElement('button');btn.className='copy';btn.textContent='复制代码';
 btn.addEventListener('click',async()=>{try{await navigator.clipboard.writeText(pre.querySelector('code').textContent);btn.textContent='已复制';setTimeout(()=>btn.textContent='复制代码',1400)}catch(e){btn.textContent='请选中复制'}});pre.appendChild(btn);
}
const links=[...document.querySelectorAll('nav a')];
const sections=links.map(a=>document.querySelector(a.getAttribute('href'))).filter(Boolean);
const io=new IntersectionObserver(entries=>{for(const e of entries){if(e.isIntersecting){links.forEach(a=>a.classList.toggle('current',a.getAttribute('href')==='#'+e.target.id));}}},{rootMargin:'-5% 0px -76% 0px'});sections.forEach(s=>io.observe(s));
})();
'''
result = '<!doctype html>\n<html lang="zh-CN"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><title>Tessent MemoryBIST 插入教材</title><style>'+css+'</style></head><body>'
result += '<aside id="sidebar"><div class="brand">DFT · MEMORY TEST</div><div class="nav-title">Tessent<br>MemoryBIST 插入教材</div><p class="nav-note">从输入识别到算法定制与分组优化<br>18 章 · 10 幅示意图 · 配套脚本</p><nav>'+''.join(nav)+'</nav><div class="badge">离线阅读版 · 无外部资源依赖</div></aside>'
result += '<main id="main"><div class="mobile-head">TESSENT MEMORYBIST · 中文教材</div><div class="document"><div class="edition"><span>工程流程 / 算法 / 规划 / 验证</span><span>接口依据：2025.1 Revision 36</span></div><article>'+str(body)+'</article></div><div class="footer">配套资料：Markdown、SVG、Tcl、UDA、Python 模型与离线验证记录。商业 EDA 流程未在本资料包中执行。</div></main><script>'+js+'</script></body></html>'
TARGET.write_text(result,encoding='utf-8')
print(f'HTML: {TARGET.name}; figures={figure_count}; formulas={count[0]}; chapters={len(nav)}; bytes={TARGET.stat().st_size}')
