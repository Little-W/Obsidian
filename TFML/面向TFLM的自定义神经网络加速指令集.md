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

