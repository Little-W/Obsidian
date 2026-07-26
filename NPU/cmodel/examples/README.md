# Keras 模型到 NPU CModel 的五个独立示例

本目录提供 RNN、GRU、LSTM、CNN 和 Transformer 五个可单独运行的端到端示例。每个模型目录都有自己的训练或构建脚本、`Makefile` 和结果检查程序。测试从 Keras 模型开始，依次完成模型准备、整数张量准备、NPU 模型编译、C 文件生成、C 驱动提交和 CModel 推理，并打印输入、Keras 参考结果、CModel 结果以及误差或分类正确率。

完整流程如下：

```text
Keras 训练
    │
    ├─ RNN / GRU / LSTM：读取循环层权重，生成单个时刻的高层 JSON 模型
    │
    └─ CNN / Transformer：保存为 .keras 模型
    │
    ▼
npu_model_compiler.py
    │
    ├─ 高层算子拆分
    ├─ 低层 JSON IR
    ├─ 生成参数内嵌的 CMD128
    └─ 生成 C 配置、CMD128 数组、权重和输入输出信息
    │
    ▼
NPU C 驱动
    │
    ├─ 固定地址命令 FIFO
    ├─ 64-bit FIXED burst
    └─ 每条 CMD128 使用低 64 bit、高 64 bit 两个 beat
    │
    ▼
单核 NPU CModel
    │
    ▼
逐样本结果和统计指标
```

> [!important] 数值类型
> 五个示例的模型输入、权重、中间张量和输出使用 INT8，矩阵乘法累加使用 INT32。Sigmoid、Tanh、Softmax、GELU 和 LayerNorm 等复杂函数按 `INT8 → FP32 → INT8` 计算；FP32 只是复杂函数或软件状态更新期间的临时数值，不作为 NPU 模型张量保存。

## 1. 五个模型分别解决什么问题

| 目录 | 应用目标 | Keras 模型 | 固定测试数据 | 编译器输入 |
| --- | --- | --- | ---: | --- |
| `rnn/` | 根据设备温度、负载和相位的历史序列估计三个随时间变化的状态 | `SimpleRNN(3, return_sequences=True)` | 3 条序列，每条 4 个时刻 | 从 Keras 权重生成的高层 JSON |
| `gru/` | 同一设备状态估计任务，用 GRU 检查更新门、重置门和候选状态 | `GRU(3, reset_after=True, return_sequences=True)` | 3 条序列，每条 4 个时刻 | 从 Keras 权重生成的高层 JSON |
| `lstm/` | 同一设备状态估计任务，用 LSTM 检查输入门、遗忘门、候选值和输出门 | `LSTM(3, return_sequences=True)` | 3 条序列，每条 4 个时刻 | 从 Keras 权重生成的高层 JSON |
| `cnn/` | 识别 6×6 灰度图中的竖向、横向和斜向划痕 | `Conv2D(4, 3×3, ReLU) → Flatten → Dense(3, Tanh)` | 6 张图，每类 2 张 | `.keras` |
| `transformer/` | 把词序和长度可变的英文房间设备命令分为开灯、关灯、开风扇和关风扇 | `词特征 + 位置特征 → 2 × Transformer Encoder → Dense(4, Linear)` | 24 条未参与训练的命令，每类 6 条，句长 3～5 个 token | `.keras` |

序列模型的每个输入时刻包含三个数：

```text
[temperature, load, phase]
```

训练目标由带时间记忆的公式生成。例如第一个目标状态满足：

$$
s_{t,0}
=
0.58s_{t-1,0}
+0.28x_{t,0}
+0.12x_{t,1}
-0.08x_{t,2}.
$$

这里，$t$ 表示当前时刻，$s_{t-1,0}$ 表示上一个时刻的第一个状态，$x_{t,0}$、$x_{t,1}$、$x_{t,2}$ 分别表示当前时刻的温度、负载和相位。因为当前输出依赖上一个时刻的状态，所以模型不能只看一个孤立输入。

CNN 数据不是无含义的随机标签。每张图都含有一条较亮的划痕，并叠加少量背景噪声：

- 类别 0：竖向划痕；
- 类别 1：横向划痕；
- 类别 2：主对角线或副对角线方向的划痕。

Transformer 使用含 `<pad>` 在内的 24 个词项。每个 token 有 32 个特征：前 24 个位置保存词项 one-hot 特征，后 8 个位置预留给正弦和余弦位置特征。构建脚本生成 192 条训练语句，并保留另外 24 条语句作训练后检查；两组语句没有重复。输入固定容纳 8 个 token，较短语句在右侧补 `<pad>`。详细语料、词义和类别定义见 [`transformer/README.md`](transformer/README.md)。

## 2. 整数编码

示例统一使用 Q5 格式。一个 INT8 数值含 5 个小数位，对应比例为：

$$
\Delta=2^{-5}=\frac{1}{32}=0.03125.
$$

浮点数 $x$ 转为 INT8 存储值 $q$ 时使用：

$$
q
=
\operatorname{clip}
\left(
\operatorname{round}(32x),
-128,
127
\right).
$$

从 INT8 存储值恢复近似实数时使用：

$$
\hat{x}=\frac{q}{32}.
$$

例如：

