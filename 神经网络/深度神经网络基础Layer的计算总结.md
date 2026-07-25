# 深度神经网络基础 Layer 的计算总结

> 本文面向刚开始学习深度学习计算的读者，集中总结 PyTorch 与 Keras 中常用基础 Layer 的数学计算、输入输出形状、参数含义、训练状态差异和手算例子。正文不依赖 Python 代码；看到一个 Layer 名称时，可以直接从公式和数字例子理解它究竟读取哪些数、做了哪些运算、产生什么形状的结果。

> [!ABSTRACT] 本文覆盖什么
> 内容包括形状调整、全连接、Embedding、激活函数、归一化、Dropout、卷积、池化、填充、上采样、循环神经网络、GRU、LSTM、注意力、Transformer 基本子层、常见损失函数、相似度以及多种 Layer 的组合分析。PyTorch 名称主要对应 `torch.nn`，Keras 名称主要对应 Keras 3 的 `keras.layers` 与 `keras.losses`。

> [!NOTE] 为什么同时写 PyTorch 与 Keras
> 两个框架实现的数学原理大多相同，差异主要集中在构造参数名称、默认轴顺序、训练状态控制方式和损失函数的输入约定。把名称并列起来，可以避免把“接口写法不同”误认为“数学计算不同”。

> [!INFO] API 名称来源
> Layer 分类和接口名称以 [PyTorch `torch.nn` 官方文档](https://docs.pytorch.org/docs/stable/nn.html) 与 [Keras Layers API](https://keras.io/api/layers/) 为主要参考；损失函数名称同时参考 [Keras Losses API](https://keras.io/api/losses/)。框架升级可能增加新 Layer 或调整可选参数，但本文重点讲解的数学计算长期适用。

---

## 1. 阅读公式前先统一形状与术语

### 1.1 Layer、算子和模型分别是什么

“算子”通常强调一次具体计算，例如矩阵乘、逐元素加法、Softmax、卷积或最大值归约。“Layer”除了计算本身，还可能保存可学习参数、运行统计量和训练状态。模型则由多个 Layer 及其连接方式组成。

以全连接计算为例：

$$
y=xW+b.
$$

矩阵乘和加法是算子；保存 $W,b$ 并定义输入输出规则的 `Linear` 或 `Dense` 是 Layer；若把多个全连接、激活和归一化组合起来，就得到一个更大的网络模块。

| 层级 | 主要内容 | 典型例子 |
| --- | --- | --- |
| 基础算子 | 对张量立即执行一次计算 | 加法、乘法、矩阵乘、最大值、指数 |
| Layer | 计算规则，可带参数和状态 | `Linear`、`Dense`、`Conv2D`、`LSTM` |
| 组合模块 | 多个 Layer 按指定顺序或分支工作 | 残差块、Transformer Encoder Layer |
| 完整模型 | 接收任务输入并产生最终预测 | 图像分类器、文本分类器、序列生成模型 |

> [!NOTE] 无参数 Layer 仍然是 Layer
> ReLU、Flatten 和最大池化通常没有可学习参数，但它们仍定义了明确的输入输出规则，也能作为独立 Layer 放入模型。

### 1.2 本文统一使用的形状记号

| 符号 | 含义 | 常见取值例子 |
| --- | --- | --- |
| $N$ | Batch Size | 1、8、32、128 |
| $C$ | Channel 数量 | RGB 图像为 3 |
| $L$ | Sequence Length 或一维信号长度 | 句子 token 数、音频采样点数 |
| $H,W$ | 高度与宽度 | $224\times224$ |
| $D$ | 深度、时间帧或体数据厚度 | 16 帧视频中的 16 |
| $E$ | Feature 宽度或 Embedding 宽度 | 128、512、768 |
| $V$ | 词表大小或类别总数 | 30,000 个 token |
| $h$ | Attention Head 数量 | 4、8、16 |
| $d_h$ | 每个 Attention Head 的宽度 | $E/h$ |

本文使用以下常见说法：

- `Batch维度`：排列多个样本的维度；
- `Batch Size`：Batch维度的长度；
- `Channel维度`：排列图像通道或特征通道的维度；
- `Feature维度`：一个位置内部的特征宽度；
- `Sequence Length`：序列包含的位置数量；
- `不含 Batch维度的输入`：只提供一个样本。

> [!TIP] 形状中的字母不是数值本身
> `(N,C,H,W)` 表示四个维度的含义和次序，不表示它们必须取某个固定数。若输入为 `(8,3,32,32)`，就是 $N=8,C=3,H=W=32$。

### 1.3 PyTorch 与 Keras 最需要先记住的轴顺序

图像 Layer 的数学公式相同，但两个框架常见的默认排列不同。

| 数据类型 | PyTorch 常见形状 | Keras 常见形状 |
| --- | --- | --- |
| 一维序列卷积 | `(N,C,L)` | `(N,L,C)` |
| 二维图像 | `(N,C,H,W)` | `(N,H,W,C)` |
| 三维体数据或视频 | `(N,C,D,H,W)` | `(N,D,H,W,C)` |
| 普通 token 序列 | 常用 `(N,L,E)`；RNN 也支持 `(L,N,E)` | `(N,L,E)` |
| 全连接特征 | `(...,E)` | `(...,E)` |

PyTorch 图像计算通常采用 channels-first，也就是 Channel维度在空间维度之前。Keras 的 `data_format` 默认通常采用 channels-last，也就是 Channel维度位于最后。

> [!WARNING] 形状能被接收，不代表含义正确
> 假设一张图的 Keras 形状是 `(N,H,W,C)`，若不调整次序就交给要求 `(N,C,H,W)` 的 PyTorch 卷积，某些尺寸组合会立即报错；若数字碰巧满足参数要求，也可能继续计算，却把高度当成通道。阅读 Layer 前必须先确认每个维度代表什么。

### 1.4 PyTorch 与 Keras 常见名称对照

| 计算类别 | PyTorch 常见名称 | Keras 常见名称 |
| --- | --- | --- |
| 全连接 | `Linear` | `Dense` |
| 查表向量 | `Embedding` | `Embedding` |
| 二维卷积 | `Conv2d` | `Conv2D` |
| 二维转置卷积 | `ConvTranspose2d` | `Conv2DTranspose` |
| 深度卷积 | `Conv2d(groups=C)` | `DepthwiseConv2D` |
| 深度可分卷积 | 深度卷积加 $1\times1$ 卷积 | `SeparableConv2D` |
| 最大池化 | `MaxPool2d` | `MaxPooling2D` |
| 全局平均池化 | `AdaptiveAvgPool2d(1)` | `GlobalAveragePooling2D` |
| Batch Normalization | `BatchNorm1d/2d/3d` | `BatchNormalization` |
| Layer Normalization | `LayerNorm` | `LayerNormalization` |
| Group Normalization | `GroupNorm` | `GroupNormalization` |
| 普通循环层 | `RNN` | `SimpleRNN` |
| GRU | `GRU` | `GRU` |
| LSTM | `LSTM` | `LSTM` |
| 双向包装 | `bidirectional=True` | `Bidirectional` |
| 多头注意力 | `MultiheadAttention` | `MultiHeadAttention` |
| 展平 | `Flatten` | `Flatten` |
| 随机失活 | `Dropout` | `Dropout` |

> [!NOTE] 名称中的大小写属于接口差异
> PyTorch 常写 `Conv2d`、`BatchNorm2d`，Keras 常写 `Conv2D`、`BatchNormalization`。名称不同不会改变卷积或归一化的核心公式。

### 1.5 阅读任意 Layer 的六个问题

面对一个陌生 Layer，可以依次回答：

1. 输入有几个维度，每个维度代表什么？
2. 哪些维度参与求和、求均值或最大值？
3. 哪些维度保留，并分别得到独立输出？
4. Layer 是否有可学习参数？参数形状是什么？
5. 输出形状怎样由输入形状和构造参数得到？
6. 训练状态与推理状态是否采用不同规则？

这六个问题比只记 Layer 名称更重要。例如 Batch Normalization、Layer Normalization 和 Group Normalization 都包含“减均值、除标准差”，真正的差异在于哪些元素放在一起计算统计量，以及参数在哪些位置共享。

### 1.6 本文公式中的常用符号

| 符号 | 含义 |
| --- | --- |
| $x$ | Layer 的输入 |
| $y$ | Layer 的输出或监督目标，具体含义由上下文说明 |
| $W$ | 权重矩阵或卷积核 |
| $b$ | 偏置 |
| $\mu$ | 均值 |
| $\sigma^2$ 或 $v$ | 方差 |
| $\epsilon$ | 防止分母过小的正数 |
| $\gamma,\beta$ | 归一化后的缩放参数与平移参数 |
| $\sigma(x)$ | Sigmoid 函数 |
| $\tanh(x)$ | 双曲正切函数 |
| $\odot$ | 逐元素乘法 |
| $\lVert x\rVert_p$ | $p$ 范数 |
| $\lfloor a\rfloor$ | 不大于 $a$ 的最大整数 |

> [!EXAMPLE] 逐元素乘法与矩阵乘法不能混淆
> 若 $a=[1,2]$、$b=[3,4]$，逐元素乘法得到 $a\odot b=[3,8]$；向量内积得到 $a\cdot b=1\times3+2\times4=11$。门控 Layer 常用逐元素乘法，注意力分数和全连接常用矩阵乘法。

### 1.7 参数、状态和训练模式

一个 Layer 内部可能保存三类数据：

| 类型 | 是否由训练更新 | 例子 |
| --- | --- | --- |
| 可学习参数 | 由梯度和优化器修改 | 全连接权重、卷积核、归一化的 $\gamma,\beta$ |
| 非训练状态 | 不由普通梯度更新，但会随模型保存 | BatchNorm 的运行均值与运行方差 |
| 临时中间结果 | 只服务于本次前向或反向计算 | ReLU 输入、池化位置、注意力权重 |

Dropout 和 Batch Normalization 在训练与推理时行为不同；Linear、Dense、普通卷积和大多数逐元素激活在两种状态下使用同一公式。

> [!WARNING] “没有参数”与“没有状态差异”不是一回事
> Dropout 没有需要训练的权重，却会根据训练状态决定是否随机置零。Batch Normalization 既有可学习参数，也保存运行统计量。判断 Layer 时应分别检查参数、状态和计算规则。

---

## 2. 形状调整、逐元素组合与多输入合并

形状类 Layer 通常没有可学习参数，却会决定后续 Layer 怎样理解每一个维度。初学者最容易忽略的一点是：形状相同只说明每个维度的长度相同，不说明维度含义相同。例如 `(N,L,E)` 与 `(N,E,L)` 都是三维张量，但前者把第 1 维当作 Sequence Length，后者把第 1 维当作 Feature维度。若下一个 Layer 要求固定的轴顺序，仅仅看到“三维输入”还不够。

### 2.1 Identity：保持输入不变

| 框架 | 名称 |
| --- | --- |
| PyTorch | `nn.Identity` |
| Keras | `keras.layers.Identity` |

Identity 的公式只有：

$$
y=x.
$$

其中：

- $x$ 是任意形状的输入张量；
- $y$ 是输出张量；
- 输出的数值、形状和 dtype 均与输入相同；
- Parameter 数量为 0。

若输入为：

$$
x=
\begin{bmatrix}
1&2\\
3&4
\end{bmatrix},
$$

那么输出仍为：

$$
y=
\begin{bmatrix}
1&2\\
3&4
\end{bmatrix}.
$$

> [!NOTE] 不做计算为什么还需要一个 Layer
> 当某个位置“有时需要激活，有时不需要”“有时需要归一化，有时直接通过”时，Identity 可以作为统一占位。模型的其他部分无需因为该位置关闭了某项功能而改变调用方式。

> [!TIP] Identity 适合调试结构
> 如果怀疑某个 Layer 使数值或形状异常，可以临时把它替换为 Identity，再比较输出。这样可以判断问题发生在该 Layer 内部，还是来自前后的数据。

### 2.2 Flatten：合并连续维度

| 框架 | 名称与常见设置 |
| --- | --- |
| PyTorch | `nn.Flatten(start_dim=1,end_dim=-1)` |
| Keras | `keras.layers.Flatten` |

设输入形状为：

$$
(A_0,A_1,\ldots,A_p).
$$

若从第 $s$ 维合并到第 $e$ 维，合并后的长度为：

$$
A_{\mathrm{flat}}=\prod_{j=s}^{e}A_j.
$$

输出形状为：

$$
(A_0,\ldots,A_{s-1},A_{\mathrm{flat}},A_{e+1},\ldots,A_p).
$$

公式中的符号含义如下：

- $A_j$ 是第 $j$ 个维度的长度；
- $s$ 是开始合并的维度编号；
- $e$ 是结束合并的维度编号；
- 乘积表示这些连续维度中的元素被排入同一个长维度；
- Flatten 的 Parameter 数量为 0。

对于 PyTorch 图像输入 `(N,C,H,W)`，`Flatten(1)` 得到：

$$
(N,C,H,W)\rightarrow(N,CHW).
$$

对于 Keras 图像输入 `(N,H,W,C)`，默认 Flatten 得到：

$$
(N,H,W,C)\rightarrow(N,HWC).
$$

两者最终长度相同，都是每个样本包含的元素总数，但展开前的轴次序不同。

设一个样本有 2 个 Channel，每个 Channel 是 `2×2`：

$$
x_0=
\left[
\begin{array}{cc}
1&2\\
3&4
\end{array}
\right],
\qquad
x_1=
\left[
\begin{array}{cc}
5&6\\
7&8
\end{array}
\right].
$$

若按 channels-first 次序展开，得到：

$$
y=[1,2,3,4,5,6,7,8].
$$

> [!WARNING] 通常不要把 Batch维度一起合并
> `(N,C,H,W)` 使用 `Flatten(1)` 会保留 $N$；若从第 0 维开始，多个样本会进入同一个长向量。分类模型通常希望每个样本独立产生预测，因此应保留 Batch维度。

> [!NOTE] Flatten 不会让相邻像素自动发生计算
> 它只是重新组织形状，不执行加法、平均或卷积。原来相邻的数在长向量中可能仍相邻，但只有后续 Linear、Dense 或其他 Layer 才会真正组合它们。

### 2.3 Reshape：按指定尺寸重新解释元素

| 框架 | 名称 |
| --- | --- |
| PyTorch | 张量的 `reshape`，常在自定义 `Module` 中使用 |
| Keras | `keras.layers.Reshape` |

PyTorch 的标准 `nn` 中没有与 Keras `Reshape` 完全同名的基础 Layer，通常直接对张量调用 `reshape`。无论接口怎样写，数学要求都是输入元素总数与输出元素总数相等：

$$
\prod_{i=0}^{p}A_i=\prod_{j=0}^{q}B_j.
$$

其中：

- $(A_0,\ldots,A_p)$ 是原形状；
- $(B_0,\ldots,B_q)$ 是目标形状；
- Reshape 的 Parameter 数量为 0；
- Reshape 通常不改变元素值，只改变各个下标怎样读取这些值。

把 12 个数：

$$
[1,2,3,4,5,6,7,8,9,10,11,12]
$$

改为 `(3,4)`，得到：

$$
\begin{bmatrix}
1&2&3&4\\
5&6&7&8\\
9&10&11&12
\end{bmatrix}.
$$

改为 `(2,2,3)` 时，第 0 个二维块为：

$$
\begin{bmatrix}
1&2&3\\
4&5&6
\end{bmatrix},
$$

第 1 个二维块为：

$$
\begin{bmatrix}
7&8&9\\
10&11&12
\end{bmatrix}.
$$

> [!WARNING] 元素总数相同不代表维度含义正确
> 长度 12 可以拆成 `(3,4)`、`(2,6)`、`(2,2,3)` 等多种形状。框架只能检查乘积，无法知道某一维应当表示 Channel、时间还是空间位置。

> [!TIP] Reshape 前后都写出维度名称
> 不要只写 `(N,12)` 变成 `(N,3,4)`，还应写清 `(N,Feature)` 变成 `(N,Channel,Length)`。一旦维度名称写不出来，通常说明目标形状的含义还没有想清。

### 2.4 Permute 与转置：改变维度次序

| 框架 | 名称 |
| --- | --- |
| PyTorch | 张量的 `permute`、`transpose`，或 `torch.permute` |
| Keras | `keras.layers.Permute` |

Permute 不合并维度，也不改变元素总数，只改变维度排列。设输入：

$$
x\in\mathbb{R}^{A_0\times A_1\times\cdots\times A_p}.
$$

给定排列 $(r_0,r_1,\ldots,r_p)$ 后，输出形状为：

$$
(A_{r_0},A_{r_1},\ldots,A_{r_p}).
$$

输出元素满足：

$$
y_{i_0,i_1,\ldots,i_p}
=
x_{j_0,j_1,\ldots,j_p},
$$

其中 $j_{r_k}=i_k$。Permute 的 Parameter 数量为 0。

例如，PyTorch 序列从 `(N,L,E)` 调整为 BatchNorm1d 常用的 `(N,E,L)`，就是交换 $L$ 与 $E$：

$$
x_{n,l,e}\rightarrow y_{n,e,l}=x_{n,l,e}.
$$

若一个样本有 2 个位置、每个位置 3 个 Feature：

$$
x=
\begin{bmatrix}
1&2&3\\
4&5&6
\end{bmatrix},
$$

其形状是 `(L,E)=(2,3)`。交换两维后得到：

$$
y=
\begin{bmatrix}
1&4\\
2&5\\
3&6
\end{bmatrix},
$$

形状变为 `(E,L)=(3,2)`。

> [!NOTE] Permute 与 Reshape 做的事不同
> Permute 明确改变轴次序；Reshape 按当前元素次序重新拆分尺寸。若本来需要交换 Channel维度和 Feature维度，却只使用 Reshape，形状可能符合要求，元素所在的位置却不符合原意。

> [!WARNING] Keras `Permute` 通常不写 Batch维度
> Keras 常把 Batch维度保留在最前，只在单样本的其余维度中指定次序。例如单样本部分从 `(L,E)` 调整为 `(E,L)` 时，设置的是 `(2,1)`，不是包含 Batch维度的三项排列。

### 2.5 Add 与残差加法

| 框架 | 名称 |
| --- | --- |
| PyTorch | `torch.add`、`+`，常封装在自定义 `Module` 中 |
| Keras | `keras.layers.Add` |

当两个张量形状相同，Add 执行逐元素加法：

$$
y_i=a_i+b_i.
$$

多维写法为：

$$
y_{n,l,e}=a_{n,l,e}+b_{n,l,e}.
$$

其中：

- $a,b$ 是两个输入；
- $y$ 是输出；
- 每个位置只与另一个输入中相同位置的数相加；
- 输入输出形状相同；
- Add 的 Parameter 数量为 0。

数值例子：

$$
a=[1,2,3],\qquad b=[10,20,30],
$$

则：

$$
y=[11,22,33].
$$

残差计算常写成：

$$
y=x+F(x),
$$

其中 $F(x)$ 是某个子模块的输出。若：

$$
x=[1,-2,3],\qquad F(x)=[0.5,1,-1],
$$

则：

$$
y=[1.5,-1,2].
$$

> [!WARNING] 残差相加需要形状兼容
> 如果 $x$ 的 Feature 宽度为 64，而 $F(x)$ 的 Feature 宽度为 128，不能直接逐元素相加。常见处理是使用 Linear、Dense 或 $1\times1$ 卷积先把其中一侧调整到相同宽度。

> [!NOTE] 广播可能让形状不同的张量仍能相加
> 例如 `(N,L,E)` 可以与 `(E,)` 相加，长度为 $E$ 的向量会供每个样本、每个位置共同使用。Keras `Add` 更强调多个输入形状相同；使用框架的底层加法时仍应主动核对广播是否符合设计。

### 2.6 Multiply：逐元素乘法与门控

| 框架 | 名称 |
| --- | --- |
| PyTorch | `torch.mul`、`*` |
| Keras | `keras.layers.Multiply` |

Multiply 的公式为：

$$
y_i=a_i b_i,
$$

或：

$$
y=a\odot b.
$$

$\odot$ 表示逐元素乘法，不是矩阵乘法。Multiply 没有 Parameter，输出形状通常与输入形状相同。

若：

$$
a=[2,-1,4],\qquad b=[0.5,0,0.25],
$$

则：

$$
y=[1,0,1].
$$

当 $b$ 的元素位于 0 和 1 之间时，可以把它理解为门值：0 表示完全抑制，1 表示完整保留，0.25 表示保留四分之一。

> [!EXAMPLE] 一个标量也可以缩放整个张量
> 若 $a=[2,4,6]$、$b=0.1$，广播后得到 $y=[0.2,0.4,0.6]$。此时同一个缩放系数供所有位置使用。

> [!WARNING] `*` 不是矩阵乘
> 两个矩阵逐元素相乘要求形状兼容；矩阵乘法则会沿公共维度求和。阅读公式时应区分 $\odot$ 与普通矩阵乘符号。

### 2.7 Concatenate：沿一个维度首尾连接

| 框架 | 名称 |
| --- | --- |
| PyTorch | `torch.cat` |
| Keras | `keras.layers.Concatenate` |

设两个输入除第 $k$ 维外都相同：

$$
a\in\mathbb{R}^{A_0\times\cdots\times A_k\times\cdots\times A_p},
$$

$$
b\in\mathbb{R}^{A_0\times\cdots\times B_k\times\cdots\times A_p}.
$$

沿第 $k$ 维连接后：

$$
y\in\mathbb{R}^{A_0\times\cdots\times(A_k+B_k)\times\cdots\times A_p}.
$$

Concatenate 不执行数值加法，Parameter 数量为 0。

若：

$$
a=[1,2],\qquad b=[3,4,5],
$$

沿唯一维度连接得到：

$$
y=[1,2,3,4,5].
$$

若 $a,b$ 形状分别为 `(N,L,4)` 与 `(N,L,6)`，沿 Feature维度连接后形状为：

$$
(N,L,4)+(N,L,6)\rightarrow(N,L,10).
$$

> [!NOTE] Add 与 Concatenate 的差别
> Add 保持宽度不变，把相同位置的数相加；Concatenate 保留两侧的原值，并让指定维度变长。前者要求位置逐项兼容，后者要求除连接维度外的其他尺寸一致。

> [!WARNING] 沿错维度会改变数据含义
> 两个 `(N,L,E)` 序列沿 Feature维度连接得到 `(N,L,2E)`；沿 Sequence Length 连接得到 `(N,2L,E)`。两种结果的元素总数相同，但前者增加每个 token 的特征，后者增加 token 数。

### 2.8 Stack、Average、Maximum 与 Subtract

PyTorch 的 `torch.stack` 会创建一个新维度；Keras 中可借助适当的组合 Layer 完成同类计算。若三个输入形状都是 `(N,E)`，沿新维度堆叠后可得到 `(N,3,E)`。它与 Concatenate 的主要差别是：Concatenate 扩大已有维度，Stack 新增维度。

Keras 还提供 `Average`、`Maximum`、`Minimum`、`Subtract` 等合并 Layer；PyTorch 可用同名张量运算完成。

Average 对 $K$ 个同形状输入计算：

$$
y_i=\frac{1}{K}\sum_{k=1}^{K}x_i^{(k)}.
$$

若三个模型给出标量预测 2、5、8，则平均结果为：

$$
y=\frac{2+5+8}{3}=5.
$$

Maximum 逐位置取最大值。若：

$$
a=[1,7,3],\qquad b=[2,4,9],
$$

则：

$$
y=[2,7,9].
$$

Subtract 对两个输入执行：

$$
y=a-b.
$$

它与 Add 不同，输入次序会改变结果。以上 Layer 均无 Parameter，输入输出形状通常相同。

> [!TIP] 看到多输入合并，先回答两个问题
> 第一，合并后是否需要保留每一侧的原始特征？若需要，通常考虑 Concatenate。第二，两个输入的同一位置是否表达相同含义？若是，才更适合 Add、Average 或 Maximum。

### 2.9 广播：较小张量怎样供多个位置共同使用

广播不是一个单独的可学习 Layer，但 Add、Multiply、Subtract 等逐元素计算经常依赖它。两个输入从最后一个维度开始比较，每一对维度满足以下任一条件时，通常可以广播：

1. 两个维度长度相同；
2. 其中一个维度长度为 1；
3. 较短形状在左侧缺少该维度，可把缺少部分看作长度 1。

设：

$$
x\in\mathbb{R}^{N\times L\times E},
\qquad
b\in\mathbb{R}^{E}.
$$

$b$ 可以先从概念上看成 `(1,1,E)`，然后供 $N$ 个样本和每个样本的 $L$ 个位置共同使用：

$$
y_{n,l,e}=x_{n,l,e}+b_e.
$$

输出形状仍为 `(N,L,E)`，Parameter 数量取决于 $b$ 的身份：若 $b$ 是普通输入，Add 本身没有 Parameter；若 $b$ 是某个 Layer 保存的偏置，则该 Layer 有 $E$ 个 bias Parameter。

具体例子：一个 Batch 中有两个样本，每个样本有两个位置，每个位置有三个 Feature：

$$
x=
\left[
\begin{array}{cc}
[1,2,3]&[4,5,6]\\
[10,20,30]&[40,50,60]
\end{array}
\right],
$$

令：

$$
b=[0.5,-1,2].
$$

广播相加后：

$$
y=
\left[
\begin{array}{cc}
[1.5,1,5]&[4.5,4,8]\\
[10.5,19,32]&[40.5,49,62]
\end{array}
\right].
$$

同一个 $b$ 没有被学习成四份不同数据，它只是分别参与四个位置的计算。

> [!WARNING] 能广播不代表应该广播
> `(N,L,E)` 与 `(L,1)` 在某些情况下可以相加，此时第二个输入会按位置提供不同值，并沿 Feature维度重复。若原意是为每个 Feature 加偏置，应使用 `(E,)`。框架只检查尺寸规则，不知道想让参数沿哪个轴共享。

> [!TIP] 广播前先在左侧补 1
> 把较短形状左侧补成同样维数，再从右向左逐维比较。例如 `(E,)` 补成 `(1,1,E)`，就能直观看出它会沿 $N,L$ 重复使用。

### 2.10 Add、Concatenate 与 Stack 的完整形状对比

设有两个特征张量：

$$
a,b\in\mathbb{R}^{N\times L\times E}.
$$

三种合并产生不同结果：

| 计算 | 输出形状 | 是否逐位置计算 | 是否新增轴 |
| --- | --- | --- | --- |
| $a+b$ | `(N,L,E)` | 是，相同位置相加 | 否 |
| 沿 Feature维度连接 | `(N,L,2E)` | 否，保留两侧原值 | 否 |
| 沿新轴堆叠 | `(N,L,2,E)` | 否，保留两侧原值 | 是 |

用最小数字说明。令：

$$
a=[1,2],\qquad b=[10,20].
$$

Add 得到：

$$
[11,22].
$$

Concatenate 得到：

$$
[1,2,10,20].
$$

Stack 得到：

$$
\begin{bmatrix}
1&2\\
10&20
\end{bmatrix}.
$$

因此，三种计算即使都被口头称为“合并”，也不能互换。

> [!EXAMPLE] 两个传感器特征怎样合并
> 若两个传感器都输出同样含义的温度、湿度和压力，可用 Average 得到融合读数；若它们提取的是不同类型特征，更适合沿 Feature维度 Concatenate，让后续 Dense 学习怎样组合；若希望保留“传感器编号”这一独立维度，可使用 Stack。

### 2.11 一个从图像到分类向量的形状过程

设 PyTorch 图像输入为：

$$
x\in\mathbb{R}^{8\times3\times4\times4}.
$$

这里一个 Batch 有 8 张图，每张图有 3 个 Channel，每个 Channel 为 `4×4`。

第一步，把空间维度合并，但保留 Channel维度：

$$
(8,3,4,4)\rightarrow(8,3,16).
$$

这相当于每个 Channel 的 16 个空间位置排成一个向量。

第二步，交换 Channel 与展开后的位置轴：

$$
(8,3,16)\rightarrow(8,16,3).
$$

现在可把每张图理解为 16 个位置，每个位置有 3 个 Feature。

第三步，若沿最后两个维度全部展开：

$$
(8,16,3)\rightarrow(8,48).
$$

每张图成为长度 48 的向量。整个过程没有做加权求和，Parameter 数量一直为 0。

同一图像在 Keras channels-last 形式中一开始就是 `(8,4,4,3)`。先合并两个空间轴可得到 `(8,16,3)`，因此不需要先交换 Channel轴。

> [!NOTE] 形状步骤会影响后续权重的含义
> 最终虽然都是 48 个数，但不同展开次序会让第 0、1、2 个位置表示不同原始元素。Dense 可以适应固定次序；若训练和推理采用不同次序，同一组权重就会读取错误位置。

### 2.12 参数为零也要检查反向计算

Flatten、Reshape、Permute、Add 与 Concatenate 通常没有 Parameter，但梯度仍会穿过它们传回输入。

Add：

$$
y=a+b
$$

对应：

$$
\frac{\partial L}{\partial a}
=
\frac{\partial L}{\partial y},
\qquad
\frac{\partial L}{\partial b}
=
\frac{\partial L}{\partial y},
$$

若 $b$ 经广播供多个位置使用，所有位置对 $b$ 的梯度会相加。

Multiply：

$$
y=a\odot b
$$

对应：

$$
\frac{\partial L}{\partial a}
=
\frac{\partial L}{\partial y}\odot b,
\qquad
\frac{\partial L}{\partial b}
=
\frac{\partial L}{\partial y}\odot a.
$$

因此，门值 $b$ 很小时，不仅前向内容被压低，传给 $a$ 的梯度也会按 $b$ 缩小。

Concatenate 的反向计算则把输出梯度沿原连接轴切回各输入。例如两个宽度分别为 2 和 3 的向量连接成宽度 5，前两个梯度返回第一个输入，后三个返回第二个输入。

> [!TIP] 无 Parameter Layer 的检查重点
> 依次检查元素次序、轴含义、广播方式和梯度分配位置。它们不会自己学习纠正形状错误，后续 Layer 可能只能在错误组织的数据上继续训练。

---

## 3. Linear、Dense、Bilinear、Embedding 与张量缩并

这一章的 Layer 都会把输入特征变成新的特征。其中 Linear 与 Dense 对单个位置的 Feature维度做加权求和；Embedding 根据整数编号取出一行参数；Bilinear 同时计算两组特征之间的乘积项；EinsumDense 用一个字符串描述更一般的乘法与求和规则。

### 3.1 Linear 与 Dense：最基础的仿射计算

| 框架 | 名称 |
| --- | --- |
| PyTorch | `nn.Linear(in_features,out_features,bias=True)` |
| Keras | `keras.layers.Dense(units,use_bias=True)` |

对一个输入向量，核心公式为：

$$
y_j=\sum_{i=1}^{I}x_iW_{i,j}+b_j,
\qquad j=1,\ldots,O.
$$

矩阵形式为：

$$
y=xW+b.
$$

符号逐项解释：

- $I$ 是输入 Feature 数量；
- $O$ 是输出 Feature 数量；
- $x_i$ 是第 $i$ 个输入特征；
- $W_{i,j}$ 表示输入特征 $i$ 对输出特征 $j$ 的系数；
- $b_j$ 是第 $j$ 个输出的偏置；
- 求和发生在输入 Feature维度；
- 每个输出位置使用一列系数。

输入形状为 `(...,I)`，输出形状为 `(...,O)`。省略号可以包含 Batch维度、Sequence Length 或其他前导维度。Linear 与 Dense 都只处理最后一个 Feature维度，不会自动组合不同 token。

使用 bias 时，Parameter 数量为：

$$
I\times O+O.
$$

不使用 bias 时为：

$$
I\times O.
$$

设：

$$
x=[2,-1,3],
$$

$$
W=
\begin{bmatrix}
1&0.5\\
2&0\\
-1&2
\end{bmatrix},
\qquad
b=[0.5,-1].
$$

第一个输出为：

$$
y_0=2\times1+(-1)\times2+3\times(-1)+0.5=-2.5.
$$

第二个输出为：

$$
y_1=2\times0.5+(-1)\times0+3\times2-1=6.
$$

所以：

$$
y=[-2.5,6].
$$

> [!NOTE] PyTorch 与 Keras 的权重保存次序不同
> PyTorch `Linear.weight` 常见形状为 `(O,I)`，前向时使用其转置；Keras `Dense.kernel` 常见形状为 `(I,O)`。上面的公式按 `(I,O)` 书写。两者表达同一种加权求和，复制权重时需要转置。

> [!EXAMPLE] 三维序列中的 Dense
> 输入 `(N,L,8)` 经过输出宽度为 3 的 Linear 或 Dense 后得到 `(N,L,3)`。同一组权重分别处理一个 Batch 中每个 token 的 8 个特征。token 之间在这一层不会相加。

> [!WARNING] Linear 不是“先把全部维度展平”
> 它只要求最后一维等于输入宽度。图像 `(N,C,H,W)` 若直接进入 `Linear(W,O)`，会把每个固定的 `(n,c,h)` 位置上的宽度向量独立处理。若想让整张图成为一个向量，应先明确使用 Flatten。

### 3.2 LazyLinear 与延迟确定输入宽度

PyTorch 提供 `nn.LazyLinear(out_features)`；Keras 的 Dense 通常也会在第一次构建时从输入形状得到输入宽度。第一次看到 `(...,I)` 后，Layer 才创建与 $I$ 相关的权重。

初始化完成后，其公式、输入输出形状和 Parameter 数量与普通 Linear 或 Dense 完全相同：

$$
\text{Parameter 数量}=I O+O.
$$

假设设置输出宽度 $O=4$，第一次输入形状为 `(N,7)`，则权重按 $I=7$ 创建，输出为 `(N,4)`，使用 bias 时 Parameter 数量为：

$$
7\times4+4=32.
$$

> [!WARNING] 第一次输入决定后续尺寸
> 若本来希望 Feature 宽度为 7，却误把宽度 8 的输入作为第一次调用，Layer 会按 8 创建权重。后续宽度 7 的输入将无法使用同一组参数。正式训练前应先用正确形状完成一次前向检查。

### 3.3 Bilinear：两组输入的二阶交互

| 框架 | 名称 |
| --- | --- |
| PyTorch | `nn.Bilinear(in1_features,in2_features,out_features)` |
| Keras | 核心 Layer 中通常使用自定义 Layer 或 `EinsumDense` 实现；`Dot` 只覆盖更简单的点积 |

对第 $o$ 个输出，Bilinear 计算：

$$
y_o=x_1^TW_ox_2+b_o.
$$

完全展开为：

$$
y_o=
\sum_{i=1}^{I_1}
\sum_{j=1}^{I_2}
x_{1,i}W_{o,i,j}x_{2,j}
+b_o.
$$

符号含义：

- $x_1\in\mathbb{R}^{I_1}$ 是第一组输入特征；
- $x_2\in\mathbb{R}^{I_2}$ 是第二组输入特征；
- $W_o\in\mathbb{R}^{I_1\times I_2}$ 是第 $o$ 个输出使用的权重；
- $O$ 是输出 Feature 数量；
- 每一项都同时含有一个 $x_1$ 特征和一个 $x_2$ 特征。

输入形状分别为 `(...,I1)` 与 `(...,I2)`，前导维度需要兼容，输出为 `(...,O)`。

使用 bias 时，Parameter 数量为：

$$
O I_1 I_2+O.
$$

设只有一个输出：

$$
x_1=[1,2],\qquad x_2=[3,-1],
$$

$$
W=
\begin{bmatrix}
1&2\\
-1&0.5
\end{bmatrix},
\qquad b=0.5.
$$

先算：

$$
Wx_2=
\begin{bmatrix}
1\\
-3.5
\end{bmatrix}.
$$

再算：

$$
y=x_1^T(Wx_2)+b
=1\times1+2\times(-3.5)+0.5
=-5.5.
$$

> [!NOTE] Bilinear 与拼接后 Dense 不相同
> 拼接后 Dense 主要形成 $a^Tx_1+c^Tx_2+b$；Bilinear 直接包含 $x_{1,i}x_{2,j}$。因此它可以表达“第一组某个特征的作用会随第二组某个特征而改变”。

> [!WARNING] Parameter 数量增长很快
> 若 $I_1=I_2=512$、$O=128$，仅权重就有 $128\times512\times512$ 个数。使用 Bilinear 前应先计算参数和存储需求。

### 3.4 Embedding：按整数编号查表

| 框架 | 名称 |
| --- | --- |
| PyTorch | `nn.Embedding(num_embeddings,embedding_dim)` |
| Keras | `keras.layers.Embedding(input_dim,output_dim)` |

Embedding 保存一个矩阵：

$$
E\in\mathbb{R}^{V\times D}.
$$

输入是整数编号 $t$，输出是第 $t$ 行：

$$
y=E[t].
$$

符号含义：

- $V$ 是可用编号总数，例如词表大小；
- $D$ 是每个编号的 Embedding 宽度；
- $t$ 是满足 $0\le t<V$ 的整数；
- $E[t]$ 是长度为 $D$ 的可学习向量。

若输入形状为 `(N,L)`，输出形状为：

$$
(N,L)\rightarrow(N,L,D).
$$

Parameter 数量为：

$$
V D.
$$

Embedding 通常不使用额外 bias。

设：

$$
E=
\begin{bmatrix}
0&0\\
1&2\\
-1&3\\
4&0.5
\end{bmatrix},
$$

输入编号为：

$$
t=[2,1,3].
$$

逐项取行后：

$$
y=
\begin{bmatrix}
-1&3\\
1&2\\
4&0.5
\end{bmatrix}.
$$

输入长度为 3，每个编号变成 2 维向量，所以输出形状是 `(3,2)`；若加上 Batch维度，例如输入 `(N,3)`，输出就是 `(N,3,2)`。

> [!NOTE] Embedding 不是把整数大小当作连续数值
> 编号 3 不表示它比编号 1 大三倍。编号只用来选择参数矩阵中的一行。两行向量是否相似，由训练后的数值决定。

> [!WARNING] 输入必须是有效整数编号
> 负数、浮点数或不小于 $V$ 的编号通常不能直接查表。预处理阶段应明确未知 token、补齐 token 和特殊 token 分别使用哪个编号。

> [!NOTE] 补齐位置的接口差异
> PyTorch 的 `padding_idx` 可让指定行不通过普通梯度更新；Keras 的 `mask_zero=True` 会把编号 0 标记为需要在支持 mask 的后续 Layer 中忽略。二者重点不同，不能只看名字相近就认为行为完全一致。

### 3.5 EmbeddingBag：先查表，再对一组向量汇总

PyTorch 提供 `nn.EmbeddingBag`。Keras 核心 Layer 中通常使用 `Embedding` 加求和或平均池化完成同类计算。

先对一组编号 $t_1,\ldots,t_K$ 查表，再以求和模式计算：

$$
y=\sum_{k=1}^{K}E[t_k].
$$

平均模式为：

$$
y=\frac{1}{K}\sum_{k=1}^{K}E[t_k].
$$

若：

$$
E[1]=[1,2],\quad E[2]=[-1,3],\quad E[3]=[4,1],
$$

一个样本包含编号 `[1,2,3]`，求和结果为：

$$
[1,2]+[-1,3]+[4,1]=[4,6].
$$

平均结果为：

$$
[4/3,2].
$$

Parameter 数量仍为 $VD$，汇总本身没有新增 Parameter。若一个 Batch 有 $N$ 个编号组，输出通常为 `(N,D)`。

> [!TIP] EmbeddingBag 适合不关心顺序的编号集合
> 它只保留汇总结果，无法区分 `[1,2,3]` 与 `[3,2,1]`。若顺序很重要，应保留 `(N,L,D)` 序列并交给 RNN、卷积或注意力 Layer。

### 3.6 Dot：点积与余弦相似度

| 框架 | 名称 |
| --- | --- |
| PyTorch | `torch.sum(a*b,dim=...)`、`torch.matmul` 或相似度函数 |
| Keras | `keras.layers.Dot` |

两个长度为 $D$ 的向量点积为：

$$
s=a^Tb=\sum_{d=1}^{D}a_db_d.
$$

输入为 `(...,D)` 与 `(...,D)` 时，按指定轴点积后，该轴通常被缩并。Dot 没有 Parameter。

若：

$$
a=[1,2,-1],\qquad b=[3,0,4],
$$

则：

$$
s=1\times3+2\times0+(-1)\times4=-1.
$$

余弦相似度还会除以两个向量的长度：

$$
\cos(a,b)=
\frac{a^Tb}{\lVert a\rVert_2\lVert b\rVert_2}.
$$

> [!WARNING] 点积会随向量长度变化
> 即使方向相同，把其中一个向量整体放大，点积也会变大；余弦相似度主要比较方向。选择哪一种，应由任务希望保留“幅度信息”还是只比较方向决定。

### 3.7 EinsumDense：用下标规则描述乘法与求和

| 框架 | 名称 |
| --- | --- |
| PyTorch | `torch.einsum` 加显式 Parameter，或在适用时使用 `Linear` |
| Keras | `keras.layers.EinsumDense` |

最常见的 Dense 规则可以写成：

$$
y_{\ldots j}=\sum_i x_{\ldots i}W_{ij}+b_j.
$$

Einsum 字符串常用 `...i,ij->...j` 表达这件事：

- `...` 表示任意前导维度原样保留；
- $i$ 同时出现在输入与权重中，却不出现在输出中，因此沿 $i$ 求和；
- $j$ 出现在权重和输出中，因此成为新的 Feature维度；
- bias 若沿 $j$ 使用，则每个输出特征拥有一个偏置。

输入 `(...,I)`、权重 `(I,O)`，输出 `(...,O)`，Parameter 数量为：

$$
IO+O.
$$

设：

$$
x=[2,3],
\qquad
W=
\begin{bmatrix}
1&4\\
-1&2
\end{bmatrix},
\qquad
b=[0.5,-0.5].
$$

则：

$$
y_0=2\times1+3\times(-1)+0.5=-0.5,
$$

$$
y_1=2\times4+3\times2-0.5=13.5.
$$

所以：

$$
y=[-0.5,13.5].
$$

EinsumDense 还可以为每个 Attention Head 保存独立权重。例如输入 `(N,L,H,D)`，权重 `(H,D,O)`，输出 `(N,L,H,O)`：

$$
y_{n,l,h,o}
=
\sum_d x_{n,l,h,d}W_{h,d,o}.
$$

这里 $h$ 同时保留在输入、权重和输出中，因此每个 Head 使用自己的权重；只有 $d$ 被求和。

> [!NOTE] 重复出现但不保留的下标会被求和
> 阅读 Einsum 时，先圈出输出右侧没有出现的重复字母，它们就是缩并维度。出现在输出中的字母决定输出轴次序。

> [!WARNING] 字符串很短，含义却可能很复杂
> 写 EinsumDense 前应先写出每个字母代表的维度、输入形状、权重形状和输出形状。只凭字符串试错，很容易在尺寸相同的情况下混淆 Sequence Length、Head 与 Feature维度。

### 3.8 Dense 的 bias 怎样供所有前导位置使用

对序列输入：

$$
x\in\mathbb{R}^{N\times L\times I},
$$

权重与 bias 为：

$$
W\in\mathbb{R}^{I\times O},
\qquad
b\in\mathbb{R}^{O}.
$$

输出的每一个位置都计算：

$$
y_{n,l,o}
=
\sum_{i=1}^{I}x_{n,l,i}W_{i,o}+b_o.
$$

$b$ 只有 $O$ 个数，却供 $N\times L$ 个位置共同使用。它不是为每个样本、每个 token 分别创建偏置。

设一个 Batch 只有一个样本，包含两个 token：

$$
x_{0,0}=[1,2],
\qquad
x_{0,1}=[3,4].
$$

令：

$$
W=
\begin{bmatrix}
1\\
2
\end{bmatrix},
\qquad
b=[0.5].
$$

第一个 token 输出：

$$
1\times1+2\times2+0.5=5.5.
$$

第二个 token 输出：

$$
3\times1+4\times2+0.5=11.5.
$$

输出形状由 `(1,2,2)` 变为 `(1,2,1)`，同一个 bias 0.5 被使用两次。

> [!NOTE] Parameter 共享是 Linear 处理多维输入的核心
> 前导维度有多少个位置，不会改变 $W,b$ 的形状。因此 Sequence Length 从 16 变为 128，Parameter 数量仍然相同，只是同一组参数被调用更多次。

### 3.9 Linear 的反向计算怎样汇总多个位置

把全部前导位置暂时合并成 $M$ 个向量：

$$
X\in\mathbb{R}^{M\times I},
\qquad
Y=XW+B.
$$

设上游梯度为：

$$
G=\frac{\partial L}{\partial Y}
\in\mathbb{R}^{M\times O}.
$$

则：

$$
\frac{\partial L}{\partial X}=GW^T,
$$

$$
\frac{\partial L}{\partial W}=X^TG,
$$

$$
\frac{\partial L}{\partial b}
=
\sum_{m=1}^{M}G_m.
$$

这里采用 $W$ 形状 `(I,O)` 的写法。第一条说明输出梯度按权重分回输入 Feature；第二条说明每个位置对共享权重的影响会相加；第三条说明 bias 梯度是全部位置输出梯度的总和。

最小例子：设单输入单输出：

$$
y=wx+b,
$$

两个位置的输入分别为 2 和 3，上游梯度分别为 4 和 -1。权重梯度为：

$$
\frac{\partial L}{\partial w}
=2\times4+3\times(-1)=5.
$$

bias 梯度为：

$$
\frac{\partial L}{\partial b}
=4+(-1)=3.
$$

> [!TIP] 查看异常梯度时记住共享次数
> 同一个 Dense 若作用于很长序列，权重梯度会汇总许多 token 的贡献。损失的 `sum` 与 `mean` 设置会进一步改变梯度尺度。

### 3.10 Embedding 与 one-hot 矩阵乘的等价关系

编号 $t$ 可以写成长度 $V$ 的 one-hot 向量 $q$。若 $t=2$、$V=4$：

$$
q=[0,0,1,0].
$$

Embedding 矩阵为：

$$
E=
\begin{bmatrix}
0&0\\
1&2\\
-1&3\\
4&0.5
\end{bmatrix}.
$$

矩阵乘得到：

$$
qE
=
0E[0]+0E[1]+1E[2]+0E[3]
=
[-1,3].
$$

这与直接取 `E[2]` 完全相同。实际 Embedding 无需先创建长度 $V$ 的稀疏 one-hot 向量，直接按编号取行通常更节省计算和存储。

反向计算时，本次输入用到哪些行，普通梯度就主要更新哪些行。若一个 Batch 的编号为 `[2,2,3]`，第 2 行会收到两个位置的梯度之和，第 3 行收到一个位置的梯度，其他未使用行通常没有来自这次输入的普通梯度。

> [!EXAMPLE] 重复 token 为什么共享同一向量
> 同一编号无论出现在第几个样本、第几个位置，都读取同一行 Parameter。训练会把这些位置的学习信号汇总到该行，这正是词或类别编号拥有统一表示的原因。

> [!WARNING] Embedding 输出宽度不是词表大小
> 输入编号范围由 $V$ 决定，输出 Feature 宽度由 $D$ 决定。例如 $V=30000,D=128$ 时，每个编号输出 128 个数，不是 30000 个数。

### 3.11 Padding、mask 与 Embedding 的关系

设编号 0 用于补齐。一个 Batch 的整数输入为：

$$
\begin{bmatrix}
5&8&2\\
4&0&0
\end{bmatrix}.
$$

Embedding 后形状为 `(2,3,D)`。第二个样本最后两个位置仍会产生 $D$ 维向量，只是该向量来自第 0 行。

PyTorch 设置 `padding_idx=0` 时，第 0 行在普通训练中不接收常规梯度更新，并常初始化为零。Keras 设置 `mask_zero=True` 时，会产生一个位置 mask：

$$
\begin{bmatrix}
\text{True}&\text{True}&\text{True}\\
\text{True}&\text{False}&\text{False}
\end{bmatrix}.
$$

支持 mask 的后续 Layer 可据此忽略补齐位置。仅有一个零向量并不自动阻止所有后续 Layer 计算；卷积、归一化、加 bias 等操作都可能让该位置再次出现非零值。

> [!NOTE] “补齐行不更新”与“后续忽略位置”是两件事
> 前者控制 Embedding Parameter 的某一行，后者控制序列 Layer 是否使用该位置。构建文本模型时通常要分别核对。

### 3.12 怎样逐字符阅读一个 Einsum 公式

考虑：

$$
y_{b,h,q,k}
=
\sum_d Q_{b,h,q,d}K_{b,h,k,d}.
$$

可按四步阅读：

1. 输出保留 $b,h,q,k$，所以输出有四个维度；
2. $d$ 同时出现在 $Q,K$ 中，却没有出现在输出，因此沿 $d$ 求和；
3. $q$ 只来自 $Q$，$k$ 只来自 $K$，所以每个 Query 位置都会与每个 Key 位置组合；
4. 若 $Q$ 形状为 `(N,H,L_q,D)`、$K$ 形状为 `(N,H,L_k,D)`，输出就是 `(N,H,L_q,L_k)`。

用一个 Head、一个 Query 的最小例子：

$$
Q=[1,2],
$$

两个 Key 为：

$$
K_0=[3,4],
\qquad
K_1=[-1,5].
$$

两个输出分别为：

$$
s_0=1\times3+2\times4=11,
$$

$$
s_1=1\times(-1)+2\times5=9.
$$

因此该 Query 对两个 Key 的原始分数为 `[11,9]`。

> [!TIP] 先用不同字母表示不同含义
> 即使两个维度长度碰巧相同，也不要随意使用同一个下标字母。相同字母通常意味着这两个轴要对齐或缩并；不同字母表示它们在输出中可以分别保留。

---

## 4. 主流激活函数与门控计算

如果多个 Linear 或 Dense 之间完全没有非线性，那么它们整体仍可合并成一个仿射计算。激活函数让模型能表达更复杂的数值关系。多数激活逐元素执行，因此输入输出形状相同，Parameter 数量为 0；PReLU 等少数 Layer 会保存可学习系数。

### 4.1 激活函数总览

| 数学计算 | PyTorch | Keras | 输出特征 |
| --- | --- | --- | --- |
| ReLU | `nn.ReLU` | `ReLU` 或 `Activation("relu")` | 负数变 0 |
| LeakyReLU | `nn.LeakyReLU` | `LeakyReLU` | 负数保留小斜率 |
| PReLU | `nn.PReLU` | `PReLU` | 负斜率可学习 |
| ELU | `nn.ELU` | `ELU` | 负半轴平滑且有下限 |
| GELU | `nn.GELU` | `GELU` 或 `Activation("gelu")` | 平滑，Transformer 常见 |
| SiLU | `nn.SiLU` | `Activation("silu")` | 又称 Swish |
| Sigmoid | `nn.Sigmoid` | `Activation("sigmoid")` | 输出在 0 与 1 之间 |
| Tanh | `nn.Tanh` | `Activation("tanh")` | 输出在 -1 与 1 之间 |
| Softplus | `nn.Softplus` | `Activation("softplus")` | 输出为正 |
| Softmax | `nn.Softmax` | `Softmax` | 指定轴之和为 1 |
| GLU | `nn.GLU` | `keras.activations.glu`，或拆分后组合 | 一半内容乘一半门值 |

### 4.2 ReLU、ReLU6 与 Threshold

ReLU 公式为：

$$
\operatorname{ReLU}(x)=\max(0,x).
$$

对每个元素独立计算。输入 `(...,E)` 输出仍为 `(...,E)`，Parameter 数量为 0。

若：

$$
x=[-3,-0.5,0,2,7],
$$

则：

$$
\operatorname{ReLU}(x)=[0,0,0,2,7].
$$

ReLU6 还把正数限制到 6：

$$
\operatorname{ReLU6}(x)=\min(6,\max(0,x)),
$$

因此上例得到：

$$
[0,0,0,2,6].
$$

Threshold 在 $x$ 不超过阈值 $t$ 时返回固定值 $v$：

$$
y=
\begin{cases}
x,&x>t,\\
v,&x\le t.
\end{cases}
$$

若 $t=1,v=-2$，输入 `[0,1,1.5,3]`，输出为：

$$
[-2,-2,1.5,3].
$$

> [!NOTE] ReLU 的梯度直觉
> 正半轴斜率为 1，负半轴斜率为 0。某个单元若在很多输入上都落在负半轴，从这些输入传回的梯度就是 0。LeakyReLU 或 PReLU 会在负半轴保留非零斜率。

> [!WARNING] 原地激活会修改输入
> PyTorch 部分激活支持 `inplace=True`。若同一个中间张量还要供残差加法或其他分支使用，原地修改会让那些位置也看到修改后的值。初学阶段使用默认的非原地形式更容易检查计算。

### 4.3 LeakyReLU 与 PReLU

LeakyReLU 为：

$$
y=
\begin{cases}
x,&x\ge0,\\
ax,&x<0.
\end{cases}
$$

$a$ 是固定负斜率。若 $a=0.1$，输入：

$$
[-3,-1,0,2]
$$

得到：

$$
[-0.3,-0.1,0,2].
$$

LeakyReLU 的 Parameter 数量为 0。

PReLU 使用相同公式，但 $a$ 是可学习 Parameter。PyTorch 可让全部 Channel 共用一个 $a$，也可为每个 Channel 设置一个；Keras 可通过共享轴设置决定参数在哪些轴共用。

若所有位置共享一个 $a$，Parameter 数量为 1；若有 $C$ 个 Channel 且每个 Channel 使用独立 $a_c$，Parameter 数量为 $C$。

手算时，设：

$$
a_0=0.1,\qquad a_1=0.25,
$$

两个 Channel 输入分别为 $-2$ 与 $-4$，则输出为：

$$
y_0=0.1\times(-2)=-0.2,
$$

$$
y_1=0.25\times(-4)=-1.
$$

> [!TIP] 先确认 PReLU 参数在哪些位置共享
> 同一个公式可能只用一个 $a$，也可能每个 Channel、每个空间位置都用不同参数。Parameter 形状不同会改变模型容量，应结合输入轴与框架设置核对。

### 4.4 Sigmoid 与 Tanh

Sigmoid 为：

$$
\sigma(x)=\frac{1}{1+e^{-x}}.
$$

输入输出形状相同，Parameter 数量为 0，输出位于 `(0,1)`。

常用数值为：

| $x$ | -2 | -1 | 0 | 1 | 2 |
| --- | ---: | ---: | ---: | ---: | ---: |
| $\sigma(x)$ | 0.119 | 0.269 | 0.500 | 0.731 | 0.881 |

它的导数为：

$$
\sigma'(x)=\sigma(x)(1-\sigma(x)).
$$

当输入绝对值很大，输出接近 0 或 1，导数会变小。

Tanh 为：

$$
\tanh(x)=\frac{e^x-e^{-x}}{e^x+e^{-x}},
$$

输出位于 `(-1,1)`。同一组输入近似得到：

| $x$ | -2 | -1 | 0 | 1 | 2 |
| --- | ---: | ---: | ---: | ---: | ---: |
| $\tanh(x)$ | -0.964 | -0.762 | 0 | 0.762 | 0.964 |

其导数为：

$$
\tanh'(x)=1-\tanh^2(x).
$$

> [!NOTE] Sigmoid 与 Tanh 在循环门中分工不同
> Sigmoid 常生成 0 到 1 的门值，用来控制保留比例；Tanh 常生成带正负号的候选内容。LSTM 与 GRU 会把两者配合使用。

> [!WARNING] 输出层要与损失输入要求配合
> 多类别训练使用 Cross Entropy 时通常直接提供 logits；多标签训练使用带 logits 的二元交叉熵时也直接提供 logits。不要因为 Sigmoid 或 Softmax 能产生概率，就在损失已经包含相关计算时再次添加。

### 4.5 ELU、CELU 与 SELU

ELU 公式为：

$$
\operatorname{ELU}(x)=
\begin{cases}
x,&x>0,\\
\alpha(e^x-1),&x\le0.
\end{cases}
$$

$\alpha$ 是固定超参数，通常不是 Parameter。输入输出形状相同。

当 $\alpha=1$：

$$
\operatorname{ELU}(-1)=e^{-1}-1\approx-0.632,
$$

$$
\operatorname{ELU}(0)=0,\qquad
\operatorname{ELU}(2)=2.
$$

CELU 的负半轴为：

$$
\alpha\left(e^{x/\alpha}-1\right),
$$

它在零点附近具有连续的一阶变化。

SELU 为正半轴和负半轴再乘固定缩放系数 $\lambda$：

$$
\operatorname{SELU}(x)=
\lambda
\begin{cases}
x,&x>0,\\
\alpha(e^x-1),&x\le0.
\end{cases}
$$

PyTorch 对应 `nn.SELU`，Keras 对应 `Activation("selu")`。标准 $\alpha,\lambda$ 是固定常数，Parameter 数量为 0。

> [!WARNING] SELU 通常要与配套设置一起考虑
> 它常与特定初始化方式及 AlphaDropout 配合。只把普通 ReLU 换成 SELU，不代表网络就会自动保持理想的数值尺度。

### 4.6 GELU、SiLU 与 Mish

GELU 的精确定义为：

$$
\operatorname{GELU}(x)=x\Phi(x),
$$

其中 $\Phi(x)$ 是标准正态分布的累积分布函数。Parameter 数量为 0，形状不变。

常见近似值：

| $x$ | -2 | -1 | 0 | 1 | 2 |
| --- | ---: | ---: | ---: | ---: | ---: |
| GELU | -0.046 | -0.159 | 0 | 0.841 | 1.955 |

SiLU 又称 Swish：

$$
\operatorname{SiLU}(x)=x\sigma(x).
$$

同一组输入得到：

| $x$ | -2 | -1 | 0 | 1 | 2 |
| --- | ---: | ---: | ---: | ---: | ---: |
| SiLU | -0.238 | -0.269 | 0 | 0.731 | 1.762 |

Mish 为：

$$
\operatorname{Mish}(x)
=x\tanh(\operatorname{softplus}(x)).
$$

其中：

$$
\operatorname{softplus}(x)=\ln(1+e^x).
$$

三者都是平滑激活。PyTorch 分别提供 `GELU`、`SiLU`、`Mish`；Keras 可用对应激活名称或 `Activation`。它们都不增加 Parameter。

> [!NOTE] GELU 与 SiLU 会保留小幅负输出
> 它们不像 ReLU 那样把所有负数直接改成 0。正输入很大时，输出逐渐接近输入本身；负输入很小时，输出逐渐接近 0。

> [!TIP] 比较激活时保持其他条件一致
> 激活函数会影响速度、内存和梯度。比较两种激活时，应使用相同数据、参数初始化、优化器与训练轮数，并同时观察任务指标和执行成本。

### 4.7 Softplus、Softsign 与收缩函数

Softplus 为：

$$
\operatorname{Softplus}(x)
=\frac{1}{\beta}\ln(1+e^{\beta x}).
$$

$\beta>0$ 控制曲线接近 ReLU 的程度。标准 $\beta=1$ 时：

$$
\operatorname{Softplus}(0)=\ln2\approx0.693,
$$

$$
\operatorname{Softplus}(1)\approx1.313,
\qquad
\operatorname{Softplus}(-1)\approx0.313.
$$

输出始终为正，Parameter 数量为 0。

Softsign 为：

$$
\operatorname{Softsign}(x)=\frac{x}{1+|x|}.
$$

输入 `[-2,0,3]` 得到：

$$
[-2/3,0,3/4].
$$

Softshrink 使用阈值 $\lambda$：

$$
y=
\begin{cases}
x-\lambda,&x>\lambda,\\
x+\lambda,&x<-\lambda,\\
0,&\text{其他情况}.
\end{cases}
$$

当 $\lambda=1$，输入 `[-2,-0.5,0,0.5,2]` 得到：

$$
[-1,0,0,0,1].
$$

以上计算都不含可学习 Parameter，输入输出形状相同。

### 4.8 Softmax、Softmin 与 LogSoftmax

| 框架 | 名称 |
| --- | --- |
| PyTorch | `nn.Softmax(dim)`、`nn.LogSoftmax(dim)` |
| Keras | `keras.layers.Softmax(axis)` |

沿指定轴，Softmax 计算：

$$
p_i=\frac{e^{z_i}}{\sum_{j=1}^{K}e^{z_j}}.
$$

其中：

- $z_i$ 是第 $i$ 个 logit；
- $K$ 是该轴的长度；
- $p_i$ 位于 0 和 1 之间；
- 同一组 $p_i$ 之和为 1；
- Parameter 数量为 0；
- 输入输出形状相同。

设：

$$
z=[1,2,0].
$$

指数近似为：

$$
[e^1,e^2,e^0]\approx[2.718,7.389,1].
$$

总和约为 11.107，因此：

$$
p\approx[0.245,0.665,0.090].
$$

Softmin 等价于对 $-z$ 做 Softmax：

$$
\operatorname{Softmin}(z)_i
=
\frac{e^{-z_i}}{\sum_j e^{-z_j}}.
$$

LogSoftmax 直接计算：

$$
\log p_i=z_i-\log\sum_j e^{z_j}.
$$

> [!WARNING] `dim` 或 `axis` 决定哪些数加起来等于 1
> 对分类 logits `(N,C)`，通常沿类别轴 $C$ 计算。若沿 Batch维度计算，得到的是同一类别在不同样本之间的比例，含义已经改变。

> [!TIP] 用求和检查轴
> Softmax 后沿目标轴求和，结果应接近 1。还要进一步确认：这一组和为 1 的元素是否确实是需要互相比较的类别、位置或其他对象。

### 4.9 GLU：内容与门值各占一半

| 框架 | 名称 |
| --- | --- |
| PyTorch | `nn.GLU(dim)` |
| Keras | `keras.activations.glu`；也可拆分张量后使用 Sigmoid 与 Multiply |

GLU 先沿指定维度把输入等分为 $a,b$，再计算：

$$
\operatorname{GLU}(a,b)=a\odot\sigma(b).
$$

若输入指定维度长度为 $2D$，输出该维度长度为 $D$。GLU 本身没有 Parameter；若前面有一个产生 $2D$ 个特征的 Dense，则 Parameter 属于该 Dense。

设：

$$
a=[2,-1],\qquad b=[0,\ln3].
$$

因为：

$$
\sigma(0)=0.5,\qquad \sigma(\ln3)=0.75,
$$

所以：

$$
y=[2\times0.5,(-1)\times0.75]=[1,-0.75].
$$

> [!WARNING] 被拆分维度必须能均分
> 输入宽度为 7 时无法等分成两个相同宽度的部分。若希望 GLU 输出宽度为 128，前一个 Linear 或 Dense 通常需要先输出 256 维。

### 4.10 SwiGLU 与 GEGLU

设输入 $x$ 先经过两组仿射计算：

$$
a=xW_a+b_a,
\qquad
g=xW_g+b_g.
$$

SwiGLU 为：

$$
y=a\odot\operatorname{SiLU}(g).
$$

GEGLU 为：

$$
y=a\odot\operatorname{GELU}(g).
$$

PyTorch 与 Keras 都可由两组 Linear 或 Dense、相应激活和逐元素乘法组成。若输入宽度为 $I$、门控内部宽度为 $D$，两组投影使用 bias 时共有：

$$
2(ID+D)
$$

个 Parameter。若后面再投影回输出宽度 $O$，还需增加：

$$
DO+O.
$$

数值例子：设某个位置上：

$$
a=[2,-1],\qquad g=[0,1].
$$

SiLU 的值为：

$$
\operatorname{SiLU}(0)=0,\qquad
\operatorname{SiLU}(1)\approx0.731.
$$

因此：

$$
y=[2\times0,(-1)\times0.731]=[0,-0.731].
$$

> [!NOTE] 门控同时使用内容和控制信号
> $a$ 提供候选内容，激活后的 $g$ 决定每个位置通过多少。两者逐元素相乘，所以宽度必须兼容。

### 4.11 激活函数怎样改变反向梯度

设：

$$
z=wx+b,
\qquad
a=f(z),
$$

损失为 $L$。复合函数求导得到：

$$
\frac{\partial L}{\partial z}
=
\frac{\partial L}{\partial a}f'(z),
$$

$$
\frac{\partial L}{\partial w}
=
\frac{\partial L}{\partial z}x.
$$

激活的导数 $f'(z)$ 位于上游梯度与权重梯度之间，因此它会直接决定有多少梯度继续传递。

取：

$$
x=2,\quad w=-1,\quad b=0.5.
$$

预激活值：

$$
z=(-1)\times2+0.5=-1.5.
$$

假设上游梯度 $\partial L/\partial a=3$。

使用 ReLU 时，$z<0$，所以：

$$
f'(z)=0,
\qquad
\frac{\partial L}{\partial w}=3\times0\times2=0.
$$

使用负斜率 $0.1$ 的 LeakyReLU 时：

$$
f'(z)=0.1,
\qquad
\frac{\partial L}{\partial w}=3\times0.1\times2=0.6.
$$

同一个前向输入，因为激活导数不同，权重收到的梯度不同。

> [!NOTE] 单个样本梯度为 0 不代表参数永远不更新
> 同一 Parameter 会供一个 Batch 中许多样本和位置共同使用。其他位置若使该单元落在非零导数区域，仍可贡献梯度。应观察一段训练中的整体激活分布，而不是只看一个元素。

### 4.12 Sigmoid 与 Tanh 的饱和区域

Sigmoid 在 $x=0$ 时：

$$
\sigma(0)=0.5,
\qquad
\sigma'(0)=0.25.
$$

当 $x=10$：

$$
\sigma(10)\approx0.99995,
$$

$$
\sigma'(10)
=
\sigma(10)(1-\sigma(10))
\approx0.000045.
$$

输入从 0 增大到 10，导数从 0.25 降到非常小。负方向很大时也有相似情况。

Tanh 在 $x=0$ 时：

$$
\tanh(0)=0,
\qquad
\tanh'(0)=1.
$$

当 $x=3$：

$$
\tanh(3)\approx0.995,
\qquad
\tanh'(3)\approx0.010.
$$

因此，Sigmoid 和 Tanh 通常在接近零的输入区域变化较明显，在绝对值很大的区域变化较小。

> [!TIP] 归一化和初始化会影响激活所处区域
> 若前一层输出绝对值普遍很大，Sigmoid 或 Tanh 更容易进入导数很小的区域。检查问题时，可统计激活前输入的最小值、最大值、均值和标准差。

### 4.13 Hardsigmoid、Hardswish 与 Hardtanh

Hardsigmoid 用分段直线近似 Sigmoid：

$$
\operatorname{Hardsigmoid}(x)=
\begin{cases}
0,&x\le-3,\\
x/6+1/2,&-3<x<3,\\
1,&x\ge3.
\end{cases}
$$

PyTorch 对应 `nn.Hardsigmoid`，Keras 对应 `Activation("hard_sigmoid")`。Parameter 数量为 0，形状不变。

对输入：

$$
[-4,-3,0,3,4],
$$

输出为：

$$
[0,0,0.5,1,1].
$$

Hardswish 为：

$$
\operatorname{Hardswish}(x)
=x\operatorname{Hardsigmoid}(x).
$$

同一组输入得到：

$$
[0,0,0,3,4].
$$

在 $x=-1$ 时：

$$
\operatorname{Hardsigmoid}(-1)
=-1/6+1/2=1/3,
$$

所以：

$$
\operatorname{Hardswish}(-1)=-1/3.
$$

Hardtanh 把输入限制到区间 $[a,b]$：

$$
y=\min(b,\max(a,x)).
$$

设 $a=-1,b=1$，输入 `[-3,-0.5,0.8,2]`，输出：

$$
[-1,-0.5,0.8,1].
$$

> [!NOTE] hard 通常表示分段计算
> 这些函数使用分段直线或截断，计算形式较简单。hard 不表示输出一定是离散值，中间区域仍可连续变化。

### 4.14 输出 Layer 的激活由任务决定

隐藏层激活主要增加非线性；输出处还要满足任务和损失的输入要求。

#### 单标签多类别

模型输出：

$$
z\in\mathbb{R}^{N\times C}
$$

作为 logits。若损失直接接收 logits，模型内部通常不先做 Softmax。需要展示概率时，再计算：

$$
p_{n,c}
=
\frac{e^{z_{n,c}}}{\sum_j e^{z_{n,j}}}.
$$

同一样本的 $C$ 个类别概率之和为 1。

#### 多标签分类

每个类别独立判断，单个 logit 可通过 Sigmoid 得到：

$$
p_{n,c}=\sigma(z_{n,c}).
$$

各类别概率不要求总和为 1。若损失名称表明内部已包含 logits 处理，训练输入仍应是 $z$。

#### 回归

- 输出可以为任意实数：最后一层不加激活；
- 输出必须为正：可用 Softplus；
- 输出需要位于 0 和 1 之间：可用 Sigmoid；
- 输出需要位于 -1 和 1 之间：可用 Tanh。

数值例子：模型要预测一个正的时间长度，预激活值为 $z=-2$。若直接输出会得到负数；使用 Softplus：

$$
\ln(1+e^{-2})\approx0.127,
$$

得到正值，同时仍可通过平滑导数更新前面参数。

> [!WARNING] 限制输出区间会同时限制梯度形态
> Sigmoid 能保证 0 到 1，但输入绝对值很大时导数会变小。若目标接近区间端点，需结合损失与数据变换一起设计。

### 4.15 主流激活的选择表

| 使用位置 | 常见起点 | 需要留意 |
| --- | --- | --- |
| 普通 MLP 隐藏层 | ReLU | 负半轴梯度为 0 |
| 希望负数保留小斜率 | LeakyReLU、PReLU | PReLU 会增加 Parameter |
| Transformer FFN | GELU、SiLU、SwiGLU | 门控版本常需要两组投影 |
| 移动端卷积网络 | ReLU6、Hardswish | 输出截断或分段形式 |
| LSTM、GRU 门值 | Sigmoid | 通常已包含在循环 Layer 内部 |
| 带正负号的候选状态 | Tanh | 大绝对值区域导数较小 |
| 正数回归输出 | Softplus | 0 输入输出约为 0.693 |
| 多类别概率展示 | Softmax | 必须选对类别轴 |

> [!TIP] 初学者可从三项检查激活
> 第一看输出形状是否保持；第二用 `[-2,-1,0,1,2]` 手算或查表；第三写出导数在负数、零附近和较大正数处的行为。完成这三步后，函数名称就不再只是需要死记的标签。

---

## 5. 归一化、Dropout 与噪声类 Layer

归一化 Layer 通常包含“选定一组元素、计算统计数据、标准化、再缩放和平移”四步。不同 Layer 的主要差异不是减均值和除标准差的形式，而是哪一组元素共享同一均值与方差。

### 5.1 统一的均值—方差公式

对一个统计集合 $\mathcal S$，均值为：

$$
\mu=\frac{1}{M}\sum_{i\in\mathcal S}x_i,
$$

方差为：

$$
v=\frac{1}{M}\sum_{i\in\mathcal S}(x_i-\mu)^2,
$$

标准化结果为：

$$
\widehat x_i=
\frac{x_i-\mu}{\sqrt{v+\epsilon}},
$$

仿射调整为：

$$
y_i=\gamma_i\widehat x_i+\beta_i.
$$

符号含义：

- $\mathcal S$ 是共同计算统计数据的元素集合；
- $M$ 是集合中的元素数量；
- $\mu$ 是均值；
- $v$ 是方差；
- $\epsilon$ 是防止分母过小的正数；
- $\gamma$ 是可学习缩放；
- $\beta$ 是可学习平移。

> [!NOTE] “统计轴”和“参数轴”要分开看
> 某些轴参与均值与方差计算，不表示参数也沿这些轴各自独立。例如 BatchNorm 对 Batch维度与空间维度统计，却通常只为每个 Channel 保存一组 $\gamma,\beta$。

### 5.2 Batch Normalization

| 框架 | 名称 |
| --- | --- |
| PyTorch | `BatchNorm1d`、`BatchNorm2d`、`BatchNorm3d` |
| Keras | `BatchNormalization` |

以 PyTorch 图像 `(N,C,H,W)` 为例，固定 Channel $c$，对 $N,H,W$ 统计：

$$
\mu_c=
\frac{1}{NHW}
\sum_{n=1}^{N}
\sum_{h=1}^{H}
\sum_{w=1}^{W}
x_{n,c,h,w},
$$

$$
v_c=
\frac{1}{NHW}
\sum_{n,h,w}
(x_{n,c,h,w}-\mu_c)^2.
$$

输出为：

$$
y_{n,c,h,w}
=
\gamma_c
\frac{x_{n,c,h,w}-\mu_c}
{\sqrt{v_c+\epsilon}}
+\beta_c.
$$

Keras 默认图像形状为 `(N,H,W,C)`，公式相同，只是 Channel维度的位置通常在最后。输出形状与输入相同。

若 `affine=True` 或 Keras 中 `scale=True,center=True`，Parameter 数量为：

$$
2C,
$$

即 $C$ 个 $\gamma$ 和 $C$ 个 $\beta$。运行均值和运行方差各有 $C$ 个数，但它们属于非训练状态，不计入可学习 Parameter。

二维手算：输入 `(N,C)=(2,2)`：

$$
x=
\begin{bmatrix}
1&10\\
3&14
\end{bmatrix}.
$$

Channel 0 使用 `[1,3]`：

$$
\mu_0=2,\qquad v_0=1.
$$

Channel 1 使用 `[10,14]`：

$$
\mu_1=12,\qquad v_1=4.
$$

忽略 $\epsilon$，并令 $\gamma=1,\beta=0$，输出为：

$$
y=
\begin{bmatrix}
-1&-1\\
1&1
\end{bmatrix}.
$$

> [!NOTE] BatchNorm 的输入维数名称表示空间维度数量
> `BatchNorm1d` 可接收 `(N,C)` 或 `(N,C,L)`；`BatchNorm2d` 常接收 `(N,C,H,W)`；`BatchNorm3d` 常接收 `(N,C,D,H,W)`。名称中的 1d、2d、3d 不包含 Batch维度和 Channel维度。

> [!WARNING] 序列轴次序要特别核对
> PyTorch `BatchNorm1d(C)` 把第 1 维看作 Channel维度。普通序列 `(N,L,E)` 若希望按 Feature $E$ 归一化，通常要先调整为 `(N,E,L)`，计算后再调回 `(N,L,E)`。

#### 5.2.1 训练与推理使用的数据不同

训练时，BatchNorm 使用当前一个 Batch 的均值和方差生成输出，并更新运行统计数据。推理时，默认使用训练期间保存的运行均值和运行方差。

PyTorch 的更新形式为：

$$
\text{running}
\leftarrow
(1-m)\text{running}
+m\text{current}.
$$

Keras 常用形式为：

$$
\text{moving}
\leftarrow
m\text{moving}
+(1-m)\text{current}.
$$

两个框架参数都常叫 momentum，但 $m$ 所乘的一侧不同。若想让新统计数据占 10%，PyTorch 常设置 $m=0.1$，Keras 常设置 $m=0.9$。

> [!WARNING] 不要只复制 momentum 数值
> 从一个框架迁移配置到另一个框架时，应先写出更新公式，再确认旧数据与当前数据各占多少。相同的数值可能产生不同更新速度。

> [!TIP] Batch Size 较小时先数每个 Channel 有多少统计元素
> 对 `(N,C,H,W)`，每个 Channel 使用 $NHW$ 个数。即使 Batch Size 为 1，只要 $H,W$ 较大，仍有多个空间元素；若空间也缩到 `1×1`，每个 Channel 就只剩一个数，训练计算可能无法进行或统计数据不稳定。

### 5.3 Layer Normalization

| 框架 | 名称 |
| --- | --- |
| PyTorch | `nn.LayerNorm(normalized_shape)` |
| Keras | `keras.layers.LayerNormalization(axis)` |

对序列输入 `(N,L,E)`，最常见设置是只对最后的 Feature维度 $E$ 统计。固定样本 $n$ 与位置 $l$：

$$
\mu_{n,l}
=
\frac{1}{E}\sum_{e=1}^{E}x_{n,l,e},
$$

$$
v_{n,l}
=
\frac{1}{E}
\sum_{e=1}^{E}
(x_{n,l,e}-\mu_{n,l})^2.
$$

输出为：

$$
y_{n,l,e}
=
\gamma_e
\frac{x_{n,l,e}-\mu_{n,l}}
{\sqrt{v_{n,l}+\epsilon}}
+\beta_e.
$$

输入输出形状相同。若只归一化宽度 $E$ 且同时使用缩放和平移，Parameter 数量为：

$$
2E.
$$

若 PyTorch 设置 `normalized_shape=(H,W)`，则最后两个维度一起统计，$\gamma,\beta$ 的形状也为 `(H,W)`，Parameter 数量是 $2HW$。Keras 可通过 `axis` 指定一个或多个轴。

手算一个 token：

$$
x=[1,3].
$$

均值：

$$
\mu=2.
$$

方差：

$$
v=\frac{(1-2)^2+(3-2)^2}{2}=1.
$$

忽略 $\epsilon$ 且令 $\gamma=1,\beta=0$：

$$
y=[-1,1].
$$

若一个 Batch 中另一个 token 为 `[100,200]`，它不会参与 `[1,3]` 的均值和方差。

> [!NOTE] LayerNorm 不依赖同一 Batch 中的其他样本
> Batch Size 从 1 改为 32，不会改变一个固定 token 使用的统计集合。这也是它常用于 Transformer 的原因之一。

> [!WARNING] PyTorch 的 `normalized_shape` 从最后维度开始匹配
> `LayerNorm(8)` 要求最后一维长度为 8；它不会搜索任意一个长度为 8 的轴。输入 `(N,8,L)` 且 $L\ne8$ 时，不能据此认为 Channel维度会被自动选择。

### 5.4 Group Normalization

| 框架 | 名称 |
| --- | --- |
| PyTorch | `nn.GroupNorm(num_groups,num_channels)` |
| Keras | `keras.layers.GroupNormalization(groups,axis)` |

GroupNorm 把 $C$ 个 Channel 分成 $G$ 组，每组包含：

$$
C_g=\frac{C}{G}
$$

个 Channel，因此 $C$ 必须能被 $G$ 整除。

对 PyTorch 图像 `(N,C,H,W)`，固定样本 $n$ 与组 $g$，在该组 Channel 及全部空间位置上计算：

$$
\mu_{n,g}
=
\frac{1}{C_gHW}
\sum_{c\in g}\sum_h\sum_w
x_{n,c,h,w}.
$$

输出仍按每个 Channel 使用 $\gamma_c,\beta_c$：

$$
y_{n,c,h,w}
=
\gamma_c\widehat x_{n,c,h,w}+\beta_c.
$$

输入输出形状相同，使用仿射参数时 Parameter 数量为：

$$
2C.
$$

数值例子：一个样本有 4 个 Channel，每个 Channel 暂时只有一个数：

$$
x=[1,3,10,14],
\qquad G=2.
$$

第 0 组 `[1,3]`：

$$
\mu_0=2,\qquad v_0=1,
$$

标准化后为 `[-1,1]`。

第 1 组 `[10,14]`：

$$
\mu_1=12,\qquad v_1=4,
$$

标准化后也为 `[-1,1]`。合起来：

$$
y=[-1,1,-1,1].
$$

> [!NOTE] 两个特殊设置
> $G=1$ 时，每个样本的全部 Channel 与空间位置共同统计；$G=C$ 时，每个组只有一个 Channel，计算方式接近 InstanceNorm。

> [!TIP] GroupNorm 常用于每张卡 Batch Size 较小的图像模型
> 它不跨样本统计，一个样本的输出不会因为同一 Batch 中换入另一张图而改变。

> [!WARNING] Keras 要明确 Channel轴
> channels-last 图像通常令 `axis=-1`；channels-first 则使用 Channel维度所在轴。组数、Channel 数和轴位置必须一起核对。

### 5.5 Instance Normalization

| 框架 | 名称 |
| --- | --- |
| PyTorch | `InstanceNorm1d`、`InstanceNorm2d`、`InstanceNorm3d` |
| Keras | 可用 `GroupNormalization(groups=-1)` 表达每个 Channel 一组；部分扩展库也提供独立名称 |

对图像 `(N,C,H,W)`，InstanceNorm 固定样本 $n$ 与 Channel $c$，只在该 Channel 的空间位置上统计：

$$
\mu_{n,c}
=
\frac{1}{HW}
\sum_h\sum_w x_{n,c,h,w},
$$

$$
v_{n,c}
=
\frac{1}{HW}
\sum_h\sum_w
(x_{n,c,h,w}-\mu_{n,c})^2.
$$

输出形状与输入相同。PyTorch InstanceNorm 默认 `affine=False`，此时可学习 Parameter 数量为 0；若启用仿射参数，则为 $2C$。使用 GroupNormalization 模拟时通常也有每 Channel 的缩放和平移，应查看其 `scale` 与 `center` 设置。

数值例子：一个样本的某个 Channel 为：

$$
\begin{bmatrix}
1&3\\
5&7
\end{bmatrix}.
$$

均值：

$$
\mu=4.
$$

方差：

$$
v=
\frac{(-3)^2+(-1)^2+1^2+3^2}{4}
=5.
$$

忽略 $\epsilon$，标准差为 $\sqrt5\approx2.236$，输出近似：

$$
\begin{bmatrix}
-1.342&-0.447\\
0.447&1.342
\end{bmatrix}.
$$

同一 Batch 中另一张图不会参与这组计算。

> [!NOTE] InstanceNorm 与 BatchNorm 的固定下标不同
> InstanceNorm 固定 $n,c$，统计 $h,w$；BatchNorm 固定 $c$，统计 $n,h,w$。因此前者每个样本独立，后者会使用同一 Batch 中其他样本的数据。

> [!WARNING] 空间元素只有一个时缺少变化
> 若某个 Channel 只有一个空间值，减去自身均值后就是 0。此时标准化结果没有可用的相对变化，应重新考虑 Layer 位置或归一化方式。

### 5.6 RMS Normalization

| 框架 | 名称 |
| --- | --- |
| PyTorch | 新版本提供 `nn.RMSNorm`；旧版本可按公式组成自定义 Module |
| Keras | `keras.layers.RMSNormalization` |

RMSNorm 不减均值，而是计算平方均值的平方根：

$$
\operatorname{RMS}(x)
=
\sqrt{\frac{1}{E}\sum_{e=1}^{E}x_e^2+\epsilon}.
$$

输出为：

$$
y_e=\gamma_e\frac{x_e}{\operatorname{RMS}(x)}.
$$

其中：

- $E$ 是被归一化的 Feature 数量；
- $\epsilon$ 防止分母过小；
- $\gamma_e$ 是每个 Feature 的可学习缩放；
- 标准 RMSNorm 通常没有减均值步骤，也通常不使用 $\beta$。

对输入 `(N,L,E)`，常在最后的 $E$ 个 Feature 上计算，输出形状不变。使用逐 Feature 缩放时 Parameter 数量为：

$$
E.
$$

手算：

$$
x=[3,4].
$$

忽略 $\epsilon$：

$$
\operatorname{RMS}(x)
=
\sqrt{\frac{3^2+4^2}{2}}
=
\sqrt{12.5}
\approx3.536.
$$

令 $\gamma=[1,1]$，得到：

$$
y\approx[0.849,1.131].
$$

可以看到，输出没有变成均值为 0，因为 RMSNorm 没有减去均值。

> [!NOTE] RMSNorm 与 LayerNorm 的主要差别
> LayerNorm 通常先减均值，再除以标准差；RMSNorm 直接按平方均值缩放。两者都常在每个 token 的 Feature维度内部计算，不依赖同一 Batch 的其他样本。

> [!WARNING] 先核对框架版本
> 不同版本是否自带 RMSNorm、参数名称及默认 $\epsilon$ 可能不同。模型文件在不同环境间使用时，应同时记录框架版本和 Layer 配置。

### 5.7 五类归一化怎样快速区分

以 PyTorch 图像 `(N,C,H,W)` 为例：

| Layer | 每组固定什么 | 每组统计什么 | 常见 Parameter 数量 |
| --- | --- | --- | ---: |
| BatchNorm2d | 固定 $c$ | $n,h,w$ | $2C$ |
| InstanceNorm2d | 固定 $n,c$ | $h,w$ | 默认 0；启用后 $2C$ |
| GroupNorm | 固定 $n,g$ | 组内 $c,h,w$ | $2C$ |
| LayerNorm(C,H,W) | 固定 $n$ | $c,h,w$ | $2CHW$ |
| RMSNorm | 由指定 Feature轴决定 | 平方均值，不减均值 | 常为归一化尺寸 |

> [!TIP] 用“固定下标”读归一化
> 先写出哪些下标固定，再让其余参与统计的下标变化。例如 BatchNorm2d 固定 $c$，InstanceNorm2d 固定 $n,c$，GroupNorm 固定 $n,g$。这个方法比只背 Layer 名称更可靠。

### 5.8 Dropout：随机置零并对保留值缩放

| 框架 | 名称 |
| --- | --- |
| PyTorch | `nn.Dropout(p)` |
| Keras | `keras.layers.Dropout(rate)` |

训练时，对每个元素采样：

$$
m_i\sim\operatorname{Bernoulli}(1-p),
$$

并计算：

$$
y_i=\frac{m_i}{1-p}x_i.
$$

其中：

- $p$ 是置零概率；
- $1-p$ 是保留概率；
- $m_i=0$ 时输出为 0；
- $m_i=1$ 时保留输入并除以 $1-p$；
- Dropout 没有可学习 Parameter；
- 输入输出形状相同。

设：

$$
x=[2,4,6,8],\qquad p=0.5.
$$

某次随机 mask 为：

$$
m=[1,0,1,0].
$$

则：

$$
y=
\frac{[1,0,1,0]}{0.5}
\odot[2,4,6,8]
=[4,0,12,0].
$$

虽然这一次数值变大，但对随机性取平均：

$$
\mathbb E[y_i]=x_i.
$$

推理时不再随机置零，输出通常直接为：

$$
y=x.
$$

> [!NOTE] 两个框架的概率名称不同
> PyTorch 使用 `p`，Keras 使用 `rate`，都表示置零概率，不是保留概率。设置为 0.2 表示平均约 20% 的目标被置零。

> [!WARNING] Dropout 训练与推理规则不同
> 如果推理时仍按训练状态工作，相同输入会得到随机输出；如果训练时误用推理状态，Dropout 就不会提供随机扰动。必须正确设置模型状态。

> [!QUESTION] 为什么保留值要除以 $1-p$
> 若不缩放，训练时输出平均值会变成原来的 $1-p$ 倍。除以保留概率后，训练输出的期望与输入一致，推理时无需再额外乘系数。

### 5.9 Spatial Dropout 与 Channel Dropout

| 数据类型 | PyTorch | Keras |
| --- | --- | --- |
| 一维特征 | `Dropout1d` | `SpatialDropout1D` |
| 二维图像 | `Dropout2d` | `SpatialDropout2D` |
| 三维体数据 | `Dropout3d` | `SpatialDropout3D` |

普通 Dropout 通常逐元素采样 mask。Spatial Dropout 或 PyTorch 的 Channel Dropout 会让同一个 Channel 的整片位置共享 mask。

以一个样本、两个 Channel、每个 Channel 有三个位置为例：

$$
x=
\begin{bmatrix}
1&2&3\\
10&20&30
\end{bmatrix}.
$$

设 $p=0.5$，某次 Channel mask 为：

$$
m=[0,1].
$$

则第 0 个 Channel 整体变为 0，第 1 个 Channel 整体保留并放大两倍：

$$
y=
\begin{bmatrix}
0&0&0\\
20&40&60
\end{bmatrix}.
$$

Parameter 数量为 0，输出形状不变。

> [!NOTE] Channel轴随框架数据格式变化
> PyTorch 二维图像常用 `(N,C,H,W)`；Keras SpatialDropout2D 默认常用 `(N,H,W,C)`。两者都以整个 Channel 为单位随机处理，但 Channel维度的位置不同。

> [!TIP] 特征图相邻位置高度相关时可考虑 Spatial Dropout
> 普通逐元素 Dropout 只去掉零散像素，邻近位置仍可能提供非常相似的信息；按 Channel 处理会移除整组特征响应。

### 5.10 AlphaDropout

| 框架 | 名称 |
| --- | --- |
| PyTorch | `nn.AlphaDropout`、`nn.FeatureAlphaDropout` |
| Keras | `keras.layers.AlphaDropout` |

AlphaDropout 主要为 SELU 网络设计。它不是简单把目标设为 0，而是设为与 SELU 负饱和值相关的常数，再进行仿射调整，以尽量保持输入的均值和方差。

可写成概念公式：

$$
y=a\left(mx+(1-m)\alpha'\right)+b,
$$

其中：

- $m$ 是 0 或 1 的随机 mask；
- $\alpha'$ 是固定负值；
- $a,b$ 是为保持数值尺度而使用的固定系数；
- 没有可学习 Parameter；
- 输入输出形状相同。

若某个简化例子取 $\alpha'=-1.5$，输入 `[2,4]`，mask 为 `[1,0]`，在暂时忽略后续固定仿射调整时，中间结果是：

$$
[2,-1.5].
$$

正式 AlphaDropout 还会使用 $a,b$ 调整该结果。

> [!WARNING] AlphaDropout 不是普通 Dropout 的任意替代品
> 它主要服务于 SELU 及其配套初始化。ReLU、GELU 等网络通常仍使用普通 Dropout 或 Spatial Dropout。

### 5.11 GaussianNoise：加性高斯噪声

| 框架 | 名称 |
| --- | --- |
| PyTorch | 通常用张量随机运算或自定义 Module |
| Keras | `keras.layers.GaussianNoise(stddev)` |

训练时：

$$
y=x+\epsilon,
$$

其中：

$$
\epsilon\sim\mathcal N(0,s^2).
$$

$s$ 是噪声标准差。该 Layer 没有可学习 Parameter，输入输出形状相同；推理时通常返回原输入。

设：

$$
x=[1,2,3],
$$

某次采样恰好为：

$$
\epsilon=[0.1,-0.2,0.05],
$$

则：

$$
y=[1.1,1.8,3.05].
$$

> [!NOTE] 数字例子只展示某一次采样
> 高斯噪声每次训练调用都可能不同。其均值为 0，所以多次采样的平均扰动接近 0，但单次输出不会等于输入。

> [!TIP] 噪声尺度要结合输入尺度
> 输入大多位于 `[-1,1]` 时，标准差 0.1 可能明显；输入大多在数百范围时，同样的 0.1 影响很小。设置前先观察输入分布。

### 5.12 GaussianDropout：乘性高斯噪声

Keras 提供 `keras.layers.GaussianDropout(rate)`；PyTorch 通常使用自定义 Module 完成。

训练时：

$$
y=xr,
$$

其中：

$$
r\sim
\mathcal N\left(
1,\frac{p}{1-p}
\right).
$$

这里：

- $p$ 是 rate；
- $r$ 的均值为 1；
- $r$ 的方差为 $p/(1-p)$；
- Layer 没有可学习 Parameter；
- 输入输出形状相同；
- 推理时通常返回 $x$。

若 $p=0.2$，则：

$$
\operatorname{Var}(r)=\frac{0.2}{0.8}=0.25,
$$

标准差为 0.5。设某次采样：

$$
r=[1.1,0.7,1.3],
\qquad
x=[2,4,6],
$$

则：

$$
y=[2.2,2.8,7.8].
$$

> [!NOTE] GaussianNoise 是加法，GaussianDropout 是乘法
> 前者加入与输入独立的扰动；后者按随机比例缩放输入。两者都只在训练时启用，但适合的数据性质并不完全相同。

### 5.13 归一化与 Dropout 的次序怎样理解

常见结构包括“Linear 或卷积、归一化、激活、Dropout”，也有 Transformer 使用归一化在子层之前或之后的结构。次序改变后，每个 Layer 看到的分布不同，不能认为只是写法差异。

例如先 BatchNorm 再 Dropout：

1. BatchNorm 先使用完整输入计算统计数据；
2. Dropout 再随机改变部分输出；
3. BatchNorm 的运行统计数据不会直接看到这次 Dropout mask。

若先 Dropout 再 BatchNorm：

1. 部分输入先被置零并缩放；
2. BatchNorm 的当前统计数据会受到随机 mask 影响；
3. 运行统计数据也会吸收这种随机变化。

> [!WARNING] 不要机械套用唯一次序
> CNN、MLP、RNN 与 Transformer 的常见结构不同。应先确认所复现模型的设计，再结合训练稳定性、推理规则和任务指标调整。

> [!TIP] 检查这类组合时逐层记录四项数据
> 对每个 Layer 记录输入形状、输出形状、均值和标准差；训练状态与推理状态分别检查一次。若差异来自 Dropout 或 BatchNorm，就能较快定位到具体位置。

---

## 6. 卷积：从局部乘加到通道组合

卷积 Layer 的核心任务，是让一组较小的权重在输入的空间维上反复使用。它不会为每一个空间位置准备一套独立权重，而是让同一组权重依次读取不同位置的局部区域。这样的参数共享方式既能提取局部特征，也能避免参数数目随着图像高宽快速增加。

### 6.1 先看懂 Conv1D、Conv2D 与 Conv3D 的输入形状

层名称中的 1D、2D、3D 表示卷积核沿几个空间维移动，不表示输入张量总共只有几个维度。输入还要包含 Batch维度和 Channel维度，所以带 Batch维度的输入通常分别是三维、四维和五维张量。

| 计算 | PyTorch Layer | Keras Layer | PyTorch 默认输入 | Keras 默认输入 |
| --- | --- | --- | --- | --- |
| 一维卷积 | `Conv1d` | `Conv1D` | $(N,C_{\mathrm{in}},L)$ | $(N,L,C_{\mathrm{in}})$ |
| 二维卷积 | `Conv2d` | `Conv2D` | $(N,C_{\mathrm{in}},H,W)$ | $(N,H,W,C_{\mathrm{in}})$ |
| 三维卷积 | `Conv3d` | `Conv3D` | $(N,C_{\mathrm{in}},D,H,W)$ | $(N,D,H,W,C_{\mathrm{in}})$ |

这里的符号含义如下：

- $N$：Batch Size；
- $C_{\mathrm{in}}$：输入 Channel 数；
- $C_{\mathrm{out}}$：输出 Channel 数；
- $L$：一维信号长度或序列长度；
- $D$：体数据深度或视频帧数；
- $H,W$：高度和宽度。

PyTorch 图像卷积默认使用 channels-first，Channel维度位于空间维之前。Keras 默认使用 channels-last，Channel维度位于空间维之后。Keras 的卷积 Layer 可以通过 `data_format` 改用 channels-first，但模型中的其他 Layer 也要采用相同次序。

> [!NOTE] 1D 不等于输入只有一个维度
> 一段音频若有 2 个输入 Channel、16000 个采样点，PyTorch 形状是 $(N,2,16000)$，Keras 默认形状是 $(N,16000,2)$。卷积核只沿长度 16000 的轴移动，Batch维度和 Channel维度并不是滑动方向。

自然语言中的 token 序列通常写成 $(N,L,E)$，其中 $E$ 是 Feature维度宽度。Keras `Conv1D` 可以直接把 $E$ 当作 Channel维度。PyTorch `Conv1d` 则需要采用 $(N,E,L)$ 的次序，也就是让 Feature维度位于长度之前。卷积完成后，若后续 Layer 要求 $(N,L,E')$，还要再次交换这两个轴。

> [!WARNING] 形状数值相同也可能含义错误
> 假设 $L=64$、$E=64$，把 $(N,L,E)$ 错当成 $(N,E,L)$ 时，形状检查可能无法发现问题，因为两个轴长度恰好相同。此时卷积会沿错误的维度移动。调试时不要只打印数字，还应写出每个轴的含义。

### 6.2 一维卷积公式：一个输出数怎样得到

先看 groups 为 1 的一维卷积。输出第 $n$ 个样本、第 $o$ 个输出 Channel、第 $t$ 个位置的数值为：

$$
y_{n,o,t}
=
b_o+
\sum_{c=0}^{C_{\mathrm{in}}-1}
\sum_{r=0}^{K-1}
w_{o,c,r}\,
x_{n,c,\,ts-p+rd}.
$$

各符号表示：

| 符号 | 含义 |
| --- | --- |
| $n$ | 样本编号 |
| $o$ | 输出 Channel 编号 |
| $t$ | 输出位置编号 |
| $c$ | 输入 Channel 编号 |
| $r$ | 卷积核内部位置编号 |
| $K$ | kernel size |
| $s$ | stride |
| $p$ | padding |
| $d$ | dilation |
| $w_{o,c,r}$ | 第 $o$ 个输出 Channel 对第 $c$ 个输入 Channel 的第 $r$ 个权重 |
| $b_o$ | 第 $o$ 个输出 Channel 的偏置 |

索引 $ts-p+rd$ 表明一次计算读取哪些输入位置。若索引位于原输入之外，就按照 padding 设置取得补入值。

> [!NOTE] 深度学习卷积通常直接做互相关
> 数学教材中的严格卷积常把核反转后再滑动。PyTorch 与 Keras 的卷积 Layer 通常不反转权重，而是按权重存放顺序直接乘加。由于权重由训练得到，这种差异不会妨碍 Layer 学习局部特征。

#### 手算：两个输入 Channel 合成一个输出 Channel

设一维输入有两个 Channel：

$$
x_0=[1,2,3,4],\qquad x_1=[10,20,30,40].
$$

某个输出 Channel 在两个输入 Channel 上的核分别为：

$$
w_0=[1,2],\qquad w_1=[0.1,0.2],
$$

偏置为 $b=1$，stride 为 1，不使用 padding。第一个输出位置读取两个 Channel 的前两个数：

$$
\begin{aligned}
y_0
&=1
+(1\times1+2\times2)
+(10\times0.1+20\times0.2)\\
&=1+5+5=11.
\end{aligned}
$$

第二个位置读取 $[2,3]$ 和 $[20,30]$：

$$
y_1
=1+(2\times1+3\times2)+(20\times0.1+30\times0.2)
=17.
$$

第三个位置读取 $[3,4]$ 和 $[30,40]$：

$$
y_2
=1+(3\times1+4\times2)+(30\times0.1+40\times0.2)
=23.
$$

所以这个输出 Channel 为 $[11,17,23]$。若 `out_channels=8`，就有 8 组不同的权重和 8 个偏置，每组各自产生一个输出 Channel。

> [!TIP] 阅读卷积时先固定一个输出数
> 初学时不要一开始就试图想象整个四维或五维张量。先固定样本编号、输出 Channel 和输出位置，再列出这个数读取的输入 Channel 与局部位置。一个输出数看懂以后，其余位置只是重复相同规则。

### 6.3 二维与三维卷积只是增加滑动轴

二维卷积的输出为：

$$
\begin{aligned}
y_{n,o,h,w}
=b_o
&+\sum_{c=0}^{C_{\mathrm{in}}-1}
\sum_{r=0}^{K_h-1}
\sum_{q=0}^{K_w-1}\\
&W_{o,c,r,q}\,
X_{n,c,\,hs_h-p_h+rd_h,\,ws_w-p_w+qd_w}.
\end{aligned}
$$

$K_h,K_w$ 是卷积核高宽，$s_h,s_w$ 是两个方向的 stride，$p_h,p_w$ 是两个方向的 padding，$d_h,d_w$ 是两个方向的 dilation。三维卷积再增加深度轴 $D$ 及核位置 $K_d$，计算思路完全相同。

#### 手算：单 Channel 的 $2\times2$ 卷积

输入为：

$$
X=
\begin{bmatrix}
1&2&3\\
4&5&6\\
7&8&9
\end{bmatrix},
\qquad
W=
\begin{bmatrix}
1&2\\
3&4
\end{bmatrix}.
$$

stride 为 1，没有 padding 和偏置。左上输出读取左上 $2\times2$ 区域：

$$
1\times1+2\times2+4\times3+5\times4=37.
$$

卷积核向右移动一格：

$$
2\times1+3\times2+5\times3+6\times4=47.
$$

第二行两个输出分别为：

$$
4\times1+5\times2+7\times3+8\times4=67,
$$

$$
5\times1+6\times2+8\times3+9\times4=77.
$$

最终输出是：

$$
Y=
\begin{bmatrix}
37&47\\
67&77
\end{bmatrix}.
$$

> [!EXAMPLE] RGB 图像上的一个卷积核并非只有二维
> RGB 输入有 3 个 Channel。一个大小写成 $3\times3$ 的普通卷积核，完整权重实际包含 3 张 $3\times3$ 小表，分别处理红、绿、蓝 Channel。三个 Channel 的乘加结果再相加，才产生一个输出数。

Conv3D 可用于体数据或短视频。PyTorch 输入 $(N,C,D,H,W)$ 中，核可以写成 $(K_d,K_h,K_w)$；Keras 默认输入 $(N,D,H,W,C)$。若设置核大小 $(3,3,3)$，一个输出位置会查看相邻 3 个深度切片以及每个切片上的 $3\times3$ 区域。

> [!TIP] 视频不一定必须使用 Conv3D
> Conv3D 会同时处理时间和空间。若只想逐帧提取图像特征，可以让 Conv2D 分别处理每一帧；若希望局部时间变化也参与一次乘加，再考虑 Conv3D 或把时间轴单独交给序列 Layer。

### 6.4 输出尺寸公式与有效核大小

对任意一个空间轴，先定义有效核大小：

$$
K_{\mathrm{eff}}=d(K-1)+1.
$$

输出长度为：

$$
L_{\mathrm{out}}
=
\left\lfloor
\frac{L_{\mathrm{in}}+2p-K_{\mathrm{eff}}}{s}
\right\rfloor+1.
$$

也可以展开为：

$$
L_{\mathrm{out}}
=
\left\lfloor
\frac{L_{\mathrm{in}}+2p-d(K-1)-1}{s}+1
\right\rfloor.
$$

> [!NOTE] 二维和三维不是新公式
> 对二维输入分别计算 $H_{\mathrm{out}}$ 与 $W_{\mathrm{out}}$；对三维输入再计算 $D_{\mathrm{out}}$。每个轴可以有不同的 kernel size、stride、padding 和 dilation。

#### 手算：一维输出长度

设 $L_{\mathrm{in}}=10$、$K=3$、$s=2$、$p=1$、$d=2$。有效核大小为：

$$
K_{\mathrm{eff}}=2(3-1)+1=5.
$$

所以：

$$
L_{\mathrm{out}}
=
\left\lfloor\frac{10+2-5}{2}\right\rfloor+1
=3+1=4.
$$

四个输出位置读取的输入索引依次是：

$$
[-1,1,3],\quad[1,3,5],\quad[3,5,7],\quad[5,7,9].
$$

索引 $-1$ 位于原输入之外，因此第一个输出会读取一个补入值。

#### 手算：三维输出形状

输入形状为 PyTorch 的 $(2,4,9,20,30)$，也就是 Batch Size 为 2、输入 Channel 为 4、深度 9、高度 20、宽度 30。使用 6 个输出 Channel，并设置：

$$
K=(3,5,3),\quad
s=(1,2,2),\quad
p=(1,2,1),\quad
d=(1,1,2).
$$

深度方向：

$$
D_{\mathrm{out}}
=
\left\lfloor
\frac{9+2-1(3-1)-1}{1}+1
\right\rfloor=9.
$$

高度方向：

$$
H_{\mathrm{out}}
=
\left\lfloor
\frac{20+4-1(5-1)-1}{2}+1
\right\rfloor=10.
$$

宽度方向的有效核大小为 $2(3-1)+1=5$：

$$
W_{\mathrm{out}}
=
\left\lfloor
\frac{30+2-2(3-1)-1}{2}+1
\right\rfloor=14.
$$

PyTorch 输出为 $(2,6,9,10,14)$；Keras 若采用默认 channels-last，相同数学设置的输出为 $(2,9,10,14,6)$。

> [!WARNING] 输出 Channel 不用空间尺寸公式计算
> 输出 Channel 数直接由 PyTorch 的 `out_channels` 或 Keras 的 `filters` 指定。空间公式只计算长度、深度、高度和宽度。

### 6.5 stride、padding 与 dilation 分别改变什么

三个参数都影响局部读取方式，但作用不同：

- stride 决定完成一个输出后，卷积核整体移动几格；
- padding 决定输入四周补入多少位置；
- dilation 决定同一个核内部相邻权重之间隔多少格读取输入。

> [!IMPORTANT] stride 与 dilation 的间隔对象不同
> `stride=2` 表示相邻两个输出使用的窗口起点相隔两格；`dilation=2` 表示同一次输出计算中，相邻核权重读取的输入位置相隔两格。前者通常减少输出位置数，后者扩大一次计算查看的范围。

#### 手算 dilation

令：

$$
x=[1,2,3,4,5,6,7],\qquad w=[1,10,100].
$$

使用 dilation 2、stride 1、无 padding。第一个输出读取输入位置 0、2、4：

$$
1\times1+3\times10+5\times100=531.
$$

第二个输出读取位置 1、3、5：

$$
2\times1+4\times10+6\times100=642.
$$

第三个输出读取位置 2、4、6：

$$
3\times1+5\times10+7\times100=753.
$$

输出为 $[531,642,753]$。核仍然只有三个权重，只是三个权重分散在长度为 5 的输入范围中。

#### 四种 padding 内容

对一维输入 $[1,2,3]$ 左右各补一个位置：

| 方式 | 补齐结果 |
| --- | --- |
| 零填充 | $[0,1,2,3,0]$ |
| 复制端点 | $[1,1,2,3,3]$ |
| 反射 | $[2,1,2,3,2]$ |
| 循环 | $[3,1,2,3,1]$ |

PyTorch 卷积通过 `padding_mode` 支持 `zeros`、`reflect`、`replicate` 与 `circular`。Keras 卷积常用 `padding="valid"` 或 `padding="same"`；若要显式加入零值，可以使用 `ZeroPadding1D/2D/3D`。反射或循环填充在 Keras 中常由框架运算或自定义 Layer 完成，具体接口要结合所用后端。

> [!WARNING] 形状相同不代表计算相同
> 四种方式都把长度 3 变成长度 5，但卷积核在两端读取的数值不同。模型依赖图像四周细节时，padding 内容会影响输出。

Keras 的 `"valid"` 表示不补位置。Keras 的 `"same"` 会选择补入数量，使输出长度通常为 $\lceil L_{\mathrm{in}}/s\rceil$。PyTorch 也支持字符串 `"valid"` 和 `"same"`，但 `"same"` 常与 stride 1 配合；需要 stride 大于 1 时，显式计算整数 padding 更容易确认形状。

> [!TIP] “same”说的是输出尺寸规则
> 它不表示两种框架在所有参数组合下都选择完全相同的左右补入方式。奇数个补入位置无法左右均分时，还要确认多出的一个位置放在哪一侧。

### 6.6 卷积参数数目怎样计算

普通 Conv1D 权重数为：

$$
C_{\mathrm{out}}C_{\mathrm{in}}K.
$$

普通 Conv2D 权重数为：

$$
C_{\mathrm{out}}C_{\mathrm{in}}K_hK_w.
$$

普通 Conv3D 权重数为：

$$
C_{\mathrm{out}}C_{\mathrm{in}}K_dK_hK_w.
$$

若使用偏置，还要为每个输出 Channel 加一个偏置，因此增加 $C_{\mathrm{out}}$ 个参数。

> [!NOTE] 参数数目与输入高宽通常无关
> 同一个 Conv2D 可以处理 $32\times32$ 或 $256\times256$ 图像，只要输入 Channel 数符合要求，卷积核参数数目不变。图像变大主要增加乘加次数与中间特征存储，不会增加这层的卷积核数目。

#### 手算：普通 Conv2D

输入 Channel 为 8，输出 Channel 为 16，核大小为 $3\times3$，使用偏置：

$$
P=16\times8\times3\times3+16=1168.
$$

若不使用偏置，则参数数目是 1152。PyTorch 权重形状为 $(16,8,3,3)$。Keras 默认内部核形状通常为 $(3,3,8,16)$。轴次序不同，但元素总数与数学计算一致。

> [!TIP] 用形状相乘核对参数
> 看到模型摘要中的参数数目时，可以把权重张量各维相乘，再加偏置数。若结果不同，应继续检查 groups、depth multiplier 或 Layer 是否还包含归一化参数。

乘加次数还会随输出空间尺寸变化。忽略 bias，一张图的普通 Conv2D 大约需要：

$$
H_{\mathrm{out}}W_{\mathrm{out}}
C_{\mathrm{out}}C_{\mathrm{in}}K_hK_w
$$

次乘法。Batch Size 为 $N$ 时再乘 $N$。这说明参数数目不随高宽改变，但计算工作量会随输出位置数增加。

### 6.7 groups：把输入和输出 Channel 分组

当 `groups=G` 时，输入 Channel 与输出 Channel 各分为 $G$ 组，只在对应组内进行卷积。必须满足：

$$
C_{\mathrm{in}}\bmod G=0,\qquad
C_{\mathrm{out}}\bmod G=0.
$$

每个输出 Channel 只读取 $C_{\mathrm{in}}/G$ 个输入 Channel，所以 Conv2D 权重数变为：

$$
P_W
=
C_{\mathrm{out}}
\frac{C_{\mathrm{in}}}{G}
K_hK_w.
$$

PyTorch `Conv1d/2d/3d` 和 Keras `Conv1D/2D/3D` 都可以通过 `groups` 指定分组数。轴排列仍分别遵循各自的默认方式。

#### 手算：groups 改变哪些数会相加

设某个空间位置有四个输入 Channel：

$$
x=[1,2,10,20].
$$

使用 $1\times1$ 卷积，并令输入与输出 Channel 都为 4。

当 groups 为 1 时，每个输出 Channel 可以读取全部四个输入数。例如某个输出的权重是 $[1,1,1,1]$，则输出为：

$$
1+2+10+20=33.
$$

当 groups 为 2 时，第 0、1 个输入 Channel 属于第一组，第 2、3 个输入 Channel 属于第二组。第一组的输出不会读取 10 和 20，第二组的输出也不会读取 1 和 2。若两组分别使用权重 $[1,1]$，输出可以是：

$$
[1+2,\;1+2,\;10+20,\;10+20]
=[3,3,30,30].
$$

> [!NOTE] groups 增大为什么能减少参数
> 每个输出 Channel 读取的输入 Channel 从 $C_{\mathrm{in}}$ 个减少到 $C_{\mathrm{in}}/G$ 个。空间核大小不变，但 Channel 方向上的连接减少了。

以 `in_channels=8`、`out_channels=16`、$3\times3$ 核和 bias 为例：

| groups | 每个输出读取的输入 Channel | 参数数目 |
| ---: | ---: | ---: |
| 1 | 8 | $16\times8\times9+16=1168$ |
| 2 | 4 | $16\times4\times9+16=592$ |
| 4 | 2 | $16\times2\times9+16=304$ |
| 8 | 1 | $16\times1\times9+16=160$ |

> [!WARNING] 分组会减少不同组之间的直接交流
> 参数更少不等于功能完全相同。一个分组卷积内，不同组的输入不会共同参与同一个输出。后续常接 $1\times1$ 卷积或 ChannelShuffle，让不同组的信息重新组合。

### 6.8 Depthwise 卷积：每个输入 Channel 单独做空间卷积

Depthwise 卷积是分组卷积的特殊情况。其分组数等于输入 Channel 数：

$$
G=C_{\mathrm{in}}.
$$

PyTorch 没有单独的 `DepthwiseConv2d` 名称，通常使用 `Conv2d` 并令 `groups=in_channels`。Keras 提供 `DepthwiseConv1D` 和 `DepthwiseConv2D` 等专用 Layer。

Keras 使用 `depth_multiplier=M` 表示每个输入 Channel 产生 $M$ 个输出 Channel，因此：

$$
C_{\mathrm{out}}=C_{\mathrm{in}}M.
$$

PyTorch 可以把 `out_channels` 设为 $C_{\mathrm{in}}M$，同时保持 `groups=C_{\mathrm{in}}`，得到相同的 Channel 数变化。

Depthwise Conv2D 权重参数数目为：

$$
P_W=C_{\mathrm{in}}M K_hK_w.
$$

若有 bias，再加 $C_{\mathrm{in}}M$。

#### 手算：两个 Channel 各算各的

设某个 $2\times2$ 局部区域有两个输入 Channel：

$$
X_0=
\begin{bmatrix}
1&2\\
3&4
\end{bmatrix},
\qquad
X_1=
\begin{bmatrix}
10&20\\
30&40
\end{bmatrix}.
$$

第 0 个 Channel 的核全为 1，第 1 个 Channel 的核为：

$$
\begin{bmatrix}
1&0\\
0&1
\end{bmatrix}.
$$

当 depth multiplier 为 1 时，第 0 个输出为：

$$
1+2+3+4=10,
$$

第 1 个输出为：

$$
10\times1+20\times0+30\times0+40\times1=50.
$$

两个输入 Channel 没有在 Depthwise 计算中相加。

> [!WARNING] Depthwise 卷积本身不组合 Channel
> 它擅长在每个 Channel 内提取空间特征，但不能让第 0 个 Channel 与第 1 个 Channel 共同产生一个新特征。若任务需要组合 Channel，通常还要接 Pointwise 卷积。

### 6.9 Separable 卷积：Depthwise 加 Pointwise

深度可分卷积通常包含两步：

1. Depthwise 卷积：每个输入 Channel 分别做空间卷积；
2. Pointwise 卷积：使用 $1\times1$ 普通卷积组合 Channel。

Keras 提供 `SeparableConv1D` 与 `SeparableConv2D`。PyTorch 通常把一个分组卷积和一个 $1\times1$ 普通卷积顺序组合。

若 depth multiplier 为 1，输入 Channel 为 $C_{\mathrm{in}}$，最终输出 Channel 为 $C_{\mathrm{out}}$，忽略 bias，参数数目为：

$$
P_{\mathrm{sep}}
=
C_{\mathrm{in}}K_hK_w
+C_{\mathrm{in}}C_{\mathrm{out}}.
$$

普通卷积参数数目为：

$$
P_{\mathrm{normal}}
=
C_{\mathrm{in}}C_{\mathrm{out}}K_hK_w.
$$

#### 数字比较

令 $C_{\mathrm{in}}=32$、$C_{\mathrm{out}}=64$、核大小为 $3\times3$。

普通卷积：

$$
32\times64\times9=18432.
$$

Depthwise 部分：

$$
32\times9=288.
$$

Pointwise 部分：

$$
32\times64=2048.
$$

两部分合计：

$$
288+2048=2336.
$$

> [!NOTE] 参数减少来自计算拆分
> 普通卷积在一次乘加中同时处理空间和 Channel。Separable 卷积先独立处理空间，再用 $1\times1$ 卷积处理 Channel。它减少了参数和乘加，但两种结构的表达方式并不完全相同。

> [!TIP] 比较模型时同时看中间 Channel
> depth multiplier 大于 1 时，Depthwise 输出 Channel 会增加，Pointwise 部分的输入 Channel 也随之增加。不能只套用 multiplier 为 1 的简式。

### 6.10 $1\times1$ 卷积：逐位置的 Channel 全连接

$1\times1$ 卷积只查看当前空间位置，不读取上下左右邻居。它仍然可以读取该位置的全部输入 Channel，因此相当于在每个空间位置重复使用同一个全连接变换。

对某个位置的输入向量：

$$
x_{n,h,w}\in\mathbb R^{C_{\mathrm{in}}},
$$

$1\times1$ 卷积计算：

$$
y_{n,h,w}=Wx_{n,h,w}+b,
\qquad
W\in\mathbb R^{C_{\mathrm{out}}\times C_{\mathrm{in}}}.
$$

#### 手算：三个 Channel 变成两个 Channel

某个像素位置的输入为：

$$
x=[2,3,5].
$$

两个输出 Channel 的权重与偏置分别为：

$$
w_0=[1,0,-1],\quad b_0=1,
$$

$$
w_1=[0,2,1],\quad b_1=-1.
$$

输出为：

$$
y_0=2\times1+3\times0+5\times(-1)+1=-2,
$$

$$
y_1=2\times0+3\times2+5\times1-1=10.
$$

输入和输出的高宽不变，Channel 从 3 变成 2。

> [!EXAMPLE] 瓶颈结构为什么使用 $1\times1$
> 假设输入有 256 个 Channel。先用 $1\times1$ 卷积降到 64 个 Channel，再做 $3\times3$ 卷积，可以显著减少后者的参数和乘加。最后还可以用另一个 $1\times1$ 卷积把 Channel 数升回去。

> [!WARNING] $1\times1$ 卷积也可能很耗计算
> 它的空间核虽小，但在高分辨率特征图上会对每个位置执行一次 Channel 组合。当输入和输出 Channel 都很大时，乘加总数仍然可观。

### 6.11 感受区域怎样随层数增大

单个 $3\times3$ 卷积的一个输出位置最多读取输入的 $3\times3$ 区域。多层卷积堆叠后，后层的一个位置会受到更大输入区域的影响。

定义：

- $R_\ell$：第 $\ell$ 层一个位置涉及原输入的理论范围；
- $J_\ell$：第 $\ell$ 层相邻位置在原输入上相隔多少格；
- $K_{\mathrm{eff},\ell}$：第 $\ell$ 层有效核大小；
- $s_\ell$：第 $\ell$ 层 stride。

从 $R_0=1,J_0=1$ 开始：

$$
J_\ell=J_{\ell-1}s_\ell,
$$

$$
R_\ell
=
R_{\ell-1}
+(K_{\mathrm{eff},\ell}-1)J_{\ell-1}.
$$

#### 手算：三层 stride 1 卷积

连续三个 $3\times3$ 卷积，stride 与 dilation 均为 1：

| 层 | $R$ | $J$ |
| --- | ---: | ---: |
| 输入 | 1 | 1 |
| 第一个卷积 | 3 | 1 |
| 第二个卷积 | 5 | 1 |
| 第三个卷积 | 7 | 1 |

第三层的一个输出最多受到原图 $7\times7$ 区域影响。

#### 手算：卷积、池化、卷积

先用 $3\times3$、stride 1 卷积，再用 $2\times2$、stride 2 池化，最后再用 $3\times3$、stride 1 卷积：

1. 第一个卷积后，$R=3,J=1$；
2. 池化后，$R=3+(2-1)\times1=4$，$J=2$；
3. 第二个卷积后，$R=4+(3-1)\times2=8$，$J=2$。

最后一个位置涉及原输入的 $8\times8$ 区域。

> [!NOTE] 理论范围不代表每个输入都同等重要
> 权重大小、非线性、输入内容以及训练结果都会影响各位置的真实作用强弱。公式主要用来说明信息可能来自多大的区域。

### 6.12 卷积常见错误与检查顺序

> [!WARNING] 错误一：把 Channel维度放错位置
> PyTorch 常见图像输入是 $(N,C,H,W)$，Keras 默认是 $(N,H,W,C)$。看到“期望 3 个 Channel，却得到 224”之类的信息时，应先检查轴次序。

> [!WARNING] 错误二：groups 不能整除 Channel
> groups 必须同时整除输入与输出 Channel。若输入 Channel 为 6、输出 Channel 为 10，groups 可以是 1 或 2，但不能是 3，因为 3 不能整除 10。

> [!WARNING] 错误三：把 dilation 当成增加权重
> dilation 只改变核元素读取输入的位置，不会增加核元素数。`kernel_size=3,dilation=4` 仍只有三个一维权重，有效核大小则变成 9。

> [!WARNING] 错误四：只看参数数目，不看输出尺寸
> 两个卷积参数数目相同，但若一个输出 $128\times128$、另一个输出 $16\times16$，计算工作量与中间张量大小会明显不同。

建议依次检查：输入轴次序、输入 Channel、kernel size、stride、padding、dilation、groups、输出 Channel，最后把每个空间轴代入公式。

### 6.13 因果 Conv1D：只读取当前位置和过去位置

普通 Conv1D 若在左右两侧对称填充，一个输出可能同时读取当前位置之前和之后的输入。对离线文本分类，这通常没有问题；对按时间逐步预测的任务，读取未来位置会让训练条件与实际逐步使用条件不一致。

因果卷积要求第 $t$ 个输出只依赖：

$$
x_t,x_{t-1},x_{t-2},\ldots,
$$

不读取 $x_{t+1},x_{t+2}$ 等未来位置。对 kernel size 为 $K$、dilation 为 $d$ 的 stride 1 卷积，可以在左侧填入：

$$
p_{\mathrm{left}}=d(K-1)
$$

个位置，右侧填入 0 个位置。这样输出长度与输入相同，并且最后一个核权重可以对准当前位置。

#### 手算：长度 4 的因果卷积

输入为：

$$
x=[1,2,3,4],
$$

核为：

$$
w=[10,1],
$$

kernel size 为 2，dilation 为 1。左侧补一个 0：

$$
x_{\mathrm{pad}}=[0,1,2,3,4].
$$

四个窗口依次是：

$$
[0,1],\quad[1,2],\quad[2,3],\quad[3,4].
$$

输出为：

$$
[0\times10+1,\;
1\times10+2,\;
2\times10+3,\;
3\times10+4]
=[1,12,23,34].
$$

第 2 个输出 23 只使用输入 2 和 3，不使用后面的 4。

Keras `Conv1D` 提供 `padding="causal"`，用于常见的一维因果卷积。PyTorch `Conv1d` 通常先在左侧显式填充，再使用 `padding=0` 的卷积，也可以把这两步封装成一个模块。

> [!WARNING] 因果只约束时间方向
> 输入轴必须确实表示时间或序列位置。如果误把 Feature维度当成长度轴，即使使用 causal 设置，限制的也会是错误维度。

> [!NOTE] dilation 可以快速扩大历史范围
> kernel size 为 3 时，dilation 依次取 1、2、4，三个 Layer 分别可以读取间隔为 1、2、4 的历史位置。堆叠后，一个输出能利用较长历史，而每层仍只有三个时间方向权重。

### 6.14 非方形核与非对称步幅

Conv2D 的 kernel size、stride、padding 和 dilation 都可以分别为高、宽提供不同数值。例如：

$$
K=(3,5),\qquad s=(2,1),\qquad p=(1,2).
$$

这个 Layer 的核高为 3、宽为 5；高度方向每次移动 2 格，宽度方向每次移动 1 格。若 dilation 为 1，padding 恰好使宽度保持不变，而高度大约减半。

输入高宽为 $H=7,W=10$ 时：

$$
H_{\mathrm{out}}
=
\left\lfloor
\frac{7+2-3}{2}
\right\rfloor+1
=4,
$$

$$
W_{\mathrm{out}}
=
\left\lfloor
\frac{10+4-5}{1}
\right\rfloor+1
=10.
$$

输出空间尺寸为 $4\times10$。

> [!EXAMPLE] 为什么核不一定是正方形
> 语谱图的一个轴表示时间，另一个轴表示频率。任务可能希望一次查看较长时间范围，却只查看较窄频率范围，此时 $3\times7$ 或 $1\times5$ 等核有明确含义。

> [!TIP] 元组顺序跟随空间轴顺序
> PyTorch `Conv2d` 与 Keras `Conv2D` 的 kernel size 元组都通常按高、宽书写；三维则按深度、高度、宽度。输入 Channel 放在前还是最后，不会改变空间参数元组内部的先后次序。

核大小为 $1\times K$ 时只沿宽度组合局部位置，$K\times1$ 时只沿高度组合。连续使用这两个卷积，可以把一个 $K\times K$ 空间计算拆成两个方向：

$$
K\times1\quad\text{后接}\quad1\times K.
$$

若输入输出 Channel 都为 $C$，忽略 bias，一个 $K\times K$ 普通卷积需要 $C^2K^2$ 个权重；两个方向卷积合计约需 $2C^2K$ 个权重。中间 Channel 数若不同，应按每一层的真实输入输出 Channel 分别计算。

### 6.15 bias 如何在空间位置共享

卷积 bias 的形状只与输出 Channel 有关。Conv2D 的第 $o$ 个偏置 $b_o$ 会加到该输出 Channel 的每个高宽位置：

$$
y_{n,o,h,w}=z_{n,o,h,w}+b_o,
$$

其中 $z$ 表示卷积乘加结果。它不会为每个像素准备不同偏置。

假设某个输出 Channel 在四个位置的卷积乘加结果为：

$$
\begin{bmatrix}
2&5\\
-1&3
\end{bmatrix},
$$

该 Channel 的 bias 为 0.5，则输出为：

$$
\begin{bmatrix}
2.5&5.5\\
-0.5&3.5
\end{bmatrix}.
$$

> [!NOTE] bias 共享是卷积位置共享的一部分
> 一个输出 Channel 只有一个 bias。输入图像从 $32\times32$ 改成 $256\times256$，bias 参数仍然只有 $C_{\mathrm{out}}$ 个。

当卷积后立即接带平移参数的 Batch Normalization 时，卷积 bias 有时会关闭，因为归一化后的 $\beta$ 已能提供每 Channel 平移。不过这是一种结构选择，不是所有“卷积后接归一化”都必须关闭 bias。若归一化的轴、参数设置或 Layer 次序不同，应重新分析。

> [!WARNING] 不要仅凭经验删除 bias
> 先确认后续 Layer 是否真的带可学习平移参数，以及卷积输出是否完整经过该 Layer。存在分支、部分 Channel 处理或特殊归一化时，结论可能不同。

### 6.16 完整形状与参数手算：一个小型卷积主干

考虑 Batch Size 为 8 的 RGB 图像，尺寸为 $64\times64$。PyTorch 输入形状：

$$
(8,3,64,64).
$$

Keras 默认输入形状：

$$
(8,64,64,3).
$$

第一层是普通 $3\times3$ 卷积，输出 Channel 为 32，stride 1，padding 1，使用 bias。空间尺寸保持 $64\times64$，参数数目：

$$
32\times3\times3\times3+32
=896.
$$

PyTorch 输出：

$$
(8,32,64,64),
$$

Keras 默认输出：

$$
(8,64,64,32).
$$

第二层是 Depthwise $3\times3$ 卷积，depth multiplier 为 1，stride 2，padding 1，不使用 bias。输出 Channel 仍为 32，高宽变成 $32\times32$，参数数目：

$$
32\times3\times3=288.
$$

第三层是 $1\times1$ Pointwise 卷积，把 Channel 从 32 改成 64，使用 bias。参数数目：

$$
64\times32+64=2112.
$$

最终 PyTorch 形状是：

$$
(8,64,32,32),
$$

Keras 默认形状是：

$$
(8,32,32,64).
$$

三层参数合计：

$$
896+288+2112=3296.
$$

> [!TIP] 建议为复杂网络维护形状表
> 每行写 Layer 名称、输入形状、输出形状、参数数目和尺寸公式。遇到分支相加或拼接时，这张表能帮助确认 Batch维度与空间轴是否一致。

> [!QUESTION] 若第二层改成普通卷积会怎样？
> 普通 `32→32` 的 $3\times3$ 卷积、不使用 bias，需要 $32\times32\times9=9216$ 个权重；Depthwise 只需 288 个。两者参数差距很大，但普通卷积能在同一步同时组合全部输入 Channel。

### 6.17 Lazy Conv 与首次输入确定 Channel

PyTorch 提供 `LazyConv1d/2d/3d` 和相应 Lazy 转置卷积。它们允许构造时暂不填写输入 Channel，首次收到输入后再根据 Channel维度创建权重。输出 Channel、kernel size、stride 等仍要提前指定。

Keras Layer 通常在 `build` 阶段根据首次输入的最后一个 Channel维度创建卷积核，因此常规 Keras `Conv1D/2D/3D` 就具有相似的延后建权重行为，用户主要指定 filters 与 kernel size。

> [!NOTE] 延后创建权重不会改变数学公式
> 输入 Channel 一旦确定，权重形状、参数数目和普通卷积完全相同。Lazy 只省去构造时手工写入输入 Channel。

> [!WARNING] 首次输入会固定输入 Channel
> 若一个 Lazy Conv2D 首次收到 5 个 Channel，它会创建适合 5 个输入 Channel 的核。之后再给 7 个 Channel，不能自动重新创建另一套权重。

---

## 7. 池化、填充、裁剪与局部窗口展开

池化用于汇总局部区域，填充用于在空间轴两端或图像四周加入位置，裁剪用于移除外侧位置，Unfold 则把滑动窗口逐个取出。它们大多没有可学习参数，但会显著改变后续 Layer 接收到的形状和数值。

### 7.1 池化 Layer 的名称、轴顺序与共同特点

| 功能 | PyTorch | Keras |
| --- | --- | --- |
| 一维最大池化 | `MaxPool1d` | `MaxPooling1D` |
| 二维最大池化 | `MaxPool2d` | `MaxPooling2D` |
| 三维最大池化 | `MaxPool3d` | `MaxPooling3D` |
| 一维平均池化 | `AvgPool1d` | `AveragePooling1D` |
| 二维平均池化 | `AvgPool2d` | `AveragePooling2D` |
| 三维平均池化 | `AvgPool3d` | `AveragePooling3D` |
| 全局平均池化 | `AdaptiveAvgPool1d/2d/3d(1)` | `GlobalAveragePooling1D/2D/3D` |
| 全局最大池化 | `AdaptiveMaxPool1d/2d/3d(1)` | `GlobalMaxPooling1D/2D/3D` |

PyTorch 池化沿 channels-first 输入的空间轴移动，Keras 默认沿 channels-last 输入的空间轴移动。池化通常逐 Channel 独立进行，不把不同 Channel 相加，也不改变 Channel 数。

> [!NOTE] 池化没有卷积核权重
> Max Pooling 只选择窗口最大值，Average Pooling 只计算窗口平均值。窗口大小和 stride 是固定设置，不是训练得到的参数。

输入 $(N,C,H,W)$ 经过 PyTorch `MaxPool2d(2)` 后，若高宽都能整除 2，输出为 $(N,C,H/2,W/2)$。相同数据在 Keras 默认次序下是 $(N,H,W,C)$ 变成 $(N,H/2,W/2,C)$。

### 7.2 Max Pooling：窗口中只保留最大值

设 $\mathcal W_{h,w}$ 表示输出位置 $(h,w)$ 对应的输入窗口，则：

$$
y_{n,c,h,w}
=
\max_{(r,q)\in\mathcal W_{h,w}}
x_{n,c,r,q}.
$$

$n$ 和 $c$ 固定不变，只在窗口包含的空间位置上取最大值。

#### 手算：$4\times4$ 输入缩成 $2\times2$

输入为：

$$
X=
\begin{bmatrix}
1&2&3&4\\
5&6&7&8\\
2&1&0&3\\
4&2&1&0
\end{bmatrix}.
$$

使用 $2\times2$ 窗口、stride 2。四个互不重叠的窗口为：

| 位置 | 窗口 | 最大值 |
| --- | --- | ---: |
| 左上 | $\begin{bmatrix}1&2\\5&6\end{bmatrix}$ | 6 |
| 右上 | $\begin{bmatrix}3&4\\7&8\end{bmatrix}$ | 8 |
| 左下 | $\begin{bmatrix}2&1\\4&2\end{bmatrix}$ | 4 |
| 右下 | $\begin{bmatrix}0&3\\1&0\end{bmatrix}$ | 3 |

输出为：

$$
Y=
\begin{bmatrix}
6&8\\
4&3
\end{bmatrix}.
$$

> [!TIP] Max Pooling 保留“强响应”，不保留其余细节
> 左上窗口只留下 6，原来的 1、2、5 不再出现在输出中。后续放大空间尺寸也不能仅凭 6 推知这三个数。

PyTorch `MaxPool1d/2d/3d` 可以通过 `return_indices=True` 同时返回最大值位置，供 `MaxUnpool1d/2d/3d` 使用。Keras 常用的 `MaxPooling` Layer 默认只返回最大值；需要位置时通常要调用后端提供的带索引最大池化运算。

> [!WARNING] MaxUnpool 也不能恢复全部输入
> 它只能把池化输出放回最大值原位置，其余位置填 0。池化窗口中未被选中的数已经丢失。

### 7.3 Max Pooling 的 padding、dilation 与 ceil mode

Max Pooling 的单轴输出尺寸可用与卷积相似的公式：

$$
L_{\mathrm{out}}
=
\left\lfloor
\frac{L_{\mathrm{in}}+2p-d(K-1)-1}{s}+1
\right\rfloor.
$$

PyTorch Max Pooling 支持 dilation。Keras 常用 MaxPooling Layer 主要设置 pool size、strides 和 padding，不把 dilation 作为常用构造参数。

对 Max Pooling 而言，补入位置可理解为负无穷，因此补入值不会在全负窗口中错误地成为最大值。例如有效输入是 $[-5,-2]$，结果仍是 $-2$，而不是 0。

#### 手算 ceil mode

输入长度为 5，窗口大小为 2，stride 为 2，不使用 padding。

默认向下取整时，窗口为：

$$
[x_0,x_1],\qquad[x_2,x_3].
$$

位置 $x_4$ 没有进入输出，输出长度为 2。PyTorch 设置 `ceil_mode=True` 后，还允许最后一个窗口从 $x_4$ 开始，输出长度变成 3。

> [!WARNING] 最后一个窗口可能只含较少有效位置
> ceil mode 可以减少末尾输入被忽略的情况，但最后一个输出与前面输出可能不是由相同数量的有效元素得到。解释数值时要考虑这一点。

Keras 的 `padding="same"` 也可以保留末尾区域，但它与 PyTorch `ceil_mode` 不是同一个参数。前者通过补入位置决定输出尺寸，后者改变窗口数量的向上取整规则。

### 7.4 Average Pooling：窗口中取平均值

Average Pooling 的一般形式为：

$$
y_{n,c,h,w}
=
\frac{1}{M}
\sum_{(r,q)\in\mathcal W_{h,w}}
x_{n,c,r,q},
$$

其中 $M$ 是参与除法的元素数。没有 padding 时，完整 $K_h\times K_w$ 窗口的 $M=K_hK_w$。

继续使用前面的 $4\times4$ 输入，四个窗口平均值为：

$$
\frac{1+2+5+6}{4}=3.5,
$$

$$
\frac{3+4+7+8}{4}=5.5,
$$

$$
\frac{2+1+4+2}{4}=2.25,
$$

$$
\frac{0+3+1+0}{4}=1.
$$

输出为：

$$
\begin{bmatrix}
3.5&5.5\\
2.25&1
\end{bmatrix}.
$$

> [!NOTE] 最大值与平均值保存的信息不同
> Max Pooling 更强调窗口中最强的局部响应；Average Pooling 更接近窗口整体水平。两者都会舍弃位置细节，但舍弃方式不同。

#### padding 是否计入除数

PyTorch Average Pooling 的 `count_include_pad` 决定补入位置是否计入除数。输入为 $[1,2,3]$，窗口大小 3，stride 1，左右各补一个 0。第一个窗口是 $[0,1,2]$。

若补入位置计入除数：

$$
(0+1+2)/3=1.
$$

若不计入：

$$
(1+2)/2=1.5.
$$

三个输出分别为：

| 设置 | 输出 |
| --- | --- |
| 计入补入位置 | $[1,\;2,\;5/3]$ |
| 不计入补入位置 | $[1.5,\;2,\;2.5]$ |

> [!WARNING] 框架默认设置要单独确认
> 两个 Layer 即使窗口、stride 和 padding 相同，只要平均值除数规则不同，图像四周输出就会不同。复现另一框架模型时，应检查是否把补入位置计入平均值。

### 7.5 Global Pooling：每个 Channel 变成一个数

二维全局平均池化对每个样本、每个 Channel 的全部空间位置求平均：

$$
y_{n,c}
=
\frac{1}{HW}
\sum_{h=0}^{H-1}
\sum_{w=0}^{W-1}
x_{n,c,h,w}.
$$

若保留空间轴，PyTorch 形状从 $(N,C,H,W)$ 变成 $(N,C,1,1)$；Keras 默认从 $(N,H,W,C)$ 变成 $(N,1,1,C)$。Keras `GlobalAveragePooling2D` 默认通常去掉空间轴，得到 $(N,C)$，可通过 `keepdims` 保留长度为 1 的空间轴。PyTorch `AdaptiveAvgPool2d(1)` 保留两个空间轴，若需要 $(N,C)$，还要再做 Flatten 或挤压。

#### 手算：两个 Channel 的全局平均

设一个样本有两个 $2\times2$ Channel：

$$
X_0=
\begin{bmatrix}
1&3\\
5&7
\end{bmatrix},
\qquad
X_1=
\begin{bmatrix}
2&4\\
6&8
\end{bmatrix}.
$$

输出为：

$$
y_0=(1+3+5+7)/4=4,
$$

$$
y_1=(2+4+6+8)/4=5.
$$

所以每个样本得到 Feature 向量 $[4,5]$。

> [!TIP] 全局池化适合连接分类头
> 它把任意高宽压缩为每个 Channel 一个数，使后面的 Dense 或 Linear 只依赖 Channel 数，不必提前固定特征图高宽。

全局最大池化则把平均改成最大值。上例得到 $[7,8]$。它保留每个 Channel 最强的空间响应，但不会告诉后续 Layer 这个最大值原来位于哪里。

### 7.6 Adaptive Pooling：直接指定输出空间大小

PyTorch 提供 `AdaptiveAvgPool1d/2d/3d` 与 `AdaptiveMaxPool1d/2d/3d`。它们不要求输入尺寸能整除输出尺寸，而是根据目标输出大小自动选择每个输出所对应的输入区间。

将长度 $L_{\mathrm{in}}$ 变成 $L_{\mathrm{out}}$ 时，第 $i$ 个区间可用下面的起止位置理解：

$$
\operatorname{start}(i)
=
\left\lfloor
\frac{iL_{\mathrm{in}}}{L_{\mathrm{out}}}
\right\rfloor,
$$

$$
\operatorname{end}(i)
=
\left\lceil
\frac{(i+1)L_{\mathrm{in}}}{L_{\mathrm{out}}}
\right\rceil.
$$

#### 手算：长度 7 变成长度 3

输入为：

$$
[1,2,3,4,5,6,7].
$$

三个区间分别是：

$$
[1,2,3],\qquad[3,4,5],\qquad[5,6,7].
$$

Adaptive Average Pooling 输出：

$$
\left[
\frac{1+2+3}{3},
\frac{3+4+5}{3},
\frac{5+6+7}{3}
\right]
=[2,4,6].
$$

Adaptive Max Pooling 输出：

$$
[3,5,7].
$$

相邻区间可以共享输入位置，例如 3 同时出现在前两个区间，5 同时出现在后两个区间。

> [!NOTE] Adaptive 不表示窗口由训练得到
> 这些 Layer 没有可学习权重。“自适应”只表示区间由输入尺寸与目标输出尺寸计算出来。

Keras 3 提供 `AdaptiveAveragePooling1D/2D/3D` 与 `AdaptiveMaxPooling1D/2D/3D`，可以直接指定目标空间大小。目标大小为 1 时，也可以使用更常见的 `GlobalAveragePooling1D/2D/3D` 与 `GlobalMaxPooling1D/2D/3D`。两类 Layer 都遵循 Keras 的 `data_format`：默认 channels-last 时只调整 Channel维度之前的空间轴，不改变 Batch维度和 Channel 数。

### 7.7 填充 Layer：在空间轴外侧加入位置

PyTorch 常见填充 Layer：

- `ConstantPad1d/2d/3d`：填入指定常数；
- `ZeroPad2d`：填入 0；
- `ReflectionPad1d/2d/3d`：以内侧值反射；
- `ReplicationPad1d/2d/3d`：重复最外侧值。

Keras 常见零填充 Layer：

- `ZeroPadding1D`；
- `ZeroPadding2D`；
- `ZeroPadding3D`。

填充不改变 Batch Size 和 Channel 数，只改变空间尺寸。

对二维输入，若左、右、上、下填充分别为 $p_l,p_r,p_t,p_b$：

$$
H_{\mathrm{out}}=H+p_t+p_b,
$$

$$
W_{\mathrm{out}}=W+p_l+p_r.
$$

#### 手算：二维非对称填充

输入为：

$$
\begin{bmatrix}
1&2\\
3&4
\end{bmatrix}.
$$

左侧补 1 列，右侧补 2 列，上方补 1 行，下方不补，并使用 0，结果为：

$$
\begin{bmatrix}
0&0&0&0&0\\
0&1&2&0&0\\
0&3&4&0&0
\end{bmatrix}.
$$

原高宽 $2\times2$ 变成 $3\times5$。

> [!WARNING] 两个框架的填充元组写法不同
> PyTorch 二维填充参数常按最后空间轴优先，顺序为左、右、上、下。Keras `ZeroPadding2D` 常写成“高度前后、宽度前后”的两对数。不要看到同样四个整数就直接照搬。

Reflection Padding 要求每侧填充数小于相应输入尺寸，因为它需要从输入内部取得可反射的数。Replication Padding 只重复端点，对很小输入也较容易使用，但连续重复可能在外侧形成大片相同数值。

> [!TIP] 把填充与卷积分开有助于观察
> 当左右或上下需要不同数量时，先用独立填充 Layer，再使用 `padding=0` 的卷积，形状关系通常更清楚。

### 7.8 Cropping：从空间轴两端移除位置

Keras 提供 `Cropping1D`、`Cropping2D` 与 `Cropping3D`。PyTorch 没有同名的常用 Cropping Layer，通常通过张量切片、`narrow` 或自定义无参数模块完成。

二维裁剪若从上、下、左、右分别移除 $c_t,c_b,c_l,c_r$：

$$
H_{\mathrm{out}}=H-c_t-c_b,
$$

$$
W_{\mathrm{out}}=W-c_l-c_r.
$$

#### 手算：从 $4\times5$ 中取中间区域

输入为：

$$
\begin{bmatrix}
1&2&3&4&5\\
6&7&8&9&10\\
11&12&13&14&15\\
16&17&18&19&20
\end{bmatrix}.
$$

上方去掉 1 行，下方去掉 1 行，左侧去掉 1 列，右侧去掉 2 列，剩下：

$$
\begin{bmatrix}
7&8\\
12&13
\end{bmatrix}.
$$

高从 4 变成 2，宽从 5 变成 2。

> [!WARNING] Cropping 删除的数据无法由这一层恢复
> 它不是把外侧数值暂时隐藏，而是让输出不再包含这些位置。若后续还需要完整尺寸，应在裁剪前保存相应特征，或明确准备补齐方式。

Cropping 常用于让两个分支的高宽一致。例如一个分支经过 valid 卷积后变小，另一个分支保持原尺寸，拼接前可以裁剪较大的分支。但应先核对为何尺寸不同，避免用裁剪掩盖错误的 stride 或 padding。

### 7.9 Unfold：把每个滑动窗口排成一列

PyTorch `Unfold` 处理常见四维图像输入 $(N,C,H,W)$，从每个滑动位置取出一个局部块，并把块内元素排成列。若核大小为 $(K_h,K_w)$，输出形状为：

$$
(N,\;CK_hK_w,\;L),
$$

其中 $L=H_{\mathrm{out}}W_{\mathrm{out}}$ 是窗口总数。

Keras 中常通过 `keras.ops.image.extract_patches` 或相应后端图像运算取得局部块。channels-last 输入常得到类似：

$$
(N,\;H_{\mathrm{out}},\;W_{\mathrm{out}},\;CK_hK_w)
$$

的组织方式。两者包含的局部数值相近，但轴排列不同。

> [!NOTE] Unfold 没有学习参数
> 它只复制并重新排列输入元素。相邻窗口共享的输入会在展开结果中重复出现，因此输出元素数可能远大于输入。

#### 手算：$3\times3$ 输入展开为四个窗口

输入为：

$$
X=
\begin{bmatrix}
1&2&3\\
4&5&6\\
7&8&9
\end{bmatrix}.
$$

使用 $2\times2$ 窗口、stride 1、无 padding。窗口按从左到右、从上到下的顺序为：

$$
\begin{bmatrix}1&2\\4&5\end{bmatrix},
\quad
\begin{bmatrix}2&3\\5&6\end{bmatrix},
\quad
\begin{bmatrix}4&5\\7&8\end{bmatrix},
\quad
\begin{bmatrix}5&6\\8&9\end{bmatrix}.
$$

每个窗口按行展开为长度 4 的列：

$$
\begin{bmatrix}1\\2\\4\\5\end{bmatrix},
\quad
\begin{bmatrix}2\\3\\5\\6\end{bmatrix},
\quad
\begin{bmatrix}4\\5\\7\\8\end{bmatrix},
\quad
\begin{bmatrix}5\\6\\8\\9\end{bmatrix}.
$$

PyTorch `Unfold` 去掉 Batch维度后可写成：

$$
\begin{bmatrix}
1&2&4&5\\
2&3&5&6\\
4&5&7&8\\
5&6&8&9
\end{bmatrix}.
$$

每一列代表一个窗口，不是每一行代表一个窗口。

> [!TIP] 用输出形状判断窗口放在哪个轴
> PyTorch 输出 $(N,CK_hK_w,L)$ 中，最后一轴枚举窗口；Keras 常见提取结果把窗口保留在高宽两轴，最后的 Feature维度保存展开后的窗口内容。

### 7.10 Unfold 怎样把卷积变成矩阵乘

继续使用上面的四个窗口。令卷积核为：

$$
W=
\begin{bmatrix}
1&0\\
0&-1
\end{bmatrix},
\qquad
w_{\mathrm{flat}}=[1,0,0,-1].
$$

将这个行向量与 Unfold 结果相乘：

$$
[1,0,0,-1]
\begin{bmatrix}
1&2&4&5\\
2&3&5&6\\
4&5&7&8\\
5&6&8&9
\end{bmatrix}
=[-4,-4,-4,-4].
$$

再把四个结果排成 $2\times2$：

$$
\begin{bmatrix}
-4&-4\\
-4&-4
\end{bmatrix},
$$

这就是对应卷积输出。

多个输入 Channel 时，每个窗口长度是 $CK_hK_w$。多个输出 Channel 时，可以把每个卷积核展成一行，得到形状：

$$
(C_{\mathrm{out}},CK_hK_w)
$$

的权重矩阵，再与每个样本的展开结果相乘。

> [!NOTE] Unfold 展示了卷积中的两件事
> 第一件事是按滑动规则取得局部窗口；第二件事是用卷积核对每个窗口做相同乘加。卷积 Layer 把这两件事组合成一个高效计算。

> [!WARNING] 不要为了理解而在大型输入上长期保留展开结果
> $3\times3$、stride 1 时，图像内部的大多数元素会在九个窗口中重复出现。输入高宽和 Channel 较大时，展开张量会占用很多内存。

### 7.11 Fold：把列放回空间位置并累加

PyTorch `Fold` 接收形状 $(N,CK_hK_w,L)$ 的列，把每列看成一个窗口，并根据 kernel size、stride、padding、dilation 放回指定输出尺寸。窗口重叠的位置采用加法。

对上一节的 Unfold 结果执行 Fold，得到：

$$
\begin{bmatrix}
1&4&3\\
8&20&12\\
7&16&9
\end{bmatrix}.
$$

这不是原输入，因为中心数 5 出现在四个窗口中，Fold 后变成 $5+5+5+5=20$；上方中间数 2 出现在两个窗口中，Fold 后变成 4。

各位置被窗口覆盖的次数为：

$$
\operatorname{divisor}
=
\begin{bmatrix}
1&2&1\\
2&4&2\\
1&2&1
\end{bmatrix}.
$$

因此：

$$
\operatorname{Fold}(\operatorname{Unfold}(X))
=
\operatorname{divisor}\odot X.
$$

在每个位置覆盖次数大于 0 时，逐元素除以 divisor 才能恢复原输入。

> [!QUESTION] Fold 什么时候直接等于原输入？
> 当窗口互不重叠、完整覆盖输入，并且每个有效位置恰好出现一次时，覆盖次数全为 1。例如 $4\times4$ 输入配合 $2\times2$ 窗口和 stride 2。

> [!WARNING] 有位置未被窗口读取时不能恢复
> 若 stride 太大，窗口之间可能留下空隙，这些位置的覆盖次数为 0。除以覆盖次数会出现无效结果，而且展开列中本来就没有这些位置的信息。

Keras 常见接口中没有与 PyTorch `Fold` 完全同名且组织方式完全相同的基础 Layer。需要重建空间张量时，通常使用后端的散点累加、图像块组合运算或自定义 Layer，并明确重叠位置采用求和还是求平均。

### 7.12 本章常见误解

> [!WARNING] 池化缩小尺寸，不等于简单删除偶数位置
> Max Pooling 与 Average Pooling 会读取整个窗口。只有非常特殊的输入和参数组合，结果才碰巧等于固定间隔取样。

> [!WARNING] Global Pooling 不会改变 Channel 数
> 它删除或保留长度为 1 的空间轴，但每个 Channel 仍产生一个结果。若要改变 Feature 宽度，还需 Dense、Linear 或 $1\times1$ 卷积。

> [!WARNING] Padding 会参与后续计算
> 补入的值不是只为了让形状好看。卷积与池化在外侧位置会读取它们，因此输出数值也会改变。

> [!WARNING] Fold 不是 Unfold 的普通逆运算
> 窗口重叠时，Fold 会把重复位置相加；有位置未被窗口读取时，Fold 无法知道原数值。应先计算覆盖次数，再讨论能否恢复。

### 7.13 LP Pooling：窗口中的 $p$ 范数

PyTorch 提供 `LPPool1d` 与 `LPPool2d`。对窗口 $\mathcal W$，其简化公式为：

$$
y
=
\left(
\sum_{u\in\mathcal W}x_u^p
\right)^{1/p}.
$$

$p$ 称为 norm type。窗口内输入为非负数时：

- $p=1$ 得到窗口元素之和；
- $p=2$ 得到平方和开方；
- $p$ 很大时，较大的元素作用更明显。

#### 手算：窗口 $[3,4]$

当 $p=1$：

$$
y=3+4=7.
$$

当 $p=2$：

$$
y=(3^2+4^2)^{1/2}=5.
$$

它与 Average Pooling 不同，因为没有除以窗口元素数；也与 Max Pooling 不同，因为 3 和 4 都参与结果。

> [!WARNING] 负数与非整数 $p$ 需要谨慎
> 负数的非整数次幂可能没有实数结果。使用 LP Pooling 前，应确认输入范围和 norm type 是否适合。经过 ReLU 的非负特征更容易直观解释。

Keras 核心 Layer 中不常见与 PyTorch `LPPool2d` 完全同名的接口。需要相同计算时，可以在自定义 Layer 中按窗口提取、幂运算、求和与开方步骤完成，并明确 padding 和 stride。

### 7.14 MaxUnpool 的位置索引怎样使用

设输入为：

$$
X=
\begin{bmatrix}
1&5&2&4\\
3&0&8&6\\
7&2&1&9\\
4&3&5&0
\end{bmatrix}.
$$

使用 $2\times2$ Max Pooling、stride 2。四个窗口最大值分别为：

$$
5,\quad8,\quad7,\quad9.
$$

输出：

$$
Y=
\begin{bmatrix}
5&8\\
7&9
\end{bmatrix}.
$$

同时记录最大值在原输入中的位置：

- 5 位于第一行第二列；
- 8 位于第二行第三列；
- 7 位于第三行第一列；
- 9 位于第三行第四列。

MaxUnpool 把四个数放回这些位置，其他位置填 0：

$$
\widetilde X=
\begin{bmatrix}
0&5&0&0\\
0&0&8&0\\
7&0&0&9\\
0&0&0&0
\end{bmatrix}.
$$

> [!NOTE] 索引属于那一次池化计算
> 若换了输入、窗口大小、stride 或 padding，旧索引就不再描述新池化结果。MaxUnpool 应使用与对应 MaxPool 同一次前向计算得到的索引。

> [!WARNING] 指定 output size 有时是必要的
> stride 大于 1 时，不同原输入尺寸可能产生相同池化输出尺寸。MaxUnpool 只看到小特征和索引时，可能需要额外给出目标输出大小，才能选择正确形状。

Keras 常规 MaxPooling Layer 不默认返回索引，因此没有像 PyTorch `MaxUnpool2d` 那样直接配套的常用基础 Layer。若模型确实需要最大值位置，必须在池化阶段就保留它们，不能在输出产生后再从最大值反推出位置。

### 7.15 填充后卷积与 valid 卷积的等价形状

一个 $5\times5$ 输入使用 $3\times3$ valid 卷积，stride 1，输出大小：

$$
\left\lfloor\frac{5-3}{1}\right\rfloor+1=3,
$$

即 $3\times3$。

若先在四周各补一个 0，输入变成 $7\times7$，再做相同 valid 卷积：

$$
\left\lfloor\frac{7-3}{1}\right\rfloor+1=5,
$$

输出恢复为 $5\times5$。这与卷积自身设置 padding 1 在形状和零填充数值上相同。

> [!TIP] 独立 Padding Layer 适合非对称设置
> 若只想在左侧补 2、右侧补 0，独立 Layer 更容易写清楚。卷积本身的整数 padding 常表示两侧使用相同数量。

再考虑连续两次 valid $3\times3$ 卷积。输入从 9 变为：

$$
9\rightarrow7\rightarrow5.
$$

若另一个分支仍为 $9\times9$，想与 $5\times5$ 分支拼接，可以从大分支四周各裁去 2 个位置。裁剪数来自两次卷积每侧总共减少 2，而不是随意试出。

> [!WARNING] 拼接前不仅要检查高宽
> Batch Size 必须相同。沿 Channel维度拼接时，高宽必须相同；做逐元素相加时，Channel 数也通常要相同或满足明确的广播规则。

### 7.16 Unfold 输出为什么会迅速增大

输入形状为 PyTorch 的：

$$
(N,3,32,32).
$$

使用 $3\times3$ 窗口、stride 1、padding 1。输出高宽仍是 $32\times32$，窗口总数：

$$
L=32\times32=1024.
$$

每个窗口展开长度：

$$
CK_hK_w=3\times3\times3=27.
$$

因此 Unfold 输出形状：

$$
(N,27,1024).
$$

每个样本含：

$$
27\times1024=27648
$$

个元素，而原输入每个样本只有：

$$
3\times32\times32=3072
$$

个元素。展开结果正好约为原输入的 9 倍，原因是图像内部的大多数输入位置出现在 9 个不同窗口中。

若输入变为 64 个 Channel、空间大小 $128\times128$，相同窗口会得到：

$$
(N,576,16384),
$$

每个样本超过九百万个元素。即使 Layer 没有参数，中间张量也可能占用大量内存。

> [!WARNING] 无参数不等于开销小
> Reshape 通常只改变观察方式，Unfold 却会复制重叠窗口内容。分析资源使用时，应同时看输出元素数。

### 7.17 Padding、Cropping、Unfold 的轴差异总结

| 操作 | PyTorch channels-first | Keras 默认 channels-last | Channel 数是否改变 |
| --- | --- | --- | --- |
| 二维零填充 | $(N,C,H,W)$ 改变 $H,W$ | $(N,H,W,C)$ 改变 $H,W$ | 否 |
| 二维裁剪 | 通过切片改变最后两轴 | `Cropping2D` 改变中间两空间轴 | 否 |
| 局部块提取 | 常输出 $(N,CK_hK_w,L)$ | 常输出 $(N,H_o,W_o,CK_hK_w)$ | 内容被放入展开后的 Feature维度 |
| Fold 或块组合 | 指定输出高宽并累加 | 常需后端运算或自定义 Layer | 由块内容决定 |

> [!TIP] 看到四元组先确认它描述什么
> PyTorch 的二维 pad 四元组常是左、右、上、下；Keras Cropping2D 的两对数常分别描述高度与宽度。它们都使用四个整数，却不能直接交换使用。

> [!QUESTION] 为什么 Keras 提取块结果不像 PyTorch Unfold？
> 两个框架默认 Channel 轴不同，而且一个把窗口位置压成单轴 $L$，另一个常保留输出高宽。把 Keras 的输出高宽展平，并把最后 Feature维度换到前面，就能得到与 $(N,CK_hK_w,L)$ 相近的组织方式。

---

## 8. 转置卷积、插值上采样与空间重排

“让空间尺寸变大”可以通过多种方式完成。转置卷积包含可学习权重；nearest、linear、bilinear、bicubic 插值没有可学习参数；PixelShuffle 把 Channel 中已有元素重排到空间；ChannelShuffle 只改变 Channel 次序。这些方法都能改变形状，但数学含义并不相同。

> [!IMPORTANT] 尺寸变大不代表旧细节自动回来
> 一个 $2\times2$ 特征图放大到 $4\times4$，只是产生了更多输出位置。若早先池化已经舍弃某些数值，仅靠上采样不能推知它们。解码器常结合跳接特征或训练得到的卷积权重补充信息。

### 8.1 转置卷积的名称、输入轴与参数

| 计算 | PyTorch | Keras | PyTorch 默认输入 | Keras 默认输入 |
| --- | --- | --- | --- | --- |
| 一维转置卷积 | `ConvTranspose1d` | `Conv1DTranspose` | $(N,C_{\mathrm{in}},L)$ | $(N,L,C_{\mathrm{in}})$ |
| 二维转置卷积 | `ConvTranspose2d` | `Conv2DTranspose` | $(N,C_{\mathrm{in}},H,W)$ | $(N,H,W,C_{\mathrm{in}})$ |
| 三维转置卷积 | `ConvTranspose3d` | `Conv3DTranspose` | $(N,C_{\mathrm{in}},D,H,W)$ | $(N,D,H,W,C_{\mathrm{in}})$ |

转置卷积不是普通卷积的数值逆运算。它对应普通卷积线性计算中转置后的算子，可把每个输入位置通过卷积核“写入”一片输出区域，多个输入写到同一位置时相加。

> [!NOTE] “转置”描述的是线性算子关系
> 它不保证把普通卷积输出送进去就恢复原输入。普通卷积可能因 stride、Channel 变化或局部求和丢失信息，一个转置算子无法凭空知道这些内容。

PyTorch `ConvTranspose2d` 的权重形状为：

$$
(C_{\mathrm{in}},C_{\mathrm{out}}/G,K_h,K_w).
$$

它与 PyTorch `Conv2d` 的：

$$
(C_{\mathrm{out}},C_{\mathrm{in}}/G,K_h,K_w)
$$

轴次序不同。Keras `Conv2DTranspose` 的核轴常按空间高、空间宽、输出 Channel、输入 Channel 排列。

忽略 bias，分组转置卷积的权重参数数目仍为：

$$
P_W
=
C_{\mathrm{in}}
\frac{C_{\mathrm{out}}}{G}
K_hK_w.
$$

若使用 bias，再加 $C_{\mathrm{out}}$。

> [!WARNING] 不要按普通卷积轴次序手工复制转置卷积权重
> 即使元素总数相同，输入与输出 Channel 所在轴也可能不同。读取权重文件时应先检查框架、Layer 类型和张量轴说明。

### 8.2 转置卷积输出尺寸公式

PyTorch 转置卷积在一个空间轴上的输出长度为：

$$
L_{\mathrm{out}}
=
(L_{\mathrm{in}}-1)s
-2p
+d(K-1)
+o
+1,
$$

其中：

- $L_{\mathrm{in}}$：输入长度；
- $K$：kernel size；
- $s$：stride；
- $p$：padding；
- $d$：dilation；
- $o$：output padding。

二维和三维分别对每个空间轴使用该式。

#### 手算：长度 5 放大到长度 10

设：

$$
L_{\mathrm{in}}=5,\quad
K=4,\quad
s=2,\quad
p=1,\quad
d=1,\quad
o=0.
$$

代入：

$$
L_{\mathrm{out}}
=(5-1)\times2-2+3+1
=10.
$$

二维输入高宽都是 5，两个轴采用相同设置时，高宽都变成 10。

> [!TIP] 不要用“乘 stride”代替完整公式
> 上例恰好从 5 变成 10，但很多设置并不是简单乘 2。kernel size、padding、dilation 和 output padding 都会参与最终尺寸。

Keras 的 `Conv1DTranspose/Conv2DTranspose/Conv3DTranspose` 常通过 `padding="valid"` 或 `"same"`、`strides` 和 `output_padding` 控制输出。跨框架迁移时，应根据实际输入尺寸逐轴核对结果，不要只根据 `"same"` 名称推断。

### 8.3 一维手算：输入位置怎样生成并叠加

输入：

$$
x=[1,2],
$$

卷积核：

$$
w=[1,2,1],
$$

stride 为 2，无 padding、无 bias。输出长度为：

$$
(2-1)\times2+3=5.
$$

第一个输入数 1 生成：

$$
1\times[1,2,1]
\rightarrow
[1,2,1,0,0].
$$

第二个输入数 2 的起点向右移动两格：

$$
2\times[1,2,1]
\rightarrow
[0,0,2,4,2].
$$

两段逐位置相加：

$$
[1,2,1,0,0]+[0,0,2,4,2]
=[1,2,3,4,2].
$$

位置 2 同时收到 $1\times1$ 与 $2\times1$，因此得到 3。

> [!NOTE] 转置卷积可理解为“每个输入写出一个小片段”
> stride 决定相邻输入写出片段的起点间隔；kernel size 与 dilation 决定片段覆盖范围；重叠位置做加法。

### 8.4 二维手算：重叠次数怎样改变数值

输入为：

$$
X=
\begin{bmatrix}
1&2\\
3&4
\end{bmatrix},
$$

核为全 1 的 $2\times2$ 矩阵。

当 stride 为 2 时，四个输入各自产生一个互不重叠的 $2\times2$ 块：

$$
Y=
\begin{bmatrix}
1&1&2&2\\
1&1&2&2\\
3&3&4&4\\
3&3&4&4
\end{bmatrix}.
$$

当 stride 为 1 时，块之间发生重叠：

$$
Y=
\begin{bmatrix}
1&3&2\\
4&10&6\\
3&7&4
\end{bmatrix}.
$$

中心的 10 来自：

$$
1+2+3+4=10.
$$

上方中间的 3 来自 $1+2$，左侧中间的 4 来自 $1+3$。

> [!WARNING] 重叠次数不均可能形成规律纹理
> 有些输出位置接收多次写入，有些只接收一次。若 kernel size 与 stride 的组合使不同位置长期拥有不同重叠次数，图像中可能出现棋盘状或周期状纹理。可以比较“先插值，再做普通卷积”的结构。

### 8.5 output padding 为什么存在

普通 stride 2 卷积可能让不同输入长度得到同一输出长度。以 kernel size 3、stride 2、padding 1 为例：

$$
L_{\mathrm{in}}=31\rightarrow L_{\mathrm{out}}=16,
$$

$$
L_{\mathrm{in}}=32\rightarrow L_{\mathrm{out}}=16.
$$

转置卷积只看到长度 16 时，无法知道目标是 31 还是 32。使用相同 kernel size、stride 和 padding：

$$
L_{\mathrm{out}}=31+o.
$$

所以 output padding 为 0 时得到 31，为 1 时得到 32。

> [!NOTE] output padding 不会直接补一个固定数
> 它只在多个合法输出尺寸中指定额外长度。新增位置的数值仍由转置卷积规则计算，不是简单在末尾写 0。

编码器和解码器使用跳接时，应记录每一级特征形状。若输入高宽为奇数，连续下采样后再按固定倍率放大，常出现相差一个像素的情况。PyTorch 转置卷积前向计算可通过 `output_size` 指定目标；Keras 可以通过明确的 padding、output padding、裁剪或补齐让形状一致。

> [!WARNING] 不要先随意裁剪，再忽略尺寸差异原因
> 相差一个像素可能来自向下取整、padding 设置或 output padding。应先逐轴代入公式，再决定采用哪种调整方式。

### 8.6 nearest 上采样：复制邻近值

PyTorch 可使用 `Upsample` 或函数式插值接口。Keras 提供 `UpSampling1D/2D/3D`，二维还可以使用 `Resizing` 指定目标高宽。nearest 没有可学习参数，只选择最近的输入位置。

一维输入：

$$
[10,20]
$$

放大 2 倍后：

$$
[10,10,20,20].
$$

二维输入：

$$
\begin{bmatrix}
1&2\\
3&4
\end{bmatrix}
$$

按高宽各放大 2 倍：

$$
\begin{bmatrix}
1&1&2&2\\
1&1&2&2\\
3&3&4&4\\
3&3&4&4
\end{bmatrix}.
$$

> [!TIP] 类别编号图通常使用 nearest
> 分割标签中的 0、1、2 表示离散类别。线性插值可能产生 0.4、1.7 等没有类别含义的数。调整标签尺寸时通常采用 nearest。

> [!NOTE] nearest 与 stride 2 转置卷积结果可能看起来相似
> 当转置卷积核取某些特殊固定值时，它也可能复制输入，但普通转置卷积的权重会训练，而且重叠位置采用乘加，因此两者不是同一 Layer。

### 8.7 linear、bilinear 与 trilinear

linear 插值用于一个空间轴；bilinear 用于二维高宽；trilinear 用于三维深度、高度和宽度。它们都根据邻近输入按距离计算权重。

一维线性插值可以写为：

$$
y=(1-\alpha)x_0+\alpha x_1,
\qquad 0\le\alpha\le1.
$$

$\alpha$ 越接近 0，输出越接近左侧输入；越接近 1，输出越接近右侧输入。

#### 手算：两个数之间插入一个中点

输入为 $[0,10]$，中点距离两端相同，因此 $\alpha=0.5$：

$$
y=0.5\times0+0.5\times10=5.
$$

得到 $[0,5,10]$。

二维 bilinear 插值会使用邻近四个输入：

$$
y
=
w_{00}x_{00}
+w_{01}x_{01}
+w_{10}x_{10}
+w_{11}x_{11},
$$

并满足：

$$
w_{00}+w_{01}+w_{10}+w_{11}=1.
$$

若新位置恰好位于四个像素中心，四个权重都是 $1/4$。输入四个数为 1、3、5、7 时：

$$
y=(1+3+5+7)/4=4.
$$

> [!NOTE] bilinear 会产生输入中没有的新数
> nearest 只复制已有值；bilinear 使用加权平均，因此会产生平滑过渡。它适合连续图像或连续特征，不适合直接处理离散类别编号。

PyTorch 中一维线性模式常称为 `linear`，二维称为 `bilinear`，三维称为 `trilinear`。Keras `UpSampling2D` 常支持 nearest 与 bilinear 等插值方式；`Resizing` 也可以选择插值方法。Keras `UpSampling1D` 常采用重复方式，若要按线性规则得到指定长度，可使用图像调整接口、后端运算或自定义 Layer。

### 8.8 align corners 改变坐标规则

PyTorch 的 linear、bilinear、bicubic、trilinear 模式可使用 `align_corners`。它决定输入与输出的坐标如何对应。

对输入 $[0,10]$ 调整到长度 4：

当 `align_corners=True` 时，首尾输入点与首尾输出点对齐：

$$
[0,\;10/3,\;20/3,\;10]
\approx
[0,\;3.333,\;6.667,\;10].
$$

当 `align_corners=False` 时，按像素小块中心关系计算，可得到：

$$
[0,\;2.5,\;7.5,\;10].
$$

> [!WARNING] align corners 为 True 不代表结果更准确
> 两种设置采用不同坐标约定。模型训练、推理、导出和其他框架重现时应保持一致。Keras 高层调整 Layer 未必暴露完全相同的参数，应通过最小数字例子核对数值。

> [!TIP] 需要与另一分支拼接时直接指定目标尺寸
> 输入高宽为奇数时，连续缩小与按倍率放大容易相差一个像素。若上采样结果要与跳接特征拼接，使用对方的实际高宽作为目标，比反复推算浮点倍率更稳妥。

### 8.9 bicubic：使用更大的邻近区域

bicubic 插值在二维图像上通常沿每个轴考虑四个邻近位置，因此一个输出像素最多受到 $4\times4$ 输入邻域影响。它使用三次函数计算权重，通常比 bilinear 更平滑，也保留更多曲线变化。

> [!NOTE] bicubic 仍然没有可学习参数
> 权重由相对坐标和固定三次插值公式决定，不由训练数据更新。这里的“权重”是本次插值系数，不是模型参数。

bicubic 的加权系数可能为负，所以输出有时会稍小于输入最小值或稍大于输入最大值。例如输入都位于 0 到 1，个别输出可能略小于 0 或略大于 1。若后续要求固定数值范围，应根据任务决定是否裁剪。

> [!WARNING] 插值更平滑不等于任务效果一定更好
> 对照片放大，bicubic 常有较平滑外观；对中间特征或标签，过度平滑可能削弱尖锐变化。应根据数据类型选择。

Keras `Resizing` 和部分 `UpSampling2D` 版本支持 bicubic；PyTorch 二维插值支持 bicubic。三维体数据通常使用 trilinear，而不是把 bicubic 直接扩展成同名三维模式。

### 8.10 使用 size 与使用 scale factor

上采样可以指定最终尺寸，也可以指定倍率。

若 PyTorch 输入为 $(N,C,H,W)$，倍率为 $(r_h,r_w)$，常见输出高宽接近：

$$
H_{\mathrm{out}}=\lfloor H r_h\rfloor,\qquad
W_{\mathrm{out}}=\lfloor W r_w\rfloor.
$$

Keras `UpSampling2D(size=(r_h,r_w))` 中的 `size` 常表示整数放大倍率；Keras `Resizing(height,width)` 中的 height 与 width 则表示目标尺寸。两个 Layer 的参数名含义不能混用。

> [!WARNING] 同名 size 在不同 Layer 中含义可能不同
> PyTorch 插值接口中的 `size` 通常是目标尺寸，Keras `UpSampling2D` 的 `size` 通常是放大倍数。阅读构造参数时要结合 Layer 名称。

假设解码器特征高宽为 $15\times16$，跳接特征为 $31\times33$。简单乘 2 得到 $30\times32$，无法拼接。直接指定目标为 $31\times33$ 可以避免两轴都差一个位置。

对于缩小图像，bilinear 或 bicubic 可以使用抗混叠设置，以减轻密集纹理缩小时出现的锯齿。PyTorch 和 Keras 的具体参数名称及支持模式可能不同，应结合版本文档确认。

### 8.11 插值后接卷积与转置卷积的比较

插值后接普通卷积包含两步：

1. 使用固定规则改变空间尺寸；
2. 使用可学习卷积组合局部位置和 Channel。

转置卷积则在一次 Layer 中完成可学习的空间扩展与乘加。

| 比较项 | 插值后接卷积 | 转置卷积 |
| --- | --- | --- |
| 放大步骤是否有参数 | 插值无参数，后续卷积有参数 | 有参数 |
| 输出尺寸控制 | 插值可直接指定目标尺寸 | 由转置卷积公式决定 |
| 重叠方式 | 插值先生成值，再普通卷积 | 输入写入区域，重叠处相加 |
| 周期状纹理风险 | 通常较容易控制 | 需留意核与 stride 组合 |
| Channel 变化 | 由后续卷积决定 | 由输出 Channel 参数决定 |

> [!TIP] 两种方法都值得掌握
> 插值后接卷积容易分开观察尺寸变化与特征计算；转置卷积可以学习更自由的放大规则。选择时要同时考虑输出质量、计算量、内存和部署环境支持。

### 8.12 PixelShuffle 与 depth to space

PixelShuffle 把 Channel维度中的元素重新排列到高和宽。它本身没有可学习参数，也不做插值或平均。

PyTorch `PixelShuffle(r)` 的形状变化为：

$$
(N,Cr^2,H,W)
\rightarrow
(N,C,Hr,Wr).
$$

Keras 或其后端常把相同操作称为 `depth_to_space`。channels-last 形状为：

$$
(N,H,W,Cr^2)
\rightarrow
(N,Hr,Wr,C).
$$

某些 Keras 版本可通过 Keras 运算接口调用 depth to space；也可以在自定义 Layer 中使用所选后端的同名运算。核心要求都是输入 Channel 数能被 $r^2$ 整除。

#### 手算：四个 Channel 变成一个 $2\times2$ 区域

输入形状为 PyTorch 的 $(1,4,1,1)$，四个 Channel 依次保存：

$$
[10,20,30,40].
$$

放大倍率 $r=2$，因为 $4=1\times2^2$，输出 Channel 为 1，高宽各变为 2：

$$
\begin{bmatrix}
10&20\\
30&40
\end{bmatrix}.
$$

四个数没有改变，只是从 Channel维度移动到空间位置。

> [!WARNING] PixelShuffle 前通常需要卷积准备 Channel
> 若希望输出有 $C$ 个 Channel、放大倍率为 $r$，前一层必须产生 $Cr^2$ 个 Channel。例如输出 RGB 图像且 $r=2$，PixelShuffle 输入需要 12 个 Channel。

> [!NOTE] PixelShuffle 本身参数数目为 0
> 超分辨率模型中的学习能力来自它前后的卷积。PixelShuffle 只按固定次序重新排列元素。

### 8.13 PixelUnshuffle 与 space to depth

PyTorch `PixelUnshuffle(r)` 是反向空间重排：

$$
(N,C,Hr,Wr)
\rightarrow
(N,Cr^2,H,W).
$$

Keras 或其后端常称为 `space_to_depth`：

$$
(N,Hr,Wr,C)
\rightarrow
(N,H,W,Cr^2).
$$

它把每个 $r\times r$ 空间小块中的数放到 Channel维度。只要轴次序与排列规则一致，PixelUnshuffle 可以还原 PixelShuffle 的结果。

以前面的矩阵为例：

$$
\begin{bmatrix}
10&20\\
30&40
\end{bmatrix}
\rightarrow
[10,20,30,40].
$$

> [!WARNING] 高宽必须能被倍率整除
> `PixelUnshuffle(2)` 要求高和宽都能被 2 整除。若高为 5，不能把每个 $2\times2$ 小块完整取出，应先明确裁剪或填充方式。

space to depth 看起来像下采样，因为高宽变小；但它没有丢弃元素，元素总数保持不变。普通池化则会舍弃或合并窗口数值。

### 8.14 ChannelShuffle：让分组后的 Channel 交错排列

ChannelShuffle 不改变张量形状，只改变 Channel 次序。PyTorch 提供 `ChannelShuffle(groups)`。Keras 常通过 Reshape、交换轴和再次 Reshape 组合实现，也可以封装成无参数自定义 Layer。

假设 Channel 数为 $C$，分组数为 $G$。先把 Channel维度拆成：

$$
(G,C/G),
$$

再交换这两个轴：

$$
(C/G,G),
$$

最后展平回长度 $C$。

#### 手算：8 个 Channel、2 组

原次序按两组写成：

$$
[a_0,a_1,a_2,a_3,\;b_0,b_1,b_2,b_3].
$$

拆成两行：

$$
\begin{bmatrix}
a_0&a_1&a_2&a_3\\
b_0&b_1&b_2&b_3
\end{bmatrix}.
$$

交换组轴与组内轴后再展平：

$$
[a_0,b_0,a_1,b_1,a_2,b_2,a_3,b_3].
$$

这样下一次 groups 为 2 的卷积中，每组会接触到来自原来不同组的 Channel。

> [!NOTE] ChannelShuffle 没有数值运算参数
> 它不做加法、乘法或插值，只改变元素次序。形状和元素总数保持不变。

> [!WARNING] Channel 数必须能被 groups 整除
> 10 个 Channel 不能均分为 4 组。即使手工 Reshape，也必须满足元素数与目标形状一致。

PyTorch channels-first 输入可把 Channel 轴拆成 $(G,C/G)$。Keras 默认 channels-last 时，应拆分最后一轴。若错误地拆分高或宽，运算可能仍能执行，但空间结构会被破坏。

### 8.15 空间重排、池化与插值的元素数比较

| Layer | 参数数目 | 是否保持元素总数 | 是否合并多个输入数 | 是否可能生成新数值 |
| --- | ---: | --- | --- | --- |
| Max Pooling | 0 | 否 | 选择最大值 | 否 |
| Average Pooling | 0 | 否 | 求平均 | 是 |
| nearest | 0 | 否，通常增加 | 复制 | 否 |
| linear/bilinear/bicubic | 0 | 否，通常增加 | 加权组合 | 是 |
| 转置卷积 | 取决于核 | 否 | 乘加 | 是 |
| PixelShuffle | 0 | 是 | 不合并 | 否 |
| PixelUnshuffle | 0 | 是 | 不合并 | 否 |
| ChannelShuffle | 0 | 是 | 不合并 | 否 |

表中的“是否保持元素总数”只计算每个样本的 Channel 与空间尺寸乘积。PixelShuffle 将 Channel 减少 $r^2$ 倍，同时让高宽乘积增加 $r^2$ 倍，所以总元素数不变。

> [!TIP] 先问“元素去了哪里”
> 池化会选择或合并元素；插值会复制或加权产生更多位置；PixelShuffle 只是重新排列；转置卷积则用可学习权重生成并累加。用这四种描述可以快速区分名称相近的放大与缩小 Layer。

### 8.16 本章常见错误与逐项检查

> [!WARNING] 错误一：把 nearest 用于连续图像后期待平滑结果
> nearest 会复制像素，放大后容易看到块状结构。若需要平滑过渡，可比较 bilinear 或 bicubic。

> [!WARNING] 错误二：把 bilinear 用于类别编号
> 加权平均会产生不存在的类别编号。标签图通常使用 nearest，并在调整后保持整数类型。

> [!WARNING] 错误三：误以为转置卷积一定恢复卷积输入
> 它只能根据当前输入和卷积核执行转置算子，无法自动恢复普通卷积已经合并或舍弃的信息。

> [!WARNING] 错误四：PixelShuffle 的 Channel 数不满足要求
> 倍率为 3 时，输入 Channel 必须能被 9 整除。目标输出 Channel 为 16 时，前一层应产生 144 个 Channel。

> [!WARNING] 错误五：忽略框架默认轴次序
> PyTorch PixelShuffle 操作第二轴 Channel，Keras 的 depth to space 常操作最后一轴 Channel。卷积、池化、填充与空间重排必须对同一轴约定保持一致。

面对一个空间尺寸变换 Layer，可以依次回答：

1. 输入使用 channels-first 还是 channels-last？
2. 哪些轴会改变，Batch维度与 Channel维度是否保留？
3. 输出尺寸由公式、目标 size 还是倍率决定？
4. Layer 是否有可学习参数？
5. 多个输入数是被选择、平均、加权相加，还是只重新排列？
6. 奇数尺寸、padding 与取整会不会让两个分支相差一个位置？
7. PyTorch 与 Keras 的参数名、默认轴和坐标规则是否一致？

能回答这七个问题，就能把转置卷积、插值、PixelShuffle 和 ChannelShuffle 区分清楚。

---

## 9. 循环序列 Layer：SimpleRNN、RNN、GRU 与 LSTM

循环序列 Layer 用于处理具有先后次序的数据，例如句子中的 token、每天的气温、语音帧和传感器读数。它们的共同特点是：第 $t$ 个位置不仅读取当前输入 $x_t$，还读取前一个位置留下的状态。这个状态让后面的计算能够利用前面已经出现的信息。

> [!NOTE] “循环”指状态被反复使用
> 同一个 Layer 参数会在第 1、2、3 等所有时间位置重复使用。序列长度增加不会增加这组参数的数量，但会增加重复计算的次数。

### 9.1 先统一循环 Layer 的符号和形状

本章使用下列符号：

| 符号 | 含义 |
| --- | --- |
| $N$ | Batch Size |
| $L$ | Sequence Length |
| $I$ | 每个时间位置的输入 Feature 宽度 |
| $H$ | 隐藏状态宽度 |
| $K$ | 循环层数 |
| $R$ | 方向数；单向为 1，双向为 2 |
| $x_t$ | 第 $t$ 个位置的输入向量，形状为 $(I)$ |
| $h_t$ | 第 $t$ 个位置的隐藏状态，形状为 $(H)$ |
| $c_t$ | LSTM 第 $t$ 个位置的记忆状态，形状为 $(H)$ |
| $W$ | 可学习权重矩阵 |
| $b$ | 可学习偏置向量 |

常见的一个 Batch 输入采用 `(N,L,I)`，也就是 Batch维度在前、序列维度居中、Feature维度在后。PyTorch 设置 `batch_first=True` 后使用这一排列；Keras 的循环 Layer 默认也采用这一排列。

| 计算对象 | 单向 RNN 或 GRU 形状 | 双向 RNN 或 GRU 形状 |
| --- | --- | --- |
| 输入 | $(N,L,I)$ | $(N,L,I)$ |
| 每个位置的最高层输出 | $(N,L,H)$ | $(N,L,2H)$ |
| PyTorch 返回的全部层最终隐藏状态 | $(K,N,H)$ | $(2K,N,H)$ |

> [!IMPORTANT] Batch维度放在前面，不会改变状态张量的组织方式
> 在 PyTorch 中，即使 `batch_first=True`，最终状态仍以“层与方向”作为第 0 维。因此双向两层网络的最终状态形状是 $(4,N,H)$，不是 $(N,4,H)$。

> [!NOTE] Keras 堆放多层循环 Layer 时要逐层查看状态
> Keras 的 `return_state=True` 返回当前循环 Layer 的状态。把多个循环 Layer 依次堆放，并不会自动把所有层状态合成上表所示的单个张量；若需要保留每一层状态，应分别接收并记录。

### 9.2 SimpleRNN 与 PyTorch `RNN`

Keras 名称 `SimpleRNN` 与 PyTorch 名称 `RNN` 都表示基础循环神经网络。最常见的双曲正切形式为：

$$
a_t=W_{ih}x_t+b_{ih}+W_{hh}h_{t-1}+b_{hh},
$$

$$
h_t=\tanh(a_t).
$$

公式中的每个符号含义如下：

| 符号 | 形状 | 含义 |
| --- | --- | --- |
| $x_t$ | $(I)$ | 当前时间位置的输入 |
| $h_{t-1}$ | $(H)$ | 前一个位置留下的隐藏状态 |
| $W_{ih}$ | $(H,I)$ | 把输入 Feature 转换到隐藏宽度 |
| $W_{hh}$ | $(H,H)$ | 处理旧隐藏状态 |
| $b_{ih},b_{hh}$ | $(H)$ | 两部分偏置 |
| $a_t$ | $(H)$ | 激活函数之前的中间结果 |
| $h_t$ | $(H)$ | 当前时间位置的新状态 |

这里的矩阵乘法分别得到两个 $H$ 维向量，再逐元素相加。$\tanh$ 把每个元素压到 $(-1,1)$。

#### 数字例子：前一个状态怎样影响当前结果

先把输入宽度和隐藏宽度都设为 1。令：

$$
x_1=2,\quad h_0=0,\quad W_{ih}=0.5,\quad W_{hh}=0.25,
$$

并令两个偏置都为 0。第一个位置为：

$$
a_1=0.5\times2+0.25\times0=1,
$$

$$
h_1=\tanh(1)\approx0.7616.
$$

第二个输入若为 $x_2=1$，则：

$$
a_2=0.5\times1+0.25\times0.7616
=0.6904,
$$

$$
h_2=\tanh(0.6904)\approx0.5982.
$$

虽然第二个位置的输入只有 1，它的结果还受到 $h_1$ 的影响。若强行把 $h_1$ 改为 0，第二个结果会变成 $\tanh(0.5)\approx0.4621$，与 0.5982 明显不同。

> [!EXAMPLE] 用自然语言理解隐藏状态
> 读取“这 部 电影 很”以后，状态中可能保留“当前正在评价电影”等信息。继续读到“精彩”时，Layer 同时利用“精彩”的输入向量和先前状态，形成新的上下文表示。

基础 RNN 也可以使用 ReLU：

$$
h_t=\max(0,a_t).
$$

PyTorch 通过 `nonlinearity="tanh"` 或 `"relu"` 选择；Keras `SimpleRNN` 通过 `activation` 选择。

| 项目 | PyTorch | Keras |
| --- | --- | --- |
| Layer 名称 | `RNN` | `SimpleRNN` |
| 单步版本 | `RNNCell` | `SimpleRNNCell` |
| 隐藏宽度参数 | `hidden_size` | `units` |
| 返回全部位置 | `output` 总会返回 | `return_sequences=True` |
| 返回最终状态 | `h_n` 总会返回 | `return_state=True` |
| 多层 | `num_layers=K` | 叠放多个 Layer |
| 双向 | `bidirectional=True` | `Bidirectional` 包装 |

> [!WARNING] SimpleRNN 并不等于“只能输入简单数据”
> “Simple”表示它的状态更新公式比 GRU 和 LSTM 少，不代表输入只能是一维数。每个时间位置仍可含几百维 Feature。

### 9.3 GRU：用门控制旧状态与候选状态

GRU 引入重置门 $r_t$、更新门 $z_t$ 和候选状态 $n_t$：

$$
r_t=\sigma(W_{ir}x_t+b_{ir}+W_{hr}h_{t-1}+b_{hr}),
$$

$$
z_t=\sigma(W_{iz}x_t+b_{iz}+W_{hz}h_{t-1}+b_{hz}),
$$

$$
n_t=\tanh\left(
W_{in}x_t+b_{in}
+r_t\odot(W_{hn}h_{t-1}+b_{hn})
\right),
$$

$$
h_t=(1-z_t)\odot n_t+z_t\odot h_{t-1}.
$$

其中：

- $\sigma$ 是 Sigmoid，把数值压到 $(0,1)$；
- $\odot$ 是逐元素乘法；
- $r_t$ 决定旧状态参与候选状态计算的程度；
- $z_t$ 决定新状态在旧状态与候选状态之间取多少；
- $n_t$ 是本位置准备写入的候选信息；
- 所有门和状态的形状都是 $(H)$。

> [!NOTE] 门不是人工指定的开关
> 门值由当前输入、旧状态和可学习参数共同算出。训练会逐渐调整这些参数，使不同样本、不同时间位置得到不同门值。

#### 数字例子：更新门怎样混合新旧信息

只观察一个隐藏元素，令：

$$
h_{t-1}=0.8,\qquad n_t=0.2.
$$

若更新门为 $z_t=0.75$：

$$
h_t=(1-0.75)\times0.2+0.75\times0.8
=0.05+0.60=0.65.
$$

结果更接近旧状态 0.8。若 $z_t=0.10$：

$$
h_t=0.90\times0.2+0.10\times0.8
=0.18+0.08=0.26.
$$

结果更接近候选状态 0.2。因此，按上式定义时，$z_t$ 越大，旧状态保留得越多。

再观察重置门。若旧状态经过线性计算后为 1.2：

- $r_t=0.9$ 时，这部分贡献为 $1.08$；
- $r_t=0.1$ 时，这部分贡献为 $0.12$。

较小的重置门会让候选状态较少利用旧信息。

| 项目 | PyTorch | Keras |
| --- | --- | --- |
| 完整序列 Layer | `GRU` | `GRU` |
| 单步计算 | `GRUCell` | `GRUCell` |
| 隐藏宽度 | `hidden_size` | `units` |
| 返回完整序列 | `output` | `return_sequences=True` |
| 返回最终状态 | `h_n` | `return_state=True` |

> [!WARNING] 两个框架的内部参数排列不宜直接按数组位置复制
> 即使门公式表达相同，不同实现的门排列、偏置组织和加速条件也可能不同。交换参数时应依据框架提供的权重说明逐项核对。

### 9.4 LSTM：分别维护隐藏状态和记忆状态

LSTM 在隐藏状态 $h_t$ 之外增加记忆状态 $c_t$，并使用输入门、遗忘门、候选记忆和输出门：

$$
i_t=\sigma(W_{ii}x_t+b_{ii}+W_{hi}h_{t-1}+b_{hi}),
$$

$$
f_t=\sigma(W_{if}x_t+b_{if}+W_{hf}h_{t-1}+b_{hf}),
$$

$$
g_t=\tanh(W_{ig}x_t+b_{ig}+W_{hg}h_{t-1}+b_{hg}),
$$

$$
o_t=\sigma(W_{io}x_t+b_{io}+W_{ho}h_{t-1}+b_{ho}),
$$

$$
c_t=f_t\odot c_{t-1}+i_t\odot g_t,
$$

$$
h_t=o_t\odot\tanh(c_t).
$$

符号逐项解释如下：

| 符号 | 名称 | 作用 |
| --- | --- | --- |
| $i_t$ | 输入门 | 控制候选记忆写入多少 |
| $f_t$ | 遗忘门 | 控制旧记忆保留多少 |
| $g_t$ | 候选记忆 | 准备写入的新内容 |
| $o_t$ | 输出门 | 控制当前记忆向外提供多少 |
| $c_{t-1}$ | 旧记忆状态 | 前一个位置保存的内部信息 |
| $c_t$ | 新记忆状态 | 旧记忆与新内容合成后的结果 |
| $h_t$ | 新隐藏状态 | 当前时间位置向外提供的结果 |

#### 数字例子：一个记忆元素怎样更新

令：

$$
c_{t-1}=0.6,\quad
f_t=0.8,\quad
i_t=0.25,\quad
g_t=-0.4,\quad
o_t=0.7.
$$

先计算旧记忆保留部分：

$$
f_t c_{t-1}=0.8\times0.6=0.48.
$$

再计算新内容写入部分：

$$
i_t g_t=0.25\times(-0.4)=-0.10.
$$

所以新记忆为：

$$
c_t=0.48-0.10=0.38.
$$

隐藏输出为：

$$
h_t=0.7\times\tanh(0.38)
\approx0.7\times0.3627
\approx0.2539.
$$

这个例子展示了两个层次：$c_t=0.38$ 是内部记忆，$h_t\approx0.2539$ 是经过输出门控制后对外给出的状态。

> [!TIP] 不要把 $h_t$ 与 $c_t$ 当成同一个量
> 普通 LSTM 中二者形状通常相同，但数值和作用不同。调用 Layer 时遗漏其中一个初始状态，或交换二者次序，都会改变计算。

| 项目 | PyTorch | Keras |
| --- | --- | --- |
| 完整序列 Layer | `LSTM` | `LSTM` |
| 单步计算 | `LSTMCell` | `LSTMCell` |
| 返回值 | `output,(h_n,c_n)` | 由 `return_sequences`、`return_state` 决定 |
| 隐藏宽度 | `hidden_size` | `units` |
| 投影 LSTM | `proj_size` | 基础 `LSTM` 无同名设置 |

普通 LSTM 中：

$$
\operatorname{shape}(h_n)=\operatorname{shape}(c_n)=(KR,N,H).
$$

PyTorch 设置投影宽度 $P>0$ 后：

$$
\operatorname{shape}(output)=(N,L,RP),
$$

$$
\operatorname{shape}(h_n)=(KR,N,P),
\qquad
\operatorname{shape}(c_n)=(KR,N,H).
$$

此时内部记忆仍是 $H$ 维，而对外隐藏状态是 $P$ 维。

### 9.5 多层与双向状态到底怎样排列

以两层双向 GRU 为例，$K=2,R=2$，最终状态第 0 维长度是 $KR=4$：

| 第 0 维下标 | 层 | 方向 |
| --- | --- | --- |
| 0 | 第 0 层 | 正向 |
| 1 | 第 0 层 | 反向 |
| 2 | 第 1 层 | 正向 |
| 3 | 第 1 层 | 反向 |

可以把 $(4,N,H)$ 理解成 $(K,R,N,H)$。若要获得最高层完整句子表示，通常选择最后一层的正向最终状态和反向最终状态，再沿 Feature维度拼接，得到 $(N,2H)$。

> [!WARNING] `output` 的最后一个序列位置不等于双向最终状态
> 正向在最后一个位置读完整条序列，反向则在第一个位置读完整条序列。直接选择 `output` 的最后一个位置，只能正确取得正向最终状态。两个方向都要使用时，读取框架返回的方向状态更稳妥。

多层网络还需要注意每一层的输入宽度：

- 第 0 层输入宽度是 $I$；
- 单向网络的第 1 层及更高层输入宽度是 $H$；
- 双向网络的第 1 层及更高层输入宽度是 $2H$，因为上一层两个方向会拼接。

循环 Layer 构造参数中的 Dropout 通常放在相邻循环层之间。只有一层时，没有层间位置可放，因此该设置通常不产生效果。

### 9.6 不等长序列：补齐位置为何必须单独处理

假设三个句子的有效长度分别是 5、3、2。组成一个 Batch 后，可以补齐成长度 5：

| 样本 | 位置 0 | 位置 1 | 位置 2 | 位置 3 | 位置 4 |
| --- | --- | --- | --- | --- | --- |
| 0 | 有效 | 有效 | 有效 | 有效 | 有效 |
| 1 | 有效 | 有效 | 有效 | PAD | PAD |
| 2 | 有效 | 有效 | PAD | PAD | PAD |

有效位置布尔表为：

$$
\begin{bmatrix}
1&1&1&1&1\\
1&1&1&0&0\\
1&1&0&0&0
\end{bmatrix}.
$$

若直接让 RNN 计算整个矩形输入，样本 1 和样本 2 仍会经历补齐时间位置。即使 PAD 的输入向量为零，状态公式仍含有 $W_{hh}h_{t-1}+b_{hh}$，所以隐藏状态可能继续变化。

PyTorch 常用打包序列功能，让循环 Layer 只处理有效长度。Keras 常通过输入 mask 把有效位置告知支持 mask 的循环 Layer。两种方法目标相近，但接口形式不同。

> [!IMPORTANT] `Embedding` 的补齐设置不能代替序列长度
> 补齐行不更新，只解决查表参数问题；循环 Layer 是否跳过补齐位置，还需要长度信息或 mask。

使用最终状态做句子表示时，若序列已经正确打包或遮住，框架返回的最终状态对应每个样本最后一个有效位置。若没有处理 PAD，短样本的最终状态可能对应最后一个补齐位置。

> [!WARNING] 有效长度不能写错
> 把实际长度 3 写成 5，会把两个 PAD 当成真实时间位置；写成 2，则第三个真实 token 不再参与计算。长度应在整理原始样本时保存。

---

## 10. 注意力与 Transformer 基础子层

注意力的核心问题是：对某个查询位置，应从哪些信息位置读取内容，并分别读取多少。它通常包含 Query、Key 和 Value 三组向量。

### 10.1 Query、Key、Value 的含义与形状

设 Query 序列长度为 $L_q$，Key 和 Value 序列长度为 $L_k$，Feature 宽度为 $E$：

$$
Q=X_qW_Q,\qquad
K=X_kW_K,\qquad
V=X_vW_V.
$$

| 符号 | 常见形状 | 含义 |
| --- | --- | --- |
| $X_q$ | $(N,L_q,E)$ | 产生查询的输入 |
| $X_k$ | $(N,L_k,E)$ | 产生检索特征的输入 |
| $X_v$ | $(N,L_k,E)$ | 产生被加权内容的输入 |
| $W_Q,W_K,W_V$ | 与投影宽度相容 | 可学习投影参数 |
| $Q$ | $(N,L_q,d_k)$ | Query |
| $K$ | $(N,L_k,d_k)$ | Key |
| $V$ | $(N,L_k,d_v)$ | Value |

Query 与 Key 用来计算“相关程度”，Value 提供真正汇总到输出中的内容。Key 和 Value 的序列长度相同，是因为每个 Key 位置都对应一个 Value 位置。

> [!EXAMPLE] 图书检索类比
> Query 像读者写下的问题，Key 像每本书的目录特征，Value 像书中的实际内容。问题与目录越相符，对应内容获得的权重越大。

自注意力中三者来自同一输入，常有 $L_q=L_k=L$。交叉注意力中，Query 可来自目标序列，Key 和 Value 来自编码器输出，此时 $L_q$ 与 $L_k$ 可以不同。

### 10.2 Dot Attention：点积注意力

最简单的点积注意力先计算：

$$
s_{ij}=q_i\cdot k_j
=\sum_{r=1}^{d_k}q_{i,r}k_{j,r}.
$$

其中：

- $i$ 是 Query 位置；
- $j$ 是 Key 位置；
- $r$ 遍历 Feature；
- $s_{ij}$ 是第 $i$ 个 Query 对第 $j$ 个 Key 的分数。

再沿 Key 位置使用 Softmax：

$$
\alpha_{ij}
=\frac{\exp(s_{ij})}
{\sum_{m=1}^{L_k}\exp(s_{im})}.
$$

最后对 Value 加权求和：

$$
o_i=\sum_{j=1}^{L_k}\alpha_{ij}v_j.
$$

#### 完整数字例子

令一个 Query 为：

$$
q=[1,2],
$$

两个 Key 为：

$$
k_1=[1,0],\qquad k_2=[0,1],
$$

对应 Value 为：

$$
v_1=[10,0],\qquad v_2=[0,20].
$$

第一步计算分数：

$$
s_1=q\cdot k_1=1\times1+2\times0=1,
$$

$$
s_2=q\cdot k_2=1\times0+2\times1=2.
$$

第二步计算 Softmax。取 $e^1\approx2.718$、$e^2\approx7.389$：

$$
\alpha_1=\frac{2.718}{2.718+7.389}\approx0.269,
$$

$$
\alpha_2=\frac{7.389}{2.718+7.389}\approx0.731.
$$

第三步加权 Value：

$$
o=0.269[10,0]+0.731[0,20]
=[2.69,14.62].
$$

输出不是选择某一个 Value，而是所有 Value 的加权和。

### 10.3 Scaled Dot-Product Attention

Transformer 使用缩放点积注意力：

$$
\operatorname{Attention}(Q,K,V)
=\operatorname{Softmax}\left(
\frac{QK^\mathsf{T}}{\sqrt{d_k}}+M
\right)V.
$$

符号含义：

| 符号 | 含义 |
| --- | --- |
| $QK^\mathsf{T}$ | 所有 Query 与所有 Key 的两两点积 |
| $d_k$ | 每个 Key 的 Feature 宽度 |
| $\sqrt{d_k}$ | 分数缩放因子 |
| $M$ | mask 加到分数上的附加项 |
| Softmax | 沿 Key 维度把每行变成权重 |

若 $Q$ 形状为 $(N,L_q,d_k)$，$K$ 为 $(N,L_k,d_k)$，则：

$$
QK^\mathsf{T}:(N,L_q,L_k).
$$

再与 $V:(N,L_k,d_v)$ 相乘，输出为：

$$
O:(N,L_q,d_v).
$$

除以 $\sqrt{d_k}$ 是为了在 Feature 较宽时控制点积分数的尺度，避免 Softmax 很早就变得过于尖锐。

> [!NOTE] Softmax 沿哪个维度很关键
> 每个 Query 都要在全部 Key 之间分配权重，因此 Softmax 沿最后的 Key 维度进行。若误沿 Query 维度计算，得到的权重含义会变化。

### 10.4 Additive Attention：加性注意力

加性注意力先把 Query 与 Key 分别做线性变换，再相加并使用非线性函数：

$$
e_{ij}=v_a^\mathsf{T}
\tanh(W_qq_i+W_kk_j+b_a),
$$

$$
\alpha_{ij}
=\frac{\exp(e_{ij})}
{\sum_m\exp(e_{im})},
\qquad
o_i=\sum_j\alpha_{ij}v_j.
$$

其中：

- $W_q$ 与 $W_k$ 把 Query 和 Key 转成相同宽度；
- $b_a$ 是偏置；
- $v_a$ 把中间向量变成一个标量分数；
- $e_{ij}$ 是未归一化分数；
- $\alpha_{ij}$ 是最终权重。

#### 一维中间特征的数字例子

令：

$$
q=1,\quad k_1=0,\quad k_2=2,
$$

$$
W_q=1,\quad W_k=0.5,\quad b_a=0,\quad v_a=1.
$$

则：

$$
e_1=\tanh(1+0.5\times0)=\tanh(1)\approx0.762,
$$

$$
e_2=\tanh(1+0.5\times2)=\tanh(2)\approx0.964.
$$

Softmax 后约为：

$$
[\alpha_1,\alpha_2]\approx[0.450,0.550].
$$

若 $v_1=3,v_2=7$：

$$
o=0.450\times3+0.550\times7=5.2.
$$

| 计算 | PyTorch 常见方式 | Keras 常见 Layer |
| --- | --- | --- |
| 简单点积 | 张量乘法或 `scaled_dot_product_attention` | `Dot`、`Attention` |
| 加性注意力 | 组合 `Linear`、加法和激活 | `AdditiveAttention` |
| 多头注意力 | `MultiheadAttention` | `MultiHeadAttention` |

### 10.5 Multi-Head Attention：为什么要分多个 Head

设模型宽度为 $E$，Head 数为 $h$，每个 Head 宽度为：

$$
d_h=\frac{E}{h}.
$$

通常要求 $E$ 能被 $h$ 整除。第 $r$ 个 Head 为：

$$
\operatorname{head}_r
=\operatorname{Attention}(Q_r,K_r,V_r).
$$

多个 Head 拼接后再做输出投影：

$$
\operatorname{MHA}
=\operatorname{Concat}
(\operatorname{head}_1,\ldots,\operatorname{head}_h)W_O.
$$

若 $N=2,L=5,E=12,h=3$，则 $d_h=4$：

| 阶段 | 形状 |
| --- | --- |
| 输入 | $(2,5,12)$ |
| 拆分后的 Q、K、V | $(2,3,5,4)$ |
| 每个 Head 的分数 | $(2,3,5,5)$ |
| 每个 Head 的输出 | $(2,3,5,4)$ |
| 拼接 | $(2,5,12)$ |
| 输出投影后 | $(2,5,12)$ |

> [!NOTE] Head 数增加不一定增加最终宽度
> 在常见设置中，总宽度 $E$ 固定。Head 数从 3 增加到 6 时，每个 Head 的宽度从 4 降为 2，拼接后仍是 12。

不同 Head 使用不同参数，可以学习关注不同关系。例如在句子“猫坐在垫子上，因为它很柔软”中，一个 Head 可能强调“它”与“垫子”，另一个 Head 可能强调“柔软”与描述对象，还有一个 Head 可能更关注相邻词。

### 10.6 mask：补齐遮罩、因果遮罩与交叉注意力遮罩

注意力分数矩阵形状为 $(N,h,L_q,L_k)$。mask 的目标是在 Softmax 前禁止某些 Query-Key 组合。浮点形式通常让允许位置加 0，让禁止位置加负无穷：

$$
\operatorname{Softmax}([2,1,-\infty])
=
\left[
\frac{e^2}{e^2+e^1},
\frac{e^1}{e^2+e^1},
0
\right].
$$

| mask 类型 | 典型形状 | 作用 |
| --- | --- | --- |
| padding mask | $(N,L_k)$ | 每个样本禁止读取 PAD Key |
| 二维注意力 mask | $(L_q,L_k)$ | 所有样本与 Head 共用 |
| 每 Head 独立 mask | 与 $(N,h,L_q,L_k)$ 信息相容 | 每个样本、每个 Head 分别指定 |
| 因果 mask | $(L,L)$ | 禁止位置 $i$ 读取未来位置 $j>i$ |

长度 4 的因果允许表为：

$$
\begin{bmatrix}
1&0&0&0\\
1&1&0&0\\
1&1&1&0\\
1&1&1&1
\end{bmatrix}.
$$

第 0 个位置只能读取自己；第 1 个位置可读取位置 0 和 1；最后一个位置可读取全部位置。

> [!WARNING] 布尔值含义要按具体接口确认
> PyTorch `MultiheadAttention` 的布尔 mask 中，`True` 通常表示禁止；Keras `MultiHeadAttention` 的布尔 attention mask 中，允许位置通常写为 1 或 `True`。两个框架的布尔含义容易相反。

> [!WARNING] padding mask 主要遮住 Key 列
> 一个 PAD Key 被遮住后，所有 Query 都不会读取它；PAD Query 对应的输出行不一定自动变成零。后续做池化或计算逐 token 损失时，还要再次排除 PAD Query。

若某一行所有 Key 都被禁止，Softmax 没有可分配权重的位置，结果可能产生非有限数。每个样本应至少保留一个有效 token。

### 10.7 Transformer Encoder Layer 的两个子层

一个基础 Encoder Layer 通常含两个子层：

1. Multi-Head Self-Attention；
2. 逐位置前馈网络。

每个子层外还包含残差相加、Dropout 和 Layer Normalization。逐位置前馈网络为：

$$
\operatorname{FFN}(x)
=W_2\phi(W_1x+b_1)+b_2.
$$

其中：

- 输入与输出宽度为 $E$；
- 中间宽度为 $F$，常大于 $E$；
- $W_1$ 把 $E$ 维变成 $F$ 维；
- $\phi$ 常为 ReLU 或 GELU；
- $W_2$ 再把 $F$ 维变回 $E$ 维；
- 每个 token 独立使用同一组 FFN 参数。

若输入为 $(N,L,E)=(2,6,16)$，Head 数为 4，中间宽度 $F=64$：

| 阶段 | 形状 |
| --- | --- |
| Layer 输入 | $(2,6,16)$ |
| Self-Attention 输出 | $(2,6,16)$ |
| 第一次残差与归一化 | $(2,6,16)$ |
| FFN 第一层 | $(2,6,64)$ |
| FFN 第二层 | $(2,6,16)$ |
| 第二次残差与归一化 | $(2,6,16)$ |

残差相加要求两侧形状相同，因此注意力输出和 FFN 最终输出都要回到 $E$ 维。

Post-Norm 可写为：

$$
z=\operatorname{LN}
\left(x+\operatorname{Dropout}(\operatorname{MHA}(x))\right),
$$

$$
y=\operatorname{LN}
\left(z+\operatorname{Dropout}(\operatorname{FFN}(z))\right).
$$

Pre-Norm 则先归一化：

$$
z=x+\operatorname{Dropout}(\operatorname{MHA}(\operatorname{LN}(x))),
$$

$$
y=z+\operatorname{Dropout}(\operatorname{FFN}(\operatorname{LN}(z))).
$$

> [!NOTE] 残差相加不是拼接
> 相加后形状仍为 $(N,L,E)$；拼接会增加 Feature宽度。Transformer 的标准残差使用逐元素相加。

### 10.8 Decoder 与交叉注意力

Transformer Decoder Layer 通常依次包含：

1. 带因果 mask 的目标自注意力；
2. 目标对 Encoder 输出的交叉注意力；
3. 逐位置 FFN。

设目标长度为 $L_t$，源序列长度为 $L_s$，模型宽度为 $E$：

| 注意力 | Query | Key、Value | 权重形状 |
| --- | --- | --- | --- |
| 目标自注意力 | $(N,L_t,E)$ | $(N,L_t,E)$ | $(N,h,L_t,L_t)$ |
| 交叉注意力 | $(N,L_t,E)$ | $(N,L_s,E)$ | $(N,h,L_t,L_s)$ |

交叉注意力中，每个目标位置都可以从源序列的全部有效位置读取信息。机器翻译时，生成目标语言当前 token 的 Query 会对源语言各 token 的 Key 分配权重，再汇总它们的 Value。

### 10.9 位置编码为什么必不可少

自注意力仅根据内容计算时，并不会天然知道 token 的先后位置。句子“狗追人”和“人追狗”包含相同 token 集合，但次序改变了含义。位置编码给每个位置加入不同信息。

经典正弦与余弦位置编码为：

$$
PE(pos,2i)
=
\sin\left(
\frac{pos}{10000^{2i/E}}
\right),
$$

$$
PE(pos,2i+1)
=
\cos\left(
\frac{pos}{10000^{2i/E}}
\right).
$$

其中：

| 符号 | 含义 |
| --- | --- |
| $pos$ | token 的位置编号，从 0 开始 |
| $i$ | 正弦、余弦频率组编号 |
| $E$ | 模型 Feature 宽度 |
| $2i$ | 偶数 Feature位置 |
| $2i+1$ | 奇数 Feature位置 |

令 $E=4,pos=1$。当 $i=0$：

$$
PE(1,0)=\sin(1)\approx0.8415,
$$

$$
PE(1,1)=\cos(1)\approx0.5403.
$$

当 $i=1$：

$$
10000^{2/4}=100,
$$

$$
PE(1,2)=\sin(0.01)\approx0.0100,
$$

$$
PE(1,3)=\cos(0.01)\approx0.99995.
$$

所以位置 1 的四维编码约为：

$$
[0.8415,0.5403,0.0100,0.99995].
$$

若某 token 向量为：

$$
[0.2,-0.1,0.4,0.3],
$$

相加后为：

$$
[1.0415,0.4403,0.4100,1.29995].
$$

> [!NOTE] 位置编码与 token 向量是相加，不是替换
> 相加后的每个位置同时含有内容信息和位置信息。两者都必须具有相同的 Feature宽度 $E$。

可学习位置参数与正弦位置编码都很常见。可学习方式把每个位置当作一行参数；正弦方式由固定公式产生，不需要训练参数。

### 10.10 PyTorch 与 Keras 的 Transformer 名称对照

| 需求 | PyTorch | Keras |
| --- | --- | --- |
| 多头注意力 | `MultiheadAttention` | `MultiHeadAttention` |
| 完整 Encoder 子层 | `TransformerEncoderLayer` | 常由 `MultiHeadAttention`、`Dense`、`LayerNormalization` 组合 |
| 多层 Encoder | `TransformerEncoder` | 通常叠放自定义 Encoder Layer |
| 完整 Decoder 子层 | `TransformerDecoderLayer` | 通常由两个注意力子层、FFN 与归一化组合 |
| 完整 Encoder-Decoder | `Transformer` | 通常由多个基础 Layer 组合 |
| Layer Normalization | `LayerNorm` | `LayerNormalization` |

> [!IMPORTANT] Transformer Layer 不负责文本预处理
> 分词、词表编号、Embedding、位置编码、补齐 mask、输出词表分类层和损失函数通常需要在 Layer 外组织。输入整数编号不能直接交给只接收连续 Feature 的 Encoder Layer。

---

## 11. 损失函数：回归、分类、分布、序列与度量学习

损失函数把模型输出与监督目标比较，产生用于更新参数的数值。先算每个样本或每个位置的损失，再根据 `reduction` 规则组合。

### 11.1 `reduction` 的三种方式

假设三个位置的未归约损失是：

$$
\ell=[0.2,0.5,0.8].
$$

则：

$$
\operatorname{none}=[0.2,0.5,0.8],
$$

$$
\operatorname{sum}=0.2+0.5+0.8=1.5,
$$

$$
\operatorname{mean}=\frac{1.5}{3}=0.5.
$$

| PyTorch | Keras | 含义 |
| --- | --- | --- |
| `reduction="none"` | `reduction="none"` | 保留逐样本或逐位置损失 |
| `reduction="sum"` | `reduction="sum"` | 求和 |
| `reduction="mean"` | `sum_over_batch_size` 等设置 | 按相应规则求平均 |

> [!WARNING] “平均”的分母要结合具体损失
> 普通平方误差常按元素数平均；带类别权重的交叉熵会考虑有效标签对应的权重；忽略 PAD 后只应统计有效 token。不要只看到 `mean` 就假定分母一定是 Batch Size。

### 11.2 回归损失：L1、MSE、Huber 与 Smooth L1

#### L1 Loss

$$
\ell=|x-y|.
$$

$x$ 是预测，$y$ 是连续目标。若 $x=3.5,y=2$：

$$
\ell=|3.5-2|=1.5.
$$

#### MSE Loss

$$
\ell=(x-y)^2.
$$

同一例子得到：

$$
\ell=(3.5-2)^2=2.25.
$$

误差从 1 增加到 2 时，L1 从 1 增加到 2，MSE 从 1 增加到 4。因此 MSE 对较大误差给出更强影响。

#### Huber Loss

误差记为 $e=x-y$，阈值为 $\delta$：

$$
\ell(e)=
\begin{cases}
\frac12e^2,&|e|\le\delta,\\
\delta(|e|-\frac12\delta),&|e|>\delta.
\end{cases}
$$

令 $\delta=1$：

- $e=0.4$ 时，$\ell=0.5\times0.4^2=0.08$；
- $e=3$ 时，$\ell=1\times(3-0.5)=2.5$。

小误差使用平方形式，大误差使用线性增长形式。

| 数学类别 | PyTorch | Keras |
| --- | --- | --- |
| 绝对误差 | `L1Loss` | `MeanAbsoluteError` |
| 平方误差 | `MSELoss` | `MeanSquaredError` |
| Huber | `HuberLoss` | `Huber` |
| Smooth L1 | `SmoothL1Loss` | 可按分段公式自定义或选择相近损失 |

> [!TIP] 回归任务先确认输出单位
> 若目标数值从几百到几万，而模型输出初始值接近 0，平方误差会很大。常见处理包括对输入和目标做合理尺度调整，并在解释预测时还原原始单位。

### 11.3 二值分类与多标签分类

二值交叉熵为：

$$
\ell=-\left[
y\log p+(1-y)\log(1-p)
\right].
$$

其中 $y\in\{0,1\}$ 是目标，$p\in(0,1)$ 是预测为正类的概率。

若 $y=1,p=0.8$：

$$
\ell=-\log(0.8)\approx0.223.
$$

若仍为正类，但 $p=0.1$：

$$
\ell=-\log(0.1)\approx2.303.
$$

错误且很自信的预测得到更大损失。

模型常直接输出 logit $z$，概率为：

$$
p=\sigma(z)=\frac{1}{1+e^{-z}}.
$$

PyTorch `BCEWithLogitsLoss` 将 Sigmoid 和二值交叉熵合在一起；Keras `BinaryCrossentropy` 接收 logits 时使用 `from_logits=True`。

> [!IMPORTANT] logits 不是概率
> logit 可以是任意实数，例如 $-3、0、2.5$。Sigmoid 后才进入 $(0,1)$。使用带 logits 的稳定损失时，模型末尾无需再添加 Sigmoid。

多标签任务中，一个样本可同时属于多个类别。例如图片可以同时含“汽车”“道路”“树木”。目标可能是：

$$
y=[1,1,0],
$$

模型输出三个独立 logits，每一类都计算一次二值交叉熵。它不同于只能选择一个类别的多类别分类。

类别正样本较少时，PyTorch 可用 `pos_weight` 调整正标签项；Keras 可通过样本权重、类别权重或自定义组合实现相应调整。权重应根据训练数据统计，并清楚说明采用的计算方式。

### 11.4 多类别交叉熵

设模型对 $C$ 个类别输出 logits：

$$
x=[x_1,x_2,\ldots,x_C].
$$

Softmax 概率为：

$$
p_c=\frac{e^{x_c}}{\sum_{j=1}^{C}e^{x_j}}.
$$

若正确类别编号为 $y$：

$$
\ell=-\log p_y.
$$

#### 三类别逐步例子

设：

$$
x=[2,1,0],
$$

正确类别是第 0 类。为提高数值稳定性，可先减去最大值 2：

$$
x'=[0,-1,-2].
$$

指数约为：

$$
[e^0,e^{-1},e^{-2}]
\approx[1,0.3679,0.1353].
$$

总和为：

$$
1+0.3679+0.1353=1.5032.
$$

第 0 类概率：

$$
p_0=\frac{1}{1.5032}\approx0.6652.
$$

损失：

$$
\ell=-\log(0.6652)\approx0.4076.
$$

> [!WARNING] 不要在稳定交叉熵前重复做 Softmax
> PyTorch `CrossEntropyLoss` 直接接收 logits。Keras `SparseCategoricalCrossentropy(from_logits=True)` 也直接接收 logits。先手工 Softmax 再传入，会改变损失接收的数据含义。

标签有两种常见形式：

| 标签形式 | 例子 | PyTorch | Keras |
| --- | --- | --- | --- |
| 整数类别编号 | `2` | `CrossEntropyLoss` | `SparseCategoricalCrossentropy` |
| one-hot 或概率分布 | `[0,0,1]` | `CrossEntropyLoss` 可接收同形概率目标 | `CategoricalCrossentropy` |

#### 类别权重与忽略位置

类别权重 $w_c$ 会调整目标属于类别 $c$ 时的损失：

$$
\ell=-w_y\log p_y.
$$

序列任务中，PAD 位置不应作为真实类别训练。PyTorch `ignore_index` 可指定被忽略的整数标签；Keras 常通过 mask 或 sample weight 让 PAD 位置权重为 0。

假设目标为：

$$
[4,2,7,0,0],
$$

其中 0 是 PAD。有效位置数是 3，前 3 项参与损失，后 2 项不参与。若三个有效损失为 $[0.3,0.6,0.9]$，平均应为：

$$
\frac{0.3+0.6+0.9}{3}=0.6,
$$

而不是除以总长度 5 得到 0.36。

> [!WARNING] 全部位置都是 PAD 时要单独处理
> 此时没有有效目标，直接求平均可能得到非有限值或无意义结果。整理 Batch 时应保证至少一个有效目标，或跳过该 Batch。

### 11.5 概率分布损失：KL Divergence

KL Divergence 比较两个概率分布。令目标分布为 $q$，模型分布为 $p$：

$$
D_{KL}(q\Vert p)
=\sum_i q_i\log\frac{q_i}{p_i}
=\sum_i q_i(\log q_i-\log p_i).
$$

若：

$$
q=[0.5,0.5],\qquad p=[0.8,0.2],
$$

则：

$$
D_{KL}
=0.5\log\frac{0.5}{0.8}
+0.5\log\frac{0.5}{0.2}.
$$

取自然对数：

$$
\log(0.625)\approx-0.4700,\qquad
\log(2.5)\approx0.9163,
$$

所以：

$$
D_{KL}\approx0.5(-0.4700)+0.5(0.9163)
\approx0.2232.
$$

KL Divergence 不具有交换对称性，一般有：

$$
D_{KL}(q\Vert p)\ne D_{KL}(p\Vert q).
$$

PyTorch `KLDivLoss` 常接收模型对数概率和目标概率；Keras 提供 `KLDivergence`。使用前必须确认输入是概率还是对数概率。

### 11.6 序列损失：逐 token 交叉熵与 CTC

语言模型输出形状常为：

$$
\text{logits}:(N,L,V),
$$

其中 $V$ 是词表大小。目标编号为：

$$
\text{target}:(N,L).
$$

每个有效位置独立计算一次 $V$ 类交叉熵，再排除 PAD 并按有效 token 组合。

生成任务会把输入与目标错开。例如完整序列：

```text
[BOS] 我 喜欢 音乐 [EOS]
```

训练输入：

```text
[BOS] 我 喜欢 音乐
```

监督目标：

```text
我 喜欢 音乐 [EOS]
```

CTC 用于输入时间位置与目标标签没有逐位置对齐信息的任务。其损失为：

$$
\mathcal L_{CTC}
=-\log
\sum_{\pi\in\mathcal B^{-1}(y)}
\prod_{t=1}^{T}p(\pi_t\mid x_t).
$$

其中：

| 符号 | 含义 |
| --- | --- |
| $T$ | 输入时间位置数量 |
| $y$ | 最终目标标签序列 |
| $\pi$ | 一条逐时间位置路径 |
| $\mathcal B$ | 删除 blank 并合并连续重复标签的操作 |
| $\mathcal B^{-1}(y)$ | 所有能得到目标 $y$ 的路径集合 |

令 blank 为 0，$A=1,B=2$，目标为 $[A,B]$，时间长度为 3。以下路径都可得到 $[A,B]$：

$$
[A,A,B],\quad[A,0,B],\quad[0,A,B],\quad[A,B,B].
$$

CTC 会把这些有效路径的概率相加，而不是要求事先说明 $A$、$B$ 分别出现在哪一帧。

| 任务 | PyTorch | Keras |
| --- | --- | --- |
| 逐 token 分类 | `CrossEntropyLoss` | `SparseCategoricalCrossentropy` |
| 无逐位置对齐的序列 | `CTCLoss` | `ctc_loss` 等 CTC 接口 |

### 11.7 相似度、排序与度量学习

#### Cosine Similarity

$$
\cos(x_1,x_2)
=
\frac{x_1\cdot x_2}
{\lVert x_1\rVert_2\lVert x_2\rVert_2}.
$$

令：

$$
x_1=[1,0],\qquad x_2=[1,1].
$$

点积为 1，范数分别为 1 和 $\sqrt2$：

$$
\cos(x_1,x_2)=\frac{1}{\sqrt2}\approx0.7071.
$$

Cosine 更关注方向，不直接关注向量长度。

#### Pairwise Distance

欧氏距离为：

$$
d(x_1,x_2)
=\sqrt{\sum_i(x_{1,i}-x_{2,i})^2}.
$$

对上例：

$$
d=\sqrt{(1-1)^2+(0-1)^2}=1.
$$

#### Triplet Margin Loss

三元组由 Anchor $a$、Positive $p$、Negative $n$ 组成：

$$
\ell=
\max
\left(
d(a,p)-d(a,n)+m,
0
\right).
$$

$m$ 是期望保留的距离间隔。若：

$$
d(a,p)=0.4,\quad d(a,n)=1.1,\quad m=0.5,
$$

则：

$$
\ell=\max(0.4-1.1+0.5,0)=0.
$$

若负样本距离变为 0.6：

$$
\ell=\max(0.4-0.6+0.5,0)=0.3.
$$

第二种情况说明负样本还不够远。

| 需求 | PyTorch | Keras 常见方式 |
| --- | --- | --- |
| 余弦相似度 | `CosineSimilarity` | `Dot` 配合归一化，或相应相似度函数 |
| 成对距离 | `PairwiseDistance` | 距离函数或自定义 Layer |
| 三元组间隔 | `TripletMarginLoss` | 自定义损失或相关扩展接口 |
| 排序 | `MarginRankingLoss` | 自定义损失 |

> [!NOTE] 相似度和距离方向相反
> 余弦相似度越大通常表示方向越接近；欧氏距离越小通常表示位置越接近。把相似度直接当距离使用时，要先处理符号和目标方向。

---

## 12. 组合选型与完整计算例子

本章把前面的 Layer 放入具体任务。重点不是给出唯一结构，而是说明怎样从输入形状、任务目标和监督形式逐步选择。

### 12.1 序列 Layer 的选择参考

| 数据与目标 | 可优先考虑 | 原因 |
| --- | --- | --- |
| 短序列、结构简单、希望参数较少 | SimpleRNN / RNN | 公式简单，计算量相对较小 |
| 中长序列，希望使用门控且结构较简洁 | GRU | 两类主要门，状态只有一组 |
| 希望分别维护内部记忆和对外状态 | LSTM | 使用 $c_t$ 与 $h_t$ |
| 每个位置可同时利用前后内容 | 双向 GRU / LSTM | 正向和反向结果拼接 |
| 生成任务，当前位置不能看未来 | 单向 RNN 或带因果 mask 的 Transformer | 保持生成次序 |
| 很长序列且需要位置间直接交互 | Attention / Transformer | 任意两个位置可直接计算相关程度 |
| 输入时间与目标标签未对齐 | CTC 配合序列模型 | 对多条有效路径求和 |

> [!WARNING] 双向结构不适合所有生成场景
> 双向网络在计算某位置时会利用未来输入。若任务要求逐步生成且未来内容尚不存在，就不能直接使用未来方向的信息。

### 12.2 自然语言分类：Embedding、双向 GRU、注意力和交叉熵

考虑情感分类句子：

```text
这 部 电影 很 精彩
```

设词表编号为：

| token | 编号 |
| --- | --- |
| `[PAD]` | 0 |
| 这 | 4 |
| 部 | 7 |
| 电影 | 12 |
| 很 | 9 |
| 精彩 | 18 |

句子编号为：

$$
[4,7,12,9,18].
$$

同一 Batch 的统一长度为 7，补齐后：

$$
[4,7,12,9,18,0,0].
$$

假设：

$$
N=8,\quad L=7,\quad V=1000,\quad
E=32,\quad H=24.
$$

#### 第一步：Embedding

Embedding 参数形状：

$$
(V,E)=(1000,32).
$$

输入形状：

$$
(N,L)=(8,7).
$$

查表后：

$$
(8,7)\rightarrow(8,7,32).
$$

每个 token 现在由 32 个连续数表示。

#### 第二步：双向 GRU

正向 GRU 从“这”读到“精彩”，反向 GRU 从“精彩”读到“这”。每个方向隐藏宽度为 24：

$$
(8,7,32)\rightarrow(8,7,48).
$$

这里 48 来自：

$$
24_{\text{正向}}+24_{\text{反向}}=48.
$$

补齐长度为 7，但真实长度是 5。应通过打包序列或 mask 告知 Layer，避免把最后两个 PAD 当成真实 token。

#### 第三步：对七个位置计算注意力

设每个位置产生一个标量分数：

$$
e_t=v^\mathsf{T}\tanh(Wh_t+b).
$$

假设某样本五个有效位置的分数为：

$$
[0.2,0.1,0.8,0.3,1.4].
$$

两个 PAD 位置加负无穷：

$$
[0.2,0.1,0.8,0.3,1.4,-\infty,-\infty].
$$

有效部分指数约为：

$$
[1.221,1.105,2.226,1.350,4.055].
$$

总和：

$$
1.221+1.105+2.226+1.350+4.055=9.957.
$$

权重约为：

$$
[0.123,0.111,0.224,0.136,0.407,0,0].
$$

“精彩”获得最大权重 0.407，但其他位置仍参与句子表示。句子向量为：

$$
s=\sum_{t=1}^{7}\alpha_t h_t,
$$

形状从 $(7,48)$ 变成 $(48)$。整个 Batch 得到 $(8,48)$。

#### 第四步：分类层

假设分为正面、负面、中性三类：

$$
(8,48)\rightarrow(8,3).
$$

某个样本 logits 为：

$$
[2.0,-0.5,0.3].
$$

正确类别为正面，也就是编号 0。减去最大值后：

$$
[0,-2.5,-1.7].
$$

指数约为：

$$
[1,0.0821,0.1827],
$$

正确类概率为：

$$
\frac{1}{1+0.0821+0.1827}\approx0.7906.
$$

交叉熵为：

$$
-\log(0.7906)\approx0.2349.
$$

#### 全部形状汇总

| 阶段 | 形状 |
| --- | --- |
| token 编号 | $(8,7)$ |
| Embedding | $(8,7,32)$ |
| 双向 GRU | $(8,7,48)$ |
| 注意力分数 | $(8,7)$ |
| 注意力权重 | $(8,7)$ |
| 加权句子向量 | $(8,48)$ |
| 三分类 logits | $(8,3)$ |
| 每样本交叉熵 | $(8)$ |
| 平均损失 | 标量 |

> [!TIP] 先检查注意力权重的两个性质
> 每个 PAD 位置权重应为 0；每个样本所有有效位置权重之和应接近 1。这两项很适合用于检查 mask 是否正确。

### 12.3 时间序列预测：滑动窗口、LSTM 与 Huber Loss

假设每小时记录温度、湿度和风速三个 Feature，希望使用过去 6 小时预测下一小时温度。

单个样本输入形状：

$$
(L,I)=(6,3).
$$

Batch Size 为 32：

$$
(N,L,I)=(32,6,3).
$$

使用两层单向 LSTM，隐藏宽度 $H=16$：

$$
output:(32,6,16),
$$

$$
h_n:(2,32,16),\qquad
c_n:(2,32,16).
$$

选择最高层最终隐藏状态：

$$
h_{\text{final}}:(32,16).
$$

再使用一个输出宽度为 1 的全连接 Layer：

$$
(32,16)\rightarrow(32,1).
$$

目标下一小时温度形状也是 $(32,1)$。

#### 一个样本的损失计算

若真实温度为 $20.0$，预测为 $22.5$，误差：

$$
e=22.5-20.0=2.5.
$$

MSE 为：

$$
e^2=6.25.
$$

L1 为：

$$
|e|=2.5.
$$

Huber 取 $\delta=1$：

$$
\ell=1\times(2.5-0.5)=2.0.
$$

若预测改为 20.4，误差为 0.4：

$$
\ell_{\text{Huber}}=\frac12\times0.4^2=0.08.
$$

> [!NOTE] 时间 Feature 的单位可能差异很大
> 温度可能在几十范围，湿度可能写成 0 到 100，风速又可能只有个位数。若直接输入，数值较大的 Feature 可能产生更大的线性响应。常先用训练数据统计每个 Feature 的均值与标准差，再进行标准化。

#### 滑动窗口不能混入未来数据

预测第 7 小时时，输入只能使用第 1 至第 6 小时；预测第 8 小时时，可使用第 2 至第 7 小时。训练集和验证集应按时间先后划分，再分别构造窗口。若先在完整时间序列上随机拆分窗口，训练数据可能包含验证时段附近甚至之后的信息。

> [!WARNING] 双向 LSTM 要结合任务时间条件
> 若对一段已经完整获得的历史数据做整体分类，双向结构可以使用前后内容。若在线预测下一时刻，输入中不存在未来观测，不能让模型读取尚未发生的数据。

### 12.4 Transformer 生成：输入准备、因果注意力与逐 token 损失

设目标句子为：

```text
[BOS] 我 喜欢 学习 [EOS]
```

编号后为：

$$
[1,5,8,11,2].
$$

训练时：

$$
\text{Decoder输入}=[1,5,8,11],
$$

$$
\text{监督目标}=[5,8,11,2].
$$

假设 Batch Size 为 4，目标输入长度为 4，模型宽度为 32，词表大小为 500：

| 阶段 | 形状 |
| --- | --- |
| 目标编号 | $(4,4)$ |
| token 与位置向量相加 | $(4,4,32)$ |
| 因果自注意力权重 | $(4,h,4,4)$ |
| Decoder 输出 | $(4,4,32)$ |
| 词表分类 logits | $(4,4,500)$ |
| 目标编号 | $(4,4)$ |
| 逐 token 损失 | $(4,4)$ |

位置 0 读取范围为位置 0；位置 1 可读取 0、1；位置 2 可读取 0、1、2；位置 3 可读取全部四个输入位置。

若某个样本实际只有：

```text
[BOS] 好 [EOS] [PAD]
```

则还要使用 padding mask 禁止读取 PAD，并在损失中忽略 PAD 目标。因果 mask 负责“不能看未来”，padding mask 负责“不能读取补齐内容”，二者解决不同问题。

> [!EXAMPLE] 第一个预测位置在学什么
> Decoder 输入位置 0 是 `[BOS]`，监督目标位置 0 是“我”。因果 mask 使这个位置只能读取 `[BOS]`，然后词表分类层应给“我”较高得分。

> [!EXAMPLE] 第三个预测位置在学什么
> Decoder 输入前 3 个位置是 `[BOS] 我 喜欢`，对应目标是“学习”。该位置可以读取此前三个输入，但不能提前读取 Decoder 输入中的后续位置。

### 12.5 损失与输出 Layer 的配对速查

| 任务 | 模型最后输出 | 目标形式 | 常见损失 |
| --- | --- | --- | --- |
| 单值回归 | 任意实数 | 浮点数 | MSE、L1、Huber |
| 二值分类 | 一个 logit | 0/1 浮点目标 | 带 logits 的二值交叉熵 |
| 单标签多类别 | $C$ 个 logits | 整数类别编号 | 多类别交叉熵 |
| 多标签分类 | $C$ 个独立 logits | $C$ 维 0/1 浮点目标 | 逐类二值交叉熵 |
| 逐 token 分类 | 每个位置 $V$ 个 logits | 每位置整数编号 | 忽略 PAD 的交叉熵 |
| 未对齐序列识别 | 每帧含 blank 的类别概率 | 较短标签序列与长度 | CTC |
| 表示相似性学习 | 向量表示 | 成对或三元组关系 | Cosine、Triplet 等 |

### 12.6 组合 Layer 时的逐项检查

> [!CHECK] 输入
> Batch维度在哪里？序列长度是多少？每个位置的 Feature宽度是多少？整数编号是否先经过 Embedding？PAD 编号是否统一？

> [!CHECK] 循环状态
> 是单向还是双向？有几层？最终状态第 0 维是否按“层数乘方向数”组织？LSTM 是否同时处理 $h$ 和 $c$？

> [!CHECK] 注意力
> Query 长度和 Key 长度分别是多少？Softmax 是否沿 Key 维度？权重形状是否包含 Head？PAD 权重是否为 0？因果任务是否禁止读取未来？

> [!CHECK] Transformer 输入
> token 向量与位置编码是否同形？模型宽度能否被 Head 数整除？残差两侧形状是否一致？补齐 mask 与因果 mask 是否各自正确？

> [!CHECK] 损失
> 模型输出是 logits、概率还是对数概率？目标是整数编号、one-hot、连续值还是序列？PAD 是否排除？`reduction` 的分母是什么？类别权重位于哪个设备？

> [!TIP] 复杂模型先写形状，再算一个位置
> 先从输入到输出列出每一步形状，再选择一个样本、一个时间位置或一个 Head 完成数字计算。这样更容易发现 Feature维度、序列维度和类别维度是否放错。

---

## 13. 同一计算在两个框架中的常见差异

### 13.1 参数名称不同，数学含义相同

| 数学含义 | PyTorch 常见参数名 | Keras 常见参数名 |
| --- | --- | --- |
| 输出特征数 | `out_features` | `units` |
| 输出通道数 | `out_channels` | `filters` |
| 步幅 | `stride` | `strides` |
| 膨胀系数 | `dilation` | `dilation_rate` |
| 是否使用偏置 | `bias` | `use_bias` |
| 激活函数 | 常作为独立 Layer | 常可写在 Layer 的 `activation` 参数中 |
| 通道排列 | 由 Layer 类型和输入约定决定 | 常由 `data_format` 指定 |
| 训练状态 | `train()` 与 `eval()` | 调用时的 `training` 状态 |

例如，全连接 Layer 的核心都是：

$$
y=xW+b.
$$

PyTorch 更常把激活写成下一个独立 Layer；Keras 常允许 `Dense` 或 `Conv2D` 直接接收 `activation`。如果激活函数相同，两种写法在数学上等价。

### 13.2 权重矩阵的保存次序可能不同

假设输入宽度为 $I$，输出宽度为 $O$：

- PyTorch `Linear` 常把权重保存为 $(O,I)$，公式写作 $xW^T+b$；
- Keras `Dense` 常把 kernel 保存为 $(I,O)$，公式写作 $xW+b$。

两者都为每个输出计算 $I$ 个输入的加权和。差异来自参数数组的轴次序，不是计算能力差异。

> [!EXAMPLE] 同一组权重的转置关系
> 若 PyTorch 权重为 $\begin{bmatrix}1&2\\3&4\end{bmatrix}$，把参数交给使用 $(I,O)$ 次序的 Layer 时通常需要转置。仅复制数字而不检查形状，可能让输出含义变化。

### 13.3 图像的 channels-first 与 channels-last

对 8 张 $32\times32$ RGB 图像：

- PyTorch 常见形状为 `(8,3,32,32)`；
- Keras 默认常见形状为 `(8,32,32,3)`。

若卷积产生 16 个输出通道，形状分别常写成：

- PyTorch：`(8,16,H_out,W_out)`；
- Keras：`(8,H_out,W_out,16)`。

卷积的每个输出数值仍来自相同的局部乘加公式。只有存放次序发生变化。

### 13.4 RNN 输出规则需要单独核对

PyTorch RNN 家族通常同时返回全部时间位置的输出和最终状态；Keras RNN 家族是否返回完整序列、最终状态，由 `return_sequences` 与 `return_state` 等参数决定。

| 目标 | PyTorch 常见结果 | Keras 常见设置 |
| --- | --- | --- |
| 取得每个时间位置 | 使用 `output` | `return_sequences=True` |
| 只取得最终输出 | 从状态或输出中选择 | `return_sequences=False` |
| 取得内部状态 | 使用 `h_n`，LSTM 还使用 `c_n` | `return_state=True` |
| 双向输出 | `bidirectional=True` | `Bidirectional` 包装 |

> [!WARNING] 双向 RNN 的“最后一个位置”不等于两个方向的最终状态
> 正向读取顺序和反向读取顺序相反。要获得两个方向各自读完整条序列后的状态，应查看框架返回的最终状态及其方向次序，而不是机械地选择输出序列的最后一个位置。

### 13.5 分类损失是否接收 logits

logits 是模型最后一层产生的任意实数得分，还不是概率。

- PyTorch `CrossEntropyLoss` 直接接收 logits；
- Keras `CategoricalCrossentropy` 或 `SparseCategoricalCrossentropy` 在接收 logits 时，应启用 `from_logits=True`；
- 二值任务中，PyTorch 常用 `BCEWithLogitsLoss`；
- Keras `BinaryCrossentropy` 接收 logits 时同样应设置 `from_logits=True`。

> [!IMPORTANT] 不要重复使用 Softmax 或 Sigmoid
> 若损失函数已经按 logits 计算稳定形式，模型输出端就不应先做同类概率函数。重复处理会改变损失所看到的数值关系。

---

## 14. 从输入到损失：一个完整的计算阅读例子

考虑一个简化图像分类器：

```text
图像
→ 二维卷积
→ Batch Normalization
→ ReLU
→ 最大池化
→ 二维卷积
→ ReLU
→ 全局平均池化
→ 全连接
→ 多类别交叉熵
```

这里的框图只表示 Layer 次序，不是 Python 代码。

设输入为 8 张 RGB 图像，形状在 PyTorch 风格下为 `(8,3,32,32)`。第一层使用 16 个 $3\times3$ 卷积核，stride 为 1，padding 为 1：

$$
(8,3,32,32)\rightarrow(8,16,32,32).
$$

Batch Normalization 和 ReLU 不改变形状：

$$
(8,16,32,32)\rightarrow(8,16,32,32).
$$

$2\times2$ 最大池化把高、宽减半：

$$
(8,16,32,32)\rightarrow(8,16,16,16).
$$

第二个卷积产生 32 个通道：

$$
(8,16,16,16)\rightarrow(8,32,16,16).
$$

全局平均池化对每个通道的 $16\times16$ 个位置求平均：

$$
(8,32,16,16)\rightarrow(8,32).
$$

全连接为每张图产生 10 个类别得分：

$$
(8,32)\rightarrow(8,10).
$$

最后，交叉熵把每张图的 10 个 logits 与一个正确类别编号比较，产生 8 个单样本损失，再依据 reduction 规则组合成一个训练目标。

> [!TIP] 阅读组合模型时不要一次计算全部细节
> 先逐层写形状，再挑一个输出元素手算，最后检查损失需要的目标类型。形状、单点计算和任务含义三部分都正确，整个模型才容易继续分析。

### 14.1 这个例子在 Keras 形状下怎样写

同样的图像在 channels-last 下从 `(8,32,32,3)` 开始：

$$
(8,32,32,3)
\rightarrow
(8,32,32,16)
\rightarrow
(8,16,16,16)
\rightarrow
(8,16,16,32)
\rightarrow
(8,32)
\rightarrow
(8,10).
$$

可以看到，通道 16、32 位于最后；空间尺寸变化和每层的数学运算与前一个例子相同。

---

## 15. 初学者常见问题

### 15.1 Layer 的输出形状是不是只看参数名就能知道

不能。还要知道输入形状、轴顺序、padding、stride、dilation、是否双向、是否返回完整序列等设置。最稳妥的方法是把每个相关数代入输出尺寸公式。

### 15.2 为什么同一个公式在两个框架中看起来不同

常见原因有三个：

1. 权重张量轴次序不同；
2. 图像 Channel维度位置不同；
3. 一个框架把激活或偏置写进 Layer 参数，另一个框架把它拆成单独步骤。

把公式展开到“哪些元素相乘、在哪个维度求和”后，通常可以看出核心计算相同。

### 15.3 为什么公式正确，模型仍然可能不能运行

公式只说明数学关系。实际 Layer 还要求：

- 维度次序正确；
- Channel 数或 Feature 宽度满足构造参数；
- 分组卷积的通道数可被 groups 整除；
- Attention 的 Feature 宽度与 Head 数相容；
- 标签类型和损失函数相容；
- 需要相加的残差分支形状相同。

### 15.4 所有 Layer 都会改变形状吗

不会。激活、Dropout 和多数归一化 Layer 通常保持形状；Linear、Dense 和卷积常改变最后的 Feature 宽度或 Channel 数；池化、上采样和转置卷积改变空间尺寸；Flatten、Reshape 和 Permute 改变形状组织方式。

### 15.5 参数更多是否一定更好

不一定。参数更多会提高表达能力，也会增加存储、计算和拟合训练数据细节的能力。Layer 选择还要考虑数据量、任务难度、延迟、设备内存和模型结构。

### 15.6 怎样确认自己真正理解了一个 Layer

至少应能完成以下任务：

1. 说出输入和输出形状；
2. 写出核心公式；
3. 解释公式中每个符号；
4. 手算一个最小数字例子；
5. 计算参数数量；
6. 说明训练与推理是否不同；
7. 找出 PyTorch 与 Keras 的名称和默认设置差异。

---

## 16. 速查表

| 需求 | 常见 Layer | 核心计算 |
| --- | --- | --- |
| 改变 Feature 宽度 | Linear / Dense | $xW+b$ |
| 加入逐元素非线性 | ReLU / GELU / SiLU | $y=f(x)$ |
| 提取局部图像特征 | Conv2d / Conv2D | 局部窗口乘加 |
| 缩小空间尺寸 | MaxPool / AveragePooling | 窗口最大值或平均值 |
| 放大空间尺寸 | 插值、转置卷积、PixelShuffle 类重排 | 重采样或可学习乘加 |
| 处理离散编号 | Embedding | 按编号取得参数行 |
| 处理序列历史 | RNN / GRU / LSTM | 当前输入与旧状态共同更新 |
| 让序列位置互相读取 | Attention / Multi-Head Attention | 分数、Softmax、Value 加权和 |
| 调整数值尺度 | BatchNorm / LayerNorm / GroupNorm | 减均值、除标准差、再缩放 |
| 随机抑制部分特征 | Dropout | 随机掩码与缩放 |
| 多类别训练 | Cross Entropy | 正确类别的负对数概率 |
| 回归训练 | MSE / MAE / Huber | 预测与目标的距离 |

---

## 17. 不写代码时怎样检查计算是否合理

### 17.1 先检查元素数量

Flatten、Reshape、Permute 和像素重排通常不创建或删除元素。

例如：

$$
(N,3,4,5)\rightarrow(N,60)
$$

是合理的，因为：

$$
3\times4\times5=60.
$$

若写成：

$$
(N,3,4,5)\rightarrow(N,50),
$$

而中间没有选取、填充或生成新值的步骤，就应立即重新检查。

> [!NOTE] 元素数量相同仍不保证含义相同
> `(N,3,4,5)` 与 `(N,5,4,3)` 的单样本元素数相同，但 Channel维度位置不同。Reshape 只负责重新组织尺寸，不会自动理解哪个数原来属于哪个通道。

### 17.2 检查求和发生在哪个维度

全连接、卷积和注意力都包含大量乘加。手算时应明确写出求和下标。

全连接：

$$
y_o=\sum_{i=1}^{I}x_iW_{io}+b_o.
$$

这里对输入 Feature 下标 $i$ 求和，输出下标 $o$ 被保留。

普通二维卷积：

$$
y_{o,h,w}
=
\sum_{c,r,s}
x_{c,h+r,w+s}W_{o,c,r,s}+b_o.
$$

这里对输入通道 $c$ 和卷积核位置 $r,s$ 求和，输出通道 $o$ 与输出位置 $h,w$ 被保留。

注意力加权和：

$$
o_i=\sum_j a_{ij}v_j.
$$

这里对 Key/Value 位置 $j$ 求和，Query 位置 $i$ 被保留。

> [!TIP] 圈出保留下标
> 一个下标若仍出现在等号右侧求和符号之外，通常会出现在输出形状中。一个下标若只出现在求和符号下方，通常会在该步计算中被消去。

### 17.3 检查 Softmax 的和

对指定维度执行 Softmax 后，每一组输出应满足：

$$
p_i\ge 0,\qquad \sum_i p_i=1.
$$

普通有限 logits 产生的每个 $p_i$ 都严格大于 0；若注意力先把禁止位置设为负无穷，Softmax 后这些位置可以正好为 0。

若类别 logits 形状为 `(N,C)`，每个样本的 $C$ 个类别概率之和应为 1。若注意力分数形状为 `(N,h,L_q,L_k)`，通常是最后的 $L_k$ 个权重之和为 1。

> [!WARNING] 总和为 1 也可能选错维度
> 沿任意维度做 Softmax 都会得到某个方向上的和为 1。除了检查数值，还要确认这一组元素是否真的应该互相竞争：类别之间、Key 位置之间，还是其他对象之间。

### 17.4 检查归一化后的均值和方差

关闭可学习缩放和平移，并暂时忽略 $\epsilon$ 时，使用同一组统计量处理后的数通常满足：

$$
\operatorname{mean}(\hat{x})\approx0,
\qquad
\operatorname{var}(\hat{x})\approx1.
$$

但必须在 Layer 实际使用的统计维度上检查。例如 Layer Normalization 处理 `(N,L,E)` 的最后一个维度时，应分别检查每个 token 的 $E$ 个数，而不是把整个张量一起求均值。

若输入组内所有数都相同，方差为 0，归一化中间结果为 0：

$$
\frac{x-\mu}{\sqrt{0+\epsilon}}=0.
$$

若随后使用 $\gamma,\beta$，最终结果为 $\beta$。

### 17.5 检查池化与上采样的信息变化

最大池化只保存窗口最大值，平均池化只保存窗口平均值。它们通常无法从输出唯一确定原输入。

例如：

$$
[1,4]\xrightarrow{\text{MaxPool}}[4].
$$

输入 `[2,4]`、`[-3,4]` 和 `[4,4]` 也会产生 `[4]`。因此，即使后续把长度重新放大为 2，也不能知道第一个数原来是多少。

> [!NOTE] 尺寸相同不等于数据相同
> 上采样、转置卷积或反池化可以把形状放大到原尺寸，但此前删除的信息不会自动重新出现。恢复出来的内容取决于保存的位置、插值规则、可学习权重或来自较早 Layer 的额外特征。

### 17.6 检查参数数量

常见参数数量公式：

| Layer | 参数数量 |
| --- | ---: |
| Linear / Dense | $IO+O$ |
| 普通 Conv2D | $C_{\mathrm{out}}C_{\mathrm{in}}K_hK_w+C_{\mathrm{out}}$ |
| groups 为 $G$ 的 Conv2D | $C_{\mathrm{out}}(C_{\mathrm{in}}/G)K_hK_w+C_{\mathrm{out}}$ |
| Embedding | $VD$ |
| 无仿射参数的池化 | 0 |
| ReLU / Sigmoid / Tanh | 0 |

表中默认使用偏置；若关闭偏置，应删去最后的输出宽度或输出通道数。

> [!EXAMPLE] 参数数量与输出空间大小无关
> `Conv2D` 的同一组卷积核会在所有空间位置重复使用。输入从 $32\times32$ 改成 $128\times128$ 时，输出元素和乘加次数会增多，但卷积核参数数量保持不变。

### 17.7 检查残差相加

残差结构通常写成：

$$
y=F(x)+x.
$$

逐元素相加要求两侧形状相同，或满足框架允许的广播规则。经典残差块通常希望每个位置一一对应，因此最好显式保证：

$$
\operatorname{shape}(F(x))=\operatorname{shape}(x).
$$

如果主分支改变了 Channel 数或空间尺寸，就需要在旁路加入投影或采样步骤，使形状相容。

### 17.8 检查训练状态

| Layer | 训练时 | 推理时 |
| --- | --- | --- |
| Dropout | 随机置零并缩放 | 通常直接通过 |
| Batch Normalization | 使用当前 Batch 的统计量并更新运行统计量 | 使用保存的运行统计量 |
| Linear / Dense | 仿射变换 | 同一仿射变换 |
| 普通卷积 | 局部乘加 | 同一局部乘加 |
| Layer Normalization | 使用当前样本指定维度的统计量 | 通常使用同一规则 |

若同一个输入在训练和推理时产生不同结果，先检查模型状态，再检查是否存在 Dropout、Batch Normalization 或带随机性的其他 Layer。

### 17.9 从 PyTorch 切换到 Keras 时的检查清单

1. 图像是 channels-first 还是 channels-last；
2. 全连接权重是否需要转置；
3. 卷积核的输入、输出 Channel 轴次序是否一致；
4. Batch Normalization 的 `axis` 是否指向 Channel维度；
5. RNN 是否返回完整序列和状态；
6. Attention mask 中允许位置与禁止位置分别用什么值；
7. 分类损失收到的是 logits 还是概率；
8. padding、stride 和 dilation 的默认设置是否相同；
9. reduction 是求和、平均还是保留逐样本结果；
10. 训练状态与推理状态怎样传递给子 Layer。

> [!SUMMARY] 检查计算的简短顺序
> 先检查形状，再检查求和维度；随后检查参数数量、概率和归一化统计；最后核对训练状态与框架默认设置。按这个顺序分析，许多看似复杂的 Layer 都可以拆成几步基础运算。

> [!SUMMARY] 最后应记住什么
> Layer 名称只是入口。真正需要掌握的是：输入形状、参与计算的维度、核心公式、参数形状、输出形状和训练状态。PyTorch 与 Keras 的接口可以不同，但只要逐项写出这些信息，大多数基础 Layer 都能用同一套数学语言解释。

<!-- BACKPROP_AND_NUMERICS_SECTION -->

<!-- WORKED_EXERCISES_SECTION -->
