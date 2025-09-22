# 面向 TFLM 的 AI-DSA 指令规范（Draft v0.2）

本文档定义 AI-DSA 扩展指令集，采用 RISC-V 自定义编码并遵循 **NICE** 的 `funct3`用法约束。

NICE 的用法约束：
芯来为了简化自定义指令译码，把 funct3 的每一位直接作为“寄存器需求标志”：

| 位段          | 作用             | Verilog 映射                             |
| ----------- | -------------- | -------------------------------------- |
| `funct3[2]` | 指令是否需要写回 `rd`  | `wire nice_need_rd  = rv32_instr[14];` |
| `funct3[1]` | 指令是否需要使用 `rs1` | `wire nice_need_rs1 = rv32_instr[13];` |
| `funct3[0]` | 指令是否需要使用 `rs2` | `wire nice_need_rs2 = rv32_instr[12];` |

---

## 二、RUN 指令集规范（AI-DSA 扩展，运行类）

### 1. 约定与术语

* **地址经由 `rs1` 传入**：`rs1` 为输出张量首地址（`out_ptr`），建议 ≥16B 对齐。
* **子配置经由 `imm12` 传入**：`imm12` 为 12 位**子配置（sub-config）比特域**（见 §4）。
* **返回值经由 `rd` 写回**：`rd ≥ 0` 为提交号（`ticket`），`rd < 0` 为立即错误码。
* **上下文/算子参数**（输入/权重/偏置/尺寸/布局/量化等）须在 RUN 之前由 `SET_*` 指令写入“当前隐式上下文”。
* **内存序**：所有 RUN 指令为 **release**；`POLL/SYNC` 为 **acquire**。

---

### 2. 指令编码

#### 2.1 通用编码格式（**I-TYPE，自定义 opcode**）

```
| 31..20   | 19..15 | 14..12 | 11..7 |  6..0  |
| imm[11:0]|  rs1   | funct3 |  rd   | opcode |
```

* `opcode` ：`custom1`（RUN 类统一使用）
* `funct7` ：—（I-TYPE 无 `funct7`，**算子种类由 opcode 扩展号 + 伪 funct7 域替代：见 §3**）
* `funct3` ：**NICE: 寄存器需求位**

  * `funct3[2]`（bit14）=1 → 需要写回 `rd`
  * `funct3[1]`（bit13）=1 → 使用 `rs1`
  * `funct3[0]`（bit12）=1 → 使用 `rs2`
    **本规范规定所有 RUN 指令：`funct3 = 3'b110`（需要 `rd` 与 `rs1`，**不**使用 `rs2`）。**
* `rs1` ：输出缓冲首地址 `out_ptr`
* `imm12`：子配置 `subcfg`（12-bit，比特域见 §4；按**无符号位域**解释，不做算术符号扩展）
* `rd`  ：提交号/错误码

> 注：硬件译码可将 `imm12` 视为**控制位域**而非地址位移；编译器侧以 `.insn i`/自定义伪指令传入。

---

### 3. 指令列表与“类码”(Class) 选择

| 指令名          | 语义               | `opcode` | `funct3`(NICE) | 类码(Class)* |
| ------------ | ---------------- | -------- | -------------- | ----------- |
| `RUN_CONV`   | 执行标准 2D 卷积       | custom1  | `0b110`        | `0x01`      |
| `RUN_DWCONV` | 执行深度可分离卷积        | custom1  | `0b110`        | `0x02`      |
| `RUN_FC`     | 执行全连接（矩阵-向量）     | custom1  | `0b110`        | `0x03`      |
| `RUN_POOL`   | 执行池化（AVG/MAX/全局） | custom1  | `0b110`        | `0x04`      |
| `RUN_RELU`   | 执行 ReLU 激活（独立算子） | custom1  | `0b110`        | `0x05`      |

\* **类码(Class)**：硬件实现可用 `custom1` 的扩展编码位或使用内部“子操作码寄存器”承载该类码（例如放在实现专用 CSR/译码旁路中）。若需在指令内显式携带类码，可占用 `imm12` 的高位或通过 `custom1` 的变体区分；本规范默认**类码由实现侧固定映射**。

---

### 4. `imm12` 子配置（sub-config）按指令独立定义

总则：
- `imm12` 为 12 位控制位域，且“按指令独立定义”。某一比特的含义不在不同指令间复用。
- 每条指令对未定义的位必须写 0，硬件必须忽略这些位。
- 若实现未支持某配置，应返回 `ERR_BAD_SW`。
- 统一 WIDTH 编码：`[1:0]` 位宽编码 `00`=s8，`01`=s16，`10`=s4，`11`=保留；未实现的编码返回 `ERR_BAD_SW`。

#### 4.1 RUN_CONV
- [1:0] WIDTH：`00`=s8，`01`=s16，`10`=s4，`11`=保留
- [11:2] 保留（写 0）

#### 4.2 RUN_DWCONV
- 同 RUN_CONV（Depthwise 语义，含 multiplier）；其余位保留

#### 4.3 RUN_FC
- [1:0] WIDTH：`00`=s8，`01`=s16，`10`=s4，`11`=保留
- [2] FC_PC：是否 per-channel 量化（`1`=per-channel，`0`=per-tensor）
- [11:3] 保留（写 0）

#### 4.4 RUN_POOL
- [1:0] WIDTH：`00`=s8，`01`=s16，`10`=s4，`11`=保留
- [3:2] POOL_MD：池化模式（`00`=AVG，`01`=MAX，`10`=GAP，`11`=GMP）
- [11:4] 保留（写 0）

