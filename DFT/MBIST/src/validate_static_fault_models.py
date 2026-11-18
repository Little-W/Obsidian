#!/usr/bin/env python3
"""Execute the stated 36-primitive static digital model with initialization before sensitization."""
import json
from collections import Counter
from itertools import product
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'examples'
S={
'March C-':[('any','w0'),('up','r0 w1'),('up','r1 w0'),('down','r0 w1'),('down','r1 w0'),('any','r0')],
'March SR':[('down','w0'),('up','r0 w1 r1 w0'),('up','r0 r0'),('up','w1'),('down','r1 w0 r0 w1'),('down','r1 r1')],
'March LR':[('any','w0'),('down','r0 w1'),('up','r1 w0 r0 w1'),('up','r1 w0'),('up','r0 w1 r1 w0'),('up','r0')],
'March SS':[('any','w0'),('up','r0 r0 w0 r0 w1'),('up','r1 r1 w1 r1 w0'),('down','r0 r0 w0 r0 w1'),('down','r1 r1 w1 r1 w0'),('any','r0')],
'March MSS':[('any','w0'),('up','r0 r0 w1 w1'),('up','r1 r1 w0 w0'),('down','r0 r0 w1 w1'),('down','r1 r1 w0 w0'),('any','r0')],
'March AB':[('any','w0'),('down','r0 w1 r1 w1 r1'),('down','r1 w0 r0 w0 r0'),('up','r0 w1 r1 w1 r1'),('up','r1 w0 r0 w0 r0'),('any','r0')],
'March AZ1 element expansion':[('any','w0'),('down','w1'),('up','w1 r1 r1 w0'),('up','w0 r0'),('up','r0 w1 w1 r1'),('up','r1')],
'March AZ element expansion':[('any','w0'),('down','w1'),('up','w1 r1 r1 w0 w0'),('up','r0'),('up','r0 w1 w1 r1'),('up','r1')],
'March AZ2':[('down','w0'),('down','w0 r0'),('up','r0 w1 w1 r1'),('up','r1 w0'),('down','r0 w1 w1 r1'),('down','r1')],
'March RAW':[('any','w0'),('up','r0 w0 r0 r0 w1 r1'),('up','r1 w1 r1 r1 w0 r0'),('down','r0 w0 r0 r0 w1 r1'),('down','r1 w1 r1 r1 w0 r0'),('any','r0')],
'RAW1 illustration':[('up','w0'),('up','w0 r0'),('up','r0'),('up','w1 r1'),('up','r1'),('up','w1 r1'),('up','r1'),('up','w0 r0'),('up','r0')],
}
for n in [1,2,3,8,9]:
 S[f'Dynamic-RAWC1 n={n}']=[('any','w0'),('up','r0 w0 '+'r0 '*n+'r0 w1 r1'),('up','r1 w1 '+'r1 '*n+'r1 w0 r0'),('down','r0 w0 r0 r0 w1 r1'),('down','r1 w1 r1 r1 w0 r0'),('any','r0')]
 if n<=8:S[f'Dynamic-RAWC2 n={n}']=[('any','w0'),('up','r0 w0 w0 '+'r0 '*n+'r0 r0 w0 r0 w1 r1'),('up','r1 w1 w1 '+'r1 '*n+'r1 r1 w1 r1 w0 r0'),('down','r0 w0 w0 r0 r0 r0 w0 r0 w1 r1'),('down','r1 w1 w1 r1 r1 r1 w1 r1 w0 r0'),('any','r0')]

def sequence(spec,n):
 for e,(direction,ops) in enumerate(spec):
  for a in (range(n-1,-1,-1) if direction=='down' else range(n)):
   for sub,op in enumerate(ops.split()):yield e,sub,a,op[0],int(op[1])

def run(spec,n=4,f=None):
 mem=[None]*n; trace=[]
 for e,sub,a,op,val in sequence(spec,n):
  pre=mem[a];ans=pre
  triggered=False
  if op=='w':mem[a]=val
  if f:
   kind,v,x,agg,y=f
   active=a==v and (agg is None or mem[agg]==y)
   if kind=='SAF':mem[v]=x;ans=mem[a]
   elif active:
    if kind in ['TF','CFtr'] and op=='w' and pre==x and val==1-x:mem[a]=x;triggered=True
    if kind in ['WDF','CFwd'] and op=='w' and pre==val==x:mem[a]=1-x;triggered=True
    if kind in ['DRDF','CFdrd'] and op=='r' and pre==x:mem[a]=1-x;triggered=True
    if kind=='RDF' and op=='r' and pre==x:mem[a]=1-x;ans=1-x;triggered=True
    if kind=='IRF' and op=='r' and pre==x:ans=1-x;triggered=True
  trace.append(dict(element=e,subop=sub,address=a,operation=op+str(val),before=pre,after=mem[a],actual_read=ans if op=='r' else None,activated=triggered))
  if op=='r' and ans!=val:return True,trace
 return False,trace

faults=[]
for k,x in product(['SAF','TF','RDF','IRF','DRDF','WDF'],[0,1]):faults.append((k,1,x,None,None))
for k,x,y,order in product(['CFtr','CFdrd','CFwd'],[0,1],[0,1],[0,1]):faults.append((k,1 if order==0 else 2,x,2 if order==0 else 1,y))
results={}
for name,spec in S.items():
 for n in [1,2,4,9]:
  bad,trace=run(spec,n=n)
  assert not bad,(name,n,trace[-1])
 result=Counter()
 for f in faults:
  detected,_=run(spec,f=f)
  result[f[0]]+=int(detected)
 results[name]={'length_per_address':sum(len(x.split()) for _,x in spec),'faults_detected':dict(result),'detected_of_36':sum(result.values())}
assert results['March AZ element expansion']['detected_of_36']==30
assert results['March AZ1 element expansion']['detected_of_36']==29
assert results['March AZ2']['detected_of_36']==30
for k in ['March SS','March MSS','March AB']:assert results[k]['detected_of_36']==36,(k,results[k])
(OUT/'march_sequence_data.json').write_text(json.dumps({'initialization_semantics':'Unknown values before the first write; state-conditioned activation requires known values; SAF is unconditional.','sequences':S,'fault_models':faults,'results':results},indent=2),encoding='utf-8')
print(json.dumps(results,indent=2))
