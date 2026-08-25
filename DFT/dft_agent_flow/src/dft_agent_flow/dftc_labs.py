from __future__ import annotations

import difflib
import hashlib
import json
import re
import shutil
import subprocess
from datetime import datetime, timezone
from pathlib import Path
from typing import Any
from uuid import uuid4

from .config import (
    DFTC_MANIFEST_FILE,
    DFTC_ORIGINAL_ROOT,
    DFTC_RUNTIME_ROOT,
    DFTC_SHELL,
    DFTC_WORKSPACES_ROOT,
)
from .runner import FlowValidationError


def _execution_errors(output: str) -> list[str]:
    """Extract actual shell diagnostics without mistaking Tcl text for failures."""
    return [line.strip() for line in output.splitlines() if line.lstrip().startswith(("Error:", "Fatal:"))]


class DftcLabTutor:
    """Tutor, evidence auditor, and constrained executor for DFTC1 course labs."""

    def __init__(
        self,
        original_root: Path = DFTC_ORIGINAL_ROOT,
        runtime_root: Path = DFTC_RUNTIME_ROOT,
        manifest_file: Path = DFTC_MANIFEST_FILE,
        workspace_root: Path = DFTC_WORKSPACES_ROOT,
        dc_shell: Path = DFTC_SHELL,
    ) -> None:
        self.original_root = original_root
        self.runtime_root = runtime_root
        self.workspace_root = workspace_root
        self.dc_shell = dc_shell
        self.manifest = json.loads(manifest_file.read_text(encoding="utf-8"))
        self._labs = {lab["id"]: lab for lab in self.manifest["labs"]}

    def list_labs(self) -> dict[str, Any]:
        return {
            "course": self.manifest["course"],
            "source_policy": self.manifest["source_policy"],
            "labs": [
                {"id": lab["id"], "state": lab["state"], "topic": lab["topic"]}
                for lab in self.manifest["labs"]
            ],
        }

    def list_skills(self) -> dict[str, Any]:
        """List short, approved DFTC skills suitable for a local model."""
        return {
            "skills": [
                {
                    "id": skill_id,
                    "lab": skill["lab"],
                    "description": skill["description"],
                    "recommended": skill.get("recommended", False),
                    "policy": "The skill stages fresh workspaces and never writes evidence trees.",
                }
                for skill_id, skill in _LAB_SKILLS.items()
            ]
        }

    def list_execution_evidence(self) -> dict[str, Any]:
        """List persisted staged evidence without trusting or modifying it."""
        records: list[dict[str, str]] = []
        if not self.workspace_root.is_dir():
            return {"records": records, "source_policy": "No staged workspace directory is available."}
        evidence_files = sorted(
            self.workspace_root.glob("*/skill_result.json"),
            key=lambda path: path.stat().st_mtime,
            reverse=True,
        )
        for evidence_file in evidence_files:
            try:
                payload = json.loads(evidence_file.read_text(encoding="utf-8"))
            except (OSError, json.JSONDecodeError):
                continue
            execution = payload.get("execution") or payload.get("repair") or {}
            verification_file = evidence_file.parent / "cross_validation.json"
            verification_status = "not_verified"
            if verification_file.is_file():
                try:
                    verification_status = str(json.loads(verification_file.read_text(encoding="utf-8")).get("status", "not_verified"))
                except (OSError, json.JSONDecodeError):
                    verification_status = "invalid_verification_record"
            records.append(
                {
                    "lab": str(execution.get("lab", "unknown")),
                    "skill": str(payload.get("skill", "unknown")),
                    "skill_status": str(payload.get("status", "unknown")),
                    "verification_status": verification_status,
                    "workspace": str(evidence_file.parent),
                    "evidence_file": str(evidence_file),
                }
            )
        return {
            "records": records,
            "source_policy": "Evidence records are read-only; only verified staged evidence can support an execution claim.",
        }

    def run_skill(self, skill_id: str) -> dict[str, Any]:
        """Execute one reviewed multi-step repair skill and return its complete evidence."""
        try:
            skill = _LAB_SKILLS[skill_id]
        except KeyError as exc:
            raise FlowValidationError(f"Unsupported DFTC skill '{skill_id}'. Allowed: {', '.join(sorted(_LAB_SKILLS))}") from exc

        if skill_id == "lab4a_protocol_direct":
            execution = self.run_lab("lab4a_protocol", "baseline_protocol", "official")
            acceptance = self._check_workspace(
                Path(execution["lab_directory"]),
                [
                    {"path": "reports/agent_dft_drc.rpt", "contains": "Total violations: 0"},
                    {"path": "reports/agent_dft_drc.rpt", "contains": "260 cells are valid scan cells"},
                    {"path": "reports/agent_scan_state.rpt", "contains": "scan cells replaced with loops"},
                ],
            )
            result = {
                "skill": skill_id,
                "status": "review_ready"
                if execution["completed_cleanly"] and all(item["passed"] for item in acceptance)
                else "execution_incomplete",
                "execution": execution,
                "acceptance": acceptance,
                "diagnosis": "This is the official Lab 4A direct route: load the provided solution setup, then source unmapped.tcl.",
                "approval": "The result is evidence-verified only after cross-validation; a DFT engineer still approves the course lab.",
            }
            return self._record_skill_result(result, Path(execution["workspace"]))
        if skill_id == "lab4a_protocol_repair":
            baseline = self.run_lab("lab4a_protocol", "official_baseline", "official")
            diagnosed = any("target library" in error.lower() for error in baseline["errors"])
            if not diagnosed:
                result = {
                    "skill": skill_id,
                    "status": "stopped_unexpected_baseline",
                    "baseline": baseline,
                    "repair": None,
                    "acceptance": [],
                    "reason": "The expected missing-target-library signature was absent; no repair was applied.",
                    "approval": "Engineer review is required before selecting another repair.",
                }
                return self._record_skill_result(result, Path(baseline["workspace"]))

            repair = self.run_lab("lab4a_protocol", "baseline_protocol", "official")
            acceptance = self._check_workspace(
                Path(repair["lab_directory"]),
                [
                    {"path": "reports/agent_dft_drc.rpt", "contains": "Total violations: 0"},
                    {"path": "reports/agent_dft_drc.rpt", "contains": "260 cells are valid scan cells"},
                    {"path": "reports/agent_scan_state.rpt", "contains": "scan cells replaced with loops"},
                ],
            )
            review_ready = repair["completed_cleanly"] and all(item["passed"] for item in acceptance)
            result = {
                "skill": skill_id,
                "status": "review_ready" if review_ready else "repair_incomplete",
                "baseline": baseline,
                "repair": repair,
                "acceptance": acceptance,
                "diagnosis": "The official baseline had no target library; the repair loaded sc_max.db through the official solution setup.",
                "approval": "A DFT engineer must review both staged logs before marking Lab 4A passed.",
            }
            return self._record_skill_result(result, Path(repair["workspace"]))
        if skill_id == "lab4b_initialization_protocol":
            execution = self.run_lab("lab4b_init", "initialization_protocol", "official")
            acceptance = self._check_workspace(
                Path(execution["lab_directory"]),
                [
                    {"path": "reports/agent_initial_drc.rpt", "contains": "4335 PRE-DFT VIOLATIONS"},
                    {"path": "reports/agent_initialized_drc.rpt", "contains": "46 PRE-DFT VIOLATIONS"},
                ],
            )
            result = {
                "skill": skill_id,
                "status": "review_ready"
                if execution["completed_cleanly"] and all(item["passed"] for item in acceptance)
                else "repair_incomplete",
                "execution": execution,
                "acceptance": acceptance,
                "diagnosis": "The legacy DDC reader and combined multi-clock declaration are replaced by current, explicit commands in the generated driver.",
                "approval": "A DFT engineer must review the initial and initialized DRC reports before marking Lab 4B passed.",
            }
            return self._record_skill_result(result, Path(execution["workspace"]))
        if skill_id == "lab5_test_mode_scan":
            execution = self.run_lab("lab5_drc", "test_mode_scan", "official")
            acceptance = self._check_workspace(
                Path(execution["lab_directory"]),
                [
                    {"path": "reports/agent_post_dft_drc.rpt", "contains": "0 TOTAL VIOLATIONS"},
                    {"path": "reports/agent_coverage.rpt", "contains": "99.91%"},
                    {"path": "reports/agent_scan_path.rpt", "contains": "261"},
                ],
            )
            result = {
                "skill": skill_id,
                "status": "review_ready"
                if execution["completed_cleanly"] and all(item["passed"] for item in acceptance)
                else "repair_incomplete",
                "execution": execution,
                "acceptance": acceptance,
                "diagnosis": "TEST_MODE removes the RTL DRC issue; escaped VHDL bus names are selected as port collections before scan insertion.",
                "approval": "A DFT engineer must review the post-DFT DRC, coverage estimate, and scan-path report before marking Lab 5 passed.",
            }
            return self._record_skill_result(result, Path(execution["workspace"]))
        if skill_id == "lab6_protocol_review":
            execution = self.run_lab("lab6_gui", "protocol_review", "ported")
            acceptance = self._check_workspace(
                Path(execution["lab_directory"]),
                [
                    {"path": "reports/agent_dft_drc.rpt", "contains": "74"},
                    {"path": "reports/agent_hierarchy.rpt", "contains": "RISC_CORE"},
                ],
            )
            result = {
                "skill": skill_id,
                "status": "review_ready"
                if execution["completed_cleanly"] and all(item["passed"] for item in acceptance)
                else "execution_incomplete",
                "execution": execution,
                "acceptance": acceptance,
                "diagnosis": "The command-mode Lab 6 flow keeps input-connectivity messages separate from its sequential DFT-rule observations.",
                "approval": "A DFT engineer must classify the remaining Lab 6 findings before course signoff.",
            }
            return self._record_skill_result(result, Path(execution["workspace"]))
        if skill_id == "lab7_autofix_scan":
            execution = self.run_lab("lab7_fixing", "autofix_scan", "ported")
            acceptance = self._check_workspace(
                Path(execution["lab_directory"]),
                [
                    {"path": "reports/agent_after_autofix.rpt", "contains": "Total violations: 0"},
                    {"path": "reports/agent_coverage.rpt", "minimum_percentage": 99.80},
                    {"path": "reports/agent_scan_path.rpt", "contains": "261"},
                ],
            )
            result = {
                "skill": skill_id,
                "status": "review_ready"
                if execution["completed_cleanly"] and all(item["passed"] for item in acceptance)
                else "execution_incomplete",
                "execution": execution,
                "acceptance": acceptance,
                "diagnosis": "AutoFix configuration is rebuilt into the protocol before preview and insertion, then checked with post-DFT DRC and coverage.",
                "approval": "A DFT engineer must review the inserted control logic and generated scan artifacts before course signoff.",
            }
            return self._record_skill_result(result, Path(execution["workspace"]))
        if skill_id == "lab8_six_chain_topdown":
            execution = self.run_lab("lab8_topdown", "six_chain_topdown", "ported")
            acceptance = self._check_workspace(
                Path(execution["lab_directory"]),
                [
                    {"path": "reports/agent_scan_path.rpt", "contains": "chain5"},
                    {"path": "reports/agent_coverage.rpt", "minimum_percentage": 95.0},
                ],
            )
            result = {
                "skill": skill_id,
                "status": "review_ready"
                if execution["completed_cleanly"] and all(item["passed"] for item in acceptance)
                else "execution_incomplete",
                "execution": execution,
                "acceptance": acceptance,
                "diagnosis": "Six collection-selected scan endpoints and mixed-clock lockup insertion are checked independently from residual model findings.",
                "approval": "A DFT engineer must classify any nonzero aggregate DRC before course signoff.",
            }
            return self._record_skill_result(result, Path(execution["workspace"]))
        if skill_id == "lab9_export_handoff":
            execution = self.run_lab("lab9_export", "export_handoff", "ported")
            acceptance = self._check_workspace(
                Path(execution["lab_directory"]),
                [
                    {"path": "reports/agent_scan_path.rpt", "contains": "chain5"},
                    {"path": "reports/agent_coverage.rpt", "minimum_percentage": 92.0},
                    {"path": "mapped_scan/ORCA.scandef", "contains": "SCANCHAINS"},
                ],
            )
            result = {
                "skill": skill_id,
                "status": "review_ready"
                if execution["completed_cleanly"] and all(item["passed"] for item in acceptance)
                else "execution_incomplete",
                "execution": execution,
                "acceptance": acceptance,
                "diagnosis": "The handoff writes scan netlist, protocol, SCANDEF, and post-insertion evidence from one staged design state.",
                "approval": "A DFT engineer must separately review TestMAX ATPG before course signoff.",
            }
            return self._record_skill_result(result, Path(execution["workspace"]))
        if skill_id == "lab10_topdown_hierarchical":
            execution = self.run_lab("lab10_hicap", "topdown_scan", "ported")
            acceptance = self._check_workspace(
                Path(execution["lab_directory"]),
                [
                    {"path": "reports/ORCA_scan_path.rpt", "contains": "chain5"},
                    {"path": "reports/ORCA_coverage.rpt", "minimum_percentage": 90.0},
                    {"path": "mapped_scan/ORCA_scan.ddc"},
                ],
            )
            result = {
                "skill": skill_id,
                "status": "review_ready"
                if execution["completed_cleanly"] and all(item["passed"] for item in acceptance)
                else "execution_incomplete",
                "execution": execution,
                "acceptance": acceptance,
                "diagnosis": "The top-down hierarchical route loads the complete mapped DDC set, inserts six chains, and preserves its own reports in a fresh workspace.",
                "approval": "A DFT engineer must review per-block DRC and coverage before course signoff.",
            }
            return self._record_skill_result(result, Path(execution["workspace"]))
        if skill_id == "lab12_dftmax_compatibility":
            execution = self.run_lab("lab12_dftmax", "compression_compatibility", "ported")
            acceptance = self._check_workspace(
                Path(execution["lab_directory"]),
                [
                    {"path": "reports/ORCA_COMP_scan_chains.rpt", "contains": "I 30"},
                    {"path": "reports/ORCA_COMP_dft.rpt", "no_errors": True},
                    {"path": "mapped_scan/ORCA_COMP.scandef", "contains": "SCANCHAINS"},
                ],
            )
            result = {
                "skill": skill_id,
                "status": "review_ready"
                if execution["completed_cleanly"] and all(item["passed"] for item in acceptance)
                else "execution_incomplete",
                "execution": execution,
                "acceptance": acceptance,
                "diagnosis": "The compression compatibility route records each current-tool diagnostic and does not suppress unsupported legacy commands.",
                "approval": "Any parsed Error:, stack trace, or failed acceptance check blocks a DFTMAX completion claim.",
            }
            return self._record_skill_result(result, Path(execution["workspace"]))
        raise AssertionError(f"Skill implementation missing: {skill_id}")  # pragma: no cover

    def run_skill_and_verify(self, skill_id: str) -> dict[str, Any]:
        """Run a skill, then require two stable, independent evidence reviews."""
        skill_result = self.run_skill(skill_id)
        verification = self.cross_validate_evidence(Path(skill_result["evidence_file"]))
        return {
            "skill_execution": skill_result,
            "cross_validation": verification,
            "conclusion": "evidence_verified" if verification["status"] == "verified" else "not_verified",
        }

    def run_skill_and_verify_summary(self, skill_id: str) -> dict[str, Any]:
        """Run a skill and return the bounded evidence summary intended for an LLM."""
        return self.summarize_skill_verification(self.run_skill_and_verify(skill_id))

    def run_all_skills_and_verify(self) -> dict[str, Any]:
        """Run every reviewed course skill, preserving an independent result for each Lab."""
        results: list[dict[str, Any]] = []
        for skill_id in _COURSE_SKILL_SEQUENCE:
            try:
                results.append(self.run_skill_and_verify_summary(skill_id))
            except Exception as exc:  # Preserve the rest of the course run after an unexpected Lab failure.
                results.append(
                    {
                        "skill": skill_id,
                        "conclusion": "not_verified",
                        "unexpected_failure": f"{type(exc).__name__}: {exc}",
                    }
                )
        verified = sum(item.get("cross_validation", {}).get("status") == "verified" for item in results)
        blocked = sum(item.get("cross_validation", {}).get("status") == "blocked" for item in results)
        return {
            "course": self.manifest["course"],
            "skills_attempted": len(results),
            "verified_count": verified,
            "blocked_count": blocked,
            "course_status": "all_execution_evidence_verified"
            if verified == len(results)
            else "completed_with_review_required",
            "results": results,
            "approval": "This suite confirms staged execution evidence only; a DFT engineer still approves each course Lab.",
        }

    @staticmethod
    def summarize_skill_verification(result: dict[str, Any]) -> dict[str, Any]:
        """Keep tool-call context small while retaining all decision-relevant evidence."""
        skill_result = result.get("skill_execution", {})
        execution = skill_result.get("execution") or skill_result.get("repair") or {}
        verification = result.get("cross_validation", {})
        rounds = verification.get("rounds", [])
        final_roles = rounds[-1].get("roles", {}) if rounds else {}
        blockers = [
            issue
            for role in final_roles.values()
            for issue in role.get("issues", [])
        ][:8]
        acceptance = [
            {
                "report": Path(str(item.get("path", "unknown"))).name,
                "passed": bool(item.get("passed")),
                "observed_percentage": item.get("observed_percentage"),
                "minimum_percentage": item.get("minimum_percentage"),
                "no_errors": bool(item.get("no_errors", False)),
            }
            for item in skill_result.get("acceptance", [])
            if isinstance(item, dict)
        ]
        return {
            "skill": skill_result.get("skill"),
            "lab": execution.get("lab"),
            "skill_status": skill_result.get("status"),
            "execution": {
                "workspace": execution.get("workspace"),
                "flow": execution.get("flow"),
                "returncode": execution.get("returncode"),
                "timed_out": execution.get("timed_out"),
                "completed_cleanly": execution.get("completed_cleanly"),
                "error_count": len(execution.get("errors", [])),
                "errors": execution.get("errors", [])[:4],
            },
            "acceptance": acceptance,
            "cross_validation": {
                "status": verification.get("status"),
                "rounds": verification.get("confirmation", {}).get("rounds"),
                "stable_snapshot": verification.get("confirmation", {}).get("stable_snapshot"),
                "blockers": blockers,
                "verification_file": verification.get("verification_file"),
            },
            "evidence_file": skill_result.get("evidence_file"),
            "conclusion": result.get("conclusion", "not_verified"),
        }

    def cross_validate_evidence(self, evidence_file: Path) -> dict[str, Any]:
        """Independently inspect execution, reports, and negative evidence twice.

        These deterministic reviewer roles intentionally do not trust the model's
        narrative or the pre-computed ``passed`` flags in ``skill_result.json``.
        """
        evidence_path = evidence_file.expanduser().resolve()
        workspace_root = self.workspace_root.resolve()
        if not evidence_path.is_file():
            raise FileNotFoundError(f"DFTC skill evidence is unavailable: {evidence_path}")
        if not self._is_within(evidence_path, workspace_root):
            raise FlowValidationError("DFTC evidence must reside in the isolated workspace root")

        first = self._cross_validation_round(evidence_path)
        second = self._cross_validation_round(evidence_path)
        roles_passed = all(
            role["passed"]
            for snapshot in (first, second)
            for role in snapshot["roles"].values()
        )
        stable = first["fingerprint"] == second["fingerprint"]
        blocking = any(
            role["blocking"]
            for snapshot in (first, second)
            for role in snapshot["roles"].values()
        )
        status = "verified" if roles_passed and stable else "blocked" if blocking else "needs_review"
        verification = {
            "status": status,
            "evidence_file": str(evidence_path),
            "verification_roles": ["execution_auditor", "report_auditor", "skeptic_auditor"],
            "confirmation": {
                "rounds": 2,
                "stable_snapshot": stable,
                "policy": "All independent roles must pass in both snapshots; model narration is not evidence.",
            },
            "rounds": [first, second],
            "approval": "Verified execution evidence still requires DFT engineer approval before a course lab is marked passed.",
        }
        verification_file = evidence_path.parent / "cross_validation.json"
        verification_file.write_text(json.dumps(verification, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        return {**verification, "verification_file": str(verification_file)}

    def lesson(self, lab_id: str) -> dict[str, Any]:
        lab = self._lab(lab_id)
        return {
            "id": lab["id"],
            "state": lab["state"],
            "topic": lab["topic"],
            "objective": lab["objective"],
            "workflow": lab["workflow"],
            "porting_notes": lab["porting_notes"],
            "acceptance_checks": lab.get("checks", []),
            "blocking_evidence": lab.get("blocking_evidence", []),
            "approved_flows": self._flow_names(lab_id),
            "writes_allowed": "Only in a newly staged workspace through an approved flow.",
        }

    def audit_runtime(self, lab_id: str) -> dict[str, Any]:
        lab = self._lab(lab_id)
        if not self.runtime_root.is_dir():
            raise FileNotFoundError(f"DFTC runtime copy is unavailable: {self.runtime_root}")
        checks = [self._check_text(lab_id, item) for item in lab.get("checks", [])]
        blockers = [self._check_text(lab_id, item) for item in lab.get("blocking_evidence", [])]
        all_checks_passed = bool(checks) and all(item["passed"] for item in checks)
        if lab["state"].startswith("verified"):
            disposition = "verified_evidence_present" if all_checks_passed else "verification_incomplete"
        else:
            disposition = "human_review_required"
        return {
            "lab": lab_id,
            "declared_state": lab["state"],
            "disposition": disposition,
            "checks": checks,
            "blocking_evidence": blockers,
            "source_policy": self.manifest["source_policy"],
        }

    def compare_porting_files(self, lab_id: str) -> dict[str, Any]:
        lab = self._lab(lab_id)
        files = []
        for relative_path in lab["porting_files"]:
            original = self.original_root / lab_id / relative_path
            runtime = self.runtime_root / lab_id / relative_path
            item: dict[str, Any] = {
                "path": relative_path,
                "original_exists": original.is_file(),
                "runtime_exists": runtime.is_file(),
            }
            if original.is_file() and runtime.is_file():
                original_text = original.read_text(encoding="utf-8", errors="replace").splitlines()
                runtime_text = runtime.read_text(encoding="utf-8", errors="replace").splitlines()
                diff = list(
                    difflib.unified_diff(
                        original_text,
                        runtime_text,
                        fromfile=f"official/{relative_path}",
                        tofile=f"runtime/{relative_path}",
                        lineterm="",
                    )
                )
                item["changed"] = bool(diff)
                item["diff_preview"] = diff[:120]
            files.append(item)
        return {"lab": lab_id, "files": files, "writes_allowed": False}

    def execution_readiness(self) -> dict[str, Any]:
        """Report whether the approved dc_shell container entrypoint is available."""
        configured = self.dc_shell.is_file() and self.dc_shell.stat().st_mode & 0o111 != 0
        return {
            "ready": bool(configured and self.original_root.is_dir()),
            "configured_launcher": str(self.dc_shell),
            "workspace_root": str(self.workspace_root),
            "message": (
                "The approved dc_shell launcher or official DFTC tree is unavailable. The agent can teach and audit evidence, but cannot claim a new DFTC run."
                if not configured
                else "The launcher is available. New runs remain restricted to generated drivers in isolated workspaces."
            ),
        }

    def stage_lab(self, lab_id: str, variant: str = "official") -> dict[str, Any]:
        """Create a writeable copy of one lab without changing either evidence tree.

        ``official`` starts from the official course file. ``ported`` overlays only
        the manifest-declared version-porting files from the recorded runtime tree.
        """
        lab = self._lab(lab_id)
        if variant not in {"official", "ported"}:
            raise FlowValidationError("DFTC variant must be 'official' or 'ported'")
        source_lab = self.original_root / lab_id
        source_ref = self.original_root / "ref"
        if not source_lab.is_dir() or not source_ref.is_dir():
            raise FileNotFoundError("Official DFTC lab or ref tree is unavailable")

        run_id = f"{datetime.now(timezone.utc):%Y%m%dT%H%M%SZ}_{lab_id}_{uuid4().hex[:8]}"
        workspace = self.workspace_root / run_id
        staged_lab = workspace / lab_id
        workspace.mkdir(parents=True)
        shutil.copytree(source_lab, staged_lab, symlinks=True)
        (workspace / "ref").symlink_to(source_ref, target_is_directory=True)
        for directory in ("logs", "reports", "unmapped", "mapped", "mapped_scan", "tmax"):
            (staged_lab / directory).mkdir(parents=True, exist_ok=True)

        overlaid: list[str] = []
        if variant == "ported":
            for relative_path in lab["porting_files"]:
                runtime_file = self.runtime_root / lab_id / relative_path
                staged_file = staged_lab / relative_path
                if runtime_file.is_file():
                    staged_file.parent.mkdir(parents=True, exist_ok=True)
                    shutil.copy2(runtime_file, staged_file)
                    overlaid.append(relative_path)

        metadata = {
            "run_id": run_id,
            "lab": lab_id,
            "variant": variant,
            "official_source": str(source_lab),
            "runtime_overlays": overlaid,
            "created_at": datetime.now(timezone.utc).isoformat(timespec="seconds"),
        }
        (workspace / "stage.json").write_text(json.dumps(metadata, indent=2) + "\n", encoding="utf-8")
        return {**metadata, "workspace": str(workspace), "lab_directory": str(staged_lab)}

    def run_lab(self, lab_id: str, flow: str = "baseline_protocol", variant: str = "official") -> dict[str, Any]:
        """Run a named, generated DFTC driver in an isolated staged workspace.

        The agent cannot submit arbitrary Tcl: drivers are selected from
        ``_FLOW_DRIVERS`` and are saved alongside their logs for review.
        """
        if not self.execution_readiness()["ready"]:
            raise RuntimeError("The approved dc_shell launcher is unavailable")
        driver = self._flow_driver(lab_id, flow)
        staged = self.stage_lab(lab_id, variant)
        lab_directory = Path(staged["lab_directory"])
        driver_path = lab_directory / f"agent_{flow}.tcl"
        driver_path.write_text(driver, encoding="utf-8")

        command = [str(self.dc_shell), "-no_gui", "-f", driver_path.name]
        try:
            result = subprocess.run(
                command,
                cwd=lab_directory,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT,
                timeout=1_200,
                check=False,
            )
            output = result.stdout
            timed_out = False
        except subprocess.TimeoutExpired as exc:
            output = (exc.stdout or "") + "\nDFTC runner timed out after 1200 seconds.\n"
            result = None
            timed_out = True

        log_path = lab_directory / "logs" / f"agent_{flow}.log"
        log_path.write_text(output, encoding="utf-8", errors="replace")
        errors = _execution_errors(output)
        return {
            **staged,
            "flow": flow,
            "driver": str(driver_path),
            "command": command,
            "log": str(log_path),
            "returncode": None if timed_out else result.returncode,
            "timed_out": timed_out,
            "errors": errors[:40],
            "completed_cleanly": not timed_out and result.returncode == 0 and not errors,
            "approval": "New execution evidence needs DFT engineer review before the lab can be marked passed.",
        }

    def _lab(self, lab_id: str) -> dict[str, Any]:
        try:
            return self._labs[lab_id]
        except KeyError as exc:
            raise FlowValidationError(f"Unsupported DFTC lab '{lab_id}'. Allowed: {', '.join(sorted(self._labs))}") from exc

    def _check_text(self, lab_id: str, expectation: dict[str, str]) -> dict[str, Any]:
        path = self.runtime_root / lab_id / expectation["path"]
        exists = path.is_file()
        needle = expectation.get("contains", "")
        text = path.read_text(encoding="utf-8", errors="replace") if exists else ""
        return {
            "path": str(path),
            "contains": needle,
            "exists": exists,
            "passed": exists and needle in text,
        }

    @staticmethod
    def _check_workspace(workspace: Path, expectations: list[dict[str, Any]]) -> list[dict[str, Any]]:
        checks = []
        for expectation in expectations:
            path = workspace / expectation["path"]
            exists = path.is_file()
            text = path.read_text(encoding="utf-8", errors="replace") if exists else ""
            needle = expectation.get("contains")
            minimum_percentage = expectation.get("minimum_percentage")
            no_errors = bool(expectation.get("no_errors", False))
            blocking = bool(expectation.get("blocking", False))
            observed_percentage = DftcLabTutor._coverage_percentage(text)
            contains_passed = needle is None or needle in text
            percentage_passed = (
                minimum_percentage is None
                or (observed_percentage is not None and observed_percentage >= float(minimum_percentage))
            )
            no_errors_passed = not no_errors or not _execution_errors(text)
            checks.append(
                {
                    "path": str(path),
                    "contains": needle,
                    "minimum_percentage": minimum_percentage,
                    "no_errors": no_errors,
                    "blocking": blocking,
                    "observed_percentage": observed_percentage,
                    "exists": exists,
                    "passed": exists and contains_passed and percentage_passed and no_errors_passed,
                }
            )
        return checks

    @staticmethod
    def _record_skill_result(result: dict[str, Any], workspace: Path) -> dict[str, Any]:
        evidence_file = workspace / "skill_result.json"
        evidence_file.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        return {**result, "evidence_file": str(evidence_file)}

    def _cross_validation_round(self, evidence_path: Path) -> dict[str, Any]:
        payload = json.loads(evidence_path.read_text(encoding="utf-8"))
        candidate = payload.get("execution") or payload.get("repair")
        evidence_root = evidence_path.parent.resolve()
        execution = self._validate_execution_candidate(payload, candidate, evidence_root)
        reports, acceptance_paths = self._validate_reports(candidate, payload.get("acceptance"), evidence_root)
        skeptic = self._validate_negative_evidence(candidate, acceptance_paths, evidence_root)
        files = [evidence_path]
        for path in (
            execution.get("driver_path"),
            execution.get("log_path"),
            *acceptance_paths,
            *[Path(path) for path in skeptic.get("crash_artifacts", [])],
        ):
            if isinstance(path, Path) and path.is_file() and path not in files:
                files.append(path)
        digest_records = [
            {
                "path": str(path.resolve().relative_to(evidence_root)),
                "sha256": self._sha256(path),
            }
            for path in sorted(files)
        ]
        fingerprint = hashlib.sha256(
            json.dumps(digest_records, ensure_ascii=False, sort_keys=True).encode("utf-8")
        ).hexdigest()
        execution.pop("driver_path", None)
        execution.pop("log_path", None)
        return {
            "fingerprint": fingerprint,
            "files": digest_records,
            "roles": {
                "execution_auditor": execution,
                "report_auditor": reports,
                "skeptic_auditor": skeptic,
            },
        }

    def _validate_execution_candidate(
        self, payload: dict[str, Any], candidate: Any, evidence_root: Path
    ) -> dict[str, Any]:
        issues: list[str] = []
        blocking = False
        driver_path: Path | None = None
        log_path: Path | None = None
        if not isinstance(candidate, dict):
            issues.append("The skill result has no final execution or repair record.")
        else:
            try:
                workspace = Path(candidate["workspace"]).resolve()
                lab_directory = Path(candidate["lab_directory"]).resolve()
                driver_path = Path(candidate["driver"]).resolve()
                log_path = Path(candidate["log"]).resolve()
            except (KeyError, TypeError):
                issues.append("The execution record lacks workspace, lab directory, driver, or log paths.")
            else:
                if workspace != evidence_root:
                    issues.append("The evidence file is not stored in the final execution workspace.")
                for label, path, parent in (
                    ("lab directory", lab_directory, workspace),
                    ("generated driver", driver_path, lab_directory),
                    ("captured log", log_path, lab_directory),
                ):
                    if not self._is_within(path, parent) or not path.exists():
                        issues.append(f"The {label} is missing or outside its staged workspace.")
                if candidate.get("returncode") != 0 or candidate.get("timed_out"):
                    issues.append("The final execution did not finish with return code 0.")
                    blocking = True
                if candidate.get("errors"):
                    issues.append("The final execution record contains parsed tool errors.")
                    blocking = True
                if not candidate.get("completed_cleanly"):
                    issues.append("The final execution record is not marked completed_cleanly.")
                    blocking = True
        if payload.get("status") != "review_ready":
            issues.append(f"The skill status is {payload.get('status')!r}, not review_ready.")
        return {
            "passed": not issues,
            "blocking": blocking,
            "issues": issues,
            "returncode": candidate.get("returncode") if isinstance(candidate, dict) else None,
            "driver_path": driver_path,
            "log_path": log_path,
        }

    def _validate_reports(
        self, candidate: Any, acceptance: Any, evidence_root: Path
    ) -> tuple[dict[str, Any], list[Path]]:
        issues: list[str] = []
        checks: list[dict[str, Any]] = []
        paths: list[Path] = []
        blocking = False
        lab_directory = (
            Path(candidate["lab_directory"]).resolve()
            if isinstance(candidate, dict) and candidate.get("lab_directory")
            else None
        )
        if not lab_directory or not self._is_within(lab_directory, evidence_root):
            issues.append("The final lab directory is unavailable for report review.")
        if not isinstance(acceptance, list) or not acceptance:
            issues.append("The skill result contains no acceptance checks.")
        else:
            for item in acceptance:
                path_text = item.get("path") if isinstance(item, dict) else None
                needle = item.get("contains") if isinstance(item, dict) else None
                minimum_percentage = item.get("minimum_percentage") if isinstance(item, dict) else None
                no_errors = bool(item.get("no_errors", False)) if isinstance(item, dict) else False
                check_is_blocking = bool(item.get("blocking", False)) if isinstance(item, dict) else False
                path = Path(path_text).resolve() if isinstance(path_text, str) else None
                valid_path = bool(path and lab_directory and self._is_within(path, lab_directory))
                text = path.read_text(encoding="utf-8", errors="replace") if valid_path and path.is_file() else ""
                observed_percentage = self._coverage_percentage(text)
                contains_passed = needle is None or (isinstance(needle, str) and needle in text)
                percentage_passed = (
                    minimum_percentage is None
                    or (observed_percentage is not None and observed_percentage >= float(minimum_percentage))
                )
                no_errors_passed = not no_errors or not _execution_errors(text)
                passed = bool(
                    valid_path and path and path.is_file() and contains_passed and percentage_passed and no_errors_passed
                )
                checks.append(
                    {
                        "path": str(path) if path else path_text,
                        "contains": needle,
                        "minimum_percentage": minimum_percentage,
                        "no_errors": no_errors,
                        "blocking": check_is_blocking,
                        "observed_percentage": observed_percentage,
                        "passed": passed,
                    }
                )
                if path and valid_path and path.is_file():
                    paths.append(path)
                if not passed:
                    issues.append(f"Acceptance report check failed: {path_text!r} did not satisfy its declared acceptance rule.")
                    blocking = blocking or check_is_blocking
        return {"passed": not issues, "blocking": blocking, "issues": issues, "checks": checks}, paths

    def _validate_negative_evidence(
        self, candidate: Any, acceptance_paths: list[Path], evidence_root: Path
    ) -> dict[str, Any]:
        issues: list[str] = []
        crash_artifacts: list[str] = []
        log_path = Path(candidate["log"]).resolve() if isinstance(candidate, dict) and candidate.get("log") else None
        lab_directory = (
            Path(candidate["lab_directory"]).resolve()
            if isinstance(candidate, dict) and candidate.get("lab_directory")
            else None
        )
        if not log_path or not self._is_within(log_path, evidence_root) or not log_path.is_file():
            issues.append("The captured tool log is unavailable for negative-evidence review.")
        else:
            errors = _execution_errors(log_path.read_text(encoding="utf-8", errors="replace"))
            if errors:
                issues.extend(f"Tool log diagnostic: {line}" for line in errors[:20])
        for path in acceptance_paths:
            report_errors = _execution_errors(path.read_text(encoding="utf-8", errors="replace"))
            issues.extend(f"Acceptance report diagnostic in {path.name}: {line}" for line in report_errors[:20])
        if lab_directory and self._is_within(lab_directory, evidence_root) and lab_directory.is_dir():
            crash_paths = sorted(
                [*lab_directory.rglob("Synopsys_stack_trace_*.txt"), *lab_directory.rglob("crte_*.txt")]
            )
            crash_artifacts = [str(path) for path in crash_paths]
            if crash_artifacts:
                issues.append("Crash artifacts are present in the final staged lab directory.")
        return {
            "passed": not issues,
            "blocking": bool(issues),
            "issues": issues,
            "crash_artifacts": crash_artifacts,
        }

    @staticmethod
    def _is_within(path: Path, root: Path) -> bool:
        try:
            path.resolve().relative_to(root.resolve())
        except ValueError:
            return False
        return True

    @staticmethod
    def _sha256(path: Path) -> str:
        digest = hashlib.sha256()
        with path.open("rb") as handle:
            for chunk in iter(lambda: handle.read(1024 * 1024), b""):
                digest.update(chunk)
        return digest.hexdigest()

    @staticmethod
    def _coverage_percentage(text: str) -> float | None:
        matches = re.findall(r"test coverage\s+([0-9]+(?:\.[0-9]+)?)%", text, flags=re.IGNORECASE)
        return float(matches[-1]) if matches else None

    def _flow_driver(self, lab_id: str, flow: str) -> str:
        try:
            return _FLOW_DRIVERS[(lab_id, flow)]
        except KeyError as exc:
            allowed = sorted(name for key_lab, name in _FLOW_DRIVERS if key_lab == lab_id)
            if not allowed:
                raise FlowValidationError(f"No approved executable flow is defined for {lab_id} yet") from exc
            raise FlowValidationError(
                f"Unsupported DFTC flow '{flow}' for {lab_id}. Allowed: {', '.join(allowed)}"
            ) from exc

    def _flow_names(self, lab_id: str) -> list[str]:
        return sorted(name for key_lab, name in _FLOW_DRIVERS if key_lab == lab_id)


_FLOW_DRIVERS = {
    (
        "lab4a_protocol",
        "official_baseline",
    ): """# Generated by DFT Agent Flow. Reproduces the official missing-library setup.
set_app_var hdlin_always_fsm_complete false
source -echo -verbose .solutions/unmapped.tcl
redirect -file reports/agent_dft_drc.rpt { dft_drc }
quit
""",
    (
        "lab4a_protocol",
        "baseline_protocol",
    ): """# Generated by DFT Agent Flow. Official Lab 4A direct solution route.
set_app_var hdlin_always_fsm_complete false
source -echo -verbose .solutions/dot.synopsys_dc.setup
source -echo -verbose .solutions/unmapped.tcl
redirect -file reports/agent_dft_drc.rpt { dft_drc }
redirect -file reports/agent_scan_state.rpt { report_scan_state }
quit
""",
    (
        "lab4b_init",
        "initialization_protocol",
    ): """# Generated by DFT Agent Flow. Current DDC and multi-clock compatibility path.
source -echo -verbose .synopsys_dc.setup
set test_simulation_library "./tmax/rams.v"
read_file -format ddc mapped/ORCA.ddc
current_design ORCA
link
set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port pclk
set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port sdr_clk
set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port sys_clk
set_dft_signal -view existing_dft -port prst_n -type Reset -active_state 0
set_dft_signal -view existing_dft -port scan_en -type ScanEnable -active_state 1
set_dft_signal -view existing_dft -type Constant -active_state 0 -port conf_ena
create_test_protocol
redirect -file reports/agent_initial_drc.rpt { dft_drc }
remove_test_protocol
read_test_protocol -section test_setup .solutions/orca_mapped.spf
create_test_protocol -capture_procedure multi_clock
redirect -file reports/agent_initialized_drc.rpt { dft_drc }
write_test_protocol -output unmapped/agent_initialized.spf
quit
""",
    (
        "lab5_drc",
        "test_mode_scan",
    ): """# Generated by DFT Agent Flow. TEST_MODE and port-collection scan insertion path.
set_app_var hdlin_always_fsm_complete false
source -echo -verbose .synopsys_dc.setup
source -echo -verbose scripts/task2_setup.tcl
set test_disable_enhanced_dft_drc_reporting false
redirect -file reports/agent_pre_dft_drc.rpt { dft_drc }
set_dft_insertion_configuration -preserve_design_name true
set scan_in_port [index_collection [get_ports {Instrn*}] 31]
set scan_out_port [index_collection [get_ports {Xecutng_Instrn*}] 31]
set_dft_signal -view spec -port $scan_in_port -type ScanDataIn
set_dft_signal -view spec -port $scan_out_port -type ScanDataOut
set_scan_configuration -chain_count 1
set_scan_configuration -clock_mixing mix_clocks
preview_dft
insert_dft
redirect -file reports/agent_post_dft_drc.rpt { dft_drc }
redirect -file reports/agent_coverage.rpt { dft_drc -coverage_estimate }
redirect -file reports/agent_scan_path.rpt { report_scan_path }
write -format ddc -hierarchy -output mapped_scan/RISC_CORE.ddc
write -format verilog -hierarchy -output mapped_scan/RISC_CORE_scan.v
quit
""",
    (
        "lab6_gui",
        "protocol_review",
    ): """# Generated by DFT Agent Flow. Command-mode Lab 6 protocol review.
source -echo -verbose .synopsys_dc.setup
source -echo -verbose .solutions/lab6.tcl
redirect -file reports/agent_dft_drc.rpt { dft_drc }
redirect -file reports/agent_hierarchy.rpt { report_hierarchy }
quit
""",
    (
        "lab7_fixing",
        "autofix_scan",
    ): """# Generated by DFT Agent Flow. Lab 7 AutoFix and scan insertion.
source -echo -verbose .synopsys_dc.setup
source -echo -verbose scripts/4read_gate_and_protocol.tcl
redirect -file reports/agent_before_autofix.rpt { dft_drc }
source -echo -verbose scripts/5preview_dft.tcl
source -echo -verbose scripts/6insert_dft.tcl
redirect -file reports/agent_after_autofix.rpt { dft_drc }
redirect -file reports/agent_coverage.rpt { dft_drc -coverage_estimate }
redirect -file reports/agent_scan_path.rpt { report_scan_path }
quit
""",
    (
        "lab8_topdown",
        "six_chain_topdown",
    ): """# Generated by DFT Agent Flow. Lab 8 six-chain top-down insertion.
source -echo -verbose .synopsys_dc.setup
source -echo -verbose scripts/4read_gate_and_protocol.tcl
source -echo -verbose scripts/settings_insert_dft.tcl
source -echo -verbose scripts/6insert_dft.tcl
redirect -file reports/agent_post_dft_drc.rpt { dft_drc }
redirect -file reports/agent_coverage.rpt { dft_drc -coverage_estimate }
redirect -file reports/agent_scan_path.rpt { report_scan_path -view existing_dft -chain all }
quit
""",
    (
        "lab9_export",
        "export_handoff",
    ): """# Generated by DFT Agent Flow. Lab 9 scan handoff and SCANDEF flow.
source -echo -verbose .synopsys_dc.setup
source -echo -verbose scripts/4read_gate_and_protocol.tcl
source -echo -verbose scripts/5preview_dft.tcl
source -echo -verbose scripts/6insert_dft.tcl
source -echo -verbose scripts/7handoff.tcl
redirect -file reports/agent_post_dft_drc.rpt { dft_drc }
redirect -file reports/agent_coverage.rpt { dft_drc -coverage_estimate }
redirect -file reports/agent_scan_path.rpt { report_scan_path -view existing_dft -chain all }
quit
""",
    (
        "lab10_hicap",
        "topdown_scan",
    ): """# Generated by DFT Agent Flow. Lab 10 top-down hierarchical scan insertion.
source -echo -verbose .synopsys_dc.setup
source -echo -verbose scripts/top_down.tcl
quit
""",
    (
        "lab12_dftmax",
        "compression_compatibility",
    ): """# Generated by DFT Agent Flow. Lab 12 DFTMAX compatibility evidence route.
source -echo -verbose .synopsys_dc.setup
source -echo -verbose scripts/4read_gate_and_protocol.tcl
source -echo -verbose scripts/5preview_dft.tcl
source -echo -verbose scripts/6insert_dft.tcl
source -echo -verbose scripts/7handoff.tcl
quit
""",
}


_LAB_SKILLS = {
    "lab4a_protocol_direct": {
        "lab": "lab4a_protocol",
        "description": "Run the official Lab 4A solution path directly: load its supplied setup, source unmapped.tcl, and collect DRC evidence.",
        "recommended": True,
    },
    "lab4a_protocol_repair": {
        "lab": "lab4a_protocol",
        "description": "Diagnostic only: reproduce the missing-target-library setup, then compare it with the supplied official setup.",
    },
    "lab4b_initialization_protocol": {
        "lab": "lab4b_init",
        "description": "Read ORCA DDC with the current reader, rebuild the three-clock protocol, then compare initial and initialized Pre-DFT DRC evidence.",
    },
    "lab5_test_mode_scan": {
        "lab": "lab5_drc",
        "description": "Apply TEST_MODE, select VHDL scan endpoints through port collections, insert one scan chain, then check DRC and coverage.",
    },
    "lab6_protocol_review": {
        "lab": "lab6_gui",
        "description": "Run the command-mode protocol flow and preserve DRC plus hierarchy evidence for message classification.",
    },
    "lab7_autofix_scan": {
        "lab": "lab7_fixing",
        "description": "Apply reviewed AutoFix settings, rebuild the protocol, insert scan, and verify post-DFT DRC, coverage, and chain evidence.",
    },
    "lab8_six_chain_topdown": {
        "lab": "lab8_topdown",
        "description": "Insert and inspect six mixed-clock top-down scan chains using collection-selected VHDL bus endpoints.",
    },
    "lab9_export_handoff": {
        "lab": "lab9_export",
        "description": "Insert six chains, export the scan handoff set, and verify SCANDEF plus post-insertion evidence.",
    },
    "lab10_topdown_hierarchical": {
        "lab": "lab10_hicap",
        "description": "Run the recorded top-down hierarchical path, then cross-check six-chain, coverage, and handoff evidence in a fresh workspace.",
    },
    "lab12_dftmax_compatibility": {
        "lab": "lab12_dftmax",
        "description": "Run the DFTMAX compression compatibility path and preserve every modern-tool diagnostic as blocking evidence when present.",
    },
}


_COURSE_SKILL_SEQUENCE = (
    "lab4a_protocol_direct",
    "lab4b_initialization_protocol",
    "lab5_test_mode_scan",
    "lab6_protocol_review",
    "lab7_autofix_scan",
    "lab8_six_chain_topdown",
    "lab9_export_handoff",
    "lab10_topdown_hierarchical",
    "lab12_dftmax_compatibility",
)
