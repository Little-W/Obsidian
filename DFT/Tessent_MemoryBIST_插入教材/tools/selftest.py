#!/usr/bin/env python3
"""Offline algorithm/configuration tests. These DO NOT execute Tessent."""
from __future__ import annotations
import itertools, json, random, re, unittest
from pathlib import Path
from march_reference import trace, simulate, PHASES
from grouping_demo import Memory, Limits, load_memories, greedy, exact, audit, feasible, hpwl
from config_steps import parse, controllers, step_members, rewrite
ROOT=Path(__file__).resolve().parents[1]

class MarchTests(unittest.TestCase):
    def test_count(self):
        for n in (1,2,4,16,31): self.assertEqual(len(trace(n,8)),10*n)
    def test_directions(self):
        data=trace(4,1)
        for phase,direction,_ in PHASES:
            addrs=list(dict.fromkeys(a.address for a in data if a.phase==phase))
            self.assertEqual(addrs,list(range(4)) if direction==1 else list(range(3,-1,-1)))
    def test_faultfree(self): self.assertEqual(simulate(16,8),[])
    def test_all_single_bit_fault_sites(self):
        for fault,address,bit in itertools.product(('sa0','sa1','tf01','tf10'),range(16),range(8)):
            self.assertTrue(simulate(16,8,fault,address,bit),(fault,address,bit))
    def test_bad_input(self):
        for n,w in ((0,8),(2,0),(-1,8)):
            with self.assertRaises(ValueError): trace(n,w)
    def test_uda_structure(self):
        text=(ROOT/'algorithms/lab_march_cminus.tcd_mem_lib').read_text()
        self.assertEqual(text.count('Instruction('),6)
        self.assertEqual(text.count('inhibit_last_address_count : on;'),1)
        parse(text)

class GroupTests(unittest.TestCase):
    def setUp(self):
        self.ms=load_memories(ROOT/'examples/memories.csv'); self.lim=Limits()
    def test_demo(self):
        g=greedy(self.ms,self.lim); e=exact(self.ms,self.lim)
        self.assertEqual(audit(self.ms,g,self.lim)['steps'],3)
        self.assertEqual(audit(self.ms,e,self.lim)['steps'],2)
    def test_duplicate_missing(self):
        for bad in ([[self.ms[0]]], [[self.ms[0]]]*6):
            with self.assertRaises(ValueError): audit(self.ms,bad,self.lim)
    def test_overpower(self): self.assertFalse(feasible(self.ms,self.lim))
    def test_incompatible(self):
        a=self.ms[0]; b=Memory('x','c2',a.clock,a.macro,a.operation_set,a.algorithm,0,0,1,1)
        self.assertFalse(feasible([a,b],Limits(100,10,100)))
    def test_small_random_against_independent_enumerator(self):
        # Independent Bell-partition recursion, not the bitmask DP recurrence.
        rng=random.Random(1729)
        for case in range(20):
            n=rng.randint(2,7)
            ms=[Memory('m'+str(i),'c1','clk','macro','op','alg',0,0,rng.randint(1,10),rng.randint(1,8)) for i in range(n)]
            lim=Limits(12,4,100)
            best=None
            def enumerate_all(index,groups):
                nonlocal best
                if index==n:
                    c=(sum(max(m.time_us for m in g) for g in groups),len(groups),sum(hpwl(g) for g in groups))
                    if best is None or c<best: best=c
                    return
                for i,g in enumerate(groups):
                    if feasible(g+[ms[index]],lim):
                        groups[i].append(ms[index]); enumerate_all(index+1,groups); groups[i].pop()
                groups.append([ms[index]]); enumerate_all(index+1,groups); groups.pop()
            enumerate_all(0,[])
            ans=exact(ms,lim)
            cost=(sum(max(m.time_us for m in g) for g in ans),len(ans),sum(hpwl(g) for g in ans))
            self.assertEqual(cost,best,case)
    def test_infeasible_singleton(self):
        with self.assertRaises(ValueError): greedy(self.ms,Limits(1,4,200))

class EditorTests(unittest.TestCase):
    def setUp(self):
        self.src=(ROOT/'examples/auto_synthetic.dft_spec').read_text()
        self.plan={'c1':[['u_mem0','u_mem3','u_mem4'],['u_mem1','u_mem2','u_mem5']]}
    def test_rewrite(self):
        out=rewrite(self.src,self.plan)
        self.assertEqual(step_members(controllers(out)['c1']),self.plan['c1'])
        self.assertIn('IjtagNetwork',out); self.assertIn('algorithm : LabMarchCMinus;',out)
    def test_detailed_interface_preserved(self):
        src=self.src.replace('instance_name : u_mem0;','instance_name : u_mem0;\n          ExtraOptions { note : "{keep}"; }')
        out=rewrite(src,self.plan)
        self.assertIn('note : "{keep}";',out)
    def test_duplicate_plan(self):
        with self.assertRaises(ValueError): rewrite(self.src,{'c1':[['u_mem0']*6]})
    def test_missing_plan(self):
        with self.assertRaises(ValueError): rewrite(self.src,{'c1':[['u_mem0']]})
    def test_unknown_controller(self):
        with self.assertRaises(ValueError): rewrite(self.src,{'c9':[['u_mem0']]})
    def test_step_property_guard(self):
        src=self.src.replace('Step {','Step { extra_setting : on;',1)
        with self.assertRaises(ValueError): rewrite(src,self.plan)
    def test_bad_braces(self):
        with self.assertRaises(ValueError): parse(self.src[:-3])
    def test_no_empty_groups(self):
        with self.assertRaises(ValueError): rewrite(self.src,{'c1':[[]]})
    def test_interface_path(self):
        src=self.src.replace('u_mem0','core/bank[0]/mem')
        plan={'c1':[['core/bank[0]/mem','u_mem3','u_mem4'],['u_mem1','u_mem2','u_mem5']]}
        out=rewrite(src,plan)
        self.assertEqual(step_members(controllers(out)['c1']),plan['c1'])

if __name__=='__main__': unittest.main(verbosity=2)
