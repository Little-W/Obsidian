#!/usr/bin/env python3
"""Small, exact MBIST teaching models. Python >= 3.10; standard library only.

These are synthetic examples, not commercial EDA, SPICE, or silicon results.
All intervals are half-open. Scheduling uses integer time and constant task power.
The exact scheduler permits idle time and enforces one active memory per controller.
"""
from __future__ import annotations
import argparse
import itertools
import json
import math
from dataclasses import asdict, dataclass
from functools import lru_cache
from pathlib import Path

@dataclass(frozen=True)
class Memory:
    name: str
    compatibility: str
    x: int
    y: int
    duration: int
    power: int

MEMORIES = (
    Memory('A', 'S1', 0, 0, 8, 5),
    Memory('B', 'S1', 2, 0, 5, 3),
    Memory('C', 'S1', 4, 0, 6, 4),
    Memory('D', 'S1', 6, 0, 3, 2),
    Memory('E', 'S2', 14, 0, 7, 4),
    Memory('F', 'S2', 16, 0, 4, 2),
)

def group_ok(group: tuple[int, ...], memories: tuple[Memory, ...], *,
             max_count: int = 3, max_distance: int = 6) -> bool:
    """Full pairwise distance, not centroid distance; no artificial group power cap.
    The selected hardware serves members serially, so global active-task power
    is checked by the scheduler, rather than summing all installed memories.
    """
    if not group or len(group) > max_count:
        return False
    if len({memories[i].compatibility for i in group}) != 1:
        return False
    return all(abs(memories[i].x-memories[j].x)+abs(memories[i].y-memories[j].y)
               <= max_distance for i, j in itertools.combinations(group, 2))

def partitions(memories: tuple[Memory, ...]):
    """Enumerate unlabeled feasible partitions without duplicate group permutations."""
    def rec(i: int, groups: tuple[tuple[int, ...], ...]):
        if i == len(memories):
            yield groups
            return
        for k, g in enumerate(groups):
            new = g + (i,)
            if group_ok(new, memories):
                yield from rec(i+1, groups[:k]+(new,)+groups[k+1:])
        yield from rec(i+1, groups+((i,),))
    yield from rec(0, ())

def exact_schedule(memories: tuple[Memory, ...], groups: tuple[tuple[int,...],...],
                   power_cap: int = 8, max_active_controllers: int = 2) -> dict:
    """Exact finite-state DP for <= 8 tasks with positive integer durations.

    There is one serial execution engine per controller, no start/readout
    overhead, and no precedence or thermal constraint. This does not claim
    optimality for continuous starts, phase-varying power, or other architectures.
    """
    n = len(memories)
    if not 1 <= n <= 8:
        raise ValueError('This exhaustive teaching model supports 1..8 tasks.')
    if power_cap <= 0 or max_active_controllers <= 0:
        raise ValueError('Resource capacities must be positive.')
    if sorted(i for g in groups for i in g) != list(range(n)):
        raise ValueError('Every memory must be assigned exactly once.')
    if any(type(m.duration) is not int or m.duration <= 0 or
           type(m.power) is not int or not 0 < m.power <= power_cap for m in memories):
        raise ValueError('Use positive integer durations and feasible positive powers.')
    owner = {i:k for k,g in enumerate(groups) for i in g}
    policy: dict[tuple, tuple[int,...]] = {}

    @lru_cache(None)
    def solve(unstarted: int, rem: tuple[int,...]) -> int:
        if unstarted == 0 and not any(rem):
            return 0
        active = [i for i,r in enumerate(rem) if r]
        busy = {owner[i] for i in active}
        power = sum(memories[i].power for i in active)
        ready = [i for i in range(n) if unstarted >> i & 1 and owner[i] not in busy]
        best, best_start = 10**9, ()
        for k in range(len(ready),-1,-1):
            for start in itertools.combinations(ready, k):
                if not active and not start:  # forbids a self-loop; useless empty idle
                    continue
                ctrls = [owner[i] for i in start]
                if len(set(ctrls)) != len(ctrls):
                    continue
                if len(busy)+len(ctrls) > max_active_controllers:
                    continue
                if power+sum(memories[i].power for i in start) > power_cap:
                    continue
                new_rem = list(rem)
                new_mask = unstarted
                for i in start:
                    new_rem[i] = memories[i].duration
                    new_mask &= ~(1 << i)
                next_rem = tuple(max(0, r-1) for r in new_rem)
                val = 1+solve(new_mask, next_rem)
                if val < best:
                    best, best_start = val, start
        policy[(unstarted, rem)] = best_start
        return best

    mask, rem = (1 << n)-1, (0,)*n
    makespan = solve(mask, rem)
    t, runs = 0, []
    while mask or any(rem):
        start = policy[(mask, rem)]
        nr = list(rem)
        for i in start:
            runs.append({'memory':memories[i].name, 'controller':owner[i],
                         'start':t, 'end':t+memories[i].duration,
                         'power_mW':memories[i].power})
            nr[i] = memories[i].duration
            mask &= ~(1 << i)
        rem = tuple(max(0, r-1) for r in nr)
        t += 1
        if t > sum(m.duration for m in memories):
            raise RuntimeError('Unexpected schedule reconstruction failure.')
    assert t == makespan
    for t in range(makespan):
        a = [r for r in runs if r['start'] <= t < r['end']]
        assert sum(r['power_mW'] for r in a) <= power_cap
        assert len({r['controller'] for r in a}) == len(a)
        assert len(a) <= max_active_controllers
    return {'makespan_us':makespan, 'runs':sorted(runs,key=lambda r:(r['start'],r['memory'])),
            'dp_states':solve.cache_info().currsize}

