# 多精度 DiP 脉动阵列 RTL

## 设计摘要

本目录实现 Abdelmaksoud、Agwa 与 Prodromakis 提出的 Diagonal-Input and Permutated weight-stationary（DiP）数据流，并在固定的 \(N\times N\) 物理 PE 阵列上支持 INT16、INT8、INT4 三种计算模式。默认 \(N=16\)：INT16 处理 \(16\times16\) 逻辑矩阵，INT8 扩展到 \(32\times32\)，INT4 扩展到 \(64\times64\)，A、B、C 的物理行带宽不随模式改变。

每个物理 PE 固定实例化 16 个 4×4 基础乘法器。模式降低输入位宽后，同一组乘法器分别组成 1 个 16×16、4 个 8×8 或 16 个 4×4 逻辑乘法。局部贡献使用 1×64 bit、2×32 bit 或 4×16 bit 的临时累加格式，阵列底部再截取为 1×INT32、2×INT16 或 4×INT8。

当前 PE 采用四级算术寄存：基础乘积寄存、逻辑乘积重组寄存、局部 K 求和寄存、分段累加寄存。权重在计算前装入 PE 并保持不变；数据与部分和在物理行之间各延迟一拍。Python 黄金模型、定向测试和 Verilator 全阵列测试覆盖三种模式、随机 GEMM、极值、valid 空拍、连续 tile 与 \(N=1\) 特例。

文中插图依据论文 Fig. 2、Fig. 3 及当前 RTL 重新绘制。论文 3×3 图用于说明 DiP 的基本计算关系；四级算术寄存、多 lane 和三种精度的逐周期独立图均以本目录 RTL 为准。

## 1. 设计参数与实现结果

### 1.1 符号

| 符号 | 定义 | 取值范围 |
|---|---|---|
| \(N\) | 物理 PE 阵列边长 | 默认 16 |
| \(w\) | 有符号输入元素位宽 | 16、8、4 |
| \(\ell\) | 一个 16-bit 物理字中的元素数 | \(\ell=16/w\) |
| \(L\) | 逻辑矩阵边长 | \(L=N\ell\) |
| \(R,C\) | 物理 PE 行号、列号 | \(0\le R,C<N\) |
| \(u\) | PE 内局部 K 编号 | \(0\le u<\ell\) |
| \(v\) | PE 内输出编号 | \(0\le v<\ell\) |
| \(m\) | A、C 的逻辑行号 | \(0\le m<L\) |
| \(j,k\) | GEMM 输出列号、K 下标 | \(0\le j,k<L\) |

三种模式满足

$$
\ell=\frac{16}{w},
\qquad
L=N\ell.
$$

### 1.2 精度、空间扩展与并行度

| `mode_i` | 模式 | \(w\) | \(\ell\) | 逻辑矩阵 | 逻辑乘法/PE/周期 | 逻辑乘法/阵列/周期 |
|---:|---|---:|---:|---:|---:|---:|
| `2'b00` | INT16 | 16 | 1 | \(N\times N\) | 1 | \(N^2\) |
| `2'b01` | INT8 | 8 | 2 | \(2N\times2N\) | 4 | \(4N^2\) |
| `2'b10` | INT4 | 4 | 4 | \(4N\times4N\) | 16 | \(16N^2\) |
| `2'b11` | 保留 | — | — | — | — | 不接受新 tile |

全阵列每周期执行的逻辑元素乘法数为

$$
\Pi_{\mathrm{mul}}=N^2\ell^2.
$$

默认 \(N=16\) 时：

| 模式 | 逻辑矩阵 | 逻辑乘法/周期 |
|---|---:|---:|
| INT16 | \(16\times16\) | 256 |
| INT8 | \(32\times32\) | 1024 |
| INT4 | \(64\times64\) | 4096 |

### 1.3 数值宽度

| 模式 | PE 局部贡献 \(Q\) | 纵向部分和 \(S\) | 每个物理 C 字 |
|---|---|---|---|
| INT16 | 1×64 bit | 1×64 bit | 1×INT32 |
| INT8 | 2×32 bit | 2×32 bit | 2×INT16 |
| INT4 | 4×16 bit | 4×16 bit | 4×INT8 |

所有输入、乘法和累加都按二补码解释。每次纵向累加在临时位宽内回绕；阵列底部保留每段低 \(2w\) bit，不执行饱和或舍入。

### 1.4 固定物理带宽与打包

| 总线 | 每个物理列 | 整行 |
|---|---:|---:|
| A 输入 | 16 bit | \(16N\) bit |
| 原始 B 输入 | 16 bit | \(16N\) bit |
| 权重装载 | 16 bit | \(16N\) bit |
| PE 间部分和 | 64 bit | \(64N\) bit |
| C 输出 | 32 bit | \(32N\) bit |
| 完整临时结果输出 | 4×64 bit | \(256N\) bit |

物理字的 lane 0 位于最低位。对物理列 \(C\) 和 lane \(v\)，A、原始 B 与 C 的位段分别为

$$
\begin{aligned}
A_{\mathrm{phys}}[C]_{vw+w-1:vw}
&=A_{m,\ell C+v},\\
B_{\mathrm{raw,phys}}[C]_{vw+w-1:vw}
&=B_{r,\ell C+v},\\
C_{\mathrm{phys}}[C]_{2vw+2w-1:2vw}
&=C_{m,\ell C+v}.
\end{aligned}
$$

因此，INT16 的一个 32-bit C 字保存一个 INT32；INT8 保存两个 INT16；INT4 保存四个 INT8。

## 2. 总体结构与 tile 事务

![[NPU/rtl/dip/docs/figures/system_overview.png]]

*图 1　多精度 DiP RTL 总体结构。A 直接进入阵列；B 先由预处理模块改变排列，再按拍装入 PE。*

`dip_gemm_core` 一次处理一个完整的 \(L\times L\times L\) 方形 GEMM tile。物理阵列尺寸始终为 \(N\times N\)，模式只改变一个物理字中的 lane 数、逻辑矩阵边长以及 PE 内并行计算数。

### 2.1 执行次序

| 阶段    | 接收或产生的内容               |      拍数 | 关键行为                 |
| ----- | ---------------------- | ------: | -------------------- |
| B 接收  | 原始 B 的 \(L\) 行         |   \(L\) | 第一个 B 行握手时锁存模式       |
| 权重装载  | \(P_{L-1},\ldots,P_0\) |   \(L\) | 每个物理列独立向下移位          |
| A 接收  | A 的 \(L\) 行            |   \(L\) | 最后一个权重拍可与第一个 A 行同拍接收 |
| 计算与排出 | C 的 \(L\) 行            | 与阵列流水重叠 | 结果按 A 的行号顺序连续输出      |