```text
x = -0.70
32x = -22.40
q = round(-22.40) = -22
x_hat = -22 / 32 = -0.6875
```

矩阵乘法先计算 INT32 累加值：

$$
a_{m,n}
=
\sum_{k=0}^{K-1}
q^{(x)}_{m,k}q^{(w)}_{k,n}
+b_n.
$$

$q^{(x)}$ 是 INT8 输入，$q^{(w)}$ 是 INT8 权重，$b_n$ 是 INT32 bias。随后按编译器生成的整数重缩放参数写回 INT8。这样，乘加过程不会因每次乘法后立即裁剪而损失过多数值信息。

> [!note] 为什么打印浮点形式
> C 程序同时打印原始 INT8 数组和按 $q/32$ 还原的数值。原始数组便于检查真实存储内容，还原后的数值便于与 Keras 结果直接比较。

## 3. 五个模型的设计与执行

下面的 $B$ 表示一次交给 Keras 的样本数，$t$ 表示序列中的时刻，$\odot$ 表示相同位置的元素相乘。RNN、GRU 和 LSTM 使用相同的设备遥测数据：每条序列有 4 个时刻，每个时刻有温度、负载和相位 3 个输入。三个监督目标的初始状态均为 0，随后按下式生成：

$$
s_{t,0}
=
0.58s_{t-1,0}
+0.28x_{t,0}
+0.12x_{t,1}
-0.08x_{t,2},
$$

$$
s_{t,1}
=
0.46s_{t-1,1}
-0.10x_{t,0}
+0.40x_{t,1}
+0.07x_{t,2},
$$

$$
s_{t,2}
=
0.34s_{t-1,2}
+0.22(x_{t,0}-x_{t,1})
+0.24x_{t,2}.
$$

这里的 $x_{t,0}$、$x_{t,1}$ 和 $x_{t,2}$ 依次是当前时刻的温度、负载和相位，$s_{t-1,j}$ 是上一个时刻的第 $j$ 个目标状态。三个式子都保留了以前时刻的信息，因此可以检查循环状态是否确实参与后续计算。

### 3.1 SimpleRNN：三状态遥测回归

#### 应用目标与张量形状

SimpleRNN 根据 4 个连续时刻的传感器数据估计 3 个随时间变化的设备状态。Keras 模型接收 `[B,4,3]`，并因 `return_sequences=True` 输出 `[B,4,3]`。固定检查数据含 3 条序列，所以保存到 fixture 中的整体输入和输出都是 `[3,4,3]`。

编译器没有一次展开全部 4 个时刻，而是生成一个时刻的计算任务：

| 名称 | 形状 | 含义 |
| --- | --- | --- |
| `x` | `[1,3]` | 当前时刻的温度、负载和相位 |
| `h_prev` | `[1,3]` | 上一个时刻的隐藏状态 |
| `h` | `[1,3]` | 当前时刻的隐藏状态，也是本时刻输出 |

#### 层结构、参数和逐层计算

Keras 层是 `SimpleRNN(3, activation="tanh", return_sequences=True)`。它含有：

- 输入权重 $W_x\in\mathbb{R}^{3\times3}$，9 个参数；
- 循环权重 $W_h\in\mathbb{R}^{3\times3}$，9 个参数；
- bias $b\in\mathbb{R}^{3}$，3 个参数。

总参数数为 $9+9+3=21$。一个时刻被明确拆成：

$$
u_t^{(x)}=x_tW_x+b,\qquad
u_t^{(h)}=h_{t-1}W_h,
$$

$$
h_t=\tanh\left(u_t^{(x)}+u_t^{(h)}\right).
$$

$x_t$ 和 $h_{t-1}$ 都是 `[1,3]`，两次矩阵乘法的结果也都是 `[1,3]`。$b$ 的形状是 `[3]`：$b_0$、$b_1$、$b_2$ 分别加到输出的第 0、1、2 个分量。若一次处理多个样本，同一组 3 个 bias 会重复用于每个样本，而不是把一个 bias 加到三个不同的输出通道。

#### 训练数据、软件与 NPU 的任务

构建脚本用固定随机种子生成 128 条训练序列和 48 条测试序列，输入从 $[-0.85,0.85]$ 均匀抽取，监督目标由本章开头的三个递推式计算。训练使用 Adam、MSE、120 个 epoch 和 16 个样本一组；固定检查再使用 3 条人工指定的序列，共 12 个时刻。

NPU 负责两个 `MatMul`、两个 `Add` 和一个 `Tanh`。现有生成物把它们转换为 2 条 `GEMM`、2 条 `ADD`、1 条 `ACT`，并配合 `COPY_1D`、`COPY_ND` 和 `EVENT_JOIN`，合计 13 条 CMD128、2 组提交。C 程序负责把初始隐藏状态清零，在每个时刻把 NPU 输出作为下一时刻的 `h_prev`，并统计相对监督目标及 Keras 输出的误差；它不重新计算 SimpleRNN 公式。

这个例子同时检查输入投影、循环投影、bias 加法、两路结果相加、Tanh、隐藏状态回送以及连续 12 次单时刻提交。若循环状态没有参与计算，后几个时刻会首先出现明显误差。

### 3.2 GRU：带更新门和重置门的遥测回归

