# PyTorch 基础 Layer 全览

> 本文按本仓库已安装的 PyTorch 2.0.1 整理 `torch.nn` 中可直接用于搭建网络的基础模块。`torch.nn.functional` 中的同名函数通常与这些模块做同一种计算；模块形式会把可学习参数、运行统计量及训练状态保存到模型中。

## 1. 先建立统一的阅读方式

### 1.1 张量记号与形状

常用记号如下：

| 任务 | 常用输入形状 | 含义 |
| --- | --- | --- |
| 全连接 | `(*, H_in)` | 前面的 `*` 可以有任意数量的维度 |
| 一维卷积 | `(N, C, L)` | 批大小、通道数、长度 |
| 二维卷积 | `(N, C, H, W)` | 批大小、通道数、高、宽 |
| 三维卷积 | `(N, C, D, H, W)` | 批大小、通道数、深度、高、宽 |
| 序列（默认） | `(L, N, E)` | 序列长度、批大小、特征宽度 |
| 序列（`batch_first=True`） | `(N, L, E)` | 批大小、序列长度、特征宽度 |

`N` 表示批大小，`C` 表示通道数，`L/H/W/D` 是空间尺寸，`E` 是嵌入宽度。模块的 `weight` 和 `bias` 都是 `nn.Parameter`，会由优化器更新；均值、方差等统计量通常是 buffer，不会由优化器更新，但会随 `state_dict()` 保存。

```python
import torch
from torch import nn
import torch.nn.functional as F

torch.manual_seed(7)
x_image = torch.randn(4, 3, 32, 32)  # 4 张 RGB 图像
x_seq = torch.randn(4, 10, 16)       # batch_first 的序列
```

### 1.2 训练状态

调用 `model.train()` 后，Dropout 会随机置零，BatchNorm 会更新运行统计量；调用 `model.eval()` 后，Dropout 不再随机置零，BatchNorm 使用已保存的运行统计量。`eval()` 不会自动停止梯度记录；推理时还应使用：

```python
model = nn.Linear(3, 2).eval()
with torch.inference_mode():
    y = model(torch.randn(5, 3))
```

### 1.3 本文覆盖范围

下表给出全文目录。`DataParallel`、`Parameter`、`UninitializedParameter` 等属于并行执行或参数管理工具，不是对输入做特征变换的层，放在最后说明。`NLLLoss2d` 是 `NLLLoss` 的旧别名。

| 类别 | 覆盖的模块 |
| --- | --- |
| 组织与形状 | `Module`、`Sequential`、`ModuleList`、`ModuleDict`、`ParameterList`、`ParameterDict`、`Identity`、`Flatten`、`Unflatten` |
| 线性与激活 | `Linear`、`Bilinear`、所有逐元素激活、`GLU`、Softmax 家族 |
| 正则化与归一化 | Dropout 家族、Batch/Instance/Group/Layer/Local Response Norm、`SyncBatchNorm` |
| 卷积与空间运算 | Conv/ConvTranspose/LazyConv 家族、池化、反池化、填充、`Unfold`、`Fold`、像素重排、上采样、通道洗牌 |
| 序列与注意力 | `Embedding`、`EmbeddingBag`、RNN/GRU/LSTM 及 Cell、Multi-Head Attention、Transformer 家族 |
| 损失与度量 | 回归、分类、概率分布、排序、度量学习损失，以及 `CosineSimilarity`、`PairwiseDistance`、`AdaptiveLogSoftmaxWithLoss` |

### 1.4 阅读复杂层的通用方法

复杂层第一次看不懂通常不是公式本身太难，而是没有同时看清“输入怎么分块、每一块做了什么、结果放到哪里”。阅读下文的复杂层时，按下面四步检查：

1. **先写形状**：例如图像写成 `(N,C,H,W)`，序列写成 `(N,S,E)`。先确定哪个维度是批、通道、空间位置或时间位置。
2. **取一个最小例子**：把大张量缩成一个通道、两三个位置，手工列出本层实际读取的数。
3. **逐步计算一个输出元素**：卷积看一个窗口，Softmax 看一行，LSTM 看一个时间步，注意力看一个 Query。
4. **检查结果形状和数据去向**：有的层只改数值，有的层改尺寸，有的层会把局部块展开成列，有的层会把列累加回平面。

本文在卷积、归一化、池化、`Unfold/Fold`、`EmbeddingBag`、LSTM、注意力和分类损失处补充了小型手算例子。它们都刻意使用小整数或两三个 token；理解过程后，再把同一规则扩展到真实形状即可。

---

## 2. 组织网络与调整形状

### 2.1 `Module`、`Sequential` 与模块容器

所有自定义层都继承 `nn.Module`。把子模块赋值给成员变量，PyTorch 才能登记其参数；在 `forward` 中定义输入到输出的计算。

```python
class TinyMLP(nn.Module):
    def __init__(self):
        super().__init__()
        self.fc1 = nn.Linear(4, 8)
        self.act = nn.ReLU()
        self.fc2 = nn.Linear(8, 2)

    def forward(self, x):
        return self.fc2(self.act(self.fc1(x)))

net = TinyMLP()
print(net(torch.randn(3, 4)).shape)  # torch.Size([3, 2])
```

`Sequential` 适合单一路径的串行结构：

$$y=f_k(\cdots f_2(f_1(x))\cdots).$$

```python
classifier = nn.Sequential(
    nn.Linear(4, 8), nn.ReLU(), nn.Linear(8, 3)
)
print(classifier(torch.randn(2, 4)).shape)  # (2, 3)
```

`ModuleList` 与 `ModuleDict` 会登记其中的子模块，却不会自行调用它们，适合循环、分支或按名称选择的结构。`ParameterList` 与 `ParameterDict` 的作用相同，只是保存对象变为参数张量。

```python
layers = nn.ModuleList([nn.Linear(4, 4) for _ in range(3)])
x = torch.randn(2, 4)
for layer in layers:
    x = F.relu(layer(x))

heads = nn.ModuleDict({"class": nn.Linear(4, 3), "score": nn.Linear(4, 1)})
out = heads["class"](x)
```

### 2.2 `Identity`、`Flatten` 与 `Unflatten`

`Identity` 原样返回输入：$y=x$。它常用于按配置选择“启用或不启用某层”而不改动外部代码。

`Flatten(start_dim=1, end_dim=-1)` 把连续维度合并。若输入是

$$x\in\mathbb{R}^{N\times C\times H\times W},$$

则 `Flatten(1)` 的输出为 $\mathbb{R}^{N\times (CHW)}$。`Unflatten` 做相反的形状拆分，元素顺序不变。

```python
x = torch.randn(2, 3, 4, 5)
flat = nn.Flatten(1)(x)
restore = nn.Unflatten(1, (3, 4, 5))(flat)
print(flat.shape, torch.equal(x, restore))  # (2, 60), True

optional_norm = nn.Identity()
print(optional_norm(torch.tensor([1., 2.])))
```

---

## 3. 仿射层与激活层

### 3.1 `Linear`、`LazyLinear` 与 `Bilinear`

`Linear(in_features, out_features, bias=True)` 对最后一维做仿射变换：

$$y=xW^T+b,$$

其中 $W\in\mathbb{R}^{H_{out}\times H_{in}}$，$b\in\mathbb{R}^{H_{out}}$。输入可为 `(*, H_in)`，输出为 `(*, H_out)`。

```python
fc = nn.Linear(5, 3)
x = torch.tensor([[1., 2., 3., 4., 5.]])
y = fc(x)
print(fc.weight.shape, fc.bias.shape, y.shape)  # (3, 5), (3,), (1, 3)
```

`LazyLinear(out_features)` 在第一次前向计算时，从输入的最后一维自动确定 `in_features`。第一次调用前它的权重尚未初始化；因此应先给一批真实形状的数据，再创建依赖参数形状的优化器或检查点流程。

```python
lazy_fc = nn.LazyLinear(4)
print(lazy_fc(torch.randn(2, 7)).shape)  # 第一次输入确定 in_features=7
```

`Bilinear(in1_features, in2_features, out_features)` 同时接收两个向量：

$$y_o=x_1^T W_o x_2+b_o,$$

其中 $W\in\mathbb{R}^{H_{out}\times H_1\times H_2}$。它适合显式表达两个特征组之间的二阶交互。

```python
bilinear = nn.Bilinear(3, 4, 2)
a, b = torch.randn(5, 3), torch.randn(5, 4)
print(bilinear(a, b).shape)  # (5, 2)
```

### 3.2 逐元素激活：总览

除 `GLU` 与 Softmax 家族外，以下层都逐元素作用，不改变张量形状。令输入标量为 $x$。

