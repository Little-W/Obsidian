#!/usr/bin/env python3
"""Create a portable combined Markdown edition and A4 PDF using Pandoc/XeLaTeX.

Requirements: pandoc, xelatex, fonts Noto Serif CJK SC / Noto Sans CJK SC /
Noto Sans Mono CJK SC. Original third-party reference PDFs are not needed.
"""
from __future__ import annotations
import argparse
from pathlib import Path
import re
import shutil
import subprocess
import tempfile

ROOT=Path(__file__).resolve().parents[1]
CHAPTERS='''00_阅读指南.md
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
HEADER='''---
title: "VC Formal 中文形式验证手册"
subtitle: "原理、SVA、工具命令与芯片工程案例"
author: "独立中文技术教程（非官方译本）"
date: "文档基线 X-2025.06-SP1 · 2026 年 10 月"
lang: zh-CN
---

'''

def build(pdf:Path, md:Path)->None:
    for c in CHAPTERS:
        if not (ROOT/c).exists(): raise FileNotFoundError(ROOT/c)
    text=HEADER + '\n\n'.join((ROOT/c).read_text(encoding='utf-8') for c in CHAPTERS)
    md.parent.mkdir(parents=True, exist_ok=True)
    md.write_text(text,encoding='utf-8')
    with tempfile.TemporaryDirectory(prefix='vcf_book_') as directory:
        tmp=Path(directory)
        pdfsource=text
        cover=None
        for idx,image in enumerate(sorted((ROOT/'插图').glob('*.png')),1):
            fig=tmp/f'figure_{idx:02d}.png'
            shutil.copy2(image,fig)
            pdfsource=pdfsource.replace(f'(插图/{image.stem}.svg)', f'({fig}){{ width=88% }}')
            if image.stem=='03_应用布局': cover=fig
        if cover is None: raise RuntimeError('Cover image missing')
        source=tmp/'book.md'; source.write_text(pdfsource,encoding='utf-8')
        preamble_text=(ROOT/'脚本与工具/latex_preamble.tex').read_text(encoding='utf-8')
        preamble_text=preamble_text.replace('{{COVER_IMAGE}}',str(cover))
        preamble=tmp/'preamble.tex'; preamble.write_text(preamble_text,encoding='utf-8')
        pdf.parent.mkdir(parents=True,exist_ok=True)
        args=['pandoc',str(source),'--from','markdown+tex_math_dollars+tex_math_single_backslash',
            '--standalone','--toc','--toc-depth=2','--top-level-division=chapter',
            '--pdf-engine=xelatex','-V','documentclass=ctexbook','-V','classoption=openany',
            '-V','papersize=a4','-V','geometry:margin=22mm','-V','fontsize=11pt',
            '-V','linestretch=1.24','-V','mainfont=Noto Serif CJK SC',
            '-V','sansfont=Noto Sans CJK SC','-V','monofont=Noto Sans Mono CJK SC',
            '-V','colorlinks=true','-V','linkcolor=blue','-H',str(preamble),'-o',str(pdf)]
        subprocess.run(args,check=True,cwd=tmp)

if __name__=='__main__':
    ap=argparse.ArgumentParser()
    ap.add_argument('--pdf',type=Path,default=ROOT/'VC_Formal_中文手册_合订本.pdf')
    ap.add_argument('--md',type=Path,default=ROOT/'合订本.md')
    args=ap.parse_args()
    build(args.pdf,args.md)
    print('合订本 Markdown:', args.md)
    print('A4 PDF:', args.pdf)
