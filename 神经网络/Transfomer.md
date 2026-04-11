# Transformer：从思想到公式，再到代码实现

## 目录

1. 背景与动机
2. Transformer 的核心思想
3. 整体结构总览
4. 输入表示与位置编码
5. 缩放点积注意力
6. 多头注意力
7. 前馈网络、残差连接与层归一化
8. Encoder 与 Decoder 的完整流程
9. 训练目标、掩码与推理方式
10. 一个可手算的注意力示例
11. NumPy 版注意力代码
12. PyTorch 版简化 Transformer 代码
13. Transformer 的复杂度、优缺点与演进
14. 总结

## 1. 背景与动机

在 Transformer 出现之前，序列建模主要依赖 RNN、LSTM 和 GRU。它们可以按时间步逐个处理 token，天然适合处理时序数据，但也存在几个非常现实的瓶颈。

第一，序列计算是串行的。第 $t$ 个位置的输出要依赖第 $t-1$ 个位置的隐藏状态，这使得训练和推理都难以充分并行化。第二，长距离依赖难以稳定捕捉。虽然 LSTM 通过门控机制缓解了梯度消失，但随着序列变长，信息仍然会逐渐衰减。第三，模型状态是压缩在一个隐向量中的，信息瓶颈明显，尤其当输入很长时，这种压缩会限制表达能力。

Transformer 的关键突破是：不再把序列信息硬塞进一个按时间递推的隐藏状态，而是让每个位置直接去“看”其他位置，从而通过注意力机制建立任意位置之间的动态联系。这样做的直接收益有两个：

一是计算可以高度并行；二是依赖关系可以跨越很远的距离，不必经过很多步递推才能传播。

2017 年 Vaswani 等人在论文 Attention Is All You Need 中提出 Transformer 后，NLP 的主流范式迅速转向基于注意力的架构，后来又扩展到视觉、语音、推荐系统和多模态领域。可以说，Transformer 不只是一个具体模型，更是一种通用的序列表示与交互范式。

## 2. Transformer 的核心思想

Transformer 的核心可以概括为一句话：让序列中的每个位置，都通过注意力机制，对序列中所有位置的信息做自适应加权汇聚。

这里有三个关键词。

第一是“自适应”。权重不是预先固定的，也不是由手工规则设定的，而是由模型根据当前输入内容动态计算出来的。比如在句子 “The animal did not cross the road because it was tired” 里，it 应该更关注 animal 而不是 road；而在另一句话里，it 可能指代别的词。注意力权重可以随上下文变化。

第二是“全局交互”。RNN 的信息传播依赖链式传递，而注意力允许任意两个位置直接交互。一个位置对另一个位置的影响，不需要等很多步传播。

第三是“多视角表达”。多头注意力把同一组输入投影到多个子空间中，允许不同的头关注不同的关系，例如语法关系、指代关系、局部搭配关系、长程依赖关系等。

从直觉上看，Transformer 就像一个“可学习的信息检索系统”：每个 token 先生成一个查询向量 Query，然后去和所有 token 的 Key 做相似度匹配，再用匹配分数对对应的 Value 做加权求和。输出不是一个固定模板，而是与上下文相关的动态表示。

## 3. 整体结构总览

经典 Transformer 分为 Encoder 和 Decoder 两部分。

Encoder 的作用是把输入序列编码成一组上下文相关的表示；Decoder 的作用是在已有输出前缀的条件下，逐步生成目标序列。机器翻译是最经典的例子：Encoder 读入源语言句子，Decoder 生成目标语言句子。

一个标准 Transformer Block 的基本组件通常包括：

1. 多头自注意力层
2. 前馈网络层
3. 残差连接
4. 层归一化
5. Dropout

Encoder 中通常堆叠若干层相同结构的 Encoder Block；Decoder 中堆叠若干层相同结构的 Decoder Block。不同之处在于 Decoder 多了一层“交叉注意力”，用于让目标端去关注源端编码结果。

可以把整体流程理解成下面这样：

- 输入 token 先做 embedding
- 再加入位置信息
- 进入多层 Encoder
- Decoder 读取已生成前缀，并通过掩码自注意力保证不能偷看未来 token
- Decoder 再通过交叉注意力去读取 Encoder 输出
- 最后通过线性层和 Softmax 得到下一个 token 的概率分布

