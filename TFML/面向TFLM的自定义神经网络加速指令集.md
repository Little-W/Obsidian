# AI-DSA（TFLM 矩阵/向量基础单元）CSR 规范（v1.0 Draft）

> 本规范仅定义**控制/参数类 CSR**，严格对应函数入参；**不承载中间结果或控制状态**。后续计算由统一脉动阵列完成。  
> 平台：RV32，小端（Little-Endian）。

---

## 1 术语与约定

- **CSR 编号**：遵循 RISC-V CSR 12 位编号空间，本规范将本组件 CSR 统一放置在实现定义范围（建议：`0x7C0` 起，连续分配）。
    
- **访问宽度**：32-bit 对齐，读写均为 **原子 32 位**。
    
- **重置值**：除注明外均为 `0x0000_0000`。
    
- **时序语义**：写入在 **同一指令退休后**对随后的计算可见；读无副作用。
    
- **异常处理**：对未实现/保留 CSR 编号写入或读取 → **非法指令异常**。
    

---

## 2 访问指令

为避免与全局 CSR 空间混淆，定义两条**自定义 CSR 访问指令**（使用 `custom-1` 主 opcode；示例编码，实际以实现为准）：

- **写 CSR**：`csrwr rs1, imm12`  
    语义：`CSR[imm12] ← (uint32)rs1`  
    约束：仅使用 `rs1`；`imm12` 为 CSR 编号。
    
- **读 CSR**：`csrrd rd, imm12`  
    语义：`rd ← (uint32)CSR[imm12]`  
    约束：仅写 `rd`；`imm12` 为 CSR 编号。
    

> 工具链封装（示例）：

```c
#define CSR_WR(id, val) __asm__ volatile (".insn i CUSTOM_1, 0x2, x0, %0, %1" :: "r"(val), "i"(id))
#define CSR_RD(id, out) __asm__ volatile (".insn i CUSTOM_1, 0x4, %0, x0, %1" : "=r"(out) : "i"(id))
```

---

## 3 地址映射（Register Map）

### 3.1 MULT（矩阵/向量×矩阵）参数 CSR

|    编号 | 名称                     | 访问  | 复位  | 描述                                |
| ----: | ---------------------- | :-: | :-: | --------------------------------- |
| 0x7C0 | `MULT_LHS_PTR`         | RW  |  0  | `lhs` 输入指针（字节地址）                  |
| 0x7C1 | `MULT_RHS_PTR`         | RW  |  0  | `rhs` 输入指针（字节地址）                  |
| 0x7C2 | `MULT_DST_PTR`         | RW  |  0  | `dst` 输出指针（字节地址）                  |
| 0x7C3 | `MULT_BIAS_PTR`        | RW  |  0  | `bias` 指针（可为 NULL=0）              |
| 0x7C4 | `MULT_KSUM_PTR`        | RW  |  0  | `kernel_sum` 指针（可为 NULL=0）        |
| 0x7C5 | `MULT_LHS_OFFSET`      | RW  |  0  | `lhs_offset`（s32）                 |
| 0x7C6 | `MULT_RHS_OFFSET`      | RW  |  0  | `rhs_offset`（s32）                 |
| 0x7C7 | `MULT_DST_OFFSET`      | RW  |  0  | `dst_offset`（s32）                 |
| 0x7C8 | `MULT_DST_MULT`        | RW  |  0  | per-tensor `dst_multiplier`（s32）  |
| 0x7C9 | `MULT_DST_SHIFT`       | RW  |  0  | per-tensor `dst_shift`（s32，右移写正）  |
| 0x7CA | `MULT_DST_MULT_PTR`    | RW  |  0  | per-channel `dst_multiplier` 数组指针 |
| 0x7CB | `MULT_DST_SHIFT_PTR`   | RW  |  0  | per-channel `dst_shift` 数组指针      |
| 0x7CC | `MULT_RHS_COLS`        | RW  |  0  | `rhs_cols`（K 维长度）                 |
| 0x7CD | `MULT_RHS_ROWS`        | RW  |  0  | `rhs_rows`（O 维长度，或 B 的行数）         |
| 0x7CE | `MULT_LHS_ROWS`        | RW  |  0  | `lhs_rows`（A 的行数，nt_t 用）          |
| 0x7CF | `MULT_OUT_CH`          | RW  |  0  | `output_ch`（s8×s16 内核用）           |
| 0x7D0 | `MULT_NUM_COL_A`       | RW  |  0  | `num_col_a`（A 展平后 K）              |
| 0x7D1 | `MULT_ALIGNED_COL_A`   | RW  |  0  | `aligned_num_col_a`（对齐后的 K）       |
| 0x7D2 | `MULT_MULT_PTR`        | RW  |  0  | `out_mult` 数组指针（s8×s16 内核）        |
| 0x7D3 | `MULT_SHIFT_PTR`       | RW  |  0  | `out_shift` 数组指针（s8×s16 内核）       |
| 0x7D4 | `MULT_ROW_ADDR_OFFSET` | RW  |  0  | `row_address_offset`（行写回步距）       |
| 0x7D5 | `MULT_LHS_COLS_OFFSET` | RW  |  0  | `lhs_cols_offset`（nt_t 左矩阵列步距）    |
| 0x7D6 | `MULT_ACT_MIN`         | RW  |  0  | 激活下限（s32，最终裁剪到 s8）                |
| 0x7D7 | `MULT_ACT_MAX`         | RW  |  0  | 激活上限（s32，最终裁剪到 s8）                |

