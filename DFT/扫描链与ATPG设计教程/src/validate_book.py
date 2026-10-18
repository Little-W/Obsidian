#!/usr/bin/env python3
"""Check local document links, figure references, source IDs and math delimiters.
This validates packaging and syntax; it does not certify the technical content.
"""
from __future__ import annotations
import json,re
from pathlib import Path
from urllib.parse import unquote,urlsplit
from document_support import ROOT,mask_code,math_items

def main():
    manifest=json.loads((ROOT/'checks/book_manifest.json').read_text(encoding='utf-8'))
    files=list(manifest['files'].values())+['README.md']
    refs=(ROOT/manifest['files']['90']).read_text(encoding='utf-8')
    ref_ids=set(re.findall(r'<a id="(s\d+)"',refs))
    issues=[];math=[];figrefs=set();links=0;chars=0
    for name in files:
        p=ROOT/name
        if not p.exists():issues.append({'file':name,'error':'missing_document'});continue
        text=p.read_text(encoding='utf-8');masked=mask_code(text)
        chars+=len(re.findall(r'[\u4e00-\u9fff]',text)) if name!='README.md' else 0
        items=list(math_items(text,name));math.extend(items)
        # Any dollar sign outside recognized math, fences and inline code is suspicious.
        remainder=masked
        for m in reversed(items):remainder=remainder[:m['start']]+' '*(m['end']-m['start'])+remainder[m['end']:]
        if re.search(r'(?<!\\)\$',remainder):issues.append({'file':name,'error':'unmatched_dollar'})
        if re.search(r'turn\d+(?:search|view|file)\d+|MATHPLACEHOLDER',masked):issues.append({'file':name,'error':'internal_reference_leak'})
        if len(re.findall(r'^```',text,re.M))%2:issues.append({'file':name,'error':'unclosed_code_fence'})
        for m in re.finditer(r'!?\[[^\]\n]*\]\(([^)]+)\)',masked):
            url=m[1].split(' "',1)[0];u=urlsplit(url)
            if u.scheme or url.startswith('//'):continue
            links+=1;target=(p.parent/unquote(u.path)) if u.path else p
            if not target.is_file():issues.append({'file':name,'error':'missing_link','target':url});continue
            if u.fragment and target.suffix=='.md':
                fragment=unquote(u.fragment);body=target.read_text(encoding='utf-8')
                if not (f'id="{fragment}"' in body or any(fragment in h for h in re.findall(r'^#+ (.+)$',body,re.M))):
                    issues.append({'file':name,'error':'missing_anchor','target':url})
            if u.path.endswith('.svg'):figrefs.add(unquote(u.path))
        for rid in re.findall(r'\[S(\d+)\]',masked):
            if f's{rid}' not in ref_ids:issues.append({'file':name,'error':'unknown_source','source':rid})
    figures=json.loads((ROOT/'assets/figures_manifest.json').read_text(encoding='utf-8'))['figures']
    for f in figures:
        svg='assets/'+f['file'];png=ROOT/'assets/png'/Path(f['file']).with_suffix('.png')
        if svg not in figrefs:issues.append({'error':'unused_figure','file':svg})
        if not png.exists():issues.append({'error':'missing_png','file':str(png)})
    out={'scope':'Document syntax, packaging and local cross references; not content or physical-design verification.',
         'documents':len(files)-1,'readme_files':1,'chinese_characters_in_documents':chars,
         'references':len(ref_ids),'local_links_checked':links,'figures':len(figures),
         'math_expressions':len(math),'inline_math':sum(not x['display'] for x in math),
         'display_math':sum(x['display'] for x in math),'issues':issues,'passed':not issues}
    (ROOT/'checks/math_input.json').write_text(json.dumps(math,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    (ROOT/'checks/document_validation.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(out,ensure_ascii=False,indent=2))
    if issues:raise SystemExit(1)
if __name__=='__main__':main()
