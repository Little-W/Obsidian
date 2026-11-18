#!/usr/bin/env python3
"""Executable finite-state memory fault examples for chapters 02 and 04.

All faults here have explicit digital semantics. Each coverage experiment injects
one primitive at a time; linked examples inject two named inversion events.
The model has no voltage, delay, probability, ECC, or transistor parameters.
"""
from __future__ import annotations

from collections import defaultdict
from dataclasses import dataclass
from itertools import product
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


@dataclass(frozen=True)
class Fault:
    kind: str
    target: int
    polarity: int = 0
    aggressor: int = -1
    forced: int = 0
    second_aggressor: int = -1


def simulate(operations, initial, fault=None, collect=False):
    """Return mismatching reads and optional operation-by-operation state.

    RDF returns the corrupted bit during its activating read. DRDF returns the
    old bit and corrupts storage after producing that result. D2R requires two
    consecutive reads to the same address while it contains the specified bit;
    an intervening write or other-address access resets its counter.
    """
    memory = list(initial)
    trace, failures = [], []
    read_streak = 0
    previous_read_address = None
    if fault and fault.kind == 'SAF':
        memory[fault.target] = fault.polarity
    if fault and fault.kind == 'CFst' and memory[fault.aggressor] == fault.polarity:
        memory[fault.target] = fault.forced
    for step, (address, operation) in enumerate(operations, 1):
        op, value = operation[0], int(operation[1])
        before = memory.copy()
        old = memory[address]
        actual = None
        if op == 'w':
            memory[address] = value
            read_streak, previous_read_address = 0, None
        elif op == 'r':
            read_streak = read_streak + 1 if previous_read_address == address else 1
            previous_read_address = address
            actual = old
        else:
            raise ValueError(operation)
        if fault:
            f = fault
            if address == f.target:
                if f.kind == 'SAF':
                    memory[address] = f.polarity
                    if op == 'r':
                        actual = f.polarity
                elif f.kind == 'TF' and op == 'w' and old != value and value == f.polarity:
                    memory[address] = old
                elif f.kind == 'WDF' and op == 'w' and old == value == f.polarity:
                    memory[address] = 1 - old
                elif f.kind == 'IRF' and op == 'r' and old == f.polarity:
                    actual = 1 - old
                elif f.kind == 'RDF' and op == 'r' and old == f.polarity:
                    memory[address] = 1 - old
                    actual = 1 - old
                elif f.kind == 'DRDF' and op == 'r' and old == f.polarity:
                    memory[address] = 1 - old
                elif f.kind == 'D2R' and op == 'r' and old == f.polarity and read_streak == 2:
                    memory[address] = 1 - old
            if f.kind in ('CFin', 'CFid', 'LINKED'):
                aggressors = (f.aggressor, f.second_aggressor) if f.kind == 'LINKED' else (f.aggressor,)
                if address in aggressors and op == 'w' and old != value and value == f.polarity:
                    memory[f.target] = f.forced if f.kind == 'CFid' else 1 - memory[f.target]
            if f.kind == 'CFst' and memory[f.aggressor] == f.polarity:
                memory[f.target] = f.forced
                if address == f.target and op == 'r':
                    actual = f.forced
        mismatch = op == 'r' and actual != value
        if mismatch:
            failures.append({'step': step, 'address': address, 'expected': value, 'actual': actual})
        if collect:
            trace.append({'step': step, 'address': address, 'operation': operation,
                          'before': before, 'after': memory.copy(), 'returned': actual,
                          'expected': value if op == 'r' else None, 'mismatch': mismatch})
    return {'detected': bool(failures), 'first_failure': failures[0] if failures else None,
            'final_memory': memory, 'trace': trace}


