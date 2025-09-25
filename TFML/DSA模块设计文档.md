# AI‑DSA MMA 计算单元：模块端口与操作约定（v0.1）

> 目标：为 `mma_top` 及其子模块（控制、加载、阵列、累加、重量化、FIFO 等）提供**端口定义**与**操作约定**。本规范优先面向硬件联调与驱动编写；语义以**有效/就绪**握手与**Tile 级调度**为核心。

---

## 0. 全局约定（Common Conventions）

**时序与复位**

* `clk` 上升沿有效；`rst_n` 低有效、异步输入、同步释放。

**数据类型与符号**

* 权重 `WEIGHT_WIDTH=8` 默认 `s8`；IA（Input Activation）`DATA_WIDTH=16` 默认 `s16`；累加通路 `s32`；输出 `s8`。
* 量化零点 `lhs_zp / dst_zp`、乘数与移位使用 `s32` 表示，右移为算术右移（保持符号）。

**矩阵维度与步幅**

* 目标运算：`[m×k] = LHS (m×k)` 与 `RHS (n×k)^T` 的块内乘加，块输出写回 `DST (m×n)`。
* 行跨度 `*_row_stride_b` 均为**字节**单位（BYTES）。
* `rhs_base` 对应 **N×K 行主序**（row‑major）。

**Tile/阵列**

* 脉动阵列尺寸 `SIZE×SIZE`。控制器将 `m×n×k` 切分为若干 Tile 执行，`valid_row_num/valid_col_num` 描述当前 Tile 的有效行/列（<=SIZE）。

**握手模型**

* 统一采用 `valid/ready` 与 `trigger/done` 语义：

  * 触发类：`*_trigger` 脉冲触发一次事务；
  * 流接口：`valid & ready` 同时为 1 时数据生效；
  * 完成类：`*_done`/`calc_done` 表示本 Tile 或本阶段结束；
  * 回压：下游 `ready=0` 时上游需保持 `valid` 与数据稳定。

**ICB LSU**

* 遵循 E203 ICB 有效/就绪握手：命令通道 `sa_icb_cmd_*`、响应通道 `sa_icb_rsp_*`。`size` 表示传输粒度（具体编码以 SoC ICB 规范为准）。

---

## 1. 顶层：`mma_top`

**参数**

* `WEIGHT_WIDTH=8`，`DATA_WIDTH=16`，`SIZE=16`，`BUS_WIDTH=32`，`REG_WIDTH=32`。

**外部接口（摘要）**

| 端口                                                   | 方向    | 位宽 | 描述                               |
| ---------------------------------------------------- | ----- | -: | -------------------------------- |
| `calc_start`                                         | In    |  1 | 触发一轮完整的 MMA 任务（控制器内部管理多 Tile）。   |
| `sa_ready`                                           | Out   |  1 | 系统空闲/可接收下一任务。                    |
| `lhs_base/rhs_base/dst_base`                         | In    | 32 | LHS/RHS/DST 基址（字节地址）。            |
| `bias_base/ksum_base`                                | In    | 32 | bias s32 / kernel\_sum（可为 0 关闭）。 |
| `lhs_zp/dst_zp`                                      | In    | 32 | 输入/输出零点（s32）。                    |
| `q_mult_pt/q_shift_pt`                               | In    | 32 | per‑tensor 乘数/右移。                |
| `q_mult_pc_base/q_shift_pc_base`                     | In    | 32 | per‑channel 参数数组基址。              |
| `use_per_channel`                                    | In    |  1 | 1=每通道量化，0=整张量量化。                 |
| `k/n/m`                                              | In    | 32 | 维度 K/N/M。                        |
| `lhs_row_stride_b/dst_row_stride_b/rhs_row_stride_b` | In    | 32 | LHS/DST/RHS 行跨度（字节）。             |
| `act_min/act_max`                                    | In    | 32 | 激活裁剪范围（s8 出口的 clamp）。            |
| `sa_icb_cmd_* / sa_icb_rsp_*`                        | Mixed |  - | ICB 主端口（读写内存）。                   |

