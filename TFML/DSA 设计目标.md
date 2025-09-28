# DSA 规格（Spec v1.0 | GEMM-INT8/INT16×INT8）

* **LHS=ia**（输入/patch）可为 **s8 或 s16**（由指令编码决定）。
* **RHS=weight** 始终为 **s8**（对称量化，零点 0）。
* 之前库里的 “s8×s16” 仅是**转置/交换矩阵位置**造成的语义差异；硬件中**不交换**：始终按 **(M×K)·(K×N)**；仅改变 LHS 元素位宽。

---

# 1. 适用范围（Scope）

* 统一加速下列 NMSIS-NN 内核（通过**同一条 DSA 数据通路**映射）：

  * `riscv_nn_mat_mult_nt_t_s8`（LHS: s8，RHS: s8）
  * `riscv_nn_mat_mult_kernel_s8_s16`（在硬件等价 **LHS: s16，RHS: s8**）
  * `riscv_nn_mat_mult_kernel_row_offset_s8_s16`（同上并启用自定义输出行步进）
* 上层典型：im2col 后端的 Conv / 1×1 Conv / FC。

---

# 2. 维度/符号

* LHS：形状 `M × K`（行主序；一行是一个输出位置/样本的 K 维向量）
* RHS：形状 `K × N`（**存储按 N×K 行主序**，逐行表示每个输出通道的 K 元素；读取等价于 `K×N`）
* DST：形状 `M × N`（行主序）
* 记号：`M=lhs_rows`，`N=output_ch`/`rhs_rows`，`K=num_col_a`/`rhs_cols`

---

# 3. 数据类型与量化约束

| 名称                      | 位宽                | 说明                                                                             |
| ----------------------- | ----------------- | ------------------------------------------------------------------------------ |
| **LHS（ia）**             | **s8 或 s16（可切换）** | 由**指令编码**决定。两种位宽下均应用 `lhs_offset`。                                             |
| **RHS（weight）**         | **s8（固定）**        | 对称量化，权重零点 **0**。                                                               |
| **Bias**                | s32               | per-channel，可为 NULL。                                                           |
| **Multiplier/Shift**    | s32/s32           | per-channel 或 per-tensor。遵循 CMSIS-NN：`doubling_high_mult + rounding >> shift`。 |
| **dst\_offset**         | s32               | 输出零点。                                                                          |
| **activation\_min/max** | s32               | 激活裁剪上下限（之后再饱和到 s8）。                                                            |

> 备注
>
> * RHS 固定对称：不支持 `rhs_offset`（恒 0）。
> * per-channel / per-tensor 的选择由是否提供 `*_PTR` 指针来自动判定（见 §6.3）。

---

# 4. 计算定义

对任意输出元素 `(m,n)`：

1. **累加：**

$$
\text{acc}_{m,n}=\text{bias}[n]+\sum_{k=0}^{K-1}\Big(\underbrace{\text{LHS}[m,k]}_{\text{s8/s16 读入并提升为 s32}}+\text{lhs\_offset}\Big)\cdot \text{RHS}[n,k]
$$

> 硬件读取顺序：LHS 按行取 K 元素；RHS 以 `N×K(s8)` 布局逐行取（每个 `n` 对应一行 K 权重）。

2. **重定标（requantize） + 输出零点：**

$$
s=\mathrm{Requantize}(\text{acc}_{m,n},\ \text{mult}[n\ \text{或}\ 0],\ \text{shift}[n\ \text{或}\ 0]),\quad
t=s+\text{dst\_offset}
$$

3. **裁剪 + 饱和写回：**

$$
u=\min(\text{activation\_max},\max(\text{activation\_min},t)),\ \ \text{DST}[m,n]=\mathrm{sat\_s8}(u)
$$

---

# 5. 内存布局与步进（stride）

* **LHS（A）**：行主序，`LHS_ROW_STRIDE_B`（字节）为相邻两行首地址差。常见：

  * s8：`K * 1`；s16：`K * 2`；也可更大以适配外部 stride/padding。
* **RHS（B）**：行主序，**布局 `N × K`，元素 s8**，每行对应一个输出通道的 K 权重。

  * `RHS_ROW_STRIDE = K_aligned * 1`（可 ≥ `K`；尾部零填或内部屏蔽）。
