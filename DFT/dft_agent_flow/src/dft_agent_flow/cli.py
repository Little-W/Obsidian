from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

from .agent import run_agent
from .config import DEFAULT_MODEL, EVALS_FILE
from .dftc_labs import DftcLabTutor
from .external_projects import ExternalDftProjectRunner
from .evaluate import evaluate_executor
from .feedback import export_sft_dataset, record_feedback
from .runner import FanRunner, FlowValidationError, Goal


def _json(payload: object) -> None:
    print(json.dumps(payload, ensure_ascii=False, indent=2))


def parser() -> argparse.ArgumentParser:
    root = argparse.ArgumentParser(description="Auditable local Design-for-Test ATPG flow")
    commands = root.add_subparsers(dest="command", required=True)

    inspect = commands.add_parser("inspect", help="Inspect an approved ISCAS benchmark")
    inspect.add_argument("--circuit", required=True)

    optimize = commands.add_parser("optimize", help="Run all approved profiles and select the best result")
    optimize.add_argument("--circuit", required=True)
    optimize.add_argument("--min-coverage", type=float, default=0.0)
    optimize.add_argument("--max-patterns", type=int)

    agent = commands.add_parser("agent", help="Use the local ToolCallingAgent for a natural-language goal")
    agent.add_argument("--goal", required=True)
    agent.add_argument("--model", default=DEFAULT_MODEL)
    agent.add_argument("--api-base", default="http://127.0.0.1:11434")

    feedback = commands.add_parser("feedback", help="Record expert review for one agent episode")
    feedback.add_argument("--episode", required=True)
    feedback.add_argument("--verdict", choices=["approved", "corrected", "rejected"], required=True)
    feedback.add_argument("--note", default="")
    feedback.add_argument("--corrected-response", default="")

    export = commands.add_parser("export-sft", help="Export approved feedback as ChatML JSONL")
    export.add_argument("--output", type=Path, default=Path("data/training/dft_agent_sft.jsonl"))

    evaluate = commands.add_parser("evaluate", help="Run deterministic goal-selection regression cases")
    evaluate.add_argument("--cases", type=Path, default=EVALS_FILE)
    evaluate.add_argument("--execute", action="store_true", help="Actually invoke FAN for each regression case")

    dftc_list = commands.add_parser("dftc-list", help="List DFTC1 course labs and their evidence state")
    dftc_list.set_defaults()

    dftc_lesson = commands.add_parser("dftc-lesson", help="Show the supervised lesson for one DFTC1 lab")
    dftc_lesson.add_argument("--lab", required=True)

    dftc_audit = commands.add_parser("dftc-audit", help="Audit recorded DFTC runtime evidence without modifying it")
    dftc_audit.add_argument("--lab", required=True)

    dftc_diff = commands.add_parser("dftc-diff", help="Compare official and recorded-port source files")
    dftc_diff.add_argument("--lab", required=True)

    commands.add_parser("dftc-ready", help="Check the approved isolated dc_shell executor")

    commands.add_parser("dftc-skills", help="List approved multi-step DFTC repair skills")

    dftc_skill = commands.add_parser("dftc-skill", help="Run one approved DFTC skill and cross-validate it twice")
    dftc_skill.add_argument("--skill", required=True)

    dftc_verify = commands.add_parser("dftc-verify", help="Cross-validate an existing staged DFTC skill_result.json")
    dftc_verify.add_argument("--evidence", type=Path, required=True)

    dftc_run = commands.add_parser("dftc-run", help="Run one approved generated DFTC flow in a new workspace")
    dftc_run.add_argument("--lab", required=True)
    dftc_run.add_argument("--flow", required=True)
    dftc_run.add_argument("--variant", choices=["official", "ported"], default="official")

    commands.add_parser("external-list", help="List commit-pinned open-source RTL projects")
    external_inspect = commands.add_parser("external-inspect", help="Inspect a pinned external RTL project")
    external_inspect.add_argument("--project", required=True)
    commands.add_parser("external-ready", help="Check the generated external DFT executor")
    external_run = commands.add_parser("external-run", help="Run and double-verify one generated external DFT baseline")
    external_run.add_argument("--project", required=True)
    external_diagnose = commands.add_parser("external-diagnose", help="Diagnose latest evidence and list approved external DFT repair actions")
    external_diagnose.add_argument("--project", required=True)
    external_repair = commands.add_parser("external-repair", help="Apply one diagnosis-approved external DFT repair")
    external_repair.add_argument("--project", required=True)
    external_repair.add_argument("--action", required=True)
    return root


def main(argv: list[str] | None = None) -> int:
    args = parser().parse_args(argv)
    try:
        if args.command == "inspect":
            _json(FanRunner().inspect(args.circuit))
        elif args.command == "optimize":
            _json(FanRunner().optimize(args.circuit, Goal(args.min_coverage, args.max_patterns)))
        elif args.command == "agent":
            _json(run_agent(args.goal, model_name=args.model, api_base=args.api_base))
        elif args.command == "feedback":
            _json(record_feedback(args.episode, args.verdict, args.note, args.corrected_response))
        elif args.command == "export-sft":
            output = args.output if args.output.is_absolute() else Path.cwd() / args.output
            _json(export_sft_dataset(output))
        elif args.command == "evaluate":
            if not args.execute:
                _json({"cases": len(args.cases.read_text(encoding="utf-8").splitlines()), "executed": False})
            else:
                _json(evaluate_executor(FanRunner(), args.cases))
        elif args.command == "dftc-list":
            _json(DftcLabTutor().list_labs())
        elif args.command == "dftc-lesson":
            _json(DftcLabTutor().lesson(args.lab))
        elif args.command == "dftc-audit":
            _json(DftcLabTutor().audit_runtime(args.lab))
        elif args.command == "dftc-diff":
            _json(DftcLabTutor().compare_porting_files(args.lab))
        elif args.command == "dftc-ready":
            _json(DftcLabTutor().execution_readiness())
        elif args.command == "dftc-skills":
            _json(DftcLabTutor().list_skills())
        elif args.command == "dftc-skill":
            _json(DftcLabTutor().run_skill_and_verify(args.skill))
        elif args.command == "dftc-verify":
            _json(DftcLabTutor().cross_validate_evidence(args.evidence))
        elif args.command == "dftc-run":
            _json(DftcLabTutor().run_lab(args.lab, args.flow, args.variant))
        elif args.command == "external-list":
            _json(ExternalDftProjectRunner().list_projects())
        elif args.command == "external-inspect":
            _json(ExternalDftProjectRunner().inspect_project(args.project))
        elif args.command == "external-ready":
            _json(ExternalDftProjectRunner().execution_readiness())
        elif args.command == "external-run":
            _json(ExternalDftProjectRunner().run_and_verify_summary(args.project))
        elif args.command == "external-diagnose":
            _json(ExternalDftProjectRunner().diagnose_project(args.project))
        elif args.command == "external-repair":
            _json(ExternalDftProjectRunner().attempt_approved_repair_summary(args.project, args.action))
        return 0
    except (FlowValidationError, FileNotFoundError, RuntimeError, ValueError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
