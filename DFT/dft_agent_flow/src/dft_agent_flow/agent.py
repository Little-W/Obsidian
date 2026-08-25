from __future__ import annotations

import json
import re
import uuid
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

from .config import (
    AGENT_RUNTIME_POLICY_FILE,
    DEFAULT_MODEL,
    EPISODES_ROOT,
    OLLAMA_API_BASE,
)
from .dftc_labs import DftcLabTutor
from .external_projects import ExternalDftProjectRunner
from .runner import FanRunner, Goal


def _system_instructions() -> str:
    return AGENT_RUNTIME_POLICY_FILE.read_text(encoding="utf-8")


def _json(payload: Any) -> str:
    return json.dumps(payload, ensure_ascii=False, indent=2)


def _tool_trace(agent: Any) -> list[dict[str, Any]]:
    trace = []
    for step in agent.memory.get_succinct_steps():
        for call in step.get("tool_calls", []):
            function = call.get("function", {})
            trace.append(
                {
                    "step": step.get("step_number"),
                    "name": function.get("name"),
                    "arguments": function.get("arguments"),
                }
            )
    return trace


def _supervised_dftc_answer(execution_result: dict[str, Any]) -> str:
    """Render the evidence conclusion deterministically after a mutating Agent tool call."""
    if "course_status" in execution_result:
        results = execution_result.get("results", [])
        unresolved = [
            item
            for item in results
            if item.get("cross_validation", {}).get("status") != "verified"
        ]
        lines = [
            "受控核验：完整 DFTC 课程已执行。"
            f"已验证 {execution_result.get('verified_count', 0)}/{execution_result.get('skills_attempted', 0)} 个 Lab；"
            f"课程状态为 `{execution_result.get('course_status')}`。"
        ]
        for item in unresolved:
            verification = item.get("cross_validation", {})
            blockers = verification.get("blockers", [])
            detail = f"{item.get('lab', item.get('skill', 'unknown'))}: `{verification.get('status', 'not_verified')}`"
            if blockers:
                detail += f"；阻塞项：{blockers[0]}"
            lines.append(detail)
        lines.append("该结论仅代表执行证据；每个课程 Lab 仍需 DFT 工程师最终签核。")
        return "\n".join(lines)

    verification = execution_result.get("cross_validation", {})
    status = verification.get("status", "not_verified")
    execution = execution_result.get("execution", {})
    lines = [
        f"受控核验：{execution_result.get('lab', execution_result.get('skill', 'unknown'))} 的交叉验证状态为 `{status}`。"
    ]
    if status == "verified":
        lines.append("执行证据已通过两轮稳定交叉验证；课程 Lab 仍需 DFT 工程师最终签核。")
    else:
        for blocker in verification.get("blockers", [])[:3]:
            lines.append(f"阻塞项：{blocker}")
        lines.append(f"证据：{execution_result.get('evidence_file', 'unavailable')}")
    return "\n".join(lines)


def _requires_dftc_execution(goal: str) -> bool:
    normalized = goal.lower()
    if "lab" not in normalized:
        return False
    audit_markers = ("审计", "audit", "讲解", "teach", "比较", "compare", "diff")
    explicit_execution = any(
        word in normalized for word in ("执行", "修复", "复跑", "重新运行", "重新跑", "repair", "execute", "rerun")
    ) or bool(re.search(r"(?:\brun(?:\s+the)?\b|运行)\s*(?:dftc\s*)?lab", normalized))
    if any(marker in normalized for marker in audit_markers) and not explicit_execution:
        return False
    return explicit_execution


def _requires_external_dft_execution(goal: str) -> bool:
    normalized = goal.lower()
    external_markers = ("开源", "external", "secworks", "freecores", "aes", "sha256", "i2c")
    execution_markers = ("执行", "运行", "从头", "跑", "execute", "run", "flow")
    return any(marker in normalized for marker in external_markers) and any(
        marker in normalized for marker in execution_markers
    )


def _is_external_dft_goal(goal: str) -> bool:
    normalized = goal.lower()
    return any(marker in normalized for marker in ("开源", "external", "secworks", "freecores", "aes", "sha256", "i2c"))


