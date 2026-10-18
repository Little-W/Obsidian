#!/usr/bin/env python3
"""Static local integrity checks. No external services or third-party dependencies."""
from pathlib import Path
from urllib.parse import unquote, urlsplit
import re
import json
import xml.etree.ElementTree as ET
from document_support import ROOT, mask_code, math_items


def main() -> None:
    errors = []
    counts = {'markdown_documents': 0, 'local_links': 0, 'image_links': 0,
              'heading_links': 0, 'footnote_uses': 0, 'code_blocks': 0}
    expressions, referenced_images = [], set()
    manifests = json.loads((ROOT / 'checks/book_manifest.json').read_text(encoding='utf-8'))
    refs = json.loads((ROOT / 'checks/reference_index.json').read_text(encoding='utf-8'))
    # Footnotes are stable global R identifiers, each document has local definitions.
    for path in sorted(ROOT.glob('*.md')):
        text = path.read_text(encoding='utf-8')
        prose = mask_code(text)
        counts['markdown_documents'] += 1
        fences = re.findall(r'^```', text, re.M)
        counts['code_blocks'] += len(fences) // 2
        if len(fences) % 2:
            errors.append(f'{path.name}: unbalanced code fences')
        used = re.findall(r'\[\^(R\d+)\](?!:)', prose)
        defs = re.findall(r'^\[\^(R\d+)\]:', prose, re.M)
        for key in set(used) - set(defs):
            errors.append(f'{path.name}: missing footnote {key}')
        if len(defs) != len(set(defs)):
            errors.append(f'{path.name}: duplicate footnote definitions')
        counts['footnote_uses'] += len(used)
        if re.search(r'\[文献\s*\d|\[\^r\d', prose):
            errors.append(f'{path.name}: old reference format')
        headings = re.findall(r'^#{1,6}\s+(.+?)\s*$', prose, re.M)
        for target in re.findall(r'\[\[#([^|\]]+)\|[^\]]+\]\]', prose):
            counts['heading_links'] += 1
            if target not in headings:
                errors.append(f'{path.name}: missing TOC heading {target}')
        for m in re.finditer(r'(!?)\[([^\]\n]*)\]\(([^)\n]+)\)', prose):
            dest = m[3].strip().strip('<>')
            parsed = urlsplit(dest)
            if parsed.scheme or dest.startswith('//'):
                continue
            filename = unquote(parsed.path)
            if not filename:
                continue
            counts['local_links'] += 1
            local = (path.parent / filename).resolve()
            if not local.is_relative_to(ROOT.resolve()):
                errors.append(f'{path.name}: link escapes package {dest}')
            elif not local.exists():
                errors.append(f'{path.name}: missing target {dest}')
            if m[1]:
                counts['image_links'] += 1
                referenced_images.add(str(local.relative_to(ROOT)))
        items = list(math_items(text, path.name))
        expressions.extend([{k: v for k, v in item.items() if k not in ('start', 'end')} for item in items])
        clean = list(prose)
        for item in items:
            clean[item['start']:item['end']] = ' ' * (item['end'] - item['start'])
        if re.search(r'(?<!\\)\$', ''.join(clean)):
            errors.append(f'{path.name}: unmatched math dollar')
        if re.search(r'\\\[|\\\]', prose):
            errors.append(f'{path.name}: non-dollar display math delimiter')
    figures = []
    for svg in sorted((ROOT / 'assets').rglob('*.svg')):
        tree = ET.parse(svg)
        texts = [e for e in tree.iter() if e.tag.endswith('}text')]
        rasters = [e for e in tree.iter() if e.tag.endswith('}image')]
        fonts = [float(e.get('font-size', '0')) for e in texts]
        item = {'file': str(svg.relative_to(ROOT)), 'text_objects': len(texts),
                'raster_images': len(rasters), 'minimum_text_size': min(fonts) if fonts else 0}
        if not texts or rasters or min(fonts) < 28:
            errors.append(f'{svg.name}: expected native SVG text of size >= 28 and no raster images')
        figures.append(item)
    svg_names = {f['file'] for f in figures}
    if svg_names != referenced_images:
        errors.append('SVG files and referenced image files are not identical sets')
    for file in ROOT.rglob('*'):
        if file.suffix.lower() in {'.ttf', '.ttc', '.otf', '.woff', '.woff2'}:
            errors.append(f'Font file present: {file}')
    source_map = json.loads((ROOT / 'checks/source_map.json').read_text(encoding='utf-8'))
    (ROOT / 'checks/math_input.json').write_text(json.dumps(expressions, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    report = {'scope': 'Local file links, headings, references, math delimiters, native SVGs; no hardware or physical validation.',
              **counts, 'reference_count': manifests['reference_count'], 'svg_count': len(figures),
              'math_expressions': len(expressions), 'display_math': sum(x['display'] for x in expressions),
              'inline_math': sum(not x['display'] for x in expressions), 'errors': errors,
              'passed': not errors, 'figures': figures}
    (ROOT / 'checks/package_validation.json').write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({k: v for k, v in report.items() if k != 'figures'}, ensure_ascii=False, indent=2))
    if errors:
        raise SystemExit(1)

if __name__ == '__main__':
    main()