| 模块 | 公式 | 主要用途或特点 |
| --- | --- | --- |
| `Threshold(t, v)` | $x$（$x>t$），否则 $v$ | 固定阈值替换 |
| `ReLU` | $\max(0,x)$ | 常用的分段线性激活 |
| `ReLU6` | $\min(\max(0,x),6)$ | 输出受限于 $[0,6]$ |
| `LeakyReLU(a)` | $x$（$x\ge0$），否则 $ax$ | 负半轴仍保留小斜率 |
| `PReLU(a)` | 同 LeakyReLU，$a$ 可学习 | 可按通道设置多个 $a$ |
| `RReLU(l,u)` | 训练时 $a\sim U(l,u)$；负半轴为 $ax$ | 训练时引入随机负斜率 |
| `ELU(a)` | $x$（$x>0$），否则 $a(e^x-1)$ | 负值平滑且有下限 |
| `CELU(a)` | $x$（$x>0$），否则 $a(e^{x/a}-1)$ | 在零点处一阶连续 |
| `SELU` | $\lambda x$（$x>0$），否则 $\lambda\alpha(e^x-1)$ | 常与特定初始化及 AlphaDropout 搭配 |
| `GELU` | $x\Phi(x)$ | Transformer 中常见；近似式也可用 |
| `SiLU` | $x\sigma(x)$ | 又称 Swish，平滑 |
| `Mish` | $x\tanh(\ln(1+e^x))$ | 平滑的非单调激活 |
| `Hardsigmoid` | $0$（$x\le-3$）；$1$（$x\ge3$）；$x/6+1/2$（其余） | Sigmoid 的分段线性近似 |
| `Hardswish` | $x\,\mathrm{Hardsigmoid}(x)$ | SiLU 的分段线性近似 |
| `Hardtanh(a,b)` | $\min(\max(x,a),b)$ | 截断到给定区间 |
| `Sigmoid` | $\sigma(x)=1/(1+e^{-x})$ | 逐元素概率值 |
| `Tanh` | $(e^{2x}-1)/(e^{2x}+1)$ | 输出位于 $(-1,1)$ |
| `LogSigmoid` | $\log\sigma(x)$ | 对数概率形式更稳定 |
| `Softplus(\beta,t)` | $\log(1+e^{\beta x})/\beta$ | 当 $\beta x>t$ 时直接取 $x$ |
| `Softsign` | $x/(1+\operatorname{abs}(x))$ | 输出位于 $(-1,1)$ |
| `Softshrink(\lambda)` | $x-\lambda$（$x>\lambda$）；$x+\lambda$（$x<-\lambda$）；否则 $0$ | 软阈值稀疏化 |
| `Hardshrink(\lambda)` | $x$（$\operatorname{abs}(x)>\lambda$），否则 $0$ | 硬阈值稀疏化 |
| `Tanhshrink` | $x-\tanh(x)$ | 平滑收缩函数 |

`GELU` 的常用快速近似为：

$$\operatorname{GELU}(x)\approx \frac{x}{2}\left[1+\tanh\left(\sqrt{\frac{2}{\pi}}(x+0.044715x^3)\right)\right].$$

下面代码一次展示各层的输出。`RReLU` 在 `train()` 与 `eval()` 的行为不同：前者采样负斜率，后者使用斜率均值。

```python
z = torch.tensor([-3., -1., 0., 1., 3.])
acts = {
    "relu": nn.ReLU(), "leaky": nn.LeakyReLU(0.1),
    "prelu": nn.PReLU(), "elu": nn.ELU(), "celu": nn.CELU(),
    "selu": nn.SELU(), "gelu": nn.GELU(), "silu": nn.SiLU(),
    "mish": nn.Mish(), "hard_sigmoid": nn.Hardsigmoid(),
    "hard_swish": nn.Hardswish(), "softplus": nn.Softplus(),
    "softshrink": nn.Softshrink(0.5), "tanhshrink": nn.Tanhshrink(),
}
for name, act in acts.items():
    print(name, act(z))
```

`PReLU(num_parameters=C)` 适合 `(N,C,...)` 输入，每个通道一条负半轴斜率；`PReLU(1)` 使用全体共享的斜率。不要对 PReLU 的斜率使用权重衰减，这是官方文档给出的常见注意事项。

### 3.3 `GLU`、`Softmax`、`Softmin` 与 `LogSoftmax`

`GLU(dim)` 先把指定维度等分成 $a,b$ 两半，再计算

$$\operatorname{GLU}(a,b)=a\odot\sigma(b).$$

故该维度长度必须为偶数，输出在该维度上减半。

Softmax 在指定维度 `dim` 上归一化：

$$\operatorname{Softmax}(x)_i=\frac{e^{x_i}}{\sum_j e^{x_j}},\qquad
\operatorname{Softmin}(x)_i=\frac{e^{-x_i}}{\sum_j e^{-x_j}}.$$

`LogSoftmax` 直接计算

$$\log\operatorname{Softmax}(x)_i=x_i-\log\sum_j e^{x_j},$$

比先算 Softmax 再取对数更稳定。`Softmax2d` 对 `(N,C,H,W)` 的通道维 `C` 做 Softmax，等价于 `Softmax(dim=1)`。

```python
gated = nn.GLU(dim=1)(torch.randn(2, 8))
logits = torch.tensor([[1.0, 2.0, 0.0]])
print(gated.shape)                         # (2, 4)
print(nn.Softmax(dim=1)(logits))            # 每行之和为 1
print(nn.LogSoftmax(dim=1)(logits).exp())   # 与 Softmax 相同
```

分类训练中，若使用 `CrossEntropyLoss`，模型应输出未归一化的 `logits`，不要在模型末尾再加 `Softmax`。

---

## 4. 正则化与归一化

### 4.1 Dropout 家族

普通 `Dropout(p)` 在训练时为每个元素生成掩码 $m_i\sim\operatorname{Bernoulli}(1-p)$：

$$y_i=\frac{m_i}{1-p}x_i.$$

因此训练阶段的期望输出仍为 $x_i$；评估阶段直接返回 $x_i$。

| 模块 | 置零单位 | 典型输入 |
| --- | --- | --- |
| `Dropout` | 每个元素 | 任意形状 |
| `Dropout1d` | 整个通道 | `(N,C,L)` 或无批维的 `(C,L)` |
| `Dropout2d` | 整个二维特征图通道 | `(N,C,H,W)` |
| `Dropout3d` | 整个三维特征体通道 | `(N,C,D,H,W)` |
| `AlphaDropout` | 元素，并保持 SELU 所需的均值、方差性质 | SELU 网络 |
| `FeatureAlphaDropout` | 整个通道，并做 AlphaDropout 的仿射修正 | 卷积式 SELU 网络 |

```python
drop = nn.Dropout(p=0.5)
u = torch.ones(2, 6)
drop.train(); print(drop(u))  # 部分元素为 0，其余通常为 2
drop.eval();  print(drop(u))  # 全为 1

spatial_drop = nn.Dropout2d(0.5)
print(spatial_drop(torch.ones(2, 3, 4, 4)).shape)
```

### 4.2 BatchNorm 家族

对某个通道 $c$，批归一化使用小批样本及空间位置求均值和方差：

$$\mu_c=\frac{1}{m}\sum_{i=1}^{m}x_i,\qquad
\sigma_c^2=\frac{1}{m}\sum_{i=1}^{m}(x_i-\mu_c)^2,$$

$$y_i=\gamma_c\frac{x_i-\mu_c}{\sqrt{\sigma_c^2+\epsilon}}+\beta_c.$$

`BatchNorm1d(C)` 用于 `(N,C)` 或 `(N,C,L)`；`BatchNorm2d(C)` 用于 `(N,C,H,W)`；`BatchNorm3d(C)` 用于 `(N,C,D,H,W)`。训练阶段用当前小批统计量，并更新 `running_mean`、`running_var`；评估阶段默认使用运行统计量。更新式为：

$$\widehat\mu\leftarrow(1-\alpha)\widehat\mu+\alpha\mu_{batch},$$

其中 `momentum=α`，它不是优化器中的动量概念。小批计算的方差采用有偏形式，而保存到 `running_var` 的方差使用无偏估计。

```python
bn = nn.BatchNorm2d(3, eps=1e-5, momentum=0.1, affine=True)
images = torch.randn(8, 3, 16, 16)
bn.train(); y_train = bn(images)
print(y_train.shape, bn.running_mean.shape)  # (8, 3, 16, 16), (3,)
bn.eval(); y_eval = bn(images)
```

`SyncBatchNorm` 在多进程多卡训练时把各进程的统计量合并后再计算；单卡场景一般用 `BatchNorm`。`LazyBatchNorm1d/2d/3d` 在首次输入时自动得到通道数。

### 4.3 InstanceNorm、GroupNorm、LayerNorm 与 LRN

| 模块 | 统计量的计算范围 | 仿射参数形状 | 适用情况 |
| --- | --- | --- | --- |
| `InstanceNorm1d/2d/3d` | 每个样本、每个通道的空间位置 | 每通道（`affine=True` 时） | 图像风格相关任务、样本间统计差异较大时 |
| `GroupNorm(G,C)` | 每个样本内，每组 $C/G$ 个通道及其空间位置 | 每通道 | 小批大小也稳定；`G=C` 类似 InstanceNorm，`G=1` 类似 LayerNorm |
| `LayerNorm(normalized_shape)` | 每个样本最后若干维 | 与 `normalized_shape` 相同 | Transformer、MLP |
| `LocalResponseNorm` | 同一位置邻近通道 | 无 | 早期视觉网络中按通道做局部抑制 |

它们的通用形式为：

$$y=\gamma\frac{x-\mu}{\sqrt{v+\epsilon}}+\beta.$$

差别只在 $\mu,v$ 的取样范围。`InstanceNorm` 默认 `track_running_stats=False`，训练与评估时均用当前输入统计量；可显式开启运行统计量。`LazyInstanceNorm1d/2d/3d` 会延迟确定通道数。

`LayerNorm` 的例子中，`normalized_shape=8` 表示每个 token 的最后 8 个数共同计算均值和方差：

```python
tokens = torch.randn(2, 5, 8)
ln = nn.LayerNorm(8)
gn = nn.GroupNorm(num_groups=2, num_channels=4)
print(ln(tokens).shape)                     # (2, 5, 8)
print(gn(torch.randn(2, 4, 6, 6)).shape)    # (2, 4, 6, 6)
```

