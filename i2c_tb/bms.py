#!/usr/bin/env python3
from __future__ import annotations

import argparse
import getpass
import os
import re
import shlex
import shutil
import subprocess
import sys
import time
from dataclasses import dataclass, field
from pathlib import Path
from typing import Iterable


SCRIPT_DIR = Path(__file__).resolve().parent


@dataclass
class FlowOptions:
    comp: list[str] = field(default_factory=list)
    vip: list[str] = field(default_factory=list)
    cov_comp: list[str] = field(default_factory=list)
    cov_sim: list[str] = field(default_factory=list)
    rtl_elab: list[str] = field(default_factory=list)
    test_elab: list[str] = field(default_factory=list)
    sim: list[str] = field(default_factory=list)
    pre_sim: list[str] = field(default_factory=list)
    post_sim: list[str] = field(default_factory=list)
    rtl_files: list[str] = field(default_factory=list)
    verif_files: list[str] = field(default_factory=list)


@dataclass
class CaseInfo:
    case_dir: Path
    tc_file: Path
    tc_name: str
    test_lib_root: Path
    project_root: Path
    vcs_com_dir: Path
    cfg_files: list[Path]
    options: FlowOptions


@dataclass
class RunContext:
    case: CaseInfo
    run_dir: Path
    compile_work_dir: Path
    simv_path: Path
    build_script: Path
    sim_script: Path
    run_script: Path
    sections: dict[str, list[str]]


def die(msg: str) -> None:
    print(f"[BMS][FATAL] {msg}", file=sys.stderr)
    raise SystemExit(1)


def info(msg: str) -> None:
    print(f"[BMS] {msg}")


def warn(msg: str) -> None:
    print(f"[BMS][WARN] {msg}", file=sys.stderr)


def read_text(path: Path) -> str:
    for enc in ("utf-8-sig", "utf-8", "gb18030", "latin-1"):
        try:
            return path.read_text(encoding=enc)
        except UnicodeDecodeError:
            continue
    return path.read_text(errors="replace")


def write_text_lf(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text.replace("\r\n", "\n").replace("\r", "\n"), encoding="utf-8", newline="\n")


def make_executable(path: Path) -> None:
    try:
        mode = path.stat().st_mode
        path.chmod(mode | 0o111)
    except OSError:
        pass


def sh_split(text: str) -> list[str]:
    text = text.strip()
    if not text:
        return []
    try:
        return shlex.split(text, posix=True)
    except ValueError:
        warn(f"cannot parse line with shlex, fallback to whitespace split: {text}")
        return text.split()


def shell_arg(token: os.PathLike[str] | str) -> str:
    value = str(token)
    if value == "":
        return "''"
    # Keep shell variables in cfg/filelist expressions expandable.
    if "$" in value or "`" in value:
        return value
    return shlex.quote(value)


def shell_join(tokens: Iterable[os.PathLike[str] | str]) -> str:
    return " ".join(shell_arg(t) for t in tokens)


def remove_tokens(accum: list[str], tokens: list[str]) -> None:
    if not tokens:
        return
    remove_set = set(tokens)
    accum[:] = [item for item in accum if item not in remove_set]


def append_or_remove(options: FlowOptions, sign: str, key: str, body: str, source: Path, line_no: int) -> None:
    key_l = key.lower()
    target_map = {
        "comp": options.comp,
        "vip": options.vip,
        "cov_comp": options.cov_comp,
        "cov_sim": options.cov_sim,
        "rtl_elab": options.rtl_elab,
        "test_elab": options.test_elab,
        "sim": options.sim,
    }

    if key_l in ("rtl_file", "rtl_files"):
        if sign == "+":
            options.rtl_files = sh_split(body)
        else:
            remove_tokens(options.rtl_files, sh_split(body))
        return
    if key_l in ("verif_file", "verif_files"):
        if sign == "+":
            options.verif_files = sh_split(body)
        else:
            remove_tokens(options.verif_files, sh_split(body))
        return

    if key_l == "sim" and body.lstrip().startswith("+PRE_SIM="):
        cmd = body.strip()[len("+PRE_SIM="):].strip()
        if sign == "+":
            options.pre_sim.append(cmd)
        else:
            remove_tokens(options.pre_sim, [cmd])
        return
    if key_l == "sim" and body.lstrip().startswith("+POST_SIM="):
        cmd = body.strip()[len("+POST_SIM="):].strip()
        if sign == "+":
            options.post_sim.append(cmd)
        else:
            remove_tokens(options.post_sim, [cmd])
        return

    if key_l not in target_map:
        warn(f"ignore unknown cfg key {key} at {source}:{line_no}")
        return

    tokens = sh_split(body)
    if sign == "+":
        target_map[key_l].extend(tokens)
    else:
        remove_tokens(target_map[key_l], tokens)


