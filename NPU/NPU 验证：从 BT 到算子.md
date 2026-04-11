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

### 3.4 验证建议：先数学映射，后代码实现

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