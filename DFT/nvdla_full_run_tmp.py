import json
from pathlib import Path

from dft_agent_flow.agent_runtime import DftAgentRuntime


projects = json.loads(Path("data/projects.json").read_text())["projects"]
project = next(item for item in projects if item.get("id") == "nvdla_hw_smic40")


def emit(event):
    if not isinstance(event, dict):
        return
    phase = str(event.get("phase", event.get("event", "")))
    if phase in {"tool_output", "output"}:
        return
    print(json.dumps(event, ensure_ascii=False, default=str), flush=True)


api = DftAgentRuntime._tool_api(
    project,
    emit,
    status_callback=emit,
    async_eda_jobs=False,
)
result = None
error = None
try:
    result = api.request_and_execute("run_dft_optimization", {"maximum_rounds": 8})
except BaseException as exc:
    error = repr(exc)
finally:
    api.close()
Path("/tmp/nvdla_full_run_20260921.json").write_text(
    json.dumps({"result": result, "error": error}, ensure_ascii=False, indent=2, default=str)
)