### 3.2 VMAX（向量最大）参数 CSR

|    编号 | 名称              | 访问  | 复位  | 描述          |
| ----: | --------------- | :-: | :-: | ----------- |
| 0x7E0 | `VMAX_VEC0_PTR` | RW  |  0  | 输入 0 指针     |
| 0x7E1 | `VMAX_VEC1_PTR` | RW  |  0  | 输入 1 指针     |
| 0x7E2 | `VMAX_DST_PTR`  | RW  |  0  | 输出指针        |
| 0x7E3 | `VMAX_LEN`      | RW  |  0  | 元素个数（单位：s8） |

### 3.3 Depthwise Conv（深度可分卷积）参数 CSR

|    编号 | 名称              | 访问  | 描述                        |
| ------: | ----------------- | :---: | --------------------------- |
|  0x7F0  | `DW_IN_PTR`       | RW    | 输入指针 (s8)               |
|  0x7F1  | `DW_KER_PTR`      | RW    | Kernel 指针 (s8)            |
|  0x7F2  | `DW_BIAS_PTR`     | RW    | Bias 指针 (s32，可为 0)     |
|  0x7F3  | `DW_OUT_PTR`      | RW    | 输出指针 (s8)               |
|  0x7F4  | `DW_IN_X`         | RW    | 输入宽                      |
|  0x7F5  | `DW_IN_Y`         | RW    | 输入高                      |
|  0x7F6  | `DW_IN_CH`        | RW    | 输入通道数                  |
|  0x7F7  | `DW_OUT_CH`       | RW    | 输出通道数                  |
|  0x7F8  | `DW_CH_MULT`      | RW    | 通道倍数 (ch_mult)          |
|  0x7F9  | `DW_KER_X`        | RW    | Kernel 宽                   |
|  0x7FA  | `DW_KER_Y`        | RW    | Kernel 高                   |
|  0x7FB  | `DW_PAD_X`        | RW    | Padding X                   |
|  0x7FC  | `DW_PAD_Y`        | RW    | Padding Y                   |
|  0x7FD  | `DW_STRIDE_X`     | RW    | 步幅 X                      |
|  0x7FE  | `DW_STRIDE_Y`     | RW    | 步幅 Y                      |
|  0x7FF  | `DW_SHFT_PTR`     | RW    | output_shift 数组指针        |
|  0x800  | `DW_MULT_PTR`     | RW    | output_mult 数组指针         |
|  0x801  | `DW_OUT_X`        | RW    | 输出宽                      |
|  0x802  | `DW_OUT_Y`        | RW    | 输出高                      |
|  0x803  | `DW_OUT_OFFS`     | RW    | 输出 offset                  |
|  0x804  | `DW_IN_OFFS`      | RW    | 输入 offset                  |
|  0x805  | `DW_ACT_MIN`      | RW    | 激活下限                     |
|  0x806  | `DW_ACT_MAX`      | RW    | 激活上限                     |

### 3.4 VSUM（向量累加）参数 CSR

|    编号 | 名称              | 访问  | 描述                        |
| ------: | ----------------- | :---: | --------------------------- |
|  0x808  | `VSUM_BUF_PTR`    | RW    | 输出缓冲指针 (s32)          |
|  0x809  | `VSUM_COLS`       | RW    | 列数                        |
|  0x80A  | `VSUM_ROWS`       | RW    | 行数                        |
|  0x80B  | `VSUM_DATA_PTR`   | RW    | 输入向量指针 (s8)           |
|  0x80C  | `VSUM_LHS_OFFS`   | RW    | lhs_offset                  |
|  0x80D  | `VSUM_RHS_OFFS`   | RW    | rhs_offset                  |
|  0x80E  | `VSUM_BIAS_PTR`   | RW    | bias_data 指针              |