def profile_power(profile: list[tuple[float,float]], local_time: float) -> float:
    if local_time < 0:
        return 0.0
    offset = 0.0
    for duration, power in profile:
        if duration <= 0 or power < 0:
            raise ValueError('Each phase requires duration > 0, power >= 0.')
        if offset <= local_time < offset+duration:
            return power
        offset += duration
    return 0.0

def check_profiles(profiles: list[list[tuple[float,float]]], starts: list[float], cap: float) -> dict:
    """Exact breakpoint sweep for these piecewise-constant half-open profiles."""
    if len(profiles) != len(starts) or any(s < 0 for s in starts):
        raise ValueError('One nonnegative start time is required per profile.')
    points = {0.0}
    for profile, start in zip(profiles, starts):
        points.add(start)
        for duration,power in profile:
            if duration <= 0 or power < 0:
                raise ValueError('Invalid phase.')
            start += duration
            points.add(start)
    pts = sorted(points)
    intervals = []
    for left,right in zip(pts,pts[1:]):
        mid = (left+right)/2
        power = sum(profile_power(p,mid-s) for p,s in zip(profiles,starts))
        intervals.append({'start_us':left, 'end_us':right, 'power_mW':power})
    peak = max((x['power_mW'] for x in intervals),default=0.0)
    return {'valid':peak <= cap, 'peak_mW':peak, 'intervals':intervals,
            'energy_nJ':sum((x['end_us']-x['start_us'])*x['power_mW'] for x in intervals)}

def repair_exact(faults: set[tuple[int,int]], spare_rows: int, spare_cols: int):
    """All failed cells must be covered; row and column budgets are separate."""
    if spare_rows < 0 or spare_cols < 0:
        raise ValueError('Spare counts cannot be negative.')
    rows = sorted({r for r,c in faults})
    for nr in range(min(len(rows),spare_rows)+1):
        for chosen in itertools.combinations(rows,nr):
            columns = sorted({c for r,c in faults if r not in chosen})
            if len(columns) <= spare_cols:
                return {'rows':list(chosen), 'columns':columns}
    return None

