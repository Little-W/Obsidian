#!/usr/bin/env python3
"""Small, exhaustively checked scan/ATPG examples. Python 3.10+, standard library.
Not a production ATPG, timing simulator, or replacement for EDA verification.
Run: python src/teaching_examples.py --random-circuits 40
"""
from __future__ import annotations
from dataclasses import dataclass
from itertools import product, combinations
from pathlib import Path
from collections import defaultdict
import argparse, json, random
ROOT=Path(__file__).resolve().parents[1]

@dataclass(frozen=True)
class Gate:
    out: str
    op: str
    ins: tuple[str,...]
@dataclass(frozen=True)
class Fault:
    kind: str
    site: str
    stuck: int
    pin: int=-1
    def label(self)->str:
        return f'{self.site}'+(f'/pin{self.pin}' if self.kind=='branch' else '')+f'/sa{self.stuck}'
@dataclass(frozen=True)
class Circuit:
    inputs: tuple[str,...]
    gates: tuple[Gate,...]
    outputs: tuple[str,...]
    def check(self):
        seen=set(self.inputs)
        if len(seen)!=len(self.inputs): raise ValueError('duplicate primary inputs')
        for g in self.gates:
            if g.out in seen or not set(g.ins)<=seen: raise ValueError('not a topological DAG')
            if len(g.ins)!=(1 if g.op in ('NOT','BUF') else 2): raise ValueError('gate arity')
            seen.add(g.out)
        if not set(self.outputs)<=seen: raise ValueError('unknown output')
    def faults(self,branches=True):
        stems=[Fault('stem',n,s) for n in self.inputs+tuple(g.out for g in self.gates) for s in (0,1)]
        pins=[Fault('branch',g.out,s,i) for g in self.gates for i in range(len(g.ins)) for s in (0,1)]
        return stems+(pins if branches else [])
    def simulate(self,x:tuple[int,...],fault:Fault|None=None)->tuple[int,...]:
        if len(x)!=len(self.inputs) or any(a not in (0,1) for a in x): raise ValueError('binary pattern shape')
        values=dict(zip(self.inputs,x))
        if fault and fault.kind=='stem' and fault.site in values: values[fault.site]=fault.stuck
        for g in self.gates:
            args=[values[n] for n in g.ins]
            if fault and fault.kind=='branch' and fault.site==g.out: args[fault.pin]=fault.stuck
            values[g.out]=logic(g.op,tuple(args))
            if fault and fault.kind=='stem' and fault.site==g.out: values[g.out]=fault.stuck
        return tuple(values[n] for n in self.outputs)

def logic(op:str,a:tuple[int,...])->int:
    if op=='NOT': return 1-a[0]
    if op=='BUF': return a[0]
    if op=='AND': return a[0]&a[1]
    if op=='NAND': return 1-(a[0]&a[1])
    if op=='OR': return a[0]|a[1]
    if op=='NOR': return 1-(a[0]|a[1])
    if op=='XOR': return a[0]^a[1]
    if op=='XNOR': return 1-(a[0]^a[1])
    raise ValueError(op)

CIRCUIT=Circuit(('a','b','c','d'),(Gate('n1','AND',('a','b')),Gate('n2','OR',('n1','c')),Gate('y','XOR',('n2','d')),Gate('z','AND',('n1','d'))),('y','z'))

class CNF:
    def __init__(self): self.n=0;self.clauses=[]
    def var(self)->int: self.n+=1;return self.n
    def relation(self,ins:list[int],out:int,op:str):
        # Exclude each input assignment paired with the wrong output. Duplicated
        # fanins remain the SAME variable, preserving reconvergent correlation.
        for vals in product((0,1),repeat=len(ins)):
            result=logic(op,vals)
            self.clauses.append(tuple([-v if b else v for v,b in zip(ins,vals)]+[out if result else -out]))
    def equal(self,a,b): self.clauses.extend([(-a,b),(a,-b)])
    def constant(self,b):
        v=self.var();self.clauses.append((v if b else -v,));return v

def fault_miter(c:Circuit,f:Fault)->tuple[CNF,list[int]]:
    cnf=CNF();shared={n:cnf.var() for n in c.inputs};copies=[]
    for faulty in (False,True):
        nodes={}
        for n in c.inputs:
            nodes[n]=cnf.var()
            if faulty and f.kind=='stem' and f.site==n: cnf.clauses.append((nodes[n] if f.stuck else -nodes[n],))
            else: cnf.equal(nodes[n],shared[n])
        for g in c.gates:
            y=cnf.var();nodes[g.out]=y
            if faulty and f.kind=='stem' and f.site==g.out: cnf.clauses.append((y if f.stuck else -y,))
            else:
                args=[nodes[n] for n in g.ins]
                if faulty and f.kind=='branch' and f.site==g.out: args[f.pin]=cnf.constant(f.stuck)
                cnf.relation(args,y,g.op)
        copies.append(nodes)
    diffs=[]
    for n in c.outputs:
        d=cnf.var();cnf.relation([copies[0][n],copies[1][n]],d,'XOR');diffs.append(d)
    cnf.clauses.append(tuple(diffs))
    return cnf,[shared[n] for n in c.inputs]

