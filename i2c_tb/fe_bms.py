#!/usr/bin/env python3
import os
import sys
import argparse
import re
import time
import signal
import subprocess
import threading
import shlex
import shutil
import hashlib
import json

# ======================================
# 环境修复：解决系统库兼容问题（Linux）
# ======================================
os.system("unset LD_PRELOAD")
if "VCS_HOME" in os.environ:
    os.environ["LD_LIBRARY_PATH"] = f"{os.environ['VCS_HOME']}/linux64/lib:{os.environ.get('LD_LIBRARY_PATH', '')}"

# ======================================
# 全局公共配置
# ======================================
MAX_LOG_SIZE_GB = 10
MAX_LOG_SIZE = MAX_LOG_SIZE_GB * 1024**3
DEFAULT_QUEUE = "normal"
DEFAULT_NCORE = int(os.environ.get("BMS_NCORE", "1").strip() or "1")
UVM_HOME = os.environ.get("UVM_HOME", "")

# 通用附加参数（可选）：不再默认注入 UUM/test_side/design_side
# 如需额外参数，可在环境变量中配置，例如:
#   export BMS_VLOGAN_EXTRA="-kdb"
#   export BMS_VCS_EXTRA="-kdb"
BMS_VLOGAN_EXTRA = os.environ.get("BMS_VLOGAN_EXTRA", "").strip()
BMS_VCS_EXTRA = os.environ.get("BMS_VCS_EXTRA", "").strip()

# DTL 模式（你给的 2025 示例流）：
# 1) vcs ... <base_pkg> -partcomp -dir=<base_dir> -enable_dynamic_tb -o simv
# 2) vcs -sharedlib=<base_dir> -partcomp <test_pkg> -dir=<test_dir> -dynamic_tb
# 3) ./simv +dtl_add_pkg=<test_dir>:<test_pkg> ...
# 默认开启，可 export BMS_USE_DTL=0 切回旧流程
BMS_USE_DTL = os.environ.get("BMS_USE_DTL", "1").strip()
BMS_DTL_BASE_PKG = os.environ.get("BMS_DTL_BASE_PKG", "base_test_pkg").strip()
BMS_DTL_BASE_DIR = os.environ.get("BMS_DTL_BASE_DIR", "BASE_IP").strip()
# 默认使用“单一 test package”模式，适合 case 数量多的项目
BMS_DTL_TEST_PKG_FMT = os.environ.get("BMS_DTL_TEST_PKG_FMT", "npu_core_test_pkg").strip()
BMS_DTL_TEST_DIR_FMT = os.environ.get("BMS_DTL_TEST_DIR_FMT", "TEST_PKG").strip()


def _env_truthy(name: str, default: bool = False) -> bool:
    v = os.environ.get(name, "").strip().lower()
    if not v:
        return default
    return v in ("1", "yes", "true", "on", "y")


def _vip_f_path(make_dir: str):
    vip_list = os.environ.get("BMS_VIP_F", "vip.f").strip() or "vip.f"
    p = os.path.join(make_dir, vip_list)
    return p if os.path.exists(p) else None


def _filelist_has_source_entries(filelist_path: str) -> bool:
    """Return True when filelist contains at least one source-file entry."""
    if not os.path.exists(filelist_path):
        return False
    with open(filelist_path, "r", encoding="utf-8", errors="ignore") as f:
        for raw in f:
            line = raw.strip()
            if (not line) or line.startswith("#") or line.startswith("//"):
                continue
            # Filelist options that are not source entries
            if (
                line.startswith("+")
                or line.startswith("-")
                or line.startswith("$(")
                or line.startswith("${")
            ):
                continue
            # Plain token is treated as source path
            return True
    return False


VIP_COMPILED_MARKER = "vip_compiled.d"
VIP_COMPILED_SIG = "vip_compiled.sig"
LIB_MANIFEST_FILE = ".bms_lib_manifest.json"


def _vip_signature(vip_path: str, comp_opt: str = "", vip_opt: str = "") -> str:
    extra_ctx = f"{comp_opt}\n{vip_opt}\n{BMS_VLOGAN_EXTRA}"
    return _filelist_signature(vip_path, extra_ctx=extra_ctx)


def _vip_cache_hit(vip_sig: str = "") -> bool:
    if _env_truthy("BMS_FORCE_VIP"):
        return False
    if not os.path.exists(VIP_COMPILED_MARKER):
        return False
    if not vip_sig:
        return True
    if not os.path.exists(VIP_COMPILED_SIG):
        return False
    try:
        with open(VIP_COMPILED_SIG, "r", encoding="utf-8", errors="ignore") as f:
            return f.read().strip() == vip_sig
    except Exception:
        return False


def _mark_vip_compiled(vip_sig: str = ""):
    os.system(f"touch {VIP_COMPILED_MARKER}")
    if not vip_sig:
        return
    try:
        with open(VIP_COMPILED_SIG, "w", encoding="utf-8") as f:
            f.write(vip_sig + "\n")
    except Exception:
        pass


DEFAULT_WAVE_TCL = """
dump -type FSDB -file wave.fsdb
dump -add /
run
dump -flush
quit
"""

CLEAN_FILES = [
    "*.fsdb", "*.vcd", "*.vpd", "wave.tcl",
    "vsim.wlf", "verdi_config*", "novas.*",
    "core", "*.log", "simv*", "test_lib.so",
    "*.ucdb", "csrc", "INCA_libs", "work",
    "uvm_compiled.d", "vip_compiled.d", "vip_compiled.sig", "verif_compiled.d", "*.d", "lsf.*", "AN.DB",
    "BASE_IP", "TEST_*",
]

sim_proc = None
CURRENT_RUN_DIR = ""
SIM_LOG_PATH = ""
COMPILE_LOG_PATHS = []


def _normalize_log_path(p: str) -> str:
    if not p:
        return ""
    q = p.strip().strip("'").strip('"')
    if not q:
        return ""
    if os.path.isabs(q):
        return q
    base = CURRENT_RUN_DIR or os.getcwd()
    return os.path.abspath(os.path.join(base, q))


def _collect_log_from_cmd(cmd: str):
    # Capture "-l <logfile>" occurrences from vcs/vlogan/simv commands.
    m = re.search(r"(?:^|\s)-l\s+([^\s]+)", cmd)
    if not m:
        return
    lp = _normalize_log_path(m.group(1))
    if lp and (lp not in COMPILE_LOG_PATHS):
        COMPILE_LOG_PATHS.append(lp)


def _resolve_uvm_home() -> str:
    """Resolve UVM home with fallback to VCS bundled UVM."""
    if UVM_HOME and os.path.isdir(UVM_HOME):
        return UVM_HOME
    vcs_home = os.environ.get("VCS_HOME", "").strip()
    if vcs_home:
        cand = os.path.join(vcs_home, "etc", "uvm-1.2")
        if os.path.isdir(cand):
            return cand
    return ""


def print_log_locations():
    print("\n" + "=" * 60)
    print("LOG PATHS")
    print("=" * 60)
    if SIM_LOG_PATH:
        print(f"[SIM] {SIM_LOG_PATH}")
    else:
        print("[SIM] (not generated yet)")
    if COMPILE_LOG_PATHS:
        print("[COMPILE]")
        for p in COMPILE_LOG_PATHS:
            print(f"  - {p}")
    else:
        print("[COMPILE] (no -l compile logs captured; check vcs_com options)")
    if CURRENT_RUN_DIR:
        print(f"[RUN_DIR] {CURRENT_RUN_DIR}")
    print("=" * 60 + "\n")


def print_result_banner(has_err: bool):
    if has_err:
        color = "1;31"
        text = [
            " _______    ___      ___   __      ",
            "|   ____|  /   \\    |_ _| |  |     ",
            "|  |__    /  ^  \\    | |  |  |     ",
            "|   __|  /  /_\\  \\   | |  |  |     ",
            "|  |    /  _____  \\ _| |_ |  `----.",
            "|__|   /__/     \\__\\_____| |_______|",
        ]
    else:
        color = "1;32"
        text = [
            " _______      ___           _______.     _______.",
            "|   __  \\    /   \\         /       |    /       |",
            "|  |__)  |  /  ^  \\       |   (----`   |   (----`",
            "|   ___/  /  /_\\  \\       \\   \\        \\   \\    ",
            "|  |     /  _____  \\  .----)   |   .----)   |   ",
            "| _|    /__/     \\__\\ |_______/    |_______/    ",
        ]
    print("\n" + "=" * 60)
    for line in text:
        print(_c(color, line))
    print("=" * 60 + "\n")


# ======================================
# Ctrl+C 安全退出
# ======================================
def handle_exit(signum, frame):
    global sim_proc
    print("\nCtrl+C 捕获，停止所有进程...")
    if sim_proc and sim_proc.poll() is None:
        try:
            sim_proc.terminate()
            time.sleep(0.5)
            if sim_proc.poll() is None:
                sim_proc.kill()
        except Exception:
            pass
    print_log_locations()
    sys.exit(0)


signal.signal(signal.SIGINT, handle_exit)
signal.signal(signal.SIGQUIT, handle_exit)


# ======================================
# 输出/执行工具
# ======================================
def _use_color() -> bool:
    if _env_truthy("BMS_NO_COLOR"):
        return False
    # 兼容大多数终端；若环境不支持 ANSI，可 export BMS_NO_COLOR=1
    return True


def _c(code: str, s: str) -> str:
    if not _use_color():
        return s
    return f"\033[{code}m{s}\033[0m"


def log_info(msg):  # noqa: D401
    print(f"{_c('1;32', '[INFO]')} {msg}")


def log_step(msg):
    print(f"\n{_c('1;34', '===== ' + msg + ' =====')}")


def log_error(msg):
    print(f"{_c('1;31', '[ERROR]')} {msg}")


def check_fail(ret, stage):
    if ret != 0:
        log_error(f"{stage} 失败")
        st = str(stage).lower()
        if "eman" not in st:
            print_log_locations()
        sys.exit(1)


def run_cmd(cmd, stage):
    log_info(f"执行: {cmd}")
    _collect_log_from_cmd(cmd)
    ret = os.system(cmd)
    check_fail(ret, stage)


# ======================================
# LSF 提交
# ======================================
def submit_lsf(job_name, run_cmd_str, queue=DEFAULT_QUEUE, ncore=DEFAULT_NCORE, mem_gb=None):
    ncore = max(1, int(ncore))
    mem_opt = ""
    if mem_gb is not None:
        mem_gb = int(mem_gb)
        if mem_gb <= 0:
            log_error(f"非法内存参数 -m/--mem: {mem_gb}（单位GB）")
            sys.exit(1)
        mem_mb = mem_gb * 1024
        mem_opt = f"-M {mem_mb} -R \"rusage[mem={mem_mb}]\" "
    lsf_cmd = (
        f"bsub -Is -q {queue} -J {job_name} "
        f"-n {ncore} -R \"span[hosts=1]\" "
        f"{mem_opt}"
        f"'bash -c \"{run_cmd_str}\"'"
    )
    log_info(f"提交交互式LSF任务: {lsf_cmd}")
    os.system(lsf_cmd)
    sys.exit(0)


def _build_python_local_cmd(args, tc_paths_abs):
    q = shlex.quote
    parts = [
        "python3",
        q(os.path.abspath(__file__)),
    ]
    parts.extend([q(p) for p in tc_paths_abs])
    parts.append("-local")
    if getattr(args, "rtl_file", ""):
        parts += ["--rtl-file", q(args.rtl_file)]
    if args.rtl:
        parts.append("-rtl")
    if getattr(args, "fast", False):
        parts.append("-f")
    if args.genlib:
        parts += ["-genlib", q(args.genlib)]
    if args.lib:
        parts += ["-lib", q(args.lib)]
    if args.d:
        parts.append("-d")
    if getattr(args, "c", False):
        parts.append("-c")
    if args.cov:
        parts.append("-cov")
    if args.run_suffix:
        parts += ["-R", q(args.run_suffix)]
    if args.seed:
        parts += ["-s", q(args.seed)]
    if args.compile_only:
        parts.append("--compile-only")
        if getattr(args, "eman_workdir", ""):
            parts += ["--eman-workdir", q(args.eman_workdir)]
    return " ".join(parts)


def _resolve_rtl_file_arg(args):
    if getattr(args, "rtl_file", ""):
        return args.rtl_file.strip()
    return "rtl.f"


def _clean_target_run_dir(path: str):
    p = os.path.abspath(path)
    if not os.path.exists(p):
        return
    log_info(f"-c: 清理目标仿真目录: {p}")
    shutil.rmtree(p, ignore_errors=True)


def _resolve_filelist_path(make_dir: str, filelist: str, default_name: str) -> str:
    chosen = (filelist or "").strip() or default_name
    return chosen if os.path.isabs(chosen) else os.path.join(make_dir, chosen)


def _iter_case_override_dirs(test_lib_dir: str, case_rel: str):
    """从当前 case 目录向上到 test_lib（不含 test_lib）逐层返回目录。"""
    if not test_lib_dir:
        return []
    base = os.path.abspath(test_lib_dir)
    rel = os.path.normpath(case_rel or "")
    if rel in ("", "."):
        return []
    cur = os.path.abspath(os.path.join(base, rel))
    dirs = []
    while True:
        if os.path.commonpath([base, cur]) != base:
            break
        if cur == base:
            break
        dirs.append(cur)
        parent = os.path.dirname(cur)
        if parent == cur:
            break
        cur = parent
    return dirs


