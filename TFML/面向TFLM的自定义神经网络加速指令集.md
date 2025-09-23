# AI-DSA 指令扩展规范（Draft v0.3）

## 0. RISC-V 标准指令格式参考（Informative）

RISC-V 32 位基本 R-type / I-type 编码（低位在右）：

```
31           25 24      20 19      15 14   12 11      7 6         0
+---------------+----------+----------+--------+----------+----------+
|    funct7     |   rs2    |   rs1    | funct3 |    rd    |  opcode  |  R-type
+---------------+----------+----------+--------+----------+----------+

31           20 19      15 14   12 11      7 6         0
+---------------+----------+--------+----------+----------+
|     imm[11:0] |   rs1    | funct3 |    rd    |  opcode  |  I-type
+---------------+----------+--------+----------+----------+
```

> 本扩展采用自定义 opcode 空间（`CUSTOM_1`, `CUSTOM_3`），并遵循 **NICE** 对 `funct3` 的用法约束：  
> `funct3[2]`→是否写回 `rd`，`funct3[1]`→是否使用 `rs1`，`funct3[0]`→是否使用 `rs2`。

---

## 1. 约定与术语

- **NICE funct3 约定**  
    `funct3[2]=1` → 指令写回 `rd`；`funct3[1]=1` → 使用 `rs1`；`funct3[0]=1` → 使用 `rs2`。  
    译码示例（Verilog）：  
    `nice_need_rd = rv32_instr[14]; nice_need_rs1 = rv32_instr[13]; nice_need_rs2 = rv32_instr[12];`
    
- **矩阵符号**
    
    - A[M×K]：左乘数（行主语义，存储布局由实现与库接口决定）。
        
    - B[K×N]：右乘数。
        
    - 结果 C[M×N] 或向量形式（M=1）。
        
- **T/NT 约定**
    
    - `mat_mult_t` 语义固定 **NT×T**：A（非转置/原始）× B（以列主/转置视图参与运算）。
        
    - `vec_mat_t` 语义固定 **vec×T**：1×K 与 B[K×N]。
        
- **cfg（配置字）**  
    R-type 的 `rs2` 寄存器载入的 32 位配置值，仅描述“位宽/特性开关”。所有地址、尺寸、量化、激活等在 **CSR** 配置。
    
- **返回码**  
    所有运算类指令把 **状态码**写回 `rd`（0=成功；详见 §5）。
    

---

## 2. 指令编码

### 2.1 CSR 访问类（I-type, `CUSTOM_3`）

|指令|语法|opcode|funct3|语义|编码要点|
|---|---|---|---|---|---|
|`csrwr`|`csrwr rs1, imm12`|CUSTOM_3|`010`|`CSR[imm12] ← rs1`|I-type：`rd=x0`；未实现 CSR → 非法指令异常|
|`csrrd`|`csrrd rd, imm12`|CUSTOM_3|`100`|`rd ← CSR[imm12]`|I-type：`rs1=x0`；未实现 CSR → 非法指令异常|

> 说明：`imm12` 为 CSR 编号；实现需对未实现/保留编号抛出非法指令异常。

### 2.2 运算类（R-type, `CUSTOM_1`）

通用：`rd`=状态码；`rs1`=输出起始地址（byte 指针）；`rs2`=cfg。

|指令|语法|opcode|funct7|funct3（NICE）|rs2 含义|
|---|---|---|---|---|---|
|`mat_mult_t`|`mat_mult_t rd, rs1, rs2`|CUSTOM_1|0x01|`111`|cfg 配置字|
|`vec_mat_t`|`vec_mat_t rd, rs1, rs2`|CUSTOM_1|0x02|`111`|cfg 配置字|
|`dwconv_mult_4`|`dwconv_mult_4 rd, rs1, x0`|CUSTOM_1|0x04|`110`|忽略（必须 x0）|

NICE 合规性：

- 需要 rd+rs1+rs2 → `funct3=0b111`；需要 rd+rs1 → `funct3=0b110`。
    