#### 手算：BatchNorm 与 LayerNorm 到底在对哪些数求统计量

先忽略 `epsilon`，并取 `gamma=1`、`beta=0`。输入只有两个样本、两个特征：

$$
x=
\begin{bmatrix}
1 & 3\\
5 & 7
\end{bmatrix}.
$$

对 `BatchNorm1d(2)`，每一列代表一个特征通道，统计量跨样本计算：

$$
\mu=[3,5],\qquad v=[4,4].
$$

所以输出近似为：

$$
\begin{bmatrix}
(1-3)/2 & (3-5)/2\\
(5-3)/2 & (7-5)/2
\end{bmatrix}
=
\begin{bmatrix}
-1 & -1\\
1 & 1
\end{bmatrix}.
$$

对 `LayerNorm(2)`，每一行是一个样本，统计量在该样本的最后一维中计算。第一行的均值为 $2$、方差为 $1$；第二行的均值为 $6$、方差为 $1$，所以输出近似为：

$$
\begin{bmatrix}
-1 & 1\\
-1 & 1
\end{bmatrix}.
$$

也就是说，BatchNorm 的同一通道会比较不同样本，LayerNorm 的同一个样本会比较自己的各个特征。下面代码可直接看到近似结果：

```python
x_small = torch.tensor([[1., 3.], [5., 7.]])
bn_small = nn.BatchNorm1d(2, affine=False, track_running_stats=False)
ln_small = nn.LayerNorm(2, elementwise_affine=False)
bn_small.train()
print(bn_small(x_small))  # 约为 [[-1, -1], [1, 1]]
print(ln_small(x_small))  # 约为 [[-1,  1], [-1, 1]]
```

#### 同一张小图中，InstanceNorm 与 GroupNorm 分别统计哪些数

再取两个样本、两个通道，每个通道有两个空间位置：

$$
\text{样本 0:}\quad
\begin{cases}
\text{通道 0}=[1,3]\\
\text{通道 1}=[5,7]
\end{cases}
\qquad
\text{样本 1:}\quad
\begin{cases}
\text{通道 0}=[2,4]\\
\text{通道 1}=[6,8].
\end{cases}
$$

下表只列出“样本 0、通道 0”相关的统计范围：

| 层 | 用于统计均值、方差的数 | 均值 |
| --- | --- | ---: |
| `BatchNorm2d(2)` 的通道 0 | $[1,3,2,4]$ | $2.5$ |
| `InstanceNorm2d(2)` 的样本 0、通道 0 | $[1,3]$ | $2$ |
| `GroupNorm(2,2)` 的样本 0、第 0 组 | $[1,3]$ | $2$ |
| `GroupNorm(1,2)` 的样本 0 | $[1,3,5,7]$ | $4$ |

因此，`GroupNorm(2,2)` 在这个形状下每组只有一个通道，统计范围与 InstanceNorm 相同；`GroupNorm(1,2)` 把两个通道放进同一组。`LayerNorm((2,1,2))` 对样本 0 的统计范围也是 $[1,3,5,7]$，但它的可学习参数按完整的 `(2,1,2)` 形状保存，和 GroupNorm 的每通道参数不同。

`LocalResponseNorm(size, alpha, beta, k)` 的计算为：

$$b_c=k+\frac{\alpha}{size}\sum_{c'\in\mathcal N(c)}x_{c'}^2,\qquad
y_c=\frac{x_c}{b_c^{\beta}},$$

其中 $\mathcal N(c)$ 是以通道 $c$ 为中心、宽度为 `size` 的邻近通道集合。`CrossMapLRN2d` 是旧式二维 LRN 实现，现代模型通常优先使用 BatchNorm、GroupNorm 或 LayerNorm。

---

## 5. 卷积层

### 5.1 `Conv1d`、`Conv2d`、`Conv3d`

以二维卷积为例，输入为 `(N, C_in, H, W)`，权重为 `(C_out, C_in/groups, K_h, K_w)`。输出第 $o$ 个通道在位置 $(h,w)$ 的值为：

$$y_{n,o,h,w}=b_o+\sum_{i=0}^{C_{in}/g-1}\sum_{r=0}^{K_h-1}\sum_{s=0}^{K_w-1}
w_{o,i,r,s}\;x_{n,\,i+qC_{in}/g,\,h\cdot s_h-p_h+r\cdot d_h,\,w\cdot s_w-p_w+s\cdot d_w},$$

其中 $q$ 是输出通道所属的组，$s$ 为 stride，$p$ 为 padding，$d$ 为 dilation。超出原图范围的取值由填充给出，`padding_mode` 可选 `zeros`、`reflect`、`replicate`、`circular`。

每个空间维的输出长度为：

$$L_{out}=\left\lfloor\frac{L_{in}+2p-d(k-1)-1}{s}+1\right\rfloor.$$

`Conv1d` 只保留一个空间维；`Conv3d` 把同一规则扩展到深、高、宽。参数可以是一个整数，也可以是按各维给出的元组。

```python
conv = nn.Conv2d(
    in_channels=3, out_channels=16, kernel_size=3,
    stride=2, padding=1, dilation=1, groups=1, bias=True
)
x = torch.randn(4, 3, 32, 32)
print(conv(x).shape)  # (4, 16, 16, 16)
```

#### 手算：一个 `Conv2d` 输出元素如何得到

先只看单张、单通道、大小为 `3×3` 的输入，卷积核大小为 `2×2`，stride 为 1，没有 bias：

$$
x=
\begin{bmatrix}
1&2&3\\
4&5&6\\
7&8&9
\end{bmatrix},
\qquad
w=
\begin{bmatrix}
1&2\\
3&4
\end{bmatrix}.
$$

左上角输出只读取输入左上角的 `2×2` 小块：

$$
y_{0,0}=1\times1+2\times2+4\times3+5\times4=37.
$$

卷积核再向右移动一格时读取 $[2,3;5,6]$，结果为 $2+6+15+24=47$。四个位置都这样计算，因此输出是：

$$
y=
\begin{bmatrix}
37&47\\
67&77
\end{bmatrix}.
$$

PyTorch 的 `Conv2d` 按权重张量给出的顺序直接做乘加，不会先把卷积核旋转 180 度。

```python
x_small = torch.tensor([[[[1., 2., 3.],
                          [4., 5., 6.],
                          [7., 8., 9.]]]])
conv_small = nn.Conv2d(1, 1, kernel_size=2, bias=False)
with torch.no_grad():
    conv_small.weight.copy_(torch.tensor([[[[1., 2.], [3., 4.]]]]))
print(conv_small(x_small))
# tensor([[[[37., 47.],
#           [67., 77.]]]])
```

`groups` 控制通道连接方式：

| 设置 | 含义 |
| --- | --- |
| `groups=1` | 每个输出通道使用全部输入通道 |
| `groups=G` | 输入与输出通道各分为 `G` 组，只在组内计算 |
| `groups=C_in` 且 `C_out=K*C_in` | 深度卷积；每个输入通道有 `K` 个卷积核 |

#### 手算：`groups` 改变哪些通道会相加

取一个空间大小为 `1×1` 的双通道输入 $[2,10]$。若 `groups=1`，一个输出通道的两个权重为 $[3,4]$，则：

$$
y=2\times3+10\times4=46.
$$

若 `groups=2`，每个组只有一个输入通道和一个输出通道，第 0 组用权重 $3$，第 1 组用权重 $4$，则输出两个通道：

$$
[2\times3,\;10\times4]=[6,40].
$$

因此 `groups=2` 时，数字 2 与数字 10 不会在同一个输出通道中相加。深度卷积就是每组只有一个输入通道的特殊情况。

深度可分卷积常先做深度卷积，再用 `1×1` 卷积混合通道：

```python
depthwise_separable = nn.Sequential(
    nn.Conv2d(8, 8, 3, padding=1, groups=8),  # 深度卷积
    nn.Conv2d(8, 24, 1),                       # 逐点卷积
)
print(depthwise_separable(torch.randn(2, 8, 20, 20)).shape)  # (2, 24, 20, 20)
```

### 5.2 转置卷积 `ConvTranspose1d/2d/3d`

转置卷积不是普通卷积的数值逆运算。它使用与卷积矩阵转置相同的线性算子，常用于学习型上采样。以一维为例：

$$L_{out}=(L_{in}-1)s-2p+d(k-1)+\text{output\_padding}+1.$$

二维、三维分别对每个空间维应用该式。`output_padding` 只用于消除 stride 大于 1 时多个可能输出尺寸之间的歧义，不会在输出上额外填入数值。

```python
upconv = nn.ConvTranspose2d(16, 8, kernel_size=4, stride=2, padding=1)
feature = torch.randn(2, 16, 16, 16)
print(upconv(feature).shape)  # (2, 8, 32, 32)
```

#### 手算：转置卷积为什么会放大长度

使用一维例子更容易看清。令输入为 $[1,2]$，卷积核为 $[1,2,1]$，`stride=2`，没有 padding。输出长度为：

$$
(2-1)\times2+3=5.
$$

可以把每个输入数理解为生成一段加权结果，并按 stride 指定的间隔放到输出上：

$$
1\times[1,2,1]\rightarrow[1,2,1,0,0],
$$

$$
2\times[1,2,1]\rightarrow[0,0,2,4,2].
$$

两段结果在同一位置出现时相加，故最终输出为：

$$
[1,2,1,0,0]+[0,0,2,4,2]=[1,2,3,4,2].
$$