* **DST（C）**：行主序，`DST_ROW_STRIDE_B`（字节）为相邻两行输出跨度。

  * 常用 `N * 1`；row-offset 版本用于自定义 stride/拼接。
* **K 对齐**：`K_ALIGNED ≥ K`，为向量化读取的上取整（如 8/16/32）。超出 K 的尾部按 0 处理。

---

# 6. CSR/寄存器映射

## 6.1 指针类

|    编号 | 名称                   |  访问 |  复位 | 类型/单位           | 说明                              |
| ----: | -------------------- | :-: | :-: | --------------- | ------------------------------- |
| 0x7C0 | `MULT_LHS_PTR`       |  RW |  0  | u32 / byte addr | A（LHS）基址；元素位宽由**指令**决定（s8/s16）。 |
| 0x7C1 | `MULT_RHS_PTR`       |  RW |  0  | u32 / byte addr | B（RHS）基址；按 **N×K 行主序**，元素 s8。   |
| 0x7C2 | `MULT_DST_PTR`       |  RW |  0  | u32 / byte addr | C（DST）写回基址；元素 s8。               |
| 0x7C3 | `MULT_BIAS_PTR`      |  RW |  0  | u32 / byte addr | Bias（s32）数组；可为 0（无 bias）。       |
| 0x7C4 | `MULT_DST_MULT_PTR`  |  RW |  0  | u32 / byte addr | per-channel 量化乘子数组（s32）；非 0 生效。 |
| 0x7C5 | `MULT_DST_SHIFT_PTR` |  RW |  0  | u32 / byte addr | per-channel 量化右移数组（s32）；非 0 生效。 |

## 6.2 尺寸/步进

|    编号 | 名称                     |  访问 |  复位 | 类型/单位           | 说明                                           |
| ----: | ---------------------- | :-: | :-: | --------------- | -------------------------------------------- |
| 0x7C6 | `MULT_RHS_COLS`        |  RW |  0  | u32             | `K`（B 的列数/内积长度）。                             |
| 0x7C7 | `MULT_RHS_ROWS`        |  RW |  0  | u32             | `N`（B 的行数/输出通道数）。                            |
| 0x7C8 | `MULT_LHS_ROWS`        |  RW |  0  | u32             | `M`（A 的行数；`vec_mat_t` 可为 1）。                 |
| 0x7C9 | `MULT_OUT_CH`          |  RW |  0  | u32             | 输出通道数（兼容域；通常与 `N` 相等）。                       |
| 0x7CA | `MULT_NUM_COL_A`       |  RW |  0  | u32             | A 展平后列数（等价 `K`）。                             |
| 0x7CB | `MULT_ALIGNED_COL_A`   |  RW |  0  | u32             | 对齐后的 K（如 8/16/32；**必须 ≥ K**）。                |
| 0x7CC | `MULT_ROW_ADDR_OFFSET` |  RW |  0  | u32 / byte step | 输出行写回步距（row stride；字节）。0 表示使用致密行步距 `N*1` 字节。 |
| 0x7CD | `MULT_LHS_COLS_OFFSET` |  RW |  0  | u32 / byte step | A 行步距（相邻行首地址差；字节）。0 表示自动：s8→`K*1`，s16→`K*2`。 |
| 0x7CE | `MULT_RHS_ROW_STRIDE`  |  RW |  0  | u32 / byte step | B 行步距（通常设为 `K_aligned * 1` 字节）。0 表示按该默认值推导。  |

## 6.3 量化/激活/类型

