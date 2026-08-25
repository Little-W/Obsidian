from __future__ import annotations

import hashlib
import json
import shutil
import subprocess
from datetime import datetime, timezone
from pathlib import Path
from typing import Any
from uuid import uuid4

from .config import (
    DFTC_REFERENCE_LIBRARY_DIR,
    DFTC_SHELL,
    EXTERNAL_DFT_WORKSPACES_ROOT,
    EXTERNAL_PROJECT_MANIFEST_FILE,
    EXTERNAL_SOURCES_ROOT,
)
from .dftc_labs import DftcLabTutor, _execution_errors
from .runner import FlowValidationError


class ExternalDftProjectRunner:
    """Run a fixed DFT baseline over a pinned, read-only external RTL catalogue."""

    def __init__(
        self,
        manifest_file: Path = EXTERNAL_PROJECT_MANIFEST_FILE,
        sources_root: Path = EXTERNAL_SOURCES_ROOT,
        workspace_root: Path = EXTERNAL_DFT_WORKSPACES_ROOT,
        dc_shell: Path = DFTC_SHELL,
        reference_library_dir: Path = DFTC_REFERENCE_LIBRARY_DIR,
    ) -> None:
        self.manifest_file = manifest_file
        self.sources_root = sources_root
        self.workspace_root = workspace_root
        self.dc_shell = dc_shell
        self.reference_library_dir = reference_library_dir
        self.manifest = json.loads(manifest_file.read_text(encoding="utf-8"))
        self._projects = {project["id"]: project for project in self.manifest["projects"]}
        self._validator = DftcLabTutor(workspace_root=workspace_root)

    def list_projects(self) -> dict[str, Any]:
        return {
            "catalogue_version": self.manifest["catalogue_version"],
            "source_policy": self.manifest["source_policy"],
            "projects": [
                {
                    "id": project["id"],
                    "title": project["title"],
                    "top": project["top"],
                    "commit": project["commit"],
                    "rtl_file_count": len(project["rtl_sources"]),
                    "minimum_estimated_coverage": project["minimum_estimated_coverage"],
                }
                for project in self._projects.values()
            ],
        }

    def inspect_project(self, project_id: str) -> dict[str, Any]:
        project = self._project(project_id)
        source_root = self._source_root(project_id)
        sources = [self._source_path(source_root, relative) for relative in project["rtl_sources"]]
        return {
            "id": project_id,
            "title": project["title"],
            "repository": project["repository"],
            "commit_expected": project["commit"],
            "commit_observed": self._git_output(source_root, "rev-parse", "HEAD") if source_root.is_dir() else None,
            "source_clean": self._is_clean_source(source_root),
            "top": project["top"],
            "clock": project["clock"],
            "reset": project["reset"],
            "minimum_estimated_coverage": project["minimum_estimated_coverage"],
            "rtl_sources": [str(path) for path in sources],
            "all_rtl_sources_exist": all(path.is_file() for path in sources),
            "source_is_read_only_input": True,
        }

    def execution_readiness(self) -> dict[str, Any]:
        launcher_ready = self.dc_shell.is_file() and bool(self.dc_shell.stat().st_mode & 0o111)
        library = self.reference_library_dir / "sc_max.db"
        return {
            "ready": bool(launcher_ready and library.is_file() and self.sources_root.is_dir()),
            "configured_launcher": str(self.dc_shell),
            "reference_library": str(library),
            "workspace_root": str(self.workspace_root),
            "message": (
                "The external DFT executor is available. Every run will use a generated driver in a new workspace."
                if launcher_ready and library.is_file()
                else "dc_shell or sc_max.db is unavailable; no external DFT execution can be claimed."
            ),
        }

    def diagnose_project(self, project_id: str) -> dict[str, Any]:
        """Classify the latest evidence and expose only approved next actions."""
        self._project(project_id)
        evidence_file = self._latest_evidence_file(project_id)
        if evidence_file is None:
            return {
                "project": project_id,
                "diagnosis": "No prior staged evidence exists.",
                "recommended_action": "run_current_baseline",
                "approved_actions": ["run_current_baseline"],
                "requires_engineer": False,
            }

        verification = self._validator.cross_validate_evidence(evidence_file)
        payload = json.loads(evidence_file.read_text(encoding="utf-8"))
        execution = payload.get("execution", {})
        diagnostics = list(execution.get("errors", []))
        if verification["status"] == "verified":
            return {
                "project": project_id,
                "evidence_file": str(evidence_file),
                "cross_validation": verification["status"],
                "diagnosis": "The latest generated baseline has stable verified evidence; no automatic repair is warranted.",
                "recommended_action": "none",
                "approved_actions": [],
                "requires_engineer": True,
            }
        known_remedy = self._known_remedy(diagnostics)
        if known_remedy:
            return {
                "project": project_id,
                "evidence_file": str(evidence_file),
                "cross_validation": verification["status"],
                "diagnosis": known_remedy["diagnosis"],
                "recommended_action": known_remedy["action"],
                "approved_actions": [known_remedy["action"]],
                "requires_engineer": False,
            }
        return {
            "project": project_id,
            "evidence_file": str(evidence_file),
            "cross_validation": verification["status"],
            "diagnosis": "The failure is not in the approved compatibility catalogue. Preserve evidence and request DFT-engineer review.",
            "diagnostics": diagnostics[:8],
            "recommended_action": "engineer_review",
            "approved_actions": [],
            "requires_engineer": True,
        }

    def attempt_approved_repair_summary(self, project_id: str, action: str) -> dict[str, Any]:
        """Apply one bounded, catalogued template remedy in a fresh workspace."""
        diagnosis = self.diagnose_project(project_id)
        if action not in diagnosis["approved_actions"]:
            raise FlowValidationError(
                f"Action '{action}' is not approved for {project_id}; use diagnose_external_dft_project first"
            )
        # The two current remedies are encoded in the generated V-2023.12 driver:
        # report_design has no unsupported option and DFTC creates its own scan ports.
        result = self.run_and_verify_summary(project_id)
        return {"diagnosis": diagnosis, "repair_action": action, "result": result}

    def run_project(self, project_id: str) -> dict[str, Any]:
        """Stage one listed project and execute the fixed baseline only."""
        if not self.execution_readiness()["ready"]:
            raise RuntimeError("The external DFT executor is unavailable")
        project = self._project(project_id)
        staged = self.stage_project(project_id)
        flow_directory = Path(staged["lab_directory"])
        driver_path = flow_directory / "agent_external_baseline.tcl"
        driver_path.write_text(self._driver(project, flow_directory), encoding="utf-8")
        command = [str(self.dc_shell), "-no_gui", "-f", driver_path.name]
        try:
            result = subprocess.run(
                command,
                cwd=flow_directory,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT,
                timeout=1_200,
                check=False,
            )
            output = result.stdout
            timed_out = False
        except subprocess.TimeoutExpired as exc:
            output = (exc.stdout or "") + "\nExternal DFT runner timed out after 1200 seconds.\n"
            result = None
            timed_out = True

        log_path = flow_directory / "logs" / "agent_external_baseline.log"
        log_path.write_text(output, encoding="utf-8", errors="replace")
        errors = _execution_errors(output)
        acceptance = DftcLabTutor._check_workspace(flow_directory, self._acceptance(project))
        execution = {
            **staged,
            "project": project_id,
            "flow": "generated_external_baseline",
            "driver": str(driver_path),
            "command": command,
            "log": str(log_path),
            "returncode": None if timed_out else result.returncode,
            "timed_out": timed_out,
            "errors": errors[:40],
            "completed_cleanly": not timed_out and result is not None and result.returncode == 0 and not errors,
        }
        payload = {
            "skill": f"external_{project_id}_baseline",
            "status": "review_ready"
            if execution["completed_cleanly"] and all(item["passed"] for item in acceptance)
            else "execution_incomplete",
            "execution": execution,
            "acceptance": acceptance,
            "source": {
                "project": project_id,
                "repository": project["repository"],
                "commit": project["commit"],
                "rtl_sources": project["rtl_sources"],
            },
            "approval": "A DFT engineer must review timing constraints, scan architecture, DRC classes, and ATPG before accepting this external design.",
        }
        evidence_file = Path(staged["workspace"]) / "skill_result.json"
        evidence_file.write_text(json.dumps(payload, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        return {**payload, "evidence_file": str(evidence_file)}

    def run_and_verify_summary(self, project_id: str) -> dict[str, Any]:
        result = self.run_project(project_id)
        verification = self._validator.cross_validate_evidence(Path(result["evidence_file"]))
        summary = DftcLabTutor.summarize_skill_verification(
            {
                "skill_execution": result,
                "cross_validation": verification,
                "conclusion": "evidence_verified" if verification["status"] == "verified" else "not_verified",
            }
        )
        return {
            "project": project_id,
            "source": result["source"],
            **summary,
            "approval": result["approval"],
        }

    def stage_project(self, project_id: str) -> dict[str, Any]:
        project = self._project(project_id)
        source_root = self._source_root(project_id)
        expected_commit = project["commit"]
        observed_commit = self._git_output(source_root, "rev-parse", "HEAD")
        if observed_commit != expected_commit:
            raise FlowValidationError(
                f"Pinned source commit mismatch for {project_id}: expected {expected_commit}, observed {observed_commit or 'missing'}"
            )
        if not self._is_clean_source(source_root):
            raise FlowValidationError(f"Pinned source {project_id} has local changes; restore a clean clone before staging")

        run_id = f"{datetime.now(timezone.utc):%Y%m%dT%H%M%SZ}_{project_id}_{uuid4().hex[:8]}"
        workspace = self.workspace_root / run_id
        flow_directory = workspace / "flow"
        rtl_directory = flow_directory / "rtl"
        for directory in (rtl_directory, flow_directory / "logs", flow_directory / "reports", flow_directory / "mapped_scan"):
            directory.mkdir(parents=True, exist_ok=True)

        staged_sources: list[dict[str, str]] = []
        for relative in project["rtl_sources"]:
            source = self._source_path(source_root, relative)
            if not source.is_file():
                raise FileNotFoundError(f"Pinned RTL source is unavailable: {source}")
            destination = rtl_directory / source.name
            if destination.exists():
                raise FlowValidationError(f"Duplicate staged RTL filename is not allowed: {source.name}")
            shutil.copy2(source, destination)
            staged_sources.append(
                {
                    "source": str(source),
                    "staged": str(destination),
                    "sha256": self._sha256(destination),
                }
            )
        transforms = self._apply_staging_transforms(project, rtl_directory)
        metadata = {
            "run_id": run_id,
            "project": project_id,
            "repository": project["repository"],
            "source_commit": observed_commit,
            "created_at": datetime.now(timezone.utc).isoformat(timespec="seconds"),
            "staged_sources": staged_sources,
            "staging_transforms": transforms,
        }
        (workspace / "stage.json").write_text(json.dumps(metadata, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        return {**metadata, "workspace": str(workspace), "lab_directory": str(flow_directory)}

    def _project(self, project_id: str) -> dict[str, Any]:
        try:
            return self._projects[project_id]
        except KeyError as exc:
            choices = ", ".join(sorted(self._projects))
            raise FlowValidationError(f"Unsupported external DFT project '{project_id}'. Allowed: {choices}") from exc

    def _source_root(self, project_id: str) -> Path:
        candidate = (self.sources_root / project_id).resolve()
        if not self._is_within(candidate, self.sources_root):
            raise FlowValidationError("External source path escapes the approved source root")
        return candidate

    def _source_path(self, source_root: Path, relative: str) -> Path:
        if Path(relative).is_absolute() or Path(relative).suffix not in {".v", ".sv"}:
            raise FlowValidationError(f"Unsupported RTL source entry: {relative}")
        candidate = (source_root / relative).resolve()
        if not self._is_within(candidate, source_root):
            raise FlowValidationError(f"RTL source escapes pinned repository: {relative}")
        return candidate

    def _driver(self, project: dict[str, Any], flow_directory: Path) -> str:
        rtl_directory = flow_directory / "rtl"
        files = [rtl_directory / Path(relative).name for relative in project["rtl_sources"]]
        file_list = " ".join(self._tcl_atom(path) for path in files)
        scan_output = f"{project['top']}_scan"
        return "\n".join(
            [
                "# Generated by dft_agent_flow. Do not edit: execution uses a fresh workspace.",
                f"set search_path [list . {self._tcl_atom(self.reference_library_dir)} {self._tcl_atom(rtl_directory)}]",
                "set target_library [list sc_max.db]",
                "set link_library [concat * $target_library dw_foundation.sldb]",
                "define_design_lib DEFAULT -path ./analyzed",
                f"analyze -format verilog [list {file_list}]",
                f"elaborate {project['top']}",
                f"current_design {project['top']}",
                "link",
                "redirect -tee reports/read_link.rpt {report_design}",
                f"create_clock -period 10 [get_ports {{{project['clock']}}}]",
                f"set_dft_signal -view existing_dft -type ScanClock -timing {{45 55}} -port {{{project['clock']}}}",
                f"set_dft_signal -view existing_dft -type Reset -active_state {project['reset_active_state']} -port {{{project['reset']}}}",
                "set_scan_configuration -chain_count 1",
                "compile -map_effort medium",
                "create_test_protocol",
                "redirect -tee reports/pre_dft_drc.rpt {dft_drc -coverage_estimate}",
                "redirect -tee reports/preview_dft.rpt {preview_dft -show scan_summary}",
                "insert_dft",
                "redirect -tee reports/post_dft_drc.rpt {dft_drc -coverage_estimate}",
                "redirect -tee reports/scan_path.rpt {report_scan_path -view existing_dft}",
                f"write -format ddc -hierarchy -output mapped_scan/{scan_output}.ddc",
                f"write -format verilog -hierarchy -output mapped_scan/{scan_output}.v",
                f"write_test_protocol -output mapped_scan/{scan_output}.spf",
                "quit",
                "",
            ]
        )

    def _latest_evidence_file(self, project_id: str) -> Path | None:
        if not self.workspace_root.is_dir():
            return None
        candidates = sorted(
            self.workspace_root.glob("*/skill_result.json"),
            key=lambda path: path.stat().st_mtime,
            reverse=True,
        )
        for candidate in candidates:
            try:
                payload = json.loads(candidate.read_text(encoding="utf-8"))
            except (OSError, json.JSONDecodeError):
                continue
            if payload.get("source", {}).get("project") == project_id:
                return candidate
        return None

    @staticmethod
    def _known_remedy(diagnostics: list[str]) -> dict[str, str] | None:
        joined = "\n".join(diagnostics)
        if "unknown option '-summary'" in joined:
            return {
                "action": "rerun_modern_report_design",
                "diagnosis": "Current DC rejects report_design -summary; rerun the approved V-2023.12 driver using report_design without that option.",
            }
        if "Value for list '-port' must have 1 elements" in joined:
            return {
                "action": "rerun_with_automatic_scan_ports",
                "diagnosis": "The requested ScanEnable port is not a design port; rerun the approved driver and let insert_dft create the supported test ports.",
            }
        if "Syntax error at or near token 'enum_state'" in joined:
            return {
                "action": "rerun_without_legacy_enum_state_pragma",
                "diagnosis": "The legacy Synopsys enum_state comment is parsed as an unsupported pragma by the current HDL reader; rerun with the approved staged-only compatibility transform.",
            }
        return None

    @staticmethod
    def _apply_staging_transforms(project: dict[str, Any], rtl_directory: Path) -> list[dict[str, Any]]:
        applied: list[dict[str, Any]] = []
        for transform in project.get("staging_transforms", []):
            if transform != "disable_legacy_enum_state_pragma":
                raise FlowValidationError(f"Unsupported approved staging transform: {transform}")
            changed_files: list[str] = []
            for filename in ("i2c_master_bit_ctrl.v", "i2c_master_byte_ctrl.v"):
                path = rtl_directory / filename
                text = path.read_text(encoding="utf-8", errors="strict")
                original = "// synopsys enum_state"
                count = text.count(original)
                if count != 1:
                    raise FlowValidationError(
                        f"Expected exactly one legacy enum_state pragma in staged {filename}, found {count}"
                    )
                path.write_text(text.replace(original, "// legacy enum_state", 1), encoding="utf-8")
                changed_files.append(filename)
            applied.append({"id": transform, "files": changed_files})
        return applied

    @staticmethod
    def _acceptance(project: dict[str, Any]) -> list[dict[str, Any]]:
        scan_output = f"{project['top']}_scan"
        return [
            {"path": "reports/read_link.rpt", "contains": project["top"], "no_errors": True},
            {"path": "reports/pre_dft_drc.rpt", "contains": "DRC", "no_errors": True},
            {"path": "reports/preview_dft.rpt", "contains": "Scan", "no_errors": True},
            {
                "path": "reports/post_dft_drc.rpt",
                "contains": "DRC",
                "no_errors": True,
                "minimum_percentage": project["minimum_estimated_coverage"],
                "blocking": True,
            },
            {"path": f"mapped_scan/{scan_output}.ddc"},
            {"path": f"mapped_scan/{scan_output}.spf"},
        ]

    @staticmethod
    def _tcl_atom(path: Path) -> str:
        value = str(path.resolve())
        if any(character in value for character in "{}[]$;\\\n"):
            raise FlowValidationError(f"Unsafe path for generated Tcl: {value}")
        return "{" + value + "}"

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
            for block in iter(lambda: handle.read(1 << 16), b""):
                digest.update(block)
        return digest.hexdigest()

    @staticmethod
    def _git_output(source_root: Path, *args: str) -> str | None:
        if not source_root.is_dir():
            return None
        result = subprocess.run(
            ["git", "-C", str(source_root), *args],
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
            check=False,
        )
        return result.stdout.strip() if result.returncode == 0 else None

    def _is_clean_source(self, source_root: Path) -> bool:
        status = self._git_output(source_root, "status", "--porcelain")
        return status == ""