def solve(clauses:list[tuple[int,...]],assigned:dict[int,bool]|None=None)->dict[int,bool]|None:
    """Complete DPLL for tiny examples; no timeout, hence None means proven UNSAT."""
    assigned=dict(assigned or {})
    while True:
        rest=[]
        for cl in clauses:
            if any(abs(l) in assigned and assigned[abs(l)]==(l>0) for l in cl): continue
            row=tuple(l for l in cl if abs(l) not in assigned)
            if not row: return None
            rest.append(row)
        if not rest: return assigned
        units=[r[0] for r in rest if len(r)==1]
        if not units: break
        for l in units:
            v,b=abs(l),l>0
            if v in assigned and assigned[v]!=b: return None
            assigned[v]=b
        clauses=rest
    counts=defaultdict(int)
    for cl in rest:
        for l in cl:counts[abs(l)]+=1
    var=max(counts,key=counts.get)
    for value in (False,True):
        branch=solve(rest,assigned|{var:value})
        if branch is not None:return branch
    return None

def sat_pattern(c,f):
    cnf,inputs=fault_miter(c,f);answer=solve(cnf.clauses)
    return None if answer is None else tuple(int(answer.get(v,False)) for v in inputs)

def validate_circuit(c:Circuit,fixed_input_checks=False):
    c.check();patterns=list(product((0,1),repeat=len(c.inputs)));fs=c.faults();checks=0;detectable=0
    for f in fs:
        witnesses=[x for x in patterns if c.simulate(x)!=c.simulate(x,f)]
        p=sat_pattern(c,f)
        assert (p is not None)==bool(witnesses),(f,p,witnesses)
        if p is not None: assert c.simulate(p)!=c.simulate(p,f);detectable+=1
        if fixed_input_checks:
            cnf,ids=fault_miter(c,f)
            for x in patterns:
                exists=solve(cnf.clauses,{v:bool(b) for v,b in zip(ids,x)}) is not None
                assert exists==(x in witnesses),(f,x)
                checks+=1
    return {'faults':len(fs),'detectable':detectable,'untestable':len(fs)-detectable,'fixed_input_miter_checks':checks}

def covers(c):
    ps=list(product((0,1),repeat=len(c.inputs)));fs=c.faults()
    masks=[sum(1<<i for i,f in enumerate(fs) if c.simulate(p)!=c.simulate(p,f)) for p in ps]
    universe=0
    for m in masks:universe|=m
    chosen=[];covered=0
    while covered!=universe:
        j=max(range(len(ps)),key=lambda i:(masks[i]&~covered).bit_count())
        assert masks[j]&~covered
        chosen.append(j);covered|=masks[j]
    best=None
    for k in range(1,len(chosen)+1):
        for inds in combinations(range(len(ps)),k):
            union=0
            for i in inds:union|=masks[i]
            if union==universe: best=inds;break
        if best is not None:break
    fmt=lambda p:''.join(map(str,p))
    return {'faults':len(fs),'detectable_faults':universe.bit_count(),'greedy_count':len(chosen),'greedy_patterns':[fmt(ps[i]) for i in chosen], 'minimum_count':len(best),'minimum_patterns':[fmt(ps[i]) for i in best], 'matrix':[{'pattern':fmt(p),'outputs':fmt(c.simulate(p)),'detects':[f.label() for i,f in enumerate(fs) if masks[k]>>i&1]} for k,p in enumerate(ps)]}

def cube_completions(cube):
    positions=[i for i,v in enumerate(cube) if v is None]
    for values in product((0,1),repeat=len(positions)):
        x=list(cube)
        for i,v in zip(positions,values):x[i]=v
        yield tuple(x)

def scan_shift(q,serial):
    q=list(q);so=[];states=[q.copy()];flips=0
    for bit in serial:
        so.append(q[-1]);n=[bit]+q[:-1]
        flips+=sum(a!=b for a,b in zip(q,n));q=n;states.append(q.copy())
    return {'q':q,'serial_out':so,'states':states,'register_flips':flips}

