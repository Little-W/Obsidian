# Vivado 综合与时序优化记录

## 1. 验证目标

本记录用于追踪 NPU 单核 RTL 在 Xilinx Artix-7 FPGA 上的综合、布局和布线结果，并记录复杂数学单元的结构调整过程。

固定配置如下：

| 项目 | 配置 |
|---|---|
| 顶层模块 | `npu_single_core_top` |
| FPGA 器件 | `xc7a200tfbg484-3` |
| Vivado | `2024.2.1` |
| 目标时钟周期 | `10.000 ns` |
| 目标频率 | `100 MHz` |
| 时钟不确定度 | `0.200 ns` |
| 输入延迟 | `1.000 ns` |
| 输出延迟 | `1.000 ns` |
| 综合方式 | Out-of-Context |

`core_clk_i` 与 `noc_clk_i` 均使用 `10.000 ns` 周期。两个时钟属于异步时钟组，因此时序工具不会检查两个时钟域之间的同步时序。

> [!NOTE]
> 综合后的时序报告用于快速判断 RTL 结构。100 MHz 是否满足要求，最终以布局和布线后的报告为准。

## 2. 命令与报告位置

### 2.1 综合快速检查

综合快速检查使用：

```sh
/home/yusen/opt/Xilinx/Vivado/2024.2/bin/vivado \
  -mode batch \
  -notrace \
  -source "/home/yusen/Obsidian Vault/NPU/rtl/syn/vivado_100mhz/run_vivado_synth_only.tcl" \
  -tclargs \
  <RTL_ROOT> \
  "/home/yusen/Obsidian Vault/NPU/rtl/syn/vivado_100mhz/npu_single_core_100mhz.xdc" \
  <REPORT_DIR> \
  xc7a200tfbg484-3 \
  10.000
```

脚本位置：

- `NPU/rtl/syn/vivado_100mhz/run_vivado_synth_only.tcl`
- `NPU/rtl/syn/vivado_100mhz/npu_single_core_100mhz.xdc`

计划保存的文本报告：

- `NPU/rtl/syn/vivado_100mhz/reports/baseline/utilization_post_synth.rpt`
- `NPU/rtl/syn/vivado_100mhz/reports/baseline/timing_post_synth.rpt`
- `NPU/rtl/syn/vivado_100mhz/reports/baseline/critical_paths_post_synth.rpt`
- `NPU/rtl/syn/vivado_100mhz/reports/fp_seq/utilization_post_synth.rpt`
- `NPU/rtl/syn/vivado_100mhz/reports/fp_seq/timing_post_synth.rpt`
- `NPU/rtl/syn/vivado_100mhz/reports/fp_seq/critical_paths_post_synth.rpt`

### 2.2 布局和布线

完整运行命令：

```sh
cd "/home/yusen/Obsidian Vault/NPU/rtl/syn/vivado_100mhz"
make clean
make syn \
  BUILD_DIR=build_fp_seq_100mhz \
  JOBS=1 \
  PART=xc7a200tfbg484-3 \
  PERIOD_NS=10.000
```

完整结果将保存在：

- `NPU/rtl/syn/vivado_100mhz/build_fp_seq_100mhz/summary.txt`
- `NPU/rtl/syn/vivado_100mhz/build_fp_seq_100mhz/utilization_post_route.rpt`
- `NPU/rtl/syn/vivado_100mhz/build_fp_seq_100mhz/timing_post_route.rpt`
- `NPU/rtl/syn/vivado_100mhz/build_fp_seq_100mhz/critical_paths_post_route.rpt`
- `NPU/rtl/syn/vivado_100mhz/build_fp_seq_100mhz/methodology_post_route.rpt`

## 3. 初始结构

初始版本的 `npu_complex_engine` 直接调用多个组合 FP32 函数。Sigmoid、Tanh、GELU、SiLU、Softmax、LayerNorm 和 RMSNorm 会同时展开多个加法、减法、乘法、倒数、指数和平方根倒数运算。