def _resolve_case_override_file(test_lib_dir: str, case_rel: str, names) -> str:
    for d in _iter_case_override_dirs(test_lib_dir, case_rel):
        for n in names:
            p = os.path.join(d, n)
            if os.path.isfile(p):
                return os.path.abspath(p)
    return ""


def _resolve_wave_tcl_path(make_dir: str, test_lib_dir: str = "", case_rel: str = "") -> str:
    """
    优先级：
    1) test_lib/<case...>/wave.tcl（就近目录优先，向上回溯至 test_lib）
    2) 与 vcs_com 同级的 common/script/wave.tcl
    """
    case_wave = _resolve_case_override_file(test_lib_dir, case_rel, ("wave.tcl",))
    if case_wave:
        return case_wave
    proj_root = os.path.dirname(os.path.abspath(make_dir))
    return os.path.join(proj_root, "common", "script", "wave.tcl")


def _apply_cov_overrides(
    comp: str,
    rtl_elab: str,
    test_elab: str,
    sim_opt: str,
    cov_comp: str,
    cov_sim: str,
    enabled: bool,
):
    if not enabled:
        return comp, rtl_elab, test_elab, sim_opt
    # 用户约定：COV_COMP 用于 elab（vcs）阶段，而非 vlogan。
    rtl_elab_cov = f"{rtl_elab} {cov_comp}".strip()
    test_elab_cov = f"{test_elab} {cov_comp}".strip()
    return comp, rtl_elab_cov, test_elab_cov, f"{sim_opt} {cov_sim}".strip()


def _sha256_text(s: str) -> str:
    return hashlib.sha256(s.encode("utf-8", errors="ignore")).hexdigest()


def _build_lib_manifest(make_dir, vlog_opt, final_rtl_elab, final_test_elab, comp, vip_opt, rtl_file, verif_file):
    rtl_abs = _resolve_filelist_path(make_dir, rtl_file, "rtl.f")
    verif_abs = _resolve_filelist_path(make_dir, verif_file, "verif.f")
    vip_path = _vip_f_path(make_dir)
    vip_sig = ""
    if vip_path and _filelist_has_source_entries(vip_path):
        vip_sig = _vip_signature(vip_path, comp, vip_opt)
    payload = {
        "format_version": 1,
        "make_dir": os.path.abspath(make_dir),
        "rtl_file": os.path.abspath(rtl_abs),
        "verif_file": os.path.abspath(verif_abs),
        "rtl_file_sig": _filelist_signature(rtl_abs, extra_ctx=f"{vlog_opt}\n{comp}\n{BMS_VLOGAN_EXTRA}"),
        "verif_file_sig": _filelist_signature(verif_abs, extra_ctx=f"{vlog_opt}\n{comp}\n{vip_opt}\n{BMS_VLOGAN_EXTRA}"),
        "vip_file": os.path.abspath(vip_path) if vip_path else "",
        "vip_sig": vip_sig,
        "vlog_opt": vlog_opt,
        "rtl_elab_opt": final_rtl_elab,
        "test_elab_opt": final_test_elab,
        "comp_opt": comp,
        "vip_opt": vip_opt,
        "vlogan_extra": BMS_VLOGAN_EXTRA,
        "vcs_extra": BMS_VCS_EXTRA,
    }
    payload["build_signature"] = _sha256_text(json.dumps(payload, sort_keys=True, ensure_ascii=True))
    return payload


def _load_lib_manifest(lib_dir: str):
    p = os.path.join(lib_dir, LIB_MANIFEST_FILE)
    if not os.path.exists(p):
        return None
    try:
        with open(p, "r", encoding="utf-8") as f:
            return json.load(f)
    except Exception:
        return None


def _save_lib_manifest(lib_dir: str, manifest: dict):
    p = os.path.join(lib_dir, LIB_MANIFEST_FILE)
    with open(p, "w", encoding="utf-8") as f:
        json.dump(manifest, f, ensure_ascii=True, indent=2, sort_keys=True)


# ======================================
# 路径解析
# ======================================
def parse_case_path(case_path):
    abs_case = os.path.abspath(case_path)
    is_tc_file = abs_case.endswith(".tc")
    if is_tc_file:
        log_error("不支持直接传 .tc 文件，请传不带 .tc 的用例路径（如 .../test_lib/ccc/yyy）")
        sys.exit(1)
    parts = abs_case.split(os.sep)
    if "test_lib" not in parts:
        log_error("路径中未找到 test_lib")
        sys.exit(1)

    tl_idx = parts.index("test_lib")
    proj_root = os.sep.join(parts[:tl_idx])
    # 新版默认目录为 vcs_com；兼容旧版 Makefile
    make_candidates = [
        os.path.join(proj_root, "vcs_com"),
        os.path.join(proj_root, "Makefile"),
    ]
    make_dir = ""
    for cand in make_candidates:
        if os.path.isdir(cand):
            make_dir = cand
            break
    if not make_dir:
        log_error(f"未找到编译目录（期望其一）：{make_candidates[0]} 或 {make_candidates[1]}")
        sys.exit(1)
    case_rel = os.sep.join(parts[tl_idx + 1:])
    test_lib_dir = os.path.join(proj_root, "test_lib")
    # 仅支持一种目录样式映射：
    # bms .../test_lib/.../yyy  ->  .../test_lib/.../yyy.tc
    case_leaf = os.path.basename(abs_case)
    case_parent = os.path.dirname(abs_case)
    chosen_tc = os.path.join(case_parent, f"{case_leaf}.tc")
    if not os.path.isfile(chosen_tc):
        log_error(f"未找到 tc（仅支持此规则）: {chosen_tc}")
        sys.exit(1)

    tc_name = os.path.splitext(os.path.basename(chosen_tc))[0]
    tc_rel_file = os.path.relpath(chosen_tc, test_lib_dir)
    case_rel = os.path.relpath(os.path.dirname(chosen_tc), test_lib_dir)
    if case_rel == ".":
        case_rel = ""
    return proj_root, make_dir, test_lib_dir, case_rel, tc_name, tc_rel_file


# ======================================
# vcs_com 分段提取（支持中文【】与英文[]，可带 #）
# ======================================
def _vcs_com_section_mode(line):
    raw = line.strip()
    if raw.startswith("#"):
        raw = raw[1:].strip()
    if "【VCS_TEST_ELAB】" in line or raw.startswith("[VCS_TEST_ELAB]"):
        return "test_elab"
    if "【VCS_RTL_ELAB】" in line or raw.startswith("[VCS_RTL_ELAB]"):
        return "rtl_elab"
    if "【VLOGAN】" in line or raw.startswith("[VLOGAN]"):
        return "vlog"
    return None


def load_vcs_com(make_dir):
    fpath = os.path.join(make_dir, "vcs_com")
    if not os.path.exists(fpath):
        log_error(f"找不到 vcs_com 文件: {fpath}")
        sys.exit(1)

    with open(fpath, "r") as f:
        lines = f.read().splitlines()

    vlog_args, rtl_elab_args, test_elab_args = [], [], []
    current = None
    for line in lines:
        line = line.strip().rstrip("\\").strip()
        if not line:
            continue
        sec = _vcs_com_section_mode(line)
        if sec:
            current = sec
            continue
        if current == "vlog":
            vlog_args.append(line)
        elif current == "rtl_elab":
            rtl_elab_args.append(line)
        elif current == "test_elab":
            test_elab_args.append(line)

    vlog_str = " ".join(vlog_args).strip()
    rtl_elab_str = " ".join(rtl_elab_args).strip()
    test_elab_str = " ".join(test_elab_args).strip()
    if not vlog_str:
        log_error("vcs_com 中 [VLOGAN]/【VLOGAN】分段为空")
        sys.exit(1)
    if not rtl_elab_str:
        log_error("vcs_com 中 [VCS_RTL_ELAB]/【VCS_RTL_ELAB】分段为空")
        sys.exit(1)
    if not test_elab_str:
        log_error("vcs_com 中 [VCS_TEST_ELAB]/【VCS_TEST_ELAB】分段为空")
        sys.exit(1)
    return vlog_str, rtl_elab_str, test_elab_str


# ======================================
# CFG 解析（三层 +VIP+）
# ======================================
def load_config(path):
    lines = []
    if os.path.exists(path):
        with open(path, "r", encoding="utf-8", errors="ignore") as f:
            for line in f:
                line = line.strip().rstrip("\\").strip()
                if line and not line.startswith("#"):
                    lines.append(line)
    return lines


def parse_all_config(global_lines, case_lines, tc_lines):
    comp = rtl_elab = test_elab = sim = vip = ""
    cov_comp = cov_sim = ""
    pre_sim_parts = []
    post_sim = ""
    rtl_file = verif_file = ""
    accum = {
        "comp": [],
        "vip": [],
        "cov_comp": [],
        "cov_sim": [],
        "rtl_elab": [],
        "test_elab": [],
        "sim": [],
    }

    def _split_opt_tokens(s: str):
        txt = (s or "").strip()
        if not txt:
            return []
        try:
            return shlex.split(txt)
        except Exception:
            return txt.split()

    def process(line):
        nonlocal pre_sim_parts, post_sim, rtl_file, verif_file
        if line.startswith("+COMP+ "):
            return ("add", "comp", line.split(" ", 1)[1])
        if line.startswith("-COMP- "):
            return ("remove", "comp", line.split(" ", 1)[1])
        if line.startswith("+VIP+ "):
            return ("add", "vip", line.split(" ", 1)[1])
        if line.startswith("-VIP- "):
            return ("remove", "vip", line.split(" ", 1)[1])
        if line.startswith("+COV_COMP+ "):
            return ("add", "cov_comp", line.split(" ", 1)[1])
        if line.startswith("-COV_COMP- "):
            return ("remove", "cov_comp", line.split(" ", 1)[1])
        if line.startswith("+COV_SIM+ "):
            return ("add", "cov_sim", line.split(" ", 1)[1])
        if line.startswith("-COV_SIM- "):
            return ("remove", "cov_sim", line.split(" ", 1)[1])
        if line.startswith("+RTL_ELAB+ "):
            return ("add", "rtl_elab", line.split(" ", 1)[1])
        if line.startswith("-RTL_ELAB- "):
            return ("remove", "rtl_elab", line.split(" ", 1)[1])
        if line.startswith("+TEST_ELAB+ "):
            return ("add", "test_elab", line.split(" ", 1)[1])
        if line.startswith("-TEST_ELAB- "):
            return ("remove", "test_elab", line.split(" ", 1)[1])
        if line.startswith("+RTL_FILE+ "):
            rtl_file = line.split(" ", 1)[1].strip()
            return None
        if line.startswith("+VERIF_FILE+ "):
            verif_file = line.split(" ", 1)[1].strip()
            return None
        m = re.match(r"(?i)^rtl_file\s*=\s*(.+)$", line)
        if m:
            rtl_file = m.group(1).strip()
            return None
        m = re.match(r"(?i)^verif_file\s*=\s*(.+)$", line)
        if m:
            verif_file = m.group(1).strip()
            return None
        if line.startswith("+SIM+ "):
            val = line.split(" ", 1)[1]
            if val.startswith("+PRE_SIM="):
                chunk = val.split("=", 1)[1].strip()
                if chunk:
                    pre_sim_parts.append(chunk)
                return None
            if val.startswith("+POST_SIM="):
                post_sim = val.split("=", 1)[1]
                return None
            return ("add", "sim", val)
        if line.startswith("-SIM- "):
            return ("remove", "sim", line.split(" ", 1)[1])
        return None

    for line in global_lines + case_lines + tc_lines:
        r = process(line)
        if not r:
            continue
        op, k, v = r
        toks = _split_opt_tokens(v)
        if not toks:
            continue
        if op == "add":
            accum[k].extend(toks)
        elif op == "remove":
            remove_set = set(toks)
            accum[k] = [x for x in accum[k] if x not in remove_set]

    comp = " ".join(accum["comp"]).strip()
    vip = " ".join(accum["vip"]).strip()
    cov_comp = " ".join(accum["cov_comp"]).strip()
    cov_sim = " ".join(accum["cov_sim"]).strip()
    rtl_elab = " ".join(accum["rtl_elab"]).strip()
    test_elab = " ".join(accum["test_elab"]).strip()
    sim = " ".join(accum["sim"]).strip()
    pre_sim = " && ".join(pre_sim_parts)

    return (
        comp.strip(),
        rtl_elab.strip(),
        test_elab.strip(),
        sim.strip(),
        vip.strip(),
        pre_sim,
        post_sim,
        rtl_file,
        verif_file,
        cov_comp.strip(),
        cov_sim.strip(),
    )


def load_three_layer(test_lib_dir, case_rel, tc_rel_file):
    # 兼容旧结构并支持 test 下继续分目录：
    # - 目录模式：test_lib/.../<case>/tc/*.tc
    # - 文件模式：test_lib/.../*.tc
    # cfg 最多 3 层：全局 cfg + 离 tc 最近的两层目录 cfg
    cfg_agg = []
    cfg_agg += load_config(os.path.join(test_lib_dir, "cfg"))

    rel_norm = os.path.normpath(case_rel)
    rel_parts = [p for p in rel_norm.split(os.sep) if p not in ("", ".")]
    # 取离 tc 最近的两层目录（若不足两层则全取）
    tail_parts = rel_parts[-2:] if len(rel_parts) > 2 else rel_parts
    start_idx = len(rel_parts) - len(tail_parts)
    for i in range(1, len(tail_parts) + 1):
        sub = rel_parts[: start_idx + i]
        cfg_agg += load_config(os.path.join(test_lib_dir, *sub, "cfg"))

    t = load_config(os.path.join(test_lib_dir, tc_rel_file))
    return parse_all_config(cfg_agg, [], t)