从工程实现角度看，Transformer 的计算图非常规整，便于并行，适合 GPU 和 TPU 加速；从建模角度看，它用注意力代替了递推，表达能力和可扩展性都显著提升。

## 4. 输入表示与位置编码

### 4.1 Token Embedding

离散 token 首先要映射到连续向量空间。设词表大小为 $V$，嵌入维度为 $d_{model}$，那么每个 token $x_i$ 会被映射成一个向量 $e_i \in \mathbb{R}^{d_{model}}$。

如果把 token 视为 one-hot 向量，那么 embedding 本质上就是一个查表操作：

$$
e_i = E[x_i]
$$

其中 $E \in \mathbb{R}^{V \times d_{model}}$ 是可学习的嵌入矩阵。

### 4.2 为什么需要位置编码

注意力机制本身对输入顺序不敏感。也就是说，如果只给它一组 token 向量，而不提供位置信息，它无法知道谁在前谁在后。为了让模型理解顺序，需要注入位置编码 Positional Encoding。

常见做法有两类：

1. 绝对位置编码：给每个位置一个向量，再加到 token embedding 上
2. 相对位置编码：在注意力打分时直接建模位置差异

原始 Transformer 使用的是正弦余弦位置编码。设位置为 $pos$，维度索引为 $i$，则：

$$
PE_{(pos, 2i)} = \sin\left(\frac{pos}{10000^{2i/d_{model}}}\right)
$$

$$
PE_{(pos, 2i+1)} = \cos\left(\frac{pos}{10000^{2i/d_{model}}}\right)
$$

这种编码有几个优点。首先，它不需要学习参数，推理时可以自然外推到更长序列。其次，不同频率的正余弦组合能表达不同尺度的位置变化，模型可以通过线性组合恢复相对位置信息。再次，这种设计与向量相加兼容，简单高效。

输入到第一层 Transformer 的表示一般写成：

$$
z_i^{(0)} = e_i + PE_i
$$

也可以再加上 token type embedding、segment embedding 或其他辅助嵌入，具体取决于任务。

### 4.3 计算示例：Embedding 与位置向量相加

为了便于手算，下面用一个简化的 4 维例子说明“词向量 + 位置向量”的计算过程。假设有三个 token：`I`、`love`、`AI`，它们的 embedding 分别为：

$$
e_{I} = [0.2, 0.0, 0.1, 0.4]
$$

$$
e_{love} = [0.0, 0.3, 0.2, 0.1]
$$

$$
e_{AI} = [0.5, 0.1, 0.0, 0.2]
$$

再假设前 3 个位置的位置信号简化为：

$$
PE_0 = [0, 1, 0, 1], \quad PE_1 = [1, 0, 1, 0], \quad PE_2 = [0.5, 0.5, 0.5, 0.5]
$$

那么输入表示就是逐元素相加：

$$
z_0^{(0)} = e_I + PE_0 = [0.2, 1.0, 0.1, 1.4]
$$

$$
z_1^{(0)} = e_{love} + PE_1 = [1.0, 0.3, 1.2, 0.1]
$$

$$
z_2^{(0)} = e_{AI} + PE_2 = [1.0, 0.6, 0.5, 0.7]
$$

这个例子强调的是计算顺序：先查表得到词向量，再加上位置向量，最后把结果送入第一层注意力。实际工程里位置向量可能是正弦余弦形式或可学习参数，但加法流程是一样的。

## 5. 缩放点积注意力

注意力是 Transformer 的核心。最常见的形式是缩放点积注意力，Scaled Dot-Product Attention。

### 5.1 Q、K、V 的来源

给定输入矩阵 $X \in \mathbb{R}^{n \times d_{model}}$，其中 $n$ 是序列长度。我们用三组线性映射把它投影到 Query、Key、Value 三个空间：

$$
Q = XW^Q, \quad K = XW^K, \quad V = XW^V
$$

其中：

- $W^Q \in \mathbb{R}^{d_{model} \times d_k}$
- $W^K \in \mathbb{R}^{d_{model} \times d_k}$
- $W^V \in \mathbb{R}^{d_{model} \times d_v}$

Q 可以理解为“我想找什么”；K 可以理解为“我有什么特征”；V 可以理解为“如果被选中，我提供什么内容”。

### 5.2 注意力打分

第 $i$ 个位置对第 $j$ 个位置的相关性分数由 Q 和 K 的点积给出：

