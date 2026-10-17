#!/usr/bin/env python3
"""Check or refresh fully embedded example code. No VC Formal execution.

Default: check content equality. Pass --update after editing an example source
file to refresh its already-present code blocks in every relevant chapter.
"""
from __future__ import annotations
import argparse
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parents[1]
PATTERN = re.compile(
    r'(<!-- source-begin: ([^\n]+) -->\n\n```[^\n]*\n)'
    r'(.*?)'
    r'(\n```\n\n<!-- source-end -->)', re.S
)

def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--update', action='store_true')
    args = parser.parse_args()
    seen: set[str] = set()
    nblocks = 0
    nchapters = 0
    errors: list[str] = []
    for md in sorted(ROOT.glob('*.md')):
        if md.name in {'合订本.md', '_pdf_source.md'}:
            continue
        text = md.read_text(encoding='utf-8')
        if not PATTERN.search(text):
            continue
        nchapters += 1
        def replace(match: re.Match[str]) -> str:
            nonlocal nblocks
            rel = match[2]
            p = (ROOT / rel).resolve()
            nblocks += 1
            seen.add(rel)
            if not p.is_relative_to(ROOT) or not p.is_file():
                errors.append(f'{md.name}: missing or unsafe source {rel}')
                return match[0]
            source = p.read_text(encoding='utf-8').rstrip('\n')
            if source != match[3] and not args.update:
                errors.append(f'{md.name}: embedded source differs: {rel}')
            return match[1] + source + match[4] if args.update else match[0]
        result = PATTERN.sub(replace, text)
        if args.update and result != text:
            md.write_text(result, encoding='utf-8')
    required = {str(p.relative_to(ROOT))
                for p in (ROOT/'案例工程').rglob('*')
                if p.is_file() and p.suffix in {'.sv','.tcl','.f','.csv','.cc'}}
    for missing in sorted(required - seen):
        errors.append(f'Not embedded in any chapter: {missing}')
    print(f'Inline chapters: {nchapters}; blocks: {nblocks}; unique files: {len(seen)}')
    for error in errors:
        print('ERROR:', error)
    print('PASS' if not errors else 'FAIL')
    return bool(errors)

if __name__ == '__main__':
    sys.exit(main())