#### 4.5 RUN_RELU
- [1:0] WIDTH：`00`=s8，`01`=s16，`10`=s4，`11`=保留
- [11:2] 保留（写 0）

> 说明：上述位域仅在对应指令下有效；各指令对未定义位必须忽略且要求软件写 0。

---

### 5. 指令语义

#### 5.1 `RUN_CONV`

* **编码**：`custom1` / **I-TYPE** / `funct3=0b110` / `imm12=subcfg`
* **操作数**：`rs1=out_ptr`；`rd=ticket/err`
* **行为**：对当前上下文执行 2D 卷积（stride/pad/dilation/groups）。`WIDTH` 选择内部切片/并行度。
* **错误**：不支持的 `WIDTH` → `ERR_BAD_SW`；地址/上下文问题见 §6。

#### 5.2 `RUN_DWCONV`

* 同 `RUN_CONV`；语义限定为 Depthwise（groups=C，支持 `multiplier`）。

#### 5.3 `RUN_FC`

* **使用位**：`WIDTH`、`FC_PC`、`FC_WTT`、`FC_SAT`。
* **行为**：矩阵-向量乘加 + 偏置 + 量化出栈；可选择 per-channel、权重转置、饱和策略。

#### 5.4 `RUN_POOL`

* **使用位**：`WIDTH`、`POOL_MD`、`POOL_EX`。
* **行为**：按模式执行 AVG/MAX/GAP/GMP；`POOL_EX` 控制平均是否排除 padding 区。

#### 5.5 `RUN_RELU`

* **使用位**：`WIDTH`。
* **行为**：对上下文输入应用 ReLU；是否就地由上下文/缓冲区配置决定，与 `imm12` 无关。

---

### 6. 异常与错误码（`rd < 0`）

| 名称              | 值    | 说明                         |
| --------------- | ---- | -------------------------- |
| `ERR_BAD_CTX`   | `-1` | 上下文不存在/未初始化                |
| `ERR_BAD_ADDR`  | `-2` | `out_ptr` 或上下文地址为 NULL/未对齐 |
| `ERR_BAD_FMT`   | `-3` | 不支持的数据/权重布局/池化模式           |
| `ERR_BAD_PARAM` | `-4` | 尺寸/步长/边界非法                 |
| `ERR_BAD_SW`    | `-5` | `WIDTH` 选择不受支持             |
| `ERR_DMA`       | `-6` | 访存失败/权限错误                  |
| `ERR_BUSY`      | `-7` | 资源不足或队列繁忙                  |
| `ERR_INTERNAL`  | `-8` | 其他内部错误                     |

---

### 7. 程序员可观察行为与顺序

* **顺序约束**：`SET_*` → `RUN_*` → `POLL/SYNC`；实现需保证 `RUN_*` 对先前 `SET_*` 的可见性。
* **对齐建议**：所有张量/权重/偏置/输出地址 ≥16B；未对齐建议直接报错。
* **幂等/重入**：同一上下文并发 RUN 的行为由实现定义；推荐以 ticket 串行或返回 `ERR_BUSY`。

---

### 8. 反汇编与示例（推荐，非规范约束）

**助记（I-TYPE）**：

```
run.conv   rd, rs1, imm12    # imm12=subcfg
run.dw     rd, rs1, imm12
run.fc     rd, rs1, imm12
run.pool   rd, rs1, imm12
run.relu   rd, rs1, imm12
```

**示例：**

```asm
# s8 卷积：WIDTH=00
li    a0, out_buf
addi  a1, x0, 0b000000000000   # imm12 = 0x000 (WIDTH=00=s8)
run.conv a2, a0, a1            # a2 <- ticket/err  （伪语法：I型立即数装入由汇编器完成）

# FC：s8 + per-channel + 权重转置
# imm12 bits: [FC_PC]=1([5]), [FC_WTT]=1([6]), WIDTH=s8([1:0]=00)
#            000 0 1 1 000 00  => 0b000001100000 = 0x60
li    a0, fc_out
addi  a1, x0, 0x060
run.fc   a3, a0, a1

# POOL：GAP + s16 + EXCL_PAD
# MODE=10([3:2]), EXCL_PAD=1([4]), WIDTH=s16([1:0]=01)
# bits: 000 0 0 0 1 010 01  => 0b0000000101001 = 0x029
li    a0, pool_out
addi  a1, x0, 0x029
run.pool a4, a0, a1

# ReLU：s8（是否就地由上下文决定）
# WIDTH=s8([1:0]=00) => imm12 = 0x000
li    a0, out_buf
addi  a1, x0, 0x000
run.relu a5, a0, a1
```

> 说明：上例把 `imm12` 写成常量便于展示；实际使用时由编译器/宏封装到 I-type 立即数位置（`imm[11:0]`）。

---

### 9. 实现提示

* **NICE 校验**：译码检查 `funct3==3'b110`；否则非法。
* **WIDTH 子集**：若仅实现 `s8`，则 `WIDTH≠00` 即刻返回 `ERR_BAD_SW`。
* **融合优化**：可在微架构上识别“同 `out_ptr` 的 `RUN_CONV` 后紧随 `RUN_RELU`”并内部融合（对 ISA 语义透明）。
* **保留位**：各指令未定义位必须写 0；硬件忽略。

—— **本节完** ——