$$
s_{ij} = q_i k_j^T
$$

把所有分数写成矩阵形式，就是：

$$
S = QK^T
$$

### 5.3 为什么要除以 $\sqrt{d_k}$

如果 $d_k$ 很大，点积的数值会变大，Softmax 之后容易变得过于尖锐，导致梯度不稳定。于是原论文使用缩放因子：

$$
A = \mathrm{softmax}\left(\frac{QK^T}{\sqrt{d_k}}\right)
$$

其中 $A$ 是注意力权重矩阵。再用它对 Value 做加权求和：

$$
\mathrm{Attention}(Q, K, V) = \mathrm{softmax}\left(\frac{QK^T}{\sqrt{d_k}}\right)V
$$

这就是最核心的一条公式。它的意义非常清楚：每个位置根据自己与其他所有位置的相似度，自动计算一个权重分布，然后用这个分布聚合信息。

### 5.4 Softmax 的作用

对某个查询位置 $i$，注意力分数向量为 $s_i$，经过 Softmax 后得到概率分布：

$$
a_{ij} = \frac{\exp(s_{ij})}{\sum_{t=1}^{n}\exp(s_{it})}
$$

于是有：

$$
\sum_{j=1}^{n} a_{ij} = 1
$$

这意味着输出是对所有 Value 的凸组合，模型可以选择“更看重谁”，也可以在某些位置几乎忽略其他 token。

### 5.5 Masked Attention

在生成式任务中，Decoder 不能看到未来 token，否则训练和推理就不一致。为此要引入上三角掩码。设掩码矩阵 $M$ 中，不允许关注的位置被置为 $-\infty$，允许的位置为 0，那么：

$$
\mathrm{Attention}(Q,K,V) = \mathrm{softmax}\left(\frac{QK^T}{\sqrt{d_k}} + M\right)V
$$

这样 Softmax 后，被屏蔽的位置概率就是 0。

### 5.6 计算示例：从 Q、K、V 到注意力输出

设输入矩阵为：

$$
X = \begin{bmatrix}
1 & 0 \\
0 & 1 \\
1 & 1
\end{bmatrix}
$$

为了突出计算流程，令：

$$
W^Q = \begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix}, \quad
W^K = \begin{bmatrix}1 & 1 \\ 0 & 1\end{bmatrix}, \quad
W^V = \begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix}
$$

则：

$$
Q = XW^Q = \begin{bmatrix}
1 & 0 \\
0 & 1 \\
1 & 1
\end{bmatrix}, \quad
K = XW^K = \begin{bmatrix}
1 & 1 \\
0 & 1 \\
1 & 2
\end{bmatrix}, \quad
V = XW^V = \begin{bmatrix}
1 & 0 \\
0 & 1 \\
1 & 1
\end{bmatrix}
$$

对第 1 个 token 来说，查询向量是 $q_1=[1,0]$，它和三个 Key 的点积分别是：

$$
[1,0]\cdot[1,1]=1, \quad [1,0]\cdot[0,1]=0, \quad [1,0]\cdot[1,2]=1
$$

缩放后得到：

$$
[0.707, 0, 0.707]
$$

做 Softmax 后，注意力权重约为：

$$
[0.401, 0.198, 0.401]
$$

于是第 1 个位置的输出为：

$$
o_1 = 0.401\cdot[1,0] + 0.198\cdot[0,1] + 0.401\cdot[1,1] = [0.802, 0.599]
$$

这个例子把“Q 和 K 算相似度、Softmax 得权重、再用权重加权 V”三步完整串起来了。

## 6. 多头注意力

单头注意力虽然有效，但它只在一个子空间里计算关系，表达能力有限。多头注意力通过多个独立头并行建模，提升了灵活性。

### 6.1 公式

设共有 $h$ 个头，第 $r$ 个头对应的投影矩阵为 $W_r^Q, W_r^K, W_r^V$，则：

$$
\mathrm{head}_r = \mathrm{Attention}(QW_r^Q, KW_r^K, VW_r^V)
$$

所有头的输出拼接后，再经过线性映射：

$$
\mathrm{MultiHead}(Q,K,V) = \mathrm{Concat}(\text{head}_1, \dots, \text{head}_h)W^O
$$

其中 $W^O \in \mathbb{R}^{hd_v \times d_{model}}$。

### 6.2 为什么多头有效