def parse_cfg_file(path: Path, options: FlowOptions) -> None:
    if not path.exists():
        return
    for line_no, raw in enumerate(read_text(path).splitlines(), 1):
        line = raw.strip()
        if not line or line.startswith("#"):
            continue

        assign = re.match(r"^(rtl_file|verif_file)\s*=\s*(.*)$", line, re.IGNORECASE)
        if assign:
            key = assign.group(1).lower()
            if key == "rtl_file":
                options.rtl_files = sh_split(assign.group(2))
            else:
                options.verif_files = sh_split(assign.group(2))
            continue

        match = re.match(r"^([+-])([A-Za-z0-9_]+)\1\s*(.*)$", line)
        if not match:
            warn(f"ignore malformed cfg/tc line at {path}:{line_no}: {line}")
            continue
        append_or_remove(options, match.group(1), match.group(2), match.group(3), path, line_no)


def parse_vcs_sections(path: Path) -> dict[str, list[str]]:
    if not path.exists():
        die(f"missing vcs_com control file: {path}")
    sections: dict[str, list[str]] = {}
    current: str | None = None
    for raw in read_text(path).splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        header = re.match(r"^\[(.+)]$", line)
        if header:
            current = header.group(1).strip().upper()
            sections.setdefault(current, [])
            continue
        if current is None:
            continue
        sections.setdefault(current, []).append(line)
    return sections


def find_test_lib_root(path: Path) -> Path:
    for item in [path] + list(path.parents):
        if item.name == "test_lib":
            return item
    die(f"path is not under a test_lib directory: {path}")


def cfg_chain(test_lib_root: Path, case_dir: Path, tc_file: Path) -> list[Path]:
    chain: list[Path] = []
    current = test_lib_root
    chain.append(current / "cfg")
    rel_parts = case_dir.relative_to(test_lib_root).parts
    for part in rel_parts:
        current = current / part
        chain.append(current / "cfg")
    chain.append(tc_file)
    return [p for p in chain if p.exists()]


def resolve_case(path_text: str) -> CaseInfo:
    raw_path = Path(path_text).expanduser()
    path = raw_path if raw_path.is_absolute() else (Path.cwd() / raw_path)
    path = path.resolve()

    if path.suffix == ".tc":
        tc_file = path
        case_dir = tc_file.parent
        tc_name = tc_file.stem
    else:
        case_dir = path
        tc_name = case_dir.name
        tc_file = case_dir / f"{tc_name}.tc"

    if not tc_file.exists():
        die(f"cannot find testcase file: {tc_file}")
    test_lib_root = find_test_lib_root(case_dir)
    project_root = test_lib_root.parent
    vcs_com_dir = project_root / "vcs_com"
    if not vcs_com_dir.exists():
        if (project_root / "Makefile").exists():
            vcs_com_dir = project_root
        else:
            die(f"cannot find vcs_com directory under project root: {project_root}")

    options = FlowOptions()
    files = cfg_chain(test_lib_root, case_dir, tc_file)
    for cfg in files:
        parse_cfg_file(cfg, options)

    return CaseInfo(
        case_dir=case_dir,
        tc_file=tc_file,
        tc_name=tc_name,
        test_lib_root=test_lib_root,
        project_root=project_root,
        vcs_com_dir=vcs_com_dir,
        cfg_files=files,
        options=options,
    )


def collect_cases(paths: list[str], eman: bool) -> list[CaseInfo]:
    if not paths:
        die("missing testcase path")
    cases: list[CaseInfo] = []
    for text in paths:
        raw = Path(text).expanduser()
        path = raw if raw.is_absolute() else (Path.cwd() / raw)
        path = path.resolve()
        if path.suffix == ".tc" or (path / f"{path.name}.tc").exists():
            cases.append(resolve_case(str(path)))
        elif eman and path.is_dir():
            for tc in sorted(path.rglob("*.tc")):
                cases.append(resolve_case(str(tc)))
        else:
            die(f"invalid testcase path: {path}")
    unique: dict[Path, CaseInfo] = {}
    for case in cases:
        unique[case.tc_file] = case
    return list(unique.values())


