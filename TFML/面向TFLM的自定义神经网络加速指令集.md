# RUN 指令集规范（AI-DSA 扩展，运行类）

## 本节定义 **RUN** 系列算子执行指令，采用 R-type 自定义编码，**激活函数独立为 `RUN_RELU`**。  
统一约定：**所有地址类操作数放在 `rs1`**；**`rs2` 为上下文/流 ID**；**`rd` 返回 ticket/错误码**。

---

### 1. 指令编码（统一格式）

**格式：R-type（32b）**

```
|  funct7  |   rs2   |   rs1   | funct3 |   rd   |  opcode  |
|  31..25  | 24..20  | 19..15  | 14..12 | 11..7  |  6..0    |
```

- `opcode`：`custom1`（运行类统一使用）
    
- `funct7`：**算子类编码**（见 §2）
    
- `funct3`：**指令位宽选择**（见 §1.1）
    
- `rs1`：**out_ptr**（输出张量首地址）
    
- `rs2`：**ctx**（0 表示当前隐式上下文）
    
- `rd` ：**ticket / err**（≥0 为提交号；<0 为立即错误）
    

#### 1.1 `funct3` —— 指令位宽（slice width）

|`funct3`|名称|语义（实现可选）|
|---|---|---|
|`000`|`s4`|4-wide 计算切片/并行度|
|`001`|`s8`|8-wide 计算切片/并行度|
|`010`|`s16`|16-wide 计算切片/并行度|

> 说明：位宽仅指**微架构执行切片/并行度/packing**选择，不改变算子数学语义与 ABI。实现可将不支持的位宽返回错误码。

---

### 2. 指令集合与 `funct7` 映射

|指令名|用途|`funct7`|
|---|---|---|
|`RUN_CONV`|标准 2D 卷积|`0x01`|
|`RUN_DWCONV`|深度可分离卷积|`0x02`|
|`RUN_FC`|全连接（矩阵-向量）|`0x03`|
|`RUN_POOL`|池化（平均/最大/全局）|`0x04`|
|`RUN_RELU`|激活：ReLU（单独指令）|`0x05`|

> 其他激活（ReLU6/Leaky/Clamp）预留为后续扩展，不在本版定义。

---

### 3. 操作数与内存对象

- `rs1 = out_ptr`：输出张量首地址（布局由配置类 `SET_*` 指令决定；建议 ≥16B 对齐）。
    
- `rs2 = ctx/x0`：上下文/流标识。`x0` = 当前隐式上下文。上下文中应已通过配置类 `SET_*` 写入：
    
    - **CONV / DWCONV**：输入/权重/偏置地址，`N,H,W,C,K,R,S`，`stride/pad/dilation/groups/multiplier`，布局/量化等；
        
    - **FC**：输入/权重/偏置地址，`in_dim/out_dim`，布局/量化等；
        
    - **POOL**：输入地址，kernel/stride/pad，`mode`（AVG/ MAX/ GLOBAL），量化等；
        
    - **RELU**：输入地址（若与输出相同则原地，就地覆写；否则 `out_ptr` 可指向不同缓冲）。
        
- `rd = ticket/err`：成功返回非负 ticket 以供 `POLL/SYNC`；若立即检查失败（如未配置、地址未对齐、不支持的位宽），`rd` 返回负错误码（见 §6）。
    

---

### 4. 指令语义

#### 4.1 `RUN_CONV.s{4,8,16}`

**编码：**

```
opcode=custom1, funct7=0x01, funct3 ∈ {000(s4),001(s8),010(s16)}
rs1 = out_ptr, rs2 = ctx/x0, rd = ticket/err
```

**语义：**  
对 `ctx` 指定的卷积上下文执行 2D 卷积（含 padding/stride/dilation、groups）。将结果写入 `out_ptr`。  
**注意：** 若上下文配置了深度可分离（groups=C, multiplier≥1），建议使用 `RUN_DWCONV`，但实现也可在 `RUN_CONV` 内自动支持。

**伪代码：**

```
assert(ctx.valid && out_ptr.aligned)
plan = mk_conv_plan(ctx, slice_width=SW_from_funct3)
ticket = enqueue(plan, out_ptr)
rd = ticket
```

---

#### 4.2 `RUN_DWCONV.s{4,8,16}`

**编码：**

```
opcode=custom1, funct7=0x02, funct3 ∈ {000,001,010}
rs1 = out_ptr, rs2 = ctx/x0, rd = ticket/err
```

**语义：**  
执行深度可分离卷积（channel-wise，可带 `multiplier`）。其余同 `RUN_CONV`。

---

#### 4.3 `RUN_FC.s{4,8,16}`

**编码：**