多头并不只是“多算几次”，更重要的是它让模型在不同表示子空间中学习不同类型的关系。比如某个头可能专门关注主谓关系，另一个头关注指代消解，还有一个头关注局部搭配。

如果只有一个头，所有关系都要挤在同一个注意力分布里，表达会更受限。多头把这一任务拆开，等于让模型同时从多个角度阅读同一段文本。

### 6.3 计算中的维度约束

通常总维度 $d_{model}$ 会被均分给多个头，例如 $d_{model}=512$，头数 $h=8$，则每个头的维度 $d_k=d_v=64$。这样各头拼接后仍然回到原始维度，便于后续残差连接。

### 6.4 计算示例：两个头如何拼接

假设某个位置经过两个注意力头后得到的输出分别是：

$$
h^{(1)} = [0.8, 0.6], \quad h^{(2)} = [0.3, 0.9]
$$

那么拼接后的向量就是：

$$
\mathrm{Concat}(h^{(1)}, h^{(2)}) = [0.8, 0.6, 0.3, 0.9]
$$

如果输出映射矩阵 $W^O$ 先按单位矩阵处理，那么最终输出仍是这个 4 维向量。若 $W^O$ 不是单位矩阵，则会继续做一次线性混合，把多个头的信息重新融合回 $d_{model}$ 维空间。

## 7. 前馈网络、残差连接与层归一化

### 7.1 位置前馈网络

注意力层解决的是 token 与 token 的交互，而前馈网络则负责对每个位置的表示做非线性变换。它对每个位置独立作用，所以又叫 position-wise feed-forward network。

原始 Transformer 里的前馈网络通常是两层全连接，中间加 ReLU：

$$
\mathrm{FFN}(x)=\max(0, xW_1+b_1)W_2+b_2
$$

其中：

- $W_1 \in \mathbb{R}^{d_{model} \times d_{ff}}$
- $W_2 \in \mathbb{R}^{d_{ff} \times d_{model}}$

一般 $d_{ff}$ 会比 $d_{model}$ 大得多，例如 2048 对 512。这样可以提供更强的非线性表达能力。

### 7.2 残差连接

Transformer 中每个子层都使用残差连接：

$$
y = x + \mathrm{Sublayer}(x)
$$

残差连接的作用很重要。它让梯度更容易反向传播，避免深层堆叠时训练困难；同时也允许模型在必要时保留输入信息，不必每层都强行重写表示。

### 7.3 LayerNorm

层归一化对每个样本的特征维度做归一化。对输入向量 $x \in \mathbb{R}^{d}$，LayerNorm 定义为：

$$
\mu = \frac{1}{d}\sum_{i=1}^{d}x_i, \quad
\sigma^2 = \frac{1}{d}\sum_{i=1}^{d}(x_i-\mu)^2
$$

$$
\mathrm{LayerNorm}(x)=\gamma \odot \frac{x-\mu}{\sqrt{\sigma^2+\epsilon}} + \beta
$$

其中 $\gamma$ 和 $\beta$ 是可学习参数。

LayerNorm 与 BatchNorm 不同。BatchNorm 依赖 batch 统计量，而 NLP 序列长度和 batch size 常常变化较大，LayerNorm 更稳定，也更适合序列建模。

### 7.4 Post-Norm 与 Pre-Norm

原始 Transformer 使用的是 Post-Norm，也就是先做残差相加，再做 LayerNorm：

$$
\mathrm{LN}(x + \mathrm{Sublayer}(x))
$$

后来大量大模型采用 Pre-Norm，即先归一化再进子层：

$$
x + \mathrm{Sublayer}(\mathrm{LN}(x))
$$

Pre-Norm 通常更利于深层训练，梯度更稳定，因此在现代大模型中更常见。

### 7.5 计算示例：FFN、残差连接与 LayerNorm

设某个位置的输入向量为：

$$
x = [1, 2]
$$

为了手算简单，令前馈网络退化成恒等映射，也就是：

$$
\mathrm{FFN}(x) = [1, 2]
$$

则残差相加后的结果为：

$$
x + \mathrm{FFN}(x) = [2, 4]
$$

接着做 LayerNorm。先算均值：

$$
\mu = \frac{2+4}{2} = 3
$$

方差为：

$$
\sigma^2 = \frac{(2-3)^2 + (4-3)^2}{2} = 1
$$

归一化后得到：