**操作流程（高层）**

1. `calc_start` 置位 1 个周期；`sa_ready` 置 0，进入忙态。
2. 控制器分块：按 `SIZE×SIZE` 切 Tile，并为边界 Tile 设置 `valid_row_num/valid_col_num`。
3. 依次完成：权重加载 → IA 加载 → 脉动阵列计算/累加 → 加 bias → Requant → FIFO 打包 → 写回 DST。
4. 所有 Tile 完成后，`sa_ready` 置 1。

---

## 2. 控制器：`mma_controller`

**职责**

* 统一调度内存访问与各子模块触发；管理 Tile 边界；桥接重量化配置与 FIFO 出口写回。

**关键端口（摘录）**

| 端口                                 | 方向     |                位宽 | 描述                                      |
| ---------------------------------- | ------ | ----------------: | --------------------------------------- |
| `load_weight_trigger`              | Out    |                 1 | 触发本 Tile 的权重加载。                         |
| `valid_row_num/valid_col_num`      | Out    |      ⌈log2(SIZE)⌉ | 当前 Tile 的有效行/列数。                        |
| `weight_wr_addr/weight_wr_en`      | Out    | ⌈log2(SIZE²)⌉ / 1 | 写入阵列权重缓冲的地址/使能。                         |
| `weight_loading_done`              | In     |                 1 | 权重已准备。                                  |
| `load_ia_trigger`                  | Out    |                 1 | 触发 IA 行流加载。                             |
| `ia_valid_row_num`                 | Out    |      ⌈log2(SIZE)⌉ | 本 Tile 的 IA 有效行数。                       |
| `ia_wr_addr/ia_wr_en`              | Out    | ⌈log2(SIZE²)⌉ / 1 | IA 写地址/使能至行缓冲。                          |
| `ia_data_bus`                      | Out    |       `BUS_WIDTH` | IA 数据读自内存后送入子模块。                        |
| `lhs_offset`                       | Out    |               s32 | 传递给 IA 加载的零点；`ia_use_offset` 控制是否减零点。   |
| `use_16bits`                       | Out    |                 1 | 1=IA 以 16bit 输入阵列；0=8bit 路径（保留）。        |
| `is_last_tile`                     | Out    |                 1 | 该 Tile 为最后一块（供尾处理）。                     |
| `acc_valid_depth/acc_is_init_data` | Out    |  ⌈log2(SIZE)⌉ / 1 | 配置累加器的有效深度与初始化标志。                       |
| `requant_cfg_load_common`          | Out    |                 1 | 装载公共量化配置。                               |
| `requant_cfg_per_channel`          | Out    |                 1 | 选择 per‑channel。                         |
| `cfg_init_quant`                   | Out    |                 1 | 量化单元进入“配置接收”阶段。                         |
| `data_valid/data_in_s32`           | Out    |       1 / SIZE×32 | 可用于直通送数（本设计由 bias\_adder 输出驱动 Requant）。 |
| `requant_in_valid/out_valid/done`  | In/Out |                 1 | 重量化输入/输出/完成握手。                          |
| `fifo_*`                           | Mixed  |                 - | 向量 s8 → 打包/写回的握手。                       |
| `sa_icb_*`                         | Mixed  |                 - | 统一内存主接口（读写权重/IA/bias/DST）。              |
| `tile_calc_over`                   | In     |                 1 | 来自 `accumulator_array` 的 Tile 完成指示（单拍脉冲），用于触发写回或下一个 Tile 调度。 |

**操作约定**

* **Tile 组织**：控制器迭代 `(tile_m, tile_n, tile_k)`，在进入阵列计算前确保：`weight_loading_done=1` 且 `ia_loading_done=1`。
* **边界 Tile**：对不足 `SIZE` 的边界，分别发出 `valid_row_num/valid_col_num`，下游据此屏蔽无效通道。
* **量化配置**：

  * `cfg_init_quant` 拉高 →（若 `use_per_channel=0`）发出 `requant_cfg_load_common`，并提供 `pt_multiplier_in/pt_shift_in/dst_offset_in/act_min/max`。
  * 若 `use_per_channel=1`：控制器按输出通道分组，从 `q_mult_pc_base/q_shift_pc_base` 读取 SIZE 颗参数并在每个输出列（O 维）切换时更新。
