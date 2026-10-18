#!/usr/bin/env python3
"""Test review-page overlay controls using inlined local SVG resources.
No navigation, external websites, or Obsidian UI are tested.
"""
from pathlib import Path
from urllib.parse import unquote
import json,re,base64,shutil
from playwright.sync_api import sync_playwright
ROOT=Path(__file__).resolve().parents[1]

def main():
    source=(ROOT/'精确绘图检查.html').read_text(encoding='utf-8')
    def inline(m):
        path=(ROOT/unquote(m[2])).resolve()
        if not path.is_relative_to(ROOT) or path.suffix!='.svg':raise ValueError(path)
        return m[1]+'="data:image/svg+xml;base64,'+base64.b64encode(path.read_bytes()).decode()+'"'
    source=re.sub(r'\b(src|data-normal|data-debug)="([^"]+)"',inline,source)
    checks=[]
    with sync_playwright() as p:
        browser=p.chromium.launch(headless=True,executable_path=shutil.which('chromium'),args=['--no-sandbox'])
        page=browser.new_page(viewport={'width':1440,'height':1000});page.set_content(source,wait_until='load')
        page.wait_for_function('[...document.images].every(i=>i.complete&&i.naturalWidth>0)')
        checks.append({'test':'normal_images_loaded','passed':page.locator('img[data-normal]').count()==19})
        page.locator('#toggle').click()
        page.wait_for_function('[...document.images].every(i=>i.complete&&i.naturalWidth>0&&i.getAttribute("src")===i.dataset.debug)')
        checks.append({'test':'19_debug_overlays_loaded','passed':page.locator('#toggle').get_attribute('aria-pressed')=='true'})
        page.locator('#toggle').click()
        page.wait_for_function('[...document.images].every(i=>i.complete&&i.naturalWidth>0&&i.getAttribute("src")===i.dataset.normal)')
        checks.append({'test':'return_to_normal_images','passed':page.locator('#toggle').get_attribute('aria-pressed')=='false'})
        browser.close()
    result={'scope':'Review-page interaction using set_content and inlined local SVGs only. Native file navigation and Obsidian UI were not tested.',
            'passed':all(i['passed'] for i in checks),'checks':checks}
    (ROOT/'checks/review_interaction_validation.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result,ensure_ascii=False,indent=2))
    if not result['passed']:raise SystemExit(1)
if __name__=='__main__':main()
