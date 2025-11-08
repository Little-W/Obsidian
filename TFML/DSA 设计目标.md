# DSA 规格（Spec v1.0 | GEMM-INT8/INT16×INT8）

# 设计目标

* **兼容 NMSIS-NN 内核**：本 DSA 设计旨在完全兼容 NMSIS-NN 的相关矩阵乘法内核，确保软件接口的一致性。
* **用于 TFLM**：通过集成到 TensorFlow Lite for Microcontrollers (TFLM)，使 TFLM 能够调用我们的加速器进行高效加速，提升嵌入式设备上的推理性能。

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

# 6. 统一执行流程（硬件视角）

对 `m=0..M-1`：

1. 取 LHS 第 m 行 K 元素（**位宽由指令决定**：s8 或 s16；两者均与 `LHS_OFFSET` 相加后再参与乘法）。
2. 对 `n=0..N-1`：读取 RHS 第 n 行 K 个 s8 权重，做 K 次乘加到 32 位累加器；如 `BIAS_PTR!=0`，加 `bias[n]`。
3. Requantize（per-channel 优先，否则 per-tensor），加 `DST_OFFSET`，Clamp 到 `[ACT_MIN, ACT_MAX]`，饱和为 s8 写入 `DST + m*DST_ROW_STRIDE_B + n`。
4. `LHS` 前进 `LHS_ROW_STRIDE_B`；`DST` 前进 `DST_ROW_STRIDE_B`。

> **K 尾部**：若 `K_ALIGNED > K`，超出部分按 0 处理（尾部掩码或零填均可）。

---

# 7. 与三种 API 的参数映射

## 7.1 `riscv_nn_mat_mult_nt_t_s8`

* **指令**选择 LHS=s8。
* **CSR 赋值**：

  * 指针：`LHS_PTR=lhs(s8)`，`RHS_PTR=rhs(s8, N×K)`，`DST_PTR=dst`，`BIAS_PTR=bias or 0`；
    `MULT_DST_MULT_PTR=dst_multipliers`（可选），`MULT_DST_SHIFT_PTR=dst_shifts`（可选）。
  * 尺寸：`M=lhs_rows`，`N=rhs_rows`，`K=rhs_cols`，`K_ALIGNED` 取向量化对齐；
    `RHS_ROW_STRIDE = (K_ALIGNED*1)` 或显式设置；`LHS_ROW_STRIDE` 留 0（自动）或显式设置；
    `ROW_ADDR_OFFSET` 留 0（致密）或显式设置。
  * 量化：`LHS_OFFSET=lhs_offset`，`DST_OFFSET=dst_offset`，`ACT_MIN/MAX`，以及 per-channel/per-tensor 二选一。

## 7.2 `riscv_nn_mat_mult_kernel_s8_s16`

* **指令**选择 LHS=s16。
* **LHS\_OFFSET 仍然参与计算**（与 s8 情况一致）。
* **CSR 赋值**：`LHS_PTR=input_a(s16)`，`RHS_PTR=weight(s8, N×K)`，其余同 7.1。

## 7.3 `riscv_nn_mat_mult_kernel_row_offset_s8_s16`

* 同 7.2，**另行设置** `MULT_ROW_ADDR_OFFSET = row_address_offset`（非 0，启用自定义输出行步距）。