> **备注**：以上编号为建议分配；实现可在同一窗口内重映射，但应保持**连续且稳定**，并在实现文档中声明。

---

## 4 字段定义与语义

上述 CSR 全为**整寄存器字段（32 位）**，不再拆分位域。语义遵循对应 NMSIS-NN/TFLM 参数：

- **指针类**：写入**字节地址**（对齐与安全性由软件保证）。指针可为 0 表示未使用/禁用（例如 `bias_ptr=0` 表示无偏置）。
    
- **offset/mult/shift**：按 NMSIS-NN 定义解释（`shift` 为右移写正；内部实现负移位→左移不建议暴露）。
    
- **激活阈值**：`ACT_MIN ≤ ACT_MAX`；若 `ACT_MIN/ACT_MAX` 均为 0，表示**不额外裁剪**（实现可约定保留值）。
    
- **长度/维度**：软件需保证与数据布局一致（例如 `rhs_cols` 为 K，`rhs_rows` 为 O）。
    

---

## 5 复位与一致性

- **硬复位**：所有 CSR 清零（`0x0000_0000`）。
    
- **一致性**：软件在提交一组参数后，应在**启动计算前**完成所有相关 CSR 写入；写入顺序由软件自定，但应避免与正在进行的计算并发写入同一 CSR。
    
- **可见性**：同核内，`csrwr` 的结果在该指令退休后可被后续取数逻辑观察到；跨核/外设同步不在本规范范围内。
    

---

## 6 非法访问与错误处理

- 访问未实现 CSR 编号或只读 CSR 的写：**非法指令异常**。
    
- 访问保留地址：**非法指令异常**。
    
- 写入导致内部参数溢出/不一致（如 `ACT_MIN > ACT_MAX`）：实现可
    
    - 选择**硬件钳制**（例如交换或截断），或
        
    - 置位内部错误并在任务提交时拒绝启动（建议返回错误码的上层 API 负责检查）。  
        本规范不强制，要求实现文档中**明确行为**。
        

---

## 7 安全与特权

- 推荐仅 **M 模式**允许访问；如需 S/U 访问，应在平台安全策略中定义相应白名单（如通过 SBI 调用或 MMIO 网关代理）。
    
- 指针参数可能指向任意内存区域，软件应确保：
    
    - 访问范围合法；
        
    - 与 DMA/缓存一致性处理妥当（若使用）。  
        违反该前置条件引发的行为为 **UNDEFINED**。
        

---

## 8 版本与兼容性

- 建议在 SoC 顶层或独立只读 CSR 暴露**实现版本**与**能力位图**（本规范不强制）。
    
- 添加新参数时应**追加编号**，不更改现有编号语义；删除参数应保留编号为 **保留** 状态。
    

---

## 9 典型使用流程（信息性）

以 `riscv_nn_vec_mat_mult_t_per_ch_s8()` 为例（per-channel 量化）：

```c
// 1) 写入指针与标量参数
CSR_WR(0x7C0, (uint32_t)lhs);
CSR_WR(0x7C1, (uint32_t)rhs);
CSR_WR(0x7C2, (uint32_t)dst);
CSR_WR(0x7C3, (uint32_t)bias);       // 可为0
CSR_WR(0x7C4, (uint32_t)kernel_sum); // 可为0

CSR_WR(0x7C5, lhs_offset);
CSR_WR(0x7C6, rhs_offset);
CSR_WR(0x7C7, dst_offset);
CSR_WR(0x7D6, activation_min);
CSR_WR(0x7D7, activation_max);

// 2) 写入维度与数组指针
CSR_WR(0x7CC, rhs_cols);
CSR_WR(0x7CD, rhs_rows);
CSR_WR(0x7CA, (uint32_t)dst_multiplier); // per-ch
CSR_WR(0x7CB, (uint32_t)dst_shift);      // per-ch

// 3) 之后通过“任务提交/启动指令”（由计算单元定义，非本 CSR 规范部分）触发执行
```

---

## 10 兼容的函数族（信息性）

- `riscv_nn_vec_mat_mult_t_s8`（per-tensor）：使用 `MULT_DST_MULT`/`MULT_DST_SHIFT`；忽略 per-channel 指针。
    
