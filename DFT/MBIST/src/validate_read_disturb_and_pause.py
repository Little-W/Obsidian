#!/usr/bin/env python3
"""Check read disturbance, transparent-test pauses and whole-word coupling.

Read disturbance is an explicit deterministic teaching model. Transparent
sequences reuse transparent_march_examples.py and its CRC definition.
"""
from __future__ import annotations

from itertools import product
import json
from pathlib import Path

from transparent_march_examples import double_addresses, run, signature

ROOT = Path(__file__).resolve().parents[1]


def read_disturb_case(value: int, stress_reads: int,
                      disturb_on_observation: bool = False) -> dict:
    """A selected read returns the old bit and then flips the stored bit."""
    assert value in (0, 1) and stress_reads >= 1
    memory = value
    trace = [{"step": 1, "phase": "initialize", "operation": f"w{value}",
              "state_after": memory}]
    for index in range(1, stress_reads + 1):
        actual = memory
        before = memory
        if index == stress_reads and not disturb_on_observation:
            memory ^= 1
        trace.append({"step": index + 1, "phase": "stress", "stress_index": index,
                      "operation": f"r{value}", "expected": value, "actual": actual,
                      "state_before": before, "state_after": memory,
                      "mismatch": actual != value})
    stress_detected = any(t.get("mismatch", False) for t in trace)
    before = actual = memory
    if disturb_on_observation:
        memory ^= 1
    trace.append({"step": stress_reads + 2, "phase": "observe",
                  "operation": f"r{value}", "expected": value, "actual": actual,
                  "state_before": before, "state_after": memory,
                  "mismatch": actual != value})
    assert not stress_detected
    assert trace[-1]["mismatch"] == (not disturb_on_observation)
    return {"initial_value": value, "K": stress_reads,
            "stress_only_detected": stress_detected,
            "with_observation_detected": trace[-1]["mismatch"],
            "disturb_on_observation": disturb_on_observation, "trace": trace}


def word_coupling_case() -> dict:
    """bit0=1 inhibits a 0-to-1 transition of bit1 in an eight-bit word."""
    operations = [("w", 0x00), ("w", 0x01), ("r", 0x01), ("w", 0x03), ("r", 0x03)]
    healthy = faulty = None
    trace = []
    for step, (operation, value) in enumerate(operations, 1):
        before = faulty
        activated = False
        if operation == "w":
            healthy = value
            activated = (faulty is not None and bool(faulty & 1)
                         and not bool(faulty & 2) and bool(value & 2))
            faulty = value & ~2 if activated else value
            mismatch = False
        else:
            assert healthy == value
            mismatch = faulty != value
        trace.append({"step": step, "operation": operation, "data": value,
                      "faulty_before": before, "faulty_after": faulty,
                      "healthy_after": healthy, "activated": activated,
                      "read_mismatch": mismatch})
    assert trace[3]["activated"] and trace[4]["read_mismatch"]
    assert trace[4]["data"] == 0x03 and trace[4]["faulty_after"] == 0x01
    return {"word_width": 8, "aggressor_bit": 0, "victim_bit": 1,
            "first_error_step": 5, "trace": trace, "passed": True}


def release_allowed(parity: list[int], pending_reads: int,
                    local_failure: bool, signature_checked: bool,
                    signature_matches: bool) -> bool:
    return (not any(parity) and pending_reads == 0 and not local_failure
            and signature_checked and signature_matches)


def validate_pause_conditions() -> dict:
    runs = block_ends = restored_ends = 0
    for gray, removed, initial, variant in product(
            (False, True), range(3), product((0, 1), repeat=4), (1, 2)):
        order = double_addresses(4, removed, gray)
        result = run(list(initial), order, variant, capture=True)
        parity = [0] * 4
        for item in result["trace"]:
            if item["operation"] != "read_compare":
                continue
            parity[item["address"]] ^= 1
            restored = item["memory_after"] == list(initial)
            assert restored == (not any(parity))
            block_ends += 1
            restored_ends += int(restored)
        assert release_allowed(parity, 0, False, True, not result["signature_mismatch"])
        assert not release_allowed(parity, 1, False, True, True)
        assert not release_allowed(parity, 0, True, True, True)
        assert not release_allowed(parity, 0, False, False, True)
        runs += 1

    initial = [0, 1, 0, 1]
    order = double_addresses(4, 2)
    example = run(initial, order, 2, capture=True)
    block_records = [item for item in example["trace"] if item["operation"] == "read_compare"]
    assert block_records[3]["memory_after"] == [1, 0, 1, 0]
    assert block_records[7]["memory_after"] == initial

    changed_by_host = [0, 0, 0, 1]
    resumed = run(changed_by_host, list(reversed(order)), 1)
    original_signature = signature(initial)
    assert resumed["restored"] and not resumed["detected"]
    assert original_signature != resumed["final_signature"]
    restarted = run(changed_by_host, order, 2)
    assert restarted["restored"] and not restarted["detected"]

    return {
        "fault_free_runs": runs, "completed_blocks_checked": block_ends,
        "restored_block_ends": restored_ends,
        "conditions": "Complete operation block, no pending read response, no local failure, restored data, completed and matching final signature; host writes require a new reference scan.",
        "example": {"initial": initial,
                    "after_four_blocks": block_records[3]["memory_after"],
                    "after_eight_blocks": block_records[7]["memory_after"],
                    "host_updated_data": changed_by_host,
                    "old_reference_signature": original_signature,
                    "signature_after_host_write": resumed["final_signature"],
                    "restart_reference_signature": restarted["reference_signature"],
                    "restart_final_signature": restarted["final_signature"]},
        "passed": True,
    }


def main() -> None:
    cases = [read_disturb_case(value, count) for value in (0, 1) for count in range(1, 65)]
    pauses = validate_pause_conditions()
    report = {
        "scope": "Specified delayed-read and whole-word digital models, and fault-free transparent-sequence state checks; no analog timing model.",
        "delayed_read_cases": len(cases),
        "delayed_read_cases_detected": sum(c["with_observation_detected"] for c in cases),
        "read_disturb_example": read_disturb_case(0, 4),
        "observation_read_disturb_example": read_disturb_case(0, 4, True),
        "transparent_pause": pauses,
        "word_coupling": word_coupling_case(),
        "passed": True,
    }
    destination = ROOT / "examples/read_disturb_and_pause_results.json"
    destination.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"passed": report["passed"], "delayed_read_cases": len(cases),
                      "transparent_runs": pauses["fault_free_runs"],
                      "block_ends_checked": pauses["completed_blocks_checked"]},
                     ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