这种写法产生以下硬件结构：

- 相同 FP32 运算在多个表达式中重复展开；
- 一个时钟周期内串接多级 FP32 运算；
- 次正规数处理包含多次连续移位；
- 指数、倒数和平方根倒数包含多层多项式运算；
- 复杂数学结果继续进入整数转换和数据类型裁剪。

初始版本快照：

| 项目 | 值 |
|---|---|
| Git 提交 | `d9b6315db52ae63c99bcf86f85d33ef689d5d271` |
| 快照目录 | `/tmp/npu_fp_baseline.8cV0xQ/rtl` |
| 首次综合并行度 | 4 |
| 首次运行结果 | 因物理内存不足产生大量主缺页，已中断 |
| 首次运行峰值内存 | `6098.270 MB`，来自 Vivado 日志 |
| 首次运行结束位置 | `Start Timing Optimization` |

> [!WARNING]
> 首次运行出现 Vivado 的 `Thrashing Detected` 提示，主缺页数量超过 70 万。该次运行没有生成最终报告，不用于资源或时序结论。随后把综合并行度改为 1 并重新运行。

## 4. RTL 调整记录

### 4.1 第 1 轮：共享顺序 FP32 加减乘单元

新增 `engines/npu_fp32_alu_seq.sv`。

主要调整：

- ADD、SUB 和 MUL 共用一个 FP32 运算单元；
- 请求使用 `req_valid_i/req_ready_o`；
- 结果使用 `rsp_valid_o/rsp_ready_i`；
- 加法对齐、加减、规格化和舍入分为多个状态；
- 次正规数每个周期移动 1 bit；
- 24-bit × 24-bit 乘法单独占用一个状态；
- 结果保持到接收方确认。

目标是缩短单周期组合数据路径，并减少重复的 FP32 运算硬件。

### 4.2 第 2 轮：复杂数学微操作状态机

新增 `engines/npu_complex_math_seq.sv`。

主要调整：

- Sigmoid、Tanh、GELU、SiLU、EXP、倒数和平方根倒数改为多周期执行；
- 复合函数通过微操作调用共享 ADD、SUB 和 MUL；
- 使用返回状态栈支持函数内部调用；
- I2F 后乘比例值、近似除法和倒数也使用同一请求/响应接口；
- 中间值存放在寄存器中，下一步运算在后续周期发起。

### 4.3 第 3 轮：Complex Engine 接入

修改 `engines/npu_complex_engine.sv`。

主要调整：

- 增加 `ST_MATH_REQ` 和 `ST_MATH_RSP`；
- 增加动作编号，记录每次数学结果的后续处理；
- 激活、Softmax、LayerNorm、RMSNorm 和 ADD_RESCALE 改为逐步发起微操作；
- 四组分段累加值按固定顺序相加；
- Welford 均值和 M2 更新改为多个微操作；
- 输出比例除法完成后再执行 FP32 到整数转换；
- 保留原有数据类型裁剪、异常状态、INT4 读改写和存储请求行为。

### 4.4 第 4 轮：拆分 EXP 的两个转换

`ST_EXP_RANGE_ROUND` 原本在同一周期执行：

1. FP32 到整数舍入；
2. 整数再转换为 FP32。

新增 `ST_EXP_RANGE_FROM_INT`，把两次转换放到两个周期，避免两段可变移位逻辑串接。

## 5. 每轮结果

### 5.1 结构修改前基线

本轮结果来自 `npu_single_core_top` 的完整 Out-of-Context 综合、布局、物理优化和布线。器件为 `xc7a200tfbg484-3`，Vivado 为 `2024.2.1`，`core_clk_i` 与 `noc_clk_i` 的周期均为 `10.000 ns`，时钟不确定度为 `0.200 ns`，Vivado 进程数为 1。布线已完成，`108272` 条需要布线的网络全部完成，布线错误数为 0。