def run_suffix(args: argparse.Namespace) -> str:
    suffix = args.run_suffix or ""
    if not suffix:
        return ""
    return suffix if suffix.startswith("_") else f"_{suffix}"


def lib_compile_dir(case: CaseInfo, args: argparse.Namespace) -> Path | None:
    lib_name = args.genlib or args.lib
    if not lib_name:
        return None
    lib_path = Path(lib_name)
    if lib_path.is_absolute():
        return lib_path.resolve()
    return (case.case_dir.parent / lib_name).resolve()


def safe_rmtree(path: Path, case: CaseInfo) -> None:
    target = path.resolve()
    allowed_roots = [case.case_dir.resolve(), case.test_lib_root.resolve(), case.project_root.resolve()]
    if not any(root == target or root in target.parents for root in allowed_roots):
        die(f"refuse to remove path outside testcase/project tree: {target}")
    if target.name in ("", "/", "\\"):
        die(f"refuse to remove suspicious path: {target}")
    shutil.rmtree(target)


def default_filelists(case: CaseInfo, options: FlowOptions) -> tuple[list[str], list[str], list[str]]:
    vip_files: list[str] = []
    rtl_files: list[str] = []
    verif_files: list[str] = []

    vip_f = case.vcs_com_dir / "vip.f"
    if vip_f.exists():
        vip_files.append(str(vip_f))

    if options.rtl_files:
        rtl_files.extend(options.rtl_files)
    else:
        rtl_f = case.vcs_com_dir / "rtl.f"
        if rtl_f.exists():
            rtl_files.append(str(rtl_f))

    if options.verif_files:
        verif_files.extend(options.verif_files)
    else:
        verif_f = case.vcs_com_dir / "verif.f"
        if verif_f.exists():
            verif_files.append(str(verif_f))

    return vip_files, rtl_files, verif_files


def adjust_cov_sim_for_non_eman(tokens: list[str]) -> list[str]:
    adjusted = list(tokens)
    for idx, token in enumerate(adjusted[:-1]):
        if token == "-cm_dir":
            adjusted[idx + 1] = "./coverage"
    return adjusted


def command_block(command: str, fragments: list[str]) -> str:
    clean = [f for f in fragments if f]
    if not clean:
        return command
    return command + " \\\n  " + " \\\n  ".join(clean)


def build_context(case: CaseInfo, args: argparse.Namespace) -> RunContext:
    suffix = run_suffix(args)
    run_dir = Path(args.run_dir).resolve() if args.run_dir else (case.case_dir / f"run{suffix}").resolve()
    lib_dir = lib_compile_dir(case, args)
    compile_work_dir = Path(args.compile_work).resolve() if args.compile_work else (lib_dir or run_dir)
    simv_path = compile_work_dir / "simv"
    sections = parse_vcs_sections(case.vcs_com_dir / "vcs_com")
    return RunContext(
        case=case,
        run_dir=run_dir,
        compile_work_dir=compile_work_dir,
        simv_path=simv_path,
        build_script=compile_work_dir / "bms_build.sh",
        sim_script=run_dir / "bms_sim.sh",
        run_script=run_dir / "bms_run.sh",
        sections=sections,
    )