$$
\frac{[2,4]-3}{\sqrt{1+\epsilon}} \approx [-1, 1]
$$

如果再令 $\gamma=[1,1]$、$\beta=[0,0]$，那么最终输出仍然是：

$$
[-1, 1]
$$

这个例子说明，FFN 负责变换表示，残差负责保信息，LayerNorm 则把数值范围拉回稳定区间。

## 8. Encoder 与 Decoder 的完整流程

### 8.1 Encoder Block

一个标准 Encoder Block 包括两部分：

1. 多头自注意力
2. 前馈网络

每部分外面都包着残差连接和归一化。若记输入为 $X$，则 Encoder Block 可以写成：

$$
H = \mathrm{LN}(X + \mathrm{MultiHeadSelfAttention}(X))
$$

$$
Y = \mathrm{LN}(H + \mathrm{FFN}(H))
$$

输出 $Y$ 会作为下一层的输入。

### 8.2 Decoder Block

Decoder Block 比 Encoder Block 多一层交叉注意力。它通常包含：

1. Masked Multi-Head Self-Attention
2. Cross-Attention
3. Feed Forward Network

如果 Decoder 当前层输入为 $X_d$，Encoder 输出为 $X_e$，那么：

$$
H_1 = \mathrm{LN}(X_d + \mathrm{MaskedMHA}(X_d))
$$

$$
H_2 = \mathrm{LN}(H_1 + \mathrm{CrossAttention}(H_1, X_e, X_e))
$$

$$
Y = \mathrm{LN}(H_2 + \mathrm{FFN}(H_2))
$$

这里 Cross-Attention 的 Query 来自 Decoder 当前状态，而 Key 和 Value 来自 Encoder 输出。这意味着 Decoder 在生成每个 token 时，都可以根据源句的上下文动态检索相关信息。

### 8.3 编码器和解码器的分工

可以把 Encoder 理解为“理解输入”，把 Decoder 理解为“按条件生成输出”。Encoder 先把整句输入变成一组高维上下文表示；Decoder 在每一步利用这些表示和已有输出前缀预测下一个 token。

在机器翻译中，这种分工尤其自然：Encoder 负责读懂源语言，Decoder 负责写出目标语言。

### 8.4 计算示例：Encoder 编码后如何被 Decoder 读取

假设输入句子是 `I love AI`。经过 Encoder 后，三个位置的输出表示分别为：

$$
h_1 = [0.9, 0.1], \quad h_2 = [0.2, 0.8], \quad h_3 = [0.6, 0.4]
$$

现在 Decoder 已经生成了前缀 `I love`，当前查询向量记为：

$$
q = [1, 0]
$$

它与三个 Encoder 输出做点积：

$$
q\cdot h_1 = 0.9, \quad q\cdot h_2 = 0.2, \quad q\cdot h_3 = 0.6
$$

Softmax 后得到近似权重：

$$
[0.412, 0.227, 0.361]
$$

于是交叉注意力得到的上下文向量为：

$$
c = 0.412\cdot[0.9,0.1] + 0.227\cdot[0.2,0.8] + 0.361\cdot[0.6,0.4]
$$

$$
= [0.633, 0.367]
$$

这个上下文向量再送入后续线性层，才能预测下一个 token。它说明 Decoder 不是凭空生成，而是每一步都在“读取 Encoder 的摘要信息”。

## 9. 训练目标、掩码与推理方式

### 9.1 语言建模目标

如果是自回归生成任务，模型通常学习最大化条件概率：

$$
P(y|x)=\prod_{t=1}^{T} P(y_t | y_{<t}, x)
$$

训练时常用交叉熵损失：

$$
\mathcal{L} = -\sum_{t=1}^{T} \log P(y_t^{*} | y_{<t}^{*}, x)
$$

其中 $y_t^{*}$ 表示真实标签 token。

### 9.2 Teacher Forcing

训练阶段常用 Teacher Forcing，也就是把真实前缀喂给 Decoder，而不是把模型自己刚生成的 token 再送回去。这样训练会更稳定、收敛更快。

但这也带来一个经典问题：训练时看到的上下文是真实前缀，推理时看到的是模型自己的历史输出，两者分布并不完全一致，这就是 exposure bias 的来源之一。

### 9.3 推理方式

推理时需要一步一步生成。

最简单的方法是 greedy decoding，每一步都选概率最大的 token：