- `riscv_nn_vec_mat_mult_t_per_ch_s8`：使用 `MULT_DST_MULT_PTR`/`MULT_DST_SHIFT_PTR`。
    
- `riscv_nn_mat_mult_kernel_row_offset_s8_s16`：使用 `MULT_OUT_CH`、`MULT_NUM_COL_A`、`MULT_ALIGNED_COL_A`、`MULT_ROW_ADDR_OFFSET`、`MULT_MULT_PTR`、`MULT_SHIFT_PTR` 等。
    
- `riscv_nn_mat_mult_kernel_s8_s16`：同上但不使用 `MULT_ROW_ADDR_OFFSET`。
    
- `riscv_nn_mat_mult_nt_t_s8`：使用 `MULT_LHS_ROWS`、`MULT_RHS_ROWS`、`MULT_RHS_COLS`、`MULT_LHS_COLS_OFFSET` 等。
    
- `vec_max_s8`：使用 `VMAX_*` 组。
    

---

### 附录 A：对照速查（函数→必需 CSR）

- **per-tensor**：`LHS_PTR`，`RHS_PTR`，`DST_PTR`，`BIAS_PTR?`，`KSUM_PTR?`，`LHS_OFFSET`，`RHS_OFFSET?`，`DST_OFFSET`，`DST_MULT`，`DST_SHIFT`，`RHS_COLS`，`RHS_ROWS`，`ACT_MIN/MAX`，`（必要时）ROW_ADDR_OFFSET/LHS_COLS_OFFSET/NUM_COL_A/ALIGNED_COL_A`。
    
- **per-channel**：将 `DST_MULT/DST_SHIFT` 换成 `DST_MULT_PTR/DST_SHIFT_PTR`；其余同上。
    
- **s8×s16 内核**：增加 `OUT_CH`、`MULT_PTR`、`SHIFT_PTR`。
    
- **VMAX**：`VMAX_VEC0_PTR/VMAX_VEC1_PTR/VMAX_DST_PTR/VMAX_LEN`。

# 运算类自定义指令规范（v1.0 Draft）

> 目标：为 TFLM/NMSIS-NN 的基础算子提供最小且稳定的 **I-type** 自定义指令集合。
> 约束：**仅编码数据位宽**于 `imm12`，其余所有“函数入参”（指针、尺寸、步距、量化数组等）均由前文定义的 CSR（如 `MULT_*`、`DW_*`、`VSUM_*`、`VMAX_*`）提供。
> 统一约定：**`rs1` 为输出数据的起始地址（byte pointer）**；**`rd` 返回状态码**。

---

## 1. 通用规范

* **指令格式**：RISC-V **I-type**（`imm[11:0] | rs1 | funct3 | rd | opcode`）
* **数据端约定**

  * `rs1`（下文简称 **`rs`**）：输出缓冲区地址（若实现允许，也可约定 `rs=0` 使用 CSR 中的 DST\_PTR，非 0 优先 `rs`）
  * `rd`：返回 32 位**状态码**（`0`=成功；非 0=错误；具体值见 §5）
* **立即数字段（sub\_conf）**：`imm12` 仅定义**位宽配置**（见 §2），**不得承载循环步长、布局子类等信息**
* **一致性**：软件必须在发起指令前完成所有相关 CSR 写入；实现需保证**指令退休后**已观察到最新 CSR 值
* **异常**：非法 opcode/funct 组合、无效位宽编码、关键 CSR 缺失等应返回非 0 状态码；必要时可触发非法指令异常（实现自定）

---

## 2. `imm12`（sub\_conf）字段定义（统一）

所有运算类指令**共用**以下 `imm12` 位域；若某字段与该指令无关，**实现可忽略**但不得误用。

| 位段          | 名称       | 编码                    | 含义                                                                    |
| ----------- | -------- | --------------------- | --------------------------------------------------------------------- |
| `imm[11:9]` | `RSV`    | `000`                 | 保留，必须写 0                                                              |
| `imm[8:7]`  | `A_W`    | `00/01/10`            | 左乘数位宽：`00=s4`, `01=s8`, `10=s16`，`11=保留`                              |
| `imm[6:5]`  | `B_W`    | `00/01/10`            | 右乘数位宽：`00=s4`, `01=s8`, `10=s16`，`11=保留`                              |
| `imm[4:3]`  | `BIAS_W` | `00/01/10/11`         | 偏置位宽：`00=s8`, `01=s16`, `10=s32`, `11=s64`                            |
| `imm[2:0]`  | `OUT_W`  | `000/001/010/011/100` | 输出位宽：`000=s4`, `001=s8`, `010=s16`, `011=s32`, `100=s64`；`101~111=保留` |

