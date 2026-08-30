#!/usr/bin/env bash

set -euo pipefail

root=/home/yusen/dft_agent_training
python=/home/yusen/miniforge3/envs/dft_lora/bin/python
dataset="$root/data/training/dft_role_guard_v9_20260830.jsonl"
model="$root/models/Qwen3.5-4B"
output="$root/artifacts/training/amd/role_guard_v9_qwen35_4b_epoch1_20260830"

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

test "$(sha256sum "$dataset" | awk '{print $1}')" = "d174abf5188dc6aa7df6191679c66078c4ef613be356560aafeddc393d9377e2"
test "$(sha256sum "$root/src/dft_agent_flow/train_lora.py" | awk '{print $1}')" = "4a122909b4dceab65448bfb57045eff22b11b0e46c00b916577a67bd1c9f0ed0"
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
  --adapter-name role_guard \
  --epochs 1 \
  --max-steps -1 \
  --max-length 768 \
  --gradient-accumulation-steps 4 \
  --learning-rate 1e-4 \
  --lora-r 16 \
  --lora-alpha 32 \
  --lora-dropout 0.05 \
  --seed 20260827 \
  --execution-mode gpu_4bit