最后一行 C 有效时 `c_row_last_o=1`；同一 tile 完成后 `tile_done_o` 拉高一个周期。

### 2.2 顶层接口

| 信号 | 方向 | 宽度 | 说明 |
|---|---|---:|---|
| `clk_i` | input | 1 | 时钟 |
| `reset_n` | input | 1 | 低有效异步复位 |
| `mode_i` | input | 2 | `00/01/10` 对应 INT16/INT8/INT4 |
| `b_raw_row_valid_i` | input | 1 | 原始 B 行有效 |
| `b_raw_row_ready_o` | output | 1 | 可以接收原始 B 行 |
| `b_raw_row_i` | input | \(16N\) | 一个 packed B 行 |
| `a_row_valid_i` | input | 1 | A 行有效 |
| `a_row_ready_o` | output | 1 | 可以接收 A 行 |
| `a_row_i` | input | \(16N\) | 一个 packed A 行 |
| `c_row_valid_o` | output | 1 | C 行有效 |
| `c_row_last_o` | output | 1 | 当前 C 行是 tile 的最后一行 |
| `c_row_o` | output | \(32N\) | 一个 packed C 行 |
| `c_accum_row_o` | output | \(256N\) | 每物理列四个 64-bit 槽，给出符号扩展后的完整临时结果 |
| `busy_o` | output | 1 | 当前 tile 尚未完成 |
| `tile_done_o` | output | 1 | 当前 tile 完成脉冲 |

输入以 `valid && ready` 表示一次接收。C 端没有 `ready`，调用方必须接收每个 `c_row_valid_o=1` 的周期。单独使用 `dip_systolic_array` 时，调用方必须从权重装载开始到最后一行 C 输出为止保持 `mode_i` 不变；使用 `dip_gemm_core` 时，顶层在首个 B 行握手时锁存模式。

## 3. DiP 基本计算关系

### 3.1 论文 3×3 示例

令

$$
A=
\begin{bmatrix}
1&2&3\\
4&5&6\\
7&8&9
\end{bmatrix},
\qquad
B=
\begin{bmatrix}
a&d&g\\
b&e&h\\
c&f&i
\end{bmatrix}.
$$

权重矩阵第 \(c\) 列向上循环移动 \(c\) 个位置：

$$
P_{r,c}=B_{(r+c)\bmod N,c}.
$$

因此

$$
P=
\begin{bmatrix}
a&e&i\\
b&f&g\\
c&d&h
\end{bmatrix}.
$$

![[NPU/rtl/dip/docs/figures/dip_3x3_dataflow.png]]

*图 2　论文 3×3 示例中的权重排列、对角数据移动和第一行结果。*

### 3.2 对角数据移动

记 A 的第 \(m\) 行在物理 PE \((R,C)\) 中的数据为 \(I_{R,C}^{(m)}\)。单 lane DiP 满足

$$
I_{R,C}^{(m)}=A_{m,(R+C)\bmod N},
\qquad
I_{R+1,C}^{(m)}=I_{R,(C+1)\bmod N}^{(m)}.
$$

从发送端观察，物理 PE 的数据寄存输出方向为

$$
(R,C)\longrightarrow\left(R+1,(C-1)\bmod N\right).
$$

普通列的数据进入下一物理行的左侧一列，第 0 列的数据循环送到下一物理行的第 \(N-1\) 列。权重与部分和均沿同一物理列向下。

### 3.3 正确性推导

装载后，物理 PE \((R,C)\) 保存

$$
P_{R,C}=B_{(R+C)\bmod N,C}.
$$

令

$$
k_R=(R+C)\bmod N.
$$

该 PE 的乘法项为

$$
I_{R,C}^{(m)}P_{R,C}
=A_{m,k_R}B_{k_R,C}.
$$

当 \(R\) 遍历 \(0,\ldots,N-1\) 时，\(k_R\) 恰好取遍全部 K 下标，因此

$$
\begin{aligned}
\sum_{R=0}^{N-1}I_{R,C}^{(m)}P_{R,C}
&=\sum_{R=0}^{N-1}
A_{m,(R+C)\bmod N}
B_{(R+C)\bmod N,C}\\
&=\sum_{k=0}^{N-1}A_{m,k}B_{k,C}\\
&=C_{m,C}.
\end{aligned}
$$

3×3 示例第一行的三个结果为

$$
\begin{aligned}
C_{0,0}&=1a+2b+3c,\\
C_{0,1}&=2e+3f+1d=1d+2e+3f,\\
C_{0,2}&=3i+1g+2h=1g+2h+3i.
\end{aligned}
$$

物理 PE 中的加法次序发生循环变化，但每个输出仍包含完整且不重复的 K 项。

## 4. 权重预处理与装载

### 4.1 通用公式

多精度模式的逻辑矩阵边长为 \(L=N\ell\)，预处理结果定义为

$$
P_{r,c}=B_{(r+c)\bmod L,c},
\qquad 0\le r,c<L.
$$

第 \(t\) 个装载拍选择的逻辑行号为

$$
p_t=L-1-t,
\qquad 0\le t<L,
$$

所以发送次序为

$$
P_{L-1},P_{L-2},\ldots,P_1,P_0.
$$

逆序发送使先到达的权重继续向下移动，最终让 \(P_0\) 留在物理第 0 行。

### 4.2 论文 3×3 装载过程

![[NPU/rtl/dip/docs/figures/weight_load_3x3.png]]

*图 3　3×3 权重按 \(P_2,P_1,P_0\) 的次序装载；最后一个权重拍与第一行 A 同时接收。*

| 周期 | PE row 0 | PE row 1 | PE row 2 | 同时发生 |
|---|---|---|---|---|
| Cycle -2 | \([c,d,h]\) | 空 | 空 | 接收 \(P_2\) |
| Cycle -1 | \([b,f,g]\) | \([c,d,h]\) | 空 | 接收 \(P_1\) |
| Cycle 0 | \([a,e,i]\) | \([b,f,g]\) | \([c,d,h]\) | 接收 \(P_0\) 和第一行 A |

### 4.3 多精度权重寄存器

每个物理列有一条独立的纵向串行移位路径，共 \(N\) 条路径并行工作。每条路径的有效深度为

$$
D_{\mathrm w}=N\ell=L.
$$

| 模式 | \(\ell\) | 每个 PE 使用的 slice | 每个物理列的装载拍数 |
|---|---:|---|---:|
| INT16 | 1 | `q0` | \(N\) |
| INT8 | 2 | `q0,q1` | \(2N\) |
| INT4 | 4 | `q0,q1,q2,q3` | \(4N\) |

将一个物理列内的寄存位置展平为

$$
g=\ell R+u,
\qquad 0\le g<L.
$$

