#!/usr/bin/env bash

set -euo pipefail

if [ "$#" -ne 1 ]; then
  echo "用法：$0 strict5|workspace_dev8|role_tool_dev10" >&2
  exit 2
fi

root=/home/yusen/dft_agent_training
python=/home/yusen/miniforge3/envs/dft_lora/bin/python
model="$root/models/Qwen3.5-4B"
adapter="$root/artifacts/training/amd/role_guard_v9_qwen35_4b_epoch1_20260830"
result_root="$root/artifacts/evals/amd"

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

test "$(sha256sum "$root/src/dft_agent_flow/evaluate_lora.py" | awk '{print $1}')" = "6ebca1da4efa1591d75c120789663923a57e21753e18f4d10a53e07d2a484e4a"
test -f "$adapter/checkpoint-129/trainer_state.json"
test -f "$adapter/adapter_config.json"
mkdir -p "$result_root"

case "$1" in
  strict5)
    cases="$root/data/evals/workspace_agent_development_v4_smoke5_20260830.jsonl"
    expected_sha=62a7f780f91aea6ad9d25021de3e5966d0638747b4122596a9b191b328b8d312
    output="$result_root/role_guard_v9_epoch1_structural5_20260830.json"
    policy=(--policy workspace)
    ;;
  workspace_dev8)
    cases="$root/data/evals/workspace_agent_development_v4_20260830.jsonl"
    expected_sha=7a4442d358a7594e4bcded204b16641f717b72a4c9f6d52eed6c56f877375c9f
    output="$result_root/role_guard_v9_epoch1_workspace_dev8_20260830.json"
    policy=(--policy workspace)
    ;;
  role_tool_dev10)
    cases="$root/data/evals/dft_role_tool_development_20260830.jsonl"
    expected_sha=57cbfa554eaa1bc6afc2b4dc1b1c50236c1d92be89bfffe5a81c7fe8139d3501
    output="$result_root/role_guard_v9_epoch1_role_tool_dev10_20260830.json"
    policy=(--policy auto --case-policy role --case-policy tool)
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
  --cases "$cases" \
  --output "$output" \
  --model "$model" \
  --max-new-tokens 1024 \
  --execution-mode gpu_4bit \
  "${policy[@]}"
