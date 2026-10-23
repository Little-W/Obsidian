#!/usr/bin/env python3
"""Independent stdlib validation: complete coverage, constraints, schedules and optimum.
The independent exact search assigns one memory at a time to canonical groups;
it does not reuse the C++ subset-DP implementation.
"""
from __future__ import annotations
import csv
import json
import subprocess
import tempfile
from pathlib import Path
import random

ROOT=Path(__file__).resolve().parents[1]
LIMITS=(3,10,300,20,2)

def read_memories(path: Path) -> list[dict]:
    with path.open(encoding='utf-8',newline='') as f:
        rows=list(csv.DictReader(f))
    for row in rows:
        for field in ('x_um','y_um','power_mw','duration_us'):
            row[field]=int(row[field])
    return rows

def hpwl(group: list[dict]) -> int:
    return max(m['x_um'] for m in group)-min(m['x_um'] for m in group)+max(m['y_um'] for m in group)-min(m['y_um'] for m in group)

def legal(group: list[dict]) -> bool:
    return bool(group) and len(group)<=3 and len({(m['clock'],m['interface']) for m in group})==1 and sum(m['power_mw'] for m in group)<=10 and hpwl(group)<=300

def independent_optimum(memories: list[dict]) -> tuple[int,int]:
    best=(len(memories)+1,10**9)
    groups: list[list[dict]]=[]
    def visit(i: int) -> None:
        nonlocal best
        if len(groups)>best[0]:
            return
        if i==len(memories):
            best=min(best,(len(groups),sum(hpwl(g) for g in groups)))
            return
        m=memories[i]
        for g in groups:
            g.append(m)
            if legal(g):
                visit(i+1)
            g.pop()
        if len(groups)<best[0] and legal([m]):
            groups.append([m]);visit(i+1);groups.pop()
    visit(0)
    return best

def validate(result: dict,memories: list[dict]) -> None:
    lookup={m['id']:m for m in memories}
    seen=[]
    for group in result['groups']:
        ids=group['members']; seen.extend(ids)
        members=[lookup[i] for i in ids]
        assert legal(members), ('illegal group',ids)
        assert group['hpwl_um']==hpwl(members)
        assert group['power_mw']==sum(m['power_mw'] for m in members)
        assert group['duration_us']==max(m['duration_us'] for m in members)
    assert sorted(seen)==sorted(lookup), 'missing / duplicated instance'
    assert result['group_count']==len(result['groups'])
    assert result['sum_hpwl_um']==sum(g['hpwl_um'] for g in result['groups'])
    events=result['schedule']
    assert sorted(e['group'] for e in events)==list(range(len(result['groups'])))
    for e in events:
        g=result['groups'][e['group']]
        assert e['start_us']>=0 and e['end_us']-e['start_us']==g['duration_us']
        assert e['power_mw']==g['power_mw']
    peak=0
    for t in sorted({e[k] for e in events for k in ('start_us','end_us')}):
        active=[e for e in events if e['start_us']<=t<e['end_us']]
        power=sum(e['power_mw'] for e in active)
        assert len(active)<=2 and power<=20
        peak=max(peak,power)
    assert result['reserved_peak_mw']==peak
    assert result['estimated_makespan_us']==max(e['end_us'] for e in events)

def main() -> None:
    base=read_memories(ROOT/'data/memories.csv')
    records=[]
    for p in sorted((ROOT/'results').glob('*.json')):
        if p.stem not in {'first_fit', 'best_fit_decreasing', 'geometry_greedy',
                          'capacity_dsatur', 'greedy_local_exact_repair', 'exact_subset_dp'}:
            continue
        r=json.loads(p.read_text());validate(r,base);records.append(r['algorithm'])
    assert len(records)==6
    optimum=independent_optimum(base)
    exact=json.loads((ROOT/'results/exact_subset_dp.json').read_text())
    assert optimum==(exact['group_count'],exact['sum_hpwl_um'])==(4,800)
    lower=max((len(base)+2)//3,(sum(m['power_mw'] for m in base)+9)//10)
    assert lower==4
    rng=random.Random(20261020)
    binary=ROOT/'build/mbist_demo'
    with tempfile.TemporaryDirectory() as td:
        tmp=Path(td)
        for trial in range(24):
            rows=[]
            for i in range(rng.randrange(4,9)):
                rows.append({'id':f'M{i}','clock':f'c{rng.randrange(2)}','interface':'SP1',
                             'x_um':rng.randrange(0,7)*100,'y_um':rng.randrange(0,3)*100,
                             'power_mw':rng.randrange(1,8),'duration_us':rng.randrange(1,6)*20})
            inp=tmp/'input.csv';out=tmp/'results'
            with inp.open('w',newline='') as f:
                w=csv.DictWriter(f,fieldnames=list(rows[0]));w.writeheader();w.writerows(rows)
            subprocess.run([str(binary),str(inp),str(out)],check=True,capture_output=True,text=True)
            for p in out.glob('*.json'):
                validate(json.loads(p.read_text()),rows)
            r=json.loads((out/'exact_subset_dp.json').read_text())
            assert independent_optimum(rows)==(r['group_count'],r['sum_hpwl_um'])
        # Invalid input tests must fail, not silently discard a memory.
        header='id,clock,interface,x_um,y_um,power_mw,duration_us\n'
        for content in [header+'A,c,SP1,0,0,11,10\n',header+'A,c,SP1,0,0,2,10\nA,c,SP1,1,1,2,10\n',header+'A,c,SP1,0,0,-1,10\n']:
            inp.write_text(content)
            r=subprocess.run([str(binary),str(inp),str(out)],capture_output=True,text=True)
            assert r.returncode!=0
    report={'base_algorithms_validated':records,'independent_optimum_groups':4,
            'independent_optimum_sum_hpwl_um':800,'group_count_lower_bound':lower,
            'random_cases_cross_checked':24,'invalid_input_cases_rejected':3,
            'commercial_eda_executed':False,
            'scope':'synthetic example; exactness applies only to declared grouping model'}
    (ROOT/'results/verification.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(report,ensure_ascii=False,indent=2))

if __name__=='__main__': main()