# ======================================
# 初始化运行目录
# ======================================
def _ensure_testlib_debug_link(test_lib_dir):
    """
    约定：所有 run/lib 都在 test_lib/debug 下。
    若 test_lib/debug 不存在，则创建软链接到 /tmpdata/zc_data/<owner>/debug/it
    其中 owner 为 Linux 用户名（getpass.getuser())。
    """
    debug_path = os.path.join(test_lib_dir, "debug")
    if os.path.exists(debug_path):
        return debug_path

    # 非 Linux/posix 环境无法遵循该软链接约定；仅创建本地目录用于开发机运行
    if os.name != "posix":
        os.makedirs(debug_path, exist_ok=True)
        return debug_path

    try:
        import getpass

        owner = getpass.getuser() or "unknown"
    except Exception:
        owner = "unknown"

    target = f"/tmpdata/zc_data/{owner}/debug/it"

    try:
        # 目标目录不存在就创建（按你的要求：不兜底，直接造出来）
        os.makedirs(target, exist_ok=True)
        os.symlink(target, debug_path)
        log_info(f"已创建 debug 软链接: {debug_path} -> {target}")
    except FileExistsError:
        pass
    except Exception as e:
        log_error(f"创建 debug 软链接失败: {debug_path} -> {target} ({e})")
        raise

    return debug_path


def init_run_dir(test_lib_dir, case_rel, tc_name, suffix=""):
    global CURRENT_RUN_DIR, SIM_LOG_PATH, COMPILE_LOG_PATHS
    # 统一工作目录：test_lib/debug（不跟 case_rel 走）
    base = _ensure_testlib_debug_link(test_lib_dir)
    run_dir = os.path.join(base, f"{tc_name}_{suffix}" if suffix else tc_name)
    os.makedirs(run_dir, exist_ok=True)
    orig = os.getcwd()
    os.chdir(run_dir)
    CURRENT_RUN_DIR = run_dir
    SIM_LOG_PATH = ""
    COMPILE_LOG_PATHS = []
    log_info(f"工作目录: {run_dir}")
    return orig, run_dir


def init_run_dir_at(run_dir_abs: str):
    """在指定绝对路径（可先经环境展开）作为编译/运行目录。"""
    global CURRENT_RUN_DIR, SIM_LOG_PATH, COMPILE_LOG_PATHS
    run_dir_abs = os.path.abspath(os.path.expanduser(os.path.expandvars(run_dir_abs)))
    os.makedirs(run_dir_abs, exist_ok=True)
    orig = os.getcwd()
    os.chdir(run_dir_abs)
    CURRENT_RUN_DIR = run_dir_abs
    SIM_LOG_PATH = ""
    COMPILE_LOG_PATHS = []
    log_info(f"工作目录: {run_dir_abs}")
    return orig, run_dir_abs


def debug_peer_dir(test_lib_dir, name):
    # 与 run_dir 同级：test_lib/debug/<name>
    return os.path.join(test_lib_dir, "debug", name)


# ======================================
# 预编译 UVM
# ======================================
def compile_uvm(vlog_opt):
    uvm_home = _resolve_uvm_home()
    if not uvm_home:
        log_info("跳过 UVM 预编译：未找到 UVM_HOME（可设置 UVM_HOME 或 VCS_HOME）")
        return
    if os.path.exists("uvm_compiled.d"):
        return
    log_step("预编译 UVM")
    uvm_src = os.path.join(uvm_home, "src", "uvm_pkg.sv")
    run_cmd(f"vlogan {BMS_VLOGAN_EXTRA} {vlog_opt} +incdir+{uvm_home}/src {uvm_src}", "vlogan UVM")
    os.system("touch uvm_compiled.d")


# ======================================
# VIP 单独 vlogan（可缓存；或合并到 verif）
# ======================================
def compile_vip(make_dir, vlog_opt, comp_opt, vip_opt, force_rebuild=False):
    if _env_truthy("BMS_VIP_COMBINED_VLOGAN"):
        return
    vip_path = _vip_f_path(make_dir)
    if not vip_path:
        return
    if not _filelist_has_source_entries(vip_path):
        log_info(f"跳过 VIP 单独编译：{os.path.basename(vip_path)} 仅包含选项（无源文件）")
        return
    vip_sig = _vip_signature(vip_path, comp_opt, vip_opt)
    if (not force_rebuild) and _vip_cache_hit(vip_sig):
        return
    if force_rebuild:
        log_info("FORCE: 检测到 -rtl，重编 VIP")
    log_step(f"编译 VIP（{os.path.basename(vip_path)}）")
    extra = f"{comp_opt} {vip_opt}".strip()
    run_cmd(f"vlogan {BMS_VLOGAN_EXTRA} {vlog_opt} {extra} -f {vip_path}", "vlogan VIP")
    _mark_vip_compiled(vip_sig)


# ======================================
# design_side: 编译 RTL + elab
# ======================================
def compile_design(make_dir, vlog_opt, rtl_elab_opt, comp_opt, rtl_file, force_rebuild=False):
    """Build simv from rtl.f (or force rebuild with ``force_rebuild``)."""
    if force_rebuild:
        if os.path.exists("simv"):
            try:
                os.remove("simv")
            except Exception:
                pass
        if os.path.exists("simv.daidir"):
            try:
                shutil.rmtree("simv.daidir", ignore_errors=True)
            except Exception:
                pass
        if os.path.exists("csrc"):
            try:
                shutil.rmtree("csrc", ignore_errors=True)
            except Exception:
                pass
        log_info("FORCE: 检测到 -rtl，重编 RTL")
    if os.path.exists("simv"):
        return
    rtl_f = _resolve_filelist_path(make_dir, rtl_file, "rtl.f")
    if not os.path.exists(rtl_f):
        log_error(f"找不到 RTL filelist: {rtl_f}")
        sys.exit(1)
    log_step(f"编译 RTL（{rtl_file}）")
    run_cmd(f"vlogan {BMS_VLOGAN_EXTRA} {vlog_opt} {comp_opt} -f {rtl_f}", "vlogan RTL")
    run_cmd(f"vcs {BMS_VCS_EXTRA} {rtl_elab_opt} -o simv", "vcs elab RTL")


# ======================================
# test_side: 编译 TB(+可选VIP合并) + 最终 elab simv
# ======================================
def compile_test(make_dir, vlog_opt, test_elab_opt, comp_opt, vip_opt="", force_vip_rebuild=False, verif_file=""):
    verif_f = _resolve_filelist_path(make_dir, verif_file, "verif.f")
    if not os.path.exists(verif_f):
        log_error(f"找不到 verif filelist: {verif_f}")
        sys.exit(1)
    vip_path = _vip_f_path(make_dir)
    log_step("编译 Testbench")
    if _env_truthy("BMS_VIP_COMBINED_VLOGAN") and vip_path:
        extra = f"{comp_opt} {vip_opt}".strip()
        vip_sig = _vip_signature(vip_path, comp_opt, vip_opt)
        if (not force_vip_rebuild) and _vip_cache_hit(vip_sig):
            run_cmd(f"vlogan {BMS_VLOGAN_EXTRA} {vlog_opt} {comp_opt} -f {verif_f}", "vlogan verif（VIP缓存）")
        else:
            if force_vip_rebuild:
                log_info("FORCE: 检测到 -rtl，重编 VIP+verif")
            run_cmd(f"vlogan {BMS_VLOGAN_EXTRA} {vlog_opt} {extra} -f {vip_path} -f {verif_f}", "vlogan VIP+verif")
            _mark_vip_compiled(vip_sig)
    else:
        run_cmd(f"vlogan {BMS_VLOGAN_EXTRA} {vlog_opt} {comp_opt} -f {verif_f}", "vlogan verif")
    run_cmd(f"vcs {BMS_VCS_EXTRA} {test_elab_opt} -o simv", "vcs elab simv")


def _dtl_names(tc_name: str):
    test_pkg = BMS_DTL_TEST_PKG_FMT.format(tc=tc_name, tc_up=tc_name.upper())
    test_dir = BMS_DTL_TEST_DIR_FMT.format(tc=tc_name, tc_up=tc_name.upper())
    return test_pkg, test_dir


def _split_verif_filelists_for_dtl(make_dir):
    """Split verif.f into base/test lists for DTL.

    Base list excludes only the dedicated test package file so seq (dma/ails)
    stay in BASE_IP when mytest lives in base_test_pkg and needs factory lookup.
    Test list contains only npu_core_test_pkg (optional extra test-side code).
    """
    verif_f = os.path.join(make_dir, "verif.f")
    base_f = ".bms_verif_base_dtl.f"
    test_f = ".bms_verif_test_dtl.f"

    base_lines = []
    test_lines = []
    with open(verif_f, "r", encoding="utf-8", errors="ignore") as f:
        for raw in f:
            line = raw.strip()
            if (not line) or line.startswith("#"):
                continue
            is_test_side = line.endswith("/seq_lib/npu_core_test_pkg.sv") or line.endswith(
                "\\seq_lib\\npu_core_test_pkg.sv"
            )
            if is_test_side:
                test_lines.append(line)
            else:
                base_lines.append(line)

    with open(base_f, "w", encoding="utf-8") as f:
        f.write("\n".join(base_lines) + ("\n" if base_lines else ""))
    with open(test_f, "w", encoding="utf-8") as f:
        f.write("\n".join(test_lines) + ("\n" if test_lines else ""))
    return base_f, test_f


def _filelist_signature(filelist_path: str, extra_ctx: str = "") -> str:
    h = hashlib.sha256()
    h.update(extra_ctx.encode("utf-8", errors="ignore"))
    if not os.path.exists(filelist_path):
        h.update(b"<missing_filelist>")
        return h.hexdigest()
    with open(filelist_path, "r", encoding="utf-8", errors="ignore") as f:
        for raw in f:
            line = raw.strip()
            if (not line) or line.startswith("#"):
                continue
            h.update(line.encode("utf-8", errors="ignore"))
            h.update(b"\n")
            # Try to track source file mtime/size for incremental validity.
            p = os.path.expandvars(line)
            if (not os.path.isabs(p)) and os.path.exists(p):
                p = os.path.abspath(p)
            if os.path.exists(p) and os.path.isfile(p):
                st = os.stat(p)
                h.update(f"{st.st_mtime_ns}:{st.st_size}".encode("utf-8"))
            else:
                h.update(b"<no_stat>")
    return h.hexdigest()


def _dtl_sharedlib_opt_from_base(elab_opt: str) -> str:
    """DTL sharedlib step should use the same elab options as base step.
    Remove -top for sharedlib compile.
    """
    if not elab_opt:
        return ""
    s = f" {elab_opt} "
    s = re.sub(r"\s-top\s+\S+", " ", s)
    return " ".join(s.split())


def compile_verif_once(make_dir, vlog_opt, comp_opt, vip_opt, skip_vip_rebuild=False):
    """分析 verif.f 一次，供 base/test pkg 后续分阶段 link。"""
    verif_base_f, _ = _split_verif_filelists_for_dtl(make_dir)

    vip_path = _vip_f_path(make_dir)
    if _env_truthy("BMS_VIP_COMBINED_VLOGAN") and vip_path and (not _vip_cache_hit()) and (not skip_vip_rebuild):
        extra = f"{comp_opt} {vip_opt}".strip()
        run_cmd(
            f"vlogan {BMS_VLOGAN_EXTRA} {vlog_opt} {extra} -f {vip_path} -f {verif_base_f}",
            "vlogan VIP+verif_base（DTL）",
        )
        os.system(f"touch {VIP_COMPILED_MARKER}")
    elif skip_vip_rebuild and _env_truthy("BMS_VIP_COMBINED_VLOGAN") and vip_path:
        log_info("FAST: 跳过 VIP 合并编译，仅编 verif_base")
        run_cmd(
            f"vlogan {BMS_VLOGAN_EXTRA} {vlog_opt} {comp_opt} -f {verif_base_f}",
            "vlogan verif_base（FAST）",
        )
    else:
        run_cmd(
            f"vlogan {BMS_VLOGAN_EXTRA} {vlog_opt} {comp_opt} -f {verif_base_f}",
            "vlogan verif_base（DTL）",
        )
    os.system("touch verif_compiled.d")


def compile_test_units_dtl(make_dir, vlog_opt, comp_opt):
    """Analyze test-side units (seq domain pkgs + test pkg) for DTL sharedlib step."""
    _, verif_test_f = _split_verif_filelists_for_dtl(make_dir)
    if not os.path.exists(verif_test_f) or os.path.getsize(verif_test_f) == 0:
        return
    run_cmd(
        f"vlogan {BMS_VLOGAN_EXTRA} {vlog_opt} {comp_opt} -f {verif_test_f}",
        "vlogan verif_test（DTL）",
    )


