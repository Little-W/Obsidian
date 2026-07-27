# DiP 脉动阵列 RTL（INT16）

本目录实现论文 *DiP: A Scalable, Energy-Efficient Systolic Array for
Matrix Multiplication Acceleration* 中的 Diagonal-Input and Permutated
weight-stationary 数据流，并按工程要求使用：

- 有符号 `int16 × int16 → int32` 乘法；
- 有符号 32 位部分和与输出；
- 两级流水 MAC（乘法寄存器、加法寄存器）；
- 参数化 `ARRAY_N × ARRAY_N` 方阵。

论文硬件评估采用 INT8；本实现的 INT16/INT32 位宽是按本项目需求做的
扩展，因此不能直接复用论文中的面积和功耗数据。

## 1. 目录

```text
rtl/dip/
├── dip_pe.sv                    # 单个两级流水 MAC PE
├── dip_systolic_array.sv        # 参数化 DiP PE 阵列
├── dip_data_preprocess.sv       # 权重分 bank 缓存、置换及逆序装载
├── dip_gemm_core.sv             # 预处理、阵列和 tile 控制顶层
├── tb/
│   ├── tb_dip_pe.sv
│   ├── tb_dip_data_preprocess.sv
│   └── tb_dip_gemm_core.sv
└── Makefile
```

## 2. DiP 数据映射

一个 tile 计算：

```text
C[m,c] = sum(k=0..N-1) A[m,k] * B[k,c]
```

论文 Algorithm 1 对 B 的每一列做循环上移：

```text
P[r,c] = B[(r+c) mod N,c]
```

最终 `PE(r,c)` 驻留 `P[r,c]`。输入从一个 PE 行移动到下一行时循环
左移一位：

```text
input[r,c] = input[r-1,(c+1) mod N]
```

因此 `PE(r,c)` 同时取得：

```text
A[m,(r+c) mod N] 和 B[(r+c) mod N,c]
```

部分和沿列向下累加，底行直接产生正常列序的 `C[m,c]`，不需要论文
所比较的输入/输出同步 FIFO。

### 权重实际装载顺序

权重寄存器从阵列顶行向下 shift，所以不能按 `P[0]` 到 `P[N-1]`
装载，而要逆序输出：

```text
load[q,c] = B[(N-1-q+c) mod N,c], q = 0..N-1
```

论文 3×3 示例为：

```text
B = [a d g]       实际顶端装载流：
    [b e h]       [c d h] -> [b f g] -> [a e i]
    [c f i]
```

`dip_data_preprocess` 用 `N` 个逻辑 column bank 表示
`bank[c][k] = B[k,c]`，先接收 N 行原始 B，再按上述地址公式并行读出。
输出支持 ready/valid 背压。

> 论文建议在软件中预置换，或通过已有多 bank 存储器重排读地址。
> 本模块内的 `N²` 个 INT16 tile buffer 是可综合的功能参考实现，
> 不属于论文 DiP 阵列的 PPA 统计范围。实际 SoC 集成时，可以用 SRAM
> bank/地址发生器替换该 buffer，或由软件直接提供正确的装载流。

## 3. PE

`dip_pe` 包含四个带使能寄存器：

| 寄存器 | 位宽 | 使能 | 行为 |
|---|---:|---|---|
| 输入 | 16 | `pe_en_i` | 锁存 signed INT16 输入 |
| 权重 | 16 | `wshift_i` | 锁存并向下一 PE 行转发权重 |
| 乘积 | 32 | `mul_en_i` | signed INT16 × INT16 |
| 部分和 | 32 | `adder_en_i` | signed INT32 加法 |

等价时序行为：

```systemverilog
if (wshift_i)   weight_q  <= weight_i;
if (pe_en_i)    data_q    <= data_i;
if (mul_en_i)   product_q <= $signed(data_q) * $signed(weight_q);
if (adder_en_i) psum_q    <= $signed(psum_i) + $signed(product_q);
```

无使能时寄存器保持，以减少无效翻转。32 位累加溢出采用二补码回绕；
论文没有定义饱和或异常协议。

## 4. 接口

所有 packed row bus 都把第 0 列放在最低位：

```text
row[col] = row_bus[col*WIDTH +: WIDTH]
```

### `dip_data_preprocess`

| 接口 | 说明 |
|---|---|
| `raw_valid_i/raw_ready_o` | 每次握手接收 B 的一行，共 N 行 |
| `raw_row_i` | N 个 signed INT16，原始 B 行 |
| `permuted_valid_o/permuted_ready_i` | 阵列装载流握手 |
| `permuted_row_o` | N 个已置换且按物理装载顺序排列的权重 |
| `permuted_last_o` | 当前拍是第 N 个装载行 |
| `busy_o/done_o` | 模块忙；一次装载流完成脉冲 |

