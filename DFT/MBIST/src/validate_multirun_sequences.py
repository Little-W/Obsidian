#!/usr/bin/env python3
"""Validate multirun background functions, healthy reads, counts, and state edges."""
import json
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'examples'
BG3=['0','r0^c0','r0','c0']
BG4=['0','c0','1','1^c0','r0','r0^c0','1^r0','1^r0^c0']
BG5=['0','r0','c0','r0^c0','c1','c0^c1','r1','r0^r1','r0^r1^c0','r1^c0','r0^c1','r0^c0^c1','r0^r1^c0^c1','r1^c0^c1','1^r0^r1^c1','1^r1^c1']
S={'MT-R3CCF':(BG3,('r','wt'),2,21),'MT-3CCF':(BG3,('r','wt','wnt','r'),2,37),'MT-4CCF':(BG4,('r','wt','wnt','r','r','wt','wnt','r'),1,73),'MT_NPSF_81N':(BG5,('r','wt'),2,81),'MT_ENPSF':(BG5,('r','wnt','r','r','wt'),2,177)}
def bg(expr,r,c):
 vals={'0':0,'1':1,'r0':r&1,'r1':r>>1&1,'c0':c&1,'c1':c>>1&1}
 x=0
 for t in expr.split('^'):x^=vals[t]
 return x

def make(name,rows=16,cols=16):
 bgs,motif,sweeps,coef=S[name];n=rows*cols;mem=[0]*n;ops=[]
 def op(a,k,d,phase,b):
  before=mem[a]
  if k=='r':assert before==d,(name,a,before,d)
  else:mem[a]=d
  ops.append((a,k,d,phase,b,before))
 for a in range(n):op(a,'w',bg(bgs[0],a//cols,a%cols),'bg',0)
 for i,expr in enumerate(bgs):
  if i:
   for a in range(n):
    desired=bg(expr,a//cols,a%cols)
    if mem[a]!=desired:op(a,'r',mem[a],'bg',i);op(a,'w',desired,'bg',i)
  for s in range(sweeps):
   for a in range(n):
    for t in motif:
     op(a,'r' if t=='r' else 'w',1-mem[a] if t=='wt' else mem[a],'test',i)
 for a in range(n):op(a,'r',mem[a],'final',len(bgs))
 assert len(ops)==coef*n,(name,len(ops),coef*n)
 return ops

def check_group(ops,group):
 state=[None]*len(group);by_addr={a:i for i,a in enumerate(group)};trans=Counter();allops=set()
 for a,k,d,phase,b,before in ops:
  if a not in by_addr:continue
  idx=by_addr[a]
  if phase=='test':
   assert None not in state
   key=(tuple(state),k,idx,d)
   allops.add(key)
   if k=='w' and before!=d:trans[key]+=1
  if k=='w':state[idx]=d
 return len(trans),set(trans.values()),len(allops)
results={}
for name in S:
 ops=make(name);groups=[]
 if '3CCF' in name:
  for r in range(4,6):
   for c in range(4,6):
    for dr,dc in [(1,1),(1,-1),(-1,1),(-1,-1)]:groups.append(sorted([r*16+c,(r+dr)*16+c,r*16+c+dc]))
 elif '4CCF' in name:
  for r in range(4,6):
   for c in range(4,6):groups.append([r*16+c,r*16+c+1,(r+1)*16+c,(r+1)*16+c+1])
 else:
  for r in range(4,8):
   for c in range(4,8):groups.append(sorted([r*16+c,(r-1)*16+c,(r+1)*16+c,r*16+c-1,r*16+c+1]))
 stats=[check_group(ops,g) for g in groups]
 k=len(groups[0]);expect=k*2**k
 assert all(t==expect and counts=={1} for t,counts,_ in stats),(name,stats)
 if name not in ['MT-R3CCF','MT_NPSF_81N']:
  assert all(total==3*expect for _,_,total in stats),(name,stats)
 results[name]={'array_shape':[16,16],'operations':len(ops),'operations_per_cell':len(ops)//256,'groups_checked':len(groups),'cells_per_group':k,'unique_transition_edges_per_group':expect,'each_transition_edge_count':1,'full_operation_edges_per_group':stats[0][2]}
print(json.dumps(results,indent=2))
(OUT/'multirun_sequences.json').write_text(json.dumps({'definitions':S,'results':results},indent=2),encoding='utf-8')
