#!/usr/bin/env python3
"""Execute explicit dual-port and 8T IMC teaching fault models from chapter 11."""
from itertools import permutations, product
import json
from pathlib import Path

def m1_run(n, fault=None):
    ideal=[0]*n; actual=[0]*n; errors=[]; cycles=0
    def rd(ids):
        nonlocal cycles
        cycles+=1
        for x in ids:
            if actual[x]!=ideal[x]:errors.append((cycles,x))
    def wr(assign, concurrent=False):
        nonlocal cycles
        cycles+=1
        old=actual[:]
        for x,b in assign.items():ideal[x]=b;actual[x]=b
        if fault and concurrent:
            a,b,v,ta,tb,effect=fault
            if a in assign and b in assign and old[a]!=ta and old[b]!=tb and assign[a]==ta and assign[b]==tb:
                actual[v]=effect
    for i,j in permutations(range(n),2):
        for tx,ty,background in product((0,1),repeat=3):
            for x in range(n):wr({x:background})
            wr({i:1-tx});wr({j:1-ty})
            rd((i,j))
            wr({i:tx,j:ty},True)
            for x in range(n):rd((x,))
    return errors,cycles

report={}
for n in (3,4):
    errors,cycles=m1_run(n)
    assert not errors
    duplex=[]
    for a,b,v in permutations(range(n),3):
        for ta,tb,effect in product((0,1),repeat=3):
            f=(a,b,v,ta,tb,effect)
            assert m1_run(n,f)[0],f
            duplex.append(f)
    concurrent=[]
    for a,b in permutations(range(n),2):
        for ta,tb in product((0,1),repeat=2):
            f=(a,b,b,ta,tb,1-tb)
            assert m1_run(n,f)[0],f
            concurrent.append(f)
    report[f'DualPortExhaustive_N{n}']={'ideal_pass':True,'duplex_instances_detected':len(duplex),'concurrent_instances_detected':len(concurrent),'abstract_cycles':cycles}

def imc_run(n,kind=None,victim=0):
    q=[0]*n; errors=[]; count=0
    def write(i,b):
        nonlocal count
        count+=1;q[i]=b
    def read(i,b):
        nonlocal count
        count+=1
        if q[i]!=b:errors.append(count)
    def nor(ids,expect):
        nonlocal count
        count+=1
        ids=list(ids)
        values=[q[i] for i in ids]
        if kind=='selected_one_ignored' and victim in ids and q[victim]==1:
            values=[q[i] for i in ids if i!=victim]
        if kind=='unselected_one_contributes' and victim not in ids and q[victim]==1:
            values.append(1)
        got=int(not any(values))
        if got!=expect:errors.append(count)
    for i in range(n):write(i,0)
    for i in range(0,n,2):
        nor([i,i+1],1);write(i,1);write(i+1,1)
    for i in range(n):read(i,1);write(i,0)
    for i in reversed(range(n)):read(i,0);write(i,1)
    for i in reversed(range(n)):read(i,1);write(i,0)
    nor(range(n),1)
    for i in reversed(range(n)):
        write(i,1);nor(range(n),0);nor([j for j in range(n) if j!=i],1);write(i,0)
    return errors,count,q
for n in (2,4,6,8):
    errors,count,q=imc_run(n)
    assert errors==[] and q==[0]*n
    assert count==12.5*n+1
    cases=[]
    for kind in ('selected_one_ignored','unselected_one_contributes'):
        for v in range(n):
            e,c,_=imc_run(n,kind,v);assert e
            cases.append({'model':kind,'victim':v,'first_mismatch':e[0]})
    report[f'IMC_Nc{n}']={'ideal_pass':True,'operations':count,'checked_formula':'12.5*Nc+1','detected_cases':cases}

def check_cross_port_pattern(n, address_map):
    memory=[0]*n
    mismatches=[]
    for target in range(n):
        memory=[0]*n
        memory[target]=1
        for logical in range(n):
            expected=int(logical==target)
            actual=memory[address_map[logical]]
            if actual!=expected:
                mismatches.append((target,logical,expected,actual))
    return mismatches

for n in (2,3,4):
    identity=tuple(range(n))
    assert not check_cross_port_pattern(n,identity)
    count=0
    for address_map in permutations(range(n)):
        if address_map!=identity:
            assert check_cross_port_pattern(n,address_map)
            count+=1
    report[f'CrossPortAddress_N{n}']={'ideal_pass':True,'detected_nonidentity_permutations':count,'port_accesses':2*n*n+n}

p=Path(__file__).resolve().parents[1]/'examples/port_imc_results.json'
p.write_text(json.dumps(report,ensure_ascii=False,indent=2))
print(json.dumps({k:{key:val for key,val in v.items() if key!='detected_cases'} for k,v in report.items()},ensure_ascii=False,indent=2))
