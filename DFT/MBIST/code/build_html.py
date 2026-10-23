#!/usr/bin/env python3
"""Build an offline HTML with embedded diagrams and SVG-rendered math.
Rebuild dependencies: markdown-it-py, node, mathjax-full. No fonts are packaged.
"""
from __future__ import annotations
import base64
import html
import json
import re
import subprocess
import tempfile
from pathlib import Path
from markdown_it import MarkdownIt

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'06_存储器分组与功耗分析.md'
OUTPUT=ROOT/'06_存储器分组与功耗分析_离线阅读.html'

STYLE=r'''
:root {--ink:#213649;--muted:#607286;--blue:#245c91;--teal:#168679;--line:#dce4eb;--pale:#f4f7fa;}
* {box-sizing:border-box} html{scroll-behavior:smooth;scroll-padding-top:25px}
body{margin:0;color:var(--ink);background:#f5f7fa;font:17px/1.85 -apple-system,BlinkMacSystemFont,"Noto Sans CJK SC","Microsoft YaHei",sans-serif}
nav{position:fixed;left:0;top:0;width:280px;height:100vh;overflow:auto;background:#edf2f6;padding:26px 23px 40px;border-right:1px solid var(--line)}
nav .brand{color:var(--blue);font-size:15px;font-weight:750;letter-spacing:.06em;margin-bottom:14px}
nav a{display:block;font-size:13px;line-height:1.55;color:#4b6276;text-decoration:none;margin:8px 0;padding:3px 5px;border-radius:4px}
nav a:hover{color:var(--teal);background:white} nav a.level2{font-weight:750;font-size:14px;margin-top:16px} nav a.level3{padding-left:15px}
main{margin:30px 30px 50px 310px;max-width:1110px;background:white;padding:48px 58px 70px;border:1px solid var(--line);border-radius:13px}
.hero-label{font-size:14px;letter-spacing:.08em;color:var(--teal);font-weight:750}
h1{font-size:34px;line-height:1.45;color:#153b59;margin:10px 0 24px;letter-spacing:-.025em}
h2{font-size:27px;line-height:1.5;color:#1b4d74;border-top:2px solid #dce7ee;padding-top:27px;margin:56px 0 22px}
h3{font-size:23px;line-height:1.5;color:#1f6170;margin:36px 0 15px}
h4{font-size:19px;line-height:1.6;color:#314d63;margin:25px 0 12px}
p{margin:13px 0} a{color:#1f6d9d;text-underline-offset:3px;overflow-wrap:anywhere} strong{font-weight:700;color:#173e58}
blockquote{margin:24px 0;padding:13px 21px;background:#edf6f5;border-left:4px solid var(--teal);font-size:16px}
blockquote p{margin:6px 0}.table-wrap{overflow:auto;margin:22px 0;border:1px solid var(--line);border-radius:8px}
table{width:100%;border-collapse:collapse;margin:0;font-size:15px;line-height:1.75} th{background:#eaf1f6;color:#234964;font-weight:700}
th,td{padding:11px 13px;border-bottom:1px solid #e0e7ed;text-align:left;vertical-align:top} tr:last-child td{border-bottom:0} tr:nth-child(even) td{background:#fafcfd}
code{font: .9em/1.7 "DejaVu Sans Mono",Consolas,monospace;background:#eff3f6;border-radius:4px;padding:2px 5px}
pre{padding:19px 22px;overflow:auto;border-radius:9px;background:#f0f4f7;border:1px solid #dbe3ea;font-size:14px;line-height:1.75;margin:20px 0}
pre code{background:none;padding:0;line-height:inherit} figure{margin:28px 0 32px}figure img{display:block;width:100%;height:auto;border:1px solid #dfe7ed;border-radius:8px;background:white}
figcaption{font-size:14px;color:var(--muted);text-align:center;line-height:1.55;margin-top:10px}
.math-display{overflow-x:auto;margin:20px 0;padding:12px 5px;max-width:100%;text-align:center}
.math-inline{display:inline;white-space:nowrap}mjx-container{max-width:100%}mjx-container svg{overflow:visible;max-width:none}
.fn-ref{font-size:.72em;line-height:0;margin:0 2px} .fn-entry{font-size:14px;line-height:1.8;border-top:1px solid #e0e7ed;padding:10px 0;margin:0}
.series-link{color:#7a8b99;font-size:.92em}.series-note{font-size:13px;color:#7a8b99;margin-bottom:25px}hr{border:0;border-top:1px solid var(--line);margin:27px 0}
ul,ol{padding-left:24px}li{margin:5px 0}.footer{margin-top:45px;padding-top:20px;border-top:1px solid var(--line);color:var(--muted);font-size:13px}
@media(max-width:1100px){nav{display:none}main{margin:15px auto;max-width:980px;padding:30px}}
@media(max-width:650px){body{font-size:16px}main{margin:0;border:0;border-radius:0;padding:24px 17px}h1{font-size:27px}h2{font-size:24px}h3{font-size:21px}th,td{padding:8px;font-size:13px}pre{font-size:12px;padding:14px}}
@media print{nav{display:none}body{background:white;font-size:11pt}main{margin:0;padding:0;max-width:none;border:0}h2,h3,h4{break-after:avoid}figure,pre{break-inside:avoid}.table-wrap{overflow:visible}a{color:inherit;text-decoration:none}}
'''