令 \(W_{g,C,v}^{(t)}\) 表示完成 \(t\) 个装载拍后，位置 \(g\) 中输出 lane \(v\) 的权重。第 \(t\) 个装载沿之后

$$
W_{g,C,v}^{(t+1)}=
\begin{cases}
P_{L-1-t,\ell C+v},&g=0,\\
W_{g-1,C,v}^{(t)},&1\le g<L.
\end{cases}
$$

完成全部 \(L\) 拍后

$$
\begin{aligned}
W_{\ell R+u,C,v}^{(L)}
&=P_{\ell R+u,\ell C+v}\\
&=B_{\left(\ell(R+C)+u+v\right)\bmod L,\ell C+v}.
\end{aligned}
$$

这就是 PE \((R,C)\) 的 slice \(u\) 为输出 lane \(v\) 保存的权重。权重只在 `wshift_i=1` 时移动；计算期间 `wshift_i=0`，全部 `weight_q` 保持不变。

### 4.4 最后权重拍与第一行 A

| 上升沿  | 权重寄存器  | 数据寄存器            | 算术寄存器                           |
| ---- | ------ | ---------------- | ------------------------------- |
| `e0` | 写入最终权重 | `data_q` 写入第一行 A | 尚未写入该 token 的乘积                 |
| `e1` | 保持     | 可接收下一行 A         | `product_q` 写入 16 个基础乘积         |
| `e2` | 保持     | —                | `logical_product_q` 写入重组后的逻辑乘积 |
| `e3` | 保持     | —                | `contribution_o` 写入局部 K 求和结果 |
| `e4` | 保持     | —                | 第 0 物理行的 `psum_q` 更新 |

`product_q` 到 `e1` 才采样乘法器输出，因此 `e0` 写入的最终权重已经稳定一个完整组合计算周期。其后三个阶段依次读取 `product_q`、`logical_product_q` 和已寄存的 `contribution_o`，不再读取权重。

### 4.5 预处理存储

`dip_data_preprocess` 使用最大尺寸为 \(4N\times N\times16\) bit 的逻辑 B buffer，提供可综合、可仿真的功能参考。面向 SoC 集成时，可以用多 bank SRAM 和读地址发生器直接产生 \(P\)，并替换当前 buffer。

## 5. 多精度 PE 的数据选择

### 5.1 输出列、K 下标与局部贡献

物理列 \(C\) 的输出 lane \(v\) 对应逻辑输出列

$$
j(C,v)=\ell C+v.
$$

PE \((R,C)\) 中局部 K 编号 \(u\) 与输出编号 \(v\) 使用

$$
k(R,C,u,v)=\left(\ell(R+C)+u+v\right)\bmod L.
$$

单个逻辑乘法及 PE 局部贡献为

$$
\begin{aligned}
M_{R,C,u,v}
&=A_{m,k(R,C,u,v)}
\times B_{k(R,C,u,v),\ell C+v},\\
Q_{R,C,v}
&=\sum_{u=0}^{\ell-1}M_{R,C,u,v}.
\end{aligned}
$$

阵列沿物理行继续累加：

$$
C_{m,\ell C+v}
=\sum_{R=0}^{N-1}Q_{R,C,v}.
$$

对固定的 \((C,v)\)，\(\ell C+v\) 是常数偏移；\((R,u)\) 的全部组合使 \(\ell R+u\) 取遍 \(0,\ldots,L-1\)。加上常数并对 \(L\) 取余后，K 下标仍各出现一次，所以结果与普通 GEMM 相同。

### 5.2 本地物理字与同行右邻

记 PE \((R,C)\) 已寄存的 16-bit 数据字为 \(D_{R,C}^{(m)}\)，其中第 \(t\) 个 lane 满足

$$
D_{R,C,t}^{(m)}
=A_{m,\left(\ell(R+C)+t\right)\bmod L}.
$$

对 \((u,v)\) 令 \(z=u+v\)，操作数选择为

$$
X_{R,C,u,v}^{(m)}=
\begin{cases}
D_{R,C,z}^{(m)},&z<\ell,\\
D_{R,(C+1)\bmod N,z-\ell}^{(m)},&z\ge\ell.
\end{cases}
$$

因为 \(0\le u+v\le2\ell-2\)，一次选择最多跨过一个 16-bit 物理字。同行右邻来自另一 PE 的 `data_q`，源端已经寄存，不形成组合环。

最右侧物理列 \(C=N-1\) 的同行右邻为第 0 列：

$$
D_{\mathrm{neighbor}}[R,N-1]=D[R,0].
$$

物理行之间的数据移动为

$$
D_{R+1,C}^{(m)}=D_{R,(C+1)\bmod N}^{(m)}.
$$

因此，下一物理行的最右列同样接收上一物理行第 0 列的数据。

### 5.3 INT8 的 \((u,v)\) 示例

![[NPU/rtl/dip/docs/figures/int8_n2_uv_example.png]]

*图 4　\(N=2\)、INT8 时最右侧 PE \((R=0,C=1)\) 的四个 \((u,v)\) 乘法。*

图中 \(\ell=2\)、\(L=4\)。目标 PE 的本地字为 \([A_2,A_3]\)，同行右邻按模 2 回到第 0 列，因此右邻字为 \([A_0,A_1]\)。

| 输出编号 \(v\) | K 编号 \(u\) | \(z=u+v\) | A 来源 |
|---:|---:|---:|---|
| 0 | 0 | 0 | `self[0]` |
| 0 | 1 | 1 | `self[1]` |
| 1 | 0 | 1 | `self[1]` |
| 1 | 1 | 2 | `right[0]` |

### 5.4 INT4 的选择表

令 `Sx` 表示 `self[x]`，`Rx` 表示 `right[x]`：

| \(u\backslash v\) | 0 | 1 | 2 | 3 |
|---:|---|---|---|---|
| 0 | S0 | S1 | S2 | S3 |
| 1 | S1 | S2 | S3 | R0 |
| 2 | S2 | S3 | R0 | R1 |
| 3 | S3 | R0 | R1 | R2 |

INT4 的 16 个逻辑乘法中有 6 个读取同行右邻。INT16 只有 \((u,v)=(0,0)\)，始终读取本地 lane 0。

## 6. PE 算术微结构

### 6.1 4×4 基础乘法器

每个物理 PE 固定实例化 16 个 `dip_base_mul4`。对 \(w=4d\) bit 的二补码数 \(x\)，按 4-bit digit 分解为

$$
x=
\sum_{p=0}^{d-2}x_p2^{4p}
+\widetilde{x}_{d-1}2^{4(d-1)},
$$

其中 \(x_0,\ldots,x_{d-2}\) 按 unsigned 解释，最高 digit \(\widetilde{x}_{d-1}\) 按 signed 解释。对另一个操作数 \(y\) 同理，乘法重组为