* **写回**：

  * `requant_out_valid`→`fifo_in_valid`；`fifo_output_req` 由控制器根据 `icb_cmd_ready` 与 `fifo_full_flag` 进行流量控制；
  * `fifo_output_valid & fifo_output_ready` 成立时，通过 ICB 写 DST，写掩码 `sa_icb_cmd_wmask` 由 `fifo_output_mask` 直接生成。

---

## 3. 权重加载：`kernel_loader`

**端口**

| 端口                            | 方向  |              位宽 | 描述                       |
| ----------------------------- | --- | --------------: | ------------------------ |
| `load_weight_trigger`         | In  |               1 | 触发一批权重加载（单拍脉冲）。          |
| `weight_data_in`              | In  |     `BUS_WIDTH` | 从控制器/LSU 读回的原始总线数据。      |
| `valid_row_num/valid_col_num` | In  |    ⌈log2(SIZE)⌉ | 此 Tile 的有效行/列。           |
| `weight_wr_addr/weight_wr_en` | In  | ⌈log2(SIZE²)⌉/1 | 写入内部权重缓冲的地址/使能。          |
| `store_weight_req`            | Out |               1 | 请求阵列锁存当前分发的权重（写入 PE 寄存）。 |
| `weight_out[SIZE]`            | Out |  `WEIGHT_WIDTH` | 并行行输出至阵列（每个元素对应一行）。      |
| `weight_loading_done`         | Out |               1 | 本 Tile 权重预加载完成。          |

**操作约定**

**内部存储与数据组织**

* **列主序存储**：内部权重缓冲按列主序展平存放，适应从内存读取的 `RHS (N×K) row‑major` 数据
* **存储映射**：以 `SIZE×SIZE` 权重矩阵为例，内部存储顺序为：
  ```
  {w[0][0], w[1][0], w[2][0], ..., w[SIZE-1][0],   // 第0列
   w[0][1], w[1][1], w[2][1], ..., w[SIZE-1][1],   // 第1列
   ...
   w[0][SIZE-1], w[1][SIZE-1], ..., w[SIZE-1][SIZE-1]}  // 第SIZE-1列
  ```

**触发与配置锁存**

* **load_weight_trigger 处理**：
  - 单拍有效的触发信号，触发时锁存当前的 `valid_row_num` 和 `valid_col_num`
  - 锁存的边界参数用于后续权重输出的有效性控制和零填充
  - 触发后启动权重数据的预加载流程

**权重输出机制（行输出模式）**

* **行输出格式**：`weight_out[i]` 表示第 `i` 行权重向量，每次输出一个完整行
* **边界处理策略**：
  - **有效行处理**：仅前 `valid_row_num` 行输出真实权重数据
  - **有效列处理**：每行内仅前 `valid_col_num` 个元素为真实权重，其余填零
  - **无效行填充**：超出 `valid_row_num` 的行全部输出零向量

**输出示例**

以 `SIZE=4, valid_row_num=2, valid_col_num=2` 为例：
```
// 内部列主序存储：{w00, w10, w20, w30, w01, w11, w21, w31, ...}
// 行输出结果：
weight_out[0] = {w00, w01, 0, 0}    // 第0行：前2个有效，后2个填零
weight_out[1] = {w10, w11, 0, 0}    // 第1行：前2个有效，后2个填零  
weight_out[2] = {0,   0,   0, 0}    // 第2行：全零（超出valid_row_num）
weight_out[3] = {0,   0,   0, 0}    // 第3行：全零（超出valid_row_num）
```

**Weight-Stationary 对接**

