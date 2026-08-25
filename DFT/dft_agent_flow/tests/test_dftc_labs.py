import json
from pathlib import Path

from dft_agent_flow.dftc_labs import DftcLabTutor, _execution_errors


def test_dftc_lesson_and_runtime_audit() -> None:
    tutor = DftcLabTutor()

    lesson = tutor.lesson("lab4a_protocol")
    audit = tutor.audit_runtime("lab4a_protocol")

    assert lesson["topic"] == "RTL test protocol and baseline DFT DRC"
    assert audit["disposition"] == "verified_evidence_present"
    assert all(item["passed"] for item in audit["checks"])


def test_dftc_under_review_evidence_cannot_be_passed() -> None:
    audit = DftcLabTutor().audit_runtime("lab12_dftmax")

    assert audit["disposition"] == "human_review_required"
    assert all(item["passed"] for item in audit["blocking_evidence"])


def test_dftc_executor_is_explicitly_configured() -> None:
    readiness = DftcLabTutor().execution_readiness()

    assert readiness["configured_launcher"] == "/usr/local/bin/dc_shell"
    assert Path(readiness["workspace_root"]).name == "DFTC1_agent_workspaces"


def test_lab4a_direct_skill_is_recommended() -> None:
    skills = DftcLabTutor().list_skills()

    assert skills["skills"][0]["id"] == "lab4a_protocol_direct"
    assert skills["skills"][0]["recommended"] is True
    assert skills["skills"][1]["id"] == "lab4a_protocol_repair"


def _write_skill_evidence(tmp_path: Path, log_text: str = "DFTC completed\n") -> Path:
    workspace = tmp_path / "run"
    lab = workspace / "lab4a_protocol"
    reports = lab / "reports"
    logs = lab / "logs"
    reports.mkdir(parents=True)
    logs.mkdir()
    driver = lab / "agent_baseline_protocol.tcl"
    driver.write_text("quit\n", encoding="utf-8")
    log = logs / "agent_baseline_protocol.log"
    log.write_text(log_text, encoding="utf-8")
    report = reports / "agent_dft_drc.rpt"
    report.write_text("Total violations: 0\n", encoding="utf-8")
    payload = {
        "skill": "lab4a_protocol_direct",
        "status": "review_ready",
        "execution": {
            "workspace": str(workspace),
            "lab_directory": str(lab),
            "driver": str(driver),
            "log": str(log),
            "returncode": 0,
            "timed_out": False,
            "errors": [],
            "completed_cleanly": True,
        },
        "acceptance": [{"path": str(report), "contains": "Total violations: 0", "passed": True}],
    }
    evidence = workspace / "skill_result.json"
    evidence.write_text(json.dumps(payload), encoding="utf-8")
    return evidence


def test_cross_validation_requires_two_stable_independent_reviews(tmp_path: Path) -> None:
    evidence = _write_skill_evidence(tmp_path)
    result = DftcLabTutor(workspace_root=tmp_path).cross_validate_evidence(evidence)

    assert result["status"] == "verified"
    assert result["confirmation"]["rounds"] == 2
    assert result["confirmation"]["stable_snapshot"] is True
    assert all(
        role["passed"]
        for snapshot in result["rounds"]
        for role in snapshot["roles"].values()
    )
    assert Path(result["verification_file"]).is_file()


def test_cross_validation_blocks_tool_diagnostics_even_with_a_passing_report(tmp_path: Path) -> None:
    evidence = _write_skill_evidence(tmp_path, "Error: bad option (CMD-005)\n")
    result = DftcLabTutor(workspace_root=tmp_path).cross_validate_evidence(evidence)

    assert result["status"] == "blocked"
    assert result["rounds"][0]["roles"]["skeptic_auditor"]["passed"] is False


def test_dftc_error_parser_ignores_tcl_configuration_text() -> None:
    output = 'suppress_message "CMD-041 UID-401"\nError: bad option (CMD-005)\nFatal: tool stopped\n'

    assert _execution_errors(output) == ["Error: bad option (CMD-005)", "Fatal: tool stopped"]


def test_workspace_check_can_require_an_error_free_report(tmp_path: Path) -> None:
    report = tmp_path / "reports" / "dft.rpt"
    report.parent.mkdir()
    report.write_text("Error: unsupported report option (CMD-005)\n", encoding="utf-8")

    check = DftcLabTutor._check_workspace(tmp_path, [{"path": "reports/dft.rpt", "no_errors": True}])

    assert check[0]["no_errors"] is True
    assert check[0]["passed"] is False


def test_skill_summary_keeps_verification_decision_and_bounds_detail(tmp_path: Path) -> None:
    evidence = _write_skill_evidence(tmp_path)
    tutor = DftcLabTutor(workspace_root=tmp_path)
    verification = tutor.cross_validate_evidence(evidence)
    result = {
        "skill_execution": json.loads(evidence.read_text(encoding="utf-8")) | {"evidence_file": str(evidence)},
        "cross_validation": verification,
        "conclusion": "evidence_verified",
    }

    summary = tutor.summarize_skill_verification(result)

    assert summary["skill"] == "lab4a_protocol_direct"
    assert summary["execution"]["returncode"] == 0
    assert summary["acceptance"] == [
        {
            "report": "agent_dft_drc.rpt",
            "passed": True,
            "observed_percentage": None,
            "minimum_percentage": None,
            "no_errors": False,
        }
    ]
    assert summary["cross_validation"]["status"] == "verified"
    assert summary["cross_validation"]["stable_snapshot"] is True