def compression_example():
    matrix=((1,0),(0,1),(1,1));reachable={}
    for seed in product((0,1),repeat=2):
        out=tuple(sum(a*b for a,b in zip(row,seed))%2 for row in matrix);reachable[''.join(map(str,out))]=''.join(map(str,seed))
    assert '111' not in reachable and reachable['101']=='10'
    return {'matrix':matrix,'reachable':reachable,'unencodable_cube':'111','encodable_cube':'1X1','seed':'10','xor_error_110_alias':1^1^0,'two_bit_compactor_111_alias':[1^1,1^1]}

def diagnosis(c):
    pats=list(product((0,1),repeat=len(c.inputs)));groups=defaultdict(list);compact=defaultdict(list)
    for f in c.faults():
        signature=tuple(tuple(a^b for a,b in zip(c.simulate(p),c.simulate(p,f))) for p in pats)
        groups[signature].append(f.label());compact[tuple(any(v) for v in signature)].append(f.label())
    return {'full_response_classes':len(groups),'pass_fail_classes':len(compact),'largest_full_class':max(map(len,groups.values())), 'full_equivalence_classes':list(groups.values()),'pass_fail_equivalence_classes':list(compact.values())}

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--random-circuits',type=int,default=40);a=parser.parse_args()
    if not 0<=a.random_circuits<=200:parser.error('0..200 random circuits allowed')
    maincheck=validate_circuit(CIRCUIT,True)
    redundant=Circuit(('a','b'),(Gate('n','AND',('a','b')),Gate('y','OR',('a','n'))),('y',))
    assert sat_pattern(redundant,Fault('stem','n',0)) is None
    assert all(redundant.simulate(p)==redundant.simulate(p,Fault('stem','n',0)) for p in product((0,1),repeat=2))
    assert sat_pattern(redundant,Fault('stem','n',1)) is not None
    cube=(1,1,0,None);target=Fault('stem','n1',0)
    assert all(CIRCUIT.simulate(x)!=CIRCUIT.simulate(x,target) for x in cube_completions(cube))
    q0=[0,1,1,0];desired=[1,1,0,1];sr=scan_shift(q0,list(reversed(desired)))
    assert sr['q']==desired and sr['serial_out']==list(reversed(q0))
    fixed_cube=[1,None,0,None];options=[]
    for p in cube_completions(fixed_cube):
        rec=scan_shift(q0,list(reversed(p)));options.append({'filled':list(p),'flips':rec['register_flips']})
    # A zero fill is not necessarily best; retain exact costs instead of claiming it is.
    rng=random.Random(20261017);random_results=[]
    for _ in range(a.random_circuits):
        ins=('a','b','c','d');available=list(ins);gs=[]
        for i in range(rng.randint(3,7)):
            op=rng.choice(['AND','OR','XOR','NAND','NOR','XNOR','NOT','BUF']);fanin=tuple(rng.choice(available) for _ in range(1 if op in ('NOT','BUF') else 2))
            out=f'g{i}';gs.append(Gate(out,op,fanin));available.append(out)
        rc=Circuit(ins,tuple(gs),(gs[-1].out,gs[-2].out));random_results.append(validate_circuit(rc))
    result={'scope':'Synthetic Boolean combinational and scan-register examples; no delay/power/industrial ATPG validation.', 'circuit_checks':maincheck,'cover':covers(CIRCUIT),'redundancy':{'fault':'n/sa0','result':'UNSAT (complete tiny DPLL + exhaustive check)'},'cube':{'target':'n1/sa0','pattern':'110X','completions':[''.join(map(str,x)) for x in cube_completions(cube)]},'scan':{'initial':q0,'desired':desired,'serial_in':list(reversed(desired)),**sr},'x_fill':{'initial':q0,'cube':fixed_cube,'options':options,'best':min(options,key=lambda x:x['flips'])},'compression':compression_example(),'diagnosis':diagnosis(CIRCUIT),'random_validation':{'seed':20261017,'circuits':len(random_results),'faults':sum(z['faults'] for z in random_results),'satisfiability_comparisons':sum(z['faults'] for z in random_results),'details':random_results}}
    (ROOT/'checks').mkdir(exist_ok=True);(ROOT/'examples').mkdir(exist_ok=True)
    (ROOT/'checks/teaching_results.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    (ROOT/'examples/detection_matrix.json').write_text(json.dumps(result['cover']['matrix'],ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:v for k,v in result.items() if k not in ('cover','random_validation','diagnosis')},ensure_ascii=False,indent=2))
    print('Minimum cover:',result['cover']['minimum_count'], result['cover']['minimum_patterns'])
    print('Greedy cover:',result['cover']['greedy_count'], result['cover']['greedy_patterns'])
    print('Diagnostic classes:', result['diagnosis']['full_response_classes'],result['diagnosis']['pass_fail_classes'])
    print('Random SAT/exhaustive checks:',result['random_validation']['faults'])
if __name__=='__main__':main()
