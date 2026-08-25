from dft_agent_flow.agent import (
    _requires_dftc_execution,
    _requires_external_dft_execution,
    _is_external_dft_goal,
    _supervised_dftc_answer,
    _supervised_external_answer,
    make_agent,
)
from dft_agent_flow.runner import FanRunner


def test_agent_exposes_only_constrained_experiment_tools() -> None:
    agent = make_agent(FanRunner())
    assert set(agent.tools) == {
        "final_answer",
        "inspect_benchmark",
        "list_benchmarks",
        "optimize_atpg_goal",
        "run_atpg_profile",
        "list_dftc_labs",
        "teach_dftc_lab",
        "audit_dftc_runtime",
        "compare_dftc_porting_files",
        "dftc_execution_readiness",
        "list_dftc_skills",
        "run_and_verify_dftc_lab_skill",
        "run_all_dftc_labs",
        "list_external_dft_projects",
        "inspect_external_dft_project",
        "external_dft_execution_readiness",
        "diagnose_external_dft_project",
        "run_and_verify_external_dft_flow",
        "attempt_approved_external_dft_repair",
    }


def test_dftc_scope_excludes_unrelated_atpg_tools() -> None:
    agent = make_agent(FanRunner(), scope="dftc")
    assert "run_and_verify_dftc_lab_skill" in agent.tools
    assert "run_all_dftc_labs" in agent.tools
    assert "run_dftc_lab_skill" not in agent.tools
    assert "run_atpg_profile" not in agent.tools


def test_lab4a_execution_guard_recognizes_chinese_and_english_goals() -> None:
    assert _requires_dftc_execution("修复并执行 lab4a_protocol")
    assert _requires_dftc_execution("run the Lab4A repair")
    assert not _requires_dftc_execution("审计 lab4a_protocol 的既有报告")
    assert not _requires_dftc_execution("审计 lab12_dftmax 的运行时证据，并列出阻塞项")
    assert _requires_dftc_execution("运行 lab12_dftmax 的受控技能")


def test_external_execution_guard_requires_a_pinned_catalogue_goal() -> None:
    assert _requires_external_dft_execution("对开源 secworks_aes 从头执行 DFT flow")
    assert _requires_external_dft_execution("run external SHA256 DFT flow")
    assert not _requires_external_dft_execution("讲解 scan insertion 原理")
    assert _is_external_dft_goal("诊断开源 secworks_aes 最近一次 DFT 基线")


def test_supervisor_adds_evidence_blockers_when_model_summary_is_too_short() -> None:
    answer = _supervised_dftc_answer(
        {
            "skill": "lab12_dftmax_compatibility",
            "lab": "lab12_dftmax",
            "evidence_file": "/tmp/evidence.json",
            "cross_validation": {
                "status": "blocked",
                "blockers": ["Acceptance report diagnostic: Error: unsupported option"],
            },
        }
    )

    assert "`blocked`" in answer
    assert "Error: unsupported option" in answer
    assert "/tmp/evidence.json" in answer


def test_supervisor_summarizes_course_without_conflating_unverified_labs() -> None:
    answer = _supervised_dftc_answer(
        {
            "skills_attempted": 2,
            "verified_count": 1,
            "course_status": "completed_with_review_required",
            "results": [
                {"lab": "lab4a_protocol", "cross_validation": {"status": "verified"}},
                {
                    "lab": "lab12_dftmax",
                    "cross_validation": {"status": "blocked", "blockers": ["Error: unsupported option"]},
                },
            ],
        }
    )

    assert "已验证 1/2" in answer
    assert "lab12_dftmax: `blocked`" in answer
    assert "Error: unsupported option" in answer


def test_external_supervisor_uses_validation_status_not_model_prose() -> None:
    answer = _supervised_external_answer(
        {
            "project": "secworks_aes",
            "evidence_file": "/tmp/external-evidence.json",
            "cross_validation": {"status": "blocked", "blockers": ["Tool log diagnostic: Error: bad Tcl"]},
        }
    )

    assert "secworks_aes" in answer
    assert "`blocked`" in answer
    assert "Error: bad Tcl" in answer
