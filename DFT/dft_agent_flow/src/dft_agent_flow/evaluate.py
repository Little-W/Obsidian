from __future__ import annotations

import json
from pathlib import Path
from typing import Any

from .config import EVALS_FILE
from .runner import FanRunner, Goal


def load_cases(path: Path = EVALS_FILE) -> list[dict[str, Any]]:
    return [json.loads(line) for line in path.read_text(encoding="utf-8").splitlines() if line.strip()]


def evaluate_executor(runner: FanRunner, path: Path = EVALS_FILE) -> dict[str, Any]:
    cases = load_cases(path)
    results = []
    for case in cases:
        outcome = runner.optimize(
            case["circuit"],
            Goal(min_coverage=case["min_coverage"], max_patterns=case.get("max_patterns")),
        )
        passed = outcome["objective_met"] and outcome["selected_profile"] == case["expected_profile"]
        results.append({"case_id": case["id"], "passed": passed, "outcome": outcome})
    return {"passed": sum(item["passed"] for item in results), "total": len(results), "results": results}