- 其它 `funct3` 编码为保留/非法（实现可直接触发非法指令异常）。
    

---

## 3. 配置字（cfg）定义（适用 `mat_mult_t` / `vec_mat_t`）

| 位段       | 名称/编码                      | 描述                                                |
| -------- | -------------------------- | ------------------------------------------------- |
| \[2:0]   | `OUT_W` 输出位宽               | 000=s4, 001=s8, 010=s16, 011=s32, 100=s64（饱和截断写回） |
| \[4:3]   | `BIAS_W` bias 位宽           | 00=s8, 01=s16, 10=s32, 11=s64                     |
| \[6:5]   | `B_W` 右乘数位宽                | 00=s4, 01=s8, 10=s16                              |
| \[8:7]   | `A_W` 左乘数位宽                | 00=s4, 01=s8, 10=s16                              |
| \[9]     | `PER_CH` 量化模式              | 0=per-tensor，1=per-channel                        |
| \[10]    | `ROW_ADDR_OFFSET_EN` 行偏移使能 | 1=启用 row\_address\_offset 路径                      |
| \[31:11] | 保留                         | 写 0                                               |


**实现约束**

- `ROW_ADDR_OFFSET_EN=1` 时，必须预先正确配置 `MULT_ROW_ADDR_OFFSET`；否则返回错误码（§5）。
    

---

## 4. 指令语义

### 4.1 关联 CSR（摘录）

- **指针**：`MULT_LHS_PTR`、`MULT_RHS_PTR`、`MULT_DST_PTR`、`MULT_BIAS_PTR`、`MULT_KSUM_PTR`
    
- **偏移**：`MULT_LHS_OFFSET`、`MULT_RHS_OFFSET`、`MULT_DST_OFFSET`
    
- **量化**：
    
    - per-tensor：`MULT_DST_MULT`、`MULT_DST_SHIFT`
        
    - per-channel：`MULT_DST_MULT_PTR`、`MULT_DST_SHIFT_PTR`
        
- **尺寸/几何**：`MULT_LHS_ROWS(M)`、`MULT_RHS_COLS(K)`、`MULT_RHS_ROWS(N)`、`MULT_ROW_ADDR_OFFSET`
    
- **激活裁剪**：`MULT_ACT_MIN`、`MULT_ACT_MAX`
    
- **DWConv 专用**：`DW_*` 组（通道倍增/步幅/核形状等）
    

> 任一**必需 CSR** 缺失或地址为 0，返回 `0x02`（§5）。

### 4.2 `mat_mult_t`（A[M×K] × B[K×N]，NT×T）

- **入口**：  
    `rd`（写回状态码）、`rs1`=C[0] 起始地址（byte），`rs2`=cfg  
    CSR 提供：A/B/C 指针与偏移、M/K/N、量化参数、可选 row-addr-offset、激活阈值
    
- **语义（伪代码）**：
    
    ```c
    require(CSRs_valid());
    cfg = RS2;
    
    for m in 0..M-1:
      for n in 0..N-1:
        acc = (bias ? load_bias(n, BIAS_W) : 0);
    
        // 可选：row address offset（逐行基址修正）
        baseA = A_ptr + row_base(m, ROW_ADDR_OFFSET_EN ? MULT_ROW_ADDR_OFFSET : 0);
    
        // 主乘累加
        for k in 0..K-1:
          a = load_A(baseA, k, A_W, LHS_OFFSET);
          b = load_B(B_ptr, k, n, B_W, RHS_OFFSET); // B 以“列视图/转置视图”参与
          acc += (int32)a * (int32)b;
    
        // 量化 & 写回
        {mult,shift} = per_channel ? load_q(n) : {MULT_DST_MULT, MULT_DST_SHIFT};
        x = requantize(acc, mult, shift, OUT_W);
        x = clamp(x, ACT_MIN, ACT_MAX);
        store_C(C_ptr, m, n, x, OUT_W, DST_OFFSET);
    return OK;
    ```
    