|    编号 | 名称                |  访问 |  复位 | 类型/单位 | 说明                                              |
| ----: | ----------------- | :-: | :-: | ----- | ----------------------------------------------- |
| 0x7CF | `MULT_LHS_OFFSET` |  RW |  0  | s32   | **A 的零点偏移（lhs\_offset）**；**s8/s16 两种位宽下均参与计算**。 |
| 0x7D0 | `MULT_RHS_OFFSET` |  RW |  0  | s32   | **B 的零点偏移（rhs\_offset）**；通常为 0（对称量化），预留扩展。 |
| 0x7D1 | `MULT_DST_OFFSET` |  RW |  0  | s32   | 输出零点（dst\_offset）。                              |
| 0x7D2 | `MULT_DST_MULT`   |  RW |  0  | s32   | per-tensor 量化乘子（当 `*_PTR` 为 0 时广播使用）。           |
| 0x7D3 | `MULT_DST_SHIFT`  |  RW |  0  | s32   | per-tensor 量化右移（写正数=右移；当 `*_PTR` 为 0 时广播使用）。    |
| 0x7D4 | `MULT_ACT_MIN`    |  RW |  0  | s32   | 激活下限。                                           |
| 0x7D5 | `MULT_ACT_MAX`    |  RW |  0  | s32   | 激活上限（需满足 `ACT_MIN ≤ ACT_MAX`）。                  |

**自动选择规则（无额外 CFG 位）：**

* **per-channel / per-tensor**：当 `MULT_DST_MULT_PTR` 与 `MULT_DST_SHIFT_PTR` **均非 0** 时，使用 per-channel；否则使用 `MULT_DST_MULT/SHIFT`（per-tensor 广播）。
* **输出行步距**：`MULT_ROW_ADDR_OFFSET==0` → 使用致密 `N*1` 字节；非 0 → 使用该值。
* **LHS 行步距**：`MULT_LHS_COLS_OFFSET==0` → 自动推导（s8→`K*1`；s16→`K*2`）；非 0 → 使用该值。
* **RHS 行步距**：`MULT_RHS_ROW_STRIDE==0` → 使用 `K_aligned * 1`；非 0 → 使用该值。

---

# 7. 统一执行流程（硬件视角）

对 `m=0..M-1`：

1. 取 LHS 第 m 行 K 元素（**位宽由指令决定**：s8 或 s16；两者均与 `LHS_OFFSET` 相加后再参与乘法）。
2. 对 `n=0..N-1`：读取 RHS 第 n 行 K 个 s8 权重，做 K 次乘加到 32 位累加器；如 `BIAS_PTR!=0`，加 `bias[n]`。
3. Requantize（per-channel 优先，否则 per-tensor），加 `DST_OFFSET`，Clamp 到 `[ACT_MIN, ACT_MAX]`，饱和为 s8 写入 `DST + m*DST_ROW_STRIDE_B + n`。
4. `LHS` 前进 `LHS_ROW_STRIDE_B`；`DST` 前进 `DST_ROW_STRIDE_B`。

> **K 尾部**：若 `K_ALIGNED > K`，超出部分按 0 处理（尾部掩码或零填均可）。

---

# 8. 与三种 API 的参数映射

## 8.1 `riscv_nn_mat_mult_nt_t_s8`

* **指令**选择 LHS=s8。
* **CSR 赋值**：

  * 指针：`LHS_PTR=lhs(s8)`，`RHS_PTR=rhs(s8, N×K)`，`DST_PTR=dst`，`BIAS_PTR=bias or 0`；
    `MULT_DST_MULT_PTR=dst_multipliers`（可选），`MULT_DST_SHIFT_PTR=dst_shifts`（可选）。
  * 尺寸：`M=lhs_rows`，`N=rhs_rows`，`K=rhs_cols`，`K_ALIGNED` 取向量化对齐；
    `RHS_ROW_STRIDE = (K_ALIGNED*1)` 或显式设置；`LHS_ROW_STRIDE` 留 0（自动）或显式设置；
    `ROW_ADDR_OFFSET` 留 0（致密）或显式设置。
  * 量化：`LHS_OFFSET=lhs_offset`，`DST_OFFSET=dst_offset`，`ACT_MIN/MAX`，以及 per-channel/per-tensor 二选一。

## 8.2 `riscv_nn_mat_mult_kernel_s8_s16`

* **指令**选择 LHS=s16。
* **LHS\_OFFSET 仍然参与计算**（与 s8 情况一致）。
* **CSR 赋值**：`LHS_PTR=input_a(s16)`，`RHS_PTR=weight(s8, N×K)`，其余同 8.1。

## 8.3 `riscv_nn_mat_mult_kernel_row_offset_s8_s16`

* 同 8.2，**另行设置** `MULT_ROW_ADDR_OFFSET = row_address_offset`（非 0，启用自定义输出行步距）。