$$
y_t = \arg\max_{w \in V} P(w | y_{<t}, x)
$$

这种方法简单但未必全局最优。更强的方法是 beam search，它保留若干个候选序列，综合考虑每一步概率，通常能得到更好的翻译或生成结果。

### 9.4 Padding Mask 与 Causal Mask

实际输入通常有 padding。为了避免模型关注到无意义的补齐位置，需要 Padding Mask。对于 Decoder 还需要 Causal Mask，防止未来信息泄露。

两种掩码通常会一起使用：

- Padding Mask：屏蔽无效 token
- Causal Mask：屏蔽未来 token

工程实现时，常把它们转换成加性 mask，然后在 attention logits 上直接加 $-\infty$。

### 9.5 计算示例：Mask、Loss 与 Greedy Decoding

假设序列长度为 3，Causal Mask 为：

$$
M = \begin{bmatrix}
0 & -\infty & -\infty \\
0 & 0 & -\infty \\
0 & 0 & 0
\end{bmatrix}
$$

如果某一行原始注意力 logits 是：

$$
[2, 1, 0]
$$

那么在第 2 个位置做 masked attention 时，第三个位置会被屏蔽，只剩下：

$$
[2, 1, -\infty]
$$

Softmax 后约为：

$$
[0.731, 0.269, 0]
$$

这表示当前位置只能看见自己和过去，不能看未来。

再看训练损失。假设模型对真实 token 的预测概率是 $p=0.2$，那么交叉熵损失就是：

$$
\mathcal{L} = -\log(0.2) \approx 1.609
$$

如果做 greedy decoding，而各候选 token 的概率分别是：

$$
[0.1, 0.6, 0.3]
$$

那么就选概率最大的第二个 token。这个过程每一步重复一次，直到生成结束符号。

## 10. 一个可手算的注意力示例

为了直观理解注意力，我们看一个非常小的例子。设序列长度为 3，每个 token 的表示维度为 2。我们直接令 $Q=K=V=X$，并取：

$$
X = \begin{bmatrix}
1 & 0 \\
0 & 1 \\
1 & 1
\end{bmatrix}
$$

于是：

$$
QK^T =
\begin{bmatrix}
1 & 0 & 1 \\
0 & 1 & 1 \\
1 & 1 & 2
\end{bmatrix}
$$

若 $d_k=2$，则缩放后为：

$$
\frac{QK^T}{\sqrt{2}} =
\begin{bmatrix}
0.707 & 0 & 0.707 \\
0 & 0.707 & 0.707 \\
0.707 & 0.707 & 1.414
\end{bmatrix}
$$

对第一行做 Softmax。先算指数近似值：

$$
e^{0.707} \approx 2.028, \quad e^0=1
$$

所以第一行权重约为：

$$
[0.401, 0.198, 0.401]
$$

这意味着第一个 token 会同时关注第 1 个和第 3 个位置，而对第 2 个位置关注较少。

输出向量就是加权和：

$$
o_1 = 0.401\cdot [1,0] + 0.198\cdot [0,1] + 0.401\cdot [1,1]
$$

$$
= [0.802, 0.599]
$$

同理可以计算其他位置的输出。这个例子说明，注意力层实际上是在每个位置上做“内容相关的动态平均”，只是这个平均权重是由模型自动学习出来的，而不是固定滑动窗口。

## 11. NumPy 版注意力代码

下面给出一个尽量简洁的 NumPy 实现，用于理解公式如何落地。

```python
import numpy as np


def softmax(x, axis=-1):
	x = x - np.max(x, axis=axis, keepdims=True)
	exp_x = np.exp(x)
	return exp_x / np.sum(exp_x, axis=axis, keepdims=True)


def scaled_dot_product_attention(q, k, v, mask=None):
	d_k = q.shape[-1]
	scores = np.matmul(q, np.swapaxes(k, -1, -2)) / np.sqrt(d_k)

	if mask is not None:
		scores = np.where(mask, scores, -1e9)

	weights = softmax(scores, axis=-1)
	output = np.matmul(weights, v)
	return output, weights


# 示例输入：batch_size=1, seq_len=3, d_model=2
x = np.array([
	[[1.0, 0.0],
	 [0.0, 1.0],
	 [1.0, 1.0]]
])

# 直接令 Q=K=V=X，方便观察计算过程
output, weights = scaled_dot_product_attention(x, x, x)

print("attention weights:\n", weights)
print("output:\n", output)
```

