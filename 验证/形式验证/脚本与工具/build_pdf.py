#!/usr/bin/env python3
"""Build the list-and-code edition as Markdown, offline HTML, and PDF.

Requirements: Python 3.10+, Pandoc, XeLaTeX, Noto CJK fonts. The HTML embeds
all images and CSS; it needs neither an Internet connection nor example files.
"""
from __future__ import annotations
import argparse
import base64
from pathlib import Path
import re
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
CHAPTERS = '''00_阅读指南.md
形式验证.md
VC_Formal_平台与环境.md
验证工程与结果判读.md
SVA语法合集.md
FPV.md
AEP.md
FXP.md
CC.md
FCA.md
SEQ.md
FRV.md
FTA.md
FuSa.md
FSV.md
DPV.md
FLP_LPC.md
调试与证明性能.md
覆盖与验证验收.md
术语表与资料索引.md
VC_Formal_Quick_Reference_Guide_中文整理版.md'''.splitlines()
HEADER = '''---
title: "VC Formal 中文形式验证手册"
subtitle: "分点说明与代码块版 · 原理、SVA、工具命令与完整案例"
author: "独立中文技术教程（非官方译本）"
date: "工具文档基线 X-2025.06-SP1 · 手册修订 1.2 · 2026-10-17"
lang: zh-CN
---

'''
READ_FORMAT = 'markdown+tex_math_dollars+tex_math_single_backslash-pipe_tables-simple_tables-multiline_tables-grid_tables'

def combined_text() -> str:
    sections = []
    for index, chapter in enumerate(CHAPTERS, 1):
        path = ROOT/chapter
        if not path.is_file():
            raise FileNotFoundError(path)
        sections.append(f'<a id="chapter-{index:02d}"></a>\n\n'+path.read_text(encoding='utf-8'))
    text = HEADER + '\n\n'.join(sections)
    for index, chapter in enumerate(CHAPTERS, 1):
        # Chapter links become internal links; image/source links are unchanged.
        text = text.replace(']('+chapter+')', f'](#chapter-{index:02d})')
    return text

def html_build(text: str, out: Path) -> None:
    result = subprocess.run([
        'pandoc','--from',READ_FORMAT,'--to','html5','--standalone',
        '--toc','--toc-depth=2','--mathml',
        '--lua-filter',str(ROOT/'脚本与工具/doc_links.lua'),
        '--metadata','pagetitle=VC Formal 中文形式验证手册｜分点说明与代码块版',
    ], input=text, text=True, capture_output=True, check=True, cwd=ROOT).stdout
    css = (ROOT/'脚本与工具/handbook.css').read_text(encoding='utf-8')
    result = result.replace('</head>', '<style>\n'+css+'\n</style>\n</head>')
    def embed(match: re.Match[str]) -> str:
        path = (ROOT/match[1]).resolve()
        if not path.is_relative_to(ROOT) or not path.is_file():
            raise FileNotFoundError(path)
        mime = {'svg':'image/svg+xml','png':'image/png','jpg':'image/jpeg'}[path.suffix[1:]]
        value = base64.b64encode(path.read_bytes()).decode('ascii')
        return 'src="data:'+mime+';base64,'+value+'"'
    result = re.sub(r'src="(插图/[^\"]+)"', embed, result)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(result, encoding='utf-8')

def pdf_build(text: str, out: Path) -> None:
    with tempfile.TemporaryDirectory(prefix='vcf_inline_book_') as directory:
        tmp = Path(directory)
        pdfsource = text
        cover = None
        for index, image in enumerate(sorted((ROOT/'插图').glob('*.png')), 1):
            figure = tmp/f'figure_{index:02d}.png'
            shutil.copy2(image, figure)
            pdfsource = pdfsource.replace(f'(插图/{image.stem}.svg)', f'({figure}){{ width=88% }}')
            if image.stem == '03_应用布局':
                cover = figure
        if cover is None:
            raise RuntimeError('Missing cover image')
        source = tmp/'book.md'
        source.write_text(pdfsource, encoding='utf-8')
        preamble = tmp/'preamble.tex'
        preamble.write_text((ROOT/'脚本与工具/latex_preamble.tex').read_text(encoding='utf-8').replace('{{COVER_IMAGE}}',str(cover)), encoding='utf-8')
        out.parent.mkdir(parents=True, exist_ok=True)
        args = [
            'pandoc', str(source), '--from', READ_FORMAT,
            '--standalone','--toc','--toc-depth=2','--top-level-division=chapter',
            '--lua-filter',str(ROOT/'脚本与工具/doc_links.lua'),
            '--pdf-engine=xelatex', '-V','documentclass=ctexbook', '-V','classoption=openany',
            '-V','papersize=a4','-V','geometry:margin=22mm','-V','fontsize=11pt',
            '-V','linestretch=1.20','-V','mainfont=Noto Serif CJK SC',
            '-V','sansfont=Noto Sans CJK SC','-V','monofont=DejaVu Sans Mono',
            '-V','colorlinks=true','-V','linkcolor=blue','-H',str(preamble),'-o',str(out),
        ]
        subprocess.run(args, check=True, cwd=tmp)

def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--pdf',type=Path,default=ROOT/'VC_Formal_中文手册_合订本.pdf')
    parser.add_argument('--md',type=Path,default=ROOT/'合订本.md')
    parser.add_argument('--html',type=Path,default=ROOT/'VC_Formal_中文手册_离线阅读版.html')
    parser.add_argument('--no-pdf',action='store_true')
    args = parser.parse_args()
    for exe in ['pandoc'] + ([] if args.no_pdf else ['xelatex']):
        if not shutil.which(exe):
            raise SystemExit(f'Missing executable: {exe}')
    subprocess.run(['python3', str(ROOT/'脚本与工具/sync_inline_sources.py')],check=True)
    subprocess.run(['python3', str(ROOT/'脚本与工具/validate_no_tables.py'), '--source-only'], check=True)
    text = combined_text()
    args.md.parent.mkdir(parents=True, exist_ok=True)
    args.md.write_text(text, encoding='utf-8')
    html_build(text,args.html)
    if not args.no_pdf:
        pdf_build(text,args.pdf)
    print('Markdown:',args.md)
    print('Offline HTML:',args.html)
    if not args.no_pdf:
        print('PDF:',args.pdf)

if __name__ == '__main__':
    main()