def generate_build_script(ctx: RunContext, args: argparse.Namespace) -> None:
    case = ctx.case
    opts = case.options
    vip_files, rtl_files, verif_files = default_filelists(case, opts)

    vlogan_fragments: list[str] = []
    vlogan_fragments.extend(ctx.sections.get("VLOGAN", []))
    vlogan_fragments.extend(shell_arg(t) for t in opts.comp)
    vlogan_fragments.extend(shell_arg(t) for t in opts.vip)
    if args.cov:
        vlogan_fragments.extend(shell_arg(t) for t in opts.cov_comp)
    for filelist in vip_files + rtl_files + verif_files:
        vlogan_fragments.append(f"-f {shell_arg(filelist)}")

    rtl_fragments = list(ctx.sections.get("VCS_RTL_ELAB", []))
    rtl_fragments.extend(shell_arg(t) for t in opts.rtl_elab)
    if args.cov:
        rtl_fragments.extend(shell_arg(t) for t in opts.cov_comp)
    rtl_fragments.append("-o simv_rtl")

    test_fragments = list(ctx.sections.get("VCS_TEST_ELAB", []))
    test_fragments.extend(shell_arg(t) for t in opts.test_elab)
    if args.cov:
        test_fragments.extend(shell_arg(t) for t in opts.cov_comp)
    test_fragments.append("-o simv")

    script = [
        "#!/usr/bin/env bash",
        "set -euo pipefail",
        f"cd {shell_arg(ctx.compile_work_dir)}",
        f"echo '[BMS] build case {case.tc_name}'",
        f"echo '[BMS] project {case.project_root}'",
        f"echo '[BMS] cfg files: {' '.join(str(p) for p in case.cfg_files)}'",
        command_block(os.environ.get("BMS_VLOGAN", "vlogan"), vlogan_fragments),
    ]
    if "VCS_RTL_ELAB" in ctx.sections:
        script.append(command_block(os.environ.get("BMS_VCS", "vcs"), rtl_fragments))
    if "VCS_TEST_ELAB" in ctx.sections:
        script.append(command_block(os.environ.get("BMS_VCS", "vcs"), test_fragments))
    else:
        die(f"missing [VCS_TEST_ELAB] in {case.vcs_com_dir / 'vcs_com'}")
    script.append("echo '[BMS] build done'")
    write_text_lf(ctx.build_script, "\n".join(script) + "\n")
    make_executable(ctx.build_script)


def generate_sim_script(ctx: RunContext, args: argparse.Namespace, eman: bool = False) -> None:
    case = ctx.case
    opts = case.options
    sim_tokens = list(opts.sim)
    if args.seed:
        sim_tokens.append(f"+ntb_random_seed={args.seed}")
    if args.cov:
        cov_sim = list(opts.cov_sim) if eman else adjust_cov_sim_for_non_eman(opts.cov_sim)
        sim_tokens.extend(cov_sim)
    if args.dump:
        wave_tcl = case.project_root / "common" / "script" / "wave.tcl"
        if wave_tcl.exists():
            sim_tokens.extend(["-ucli", "-i", str(wave_tcl)])
        else:
            warn(f"dump requested but wave.tcl does not exist: {wave_tcl}")

    sim_cmd = f"{shell_arg(ctx.simv_path)} {shell_join(sim_tokens)}".rstrip()

    lines = [
        "#!/usr/bin/env bash",
        "set -euo pipefail",
        f"mkdir -p {shell_arg(ctx.run_dir)}",
        f"cd {shell_arg(ctx.run_dir)}",
        f"echo '[BMS] simulate case {case.tc_name}'",
    ]
    for cmd in opts.pre_sim:
        lines.append(f"echo '[BMS] PRE_SIM: {cmd}'")
        lines.append(cmd)
    lines.append(sim_cmd)
    for cmd in opts.post_sim:
        lines.append(f"echo '[BMS] POST_SIM: {cmd}'")
        lines.append(cmd)
    lines.append("echo '[BMS] simulation done'")
    write_text_lf(ctx.sim_script, "\n".join(lines) + "\n")
    make_executable(ctx.sim_script)


def generate_run_script(ctx: RunContext, args: argparse.Namespace) -> None:
    fast_expr = "1" if args.fast else "0"
    lines = [
        "#!/usr/bin/env bash",
        "set -euo pipefail",
        f"FAST={fast_expr}",
        f"SIMV={shell_arg(ctx.simv_path)}",
        f"BUILD={shell_arg(ctx.build_script)}",
        f"SIM={shell_arg(ctx.sim_script)}",
        'if [[ "$FAST" == "1" && -x "$SIMV" ]]; then',
        "  echo '[BMS] fast mode: reuse existing simv'",
        "else",
        '  bash "$BUILD"',
        "fi",
        'bash "$SIM"',
    ]
    write_text_lf(ctx.run_script, "\n".join(lines) + "\n")
    make_executable(ctx.run_script)


def prepare_case_scripts(case: CaseInfo, args: argparse.Namespace, eman: bool = False) -> RunContext:
    ctx = build_context(case, args)
    if args.clean and not args.build_only and ctx.run_dir.exists():
        info(f"clean run directory: {ctx.run_dir}")
        safe_rmtree(ctx.run_dir, case)
    ctx.run_dir.mkdir(parents=True, exist_ok=True)
    ctx.compile_work_dir.mkdir(parents=True, exist_ok=True)
    if not args.sim_only:
        generate_build_script(ctx, args)
    if not args.build_only:
        generate_sim_script(ctx, args, eman=eman)
    if not args.build_only and not args.sim_only:
        generate_run_script(ctx, args)
    return ctx