> **乘数位宽完整组合（A\_W×B\_W）**： 3×3 = 9 组
> `{s4,s8,s16} × {s4,s8,s16}` = `{s4*s4, s4*s8, s4*s16, s8*s4, s8*s8, s8*s16, s16*s4, s16*s8, s16*s16}`
> 不支持的组合可返回错误码（见 §5），ABI 不变。

---

## 3. 指令列表与编码（建议编码；实现可等价选择）

为简化译码，**每条指令占用一个 custom 主 opcode**；`funct3` 统一为 `0b110`（需 `rd` 与 `rs1`），便于工具链内联。

| 指令助记       | 语法                       | `opcode`（建议） | `funct3` | 语义摘要                                                                   |
| ---------- | ------------------------ | ------------ | -------- | ---------------------------------------------------------------------- |
| `mat_mult` | `mat_mult rd, rs, imm12` | `CUSTOM_1`   | `110`    | **矩阵/向量×矩阵**：乘加 → +bias → requant → +dst\_offset → 激活裁剪 → **写回到 `rs`** |
| `dwconv`   | `dwconv   rd, rs, imm12` | `CUSTOM_2`   | `110`    | **Depthwise Conv（mult\_4）**：按 DW\_\* CSR 计算 → **写回 `rs`**              |
| `vsum`     | `vsum     rd, rs, imm12` | `CUSTOM_3`   | `110`    | **向量列/行和**（按 VSUM\_\* CSR）→ **写回 `rs`**                                |
| `vmax`     | `vmax     rd, rs, imm12` | `CUSTOM_0`   | `110`    | **逐元素 max**（按 VMAX\_\* CSR）→ **写回 `rs`**                               |

> 注：若平台希望共用同一 `opcode`，也可改用不同 `funct3` 区分；但本文默认“一指令一 opcode”，最清晰。

---

## 4. 指令语义（规范性定义）

### 4.1 `mat_mult rd, rs, imm12`

* **功能**：读取 `MULT_*` CSR 的全部入参，执行完整输出流程并写回 `rs`
* **数值流程**（与 NMSIS-NN/TFLM 对齐）

  1. **乘加**：按 `A_W×B_W` 做 dot/GEMM，内部累加至少 **s32**（必要时可升 s64）
  2. **加 bias**：按 `BIAS_W` 加到累加和
  3. **requant**：`acc = requant_Q31(acc, multiplier[, per-channel], shift)`（算术右移 + 规范舍入）
  4. **`acc += dst_offset`**
  5. **激活裁剪**：`acc = clamp(acc, ACT_MIN, ACT_MAX)`（在 s32 域）
  6. **饱和截断**：将 `acc` 饱和到 `OUT_W` 指定位宽（s4/s8/s16/s32/s64）
  7. **写回**：元素序按实现/CSR 约定，起始地址为 **`rs`**（`rs==0` 可选落回 `MULT_DST_PTR`）
* **忽略项**：对 `vmax/vsum/dwconv` 专属 CSR 不产生访问
* **返回**：`rd=0` 成功；非 0 错误（见 §5）

### 4.2 `dwconv rd, rs, imm12`

* **功能**：读取 `DW_*` CSR，执行 depthwise\_conv\_s8\_mult\_4 语义的 DWConv，并写回 `rs`
* **位宽含义**：常用 `A_W=s8, B_W=s8, BIAS_W=s32, OUT_W=s8`；其它组合如被实现支持则按同流程执行
* **返回**：同上

### 4.3 `vsum rd, rs, imm12`

* **功能**：读取 `VSUM_*` CSR，对 `vector_data` 做列/行方向求和，结果写入 `rs`（通常 s32）
* **位宽含义**：`A_W/B_W` 可忽略；若 `BIAS_PTR != 0` 则按 `BIAS_W` 叠加偏置；`OUT_W` 指示写回元素位宽（常用 s32）
* **返回**：同上

### 4.4 `vmax rd, rs, imm12`

* **功能**：读取 `VMAX_*` CSR，计算逐元素 `max`，写回 `rs`
* **位宽含义**：仅 **`OUT_W`** 生效（输出元素位宽，常用 s8）；`A_W/B_W/BIAS_W` 忽略
* **返回**：同上

---

## 5. 返回码（推荐）