#### 应用目标与张量形状

GRU 解决与 SimpleRNN 相同的三状态遥测回归任务，但它用更新门决定保留多少旧状态，用重置门决定旧状态在候选值中占多大比重。Keras 输入和输出分别是 `[B,4,3]` 与 `[B,4,3]`；固定数据的整体形状均为 `[3,4,3]`。

每次 NPU 运行接收 `x:[1,3]` 和 `h_prev:[1,3]`，返回四个 `[1,3]` 张量：更新门 `z`、重置门 `r`、候选值的输入投影 `x_h_biased`，以及候选值的循环投影 `recurrent_h_biased`。

#### 层结构、参数和逐层计算

Keras 层是 `GRU(3, reset_after=True, activation="tanh", recurrent_activation="sigmoid", return_sequences=True)`。其参数为：

| 参数 | 形状 | 参数数 |
| --- | ---: | ---: |
| 输入权重 $W$ | `[3,9]` | 27 |
| 循环权重 $U$ | `[3,9]` | 27 |
| 输入侧和循环侧 bias | `[2,9]` | 18 |
| 合计 |  | 72 |

第二个维度的 9 个值按更新门、重置门、候选值各 3 个分量分组。因为 `reset_after=True`，输入投影和循环投影各有一行 bias。以更新门为例，$b_z^{(x)}$ 和 $b_z^{(h)}$ 的形状都是 `[3]`，它们分别加到输入投影和循环投影的 3 个输出分量：

$$
z_t
=
\sigma\left(
x_tW_z+b_z^{(x)}
+h_{t-1}U_z+b_z^{(h)}
\right),
$$

$$
r_t
=
\sigma\left(
x_tW_r+b_r^{(x)}
+h_{t-1}U_r+b_r^{(h)}
\right).
$$

候选值和当前状态按 Keras 的 `reset_after=True` 形式计算：

$$
p_t^{(x)}=x_tW_h+b_h^{(x)},\qquad
p_t^{(h)}=h_{t-1}U_h+b_h^{(h)},
$$

$$
\widetilde{h}_t
=
\tanh\left(p_t^{(x)}+r_t\odot p_t^{(h)}\right),
$$

$$
h_t
=
z_t\odot h_{t-1}
+(1-z_t)\odot\widetilde{h}_t.
$$

$\sigma(v)=1/(1+e^{-v})$ 是 Sigmoid。更新门接近 1 时更重视旧状态，接近 0 时更重视候选值；重置门接近 0 时，候选值会较少使用旧状态。

#### 训练数据、软件与 NPU 的任务

GRU 使用与 3.1 节相同的 128 条训练序列、48 条测试序列、3 条固定序列和三个监督目标递推式，训练配置同样是 Adam、MSE、120 个 epoch 和 16 个样本一组。

NPU 计算 6 个 `MatMul`、8 个 `Add` 和 2 个 `Sigmoid`。现有生成物对应 6 条 `GEMM`、8 条 `ADD`、2 条 `ACT`，再加数据复制和事件等待所需指令，共 43 条 CMD128、6 组提交。NPU 把 `z`、`r`、$p_t^{(x)}$、$p_t^{(h)}$ 四个中间结果写回。

当前 Vector `MUL` 产生 INT32，而下一个时刻的 `h_prev` 需要 INT8 Q5，所以 C 程序暂时用 FP32 完成 $r_t\odot p_t^{(h)}$、候选值 Tanh 和最后的状态组合，再把 $h_t$ 编成 INT8 Q5。测试会逐时刻打印 `z` 与 `r`，并检查 3 条序列的全部 12 个时刻。这样既覆盖两组门值的 Sigmoid，也覆盖输入侧与循环侧两组 bias、四个 NPU 输出、软件状态组合和下一时刻状态输入。

### 3.3 LSTM：同时维护隐藏状态和单元状态

#### 应用目标与张量形状

LSTM 继续估计相同的三个设备状态，并额外维护单元状态 $c_t$。Keras 输入和输出是 `[B,4,3]` 与 `[B,4,3]`，固定数据整体为 `[3,4,3]`。每次 NPU 运行仍接收 `x:[1,3]` 和 `h_prev:[1,3]`，返回输入门 `i`、遗忘门 `f`、候选值 `g` 和输出门 `o`，四个输出的形状都是 `[1,3]`。

#### 层结构、参数和逐层计算

Keras 层是 `LSTM(3, activation="tanh", recurrent_activation="sigmoid", unit_forget_bias=False, return_sequences=True)`。参数由输入权重 `[3,12]`、循环权重 `[3,12]` 和 bias `[12]` 组成，参数数分别为 36、36 和 12，总计 84。12 个输出分量按 `i`、`f`、`g`、`o` 各 3 个分量分组；每组 bias 的形状都是 `[3]`。

四组门值为：

$$
i_t=\sigma(x_tW_i+b_i+h_{t-1}U_i),
$$

$$
f_t=\sigma(x_tW_f+b_f+h_{t-1}U_f),
$$

$$
g_t=\tanh(x_tW_g+b_g+h_{t-1}U_g),
$$

$$
o_t=\sigma(x_tW_o+b_o+h_{t-1}U_o).
$$