def bash_available() -> bool:
    return shutil.which("bash") is not None


def bsub_available() -> bool:
    return shutil.which("bsub") is not None


def run_command(command: list[str], cwd: Path | None = None, dry_run: bool = False) -> int:
    info("command: " + " ".join(shell_arg(c) for c in command))
    if dry_run:
        return 0
    return subprocess.call(command, cwd=str(cwd) if cwd else None)


def lsf_submit(script: Path, args: argparse.Namespace, cwd: Path) -> int:
    queue = args.queue or os.environ.get("BMS_LSF_QUEUE", "normal")
    ncore = str(args.ncore)
    mem_mb = str(max(1, args.memory_gb) * 1024)
    log = cwd / "bms_lsf.log"
    command = [
        "bsub",
        "-q",
        queue,
        "-n",
        ncore,
        "-M",
        mem_mb,
        "-R",
        f"rusage[mem={mem_mb}]",
        "-oo",
        str(log),
        f"bash {shell_arg(script)}",
    ]
    return run_command(command, cwd=cwd, dry_run=args.dry_run)


def run_single_case(case: CaseInfo, args: argparse.Namespace, eman: bool = False) -> int:
    ctx = prepare_case_scripts(case, args, eman=eman)
    if args.build_only:
        script = ctx.build_script
        work_dir = ctx.compile_work_dir
    elif args.sim_only:
        script = ctx.sim_script
        work_dir = ctx.run_dir
    else:
        script = ctx.run_script
        work_dir = ctx.run_dir

    info(f"case       : {case.tc_file}")
    info(f"run dir    : {ctx.run_dir}")
    info(f"compile dir: {ctx.compile_work_dir}")
    info(f"build sh   : {ctx.build_script}")
    info(f"sim sh     : {ctx.sim_script}")

    if args.dry_run:
        return 0
    if not bash_available():
        die("bash is not available; generated scripts are ready but cannot be executed here")

    if args.local or args.build_only or args.sim_only or not bsub_available():
        if not args.local and not args.build_only and not args.sim_only:
            warn("bsub is not available; run locally")
        return run_command(["bash", str(script)], cwd=work_dir, dry_run=args.dry_run)
    return lsf_submit(script, args, work_dir)


def timestamp() -> str:
    return time.strftime("%Y%m%d_%H%M%S")


def parse_counts(text: str | None, ncases: int) -> list[int]:
    if not text:
        return [1] * ncases
    values = [int(x.strip()) for x in text.split(",") if x.strip()]
    if len(values) == 1:
        return values * ncases
    if len(values) != ncases:
        die(f"-num count mismatch: got {len(values)} values for {ncases} cases")
    return values


def find_eman_template(case: CaseInfo) -> Path:
    env_template = os.environ.get("BMS_EMAN_TEMPLATE")
    if env_template:
        path = Path(env_template).expanduser().resolve()
        if not path.exists():
            die(f"BMS_EMAN_TEMPLATE does not exist: {path}")
        return path
    candidates = [
        case.project_root / "regr" / "eman_template.emc",
        case.vcs_com_dir / "eman_template.emc",
    ]
    for path in candidates:
        if path.exists():
            return path
    die(f"cannot find eman_template.emc under {case.project_root / 'regr'} or {case.vcs_com_dir}")


def find_eman_error_pattern(case: CaseInfo) -> Path | None:
    env_path = os.environ.get("BMS_EMAN_ERROR_PATTERN")
    if env_path:
        path = Path(env_path).expanduser().resolve()
        return path if path.exists() else None
    for name in ("vcs_error_patterns.eme", "vcs_error_patterns.emc"):
        path = case.project_root / "regr" / name
        if path.exists():
            return path
    return None


def yaml_quote(text: str) -> str:
    return '"' + text.replace("\\", "\\\\").replace('"', '\\"') + '"'


