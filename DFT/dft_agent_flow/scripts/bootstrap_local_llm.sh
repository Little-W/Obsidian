#!/usr/bin/env bash
set -euo pipefail

script_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
project_root=$(cd -- "$script_dir/.." && pwd)
ollama_bin="${OLLAMA_BIN:-ollama}"
conda_env="${CONDA_ENV:-tf_2_18}"

if ! command -v "$ollama_bin" >/dev/null 2>&1; then
  printf '%s\n' "Ollama was not found. Set OLLAMA_BIN to its executable path."
  exit 2
fi

conda run -n "$conda_env" python -m pip install -e "$project_root"
mkdir -p "$project_root/artifacts/logs"
if ! curl --silent --fail http://127.0.0.1:11434/api/tags >/dev/null 2>&1; then
  nohup "$script_dir/start_ollama.sh" >"$project_root/artifacts/logs/ollama.log" 2>&1 &
  for _ in $(seq 1 30); do
    curl --silent --fail http://127.0.0.1:11434/api/tags >/dev/null 2>&1 && break
    sleep 1
  done
fi

export OLLAMA_MODELS="$project_root/.ollama_models"
"$ollama_bin" pull qwen3:4b-instruct
"$ollama_bin" list
