#!/usr/bin/env python3
"""Inject one state-conditioned local fault into each multirun test.

Each primitive specifies a complete local bit pattern, one addressed cell, one
read/write event, and one victim. The event flips the victim relative to the
value after the normal operation. A triggering victim read returns its old
value before corruption, so a later read must observe the damage. The first
background write initializes the local array from an all-zero starting state.
These finite digital models do not include timing, probability, or linked faults.
"""
from contextlib import redirect_stdout
import io
from itertools import product
import json
from pathlib import Path

with redirect_stdout(io.StringIO()):
    from validate_multirun_sequences import make

ROOT=Path(__file__).resolve().parents[1]


def local_trace(operations,group):
    index={address:i for i,address in enumerate(group)}
    return [(index[a],op,value) for a,op,value,*_ in operations if a in index]


def detect(trace,pattern,trigger,kind,victim):
    memory=[0]*len(pattern)
    op='r' if kind=='read' else 'w'
    value=1-pattern[trigger] if kind=='transition' else pattern[trigger]
    activated=False
    for step,(address,operation,expected) in enumerate(trace,1):
        active=(address==trigger and operation==op and
                (operation=='r' or expected==value) and tuple(memory)==pattern)
        actual=memory[address]
        if operation=='r' and actual!=expected:
            return True,activated,step
        if operation=='w':
            memory[address]=expected
        if active:
            memory[victim]=1-memory[victim]
            activated=True
    return False,activated,None


def groups_for(name):
    if '3CCF' in name:
        for r,c,dr,dc in product(range(4,6),range(4,6),(-1,1),(-1,1)):
            yield sorted([r*16+c,(r+dr)*16+c,r*16+c+dc]),None
    elif '4CCF' in name:
        for r,c in product(range(4,6),repeat=2):
            yield [r*16+c,r*16+c+1,(r+1)*16+c,(r+1)*16+c+1],None
    else:
        for r,c in product(range(4,8),repeat=2):
            group=sorted([r*16+c,(r-1)*16+c,(r+1)*16+c,r*16+c-1,r*16+c+1])
            yield group,group.index(r*16+c)


def main():
    results=[]
    names=['MT-R3CCF','MT-3CCF','MT-4CCF','MT_NPSF_81N','MT_ENPSF']
    for name in names:
        operations=make(name)
        kinds=('transition',) if name in ('MT-R3CCF','MT_NPSF_81N') else ('transition','nontransition','read')
        detected=total=0
        misses=[]
        representative=None
        count_groups=0
        for group,fixed_victim in groups_for(name):
            count_groups+=1
            trace=local_trace(operations,group)
            victims=range(len(group)) if fixed_victim is None else (fixed_victim,)
            for pattern,trigger,kind,victim in product(product((0,1),repeat=len(group)),range(len(group)),kinds,victims):
                hit,activated,first=detect(trace,pattern,trigger,kind,victim)
                total+=1
                detected+=hit
                record={'group':group,'pattern':pattern,'trigger_cell':trigger,'event':kind,
                        'victim_cell':victim,'activated':activated,'first_wrong_read_in_local_trace':first}
                if not hit:
                    misses.append(record)
                elif representative is None:
                    representative=record
        item={'algorithm':name,'group_classes':count_groups,'fault_scenarios':total,
              'detected_scenarios':detected,'passed':detected==total,'misses':misses,
              'representative':representative}
        results.append(item)
        print(name,detected,'/',total)
    report={'scope':__doc__.strip(),'passed':all(x['passed'] for x in results),
            'fault_scenarios':sum(x['fault_scenarios'] for x in results),'results':results}
    (ROOT/'examples/multirun_fault_results.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    if not report['passed']:
        raise SystemExit(1)


if __name__=='__main__':
    main()