$$
xy=
\sum_{p=0}^{d-1}
\sum_{q=0}^{d-1}
\left(x_py_q\right)2^{4(p+q)},
$$

其中涉及最高 digit 的基础乘法按相应 signed 属性扩展。

每个 PE 的逻辑乘法数为 \(\ell^2\)，每个 \(w\times w\) 逻辑乘法需要 \((w/4)^2\) 个 4×4 基础乘法，因此

$$
N_{\mathrm{base}}
=\ell^2\left(\frac{w}{4}\right)^2
=\left(\frac{16}{w}\right)^2
\left(\frac{w}{4}\right)^2
=16.
$$

三种模式都完整使用同一组 16 个基础乘法器。

| 模式 | 逻辑乘法/PE | 每个逻辑乘法的基础乘积数 | 总基础乘积数 |
|---|---:|---:|---:|
| INT16 | 1 个 16×16 | 16 | 16 |
| INT8 | 4 个 8×8 | 4 | 16 |
| INT4 | 16 个 4×4 | 1 | 16 |

### 6.2 局部重组与 K 求和

`dip_simd_dot_product` 的 Stage 1 产生 16 个 8-bit 基础乘积并写入 `product_q[0:15]`。Stage 2 按模式重组为 \(w\times w\) 元素乘积，并将 1、4 或 16 个有效结果写入 32-bit signed 的 `logical_product_q[0:15]`。本文以 \(LP\) 表示这一组寄存结果。

Stage 3 沿 \(u\) 对 `logical_product_q` 求和，并把每个输出 lane 的局部贡献写入 `contribution_o`。本文以 \(Q\) 表示该寄存结果。Stage 2 与 Stage 3 分别使用独立的组合加法树；Stage 4 的 `dip_segmented_adder64` 再把 \(Q\) 与上排部分和相加。

### 6.3 分段 64-bit 加法器

`dip_segmented_adder64` 实例化 16 个 `dip_base_add4`，并按模式阻断指定位置的进位：

| 模式 | 独立累加段 | 阻断进位的位置 |
|---|---|---|
| INT16 | `[63:0]` | 无 |
| INT8 | `[31:0]`、`[63:32]` | bit 32 |
| INT4 | `[15:0]`、`[31:16]`、`[47:32]`、`[63:48]` | bit 16、32、48 |

这组硬件分别执行 1×64 bit、2×32 bit 或 4×16 bit 的独立二补码加法。

### 6.4 回绕与截断

对 \(b\) bit 临时结果，RTL 的二补码回绕可写为

$$
\operatorname{wrap}_b(x)
=\left((x+2^{b-1})\bmod2^b\right)-2^{b-1}.
$$

阵列底部把每个有效累加段符号扩展到 64 bit 后写入 `c_accum_row_o`，同时把每段低 \(2w\) bit 写入 `c_row_o`：

$$
C_{m,j}
=\operatorname{wrap}_{2w}\left(S_{N-1,j}\right).
$$

例如，INT4 临时结果 204 在 16 bit 中为 `16'h00CC`；截取为 8 bit 后得到 `8'hCC`，按 signed 解释为 \(-52\)。

## 7. 四级算术寄存与输出时序

![[NPU/rtl/dip/docs/figures/pe_pipeline_and_alignment.png]]

*图 5　当前 PE 的四级算术寄存和相邻物理行的一拍错位。*

### 7.1 单 PE 寄存器时序

四级算术寄存不包含输入寄存器 D。对在 `e0` 写入 `data_q` 的同一个 A 行 token：

| 上升沿 | 使能 | 更新内容 | 上升沿前读取的内容 |
|---|---|---|---|
| `e0` | `pe_en_i` | `data_q`、`data_mode_q` | `data_i`、`mode_i` |
| `e1` | `mul_en_i` | `product_q[0:15]`、`product_mode_q` | 本地 `data_q`、同行右邻 `data_q`、静止权重 |
| `e2` | `reassemble_en_i` | `logical_product_q[0:15]`、`logical_product_mode_q` | `product_q`、`product_mode_q` |
| `e3` | `reduce_en_i` | `contribution_o`、`contribution_mode_o` | `logical_product_q`、`logical_product_mode_q` |
| `e4` | `adder_en_i` | `psum_q` | `contribution_o`、`contribution_mode_o`、`psum_i` |

四个组合阶段为

$$
\begin{aligned}
(\mathtt{data\_q},\mathtt{weight\_q})
&\xrightarrow{\;16\text{ 个基础乘法器}\;}
\mathtt{product\_q}\\
&\xrightarrow{\;\mathrm{radix\ 重组}\;}
\mathtt{logical\_product\_q}\\
&\xrightarrow{\;\text{局部 }K\text{ 求和}\;}
Q\\
&\xrightarrow{\;\text{分段 64-bit 加法}\;}
\mathtt{psum\_q}.
\end{aligned}
$$

模式与对应数据同步：

$$
\mathtt{data\_mode\_q}
\longrightarrow
\mathtt{product\_mode\_q}
\longrightarrow
\mathtt{logical\_product\_mode\_q}
\longrightarrow
\mathtt{contribution\_mode\_o}.
$$

`dip_segmented_adder64` 组合读取 `contribution_mode_o`，此处没有额外模式寄存级。权重只参与 Stage 1，不随 \(M\)、\(LP\)、\(Q\)、\(S\) 延迟。

### 7.2 valid 与跨物理行对齐

| 使能 | 作用 |
|---|---|
| `pe_en[R]` | 写入物理行 \(R\) 的 `data_q` |
| `mul_en[R]` | 将 16 个基础乘积写入 `product_q` |
| `reassemble_en[R]` | 将重组后的逻辑乘积写入 `logical_product_q` |
| `reduce_en[R]` | 将局部 K 求和结果写入 `contribution_o` |
| `adder_en[R]` | 将本地 \(Q\) 与上一物理行 \(S\) 写入 `psum_q` |

第 0 物理行没有上游部分和：

$$
\mathtt{adder\_en}[0]
=\mathtt{contribution\_valid\_q}[0].
$$

对 \(R>0\)：

$$
\mathtt{adder\_en}[R]
=\mathtt{contribution\_valid\_q}[R]
\land
\mathtt{psum\_valid\_q}[R-1].
$$

若第 \(m\) 个 A 行在上升沿 \(e_m\) 被顶行接收，则同一 token 在物理行 \(R\) 的更新时间为

| 寄存内容 | 更新时间 |
|---|---|
| `data_q[R]` | \(e_{m+R}\) |
| `product_q[R]` | \(e_{m+R+1}\) |
| `logical_product_q[R]` | \(e_{m+R+2}\) |
| `contribution_o[R]` | \(e_{m+R+3}\) |
| `psum_q[R]` | \(e_{m+R+4}\) |

