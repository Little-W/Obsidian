# NPU 验证：从 BT 到算子

## 文档目标

本文面向模块级验证工程师，聚焦两个核心问题：

1. 模型算子在语义上做了什么。
2. 算子如何映射到硬件模块与指令链路。

写作顺序采用“模型语义 -> 算子分类 -> 硬件映射 -> 验证关注点”，目标是提供可复用的分析框架，而不是零散记忆单条指令。

## 阅读建议

1. 先看第 1-2 章，建立 GEMM/Conv 的主计算路径。
2. 再看第 3 章，理解布局和重排为什么影响性能与正确性。
3. 然后看第 4-6 章，建立算子到硬件模块的映射关系。
4. 最后看第 7-8 章，形成误差分析与验证回归方法。

## 术语与模块约定

- AILS：负责调度、搬运组织、tile 级数据编排。
- Matrix：核心乘加计算阵列（GEMM 主引擎）。
- PPROC：后处理模块，承担元素级处理、部分量化相关处理。
- VA：向量/归一化类计算模块（如 softmax、layernorm 路径）。
- DMA/CP：数据搬运与重排模块（split/permute/padding 等）。

## 0. NPU 在端侧推理中的定位

端侧 NPU 关注点不是训练能力，而是：

- 在有限面积、带宽、功耗下提升吞吐与时延表现。
- 对主干算子（GEMM、Conv、元素级、归一化、量化）做工程最优化。
- 在精度可接受范围内，最大化能效比（performance per watt）。

背景资料：

- 算力基础：https://ncnkvwuxka57.feishu.cn/wiki/KjAcwiCi0iwXyOkJZ0KcZmpvnic
- 训练与推理硬件差异：https://ncnkvwuxka57.feishu.cn/wiki/BROfwVdWtiye4ak8y28cRRGnn3c

---

## 1. 矩阵乘法（GEMM）：核心计算基元

### 1.1 数学定义

给定 $A \in \mathbb{R}^{M \times K}$、$B \in \mathbb{R}^{K \times N}$，输出为：

$$
C_{m,n}=\sum_{k=0}^{K-1}A_{m,k}\cdot B_{k,n}
$$

几乎所有主流推理算子都可归约为 GEMM 或 GEMM 变体（Linear、Conv 展开后、Attention 中 QK^T 和 AV 等）。

