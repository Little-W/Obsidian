# Local DFT Agent Flow

这是面向本仓库开源 Design-for-Test 资源的本地 ATPG agent。它以 `FAN_ATPG` 的 ISCAS 组合逻辑电路为执行后端，使用本地 `qwen3:4b-instruct` 理解中文目标并通过受限 Python 工具工作。

它不是量子化学的 Density Functional Theory 工作流。原始资源表明这里的 DFT 是 Design for Test。

详细架构、信任边界、轻度诊断/修复权限见 [docs/AGENT_DESIGN.md](docs/AGENT_DESIGN.md)，逐项调试证据见 [docs/DEBUG_REPORT_2026-08-25.md](docs/DEBUG_REPORT_2026-08-25.md)。

## 设计边界

- 轻量框架：Hugging Face `smolagents` 的 `ToolCallingAgent`，不授予模型 Python/shell 执行能力。
- 本地模型：默认是 Ollama 上的 `qwen3:4b-instruct`，4-bit 约 2.5 GB。已在本机 32K 设置下对比 `qwen3.5:4b`（约 3.4 GB）；后者可调用审计工具，但无法稳定生成框架要求的最终工具 JSON，因此保留为候选而不替换默认模型。默认上下文限制为 32768，并发为 1；显存不足时 Ollama 会部分卸载到 CPU，推理会变慢。
- 执行安全：模型只能调用四个 Python 工具。电路和配置由白名单校验；FAN 输入是原资源的只读链接；输出只写入 `artifacts/runs/`。
- 优化目标：先满足最低 fault coverage 和可选的最大 pattern 数，再最小化 pattern 数；所有候选配置的真实报告都会被保留。
- 监督闭环：每次 agent 会话保存 episode，工程师可记录批准、修正或拒绝；只将批准/修正的样本导出为 SFT 数据。
- DFTC 执行：模型只能调用“运行并双重验证”的受控技能。执行、报告、反证三个独立审计角色会读取同一工作区两次；只有两轮哈希一致且均通过时，才得到 `verified` 执行证据。

## 安装和启动

已为本机的 `tf_2_18` 环境准备。首次启动运行：

```bash
cd "/home/yusen/Obsidian Vault/DFT/dft_agent_flow"
OLLAMA_BIN="/home/yusen/.local/bin/ollama" ./scripts/bootstrap_local_llm.sh
```

可复现 Python 依赖在 `requirements.txt`；测试和可选 QLoRA 训练分别使用 `requirements-dev.txt` 和 `requirements-train.txt`：

```bash
conda run -n tf_2_18 python -m pip install -r requirements.txt
conda run -n tf_2_18 python -m pip install -e .
```

脚本会安装本项目、启动仅监听本机的 Ollama 服务，并下载 `qwen3:4b-instruct` 到 `.ollama_models/`。模型下载完成后，执行一个不依赖 LLM 的真实目标优化：

```bash
conda run -n tf_2_18 dft-flow optimize --circuit s27 --min-coverage 94.5 --max-patterns 5
```

结果 JSON 中的 `selected_run_id`、`selected_profile`、`objective_met` 和 `candidates` 是完整实验依据。每次运行的脚本、FAN stdout/stderr、报告、PAT/STIL 和结构化结果都在 `artifacts/runs/<run-id>/`。

## Agent 用法

```bash
conda run -n tf_2_18 dft-flow agent \
  --goal "对 s27 执行 ATPG，fault coverage 至少 94.5%，pattern 不超过 5，给出最优可验证配置。"
```

agent 先使用工具确认可用电路和配置，再调用一个或多个受限工具。它不能运行任意 shell、编写任意 FAN 脚本、修改网表，也不能把未经执行的数值当成结果。对 scan insertion、商业 DFT 工具设置、DRC、时序/功耗签核和量产向量发布，本原型只会要求人工批准。

DFTC Lab 4A 的官方直接验证可从命令行运行：

```bash
conda run -n tf_2_18 dft-flow dftc-skill --skill lab4a_protocol_direct
```

