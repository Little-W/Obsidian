from __future__ import annotations

import json
import re
import subprocess
import uuid
from dataclasses import asdict, dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

from .config import AUDIT_LOG, FAN_BINARY, FAN_ROOT, PROFILES, RUNS_ROOT, available_circuits


class FlowValidationError(ValueError):
    """Raised when a request falls outside the approved experiment surface."""


@dataclass(frozen=True)
class Goal:
    min_coverage: float = 0.0
    max_patterns: int | None = None

    def validate(self) -> None:
        if not 0.0 <= self.min_coverage <= 100.0:
            raise FlowValidationError("min_coverage must be between 0 and 100")
        if self.max_patterns is not None and self.max_patterns < 1:
            raise FlowValidationError("max_patterns must be at least 1 when supplied")


@dataclass(frozen=True)
class AtpgMetrics:
    circuit: str
    profile: str
    test_coverage: float
    fault_coverage: float
    patterns: int
    runtime_seconds: float


@dataclass(frozen=True)
class RunResult:
    run_id: str
    run_dir: str
    return_code: int
    success: bool
    metrics: AtpgMetrics | None
    stdout_file: str
    stderr_file: str
    report_file: str
    error: str | None = None


def _now() -> str:
    return datetime.now(timezone.utc).isoformat(timespec="seconds")


def _safe_identifier(value: str, kind: str, allowed: tuple[str, ...] | dict[str, Any]) -> str:
    if value not in allowed:
        choices = ", ".join(sorted(allowed))
        raise FlowValidationError(f"Unsupported {kind} '{value}'. Allowed: {choices}")
    return value


def parse_report(text: str, circuit: str, profile: str) -> AtpgMetrics:
    def find_float(label: str) -> float:
        match = re.search(rf"{label}\s+([0-9]+(?:\.[0-9]+)?)%", text, re.IGNORECASE)
        if not match:
            raise FlowValidationError(f"FAN report does not contain {label}")
        return float(match.group(1))

    patterns = re.search(r"#Patterns\s+([0-9]+)", text, re.IGNORECASE)
    runtime = re.search(
        r"ATPG runtime\s+([0-9]+(?:\.[0-9]+)?(?:[eE][+-]?[0-9]+)?)\s+s",
        text,
        re.IGNORECASE,
    )
    if not patterns or not runtime:
        raise FlowValidationError("FAN report is missing pattern count or runtime")
    return AtpgMetrics(
        circuit=circuit,
        profile=profile,
        test_coverage=find_float("test coverage"),
        fault_coverage=find_float("fault coverage"),
        patterns=int(patterns.group(1)),
        runtime_seconds=float(runtime.group(1)),
    )