这段代码与公式完全对应。`scores` 就是 $QK^T / \sqrt{d_k}$，`weights` 是 Softmax 后的注意力分布，`output` 是加权求和结果。

如果需要加入上三角掩码，可以这样构造：

```python
seq_len = x.shape[1]
causal_mask = np.tril(np.ones((seq_len, seq_len), dtype=bool))
causal_mask = causal_mask[None, :, :]

output_masked, weights_masked = scaled_dot_product_attention(x, x, x, mask=causal_mask)
```

## 12. PyTorch 版简化 Transformer 代码

工程上更常用 PyTorch。下面给出一个简化版多头注意力和编码器层，便于你把公式和模块对应起来。

```python
import math
import torch
import torch.nn as nn


class MultiHeadSelfAttention(nn.Module):
	def __init__(self, d_model, num_heads, dropout=0.0):
		super().__init__()
		assert d_model % num_heads == 0
		self.d_model = d_model
		self.num_heads = num_heads
		self.d_head = d_model // num_heads

		self.w_q = nn.Linear(d_model, d_model)
		self.w_k = nn.Linear(d_model, d_model)
		self.w_v = nn.Linear(d_model, d_model)
		self.w_o = nn.Linear(d_model, d_model)
		self.dropout = nn.Dropout(dropout)

	def reshape_heads(self, x):
		bsz, seq_len, _ = x.shape
		x = x.view(bsz, seq_len, self.num_heads, self.d_head)
		return x.transpose(1, 2)

	def forward(self, x, mask=None):
		q = self.reshape_heads(self.w_q(x))
		k = self.reshape_heads(self.w_k(x))
		v = self.reshape_heads(self.w_v(x))

		scores = torch.matmul(q, k.transpose(-2, -1)) / math.sqrt(self.d_head)

		if mask is not None:
			scores = scores.masked_fill(~mask, float("-inf"))

		attn = torch.softmax(scores, dim=-1)
		attn = self.dropout(attn)
		out = torch.matmul(attn, v)

		out = out.transpose(1, 2).contiguous().view(x.size(0), x.size(1), self.d_model)
		return self.w_o(out), attn


class FeedForward(nn.Module):
	def __init__(self, d_model, d_ff, dropout=0.0):
		super().__init__()
		self.net = nn.Sequential(
			nn.Linear(d_model, d_ff),
			nn.ReLU(),
			nn.Dropout(dropout),
			nn.Linear(d_ff, d_model),
		)

	def forward(self, x):
		return self.net(x)


class TransformerEncoderLayer(nn.Module):
	def __init__(self, d_model, num_heads, d_ff, dropout=0.0):
		super().__init__()
		self.self_attn = MultiHeadSelfAttention(d_model, num_heads, dropout)
		self.ffn = FeedForward(d_model, d_ff, dropout)
		self.norm1 = nn.LayerNorm(d_model)
		self.norm2 = nn.LayerNorm(d_model)
		self.dropout = nn.Dropout(dropout)

	def forward(self, x, mask=None):
		attn_out, _ = self.self_attn(x, mask)
		x = self.norm1(x + self.dropout(attn_out))

		ffn_out = self.ffn(x)
		x = self.norm2(x + self.dropout(ffn_out))
		return x


class PositionalEncoding(nn.Module):
	def __init__(self, d_model, max_len=5000):
		super().__init__()
		pe = torch.zeros(max_len, d_model)
		position = torch.arange(0, max_len, dtype=torch.float).unsqueeze(1)
		div_term = torch.exp(
			torch.arange(0, d_model, 2).float() * (-math.log(10000.0) / d_model)
		)
		pe[:, 0::2] = torch.sin(position * div_term)
		pe[:, 1::2] = torch.cos(position * div_term)
		pe = pe.unsqueeze(0)
		self.register_buffer("pe", pe)

	def forward(self, x):
		return x + self.pe[:, :x.size(1)]


class TinyTransformerEncoder(nn.Module):
	def __init__(self, vocab_size, d_model=128, num_heads=4, d_ff=256, num_layers=2, max_len=512):
		super().__init__()
		self.embed = nn.Embedding(vocab_size, d_model)
		self.pos = PositionalEncoding(d_model, max_len)
		self.layers = nn.ModuleList([
			TransformerEncoderLayer(d_model, num_heads, d_ff)
			for _ in range(num_layers)
		])
		self.norm = nn.LayerNorm(d_model)

	def forward(self, input_ids, mask=None):
		x = self.embed(input_ids)
		x = self.pos(x)

		for layer in self.layers:
			x = layer(x, mask)

		return self.norm(x)
```

