#!/usr/bin/env python3
"""Optional local browser checks. Requires Playwright and Chromium.

Checks file/anchor links, image loading, MathJax conversion output, and page width.
It does not test the Obsidian application, hardware behavior, or external URLs.
"""
from pathlib import Path
from urllib.parse import unquote, urlsplit, quote
import argparse
import json
import shutil
import re
import base64
import mimetypes
from html.parser import HTMLParser
from playwright.sync_api import sync_playwright

ROOT = Path(__file__).resolve().parents[1]
class Links(HTMLParser):
    def __init__(self):
        super().__init__(); self.ids=[]; self.links=[]
    def handle_starttag(self, tag, attrs):
        attrs=dict(attrs)
        if 'id' in attrs: self.ids.append(attrs['id'])
        for key in ('href','src'):
            if key in attrs: self.links.append(attrs[key])

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--browser', type=Path)
    parser.add_argument('--screenshots', type=Path, help='Optional inspection folder outside the package.')
    args=parser.parse_args()
    pages=sorted(ROOT.glob('*.html'))+sorted((ROOT/'html').glob('*.html'))
    parsed={}
    errors=[]
    for file in pages:
        p=Links();p.feed(file.read_text(encoding='utf-8'));parsed[file.resolve()]=p
        if len(p.ids)!=len(set(p.ids)):errors.append(f'{file.name}: duplicate IDs')
    checked_links=0
    for file, content in parsed.items():
        for url in content.links:
            part=urlsplit(url)
            if part.scheme or url.startswith('//'):continue
            checked_links+=1
            target=(file.parent/unquote(part.path)).resolve() if part.path else file
            if not target.exists():errors.append(f'{file.name}: missing local target {url}')
            elif part.fragment and target in parsed and unquote(part.fragment) not in parsed[target].ids:
                errors.append(f'{file.name}: missing anchor {url}')
    browser_results=[]
    with sync_playwright() as p:
        browser=p.chromium.launch(headless=True,executable_path=str(args.browser) if args.browser else shutil.which('chromium'),args=['--no-sandbox'])
        for width in (1440,390):
            page=browser.new_page(viewport={'width':width,'height':1000},device_scale_factor=1)
            for file in pages:
                source=file.read_text(encoding='utf-8')
                def css_inline(m):
                    target=(file.parent/unquote(m[1])).resolve()
                    return '<style>'+target.read_text(encoding='utf-8')+'</style>'
                source=re.sub(r'<link rel="stylesheet" href="([^"]+)">',css_inline,source)
                def image_inline(m):
                    target=(file.parent/unquote(m[1])).resolve()
                    mime=mimetypes.guess_type(target.name)[0] or 'application/octet-stream'
                    return 'src="data:'+mime+';base64,'+base64.b64encode(target.read_bytes()).decode()+'"'
                source=re.sub(r'src="([^"]+)"',image_inline,source)
                page.set_content(source,wait_until='load')
                page.evaluate('document.fonts.ready')
                metrics=page.evaluate('''() => ({bodyWidth:document.body.scrollWidth,viewport:innerWidth,
                    brokenImages:[...document.images].filter(x=>!x.complete||x.naturalWidth===0).map(x=>x.src),
                    placeholder:/SCANMATHPLACEHOLDER/.test(document.body.innerText),
                    mathErrors:document.querySelectorAll('[data-mjx-error],[data-mml-node="merror"]').length,
                    svgMath:document.querySelectorAll('mjx-container').length})''')
                metrics.update(file=str(file.relative_to(ROOT)),tested_width=width)
                browser_results.append(metrics)
                if metrics['bodyWidth']>width+2 or metrics['brokenImages'] or metrics['placeholder'] or metrics['mathErrors']:
                    errors.append({'file':str(file.relative_to(ROOT)),'width':width,'metrics':metrics})
                if args.screenshots and width==1440 and file.name.startswith(('阅读入口','00_','03_','06_','10_')):
                    args.screenshots.mkdir(parents=True,exist_ok=True)
                    page.screenshot(path=str(args.screenshots/(file.stem+'.png')),full_page=False)
            page.close()
        browser.close()
    report={'scope':'Chromium set_content with inlined local CSS and images; links checked statically. File navigation, external URLs, and Obsidian UI not tested.',
            'pages':len(pages),'local_links':checked_links,'viewport_checks':len(browser_results),
            'passed':not errors,'errors':errors,'browser_results':browser_results}
    (ROOT/'checks/browser_validation.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:v for k,v in report.items() if k!='browser_results'},ensure_ascii=False,indent=2))
    if errors:raise SystemExit(1)

if __name__=='__main__':main()