def compile_base_dtl(make_dir, vlog_opt, rtl_elab_opt, comp_opt, rtl_file, force_rtl=False):
    """编 base test pkg 并生成 simv（enable_dynamic_tb）。"""
    # 默认复用已编译 RTL/base；加 -rtl 时强制重编。
    # 也可配合 BMS_DTL_REUSE_BASE 控制复用。
    reuse_base = _env_truthy("BMS_DTL_REUSE_BASE", True) and (not force_rtl)
    if reuse_base and os.path.exists("simv") and os.path.exists(BMS_DTL_BASE_DIR):
        log_info("DTL: 复用已存在 BASE_IP/simv（默认模式）")
        return
    if force_rtl:
        log_info("DTL: 检测到 -rtl，强制重编 RTL/base")
    if os.path.exists("simv"):
        try:
            os.remove("simv")
        except Exception:
            pass
    if os.path.exists("simv.daidir"):
        try:
            shutil.rmtree("simv.daidir", ignore_errors=True)
        except Exception:
            pass
    if os.path.exists(BMS_DTL_BASE_DIR):
        try:
            shutil.rmtree(BMS_DTL_BASE_DIR, ignore_errors=True)
        except Exception:
            pass
    rtl_f = _resolve_filelist_path(make_dir, rtl_file, "rtl.f")
    if not os.path.exists(rtl_f):
        log_error(f"找不到 RTL filelist: {rtl_f}")
        sys.exit(1)
    log_step(f"DTL: 编译 RTL（{rtl_file}）")
    run_cmd(f"vlogan {BMS_VLOGAN_EXTRA} {vlog_opt} {comp_opt} -f {rtl_f}", "vlogan RTL（DTL）")
    log_step(f"DTL: 生成 simv（base pkg={BMS_DTL_BASE_PKG}, dir={BMS_DTL_BASE_DIR}）")
    run_cmd(
        f"vcs {BMS_VCS_EXTRA} {rtl_elab_opt} {BMS_DTL_BASE_PKG} "
        f"-partcomp -dir={BMS_DTL_BASE_DIR} -enable_dynamic_tb -o simv",
        "vcs base（DTL）",
    )


def compile_test_dtl(dtl_shared_opt, tc_name, sharedlib_path):
    """按 tc 名生成 test pkg 动态库。"""
    test_pkg, test_dir = _dtl_names(tc_name)
    # DTL 下默认每次都重建 test pkg 分区，避免改 seq 后被旧 TEST_PKG 缓存吞掉。
    # 如需复用旧分区，可 export BMS_DTL_REUSE_TEST_PKG=1。
    if _env_truthy("BMS_DTL_REUSE_TEST_PKG") and os.path.exists(test_dir):
        return test_pkg, test_dir
    log_step(f"DTL: 编译 test pkg（pkg={test_pkg}, dir={test_dir}）")
    run_cmd(
        f"vcs {BMS_VCS_EXTRA} -sharedlib={sharedlib_path} -partcomp {test_pkg} -dir={test_dir} "
        f"{dtl_shared_opt} -dynamic_tb",
        "vcs sharedlib（DTL）",
    )
    return test_pkg, test_dir


# ======================================
# 日志监控
# ======================================
def monitor_log_size(log_path):
    while True:
        if os.path.exists(log_path) and os.path.getsize(log_path) > MAX_LOG_SIZE:
            log_error(f"日志超过 {MAX_LOG_SIZE_GB}G，停止仿真")
            handle_exit(0, None)
            return
        time.sleep(2)


# ======================================
# 运行 + 简单判错
# ======================================
def run_and_check(
    tc_name,
    sim_opts,
    pre,
    post,
    seed,
    do_dump,
    wave_tcl_path="",
    no_rtl_update_notice=False,
    *,
    make_dir: str = "",
    test_lib_dir: str = "",
    case_rel: str = "",
):
    global sim_proc, SIM_LOG_PATH
    logfile = f"{tc_name}.log"
    SIM_LOG_PATH = _normalize_log_path(logfile)
    if pre:
        run_cmd(pre, "pre_sim")
    seed_opt = f"+UVM_RANDOM_SEED={seed} +ntb_random_seed={seed}" if seed else ""
    cmd = f"./simv {sim_opts} {seed_opt} -l {logfile}"
    if do_dump:
        if not wave_tcl_path:
            log_error("缺少波形脚本路径：请检查 common/script/wave.tcl")
            sys.exit(1)
        wave_tcl_abs = os.path.abspath(wave_tcl_path)
        if not os.path.exists(wave_tcl_abs):
            log_error(f"未找到波形脚本: {wave_tcl_abs}")
            sys.exit(1)
        log_info(f"波形脚本: {wave_tcl_abs}")
        cmd += f" -ucli -do {shlex.quote(wave_tcl_abs)}"
    log_step("开始仿真")
    log_info(f"仿真命令: {cmd}")
    sim_proc = subprocess.Popen(cmd, shell=True)
    threading.Thread(target=monitor_log_size, args=(logfile,), daemon=True).start()
    rc = sim_proc.wait()
    if post:
        run_cmd(post, "post_sim")
    has_err = (rc != 0)
    if os.path.exists(logfile):
        with open(logfile, "r", errors="ignore") as f:
            c = f.read()
        # 非 -eman：优先吃 regr/vcs_error_patterns.eme（或 test 目录覆盖）中的规则，
        # 避免把 UVM summary 统计行误判为失败。
        ep = ""
        if make_dir:
            ep = _resolve_local_error_pattern_path(make_dir, test_lib_dir=test_lib_dir, case_rel=case_rel)
        pats = _load_error_patterns_file(ep) if ep else []
        if pats:
            has_err = has_err or _has_log_error_by_patterns(c, pats)
        else:
            # fallback：无规则文件时保留旧逻辑
            if re.search(r"UVM_(ERROR|FATAL)", c, re.I):
                has_err = True
            if re.search(r"Assertion failed|offending", c, re.I):
                has_err = True
    print_result_banner(has_err)
    print_log_locations()
    if no_rtl_update_notice:
        print(f"{_c('1;31', '[NOTICE]')} 本次采用快速复用模式，RTL/VIP 未执行强制重编")


def run_and_check_dtl(
    tc_name,
    sim_opts,
    pre,
    post,
    seed,
    do_dump,
    test_pkg,
    test_dir,
    simv_path,
    wave_tcl_path="",
    no_rtl_update_notice=False,
):
    global sim_proc, SIM_LOG_PATH
    logfile = f"{tc_name}.log"
    SIM_LOG_PATH = _normalize_log_path(logfile)
    if pre:
        run_cmd(pre, "pre_sim")
    seed_opt = f"+UVM_RANDOM_SEED={seed} +ntb_random_seed={seed}" if seed else ""
    # Use absolute DTL package dir to avoid cwd mismatch (e.g. bsub node shell).
    pkg_dir = test_dir if os.path.isabs(test_dir) else os.path.abspath(test_dir)
    cmd = f"{simv_path} +dtl_add_pkg={pkg_dir}:{test_pkg} {sim_opts} {seed_opt} -l {logfile}"
    if do_dump:
        if not wave_tcl_path:
            log_error("缺少波形脚本路径：请检查 common/script/wave.tcl")
            sys.exit(1)
        wave_tcl_abs = os.path.abspath(wave_tcl_path)
        if not os.path.exists(wave_tcl_abs):
            log_error(f"未找到波形脚本: {wave_tcl_abs}")
            sys.exit(1)
        log_info(f"波形脚本: {wave_tcl_abs}")
        cmd += f" -ucli -do {shlex.quote(wave_tcl_abs)}"
    log_step("开始仿真（DTL）")
    log_info(f"仿真命令: {cmd}")
    sim_proc = subprocess.Popen(cmd, shell=True)
    threading.Thread(target=monitor_log_size, args=(logfile,), daemon=True).start()
    rc = sim_proc.wait()
    if post:
        run_cmd(post, "post_sim")
    has_err = (rc != 0)
    if os.path.exists(logfile):
        with open(logfile, "r", errors="ignore") as f:
            c = f.read()
        if re.search(r"UVM_(ERROR|FATAL)", c, re.I):
            has_err = True
        if re.search(r"Assertion failed|offending", c, re.I):
            has_err = True
    print_result_banner(has_err)
    print_log_locations()
    if no_rtl_update_notice:
        print(f"{_c('1;31', '[NOTICE]')} 本次采用快速复用模式，RTL/VIP 未执行强制重编")


def _yaml_dq(s: str) -> str:
    return '"' + s.replace("\\", "\\\\").replace('"', '\\"') + '"'


def _eman_emc_top_block(wave_tcl_path: str, run_dir_expr: str) -> str:
    """每份 .emc 头：env + variables(fsdb_opt, cov_opt) + modes，供 Web 里手动 rerun 时选 dump / 覆盖率。"""
    w = (wave_tcl_path or "").strip()
    if w and os.path.isfile(os.path.abspath(w)):
        wabs = os.path.abspath(w)
        fsdb_ex = f"-ucli -do {shlex.quote(wabs)}"
    else:
        fsdb_ex = ""
    cov_ex = f"-cm_name coverage -cm_dir {run_dir_expr}/$$EMAN_TESTCASE/coverage"
    return (
        "env:\n"
        "  - EMAN_HOME\n"
        "  - EMAN_PROJECT\n"
        "  - DESIGNWARE_HOME\n"
        "variables:\n"
        f"  - fsdb_opt: {_yaml_dq(fsdb_ex)}\n"
        f"  - cov_opt: {_yaml_dq(cov_ex)}\n"
        "modes:\n"
        "  - fsdb: fsdb_opt\n"
        "  - cov: cov_opt\n"
    )


def parse_eman_counts(num_spec: str, n_paths: int, force_single: bool = False) -> list:
    """解析 -num：单值对所有路径复用；多值逗号分隔与路径顺序一一对应。"""
    raw = (num_spec or "1").strip()
    parts = [p.strip() for p in raw.split(",") if p.strip()]
    if not parts:
        vals = [1]
    else:
        vals = []
        for p in parts:
            try:
                vals.append(max(1, int(p)))
            except ValueError:
                log_error(f"-num 非法（需整数或逗号分隔整数）: {num_spec!r}")
                sys.exit(1)
    if force_single and len(vals) > 1:
        log_error("目录回归模式下 -num 仅支持单个值（对所有 case 生效）")
        sys.exit(1)
    if n_paths < 1:
        return []
    if len(vals) == 1:
        return vals * n_paths
    if len(vals) != n_paths:
        log_error(
            f"-num 与用例路径数不匹配：解析到 {len(vals)} 个值 {vals!r}，"
            f"需要 1 个（共用）或 {n_paths} 个（与路径顺序对齐）"
        )
        sys.exit(1)
    return vals


def expand_eman_targets(raw_paths: list) -> tuple[list, bool]:
    """
    -eman 下支持目录输入：
    1) 若目录本身符合 case 规则（<dir>/<leaf>.tc），视作单 case；
    2) 否则递归收集目录下所有 .tc，映射为不带 .tc 的 case 路径。
    返回：(展开后的绝对路径列表, 是否发生目录展开)
    """
    out: list[str] = []
    expanded_from_dir = False
    seen = set()

    for p in raw_paths:
        ap = os.path.abspath(p)
        if not os.path.isdir(ap):
            if ap not in seen:
                out.append(ap)
                seen.add(ap)
            continue

        leaf = os.path.basename(ap.rstrip(os.sep))
        direct_tc = os.path.join(ap, f"{leaf}.tc")
        if os.path.isfile(direct_tc):
            if ap not in seen:
                out.append(ap)
                seen.add(ap)
            continue

        tc_files = []
        for root, _, files in os.walk(ap):
            for fn in files:
                if fn.endswith(".tc"):
                    tc_files.append(os.path.join(root, fn))
        tc_files.sort()
        if not tc_files:
            log_error(f"-eman 目录下未找到任何 .tc: {ap}")
            sys.exit(1)
        expanded_from_dir = True
        for tf in tc_files:
            case_p = tf[:-3]  # remove ".tc"
            if case_p not in seen:
                out.append(case_p)
                seen.add(case_p)

    return out, expanded_from_dir


def _format_eman_session_name(metas_light: list, ts: str) -> str:
    """
    供 eman -session_name：与 emc 中 build 的 name 一致单 case 为 build_<tc>；
    多 case 为 <N>builds（如 3builds）。整体形如：<build_id>_session_<user>_<ts>。
    """
    user = _eman_login_name()
    if len(metas_light) == 1:
        b = f"build_{_eman_safe_id(metas_light[0]['tc_name'])}"
    else:
        b = f"{len(metas_light)}builds"
    return _eman_safe_id(f"{b}_session_{user}_{ts}")


def derive_eman_session_name(raw_paths: list, expanded_paths: list, folder_expand_mode: bool) -> str:
    """
    规则：
    1) bms -eman 接一个目录且进入递归目录模式 -> 用目录名
    2) 其余（一个或多个 case）-> 用第一个 case 的 tc 名
    """
    if (not raw_paths) or (not expanded_paths):
        return ""
    if len(raw_paths) == 1:
        raw0 = os.path.abspath(raw_paths[0])
        if folder_expand_mode and os.path.isdir(raw0):
            return _eman_safe_id(os.path.basename(raw0.rstrip(os.sep)))
    try:
        _, _, _, _, tc_name, _ = parse_case_path(expanded_paths[0])
        if len(expanded_paths) > 1:
            return _eman_safe_id(f"{tc_name}_and_other")
        return _eman_safe_id(tc_name)
    except Exception:
        return _eman_safe_id(os.path.basename(expanded_paths[0].rstrip(os.sep)))


def _proj_root_from_make_dir(make_dir: str) -> str:
    """make_dir 一般为 .../vcs_com 或 .../Makefile 所在目录，其父目录为工程根。"""
    return os.path.dirname(os.path.abspath(make_dir))