class FanRunner:
    """Runs only verified FAN_ATPG configurations in isolated artifact directories."""

    def __init__(self, timeout_seconds: int = 900) -> None:
        self.timeout_seconds = timeout_seconds

    def inspect(self, circuit: str) -> dict[str, Any]:
        circuit = _safe_identifier(circuit, "circuit", available_circuits())
        netlist = FAN_ROOT / "mod_netlist" / f"{circuit}.v"
        return {
            "circuit": circuit,
            "netlist": str(netlist),
            "netlist_bytes": netlist.stat().st_size,
            "profiles": sorted(PROFILES),
            "source_is_read_only": True,
        }

    def run(self, circuit: str, profile: str) -> RunResult:
        circuit = _safe_identifier(circuit, "circuit", available_circuits())
        profile = _safe_identifier(profile, "profile", PROFILES)
        if not FAN_BINARY.is_file():
            raise FileNotFoundError(f"FAN binary not found: {FAN_BINARY}")

        run_id = f"{datetime.now(timezone.utc):%Y%m%dT%H%M%SZ}_{circuit}_{profile}_{uuid.uuid4().hex[:8]}"
        run_dir = RUNS_ROOT / run_id
        run_dir.mkdir(parents=True, exist_ok=False)
        self._link_input_tree(run_dir)

        script_file = run_dir / "atpg.script"
        script_file.write_text("\n".join(self._script_lines(circuit, profile)) + "\n", encoding="utf-8")
        stdout_file = run_dir / "fan.stdout.log"
        stderr_file = run_dir / "fan.stderr.log"
        report_file = run_dir / "report.rpt"

        try:
            process = subprocess.run(
                [str(FAN_BINARY), "-f", str(script_file.name)],
                cwd=run_dir,
                text=True,
                capture_output=True,
                timeout=self.timeout_seconds,
                check=False,
            )
            stdout_file.write_text(process.stdout, encoding="utf-8")
            stderr_file.write_text(process.stderr, encoding="utf-8")
            error = None
            metrics = None
            if process.returncode != 0:
                error = f"FAN exited with status {process.returncode}"
            elif not report_file.is_file():
                error = "FAN completed but did not produce report.rpt"
            else:
                try:
                    metrics = parse_report(report_file.read_text(encoding="utf-8"), circuit, profile)
                except FlowValidationError as exc:
                    error = str(exc)
        except subprocess.TimeoutExpired as exc:
            stdout_file.write_text(exc.stdout or "", encoding="utf-8")
            stderr_file.write_text(exc.stderr or "", encoding="utf-8")
            process = None
            metrics = None
            error = f"FAN exceeded {self.timeout_seconds} seconds"

        result = RunResult(
            run_id=run_id,
            run_dir=str(run_dir),
            return_code=process.returncode if process is not None else 124,
            success=metrics is not None and error is None,
            metrics=metrics,
            stdout_file=str(stdout_file),
            stderr_file=str(stderr_file),
            report_file=str(report_file),
            error=error,
        )
        self._write_json(run_dir / "result.json", self.result_dict(result))
        self._audit("run_atpg", {"circuit": circuit, "profile": profile, "result": self.result_dict(result)})
        return result

    def optimize(self, circuit: str, goal: Goal) -> dict[str, Any]:
        goal.validate()
        circuit = _safe_identifier(circuit, "circuit", available_circuits())
        results = [self.run(circuit, profile) for profile in PROFILES]
        successful = [result for result in results if result.success and result.metrics]
        if not successful:
            raise RuntimeError("All FAN profiles failed; inspect the individual artifact logs")
        best = min(successful, key=lambda result: self._ranking_key(result.metrics, goal))
        payload = {
            "goal": asdict(goal),
            "circuit": circuit,
            "selected_run_id": best.run_id,
            "selected_profile": best.metrics.profile,
            "objective_met": self.meets_goal(best.metrics, goal),
            "candidates": [self.result_dict(result) for result in results],
        }
        self._audit("optimize", payload)
        return payload

    @staticmethod
    def meets_goal(metrics: AtpgMetrics, goal: Goal) -> bool:
        return metrics.fault_coverage >= goal.min_coverage and (
            goal.max_patterns is None or metrics.patterns <= goal.max_patterns
        )

    @staticmethod
    def _ranking_key(metrics: AtpgMetrics, goal: Goal) -> tuple[float, ...]:
        # A satisfied hard constraint dominates. Then minimize test length while retaining coverage.
        if FanRunner.meets_goal(metrics, goal):
            return (0.0, float(metrics.patterns), -metrics.fault_coverage, metrics.runtime_seconds)
        coverage_shortfall = max(0.0, goal.min_coverage - metrics.fault_coverage)
        pattern_overrun = max(0, metrics.patterns - (goal.max_patterns or metrics.patterns))
        return (1.0, coverage_shortfall, float(pattern_overrun), -metrics.fault_coverage, float(metrics.patterns))

    @staticmethod
    def result_dict(result: RunResult) -> dict[str, Any]:
        payload = asdict(result)
        return payload

    @staticmethod
    def _link_input_tree(run_dir: Path) -> None:
        for name in ("techlib", "mod_netlist"):
            (run_dir / name).symlink_to(FAN_ROOT / name, target_is_directory=True)

    @staticmethod
    def _script_lines(circuit: str, profile: str) -> list[str]:
        settings = PROFILES[profile]
        lines = [
            "read_lib techlib/mod_nangate45.mdt",
            f"read_netlist mod_netlist/{circuit}.v",
            "report_netlist",
            "build_circuit --frame 1",
            "report_circuit",
            "set_fault_type saf",
            "add_fault --all",
        ]
        if settings["static_compression"]:
            lines.append("set_static_compression on")
        if settings["dynamic_compression"]:
            lines.append("set_dynamic_compression on")
        # Every bundled FAN reference profile enables X-Fill.
        lines.append("set_X-Fill on")
        lines.extend(
            [
                "run_atpg",
                "report_statistics > report.rpt",
                "write_pattern result.pat",
                "write_to_STIL result.stil",
                "exit",
            ]
        )
        return lines

    @staticmethod
    def _write_json(path: Path, payload: dict[str, Any]) -> None:
        path.write_text(json.dumps(payload, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")

    @staticmethod
    def _audit(event: str, payload: dict[str, Any]) -> None:
        AUDIT_LOG.parent.mkdir(parents=True, exist_ok=True)
        record = {"timestamp": _now(), "event": event, "payload": payload}
        with AUDIT_LOG.open("a", encoding="utf-8") as handle:
            handle.write(json.dumps(record, ensure_ascii=False) + "\n")