#### 5.1.1 时序结果

| 指标 | 综合后 | 布线后 |
|---|---:|---:|
| WNS | `-58.981 ns` | `-78.625 ns` |
| TNS | `-601676.673 ns` | `-1044141.190 ns` |
| setup 失败终点数 | `19370` | `49140` |
| WHS | `-0.021 ns` | `+0.009 ns` |
| THS | `-2.256 ns` | `0.000 ns` |
| hold 失败终点数 | `144` | `0` |
| 最差 setup 数据路径延迟 | `68.244 ns` | `88.194 ns` |
| 最差 setup 逻辑级数 | `212` | `205` |

综合后的最差 setup 路径从 `u_task_scheduler/task_submit_seq_q_reg[0][1]/C` 到 `u_task_scheduler/u_task_desc_decode/desc_flat_o0/B[0]`。布线后的最差 setup 路径从 `u_task_scheduler/task_submit_seq_q_reg[0][19]/C` 到 `u_task_scheduler/decode_pending_cmd_q_reg[123]_rep/D`。

> [!WARNING]
> `10.000 ns` 周期要求下，布线后 WNS 为 `-78.625 ns`，因此本轮结果不满足 100 MHz。按照最差路径所需时间进行粗略换算，频率约为 11.3 MHz；该数值只用于说明差距，不作为可用工作频率。

#### 5.1.2 层级资源

| 层级 | Slice LUTs | Slice Registers | RAMB36 | DSP48E1 |
|---|---:|---:|---:|---:|
| `npu_single_core_top` | `96374` | `30306` | `256` | `134` |
| `u_task_scheduler` | `60390` | `18111` | `0` | `10` |
| `u_task_scheduler/u_task_desc_decode` | `11912` | `32` | `0` | `10` |
| `u_axi_slave_frontend` | `11645` | `2740` | `0` | `0` |
| `u_complex_engine` | `9010` | `2797` | `0` | `33` |
| `u_matrix_engine` | `4573` | `864` | `0` | `49` |
| `u_dma_engine` | `3448` | `2535` | `0` | `0` |
| `u_vector_engine` | `2811` | `835` | `0` | `42` |
| `u_l1buf` | `2527` | `346` | `256` | `0` |
| `u_cmd_frontend` | `1551` | `1163` | `0` | `0` |

器件总体使用率为 Slice LUT `72.03%`、Slice Register `11.33%`、Block RAM Tile `70.14%`、DSP `18.11%`。`u_task_scheduler` 占全部 Slice LUT 的 `62.66%`，占全部 Slice Register 的 `59.76%`，是本轮面积与布线压力的主要来源。

#### 5.1.3 L1 RAM 原语检查

| 检查项 | 结果 |
|---|---:|
| 全设计 RAMB36E1 | `256` |
| 全设计 RAMB18 | `0` |
| 全设计 LUTRAM | `0` |
| L1 RAMB36E1 | `256` |
| L1 RAMB18 | `0` |
| L1 LUTRAM | `0` |
| L1 `memory_q` 名称下的触发器 | `0` |

L1 的 16 个 bank 各使用 16 个 RAMB36E1。大容量存储均由 Block RAM 实现，检查结果为 PASS。

> [!NOTE]
> Vivado 同时报告 256 条 `SYNTH-6` 告警：Block RAM 输出寄存器没有并入 RAM 原语。这不会改变上表中的原语数量，但会增加 RAM 读数据之后的时序压力，后续需要结合 L1 请求和响应周期处理。

#### 5.1.4 关键路径根因

setup 原始报告中的 200 条路径经过结构去重后保留 26 条。最差的 5 条记录如下：