例如 $b_o=[b_{o,0},b_{o,1},b_{o,2}]$，三个值分别加到输出门的三个分量。它不会改变时刻数，也不会把 $b_{o,0}$ 加到整个向量。随后更新单元状态和隐藏状态：

$$
c_t=f_t\odot c_{t-1}+i_t\odot g_t,
$$

$$
h_t=o_t\odot\tanh(c_t).
$$

遗忘门控制旧单元状态的保留比例，输入门控制候选值写入多少，输出门控制当前单元状态对隐藏状态的影响。

#### 训练数据、软件与 NPU 的任务

LSTM 使用与 3.1 节相同的训练、测试和固定序列，监督目标仍由本章开头的三个递推式生成；训练使用 Adam、MSE、120 个 epoch 和 16 个样本一组。

NPU 负责 8 个 `MatMul`、8 个 `Add`、3 个 `Sigmoid` 和 1 个 `Tanh`。现有生成物把这些工作转换为 8 条 `GEMM`、8 条 `ADD`、4 条 `ACT`，配合数据复制和事件等待后合计 55 条 CMD128、7 组提交。C 程序把 $c_0$ 和 $h_0$ 清零，用 FP32 临时值完成 $c_t$、$\tanh(c_t)$ 和 $h_t$ 的状态更新，再把 $h_t$ 编成 INT8 Q5 交给下一个时刻。

测试在 12 次单时刻运行中分别读取四个门值，打印输入门、遗忘门和输出门，并把最终隐藏状态同时与监督目标和 Keras 结果比较。因此，一个示例就能检查 8 次矩阵乘法、四类激活输出、单元状态记忆、隐藏状态回送以及多时刻误差变化。

### 3.4 CNN：6×6 划痕方向分类

#### 应用目标、张量形状和参数

CNN 用于识别 6×6 灰度图中的竖向、横向和斜向划痕。Keras 模型的逐层形状和参数如下：

| 层 | 输入形状 | 输出形状 | 参数 |
| --- | --- | --- | ---: |
| `Conv2D(4,3×3,valid,ReLU)` | `[B,6,6,1]` | `[B,4,4,4]` | 40 |
| `Flatten` | `[B,4,4,4]` | `[B,64]` | 0 |
| `Dense(3,Tanh)` | `[B,64]` | `[B,3]` | 195 |
| 合计 |  |  | 235 |

固定检查含 6 张图，因此 fixture 的整体输入是 `[6,6,6,1]`，整体输出是 `[6,3]`；CModel 每次只运行其中 1 张，NPU 输入和输出分别是 `[1,6,6,1]` 与 `[1,3]`。

#### 逐层计算

卷积核 $K$ 的形状是 `[3,3,1,4]`，卷积 bias $b$ 的形状是 `[4]`。步长为 1 且不补零时：

$$
y_{n,r,c,o}
=
b_o+
\sum_{u=0}^{2}
\sum_{v=0}^{2}
\sum_{i=0}^{0}
x_{n,r+u,c+v,i}K_{u,v,i,o}.
$$

$o=0,1,2,3$ 表示四个输出通道。一个 $b_o$ 会加到第 $o$ 个输出通道的全部 $4\times4$ 个空间位置；例如 $b_2$ 加到 `y[n,0,0,2]`、`y[n,0,1,2]`，一直到 `y[n,3,3,2]`，不会加到通道 0、1、3。ReLU 再执行 $\max(0,y)$。

Flatten 按张量的存储次序把 `[4,4,4]` 视为长度 64 的向量。全连接层权重 $V$ 的形状是 `[64,3]`，bias $d$ 的形状是 `[3]`：

$$
q_{n,j}
=
\tanh\left(
\sum_{k=0}^{63}f_{n,k}V_{k,j}+d_j
\right),\qquad j=0,1,2.
$$

$d_0$、$d_1$、$d_2$ 分别加到竖向、横向和斜向三个分数；每处理一张图都会使用同一组 3 个值。

#### 训练数据、软件与 NPU 的任务

构建脚本生成 720 张训练图和 180 张测试图，三个类别按样本编号轮流生成，随后随机打乱。背景噪声从 $[0,0.12]$ 取值，划痕亮度从 $[0.72,1.0]$ 取值；竖向和横向划痕的位置会变化，斜向划痕随机选择主对角线或副对角线。标签 0、1、2 分别表示竖向、横向和斜向。固定检查另生成每类 2 张图，背景噪声上限降为 0.035。模型使用 Adam、稀疏类别交叉熵、45 个 epoch 和 48 张图一组训练。

底层暂时没有专用卷积指令。编译器先按 3×3 的九个采样位置建立 im2col 数据，再用 `GEMM` 完成卷积。一个 3×3 卷积窗口有 9 个元素，4×4 输出平面有 16 个位置，因此 im2col 要写入 $9\times16=144$ 个 INT8 元素。参数内嵌格式的连续复制指令不能在一条命令中同时表达这里的源步长和目标步长，所以编译器把它们展开成 144 条 `COPY_1D`。输入的 36 个像素也逐元素装入 L1，加上常量、Flatten、输出等复制后，共有 184 条 `COPY_1D`。