```
opcode=custom1, funct7=0x03, funct3 ∈ {000,001,010}
rs1 = out_ptr, rs2 = ctx/x0（低位可指示 per-channel 量化）, rd = ticket/err
```

**语义：**  
执行全连接（矩阵-向量乘加 + 偏置 + 量化出栈），结果写入 `out_ptr`。

- `rs2` 用最低 bit 位（如 `rs2[0]`）指示量化类型：
    - `rs2[0]=0`：per-tensor 量化
    - `rs2[0]=1`：per-channel 量化
  其余高位为 ctx。

---

#### 4.4 `RUN_POOL.s{4,8,16}`

**编码：**

```
opcode=custom1, funct7=0x04, funct3 ∈ {000,001,010}
rs1 = out_ptr, rs2 = ctx/x0, rd = ticket/err
```

**语义：**  
按上下文中的 `mode`（AVG/ MAX）与 `global` 标志执行池化；结果写 `out_ptr`。  
平均池化的定点除法/舍入策略由上下文量化配置决定。

---

#### 4.5 `RUN_RELU.s{4,8,16}`

**编码：**

```
opcode=custom1, funct7=0x05, funct3 ∈ {000,001,010}
rs1 = out_ptr, rs2 = ctx/x0, rd = ticket/err
```

**语义：**  
对 `ctx` 指定的输入张量应用 **ReLU**。

- 若上下文声明**就地**：`in_ptr == out_ptr`，在原缓冲区内就地更新；
    
- 若声明**非就地**：硬件从上下文的输入地址读取，写入本指令 `out_ptr`。
    

> 其他激活（ReLU6/Leaky/Clamp）留作后续扩展；其参数应通过配置类 `SET_ACT_PARAM` 提前设置。

---

### 5. 内存序与可观察行为

- **顺序保证**：所有 `SET_*` 在程序次序上先于对应 `RUN_*`；实现应将 `RUN_*` 视为 **release**，`POLL/SYNC` 视为 **acquire**。
    
- **对齐与访问**：建议 `out_ptr`、上下文中的各张量地址按 16B 对齐；未对齐可直接报错或降速路径（实现自定，但需一致）。
    
- **重入/幂等**：对同一 `ctx` 的并发 `RUN_*` 行为由实现定义；建议以 ticket 串行化，或返回 `-BUSY`。
    

---

### 6. 错误码（`rd<0`）

|名称|值|说明|
|---|---|---|
|`ERR_BAD_CTX`|`-1`|上下文不存在/未初始化|
|`ERR_BAD_ADDR`|`-2`|`out_ptr` 或上下文地址为 NULL / 未对齐|
|`ERR_BAD_FMT`|`-3`|不支持的数据/权重布局或池化模式|
|`ERR_BAD_PARAM`|`-4`|尺寸/步长/边界非法|
|`ERR_BAD_SW`|`-5`|`funct3` 所选位宽不受支持|
|`ERR_DMA`|`-6`|访存失败/权限错误|
|`ERR_BUSY`|`-7`|资源不足或上下文繁忙|
|`ERR_INTERNAL`|`-8`|其他内部错误|

---

### 7. 反汇编助记与示例（建议）

**助记形式：**

```
run.conv.s4    rd, rs1=out, rs2=ctx      # funct7=0x01, funct3=000
run.conv.s8    rd, rs1, rs2              # funct7=0x01, funct3=001
run.conv.s16   rd, rs1, rs2              # funct7=0x01, funct3=010
...
run.relu.s8    rd, rs1, rs2              # funct7=0x05, funct3=001
```

**示例：**

```asm
# 已用 SET_* 配好 ctx=3
# 1) 卷积（s8 宽度），输出到 out_buf
addi  a1, x0, 3              # ctx=3
la    a0, out_buf
run.conv.s8 a2, a0, a1       # rd=a2 <- ticket or err

# 2) ReLU（就地，s8 宽度）
run.relu.s8 a3, a0, a1       # 对 out_buf 执行 ReLU，rd=a3
```

---

### 8. 兼容性与实现备注

- **位宽选择**：实现可将 `s4/s8/s16` 映射为不同的 MAC 并行度/向量化粒度/片上 SRAM 访问宽度。若不支持某种位宽，应返回 `ERR_BAD_SW`。
    
- **融合优化（非规范要求）**：实现可在内部识别“同一 `ctx` 的 `RUN_CONV` 紧随 `RUN_RELU` 且 `out_ptr` 相同”，在后端执行路径上融合为“卷积出栈 + ReLU”，以减少访存次数；但对软件而言这两条指令仍是可见的独立提交。
    
- **地址检查**：强烈建议在发起时检查 `NULL/对齐/越界` 并即时在 `rd` 返回错误，避免隐式故障。
    

---

**本节完。**