def repair_greedy(faults: set[tuple[int,int]], spare_rows: int, spare_cols: int):
    """Deliberately simple baseline: maximum uncovered count, row-first ties."""
    remaining, trace = set(faults), []
    rows, cols = [], []
    while remaining:
        options = []
        if spare_rows:
            options.extend((sum(x==r for x,y in remaining),0,r)
                           for r in sorted({r for r,c in remaining}))
        if spare_cols:
            options.extend((sum(y==c for x,y in remaining),1,c)
                           for c in sorted({c for r,c in remaining}))
        if not options:
            return {'repairable':False, 'rows':rows, 'columns':cols,
                    'remaining':sorted(remaining), 'trace':trace}
        count,kind,k = min(options,key=lambda x:(-x[0],x[1],x[2]))
        trace.append({'kind':'row' if kind==0 else 'column','index':k,'covered':count})
        if kind==0:
            rows.append(k);spare_rows-=1
            remaining = {p for p in remaining if p[0]!=k}
        else:
            cols.append(k);spare_cols-=1
            remaining = {p for p in remaining if p[1]!=k}
    return {'repairable':True,'rows':rows,'columns':cols,'remaining':[],'trace':trace}

def run_all() -> dict:
    ps = list(partitions(MEMORIES))
    min_count = min(map(len,ps))
    candidates = [p for p in ps if len(p)==min_count]
    evaluated = []
    for p in candidates:
        sch = exact_schedule(MEMORIES,p)
        evaluated.append({'groups':[[MEMORIES[i].name for i in g] for g in p], **sch})
    best = min(evaluated,key=lambda e:e['makespan_us'])
    profiles = [[(2,6),(4,2)],[(4,2),(2,6)]]
    overlap = check_profiles(profiles,[0,0],8)
    serial = check_profiles(profiles,[0,6],8)
    unsafe = check_profiles([[(2,2),(2,7)],[(2,2),(2,7)]],[0,0],10)
    faults = {(0,0),(0,1),(1,0),(1,1),(2,2)}
    exact,greedy = repair_exact(faults,1,2),repair_greedy(faults,1,2)
    assert exact == {'rows':[2],'columns':[0,1]}
    assert not greedy['repairable']
    assert overlap['valid'] and overlap['peak_mW']==8
    assert overlap['energy_nJ'] == serial['energy_nJ'] == 40
    assert not unsafe['valid'] and unsafe['peak_mW']==14
    assert min_count == 3
    # 512 logical words each, but mismatched physical row/column-address loops.
    padding = {'memory_1':{'rows':128,'column_addresses':4},
               'memory_2':{'rows':32,'column_addresses':16},
               'separate_address_steps':128*4+32*16,
               'shared_nested_loop_steps':128*16}
    # Zero errors in n independent Bernoulli samples: one-sided 95% upper bound.
    n = 3000
    stats = {'zero_escape_samples':n,'upper_probability_95':1-math.pow(.05,1/n)}
    return {'notice':'Synthetic teaching examples; not EDA or silicon measurements.',
            'units':{'time':'us','power':'mW','energy':'nJ','distance':'arbitrary layout units'},
            'memories':[asdict(m) for m in MEMORIES],
            'grouping':{'max_count':3,'max_pairwise_manhattan_distance':6,
                        'feasible_partition_count':len(ps),'minimum_group_count':min_count,
                        'minimum_count_partition_count':len(candidates)},
            'serial_controller_scheduling':{'global_power_cap_mW':8,'max_active_controllers':2,
                                           'best_among_minimum_count_partitions':best,
                                           'all_minimum_count_partitions':evaluated},
            'phase_profiles':{'profiles':profiles,'overlap':overlap,'serial':serial,
                              'unsafe_start_only_check':unsafe},
            'repair':{'faults':sorted(faults),'row_spares':1,'column_spares':2,
                      'exact':exact,'greedy':greedy},
            'address_padding':padding,'statistical_example':stats,
            'tests':{'assertions':'passed','scope':'six fixed deterministic examples and schedule interval checks'}}

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--output',type=Path,default=Path(__file__).resolve().parents[1]/'examples'/'results.json')
    args = ap.parse_args()
    result = run_all()
    args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'output':str(args.output),'grouping':result['grouping'],
                      'best_schedule_us':result['serial_controller_scheduling']['best_among_minimum_count_partitions']['makespan_us'],
                      'repair':result['repair']['exact']},ensure_ascii=False,indent=2))

if __name__ == '__main__':
    main()
