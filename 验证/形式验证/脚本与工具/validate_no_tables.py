#!/usr/bin/env python3
"""Reject tables and stray pipe escapes in handbook source and rendered HTML.

Requirements: Python 3.10+, markdown-it-py, Pandoc.
This is a documentation check, not a SystemVerilog or VC Formal validation.
"""
from __future__ import annotations
import argparse
from html.parser import HTMLParser
import json
from pathlib import Path
import re
import subprocess
import sys
from markdown_it import MarkdownIt

ROOT = Path(__file__).resolve().parents[1]
READER = 'markdown+tex_math_dollars+tex_math_single_backslash'

def nodes(value):
    if isinstance(value, dict):
        yield value
        for child in value.values():
            yield from nodes(child)
    elif isinstance(value, list):
        for child in value:
            yield from nodes(child)

class HtmlCheck(HTMLParser):
    def __init__(self):
        super().__init__()
        self.tables = 0
        self.text = []
    def handle_starttag(self, tag, attrs):
        if tag.lower() == 'table':
            self.tables += 1
    def handle_data(self, data):
        self.text.append(data)

def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--source-only', action='store_true', help='Skip generated editions.')
    args = ap.parse_args()
    parser = MarkdownIt('commonmark').enable('table')
    errors = []
    paths = sorted(ROOT.rglob('*.md'))
    if args.source_only:
        paths = [p for p in paths if p.name not in {'合订本.md', '_pdf_source.md'}]
    codeblocks = 0
    for path in paths:
        text = path.read_text(encoding='utf-8')
        rel = path.relative_to(ROOT)
        tokens = parser.parse(text)
        for t in tokens:
            if t.type == 'table_open':
                errors.append(f'{rel}: Markdown table at {t.map}')
            if t.type in {'fence', 'code_block'}:
                codeblocks += 1
                if re.search(r'\\+\|', t.content):
                    errors.append(f'{rel}: pipe escape inside code at {t.map}')
        # The actual handbook contains no intentional backslash-pipe sequences.
        for n, line in enumerate(text.splitlines(), 1):
            if re.search(r'\\+\|', line):
                errors.append(f'{rel}:{n}: unwanted pipe escape')
        result = subprocess.run(
            ['pandoc', '-f', READER, '-t', 'json'],
            input=text, text=True, capture_output=True, check=True)
        doc = json.loads(result.stdout)
        if any(n.get('t') == 'Table' for n in nodes(doc)):
            errors.append(f'{rel}: Pandoc detects a table')
    html_paths = [] if args.source_only else sorted(ROOT.glob('*.html'))
    if not args.source_only and not html_paths:
        errors.append('Offline HTML has not been built.')
    for path in html_paths:
        check = HtmlCheck()
        check.feed(path.read_text(encoding='utf-8'))
        if check.tables:
            errors.append(f'{path.name}: {check.tables} HTML tables')
        if re.search(r'\\+\|', ''.join(check.text)):
            errors.append(f'{path.name}: unwanted pipe escape in rendered text')
    print(f'Markdown documents: {len(paths)}; code blocks: {codeblocks}; HTML editions: {len(html_paths)}')
    for error in errors:
        print('ERROR:', error)
    print('No-table / pipe-rendering checks: ' + ('PASS' if not errors else 'FAIL'))
    return int(bool(errors))

if __name__ == '__main__':
    sys.exit(main())