```python
x_1d = torch.tensor([[[1., 2.]]])
deconv = nn.ConvTranspose1d(1, 1, kernel_size=3, stride=2, bias=False)
with torch.no_grad():
    deconv.weight.copy_(torch.tensor([[[1., 2., 1.]]]))
print(deconv(x_1d))  # tensor([[[1., 2., 3., 4., 2.]]])
```

这说明转置卷积不是“把原图倒着还原”。它是一个可学习的上采样算子：相邻输入位置生成的结果可能相加，权重由训练得到。

#### `output_padding` 只决定输出尺寸

以 `kernel_size=2, stride=2` 的普通一维卷积为例，输入长度为 4 和 5 时，输出长度都可能为 2：

$$
\left\lfloor\frac{4-2}{2}+1\right\rfloor=2,
\qquad
\left\lfloor\frac{5-2}{2}+1\right\rfloor=2.
$$

因此，当转置卷积的输入长度为 2 时，硬件无法只从这个长度判断原输入是 4 还是 5。此时 `output_padding=0` 选择长度 4，`output_padding=1` 选择长度 5。它不在结果末尾写入一个固定数，只是选择哪一种合法的输出尺寸。

### 5.3 LazyConv 家族

`LazyConv1d/2d/3d` 与 `LazyConvTranspose1d/2d/3d` 只省去 `in_channels`，首次输入会确定它。其数学计算、其他构造参数和输出尺寸规则与对应的普通卷积完全一致。

```python
lazy_conv = nn.LazyConv2d(out_channels=12, kernel_size=3, padding=1)
print(lazy_conv(torch.randn(2, 5, 10, 10)).shape)  # 首次输入确定 in_channels=5
```

---

## 6. 池化、反池化、填充与空间重排

### 6.1 MaxPool、AvgPool 与 LPPool

`MaxPool1d/2d/3d` 在每个局部窗口取最大值：

$$y=\max_{u\in\mathcal W}x_u.$$

`AvgPool1d/2d/3d` 取窗口平均值：

$$y=\frac{1}{|\mathcal W|}\sum_{u\in\mathcal W}x_u.$$

`LPPool1d/2d(norm_type=p)` 为：

$$y=\left(\sum_{u\in\mathcal W}x_u^p\right)^{1/p}.$$

池化层的每个空间维输出长度同卷积公式。`MaxPool` 的 `return_indices=True` 会同时返回最大值的位置索引，供 `MaxUnpool` 使用；`ceil_mode=True` 允许窗口从左侧起点开始但在右侧未完整覆盖时仍产生输出。

```python
x = torch.tensor([[[[1., 2., 3., 4.],
                    [5., 6., 7., 8.],
                    [2., 1., 0., 3.],
                    [4., 2., 1., 0.]]]])
pool = nn.MaxPool2d(2, stride=2, return_indices=True)
values, indices = pool(x)
print(values)  # [[[[6., 8.], [4., 3.]]]]
print(nn.AvgPool2d(2)(x))
```

#### 按窗口看：MaxPool 和 AvgPool 到底保留了什么

上面输入是一个 `4×4` 图，`kernel_size=2`、`stride=2`，因此它被分成四个互不重叠的窗口：

| 窗口位置 | 窗口中的数 | MaxPool 输出 | AvgPool 输出 |
| --- | --- | ---: | ---: |
| 左上 | $\begin{bmatrix}1&2\\5&6\end{bmatrix}$ | $6$ | $(1+2+5+6)/4=3.5$ |
| 右上 | $\begin{bmatrix}3&4\\7&8\end{bmatrix}$ | $8$ | $5.5$ |
| 左下 | $\begin{bmatrix}2&1\\4&2\end{bmatrix}$ | $4$ | $2.25$ |
| 右下 | $\begin{bmatrix}0&3\\1&0\end{bmatrix}$ | $3$ | $1$ |

所以 MaxPool 输出为 $[[6,8],[4,3]]$。它只保留每个窗口中最大的数；AvgPool 则保留每个窗口的平均值。`indices` 记录的是最大数在原输入中的位置，而不是窗口内的第几个数。

### 6.2 自适应池化与分数最大池化

`AdaptiveAvgPool1d/2d/3d(output_size)`、`AdaptiveMaxPool1d/2d/3d(output_size)` 自动选择窗口，使输出空间尺寸严格等于 `output_size`。`output_size=1` 特别常见，它把任意 `H×W` 特征图变成每通道一个数：

$$y_{n,c}=\frac{1}{HW}\sum_{h,w}x_{n,c,h,w}.$$

```python
gap = nn.AdaptiveAvgPool2d((1, 1))
print(gap(torch.randn(3, 64, 7, 11)).shape)  # (3, 64, 1, 1)

adaptive_max = nn.AdaptiveMaxPool2d((3, 5), return_indices=True)
v, idx = adaptive_max(torch.randn(2, 4, 12, 16))
print(v.shape, idx.shape)  # 均为 (2, 4, 3, 5)
```

`FractionalMaxPool2d/3d` 以随机方式选择步幅不完全固定的池化窗口。可以设置 `output_size` 或 `output_ratio`，可选 `_random_samples` 以便复现窗口选择。它适合需要非整数缩小倍率的老式网络，通常不如自适应池化常用。

### 6.3 `MaxUnpool1d/2d/3d`

反池化把池化值放回 `indices` 指示的位置，其他位置填零。它不能复原被最大池化丢弃的非最大值。

```python
unpool = nn.MaxUnpool2d(2, stride=2)
restored = unpool(values, indices, output_size=x.shape)
print(restored)
# 只有原来每个 2×2 窗口的最大值位置保留数值
```

对上一个 `4×4` 输入，反池化的实际结果为：

$$
\begin{bmatrix}
0&0&0&0\\
0&6&0&8\\
0&0&0&3\\
4&0&0&0
\end{bmatrix}.
$$

例如数字 $6$ 回到左上窗口中的原位置（第 2 行、第 2 列），数字 $8$ 回到右上窗口中的原位置。窗口内原来不是最大值的数已经在 MaxPool 时丢失，因此反池化不能把它们补回来。

### 6.4 填充层

| 模块 | 填充内容 | 输入要求 |
| --- | --- | --- |
| `ConstantPad1d/2d/3d(padding, value)` | 常量 `value` | 对应维度的任意浮点或整数张量 |
| `ZeroPad2d(padding)` | 0 | 二维图像张量 |
| `ReflectionPad1d/2d/3d` | 以端点内侧的值反射 | 每侧填充量必须小于对应输入尺寸 |
| `ReplicationPad1d/2d/3d` | 重复最外侧数值 | 对应空间维 |

二维 `padding=(left, right, top, bottom)`。一维只给 `(left, right)`；三维给 `(left, right, top, bottom, front, back)`。例如：

```python
x = torch.tensor([[[[1., 2.], [3., 4.]]]])
print(nn.ZeroPad2d((1, 2, 1, 0))(x).shape)           # (1, 1, 3, 5)
print(nn.ReflectionPad2d(1)(x))
print(nn.ConstantPad2d(1, value=-1.)(x))
```

需要循环式填充时可调用 `F.pad(x, pad, mode="circular")`；卷积自身也可以设置 `padding_mode="circular"`。

### 6.5 `Unfold` 与 `Fold`

这一对层最容易混淆。可以先记一句话：

- `Unfold`：把每个滑动窗口**复制出来，并排成一列**。
- `Fold`：把这些列还原成窗口，并按原位置**逐项相加**。

它们只处理四维图像张量 `(N,C,H,W)`。`Unfold`（也称 im2col）从输入提取局部块，输出为：

$$\text{patches}\in\mathbb R^{N\times(CK_hK_w)\times L},$$

其中：

- $C K_hK_w$ 是每个窗口展开后的长度；
- $L$ 是窗口个数；
- 输出的最后一维每一列对应一个窗口。

它能把卷积改写成“局部块矩阵乘权重矩阵”。下面用最小的二维例子把每一步写出来。

#### 第一步：`Unfold` 如何把窗口排成列

令输入为一个单通道 `3×3` 图，卷积窗口大小为 `2×2`、stride 为 1：

$$
x=
\begin{bmatrix}
1&2&3\\
4&5&6\\
7&8&9
\end{bmatrix}.
$$

窗口一共有四个，按从左到右、从上到下的顺序为：

| 列编号 | 取到的窗口 | 展开后的列 |
| --- | --- | --- |
| 0 | $\begin{bmatrix}1&2\\4&5\end{bmatrix}$ | $[1,2,4,5]^T$ |
| 1 | $\begin{bmatrix}2&3\\5&6\end{bmatrix}$ | $[2,3,5,6]^T$ |
| 2 | $\begin{bmatrix}4&5\\7&8\end{bmatrix}$ | $[4,5,7,8]^T$ |
| 3 | $\begin{bmatrix}5&6\\8&9\end{bmatrix}$ | $[5,6,8,9]^T$ |

因此 `Unfold` 的结果形状是 `(1,4,4)`。去掉 batch 维后，它是下面这个矩阵；**每一列就是一个窗口**：

$$
\begin{bmatrix}
1&2&4&5\\
2&3&5&6\\
4&5&7&8\\
5&6&8&9
\end{bmatrix}.
$$

#### 第二步：为什么 `Unfold` 能用于卷积

继续使用卷积核：

$$
w=
\begin{bmatrix}
1&0\\
0&-1
\end{bmatrix}
\quad\Longrightarrow\quad
w_{\mathrm{flat}}=[1,0,0,-1].
$$

将这个长度为 4 的行向量乘上上面的 `Unfold` 结果：

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

再把这四个数按 `2×2` 摆回去，正好就是 `Conv2d` 的输出：