def make_eman_blocks(cases: list[CaseInfo], args: argparse.Namespace, top_run_dir: Path) -> tuple[str, str, str]:
    user = getpass.getuser()
    stamp = timestamp()
    session_name = (
        f"build_{cases[0].tc_name}_session_{user}_{stamp}"
        if len(cases) == 1
        else f"{len(cases)}builds_session_{user}_{stamp}"
    )

    top_lines = [
        f"session_name: {yaml_quote(session_name)}",
        f"top_run_dir: {yaml_quote(str(top_run_dir))}",
    ]

    counts = parse_counts(args.num, len(cases))
    script = Path(__file__).resolve()
    build_nodes = int(os.environ.get("BMS_EMAN_BUILD_NODES", "1"))
    build_timeout = int(os.environ.get("BMS_EMAN_BUILD_TIMEOUT", "86400"))
    build_blocks: list[str] = []
    test_blocks: list[str] = []

    for case, count in zip(cases, counts):
        case_key = "_".join(case.tc_file.relative_to(case.test_lib_root).with_suffix("").parts)
        build_name = f"build_{case_key}"
        test_name = f"test_{case_key}"
        build_dir = top_run_dir / "builds" / build_name
        test_dir = top_run_dir / "tests" / test_name

        common_flags = []
        if args.cov:
            common_flags.append("-cov")
        if args.dump:
            common_flags.append("-d")
        if args.seed:
            common_flags.extend(["-s", str(args.seed)])

        build_cmd = [
            sys.executable or "python3",
            str(script),
            str(case.case_dir),
            "--build-only",
            "--local",
            "--run-dir",
            str(build_dir),
            "--compile-work",
            str(build_dir),
        ] + common_flags
        sim_cmd = [
            sys.executable or "python3",
            str(script),
            str(case.case_dir),
            "--sim-only",
            "--local",
            "--run-dir",
            str(test_dir),
            "--compile-work",
            str(build_dir),
        ] + common_flags

        build_blocks.extend([
            f"  {build_name}:",
            f"    run_dir: {yaml_quote(str(build_dir))}",
            "    cmd: |",
            f"      {shell_join(build_cmd)}",
            "    options:",
            f"      nodes: {build_nodes}",
            f"      timeout: {build_timeout}",
        ])
        test_blocks.extend([
            f"  {test_name}:",
            f"    build: {build_name}",
            f"    run_dir: {yaml_quote(str(test_dir))}",
            f"    count: {count}",
            "    cmd: |",
            f"      {shell_join(sim_cmd)}",
        ])
        if args.debug:
            rerun_count = int(os.environ.get("BMS_EMAN_DEBUG_RERUN_COUNT", "2"))
            test_blocks.extend([
                "    options:",
                f"      debug_rerun_count: {rerun_count}",
                "      debug_run_cmd: |",
                f"        {shell_join(sim_cmd)}",
            ])

    return "\n".join(top_lines), "\n".join(build_blocks), "\n".join(test_blocks)


def generate_eman(cases: list[CaseInfo], args: argparse.Namespace) -> int:
    first = cases[0]
    template = find_eman_template(first)
    debug_base_text = os.environ.get("BMS_EMAN_DEBUG_DIR")
    if debug_base_text:
        debug_base = Path(debug_base_text.format(user=getpass.getuser(), u=getpass.getuser())).expanduser().resolve()
    else:
        debug_base = (first.test_lib_root / "debug").resolve()
    top_run_dir = debug_base / "eman" / "eman_regression" / "eman_rundir" / f"eman_rundir_{timestamp()}"
    top_run_dir.mkdir(parents=True, exist_ok=True)
    emc_path = top_run_dir / "bms_generated.emc"

    top, builds, tests = make_eman_blocks(cases, args, top_run_dir)
    content = read_text(template)
    content = content.replace("__BMS_EMC_TOP__", top)
    content = content.replace("__BMS_EMC_BUILDS__", builds)
    content = content.replace("__BMS_EMC_TESTS__", tests)
    write_text_lf(emc_path, content)

    info(f"generated EMAN emc: {emc_path}")
    command = ["eman", str(emc_path)]
    project = os.environ.get("BMS_EMAN_PROJECT") or os.environ.get("EMAN_PROJECT") or getpass.getuser()
    config = os.environ.get("BMS_EMAN_CONFIG") or first.project_root.name
    command.extend(["-project", project, "-config", config])
    command.extend(["-session_name", re.search(r'session_name: "([^"]+)"', top).group(1)])
    command.extend(["-top_run_dir", str(top_run_dir)])
    command.extend(["-j", str(args.eman_nodes)])

    err_pat = find_eman_error_pattern(first)
    if err_pat:
        command.extend(["-error_pattern_file", str(err_pat)])
    if args.debug:
        command.append("-debug")
    if args.cov:
        command.append("-cov")
    if os.environ.get("BMS_EMAN_OVERWRITE") == "1":
        command.append("-overwrite")
    auto_cleanup = os.environ.get("BMS_EMAN_AUTO_CLEANUP", "1") != "0" and os.environ.get("BMS_EMAN_NO_AUTO_CLEANUP") != "1"
    if auto_cleanup:
        command.append("-auto_cleanup")
    extra = os.environ.get("BMS_EMAN_EXTRA")
    if extra:
        command.extend(sh_split(extra))
    return run_command(command, cwd=emc_path.parent, dry_run=args.dry_run)


