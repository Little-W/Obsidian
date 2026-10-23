#!/usr/bin/env python3
"""Power-limited synchronized Step partitioning within EXISTING controllers.
The cost sum(max(time_i)) is an explicit simplified model, not a universal
Tessent cycle estimator. No bank, pipeline, row/column-counter or repair cost.
"""
from __future__ import annotations
import argparse, csv, json, math, re
from dataclasses import dataclass
from functools import lru_cache
from pathlib import Path

@dataclass(frozen=True)
class Memory:
    name: str
    controller: str
    clock: str
    macro: str
    operation_set: str
    algorithm: str
    x_um: float
    y_um: float
    power_mw: float
    time_us: float

@dataclass(frozen=True)
class Limits:
    power_mw: float = 60
    count: int = 4
    hpwl_um: float = 200

NAME = re.compile(r"^[A-Za-z_][A-Za-z0-9_./\[\]-]*$")

def load_memories(path: Path) -> list[Memory]:
    with path.open(newline="", encoding="utf-8-sig") as f:
        raw = list(csv.DictReader(f))
    if not raw: raise ValueError("empty memory input")
    memories = []
    seen = set()
    for row in raw:
        values = {k: row[k] for k in ("name", "controller", "clock", "macro", "operation_set", "algorithm")}
        if any(not v or not NAME.fullmatch(v) for v in values.values()):
            raise ValueError(f"unsupported identifier in row: {row}")
        if values["name"] in seen: raise ValueError("duplicate memory: " + values["name"])
        seen.add(values["name"])
        nums = {k: float(row[k]) for k in ("x_um", "y_um", "power_mw", "time_us")}
        if any(not math.isfinite(v) for v in nums.values()): raise ValueError("nonfinite numeric input")
        if nums["power_mw"] <= 0 or nums["time_us"] <= 0: raise ValueError("power/time must be positive")
        memories.append(Memory(**values, **nums))
    return memories

def hpwl(group: list[Memory]) -> float:
    if not group: return 0.0
    return max(m.x_um for m in group)-min(m.x_um for m in group) + max(m.y_um for m in group)-min(m.y_um for m in group)

def feasible(group: list[Memory], limits: Limits) -> bool:
    # Exact macro equality is a deliberately stricter demonstration rule.
    if not group or len(group) > limits.count: return False
    attributes = {(m.controller, m.clock, m.macro, m.operation_set, m.algorithm) for m in group}
    return (len(attributes) == 1 and sum(m.power_mw for m in group) <= limits.power_mw + 1e-9
            and hpwl(group) <= limits.hpwl_um + 1e-9)

def validate_input(memories: list[Memory], limits: Limits) -> None:
    if not math.isfinite(limits.power_mw) or not math.isfinite(limits.hpwl_um):
        raise ValueError("nonfinite limits")
    if limits.power_mw <= 0 or limits.hpwl_um < 0 or limits.count <= 0:
        raise ValueError("invalid limits")
    for m in memories:
        if not feasible([m], limits): raise ValueError("singleton infeasible: " + m.name)

def greedy(memories: list[Memory], limits: Limits) -> list[list[Memory]]:
    validate_input(memories, limits)
    groups: list[list[Memory]] = []
    for m in sorted(memories, key=lambda x: (-x.power_mw, -x.time_us, x.name)):
        candidates = [(hpwl(g+[m])-hpwl(g), limits.power_mw-sum(x.power_mw for x in g)-m.power_mw, i)
                      for i,g in enumerate(groups) if feasible(g+[m], limits)]
        if candidates: groups[min(candidates)[2]].append(m)
        else: groups.append([m])
    return groups

def exact(memories: list[Memory], limits: Limits) -> list[list[Memory]]:
    validate_input(memories, limits)
    if not 1 <= len(memories) <= 16:
        raise ValueError("exact demonstration is restricted to 1..16 memories")
    n = len(memories)
    valid = {}
    for mask in range(1, 1 << n):
        g = [memories[i] for i in range(n) if mask >> i & 1]
        if feasible(g, limits): valid[mask] = (max(m.time_us for m in g), 1, hpwl(g))
    @lru_cache(None)
    def solve(mask: int):
        if not mask: return (0.0, 0, 0.0), ()
        anchor = mask & -mask
        best = None
        sub = mask
        while sub:
            if sub & anchor and sub in valid:
                rest, partition = solve(mask ^ sub)
                cost = tuple(a+b for a,b in zip(rest, valid[sub]))
                candidate = cost, (sub,) + partition
                if best is None or candidate < best: best = candidate
            sub = (sub - 1) & mask
        if best is None: raise ValueError("no feasible partition")
        return best
    _, masks = solve((1 << n)-1)
    return [[memories[i] for i in range(n) if mask >> i & 1] for mask in masks]

def audit(memories: list[Memory], groups: list[list[Memory]], limits: Limits) -> dict:
    expected = {m.name for m in memories}
    actual = [m.name for g in groups for m in g]
    if len(actual) != len(set(actual)) or set(actual) != expected:
        raise ValueError("missing, unknown or duplicate memory in plan")
    if any(not feasible(g, limits) for g in groups): raise ValueError("illegal step")
    controller_times = {}
    for g in groups:
        cid = g[0].controller
        controller_times[cid] = controller_times.get(cid, 0.0) + max(m.time_us for m in g)
    return {"steps": len(groups), "controller_time_us": controller_times,
            "largest_step_power_mw": max(sum(m.power_mw for m in g) for g in groups),
            "sum_hpwl_um": sum(hpwl(g) for g in groups),
            "chip_time_us": None,
            "note": "Chip-wide concurrency/power scheduling has NOT been solved."}

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("input", type=Path)
    ap.add_argument("--method", choices=("greedy","exact"), default="greedy")
    ap.add_argument("--power", type=float, default=60)
    ap.add_argument("--count", type=int, default=4)
    ap.add_argument("--hpwl", type=float, default=200)
    ap.add_argument("--out", type=Path, required=True)
    args=ap.parse_args()
    try:
        memories=load_memories(args.input); limits=Limits(args.power,args.count,args.hpwl)
        validate_input(memories, limits)
        groups=[]
        for cid in sorted({m.controller for m in memories}):
            subset=[m for m in memories if m.controller==cid]
            groups += (greedy if args.method=="greedy" else exact)(subset,limits)
        summary=audit(memories,groups,limits)
        plan={cid:[[m.name for m in g] for g in groups if g[0].controller==cid]
              for cid in sorted({m.controller for m in memories})}
        args.out.mkdir(parents=True,exist_ok=True)
        (args.out/"steps_plan.json").write_text(json.dumps(plan,indent=2)+"\n",encoding="utf-8")
        (args.out/"summary.json").write_text(json.dumps(summary,indent=2)+"\n",encoding="utf-8")
        # Controller tags do not specify the Step partition; emit only existing controller boundaries.
        with (args.out/"controller_boundaries.tcl").open("w",encoding="utf-8") as f:
            f.write("# Different labels prohibit sharing; same label does NOT force a single controller.\n")
            for cid in sorted(plan):
                names=" ".join(m.name for m in memories if m.controller==cid)
                f.write(f"set_memory_instance_options {{{names}}} -partitioning_group {cid}\n")
        print(json.dumps(summary,indent=2))
    except (OSError, ValueError, KeyError) as exc: ap.exit(2,f"error: {exc}\n")

if __name__=="__main__": main()