def _regr_dir_from_make_dir(make_dir: str) -> str:
    return os.path.join(_proj_root_from_make_dir(make_dir), "regr")


def _eman_login_name() -> str:
    """当前 OS 登录用户名（与 eman -project 默认同源）；路径里 jialin 这类目录即为此名。"""
    try:
        import getpass

        return (getpass.getuser() or "unknown").strip() or "unknown"
    except Exception:
        return "unknown"


def _eman_debug_base_dir(test_lib_dir: str) -> str:
    """
    EMAN 下编译/仿真的 debug 根目录。不设 BMS_EMAN_DEBUG_DIR 时为 test_lib/debug（与单例 run 一致）。
    覆盖示例：export BMS_EMAN_DEBUG_DIR=/tmpdata/zc_data/{user}/debug
    其中 {user}、%u 会替换为当前登录名；亦可写 $USER 等（经 expandvars）。
    """
    e = os.environ.get("BMS_EMAN_DEBUG_DIR", "").strip()
    if e:
        u = _eman_login_name()
        e = e.replace("{user}", u).replace("%u", u)
        return os.path.abspath(os.path.expanduser(os.path.expandvars(e)))
    return os.path.abspath(os.path.join(test_lib_dir, "debug"))


def _eman_generated_emc_dir(test_lib_dir: str) -> str:
    """bms 生成的回归 .emc 输出目录：{debug_base}/eman/eman_regression/emc_dir/。"""
    return os.path.join(_eman_debug_base_dir(test_lib_dir), "eman", "eman_regression", "emc_dir")


def _default_eman_project_name() -> str:
    """eman -project 默认用当前系统用户名；可用 BMS_EMAN_PROJECT / EMAN_PROJECT 覆盖。"""
    env_p = os.environ.get("BMS_EMAN_PROJECT", os.environ.get("EMAN_PROJECT", "")).strip()
    if env_p:
        return env_p
    return _eman_login_name()


def _resolve_eman_template_path(make_dir: str) -> str:
    env_t = os.environ.get("BMS_EMAN_TEMPLATE", "").strip()
    if env_t and os.path.isfile(env_t):
        return env_t
    regr_t = os.path.join(_regr_dir_from_make_dir(make_dir), "eman_template.emc")
    if os.path.isfile(regr_t):
        return regr_t
    cand = os.path.join(make_dir, "eman_template.emc")
    if os.path.isfile(cand):
        return cand
    here = os.path.join(os.path.dirname(os.path.abspath(__file__)), "eman_template.emc")
    return here if os.path.isfile(here) else ""


def _resolve_eman_error_pattern_path(make_dir: str, test_lib_dir: str = "", case_rel: str = "") -> str:
    """优先 case 目录同名文件，其次 regr/vcs_error_patterns.eme|.emc；可用环境变量覆盖。"""
    env_p = os.environ.get("BMS_EMAN_ERROR_PATTERN", "").strip()
    if env_p and os.path.isfile(env_p):
        return os.path.abspath(env_p)
    case_p = _resolve_case_override_file(
        test_lib_dir, case_rel, ("vcs_error_patterns.eme", "vcs_error_patterns.emc")
    )
    if case_p:
        return case_p
    regr = _regr_dir_from_make_dir(make_dir)
    for name in ("vcs_error_patterns.eme", "vcs_error_patterns.emc"):
        p = os.path.join(regr, name)
        if os.path.isfile(p):
            return os.path.abspath(p)
    return ""


def _resolve_local_error_pattern_path(make_dir: str, test_lib_dir: str = "", case_rel: str = "") -> str:
    """
    非 -eman 模式下的 log 判定规则文件。
    优先级：
    1) test_lib/<case...>/vcs_error_patterns.eme|.emc（就近目录优先，向上回溯至 test_lib）
    2) <proj_root>/regr/vcs_error_patterns.eme|.emc（与 vcs_com 同级的 regr 目录）
    可用环境变量 BMS_LOCAL_ERROR_PATTERN 覆盖为绝对路径。
    """
    env_p = os.environ.get("BMS_LOCAL_ERROR_PATTERN", "").strip()
    if env_p and os.path.isfile(env_p):
        return os.path.abspath(env_p)
    case_p = _resolve_case_override_file(
        test_lib_dir, case_rel, ("vcs_error_patterns.eme", "vcs_error_patterns.emc")
    )
    if case_p:
        return case_p
    regr = _regr_dir_from_make_dir(make_dir)
    for name in ("vcs_error_patterns.eme", "vcs_error_patterns.emc"):
        p = os.path.join(regr, name)
        if os.path.isfile(p):
            return os.path.abspath(p)
    return ""


def _load_error_patterns_file(path: str) -> list[tuple[re.Pattern, str]]:
    """
    解析类似 ExecMan error pattern 文件中的 pattern 行：
      <regex>:::<status>:::<tag>:::<id>
    这里只使用 regex 与 status（pass/warn/fail/error/fatal 等），其余字段忽略。
    """
    out: list[tuple[re.Pattern, str]] = []
    if not path or (not os.path.isfile(path)):
        return out
    try:
        with open(path, "r", encoding="utf-8", errors="ignore") as f:
            for raw in f.read().splitlines():
                line = raw.strip()
                if not line or line.startswith("#"):
                    continue
                if ":::" not in line:
                    continue
                parts = [p.strip() for p in line.split(":::")]
                if len(parts) < 2:
                    continue
                pat = parts[0]
                status = (parts[1] or "").strip().lower()
                if not pat or not status:
                    continue
                try:
                    out.append((re.compile(pat), status))
                except re.error:
                    continue
    except Exception:
        return out
    return out


def _has_log_error_by_patterns(log_text: str, patterns: list[tuple[re.Pattern, str]]) -> bool:
    """
    按 pattern 文件判定是否失败：
    - 对每一行按文件顺序找第一个匹配的 pattern
    - 若其 status 属于 fail/error/fatal 则判失败；pass/warn/info 不判失败
    """
    if not log_text or not patterns:
        return False
    bad = {"fail", "failed", "error", "fatal"}
    for ln in log_text.splitlines():
        for rx, st in patterns:
            if rx.search(ln):
                return st in bad
    return False


def _resolve_eman_rules_path(make_dir: str) -> str:
    """优先级：BMS_EMAN_RULES_FILE -> regr/bms_rules.emr -> regr/rules.emr。"""
    env_p = os.environ.get("BMS_EMAN_RULES_FILE", "").strip()
    if env_p and os.path.isfile(env_p):
        return os.path.abspath(env_p)
    regr = _regr_dir_from_make_dir(make_dir)
    for name in ("bms_rules.emr", "rules.emr"):
        p = os.path.join(regr, name)
        if os.path.isfile(p):
            return os.path.abspath(p)
    return ""


def _eman_default_config_name(test_lib_dir: str = "", make_dir: str = "") -> str:
    """
    eman -config 的默认值：test_lib 的父目录名（如 .../2_verf/it/test_lib -> it）。
    仅 --emc 且无 test_lib 时，用 make_dir（vcs_com 或 Makefile）的父目录名。
    """
    if test_lib_dir:
        parent = os.path.dirname(os.path.abspath(test_lib_dir))
        return os.path.basename(parent) if parent else ""
    if make_dir:
        md = os.path.abspath(make_dir)
        b = os.path.basename(md)
        if b in ("vcs_com", "Makefile"):
            pr = os.path.dirname(md)
            return os.path.basename(pr) if pr else ""
    return ""


def _default_eman_merge_dir(test_lib_dir: str = "", emc_abs: str = "") -> str:
    """
    默认 merge 目录：
    - 有 test_lib 时：<debug_base>/eman/merge/<emc_stem>
    - 仅有 emc 时：<emc_dir>/merge/<emc_stem>
    """
    stem = ""
    if emc_abs:
        stem = os.path.splitext(os.path.basename(emc_abs))[0]
    if not stem:
        stem = "bms_merge"
    if test_lib_dir:
        base = os.path.join(_eman_debug_base_dir(test_lib_dir), "eman", "merge")
        return os.path.abspath(os.path.join(base, stem))
    if emc_abs:
        return os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(emc_abs)), "merge", stem))
    return ""


def _guess_make_dir_from_emc_path(emc_path: str) -> str:
    """从生成的 emc 路径向上找 vcs_com，供 --emc 模式拼 eman 参数。"""
    d = os.path.dirname(os.path.abspath(emc_path))
    for _ in range(16):
        vcs_com = os.path.join(d, "vcs_com")
        if os.path.isdir(vcs_com):
            return vcs_com
        parent = os.path.dirname(d)
        if parent == d:
            break
        d = parent
    return ""


def build_eman_command_line(
    emc_abs: str,
    make_dir: str,
    test_lib_dir: str = "",
    case_rel: str = "",
    cov_enable: bool = False,
    session_name_override: str = "",
    top_run_dir_override: str = "",
) -> str:
    """
    参考 ExecMan GUI（server）：eman -auto_cleanup -project [-config] [-error_pattern_file] -regr_config ...
    -config 默认：test_lib 上一层目录名；可用 BMS_EMAN_CONFIG 覆盖。
    工程根下 regr/ 与 vcs_com 同级，放 eman_template.emc 与 vcs_error_patterns.eme。
    """
    parts = ["eman"]
    if (not _env_truthy("BMS_EMAN_NO_AUTO_CLEANUP")) and _env_truthy(
        "BMS_EMAN_AUTO_CLEANUP", True
    ):
        parts.append("-auto_cleanup")
    if _env_truthy("BMS_EMAN_OVERWRITE"):
        parts.append("-overwrite")

    cfg = os.environ.get("BMS_EMAN_CONFIG", "").strip()
    if not cfg:
        cfg = _eman_default_config_name(test_lib_dir=test_lib_dir, make_dir=make_dir)
    if cfg:
        parts += ["-config", shlex.quote(cfg)]

    ep = ""
    if make_dir:
        ep = _resolve_eman_error_pattern_path(make_dir, test_lib_dir=test_lib_dir, case_rel=case_rel)
    if ep:
        parts += ["-error_pattern_file", shlex.quote(ep)]
    rf = ""
    if make_dir:
        rf = _resolve_eman_rules_path(make_dir)
    if rf:
        parts += ["-rules_file", shlex.quote(rf)]

    proj = _default_eman_project_name()
    parts += ["-project", shlex.quote(proj)]
    if session_name_override:
        parts += ["-session_name", shlex.quote(session_name_override)]
    top_run_dir = (top_run_dir_override or "").strip()
    if top_run_dir:
        parts += ["-top_run_dir", shlex.quote(os.path.abspath(top_run_dir))]
    # bms -eman -debug 只改 .emc（debug_rerun_count/debug_run_cmd/debug_run_dir），不向 eman 命令行自动加 -debug。
    # 需要 eman -debug 时请设 BMS_EMAN_REGR_DEBUG=1 或 BMS_EMAN_REGR_DEBUG_FLAGS。
    _rdf = (os.environ.get("BMS_EMAN_REGR_DEBUG_FLAGS", "") or "").strip()
    if _rdf:
        parts.extend(shlex.split(_rdf))
    elif _env_truthy("BMS_EMAN_REGR_DEBUG"):
        parts.append("-debug")
    parts += ["-regr_config", shlex.quote(os.path.abspath(emc_abs))]

    # 覆盖率模式下才执行 merge（bms -eman -cov）
    if cov_enable and _env_truthy("BMS_EMAN_MERGE", True):
        merge_dir = os.environ.get("BMS_EMAN_MERGE_DIR", "").strip()
        if not merge_dir:
            merge_dir = _default_eman_merge_dir(test_lib_dir=test_lib_dir, emc_abs=emc_abs)
        if merge_dir:
            parts += ["-merge_dir", shlex.quote(os.path.abspath(os.path.expanduser(os.path.expandvars(merge_dir))))]
        # URG 参数：仅当用户显式指定时才传入（默认不自动注入）。
        # 若需要并行 merge，请优先使用 .emc 的 merge_options.parallel_merge；
        # 或自行在命令行添加 ExecMan 支持的并行参数（如 -parallel_merge）。
        urg_opts = os.environ.get("BMS_EMAN_URG_OPTS", "").strip()
        if urg_opts:
            parts += ["-urg_opts", shlex.quote(urg_opts)]

    extra = os.environ.get("BMS_EMAN_EXTRA", "").strip()
    if extra:
        parts.extend(shlex.split(extra))
    eman_cmd = " ".join(parts)
    return f"bsub -Is -q normal {eman_cmd} &"


def _eman_safe_id(name: str) -> str:
    return re.sub(r"[^0-9a-zA-Z_]", "_", name)


def _eman_run_dir_expr_for_case(test_lib_dir: str, tc_name: str) -> str:
    """
    EMAN build/test 共用的工作目录表达式（--eman-workdir 与 simv 路径一致）。
    默认：{debug_base}/eman/eman_regression/$$EMAN_SESSION_NAME/{tc_name}（与 emc_dir、eman_rundir/ 并列于 eman_regression 下）。
    若需整回归共用一个目录（旧行为），请 export BMS_EMAN_RUNDIR_EXPR=$$EMAN_RUNDIR
    """
    if "BMS_EMAN_RUNDIR_EXPR" in os.environ:
        return (os.environ.get("BMS_EMAN_RUNDIR_EXPR", "") or "$$EMAN_RUNDIR").strip() or "$$EMAN_RUNDIR"
    base = _eman_debug_base_dir(test_lib_dir).replace("\\", "/")
    return f"{base}/eman/eman_regression/$$EMAN_SESSION_NAME/{tc_name}"