def run_existing_emc(args: argparse.Namespace) -> int:
    emc = Path(args.emc).expanduser().resolve()
    if not emc.exists():
        die(f"emc file does not exist: {emc}")
    command = ["eman", str(emc)]
    if args.cov:
        command.append("-cov")
    if args.debug:
        command.append("-debug")
    return run_command(command, cwd=emc.parent, dry_run=args.dry_run)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="bms.py",
        description="BMS simulation driver for test_lib/vcs_com based UVM projects.",
    )
    parser.add_argument("tc", nargs="*", help="testcase path without .tc, .tc file, directory for -eman, or .emc with --emc")
    parser.add_argument("-f", "-fast", "--fast", action="store_true", help="reuse compiled simv if present")
    parser.add_argument("-c", "--clean", action="store_true", help="clean run directory before running")
    parser.add_argument("-genlib", "--genlib", nargs="?", const="compile_lib", help="build/reuse a compile library directory")
    parser.add_argument("-lib", "--lib", nargs="?", const="compile_lib", help="alias of -genlib")
    parser.add_argument("-d", "-dump", "--dump", action="store_true", help="enable waveform dump through common/script/wave.tcl")
    parser.add_argument("-cov", "--cov", action="store_true", help="enable compile/sim coverage options from cfg")
    parser.add_argument("-R", "--run-suffix", default="", help="suffix appended to run directory")
    parser.add_argument("-q", "--queue", default=os.environ.get("BMS_LSF_QUEUE", "normal"), help="LSF queue")
    parser.add_argument("--ncore", type=int, default=int(os.environ.get("BMS_NCORE", "4")), help="LSF core count")
    parser.add_argument("-m", "--memory-gb", type=int, default=int(os.environ.get("BMS_MEMORY_GB", "16")), help="LSF memory in GB")
    parser.add_argument("-eman", "--eman", action="store_true", help="generate and submit an EMAN regression")
    parser.add_argument("-num", "--num", help="EMAN testcase count, one value or comma-separated per case")
    parser.add_argument("-j", "--eman-nodes", type=int, default=int(os.environ.get("BMS_EMAN_NODES", "50")), help="EMAN build/test nodes")
    parser.add_argument("-s", "--seed", help="random seed passed as +ntb_random_seed")
    parser.add_argument("--emc", help="run an existing .emc directly")
    parser.add_argument("-debug", "--debug", action="store_true", help="enable EMAN debug options where supported")
    parser.add_argument("--local", "--no-lsf", action="store_true", help="run locally instead of submitting to LSF")
    parser.add_argument("-n", "--dry-run", action="store_true", help="generate scripts and print commands without executing")

    parser.add_argument("--build-only", action="store_true", help=argparse.SUPPRESS)
    parser.add_argument("--sim-only", action="store_true", help=argparse.SUPPRESS)
    parser.add_argument("--run-dir", help=argparse.SUPPRESS)
    parser.add_argument("--compile-work", help=argparse.SUPPRESS)
    return parser


def main(argv: list[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)

    if args.build_only and args.sim_only:
        die("--build-only and --sim-only cannot be used together")

    if args.emc or (args.eman and len(args.tc) == 1 and args.tc[0].endswith(".emc")):
        if not args.emc:
            args.emc = args.tc[0]
        return run_existing_emc(args)

    if args.eman:
        cases = collect_cases(args.tc, eman=True)
        return generate_eman(cases, args)

    cases = collect_cases(args.tc, eman=False)
    if len(cases) != 1:
        die("non-EMAN mode accepts exactly one testcase")
    return run_single_case(cases[0], args, eman=False)


if __name__ == "__main__":
    raise SystemExit(main())
