#!/usr/bin/env python3
"""March C- word-level teaching model; not a Tessent/physical SRAM simulator."""
from __future__ import annotations
import argparse, csv, json
from dataclasses import dataclass
from pathlib import Path

@dataclass(frozen=True)
class Access:
    phase: str
    address: int
    op: str
    value: int

PHASES = (
    ("UP_INIT", 1, (("w", 0),)),
    ("UP_FLIP", 1, (("r", 0), ("w", 1))),
    ("UP_RESTORE", 1, (("r", 1), ("w", 0))),
    ("DOWN_FLIP", -1, (("r", 0), ("w", 1))),
    ("DOWN_RESTORE", -1, (("r", 1), ("w", 0))),
    ("DOWN_VERIFY", -1, (("r", 0),)),
)

def trace(depth: int, width: int) -> list[Access]:
    if not 1 <= depth <= 100000 or not 1 <= width <= 4096:
        raise ValueError("depth must be 1..100000; width must be 1..4096")
    ones = (1 << width) - 1
    result = []
    for phase, direction, operations in PHASES:
        addresses = range(depth) if direction == 1 else range(depth-1, -1, -1)
        for a in addresses:
            for op, bit in operations:
                result.append(Access(phase, a, op, ones if bit else 0))
    return result

def simulate(depth: int, width: int, fault: str = "none", address: int = 0,
             bit: int = 0) -> list[dict]:
    if fault not in {"none", "sa0", "sa1", "tf01", "tf10"}:
        raise ValueError(f"unsupported fault: {fault}")
    if not 0 <= address < depth or not 0 <= bit < width:
        raise ValueError("fault address/bit outside memory")
    accesses = trace(depth, width)
    mem = [0] * depth
    mask = 1 << bit
    if fault == "sa1":
        mem[address] |= mask
    errors = []
    for index, access in enumerate(accesses):
        a = access.address
        if access.op == "w":
            new = access.value
            if a == address:
                if fault == "sa0": new &= ~mask
                elif fault == "sa1": new |= mask
                elif fault == "tf01" and not mem[a] & mask and new & mask:
                    new &= ~mask
                elif fault == "tf10" and mem[a] & mask and not new & mask:
                    new |= mask
            mem[a] = new
        elif mem[a] != access.value:
            errors.append({"access": index, "phase": access.phase, "address": a,
                           "expected": access.value, "observed": mem[a]})
    return errors

def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--depth", type=int, default=16)
    ap.add_argument("--width", type=int, default=8)
    ap.add_argument("--out", type=Path, default=Path("results/march"))
    args = ap.parse_args()
    try:
        accesses = trace(args.depth, args.width)
        args.out.mkdir(parents=True, exist_ok=True)
        with (args.out / "trace.csv").open("w", newline="", encoding="utf-8") as f:
            w = csv.writer(f); w.writerow(["index", "phase", "address", "op", "value"])
            for i, a in enumerate(accesses):
                w.writerow([i, a.phase, a.address, a.op, hex(a.value)])
        summary = {"model": "word-level, fixed single-bit faults; no timing",
                   "depth": args.depth, "width": args.width,
                   "accesses": len(accesses), "expected_accesses": 10 * args.depth,
                   "fault_address": args.depth // 2, "fault_bit": 0, "faults": {}}
        for fault in ("none", "sa0", "sa1", "tf01", "tf10"):
            errors = simulate(args.depth, args.width, fault, args.depth // 2)
            summary["faults"][fault] = {"mismatches": len(errors),
                                        "first_error": errors[0] if errors else None}
        (args.out / "summary.json").write_text(json.dumps(summary, ensure_ascii=False, indent=2)+"\n", encoding="utf-8")
        print(json.dumps(summary, ensure_ascii=False, indent=2))
    except (ValueError, OSError) as exc:
        ap.exit(2, f"error: {exc}\n")

if __name__ == "__main__": main()
