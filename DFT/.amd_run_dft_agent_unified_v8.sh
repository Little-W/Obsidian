#!/usr/bin/env bash

set -euo pipefail
root=/home/yusen/dft_agent_training
python=/home/yusen/miniforge3/envs/dft_lora/bin/python
dataset="$root/data/training/dft_agent_unified_v8_candidate_20260831.jsonl"
manifest="$root/data/training/dft_agent_unified_v8_candidate_20260831.manifest.json"
model="$root/models/Qwen3.5-4B"
output="$root/artifacts/training/amd/dft_agent_unified_v8_qwen35_4b_20260831_r1"

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

test "$(sha256sum "$dataset" | awk '{print $1}')" = "a4cdb4a7bd2163ce94195bbe863272c46651d5e65bd321513c7b901be6f26c7b"
test "$(sha256sum "$manifest" | awk '{print $1}')" = "2f6b635d55ae17f9e6c33ca2560308dfa7c7ae8c5f1be6ec051cc684dd7f0cd0"
test "$(sha256sum "$root/src/dft_agent_flow/train_lora.py" | awk '{print $1}')" = "87946760ffd6633e158f493a248e190cc100efdec47f718fa613ad5dfd263469"
test -d "$model"
if [ -e "$output" ]; then
  echo "输出目录已经存在，拒绝覆盖：$output" >&2
  exit 8
fi

"$python" - <<'PY'
import torch
assert torch.cuda.is_available()
assert torch.cuda.is_bf16_supported()
x = torch.randn((128, 128), dtype=torch.bfloat16, device="cuda")
y = x @ x.T
assert torch.isfinite(y).all().item()
print({"bf16": True, "device": torch.cuda.get_device_name(0), "finite": True})
PY

exec "$python" -u -m dft_agent_flow.train_lora \
  --dataset "$dataset" \
  --output "$output" \
  --model "$model" \
  --adapter-name dft_agent \
  --epochs 1 \
  --max-steps -1 \
  --max-length 1280 \
  --gradient-accumulation-steps 4 \
  --learning-rate 1e-4 \
  --lora-r 16 \
  --lora-alpha 32 \
  --lora-dropout 0.05 \
  --seed 20260827 \
  --save-strategy steps \
  --save-steps 300 \
  --save-total-limit 4 \
  --execution-mode gpu_4bit \
  --deployment-backend llama_cpp