对 \(R>0\)，本地 \(Q\) 与上一物理行 \(S\) 都在 \(e_{m+R+3}\) 更新，并在下一个上升沿前保持稳定，所以本行在 \(e_{m+R+4}\) 相加时读取的是同一个 token。RTL 使用非阻塞赋值；即使连续 A 行相邻到达，加法器仍读取上升沿前保存的两项，不会混合相邻 token。

令 \(V_A[n]\) 表示上升沿 \(n\) 是否接收 A 行，则

$$
\begin{aligned}
V_D(R,n)&=V_A[n-R],\\
V_M(R,n)&=V_A[n-R-1],\\
V_{LP}(R,n)&=V_A[n-R-2],\\
V_Q(R,n)&=V_A[n-R-3],\\
V_S(R,n)&=V_A[n-R-4].
\end{aligned}
$$

输入 valid 空拍会按相同形状延迟到输出。

### 7.3 逐周期独立图的阅读规则

下面采用与论文 Fig. 3 相同的主要表现方式：每张图片完整重画一次物理阵列，PE 位置固定，蓝色箭头表示 packed A，灰色箭头表示同列部分和，固定权重写在 PE 顶部，结果放在阵列底部。当前 RTL 比论文示例多两个算术寄存级，因此周期编号、PE 内寄存内容和首次输出时刻均按本目录 RTL 重新计算。

所有图片使用 `ARRAY_N=4`，从最终权重拍与 A 行 0 同时接收的 `e0` 开始，一张图片只表示一个上升沿后的状态，不把多个周期合并。A 行连续输入且不插入空拍。对图片中的任意物理行 \(R\)，五组有效寄存内容所属的 A 行号为

$$
\begin{aligned}
m_D&=e-R,\\
m_M&=e-R-1,\\
m_{LP}&=e-R-2,\\
m_Q&=e-R-3,\\
m_S&=e-R-4.
\end{aligned}
$$

只有满足 \(0\le m_D,m_M,m_{LP},m_Q,m_S<L\) 的寄存内容才有效。

因此同一个 PE 可以同时保存五个不同 A 行的 `data_q`、`product_q`、`logical_product_q`、`contribution_o` 和 `psum_q`。图片在 PE 框内同时列出五组当前有效内容；灰色短横线表示相应 valid 为 0。使能为 0 时，实际寄存器继续保留旧位值，但该旧值不属于当前有效 token。\(Q\) 明确表示触发器输出 `contribution_o`，不表示寄存器之间的组合中间值。

灰色竖箭头表示本上升沿到达前由上一物理行保存的 \(S\)，标签同时给出实际数值。例如 `e5` 写入物理行 1 的结果时，组合加法器读取 `e4` 后保持的 \(Q_{m,1}\) 和 \(S_{m,0}\)，随后在 `e5` 将

$$
\mathbf S_m^{(1)}
=\mathbf Q_m^{(1)}+\mathbf S_m^{(0)}
$$

写入物理行 1。读取动作本身不会清除上一物理行的 `psum_q`；若上一物理行的 `adder_en` 在同一上升沿也为 1，它会在该上升沿后改写为下一 token 的结果。蓝色斜箭头采用相同的上升沿定义，目标 PE 在该上升沿采样上一物理行的 `data_q`。

三组图共用以下小数值例子：

$$
\begin{aligned}
A[m,k]&=((3m+k)\bmod7)-3,\\
B[k,j]&=((2k+j)\bmod5)-2.
\end{aligned}
$$

A、B 的所有元素都在 INT4 可表示范围内。绘图脚本逐 PE 计算 packed A、\(LP\)、\(Q\)、\(S\) 和 C，并检查 \(LP\) 分组求和等于 \(Q\)，以及最底物理行的 \(S\) 等于普通 GEMM 结果。每张图右侧还给出五组 valid 的 `[R3:R0]` 值、本上升沿写入的部分和以及输出端口状态。

首个 C 行在

$$
e_{\mathrm{first}}=e_{N+3}=e_7
$$

更新，并在该上升沿后使 `c_row_valid_o=1`。默认 \(N=16\) 时，同一逐周期关系继续到 \(e_{19}\)。模式改变的是每个物理字包含的逻辑元素数以及完整 tile 的 A、C 行数，不改变首个 token 穿过 \(N\) 个物理行所需的拍数。

### 7.4 INT16：Cycle 0 至 Cycle 7

INT16 的 \(L=4\)，所以 A 行 0、1、2、3 分别在 `e0`、`e1`、`e2`、`e3` 接收；从 `e4` 开始不再接收新的 A 行。一个 PE 有一个有效的 32-bit `logical_product_q`，\(Q\) 和 \(S\) 都是一个 64-bit signed 值；`e7` 从四个物理列分别给出完整临时结果并截取低 32 bit。

#### Cycle 0：最终权重与 A 行 0 同拍写入

![[NPU/rtl/dip/docs/figures/cycle_traces/int16_n04/dip_int16_n04_compute_e000_post.png]]

*图 6(a)　INT16 Cycle 0：只有物理行 0 的 D 有效，四级算术寄存结果尚未产生。*

#### Cycle 1：首行基础乘积写入

![[NPU/rtl/dip/docs/figures/cycle_traces/int16_n04/dip_int16_n04_compute_e001_post.png]]

*图 6(b)　INT16 Cycle 1：物理行 0 同时保存 A 行 1 的 D 与 A 行 0 的 M；A 行 0 的 packed 数据已循环移入物理行 1。*

#### Cycle 2：首行逻辑乘积写入

![[NPU/rtl/dip/docs/figures/cycle_traces/int16_n04/dip_int16_n04_compute_e002_post.png]]

*图 6(c)　INT16 Cycle 2：物理行 0 得到 A 行 0 的 LP，物理行 1 得到对应 M，物理行 2 接收对应 D。*

#### Cycle 3：首个局部贡献写入

![[NPU/rtl/dip/docs/figures/cycle_traces/int16_n04/dip_int16_n04_compute_e003_post.png]]

*图 6(d)　INT16 Cycle 3：物理行 0 写入 A 行 0 的 Q；首个 token 的 D、M、LP、Q 分别位于四个物理行。*

#### Cycle 4：首个部分和写入物理行 0

![[NPU/rtl/dip/docs/figures/cycle_traces/int16_n04/dip_int16_n04_compute_e004_post.png]]

*图 6(e)　INT16 Cycle 4：物理行 0 写入 \(\mathbf S_0^{(0)}=\mathbf Q_0^{(0)}\)；灰色顶部箭头给出四列的 \(0+\mathbf Q_0^{(0)}\) 数值。*

#### Cycle 5：首个部分和进入物理行 1

![[NPU/rtl/dip/docs/figures/cycle_traces/int16_n04/dip_int16_n04_compute_e005_post.png]]