![矩阵乘法基础示意](https://ncnkvwuxka57.feishu.cn/space/api/box/stream/download/asynccode/?code=YTE1NzQ3OWJmZjIyOTNjM2EwOGYyZTlmMTIxNzFmZmFfaktlNURQVHZPRE1kdzFJSkF6NmZsWGJSaDhLSm8zelZfVG9rZW46SE5hTGJEcHRKb0Q4SFJ4dDhDdWN4QmpvblBlXzE3NzU3MTk2MTE6MTc3NTcyMzIxMV9WNA)

![矩阵乘法三层循环过程示意](https://ncnkvwuxka57.feishu.cn/space/api/box/stream/download/asynccode/?code=NDA0MDJkZTVjNDNmNzA2NzJlNjQ2NzI2ZWEyZWExOTRfWDN0RFpCdTNMZEFVUDBBWWVCY0tSYVl3d3FLd0ZJY01fVG9rZW46U1JqSWJEN3dNbzdRUjB4QmNkc2N2VXdibllnXzE3NzU3MTk2MTE6MTc3NTcyMzIxMV9WNA)

### 1.2 软件到硬件的实现差异

软件层可视作 3 重循环 MAC；硬件层实际是 tile/block 级并行，典型流程：

1. AILS 按 tile 组织 A/B 子块并送入 Matrix。
2. Matrix 执行高吞吐乘累加。
3. 结果 tile 交给 PPROC 进行后处理或 bypass。
4. AILS 负责结果回写与下一轮调度。

关键结论：硬件不是“按元素计算”，而是“按 tile 流水执行”。验证中要重点对齐 tile 边界与累加边界行为。

![分块 tile 与矩阵单元协同示意](https://ncnkvwuxka57.feishu.cn/space/api/box/stream/download/asynccode/?code=NGMxN2U2Yzc3MWU2ODQ3ZWMxNjRlNTMwZmIwOWFmNjJfczFwT2ZhZ3dIbFVpckNqNHViT3lVU1kzM1VVNUxRUGxfVG9rZW46UnBxMGJuTFFwb0VLSEZ4MVg4b2Nvb3BabkRjXzE3NzU3MTk2MTE6MTc3NTcyMzIxMV9WNA)

参考：

- TPU 脉动阵列讲解：https://www.bilibili.com/video/BV12P411W7YC/?share_source=copy_web&vd_source=86657b9ca69d2f971499275f09bfcec2

### 1.3 GEMM 验证关注点

- 维度一致性：$A(M,K)$ 与 $B(K,N)$ 的 K 维必须一致。
- tile 拼接正确性：跨 tile 累加顺序是否正确。
- 边界块处理：尾块（不足整 tile）是否补零/掩码正确。
- 累加精度：混合精度路径（如 INT8 accumulate 到 INT32）是否按规格。

---

## 2. 卷积到 GEMM：展开、计算、恢复

### 2.1 卷积本质

卷积是“滑动窗口上的局部乘加”。
对硬件而言，核心不是“是否支持 Conv 指令名”，而是“是否稳定完成卷积到规则矩阵乘的映射”。

二维卷积输出尺寸公式：

$$
H_{out}=\left\lfloor\frac{H+2P_h-D_h\cdot(K_h-1)-1}{S_h}+1\right\rfloor,
\quad
W_{out}=\left\lfloor\frac{W+2P_w-D_w\cdot(K_w-1)-1}{S_w}+1\right\rfloor
$$

### 2.2 工程通路：im2col -> GEMM -> col2im

- im2col：将滑动窗口展开成规则矩阵，换取规整访存与并行度。
- GEMM：复用 Matrix 高吞吐算力。
- 输出恢复：按目标张量布局回填输出。

本质上 1D/2D/3D 卷积都可抽象成该三段式流程。

### 2.3 在本硬件中的模块职责

- AILS：负责展开与数据组织。
- Matrix：执行核心乘加。
- PPROC：做后处理和格式整理。

结论：Matrix/PPROC 往往不需要显式感知“当前是 Conv 模式”，它们只处理被组织好的 tile 流。

参考：

- CNN 基础讲解：https://www.bilibili.com/video/BV1XcWDemE1F/?p=2&share_source=copy_web&vd_source=86657b9ca69d2f971499275f09bfcec2
- im2col 文章：https://zhuanlan.zhihu.com/p/7920043962

---

## 3. 数据排布与张量重排

### 3.1 维度语义与内存排布是两件事

- 维度语义：张量逻辑结构（N、C、H、W）。
- 内存排布：数据在地址空间中的线性组织。

排布决定访存连续性、cache 命中、DMA 事务粒度与带宽利用率。

![张量维度与内存组织示意](https://ncnkvwuxka57.feishu.cn/space/api/box/stream/download/asynccode/?code=NDFmMzQ0NzFmYTZhMTBhZDQ2NDkyNTllYmY3OWE4NDNfQmVpYkQyb1NyNjJTalAzNDRkWlBKTDNMVjlzR1M1U2hfVG9rZW46Q2lhN2Jpc3Fab0hMT1J4ZjB3Y2NORlZ5bmZwXzE3NzU3MTk2MTE6MTc3NTcyMzIxMV9WNA)

### 3.2 常见排布

- NCHW：GPU/CUDA 生态常见，卷积优化成熟。
- NHWC：CPU/移动端常见，像素内通道连续，缓存友好。

两种排布可以从“线性地址映射”直接看出差异。设张量形状为 $(N,C,H,W)$，元素类型大小为 $s$ 字节，忽略 batch 跨距时：

- NCHW 的线性偏移（按元素计）可写为：

$$
\mathrm{offset}_{\mathrm{NCHW}}=((c\cdot H+h)\cdot W+w)
$$

对应字节地址增量为 $\mathrm{offset}\cdot s$。其特点是同一通道内的 $H/W$ 连续，适合卷积核在空间维做滑窗。

- NHWC 的线性偏移（按元素计）可写为：

$$
\mathrm{offset}_{\mathrm{NHWC}}=((h\cdot W+w)\cdot C+c)
$$

其特点是同一像素点的通道连续，适合 CPU/向量单元按像素打包加载。

工程上可按以下经验选择：

1. 若主要算子是卷积/GEMM 且后端对 NCHW 优化充分，优先 NCHW。
2. 若目标是移动端 CPU 或需要高效逐像素后处理，优先 NHWC。
3. 若链路跨多个后端，优先减少中间转置次数，而不是只看单算子峰值性能。

验证时建议显式覆盖 NCHW <-> NHWC 互转：

- 关注维度元数据是否同步更新。
- 关注 stride/step 是否与新布局一致。
- 关注量化逐通道参数在变换后是否仍对齐到正确通道。

### 3.3 分块表达法（建议统一）

建议统一采用“从外到内”的箭头表达法，例如：

- 原始：`n -> c -> h -> w`
- C 方向按 32 分块：`n -> c/32 -> h -> w -> 32`

最右侧维度可理解为最内层访问方向，有助于快速推断循环嵌套与访存步长。

![通道切分与分块排布局示意](https://ncnkvwuxka57.feishu.cn/space/api/box/stream/download/asynccode/?code=NDlkODZiMTE1OTRiMmRiZjkxMGUyMTczZGYyMWZkM2JfUWF2OExKNGl1N0FYb2VFSThYeWJscE93Y1ZqZjU4SDlfVG9rZW46V3hDdmJXdUVmb2VkdHB4MXh2RGNZcTRZbldoXzE3NzU3MTk2MTE6MTc3NTcyMzIxMV9WNA)

### 3.4 DMA 视角下的 `NSliceHWC32` 内存排布

DMA spec 中提到 DMA 可以将一个一至五维的 `NSliceHWC32` Tensor 从 `src memory` 搬到 `dst memory`。这里的重点是：DMA 不理解“图片”“token”“特征图”这些高级语义，它看到的是描述符给出的源地址、目的地址、形状、步长和 layout，然后按地址映射规则发起读写。

`NSliceHWC32` 可以理解为把逻辑通道维 `C` 按 32 个元素一组切块：

- `N`：batch 或更外层样本维。
- `Slice`：通道块编号，通常为 `ceil(C / 32)`。
- `H`：高度或行方向。
- `W`：宽度或列方向。
- `C32`：每个通道块内部的 32 个通道，最内层连续存放。

用箭头表达就是：

```text
n -> slice -> h -> w -> c32
```

因此逻辑元素 `x[n, c, h, w]` 在 `NSliceHWC32` 中需要先拆通道：

```text
slice = c / 32
c32   = c % 32
```

设元素大小为 `elem_bytes`，`S = ceil(C / 32)`，则连续紧凑排布时，线性偏移为：

```text
offset_elem = ((((n * S + slice) * H + h) * W + w) * 32 + c32)
addr        = base_addr + offset_elem * elem_bytes
```

这个公式比“看起来是五维张量”更重要。验证 DMA 时，本质上就是检查 RTL 是否按这个公式从源空间读出，并按目的 layout 的公式写入目标空间。

#### 例 1：`C=64`，没有尾块 padding

假设一个激活张量：

```text
N = 1
C = 64
H = 2
W = 3
elem_bytes = 1  // int8
base_addr = 0x1000
S = C / 32 = 2
```

物理排布顺序是：

```text
n0 slice0 h0 w0 c0..c31
n0 slice0 h0 w1 c0..c31
n0 slice0 h0 w2 c0..c31
n0 slice0 h1 w0 c0..c31
n0 slice0 h1 w1 c0..c31
n0 slice0 h1 w2 c0..c31
n0 slice1 h0 w0 c32..c63
...
```

几个具体元素地址：

| 逻辑元素 | `slice` | `c32` | `offset_elem` | 地址 |
|---|---:|---:|---:|---:|
| `x[0, 0, 0, 0]` | 0 | 0 | 0 | `0x1000` |
| `x[0, 31, 0, 0]` | 0 | 31 | 31 | `0x101f` |
| `x[0, 0, 0, 1]` | 0 | 0 | 32 | `0x1020` |
| `x[0, 0, 1, 0]` | 0 | 0 | 96 | `0x1060` |
| `x[0, 32, 0, 0]` | 1 | 0 | 192 | `0x10c0` |
| `x[0, 63, 1, 2]` | 1 | 31 | 383 | `0x117f` |

注意 `x[0, 32, 0, 0]` 并不是紧跟在 `x[0, 31, 0, 0]` 后面。因为 layout 是 `slice -> h -> w -> c32`，所以硬件会先把 `slice0` 的所有 `H*W` 位置放完，再进入 `slice1`。

#### 例 2：`C=48`，最后一个 slice 有 padding

假设：

```text
N = 1
C = 48
H = 1
W = 2
elem_bytes = 1
base_addr = 0x2000
S = ceil(48 / 32) = 2
```

逻辑数据量是：

```text
N * C * H * W = 1 * 48 * 1 * 2 = 96 bytes
```

但 `NSliceHWC32` 的物理占用是：

```text
N * S * H * W * 32 = 1 * 2 * 1 * 2 * 32 = 128 bytes
```

多出来的 32 bytes 是尾块 padding。具体来说，`slice1` 只包含真实通道 `c=32..47`，对应 `c32=0..15`；`c32=16..31` 是 padding，不应该参与有效计算。

| 物理位置 | 含义 |
|---|---|
| `slice0, w0, c32=0..31` | 真实通道 `c=0..31` |
| `slice0, w1, c32=0..31` | 真实通道 `c=0..31` |
| `slice1, w0, c32=0..15` | 真实通道 `c=32..47` |
| `slice1, w0, c32=16..31` | padding |
| `slice1, w1, c32=0..15` | 真实通道 `c=32..47` |
| `slice1, w1, c32=16..31` | padding |

验证时必须同时检查两类行为：

- DMA 是否搬运了按 layout 对齐后的物理区域，也就是 128 bytes。
- 消费该数据的 Tensor/VA 是否只把 `C=48` 的真实通道作为有效数据，尾块 padding 不应影响结果。

#### 例 3：`fp16` 数据的地址步长

如果同样是 `N=1, C=64, H=2, W=3`，但元素类型是 `fp16`：

```text
elem_bytes = 2
base_addr = 0x8000
```

则 `offset_elem` 不变，只是字节地址乘 2：

| 逻辑元素 | `offset_elem` | 地址 |
|---|---:|---:|
| `x[0, 0, 0, 0]` | 0 | `0x8000` |
| `x[0, 31, 0, 0]` | 31 | `0x803e` |
| `x[0, 0, 0, 1]` | 32 | `0x8040` |
| `x[0, 32, 0, 0]` | 192 | `0x8180` |

这也是很多 DMA bug 的来源：描述符里如果按元素数填写长度，scoreboard 就要按元素大小换算字节；如果描述符字段本身是字节长度，就不能再乘一次 `elem_bytes`。

#### 例 4：从 DDR 搬到 L1BUF 时，`src` 和 `dst` 可以是不同排布

DMA 描述符通常要同时描述源 tensor 和目的 tensor。比如源 DDR 是普通 NHWC，目标 L1BUF 是 `NSliceHWC32`：

```text
src layout: n -> h -> w -> c
dst layout: n -> slice -> h -> w -> c32
```

逻辑元素 `x[n,c,h,w]` 在源地址和目的地址的公式不同：

```text
src_offset = ((n * H + h) * W + w) * C + c

slice = c / 32
c32   = c % 32
dst_offset = ((((n * S + slice) * H + h) * W + w) * 32 + c32)
```

以 `N=1, C=64, H=2, W=3, int8` 为例，逻辑元素 `x[0,32,0,0]`：

```text
src_offset = ((0 * 2 + 0) * 3 + 0) * 64 + 32 = 32
dst_offset = ((((0 * 2 + 1) * 2 + 0) * 3 + 0) * 32 + 0) = 192
```

所以 DMA 可能从 `src_base + 32` 读这个元素，却写到 `dst_base + 192`。这就是“搬运”和“重排”绑定在一起时，不能只比较连续内存 dump 的原因：scoreboard 要按逻辑坐标逐元素比对。

#### DMA/排布验证检查点

- `Slice` 是否按 `ceil(C / 32)` 计算，而不是 `C / 32` 向下取整。
- 最内层 `C32` 是否连续，连续 32 个元素的 byte lane 顺序是否正确。
- `H/W` 步长是否按 `W * 32`、`H * W * 32` 推导。
- 尾块 padding 是否被搬运、清零或保持 don't-care，需要和 spec 对齐。
- 源 layout 与目的 layout 不同时，scoreboard 应按逻辑坐标比对，不要直接 `memcmp`。
- 描述符中的长度单位要明确是元素数、byte 数、还是按 32B/128B 对齐后的 beat 数。
- L1BUF 对齐约束要单独检查：即使逻辑 tensor 很小，DMA burst 也可能按硬件要求对齐到更大的边界。

### 3.5 Spec Layout 表解读

从 DMA spec 的 Layout 表看，DDR 和 L1BUF 的排布并不总是一致。DDR 更偏向软件/MC 侧容易生成和存放的格式；L1BUF 更偏向 Tensor/VA 计算单元容易读取的格式。因此 DMA 经常不只是“搬一段连续 bytes”，而是在搬运过程中完成 layout 变换。

| 数据类型 | 场景 | DDR 排布 | L1BUF 排布 | 解读 |
|---|---|---|---|---|
| Activation | Conv | `NHWC` | 依赖 Conv 输入要求 | DDR 侧按常见激活格式保存，同一像素的通道连续，适合前处理/软件侧组织。 |
| Activation | MatMul | `NHW` | `NSlice(32B)HW32` 或 `NHW(MoE, convert)` | Linear/MatMul 会把 hidden 维切成硬件喜欢的 32-lane 块。`H <= 1` 时按 Linear 排布，其余情况 padding 到 `H16`。 |
| Weight | Conv | `NSlice(32B)WH32` | `NSlice(32B)WH32` | 权重在 DDR 中已经按硬件计算格式离线排好，DMA 主要负责搬运。 |
| Weight | MatMul | `NSlice(32B)WH32` | `NSlice(32B)WH32` | Linear 权重同样采用硬件友好格式，备注里的“Linear 传输，只读”可理解为该路径主要面向权重只读搬入。 |
| KV Cache | Transpose | `NHW` | `NSlice(32B)HW32` | 需要转置。当前 DDR 受 MC 限制，KV cache 暂按 `NHW` 放置，搬入 L1BUF 时转成硬件计算格式。 |
| KV Cache | Normal | `NHW` | `NSlice(32B)WH32` | 不做 transpose 语义时，仍按 L1BUF 中 weight 类格式摆放。 |

这里可以把几种 layout 名字拆开看：

- `NHWC`：`n -> h -> w -> c`，通道 `c` 最内层连续。
- `NHW`：`n -> h -> w`，常用于把最后一维隐含为 hidden/head 内的连续向量，表格中 MatMul/KV cache 都把它作为 DDR 侧简化表示。
- `NSlice(32B)HW32`：`n -> slice -> h -> w -> lane32`，适合按 H/W 空间位置读取，每个位置内有 32 路/lane 的连续小块。
- `NSlice(32B)WH32`：`n -> slice -> w -> h -> lane32`，只是 `H` 和 `W` 的内外顺序对调，更贴近 weight 或某些矩阵乘访问方向。

`NSlice(32B)HW32` 和 `NSlice(32B)WH32` 的核心差别不是有没有切块，而是中间两维谁更连续：

```text
NSlice(32B)HW32: n -> slice -> h -> w -> lane32
NSlice(32B)WH32: n -> slice -> w -> h -> lane32
```

如果用连续紧凑排布近似，二者的地址公式可以写成：

```text
// HW32
offset_hw32 = ((((n * S + slice) * H + h) * W + w) * 32 + lane)

// WH32
offset_wh32 = ((((n * S + slice) * W + w) * H + h) * 32 + lane)
```

举一个小例子，设：

```text
N = 1
S = 1
H = 2
W = 3
lane = 0
elem_bytes = 1
base = 0x4000
```

同一个逻辑位置 `(h=1, w=0, lane=0)`：

```text
HW32 offset = (((0 * 1 + 0) * 2 + 1) * 3 + 0) * 32 + 0 = 96
WH32 offset = (((0 * 1 + 0) * 3 + 0) * 2 + 1) * 32 + 0 = 32
```

所以：

| 排布 | 地址 |
|---|---:|
| `NSlice(32B)HW32` | `0x4000 + 96 = 0x4060` |
| `NSlice(32B)WH32` | `0x4000 + 32 = 0x4020` |

这说明 `HW32` 和 `WH32` 不能只看名字里都有 `32` 就当成一样。它们对 DMA 来说是完全不同的 stride 关系；如果 scoreboard 用错公式，会表现为大块数据都对不上，但每个 32-lane 小块内部看起来又像是对的。

关于 `Slice(32B)` 的一个容易混淆点：`32B` 更像硬件搬运/对齐粒度提示，而末尾 `32` 更像每个块内的 lane 数。对 `int8` 来说 32 lane 刚好是 32 bytes；对 `fp16/bf16` 来说 32 lane 是 64 bytes。因此验证时不要只从 layout 字符串推断 byte 数，要回到描述符里的数据类型、元素大小、burst 对齐字段和 L1BUF bank 规则。

#### Activation MatMul 的 `H16 padding`

表格备注里提到：`H <= 1` 时按 Linear 排布，其余情况 padding 到 `H16`。可以这样理解：

- Linear 常见输入近似是 `[N, H=1, W=hidden]` 或 `[token, hidden]`，不需要额外把 H 方向凑齐。
- 当 `H > 1` 时，硬件可能要求 H 维按 16 对齐，以便 Tensor/VA 侧固定并行粒度读取。
- padding 后的物理高度 `H_pad = ceil(H / 16) * 16`，真实计算仍只使用原始 `H` 范围。

例子：

```text
N = 1
H = 5
W = 2
lane32 = 32
elem_bytes = 1
H_pad = 16
```

逻辑数据量：

```text
1 * 5 * 2 * 32 = 320 bytes
```

L1BUF 物理占用：

```text
1 * 16 * 2 * 32 = 1024 bytes
```

其中 `h=5..15` 都是 H padding。验证时需要确认 DMA 是否写了 padding 区、padding 值是否有约定，以及计算模块是否正确 mask 掉 padding 区。

### 3.6 KV cache 搬运解读

KV cache 搬运的特殊性在于：它不是一次性搬一块普通 activation，而是围绕 attention 的历史 token 窗口反复读写，并且要跨 DDR channel 组织带宽。

从 spec 描述可以整理出几个规则：

- KV cache 按 `head_size` 大小均匀存储在 4 个 DDR channel 中。
- 支持 KV cache 搬运，也支持多通道 interleave 读。
- 支持 1/2/4 个 DDR channel 交织。
- 支持 KV cache 量化参数搬运。
- 支持普通搬运，即没有滑动窗口。
- 支持 ring 搬运，即有滑动窗口，读/写地址到结束边界后回到起始地址。
- 读写可以覆盖多个 chunk；当前需求中写只需要写一个 chunk。

`head_size` 和 `interleave_num` 的关系：

| `head_size` | `interleave_num` | 含义 |
|---:|---:|---|
| 1 | 4 | 单个 head 数据太窄，需要 4 个 DDR channel 并行交织来凑带宽。 |
| 2 | 2 | 每个 head 稍宽，用 2 个 DDR channel 交织。 |
| `>= 4` | 1 | 单个 head 已经足够宽，单 channel 顺序访问即可。 |

一个直观理解是：`head_size` 越小，单 head 连续数据越少，DDR burst 越不容易打满，所以需要更高的 channel interleave；`head_size` 越大，单 head 自身就能形成较长连续访问，反而不需要跨太多 channel。

#### 例 1：普通 KV cache 读取，没有滑动窗口

假设：

```text
seq_len = 8
head_size = 2
interleave_num = 2
chunk = 4 tokens
```

普通搬运读取 token `[0, 1, 2, 3]` 时，可以理解为顺序读：

```text
read token 0
read token 1
read token 2
read token 3
```

如果按 2 channel interleave，逻辑上可近似理解为：

```text
channel0: token 0, token 2
channel1: token 1, token 3
```

真实 RTL 里 channel 选择可能由地址低位、interleave 粒度和 NOC/DDR 配置共同决定，但验证模型至少要检查：同一个 chunk 的数据是否完整、顺序是否按 spec 恢复、跨 channel 返回后是否能重组成原始 token 顺序。

#### 例 2：ring 搬运，有滑动窗口

ring 搬运用于滑动窗口 KV cache。它有一个固定的环形缓存区：

```text
ring_start = 0
ring_end   = 8    // token index 上界，采用 [start, end)
window     = 4
```

如果当前读指针从 `6` 开始，要读 4 个 token：

```text
6, 7, 0, 1
```

因为读地址到达结束边界 `8` 后，会回到起始地址 `0` 继续读。写 ring 也是同理：写地址到结束边界后回到起始地址写入。

这个场景的 scoreboard 不能简单地期望 DDR 地址单调递增，而要按 ring 规则生成 golden：

```text
next_idx = idx + 1
if next_idx == ring_end:
    next_idx = ring_start
```

#### 例 3：写一个 chunk，读多个 chunk

当前需求是“写只需要写一个 chunk”，但读可以读多个 chunk。可以这样理解：

- 写路径：通常是当前 step 新生成的 K/V，只追加一个新 token 或一小段 token，所以写一个 chunk 足够。
- 读路径：attention 需要读取历史窗口内多个 token，可能跨多个 chunk，尤其在 ring 场景中还可能跨 ring 边界。

假设：

```text
chunk_size = 4 tokens
read_start = 6
read_len = 10
ring range = [0, 16)
```

读取序列是：

```text
6, 7, 8, 9, 10, 11, 12, 13, 14, 15
```

如果 `read_start = 12, read_len = 10`：

```text
12, 13, 14, 15, 0, 1, 2, 3, 4, 5
```

这类 case 很适合验证 ring 边界：一个 case 覆盖不回绕，一个 case 覆盖读回绕，一个 case 覆盖写回绕，一个 case 覆盖读写同时接近边界。

#### KV cache 搬运验证检查点

- `head_size` 到 `interleave_num` 的映射是否正确：`1 -> 4`、`2 -> 2`、`>=4 -> 1`。
- 4 个 DDR channel 中 KV cache 是否按 `head_size` 粒度均匀分布。
- 普通搬运时地址是否线性递增，chunk 边界是否正确。
- ring 搬运时读地址和写地址是否在结束边界回绕到起始地址。
- 读多个 chunk 时，跨 chunk 的数据顺序是否和逻辑 token 顺序一致。
- 写一个 chunk 时，是否只更新目标 chunk，没有覆盖相邻 chunk。
- KV cache 量化参数是否和对应 K/V 数据使用同一套 head/token 索引规则，避免参数和数据错位。
- DDR `NHW` 到 L1BUF `NSlice(32B)HW32/WH32` 的转换是否和 transpose/normal 模式一致。

### 3.7 验证建议：先数学映射，后代码实现

先写映射关系，再写 C/SV/PyTorch 实现，可显著降低重排类 bug 定位成本。

建议每个重排算子至少覆盖：

- 正常形状。
- 非对齐尾块。
- 含 padding 情况。
- 与下一算子直连场景（避免接口假设不一致）。

---

## 4. 简单算子分类与模块映射

本文将简单算子分为 5 类：元素级、规约、归一化、线性代数、维度变换。

### 4.1 元素级算子（Element-wise）

定义：输出元素仅依赖当前位置输入元素（或另一个张量对应位置元素）。

单输入常见类型：

- 激活：ReLU、Sigmoid、Tanh、GELU、Leaky ReLU。
- 数值变换：abs、sqrt、exp、log、sign。
- 阈值类：按阈值二值化。

双输入常见类型：

- 算术：add/sub/mul/div。
- 比较：gt/lt/eq/ge/le。
- 逻辑：and/or/xor（布尔张量）。

在本硬件中的典型映射：

- PPROC：承担大部分元素级后处理。
- VA：向量类元素计算。

补充：RoPE 不属于纯元素级，因为存在组内跨元素依赖。

### 4.2 规约算子（Reduction）

定义：沿一个或多个维度聚合，通常导致维度压缩。

| 类型 | PyTorch 接口 | 关键参数 |
|---|---|---|
| 求和 | `sum` | `dim`、`keepdim`、`dtype` |
| 均值 | `mean` | `dim`、`keepdim` |
| 最值 | `max/min` | `dim`、`keepdim` |
| 极值索引 | `argmax/argmin` | `dim`、`keepdim` |
| 方差标准差 | `var/std` | `dim`、`unbiased` |
| 逻辑规约 | `all/any` | `dim`、`keepdim` |

验证重点：规约维度、keepdim 语义、数值稳定性。

### 4.3 归一化算子（Normalization）

归一化核心是“统计量计算 + 仿射变换”。

| 算子 | 统计范围 | 特点 | 常见场景 |
|---|---|---|---|
| BatchNorm | 批次+通道 | 依赖 batch 统计 | CNN 训练 |
| LayerNorm | 单样本特征维 | 无 batch 依赖 | Transformer |
| RMSNorm | 单样本特征维 | 不减均值，计算轻 | LLM 推理 |
| Softmax | 指定维度 | 输出概率和为 1 | 分类/注意力 |
| L2Norm | 指定维度 | 单位向量化 | 检索/匹配 |

本硬件常由 VA 路径处理归一化相关算子。

### 4.4 线性代数算子

- MatMul：AILS + Matrix 主完成，PPROC 通常做后处理或 bypass。
- Linear：本质是 MatMul + Bias Add。
- Conv：本质是局部乘加，常通过展开转 GEMM 实现。
- Batch MatMul：若硬件不直接支持，可通过调度多个 MatMul 批处理执行。

### 4.5 维度变换算子

定义：改变 shape/布局，不改变或规则复制元素值。

| 算子 | 元素总数变化 | 典型作用 |
|---|---|---|
| split/chunk | 不变 | 分支拆分 |
| cat/stack | 不变 | 多分支合并 |
| reshape/view | 不变 | 形状重塑 |
| permute/transpose | 不变 | 维度重排 |
| squeeze/unsqueeze | 不变 | 维度适配 |
| repeat/repeat_interleave | 增加 | 扩展复制 |
| flatten | 不变 | 降维输入线性层 |

通常由 DMA/CP 路径承担，属于“有语义的数据搬运”。

### 4.6 算子公式总表（按本文出现的算子）

以下给出本文提到的主要算子统一公式，便于验证时直接对照 golden。

#### 4.6.1 线性代数与卷积

- GEMM / MatMul：

$$
C_{m,n}=\sum_{k=0}^{K-1}A_{m,k}B_{k,n}
$$

- Batch MatMul（第 $b$ 个批次）：

$$
C^{(b)}=A^{(b)}B^{(b)}
$$

- Linear：

$$
y = Wx+b
$$

- Conv2d：

$$
Y_{n,c_o,h,w}=\sum_{c_i}\sum_{i=0}^{K_h-1}\sum_{j=0}^{K_w-1}
K_{c_o,c_i,i,j}\cdot X_{n,c_i,h+i,w+j}+b_{c_o}
$$

- Conv1d/Conv3d：同理分别在 1D/3D 滑动窗口上做局部乘加。

#### 4.6.2 元素级算子

- Add/Sub/Mul/Div：

$$
y_i=x_i\pm z_i,\quad y_i=x_i\cdot z_i,\quad y_i=\frac{x_i}{z_i}
$$

- ReLU：

$$
y_i=\max(0,x_i)
$$

- Leaky ReLU（斜率 $\alpha$）：

$$
y_i=\begin{cases}
x_i, & x_i\ge 0\\
\alpha x_i, & x_i<0
\end{cases}
$$

- Sigmoid：

$$
y_i=\sigma(x_i)=\frac{1}{1+e^{-x_i}}
$$

- Tanh：

$$
y_i=\tanh(x_i)=\frac{e^{x_i}-e^{-x_i}}{e^{x_i}+e^{-x_i}}
$$

- GELU（常见近似）：

$$
\mathrm{GELU}(x)\approx 0.5x\left(1+\tanh\left(\sqrt{\frac{2}{\pi}}(x+0.044715x^3)\right)\right)
$$

- abs/sign/sqrt/exp/log：

$$
|x|,\quad \mathrm{sign}(x),\quad \sqrt{x},\quad e^x,\quad \log(x)
$$

- 阈值二值化（阈值 $\theta$）：

$$
y_i=\mathbf{1}(x_i>\theta)
$$

- Scale（系数 $\alpha$）：

$$
y_i=\alpha x_i
$$

- Mask（掩码 $m_i\in\{0,1\}$）：

$$
y_i=m_i\cdot x_i
$$

- 比较/逻辑（示例）：

$$
y_i=\mathbf{1}(x_i>z_i),\quad y_i=x_i\land z_i,\quad y_i=x_i\lor z_i
$$

- RoPE（二维分组形式）：

$$
\begin{aligned}
q'_{2t} &= q_{2t}\cos\theta_t - q_{2t+1}\sin\theta_t \\
q'_{2t+1} &= q_{2t}\sin\theta_t + q_{2t+1}\cos\theta_t
\end{aligned}
$$

说明：RoPE 依赖同组相邻元素，不是严格独立的 element-wise。

#### 4.6.3 规约算子

- Sum / Mean：

$$
y=\sum_{i\in\mathcal{D}}x_i,\quad
y=\frac{1}{|\mathcal{D}|}\sum_{i\in\mathcal{D}}x_i
$$

- Max / Min / Argmax / Argmin：

$$
y=\max_{i\in\mathcal{D}}x_i,\quad
k=\arg\max_{i\in\mathcal{D}}x_i
$$

- Prod：

$$
y=\prod_{i\in\mathcal{D}}x_i
$$

- Var / Std：

$$
\mu=\frac{1}{|\mathcal{D}|}\sum_{i\in\mathcal{D}}x_i,
\quad
\mathrm{Var}=\frac{1}{|\mathcal{D}|}\sum_{i\in\mathcal{D}}(x_i-\mu)^2,
\quad
\mathrm{Std}=\sqrt{\mathrm{Var}}
$$

- All / Any（布尔域）：

$$
\mathrm{all}(\{x_i\})=\bigwedge_i x_i,
\quad
\mathrm{any}(\{x_i\})=\bigvee_i x_i
$$

#### 4.6.4 归一化算子

- Softmax（沿维度 $d$）：

$$
y_i=\frac{e^{x_i}}{\sum_{j\in d}e^{x_j}}
$$

- LayerNorm：

$$
\mu=\frac{1}{m}\sum_{i=1}^{m}x_i,
\quad
\sigma^2=\frac{1}{m}\sum_{i=1}^{m}(x_i-\mu)^2,
\quad
y_i=\gamma\frac{x_i-\mu}{\sqrt{\sigma^2+\varepsilon}}+\beta
$$

- BatchNorm（推理态）：

$$
y=\gamma\frac{x-\mu_{\mathrm{run}}}{\sqrt{\sigma^2_{\mathrm{run}}+\varepsilon}}+\beta
$$

- RMSNorm：

$$
\mathrm{rms}(x)=\sqrt{\frac{1}{m}\sum_{i=1}^{m}x_i^2+\varepsilon},
\quad
y_i=\gamma\frac{x_i}{\mathrm{rms}(x)}
$$

- L2Normalize：

$$
y=\frac{x}{\|x\|_2+\varepsilon}
$$

#### 4.6.5 量化与反量化

- 线性量化（scale/zero-point 形式）：

$$
q=\mathrm{clip}(\mathrm{round}(x/s)+z, q_{\min}, q_{\max})
$$

- 反量化：

$$
\hat{x}=s\cdot(q-z)
$$

可与本文前述 $\alpha,\beta$ 形式互相等价变换。

#### 4.6.6 维度变换与索引映射

- reshape/view/permute/split/cat/flatten 的共同点：本质是索引映射函数

$$
\mathrm{dst}[i']=\mathrm{src}[f(i')]
$$

其中 $f(\cdot)$ 由目标 shape 与排列顺序决定；验证时重点是 $f(\cdot)$ 是否与规格一致。

#### 4.6.7 Embedding 与 repeat

- Embedding（查表）：

$$
Y_{t,:}=W_{\mathrm{index}_t,:}
$$

- repeat/repeat\_interleave（重复）：

$$
\mathrm{dst}=\mathrm{repeat}(\mathrm{src}, r)
$$

本质是规则复制映射，不引入新数值计算。

---

## 5. PyTorch 算子到硬件能力的参考映射

| PyTorch 算子 | 模块归属 | 硬件侧说明 |
|---|---|---|
| `torch.Embedding` | DMA | 先搬运 index 到 L1，再做 gather load |
| `torch.repeat_interleave` | DMA/CP | 对应 expand/重复扩展路径 |
| `torch.split` | DMA/CP | 维度拆分搬运 |
| `torch.permute` | DMA/CP | 维度重排搬运 |
| `F.softmax` | VA | 指定维归一化，常用于 attention |
| `F.layer_norm` | VA | 单样本特征维归一化 |
| `nn.Linear` | Matrix + PPROC | MatMul + Bias Add |
| `nn.Conv1d/2d/3d` | AILS + Matrix + PPROC | 展开后进入 GEMM 主路径 |

说明：此表是“工程映射参考”，具体以指令规格和版本实现为准。

---

## 6. 量化技术：性能收益与精度代价

### 6.1 量化不是算子，是执行优化策略

量化通过低比特表示降低存储带宽与计算成本，典型目标格式为 INT8/INT4/FP8。

常见线性量化表达：

$$
Q = \mathrm{round}(\alpha X - \beta), \quad
\hat{X} = \frac{Q + \beta}{\alpha}
$$

说明：实现中也常使用 scale/zero-point 等等价参数化形式。

### 6.2 硬件路径示例

典型 GEMM 量化链：

`FP32/FP16 -> 低比特量化 -> 低比特乘法 -> 高位宽累加 -> 反量化`

例如 INT8 路径常见为“INT8 乘 + INT32 累加 + 反量化输出”。

### 6.3 粒度选择

常见粒度：

- per-tensor：实现简单，精度损失可能偏大。
- per-channel：精度更好，参数管理更复杂。
- per-group/token（LLM 常见）：平衡精度与开销。

资料：

- 量化粒度：https://ncnkvwuxka57.feishu.cn/wiki/NCM7wHBx4iVfjQkiUoNccgVFn8f
- round 规则：https://ncnkvwuxka57.feishu.cn/wiki/F6gFwIQRaiyxXGkP8DscrNgenge

### 6.4 量化收益参考

| 目标格式 | 比特数 | 理论计算提升 | 典型功耗收益 |
|---|---|---|---|
| INT8 | 8 | 约 4x | 50%-70% |
| FP8 | 8 | 约 3x-4x | 40%-60% |
| INT4 | 4 | 约 8x | 70%-80% |
| INT2 | 2 | 约 16x | 85%-90% |

### 6.5 验证重点

- scale/zero-point（或等价参数）加载与生效时序。
- 饱和/截断边界行为。
- 反量化位置是否符合规格（Matrix/PPROC/VA 路径差异）。
- 与融合算子串联时的精度漂移。

---

## 7. Transformer 融合算子与带宽优化

### 7.1 常见推理链路

`QKV 线性投影 -> reshape/transpose -> QK^T -> mask -> softmax -> AV -> residual add -> layernorm -> MLP`

融合目的：减少中间张量反复回写，降低带宽压力并提升局部性。

### 7.2 验证三要点

1. 融合前后数学等价性是否成立。
2. 被省略的中间结果是否被正确复用。
3. mask/softmax/量化顺序是否严格符合规格。

### 7.3 模块协作视角

- Matrix：线性投影、attention 核心乘法。
- PPROC/VA：softmax、归一化、元素级后处理。
- DMA/CP：重排与搬运。

资料：

- Transformer 论文精读：https://www.bilibili.com/video/BV1pu411o7BE/?share_source=copy_web&vd_source=86657b9ca69d2f971499275f09bfcec2
- Transformer 架构讲解：https://www.bilibili.com/video/BV1xoJwzDESD/?share_source=copy_web&vd_source=86657b9ca69d2f971499275f09bfcec2
- 融合算子整理：https://ncnkvwuxka57.feishu.cn/wiki/YPn1whOi0ik9p0kqPA8cKXuKnkc

---

## 8. 误差来源、分析方法与回归策略

### 8.1 误差来源分类

- 浮点舍入误差：有限精度表示不可避免。
- 累加误差：MAC 次数越多，误差越容易累积。
- 量化误差：离散化、截断、饱和引入偏差。
- 布局/切分误差：索引映射或边界拼接错误导致系统性偏差。

![GEMM 乘累加误差示意](https://ncnkvwuxka57.feishu.cn/space/api/box/stream/download/asynccode/?code=NmQwZjU5ZWY5NTAyOTc2NzExMmY0ZmNlMjE1MmU0YjVfTHVDM0ZGc0RMYTFQTFJhOVgxSFJFemNTRVNleHZ6Z0NfVG9rZW46S3FDbWIxdDYyb2RmUGF4cDBTcGNUdDhpbndoXzE3NzU3MTk2MTE6MTc3NTcyMzIxMV9WNA)

参考：

- NPU/GPU 精度差异讲解：https://www.bilibili.com/video/BV1wGE9zSE1C/?share_source=copy_web&vd_source=86657b9ca69d2f971499275f09bfcec

### 8.2 GEMM 误差与切分方向

切分不会消除误差，但会改变误差累积方式。

经验上优先沿 K 维（累加维）做切分更有利于控制误差，因为每个子块的累加深度变小，单块误差累积减弱。

### 8.3 验证落地清单

建议每条关键算子链至少覆盖以下 case：

1. 极值输入（max/min、接近溢出）。
2. 全零与稀疏输入。
3. 长序列输入（Transformer 典型）。
4. 非对齐 shape 与 padding 边界。
5. 融合开关前后对齐（数值误差阈值内一致）。

误差分析建议分层：

- 第 1 层：先区分“实现错误”还是“数值可接受误差”。
- 第 2 层：定位误差来源于浮点、量化还是重排映射。
- 第 3 层：用分段对比（模块边界 dump）缩小问题域。

---

## 9. 总结

对验证工程师而言，最重要的是把这条链路打通：

`模型算子语义 -> 硬件模块职责 -> 数据排布/重排 -> 量化与误差行为`

当这条链路清晰后，波形阅读、指令审查、覆盖率分析和误差定位都会更高效。

如果后续继续扩展本文，建议优先补充两类内容：

1. 各模块“输入约束 + 输出约束 + 失败模式”清单。
2. 典型模型（CNN/LLM）端到端算子映射实例。