def _eman_test_run_dir_expr_for_case(test_lib_dir: str, tc_name: str) -> str:
    """
    每个 test 实例（count 展开后）独立目录。
    末级使用 $$EMAN_TESTCASE（通常包含 seed / flags），可区分 num 的每一次实例。
    """
    return f"{_eman_run_dir_expr_for_case(test_lib_dir, tc_name)}/$$EMAN_TESTCASE"


def gather_eman_case_meta(tc_input_abs: str, args):
    """不编译，仅解析 cfg / DTL 包名，供生成 EMAN build+tests。"""
    proj_root, make_dir, test_lib_dir, case_rel, tc_name, tc_rel_file = parse_case_path(tc_input_abs)
    comp, rtl_elab, test_elab, sim_opt, vip_opt, pre, post, _, _, cov_comp, cov_sim = load_three_layer(
        test_lib_dir, case_rel, tc_rel_file
    )
    comp, rtl_elab, test_elab, sim_opt = _apply_cov_overrides(
        comp, rtl_elab, test_elab, sim_opt, cov_comp, cov_sim, args.cov
    )
    test_pkg, test_dir = _dtl_names(tc_name)
    return {
        "proj_root": proj_root,
        "make_dir": make_dir,
        "test_lib_dir": test_lib_dir,
        "case_rel": case_rel,
        "tc_name": tc_name,
        "tc_abs": os.path.abspath(tc_input_abs),
        "sim_opt": sim_opt,
        "pre": pre,
        "post": post,
        "wave_tcl_path": _resolve_wave_tcl_path(make_dir, test_lib_dir=test_lib_dir, case_rel=case_rel),
        "test_pkg": test_pkg,
        "test_dir": test_dir,
    }


def build_eman_compile_cmd(tc_abs: str, args, run_dir_expr: str) -> str:
    """EMAN build 里执行的命令（run_dir_expr 如 $$EMAN_RUNDIR，勿 shell 提前展开）。"""
    q = shlex.quote
    chunks = ["python3", q(os.path.abspath(__file__)), q(os.path.abspath(tc_abs)), "--compile-only"]
    if getattr(args, "rtl_file", ""):
        chunks += ["--rtl-file", q(args.rtl_file)]
    if args.rtl:
        chunks.append("-rtl")
    if args.cov:
        chunks.append("-cov")
    if args.genlib:
        chunks += ["-genlib", q(args.genlib)]
    if args.lib:
        chunks += ["-lib", q(args.lib)]
    if args.run_suffix:
        chunks += ["-R", q(args.run_suffix)]
    return " ".join(chunks) + " --eman-workdir " + run_dir_expr


def _eman_run_cmd_for_submit(
    sim_opt: str,
    do_dump: bool,
    run_dir_expr: str,
    wave_tcl_path: str = "",
    cov_enable: bool = False,
    pre_sim: str = "",
) -> str:
    """传统三步下的 EMAN 测试 run_cmd（run_dir_expr/simv）。

    pre_sim：cfg/tc 中 +PRE_SIM= 合并结果，在 worker 上于 simv 前执行（shell，与 `&&` 串接）。
    do_dump=True 时与本地 -d 一致（-ucli -do wave.tcl）；-eman 下 debug_run_cmd 固定用 do_dump=True。
    """
    simv_e = f"{run_dir_expr}/simv"
    base_cmd = f"{simv_e} {sim_opt} +UVM_RANDOM_SEED=$$EMAN_RANDOM +ntb_random_seed=$$EMAN_RANDOM -l $$EMAN_LOG_FILE"
    if cov_enable:
        # EMAN merge 依赖稳定可定位的 testdata；这里固定到每个 testcase 目录下。
        base_cmd += f" -cm_name coverage -cm_dir {run_dir_expr}/$$EMAN_TESTCASE/coverage"
    if do_dump:
        if not wave_tcl_path:
            log_error("缺少波形脚本路径：请检查 common/script/wave.tcl")
            sys.exit(1)
        wave_tcl_abs = os.path.abspath(wave_tcl_path)
        if not os.path.exists(wave_tcl_abs):
            log_error(f"未找到波形脚本: {wave_tcl_abs}")
            sys.exit(1)
        base_cmd += f" -ucli -do {shlex.quote(wave_tcl_abs)}"
    pre = (pre_sim or "").strip()
    if pre:
        base_cmd = f"{pre} && {base_cmd}"
    return base_cmd


def _eman_builds_yaml_block(entries: list) -> str:
    """entries: (build_id, run_cmd, nodes, timeout)"""
    if entries:
        nodes = int(entries[0][2])
        timeout = int(entries[0][3])
    else:
        nodes = 1
        timeout = 86400
    # 传统块写法：- options: 下单独一行一键，子键 4 空格与 tests 的 build/run_cmd 对齐。
    lines = [
        "  - options:",
        f"    nodes: {nodes}",
        f"    timeout: {timeout}",
    ]
    for bid, run_cmd, _, _ in entries:
        lines.append(f"  - name: {bid}")
        lines.append(f"    run_cmd: {_yaml_dq(run_cmd)}")
    return "\n".join(lines)


def _eman_tests_yaml_block_with_build(
    items: list, nodes: int = 50, with_debug_rerun: bool = True
) -> str:
    """with_debug_rerun 为 True 时 items 为 6 元组；写出 options.debug_rerun_count、debug_run_cmd、debug_run_dir（debug_run_dir=run_dir+/debug_dir）。为 False 时 5 元组且无 debug 段。"""
    if with_debug_rerun:
        try:
            dr = int((os.environ.get("BMS_EMAN_DEBUG_RERUN_COUNT", "2") or "2").strip() or "2")
        except ValueError:
            dr = 2
        dr = max(0, dr)
        lines = [
            "  - options:",
            f"    debug_rerun_count: {dr}",
            f"    nodes: {int(nodes)}",
        ]
    else:
        lines = [
            "  - options:",
            f"    nodes: {int(nodes)}",
        ]
    for row in items:
        if with_debug_rerun:
            tc_name, build_id, run_cmd, count, run_dir_expr, debug_run_cmd = row
        else:
            tc_name, build_id, run_cmd, count, run_dir_expr = row
            debug_run_cmd = None
        count = max(1, int(count))
        safe_name = tc_name.replace('"', "'")
        lines.append(f"  - name: {safe_name}")
        lines.append(f"    build: {build_id}")
        lines.append(f"    run_dir: {_yaml_dq(run_dir_expr)}")
        lines.append(f"    run_cmd: {_yaml_dq(run_cmd)}")
        if with_debug_rerun and debug_run_cmd is not None:
            lines.append(f"    debug_run_cmd: {_yaml_dq(debug_run_cmd)}")
            lines.append(f"    debug_run_dir: {_yaml_dq(f'{run_dir_expr}/debug_dir')}")
        lines.append(f"    count: {count}")
    return "\n".join(lines)


def _emc_fill_placeholders(
    emc_text: str, builds_yaml: str, tests_yaml: str, count_str: str, emc_top_yaml: str = ""
) -> str:
    """
    仅整行替换占位符。若用 str.replace 全局替换，注释里若写了 __BUILDS_YAML__ 等子串会把大块 YAML
    插入注释行，导致 run_cmd 与 tests 列表粘连等错乱。
    兼容旧模板整行：__BUILDS_YAML__ / __TESTS_YAML__ / __COUNT__。
    emc_top_yaml：env/variables/modes 默认块，替换整行 __BMS_EMC_TOP__（及旧名 __BMS_EMC_MODES_BLOCK__）。
    """
    ends_nl = emc_text.endswith("\n")
    out_lines: list = []
    for line in emc_text.splitlines():
        s = line.strip()
        if s in ("__BMS_EMC_BUILDS__", "__BUILDS_YAML__"):
            out_lines.extend(builds_yaml.splitlines())
        elif s in ("__BMS_EMC_TESTS__", "__TESTS_YAML__"):
            out_lines.extend(tests_yaml.splitlines())
        elif s in ("__BMS_EMC_TOP__", "__BMS_EMC_MODES_BLOCK__", "__BMS_EMC_MODES__"):
            if (emc_top_yaml or "").strip():
                out_lines.extend((emc_top_yaml or "").rstrip().splitlines())
        elif s in ("__BMS_EMC_COUNT__", "__COUNT__"):
            out_lines.append(count_str)
        elif "__COUNT__" in line and not line.lstrip().startswith("#"):
            out_lines.append(line.replace("__COUNT__", count_str))
        else:
            out_lines.append(line)
    text = "\n".join(out_lines)
    if ends_nl:
        text += "\n"
    return text


def _emc_template_line_markers(emc_text: str):
    """返回模板中作为独立一行出现的占位符集合（strip 后）。"""
    return {ln.strip() for ln in emc_text.splitlines()}


def run_eman_existing(
    emc_path: str,
    make_dir: str = "",
    cov_enable: bool = False,
    session_name_override: str = "",
):
    """直接对已存在的 .emc 执行 eman（不经过 bms 编译）。不传 -session_name，由 EMAN 自命名。"""
    emc_abs = os.path.abspath(emc_path)
    if not os.path.isfile(emc_abs):
        log_error(f"EMC 文件不存在: {emc_abs}")
        sys.exit(1)
    emc_dir = os.path.dirname(emc_abs)
    md = (
        (make_dir or "").strip()
        or os.environ.get("BMS_EMAN_MAKE_DIR", "").strip()
        or _guess_make_dir_from_emc_path(emc_abs)
    )
    cmd = build_eman_command_line(
        emc_abs,
        md,
        cov_enable=cov_enable,
        session_name_override=session_name_override,
    )
    log_step("回归（已有 EMC）")
    log_info(f"EMAN命令: {cmd}")
    cwd_before = os.getcwd()
    os.chdir(emc_dir)
    try:
        run_cmd(cmd, "eman 回归(已有emc)")
    finally:
        os.chdir(cwd_before)
    log_info("EMAN完成，可用 `eman -get_web_url` 查看Web地址，或查看 EMAN 工作目录下 eman_logs/*.summary.txt")


def run_with_eman_dtl(
    pre: str,
    post: str,
    emc_template_path: str,
    debug_dir: str,
    emc_filename: str,
    *,
    builds_yaml: str,
    tests_yaml: str,
    template_count: int = 1,
    eman_make_dir: str = "",
    test_lib_dir: str = "",
    case_rel: str = "",
    cov_enable: bool = False,
    session_name_override: str = "",
    emc_top_yaml: str = "",
):
    """
    Server EMAN：模板在 build:/tests: 下各一行占位符 __BMS_EMC_BUILDS__ / __BMS_EMC_TESTS__
    （或兼容旧名整行 __BUILDS_YAML__ / __TESTS_YAML__）；勿在注释中写这些字符串。
    emc_top_yaml：在 __BMS_EMC_TOP__ 行展开 env/variables/modes，供手动 rerun 选 fsdb / cov（由 bms 默认生成）。
    """
    count0 = max(1, int(template_count))
    if not emc_template_path or (not os.path.isfile(emc_template_path)):
        log_error(f"EMAN模板不存在: {emc_template_path}")
        sys.exit(1)
    if not debug_dir:
        log_error("EMAN运行目录为空（debug_dir）")
        sys.exit(1)
    if not emc_filename:
        log_error("EMAN 输出文件名未指定")
        sys.exit(1)

    with open(emc_template_path, "r", encoding="utf-8", errors="ignore") as f:
        emc_text = f.read()

    markers = _emc_template_line_markers(emc_text)
    build_ok = ("__BMS_EMC_BUILDS__" in markers) or ("__BUILDS_YAML__" in markers)
    test_ok = ("__BMS_EMC_TESTS__" in markers) or ("__TESTS_YAML__" in markers)
    if not build_ok:
        log_error(
            "EMAN 模板须在 build: 段下有一整行占位符 __BMS_EMC_BUILDS__（或旧名 __BUILDS_YAML__）"
        )
        sys.exit(1)
    if not test_ok:
        log_error(
            "EMAN 模板须在 tests: 段下有一整行占位符 __BMS_EMC_TESTS__（或旧名 __TESTS_YAML__）"
        )
        sys.exit(1)
    if (emc_top_yaml or "").strip() and ("__BMS_EMC_TOP__" not in emc_text) and (
        "__BMS_EMC_MODES_BLOCK__" not in emc_text
    ) and ("__BMS_EMC_MODES__" not in emc_text):
        log_info(
            "本仓库默认模板在 builds: 前应有整行 __BMS_EMC_TOP__，否则 env/variables/modes 不会写入生成的 .emc"
        )
    emc_text = _emc_fill_placeholders(
        emc_text, builds_yaml, tests_yaml, str(count0), emc_top_yaml=emc_top_yaml
    )

    os.makedirs(debug_dir, exist_ok=True)
    emc_file = os.path.join(debug_dir, emc_filename)
    with open(emc_file, "w", encoding="utf-8") as f:
        f.write(emc_text)

    md = (eman_make_dir or "").strip()
    if not md and emc_template_path:
        tdir = os.path.dirname(os.path.abspath(emc_template_path))
        if os.path.basename(tdir) == "regr":
            md = os.path.join(os.path.dirname(tdir), "vcs_com")
        elif os.path.basename(tdir) == "vcs_com":
            md = tdir
    cmd = build_eman_command_line(
        emc_file,
        md,
        test_lib_dir=test_lib_dir,
        case_rel=case_rel,
        cov_enable=cov_enable,
        session_name_override=session_name_override,
        top_run_dir_override=os.path.join(
            os.path.dirname(debug_dir), "eman_rundir", f"eman_rundir_{time.strftime('%Y%m%d_%H%M%S')}"
        ),
    )
    # pre_sim 已写入 .emc 中各 test 的 run_cmd（在 EMAN worker 上 simv 前执行），此处不再在提交机重复执行 pre。
    log_step("开始回归（EMAN）")
    log_info(f"已生成: {emc_file}")
    log_info(f"EMAN命令: {cmd}")
    cwd_before = os.getcwd()
    os.chdir(debug_dir)
    try:
        run_cmd(cmd, "eman 回归")
    finally:
        os.chdir(cwd_before)
    if post:
        run_cmd(post, "post_sim")
    log_info(
        "EMAN完成，可用 `eman -get_web_url` 查看Web地址，或查看 "
        "<debug_base>/eman/eman_regression/eman_rundir/eman_rundir_时间戳/eman_logs/*.summary.txt"
    )


