#!/usr/bin/env bash

set -euo pipefail

if [ "$#" -ne 1 ]; then
  echo "用法：$0 strict5|workspace8|role_tool10|terminal20|source4|supervisor8|cheshire8" >&2
  exit 2
fi

root=/home/yusen/dft_agent_training
python=/home/yusen/miniforge3/envs/dft_lora/bin/python
model="$root/models/Qwen3.5-4B"
adapter="$root/artifacts/training/amd/dft_agent_unified_v2_qwen35_4b_20260830"
result_root="$root/artifacts/evals/amd/dft_agent_unified_v2"

unset HTTP_PROXY HTTPS_PROXY ALL_PROXY http_proxy https_proxy all_proxy
export HF_ENDPOINT=https://hf-mirror.com
export HF_HUB_OFFLINE=1
export TRANSFORMERS_OFFLINE=1
export HF_HOME="$root/cache/huggingface"
export TRANSFORMERS_CACHE="$root/cache/huggingface/transformers"
export HUGGINGFACE_HUB_CACHE="$root/cache/huggingface/hub"
export PYTHONPATH="$root/src"
export HSA_OVERRIDE_GFX_VERSION=10.3.0
export PYTORCH_ROCM_ARCH=gfx1030

test "$(sha256sum "$root/src/dft_agent_flow/evaluate_lora.py" | awk '{print $1}')" = "b24ba983a5f66f67cf332c0b00739877a959a417015e82089315a214ebf2da8c"
test "$(sha256sum "$root/src/dft_agent_flow/terminal.py" | awk '{print $1}')" = "e3d7dddf72f0000b6c320004562767624cf084433adf0e471f607eba7ecb62cc"
test -f "$adapter/checkpoint-327/trainer_state.json"
test -f "$adapter/adapter_config.json"
mkdir -p "$result_root"

case "$1" in
  strict5)
    cases="$root/data/evals/workspace_agent_development_v4_smoke5_20260830.jsonl"
    expected_sha=62a7f780f91aea6ad9d25021de3e5966d0638747b4122596a9b191b328b8d312
    output="$result_root/dft_agent_unified_v2_structural5_20260830.json"
    policy=(--policy workspace)
    ;;
  workspace8)
    cases="$root/data/evals/workspace_agent_development_v4_20260830.jsonl"
    expected_sha=7a4442d358a7594e4bcded204b16641f717b72a4c9f6d52eed6c56f877375c9f
    output="$result_root/dft_agent_unified_v2_workspace8_20260830.json"
    policy=(--policy workspace)
    ;;
  role_tool10)
    cases="$root/data/evals/dft_role_tool_development_20260830.jsonl"
    expected_sha=0dc12252e0fae0ec4713326cdc7945349454041516f27ba4e980635c2c7b1765
    output="$result_root/dft_agent_unified_v2_role_tool10_20260830.json"
    policy=(--policy auto --case-policy role --case-policy tool)
    ;;
  terminal20)
    cases="$root/data/evals/terminal_agent_development_v1_20260830.jsonl"
    expected_sha=f4c56a5c1e450891a2b2198751621e7c0c095777033a59027e4f97c0ec25c3ea
    output="$result_root/dft_agent_unified_v2_terminal20_20260830.json"
    policy=(--policy workspace)
    ;;
  source4)
    cases="$root/data/evals/source_preprocess_recovery_development_v1_20260830.jsonl"
    expected_sha=6eb97b3d2120b59b1ed8b9693e3244bb32cbabd2964b3a417d2ccab00a4d96a3
    output="$result_root/dft_agent_unified_v2_source4_20260830.json"
    policy=(--policy auto)
    ;;
  supervisor8)
    cases="$root/data/evals/supervisor_iteration_development_v1_20260830.jsonl"
    expected_sha=3894e043b3c4e2dfdede429c52984e8a794c8de87f67b61d1ce33294e7a88e9b
    output="$result_root/dft_agent_unified_v2_supervisor8_20260830.json"
    policy=(--policy auto)
    ;;
  cheshire8)
    cases="$root/data/evals/cheshire_workspace_development_v1_20260830.jsonl"
    expected_sha=ed584166fb100600d39b2742f95774a967397010d7b55595b6bf1efc3accbf88
    output="$result_root/dft_agent_unified_v2_cheshire8_20260830.json"
    policy=(--policy auto)
    ;;
  *)
    echo "未知测试组：$1" >&2
    exit 3
    ;;
esac

test "$(sha256sum "$cases" | awk '{print $1}')" = "$expected_sha"
if [ -e "$output" ]; then
  echo "结果文件已经存在，拒绝覆盖：$output" >&2
  exit 8
fi

exec "$python" -u -m dft_agent_flow.evaluate_lora \
  --adapter "$adapter" \
  --require-runtime-identity \
  --cases "$cases" \
  --output "$output" \
  --model "$model" \
  --max-new-tokens 1024 \
  --execution-mode gpu_4bit \
  "${policy[@]}"