* **store_weight_req 生成**：权重数据准备完毕后，发出多周期脉冲请求脉动阵列锁存，持续valid_row_num周期
* **列向分发适配**：虽然模块以行形式输出，但确保与 WS 阵列的列向权重分发兼容
* **时序协调**：`store_weight_req` 与有效权重数据同拍输出，阵列在该周期锁存至各PE

**完成与状态管理**

* **weight_loading_done 时机**：所有权重数据从内存预取到内部缓冲完成时拉高
* **多Tile支持**：每个Tile独立触发，支持不同的 `valid_row_num/valid_col_num` 配置

---

## 4. IA 加载：`ia_loader`

**端口**

| 端口                    | 方向  |              位宽 | 描述                            |
| --------------------- | --- | --------------: | ----------------------------- |
| `load_ia_trigger`     | In  |               1 | 触发一批 IA 加载（单拍脉冲）。             |
| `valid_row_num`       | In  |    ⌈log2(SIZE)⌉ | 本 Tile 有效行数。                  |
| `is_last_tile`        | In  |               1 | 最后 Tile 标志（供尾处理逻辑）。           |
| `ia_wr_addr/ia_wr_en` | In  | ⌈log2(SIZE²)⌉/1 | 写入双缓冲区的地址/使能。                 |
| `ia_data_in`          | In  |     `BUS_WIDTH` | 总线读回的 IA 原始数据。                |
| `lhs_offset`          | In  |             s32 | 输入零点。                         |
| `ia_use_offset`       | In  |               1 | 1：执行 `IA := IA - lhs_offset`。 |
| `use_16bits`          | In  |               1 | 1：IA 以 16bit 进入阵列。            |
| `ia_out[SIZE]`        | Out |    `DATA_WIDTH` | 并行输出至 `data_setup`。           |
| `ia_row_valid`        | Out |               1 | 一行 IA 数据有效（与输出同步）。            |
| `ia_calc_done`        | Out |               1 | 本批次 IA 输出完毕（最后一行时有效）。         |
| `ia_loading_done`     | Out |               1 | IA 预取完成，可进入计算阶段。              |
| `buffer_switch_req`   | Out |               1 | 请求缓冲区切换（内部状态指示）。              |

**操作约定**

**双缓冲区交替运行机制**

* **缓冲区设计**：内部采用双缓冲区（buffer0/buffer1），每个缓冲区可存储 `SIZE×SIZE` 个 `DATA_WIDTH` 位数据
* **交替工作模式**：
  - 缓冲区A输出数据到脉动阵列时，缓冲区B可同时接收控制器写入的新数据
  - 输出完成后角色切换：原输出缓冲区转为接收态，原接收缓冲区转为输出态
  - 实现数据加载与输出的流水线重叠，提高吞吐率

**触发与配置锁存**

* **load_ia_trigger 处理**：
  - 单拍有效的触发信号，每次触发时锁存当前 `valid_row_num` 和 `is_last_tile`
  - 锁存的参数用于控制后续数据输出的行数和尾处理逻辑
  - 触发后启动当前接收缓冲区的数据写入流程

**行数据输出时序**

* **逐行输出**：按锁存的 `valid_row_num` 逐行输出 IA 向量到 `ia_out[SIZE]`
* **同步信号**：每行输出时同步拉高 `ia_row_valid`，指示当前行数据有效
* **边界处理**：超出 `valid_row_num` 的行位置输出零向量，ia_row_valid保持低电平

**最后Tile处理与完成信号**

* **ia_calc_done 生成**：
  - 仅在输出最后一行数据时检查锁存的 `is_last_tile` 标志
  - 若为最后Tile，与最后一行的 `ia_row_valid` 同拍拉高 `ia_calc_done`
  - 通知下游进行部分和累加以获得最终结果

* **ia_loading_done 时机**：当前批次所有有效行数据预取到缓冲区完成时拉高

**零点补偿与数据格式**

