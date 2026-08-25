#!/usr/bin/env bash
set -euo pipefail

script_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
project_root=$(cd -- "$script_dir/.." && pwd)
mkdir -p "$project_root/.ollama_models"

export OLLAMA_MODELS="$project_root/.ollama_models"
export OLLAMA_NUM_PARALLEL="1"
export OLLAMA_KEEP_ALIVE="15m"
# Keep enough tool evidence in context for the two-round DFTC verification flow.
export OLLAMA_CONTEXT_LENGTH="${OLLAMA_CONTEXT_LENGTH:-32768}"
exec "${OLLAMA_BIN:-ollama}" serve
