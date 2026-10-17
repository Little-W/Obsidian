#!/usr/bin/env python3
"""Validate table column counts, GFM rendering and Pandoc table code escaping.

Requires markdown-it-py and pandoc. This checks document rendering, not SVA
language correctness or VC Formal command availability.
"""
from __future__ import annotations
import json
from pathlib import Path
import re
import subprocess
import sys
from markdown_it import MarkdownIt

ROOT = Path(__file__).resolve().parents[1]
md_parser = MarkdownIt('commonmark').enable('table')
errors: list[str] = []
table_count = 0
row_count = 0
inline_pipe_count = 0

def cells(line: str) -> list[str]:
    # GFM splits unescaped vertical bars, including bars in inline code.
    return re.split(r'(?<!\\)\|', line.strip())[1:-1]

def all_nodes(obj):
    if isinstance(obj, dict):
        yield obj
        for value in obj.values():
            yield from all_nodes(value)
    elif isinstance(obj, list):
        for value in obj:
            yield from all_nodes(value)

paths = sorted(p for p in ROOT.glob('*.md') if p.name not in {'合订本.md','_pdf_source.md'})
paths += sorted((ROOT/'案例工程').rglob('*.md'))
for path in paths:
    text = path.read_text(encoding='utf-8')
    lines = text.splitlines()
    fence = False
    width = None
    for number, line in enumerate(lines, 1):
        if re.match(r'^\s*(```|~~~)', line):
            fence = not fence
            width = None
            continue
        if fence:
            continue
        if line.startswith('|') and line.rstrip().endswith('|'):
            actual = len(cells(line))
            if width is None:
                width = actual
                table_count += 1
            elif actual != width:
                errors.append(f'{path.name}:{number}: columns {actual}, expected {width}')
            row_count += 1
            for match in re.finditer(r'(`+)(.+?)\1', line):
                code = match[2]
                if re.search(r'(?<!\\)\|', code):
                    errors.append(f'{path.name}:{number}: unescaped pipe in table code')
                inline_pipe_count += code.count(r'\|')
        else:
            width = None
    if fence:
        errors.append(f'{path.name}: unclosed code fence')

    # GFM-compatible parser must consume the escape, not show it as code text.
    stack = 0
    for token in md_parser.parse(text):
        if token.type == 'table_open':
            stack += 1
        elif token.type == 'table_close':
            stack -= 1
        elif stack and token.children:
            for child in token.children:
                if child.type == 'code_inline' and r'\|' in child.content:
                    errors.append(f'{path.name}: GFM displays an unwanted slash: {child.content}')

    if '|' not in text:
        continue
    process = subprocess.run([
        'pandoc','-f','markdown+tex_math_dollars+tex_math_single_backslash',
        '-t','json','--lua-filter',str(ROOT/'脚本与工具/table_render.lua')
    ], input=text,text=True,capture_output=True,check=True)
    document = json.loads(process.stdout)
    for table in (n for n in all_nodes(document) if n.get('t') == 'Table'):
        for node in all_nodes(table):
            if node.get('t') == 'Code' and r'\|' in node['c'][1]:
                errors.append(f'{path.name}: Pandoc leaves an unwanted escape in table code')

print(f'Active Markdown files: {len(paths)}; tables: {table_count}; rows: {row_count}; escaped table operator bars: {inline_pipe_count}')
for error in errors:
    print('ERROR:',error)
print('Table rendering checks: '+('PASS' if not errors else 'FAIL'))
sys.exit(bool(errors))