后续依次执行卷积 `GEMM`、`RELU`、用于 Flatten 的复制、Dense `GEMM`、bias `ADD`、形状整理、Tanh `ACT` 和输出复制。当前生成物共有 418 条 CMD128、194 组提交，其中还包括 148 条 `EVENT_JOIN` 和 81 条 `EVENT_REARM`。事件编号再次使用前必须先执行 `EVENT_REARM`，该指令单独占一组提交，避免新任务把旧事件的完成状态误认为自己的完成条件。

C 程序只复制权重和当前图像，完成缓存同步、CMD128 提交、等待、查询、回收与结果读取，再对 3 个分数执行 `argmax`。每条 CMD128 已带有执行该操作所需的参数，不需要另外准备任务描述数据。卷积、Flatten、全连接和激活都由 NPU CModel 执行。Keras 分数和真实类别只用于比较，不会写入 CModel 输出存储区。六张固定图覆盖三个类别、两种对角线方向、变化的行列位置、九个卷积采样位置、ReLU、Flatten 和 Dense，因此不仅检查分类结果，也检查 Conv2D 经 im2col 拆分后的数据次序。

> [!note] 为什么循环层不直接把 `.keras` 交给编译器
> 当前 Keras 前端可以直接处理本示例的 CNN 和 Transformer，但尚未直接展开 Keras 的 SimpleRNN、GRU 和 LSTM 层。三个循环模型的构建脚本读取训练完成后的权重，生成只含 MatMul、Add、Sigmoid 和 Tanh 等基础算子的高层 JSON，再交给同一个 `npu_model_compiler.py`。

### 3.5 Transformer：可变词序的房间设备命令分类

#### 应用目标与输入、输出

Transformer 把英文房间设备命令分成 `light_on`、`light_off`、`fan_on` 和 `fan_off` 四类。它不仅区分设备和开关状态，还用不同词序、同义词和长度变化检查注意力是否能综合整句信息。

模型有两个 INT8 Q5 输入：

| 输入 | 形状 | 内容 |
| --- | --- | --- |
| `word_features` | `[1,8,32]` | 前 24 个特征保存词项 one-hot，命中位置取 0.75，其余为 0 |
| `position_features` | `[1,8,32]` | 前 24 个特征为 0，后 8 个特征保存当前位置的正弦和余弦值 |

导出模型有三个输出：

| 输出 | 形状 | 用途 |
| --- | --- | --- |
| 第一编码器探针 | `[1,8,32]` | 检查第一组注意力、残差、LayerNorm 和前馈网络 |
| 第二编码器探针 | `[1,8,32]` | 检查第二组编码器及跨层误差 |
| `intent_logits` | `[1,8,4]` | 每个 token 对四种意图的线性分数 |

句子真实长度记为 $L$。最终分类只对前 $L$ 个 token 的同类分数求平均，再选择分数最大的类别；右侧 `<pad>` 对应的输出不参与句子分类。

#### 词特征、位置特征和 padding

词表含 24 个词项，包括 `<pad>`、`light/lamp`、`fan/blower`、`enable/activate`、`disable/deactivate` 以及位置和礼貌用词。第 $p$ 个有效 token 的词向量记为 $E_p\in\mathbb{R}^{32}$，其中前 24 个分量只有词项对应位置为 0.75。

位置特征只写入后 8 个分量。对 $j=0,1,2,3$：

$$
P_{p,2j}
=
0.25\sin\left(
\frac{p}{10000^{2j/8}}
\right),
$$

$$
P_{p,2j+1}
=
0.25\cos\left(
\frac{p}{10000^{2j/8}}
\right).
$$

这些值先按 Q5 取整。NPU 的第一个 `Add` 计算 $X_p=E_p+P_p$，所以即使两个位置出现同一个单词，进入注意力的数值也不同。

短句在右侧补到 8 个 token。padding 行的词特征和位置特征都是 0；训练时该行的 MSE 权重也是 0，句子分类时也不读取该行。当前模型没有额外的 `attention_mask` 输入，因此 padding 的处理方式是“零输入行 + 不统计 padding 输出”，而不是在 Softmax 前屏蔽对应分数。

#### 双编码器层结构与参数

每个编码器的宽度为 32，含 4 个注意力 head，每个 head 宽度为 8；前馈网络先从 32 扩展到 48，再缩回 32。第 $\ell$ 个编码器执行：

$$
Q=XW_Q,\qquad K=XW_K,\qquad V=XW_V,
$$

$$
A
=
\operatorname{softmax}
\left(
\frac{QK^\mathsf{T}}{\sqrt{8}}
\right),
\qquad
O=\operatorname{Concat}(AV)W_O,
$$

$$
N_1=\operatorname{LayerNorm}(X+O),
$$

$$
F=W_2\operatorname{GELU}(W_1N_1+b_1)+b_2,
$$

$$
X_{\mathrm{next}}
=
\operatorname{LayerNorm}(N_1+F).
$$

第一组编码器的 $X_{\mathrm{next}}$ 送入第二组编码器。两个 `MultiHeadAttention` 都关闭 bias。每个注意力层有 4096 个参数，每个前馈网络有 3152 个参数，每个编码器的两组 LayerNorm 合计 128 个参数。两个编码器共有 14752 个参数，末尾 `Dense(32,4,activation="linear")` 有 132 个参数，模型总计 14884 个可训练参数。

