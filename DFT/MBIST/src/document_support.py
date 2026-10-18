"""Shared text utilities for the handbook validators and HTML export."""
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
FENCE = re.compile(r'^```[^\n]*\n[\s\S]*?^```\s*$', re.M)
INLINE_CODE = re.compile(r'`[^`\n]+`')
MATH = re.compile(r'(?<!\\)\$\$([\s\S]*?)(?<!\\)\$\$|(?<![\\$])\$(?!\$)([^\n]*?)(?<!\\)\$(?!\$)')

def without_frontmatter(text: str) -> str:
    return re.sub(r'\A---\n[\s\S]*?\n---\n', '', text, count=1)

def mask_code(text: str) -> str:
    def blank(match):
        return re.sub(r'[^\n]', ' ', match[0])
    return INLINE_CODE.sub(blank, FENCE.sub(blank, text))

def math_items(text: str, filename: str):
    masked = mask_code(text)
    for m in MATH.finditer(masked):
        yield {'file': filename, 'line': masked[:m.start()].count('\n') + 1,
               'tex': m[1] if m[1] is not None else m[2], 'display': m[1] is not None,
               'start': m.start(), 'end': m.end()}