* `0x00000000`：成功
* `0x00000001`：不支持的位宽组合（`A_W/B_W/BIAS_W/OUT_W`）
* `0x00000002`：必需 CSR 缺失或指针为 0
* `0x00000003`：尺寸/对齐非法
* `0x00000004`：资源忙/内部阻塞，可重试
* `0x00000005`：实现定义的其他错误

---

## 6. 时序与一致性（信息性）

* **取参时序**：实现应在译码/执行阶段**快照**所有相关 CSR 值，确保一次指令的所有子计算使用一致配置
* **访存顺序**：建议 `rs` 写出采用自然顺序；若需要特定步距/交错，由 CSR 的地址/步距参数定义
* **并发**：当多核/多引擎并发使用共享 CSR 时，需由软件或上层协议保证互斥；本规范不定义锁语义

---

## 7. 编码示例（子规范性）

* **`mat_mult`，`s8*s16`，`bias=s32`，`out=s8`**

  * `imm12 = RSV(000) | A_W(01) | B_W(10) | BIAS_W(10) | OUT_W(001)` → `0b000_01_10_10_001`
  * 汇编：`mat_mult x0, a0, 0x1A1`（`a0` 为输出地址）
* **`dwconv`，`s8*s8`，`bias=s32`，`out=s8`**

  * `imm12 = 0b000_01_01_10_001`
* **`vsum`，写 s32**

  * `imm12 = 0b000_xx_xx_10_011`（A/B 忽略）

---

## 8. C 端宏（便捷封装）

```c
// 位宽枚举
enum { W_S4=0, W_S8=1, W_S16=2 };
enum { BIAS_S8=0, BIAS_S16=1, BIAS_S32=2, BIAS_S64=3 };
enum { OUT_S4=0, OUT_S8=1, OUT_S16=2, OUT_S32=3, OUT_S64=4 };

// imm12 构造器（高3位RSV=0）
#define SUBCONF(a_w,b_w,bias_w,out_w) \
  ( ((a_w)&3)<<7 | ((b_w)&3)<<5 | ((bias_w)&3)<<3 | ((out_w)&7) )

// I-type 内联（funct3=0b110）
#define MAT_MULT(status_out, dst_ptr, imm12) \
  __asm__ volatile (".insn i CUSTOM_1, 0x6, %0, %1, %2" \
                   : "=r"(status_out) : "r"(dst_ptr), "i"(imm12))

#define DWCONV(status_out, dst_ptr, imm12) \
  __asm__ volatile (".insn i CUSTOM_2, 0x6, %0, %1, %2" \
                   : "=r"(status_out) : "r"(dst_ptr), "i"(imm12))

#define VSUM(status_out, dst_ptr, imm12) \
  __asm__ volatile (".insn i CUSTOM_3, 0x6, %0, %1, %2" \
                   : "=r"(status_out) : "r"(dst_ptr), "i"(imm12))

#define VMAX(status_out, dst_ptr, imm12) \
  __asm__ volatile (".insn i CUSTOM_0, 0x6, %0, %1, %2" \
                   : "=r"(status_out) : "r"(dst_ptr), "i"(imm12))
```

---

## 9. 兼容性与演进

* **ABI 稳定**：`imm12` 仅承载位宽；未来扩展优先使用 CSR 增项（不改 `imm12` 语义）
* **位宽扩展**：若需增加 `s32*s8` 等更大乘数位宽，应另起一版规范或通过新 opcode 定义
* **错误处理**：对不支持的组合/路径必须返回明确错误码，便于库侧降级或回退

---

### 附录 A：与 CSR 的接口边界（摘要）

* `mat_mult` 依赖：`MULT_LHS_PTR/MULT_RHS_PTR/MULT_*_OFFSET/MULT_*_MULT(_PTR)/MULT_*_SHIFT(_PTR)/MULT_ACT_*` 等
* `dwconv` 依赖：`DW_IN_PTR/DW_KER_PTR/DW_BIAS_PTR/DW_OUT_PTR/DW_STRIDE_*/DW_PAD_*/DW_*_MULT_PTR/DW_*_SHFT_PTR/...`
* `vsum` 依赖：`VSUM_DATA_PTR/VSUM_ROWS/VSUM_COLS/VSUM_BUF_PTR/VSUM_*_OFFS/VSUM_BIAS_PTR`
* `vmax` 依赖：`VMAX_VEC0_PTR/VMAX_VEC1_PTR/VMAX_LEN`（输入只读；输出由 `rs` 指定）