def _external_project_id(goal: str, external_runner: ExternalDftProjectRunner) -> str | None:
    normalized = goal.lower()
    matches = [
        project["id"]
        for project in external_runner.list_projects()["projects"]
        if project["id"].lower() in normalized
    ]
    return matches[0] if len(matches) == 1 else None


def _supervised_external_answer(execution_result: dict[str, Any]) -> str:
    """Render an external DFT conclusion from evidence, never model narration."""
    verification = execution_result.get("cross_validation", {})
    status = verification.get("status", "not_verified")
    execution = execution_result.get("execution", {})
    project = execution_result.get("project", "unknown")
    lines = [f"受控核验：开源项目 `{project}` 的从零 DFT 基线状态为 `{status}`。"]
    if status == "verified":
        lines.append("生成的 DFT 流、报告和两轮独立取证均一致；仍需 DFT 工程师完成约束与 ATPG 签核。")
    else:
        for blocker in verification.get("blockers", [])[:3]:
            lines.append(f"阻塞项：{blocker}")
        lines.append(f"证据：{execution_result.get('evidence_file', 'unavailable')}")
    return "\n".join(lines)


def make_agent(
    runner: FanRunner,
    dftc_tutor: DftcLabTutor | None = None,
    external_runner: ExternalDftProjectRunner | None = None,
    model_name: str = DEFAULT_MODEL,
    api_base: str = OLLAMA_API_BASE,
    scope: str = "all",
    execution_results: list[dict[str, Any]] | None = None,
):
    """Build a ToolCallingAgent whose only mutating action is a validated FAN run."""
    try:
        from smolagents import OpenAIModel, ToolCallingAgent, tool
    except ImportError as exc:  # pragma: no cover - installation error path
        raise RuntimeError("Install the project dependencies before using the agent") from exc

    dftc_tutor = dftc_tutor or DftcLabTutor()
    external_runner = external_runner or ExternalDftProjectRunner()

    @tool
    def list_benchmarks() -> str:
        """List the available ISCAS benchmark circuits and approved ATPG profiles.

        Returns:
            A JSON object describing the allowed benchmark circuits and profiles.
        """
        from .config import PROFILES, available_circuits

        return _json({"circuits": available_circuits(), "profiles": sorted(PROFILES)})

    @tool
    def inspect_benchmark(circuit: str) -> str:
        """Inspect a benchmark before running it.

        Args:
            circuit: Exact circuit identifier returned by list_benchmarks, for example s27.

        Returns:
            A JSON object with the netlist metadata and allowed profiles.
        """
        return _json(runner.inspect(circuit))

    @tool
    def run_atpg_profile(circuit: str, profile: str) -> str:
        """Run one approved FAN_ATPG compression profile in an isolated artifact directory.

        Args:
            circuit: Exact circuit identifier returned by list_benchmarks.
            profile: One of none, static, or static_dynamic.

        Returns:
            A JSON object with the actual parsed report metrics and artifact locations.
        """
        return _json(runner.result_dict(runner.run(circuit, profile)))

    @tool
    def optimize_atpg_goal(circuit: str, min_coverage: float, max_patterns: int) -> str:
        """Evaluate every approved profile and select the best one for a hard ATPG goal.

        Args:
            circuit: Exact circuit identifier returned by list_benchmarks.
            min_coverage: Required fault coverage percentage from 0 to 100.
            max_patterns: Largest acceptable number of patterns. Use 0 for no upper limit.

        Returns:
            A JSON object containing all actual measurements, the selected profile, and whether the goal was met.
        """
        goal = Goal(min_coverage=min_coverage, max_patterns=max_patterns or None)
        return _json(runner.optimize(circuit, goal))

    @tool
    def list_dftc_labs() -> str:
        """List the DFTC1 official course labs and their current evidence state.

        Returns:
            A JSON object with lab identifiers, topics, states, and evidence policy.
        """
        catalog = dftc_tutor.list_labs()
        return _json(
            {
                "course": catalog["course"],
                "labs": [{"id": lab["id"], "state": lab["state"]} for lab in catalog["labs"]],
                "next_step": "Use list_dftc_skills before any execution, or teach_dftc_lab for the full lesson.",
            }
        )

    @tool
    def teach_dftc_lab(lab: str) -> str:
        """Teach one DFTC1 lab before reviewing or executing it.

        Args:
            lab: Exact identifier from list_dftc_labs, such as lab4a_protocol.

        Returns:
            A JSON lesson with objectives, workflow, porting notes, and acceptance criteria.
        """
        return _json(dftc_tutor.lesson(lab))

    @tool
    def audit_dftc_runtime(lab: str) -> str:
        """Audit the recorded V-2023.12-SP3 DFTC evidence for one lab without modifying it.

        Args:
            lab: Exact identifier from list_dftc_labs.

        Returns:
            A JSON object containing evidence checks and the allowed conclusion.
        """
        return _json(dftc_tutor.audit_runtime(lab))

    @tool
    def compare_dftc_porting_files(lab: str) -> str:
        """Compare selected official DFTC source files with the recorded modern port.

        Args:
            lab: Exact identifier from list_dftc_labs.

        Returns:
            A JSON diff preview. This never writes either source tree.
        """
        return _json(dftc_tutor.compare_porting_files(lab))

    @tool
    def dftc_execution_readiness() -> str:
        """Check whether the approved dc_shell-based, isolated DFTC executor is available.

        Returns:
            A JSON readiness report with the workspace location and safety policy.
        """
        return _json(dftc_tutor.execution_readiness())

    @tool
    def list_dftc_skills() -> str:
        """List approved multi-step DFTC repair skills.

        Returns:
            A JSON object with skill identifiers and their restricted purpose.
        """
        skills = dftc_tutor.list_skills()["skills"]
        return _json(
            {
                "skills": [
                    {"id": skill["id"], "lab": skill["lab"], "recommended": skill["recommended"]}
                    for skill in skills
                ],
                "next_step": "For one Lab call run_and_verify_dftc_lab_skill. For the complete course call run_all_dftc_labs once.",
            }
        )

    @tool
    def run_dftc_lab_skill(skill_id: str) -> str:
        """Execute a reviewed DFTC repair skill in fresh isolated workspaces.

        Args:
            skill_id: Exact identifier from list_dftc_skills, for example lab4a_protocol_repair.

        Returns:
            A JSON evidence bundle with every run, log, parsed errors, and acceptance checks.
        """
        return _json(dftc_tutor.run_skill(skill_id))

    @tool
    def run_and_verify_dftc_lab_skill(skill_id: str) -> str:
        """Execute one approved DFTC skill and cross-validate its evidence twice.

        Args:
            skill_id: Exact identifier returned by list_dftc_skills. For a normal Lab 4A run, use lab4a_protocol_direct.

        Returns:
            A bounded JSON summary containing the staged execution status, acceptance results, and two independent validation rounds. Full logs remain in the returned evidence paths. Only cross_validation.status=verified is evidence-verified.
        """
        result = dftc_tutor.run_skill_and_verify_summary(skill_id)
        if execution_results is not None:
            execution_results.append(result)
        return _json(result)

    @tool
    def run_all_dftc_labs() -> str:
        """Run every reviewed DFTC course skill and cross-validate each Lab twice.

        Returns:
            A bounded per-Lab evidence summary. A blocked Lab is recorded as blocked; the tool never turns an incomplete or error-containing run into a pass.
        """
        result = dftc_tutor.run_all_skills_and_verify()
        if execution_results is not None:
            execution_results.append(result)
        return _json(result)

    @tool
    def run_dftc_lab_flow(lab: str, flow: str, variant: str) -> str:
        """Run one approved, generated DFTC flow in a new isolated workspace.

        Args:
            lab: Exact identifier from list_dftc_labs.
            flow: Exact approved flow returned by the lesson. For lab4a_protocol, use official_baseline to reproduce the legacy issue or baseline_protocol for the reviewed target-library repair.
            variant: official for the unmodified course source, or ported to overlay only recorded compatibility fixes.

        Returns:
            A JSON object with the staged workspace, command, log, parsed errors, and review requirement.
        """
        return _json(dftc_tutor.run_lab(lab, flow, variant))

    @tool
    def list_external_dft_projects() -> str:
        """List the commit-pinned open-source RTL projects approved for a generated DFT baseline.

        Returns:
            A JSON catalogue with project IDs, repositories, commits, and top modules.
        """
        return _json(external_runner.list_projects())

    @tool
    def inspect_external_dft_project(project_id: str) -> str:
        """Inspect one approved external RTL source without executing repository scripts.

        Args:
            project_id: Exact project identifier from list_external_dft_projects.

        Returns:
            A JSON source-integrity and RTL manifest report.
        """
        return _json(external_runner.inspect_project(project_id))

    @tool
    def external_dft_execution_readiness() -> str:
        """Check whether the generated external DFT executor and reference library are available.

        Returns:
            A JSON readiness report. This never starts a flow.
        """
        return _json(external_runner.execution_readiness())

    @tool
    def diagnose_external_dft_project(project_id: str) -> str:
        """Diagnose the most recent external DFT evidence and list only approved recovery actions.

        Args:
            project_id: Exact identifier from list_external_dft_projects.

        Returns:
            A JSON diagnosis based on logs and double validation, not on model speculation.
        """
        return _json(external_runner.diagnose_project(project_id))

    @tool
    def run_and_verify_external_dft_flow(project_id: str) -> str:
        """Run the generated baseline DFT flow for one pinned external project and verify it twice.

        Args:
            project_id: Exact identifier from list_external_dft_projects.

        Returns:
            A bounded evidence summary. Only cross_validation.status=verified means the run has evidence; a blocked result must not be described as complete.
        """
        result = external_runner.run_and_verify_summary(project_id)
        if execution_results is not None:
            execution_results.append(result)
        return _json(result)

    @tool
    def attempt_approved_external_dft_repair(project_id: str, action: str) -> str:
        """Apply one diagnosis-approved compatibility remedy and re-run in a new workspace.

        Args:
            project_id: Exact identifier from list_external_dft_projects.
            action: Exact action returned by diagnose_external_dft_project.

        Returns:
            A JSON record of the diagnosis, approved repair selection, fresh run, and double validation.
        """
        result = external_runner.attempt_approved_repair_summary(project_id, action)
        if execution_results is not None:
            execution_results.append(result["result"])
        return _json(result)

    openai_base = api_base.rstrip("/")
    if not openai_base.endswith("/v1"):
        openai_base = f"{openai_base}/v1"
    model = OpenAIModel(
        model_id=model_name,
        api_base=openai_base,
        api_key="ollama",
        temperature=0.1,
        max_tokens=128,
        # Qwen3's hidden reasoning is costly after a deterministic tool has
        # already returned the complete evidence bundle.
        extra_body={"think": False},
    )
    fan_tools = [list_benchmarks, inspect_benchmark, run_atpg_profile, optimize_atpg_goal]
    dftc_tools = [
        list_dftc_labs,
        teach_dftc_lab,
        audit_dftc_runtime,
        compare_dftc_porting_files,
        dftc_execution_readiness,
        list_dftc_skills,
        run_and_verify_dftc_lab_skill,
        run_all_dftc_labs,
    ]
    external_tools = [
        list_external_dft_projects,
        inspect_external_dft_project,
        external_dft_execution_readiness,
        diagnose_external_dft_project,
        run_and_verify_external_dft_flow,
        attempt_approved_external_dft_repair,
    ]
    if scope == "fan":
        tools = fan_tools
    elif scope == "dftc":
        tools = dftc_tools
    elif scope == "external":
        tools = external_tools
    elif scope == "all":
        tools = fan_tools + dftc_tools + external_tools
    else:
        raise ValueError("Agent scope must be one of: all, fan, dftc, external")
    return ToolCallingAgent(
        tools=tools,
        model=model,
        instructions=_system_instructions(),
        max_steps=6,
        add_base_tools=False,
        name="dft_atpg_agent",
        description="A constrained local assistant for FAN_ATPG, supervised DFTC labs, and commit-pinned external RTL DFT baselines.",
    )