### `dip_systolic_array`

| 接口 | 说明 |
|---|---|
| `weight_valid_i` | 全阵列共享 `wshift`，有效时装载一行权重 |
| `weight_row_i` | N 个 signed INT16 权重 |
| `data_valid_i` | 顶部 A 行有效；允许插入气泡 |
| `data_row_i` | N 个 signed INT16 输入 |
| `result_valid_o` | 底行 N 个结果同时有效 |
| `result_row_o` | N 个 signed INT32 结果 |

阵列内部自动生成按 PE 行共享的 `pe_en`、`mul_en` 和 `adder_en`。
输出端没有 ready；增加输出背压需要冻结整个阵列的 valid 和所有 PE
寄存器，不能只阻塞底行。

### `dip_gemm_core`

顶层依次接收一个完整 `N×N` B tile 和一个完整 `N×N` A tile：

| 接口 | 说明 |
|---|---|
| `b_raw_row_valid_i/b_raw_row_ready_o` | 原始 B 行输入 |
| `a_row_valid_i/a_row_ready_o` | A 行输入 |
| `c_row_valid_o/c_row_o` | C 行输出，输出无背压 |
| `c_row_last_o` | 当前是该 tile 最后一行 |
| `busy_o` | 已开始接收 B 或正在计算/排空 |
| `tile_done_o` | 最后一个 C 行完成后产生一个时钟周期脉冲 |

控制器让最后一个权重装载行和第一个 A 行在同一上升沿握手，与论文
Fig. 3 的 Cycle 0 行为一致。输入 valid 可以有气泡，内部 valid 会沿
对角数据通路传播。

## 5. 时序

设最后一个权重装载行和 `A[0,:]` 在上升沿 `e0` 同时被接收，两级
MAC 的边沿时序为：

```text
e0    : row 0 锁存 A[0,:]
e1    : row 0 乘法；A[0,:] 进入 row 1
e2    : row 0 加法；row 1 乘法
...
e(N+1): C[0,:] 有效
e(2N) : 连续输入时 C[N-1,:] 有效
```

从 `e0` 到最后结果经过 `2N` 个时钟，等价于论文对二级 MAC 给出的
`Latency = 2N`。论文把边沿后的区间编号为 Cycle，所以图中 3×3
结果标在 Cycle 3、4、5，而本 README 用上升沿编号避免歧义。

论文的计算延迟不含 Cycle 0 之前的 `N-1` 个权重预装载周期。本参考
顶层还先接收原始 B 到 tile buffer，因此从原始 B 接口观察到的冷启动
时间也包含 N 拍 buffer 填充。

## 6. Verilator 验证

已使用 Verilator 5.040 进行 lint 和自检仿真：

```bash
make -C rtl/dip lint
make -C rtl/dip test
```

也可以单独运行：

```bash
make -C rtl/dip pe-test
make -C rtl/dip preprocess-test
make -C rtl/dip gemm-test
make -C rtl/dip n1-test
```

测试覆盖：

- PE signed INT16 乘法、INT32 累加、寄存器使能保持和异步复位；
- 3×3 非 2 次幂取模置换、逆序装载、负数和输出背压保持；
- 论文 3×3 数值例，其中：

  ```text
  A = B = [1 2 3; 4 5 6; 7 8 9]
  C = [30 36 42; 66 81 96; 102 126 150]
  ```

- signed INT16 tile、A 输入 valid 气泡、连续两个 tile 的状态复用；
- 连续 3×3 tile 从首个 A 握手到末行 C 的 `2N` 周期延迟断言；
- `ARRAY_N=1` 参数边界及 INT16 最大乘积；
- `c_row_last_o`、`tile_done_o` 和返回权重接收状态。

成功日志应包含：

```text
tb_dip_pe: PASS
tb_dip_data_preprocess: PASS
tb_dip_gemm_core: PASS
tb_dip_gemm_n1: PASS
```

## 7. 当前边界

- 顶层一次处理完整的方形 `N×N×N` tile；
- 非整除尾块应在上游对 A/B 做零填充，并丢弃越界 C 元素；
- 多个 K tile 的部分结果需要在阵列外累加；
- 不支持 C 输出背压；
- 不在当前 core 内重叠下一 B tile 的预取与当前 tile 计算；
- `reset_n` 为低有效异步复位。