| 序号 | 起点 | 终点 | Slack | 数据路径延迟 | 逻辑级数 | 重复数 |
|---:|---|---|---:|---:|---:|---:|
| 1 | `task_submit_seq_q[0][19]/C` | `decode_pending_cmd_q[123]_rep/D` | `-78.625 ns` | `88.194 ns` | `205` | `3` |
| 2 | `task_submit_seq_q[0][19]/C` | `decode_pending_cmd_q[123]/D` | `-78.617 ns` | `88.198 ns` | `205` | `18` |
| 3 | `task_submit_seq_q[0][19]/C` | `decode_pending_input_base_q[18]/CE` | `-78.565 ns` | `88.145 ns` | `204` | `21` |
| 4 | `task_submit_seq_q[0][19]/C` | `decode_pending_weight_base_q[17]/D` | `-78.546 ns` | `88.371 ns` | `206` | `15` |
| 5 | `task_submit_seq_q[0][19]/C` | `decode_pending_weight_base_q[10]/CE` | `-78.534 ns` | `88.144 ns` | `204` | `22` |

这 5 条记录具有相同的结构原因。Scheduler 在一个周期内检查 16 个任务槽，计算每个槽的顺序阻塞状态，再使用 64-bit 提交序号逐项选择可执行任务。综合结果把这些比较器和优先选择逻辑串接起来，最差路径包含 112 个 CARRY4。随后，该选择结果同时驱动命令、基地址、命令编号等快照寄存器的 D 或 CE 引脚。

最差路径的逻辑延迟为 `23.718 ns`，布线延迟为 `64.476 ns`，布线部分占 `73.1%`。布局报告中的方向热点约为 `85.6%` 至 `93.7%`。因此问题不仅来自 64-bit 比较器本身，也来自 Scheduler 的大规模组合扫描、高扇出控制以及较高的 LUT 使用率。

#### 5.1.5 Methodology 告警与 Out-of-Context 限制

Methodology 报告没有 Error 或 Critical Warning，共记录 2491 条 Warning。需要优先关注的项目如下：

| 规则 | 数量 | 说明 |
|---|---:|---|
| `LUTAR-1` | `2` | 组合 LUT 驱动异步清除，其中一项涉及 12505 个清除引脚，另一项涉及 163 个清除引脚，存在毛刺触发风险 |
| `TIMING-16` | `1000` | 大 setup 违例 |
| `TIMING-9` | `1` | 工具发现未识别的跨时钟处理结构 |
| `TIMING-18` | `241` | 部分输入或输出缺少相对于相应时钟的延迟设置 |
| `XDCH-2` | `616` | 输入或输出的最小延迟与最大延迟均设置为 `1.000 ns`，需要结合 SoC 接口时序确认 |
| `SYNTH-6` | `256` | Block RAM 输出寄存器没有并入 RAM 原语 |
| `SYNTH-10` | `119` | 宽乘法器被拆成多个 DSP |
| `SYNTH-15` | `256` | Block RAM 没有推断出 byte-wide write enable |

本轮使用 Out-of-Context 方式，因此没有顶层封装中的真实时钟缓冲位置、芯片引脚位置和 SoC 总线外围逻辑。报告明确提示 `core_clk_i` 未设置 `HD.CLK_SRC`，部分端口未设置 `HD.PARTPIN_LOCS`。这些缺失会影响时钟偏差和端口路径估算，最终 SoC 工程需要使用实际引脚、时钟资源和外部器件时序重新检查。

> [!NOTE]
> 最差 setup 路径的起点和终点都位于 `core_clk` 时钟域内，不经过顶层输入或输出端口。因此，I/O 延迟设置不完整不能解释 `-78.625 ns` 的内部路径违例；Scheduler 组合结构仍是当前需要优先处理的问题。

#### 5.1.6 报告文件