这段代码体现了一个 Encoder 的基本骨架。需要注意的是，真正完整的 Transformer Decoder 还要加入 causal mask 和 cross-attention。为了聚焦原理，这里先展示最核心的编码器结构。

下面给出一个最小的前向调用示例：

```python
model = TinyTransformerEncoder(vocab_size=1000)
input_ids = torch.randint(0, 1000, (2, 16))
output = model(input_ids)
print(output.shape)  # [2, 16, 128]
```

如果你想用 PyTorch 自带模块快速搭建，也可以直接使用 `nn.TransformerEncoderLayer` 和 `nn.TransformerDecoderLayer`。它们已经实现了多头注意力、FFN、残差和归一化。

## 13. Transformer 的复杂度、优缺点与演进

### 13.1 复杂度

Transformer 的一个经典问题是注意力的时间和空间复杂度与序列长度平方相关。对于长度为 $n$ 的序列，注意力矩阵大小为 $n \times n$，因此复杂度大致是：

$$
O(n^2 d)
$$

当序列很长时，这个二次复杂度会成为瓶颈。这也是为什么长上下文建模、稀疏注意力、线性注意力、分块注意力等方法会持续出现。

### 13.2 优点

Transformer 的主要优点包括：

1. 可以并行计算，训练效率高
2. 长距离依赖建模能力强
3. 结构规整，易于扩展到大规模模型
4. 适配多种模态和任务
5. 容易和预训练范式结合

### 13.3 局限性

它的局限也很明显：

1. 二次复杂度在长序列上代价高
2. 对位置信息的处理需要额外设计
3. 纯注意力并不天然具备卷积那样的局部归纳偏置
4. 在数据较少时，可能不如强归纳偏置模型稳定

### 13.4 主要演进方向

Transformer 提出后，围绕它出现了大量变体：

- BERT：以 Encoder 为主，适合理解类任务
- GPT：以 Decoder 为主，适合自回归生成
- T5：把任务统一成 text-to-text 范式
- ViT：把图像切成 patch 后用 Transformer 处理
- Longformer、Performer、Linformer 等：尝试降低长序列计算成本
- RoPE、ALiBi、相对位置编码：改进位置建模

可以看到，Transformer 已经从一种具体结构，演化成一整套通用建模基础设施。

## 14. 总结

Transformer 的核心创新不是某一个单独的技巧，而是把“序列中任意位置之间的交互”作为第一公民来建模。它通过 Query、Key、Value 的机制，让每个 token 都能根据上下文动态决定要关注谁；通过多头注意力，它能在多个子空间中并行学习不同关系；通过前馈网络、残差连接和层归一化，它保证了深层堆叠的稳定性；通过位置编码和掩码，它让模型同时拥有顺序感和因果约束。

如果用一句工程化的话来概括：Transformer 是一种“把序列建模问题转化为内容检索与信息聚合问题”的架构。它将传统递推式建模改造成可并行的全局交互系统，因此在训练规模、模型容量和任务迁移能力上都展现出极强优势。

对于学习者来说，理解 Transformer 最好的路径不是只背公式，而是把它拆成三层：

1. 机制层：Q、K、V 如何做匹配与汇聚
2. 结构层：Attention、FFN、Residual、Norm 如何组合成 Block
3. 系统层：Encoder、Decoder、Mask、Loss、Decoding 如何完成完整任务

只要把这三层打通，Transformer 的大部分变体都能很快读懂。后续如果你继续研究 BERT、GPT、ViT、LLaMA 或多模态模型，本质上都会回到这些基础组件。

如果需要进一步学习，建议继续补充三类内容：

1. 更细的反向传播推导，理解注意力梯度如何流动
2. 更完整的 Decoder 实现，理解 cross-attention 和 causal mask
3. 现代位置编码方案，例如 RoPE、ALiBi 和相对位置偏置

到这里，Transformer 的思想、结构、公式和基础代码框架就已经完整串起来了。你可以把这篇笔记作为后续学习大模型、视觉 Transformer 和多模态架构的总入口。