命令会在 `/media/6/Projects/DFTC1_agent_workspaces/` 新建工作区，生成 `skill_result.json` 与 `cross_validation.json`。已有工作区可只读复核：

```bash
conda run -n tf_2_18 dft-flow dftc-verify --evidence /media/6/Projects/DFTC1_agent_workspaces/<run>/skill_result.json
```

## 图形界面

启动 PyQt6 操作界面：

```bash
conda run -n tf_2_18 dft-gui
```

界面可设置四类目标：DFTC 单 Lab 的受控执行、审计、教学和差异比较，完整课程的逐 Lab 交叉验证，FAN ATPG 的 circuit、最低 coverage、最大 pattern 数，以及提交锁定的开源 RTL 从零 DFT 或证据诊断。所有“运行”按钮都仍由同一个 Agent 工具边界执行；底部证据表可以重新只读复核已有的 `skill_result.json`。

对于 DFTC 执行，模型的自然语言最终答复不作为结论来源。运行工具返回后，监督层会以实际 `cross_validation.json` 强制生成 `verified`、`blocked` 或 `needs_review` 状态、阻塞项和证据路径。

## 开源 RTL 从零 DFT

`external_sources/` 包含三个只读、浅克隆且提交锁定的 Verilog 项目：`secworks_aes`、`secworks_sha256` 和 `freecores_i2c`。Agent 不会执行其中的脚本；它只会把 manifest 白名单中的 RTL 复制进新的工作区，用生成 Tcl 读取、综合、建立测试协议、预览和插入 scan，并双轮复核全部证据。

```bash
conda run -n tf_2_18 dft-flow external-list
conda run -n tf_2_18 dft-flow external-inspect --project secworks_aes
conda run -n tf_2_18 dft-flow external-run --project secworks_aes
conda run -n tf_2_18 dft-flow external-diagnose --project secworks_aes
```

也可将相同目标交给 Agent：

```bash
conda run -n tf_2_18 dft-flow agent \
  --goal "对开源 secworks_aes 从头执行 DFT flow，必须调用受控工具并双重交叉验证；中文仅报告证据。"
```

外部流程证据位于 `/media/6/Projects/DFT_agent_external_workspaces/`。如果诊断返回 `approved_actions`，Agent 只能使用其中的精确 action 通过 `external-repair` 重跑；未分类问题会要求工程师审查，而不会生成任意修复脚本。

候选模型可在不改默认配置的前提下测试：

```bash
conda run -n tf_2_18 dft-flow agent \
  --model qwen3.5:4b \
  --goal "审计 lab12_dftmax 的运行时证据，并列出所有阻塞项。"
```

## 监督、评测和微调

审阅 agent 的 `episode_id` 后记录反馈：

```bash
conda run -n tf_2_18 dft-flow feedback \
  --episode <episode-id> --verdict corrected \
  --note "遗漏了 artifact 目录" \
  --corrected-response "...经工程师修订的最终答复..."

conda run -n tf_2_18 dft-flow export-sft \
  --output data/training/dft_agent_sft.jsonl
```

先运行确定性回归案例，确认工具层没有退化：

```bash
conda run -n tf_2_18 dft-flow evaluate --execute
```

只有积累了经过复核的样本后才启动 LoRA。训练基座是 `Qwen/Qwen3-1.7B`，以 4-bit QLoRA 方式训练 adapter，不训练或覆盖 Ollama 的量化推理模型：

```bash
conda run -n tf_2_18 python -m pip install -e '.[train]'
conda run -n tf_2_18 python -m dft_agent_flow.train_lora \
  --dataset data/training/dft_agent_sft.jsonl \
  --output adapters/qwen3-1.7b-dft
```

训练脚本会在可用显存低于 5 GiB 时停止。先关闭占用 GPU 的程序，或明确审核后才使用 `--force`。LoRA adapter 训练后应先通过 holdout 目标与人工审阅，不能直接替代基本模型。
