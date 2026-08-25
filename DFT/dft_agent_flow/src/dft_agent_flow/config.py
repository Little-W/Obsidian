from __future__ import annotations

from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[2]
VAULT_ROOT = PROJECT_ROOT.parent
FAN_ROOT = VAULT_ROOT / "开源实验资源" / "FAN_ATPG"
FAN_BINARY = FAN_ROOT / "bin" / "opt" / "fan"
ARTIFACTS_ROOT = PROJECT_ROOT / "artifacts"
RUNS_ROOT = ARTIFACTS_ROOT / "runs"
EPISODES_ROOT = ARTIFACTS_ROOT / "episodes"
AUDIT_LOG = ARTIFACTS_ROOT / "audit.jsonl"
FEEDBACK_LOG = PROJECT_ROOT / "data" / "feedback.jsonl"
EVALS_FILE = PROJECT_ROOT / "data" / "evals" / "agent_tasks.jsonl"
SYSTEM_PROMPT_FILE = PROJECT_ROOT / "instructions" / "SYSTEM_PROMPT.md"
DFTC_PROMPT_FILE = PROJECT_ROOT / "instructions" / "DFTC_LAB_AGENT.md"
AGENT_RUNTIME_POLICY_FILE = PROJECT_ROOT / "instructions" / "AGENT_RUNTIME_POLICY.md"
DFTC_MANIFEST_FILE = PROJECT_ROOT / "data" / "dftc_labs.json"
EXTERNAL_PROJECT_MANIFEST_FILE = PROJECT_ROOT / "data" / "external_dft_projects.json"
EXTERNAL_SOURCES_ROOT = PROJECT_ROOT / "external_sources"
OLLAMA_MODELS_ROOT = PROJECT_ROOT / ".ollama_models"

# The official course tree and the modern-tool execution copy are evidence sources.
# The agent may inspect them but never writes to either location.
DFTC_ORIGINAL_ROOT = Path("/media/6/Projects/DFTC1_2010.03-ori")
DFTC_RUNTIME_ROOT = Path("/media/6/Projects/DFTC1_2010.03-lab-runtime")
# DFTC runs must happen outside the evidence trees. This location is visible to
# the host and to the AlmaLinux container entered by /usr/local/bin/dc_shell.
DFTC_WORKSPACES_ROOT = Path("/media/6/Projects/DFTC1_agent_workspaces")
# External RTL is copied from a commit-pinned source catalogue into this
# disposable location.  It is deliberately separate from course-lab evidence.
EXTERNAL_DFT_WORKSPACES_ROOT = Path("/media/6/Projects/DFT_agent_external_workspaces")
DFTC_SHELL = Path("/usr/local/bin/dc_shell")
DFTC_REFERENCE_LIBRARY_DIR = DFTC_ORIGINAL_ROOT / "ref" / "db"

OLLAMA_API_BASE = "http://127.0.0.1:11434"
DEFAULT_MODEL = "qwen3:4b-instruct"
DEFAULT_NUM_CTX = 32768

# These profiles are taken from the verified FAN_ATPG example scripts.
PROFILES = {
    "none": {"static_compression": False, "dynamic_compression": False},
    "static": {"static_compression": True, "dynamic_compression": False},
    "static_dynamic": {"static_compression": True, "dynamic_compression": True},
}


def available_circuits() -> tuple[str, ...]:
    netlist_dir = FAN_ROOT / "mod_netlist"
    return tuple(sorted(path.stem for path in netlist_dir.glob("*.v") if path.stem))