*图 6(f)　INT16 Cycle 5：灰色竖箭头给出物理行 0 的沿前 \(S\)，物理行 1 写入 \(\mathbf S_0^{(1)}=\mathbf Q_0^{(1)}+\mathbf S_0^{(0)}\)。*

#### Cycle 6：首个部分和进入物理行 2

![[NPU/rtl/dip/docs/figures/cycle_traces/int16_n04/dip_int16_n04_compute_e006_post.png]]

*图 6(g)　INT16 Cycle 6：物理行 2 写入 \(\mathbf S_0^{(2)}\)，物理行 3 保存同一 token 的 Q；此时 `c_row_valid_o=0`。*

#### Cycle 7：首行结果有效

![[NPU/rtl/dip/docs/figures/cycle_traces/int16_n04/dip_int16_n04_compute_e007_post.png]]

*图 6(h)　INT16 Cycle 7：物理行 3 写入 \(\mathbf S_0^{(3)}\)，`c_row_valid_o=1`；完整临时结果与四个 INT32 输出 \([4,3,-3,1]\) 同时显示。*

### 7.5 INT8：Cycle 0 至 Cycle 7

INT8 的 \(L=8\)。每个蓝色物理字包含两个 INT8；每个 PE 的 `product_q` 保存 16 个基础乘积，`logical_product_q` 有四个有效 32-bit signed 项，`contribution_o` 与 `psum_q` 分别保存两个 32-bit signed 段。到 `e7` 仍处于 A 输入阶段，阵列各排可以同时存在五个不同 token 的 D、M、LP、Q、S。

#### Cycle 0

![[NPU/rtl/dip/docs/figures/cycle_traces/int8_n04/dip_int8_n04_compute_e000_post.png]]

*图 7(a)　INT8 Cycle 0：A 行 0 以四个双 lane 物理字写入物理行 0。*

#### Cycle 1

![[NPU/rtl/dip/docs/figures/cycle_traces/int8_n04/dip_int8_n04_compute_e001_post.png]]

*图 7(b)　INT8 Cycle 1：A 行 0 向下一排循环移动一个完整 16-bit 物理字，物理行 0 同时接收 A 行 1。*

#### Cycle 2

![[NPU/rtl/dip/docs/figures/cycle_traces/int8_n04/dip_int8_n04_compute_e002_post.png]]

*图 7(c)　INT8 Cycle 2：A 行 0 的四个逻辑乘积 LP 首次写入物理行 0。*

#### Cycle 3

![[NPU/rtl/dip/docs/figures/cycle_traces/int8_n04/dip_int8_n04_compute_e003_post.png]]

*图 7(d)　INT8 Cycle 3：物理行 0 写入 A 行 0 的两个局部贡献段 Q，其他物理行继续处理同一 token 的 LP、M 与 D。*

#### Cycle 4

![[NPU/rtl/dip/docs/figures/cycle_traces/int8_n04/dip_int8_n04_compute_e004_post.png]]

*图 7(e)　INT8 Cycle 4：物理行 0 首次写入 A 行 0 的两个部分和段；顶部灰色箭头标明 \(0+Q\) 的实际值。*

#### Cycle 5

![[NPU/rtl/dip/docs/figures/cycle_traces/int8_n04/dip_int8_n04_compute_e005_post.png]]

*图 7(f)　INT8 Cycle 5：A 行 0 的两个部分和段进入物理行 1；阵列中 D、M、LP、Q、S 五组寄存内容持续处理不同 A 行。*

#### Cycle 6

![[NPU/rtl/dip/docs/figures/cycle_traces/int8_n04/dip_int8_n04_compute_e006_post.png]]

*图 7(g)　INT8 Cycle 6：A 行 0 的两个部分和段进入物理行 2，最底物理行保存对应 Q；`c_row_valid_o=0`。*

#### Cycle 7

![[NPU/rtl/dip/docs/figures/cycle_traces/int8_n04/dip_int8_n04_compute_e007_post.png]]

*图 7(h)　INT8 Cycle 7：最底物理行写入 A 行 0 的最终 S，`c_row_valid_o=1`；八个 INT16 结果为 \([-5,12,4,-4,-7,-5,12,4]\)。*

### 7.6 INT4：Cycle 0 至 Cycle 7

INT4 的 \(L=16\)。每个蓝色物理字包含四个 INT4；每个 PE 每拍形成 16 个 4×4 基础乘积，Stage 2 将其写为 16 个有效的 32-bit `logical_product_q`，\(Q\) 与 \(S\) 分成四个 16-bit signed 段，输出端从每段保留低 8 bit。

#### Cycle 0

![[NPU/rtl/dip/docs/figures/cycle_traces/int4_n04/dip_int4_n04_compute_e000_post.png]]

*图 8(a)　INT4 Cycle 0：A 行 0 以四个四 lane 物理字写入物理行 0。*

#### Cycle 1

![[NPU/rtl/dip/docs/figures/cycle_traces/int4_n04/dip_int4_n04_compute_e001_post.png]]

*图 8(b)　INT4 Cycle 1：A 行 0 的 packed 数据进入物理行 1，物理行 0 写入该行的 16 个基础乘积。*

#### Cycle 2

![[NPU/rtl/dip/docs/figures/cycle_traces/int4_n04/dip_int4_n04_compute_e002_post.png]]

*图 8(c)　INT4 Cycle 2：物理行 0 写入 A 行 0 的 16 个逻辑乘积 LP。*

#### Cycle 3

![[NPU/rtl/dip/docs/figures/cycle_traces/int4_n04/dip_int4_n04_compute_e003_post.png]]

*图 8(d)　INT4 Cycle 3：物理行 0 写入 A 行 0 的四段局部贡献 Q；首个 token 的 D、M、LP、Q 分别位于四个物理行。*

#### Cycle 4

![[NPU/rtl/dip/docs/figures/cycle_traces/int4_n04/dip_int4_n04_compute_e004_post.png]]

*图 8(e)　INT4 Cycle 4：物理行 0 首次写入四段 S，顶部灰色箭头给出四列的 \(0+Q\) 数值。*

#### Cycle 5

![[NPU/rtl/dip/docs/figures/cycle_traces/int4_n04/dip_int4_n04_compute_e005_post.png]]

*图 8(f)　INT4 Cycle 5：物理行 1 读取上排四段沿前 S，并与本地四段 Q 相加。*

#### Cycle 6

![[NPU/rtl/dip/docs/figures/cycle_traces/int4_n04/dip_int4_n04_compute_e006_post.png]]

*图 8(g)　INT4 Cycle 6：物理行 2 完成 A 行 0 的第三次纵向累加，物理行 3 保存对应 Q；`c_row_valid_o=0`。*

#### Cycle 7