def examples():
    definitions = [
        ('SAF0', [(0,'w1'),(0,'r1')], [0], Fault('SAF',0,0), 2),
        ('TF_up', [(0,'w0'),(0,'w1'),(0,'r1')], [1], Fault('TF',0,1), 3),
        ('WDF0', [(0,'w1'),(0,'w0'),(0,'w0'),(0,'r0')], [0], Fault('WDF',0,0), 4),
        ('RDF0', [(0,'w0'),(0,'r0')], [1], Fault('RDF',0,0), 2),
        ('IRF0', [(0,'w0'),(0,'r0')], [1], Fault('IRF',0,0), 2),
        ('DRDF0', [(0,'w0'),(0,'r0'),(0,'r0')], [1], Fault('DRDF',0,0), 3),
        ('DRDF0_single_read', [(0,'w0'),(0,'r0')], [1], Fault('DRDF',0,0), None),
        ('D2R0', [(0,'w0'),(0,'r0'),(0,'r0'),(0,'r0')], [1], Fault('D2R',0,0), 4),
        ('D2R0_two_reads', [(0,'w0'),(0,'r0'),(0,'r0')], [1], Fault('D2R',0,0), None),
        ('D2R0_interrupted', [(0,'w0'),(0,'r0'),(1,'w0'),(0,'r0'),(0,'r0')], [1,1], Fault('D2R',0,0), None),
        ('CFin_up', [(0,'w0'),(1,'w0'),(0,'w1'),(1,'r0')], [1,1], Fault('CFin',1,1,0), 4),
        ('CFin_overwritten', [(0,'w0'),(1,'w0'),(0,'w1'),(1,'w0'),(1,'r0')], [1,1], Fault('CFin',1,1,0), None),
        ('LINKED_masked', [(0,'w0'),(1,'w0'),(2,'w0'),(0,'w1'),(1,'w1'),(2,'r0')], [1,1,1], Fault('LINKED',2,1,0,0,1), None),
        ('LINKED_observed', [(0,'w0'),(1,'w0'),(2,'w0'),(0,'w1'),(2,'r0'),(1,'w1'),(2,'r0')], [1,1,1], Fault('LINKED',2,1,0,0,1), 5),
    ]
    output = []
    for name, ops, initial, fault, expected_step in definitions:
        healthy = simulate(ops, initial, collect=True)
        faulty = simulate(ops, initial, fault, collect=True)
        assert not healthy['detected'], (name, healthy)
        observed_step = faulty['first_failure']['step'] if faulty['first_failure'] else None
        assert observed_step == expected_step, (name, observed_step, expected_step)
        output.append({'name': name, 'fault': fault.__dict__, 'initial': initial,
                       'expected_first_failure_step': expected_step, 'healthy': healthy,
                       'faulty': faulty, 'passed': True})
    # Mirror each single-cell example to verify both bit polarities independently.
    mirror_count = 0
    for name, ops, initial, fault, expected_step in definitions:
        if len(initial) != 1:
            continue
        mirrored_ops = [(a, op[0] + str(1-int(op[1]))) for a, op in ops]
        mirrored = Fault(fault.kind, fault.target, 1-fault.polarity)
        result = simulate(mirrored_ops, [1-x for x in initial], mirrored)
        actual_step = result['first_failure']['step'] if result['first_failure'] else None
        assert actual_step == expected_step, name
        mirror_count += 1
    return output, mirror_count


def primitives(n):
    for kind in ('SAF','TF','WDF','IRF','RDF','DRDF','D2R'):
        for target, bit in product(range(n), (0,1)):
            yield Fault(kind, target, bit)
    for a, v in product(range(n), repeat=2):
        if a == v:
            continue
        for bit in (0,1):
            yield Fault('CFin',v,bit,a)
            for forced in (0,1):
                yield Fault('CFid',v,bit,a,forced)
                yield Fault('CFst',v,bit,a,forced)


def march_coverage(n=3):
    """Enumerate all initial states, address assignments, and allowed directions.

    A primitive is counted as guaranteed within this experiment only when every
    tested initial state and direction assignment produces an incorrect read.
    This finite experiment is deliberately separate from literature coverage.
    """
    from validate_march_sequences import extract
    all_faults = list(primitives(n))
    results = []
    for name, line, label, elements, block in extract():
        arbitrary_count = sum(direction == '⇕' for direction,_ in elements)
        healthy_runs, faulty_runs = 0, 0
        success = {fault: True for fault in all_faults}
        first_missed = {}
        for directions in product(('↑','↓'), repeat=arbitrary_count):
            choices = iter(directions)
            ops = []
            for direction, operations in elements:
                if direction == '⇕':
                    direction = next(choices)
                addresses = range(n) if direction == '↑' else range(n-1,-1,-1)
                ops.extend((address,op) for address in addresses for op in operations)
            for initial in product((0,1), repeat=n):
                assert not simulate(ops,initial)['detected'], (label, initial)
                healthy_runs += 1
                for fault in all_faults:
                    detected = simulate(ops,initial,fault)['detected']
                    success[fault] = success[fault] and detected
                    faulty_runs += 1
                    if not detected and fault.kind not in first_missed:
                        first_missed[fault.kind] = {'primitive':fault.__dict__, 'initial':initial,
                                                   'arbitrary_directions':directions}
        by_kind = defaultdict(lambda: {'detected_in_all_tested_settings':0,'primitive_count':0})
        for fault, detected in success.items():
            by_kind[fault.kind]['primitive_count'] += 1
            by_kind[fault.kind]['detected_in_all_tested_settings'] += int(detected)
        results.append({'source':name,'line':line,'label':label,'sequence':block,
                        'operations_per_address':sum(len(ops) for _,ops in elements),
                        'memory_size':n,'healthy_runs':healthy_runs,'faulty_runs':faulty_runs,
                        'digital_model_coverage':dict(by_kind),'missed_examples':first_missed})
    assert results
    return results


def main():
    episodes, mirror_count = examples()
    coverage = march_coverage()
    result = {
        'scope':'Finite digital fault models defined in this source; N=3 enumeration; one primitive per coverage run. Linked masking is demonstrated separately.',
        'literature_coverage_claim':False,
        'example_count':len(episodes), 'mirrored_example_count':mirror_count,
        'march_sequence_count':len(coverage),
        'healthy_run_count':sum(x['healthy_runs'] for x in coverage),
        'fault_injection_run_count':sum(x['faulty_runs'] for x in coverage),
        'examples':episodes, 'march_experiments':coverage, 'passed':True,
    }
    path = ROOT/'examples/fault_detection_results.json'
    path.parent.mkdir(exist_ok=True)
    path.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:v for k,v in result.items() if k not in ('examples','march_experiments')},ensure_ascii=False,indent=2))


if __name__ == '__main__':
    main()