$$
\begin{bmatrix}
-4&-4\\
-4&-4
\end{bmatrix}.
$$

这就是“卷积可写成矩阵乘”的具体含义：`Unfold` 负责整理窗口，矩阵乘负责对每个窗口做乘加。

#### 第三步：`Fold` 为什么不会总是直接还原原图

`Fold(output_size, kernel_size)` 接收形状 `(N,C K_hK_w,L)` 的列，把每列看回一个窗口并放回对应位置。这里四个 `2×2` 窗口会在中间位置重叠，例如中心数字 $5$ 出现在四个窗口中，所以 `Fold` 会把四个 $5$ 相加。

对上面的 `Unfold` 结果执行 `Fold`，得到：

$$
\operatorname{Fold}(\operatorname{Unfold}(x))=
\begin{bmatrix}
1&4&3\\
8&20&12\\
7&16&9
\end{bmatrix}.
$$

每个位置被窗口覆盖的次数是：

$$
\operatorname{divisor}=
\begin{bmatrix}
1&2&1\\
2&4&2\\
1&2&1
\end{bmatrix}.
$$

所以应逐元素相除，才能得到原输入：

$$
\operatorname{Fold}(\operatorname{Unfold}(x))
=\operatorname{divisor}\odot x.
$$

```python
x = torch.tensor([[[[1., 2., 3.],
                    [4., 5., 6.],
                    [7., 8., 9.]]]])
unfold = nn.Unfold(kernel_size=2, stride=1)
patches = unfold(x)
print(patches.shape)  # torch.Size([1, 4, 4])
print(patches[0])
# tensor([[1., 2., 4., 5.],
#         [2., 3., 5., 6.],
#         [4., 5., 7., 8.],
#         [5., 6., 8., 9.]])

# 使用 Unfold 结果完成一次 2×2 卷积
kernel_flat = torch.tensor([1., 0., 0., -1.])
conv_out = (kernel_flat.unsqueeze(0) @ patches[0]).reshape(1, 1, 2, 2)
print(conv_out[0, 0])
# tensor([[-4., -4.],
#         [-4., -4.]])

fold = nn.Fold(output_size=(3, 3), kernel_size=2, stride=1)
summed = fold(patches)
divisor = fold(unfold(torch.ones_like(x)))
print(summed[0, 0])
# tensor([[ 1.,  4.,  3.],
#         [ 8., 20., 12.],
#         [ 7., 16.,  9.]])
print(divisor[0, 0])
# tensor([[1., 2., 1.],
#         [2., 4., 2.],
#         [1., 2., 1.]])
print(summed / divisor)  # 恢复为原始 x
```

若窗口彼此不重叠且完整覆盖输入，例如 `4×4` 输入配合 `kernel_size=2, stride=2`，每个位置的覆盖次数都为 1，此时 `Fold(Unfold(x))` 才会直接等于 $x$。

### 6.6 `PixelShuffle`、`PixelUnshuffle`、`ChannelShuffle`

`PixelShuffle(r)` 将通道中的子像素重排到空间维：

$$ (N, C r^2, H, W)\rightarrow(N,C,Hr,Wr).$$

`PixelUnshuffle(r)` 是反向重排：

$$ (N,C,Hr,Wr)\rightarrow(N,C r^2,H,W).$$

它们不引入参数，常用于超分辨率或无插值下采样。`ChannelShuffle(g)` 先把通道视作 `(g,C/g)`，交换这两个通道轴，再展平；常与分组卷积配合以让不同组的特征在下一层相互混合。

```python
x = torch.randn(2, 12, 5, 7)
up = nn.PixelShuffle(2)(x)
back = nn.PixelUnshuffle(2)(up)
print(up.shape, torch.equal(x, back))  # (2, 3, 10, 14), True
print(nn.ChannelShuffle(groups=3)(torch.randn(2, 12, 5, 5)).shape)
```

#### 手算：`PixelShuffle(2)` 改变的是位置，不是数值

取最小输入 `(N,C,H,W)=(1,4,1,1)`，四个通道的数依次为 $10,20,30,40$。因为放大倍率 $r=2$，输入通道数 $4$ 恰好等于输出通道数 $1$ 乘 $r^2$：

$$
[10,20,30,40]\longrightarrow
\begin{bmatrix}
10&20\\
30&40
\end{bmatrix}.
$$

```python
x_small = torch.tensor([[[[10.]], [[20.]], [[30.]], [[40.]]]])
y_small = nn.PixelShuffle(2)(x_small)
print(y_small.shape)   # torch.Size([1, 1, 2, 2])
print(y_small[0, 0])
# tensor([[10., 20.],
#         [30., 40.]])
```

这里没有插值、平均或乘法，四个数完全不变，只是从通道维重新排到高和宽。`PixelUnshuffle(2)` 会把这个 `2×2` 图重新放回四个通道。

### 6.7 `Upsample` 与旧式上采样模块

`Upsample(size=None, scale_factor=None, mode=...)` 按指定目标尺寸或倍率放大张量。最近邻插值只是复制相邻值；双线性插值以四个邻点的加权平均求值。二维双线性插值可写为：

$$y(i,j)=\sum_{a\in\{0,1\}}\sum_{b\in\{0,1\}}w_{ab}x(i_a,j_b),\qquad\sum w_{ab}=1.$$

`mode` 可为 `nearest`、`linear`、`bilinear`、`bicubic`、`trilinear` 等。`align_corners` 仅适用于线性类插值：为 `True` 时，输入与输出最角落像素的中心对齐；为 `False` 时按像素方块几何关系计算，改变尺寸时通常更一致。

```python
feature = torch.randn(2, 8, 7, 9)
nearest = nn.Upsample(scale_factor=2, mode="nearest")
bilinear = nn.Upsample(size=(20, 24), mode="bilinear", align_corners=False)
print(nearest(feature).shape)   # (2, 8, 14, 18)
print(bilinear(feature).shape)  # (2, 8, 20, 24)
```

`UpsamplingNearest2d` 和 `UpsamplingBilinear2d` 是兼容旧代码的专用版本，功能分别对应 `Upsample(mode="nearest")` 与 `Upsample(mode="bilinear", align_corners=True)`；新代码优先写 `Upsample` 或 `F.interpolate`。

---

## 7. 词表层与循环序列层

### 7.1 `Embedding`

`Embedding(num_embeddings, embedding_dim)` 保存查找表

$$E\in\mathbb R^{V\times D},$$

输入的整数索引 $i$ 输出第 $i$ 行 $E_i$。输入形状为任意整数张量 `(*)`，输出为 `(*, D)`。输入必须是 `torch.long` 或 `torch.int` 类型，不能直接传 one-hot 浮点张量。

```python
embed = nn.Embedding(num_embeddings=1000, embedding_dim=32, padding_idx=0)
token_ids = torch.tensor([[0, 15, 42], [9, 2, 0]], dtype=torch.long)
vectors = embed(token_ids)
print(vectors.shape)             # (2, 3, 32)
print(vectors[0, 0])             # padding_idx 对应行默认全零
```

`padding_idx` 对应行不参与梯度更新；`max_norm` 会在前向计算中把被访问行的范数限制到给定值；`scale_grad_by_freq=True` 使频繁出现的词得到按频次缩小的梯度；`sparse=True` 产生稀疏梯度，优化器需支持它（如 `SparseAdam`）。

### 7.2 `EmbeddingBag`

`EmbeddingBag` 直接对一袋索引向量做 `sum`、`mean` 或 `max` 聚合，不需要先创建所有单词向量再做归约。对第 $b$ 个袋 $S_b$：

$$y_b=\sum_{i\in S_b}E_i\quad\text{或}\quad y_b=\frac{1}{|S_b|}\sum_{i\in S_b}E_i.$$

二维输入中，每一行是一袋；一维扁平输入则用 `offsets` 指明每袋起点。

```python
bag = nn.EmbeddingBag(50, 8, mode="mean")
ids = torch.tensor([[1, 2, 3], [4, 5, 6]], dtype=torch.long)
print(bag(ids).shape)  # (2, 8)

flat_ids = torch.tensor([1, 2, 3, 4, 5], dtype=torch.long)
offsets = torch.tensor([0, 3], dtype=torch.long)  # 两袋：[1,2,3] 与 [4,5]
print(bag(flat_ids, offsets).shape)  # (2, 8)
```

#### 手算：`offsets` 怎样把一维索引分成多个袋

假设查找表中只关心以下四行：

$$
E=
\begin{bmatrix}
0&0\\
1&10\\
2&20\\
3&30
\end{bmatrix}.
$$

输入为 `ids=[1,2,3]`、`offsets=[0,2]`，并使用 `mode="mean"`。`offsets` 的含义是“每个袋从 `ids` 的哪个位置开始”：

- 第 0 个袋从位置 0 开始，到下一个起点位置 2 之前结束，因此它包含索引 $[1,2]$；
- 第 1 个袋从位置 2 开始，到 `ids` 末尾结束，因此它包含索引 $[3]$。

查表后：

$$
E_1=[1,10],\qquad E_2=[2,20],\qquad E_3=[3,30].
$$

两个袋的平均结果为：

$$
\operatorname{bag}_0=([1,10]+[2,20])/2=[1.5,15],
\qquad
\operatorname{bag}_1=[3,30].
$$

```python
weight = torch.tensor([[0., 0.], [1., 10.], [2., 20.], [3., 30.]])
bag_small = nn.EmbeddingBag.from_pretrained(weight, mode="mean", freeze=True)
ids = torch.tensor([1, 2, 3])
offsets = torch.tensor([0, 2])
print(bag_small(ids, offsets))
# tensor([[ 1.5000, 15.0000],
#         [ 3.0000, 30.0000]])
```

