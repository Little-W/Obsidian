#!/usr/bin/env python3
"""Offline static verification for the supplied teaching handbook.

This is not a VC Formal, SystemVerilog compiler, or proof execution.
"""
from __future__ import annotations
import re
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
errors: list[str] = []
warnings: list[str] = []
mds = [x for x in ROOT.glob('*.md') if x.name != '合订本.md'] + list((ROOT/'案例工程').rglob('*.md'))
link_pat = re.compile(r'!?\[[^\]]*\]\(([^)]+)\)')
num_links=0
for md in mds:
    src=md.read_text(encoding='utf-8')
    in_fence=False
    for line_num, line in enumerate(src.splitlines(), 1):
        if line.lstrip().startswith('```') or line.lstrip().startswith('~~~'):
            in_fence=not in_fence
            continue
        if in_fence: continue
        for match in link_pat.finditer(line):
            dest=match.group(1).split(' ',1)[0].strip('<>')
            if dest.startswith(('https://','http://','mailto:','#','data:')): continue
            path=dest.split('#',1)[0]
            if not path: continue
            num_links +=1
            if not (md.parent/path).exists():
                errors.append(f'{md.relative_to(ROOT)}:{line_num}: missing link {dest}')

files=list((ROOT/'案例工程').glob('*.f'))
file_refs=0
for f in files:
    for line_num, line in enumerate(f.read_text().splitlines(),1):
        line=line.strip()
        if not line or line.startswith(('#','//','+')): continue
        if not (f.parent/line).exists():
            errors.append(f'{f.relative_to(ROOT)}:{line_num}: missing source {line}')
        file_refs+=1

tcl=list((ROOT/'案例工程').rglob('*.tcl'))
for f in tcl:
    cmd=subprocess.run(['tclsh','-'],input=(
        'set f {'+str(f)+'}\nset h [open $f r]\nset s [read $h]\nclose $h\nputs [info complete $s]\n'
        ).encode(), stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=3)
    if cmd.returncode!=0 or cmd.stdout.strip()!=b'1':
        errors.append(f'{f.relative_to(ROOT)}: Tcl incomplete: {cmd.stdout!r} {cmd.stderr!r}')

sv=list((ROOT/'案例工程/rtl').glob('*.sv'))+list((ROOT/'案例工程/formal').glob('*.sv'))
for f in sv:
    s=f.read_text()
    for left,right in [('module','endmodule'),('interface','endinterface')]:
        l=len(re.findall(r'^\s*'+left+r'\b',s,flags=re.M))
        r=len(re.findall(r'^\s*'+right+r'\b',s,flags=re.M))
        if l!=r:
            errors.append(f'{f.relative_to(ROOT)}: {left} count {l} != {right} count {r}')

svgs=list((ROOT/'插图').glob('*.svg'))
for f in svgs:
    import xml.etree.ElementTree as ET
    try: ET.parse(f)
    except ET.ParseError as e: errors.append(f'{f.name}: Invalid SVG {e}')
    if not f.with_suffix('.png').exists(): errors.append(f'{f.name}: PNG version missing')

print('离线检查结果（不等同 VC Formal 编译/证明）')
print(f'章节 Markdown: {len(mds)}；本地图片/文件链接: {num_links}；文件列表: {len(files)} / {file_refs} 个输入；Tcl: {len(tcl)}；SV: {len(sv)}；SVG: {len(svgs)}')
for x in warnings: print('WARNING',x)
for x in errors: print('ERROR',x)
print('静态检查：' + ('通过' if not errors else f'有 {len(errors)} 项错误'))
sys.exit(bool(errors))