* **零点处理**：`ia_use_offset=1` 时，在数据输出前执行 `IA := IA - lhs_offset`
* **位宽适配**：根据 `use_16bits` 选择 16bit 或 8bit 输出路径
* **数值范围**：确保零点补偿后数据在 `s16` 动态范围内，避免溢出

**缓冲区管理策略**

* **切换条件**：当前输出缓冲区所有有效行输出完毕后触发切换
* **写入保护**：正在输出的缓冲区禁止写入，避免数据竞争
* **状态同步**：`buffer_switch_req` 向控制器指示缓冲区状态变化

---

## 5. 数据对齐：`data_setup`

**端口**

| 端口               | 方向  |           位宽 | 描述                    |
| ---------------- | --- | -----------: | --------------------- |
| `data_in[SIZE]`  | In  | `DATA_WIDTH` | 来自 `ia_loader` 的并行矢量。 |
| `input_valid_i`  | In  |            1 | 有效行到达。                |
| `calc_done_i`    | In  |            1 | IA 批次完成。              |
| `data_out[SIZE]` | Out | `DATA_WIDTH` | 对齐后送阵列的矢量。            |
| `input_valid_o`  | Out |            1 | 延迟对齐后的有效信号。           |
| `calc_done_o`    | Out |            1 | 延迟对齐后的完成信号。           |

**操作约定**

* 仅用于管线对齐/级联延迟补偿；不改变数值。

---

## 6. 脉动阵列：`ws_systolic_array`

**端口**

| 端口                 | 方向  |             位宽 | 描述                              |
| ------------------ | --- | -------------: | ------------------------------- |
| `store_weight_req` | In  |              1 | 锁存当前 `weight_in` 至各 PE 的本地权重寄存。 |
| `weight_in[SIZE]`  | In  | `WEIGHT_WIDTH` | 列向并行权重流。                        |
| `data_in[SIZE]`    | In  |   `DATA_WIDTH` | 行向并行 IA 流。                      |
| `sum_out[SIZE]`    | Out |            s32 | 每列的部分和/累加输出。                    |

**操作约定**

* Weight‑Stationary：权重在 PE 内保持静止，IA 沿行推进，部分和沿列推进。
* 边界屏蔽：对无效行/列输入零或门控 PE 以抑制贡献。

---

## 7. 累加阵列：`accumulator_array`

**端口**

| 端口                             | 方向  |           位宽 | 描述                                           |
| ------------------------------ | --- | -----------: | -------------------------------------------- |
| `data_in[SIZE]`                | In  |          s32 | 来自阵列的列向部分和。                                  |
| `input_valid_i`                | In  |            1 | 有效数据入列。                                      |
| `calc_done_i`                  | In  |            1 | 本批次流结束。                                      |
| `valid_depth_i`                | In  | ⌈log2(SIZE)⌉ | 有效深度（K 方向或阵列流水深）。                            |
| `is_init_data_i`               | In  |            1 | 1：本 Tile 首次写；0：继续累加（K 分块）。                   |
| `data_out[SIZE]`               | Out |          s32 | 输出到 `bias_adder`。                            |
| `calc_done_o`                  | Out |            1 | 本 Tile 累加完成。                                 |
| `tile_calc_over_o`             | Out |            1 | 累加阵列指示本 Tile 计算结束的单拍脉冲，连接到 `mma_controller`。 |
| `valid_depth_o/is_init_data_o` | Out |            - | 同步透传给下游需要的边界信息。                              |

**操作约定**
* **tile_calc_over_o 生成**：当累加阵列完成当前 Tile 的所有行/列累加后，输出单拍脉冲 `tile_calc_over_o`，供 `mma_controller` 识别 Tile 级别的脉动阵列运算结束，可以加载新的权重进入脉动阵列了。
* `is_init_data_i=1` 时清零累加寄存；否则叠加（支持 K 方向分块）。

---

## 8. 加偏置：`bias_adder`

**端口**