LayerNorm 的 $\gamma$ 和 $\beta$ 形状均为 `[32]`。它们分别作用于每个 token 的 32 个特征：同一组参数会用于 8 个 token，但每个 token 都根据自己的 32 个特征计算均值和方差。前馈层的两个 bias 分别为 `[48]` 和 `[32]`；分类层 bias 为 `[4]`，四个值分别加到四类意图分数。

#### 训练与留出语句

构建脚本从 8 种语序模板、设备同义词、普通动作词和状态动作词中选择 192 条训练语句，每类 48 条。训练语句包含 `light/lamp`、`fan/blower`、`turn/set/switch`、`enable/activate`、`disable/deactivate` 等组合。留出集另有 24 条语句，每类 6 条，长度为 3～5 个 token，并使用与训练集不同的完整语句；脚本会直接检查两组句子没有重复。

每个有效 token 都有四个监督分数。正确类的目标值为：

$$
y_{p,c^\ast}=0.56+0.018L+0.012p,
$$

其他类的目标值为：

$$
y_{p,c}
=
-0.24+0.018c-0.008p+0.004L.
$$

$c^\ast$ 是真实类别，$c$ 是其他类别编号，$p$ 是 token 位置。模型使用 Adam、MSE、100 个 epoch、16 条语句一组，并对有参数的层使用 $2\times10^{-5}$ 的 L2 系数。

#### 防止最终分数过度饱和

末尾分类层使用 Linear，不再使用 Tanh。训练目标也不是 $\pm1$，这让四个输出保留更细的数值差异。构建脚本还会检查：

- 三个输出中落到 INT8 最小值或最大值的比例不超过 1%；
- 每个输出至少出现 16 种不同的 INT8 数值，标准差至少为 0.08；
- 最终分数中绝对值不小于 0.95 的比例不超过 35%；
- 留出语句的第一名与第二名平均分之差至少为 0.12；
- 所有训练权重都能用 INT8 Q5 表示。

固定种子生成的当前 Keras 报告中，训练集和 24 条留出语句的分类正确率均为 1.0。最终分数最小值为 -0.6558433，最大值为 1.2765224，均值为 0.0041330，标准差为 0.5127850；绝对值不小于 0.95 的值有 74/768，INT8 两端值为 0/768，不同 INT8 数值有 44 种，最小第一名分差为 0.7661784。

#### 软件与 NPU 的任务及验证内容

软件生成两个输入张量，复制权重和输入，直接提交编译器给出的 CMD128 数组，等待并读取三个输出；分类时只平均有效 token。NPU 执行词特征与位置特征相加、两组多头注意力、四次 LayerNorm、两组前馈网络和线性分类层。当前编译结果使用的主要指令类别包括 `GEMM`、`BMM`、`SPLIT`、`TRANSPOSE_2D`、`PACK`、`SOFTMAX`、`NORM`、`ACT`、`ADD`、`COPY_1D`、`COPY_ND`、`EVENT_JOIN` 和事件重复使用所需的控制指令。

> [!note] 参数放在哪里
> 当前 C 包采用 `cmd128-inline-v2`。每条命令的 80-bit 操作参数与命令编号、数据类型、等待事件和完成事件一起放在 128-bit 命令中，`external_descriptor_bytes` 必须为 0。指令数量会受任务拆分和事件重复使用方式影响，每次编译后的准确数值应读取 `transformer/build/generated/keras_transformer.manifest.json`。

测试数据同时保存第一编码器输出、第二编码器输出和最终分数的 Keras INT8 参考值。这样可以区分误差是在第一组编码器、第二组编码器还是分类层开始增大；24 条留出语句还覆盖同义词、词序变化、3～5 个有效 token 和右侧 padding。CModel 的最终误差与分类统计以本次 `make test` 的终端输出为准，不在测试程序完成更新前猜测数值。

## 4. 环境要求

训练和模型导入使用 conda 环境 `tf_2_18`。本机验证时检测到：

```text
TensorFlow 2.18.0
Keras 3.6.0
```

还需要：

- 支持 C11 的 GCC 或 Clang；
- GNU Make；
- 已有的 NPU C 驱动与 CModel 源码。

默认命令已经写成：

```bash
conda run -n tf_2_18 python ...
```

不需要先执行 `conda activate`。

## 5. 运行单个模型

### 5.1 RNN

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel/examples/rnn"
make clean
make test
```

### 5.2 GRU

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel/examples/gru"
make clean
make test
```

### 5.3 LSTM

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel/examples/lstm"
make clean
make test
```

### 5.4 CNN

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel/examples/cnn"
make clean
make test
```

### 5.5 Transformer

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel/examples/transformer"
make clean
make test
```

`make test` 会自动执行以下工作：

1. 在 `tf_2_18` 中建立并训练 Keras 模型；
2. 保存 `.keras` 文件和训练报告；
3. RNN、GRU、LSTM 额外生成单时刻高层 JSON；
4. 调用通用模型编译器；
5. 再次编译并比较产物，检查生成过程是否可重复；
6. 使用严格警告参数编译生成的 C 文件；
7. 链接 C 驱动、CModel 和结果检查程序；
8. 运行全部固定输入并检查误差或分类正确率。

## 6. 一次运行五个模型

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel/examples"
make clean
make test
```