- 总结：`NPU/rtl/syn/vivado_100mhz/build/summary.txt`
- 综合后总结：`NPU/rtl/syn/vivado_100mhz/build/summary_post_synth.txt`
- 布线后总结：`NPU/rtl/syn/vivado_100mhz/build/summary_post_route.txt`
- 层级资源：`NPU/rtl/syn/vivado_100mhz/build/utilization_hierarchical_post_route.rpt`
- RAM 原语：`NPU/rtl/syn/vivado_100mhz/build/memory_primitives_post_route.rpt`
- 去重后的 setup 路径：`NPU/rtl/syn/vivado_100mhz/build/timing_paths_setup_post_route_dedup.rpt`
- Methodology：`NPU/rtl/syn/vivado_100mhz/build/methodology_post_route.rpt`
- 布线状态：`NPU/rtl/syn/vivado_100mhz/build/route_status_post_route.rpt`
- Vivado 日志：`NPU/rtl/syn/vivado_100mhz/build/vivado_resume_internal.log`
- 布线后检查点：`NPU/rtl/syn/vivado_100mhz/build/post_route.dcp`

### 5.2 优化后结果

Scheduler 共用扫描器、Matrix 标量后处理分级以及 DiP 数据路径调整完成后，在相同器件、时钟设置和工具版本下重新运行。下表保留给后续结果：

| 指标 | 综合后 | 布线后 |
|---|---:|---:|
| Slice LUTs | 待填写 | 待填写 |
| Slice Registers | 待填写 | 待填写 |
| Block RAM Tile | 待填写 | 待填写 |
| DSPs | 待填写 | 待填写 |
| WNS | 待填写 | 待填写 |
| TNS | 待填写 | 待填写 |
| WHS | 待填写 | 待填写 |
| THS | 待填写 | 待填写 |

关键路径：

| 项目 | 综合后 | 布线后 |
|---|---|---|
| 起点 | 待填写 | 待填写 |
| 终点 | 待填写 | 待填写 |
| 逻辑级数 | 待填写 | 待填写 |
| 数据路径延迟 | 待填写 | 待填写 |
| 主要逻辑 | 待填写 | 待填写 |

100 MHz 结论：待填写。

## 6. 功能回归

当前已经完成：

| 测试 | 结果 |
|---|---|
| 顶层 Verilator lint | PASS，无告警 |
| FP32 ADD/SUB/MUL 随机比对 | PASS，6010 项 |
| 复杂数学参考测试 | PASS，71 项 |
| 模块级 Engine 测试 | PASS，L1 握手 156 次，MIF 握手 8 次 |
| 独立 Complex Engine 测试 | PASS |
| Sigmoid、Tanh、Softmax、LayerNorm 示例 | PASS |

Transformer 旧构建的 41 条指令测试结果：

```text
score=[14,-5,-5,30]
probability=[4,0,0,4]
context=[2,-1,3,0,-2,4,1,3]
int8=[7,-8,13,-14,-3,4,1,5]
```

最新 RTL 的 `make clean && make test` 结果：待实现结果。

## 7. 综合警告

初始版本日志已经确认以下类别：

- 前端部分数组无法推断为 Block RAM，工具改用寄存器；
- 部分寄存器同时具有 set 和 reset；
- 若干未使用寄存器被综合工具删除；
- 首次 4 进程运行发生物理内存不足和大量主缺页。

结构修改前基线的完整 Methodology 结果见 5.1.5。当前需要优先处理组合 LUT 驱动异步清除、Scheduler 大 setup 违例、跨时钟处理检查、I/O 延迟设置、Block RAM 输出寄存器和宽乘法器拆分等项目。

## 8. 当前结论

结构修改前基线已经完成综合、布局、物理优化和布线。L1 使用 256 个 RAMB36E1，RAM 原语检查通过，hold 检查通过；setup 的 WNS 为 `-78.625 ns`，不满足 100 MHz。关键问题集中在 Scheduler 的 16-slot 组合扫描、64-bit 提交序号比较和逐项优先选择，相关逻辑还带来较高的 LUT 使用率和布线延迟。

后续结果需要在 Scheduler、Matrix 和 DiP 调整完成并通过功能回归后，使用相同器件、周期、Vivado 版本和报告脚本重新生成。5.2 暂不填写，避免把结构修改前结果与调整后的 RTL 混在一起。