- **注意事项**：
    
    - `OUT_W` 控制饱和写回位宽；`BIAS_W` 控制 bias 加法位宽。
        
    - `A_W/B_W` 允许 s4/s8/s16 组合，非法组合 → `0x01`。
        
    - per-channel 时，量化参数地址需有效，否则 `0x02`。
        
    - `ROW_ADDR_OFFSET_EN=1` 必须已设定 `MULT_ROW_ADDR_OFFSET`，否则 `0x03`。
        

### 4.3 `vec_mat_t`（1×K × B[K×N]，vec×T）

- 与 `mat_mult_t` 同源实现，固定 `M=1`：仅计算一行（或一个 batch=1 向量）。
    
- CSR 仍需提供 K、N 与量化参数；写回从 `rs1` 指向的 C[0] 起始地址开始连续放置 N 元素。
    
- 其它行为（行偏移、量化、位宽、激活）与 `mat_mult_t` 一致。
    

### 4.4 `dwconv_mult_4`（Depthwise-Conv 4× 通道展开变体）

- **加速前置条件（全部满足才执行硬件加速）**：
    
    1. `ch_mult % 4 == 0`；2) `N == 1`（无 batch 扩展）；3) `dilation.w == 1 && dilation.h == 1`。  
- **语义概述**：
    
    - 输入特征图按 NHWC（实现可兼容 TFLM/NMSIS-NN 默认布局）；
        
    - 滑窗核逐像素执行通道独立的点乘与偏置、量化、激活；
        
    - 通道乘法（`ch_mult`）按 4 的倍数展开并行累加与写回。
        
- **配置**：尺寸、步幅、padding、指针、量化等均由 `DW_*` CSR 族提供；`rs2` 固定 `x0`。
    

---

## 5. 异常与错误码
12
### 5.1 非法指令异常（架构异常）

- 访问未实现/保留 CSR 编号（`csrrd/csrwr`）。
    
- 使用保留的 `funct3` 或保留 `funct7` 编码。
    
- 自定义空间以外的 opcode 误用。
    

### 5.2 运行时返回码（写回到 `rd`）

| 代码           | 含义                                                           |
| ------------ | ------------------------------------------------------------ |
| `0x00000000` | 成功                                                           |
| `0x00000001` | 不支持/未实现的模式或位宽组合                                              |
| `0x00000002` | 必需 CSR 缺失或指针为 0（包括 per-channel 量化指针无效）                       |
| `0x00000003` | 尺寸/对齐非法，或启用 `ROW_ADDR_OFFSET_EN` 但未设置 `MULT_ROW_ADDR_OFFSET` |
| `0x00000004` | 资源忙/内部阻塞（可重试）                                                |
| `0x00000005` | 实现自定义其他错误                                                    |

> 建议实现：对不可恢复错误可在 `0x05` 同时置内部错误寄存器以便调试。

---

## 6. 反汇编与示例（推荐，非规范约束）

### 6.1 建议反汇编格式

- `mat_mult_t rd, rs1, rs2` ; `CUSTOM_1`/`funct7=0x01`/`funct3=0b111`
    
- `vec_mat_t rd, rs1, rs2` ; `CUSTOM_1`/`funct7=0x02`/`funct3=0b111`
    
- `dwconv_mult_4 rd, rs1` ; `CUSTOM_1`/`funct7=0x04`/`funct3=0b110`/`rs2=x0`
    
- `csrwr rs1, imm12` ; `CUSTOM_3`/I-type/`funct3=0b010`
    
- `csrrd rd, imm12` ; `CUSTOM_3`/I-type/`funct3=0b100`
    

### 6.2 GCC inline 宏（供参考）