`make all` 与 `make test` 等价，都会依次运行五个模型：

```bash
make all
```

也可以留在总目录，只运行一个独立子项目：

```bash
make rnn
make gru
make lstm
make cnn
make transformer
```

上述五个目标分别进入同名子目录执行 `make test`。每个子目录都有自己的
`Makefile` 和 `build/`，因此既可以从总目录选择模型，也可以进入子目录独立
执行 `make clean`、`make`、`make test` 或 `make regress`，不会清除其他模型的
生成文件。

只生成 Keras 模型和测试数据：

```bash
make -C rnn model
```

只运行模型编译：

```bash
make -C rnn compile
```

已有文件不变时直接再次运行 C 推理：

```bash
make -C rnn test
```

使用 GCC、Clang 和 Sanitizer 依次检查一个模型：

```bash
make -C rnn regress
```

总目录也提供相同的检查入口。下面三条命令会依次进入五个子目录：

```bash
make check
make test-sanitize
make regress
```

其中 `make check` 检查编译器重复生成的一致性及生成 C 源码的严格警告，
`make test-sanitize` 使用 Clang 的 AddressSanitizer 和
UndefinedBehaviorSanitizer 运行五组推理，`make regress` 还会增加 GCC 与
Clang 的普通构建。

## 7. 生成文件

每个模型的 `build/` 都是可删除的生成目录。主要文件如下：

| 文件 | 内容 |
| --- | --- |
| `build/model.keras` | RNN、GRU、LSTM、CNN 训练完成的 Keras 模型 |
| `build/model.json` | RNN、GRU、LSTM 的单时刻高层模型；CNN 没有此文件 |
| `build/generated/model_model.h` | C 类型、尺寸、地址、输入输出和数组声明 |
| `build/generated/model_model.c` | C 配置、参数内嵌的 CMD128 数组、权重数组和命令分组 |
| `build/generated/model.manifest.json` | 算子、指令数、外部任务描述字节数、权重字节数和生成文件摘要 |
| `build/generated/model_fixture.h` | 固定输入、目标值和 Keras 参考输出 |
| `build/generated/model_report.json` | TensorFlow/Keras 版本、训练配置和训练指标 |
| `build/model_infer` | C 驱动加 CModel 推理程序 |

Transformer 的同类文件位于 `transformer/build/generated/`，文件名前缀为 `keras_transformer`；其可执行程序是 `transformer/build/transformer_runner`。

生成的 C 包含这些核心对象：

```c
model_model_config
model_model_commands
model_model_weights
model_model_inputs
model_model_outputs
model_model_command_batches
model_model_batch_command_ids
```

`model_model_commands` 的每个元素包含 `low` 和 `high` 两个 64-bit word。操作参数已放进这两个 word，不再生成 `model_model_descriptors`。`model_model_command_batches` 把命令分为每组不超过 8 条，以满足一次 FIXED burst 最多 16 个 64-bit beat 的限制。

## 8. 固定地址命令 FIFO 的提交方式

C 驱动调用：

```c
npu_drv_submit_batch(...)
```

驱动把一组 CMD128 展开为：

```text
command 0 low
command 0 high
command 1 low
command 1 high
...
```

随后用一个 64-bit FIXED burst 写入固定命令 FIFO 地址。一次命令组包含 1～8 条命令，因此 burst 长度为 2～16 个 beat。所有 beat 使用相同地址，只有传输数据和最后一个 beat 的结束标志发生变化。驱动再读取每条命令对应的响应，等待任务完成，查询终态并回收任务项。

每个模型的第一次设备执行会打印全部命令组：

```text
command_batch[0]: commands=8 beats=16 responses=8 rc=0
```

字段含义如下：

- `commands`：本次提交的 CMD128 数量；
- `beats`：64-bit beat 数量，恒等于 `2 × commands`；
- `responses`：收到的命令响应数量；
- `rc=0`：本次提交和所有响应均成功。

如果设备返回错误，程序还会打印命令编号、设备状态、FIFO 空闲项数和原始响应值。
后续样本仍会执行并检查相同的命令组，只省略重复的提交明细，输入、推理结果和
统计指标照常逐样本显示。

## 9. 如何阅读详细推理输出

序列模型按“样本 → 时刻”打印。例如：

```text
sample[0]
  time_step[0] device execution
    input:             [-0.7000000, 0.2000000, -0.5000000]
    target:            [-0.1320000, 0.1150000, -0.3180000]
    Keras_reference:   [-0.1384222, 0.1237977, -0.3163002]
    CModel_prediction: [-0.1320487, 0.1113996, -0.3096720]
```

- `input` 是送入当前时刻的三个传感器数值；
- `target` 是数据生成公式给出的目标状态；
- `Keras_reference` 是训练后 Keras 模型的输出；
- `CModel_prediction` 是通用编译器产物经 C 驱动和 CModel 得到的结果。

GRU 还会打印更新门和重置门，LSTM 会打印输入门、遗忘门和输出门。这样可以判断误差从哪个时刻或哪组门值开始增加。

CNN 会打印完整 6×6 输入图、C 的 INT8 输出、恢复后的输出、Keras 输出、真实类别和两个实现各自选择的类别。例如：