| 端口                                         | 方向  |             位宽 | 描述                         |
| ------------------------------------------ | --- | -------------: | -------------------------- |
| `init_bias_cfg`                            | In  |              1 | 初始化/装载 bias 的阶段标志。         |
| `need_bias`                                | In  |              1 | 1：加 bias；0：透传。             |
| `bias_data_in`                             | In  |    `BUS_WIDTH` | 从内存读回的 s32 bias 数据（或按列分发）。 |
| `bias_wr_addr/bias_wr_en`                  | In  | ⌈log2(SIZE)⌉/1 | 写入内部 bias 缓冲。              |
| `valid_row_num`                            | In  |   ⌈log2(SIZE)⌉ | 有效输出行数（用于屏蔽）。              |
| `data_in[SIZE]`                            | In  |            s32 | 来自累加阵列。                    |
| `calc_done_i/valid_depth_i/is_init_data_i` | In  |              - | 同步边界信号。                    |
| `data_out[SIZE]`                           | Out |            s32 | 加偏置后的结果。                   |
| `output_valid_o`                           | Out |              1 | 有效输出到 Requant。             |
| `valid_depth_o/is_init_data_o`             | Out |              - | 透传边界信息。                    |

**操作约定**

* 按输出通道（列）对齐 bias；`need_bias=0` 时直通。边界行屏蔽无效写。

---

## 9. 向量重量化：`vec_requant`

**端口**

| 端口                             | 方向  |          位宽 | 描述                                        |
| ------------------------------ | --- | ----------: | ----------------------------------------- |
| `cfg_load_common`              | In  |           1 | 装载通用量化参数（激活阈值、dst_offset、per‑tensor量化参数）。 |
| `cfg_per_channel`              | In  |           1 | 1：使用 per‑channel；0：per‑tensor。            |
| `activation_min_in/max_in`     | In  |          32 | s8 输出范围的下/上限。                             |
| `dst_offset_in`                | In  |          32 | 输出零点。                                     |
| `pt_multiplier_in/pt_shift_in` | In  |       32/32 | per‑tensor 乘数/右移（算术）。                     |
| `pc_multiplier_in/pc_shift_in` | In  |       32/32 | per‑channel 乘数/右移（逐通道写入）。                 |
| `cfg_init_quant`               | In  |           1 | 进入量化参数接收态（per‑channel时连续写入16个参数对）。        |
| `in_valid/in_vec_s32[SIZE]`    | In  | 1 / SIZE×32 | 来自 bias\_adder 的向量输入。                     |
| `out_valid/out_vec_s8[SIZE]`   | Out |  1 / SIZE×8 | 量化后 s8 向量。                                |
| `done`                         | Out |           1 | 一次向量处理完成标志。                               |

**操作约定**

**量化算法（兼容 CMSIS-NN/NMSIS-NN）**

* 量化公式（逐元素）：
  ```
  temp = (x << left_shift) * multiplier
  y_scaled = (temp + round_offset) >> right_shift
  y = clamp(act_min, act_max, y_scaled + dst_offset)
  ```
  其中 `left_shift` 通常为 0，`round_offset = 1 << (right_shift - 1)` 用于四舍五入。

**配置机制**

* **初始化序列**：
  1. `cfg_load_common` 拉高 1 拍：装载 `activation_min/max_in` 和 `dst_offset_in`
     - 若 `cfg_per_channel=0`：同时装载 `pt_multiplier_in/pt_shift_in`
  2. 若 `cfg_per_channel=1`：
     - `cfg_init_quant` 拉高后，连续 16 拍提供 `pc_multiplier_in[0..15]/pc_shift_in[0..15]`
     - 每拍写入一个通道的量化参数对
  3. 初始化完成后，模块进入就绪态，可接收数据流

* **参数更新**：per‑channel 模式下，控制器可在输出列切换时重新执行步骤 2

**数据处理流程**

* `in_valid=1` 时锁存 16 路 s32 输入向量
* 下一拍并行执行 16 路量化计算：
  - 左移预处理（可选）
  - 乘法器取高位（32×32→32 高位）
  - 右移四舍五入
  - 加零点偏移
  - 激活裁剪至 [-128, 127] 或用户指定范围