### 7.3 `RNN` 与 `RNNCell`

最简单的循环神经网络在第 $t$ 个位置计算：

$$h_t=\tanh(W_{ih}x_t+b_{ih}+W_{hh}h_{t-1}+b_{hh}).$$

`RNN(n_in, hidden_size, nonlinearity="tanh" | "relu")` 可堆叠多层、可双向。默认输入 `(L,N,H_in)`，若 `batch_first=True` 则为 `(N,L,H_in)`。输出 `output` 包含每个位置最后一层的隐藏状态；`h_n` 包含每层、每个方向的最后隐藏状态。

```python
rnn = nn.RNN(6, 10, num_layers=2, batch_first=True, bidirectional=True)
seq = torch.randn(3, 5, 6)
output, h_n = rnn(seq)
print(output.shape, h_n.shape)  # (3, 5, 20), (4, 3, 10)

cell = nn.RNNCell(6, 10)
h = torch.zeros(3, 10)
for x_t in seq.unbind(dim=1):
    h = cell(x_t, h)
print(h.shape)  # (3, 10)
```

#### 手算：`RNNCell` 的前一时刻状态如何参与下一步

把所有向量缩成一个数，令 $x_t=1$、$h_{t-1}=0.5$、$W_{ih}=2$、$W_{hh}=0.4$，两个 bias 都为 0。则：

$$
h_t=\tanh(2\times1+0.4\times0.5)=\tanh(2.2)\approx0.976.
$$

下一步若 $x_{t+1}=0$，仍然会使用刚得到的 $h_t$：

$$
h_{t+1}=\tanh(2\times0+0.4\times0.976)
=\tanh(0.3904)\approx0.372.
$$

这就是循环层的核心：当前输入和上一时刻状态共同决定新状态。真实网络只是把这些标量换成向量和矩阵。

双向时输出最后一维是 `2*hidden_size`，而 `h_n` 的第 0 维为 `num_layers * 2`。若输入中不同样本有效长度不同，可使用 `pack_padded_sequence`，避免对填充位置做无意义计算。

### 7.4 `GRU` 与 `GRUCell`

GRU 使用更新门 $z_t$ 和重置门 $r_t$：

$$r_t=\sigma(W_{ir}x_t+b_{ir}+W_{hr}h_{t-1}+b_{hr}),$$
$$z_t=\sigma(W_{iz}x_t+b_{iz}+W_{hz}h_{t-1}+b_{hz}),$$
$$n_t=\tanh(W_{in}x_t+b_{in}+r_t\odot(W_{hn}h_{t-1}+b_{hn})),$$
$$h_t=(1-z_t)\odot n_t+z_t\odot h_{t-1}.$$

`GRU` 的输入、`batch_first`、`num_layers`、`bidirectional` 语义与 RNN 一致；返回 `(output, h_n)`。`GRUCell` 只计算一个时间步，输入 `(N,H_in)`，状态 `(N,H_hidden)`。

```python
gru = nn.GRU(6, 10, batch_first=True, dropout=0.1, num_layers=2)
output, h_n = gru(torch.randn(3, 5, 6))
print(output.shape, h_n.shape)  # (3, 5, 10), (2, 3, 10)
```

#### 手算：GRU 的更新门决定保留多少旧状态

GRU 最后一式为：

$$
h_t=(1-z_t)n_t+z_t h_{t-1}.
$$

若旧状态 $h_{t-1}=0.8$、候选新状态 $n_t=0.2$、更新门 $z_t=0.75$，则：

$$
h_t=(1-0.75)\times0.2+0.75\times0.8=0.65.
$$

这里 $z_t$ 越接近 1，输出越接近旧状态；$z_t$ 越接近 0，输出越接近候选新状态。例如改为 $z_t=0.1$ 时，$h_t=0.26$。这正是 GRU 能按需保留历史信息的原因。

注意：RNN、GRU、LSTM 的 `dropout` 只放在相邻循环层之间；`num_layers=1` 时该参数没有作用。

### 7.5 `LSTM` 与 `LSTMCell`

LSTM 维护隐藏状态 $h_t$ 与记忆状态 $c_t$。令 $\sigma$ 为 Sigmoid，$\odot$ 为逐元素乘：

$$i_t=\sigma(W_{ii}x_t+b_{ii}+W_{hi}h_{t-1}+b_{hi}),$$
$$f_t=\sigma(W_{if}x_t+b_{if}+W_{hf}h_{t-1}+b_{hf}),$$
$$g_t=\tanh(W_{ig}x_t+b_{ig}+W_{hg}h_{t-1}+b_{hg}),$$
$$o_t=\sigma(W_{io}x_t+b_{io}+W_{ho}h_{t-1}+b_{ho}),$$
$$c_t=f_t\odot c_{t-1}+i_t\odot g_t,\qquad h_t=o_t\odot\tanh(c_t).$$

`LSTM` 返回 `output, (h_n, c_n)`。设置 `proj_size=P>0` 时，内部记忆宽度仍为 `hidden_size`，但输出隐藏向量会投影为 $P$ 维，相关权重名为 `weight_hr_l[k]`。

```python
lstm = nn.LSTM(6, 12, num_layers=2, batch_first=True, bidirectional=True)
output, (h_n, c_n) = lstm(torch.randn(3, 5, 6))
print(output.shape)  # (3, 5, 24)
print(h_n.shape)     # (4, 3, 12)
print(c_n.shape)     # (4, 3, 12)

cell = nn.LSTMCell(6, 12)
h, c = cell(torch.randn(3, 6), (torch.zeros(3, 12), torch.zeros(3, 12)))
```

#### 手算：LSTM 的四个门怎样更新记忆状态

实际 LSTM 先通过矩阵乘得到四个门的原始值。为了只看门控含义，令两个时间步的门值都为：

$$
i_t=f_t=o_t=0.5,\qquad g_t=\tanh(1)\approx0.7616,
$$

并从 $h_0=c_0=0$ 开始。第一个时间步：

$$
c_1=0.5\times0+0.5\times0.7616=0.3808,
$$

$$
h_1=0.5\times\tanh(0.3808)\approx0.1817.
$$

第二个时间步仍使用 $c_1$：

$$
c_2=0.5\times0.3808+0.5\times0.7616=0.5712,
$$

$$
h_2=0.5\times\tanh(0.5712)\approx0.2581.
$$

这里 $c_t$ 是用于长期保留信息的内部记忆，$h_t$ 是当前时间步向外给出的隐藏状态。遗忘门 $f_t$ 控制旧记忆保留多少，输入门 $i_t$ 控制候选内容写入多少，输出门 $o_t$ 控制从记忆中输出多少。真实层中这些门值由输入、上一时刻状态和可学习权重计算得到。

---

## 8. 注意力与 Transformer

### 8.1 `MultiheadAttention`

多头注意力先得到 Query、Key、Value：

$$Q=X_QW_Q,\qquad K=X_KW_K,\qquad V=X_VW_V.$$

第 $j$ 个头的宽度为 $d_h=E/h$，其输出为：

$$\operatorname{head}_j=\operatorname{Softmax}\left(\frac{Q_jK_j^T}{\sqrt{d_h}}+M\right)V_j,$$

$$\operatorname{MHA}=\operatorname{Concat}(\operatorname{head}_1,\ldots,\operatorname{head}_h)W_O.$$

`nn.MultiheadAttention(embed_dim=E, num_heads=h, batch_first=True)` 在自注意力中把同一个张量传给 `query`、`key`、`value`。`key_padding_mask` 形状为 `(N,S)`，其中 `True` 表示该 Key 位置应被忽略；浮点 `attn_mask` 加到注意力分数上，布尔 `attn_mask=True` 表示该位置不允许关注。

```python
mha = nn.MultiheadAttention(embed_dim=16, num_heads=4, batch_first=True)
x = torch.randn(2, 5, 16)
padding_mask = torch.tensor([[False, False, False, False, True],
                             [False, False, False, True, True]])
attended, weights = mha(x, x, x, key_padding_mask=padding_mask,
                        need_weights=True)
print(attended.shape, weights.shape)  # (2, 5, 16), (2, 5, 5)
```

#### 手算：三个 token 的单头注意力

为了只看注意力本身，令单头宽度 $d_h=2$，并人为令 Q、K、V 的投影矩阵和输出投影矩阵都是单位矩阵。三个 token 为：

$$
X=
\begin{bmatrix}
1&0\\
0&1\\
1&1
\end{bmatrix}.
$$

因此 $Q=K=V=X$。第 0 个 token 的 Query 与全部 Key 相乘，并除以 $\sqrt2$：

$$
\frac{q_0K^T}{\sqrt2}=[0.707,0,0.707].
$$

对这一行做 Softmax：

$$
\operatorname{Softmax}([0.707,0,0.707])
\approx[0.4011,0.1978,0.4011].
$$

它的输出是对三个 Value 的加权和：

$$
0.4011[1,0]+0.1978[0,1]+0.4011[1,1]
\approx[0.8022,0.5989].
$$

这表示第 0 个 token 同时读取三个 token 的信息，但给第 0 个和第 2 个 token 更大的权重。

因果掩码会阻止位置 $i$ 查看未来位置。例如第 1 个 token 原始分数为 $[0,0.707,0.707]$；第三个位置属于未来，加入掩码后变为：

$$
[0,0.707,-\infty].
$$

其权重与输出为：