def run_dtl_compile_phase(tc_input_abs: str, args, per_case_isolated: bool = False, forced_work_dir: str = ""):
    """
    单 case 的 DTL 编译阶段（至 compile_test_dtl），供仿真或 EMAN 复用。
    per_case_isolated: 为 True 时忽略 -lib/-genlib，始终在各自 run_dir 下完整编译（多 case -eman 用）。
    forced_work_dir: 非空时在此目录编译（EMAN build 节点上由 --eman-workdir 传入已展开路径）。
    返回 meta：tc_name, run_dir, simv_path, test_pkg, test_dir, sim_opt, pre, post, make_dir, test_lib_dir, ...
    """
    proj_root, make_dir, test_lib_dir, case_rel, tc_name, tc_rel_file = parse_case_path(tc_input_abs)
    vlog_opt, rtl_elab_opt, test_elab_opt = load_vcs_com(make_dir)
    RTL_FILE = _resolve_rtl_file_arg(args)
    fw = (forced_work_dir or "").strip() or (getattr(args, "eman_workdir", None) or "").strip()
    if fw:
        _, run_dir = init_run_dir_at(fw)
    else:
        _, run_dir = init_run_dir(test_lib_dir, case_rel, tc_name, args.run_suffix)
    comp, rtl_elab, test_elab, sim_opt, vip_opt, pre, post, rtl_file_cfg, verif_file_cfg, cov_comp, cov_sim = load_three_layer(
        test_lib_dir, case_rel, tc_rel_file
    )
    comp, rtl_elab, test_elab, sim_opt = _apply_cov_overrides(
        comp, rtl_elab, test_elab, sim_opt, cov_comp, cov_sim, args.cov
    )
    if (not getattr(args, "rtl_file", "").strip()) and rtl_file_cfg:
        RTL_FILE = rtl_file_cfg
    final_rtl_elab = f"{rtl_elab_opt} {rtl_elab}".strip()
    final_test_elab = f"{test_elab_opt} {test_elab}".strip()
    dtl_shared_opt = _dtl_sharedlib_opt_from_base(final_rtl_elab)
    if final_test_elab and final_test_elab != final_rtl_elab:
        log_info("DTL提示: 为避免 DTL-SHLIB-ERR，sharedlib 编译复用 base elab 选项（去掉 -top）")

    lib_mode_name = None if per_case_isolated else (args.genlib or args.lib)
    lib_mode_dir = ""
    if lib_mode_name:
        lib_mode_dir = debug_peer_dir(test_lib_dir, lib_mode_name)
        if args.genlib:
            if os.path.isdir(lib_mode_dir):
                log_info(f"-genlib 检测到同名目录，先删除重建: {lib_mode_dir}")
                shutil.rmtree(lib_mode_dir, ignore_errors=True)
            os.makedirs(lib_mode_dir, exist_ok=True)
        elif not os.path.isdir(lib_mode_dir):
            log_error(f"找不到可复用编译库目录: {lib_mode_dir}")
            sys.exit(1)

    base_work_dir = lib_mode_dir if lib_mode_dir else run_dir
    simv_path = os.path.abspath(os.path.join(base_work_dir, "simv"))
    sharedlib_path = os.path.join(base_work_dir, BMS_DTL_BASE_DIR)

    cwd_before = os.getcwd()
    os.chdir(base_work_dir)
    try:
        if args.lib and (not args.rtl):
            if not (os.path.exists("simv") and os.path.exists(BMS_DTL_BASE_DIR)):
                log_error(f"-lib 模式下缺少已编译产物（simv/BASE_IP）: {base_work_dir}")
                sys.exit(1)
            log_info(f"复用编译库: {base_work_dir}")
        else:
            if args.genlib:
                log_info(f"生成编译库: {base_work_dir}")
            compile_uvm(vlog_opt)
            compile_vip(make_dir, vlog_opt, comp, vip_opt, force_rebuild=args.rtl)
            compile_verif_once(make_dir, vlog_opt, comp, vip_opt, skip_vip_rebuild=(not args.rtl))
            compile_base_dtl(make_dir, vlog_opt, final_rtl_elab, comp, RTL_FILE, force_rtl=args.rtl)
    finally:
        os.chdir(cwd_before)

    compile_test_units_dtl(make_dir, vlog_opt, comp)
    test_pkg, test_dir = compile_test_dtl(dtl_shared_opt, tc_name, sharedlib_path)

    return {
        "proj_root": proj_root,
        "make_dir": make_dir,
        "test_lib_dir": test_lib_dir,
        "tc_name": tc_name,
        "run_dir": run_dir,
        "simv_path": simv_path,
        "test_pkg": test_pkg,
        "test_dir": test_dir,
        "sim_opt": sim_opt,
        "pre": pre,
        "post": post,
        "vlog_opt": vlog_opt,
        "final_rtl_elab": final_rtl_elab,
    }