```text
CModel_logits_INT8: [-32, 32, -32]
CModel_logits:      [-1.0000000, 1.0000000, -1.0000000]
Keras_reference:   [-0.9984027, 0.9988580, -0.9953637]
CModel_class=1 (horizontal_scratch)
Keras_class=1 (horizontal_scratch)
match=yes
```

Transformer 的详细输出按“语句 → token → 三个输出”组织。每条语句会显示有效长度、右侧 padding 数、词项和含义，并分别概括 32 元词特征与 8 元位置特征。第一编码器探针、第二编码器探针和最终分数都会给出 Keras 与 CModel 的最小值、最大值、均值、标准差和误差。最终分类部分只对有效 token 求平均，并打印真实类别、Keras 类别、CModel 类别和第一名分差。例如，一条语句的摘要形式如下：

```text
result sample=0 sentence="light on please" valid_tokens=3 padded_tokens=5
token_position=0 word=light meaning="the room light"
  word_feature_nonzero: channel=10 value_INT8=24 value=0.750000
  position_feature_INT8=[...8 values...]
encoder1_probe: Keras_mean=... CModel_mean=... max_abs_error_lsb=...
encoder2_probe: Keras_mean=... CModel_mean=... max_abs_error_lsb=...
sentence_logits:
  Keras_mean=[...4 values...]
  CModel_mean=[...4 values...]
true_intent=light_on Keras_prediction=light_on CModel_prediction=light_on
```

## 10. 本机完整运行结果

以下数据来自固定随机种子 `20260726` 的实际运行。

### 10.1 训练结果

| 模型 | 初始训练指标 | 最终训练指标 | 测试指标 | 固定输入的 Keras 指标 |
| --- | ---: | ---: | ---: | ---: |
| RNN | MSE 0.391596079 | MSE 0.000029877 | MSE 0.000028491 | MSE 0.000016820 |
| GRU | MSE 0.078634515 | MSE 0.000064286 | MSE 0.000074586 | MSE 0.000034169 |
| LSTM | MSE 0.044973709 | MSE 0.000127297 | MSE 0.000138611 | MSE 0.000088816 |
| CNN | loss 1.12460458，accuracy 0.420833 | loss 0.241459206，accuracy 1.0 | loss 0.241366744，accuracy 1.0 | accuracy 1.0 |
| Transformer | loss 1.52578104 | loss 0.00344889，训练语句 accuracy 1.0 | 24 条留出语句 loss 0.00427343，accuracy 1.0 | 整句 accuracy 24/24，最小第一名分差 0.7661784 |

### 10.2 CModel 结果

| 模型 | CModel 对目标 | CModel 对 Keras | 其他结果 |
| --- | --- | --- | --- |
| RNN | MSE 0.000336368，MAE 0.0152961，R² 0.990780 | MSE 0.000309134，最大绝对误差 0.0486806 | 12 次单时刻运行全部通过 |
| GRU | MSE 0.000248849，MAE 0.0132689，R² 0.993179 | MSE 0.000234086，最大绝对误差 0.0352441 | 12 次单时刻运行全部通过 |
| LSTM | MSE 0.000175715，MAE 0.0105138，R² 0.995183 | MSE 0.000145138，最大绝对误差 0.0361390 | 12 次单时刻运行全部通过 |
| CNN | 6/6 分类正确，accuracy 1.0 | 6/6 类别一致，MSE 0.0000244733 | 三个类别各检查 2 张图 |
| Transformer | 多输出 runner 更新完成后以本次 `make test` 为准 | 分别统计第一编码器、第二编码器和最终分数，不预填未经运行确认的数据 | 24 条留出语句覆盖同义词、词序变化、padding 和不同有效长度 |

### 10.3 编译产物规模

| 模型 | CMD128 数量 | 命令组数 | 外部任务描述数据 | 权重 |
| --- | ---: | ---: | ---: | ---: |
| RNN | 13 | 2 | 0 B | 448 B |
| GRU | 43 | 6 | 0 B | 1472 B |
| LSTM | 55 | 7 | 0 B | 1984 B |
| CNN | 418 | 194 | 0 B | 832 B |
| Transformer | 见当前 manifest | 见当前 manifest | 0 B | 见当前 manifest |

五个模型都要求 manifest 中的 `command_format` 为 `cmd128-inline-v2`，`external_descriptor_bytes` 为 0。命令数和命令组数会随算子拆分及事件重复使用方式变化，请以各目录本次生成的 manifest 为准；这些数值不是模型结构本身的固定参数。

> [!note] 结果为什么与 Keras 不会逐 bit 相同
> Keras 参考模型使用 FP32，NPU 模型张量使用步长为 1/32 的 INT8。输入、权重、门值和每个时刻的隐状态都可能产生不超过若干个步长的差异。序列模型还会把前一时刻的差异带到下一时刻。因此测试同时检查对真实目标的误差、对 Keras 的误差和最大绝对误差，而不是要求逐 bit 相同。

## 11. 清理

删除五个模型的生成目录：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel/examples"
make clean
```

删除单个模型的生成目录：

```bash
make -C cnn clean
```

清理后再次执行 `make test`，会从训练开始重新生成全部内容。
