#!/usr/bin/env python3
"""Validate publication structure, examples and local links; never runs VC Formal."""
from pathlib import Path
import argparse,collections,hashlib,json,re,subprocess,sys,tkinter
ROOT=Path(__file__).resolve().parents[1]
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--source-only',action='store_true')
a=p.parse_args()
errors=[];tables=0;rows=0;codes=0;links=0
chapters=json.loads((ROOT/'脚本与工具/章节顺序.json').read_text())
mds=[x for x in ROOT.rglob('*.md') if x.name!='合订本.md']
generated={'合订本.md','VC_Formal_中文手册_合订本.pdf','VC_Formal_中文手册_离线阅读版.html'}
link_re=re.compile(r'!?\[[^\]]*\]\(([^)]+)\)')
for md in mds:
 s=md.read_text();lines=s.splitlines();fence=None;table_cols=None
 for bad in ['源码内嵌版','（按 User Guide）','本版不使用表格','分点说明与代码块版']:
  if bad in s:errors.append(f'{md.name}: stale phrase {bad}')
 for n,line in enumerate(lines,1):
  m=re.match(r'^\s*(`{3,}|~{3,})',line)
  if m:
   if fence is None:fence=m[1][0];codes+=1
   elif fence==m[1][0]:fence=None
   continue
  if fence:continue
  if '\\|' in line:errors.append(f'{md.name}:{n}: escaped pipe outside code')
  for target in link_re.findall(line):
   target=target.strip('<>').split(' ',1)[0].split('#',1)[0]
   if not target or target.startswith(('http:','https:','mailto:','data:')):continue
   links+=1
   if a.source_only and Path(target).name in generated:continue
   if not (md.parent/target).exists():errors.append(f'{md.name}:{n}: missing link {target}')
  if line.startswith('|') and line.rstrip().endswith('|'):
   cells=line.strip().split('|')[1:-1]
   if n<len(lines) and re.match(r'^\|\s*:?-{3,}',lines[n]):
    table_cols=len(cells);tables+=1
   elif all(re.fullmatch(r'\s*:?-{3,}:?\s*',c) for c in cells):pass
   else:
    rows+=1
    if table_cols is None:errors.append(f'{md.name}:{n}: table without header')
    elif len(cells)!=table_cols:errors.append(f'{md.name}:{n}: {len(cells)} table cells, expected {table_cols}')
  else:table_cols=None
 if fence:errors.append(f'{md.name}: unclosed code fence')
# Tcl completeness is structural, not command execution.
tcl=tkinter.Tcl();tcls=list((ROOT/'案例工程').rglob('*.tcl'))
for f in tcls:
 if not tcl.call('info','complete',f.read_text()):errors.append(f'{f.name}: incomplete Tcl')
D=json.loads((ROOT/'脚本与工具/命令资料索引.json').read_text())
for c in D:
 if c['name']!='vcf' and not tcl.call('info','complete',c['example']):errors.append(f'{c["name"]}: incomplete Tcl snippet')
 if not c['pages'] or not c['syntax'] or not c['params'] or not c['example']:errors.append(f'{c["name"]}: missing command content')
for f in (ROOT/'案例工程').glob('*.f'):
 for line in f.read_text().splitlines():
  line=line.strip()
  if line and not line.startswith(('#','//','+')) and not (f.parent/line).exists():errors.append(f'{f.name}: missing source {line}')
res=subprocess.run([sys.executable,str(ROOT/'脚本与工具/sync_inline_sources.py')],text=True,capture_output=True)
if res.returncode:errors.append(res.stdout+res.stderr)
# Reproducible source hashes.
hashes={str(f.relative_to(ROOT)):hashlib.sha256(f.read_bytes()).hexdigest() for f in (ROOT/'案例工程').rglob('*') if f.is_file() and f.suffix in {'.sv','.tcl','.f','.cc','.csv'}}
(ROOT/'脚本与工具/案例源码校验值_SHA256.json').write_text(json.dumps(hashes,ensure_ascii=False,indent=2))
if not a.source_only:
 for f in generated:
  if not (ROOT/f).is_file():errors.append('missing generated file '+f)
 if (ROOT/'VC_Formal_中文手册_离线阅读版.html').is_file():
  from bs4 import BeautifulSoup
  html=BeautifulSoup((ROOT/'VC_Formal_中文手册_离线阅读版.html').read_text(),'html.parser')
  for code in html.select('pre code'):
   if '\\|' in code.get_text():errors.append('HTML: escaped pipe in code block')
  for table in html.find_all('table'):
   for row in table.find_all('tr'):
    if row.find('pre'):errors.append('HTML: code block inside table')
report=dict(revision='1.3',mode='source-only' if a.source_only else 'publication',
 tutorial_chapters=len(chapters),markdown_files=len(mds),overview_tables=tables,table_body_rows=rows,
 fenced_code_blocks=codes,local_links=links,command_entries=len(D),source_files=len(hashes),
 tcl_source_files=len(tcls),inline_source_check=res.stdout.strip(),vc_formal_executed=False,errors=errors)
(ROOT/'脚本与工具/发布检查记录.json').write_text(json.dumps(report,ensure_ascii=False,indent=2))
print(json.dumps(report,ensure_ascii=False,indent=2))
sys.exit(bool(errors))