```c
enum { W_S4=0, W_S8=1, W_S16=2 };
enum { BIAS_S8=0, BIAS_S16=1, BIAS_S32=2, BIAS_S64=3 };
enum { OUT_S4=0, OUT_S8=1, OUT_S16=2, OUT_S32=3, OUT_S64=4 };

#define CFG_OUT_W(x)       ((uint32_t)(x) & 7u)
#define CFG_BIAS_W(x)      (((uint32_t)(x) & 3u) << 3)
#define CFG_B_W(x)         (((uint32_t)(x) & 3u) << 5)
#define CFG_A_W(x)         (((uint32_t)(x) & 3u) << 7)
#define CFG_PER_CH(b)      ((uint32_t)(!!(b)) << 9)
#define CFG_ROW_ADDR_EN(b) ((uint32_t)(!!(b)) << 10)

#define MATVEC_CFG(a_w,b_w,bias_w,out_w, per_ch, row_addr_en) \
  ( CFG_A_W(a_w) | CFG_B_W(b_w) | CFG_BIAS_W(bias_w) | CFG_OUT_W(out_w) | \
    CFG_PER_CH(per_ch) | CFG_ROW_ADDR_EN(row_addr_en) )

#define MAT_MULT_T(status_out, dst_ptr, cfg) \
  __asm__ volatile (".insn r CUSTOM_1, 0x7, %0, %1, %2, 0x01" \
                    : "=r"(status_out) : "r"(dst_ptr), "r"(cfg))

#define VEC_MAT_T(status_out, dst_ptr, cfg) \
  __asm__ volatile (".insn r CUSTOM_1, 0x7, %0, %1, %2, 0x02" \
                    : "=r"(status_out) : "r"(dst_ptr), "r"(cfg))

#define DWCONV_MULT_4(status_out, dst_ptr) \
  __asm__ volatile (".insn r CUSTOM_1, 0x6, %0, %1, x0, 0x04" \
                    : "=r"(status_out) : "r"(dst_ptr))
```

### 6.3 cfg 速用示例

- **常规 per-channel：s8×s8 + bias s32 → out s8；禁用行偏移**
    
    ```c
    uint32_t cfg = MATVEC_CFG(W_S8, W_S8, BIAS_S32, OUT_S8, /*per_ch=*/1, /*row_addr=*/0);
    ```
    
- **s8×s16 行偏移核：bias s32 → out s8；启用行偏移**
    
    ```c
    uint32_t cfg = MATVEC_CFG(W_S8, W_S16, BIAS_S32, OUT_S8, /*per_ch=*/1, /*row_addr=*/1);
    // 需配好 MULT_ROW_ADDR_OFFSET、MULT_DST_MULT_PTR/SHIFT_PTR 等 CSR
    ```
    

### 6.4 最小调用序列（示意）

```c
// 1) 配 CSR（指针/尺寸/量化/激活/偏移等）
csrwr(MULT_LHS_PTR,   (uintptr_t)A);
csrwr(MULT_RHS_PTR,   (uintptr_t)B);
csrwr(MULT_DST_PTR,   (uintptr_t)C);
csrwr(MULT_LHS_ROWS,  M);
csrwr(MULT_RHS_COLS,  K);
csrwr(MULT_RHS_ROWS,  N);
csrwr(MULT_DST_MULT,  dst_mult);              // per-tensor
csrwr(MULT_DST_SHIFT, dst_shift);
csrwr(MULT_ACT_MIN,   act_min);
csrwr(MULT_ACT_MAX,   act_max);
// 可选：per-channel / row offset
// csrwr(MULT_DST_MULT_PTR, ...); csrwr(MULT_DST_SHIFT_PTR, ...);
// csrwr(MULT_ROW_ADDR_OFFSET, ...);

// 2) 触发
uint32_t status;
uint32_t cfg = MATVEC_CFG(W_S8, W_S8, BIAS_S32, OUT_S8, 0, 0);
MAT_MULT_T(status, /*dst_ptr=*/C, cfg);
// or: VEC_MAT_T(status, C, cfg);

// 3) 检查返回码
if (status != 0) { /* 处理错误 */ }
```

---