* `out_valid=1` 与量化结果同时输出
* `done=1` 指示本次向量处理完成（单拍脉冲）

**边界与特殊情况处理**

* **饱和保护**：中间计算溢出时饱和到 s32 边界
* **零移位处理**：`shift=0` 时跳过移位操作
* **无效通道**：根据 `valid_col_num` 屏蔽无效输出通道
* **流水线对齐**：保证 `in_valid` 到 `out_valid` 的固定延迟（1 拍）

---

## 10. 向量到 FIFO：`vec_s8_to_fifo`

**端口**

| 端口                          | 方向     |           位宽 | 描述                         |
| --------------------------- | ------ | -----------: | -------------------------- |
| `in_valid/in_vec_s8[SIZE]`  | In     |   1 / SIZE×8 | 来自 Requant 的 s8 向量。        |
| `output_req/req_ack`        | In/Out |            1 | 控制器发起出队请求；模块应在准备好一拍内应答。    |
| `vec_valid_num_col`         | In     | ⌈log2(SIZE)⌉ | 有效列数，用于边界打包。               |
| `output_valid/output_ready` | Out/In |            1 | 打包好的 32 位数据有效 / 控制器就绪。     |
| `output_mask`               | Out    |            4 | 字节掩码（与 `BUS_WIDTH=32` 对齐）。 |
| `output_data`               | Out    |           32 | 打包数据（最多 4 个 s8）。           |
| `fifo_full_flag`            | Out    |            1 | 内部 FIFO 满，提示控制器节流。         |

**操作约定**

* 以 32bit 为粒度打包（小端序）：`output_mask[i]=1` 表示 `output_data` 的第 `i` 字节有效。
* 边界列（非 4 对齐）依 `vec_valid_num_col` 计算掩码。

---

## 11. ICB LSU 接口（外存访问）

**命令通道**

* `sa_icb_cmd_valid` / `sa_icb_cmd_ready`：握手。
* `sa_icb_cmd_addr`：字节地址。
* `sa_icb_cmd_read`：1=读，0=写。
* `sa_icb_cmd_wdata` / `sa_icb_cmd_wmask`：写数据 / 字节掩码。
* `sa_icb_cmd_size`：传输粒度编码（参考 SoC ICB 规范）。

**响应通道**

* `sa_icb_rsp_valid` / `sa_icb_rsp_ready`：握手。
* `sa_icb_rsp_rdata`：读数据。
* `sa_icb_rsp_err`：错误标志。

**访问约定**

* 控制器负责突发/对齐策略；所有步幅以**字节**计算。
* 读权重/IA/bias 时应考虑 `row_stride_b` 与阵列 `SIZE` 的对齐；写 DST 以 `output_mask` 掩码进行按字节写。

---

## 12. 激活裁剪与数值范围

* `act_min/act_max` 仅在 Requant 后的 s8 域生效。
* 上游 s32 累加溢出由累加器设计保证（建议采用 40bit/饱和保护可配置）。

---

## 13. 边界与异常处理

* **尺寸非整倍数**：以 `valid_row_num/valid_col_num` 与 `vec_valid_num_col` 驱动屏蔽与掩码。
* **无 bias**：`bias_base=0` 或 `need_bias=0` 时，`bias_adder` 直通。
* **kernel\_sum**：保留，用于某些零点补偿方案（例如 TFLM 的 `-lhs_zp * sum(W)`）；若未使用，`ksum_base=0`。
* **总线回压**：ICB `cmd_ready=0` 或 `resp_valid` 延迟时，控制器需暂停新触发，保证数据不丢失。

---

### 术语表

* **WS（Weight‑Stationary）**：权重静止型脉动阵列数据流。
* **Tile**：以 `SIZE×SIZE` 为基的计算分块，边界不足用 `valid_*` 指示。
* **per‑tensor/per‑channel**：重量化参数作用于整张量或每个输出通道。