$$
\operatorname{Softmax}([0,0.707,-\infty])
\approx[0.3302,0.6698,0],
$$

$$
0.3302[1,0]+0.6698[0,1]=[0.3302,0.6698].
$$

`key_padding_mask` 是按 Key 的列生效：一个填充位置会对所有 Query 都不可用；`attn_mask` 则可以指定每一对 Query 与 Key 是否允许互相关注。

因果自注意力中，第 $i$ 个位置不得看未来位置。可构造上三角掩码：

```python
L = 5
causal_mask = torch.triu(torch.full((L, L), float("-inf")), diagonal=1)
y, _ = mha(x, x, x, attn_mask=causal_mask)
```

### 8.2 `TransformerEncoderLayer` 与 `TransformerEncoder`

一个编码器层通常由“自注意力 + 残差 + 归一化”和“前馈网络 + 残差 + 归一化”组成。前馈网络为：

$$\operatorname{FFN}(x)=W_2\phi(W_1x+b_1)+b_2.$$

当 `norm_first=False`（默认）时，结构为：

$$z=\operatorname{LN}(x+\operatorname{Dropout}(\operatorname{MHA}(x))),$$
$$y=\operatorname{LN}(z+\operatorname{Dropout}(\operatorname{FFN}(z))).$$

当 `norm_first=True` 时，LayerNorm 放在每个子层之前。`TransformerEncoder` 将指定的 `TransformerEncoderLayer` 复制 `num_layers` 次；可选 `enable_nested_tensor` 对大量填充序列改善效率。

```python
encoder_layer = nn.TransformerEncoderLayer(
    d_model=16, nhead=4, dim_feedforward=64,
    dropout=0.1, batch_first=True, norm_first=True
)
encoder = nn.TransformerEncoder(encoder_layer, num_layers=3)
src = torch.randn(2, 7, 16)
src_padding = torch.tensor([[False] * 6 + [True], [False] * 7])
memory = encoder(src, src_key_padding_mask=src_padding)
print(memory.shape)  # (2, 7, 16)
```

#### 形状跟踪：一个 EncoderLayer 内部发生了什么

以本例的 `src.shape=(2,7,16)`、`nhead=4` 为例，内部主要张量形状如下：

| 阶段 | 形状 | 含义 |
| --- | --- | --- |
| 输入 token | $(2,7,16)$ | 2 个样本，每个 7 个 token，每个 token 16 维 |
| 每个头的 Q、K、V | $(2,4,7,4)$ | 16 维按 4 个头拆成每头 4 维 |
| 每个头的注意力权重 | $(2,4,7,7)$ | 每个 Query token 对 7 个 Key token 的权重 |
| 拼接后的注意力输出 | $(2,7,16)$ | 四个头拼回 16 维 |
| FFN 第一层输出 | $(2,7,64)$ | `dim_feedforward=64` |
| FFN 第二层输出 | $(2,7,16)$ | 回到模型宽度，便于做残差相加 |

残差相加要求两侧形状相同，因此注意力子层和 FFN 子层的最终输出都必须回到 $(2,7,16)$。

### 8.3 `TransformerDecoderLayer` 与 `TransformerDecoder`

解码器层依次含有：目标序列自注意力、目标对编码器输出的交叉注意力、前馈网络。交叉注意力使用目标表示作 $Q$，编码器输出作 $K,V$。`TransformerDecoder` 堆叠多个解码器层。

```python
decoder_layer = nn.TransformerDecoderLayer(
    d_model=16, nhead=4, dim_feedforward=64, batch_first=True
)
decoder = nn.TransformerDecoder(decoder_layer, num_layers=2)
tgt = torch.randn(2, 4, 16)
memory = torch.randn(2, 7, 16)
tgt_mask = torch.triu(torch.full((4, 4), float("-inf")), diagonal=1)
out = decoder(tgt, memory, tgt_mask=tgt_mask)
print(out.shape)  # (2, 4, 16)
```

#### 形状跟踪：Decoder 的自注意力和交叉注意力有什么不同

在上例中，`tgt` 的形状为 $(2,4,16)$，`memory` 的形状为 $(2,7,16)$，且 `nhead=4`。两种注意力的张量形状如下：

| 子层 | Query | Key / Value | 注意力权重 | 输出 |
| --- | --- | --- | --- | --- |
| 目标自注意力 | $(2,4,4,4)$ | $(2,4,4,4)$ | $(2,4,4,4)$ | $(2,4,16)$ |
| 交叉注意力 | $(2,4,4,4)$ | $(2,4,7,4)$ | $(2,4,4,7)$ | $(2,4,16)$ |

这里四维顺序是 $(N,\text{头数},\text{序列长度},\text{单头宽度})$。目标自注意力的 Query、Key、Value 都来自 `tgt`；交叉注意力的 Query 来自 `tgt`，Key 和 Value 来自 Encoder 输出 `memory`。因此 `tgt_mask` 的形状为 $(4,4)$，而若使用 `memory_mask`，它的形状应为 $(4,7)$。

### 8.4 完整 `Transformer`

`nn.Transformer` 是 Encoder 与 Decoder 的组合，输入 `src` 和 `tgt`，输出解码器表征。关键参数包括 `d_model`、`nhead`、编码器/解码器层数、`dim_feedforward`、`dropout`、`batch_first` 与 `norm_first`。

```python
transformer = nn.Transformer(
    d_model=16, nhead=4, num_encoder_layers=2,
    num_decoder_layers=2, dim_feedforward=64, batch_first=True
)
src = torch.randn(2, 7, 16)
tgt = torch.randn(2, 4, 16)
print(transformer(src, tgt).shape)  # (2, 4, 16)
```

位置位置信息不是 `nn.Transformer` 自动添加的；输入 embedding 前应自行加入可学习位置参数或正弦位置编码。

---

## 9. 损失函数与相似度模块

损失层返回一个标量或按样本返回的张量。大多数损失都有 `reduction="none" | "mean" | "sum"`：`none` 保留逐元素损失，`mean` 取平均，`sum` 求和。以下 $y$ 是目标值，$x$ 是模型输出；分类标签通常为整型类别编号。

### 9.1 回归与二值分类

| 模块 | 公式 | 输入与目标 |
| --- | --- | --- |
| `L1Loss` | $\lvert x-y\rvert$ | 同形状连续值 |
| `MSELoss` | $(x-y)^2$ | 同形状连续值 |
| `SmoothL1Loss(\beta)` | $0.5(x-y)^2/\beta$（$\lvert x-y\rvert<\beta$），否则 $\lvert x-y\rvert-0.5\beta$ | 对异常大误差较稳健 |
| `HuberLoss(\delta)` | $0.5(x-y)^2$（$\lvert x-y\rvert<\delta$），否则 $\delta(\lvert x-y\rvert-0.5\delta)$ | Huber 形式；与 SmoothL1 的缩放不同 |
| `BCELoss` | $-[y\log x+(1-y)\log(1-x)]$ | 输入必须是概率值 $(0,1)$ |
| `BCEWithLogitsLoss` | 同 BCE，但内部以稳定方式处理 logits | 输入为未激活 logits；可用 `pos_weight` 处理类别不均衡 |
| `GaussianNLLLoss` | $\frac12[\log(\max(v,\epsilon))+(x-y)^2/\max(v,\epsilon)]$ | 预测均值 `x`、方差 `v` 与目标 `y` |
| `PoissonNLLLoss` | $\exp(x)-yx$（`log_input=True`） | 计数目标；常数项可由 `full=True` 加入 |

```python
pred = torch.tensor([0.2, -1.0], requires_grad=True)
target = torch.tensor([0.0, 1.0])
print(nn.MSELoss()(pred, target))

logits = torch.tensor([[2.0], [-1.0]], requires_grad=True)
labels = torch.tensor([[1.0], [0.0]])
loss = nn.BCEWithLogitsLoss(pos_weight=torch.tensor([2.0]))(logits, labels)
loss.backward()
```

`BCELoss` 之前必须显式做 `Sigmoid`；更推荐直接使用 `BCEWithLogitsLoss`，后者避免 `sigmoid` 后接近 0 或 1 时的数值问题。

### 9.2 多类别分类

`CrossEntropyLoss` 对类别 logits 计算：

$$\ell=-\log\frac{e^{x_y}}{\sum_{c=1}^{C}e^{x_c}}.$$

输入常为 `(N,C)` 或 `(N,C,d_1,...,d_k)`，整型目标形状为 `(N)` 或 `(N,d_1,...,d_k)`，每个值位于 `[0,C)`。它等价于 `LogSoftmax(dim=1)` 后接 `NLLLoss`。若目标本身是同形状的类别概率分布，也可直接传入软标签。

```python
logits = torch.tensor([[2.0, 0.1, -1.0], [0.0, 1.0, 2.0]], requires_grad=True)
labels = torch.tensor([0, 2])
ce = nn.CrossEntropyLoss(label_smoothing=0.1)
print(ce(logits, labels))

log_prob = F.log_softmax(logits, dim=1)
print(nn.NLLLoss()(log_prob, labels))
```

#### 手算：一个 `CrossEntropyLoss` 数值

若某个样本的 logits 为 $[2,1,0]$，正确类别是第 0 类，则：

$$
\operatorname{Softmax}([2,1,0])
\approx[0.665,0.245,0.090].
$$

损失只取正确类别的概率：

$$
\ell=-\log(0.665)\approx0.408.
$$

若模型把第 0 类的 logit 提高，正确类别的概率会变大，损失会变小。传给 `CrossEntropyLoss` 的应是原始 logits；该层内部已经完成 `LogSoftmax` 和取负对数。