def run_agent(
    goal: str,
    runner: FanRunner | None = None,
    model_name: str = DEFAULT_MODEL,
    api_base: str = OLLAMA_API_BASE,
) -> dict[str, str]:
    runner = runner or FanRunner()
    normalized_goal = goal.lower()
    if "dftc" in normalized_goal or "lab" in normalized_goal:
        scope = "dftc"
    elif _is_external_dft_goal(goal):
        scope = "external"
    else:
        scope = "fan"
    execution_results: list[dict[str, Any]] = []
    dftc_tutor = DftcLabTutor() if scope == "dftc" else None
    external_runner = ExternalDftProjectRunner() if scope == "external" else None
    if scope == "external" and external_runner is not None:
        project_id = _external_project_id(goal, external_runner)
        if project_id is None:
            answer = "开源 DFT 目标必须包含一个精确的已批准项目 ID；请先调用 external-list。"
            model_answer = "Policy agent rejected an ambiguous external project selection."
            tool_trace: list[dict[str, Any]] = []
        elif _requires_external_dft_execution(goal):
            execution = external_runner.run_and_verify_summary(project_id)
            answer = _supervised_external_answer(execution)
            model_answer = "Policy agent executed the constrained external DFT skill."
            tool_trace = [{"step": 1, "name": "run_and_verify_external_dft_flow", "arguments": {"project_id": project_id}}]
        else:
            diagnosis = external_runner.diagnose_project(project_id)
            answer = _json(diagnosis)
            model_answer = "Policy agent inspected constrained external DFT evidence."
            tool_trace = [{"step": 1, "name": "diagnose_external_dft_project", "arguments": {"project_id": project_id}}]
        episode_id = f"{datetime.now(timezone.utc):%Y%m%dT%H%M%SZ}_{uuid.uuid4().hex[:10]}"
        episode = {
            "episode_id": episode_id,
            "timestamp": datetime.now(timezone.utc).isoformat(timespec="seconds"),
            "framework": "dft_agent_flow.policy_external_agent",
            "model": "deterministic-policy-fallback",
            "scope": scope,
            "goal": goal,
            "model_answer": model_answer,
            "answer": answer,
            "tool_trace": tool_trace,
        }
        EPISODES_ROOT.mkdir(parents=True, exist_ok=True)
        episode_path = EPISODES_ROOT / f"{episode_id}.json"
        episode_path.write_text(_json(episode) + "\n", encoding="utf-8")
        return {"episode_id": episode_id, "episode_file": str(episode_path), "answer": answer}
    agent = make_agent(
        runner,
        dftc_tutor=dftc_tutor,
        external_runner=external_runner,
        model_name=model_name,
        api_base=api_base,
        scope=scope,
        execution_results=execution_results,
    )
    model_answer = str(agent.run(goal))
    answer = model_answer
    tool_trace = _tool_trace(agent)
    if scope == "dftc" and _requires_dftc_execution(goal):
        invoked = {item["name"] for item in tool_trace}
        if not invoked.intersection({"run_and_verify_dftc_lab_skill", "run_all_dftc_labs"}):
            answer = (
                "Agent 未调用受控的双重验证执行工具，因此本次未获得双重交叉验证，"
                "不能声称已执行、修复或通过。请记录为需要改进的工具选择样本。"
            )
        elif execution_results:
            answer = _supervised_dftc_answer(execution_results[-1])
    episode_id = f"{datetime.now(timezone.utc):%Y%m%dT%H%M%SZ}_{uuid.uuid4().hex[:10]}"
    episode = {
        "episode_id": episode_id,
        "timestamp": datetime.now(timezone.utc).isoformat(timespec="seconds"),
        "framework": "smolagents.ToolCallingAgent",
        "model": model_name,
        "scope": scope,
        "goal": goal,
        "model_answer": model_answer,
        "answer": answer,
        "tool_trace": tool_trace,
    }
    EPISODES_ROOT.mkdir(parents=True, exist_ok=True)
    episode_path = EPISODES_ROOT / f"{episode_id}.json"
    episode_path.write_text(_json(episode) + "\n", encoding="utf-8")
    return {"episode_id": episode_id, "episode_file": str(episode_path), "answer": answer}