def run_traditional_compile_phase(tc_input_abs: str, args, forced_work_dir: str = ""):
    """单 case 传统三步编译阶段（用于本地执行和 EMAN build 节点 compile-only）。"""
    proj_root, make_dir, test_lib_dir, case_rel, tc_name, tc_rel_file = parse_case_path(tc_input_abs)
    vlog_opt, rtl_elab_opt, test_elab_opt = load_vcs_com(make_dir)
    rtl_file = _resolve_rtl_file_arg(args)

    fw = (forced_work_dir or "").strip() or (getattr(args, "eman_workdir", None) or "").strip()
    if fw:
        _, run_dir = init_run_dir_at(fw)
    else:
        _, run_dir = init_run_dir(test_lib_dir, case_rel, tc_name, args.run_suffix)


    comp, rtl_elab, test_elab, sim_opt, vip_opt, pre, post, rtl_file_cfg, verif_file_cfg, cov_comp, cov_sim = load_three_layer(
        test_lib_dir, case_rel, tc_rel_file
    )
    comp, rtl_elab, test_elab, sim_opt = _apply_cov_overrides(
        comp, rtl_elab, test_elab, sim_opt, cov_comp, cov_sim, args.cov
    )
    if (not getattr(args, "rtl_file", "").strip()) and rtl_file_cfg:
        rtl_file = rtl_file_cfg
    final_rtl_elab = f"{rtl_elab_opt} {rtl_elab}".strip()
    final_test_elab = f"{test_elab_opt} {test_elab}".strip()

    cwd_before = os.getcwd()
    os.chdir(run_dir)
    try:
        compile_uvm(vlog_opt)
        compile_vip(make_dir, vlog_opt, comp, vip_opt, force_rebuild=args.rtl)
        compile_design(make_dir, vlog_opt, final_rtl_elab, comp, rtl_file, force_rebuild=args.rtl)
        compile_test(
            make_dir,
            vlog_opt,
            final_test_elab,
            comp,
            vip_opt,
            force_vip_rebuild=args.rtl,
            verif_file=verif_file_cfg,
        )
    finally:
        os.chdir(cwd_before)

    return {
        "proj_root": proj_root,
        "make_dir": make_dir,
        "test_lib_dir": test_lib_dir,
        "tc_name": tc_name,
        "run_dir": run_dir,
        "simv_path": os.path.abspath(os.path.join(run_dir, "simv")),
        "sim_opt": sim_opt,
        "pre": pre,
        "post": post,
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "tc",
        nargs="*",
        help="用例路径（含 test_lib，不带 .tc）；-eman 下也支持目录（递归收集目录内全部 .tc）",
    )
    parser.add_argument("--rtl-file", default="", help="指定 RTL filelist（相对 vcs_com 或绝对路径）")
    parser.add_argument("-rtl", action="store_true", help="强制重编 RTL/VIP（EMAN/compile-only 保持该语义）")
    parser.add_argument("-f", "-fast", dest="fast", action="store_true", help="快速模式：复用已编译 RTL/VIP（仅非-eman）")
    parser.add_argument("-c", action="store_true", help="非-eman：先清理目标仿真目录再运行")
    parser.add_argument("-genlib", help="生成可复用编译库（目录名，位于case同级）")
    parser.add_argument("-lib", help="复用已存在编译库（目录名，位于case同级）")
    parser.add_argument("-d", "-dump", action="store_true", help="开启波形")
    parser.add_argument("-cov", action="store_true", help="覆盖率模式：-eman -cov 才进行EMAN merge；-cov单跑时为单case覆盖率仿真")
    parser.add_argument("-R", "--run-suffix", default="", help="运行目录后缀")
    parser.add_argument("-q", "--queue", default=DEFAULT_QUEUE, help="LSF队列名（非-eman默认提交）")
    parser.add_argument("-j", type=int, default=None, help="EMAN（非--emc直跑）build/test 的统一 nodes，默认50")
    parser.add_argument("--ncore", type=int, default=DEFAULT_NCORE, help="LSF申请核数（默认1）")
    parser.add_argument("-m", "--mem", type=int, default=None, help="LSF申请内存（单位GB，例如 -m 30）")
    parser.add_argument("-local", action="store_true", help="本地运行（不提交LSF）")
    parser.add_argument(
        "-eman",
        action="store_true",
        help="提交 EMAN 回归（支持目录/多 case 展开并在服务器侧执行）",
    )
    parser.add_argument(
        "-debug",
        action="store_true",
        help="仅与 -eman 同用：生成 .emc 时写入自动 debug 重跑（options.debug_rerun_count、debug_run_cmd、debug_run_dir）。"
        "不向 eman 命令行自动加 -debug；需要时设 BMS_EMAN_REGR_DEBUG=1 或 BMS_EMAN_REGR_DEBUG_FLAGS。",
    )
    parser.add_argument(
        "-num",
        type=str,
        default="1",
        help="EMAN 各测试 count：单值对所有用例相同；多例可写逗号分隔与路径顺序对齐，如 -num 10,20",
    )
    parser.add_argument("-s", "--seed", help="随机种子")
    parser.add_argument(
        "--emc",
        "-emc",
        dest="emc_path",
        default="",
        help="已有 .emc：直接执行 server 侧 eman",
    )
    parser.add_argument("--compile-only", action="store_true", help=argparse.SUPPRESS)
    parser.add_argument(
        "--eman-workdir",
        default="",
        help=argparse.SUPPRESS,
    )
    parser.add_argument(
        "--eman-make-dir",
        default="",
        help="vcs_com 目录绝对路径；与 --emc 连用时可指向工程内 vcs_com，便于 -error_pattern_file 与默认 -config（vcs_com 父目录名）",
    )
    args = parser.parse_args()
    raw_tc_args = list(args.tc)

    # 兼容入口：bms -eman xxx.emc
    # 规则：当未显式传 --emc，且 -eman 下仅有一个位置参数且为 .emc 文件时，
    # 将其视作已有 emc 直跑模式（等价于 --emc xxx.emc -eman）。
    if (not args.emc_path.strip()) and args.eman and len(args.tc) == 1:
        tc0 = args.tc[0].strip()
        if tc0.lower().endswith(".emc"):
            args.emc_path = tc0
            args.tc = []

    if (not args.eman) and args.fast and args.rtl:
        log_error("非-eman 模式下 -f/-fast 与 -rtl 语义冲突，请二选一")
        sys.exit(1)

    if args.debug and (not args.eman):
        log_error("-debug 仅在与 -eman 同用时有效（由 bms 生成/提交 EMAN 流程）")
        sys.exit(1)
    if args.emc_path.strip():
        run_eman_existing(
            args.emc_path.strip(),
            args.eman_make_dir,
            cov_enable=args.cov,
        )
        sys.exit(0)

    if len(args.tc) == 1 and args.tc[0] == "clean":
        for f in CLEAN_FILES:
            os.system(f"rm -rf {f}")
        log_info("清理完成")
        sys.exit(0)

    if not args.tc:
        print(
            "bms 用法：\n"
            "  单例：bms 用例路径 .../test_lib/.../name [--rtl-file xxx.f] [-f|-fast] [-d] [-R 后缀] "
            "[-q 队列] [--ncore N] [-m GB] [-local] [-cov] [-s 种子]\n"
            "  EMAN：bms -eman 用例路径/目录（支持目录展开、多 case、服务器侧提交）\n"
            "  直跑EMC：bms -eman xxx.emc（等价于 --emc xxx.emc）；-debug 仅影响 bms 生成的 .emc 中 debug 重跑段\n"
            "  说明：非 -eman 走传统三步法（compile RTL/VIP -> compile TB -> run）\n"
            "       非-eman 默认强制重编；-f/-fast 表示复用已编译结果（旧默认行为）"
        )
        sys.exit(1)

    if len(args.tc) > 1 and (not args.eman):
        log_error("多个用例路径仅支持与 -eman 同时使用（单例仿真请每次传一个路径）")
        sys.exit(1)

    if args.j is not None and args.j <= 0:
        log_error("-j 必须为正整数")
        sys.exit(1)

    if args.genlib and args.lib:
        log_error("-genlib 与 -lib 不能同时使用")
        sys.exit(1)

    # 覆盖率单跑模式：不带 -eman 时仅支持单 case
    if args.cov and (not args.eman) and len(args.tc) != 1:
        log_error("-cov（非-eman）仅支持单个用例路径")
        sys.exit(1)

    tc_paths_abs = [os.path.abspath(p) for p in args.tc]
    folder_expand_mode = False
    if args.eman:
        tc_paths_abs, folder_expand_mode = expand_eman_targets(tc_paths_abs)
    # -eman 时在下文根据 build 名 + 用户 + 时间戳 设置 eman_session_name 并传 -session_name
    eman_session_name = ""
    multi_eman = len(tc_paths_abs) > 1 and args.eman
    if multi_eman and (args.lib or args.genlib):
        log_error("多 case 与 -eman 组合时，每个用例必须单独编译；请勿使用 -lib / -genlib（否则会共用编译目录）")
        sys.exit(1)
    orig_main = os.getcwd()

    # 默认提交服务器；显式 -local 才本地跑
    if (not args.local) and (not args.eman) and (not args.compile_only):
        if len(tc_paths_abs) != 1:
            log_error("非-eman模式提交LSF仅支持单用例路径")
            sys.exit(1)
        _, _, _, _, tc_name_for_job, _ = parse_case_path(tc_paths_abs[0])
        node_cmd = _build_python_local_cmd(args, tc_paths_abs)
        submit_lsf(f"bms_{tc_name_for_job}", node_cmd, args.queue, args.ncore, args.mem)

    if args.compile_only:
        if len(tc_paths_abs) != 1:
            log_error("--compile-only 仅支持单个用例路径")
            sys.exit(1)
        run_traditional_compile_phase(tc_paths_abs[0], args, forced_work_dir=args.eman_workdir)
        log_info("compile-only 完成")
        os.chdir(orig_main)
        sys.exit(0)

    # 非 -eman 走传统三步；-eman 走 EMAN 提交流程（支持目录/多 case 展开）
    use_eman = bool(args.eman)

    if use_eman:
        if args.c:
            log_error("-c 仅支持非-eman 流程")
            sys.exit(1)
        first_make = None
        metas_light = []
        for tc_abs in tc_paths_abs:
            _, md, _, _, _, _ = parse_case_path(tc_abs)
            if first_make is None:
                first_make = md
            elif md != first_make:
                log_error("多 case EMAN 要求同属同一工程（vcs_com 目录一致）")
                sys.exit(1)
            metas_light.append(gather_eman_case_meta(tc_abs, args))

        eman_counts = parse_eman_counts(args.num, len(metas_light), force_single=folder_expand_mode)
        emc_template_path = _resolve_eman_template_path(first_make)
        if not emc_template_path:
            log_error(
                "未找到 EMAN 模板：请在工程根下 regr/eman_template.emc 或 vcs_com/eman_template.emc 放置模板，"
                "或与 bms.py 同目录提供默认模板，或设置 BMS_EMAN_TEMPLATE"
            )
            sys.exit(1)
        nodes = int(args.j) if (args.j is not None) else 50
        timeout = int(os.environ.get("BMS_EMAN_BUILD_TIMEOUT", "86400").strip() or "86400")
        build_entries = []
        test_items = []
        tlib0 = metas_light[0]["test_lib_dir"]
        eman_dbg = bool(args.debug)
        for meta, cnt in zip(metas_light, eman_counts):
            bid = f"build_{_eman_safe_id(meta['tc_name'])}"
            rd_expr = _eman_run_dir_expr_for_case(tlib0, meta["tc_name"])
            bc = build_eman_compile_cmd(meta["tc_abs"], args, rd_expr)
            build_entries.append((bid, bc, nodes, timeout))
            sim_cmd = _eman_run_cmd_for_submit(
                meta["sim_opt"],
                args.d,
                rd_expr,
                wave_tcl_path=meta.get("wave_tcl_path", ""),
                cov_enable=args.cov,
                pre_sim=meta.get("pre") or "",
            )
            _pre_m = (meta.get("pre") or "").strip()
            if _pre_m:
                log_info(
                    f"  -eman [{meta['tc_name']}] pre_sim 已并入 EMAN 该 test 的 run_cmd 前缀 "
                    f"（{len(_pre_m)} 字符，worker 上先于 simv 执行；与 simv 之间为 &&）"
                )
            test_run_dir_expr = _eman_test_run_dir_expr_for_case(tlib0, meta["tc_name"])
            if eman_dbg:
                # 仅 bms -eman -debug：写 debug_run_cmd、debug_run_dir、options.debug_rerun_count
                debug_run_cmd = _eman_run_cmd_for_submit(
                    meta["sim_opt"],
                    True,
                    rd_expr,
                    wave_tcl_path=meta.get("wave_tcl_path", ""),
                    cov_enable=args.cov,
                    pre_sim=meta.get("pre") or "",
                )
                test_items.append((meta["tc_name"], bid, sim_cmd, cnt, test_run_dir_expr, debug_run_cmd))
            else:
                test_items.append((meta["tc_name"], bid, sim_cmd, cnt, test_run_dir_expr))

        builds_yaml = _eman_builds_yaml_block(build_entries)
        tests_yaml = _eman_tests_yaml_block_with_build(
            test_items, nodes=nodes, with_debug_rerun=eman_dbg
        )
        if eman_dbg:
            log_info(
                "-eman -debug：.emc 已写 options.debug_rerun_count、每 test 的 debug_run_cmd / debug_run_dir（等同 -d）；"
                "失败时供 ExecMan 自动 debug 重跑。eman 是否加 -debug 仅由 BMS_EMAN_REGR_DEBUG / BMS_EMAN_REGR_DEBUG_FLAGS 决定"
            )

        debug_dir = _eman_generated_emc_dir(metas_light[0]["test_lib_dir"])
        ts = time.strftime("%Y%m%d_%H%M%S")
        eman_session_name = _format_eman_session_name(metas_light, ts)
        log_info(f"-eman -session_name: {eman_session_name}")
        emc_fn = (
            f"{metas_light[0]['tc_name']}_{ts}.emc"
            if len(metas_light) == 1
            else f"bms_eman_{len(metas_light)}cases_{ts}.emc"
        )
        pre0 = metas_light[0]["pre"]
        post0 = metas_light[0]["post"]
        if len(metas_light) > 1:
            for m in metas_light[1:]:
                if m["pre"] != pre0 or m["post"] != post0:
                    log_info("多 case EMAN：pre_sim/post_sim 使用第一个 case 的 cfg；其余若不同请编辑生成的 emc")
                    break
        _rd0 = _eman_run_dir_expr_for_case(tlib0, metas_light[0]["tc_name"])
        log_info(
            "-eman：不在本机编译；已生成 build.run_cmd（EMAN 调度编译）。"
            f"工作目录表达式（首 case 示例）: {_rd0!r}"
            + (
                "；已设 BMS_EMAN_RUNDIR_EXPR 时全 case 共用该表达式"
                if "BMS_EMAN_RUNDIR_EXPR" in os.environ
                else "；未设 BMS_EMAN_RUNDIR_EXPR 时为 per-case 的 …/$$EMAN_SESSION_NAME/<tc_name>"
            )
        )
        if len(metas_light) > 1:
            for meta, c in zip(metas_light, eman_counts):
                _bid = f"build_{_eman_safe_id(meta['tc_name'])}"
                log_info(f"  [{meta['tc_name']}] build={_bid} count={c}")
        emc_top_yaml = _eman_emc_top_block(
            metas_light[0].get("wave_tcl_path", ""),
            _eman_run_dir_expr_for_case(tlib0, metas_light[0]["tc_name"]),
        )
        if len(metas_light) > 1:
            log_info("EMAN 头块（env/variables/modes）按首 case 的 wave 与 run_dir 生成；多 case 手动 rerun 时可编辑 .emc")
        run_with_eman_dtl(
            pre0,
            post0,
            emc_template_path,
            debug_dir,
            emc_fn,
            builds_yaml=builds_yaml,
            tests_yaml=tests_yaml,
            template_count=eman_counts[0],
            eman_make_dir=first_make,
            test_lib_dir=tlib0,
            case_rel=metas_light[0].get("case_rel", ""),
            cov_enable=args.cov,
            session_name_override=eman_session_name,
            emc_top_yaml=emc_top_yaml,
        )
    else:
        if len(tc_paths_abs) != 1:
            log_error("非 EMAN 模式仅支持单用例")
            sys.exit(1)
        # 非-eman：默认强制重编；仅 -f/-fast 走快速复用模式（旧默认行为）。
        force_rtl_rebuild = (not args.fast)
        tc_input_abs = tc_paths_abs[0]
        proj_root, make_dir, test_lib_dir, case_rel, tc_name, tc_rel_file = parse_case_path(tc_input_abs)
        vlog_opt, rtl_elab_opt, test_elab_opt = load_vcs_com(make_dir)
        RTL_FILE = _resolve_rtl_file_arg(args)
        lib_mode_name = args.genlib or args.lib
        if lib_mode_name:
            lib_dir = debug_peer_dir(test_lib_dir, lib_mode_name)
            if args.c:
                _clean_target_run_dir(lib_dir)
            if args.lib and (not os.path.isdir(lib_dir)):
                log_error(f"找不到可复用编译库目录: {lib_dir}")
                sys.exit(1)
            os.makedirs(lib_dir, exist_ok=True)
            _, run_dir = init_run_dir_at(lib_dir)
        else:
            if args.c:
                debug_base = _ensure_testlib_debug_link(test_lib_dir)
                target_name = f"{tc_name}_{args.run_suffix}" if args.run_suffix else tc_name
                _clean_target_run_dir(os.path.join(debug_base, target_name))
            _, run_dir = init_run_dir(test_lib_dir, case_rel, tc_name, args.run_suffix)
        comp, rtl_elab, test_elab, sim_opt, vip_opt, pre, post, rtl_file_cfg, verif_file_cfg, cov_comp, cov_sim = load_three_layer(
            test_lib_dir, case_rel, tc_rel_file
        )
        comp, rtl_elab, test_elab, sim_opt = _apply_cov_overrides(
            comp, rtl_elab, test_elab, sim_opt, cov_comp, cov_sim, args.cov
        )
        if (not getattr(args, "rtl_file", "").strip()) and rtl_file_cfg:
            RTL_FILE = rtl_file_cfg
        final_rtl_elab = f"{rtl_elab_opt} {rtl_elab}".strip()
        final_test_elab = f"{test_elab_opt} {test_elab}".strip()
        wave_tcl_path = _resolve_wave_tcl_path(make_dir, test_lib_dir=test_lib_dir, case_rel=case_rel)
        lib_manifest = _build_lib_manifest(
            make_dir, vlog_opt, final_rtl_elab, final_test_elab, comp, vip_opt, RTL_FILE, verif_file_cfg
        )
        skip_compile_for_lib = False
        if args.lib:
            if force_rtl_rebuild:
                log_info("[LIB] 非-eman默认强制重编：在复用库目录内重编并刷新 manifest")
            else:
                saved_manifest = _load_lib_manifest(run_dir)
                if not saved_manifest:
                    log_error(f"-lib 目录缺少 manifest: {os.path.join(run_dir, LIB_MANIFEST_FILE)}")
                    sys.exit(1)
                if saved_manifest.get("build_signature") != lib_manifest.get("build_signature"):
                    log_error("-lib 命中失败：编译上下文不一致，请改用 -genlib 重新生成")
                    log_info(f"当前签名: {lib_manifest.get('build_signature')}")
                    log_info(f"库内签名: {saved_manifest.get('build_signature')}")
                    sys.exit(1)
                if not os.path.exists(os.path.join(run_dir, "simv")):
                    log_error(f"-lib 目录缺少 simv: {os.path.join(run_dir, 'simv')}")
                    sys.exit(1)
                skip_compile_for_lib = True
                log_info("[LIB] reuse hit: 跳过 UVM/VIP/RTL/TB 编译")

        if not skip_compile_for_lib:
            compile_uvm(vlog_opt)
            compile_vip(make_dir, vlog_opt, comp, vip_opt, force_rebuild=force_rtl_rebuild)
            compile_design(make_dir, vlog_opt, final_rtl_elab, comp, RTL_FILE, force_rebuild=force_rtl_rebuild)
            compile_test(
                make_dir,
                vlog_opt,
                final_test_elab,
                comp,
                vip_opt,
                force_vip_rebuild=force_rtl_rebuild,
                verif_file=verif_file_cfg,
            )
            if args.genlib or args.lib:
                _save_lib_manifest(run_dir, lib_manifest)
                log_info(f"[LIB] 已更新编译库: {run_dir}")
        run_and_check(
            tc_name,
            sim_opt,
            pre,
            post,
            args.seed,
            args.d,
            wave_tcl_path=wave_tcl_path,
            no_rtl_update_notice=(not force_rtl_rebuild),
            make_dir=make_dir,
            test_lib_dir=test_lib_dir,
            case_rel=case_rel,
        )

    os.chdir(orig_main)
