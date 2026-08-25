# DFTC Guided Fine-Tuning

`data/training/dftc_guided_sft.jsonl` 是起始的工具选择与反幻觉样本，不能单独作为生产训练集。每次真实 Agent episode 由 DFT 工程师标为 `approved` 或给出 `corrected` 回复后，导出到同一训练文件；`rejected` episode 只保留为反例审计，绝不导出。

训练前置条件：至少收集 12 条经审阅的 DFTC 轨迹、保留 3 条未参与训练的 holdout、关闭 Ollama 或其他 GPU 工作负载，并确认 `nvidia-smi` 可用显存不低于 5 GiB。

```bash
conda run -n tf_2_18 python -m pip install -e '.[train]'
conda run -n tf_2_18 python -m dft_agent_flow.train_lora \
  --dataset data/training/dftc_guided_sft.jsonl \
  --output adapters/qwen3-1.7b-dftc
```

先在 holdout 上检查：模型是否调用正确技能、是否拒绝任意 shell/Tcl、是否只复述工具证据。运行时使用 16k context 并关闭 Qwen3 hidden thinking；adapter 通过这些检查和工程师审阅后，才可用于替代基础模型；它不能替代 DFT 签核。