| 模块 | 作用 |
| --- | --- |
| `NLLLoss` | 接收对数概率，目标是类别编号；`NLLLoss2d` 是旧名 |
| `MultiLabelSoftMarginLoss` | 每类独立的二值交叉熵，接收多热标签（0/1） |
| `MultiLabelMarginLoss` | 多标签排序损失；目标是一行类别编号，负数填充未使用位置 |
| `MultiMarginLoss` | 多类别间隔损失，输入为类别分数，目标为单一类别编号 |
| `AdaptiveLogSoftmaxWithLoss` | 面向超大词表的分层 Softmax，减少训练计算量 |

`AdaptiveLogSoftmaxWithLoss(in_features, n_classes, cutoffs)` 将词表按高频与低频区间分层。返回对象含 `.output`（目标词的对数概率）与 `.loss`；推理时可用 `.log_prob(x)` 得到完整词表对数概率，或用 `.predict(x)` 得到最高分的类别。

```python
adaptive = nn.AdaptiveLogSoftmaxWithLoss(
    in_features=32, n_classes=10000, cutoffs=[1000, 5000]
)
result = adaptive(torch.randn(4, 32), torch.tensor([4, 999, 2000, 9000]))
print(result.output.shape, result.loss.shape)  # (4,), 标量
```

### 9.3 概率分布与序列对齐

`KLDivLoss` 的常见输入是模型对数概率 `input=log p` 与目标概率 `target=q`：

$$D_{KL}(q\parallel p)=\sum_i q_i(\log q_i-\log p_i).$$

若 `log_target=True`，目标也应传入 $\log q$。当批大小不同时，`reduction="batchmean"` 与 KL 的数学定义更一致。

`CTCLoss` 用于输入时间长度与目标标签长度不一致、且没有逐位置对齐标注的序列任务。对所有能压缩成目标标签序列的路径 $\pi$ 求概率和：

$$\mathcal L_{CTC}=-\log\sum_{\pi\in\mathcal B^{-1}(y)}\prod_{t=1}^{T}p(\pi_t\mid x_t).$$

其中 blank 的类别编号由 `blank` 指定，$\mathcal B$ 会移除 blank 并合并连续重复标签。

#### 小例子：CTC 为什么要对多条路径求和

令 blank 为 $0$，标签 $A=1$、$B=2$，目标序列为 $[A,B]$，时间长度为 3。以下四条逐时刻路径在合并连续重复标签、再删除 blank 后，都会得到目标 $[A,B]$：

$$
[A,A,B],\qquad[A,0,B],\qquad[0,A,B],\qquad[A,B,B].
$$

因此 CTC 不只看其中一条路径，而是把所有这类路径的概率相加后再取负对数。它适合语音等任务：已知最终标签顺序，却不知道每个标签准确出现在哪个时间位置。

```python
# T=6，N=2，C=5；第 0 类留作 blank
log_probs = F.log_softmax(torch.randn(6, 2, 5), dim=2)
targets = torch.tensor([1, 2, 1, 3], dtype=torch.long)  # 扁平拼接的两个目标序列
input_lengths = torch.tensor([6, 6], dtype=torch.long)
target_lengths = torch.tensor([2, 2], dtype=torch.long)
ctc = nn.CTCLoss(blank=0, zero_infinity=True)
print(ctc(log_probs, targets, input_lengths, target_lengths))
```

### 9.4 排序、相似度与度量学习

| 模块 | 公式或含义 |
| --- | --- |
| `MarginRankingLoss(margin)` | $\max(0,-y(x_1-x_2)+m)$，$y\in\{-1,1\}$ |
| `HingeEmbeddingLoss(margin)` | $x$（$y=1$）；$\max(0,m-x)$（$y=-1$） |
| `SoftMarginLoss` | $\log(1+\exp(-yx))$，$y\in\{-1,1\}$ |
| `CosineEmbeddingLoss(margin)` | $1-\cos(x_1,x_2)$（$y=1$）；$\max(0,\cos(x_1,x_2)-m)$（$y=-1$） |
| `TripletMarginLoss(margin,p)` | $\max(\lVert a-p\rVert_p-\lVert a-n\rVert_p+m,0)$ |
| `TripletMarginWithDistanceLoss` | 与上一行相同，但距离函数可自定义 |
| `CosineSimilarity(dim)` | $\frac{x_1\cdot x_2}{\max(\lVert x_1\rVert_2\lVert x_2\rVert_2,\epsilon)}$ |
| `PairwiseDistance(p)` | $\lVert x_1-x_2+\epsilon e\rVert_p$ |

```python
anchor = torch.randn(4, 16)
positive = anchor + 0.05 * torch.randn(4, 16)
negative = torch.randn(4, 16)
triplet_loss = nn.TripletMarginLoss(margin=0.5)(anchor, positive, negative)
cos = nn.CosineSimilarity(dim=1)(anchor, positive)
dist = nn.PairwiseDistance(p=2)(anchor, negative)
print(triplet_loss, cos.shape, dist.shape)
```

`MultiMarginLoss` 的类别间隔形式为：

$$\ell=\frac{1}{C}\sum_{j\ne y}\max(0,m-x_y+x_j)^p.$$

`MultiLabelMarginLoss` 对每个正类 $y_j$ 和非正类 $i$ 累加 $\max(0,1-x[y_j]+x[i])$；目标数组中用负数标记未使用位置。

---

## 10. 一份可运行的图像分类例子

这段网络把前面的卷积、归一化、激活、池化、Dropout、Flatten、Linear 与 `CrossEntropyLoss` 放在一起。输入是 `(N,3,32,32)`，输出是 10 个类别的 logits。

```python
class SmallCNN(nn.Module):
    def __init__(self, n_classes=10):
        super().__init__()
        self.features = nn.Sequential(
            nn.Conv2d(3, 16, 3, padding=1),   # (N,16,32,32)
            nn.BatchNorm2d(16),
            nn.ReLU(),
            nn.MaxPool2d(2),                  # (N,16,16,16)
            nn.Conv2d(16, 32, 3, padding=1),  # (N,32,16,16)
            nn.GroupNorm(4, 32),
            nn.GELU(),
            nn.AdaptiveAvgPool2d(1),          # (N,32,1,1)
        )
        self.classifier = nn.Sequential(
            nn.Flatten(1),                    # (N,32)
            nn.Dropout(0.2),
            nn.Linear(32, n_classes),         # (N,10)
        )

    def forward(self, x):
        return self.classifier(self.features(x))

model = SmallCNN()
images = torch.randn(8, 3, 32, 32)
labels = torch.randint(0, 10, (8,))
logits = model(images)
loss = nn.CrossEntropyLoss()(logits, labels)
loss.backward()
print(logits.shape, loss.item())
```

关键检查项：卷积的输入通道应等于上一层输出通道；`GroupNorm` 的 `num_channels` 必须能被 `num_groups` 整除；分类标签是 `long` 类型且不应 one-hot；训练代码直接把 logits 传给 `CrossEntropyLoss`。

---

## 11. 版本兼容与非层工具

- `Module` 是所有模块的基类；`Container` 是历史容器基类，日常直接使用 `Sequential`、`ModuleList` 或 `ModuleDict`。
- `Parameter`、`ParameterList`、`ParameterDict` 用来登记可学习张量。`UninitializedParameter`、`UninitializedBuffer` 是 Lazy 模块在第一次输入前使用的内部对象。
- `RNNBase`、`RNNCellBase` 是 RNN 家族基类，应实例化 `RNN`、`GRU`、`LSTM` 或对应的 Cell。
- `DataParallel` 用于把一个模型复制到多张 GPU 执行，不属于网络层。新代码在多 GPU 训练中通常使用 `DistributedDataParallel`。
- `CrossMapLRN2d` 与 `NLLLoss2d` 主要为旧代码兼容而保留；新模型分别使用 `LocalResponseNorm` 和 `NLLLoss`。
- 除 `Module` 组织工具与损失函数外，本文列出的模块均可通过 `print(module)`、`named_parameters()`、`state_dict()` 查看其结构、参数与保存内容。

```python
layer = nn.Conv2d(3, 8, 3, padding=1)
print(layer)
for name, parameter in layer.named_parameters():
    print(name, parameter.shape)  # weight: (8,3,3,3), bias: (8,)
```

## 12. 选层速查

| 需求 | 优先选择 |
| --- | --- |
| 固定宽度特征变换 | `Linear` + `ReLU/GELU/SiLU` |
| 图像局部纹理 | `Conv2d`；小批时可配 `GroupNorm` |
| 变长离散词序列 | `Embedding` + `GRU/LSTM/TransformerEncoder` |
| token 间全局交互 | `MultiheadAttention` 或 `TransformerEncoderLayer` |
| 缩小任意尺寸特征图 | `AdaptiveAvgPool2d(1)` |
| 放大特征图 | `Upsample`、`ConvTranspose2d` 或 `PixelShuffle` |
| 单标签多类别 | logits + `CrossEntropyLoss` |
| 多标签分类 | logits + `BCEWithLogitsLoss` |
| 连续数值预测 | `MSELoss`、`L1Loss`、`SmoothL1Loss` 或 `HuberLoss` |
| 向量检索或人脸比对 | `CosineSimilarity`、`TripletMarginLoss` |

选择模块时，先写清输入/输出形状、参数量、训练与评估状态下的差异，再用一小批随机输入跑通前向和反向计算；这能及早发现通道数、类别维度、数据类型或掩码形状不匹配的问题。
