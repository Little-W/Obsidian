#!/usr/bin/env python3
"""Run the handbook's executable examples and document checks.

The default command needs Python 3.10 or newer. --rebuild-html additionally
uses the documented Mistune, Node.js and MathJax dependencies.
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[1]

MODEL_CHECKS = [
    ("march_sequences", "validate_march_sequences.py", []),
    ("fault_detection", "fault_detection_examples.py", []),
    ("static_fault_models", "validate_static_fault_models.py", []),
    ("multirun_sequences", "validate_multirun_sequences.py", []),
    ("multirun_faults", "validate_multirun_faults.py", []),
    ("sequence_generation", "sequence_generation_examples.py", []),
    ("port_and_imc", "port_imc_examples.py", []),
    ("march_ic", "validate_march_ic.py", []),
    ("transparent_march", "transparent_march_examples.py", []),
    ("read_disturb_and_pause", "validate_read_disturb_and_pause.py", []),
    ("teaching_examples", "teaching_examples.py", []),
    ("trace_exports", "export_march_traces.py", ["--examples"]),
]


def run_one(name: str, command: list[str], timeout: float) -> dict:
    started = time.perf_counter()
    print(f"Running {name} ...", flush=True)
    try:
        result = subprocess.run(command, cwd=ROOT, capture_output=True,
                                text=True, encoding="utf-8", timeout=timeout)
        record = {"name": name, "command": [Path(command[0]).name, *command[1:]],
                  "elapsed_seconds": round(time.perf_counter() - started, 3),
                  "return_code": result.returncode, "passed": result.returncode == 0}
        if not record["passed"]:
            record["output"] = (result.stdout + "\n" + result.stderr)[-12000:]
            print(record["output"], file=sys.stderr)
    except subprocess.TimeoutExpired:
        record = {"name": name, "command": [Path(command[0]).name, *command[1:]],
                  "elapsed_seconds": round(time.perf_counter() - started, 3),
                  "passed": False, "reason": "timeout", "timeout_seconds": timeout}
    print(f"{name}: {'PASS' if record['passed'] else 'FAIL'}", flush=True)
    return record


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--models-only", action="store_true",
                        help="Run the digital examples and CSV exports only.")
    parser.add_argument("--rebuild-html", action="store_true",
                        help="Check formulas and regenerate HTML before static HTML checks.")
    parser.add_argument("--timeout", type=float, default=300,
                        help="Maximum seconds for each individual command.")
    args = parser.parse_args()
    if args.timeout <= 0:
        parser.error("--timeout must be greater than zero")
    if args.models_only and args.rebuild_html:
        parser.error("--models-only and --rebuild-html select different execution scopes")
    commands = [(name, [sys.executable, "src/" + script, *extra])
                for name, script, extra in MODEL_CHECKS]
    if not args.models_only:
        commands.append(("document_files", [sys.executable, "src/validate_handbook.py"]))
        if args.rebuild_html:
            commands.extend([
                ("mathjax", ["node", "src/check_mathjax.js"]),
                ("html_export", [sys.executable, "src/render_html.py"]),
                ("standalone_grouping_html", [sys.executable, "code/build_html.py"]),
            ])
        commands.append(("html_references", [sys.executable, "src/check_html.py", "--static-only"]))
    records = []
    destination = ROOT / "checks/run_checks_results.json"
    destination.parent.mkdir(exist_ok=True)
    destination.write_text(json.dumps({"status": "running", "expected_commands": len(commands)},
                                     indent=2) + "\n", encoding="utf-8")
    for name, command in commands:
        record = run_one(name, command, args.timeout)
        records.append(record)
        if not record["passed"]:
            break
    report = {
        "scope": "Digital examples and CSV export consistency" if args.models_only
                 else "Digital examples, CSV exports and local document consistency",
        "html_regenerated": bool(args.rebuild_html),
        "expected_commands": len(commands),
        "completed_commands": len(records),
        "passed": len(records) == len(commands) and all(r["passed"] for r in records),
        "checks": records,
    }
    destination.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({k: v for k, v in report.items() if k != "checks"}, ensure_ascii=False, indent=2))
    raise SystemExit(0 if report["passed"] else 1)


if __name__ == "__main__":
    main()