![[NPU/rtl/dip/docs/figures/cycle_traces/int4_n04/dip_int4_n04_compute_e007_post.png]]

*图 8(h)　INT4 Cycle 7：物理行 3 写入最终 S，`c_row_valid_o=1`；十六个 INT8 结果为 \([-2,3,13,-2,-12,-2,3,13,-2,-12,-2,3,13,-2,-12,-2]\)。*

三种模式的逐周期图由 [`docs/figures/generate_rtl_cycle_traces.py`](./docs/figures/generate_rtl_cycle_traces.py) 生成。每个模式目录同时包含八张 PNG、对应 SVG 和 `trace_manifest.json`；README 仅嵌入 PNG。

```bash
python3 rtl/dip/docs/figures/generate_rtl_cycle_traces.py
```

该命令需要系统已安装 `inkscape`，脚本会直接生成 SVG 和 PNG。

### 7.7 连续结果与完整 tile

第 \(m\) 个 C 行的有效上升沿为

$$
e_C(m)=e_{m+N+3},
\qquad 0\le m<L.
$$

因此

$$
e_{\mathrm{first}}=e_{N+3},
\qquad
e_{\mathrm{last}}=e_{L+N+2}.
$$

连续输入时

$$
e_C(m+1)-e_C(m)=1,
$$

所以流水充满后每周期输出一行 C。由 `e0` 到最后一行 C 有效的时钟差为

$$
\Delta_{\mathrm{tile}}=L+N+2.
$$

| 模式 | \(L\) | \(\Delta_{\mathrm{tile}}\) | 默认 \(N=16\) 的末行 |
|---|---:|---:|---:|
| INT16 | \(N\) | \(2N+2\) | `e34` |
| INT8 | \(2N\) | \(3N+2\) | `e50` |
| INT4 | \(4N\) | \(5N+2\) | `e82` |

该区间不包含原始 B 的接收，也不包含最终权重拍之前的 \(L-1\) 个权重装载拍。

## 8. `N=2`、INT8 完整数值例子

取

$$
A=
\begin{bmatrix}
1&2&3&4
\end{bmatrix},
\qquad
B=
\begin{bmatrix}
1&2&3&4\\
5&6&7&8\\
9&10&11&12\\
13&14&15&16
\end{bmatrix}.
$$

两个 16-bit A 物理字为

| 物理列 | lane 0 | lane 1 | 物理字 |
|---:|---:|---:|---:|
| 0 | 1 | 2 | `16'h0201` |
| 1 | 3 | 4 | `16'h0403` |

预处理后的权重为

$$
P=
\begin{bmatrix}
1&6&11&16\\
5&10&15&4\\
9&14&3&8\\
13&2&7&12
\end{bmatrix},
$$

发送次序为 \(P_3,P_2,P_1,P_0\)。四拍结束后：

| PE | `q0` 的 \([v0,v1]\) | `q1` 的 \([v0,v1]\) |
|---|---|---|
| \((0,0)\) | \([1,6]\) | \([5,10]\) |
| \((0,1)\) | \([11,16]\) | \([15,4]\) |
| \((1,0)\) | \([9,14]\) | \([13,2]\) |
| \((1,1)\) | \([3,8]\) | \([7,12]\) |

每个 PE 的两个局部结果为

| PE | 输出 lane 0 | 输出 lane 1 |
|---|---:|---:|
| \((0,0)\) | \(1\times1+2\times5=11\) | \(2\times6+3\times10=42\) |
| \((1,0)\) | \(3\times9+4\times13=79\) | \(4\times14+1\times2=58\) |
| \((0,1)\) | \(3\times11+4\times15=93\) | \(4\times16+1\times4=68\) |
| \((1,1)\) | \(1\times3+2\times7=17\) | \(2\times8+3\times12=52\) |

同一物理列纵向相加：

$$
\begin{aligned}
C
&=[11+79,\;42+58,\;93+17,\;68+52]\\
&=[90,\;100,\;110,\;120].
\end{aligned}
$$

直接计算普通 GEMM 可得

$$
\begin{aligned}
C_0&=1\times1+2\times5+3\times9+4\times13=90,\\
C_1&=1\times2+2\times6+3\times10+4\times14=100,\\
C_2&=1\times3+2\times7+3\times11+4\times15=110,\\
C_3&=1\times4+2\times8+3\times12+4\times16=120.
\end{aligned}
$$

最终两个 32-bit 输出字为

| 物理列 | lane 内容（高位到低位） | `c_row_o` 位段 |
|---:|---|---|
| 0 | \(\{\mathrm{INT16}(100),\mathrm{INT16}(90)\}\) | `32'h0064_005A` |
| 1 | \(\{\mathrm{INT16}(120),\mathrm{INT16}(110)\}\) | `32'h0078_006E` |

## 9. RTL 模块与文件

| 文件 | 层次 | 职责 |
|---|---|---|
| [`dip_base_mul4.sv`](./dip_base_mul4.sv) | 基础算术 | 可配置 signed 属性的 4×4 乘法 |
| [`dip_base_add4.sv`](./dip_base_add4.sv) | 基础算术 | 带进位输入、输出的 4-bit 加法 |
| [`dip_simd_dot_product.sv`](./dip_simd_dot_product.sv) | PE 算术 | 16 个基础乘法、逻辑乘积重组、局部 K 求和及三个内部寄存层 |
| [`dip_segmented_adder64.sv`](./dip_segmented_adder64.sv) | PE 算术 | 1×64、2×32、4×16 分段加法 |
| [`dip_pe.sv`](./dip_pe.sv) | PE | 数据、权重、基础乘积、逻辑乘积、局部贡献与部分和寄存 |
| [`dip_systolic_array.sv`](./dip_systolic_array.sv) | 阵列 | \(N\times N\) PE、对角数据连接、纵向权重和部分和 |
| [`dip_data_preprocess.sv`](./dip_data_preprocess.sv) | 预处理 | 接收 B、产生 \(P\)、逆序发送 |
| [`dip_gemm_core.sv`](./dip_gemm_core.sv) | 顶层 | 模式锁存、tile 控制、A/B/C 计数与完成信号 |
| [`tb/gen_random_vectors.py`](./tb/gen_random_vectors.py) | 黄金模型 | 生成可重复的三模式随机 GEMM |
| [`tb/tb_dip_pe.sv`](./tb/tb_dip_pe.sv) | 测试 | PE 算术、时序、右邻选择与截断 |
| [`tb/tb_dip_data_preprocess.sv`](./tb/tb_dip_data_preprocess.sv) | 测试 | 权重预处理、逆序发送与停顿 |
| [`tb/tb_dip_gemm_core.sv`](./tb/tb_dip_gemm_core.sv) | 测试 | Python 向量驱动的完整 tile |
| [`tb/tb_dip_gemm_n1.sv`](./tb/tb_dip_gemm_n1.sv) | 测试 | \(N=1\) 特例 |
| [`docs/figures/generate_rtl_cycle_traces.py`](./docs/figures/generate_rtl_cycle_traces.py) | 文档工具 | 校验数值例子并生成三种模式的逐周期 SVG、PNG 与清单 |

