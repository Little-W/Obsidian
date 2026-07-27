#!/usr/bin/env python3
"""Deduplicate Vivado report_timing path reports.

Vivado often emits repeated rise/fall variants for the same endpoint pair.  This
tool keeps the first path for each key, which is also the worst one when the
input report is sorted by slack, and annotates how many duplicates were folded
into it.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable


PATH_START_RE = re.compile(r"^Slack \((?P<status>[^)]+)\)\s*:\s*(?P<slack>[-+]?\d+(?:\.\d+)?)ns")
DATA_DELAY_RE = re.compile(
    r"Data Path Delay:\s*(?P<delay>[-+]?\d+(?:\.\d+)?)ns\s*"
    r"\(logic\s*(?P<logic>[-+]?\d+(?:\.\d+)?)ns.*"
    r"route\s*(?P<route>[-+]?\d+(?:\.\d+)?)ns"
)
LOGIC_LEVEL_RE = re.compile(r"Logic Levels:\s*(?P<levels>\d+)")


@dataclass
class TimingPath:
    block: list[str]
    index: int
    slack: str = "NA"
    slack_value: float | None = None
    status: str = "NA"
    source: str = "UNKNOWN_SOURCE"
    destination: str = "UNKNOWN_DESTINATION"
    path_group: str = "UNKNOWN_GROUP"
    path_type: str = "UNKNOWN_TYPE"
    data_delay: str = "NA"
    logic_delay: str = "NA"
    route_delay: str = "NA"
    logic_levels: str = "NA"
    classification: str = "unclassified"
    route_ratio: float | None = None


def split_report(lines: list[str]) -> tuple[list[str], list[list[str]]]:
    header: list[str] = []
    blocks: list[list[str]] = []
    current: list[str] | None = None

    for line in lines:
        if PATH_START_RE.match(line):
            if current is not None:
                blocks.append(current)
            current = [line]
        elif current is None:
            header.append(line)
        else:
            current.append(line)

    if current is not None:
        blocks.append(current)

    return header, blocks


def parse_path(block: list[str], index: int) -> TimingPath:
    timing_path = TimingPath(block=block, index=index)

    start_match = PATH_START_RE.match(block[0])
    if start_match:
        timing_path.status = start_match.group("status")
        timing_path.slack = start_match.group("slack")
        timing_path.slack_value = float(timing_path.slack)

    for line in block:
        stripped = line.strip()
        if stripped.startswith("Source:"):
            timing_path.source = stripped.split(":", 1)[1].strip()
        elif stripped.startswith("Destination:"):
            timing_path.destination = stripped.split(":", 1)[1].strip()
        elif stripped.startswith("Path Group:"):
            timing_path.path_group = stripped.split(":", 1)[1].strip()
        elif stripped.startswith("Path Type:"):
            timing_path.path_type = stripped.split(":", 1)[1].strip()

        delay_match = DATA_DELAY_RE.search(stripped)
        if delay_match:
            timing_path.data_delay = delay_match.group("delay")
            timing_path.logic_delay = delay_match.group("logic")
            timing_path.route_delay = delay_match.group("route")
            data_delay = float(timing_path.data_delay)
            if data_delay > 0.0:
                timing_path.route_ratio = float(timing_path.route_delay) / data_delay

        levels_match = LOGIC_LEVEL_RE.search(stripped)
        if levels_match:
            timing_path.logic_levels = levels_match.group("levels")

    timing_path.classification = classify_path(timing_path)
    return timing_path


def normalize_endpoint(endpoint: str) -> str:
    endpoint = re.sub(r"\[\d+\]", "[]", endpoint)
    endpoint = re.sub(r"_[0-9]+(?=[/\]])", "_N", endpoint)
    return endpoint


def make_key(timing_path: TimingPath, key_mode: str) -> tuple[str, ...]:
    if key_mode == "endpoint":
        return (
            timing_path.path_group,
            timing_path.path_type,
            timing_path.source,
            timing_path.destination,
        )
    if key_mode == "structural":
        return (
            timing_path.path_group,
            timing_path.path_type,
            normalize_endpoint(timing_path.source),
            normalize_endpoint(timing_path.destination),
        )
    raise ValueError(f"unsupported key mode: {key_mode}")


def path_text(timing_path: TimingPath) -> str:
    return "\n".join(timing_path.block).lower()


def endpoint_text(timing_path: TimingPath) -> str:
    return f"{timing_path.source} {timing_path.destination}".lower()


def classify_path(timing_path: TimingPath) -> str:
    endpoints = endpoint_text(timing_path)
    text = f"{endpoints} {path_text(timing_path)}"
    route_ratio = timing_path.route_ratio or 0.0

    if any(token in endpoints for token in ("branch", "bru", "jump", "rollback", "mispred", "pc_", "ifu")):
        return "branch-ifu-control"
    if any(token in endpoints for token in ("dispatch", "hdu", "scoreboard", "bypass", "raw", "forward")):
        return "dispatch-hazard-bypass"
    if any(token in endpoints for token in ("mul", "div", "alu", "add", "sub", "cmp", "compare", "carry", "dsp")):
        return "arithmetic"
    if any(token in endpoints for token in ("lsu", "axi", "ram", "mem", "fifo", "ar", "aw", "raddr", "waddr")):
        return "memory-address-fifo"
    if any(token in text for token in ("rst", "reset", "flush", "stall", "valid", "clock_enable", "/ce", "_ce")):
        if route_ratio >= 0.60:
            return "reset-ce-high-fanout"
        return "reset-ce-control"
    if any(token in text for token in ("alu", "add", "sub", "cmp", "compare", "mul", "div", "carry", "dsp")):
        return "arithmetic"
    if any(token in text for token in ("lsu", "axi", "ram", "mem", "fifo", "ar", "aw", "raddr", "waddr")):
        return "memory-address-fifo"
    if route_ratio >= 0.65:
        return "physical-route-dominated"
    return "control-or-mux"


def optimization_hints(path_class: str) -> list[str]:
    common = [
        "Use the full implementation/post-route result as the acceptance gate; OOC or synth-only improvement is only a filter.",
        "Do not change external interfaces, architectural latency, outstanding depth, or CoreMark-visible behavior without a compensating proof.",
        "Preserve the CoreMark 359+ baseline and CRC; rerun functional/performance smoke tests for any RTL edit.",
    ]
    by_class = {
        "reset-ce-high-fanout": [
            "Look for flush/stall/valid/CE/reset fanout crossing module boundaries.",
            "Prefer local decode or registered compact control over a wide global enable.",
            "Separate payload registers from valid/reset state when legal.",
        ],
        "reset-ce-control": [
            "Check whether reset/flush controls are unnecessarily clearing wide payloads.",
            "Keep reset semantics explicit; avoid hiding logic under SYNTHESIS-only branches.",
        ],
        "branch-ifu-control": [
            "Avoid late data feeding branch compare and then IFU PC/flush control in one cycle.",
            "Keep branch redirect control narrow and registered; move wide data muxing into EXU-local logic.",
        ],
        "dispatch-hazard-bypass": [
            "Separate RAW readiness/source selection from wide operand data.",
            "Prefer compact source/bank tokens through dispatch_pipe and local EXU muxing.",
            "For loads, release consumers only when the bypass-bank write/data-valid event is real.",
        ],
        "memory-address-fifo": [
            "Check RAM/FIFO count, pointer, full/empty, and address-generation cones.",
            "Do not fake synchronous RAM latency or shrink outstanding queues to win timing.",
            "If adding status flags, verify they do not migrate into IFU PC CE or global control.",
        ],
        "arithmetic": [
            "Inspect wide add/compare/mux association and whether inputs arrive late.",
            "Pipeline or precompute only when valid/sideband semantics remain aligned.",
            "Avoid reusing carry-chain arithmetic for branch/control if it lengthens global control paths.",
        ],
        "physical-route-dominated": [
            "Treat high route ratio as a placement/fanout symptom; look for cross-hierarchy or high-fanout nets.",
            "Prefer local replication/registered control at natural module boundaries over global attributes first.",
        ],
        "control-or-mux": [
            "Map the cone to priority chains, case muxes, and late select signals.",
            "Reduce select fanout or re-associate muxes only inside the target configuration with generate guards.",
        ],
    }
    return by_class.get(path_class, by_class["control-or-mux"]) + common


def endpoint_summary(endpoint: str) -> str:
    parts = [part for part in re.split(r"[/.\s]+", endpoint) if part]
    if len(parts) <= 5:
        return endpoint
    return "/".join(parts[-5:])


def format_summary_line(timing_path: TimingPath, duplicate_count: int) -> str:
    route_ratio = "NA" if timing_path.route_ratio is None else f"{timing_path.route_ratio:.2f}"
    return (
        f"{timing_path.index:5d}  dup={duplicate_count:<4d} "
        f"slack={timing_path.slack:>8s}ns  "
        f"delay={timing_path.data_delay:>8s}ns  "
        f"logic={timing_path.logic_delay:>8s}ns  "
        f"route={timing_path.route_delay:>8s}ns  "
        f"route_ratio={route_ratio:>5s}  "
        f"levels={timing_path.logic_levels:>4s}  "
        f"class={timing_path.classification:<24s}  "
        f"{timing_path.source} -> {timing_path.destination}\n"
    )


def path_to_json(timing_path: TimingPath, duplicate_count: int, key_mode: str) -> dict[str, object]:
    return {
        "original_index": timing_path.index,
        "duplicates": duplicate_count,
        "dedup_key_mode": key_mode,
        "slack_ns": timing_path.slack_value,
        "status": timing_path.status,
        "source": timing_path.source,
        "destination": timing_path.destination,
        "path_group": timing_path.path_group,
        "path_type": timing_path.path_type,
        "data_delay_ns": None if timing_path.data_delay == "NA" else float(timing_path.data_delay),
        "logic_delay_ns": None if timing_path.logic_delay == "NA" else float(timing_path.logic_delay),
        "route_delay_ns": None if timing_path.route_delay == "NA" else float(timing_path.route_delay),
        "route_ratio": timing_path.route_ratio,
        "logic_levels": None if timing_path.logic_levels == "NA" else int(timing_path.logic_levels),
        "classification": timing_path.classification,
    }


def sort_key(timing_path: TimingPath) -> tuple[float, int]:
    slack = timing_path.slack_value
    if slack is None:
        slack = float("inf")
    return slack, timing_path.index


def select_top_paths(unique: list[TimingPath], top_n: int) -> list[TimingPath]:
    if top_n <= 0:
        return []
    return sorted(unique, key=sort_key)[:top_n]


def task_markdown(
    timing_path: TimingPath,
    duplicate_count: int,
    rank: int,
    key_mode: str,
    input_path: Path,
) -> str:
    route_ratio = "NA" if timing_path.route_ratio is None else f"{timing_path.route_ratio:.2f}"
    hints = "\n".join(f"- {hint}" for hint in optimization_hints(timing_path.classification))
    return (
        f"# Timing Path Task {rank:02d}\n\n"
        f"Source report: `{input_path}`\n"
        f"Dedup key mode: `{key_mode}`\n"
        f"Original path index: `{timing_path.index}`\n"
        f"Duplicate count: `{duplicate_count}`\n"
        f"Class: `{timing_path.classification}`\n\n"
        "## Timing\n\n"
        f"- Slack: `{timing_path.slack} ns` ({timing_path.status})\n"
        f"- Data delay: `{timing_path.data_delay} ns`\n"
        f"- Logic delay: `{timing_path.logic_delay} ns`\n"
        f"- Route delay: `{timing_path.route_delay} ns`\n"
        f"- Route ratio: `{route_ratio}`\n"
        f"- Logic levels: `{timing_path.logic_levels}`\n"
        f"- Path group: `{timing_path.path_group}`\n"
        f"- Path type: `{timing_path.path_type}`\n\n"
        "## Endpoints\n\n"
        f"- Source: `{timing_path.source}`\n"
        f"- Destination: `{timing_path.destination}`\n"
        f"- Compact source: `{endpoint_summary(timing_path.source)}`\n"
        f"- Compact destination: `{endpoint_summary(timing_path.destination)}`\n\n"
        "## Optimization Guardrails\n\n"
        f"{hints}\n\n"
        "## Full Path\n\n"
        "```text\n"
        f"{''.join(timing_path.block).rstrip()}\n"
        "```\n"
    )


def write_task_outputs(
    input_path: Path,
    selected: list[TimingPath],
    counts: dict[tuple[str, ...], int],
    key_mode: str,
    tasks_output: Path | None,
    task_dir: Path | None,
) -> None:
    if not selected:
        return

    if tasks_output is not None:
        tasks_output.parent.mkdir(parents=True, exist_ok=True)
        with tasks_output.open("w") as out:
            out.write("# Vivado Timing Top Path Optimization Tasks\n\n")
            out.write(f"Source report: `{input_path}`\n\n")
            for rank, timing_path in enumerate(selected, 1):
                out.write(
                    task_markdown(
                        timing_path,
                        counts[make_key(timing_path, key_mode)],
                        rank,
                        key_mode,
                        input_path,
                    )
                )
                out.write("\n---\n\n")

    if task_dir is not None:
        task_dir.mkdir(parents=True, exist_ok=True)
        for rank, timing_path in enumerate(selected, 1):
            task_path = task_dir / f"path_{rank:02d}_idx_{timing_path.index}.md"
            task_path.write_text(
                task_markdown(
                    timing_path,
                    counts[make_key(timing_path, key_mode)],
                    rank,
                    key_mode,
                    input_path,
                )
            )


def deduplicate_report(
    input_path: Path,
    output_path: Path,
    key_mode: str,
    top_n: int = 30,
    tasks_output: Path | None = None,
    task_dir: Path | None = None,
    json_output: Path | None = None,
) -> tuple[int, int]:
    lines = input_path.read_text(errors="replace").splitlines(keepends=True)
    header, blocks = split_report(lines)
    timing_paths = [parse_path(block, index + 1) for index, block in enumerate(blocks)]

    unique: list[TimingPath] = []
    counts: dict[tuple[str, ...], int] = {}
    seen: dict[tuple[str, ...], TimingPath] = {}

    for timing_path in timing_paths:
        key = make_key(timing_path, key_mode)
        counts[key] = counts.get(key, 0) + 1
        if key not in seen:
            seen[key] = timing_path
            unique.append(timing_path)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    with output_path.open("w") as out:
        out.write("Deduplicated Vivado timing path report\n")
        out.write("======================================\n\n")
        out.write(f"Input report: {input_path}\n")
        out.write(f"Dedup key: {key_mode} (path_group, path_type, source, destination)\n")
        out.write(f"Top task count: {top_n}\n")
        out.write(f"Total paths: {len(timing_paths)}\n")
        out.write(f"Unique paths: {len(unique)}\n")
        out.write(f"Removed duplicates: {len(timing_paths) - len(unique)}\n\n")

        if unique:
            out.write("Unique path summary\n")
            out.write("-------------------\n")
            for timing_path in unique:
                out.write(format_summary_line(timing_path, counts[make_key(timing_path, key_mode)]))
            out.write("\n")

        out.write("Full unique paths\n")
        out.write("-----------------\n\n")
        if header:
            out.writelines(header)
            if not header[-1].endswith("\n"):
                out.write("\n")

        for timing_path in unique:
            duplicate_count = counts[make_key(timing_path, key_mode)]
            out.write(
                f"\n# Dedup path {timing_path.index}: duplicates={duplicate_count} "
                f"key={key_mode} class={timing_path.classification}\n"
            )
            out.writelines(timing_path.block)
            if timing_path.block and not timing_path.block[-1].endswith("\n"):
                out.write("\n")

    selected = select_top_paths(unique, top_n)
    write_task_outputs(input_path, selected, counts, key_mode, tasks_output, task_dir)

    if json_output is not None:
        json_output.parent.mkdir(parents=True, exist_ok=True)
        json_output.write_text(
            json.dumps(
                {
                    "input_report": str(input_path),
                    "dedup_key_mode": key_mode,
                    "total_paths": len(timing_paths),
                    "unique_paths": len(unique),
                    "removed_duplicates": len(timing_paths) - len(unique),
                    "top_count": len(selected),
                    "top_paths": [
                        path_to_json(timing_path, counts[make_key(timing_path, key_mode)], key_mode)
                        for timing_path in selected
                    ],
                },
                indent=2,
            )
            + "\n"
        )

    return len(timing_paths), len(unique)


def default_output_path(input_path: Path, suffix: str) -> Path:
    return input_path.with_name(f"{input_path.stem}{suffix}{input_path.suffix or '.rpt'}")


def expand_inputs(inputs: Iterable[str]) -> list[Path]:
    expanded: list[Path] = []
    for raw_path in inputs:
        path = Path(raw_path)
        if path.is_dir():
            expanded.extend(
                sorted(
                    candidate
                    for candidate in path.rglob("*timing_paths*.rpt")
                    if "_dedup" not in candidate.stem
                )
            )
        else:
            expanded.append(path)
    return expanded


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("inputs", nargs="+", help="Vivado timing path report file or directory")
    parser.add_argument(
        "-o",
        "--output",
        help="Output report path. Only valid when processing one input file.",
    )
    parser.add_argument(
        "--key-mode",
        choices=("endpoint", "structural"),
        default="endpoint",
        help="Deduplication key. 'structural' also collapses numeric bit indices.",
    )
    parser.add_argument(
        "--suffix",
        default="_dedup",
        help="Suffix used when --output is not provided.",
    )
    parser.add_argument(
        "--top",
        type=int,
        default=30,
        help="Number of worst unique paths to include in task outputs.",
    )
    parser.add_argument(
        "--tasks-output",
        help="Combined Markdown file with one optimization task per top unique path.",
    )
    parser.add_argument(
        "--task-dir",
        help="Directory for per-path Markdown task shards, suitable for parallel analysis.",
    )
    parser.add_argument(
        "--json-output",
        help="JSON summary for the selected top unique paths. Only valid with one input file.",
    )
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    input_paths = expand_inputs(args.inputs)
    if not input_paths:
        print("No timing path reports found.", file=sys.stderr)
        return 1

    if args.output and len(input_paths) != 1:
        print("--output is only valid with one input file.", file=sys.stderr)
        return 2
    if args.tasks_output and len(input_paths) != 1:
        print("--tasks-output is only valid with one input file.", file=sys.stderr)
        return 2
    if args.task_dir and len(input_paths) != 1:
        print("--task-dir is only valid with one input file.", file=sys.stderr)
        return 2
    if args.json_output and len(input_paths) != 1:
        print("--json-output is only valid with one input file.", file=sys.stderr)
        return 2

    status = 0
    for input_path in input_paths:
        if not input_path.is_file():
            print(f"Skipping missing report: {input_path}", file=sys.stderr)
            status = 1
            continue

        output_path = Path(args.output) if args.output else default_output_path(input_path, args.suffix)
        tasks_output = Path(args.tasks_output) if args.tasks_output else None
        task_dir = Path(args.task_dir) if args.task_dir else None
        json_output = Path(args.json_output) if args.json_output else None
        try:
            total_paths, unique_paths = deduplicate_report(
                input_path,
                output_path,
                args.key_mode,
                top_n=args.top,
                tasks_output=tasks_output,
                task_dir=task_dir,
                json_output=json_output,
            )
        except OSError as exc:
            print(f"Failed to process {input_path}: {exc}", file=sys.stderr)
            status = 1
            continue

        print(f"{input_path} -> {output_path} ({unique_paths}/{total_paths} unique paths)")

    return status


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