def main():
    s=SOURCE.read_text(encoding='utf-8')
    s=re.sub(r'^---\n.*?\n---\n','',s,flags=re.S)
    definitions={}
    def def_fn(m):
        definitions[m.group(1)]=m.group(2);return ''
    s=re.sub(r'^\[\^([^\]]+)\]:\s*(.*)$',def_fn,s,flags=re.M)
    order=[]
    def reference(m):
        key=m.group(1)
        if key not in definitions:raise ValueError('Undefined footnote '+key)
        if key not in order:order.append(key)
        n=order.index(key)+1
        return f'<sup class="fn-ref"><a href="#fn-{key}">[{n}]</a></sup>'
    s=re.sub(r'\[\^([^\]]+)\]',reference,s)
    s+='\n\n'+ '\n\n'.join(f'<div class="fn-entry" id="fn-{key}">\n\n[{i+1}] '+definitions[key]+'\n\n</div>' for i,key in enumerate(order))
    # Protect code so shell variables and code fragments never become math.
    codes={}
    def code_save(m):
        key=f'CODEBLOCKTOKEN{len(codes):04d}END';codes[key]=m.group(0);return '\n'+key+'\n'
    s=re.sub(r'^```[^\n]*\n.*?^```\s*$',code_save,s,flags=re.M|re.S)
    inline_codes={}
    def inline_code_save(m):
        key=f'CODEINLINETOKEN{len(inline_codes):04d}END'
        inline_codes[key]=m.group(0)
        return key
    s=re.sub(r'(`+)([^\n]*?)\1',inline_code_save,s)
    math_items=[]
    def store(tex,display):
        ident=f'MATHTOKEN{len(math_items):04d}END';math_items.append({'id':ident,'tex':tex.strip(),'display':display});return ident
    s=re.sub(r'\$\$(.*?)\$\$',lambda m:'\n\n'+store(m.group(1),True)+'\n\n',s,flags=re.S)
    s=re.sub(r'(?<!\\)\$([^\n$]+?)(?<!\\)\$',lambda m:store(m.group(1),False),s)
    for key,val in codes.items():s=s.replace(key,val)
    for key,val in inline_codes.items():s=s.replace(key,val)
    def slug(text):
        return re.sub(r'[^\w\u4e00-\u9fff-]+','-',text.strip(),flags=re.U).strip('-')
    s=re.sub(r'\[\[#([^|\]]+)\|([^\]]+)\]\]',lambda m:f'[{m.group(2)}](#{slug(m.group(1))})',s)
    md=MarkdownIt('commonmark',{'html':True}).enable('table').enable('strikethrough')
    tokens=md.parse(s)
    nav=[];seen={}
    for i,tok in enumerate(tokens):
        if tok.type=='heading_open':
            text=tokens[i+1].content;anchor=slug(text);num=seen.get(anchor,0);seen[anchor]=num+1
            if num:anchor+=f'-{num}'
            tok.attrSet('id',anchor)
            if tok.tag in ('h2','h3'):
                nav.append(f'<a class="level{tok.tag[-1]}" href="#{anchor}">{html.escape(text)}</a>')
    body=md.renderer.render(tokens,md.options,{})
    with tempfile.TemporaryDirectory() as td:
        inp=Path(td)/'input.json';out=Path(td)/'output.json';inp.write_text(json.dumps(math_items,ensure_ascii=False))
        subprocess.run(['node',str(ROOT/'code/render_math.cjs'),str(inp),str(out)],check=True)
        rendered={x['id']:x['svg'] for x in json.loads(out.read_text())}
    errors=[]
    for item in math_items:
        svg=rendered[item['id']]
        if 'data-mml-node="merror"' in svg:errors.append(item)
        if item['display']:
            body=body.replace('<p>'+item['id']+'</p>','<div class="math-display">'+svg+'</div>')
            body=body.replace(item['id'],'<div class="math-display">'+svg+'</div>')
        else:body=body.replace(item['id'],'<span class="math-inline">'+svg+'</span>')
    if errors:raise RuntimeError('TeX render errors: '+json.dumps(errors,ensure_ascii=False))
    def image(m):
        src,alt=m.group(1),m.group(2);path=ROOT/src
        if not path.is_file():raise FileNotFoundError(path)
        encoded=base64.b64encode(path.read_bytes()).decode()
        return f'<figure><img alt="{alt}" src="data:image/svg+xml;base64,{encoded}"><figcaption>{alt}</figcaption></figure>'
    body=re.sub(r'<p><img src="([^"]+)" alt="([^"]*)"\s*/?></p>',image,body)
    body=re.sub(r'(<table>.*?</table>)',r'<div class="table-wrap">\1</div>',body,flags=re.S)
    def mdlink(m):
        target,label=m.group(1),m.group(2)
        if not (ROOT/target).is_file():return f'<span class="series-link" title="原MBIST系列的其他章节，本独立包未包含">{label}</span>'
        return m.group(0)
    body=re.sub(r'<a href="([^"#]+\.md)">([^<]+)</a>',mdlink,body)
    page='<!doctype html><html lang="zh-CN"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>06 存储器分组与功耗分析 · 算法详解</title><style>'+STYLE+'</style></head><body>'
    page+='<nav aria-label="文章目录"><div class="brand">MBIST / CHAPTER 06</div>'+''.join(nav)+'</nav>'
    page+='<main><div class="hero-label">算法原理 · 几何与功率约束 · 可复现用例</div>'+body
    page+='<div class="footer">离线阅读版：全部26幅图和公式已内嵌，不依赖网络加载。原系列其他章节的导航仅保留文字说明。</div></main></body></html>'
    OUTPUT.write_text(page,encoding='utf-8')
    report={'display_equations':sum(x['display'] for x in math_items),'inline_equations':sum(not x['display'] for x in math_items),'tex_errors':len(errors),'embedded_figures':body.count('data:image/svg+xml;base64,'),'footnotes':len(order),'html_bytes':len(page.encode())}
    (ROOT/'results/rendering.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(report,ensure_ascii=False,indent=2))

if __name__=='__main__':main()