`dip_pe` 的固定宽度端口为

| 端口 | 宽度 | 说明 |
|---|---:|---|
| `data_i/data_neighbor_i/data_o` | 16 | 本地数据、同行右邻数据、对角输出 |
| `weight_i/weight_o` | 16 | 纵向权重移位 |
| `psum_i/psum_o` | 64 | 纵向临时部分和 |
| `mode_i` | 2 | 算术拆分方式 |
| `wshift_i` | 1 | 权重寄存使能 |
| `pe_en_i` | 1 | 输入寄存使能 |
| `mul_en_i` | 1 | 基础乘积寄存使能 |
| `reassemble_en_i` | 1 | 逻辑乘积寄存使能 |
| `reduce_en_i` | 1 | 局部贡献寄存使能 |
| `adder_en_i` | 1 | 临时部分和寄存使能 |

## 10. Python 向量与 Verilator 验证

### 10.1 随机向量

`tb/gen_random_vectors.py` 生成可重复的 signed A/B 随机矩阵，并按 RTL 的临时位宽逐项回绕，最后截取到输出位宽。默认覆盖 INT16、INT8、INT4，并插入最小负数、最大正数、\(-1,0,1\) 等典型值。

从 `NPU` 目录生成默认向量：

```bash
python3 rtl/dip/tb/gen_random_vectors.py \
  --array-n 16 \
  --tiles-per-mode 2 \
  --seed 20250727 \
  --output /tmp/dip_vectors.txt
```

只生成 INT8 和 INT4：

```bash
python3 rtl/dip/tb/gen_random_vectors.py \
  --array-n 4 \
  --modes int8 int4 \
  --no-corners
```

向量文件按纯十进制记录：

| 次序 | 记录数 | 字段 |
|---:|---:|---|
| 文件头 | 1 行 | `version physical_n tile_count seed` |
| tile 元数据 | 每 tile 1 行 | `tile_id precision_bits lanes logical_n input_bits accumulator_bits output_bits` |
| A | 每 tile \(L\) 行 | 每行 \(L\) 个 signed 十进制元素 |
| B | 每 tile \(L\) 行 | 每行 \(L\) 个 signed 十进制元素 |
| 期望 C | 每 tile \(L\) 行 | 每行 \(L\) 个 signed 十进制元素 |

### 10.2 运行测试

```bash
make -C rtl/dip lint
make -C rtl/dip test
```

单独运行：

```bash
make -C rtl/dip pe-test
make -C rtl/dip preprocess-test
make -C rtl/dip random-vectors
make -C rtl/dip gemm-test
make -C rtl/dip n1-test
```

扩大随机测试：

```bash
make -C rtl/dip gemm-test \
  VECTOR_SEED=12345 \
  TILES_PER_MODE=10
```

### 10.3 覆盖内容

- 三种模式的 radix 乘积重组、局部 K 求和与分段临时累加；
- signed 极值、二补码回绕与最终截断；
- INT8、INT4 的同行右邻选择以及最右列循环回接；
- 三种模式的权重预处理、逆序装载和 ready/valid 停顿；
- 最后一个权重拍与第一行 A 同拍接收；
- Python 生成的完整随机 GEMM；
- 四级算术寄存后的 \(2N+2\)、\(3N+2\)、\(5N+2\) tile 时钟差；
- 连续 A 输入时 C 保持每周期一行；
- A/B valid 空拍、连续 tile、`last/done/busy`；
- `ARRAY_N=1` 特例、异步复位和保留 mode。

### 10.4 测试结果

| 目标 | 测试对象 | 结果 |
|---|---|---|
| `pe-test` | `tb_dip_pe` | PASS |
| `preprocess-test` | `tb_dip_data_preprocess` | PASS |
| `gemm-test` | `tb_dip_gemm_core` 与 Python 向量 | PASS |
| `n1-test` | `tb_dip_gemm_n1` | PASS |

## 11. 与论文原型的差异

| 项目 | 论文原型 | 当前 RTL |
|---|---|---|
| 主要精度 | INT8 | INT16、INT8、INT4 |
| 物理 PE 每周期工作量 | 一个逻辑 MAC | 1、4、16 个逻辑乘法 |
| MAC 流水 | 二级 | 四级算术寄存 |
| 权重准备 | 软件预处理或存储器读次序调整 | RTL buffer 功能参考 |
| 3×3 首个结果 | Cycle 3 结束，按本文上升沿记法为 `e4` | \(e_{N+3}=e6\) |
| 逻辑矩阵边长 | \(N\) | \(L=N\ell\) |

论文给出的 DiP 单 tile 延迟为

$$
T_{\mathrm{DiP}}=2N+S-2,
$$

其中 \(S\) 为 MAC 算术寄存级数，论文采用 \(S=2\)。当前 RTL 的输入与输出行数为 \(L\)，四级算术寄存对应

$$
T_{\mathrm{RTL}}
=L+N+S-2
=L+N+2.
$$

论文图中的 Cycle 表示周期区间，本文的 \(e_n\) 表示上升沿。论文 3×3 首个结果在 Cycle 3 结束后可见，对应本文记法中的 `e4`；当前四级 RTL 在 `e6` 更新，增加两拍。

论文在 22 nm、INT8 和特定阵列规模下给出的面积、功耗与性能数据不能直接用于当前多精度 PE。当前设计增加了 radix 重组、局部 K 求和、更宽临时累加器和额外寄存器，需要重新综合、布局布线并测量。

## 12. 当前约束

- 顶层一次处理一个完整方形 tile；非整除尾块由上游补零，并丢弃超出有效尺寸的结果。
- 多个 K tile 的临时结果需要在阵列外合并。
- C 输出没有 `ready`，不能暂停输出。
- 当前 core 不重叠下一 B tile 的预取和当前 tile 计算。
- 最终输出采用低位截取和二补码回绕，不执行饱和或舍入。
- 第 0 列到最右列的循环连接可能形成较长物理连线，但源端为 `data_q`，终点为下一数据寄存器或 `product_q`，不存在组合环。
- 当前预处理 buffer 是功能参考，产品实现通常替换为 SRAM bank 和读地址控制。
- `reset_n` 为低有效异步复位。

## 参考文献

[1] A. J. Abdelmaksoud, S. Agwa, and T. Prodromakis, “DiP: A Scalable, Energy-Efficient Systolic Array for Matrix Multiplication Acceleration,” arXiv:2412.09709v2, Jul. 2025.
