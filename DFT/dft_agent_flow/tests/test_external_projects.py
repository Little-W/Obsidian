import json
from pathlib import Path

import pytest

from dft_agent_flow.external_projects import ExternalDftProjectRunner
from dft_agent_flow.runner import FlowValidationError


def test_catalogue_projects_have_clean_pinned_sources() -> None:
    runner = ExternalDftProjectRunner()
    projects = runner.list_projects()["projects"]

    assert [project["id"] for project in projects] == [
        "secworks_aes",
        "secworks_sha256",
        "freecores_i2c",
    ]
    for project in projects:
        inspected = runner.inspect_project(project["id"])
        assert inspected["commit_observed"] == inspected["commit_expected"]
        assert inspected["source_clean"] is True
        assert inspected["all_rtl_sources_exist"] is True


def test_generated_driver_uses_only_staged_rtl_and_supported_modern_template(tmp_path: Path) -> None:
    runner = ExternalDftProjectRunner(workspace_root=tmp_path)
    project = runner._project("secworks_aes")
    flow_directory = tmp_path / "flow"
    flow_directory.mkdir()

    driver = runner._driver(project, flow_directory)

    assert "report_design -summary" not in driver
    assert "-port scan_enable" not in driver
    assert "insert_dft" in driver
    assert str(flow_directory / "rtl" / "aes.v") in driver


def test_i2c_legacy_pragma_transform_is_staged_only(tmp_path: Path) -> None:
    runner = ExternalDftProjectRunner(workspace_root=tmp_path)
    staged = runner.stage_project("freecores_i2c")
    bit_controller = Path(staged["lab_directory"]) / "rtl" / "i2c_master_bit_ctrl.v"
    source = runner.sources_root / "freecores_i2c" / "rtl" / "verilog" / "i2c_master_bit_ctrl.v"

    assert "// legacy enum_state" in bit_controller.read_text(encoding="utf-8")
    assert "// synopsys enum_state" in source.read_text(encoding="utf-8")
    assert staged["staging_transforms"][0]["id"] == "disable_legacy_enum_state_pragma"


def test_unknown_external_repair_action_is_rejected() -> None:
    runner = ExternalDftProjectRunner()
    with pytest.raises(FlowValidationError):
        runner.attempt_approved_repair_summary("secworks_aes", "write_arbitrary_tcl")


def test_diagnosis_returns_no_automatic_action_for_verified_evidence(tmp_path: Path) -> None:
    runner = ExternalDftProjectRunner(workspace_root=tmp_path)
    workspace = tmp_path / "run"
    flow = workspace / "flow"
    reports = flow / "reports"
    logs = flow / "logs"
    reports.mkdir(parents=True)
    logs.mkdir()
    driver = flow / "agent_external_baseline.tcl"
    log = logs / "agent_external_baseline.log"
    report = reports / "post_dft_drc.rpt"
    driver.write_text("quit\n", encoding="utf-8")
    log.write_text("done\n", encoding="utf-8")
    report.write_text("DRC\n", encoding="utf-8")
    payload = {
        "status": "review_ready",
        "source": {"project": "secworks_aes"},
        "execution": {
            "workspace": str(workspace),
            "lab_directory": str(flow),
            "driver": str(driver),
            "log": str(log),
            "returncode": 0,
            "timed_out": False,
            "errors": [],
            "completed_cleanly": True,
        },
        "acceptance": [{"path": str(report), "contains": "DRC", "passed": True}],
    }
    evidence = workspace / "skill_result.json"
    evidence.write_text(json.dumps(payload), encoding="utf-8")

    diagnosis = runner.diagnose_project("secworks_aes")

    assert diagnosis["recommended_action"] == "none"
    assert diagnosis["approved_actions"] == []
