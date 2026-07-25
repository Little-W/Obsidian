# PyTorch 基础 Layer 全览

> 本文按本仓库已安装的 PyTorch 2.0.1 整理 `torch.nn` 中可直接用于搭建网络的基础模块。`torch.nn.functional` 中的同名函数通常与这些模块做同一种计算；模块形式会把可学习参数、运行统计量及训练状态保存到模型中。

> [!ABSTRACT] 本文怎样使用
> 这是一篇从张量形状出发的入门教程。第一次阅读可以先看每节的用途、形状表和引用框，再运行最小代码；需要手工推导时，再回到公式与数值例子。文中尽量把“层读取哪些数、怎样计算、输出放到哪里”逐项写清。

> [!TIP] 引用框的含义
> `NOTE` 补充概念，`TIP` 给出阅读或调试方法，`WARNING` 提醒常见错误，`EXAMPLE` 展开小例子，`QUESTION` 回答初学者常问的问题。只快速浏览引用框，也能复习各层最容易混淆的部分。

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

> [!NOTE] `*` 表示零个或多个前导维度
> `Linear` 的输入写成 `(*,H_in)`，表示最后一维必须是 `H_in`，前面可以没有维度，也可以有很多维。例如 `(8,)`、`(4,8)`、`(2,5,8)` 都能传给 `Linear(8,3)`，输出依次为 `(3,)`、`(4,3)`、`(2,5,3)`。

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

> [!WARNING] `eval()` 不等于关闭梯度
> `eval()` 只改变 Dropout、BatchNorm 等模块的工作方式，不会禁止 PyTorch 保存反向计算所需的数据。推理时仍应配合 `torch.inference_mode()`；回到训练前再调用 `model.train()`。

### 1.3 本文覆盖范围

下表给出全文目录。`DataParallel`、`Parameter`、`UninitializedParameter` 等属于并行执行或参数管理工具，不是对输入做特征变换的层，放在最后说明。`NLLLoss2d` 是 `NLLLoss` 的旧别名。

| 类别      | 覆盖的模块                                                                                                            |
| ------- | ---------------------------------------------------------------------------------------------------------------- |
| 组织与形状   | `Module`、`Sequential`、`ModuleList`、`ModuleDict`、`ParameterList`、`ParameterDict`、`Identity`、`Flatten`、`Unflatten` |
| 线性与激活   | `Linear`、`Bilinear`、所有逐元素激活、`GLU`、Softmax 家族                                                                     |
| 正则化与归一化 | Dropout 家族、Batch/Instance/Group/Layer/Local Response Norm、`SyncBatchNorm`                                        |
| 卷积与空间运算 | Conv/ConvTranspose/LazyConv 家族、池化、反池化、填充、`Unfold`、`Fold`、像素重排、上采样、通道洗牌                                           |
| 序列与注意力  | `Embedding`、`EmbeddingBag`、RNN/GRU/LSTM 及 Cell、Multi-Head Attention、Transformer 家族                               |
| 损失与度量   | 回归、分类、概率分布、排序、度量学习损失，以及 `CosineSimilarity`、`PairwiseDistance`、`AdaptiveLogSoftmaxWithLoss`                       |

### 1.4 阅读复杂层的通用方法

复杂层第一次看不懂通常不是公式本身太难，而是没有同时看清“输入怎么分块、每一块做了什么、结果放到哪里”。阅读下文的复杂层时，按下面四步检查：

1. **先写形状**：例如图像写成 `(N,C,H,W)`，序列写成 `(N,S,E)`。先确定哪个维度是批、通道、空间位置或时间位置。
2. **取一个最小例子**：把大张量缩成一个通道、两三个位置，手工列出本层实际读取的数。
3. **逐步计算一个输出元素**：卷积看一个窗口，Softmax 看一行，LSTM 看一个时间步，注意力看一个 Query。
4. **检查结果形状和数据去向**：有的层只改数值，有的层改尺寸，有的层会把局部块展开成列，有的层会把列累加回平面。

本文在卷积、归一化、池化、`Unfold/Fold`、`EmbeddingBag`、LSTM、注意力和分类损失处补充了小型手算例子。它们都刻意使用小整数或两三个 token；理解过程后，再把同一规则扩展到真实形状即可。

### 1.5 Parameter、buffer 与普通成员变量

一个 `nn.Module` 不只保存计算函数，还会保存不同性质的数据。理解它们的区别，才能看懂参数更新、模型保存和设备切换。

| 数据类型 | 典型例子 | 优化器是否更新 | 是否进入 `state_dict()` | 调用 `.to(device)` 是否跟随移动 |
| --- | --- | --- | --- | --- |
| `nn.Parameter` | Linear 的 `weight`、`bias` | 是 | 是 | 是 |
| buffer | BatchNorm 的 `running_mean` | 否 | 默认是 | 是 |
| 普通 Python 成员 | 层数、字符串配置 | 否 | 否 | 不适用 |
| 未登记的普通张量成员 | 手工写的 `self.some_tensor` | 否 | 否 | 否 |

`Parameter` 是需要通过梯度学习的张量。下面把一个 3 维向量登记成参数：

```python
class ScaleLayer(nn.Module):
    def __init__(self):
        super().__init__()
        self.scale = nn.Parameter(torch.ones(3))

    def forward(self, x):
        return x * self.scale

layer = ScaleLayer()
x = torch.tensor([[1., 2., 3.]])
loss = layer(x).sum()
loss.backward()
print(layer.scale.grad)  # tensor([1., 2., 3.])
```

梯度说明“损失对参数做微小改变时会怎样变化”。在这个例子中：

$$
\text{loss}=1\gamma_0+2\gamma_1+3\gamma_2,
$$

所以三个偏导数就是 $[1,2,3]$。

> [!NOTE] `requires_grad=True` 与 `nn.Parameter` 不完全相同
> 普通张量即使开启梯度，也不会自动出现在 `model.parameters()` 中。优化器通常从 `model.parameters()` 接收待更新对象，因此模型成员中的可学习张量应登记为 `nn.Parameter`。

buffer 适合“需要随模型保存和移动，但不通过梯度学习”的数据：

```python
class RunningCounter(nn.Module):
    def __init__(self):
        super().__init__()
        self.register_buffer("forward_count", torch.zeros((), dtype=torch.long))

    def forward(self, x):
        if self.training:
            self.forward_count += 1
        return x

counter = RunningCounter()
_ = counter(torch.randn(2, 3))
print(counter.forward_count)            # tensor(1)
print(counter.state_dict().keys())      # odict_keys(['forward_count'])
```

`register_buffer(..., persistent=False)` 可以让 buffer 跟随设备移动，却不写入 `state_dict()`，适合可随时重新生成的临时数据。

> [!WARNING] 不要把需要跟随设备的张量只写成普通成员
> 若在 `__init__` 中写 `self.table = torch.randn(...)`，调用 `model.cuda()` 时它不会自动移动。应根据用途把它登记为 Parameter 或 buffer。

#### 1.5.1 `state_dict()` 里保存了什么

`state_dict()` 是“名称到张量”的有序字典，包含已登记参数和持久 buffer：

```python
model = nn.Sequential(
    nn.Linear(4, 3),
    nn.BatchNorm1d(3),
)

for name, value in model.state_dict().items():
    print(name, tuple(value.shape))
```

常见名称如下：

```text
0.weight
0.bias
1.weight
1.bias
1.running_mean
1.running_var
1.num_batches_tracked
```

名称中的数字来自 `Sequential` 中的模块位置。若使用带名字的 `OrderedDict` 或自定义成员名，名称会更易读。

保存与加载通常写为：

```python
torch.save(model.state_dict(), "model.pt")

restored = nn.Sequential(
    nn.Linear(4, 3),
    nn.BatchNorm1d(3),
)
restored.load_state_dict(torch.load("model.pt"))
```

> [!IMPORTANT] 先创建同样结构，再加载张量
> `state_dict` 只保存张量和少量附带信息，不会替你重新定义 Python 类。加载端要先构造参数名称与形状相符的模型。

#### 1.5.2 设备和数据类型必须相容

层参数和输入通常要位于同一设备，并具有可参与同一运算的数据类型：

```python
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model = nn.Linear(4, 2).to(device)
x = torch.randn(3, 4, device=device)
y = model(x)
```

若模型在 GPU、输入在 CPU，矩阵乘无法直接执行。常见做法是先确定 `device`，再让模型和每个小批都调用 `.to(device)`。

浮点层还可以改变参数类型：

```python
model = nn.Linear(4, 2).double()
x = torch.randn(3, 4, dtype=torch.float64)
print(model(x).dtype)  # torch.float64
```

整数 token 编号是例外：Embedding 的输入通常保持 `torch.long`，输出则使用嵌入表的浮点类型。

> [!TIP] 调试类型或设备错误先打印四项
> 打印 `x.shape`、`x.dtype`、`x.device`，再打印下一层参数的 `dtype` 和 `device`。许多看似复杂的运行错误都能由这几项直接定位。

#### 1.5.3 `train()` 会递归设置所有子模块

调用顶层 `model.train()` 会把它和所有子模块的 `training` 设为 `True`；`model.eval()` 等价于 `model.train(False)`，也会递归处理。

```python
model = nn.Sequential(
    nn.Linear(4, 4),
    nn.Dropout(0.5),
    nn.BatchNorm1d(4),
)

model.eval()
for name, module in model.named_modules():
    print(name or "<root>", module.training)
```

`named_modules()` 会列出顶层模块和全部已登记子模块；`named_parameters()` 只列可学习参数；`named_buffers()` 只列 buffer。

> [!SUMMARY] 阅读一个层时再加三项检查
> 除输入形状和输出形状外，还应检查：层是否含可学习参数，是否含运行数据，训练与评估是否执行不同规则。这三项会直接影响保存、加载和推理。

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

> [!WARNING] 普通 Python 列表不会逐项登记其中的模块
> 将若干层放进普通 `list` 后再赋给成员变量，PyTorch 不会把每个子层当作已登记模块。需要训练和保存这些子层时，应使用 `ModuleList`；如果还希望系统自动依次调用，则使用 `Sequential`。

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

> [!NOTE] `Unflatten` 只恢复形状，不理解各维含义
> 只要元素总数相等，它就能拆分维度，但不知道每一维代表通道、高还是宽。若尺寸顺序写错，代码仍可能执行，元素所代表的位置却已经不同。

### 2.3 从 `__init__` 到 `forward`：自定义层的完整阅读方法

自定义模块通常分成两个阶段：

1. `__init__`：声明长期保存的子层、参数、buffer 和配置；
2. `forward`：说明本次输入怎样经过这些对象得到输出。

```python
class ResidualMLP(nn.Module):
    def __init__(self, width):
        super().__init__()
        self.fc1 = nn.Linear(width, width * 2)
        self.act = nn.GELU()
        self.fc2 = nn.Linear(width * 2, width)

    def forward(self, x):
        residual = x
        x = self.fc1(x)
        x = self.act(x)
        x = self.fc2(x)
        return x + residual
```

若输入是 `(N,L,width)`：

| 步骤 | 形状 |
| --- | --- |
| 输入与 `residual` | `(N,L,width)` |
| `fc1` 后 | `(N,L,2×width)` |
| GELU 后 | 不变 |
| `fc2` 后 | `(N,L,width)` |
| 与 residual 相加 | `(N,L,width)` |

最后一层必须回到 `width`，否则无法逐元素相加。

> [!WARNING] 不要在 `forward` 中临时创建需要训练的 Linear
> 每次前向都写 `nn.Linear(...)(x)` 会产生一套新参数，优化器也不会稳定地更新同一个对象。需要学习的子层应在 `__init__` 中创建并赋给成员变量。

#### 2.3.1 为什么通常调用 `module(x)`，而不是 `module.forward(x)`

`module(x)` 会进入 `nn.Module.__call__`，再调用 `forward`。这个外层过程还会处理前向钩子、混合精度等模块机制。直接调用 `forward` 会跳过其中一部分功能。

```python
layer = nn.Linear(4, 2)
x = torch.randn(3, 4)
y = layer(x)  # 推荐
```

编写自定义层时负责实现 `forward`；使用层时调用模块对象。

#### 2.3.2 复用同一个模块与创建两个模块

下面两种写法含义不同：

```python
shared = nn.Linear(4, 4)
y_shared = shared(shared(x))

first = nn.Linear(4, 4)
second = nn.Linear(4, 4)
y_separate = second(first(x))
```

第一种两次使用同一套 `weight` 和 `bias`；第二种有两套互不相同的参数。参数共享可以减少参数量，但只有模型设计明确要求时才应使用。

> [!EXAMPLE] 怎样确认是否为同一个对象
> 可比较 `id(module)`，也可检查 `named_parameters()` 中出现几套名称。共享参数在优化器里只应登记一次。

#### 2.3.3 `Sequential`、`ModuleList` 与 `ModuleDict` 怎样选择

| 需求 | 容器 |
| --- | --- |
| 输入依次经过每个子层 | `Sequential` |
| 需要循环、跳层或按索引调用 | `ModuleList` |
| 需要按名称选择分支 | `ModuleDict` |
| 只保存若干可学习张量 | `ParameterList`、`ParameterDict` |

多分支例子：

```python
class MultiTaskHead(nn.Module):
    def __init__(self, width):
        super().__init__()
        self.heads = nn.ModuleDict({
            "classify": nn.Linear(width, 5),
            "score": nn.Linear(width, 1),
        })

    def forward(self, x):
        return {
            name: head(x)
            for name, head in self.heads.items()
        }

heads = MultiTaskHead(8)
result = heads(torch.randn(2, 8))
print(result["classify"].shape, result["score"].shape)
```

`ModuleDict` 负责登记，并不会自动决定使用哪个分支；选择过程仍由 `forward` 编写。

#### 2.3.4 `Flatten` 的起止维度要根据任务决定

对图像 `(N,C,H,W)`：

```python
x = torch.randn(2, 3, 4, 5)

print(nn.Flatten(1)(x).shape)     # (2, 60)
print(nn.Flatten(2)(x).shape)     # (2, 3, 20)
print(nn.Flatten(0, 1)(x).shape)  # (6, 4, 5)
```

- `Flatten(1)` 保留批维，把整张图变成每样本一个向量；
- `Flatten(2)` 保留批和通道，只合并空间维；
- `Flatten(0,1)` 连批与通道一起合并，通常只在明确需要时使用。

> [!WARNING] 分类网络中不要误把批维合并
> `nn.Flatten()` 的默认 `start_dim=1` 正适合常见图像分类。若写成 `Flatten(0)`，多个样本会合成一个长向量，后续层将失去样本分隔。

#### 2.3.5 前向钩子可用于观察形状

钩子适合调试，不必修改模块本身：

```python
def print_shape(module, inputs, output):
    in_shape = tuple(inputs[0].shape)
    out_shape = tuple(output.shape)
    print(module.__class__.__name__, in_shape, "->", out_shape)

model = nn.Sequential(
    nn.Linear(4, 8),
    nn.ReLU(),
    nn.Linear(8, 2),
)

handles = [
    module.register_forward_hook(print_shape)
    for module in model
]
_ = model(torch.randn(3, 4))
for handle in handles:
    handle.remove()
```

> [!TIP] 钩子用完要移除
> `register_forward_hook` 返回 handle。调试结束后调用 `handle.remove()`，避免重复登记后一次前向打印多遍，或长期保留不再需要的回调。

---

## 3. 仿射层与激活层

### 3.1 `Linear`、`LazyLinear` 与 `Bilinear`

`Linear(in_features, out_features, bias=True)` 对最后一维做仿射变换：

$$y=xW^T+b,$$

其中 $W\in\mathbb{R}^{H_{out}\times H_{in}}$，$b\in\mathbb{R}^{H_{out}}$。输入可为 `(*, H_in)`，输出为 `(*, H_out)`。

> [!EXAMPLE] `Linear` 会独立处理每个 token
> 输入 `(2,5,8)` 可表示 2 个样本、每个样本 5 个 token、每个 token 8 维。经过 `Linear(8,3)` 后得到 `(2,5,3)`。同一组权重会分别作用于 10 个 token；token 之间不会在这个线性层中交换信息。

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

> [!QUESTION] Softmax 的 `dim` 选错会发生什么？
> 对形状 `(N,C)` 的分类 logits，通常使用 `dim=1`，让每个样本的 `C` 个类别概率之和为 1。若误用 `dim=0`，得到的是同一类别在不同样本之间的比例，含义已经改变。

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

### 3.4 把常见激活函数放到同一组数字上比较

只看公式时，初学者很容易觉得“这些函数似乎都差不多”。更直观的办法，是让同一组输入分别通过不同激活函数。下面取

$$x=[-2,-1,0,1,2].$$

结果保留四位小数：

| $x$ | `ReLU` | `LeakyReLU(0.1)` | `Sigmoid` | `Tanh` | `GELU` | `SiLU` |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| $-2$ | $0$ | $-0.2$ | $0.1192$ | $-0.9640$ | $-0.0455$ | $-0.2384$ |
| $-1$ | $0$ | $-0.1$ | $0.2689$ | $-0.7616$ | $-0.1587$ | $-0.2689$ |
| $0$ | $0$ | $0$ | $0.5000$ | $0$ | $0$ | $0$ |
| $1$ | $1$ | $1$ | $0.7311$ | $0.7616$ | $0.8413$ | $0.7311$ |
| $2$ | $2$ | $2$ | $0.8808$ | $0.9640$ | $1.9545$ | $1.7616$ |

这张表可以这样读：

- `ReLU` 直接删去负值，正值原样保留；
- `LeakyReLU` 不完全删去负值，而是把负值缩小；
- `Sigmoid` 把任何实数压到 $(0,1)$，因此适合表示独立的二值概率；
- `Tanh` 把数值压到 $(-1,1)$，并且以零为中心；
- `GELU` 和 `SiLU` 都是平滑函数，小负值可能被保留，正值也不是简单截断。

```python
import torch
from torch import nn

x = torch.tensor([-2., -1., 0., 1., 2.])
layers = [
    nn.ReLU(),
    nn.LeakyReLU(negative_slope=0.1),
    nn.Sigmoid(),
    nn.Tanh(),
    nn.GELU(),
    nn.SiLU(),
]

for layer in layers:
    values = layer(x)
    print(f"{layer.__class__.__name__:>12s}: {values.tolist()}")
```

> [!NOTE] 激活层通常不负责改变特征个数
> 若输入形状是 `(4, 10, 32)`，逐元素激活后的形状仍是 `(4, 10, 32)`。它改变的是每个元素的数值。真正把最后一维从 32 改成 64 的通常是 `Linear(32,64)` 等含权重的层。

#### 3.4.1 为什么还要关心导数

训练时，自动求导需要把损失对输出的变化逐层传回参数。设激活函数为 $y=f(x)$，上一层收到的梯度会乘上 $f'(x)$。因此，函数值决定前向输出，导数决定反向信号能保留多少。

ReLU 的导数可写为

$$
f'(x)=
\begin{cases}
0,&x<0,\\
1,&x>0.
\end{cases}
$$

在 $x=0$ 处不可微，PyTorch 选用一个约定值处理，不妨碍自动求导。对负输入，导数为零，这个位置暂时不会把梯度传给前面的计算。`LeakyReLU(a)` 在负半轴的导数是 $a$，例如 $a=0.1$ 时还能传回原信号的十分之一。

Sigmoid 的导数是

$$\sigma'(x)=\sigma(x)\bigl(1-\sigma(x)\bigr).$$

它的最大值为 $0.25$，出现在 $x=0$。当 $x$ 很大或很小时，$\sigma(x)$ 接近 1 或 0，导数也接近 0。这个现象常称为激活饱和。Tanh 也有类似现象：

$$\frac{\mathrm{d}}{\mathrm{d}x}\tanh(x)=1-\tanh^2(x).$$

当输入绝对值很大时，Tanh 的导数变小。因此，在很深的前馈网络内部，通常不会把 Sigmoid 作为所有隐藏层的默认选择。它依然很适合二值输出、门控系数和需要限制到 $(0,1)$ 的中间值。

```python
import torch
from torch import nn

x = torch.tensor([-6., -2., 0., 2., 6.], requires_grad=True)
y = nn.Sigmoid()(x)
y.sum().backward()

print("输出:", y.detach())
print("导数:", x.grad)
```

> [!TIP] 不要只根据“新旧”选择激活函数
> 图像卷积网络常用 ReLU 或 SiLU；Transformer 常用 GELU；循环单元内部需要 Sigmoid 和 Tanh 来构造门。最终选择还要结合模型结构、数值范围、算力预算与实验结果。

#### 3.4.2 输出层是否需要激活函数

输出层的写法由任务和损失函数共同决定：

| 任务 | 模型最后一层通常输出 | 常配损失 |
| --- | --- | --- |
| 单标签多类别分类 | 任意实数 logits，不先做 Softmax | `CrossEntropyLoss` |
| 二分类 | 一个任意实数 logit，不先做 Sigmoid | `BCEWithLogitsLoss` |
| 多标签分类 | 每个标签一个 logit，不先做 Sigmoid | `BCEWithLogitsLoss` |
| 无限制回归 | 任意实数 | `MSELoss`、`L1Loss` |
| 要求预测为正数 | 可考虑 `Softplus` | 由任务定义 |

`BCEWithLogitsLoss` 已把 Sigmoid 与二元交叉熵合在一个数值更稳定的计算中。若模型先手动做 Sigmoid，再把结果传给它，就等于重复处理。`CrossEntropyLoss` 同样接收 logits，并在内部完成所需的对数概率计算。

> [!EXAMPLE] “logit” 是什么
> 模型给出 `[-1.2, 2.0, 0.3]` 时，这三个数还不是概率，可以为负，也不要求总和为 1。对它们沿类别维做 Softmax 后，才得到总和为 1 的三个类别概率。训练阶段保留 logits 交给损失函数，展示预测时再求概率。

#### 3.4.3 `inplace=True` 为什么要谨慎

部分激活层接受 `inplace=True`，例如 `nn.ReLU(inplace=True)`。它会尽量直接改写输入张量所占的存储空间，有时能少保留一份中间结果，但也会使调试和自动求导更复杂。

下面的写法会报错，因为叶子张量 `x` 需要梯度，却被原地修改：

```python
import torch
from torch import nn

x = torch.tensor([-1., 2.], requires_grad=True)
relu = nn.ReLU(inplace=True)

try:
    y = relu(x)
except RuntimeError as error:
    print(type(error).__name__, error)
```

残差结构也常需要保留激活前的值。如果一个分支原地改写了共享张量，另一个分支读到的就不再是原值。初学阶段建议使用默认的 `inplace=False`；只有确认该张量之后不再被其他计算使用，并且内存分析确实显示值得调整时，再考虑原地操作。

### 3.5 逐步计算 GLU 与数值稳定的 Softmax

先看 GLU。假设 `dim=1`，输入为

$$x=[2,-1,0,\ln 3].$$

它被等分为

$$a=[2,-1],\qquad b=[0,\ln 3].$$

因为 $\sigma(0)=0.5$、$\sigma(\ln 3)=0.75$，所以

$$
\operatorname{GLU}(x)
=a\odot\sigma(b)
=[2,-1]\odot[0.5,0.75]
=[1,-0.75].
$$

可以把 $a$ 理解为候选特征，把 $\sigma(b)$ 理解为位于 0 和 1 之间的开合程度。第二部分不是独立输出，而是调节第一部分保留多少。

```python
import math
import torch
from torch import nn

x = torch.tensor([[2., -1., 0., math.log(3.)]])
print(nn.GLU(dim=1)(x))  # tensor([[ 1.0000, -0.7500]])
```

再看 Softmax。对 logits $[1,2,0]$：

$$
e^1\approx2.718,\quad e^2\approx7.389,\quad e^0=1,
$$

$$
\operatorname{Softmax}([1,2,0])
\approx[0.2447,0.6652,0.0900].
$$

三个输出都为正，总和为 1，最大 logit 对应最大概率。若 logits 是 $[1001,1002,1000]$，直接计算指数可能超出浮点数可表示的范围。Softmax 对所有元素同时减去同一个数不改变结果，因此可先减去最大值 1002：

$$[1001,1002,1000]-1002=[-1,0,-2].$$

随后再计算指数，既得到相同概率，也避免巨大中间值。PyTorch 内部已经采用稳定算法，通常直接调用 `torch.softmax` 或 `nn.Softmax` 即可。

```python
import torch

small = torch.tensor([[1., 2., 0.]])
large = torch.tensor([[1001., 1002., 1000.]])
print(torch.softmax(small, dim=1))
print(torch.softmax(large, dim=1))  # 与上一行相同
```

> [!WARNING] Softmax 的每一个切片都必须有明确含义
> 对 `(N,L,C)` 的分类输出，`dim=-1` 表示每个 token 在 `C` 个类别之间分配概率；`dim=1` 则表示每个类别在 `L` 个位置之间分配比例。这两种计算都能运行，但回答的是不同问题。

---

## 4. 正则化与归一化

### 4.1 Dropout 家族

普通 `Dropout(p)` 在训练时为每个元素生成掩码 $m_i\sim\operatorname{Bernoulli}(1-p)$：

$$y_i=\frac{m_i}{1-p}x_i.$$

因此训练阶段的期望输出仍为 $x_i$；评估阶段直接返回 $x_i$。

> [!NOTE] “期望不变”不代表每次结果不变
> 当 `p=0.5` 时，保留下来的元素会除以 `0.5`，也就是乘 2。大量随机试验的平均输出接近原输入，但某一次前向计算仍可能出现较多的 0 或较多的 2。

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

除 LocalResponseNorm 外，BatchNorm、InstanceNorm、GroupNorm 与 LayerNorm 都可以写成下面的均值—方差形式：

$$y=\gamma\frac{x-\mu}{\sqrt{v+\epsilon}}+\beta.$$

这些层的主要差别是 $\mu,v$ 的取样范围，以及 $\gamma,\beta$ 的共享方式。LocalResponseNorm 不减均值、不计算方差，也没有 $\gamma,\beta$；它使用邻近通道的平方和缩放当前值。`InstanceNorm` 默认 `track_running_stats=False`，训练与评估时均用当前输入统计量；可显式开启运行统计量。`LazyInstanceNorm1d/2d/3d` 会延迟确定通道数。

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

### 4.4 多维张量进入归一化层后，究竟会发生什么

前面的公式适合建立第一印象，但初学者最容易卡住的问题通常不是“减均值、除标准差”本身，而是下面四件事：

1. 哪些元素放在一起计算均值和方差？
2. 哪些维度各自保留一套均值和方差？
3. 可学习参数 $\gamma$、$\beta$ 怎样加到多维输出上？
4. 训练状态与评估状态是否使用同一批统计数据？

> [!IMPORTANT] 先记住最重要的结论
> 绝大多数归一化层都不会改变输入形状。它们改变的是“哪些数互相比较，以及每个数怎样重新调整”。如果输入形状是 `[2, 3, 4, 5]`，输出通常仍是 `[2, 3, 4, 5]`。

#### 4.4.1 用“统计维度”和“保留维度”阅读公式

设输入张量为：

$$
x\in\mathbb R^{A_0\times A_1\times\cdots\times A_{p-1}}.
$$

$p$ 是张量的维数，$A_j$ 是第 $j$ 个维度的长度。例如图像张量 `(N,C,H,W)` 有四个维度，分别对应批、通道、高和宽。

某个归一化层会选出一组**统计维度** $\mathcal R$。对于不在 $\mathcal R$ 中的下标保持不变，把 $\mathcal R$ 中所有下标能够取到的元素放在一起。若这一组共有 $M$ 个元素，则：

$$
\mu=\frac{1}{M}\sum_{j=1}^{M}x_j,
\qquad
v=\frac{1}{M}\sum_{j=1}^{M}(x_j-\mu)^2,
$$

$$
\widehat x_j=\frac{x_j-\mu}{\sqrt{v+\epsilon}},
\qquad
y_j=\gamma\widehat x_j+\beta.
$$

这里：

| 符号 | 初学者可以怎样理解 |
| --- | --- |
| $\mathcal R$ | 哪些维度中的元素要放在一起计算 |
| $M$ | 当前这一组一共有多少个数 |
| $\mu$ | 当前这一组数的平均值 |
| $v$ | 当前这一组数的方差；衡量这些数离均值有多分散 |
| $\epsilon$ | 加在方差上的很小正数，避免除以零并改善数值稳定性 |
| $\widehat x$ | 减去均值并除以标准差后的中间结果 |
| $\gamma$ | 可学习的缩放参数 |
| $\beta$ | 可学习的平移参数 |
| $y$ | 层的最终输出 |

不参与统计的维度可以称为**保留维度**。每一种保留下标组合都有自己的一套 $\mu$ 和 $v$。

> [!TIP] 一个非常实用的阅读方法
> 先不要急着代入公式。先把某个输出元素的下标全部写出来，再问：“为了计算这个元素所用的均值，我能让哪些下标变化？”能变化的就是统计维度，必须固定的就是保留维度。

下面用常见形状做总览：

| 层与输入 | 统计时变化的下标 | 必须固定的下标 | 每套统计数据对应什么 |
| --- | --- | --- | --- |
| `BatchNorm1d`，`(N,C)` | $n$ | $c$ | 一个通道 |
| `BatchNorm1d`，`(N,C,L)` | $n,l$ | $c$ | 一个通道 |
| `BatchNorm2d`，`(N,C,H,W)` | $n,h,w$ | $c$ | 一个通道 |
| `BatchNorm3d`，`(N,C,D,H,W)` | $n,d,h,w$ | $c$ | 一个通道 |
| `InstanceNorm2d`，`(N,C,H,W)` | $h,w$ | $n,c$ | 一个样本中的一个通道 |
| `GroupNorm(G,C)`，`(N,C,H,W)` | 组内通道、$h,w$ | $n$、组号 | 一个样本中的一个通道组 |
| `LayerNorm(E)`，`(N,L,E)` | $e$ | $n,l$ | 一个样本中的一个 token |
| `LayerNorm((H,W))`，`(N,C,H,W)` | $h,w$ | $n,c$ | 一个样本中的一个通道平面 |

#### 4.4.2 “按维度计算”并不是把那个维度删除

例如 `LayerNorm(8)` 接收 `(N,L,8)`。最后一维的 8 个数一起计算均值和方差，但输出中这 8 个位置仍全部保留。归一化不是 `mean(dim=-1)` 那样把最后一维压成长度 1，而是先以 `keepdim=True` 的效果得到统计数据，再把结果用于原张量中的每个元素。

可以把一次计算想成：

```python
x = torch.randn(2, 5, 8)
mean = x.mean(dim=-1, keepdim=True)                 # (2, 5, 1)
var = x.var(dim=-1, unbiased=False, keepdim=True)  # (2, 5, 1)
y = (x - mean) / torch.sqrt(var + 1e-5)            # 广播后仍是 (2, 5, 8)
```

`mean` 的最后一维虽然是 1，但它可以在减法中自动扩展到 8 个位置。这个规则叫作广播。

> [!NOTE] 广播不是复制八份存储
> 可以把广播理解成“同一个统计值供八个位置使用”。底层实现不必真的先创建八份完全相同的数据，因此既便于书写，也避免了无意义的额外存储。

#### 4.4.3 归一化层通常只改数值，不改元素次序

BatchNorm、InstanceNorm、GroupNorm 和 LayerNorm 都会给输入中的每个元素产生一个对应输出。它们不会像卷积那样组合邻域形成新位置，也不会像池化那样减少空间尺寸。

`LocalResponseNorm` 也保持形状，但它与前四类不同：它不计算均值和方差，而是在同一空间位置查看邻近通道的平方和，再缩小当前通道的值。第 4.9 节会单独解释。

### 4.5 BatchNorm 如何处理二维、三维、四维和五维输入

BatchNorm 的核心规则可以压缩成一句话：

> [!NOTE] BatchNorm 的通道规则
> 固定通道下标 `C`，让批下标和所有空间下标变化，把得到的全部元素放在一起计算。每个通道各有一套均值、方差、`weight` 和 `bias`。

#### 4.5.1 `BatchNorm1d(C)` 接收二维输入 `(N,C)`

二维输入中没有额外的长度维。对通道 $c$：

$$
\mu_c=\frac{1}{N}\sum_{n=0}^{N-1}x_{n,c},
\qquad
v_c=\frac{1}{N}\sum_{n=0}^{N-1}(x_{n,c}-\mu_c)^2.
$$

例如：

$$
x=
\begin{bmatrix}
1&10\\
3&20\\
5&30
\end{bmatrix},
\qquad x.shape=(3,2).
$$

第 0 个通道使用 $[1,3,5]$，均值为 3；第 1 个通道使用 $[10,20,30]$，均值为 20。两个通道互不混合。

若暂时忽略 $\epsilon$，并令 `affine=False`，两个通道的结果都是：

$$
\left[-\sqrt{\frac32},\ 0,\ \sqrt{\frac32}\right]
\approx[-1.225,0,1.225].
$$

这是因为第二个通道恰好是第一个通道的 10 倍。减均值并除以各自标准差后，它们具有相同的相对分布。

> [!WARNING] 二维输入的第 0 维一定被当作批
> 对 `BatchNorm1d` 来说，二维形状 `(C,L)` 不表示“无批输入”，而会被解释为 `(N,C)`。因此它与 `InstanceNorm1d` 的无批形式不同，不能仅凭维数判断含义。

#### 4.5.2 `BatchNorm1d(C)` 接收三维输入 `(N,C,L)`

三维输入常见于一维信号和经过换轴的序列。此时：

$$
\mu_c=\frac{1}{NL}
\sum_{n=0}^{N-1}\sum_{l=0}^{L-1}x_{n,c,l},
$$

$$
v_c=\frac{1}{NL}
\sum_{n=0}^{N-1}\sum_{l=0}^{L-1}(x_{n,c,l}-\mu_c)^2.
$$

取 $N=2,C=2,L=3$：

$$
\begin{aligned}
\text{样本 0，通道 0}&=[1,2,3],&
\text{样本 0，通道 1}&=[10,20,30],\\
\text{样本 1，通道 0}&=[4,5,6],&
\text{样本 1，通道 1}&=[40,50,60].
\end{aligned}
$$

通道 0 的统计集合为 $[1,2,3,4,5,6]$：

$$
\mu_0=3.5,\qquad
v_0=\frac{17.5}{6}\approx2.9167,\qquad
\sqrt{v_0}\approx1.7078.
$$

通道 1 的统计集合为 $[10,20,30,40,50,60]$：

$$
\mu_1=35,\qquad
v_1\approx291.6667,\qquad
\sqrt{v_1}\approx17.078.
$$

忽略 $\epsilon$ 后，两个通道都会得到近似序列：

$$
[-1.464,-0.878,-0.293,\ 0.293,\ 0.878,\ 1.464].
$$

这六个输出会按原来的样本、通道和长度位置放回，形状仍为 `(2,2,3)`。

```python
x = torch.tensor([
    [[1., 2., 3.], [10., 20., 30.]],
    [[4., 5., 6.], [40., 50., 60.]],
])

bn = nn.BatchNorm1d(2, affine=False, track_running_stats=False)
y = bn(x)
print(y.shape)               # torch.Size([2, 2, 3])
print(y[:, 0, :].reshape(-1))
print(y[:, 1, :].reshape(-1))
```

> [!EXAMPLE] 怎样数出每个通道使用多少个元素
> 对 `(N,C,L)`，固定一个 `c` 后，`n` 有 `N` 种取值，`l` 有 `L` 种取值，所以每个通道使用 `N×L` 个元素。对 `(N,C,H,W)` 则是 `N×H×W` 个。

#### 4.5.3 序列 `(N,L,E)` 为什么经常需要换轴

很多序列模型在 `batch_first=True` 时使用：

$$
x.shape=(N,L,E),
$$

其中 $L$ 是 token 数，$E$ 是特征宽度。`BatchNorm1d(num_features)` 规定通道必须位于第 1 维，因此若希望把每个特征当作一个通道，应先变成 `(N,E,L)`：

```python
N, L, E = 4, 6, 8
x = torch.randn(N, L, E)
bn = nn.BatchNorm1d(E)

x_nel = x.transpose(1, 2)  # (N, E, L)
y_nel = bn(x_nel)
y = y_nel.transpose(1, 2)  # 回到 (N, L, E)
print(y.shape)             # torch.Size([4, 6, 8])
```

此时每个特征 $e$ 的均值和方差由所有样本、所有 token 共同提供：

$$
\mu_e=\frac{1}{NL}\sum_n\sum_l x_{n,l,e}.
$$

如果把 `(N,L,E)` 直接传给 `BatchNorm1d(L)`，代码可能正常执行，但层会把 token 位置 $L$ 当作通道，并跨批与特征维 $E$ 统计。这通常不是设计者想要的含义。

> [!WARNING] 形状恰好相等时更要小心
> 假设 `L=E=8`，把 `(N,L,E)` 直接传给 `BatchNorm1d(8)` 不会因尺寸不符而报错，但它统计的是第 1 维，也就是 token 位置。尺寸正确不等于含义正确。

> [!EXAMPLE] 同一个三维序列经过 BatchNorm 与 LayerNorm
> 设两个样本各有两个 token，每个 token 有两个特征：样本 0 为 `[[1,10],[3,30]]`，样本 1 为 `[[5,50],[7,70]]`。换轴后的 `BatchNorm1d(2)` 对特征 0 使用 `[1,3,5,7]`，均值为 4、方差为 5；对特征 1 使用 `[10,30,50,70]`，均值为 40、方差为 500。`LayerNorm(2)` 则分别处理 `[1,10]`、`[3,30]`、`[5,50]`、`[7,70]`，忽略 `eps` 与仿射参数时，每个 token 都得到 `[-1,1]`。两层输入和输出形状可以相同，但计算所用的数完全不同。

对带补齐位的文本批次还要考虑：BatchNorm 会把补齐位置也放入统计集合。即使后续注意力使用 mask，均值和方差已经受到补齐值影响。Transformer 因此更常使用只在每个 token 特征内部计算的 LayerNorm。

#### 4.5.4 `BatchNorm2d(C)` 接收四维图像 `(N,C,H,W)`

对每个通道 $c$：

$$
\mu_c=
\frac{1}{NHW}
\sum_{n=0}^{N-1}
\sum_{h=0}^{H-1}
\sum_{w=0}^{W-1}
x_{n,c,h,w}.
$$

方差也对同样的 $N\times H\times W$ 个元素计算。一个 RGB 批次 `(32,3,224,224)` 会得到 3 个均值和 3 个方差，而不是每张图 3 个，也不是每个像素 3 个。

`weight` 和 `bias` 的形状都是 `(C,)`。计算时可把它们想成：

$$
\gamma.shape=(1,C,1,1),\qquad
\beta.shape=(1,C,1,1),
$$

从而同一通道的所有样本和空间位置共享一对参数。

```python
x = torch.randn(8, 3, 16, 16)
bn = nn.BatchNorm2d(3)
y = bn(x)

print(y.shape)          # (8, 3, 16, 16)
print(bn.weight.shape)  # (3,)
print(bn.bias.shape)    # (3,)
```

> [!QUESTION] `BatchNorm2d` 会把图像展平成一条长向量吗？
> 概念上可以把一个通道的 `N×H×W` 个数列成一组来理解，但输出仍按原来的四维位置保存。实现也不要求真的创建一个长向量。

#### 4.5.5 `BatchNorm3d(C)` 接收五维体数据 `(N,C,D,H,W)`

五维输入常见于视频片段、医学体数据和三维卷积。对通道 $c$：

$$
\mu_c=
\frac{1}{NDHW}
\sum_n\sum_d\sum_h\sum_w x_{n,c,d,h,w}.
$$

这里 $D$ 可以表示深度，也可以表示帧数。BatchNorm 不关心它在业务中的名称，只依据维度位置执行计算。

| 模块 | 输入 | 每个通道用于统计的元素数 |
| --- | --- | ---: |
| `BatchNorm1d(C)` | `(N,C)` | $N$ |
| `BatchNorm1d(C)` | `(N,C,L)` | $NL$ |
| `BatchNorm2d(C)` | `(N,C,H,W)` | $NHW$ |
| `BatchNorm3d(C)` | `(N,C,D,H,W)` | $NDHW$ |

#### 4.5.6 训练状态、评估状态与运行统计量

训练状态下，BatchNorm 使用当前小批的 $\mu_{\text{batch}}$ 和 $v_{\text{batch}}$ 生成当前输出，同时更新 buffer：

$$
\text{running\_mean}
\leftarrow
(1-\alpha)\text{running\_mean}
+\alpha\mu_{\text{batch}}.
$$

`momentum=α` 控制新小批对运行统计量的影响。它与优化器里常见的 momentum 含义不同。`momentum=None` 表示使用累计平均，每一批的权重会随已处理批次数变化。

```python
bn = nn.BatchNorm1d(3, momentum=0.1)
bn.train()
_ = bn(torch.randn(16, 3))

print(bn.running_mean.shape)     # (3,)
print(bn.running_var.shape)      # (3,)
print(bn.num_batches_tracked)    # 已处理的小批数

bn.eval()
with torch.inference_mode():
    y = bn(torch.randn(4, 3))    # 使用 running_mean 与 running_var
```

当前小批前向计算中的方差使用 `unbiased=False` 的形式，也就是除以 $M$；写入 `running_var` 时使用无偏估计，也就是样本数足够时除以 $M-1$。初学阶段只需知道：手算当前输出时用除以 $M$ 的方差。

> [!WARNING] `eval()` 不会重新计算当前输入的均值
> 默认设置下，评估状态使用训练期间保存的运行统计量。因此，同一张图单独推理与放进更大的推理批次，BatchNorm 输出通常一致；训练状态下则可能不同。

若设置 `track_running_stats=False`，模块不保存运行均值和运行方差，训练与评估都会使用当前输入的统计数据。这样会使一个样本的输出可能受到同批其他样本影响，使用前应明确是否符合任务需求。

#### 4.5.7 为什么很小的小批可能出现问题

训练状态下，每个通道至少需要两个可用于统计的值。以下输入会报错：

```python
bn = nn.BatchNorm1d(4)
x = torch.randn(1, 4)  # 每通道只有一个值
# bn(x)  # ValueError: Expected more than 1 value per channel when training
```

但 `BatchNorm2d(4)` 接收 `(1,4,8,8)` 时，每个通道仍有 $1\times8\times8=64$ 个值，通常可以执行。能够执行并不代表统计数据一定足够可靠；空间尺寸逐渐缩到 `1×1` 时，小批大小的影响会更明显。

> [!TIP] 小批图像模型的常见选择
> 如果显存限制使每卡只能处理很少样本，可以考虑 GroupNorm。它不跨样本计算，因此不会随小批组成发生同样的变化。

#### 4.5.8 `SyncBatchNorm` 合并多进程中的统计数据

分布式训练时，普通 BatchNorm 默认只查看当前进程所持有的小批。`SyncBatchNorm` 会让参与训练的进程交换必要的统计数据，再使用合并后的均值和方差。

`SyncBatchNorm(C)` 接受形如 `(N,C,...)`、维数至少为 2 的输入。它固定通道 `C`，在参与同步的进程中，对批维与全部尾部维度共同统计。

例如 4 个进程各持有 2 张图，普通 BatchNorm 每次看到 2 张图及其空间位置；同步版本在统计意义上看到 8 张图及其空间位置。可使用：

```python
model = nn.SyncBatchNorm.convert_sync_batchnorm(model)
```

应在用 `DistributedDataParallel` 包装模型之前执行转换。PyTorch 2.0.1 只有训练状态会执行同步路径，该路径要求 CUDA，并采用每个进程一张 GPU 的方式。评估状态仍使用保存的运行统计量。

它会带来额外通信。它解决的是多进程之间统计数据彼此分离的问题，不会自动处理补齐 token、错误维度或不合适的通道定义。

> [!WARNING] SyncBatchNorm 不是普通单机代码的加速开关
> 未初始化分布式进程组时，它可以像普通 BatchNorm 那样执行；真正启用同步后会增加通信。只有确实需要跨进程合并统计数据时才使用。

### 4.6 LayerNorm 如何处理任意数量的前导维度

LayerNorm 的核心规则是：

> [!NOTE] LayerNorm 的末尾维度规则
> `normalized_shape` 有几个数，就从输入末尾取几个维度共同计算。输入前面可以有任意数量的维度，每一种前导下标组合都独立计算。

设：

```python
ln = nn.LayerNorm(normalized_shape)
```

若 `normalized_shape=(a_1,a_2,\ldots,a_D)`，输入最后 $D$ 个维度必须正好也是这些长度。对每一种前导下标组合，共有：

$$
M=\prod_{j=1}^{D}a_j
$$

个元素参与同一组统计。

#### 4.6.1 一维 `normalized_shape=E`：每个 token 独立处理

输入 `(N,L,E)` 配置 `LayerNorm(E)` 时，固定样本 $n$ 和 token 位置 $l$，只让特征下标 $e$ 变化：

$$
\mu_{n,l}
=\frac{1}{E}\sum_{e=0}^{E-1}x_{n,l,e},
$$

$$
v_{n,l}
=\frac{1}{E}\sum_{e=0}^{E-1}
(x_{n,l,e}-\mu_{n,l})^2.
$$

因此共有 $N\times L$ 套均值和方差。不同样本不混合，不同 token 也不混合。

取一个样本的三个 token，每个 token 有两个特征：

$$
x=
\begin{bmatrix}
1&3\\
2&6\\
10&14
\end{bmatrix},
\qquad x.shape=(1,3,2).
$$

三个 token 的均值分别为 $2,4,12$，方差分别为 $1,4,4$。忽略 $\epsilon$ 并关闭仿射参数后，输出为：

$$
\begin{bmatrix}
-1&1\\
-1&1\\
-1&1
\end{bmatrix}.
$$

```python
x = torch.tensor([[[1., 3.], [2., 6.], [10., 14.]]])
ln = nn.LayerNorm(2, elementwise_affine=False)
print(ln(x))
```

> [!NOTE] 序列长度可以变化
> `LayerNorm(E)` 只要求最后一维长度等于 `E`。同一个层可以先处理 `(2,10,E)`，再处理 `(5,37,E)`，因为批大小和 token 数都属于前导维度。

#### 4.6.2 多维 `normalized_shape`：最后多维一起计算

若输入为 `(N,C,H,W)`：

```python
ln_hw = nn.LayerNorm((H, W))
ln_chw = nn.LayerNorm((C, H, W))
```

两者差别很大：

| 设置 | 每一组共同统计的元素 | 共有多少组 | `weight` 形状 |
| --- | --- | ---: | --- |
| `LayerNorm((H,W))` | 同一样本、同一通道的整个平面 | $NC$ | `(H,W)` |
| `LayerNorm((C,H,W))` | 同一样本的全部通道和空间位置 | $N$ | `(C,H,W)` |

`LayerNorm((H,W))` 固定 $n,c$，对 $h,w$ 统计；`LayerNorm((C,H,W))` 只固定 $n$，对 $c,h,w$ 统计。虽然两者输出形状都与输入相同，但统计数据和参数数量都不同。

> [!WARNING] `LayerNorm(C)` 直接接收 `(N,C,H,W)` 通常不是按通道处理
> LayerNorm 总是检查最后一个维度。对 `(N,C,H,W)`，最后一维是 `W`。如果 `C!=W` 会报尺寸错误；如果碰巧 `C==W`，代码虽然能执行，却是在每一行的宽度方向统计。

#### 4.6.3 想对每个像素的通道做 LayerNorm，应先改成 channels-last

若目标是固定 $(n,h,w)$，让通道 $c$ 变化，应把输入从 `(N,C,H,W)` 改成 `(N,H,W,C)`：

```python
N, C, H, W = 2, 3, 4, 5
x = torch.randn(N, C, H, W)
ln_channel = nn.LayerNorm(C)

x_nhwc = x.permute(0, 2, 3, 1)     # (N, H, W, C)
y_nhwc = ln_channel(x_nhwc)
y = y_nhwc.permute(0, 3, 1, 2)     # (N, C, H, W)
```

此时每个像素位置独立使用自己的 $C$ 个通道值。换轴只改变维度次序，不改变元素值。

> [!TIP] `permute` 后是否需要 `contiguous`
> LayerNorm 本身通常可以处理非连续张量。若后续使用 `view` 或某些要求连续存储的算子，再调用 `contiguous()`。不要在不了解需要的情况下到处添加，它会产生一次实际的数据整理。

#### 4.6.4 LayerNorm 的参数为什么比 GroupNorm 更细

`LayerNorm((C,H,W))` 的 `weight`、`bias` 形状都是 `(C,H,W)`。每个通道和每个空间位置都有自己的 $\gamma$、$\beta$：

$$
y_{n,c,h,w}
=\gamma_{c,h,w}\widehat x_{n,c,h,w}
+\beta_{c,h,w}.
$$

相比之下，`GroupNorm(G,C)` 的参数只有 `(C,)`，同一通道在所有空间位置共享参数：

$$
y_{n,c,h,w}
=\gamma_c\widehat x_{n,c,h,w}
+\beta_c.
$$

即使 `GroupNorm(1,C)` 与 `LayerNorm((C,H,W))` 选取了相同的统计元素，它们在仿射参数上仍不完全相同。

#### 4.6.5 LayerNorm 不保存运行统计量

LayerNorm 始终使用当前输入中最后若干维的统计数据。它没有 `running_mean`、`running_var`，训练状态和评估状态的计算规则相同：

```python
ln = nn.LayerNorm(8)
x = torch.randn(2, 5, 8)

ln.train()
y_train = ln(x)
ln.eval()
y_eval = ln(x)

print(torch.allclose(y_train, y_eval))  # True
```

这里没有 Dropout 等随机层参与，所以同一输入的结果相同。梯度记录是否开启仍由 `torch.no_grad()` 或 `torch.inference_mode()` 决定。

#### 4.6.6 手工复现 `LayerNorm((H,W))`

下面把最后两个维度一起统计：

```python
x = torch.tensor([
    [
        [[1., 2.], [3., 4.]],
        [[10., 20.], [30., 40.]],
    ]
])  # (N=1, C=2, H=2, W=2)

mean = x.mean(dim=(-2, -1), keepdim=True)
var = x.var(dim=(-2, -1), unbiased=False, keepdim=True)
manual = (x - mean) / torch.sqrt(var + 1e-5)

layer = nn.LayerNorm((2, 2), elementwise_affine=False)
actual = layer(x)
torch.testing.assert_close(actual, manual)
```

第 0 个通道用 `[1,2,3,4]`，第 1 个通道用 `[10,20,30,40]`。两个通道分别计算，并不会把八个数放进同一组。

> [!QUESTION] 为什么归一化后不一定精确等于均值 0、方差 1？
> 首先，分母中加入了 $\epsilon$，所以方差很小时会有可见差异；其次，默认还会乘 $\gamma$、加 $\beta$；最后，BatchNorm 在评估状态可能使用保存的数据，而不是当前输入的数据。

### 4.7 InstanceNorm：每个样本、每个通道各算各的

InstanceNorm 的核心规则是：

> [!NOTE] InstanceNorm 的统计规则
> 固定样本下标 `N` 和通道下标 `C`，只让空间下标变化。不同样本不共享均值和方差，同一样本中的不同通道也不共享。

把一维、二维、三维版本写在一起：

| 模块 | 有批输入 | 无批输入 | 每一组使用的元素 |
| --- | --- | --- | --- |
| `InstanceNorm1d(C)` | `(N,C,L)` | `(C,L)` | 固定 $n,c$ 后的 $L$ 个数 |
| `InstanceNorm2d(C)` | `(N,C,H,W)` | `(C,H,W)` | 固定 $n,c$ 后的 $HW$ 个数 |
| `InstanceNorm3d(C)` | `(N,C,D,H,W)` | `(C,D,H,W)` | 固定 $n,c$ 后的 $DHW$ 个数 |

对二维图像：

$$
\mu_{n,c}
=\frac{1}{HW}
\sum_{h=0}^{H-1}\sum_{w=0}^{W-1}x_{n,c,h,w},
$$

$$
v_{n,c}
=\frac{1}{HW}
\sum_h\sum_w(x_{n,c,h,w}-\mu_{n,c})^2.
$$

总共有 $N\times C$ 套均值和方差。

#### 4.7.1 同一通道的两张图不会互相影响

设输入只有一个通道，两张图各有四个数：

$$
\text{样本 0}=
\begin{bmatrix}1&2\\3&4\end{bmatrix},
\qquad
\text{样本 1}=
\begin{bmatrix}100&200\\300&400\end{bmatrix}.
$$

第二张图恰好是第一张图的 100 倍。InstanceNorm2d 分别计算两张图：

$$
\mu_{0,0}=2.5,\qquad
\mu_{1,0}=250.
$$

忽略 $\epsilon$ 时，两张图在关闭仿射参数后会得到相同的标准化结果。使用默认 `eps=1e-5` 时结果几乎相同，但会有很小的数值差异，因为两张图的方差尺度不同。若把第二张图改成别的数，第一张图的输出仍不变。

```python
x = torch.tensor([
    [[[1., 2.], [3., 4.]]],
    [[[100., 200.], [300., 400.]]],
])

layer = nn.InstanceNorm2d(1, affine=False, track_running_stats=False)
y = layer(x)
print(y[0])
print(y[1])
```

而 BatchNorm2d 会把两张图同一通道的八个数放在一起，所以第一张图的结果会受到第二张图影响。

> [!EXAMPLE] 用切片直接表示统计集合
> 对 `(N,C,H,W)`，`InstanceNorm2d` 为 `x[n,c,:,:]` 计算；`BatchNorm2d` 为 `x[:,c,:,:]` 计算。一个固定 `n,c`，另一个只固定 `c`。

#### 4.7.2 `affine` 和 `track_running_stats` 的默认值

InstanceNorm 默认：

```python
affine=False
track_running_stats=False
```

因此默认没有可学习的 `weight`、`bias`，也不保存运行均值和运行方差。训练与评估都使用当前样本自己的空间统计数据。

若设置 `affine=True`，参数形状为 `(C,)`，同一通道在所有样本和空间位置共享 $\gamma_c,\beta_c$：

```python
layer = nn.InstanceNorm2d(3, affine=True)
print(layer.weight.shape, layer.bias.shape)  # (3,), (3,)
```

若设置 `track_running_stats=True`，训练时会更新每通道运行统计量，评估时默认使用保存的数据。这样评估规则会更接近 BatchNorm，但训练前向仍按每个样本、每个通道计算当前统计数据。

> [!WARNING] 不要只根据层名猜默认参数
> BatchNorm 默认 `affine=True`、`track_running_stats=True`；InstanceNorm 默认 `affine=False`、`track_running_stats=False`。两者的构造参数很相似，默认行为却不同。

#### 4.7.3 序列输入中，InstanceNorm 与 LayerNorm 做的不是一件事

假设序列形状为 `(N,L,E)`：

- `LayerNorm(E)`：固定样本和 token，对一个 token 的 $E$ 个特征计算。
- 将输入换成 `(N,E,L)` 后使用 `InstanceNorm1d(E)`：固定样本和特征，对该特征在 $L$ 个 token 上的数值计算。

```python
x = torch.randn(2, 6, 8)  # (N, L, E)

ln = nn.LayerNorm(8)
y_ln = ln(x)              # 每个 token 的 8 个特征一起计算

in1d = nn.InstanceNorm1d(8, affine=True)
y_in = in1d(x.transpose(1, 2)).transpose(1, 2)
# 每个样本、每个特征在 6 个 token 上一起计算
```

两种输出形状相同，但统计集合完全不同。

> [!QUESTION] `InstanceNorm1d` 为什么也要换轴？
> 它与 `BatchNorm1d` 一样要求通道位于第 1 维。差别在于 BatchNorm 跨样本和长度统计，InstanceNorm 只在每个样本内部跨长度统计。

#### 4.7.4 空间元素太少时会怎样

默认 InstanceNorm 使用 `track_running_stats=False`，训练与评估都依赖当前输入的空间统计。若每个通道只有一个空间元素，例如输入 `(N,C,1,1)`，两种状态都会报错，因为每个 `(n,c)` 都只有一个可用值。

只有先设置 `track_running_stats=True`，在具有多个空间元素的训练输入上积累运行数据，再切换到评估状态，模块才可以使用保存的统计量处理 `(N,C,1,1)`。

即使空间元素多于一个，如果某个样本某个通道内所有值完全相同，则 $v=0$。标准化中间结果会接近 0；若启用仿射参数，最终输出接近该通道的 $\beta_c$。

### 4.8 GroupNorm：先把通道分组，再在每个样本内计算

GroupNorm 只有一个通用模块：

```python
nn.GroupNorm(num_groups=G, num_channels=C)
```

它不区分一维、二维、三维，因为所有通道之后的维度都作为空间维参与统计。

> [!NOTE] GroupNorm 的形状拆分法
> 对 `(N,C,...)`，可以暂时把通道拆成 `(G,C/G)`，从而把输入看作 `(N,G,C/G,...)`。固定样本 `n` 和组号 `g`，让组内通道及全部空间下标变化。

必须满足：

$$
C\bmod G=0.
$$

也就是通道数必须能被组数整除。

#### 4.8.1 四维输入的公式

输入为 `(N,C,H,W)` 时，每组通道数为：

$$
C_g=\frac{C}{G}.
$$

固定样本 $n$ 和组 $g$，共有：

$$
M=C_gHW
$$

个元素参与计算：

$$
\mu_{n,g}
=\frac{1}{C_gHW}
\sum_{c\in g}\sum_h\sum_w x_{n,c,h,w}.
$$

一共得到 $N\times G$ 套均值和方差。批中其他样本不会参与。

例如输入 `(2,8,4,4)`，使用 `GroupNorm(4,8)`：

1. 每组有 $8/4=2$ 个通道。
2. 每个样本每组使用 $2\times4\times4=32$ 个元素。
3. 两个样本、四个组，共有 $2\times4=8$ 套统计数据。

#### 4.8.2 手算四个通道、两个组

取一个样本，四个通道，每个通道有两个位置：

$$
\begin{aligned}
c_0&=[1,3],&
c_1&=[5,7],\\
c_2&=[2,4],&
c_3&=[6,8].
\end{aligned}
$$

使用 `GroupNorm(2,4, affine=False)`：

- 第 0 组包含 $c_0,c_1$，统计集合为 $[1,3,5,7]$；
- 第 1 组包含 $c_2,c_3$，统计集合为 $[2,4,6,8]$。

两组方差都为 5，均值分别为 4 和 5。忽略 $\epsilon$ 后，第 0 组输出约为：

$$
[-1.342,-0.447,0.447,1.342],
$$

第 1 组也得到同样的相对数值。结果再按原通道和位置放回。

```python
x = torch.tensor([[
    [[1., 3.]],
    [[5., 7.]],
    [[2., 4.]],
    [[6., 8.]],
]])  # (1, 4, 1, 2)

gn = nn.GroupNorm(2, 4, affine=False)
print(gn(x))
```

> [!TIP] 组是连续划分的
> `GroupNorm(2,4)` 默认把通道 0、1 放进第 0 组，把通道 2、3 放进第 1 组。它不会自行寻找相似通道，也不会在每次前向时改变分组。

#### 4.8.3 两个特殊设置

当 `G=C` 时，每组只有一个通道，统计数据的选取方式与 InstanceNorm 相似：

```python
nn.GroupNorm(num_groups=C, num_channels=C)
```

当 `G=1` 时，所有通道位于同一组，每个样本独立对全部通道和空间位置计算：

```python
nn.GroupNorm(num_groups=1, num_channels=C)
```

第二种设置与 `LayerNorm((C,H,W))` 的统计集合相同，但参数仍不同：

| 层 | `weight` 形状 | 参数共享方式 |
| --- | --- | --- |
| `GroupNorm(1,C)` | `(C,)` | 同一通道的所有空间位置共享 |
| `LayerNorm((C,H,W))` | `(C,H,W)` | 每个通道、每个空间位置分别保存 |

此外，GroupNorm 默认 `affine=True`；InstanceNorm 默认 `affine=False`。所以“统计集合相似”并不代表两个模块可以在任何设置下直接替换。

#### 4.8.4 GroupNorm 不依赖小批组成

GroupNorm 不跨样本统计，也不保存运行均值和运行方差。训练与评估使用相同的当前输入计算规则：

```python
gn = nn.GroupNorm(4, 32)
print(gn.weight.shape)  # (32,)

x = torch.randn(2, 32, 8, 8)
gn.train()
y1 = gn(x)
gn.eval()
y2 = gn(x)
print(torch.allclose(y1, y2))  # True
```

它适合每卡样本数较少的卷积网络。组数是需要选择的超参数：组太多时，每组通道很少；组太少时，许多性质不同的通道会一起统计。常见设置是让每组包含固定数量的通道，但仍需结合通道数和任务测试。

> [!WARNING] `num_channels` 必须与实际第 1 维一致
> 输入 `(N,64,H,W)` 必须搭配 `num_channels=64`。如果前一层改变了通道数，GroupNorm 的构造参数也要同步修改。

PyTorch 2.0.1 还要求一次 GroupNorm 调用中每组可用的总元素数不能只有 1。检查量可写为：

$$
N\times\frac{C}{G}\times\text{空间元素数}.
$$

例如 `(1,C)` 配置 `GroupNorm(C,C)` 时该值为 1，会报错。即使某些更大批次能够执行，每个样本、每组若实际只有一个值，标准化中间结果也只能为 0，通常缺少有用变化。

### 4.9 LocalResponseNorm：同一位置查看邻近通道

`LocalResponseNorm(size, alpha, beta, k)` 与前面几类均值—方差归一化不同。对固定样本 $n$ 和固定空间位置，只在通道方向取以 $c$ 为中心的邻近通道：

$$
y_{n,c,\ldots}
=
\frac{x_{n,c,\ldots}}
{\left(
k+\frac{\alpha}{size}
\sum_{c'\in\mathcal N(c)}
x_{n,c',\ldots}^{2}
\right)^\beta}.
$$

公式中的省略号代表任意空间下标。例如四维图像中，它就是固定 $(n,h,w)$，查看相邻通道；不会查看旁边的像素。

#### 4.9.1 三个通道的数值例子

固定一个空间位置，三个通道值为：

$$
[x_0,x_1,x_2]=[1,2,3].
$$

设置：

$$
size=3,\quad \alpha=3,\quad \beta=1,\quad k=1.
$$

第 0 个通道可看到通道 0、1，平方和为 $1^2+2^2=5$：

$$
y_0=\frac{1}{1+(3/3)\times5}=\frac16.
$$

第 1 个通道可看到三个通道，平方和为 14：

$$
y_1=\frac{2}{1+14}=\frac{2}{15}.
$$

第 2 个通道可看到通道 1、2，平方和为 13：

$$
y_2=\frac{3}{1+13}=\frac{3}{14}.
$$

靠近通道序列两端时，不存在的通道可理解为贡献 0。该层没有可学习的 $\gamma,\beta$，也没有运行统计量，训练与评估规则相同。

```python
x = torch.tensor([[[[1.]], [[2.]], [[3.]]]])  # (1, 3, 1, 1)
lrn = nn.LocalResponseNorm(size=3, alpha=3.0, beta=1.0, k=1.0)
print(lrn(x).flatten())
# 约为 tensor([0.1667, 0.1333, 0.2143])
```

> [!NOTE] 不要把 LRN 与 LayerNorm 混为一类
> LRN 只利用相邻通道的平方和缩放当前值；LayerNorm 使用指定末尾维度的均值和方差。两者名字都含有 Norm，但计算过程明显不同。

`LocalResponseNorm` 要求输入至少有三个维度，常见形式为 `(N,C,L)`、`(N,C,H,W)` 或更高维。`size` 为奇数时邻近通道在左右两侧对称；在 PyTorch 2.0.1 中，`size` 为偶数时左侧会比右侧多取一个位置。通道两端缺少的位置按 0 处理，但分母仍除以完整的 `size`。

### 4.10 用同一个四维张量比较四类归一化

设：

$$
x.shape=(N=2,C=2,H=1,W=2),
$$

具体数值为：

$$
\begin{aligned}
\text{样本 0}:&\quad c_0=[1,3],\quad c_1=[5,7],\\
\text{样本 1}:&\quad c_0=[2,4],\quad c_1=[6,8].
\end{aligned}
$$

下表列出每种设置的全部统计集合：

| 设置 | 统计集合 | 统计数据组数 |
| --- | --- | ---: |
| `BatchNorm2d(2)` | $c_0:[1,3,2,4]$；$c_1:[5,7,6,8]$ | 2 |
| `InstanceNorm2d(2)` | 每个 `(n,c)` 的两个空间值 | $2\times2=4$ |
| `GroupNorm(1,2)` | 样本 0 用 `[1,3,5,7]`；样本 1 用 `[2,4,6,8]` | 2 |
| `GroupNorm(2,2)` | 与本例 InstanceNorm 的四组相同 | 4 |
| `LayerNorm((2,1,2))` | 与 `GroupNorm(1,2)` 的两组相同 | 2 |
| `LayerNorm((1,2))` | 与本例 InstanceNorm 的四组相同 | 4 |

虽然一些行选取了相同的数，但仿射参数形状可能不同：

| 设置 | $\gamma,\beta$ 形状 |
| --- | --- |
| BatchNorm2d | `(2,)` |
| InstanceNorm2d，`affine=True` | `(2,)` |
| GroupNorm | `(2,)` |
| `LayerNorm((2,1,2))` | `(2,1,2)` |
| `LayerNorm((1,2))` | `(1,2)` |

> [!IMPORTANT] 比较归一化层要看两件事
> 第一看哪些元素共同计算均值和方差；第二看 $\gamma,\beta$ 怎样共享。只比较第一项，容易误以为某些层完全相同。

下面用手工公式核对 PyTorch：

```python
x = torch.tensor([
    [[[1., 3.]], [[5., 7.]]],
    [[[2., 4.]], [[6., 8.]]],
])
eps = 1e-5

def standardize(x, dims):
    mean = x.mean(dim=dims, keepdim=True)
    var = x.var(dim=dims, unbiased=False, keepdim=True)
    return (x - mean) / torch.sqrt(var + eps)

# BatchNorm2d：统计 N、H、W
manual_bn = standardize(x, dims=(0, 2, 3))
actual_bn = nn.BatchNorm2d(
    2, eps=eps, affine=False, track_running_stats=False
)(x)
torch.testing.assert_close(actual_bn, manual_bn)

# InstanceNorm2d：统计 H、W
manual_in = standardize(x, dims=(2, 3))
actual_in = nn.InstanceNorm2d(
    2, eps=eps, affine=False, track_running_stats=False
)(x)
torch.testing.assert_close(actual_in, manual_in)

# GroupNorm(1,2)：每个样本统计 C、H、W
manual_gn1 = standardize(x, dims=(1, 2, 3))
actual_gn1 = nn.GroupNorm(1, 2, eps=eps, affine=False)(x)
torch.testing.assert_close(actual_gn1, manual_gn1)

# LayerNorm((2,1,2))：统计最后 C、H、W
actual_ln = nn.LayerNorm(
    (2, 1, 2), eps=eps, elementwise_affine=False
)(x)
torch.testing.assert_close(actual_ln, manual_gn1)
```

这段代码中所有层都关闭了仿射参数，所以可以直接与标准化中间结果比较。

#### 4.10.1 五维视频或体数据的具体统计集合

构造连续整数：

```python
x5 = torch.arange(
    2 * 4 * 2 * 2 * 2,
    dtype=torch.float32,
).reshape(2, 4, 2, 2, 2)
```

其形状为 `(N,C,D,H,W)=(2,4,2,2,2)`。连续存储下：

- 样本 0、通道 2 是 16 到 23；
- 样本 0、通道 3 是 24 到 31；
- 样本 1、通道 2 是 48 到 55。

围绕通道 2 比较：

| 层 | 统计集合 | 元素数 | 均值 | 方差 |
| --- | --- | ---: | ---: | ---: |
| `BatchNorm3d(4)` 的通道 2 | 16～23 与 48～55 | 16 | 35.5 | 261.25 |
| `InstanceNorm3d(4)` 的样本 0、通道 2 | 16～23 | 8 | 19.5 | 5.25 |
| `GroupNorm(2,4)` 的样本 0、第 1 组 | 16～31 | 16 | 23.5 | 21.25 |
| `LayerNorm((2,2,2))` 的样本 0、通道 2 | 16～23 | 8 | 19.5 | 5.25 |
| `LayerNorm((4,2,2,2))` 的样本 0 | 0～31 | 32 | 15.5 | 85.25 |

> [!NOTE] 五维输入没有引入新的计算原理
> 相比四维图像，它只是多了深度或时间维 `D`。BatchNorm3d 将 `N,D,H,W` 一起统计；InstanceNorm3d 在每个样本、每个通道内部统计 `D,H,W`；LayerNorm 仍只看 `normalized_shape` 指定的最后若干维。

### 4.11 $\gamma$、$\beta$ 与统计数据怎样在多维张量中广播

归一化层中常同时出现三类数据：

1. 可学习参数，例如 `weight` 和 `bias`；
2. 当前输入算出的均值与方差；
3. BatchNorm 可选的运行均值与运行方差。

它们的形状不一定与输入相同，但会依据广播规则作用到正确位置。

#### 4.11.1 各层的参数形状

| 模块 | 参数开关 | `weight`、`bias` 的形状 |
| --- | --- | --- |
| BatchNorm 家族 | `affine=True` | `(C,)` |
| SyncBatchNorm | `affine=True` | `(C,)` |
| InstanceNorm 家族 | `affine=True` | `(C,)` |
| GroupNorm | `affine=True` | `(C,)` |
| `LayerNorm(normalized_shape)` | `elementwise_affine=True` | 与 `normalized_shape` 完全相同 |
| LocalResponseNorm | 无 | 没有这两个参数 |

对 `(N,C,H,W)` 输入，形状为 `(C,)` 的参数可理解为 `(1,C,1,1)`。对 `(N,C,D,H,W)`，可理解为 `(1,C,1,1,1)`。

```python
x = torch.randn(2, 3, 4, 5)

gamma = torch.tensor([1.0, 2.0, 0.5]).view(1, 3, 1, 1)
beta = torch.tensor([0.0, 10.0, -1.0]).view(1, 3, 1, 1)

# 假设 normalized 已经是标准化中间结果
normalized = torch.randn_like(x)
y = gamma * normalized + beta
print(y.shape)  # (2, 3, 4, 5)
```

通道 0 使用 `gamma=1, beta=0`；通道 1 使用 `gamma=2, beta=10`；通道 2 使用 `gamma=0.5, beta=-1`。同一通道中的所有样本和位置共享。

> [!NOTE] GroupNorm 的参数不是每组一个
> `GroupNorm(4,32)` 会按 4 组计算统计数据，但仍保存 32 个缩放值和 32 个偏移值。组内不同通道可以学习不同参数。

#### 4.11.2 LayerNorm 的参数随 `normalized_shape` 增长

```python
ln_e = nn.LayerNorm(8)
ln_hw = nn.LayerNorm((4, 5))
ln_chw = nn.LayerNorm((3, 4, 5))

print(ln_e.weight.shape)    # (8,)
print(ln_hw.weight.shape)   # (4, 5)
print(ln_chw.weight.shape)  # (3, 4, 5)
```

`LayerNorm((3,4,5))` 有 $3\times4\times5=60$ 个 `weight` 和 60 个 `bias`。这些参数在前导维度上共享，例如输入 `(N,3,4,5)` 时，不同样本共享同一套 60 个参数。

> [!WARNING] 参数多不等于一定更好
> 把整个 `(C,H,W)` 写入 `normalized_shape` 会让参数依赖固定的空间尺寸，也会明显增加参数数量。若输入高宽可能变化，这种设置往往不合适。

#### 4.11.3 均值张量的形状能帮助理解广播

对 `x.shape=(N,C,H,W)`，使用 `keepdim=True` 后：

| 计算方式 | 均值形状 | 同一个均值供哪些位置使用 |
| --- | --- | --- |
| `x.mean((0,2,3), keepdim=True)` | `(1,C,1,1)` | BatchNorm2d 的一个通道 |
| `x.mean((2,3), keepdim=True)` | `(N,C,1,1)` | InstanceNorm2d 的一个样本、一个通道 |
| `x.mean((1,2,3), keepdim=True)` | `(N,1,1,1)` | LayerNorm `(C,H,W)` 或 GroupNorm 单组的一个样本 |
| `x.mean(1, keepdim=True)` | `(N,1,H,W)` | 手工计算每个像素的通道集合 |

最后一行只是帮助理解；对 channels-first 输入直接写 `x.mean(1)` 可以手算每像素通道统计，但 `nn.LayerNorm(C)` 仍要求先把通道移到最后。

### 4.12 方差、`eps`、常量输入与训练状态

#### 4.12.1 手工复现时为什么要写 `unbiased=False`

PyTorch 归一化层当前前向计算通常使用：

$$
v=\frac{1}{M}\sum_{i=1}^{M}(x_i-\mu)^2.
$$

对应：

```python
x.var(dim=dims, unbiased=False, keepdim=True)
```

BatchNorm 与 SyncBatchNorm 有一个容易混淆的细节：当前训练输出使用上述有偏形式，但更新 `running_var` 时使用无偏估计。后者在 $M>1$ 时以 $M-1$ 为除数。

InstanceNorm 开启 `track_running_stats=True` 后也有类似区别：当前输出仍使用每个样本空间元素的有偏方差；运行均值由各样本的通道均值汇总更新，运行方差由各样本的空间无偏方差汇总更新。默认 InstanceNorm 不追踪这些数据，因此初学时通常不会遇到这一细节。

| 模块 | 当前前向中的方差 |
| --- | --- |
| BatchNorm、SyncBatchNorm | `unbiased=False`；运行方差更新另有无偏换算 |
| InstanceNorm | `unbiased=False` |
| GroupNorm | `unbiased=False` |
| LayerNorm | `unbiased=False` |
| LocalResponseNorm | 不计算方差 |

> [!TIP] 对照模块时先关闭仿射参数和运行统计
> 例如 `BatchNorm2d(C, affine=False, track_running_stats=False)`，这样输出只由当前输入、方差公式和 `eps` 决定，更适合与手工结果核对。

#### 4.12.2 `eps` 在方差很小时尤其重要

若一组数据是：

$$
[5,5,5,5],
$$

则 $\mu=5,v=0$。加入 `eps` 后：

$$
\widehat x_i=\frac{5-5}{\sqrt{0+\epsilon}}=0.
$$

关闭仿射参数时输出全 0；有仿射参数时：

$$
y_i=\gamma\cdot0+\beta=\beta.
$$

所以“全零输入经过 LayerNorm 后一定还是全零”只在 $\beta=0$ 时成立。初始化时 LayerNorm 的 `bias` 通常是 0，但训练后它可以改变。

不要为了让数值“看起来更标准”而随意把 `eps` 改得极小。低精度训练或接近常量的数据更需要足够的数值保护。若没有明确实验依据，优先使用模块默认值。

#### 4.12.3 哪些层在 `train()` 与 `eval()` 下会改变

| 模块与设置 | 训练状态 | 评估状态 |
| --- | --- | --- |
| BatchNorm，默认追踪运行统计 | 当前小批；同时更新 buffer | 使用运行统计 |
| BatchNorm，`track_running_stats=False` | 当前输入 | 当前输入 |
| SyncBatchNorm，默认设置 | 训练时按参与进程合并 | 使用运行统计 |
| InstanceNorm，默认设置 | 当前样本 | 当前样本 |
| InstanceNorm，开启运行统计 | 当前样本并更新 buffer | 使用运行统计 |
| GroupNorm | 当前样本、当前组 | 同左 |
| LayerNorm | 当前输入最后若干维 | 同左 |
| LocalResponseNorm | 邻近通道平方和 | 同左 |

```python
layers = {
    "bn": nn.BatchNorm2d(3),
    "in": nn.InstanceNorm2d(3),
    "gn": nn.GroupNorm(1, 3),
    "ln": nn.LayerNorm((3, 4, 4)),
}

for name, layer in layers.items():
    print(name, list(layer.state_dict().keys()))
```

典型输出含义：

- BatchNorm：有 `weight`、`bias`、`running_mean`、`running_var`、`num_batches_tracked`；
- 默认 InstanceNorm：没有参数和运行统计，因此 `state_dict` 可为空；
- GroupNorm：有 `weight`、`bias`；
- LayerNorm：有 `weight`、`bias`。

> [!NOTE] buffer 会保存，但不会由优化器更新
> `running_mean` 和 `running_var` 会进入 `state_dict()`，因此保存模型时不会丢失；它们不是 `nn.Parameter`，优化器不会根据梯度修改它们。

#### 4.12.4 `model.eval()` 与停止梯度是两件事

```python
model.eval()
with torch.inference_mode():
    output = model(input_tensor)
```

第一行改变 BatchNorm、Dropout 等模块的工作状态；第二行让 PyTorch 不再为反向计算保存中间数据。只调用其中一个不能完全替代另一个。

### 4.13 序列、图像、视频和全连接特征怎样选择

下面不是不可更改的规则，而是常见起点：

| 数据与网络 | 常见选择 | 主要原因 |
| --- | --- | --- |
| MLP 输入 `(...,E)` | `LayerNorm(E)` 或不使用归一化 | 最后一维含义清楚，不依赖同批样本 |
| Transformer 输入 `(N,L,E)` | `LayerNorm(E)` | 每个 token 独立处理自己的特征 |
| RNN/LSTM 隐状态 `(...,H)` | `LayerNorm(H)` | 可按时间位置处理隐藏特征 |
| 常规二维卷积，单卡小批较充足 | `BatchNorm2d(C)` | 每通道统计，使用成熟广泛 |
| 每卡样本很少的卷积网络 | `GroupNorm(G,C)` | 不跨样本统计 |
| 图像风格处理 | `InstanceNorm2d(C)` | 每张图、每通道独立处理空间数值 |
| 视频或体数据 | `BatchNorm3d(C)`、`InstanceNorm3d(C)` 或 GroupNorm | 取决于是否希望跨样本、跨通道组 |
| 每个像素对通道处理 | 转成 `(N,H,W,C)` 后 `LayerNorm(C)` | 固定像素，只比较通道 |
| 复现早期视觉模型 | LocalResponseNorm | 保持原模型计算方式 |
| 多进程训练且需要跨进程批统计 | SyncBatchNorm | 合并参与进程的数据 |

#### 4.13.1 一个简洁的选择顺序

1. 先写输入形状，并给每个维度标上含义。
2. 决定一个样本是否应受到同批其他样本影响。
3. 决定通道应分开、分组，还是与其他特征一起处理。
4. 决定空间位置或 token 位置是否应参与同一组统计。
5. 检查输入长度和空间尺寸是否会变化。
6. 最后才选择类名与构造参数。

> [!TIP] 先画圈，再写代码
> 在一个很小的张量上，把应该共同计算的数用同一种颜色圈起来。若每列同色，接近二维 BatchNorm；若每行同色，接近 LayerNorm；若一张图的每个通道平面各自同色，接近 InstanceNorm。

#### 4.13.2 带补齐位置的序列

对 `(N,L,E)` 使用 `LayerNorm(E)` 时，每个 token 只使用自己的 $E$ 个特征。补齐 token 不会改变有效 token 的均值和方差。

但是，补齐 token 自己仍会经过 LayerNorm。若其输入全为 0：

- 初始 $\beta=0$ 时输出通常仍为 0；
- 训练后 $\beta$ 可能不再为 0，输出也可能非零。

因此注意力和损失仍需要正确 mask，池化时也应只汇总有效 token。

对换轴后的 `(N,E,L)` 使用 BatchNorm1d 或 InstanceNorm1d 时，长度维 $L$ 会参与统计。这些层没有接收序列 mask 的参数，补齐值会进入均值和方差。

> [!WARNING] 归一化不能代替序列 mask
> LayerNorm 只保证有效 token 不使用其他 token 的统计数据；它不会阻止注意力读取补齐位置，也不会阻止损失函数计算补齐标签。

#### 4.13.3 输入尺寸变化对各层有什么影响

| 模块 | 哪些尺寸通常可以变化 |
| --- | --- |
| BatchNorm 家族 | `N` 和空间尺寸可变化，`C` 必须等于 `num_features` |
| InstanceNorm 家族 | `N` 和空间尺寸可变化，`C` 必须等于 `num_features` |
| GroupNorm | `N` 和空间尺寸可变化，`C` 必须等于 `num_channels` |
| `LayerNorm(E)` | 所有前导尺寸可变化，最后一维必须是 `E` |
| `LayerNorm((H,W))` | 前导尺寸可变化，最后两维必须固定为 `H,W` |

例如 `LayerNorm(768)` 可以处理不同批大小和不同 token 数，只要每个 token 的特征宽度始终为 768。`LayerNorm((14,14))` 则不能直接处理空间尺寸变成 `(16,16)` 的输入。

### 4.14 常见报错、静默错误与排查代码

#### 4.14.1 常见报错分别在说什么

| 现象或报错要点 | 常见原因 | 检查方法 |
| --- | --- | --- |
| BatchNorm 提示运行均值元素数不符 | 第 1 维通道数与 `num_features` 不同 | 打印 `x.shape[1]` |
| LayerNorm 提示期望末尾形状 | 输入最后若干维与 `normalized_shape` 不同 | 从右向左逐维比较 |
| GroupNorm 提示通道数或整除关系不符 | `C!=num_channels` 或 `C%G!=0` | 检查前一层输出通道和组数 |
| 训练时提示每通道需要多个值 | BatchNorm 每通道只有一个元素 | 计算 `N×空间元素数` |
| InstanceNorm 提示需要多个空间元素 | 每个 `(n,c)` 只有一个空间值 | 计算 `L`、`H×W` 或 `D×H×W` |

#### 4.14.2 最危险的是“能运行但含义不对”

下面代码在 `L=E` 时可能不报错：

```python
N, L, E = 2, 8, 8
x = torch.randn(N, L, E)
bn = nn.BatchNorm1d(E, affine=False, track_running_stats=False)
wrong = bn(x)
```

`BatchNorm1d` 把第 1 维看作通道，所以这里把 token 位置当成了通道。正确写法应依据设计目标决定是否换轴：

```python
correct = bn(x.transpose(1, 2)).transpose(1, 2)
```

这里关闭运行统计，是为了单独比较两个统计维度。如果使用默认 BatchNorm，错误的第一次前向还会更新 `running_mean` 和 `running_var`；修正轴顺序后应重新创建模块或恢复正确的运行数据，不能继续混用已经受到错误输入影响的 buffer。

同样地，`LayerNorm(C)` 直接接收 `(N,C,H,W)` 时，如果 `C==W`，它会把宽度当作 `normalized_shape`。仅检查输出形状无法发现问题。

> [!IMPORTANT] 每次使用归一化层都写一句轴说明
> 例如：“输入 `(N,L,E)`，本层固定 `n,l`，对 `e` 统计。”这句话能在代码评审时快速暴露维度误用。

还有一种容易误导初学者的情况：关闭依赖通道数的参数和运行统计后，PyTorch 2.0.1 的部分后端路径未必检查构造参数中的 `C` 是否与实际第 1 维一致。例如默认 InstanceNorm，或同时使用 `affine=False, track_running_stats=False` 的 BatchNorm，某些错误配置可能仍能执行。应始终主动核对通道维，不要把“没有报错”当作配置正确。

#### 4.14.3 用 `keepdim=True` 打印统计数据形状

```python
def show_moments(name, x, dims):
    mean = x.mean(dim=dims, keepdim=True)
    var = x.var(dim=dims, unbiased=False, keepdim=True)
    print(
        f"{name:22s}",
        "input=", tuple(x.shape),
        "dims=", dims,
        "mean=", tuple(mean.shape),
        "var=", tuple(var.shape),
    )

x = torch.randn(2, 3, 4, 5)
show_moments("BatchNorm2d", x, (0, 2, 3))
show_moments("InstanceNorm2d", x, (2, 3))
show_moments("LayerNorm(W)", x, (3,))
show_moments("LayerNorm(H,W)", x, (2, 3))
show_moments("LayerNorm(C,H,W)", x, (1, 2, 3))
```

预期均值形状：

```text
BatchNorm2d       -> (1, 3, 1, 1)
InstanceNorm2d    -> (2, 3, 1, 1)
LayerNorm(W)      -> (2, 3, 4, 1)
LayerNorm(H,W)    -> (2, 3, 1, 1)
LayerNorm(C,H,W)  -> (2, 1, 1, 1)
```

注意 `InstanceNorm2d` 和 `LayerNorm((H,W))` 的统计数据形状相同，但仿射参数形状不同，默认设置也不同。

#### 4.14.4 检查是否会受到其他样本影响

```python
torch.manual_seed(0)
x = torch.randn(2, 3, 4, 4)
x_changed = x.clone()
x_changed[1] = x_changed[1] * 100 + 50  # 只改样本 1

bn = nn.BatchNorm2d(3, affine=False, track_running_stats=False)
gn = nn.GroupNorm(1, 3, affine=False)
ln = nn.LayerNorm((3, 4, 4), elementwise_affine=False)

print(torch.allclose(bn(x)[0], bn(x_changed)[0]))  # 通常 False
print(torch.allclose(gn(x)[0], gn(x_changed)[0]))  # True
print(torch.allclose(ln(x)[0], ln(x_changed)[0]))  # True
```

这个小实验直接展示：BatchNorm 在训练规则下跨样本，GroupNorm 和 LayerNorm 不跨样本。

### 4.15 初学者常问的归一化问题

> [!QUESTION] 名字中的 1d、2d、3d 是张量维数吗？
> 不是。它表示空间维的数量。`BatchNorm1d` 可接收二维 `(N,C)` 或三维 `(N,C,L)`；`BatchNorm2d` 的常规输入是四维 `(N,C,H,W)`；`BatchNorm3d` 的常规输入是五维 `(N,C,D,H,W)`。

> [!QUESTION] 归一化会不会丢掉均值和尺度信息？
> 标准化中间步骤会移除当前统计集合的中心和尺度，但可学习的 $\gamma,\beta$ 能重新调整输出。网络的其他层也会保留和组合信息。是否适合使用仍取决于模型结构与任务。

> [!QUESTION] 可以在 BatchNorm 后再接 LayerNorm 吗？
> PyTorch 允许这样写，但两层会连续调整数值。除非模型结构有明确理由，否则不要因为“归一化越多越好”而随意堆叠。先遵循所实现架构的设计，再用对照实验判断。

> [!QUESTION] `affine=False` 是否意味着层没有任何作用？
> 不是。它仍会减均值、除标准差，只是不再乘可学习的 $\gamma$、加可学习的 $\beta$。

> [!QUESTION] GroupNorm 的组数越大越好吗？
> 不一定。组数增大后，每组通道数减少；组数减小后，更多通道一起统计。两者改变了模型看到的特征组合，应结合通道数和任务选择。

> [!QUESTION] 为什么训练与评估的 BatchNorm 结果差很多？
> 常见原因包括：训练时间太短，运行统计尚不稳定；训练和评估数据分布差异明显；小批太小；忘记在训练后调用 `eval()`；加载模型时遗漏了 buffer。

> [!QUESTION] 为什么 LayerNorm 能处理任意批大小？
> `LayerNorm(E)` 不在批维上计算，每个前导位置独立使用最后的 $E$ 个特征。因此批从 1 变成 100 不会改变单个位置所用的统计集合。

> [!QUESTION] 换轴后为什么输出还要换回来？
> 下游层通常约定原来的维度顺序。例如 Transformer 常使用 `(N,L,E)`，而 BatchNorm1d 要求 `(N,E,L)`。计算后换回，可让后续注意力和线性层继续按原约定读取。

> [!SUMMARY] 归一化层的最终记忆法
> 先写输入形状，再回答三个问题：哪些下标变化并共同统计；哪些下标固定并各有一套统计数据；$\gamma,\beta$ 在哪些位置共享。能回答这三问，多维输入就不再只是需要死记的类名列表。

### 4.16 名称相近但计算对象不同的工具

`torch.nn.functional.normalize` 常被简称为 normalize，但它不是前面所讲的均值—方差归一化层。它按指定维度计算向量范数：

$$
y=\frac{x}{\max(\lVert x\rVert_p,\epsilon)}.
$$

例如按行计算二范数：

```python
x = torch.tensor([[3., 4.], [0., 5.]])
y = F.normalize(x, p=2, dim=1)
print(y)
# tensor([[0.6000, 0.8000],
#         [0.0000, 1.0000]])
```

第一行的二范数是 $\sqrt{3^2+4^2}=5$，所以除以 5；第二行的二范数也是 5。它不减均值，没有 $\gamma,\beta$，也不保存运行统计。

`weight_norm`、`spectral_norm` 等工具处理的是层的权重，而 BatchNorm、InstanceNorm、GroupNorm、LayerNorm 主要处理前向输入或中间特征。看到名称中含有 norm 时，应先确认“被处理的是输入张量，还是模块参数”。

> [!NOTE] 为什么本节把函数工具单独列出
> `F.normalize` 不是带状态的 `nn.Module`，权重相关工具也不是普通的输入处理层。把它们与前面的层区分开，可以避免只根据名字误判公式。

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

#### 先从输入形状读懂三类卷积

`Conv1d`、`Conv2d`、`Conv3d` 中的数字表示卷积核沿几个空间维滑动，不表示输入张量总共有几个维度。加入小批维和通道维后，张量维数通常比层名称中的数字多 2。

| 层 | 带小批维的输入 | 权重形状 | 输出 |
| --- | --- | --- | --- |
| `Conv1d` | `(N,C_in,L)` | `(C_out,C_in/groups,K)` | `(N,C_out,L_out)` |
| `Conv2d` | `(N,C_in,H,W)` | `(C_out,C_in/groups,K_h,K_w)` | `(N,C_out,H_out,W_out)` |
| `Conv3d` | `(N,C_in,D,H,W)` | `(C_out,C_in/groups,K_d,K_h,K_w)` | `(N,C_out,D_out,H_out,W_out)` |

表中：

- $N$ 是小批中的样本数；
- $C_{\mathrm{in}}$ 和 $C_{\mathrm{out}}$ 是输入、输出通道数；
- $L$ 可以表示音频采样点、时间步或序列位置；
- $H,W$ 是图像的高和宽；
- $D$ 可以表示医学体数据的深度，也可以表示视频时间；
- $K$ 表示卷积核在相应空间维的大小。

> [!NOTE] 一个输出通道对应一组完整权重
> 对普通 `Conv2d` 而言，一组权重不只是一个 $K_h\times K_w$ 小片，而是覆盖所有输入通道的 $C_{\mathrm{in}}\times K_h\times K_w$ 张量。它先在各输入通道做乘加，再把结果相加成一个输出通道。`out_channels=16` 表示会产生 16 组这样的结果。

PyTorch 允许省略小批维，因此 `Conv2d` 也能接收 `(C,H,W)`。不过网络代码通常保留小批维，即使一次只有一张图，也整理成 `(1,C,H,W)`，这样更容易与数据读取器和后续层配合。

> [!WARNING] PyTorch 卷积默认采用 channels-first
> 图像通常写成 `(N,C,H,W)`，而不是 `(N,H,W,C)`；视频或体数据通常写成 `(N,C,D,H,W)`。若外部工具给出 channels-last 数据，应先用 `permute` 调整各轴次序。

自然语言序列常写成 `(N,L,E)`，其中 $E$ 是每个 token 的特征数。若希望 `Conv1d` 沿序列位置滑动，需要暂时把特征轴放到通道位置：

```python
tokens = torch.randn(8, 20, 64)        # (N,L,E)
x = tokens.transpose(1, 2)             # (N,E,L)
conv = nn.Conv1d(64, 96, kernel_size=3, padding=1)
y = conv(x)                             # (N,96,L)
y = y.transpose(1, 2)                  # (N,L,96)
print(y.shape)
```

> [!EXAMPLE] `Conv1d` 不只用于音频
> 若一句话有 20 个 token，每个 token 用 64 个数表示，输入可看成 64 个特征通道、每个通道长度为 20。大小为 3 的卷积核每次查看相邻三个 token，可以学习局部词组附近的组合特征。

#### 每个空间维都可以单独计算输出大小

先定义卷积核在某一维上的实际覆盖长度：

$$K_{\mathrm{eff}}=d(K-1)+1,$$

其中 $K$ 是核大小，$d$ 是 dilation。当 `dilation=1` 时，$K_{\mathrm{eff}}=K$；当 `kernel_size=3,dilation=2` 时，三个核元素之间各跳过一个输入位置，实际覆盖长度为 5。

输出长度可以改写为：

$$
L_{\mathrm{out}}
=
\left\lfloor
\frac{L_{\mathrm{in}}+2p-K_{\mathrm{eff}}}{s}
\right\rfloor+1.
$$

> [!TIP] 形状计算分三步
> 先用 $d(K-1)+1$ 求实际覆盖长度，再计算加入 padding 后可供滑动的长度，最后除以 stride 并向下取整。二维和三维只是分别对每个空间轴重复这三步。

例如输入形状是 `(2,4,9,20,30)`，使用：

```python
conv3d = nn.Conv3d(
    in_channels=4,
    out_channels=6,
    kernel_size=(3, 5, 3),
    stride=(1, 2, 2),
    padding=(1, 2, 1),
    dilation=(1, 1, 2),
)
x = torch.randn(2, 4, 9, 20, 30)
print(conv3d(x).shape)  # (2,6,9,10,14)
```

深度方向：

$$
D_{\mathrm{out}}
=
\left\lfloor
\frac{9+2-1(3-1)-1}{1}+1
\right\rfloor
=9.
$$

高度方向：

$$
H_{\mathrm{out}}
=
\left\lfloor
\frac{20+4-1(5-1)-1}{2}+1
\right\rfloor
=10.
$$

宽度方向的核大小为 3，dilation 为 2，实际覆盖长度为 $2(3-1)+1=5$：

$$
W_{\mathrm{out}}
=
\left\lfloor
\frac{30+2-2(3-1)-1}{2}+1
\right\rfloor
=14.
$$

最终输出形状为 `(2,6,9,10,14)`。输出通道数直接等于 `out_channels=6`，不由空间尺寸公式计算。

#### stride、padding 与 dilation 分别改变什么

- stride 决定完成一次输出后，卷积核整体移动几格；
- padding 决定输入四周补入多少位置；
- dilation 决定同一卷积核内部相邻权重隔几格读取输入。

> [!IMPORTANT] stride 与 dilation 表示两种不同间隔
> `stride=2` 表示下一次整体计算向前移动两格；`dilation=2` 表示一次计算中的相邻核元素相隔两格。前者通常减少输出位置数，后者在不增加权重数的情况下扩大单次计算查看的范围。

令一维输入和卷积核为：

$$
x=[1,2,3,4,5,6,7],
\qquad
w=[1,10,100].
$$

当 `dilation=2,stride=1` 时，第一个输出读取 $x_0,x_2,x_4$：

$$1\times1+3\times10+5\times100=531.$$

第二个输出读取 $x_1,x_3,x_5$，得到 642；第三个输出读取 $x_2,x_4,x_6$，得到 753。因此输出是 `[531,642,753]`。核仍然只有三个权重，但一次计算覆盖五个连续输入位置。

```python
x = torch.arange(1, 8, dtype=torch.float32).reshape(1, 1, 7)
conv = nn.Conv1d(1, 1, kernel_size=3, dilation=2, bias=False)
with torch.no_grad():
    conv.weight.copy_(torch.tensor([[[1., 10., 100.]]]))
print(conv(x))  # tensor([[[531., 642., 753.]]])
```

若再把 stride 改为 2，只计算第一组和第三组，输出便是 `[531,753]`。可见，dilation 改变每个窗口内部读哪些位置，stride 改变一共有多少个窗口。

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

> [!NOTE] 深度学习里的“卷积”实际按互相关方式计算
> 数学教材中的严格卷积常先翻转卷积核，PyTorch 则直接按权重存放顺序乘加。权重会由训练得到，因此这种写法仍能学习所需的局部模式，深度学习资料也继续把它称为卷积。

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

> [!WARNING] 分组数必须同时整除输入和输出通道数
> `groups=G` 时需要满足 `C_in % G == 0` 且 `C_out % G == 0`。每个输出通道只能读取所属组内的 `C_in/G` 个输入通道。

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

> [!WARNING] 重叠次数不均可能产生棋盘状纹理
> 不同输入位置写入输出时，有些输出位置可能收到多次相加，另一些收到的次数较少。核大小与 stride 的组合不合适时，图像上可能出现规律纹理。可以同时比较“插值后接普通卷积”的结果。

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

> [!NOTE] 自适应池化不要求输入尺寸能整除输出尺寸
> 从 7 个位置缩成 3 个位置时，PyTorch 会自动选取三个覆盖区间，这些区间的宽度可以不同，也可能共享邻近输入位置。它保证输出尺寸，不保证固定窗口宽度与固定 stride。

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

> [!WARNING] MaxUnpool 必须使用配套的池化索引
> `indices` 应来自对应的 `MaxPool(..., return_indices=True)`，核大小、stride、padding 等设置也应互相匹配。错用另一层的索引，可能把数值放到错误位置或触发索引错误。

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

> [!TIP] 填充元组从最后一个空间维开始写
> 二维输入的最后一维是宽，所以先写 `(left,right)`；倒数第二维是高，再写 `(top,bottom)`。因此 `(1,2,3,4)` 表示左 1、右 2、上 3、下 4。

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

> [!WARNING] Unfold 可能产生很大的临时张量
> 相邻窗口会重复保存共享像素。输入较大、窗口较大且 stride 较小时，展开结果可能远大于原图。例如 `3×3` 窗口、stride 1 时，大部分内部像素会在 9 个窗口中重复出现。

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

> [!QUESTION] Fold 什么时候能直接得到原图？
> 需要每个有效位置恰好被一个窗口覆盖。只要窗口重叠，Fold 就会累加；只要有位置未被任何窗口覆盖，就无法从这些列得到该位置。通用方法是先 Fold 全 1 张量，得到覆盖次数，再检查是否可以逐元素相除。

### 6.6 `PixelShuffle`、`PixelUnshuffle`、`ChannelShuffle`

`PixelShuffle(r)` 将通道中的子像素重排到空间维：

$$ (N, C r^2, H, W)\rightarrow(N,C,Hr,Wr).$$

`PixelUnshuffle(r)` 是反向重排：

$$ (N,C,Hr,Wr)\rightarrow(N,C r^2,H,W).$$

它们不引入参数，常用于超分辨率或无插值下采样。`ChannelShuffle(g)` 先把通道视作 `(g,C/g)`，交换这两个通道轴，再展平；常与分组卷积配合以让不同组的特征在下一层相互混合。

> [!WARNING] PixelShuffle 要求输入通道数可被 $r^2$ 整除
> 使用倍率 `r=2` 时，12 个输入通道可以重排成 3 个输出通道，但 10 个输入通道不能满足要求。该层只改变位置，不会凭空产生或删除元素。

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

> [!WARNING] Embedding 输入的是编号，不是连续特征
> 若词表大小为 `V`，每个编号必须位于 `[0,V)`。未知词应在分词阶段替换成专用未知词编号；负数或超过词表大小的编号会报错。

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

> [!NOTE] `output` 与 `h_n` 保存的内容不同
> `output` 保存最后一层在每个时间位置的隐藏状态；`h_n` 只保存每层、每个方向的最终状态。双向网络中，不能简单把 `output[:,-1]` 当作两个方向最终状态的组合，因为反向方向的读取顺序相反。

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

### 7.6 多层、双向循环网络的形状怎样阅读

先统一符号：

| 符号 | 含义 |
| --- | --- |
| $N$ | 小批大小 |
| $L$ | 序列长度 |
| $I$ | 输入特征宽度 `input_size` |
| $H$ | 隐藏宽度 `hidden_size` |
| $K$ | 循环层数 `num_layers` |
| $R$ | 方向数，单向为 1，双向为 2 |
| $P$ | LSTM 投影宽度 `proj_size` |

当 `batch_first=True` 时，RNN、GRU 与普通 LSTM 的主要形状如下：

| 张量 | RNN / GRU | 无投影 LSTM |
| --- | --- | --- |
| 输入 `x` | $(N,L,I)$ | $(N,L,I)$ |
| `output` | $(N,L,RH)$ | $(N,L,RH)$ |
| `h_n` | $(KR,N,H)$ | $(KR,N,H)$ |
| `c_n` | 无 | $(KR,N,H)$ |

> [!IMPORTANT] `batch_first` 不改变状态张量的次序
> `batch_first=True` 只把输入与逐位置输出改成小批在前。`h_n` 和 `c_n` 仍以“层与方向”作为第 0 维，不会变成 `(N,K,H)`。

以两层双向 GRU 为例，`h_n.shape=(4,N,H)`。第 0 维依次保存：

| `h_n` 下标 | 内容 |
| ---: | --- |
| 0 | 第 0 层正向最终状态 |
| 1 | 第 0 层反向最终状态 |
| 2 | 第 1 层正向最终状态 |
| 3 | 第 1 层反向最终状态 |

```python
import torch
from torch import nn

torch.manual_seed(0)

num_layers = 2
num_directions = 2
hidden_size = 6

gru = nn.GRU(
    input_size=4,
    hidden_size=hidden_size,
    num_layers=num_layers,
    bidirectional=True,
    batch_first=True,
)

x = torch.randn(3, 5, 4)
output, h_n = gru(x)

print(output.shape)  # (3,5,12)
print(h_n.shape)     # (4,3,6)

h_by_layer = h_n.reshape(
    num_layers,
    num_directions,
    x.size(0),
    hidden_size,
)

top_forward = h_by_layer[-1, 0]   # (3,6)
top_backward = h_by_layer[-1, 1]  # (3,6)
sentence_vector = torch.cat(
    [top_forward, top_backward],
    dim=-1,
)
print(sentence_vector.shape)      # (3,12)
```

多层循环网络中，第 0 层接收宽度为 $I$ 的输入。更高层接收上一层的输出，因此双向网络中更高层的输入宽度是 $2H$。

`output` 只包含最高一层的逐位置结果；`h_n` 保存每一层、每一方向的最终状态。选择哪个张量取决于后续任务：

- 需要每个 token 的上下文表示时，使用 `output`；
- 需要观察各层最终状态时，使用 `h_n`；
- 需要把整条序列压成一个向量时，常拼接最高层的正向和反向最终状态。

> [!WARNING] 双向网络不能总取 `output[:, -1, :]`
> 对没有补齐的等长序列，`output[:, -1, :H]` 是正向读取完整条序列后的状态，但 `output[:, -1, H:]` 只是反向刚开始读取末尾 token 时的状态。反向读取完整条序列后的状态位于 `output[:, 0, H:]`。使用 `h_n` 并拆开层和方向通常更清楚。

下面代码验证这一关系：

```python
rnn = nn.RNN(
    input_size=3,
    hidden_size=5,
    num_layers=1,
    bidirectional=True,
    batch_first=True,
)

x = torch.randn(2, 4, 3)
output, h_n = rnn(x)
h = h_n.reshape(1, 2, 2, 5)

print(torch.allclose(output[:, -1, :5], h[-1, 0]))
print(torch.allclose(output[:, 0, 5:], h[-1, 1]))
# 两行均为 True
```

#### 7.6.1 LSTM 为什么返回两组状态

LSTM 同时返回 $h_n$ 和 $c_n$：

- $h_n$ 是向外提供的隐藏状态；
- $c_n$ 是内部记忆状态；
- 普通 LSTM 中两者的层数、方向数、小批数和最后一维都相同。

```python
lstm = nn.LSTM(
    input_size=8,
    hidden_size=10,
    num_layers=3,
    bidirectional=True,
    batch_first=True,
)

x = torch.randn(4, 7, 8)
output, (h_n, c_n) = lstm(x)

print(output.shape)  # (4,7,20)
print(h_n.shape)     # (6,4,10)
print(c_n.shape)     # (6,4,10)
```

若省略初始状态，PyTorch 使用全零状态。手工提供时，设备、数据类型和形状必须与输入相容：

```python
directions = 2
layers = 3
batch_size = x.size(0)
hidden_size = 10

h0 = x.new_zeros(layers * directions, batch_size, hidden_size)
c0 = x.new_zeros(layers * directions, batch_size, hidden_size)

output, (h_n, c_n) = lstm(x, (h0, c0))
```

> [!TIP] 使用 `x.new_zeros(...)`
> 与直接写 `torch.zeros(...)` 相比，`x.new_zeros(...)` 会自动沿用输入的设备和数据类型，可减少 CPU、GPU 或浮点类型不一致的问题。

设置 `proj_size=P` 后，内部记忆仍使用宽度 $H$，向外给出的隐藏状态宽度变为 $P$：

| 张量 | 带投影 LSTM 的形状 |
| --- | --- |
| `output` | $(N,L,RP)$ |
| `h_n` | $(KR,N,P)$ |
| `c_n` | $(KR,N,H)$ |

```python
lstm = nn.LSTM(
    input_size=8,
    hidden_size=12,
    proj_size=5,
    num_layers=2,
    bidirectional=True,
    batch_first=True,
)

x = torch.randn(3, 6, 8)
output, (h_n, c_n) = lstm(x)

print(output.shape)  # (3,6,10)，2 个方向 × 5
print(h_n.shape)     # (4,3,5)
print(c_n.shape)     # (4,3,12)
```

带投影时，`h_n` 与 `c_n` 的最后一维本来就不同，不应强行要求两者同形。

> [!NOTE] 循环层构造参数中的 `dropout`
> `RNN`、`GRU`、`LSTM` 的 `dropout` 只用在相邻循环层之间。`num_layers=1` 时没有层间位置可以使用它，因此不会产生随机丢弃效果。它也不表示同一层每个时间步后都会额外调用一次普通 `Dropout`。

### 7.7 不同样本长度不同：补齐、打包与还原

一批句子常有不同长度。例如三个样本的有效长度分别是 5、3、2。为了组成规则张量，短样本要补到长度 5：

```text
样本 0：a b c d e
样本 1：f g h PAD PAD
样本 2：i j PAD PAD PAD
```

若只补齐后直接传给 GRU，GRU 仍会计算 `PAD` 时间步。`Embedding.padding_idx` 只能阻止补齐词向量通过梯度更新，不能阻止循环状态继续变化。

`pack_padded_sequence` 根据真实长度建立紧凑表示，让循环层跳过补齐部分；`pad_packed_sequence` 再把输出还原为规则张量。

```python
import torch
from torch import nn
from torch.nn.utils.rnn import (
    pad_sequence,
    pack_padded_sequence,
    pad_packed_sequence,
)

torch.manual_seed(1)

sequences = [
    torch.randn(5, 4),
    torch.randn(3, 4),
    torch.randn(2, 4),
]
lengths = torch.tensor([len(seq) for seq in sequences])

# 形状为 (3,5,4)，补齐值默认为 0。
padded = pad_sequence(sequences, batch_first=True)

packed = pack_padded_sequence(
    padded,
    lengths.cpu(),
    batch_first=True,
    enforce_sorted=False,
)

gru = nn.GRU(
    input_size=4,
    hidden_size=6,
    num_layers=2,
    bidirectional=True,
    batch_first=True,
)

packed_output, h_n = gru(packed)

output, restored_lengths = pad_packed_sequence(
    packed_output,
    batch_first=True,
    total_length=padded.size(1),
)

print(padded.shape)          # (3,5,4)
print(output.shape)          # (3,5,12)
print(h_n.shape)             # (4,3,6)
print(restored_lengths)      # tensor([5,3,2])

positions = torch.arange(padded.size(1)).unsqueeze(0)
valid_mask = positions < lengths.unsqueeze(1)
print(valid_mask)

# 还原后的无效位置由 pad_packed_sequence 填为 0。
assert torch.allclose(
    output[~valid_mask],
    torch.zeros_like(output[~valid_mask]),
)

h = h_n.reshape(2, 2, 3, 6)
sequence_features = torch.cat([h[-1, 0], h[-1, 1]], dim=-1)
print(sequence_features.shape)  # (3,12)
```

参数和张量可以这样理解：

- `lengths` 保存每个样本补齐前的有效长度；
- 若 `lengths` 是张量，通常应放在 CPU；
- `enforce_sorted=False` 允许输入不按长度从大到小排列；
- `batch_first=True` 应与补齐张量的排列方式一致；
- `total_length` 可强制还原到指定长度，后面还要堆叠其他模块时很有用。

> [!WARNING] 长度必须与样本内容一致
> 若某个样本实际只有 3 个有效位置，却把长度写成 5，循环层会把两个补齐位置当成真实输入；若长度写得过小，末尾真实内容又会被跳过。长度应在整理小批时从原始数据可靠地保存。

> [!WARNING] 不要把长度为 0 的样本直接送入打包函数
> 有效长度必须大于 0。空文本可以加入 `[UNK]`、`[CLS]` 等占位 token，或在整理数据时单独处理。

对词编号序列，常见次序是：

```text
编号序列
  → pad_sequence
  → Embedding
  → pack_padded_sequence
  → RNN / GRU / LSTM
  → pad_packed_sequence
```

如果只需要整条序列的最终表示，可以直接从 `h_n` 取得最高层状态，不必先在补齐后的 `output` 中手工寻找最后有效位置。

---

## 8. 注意力与 Transformer

### 8.1 `MultiheadAttention`

多头注意力先得到 Query、Key、Value：

$$Q=X_QW_Q,\qquad K=X_KW_K,\qquad V=X_VW_V.$$

第 $j$ 个头的宽度为 $d_h=E/h$，其输出为：

$$\operatorname{head}_j=\operatorname{Softmax}\left(\frac{Q_jK_j^T}{\sqrt{d_h}}+M\right)V_j,$$

$$\operatorname{MHA}=\operatorname{Concat}(\operatorname{head}_1,\ldots,\operatorname{head}_h)W_O.$$

`nn.MultiheadAttention(embed_dim=E, num_heads=h, batch_first=True)` 在自注意力中把同一个张量传给 `query`、`key`、`value`。`key_padding_mask` 形状为 `(N,S)`，其中 `True` 表示该 Key 位置应被忽略；浮点 `attn_mask` 加到注意力分数上，布尔 `attn_mask=True` 表示该位置不允许关注。

> [!WARNING] PyTorch 布尔注意力 mask 中的 `True` 表示禁止读取
> 这一约定与部分库相反。移植代码时应先核对接口说明，并用两三个 token 的小张量确认被遮住位置的注意力权重是否为 0。

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

#### 多头权重与两类遮罩的完整形状

令：

- $N$ 为小批大小；
- $L_q$ 为 Query 长度；
- $L_k$ 为 Key 和 Value 长度；
- $E$ 为输入宽度；
- $h$ 为头数。

当 `batch_first=True` 时：

| 张量 | 形状 |
| --- | --- |
| `query` | $(N,L_q,E)$ |
| `key` | $(N,L_k,E)$ |
| `value` | $(N,L_k,E)$ |
| 注意力输出 | $(N,L_q,E)$ |
| 各头平均后的权重 | $(N,L_q,L_k)$ |
| 保留每个头的权重 | $(N,h,L_q,L_k)$ |

`embed_dim` 必须能被 `num_heads` 整除，每个头的宽度为 $d_h=E/h$。例如 `embed_dim=8,num_heads=2` 时，每个头处理 4 维 Query、Key 和 Value。

默认 `average_attn_weights=True`，返回的权重已经在头维取平均。要观察每个头，应传入 `average_attn_weights=False`：

```python
import torch
from torch import nn

torch.manual_seed(7)

mha = nn.MultiheadAttention(
    embed_dim=8,
    num_heads=2,
    dropout=0.0,
    batch_first=True,
)

query = torch.randn(2, 3, 8)      # L_q=3
key_value = torch.randn(2, 5, 8)  # L_k=5

key_padding_mask = torch.tensor([
    [False, False, False, False, True],
    [False, False, False, True,  True],
])

# 所有样本、所有头都禁止读取最后一个 Key。
pair_mask = torch.zeros(3, 5, dtype=torch.bool)
pair_mask[:, 4] = True

output, weights = mha(
    query,
    key_value,
    key_value,
    key_padding_mask=key_padding_mask,
    attn_mask=pair_mask,
    need_weights=True,
    average_attn_weights=False,
)

print(output.shape)   # (2,3,8)
print(weights.shape)  # (2,2,3,5)

# 第 0 个样本的最后一列不可读。
assert torch.all(weights[0, :, :, 4] == 0)

# 第 1 个样本的最后两列不可读。
assert torch.all(weights[1, :, :, 3:] == 0)

# dropout=0 且每行至少有一个可读位置时，每行权重和为 1。
assert torch.allclose(
    weights.sum(dim=-1),
    torch.ones_like(weights.sum(dim=-1)),
    atol=1e-6,
)
```

两类遮罩负责不同事情：

| 参数 | 常见形状 | 作用 |
| --- | --- | --- |
| `key_padding_mask` | $(N,L_k)$ | 指定每个样本的哪些 Key 是补齐位置 |
| 二维 `attn_mask` | $(L_q,L_k)$ | 所有样本、所有头共用同一规则 |
| 三维 `attn_mask` | $(Nh,L_q,L_k)$ | 每个样本的每个头可以使用独立规则 |

> [!NOTE] 三维 `attn_mask` 的第 0 维
> `MultiheadAttention` 接收的是 `(N*num_heads,L_q,L_k)`，不是 `(N,num_heads,L_q,L_k)`。若手中已有四维布尔张量，可用 `reshape(N*num_heads,L_q,L_k)` 合并前两维。

布尔遮罩中，`True` 表示禁止读取。浮点遮罩会直接加到注意力分数上，通常用 0 表示允许，用负无穷表示禁止：

```python
length = 4

bool_causal_mask = torch.triu(
    torch.ones(length, length, dtype=torch.bool),
    diagonal=1,
)

float_causal_mask = torch.zeros(length, length)
float_causal_mask.masked_fill_(
    bool_causal_mask,
    float("-inf"),
)

print(bool_causal_mask)
# tensor([[False,  True,  True,  True],
#         [False, False,  True,  True],
#         [False, False, False,  True],
#         [False, False, False, False]])
```

> [!TIP] 同时传入两类遮罩时尽量保持类型一致
> `attn_mask` 和 `key_padding_mask` 最好都使用布尔类型，或都使用相容的浮点类型。布尔形式更适合表达“允许”和“禁止”两种状态。

> [!WARNING] 不要把某一行的全部 Key 都遮住
> Softmax 至少需要一个可读位置。若某个 Query 的全部分数都变成负无穷，输出可能含非有限数。整理数据时应保证每个样本至少有一个有效 token。

#### 补齐 Key 与补齐 Query 不是同一件事

`key_padding_mask` 遮住的是 Key 所在的列：其他 Query 不会读取这些补齐位置。它不会自动把“补齐 Query 对应的输出行”设为零。

假设某个样本有效长度为 2，张量长度补到 4。后两个位置作为 Key 时会被遮住；但后两个位置作为 Query 时，仍可能读取前两个有效 Key，因而产生非零输出。若随后要按序列位置求平均，应再次用有效位置遮罩：

```python
padding_mask = torch.tensor([
    [False, False, False, True],
    [False, False, True,  True],
])

features = torch.randn(2, 4, 8)
valid = (~padding_mask).unsqueeze(-1)

pooled = (
    (features * valid).sum(dim=1)
    / valid.sum(dim=1).clamp_min(1)
)

print(pooled.shape)  # (2,8)
```

分母是每个样本的有效位置数，而不是统一的序列长度 4。这样短句不会因为补齐更多而被额外缩小。

> [!NOTE] `need_weights=False` 可减少不必要的保存
> 训练中若只需要注意力输出，可传 `need_weights=False`。完整权重张量的元素数随 $L_qL_k$ 增长，长序列时会占用较多内存。分析或展示各 token 关系时再请求权重更合适。

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

位置信息不是 `nn.Transformer` 自动添加的；输入 embedding 前应自行加入可学习位置参数或正弦位置编码。

> [!NOTE] `nn.Transformer` 不是完整的文本生成模型
> 它不会自动完成分词、Embedding、位置编码和词表分类。文本任务通常还要在输入端加入 Embedding 与位置信息，在输出端加入 `Linear(d_model,vocab_size)`，训练时再计算下一个 token 的分类损失。

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

> [!WARNING] 不要在 `CrossEntropyLoss` 前再次使用 Softmax
> 再加 Softmax 会把概率当作 logits 传入，使损失含义和梯度发生变化。推理时若需要展示概率，再对 logits 调用 Softmax。

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

### 9.5 `reduction`、类别权重与 `ignore_index`

以平方误差为例，预测为 $[1,3]$，目标为 $[0,1]$，逐元素损失是：

$$[(1-0)^2,(3-1)^2]=[1,4].$$

三种归约方式分别得到：

$$
\text{none}=[1,4],\qquad
\text{sum}=1+4=5,\qquad
\text{mean}=\frac{1+4}{2}=2.5.
$$

```python
import torch
from torch import nn

pred = torch.tensor([1.0, 3.0])
target = torch.tensor([0.0, 1.0])

print(nn.MSELoss(reduction="none")(pred, target))
print(nn.MSELoss(reduction="sum")(pred, target))
print(nn.MSELoss(reduction="mean")(pred, target))
```

`reduction="none"` 很适合排查，因为可以看到每个样本或每个位置分别产生多大损失；还可以在之后加入样本权重、位置遮罩或自定义平均方式。

> [!NOTE] 不同损失的 `mean` 分母不一定相同
> 普通 MSE 通常除以元素数；带类别权重的交叉熵会依据有效目标对应的权重求平均；忽略部分位置后，又只统计未忽略位置。比较不同配置的损失数值前，应先确认分子和分母。

#### 9.5.1 序列交叉熵与 `ignore_index`

语言模型 logits 常写成 `(N,L,V)`，其中 $V$ 是词表大小。但 `CrossEntropyLoss` 规定类别维位于第 1 维，所以有两种常见写法：

```python
# 写法一：把类别维换到第 1 维。
loss = nn.CrossEntropyLoss(ignore_index=0)(
    logits.transpose(1, 2),  # (N,V,L)
    targets,                 # (N,L)
)

# 写法二：合并小批维与序列维。
loss = nn.CrossEntropyLoss(ignore_index=0)(
    logits.reshape(-1, logits.size(-1)),  # (N*L,V)
    targets.reshape(-1),                  # (N*L,)
)
```

`ignore_index=0` 表示目标编号为 0 的位置不参与损失和梯度，很适合忽略 `[PAD]`：

```python
torch.manual_seed(3)

vocab_size = 5
pad_id = 0

logits = torch.randn(2, 4, vocab_size, requires_grad=True)
targets = torch.tensor([
    [2, 3, 4, 0],
    [1, 2, 0, 0],
])

per_token = nn.functional.cross_entropy(
    logits.transpose(1, 2),
    targets,
    ignore_index=pad_id,
    reduction="none",
)

valid = targets.ne(pad_id)
valid_count = valid.sum()
if valid_count == 0:
    raise ValueError("这个小批没有有效目标")

loss = per_token.sum() / valid_count
loss.backward()

print(per_token.shape)  # (2,4)
print(per_token)
print(loss)
```

`reduction="none"` 时，被忽略位置的结果为 0。手工平均时仍应除以有效位置数，不能直接对整个规则张量调用 `.mean()`；否则补齐位置越多，最终数值会被压得越小。

> [!WARNING] 软标签不能按同一种方式使用 `ignore_index`
> 目标为类别编号时，可以指定一个被忽略编号；目标本身若是与 logits 同形状的概率分布，应使用额外的布尔遮罩，手工选择有效位置并组合损失。

#### 9.5.2 类别权重怎样参与交叉熵

若类别 $c$ 的权重为 $w_c$，单个样本的加权损失可写为：

$$
\ell_n
=
-w_{y_n}
\log
\frac{\exp(x_{n,y_n})}
{\sum_c\exp(x_{n,c})}.
$$

在默认 `reduction="mean"` 下，平均时还会考虑有效样本对应的权重之和，所以不是简单除以样本数。

```python
class_weight = torch.tensor([1.0, 3.0, 0.5])
criterion = nn.CrossEntropyLoss(weight=class_weight)

logits = torch.tensor([
    [2.0, 0.0, -1.0],
    [0.0, 2.0, 1.0],
])
labels = torch.tensor([0, 1])

print(criterion(logits, labels))
```

类别权重张量应满足：

- 长度等于类别数；
- 与 logits 位于同一设备；
- 使用相容的浮点类型；
- 依据训练数据中的标签统计确定，不把验证数据统计混入训练配置。

`BCEWithLogitsLoss` 中的 `weight` 与 `pos_weight` 含义不同：

- `weight` 缩放每个样本或每个元素的完整损失；
- `pos_weight` 只改变正标签项的影响，形状通常与类别维相容。

> [!WARNING] 单标签多类别与多标签是两类任务
> 单标签多类别任务中，一个样本只属于一个类别，常用 `CrossEntropyLoss` 和整数标签；多标签任务中，一个样本可同时属于多个类别，常用 `BCEWithLogitsLoss` 和 0/1 浮点矩阵。

若权重属于每个样本，而不是每个类别，可以先保留逐样本损失：

```python
logits = torch.randn(4, 3, requires_grad=True)
labels = torch.tensor([0, 2, 1, 0])
sample_weight = torch.tensor([1.0, 0.5, 2.0, 1.0])

per_sample = nn.functional.cross_entropy(
    logits,
    labels,
    reduction="none",
)

loss = (
    (per_sample * sample_weight).sum()
    / sample_weight.sum().clamp_min(1e-12)
)
loss.backward()
```

这种写法把“每个样本怎样计算”和“怎样组合多个损失”分成两步，便于逐项核对。

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

> [!NOTE] 这段示例只演示一次前向与反向计算
> 完整训练循环通常在每个小批依次执行 `optimizer.zero_grad()`、前向计算、`loss.backward()` 和 `optimizer.step()`。验证时切换到 `eval()` 并使用 `torch.inference_mode()`，返回训练前再调用 `train()`。

### 10.1 先用形状表读懂整个模型

设小批大小为 $N=8$。`SmallCNN` 中各步的形状如下：

| 步骤 | 输入形状 | 输出形状 | 这一层做了什么 |
| --- | --- | --- | --- |
| `Conv2d(3,16,3,padding=1)` | `(8,3,32,32)` | `(8,16,32,32)` | 从每个 $3\times3$ 邻域提取 16 组特征 |
| `BatchNorm2d(16)` | `(8,16,32,32)` | `(8,16,32,32)` | 分别处理 16 个通道的数值尺度 |
| `ReLU()` | `(8,16,32,32)` | `(8,16,32,32)` | 逐元素加入非线性 |
| `MaxPool2d(2)` | `(8,16,32,32)` | `(8,16,16,16)` | 每个 $2\times2$ 窗口保留最大值 |
| 第二个 `Conv2d` | `(8,16,16,16)` | `(8,32,16,16)` | 把通道数从 16 改成 32 |
| `GroupNorm(4,32)` | `(8,32,16,16)` | `(8,32,16,16)` | 每 8 个通道组成一组 |
| `GELU()` | `(8,32,16,16)` | `(8,32,16,16)` | 逐元素加入平滑非线性 |
| `AdaptiveAvgPool2d(1)` | `(8,32,16,16)` | `(8,32,1,1)` | 每个通道汇总为一个数 |
| `Flatten(1)` | `(8,32,1,1)` | `(8,32)` | 保留小批维，合并其余维 |
| `Linear(32,10)` | `(8,32)` | `(8,10)` | 为每张图产生 10 个 logits |

第一个卷积为什么保持 $32\times32$？把卷积输出公式代入：

$$
H_{out}
=\left\lfloor
\frac{H_{in}+2p-d(k-1)-1}{s}+1
\right\rfloor
=\left\lfloor
\frac{32+2\times1-1\times(3-1)-1}{1}+1
\right\rfloor
=32.
$$

式中，$H_{in}=32$ 是输入高度，$p=1$ 是两侧填充，$d=1$ 是膨胀系数，$k=3$ 是卷积核高度，$s=1$ 是步幅。宽度用同一方法计算。

> [!TIP] 先检查一批数据，再开始长时间训练
> 用 `next(iter(loader))` 取一个小批，打印输入、标签和输出形状，可以很早发现通道次序、标签类型及类别数错误。

### 10.2 从人造数据开始搭建可运行的数据读取过程

为了只关注 Layer 与训练步骤，下面用随机张量构造数据集。它不具备真实学习价值，但可以验证程序是否能完整执行。

```python
import torch
from torch.utils.data import DataLoader, TensorDataset

torch.manual_seed(7)

# 96 张训练图、32 张验证图；每张图有 3 个通道，大小为 32×32。
train_images = torch.randn(96, 3, 32, 32)
train_labels = torch.randint(0, 10, (96,), dtype=torch.long)
valid_images = torch.randn(32, 3, 32, 32)
valid_labels = torch.randint(0, 10, (32,), dtype=torch.long)

train_set = TensorDataset(train_images, train_labels)
valid_set = TensorDataset(valid_images, valid_labels)

train_loader = DataLoader(train_set, batch_size=16, shuffle=True)
valid_loader = DataLoader(valid_set, batch_size=16, shuffle=False)

images, labels = next(iter(train_loader))
print(images.shape)  # (16, 3, 32, 32)
print(labels.shape)  # (16,)
print(labels.dtype)  # torch.int64
```

这里有三个容易忽略的细节：

1. `TensorDataset` 按第零维把图像和标签配对，所以两者第零维长度必须相同。
2. 训练数据使用 `shuffle=True`，每轮会重新打乱样本次序；验证数据不需要打乱。
3. `CrossEntropyLoss` 的类别编号目标应为整数类型 `torch.long`，形状通常是 `(N,)`，每个值位于 $[0,C-1]$。

> [!NOTE] 随机数据上的准确率没有任务含义
> 标签和图像彼此无关，模型不可能学到可靠规律。这里关注的是代码、形状、梯度和状态切换。替换成真实数据后，仍应检查样本含义、预处理方式和训练集与验证集的划分。

### 10.3 一个小批的五个训练步骤

一个小批通常按以下次序处理：

```python
optimizer.zero_grad(set_to_none=True)
logits = model(images)
loss = criterion(logits, labels)
loss.backward()
optimizer.step()
```

逐行解释如下。

#### 第一步：清理旧梯度

PyTorch 默认把多次反向计算所得梯度相加。若上一个小批留下了梯度而没有清理，当前小批的结果会继续累加到 `parameter.grad`。普通训练每个小批都先调用

```python
optimizer.zero_grad(set_to_none=True)
```

`set_to_none=True` 会把梯度设为 `None`，而不是填成全零张量，常能减少不必要的写入。若确实想把多个小批的梯度相加后再更新参数，就要明确设计累加次数，并对损失缩放。

#### 第二步：前向计算

```python
logits = model(images)
```

这一步按 `forward` 中定义的计算得到预测。只要输入和参数需要梯度，PyTorch 就会记录反向计算所需的信息。`logits` 的形状为 `(N,10)`，每一行对应一张图的 10 个类别得分。

#### 第三步：计算标量损失

```python
loss = criterion(logits, labels)
```

默认 `CrossEntropyLoss(reduction="mean")` 对小批中所有样本的损失取平均，因而 `loss.shape` 是空形状 `torch.Size([])`，也就是一个标量张量。

假设一个小批有两个样本，单样本损失分别为 1.2 和 0.8，那么平均损失为

$$\frac{1.2+0.8}{2}=1.0.$$

#### 第四步：自动求导

```python
loss.backward()
```

这一步计算损失对每个可学习参数的偏导，并把结果存入参数的 `.grad`。它只计算梯度，不会自行改变权重。

```python
first_weight = model.features[0].weight
print(first_weight.shape)       # (16, 3, 3, 3)
print(first_weight.grad.shape)  # 与参数形状相同
```

#### 第五步：优化器更新参数

```python
optimizer.step()
```

以最简单的随机梯度下降为例：

$$\theta_{\text{new}}=\theta_{\text{old}}-\eta g,$$

其中 $\theta$ 表示参数，$g$ 表示当前梯度，$\eta$ 表示学习率。Adam 还会维护梯度的一阶和二阶历史统计，但使用步骤仍然是 `zero_grad`、`backward`、`step`。

> [!WARNING] `backward()` 和 `step()` 的职责不同
> `backward()` 负责求梯度，`step()` 负责依据梯度修改参数。只调用前者，权重保持不变；只调用后者而没有有效梯度，也得不到本轮所需的更新。

### 10.4 完整的训练轮与验证函数

下面代码可直接接在 `SmallCNN` 与数据读取代码之后。它会自动使用可用的 CUDA 设备，否则使用 CPU。

```python
import torch
from torch import nn

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model = SmallCNN(n_classes=10).to(device)
criterion = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(model.parameters(), lr=1e-3)


def train_one_epoch(model, loader, criterion, optimizer, device):
    model.train()
    loss_sum = 0.0
    correct = 0
    sample_count = 0

    for images, labels in loader:
        images = images.to(device)
        labels = labels.to(device)

        optimizer.zero_grad(set_to_none=True)
        logits = model(images)
        loss = criterion(logits, labels)
        loss.backward()
        optimizer.step()

        batch_size = labels.size(0)
        loss_sum += loss.item() * batch_size
        predictions = logits.argmax(dim=1)
        correct += (predictions == labels).sum().item()
        sample_count += batch_size

    return {
        "loss": loss_sum / sample_count,
        "accuracy": correct / sample_count,
    }


def evaluate(model, loader, criterion, device):
    model.eval()
    loss_sum = 0.0
    correct = 0
    sample_count = 0

    with torch.inference_mode():
        for images, labels in loader:
            images = images.to(device)
            labels = labels.to(device)

            logits = model(images)
            loss = criterion(logits, labels)

            batch_size = labels.size(0)
            loss_sum += loss.item() * batch_size
            predictions = logits.argmax(dim=1)
            correct += (predictions == labels).sum().item()
            sample_count += batch_size

    return {
        "loss": loss_sum / sample_count,
        "accuracy": correct / sample_count,
    }


for epoch in range(2):
    train_metrics = train_one_epoch(
        model, train_loader, criterion, optimizer, device
    )
    valid_metrics = evaluate(model, valid_loader, criterion, device)
    print(
        f"epoch={epoch + 1} "
        f"train_loss={train_metrics['loss']:.4f} "
        f"train_acc={train_metrics['accuracy']:.3f} "
        f"valid_loss={valid_metrics['loss']:.4f} "
        f"valid_acc={valid_metrics['accuracy']:.3f}"
    )
```

`loss.item()` 得到的是当前小批的平均损失。为了正确得到整套数据的平均值，代码先乘回 `batch_size`，累计各样本损失，再除以总样本数。最后一个小批可能小于设定的 `batch_size`，因此不能简单地对“小批平均值”再次等权平均。

准确率使用

```python
predictions = logits.argmax(dim=1)
```

从每行 10 个得分中选出最大值所在的类别编号。它只用于统计，不参与损失计算。

#### 10.4.1 `train()`、`eval()` 与 `inference_mode()` 分别控制什么

- `model.train()` 把模型及所有子模块设为训练状态，Dropout 会随机置零，BatchNorm 会使用当前小批统计并更新运行统计；
- `model.eval()` 把它们设为评估状态，Dropout 不再随机置零，BatchNorm 使用已保存的运行统计；
- `torch.inference_mode()` 停止记录自动求导信息，并进行适合推理的额外优化。

`eval()` 不会自动停止梯度记录，`inference_mode()` 也不会替代 `eval()` 对 Dropout 和 BatchNorm 的状态设置。因此验证时通常两者同时使用。

> [!EXAMPLE] 为什么评估后要重新调用 `train()`
> 如果在每一轮末尾运行 `evaluate()`，模型会停留在评估状态。下一轮开头的 `model.train()` 不可省略，否则 Dropout 和 BatchNorm 会继续按评估方式工作。

#### 10.4.2 何时使用梯度裁剪

循环网络等模型有时会出现梯度范数非常大。可以在 `backward()` 之后、`step()` 之前加入：

```python
loss.backward()
total_norm = torch.nn.utils.clip_grad_norm_(model.parameters(), max_norm=1.0)
optimizer.step()
```

`clip_grad_norm_` 把所有参数的梯度看成一个整体；当总范数大于 `max_norm` 时，按相同比例缩小。返回值是裁剪前的总范数，可用于日志。不要把它写在 `backward()` 之前，因为那时本轮梯度还未算出。

### 10.5 保存与恢复训练状态

只保存模型参数适合推理：

```python
torch.save(model.state_dict(), "small_cnn_weights.pt")

restored_model = SmallCNN(n_classes=10).to(device)
state = torch.load("small_cnn_weights.pt", map_location=device)
restored_model.load_state_dict(state)
restored_model.eval()
```

若要稍后继续训练，还应保存优化器状态和当前轮数：

```python
checkpoint = {
    "epoch": 2,
    "model": model.state_dict(),
    "optimizer": optimizer.state_dict(),
}
torch.save(checkpoint, "small_cnn_checkpoint.pt")

loaded = torch.load("small_cnn_checkpoint.pt", map_location=device)
model.load_state_dict(loaded["model"])
optimizer.load_state_dict(loaded["optimizer"])
start_epoch = loaded["epoch"]
print(start_epoch)
```

优化器状态可能包含动量或 Adam 的历史统计，只恢复模型权重而新建优化器，会丢失这些训练信息。加载后还要确保模型结构、类别数与保存时相容。

> [!CAUTION] 只加载可信来源的文件
> `torch.load` 使用 Python 的序列化机制。对来源不明的文件，不应直接加载。版本较新的 PyTorch 提供了更严格的加载选项，但使用前要核对当前安装版本的函数签名。

### 10.6 用一个小批进行系统排查

模型报错或结果异常时，可以先执行下面的检查：

```python
images, labels = next(iter(train_loader))
images = images.to(device)
labels = labels.to(device)

print("images:", images.shape, images.dtype, images.device)
print("labels:", labels.shape, labels.dtype, labels.device)
print("label range:", labels.min().item(), labels.max().item())

model.train()
logits = model(images)
print("logits:", logits.shape, logits.dtype, logits.device)
print("finite logits:", torch.isfinite(logits).all().item())

loss = criterion(logits, labels)
print("loss:", loss.item(), "finite:", torch.isfinite(loss).item())

optimizer.zero_grad(set_to_none=True)
loss.backward()
for name, parameter in model.named_parameters():
    if parameter.grad is None:
        print("no grad:", name)
    elif not torch.isfinite(parameter.grad).all():
        print("non-finite grad:", name)
```

检查顺序包含：

1. 输入是否是 `(N,C,H,W)`，而不是常见于图像文件的 `(N,H,W,C)`；
2. 图像与模型参数是否位于同一设备；
3. 标签是否为 `long`，最小值和最大值是否在类别范围内；
4. 输出最后一维是否等于类别数；
5. 输出、损失和梯度是否都是有限数；
6. 预期参与训练的参数是否真的拿到了梯度。

如果模型能运行但准确率一直接近随机猜测，还应核对图像与标签配对、输入缩放、类别编号、数据重复、学习率以及训练和评估状态。先让几十个样本被模型明显拟合，常能帮助区分“程序有误”和“任务本身较难”。

---

## 11. 版本兼容与非层工具

- `Module` 是所有模块的基类；`Container` 是历史容器基类，日常直接使用 `Sequential`、`ModuleList` 或 `ModuleDict`。
- `Parameter`、`ParameterList`、`ParameterDict` 用来登记可学习张量。`UninitializedParameter`、`UninitializedBuffer` 是 Lazy 模块在第一次输入前使用的内部对象。
- `RNNBase`、`RNNCellBase` 是 RNN 家族基类，应实例化 `RNN`、`GRU`、`LSTM` 或对应的 Cell。
- `DataParallel` 用于把一个模型复制到多张 GPU 执行，不属于网络层。新代码在多 GPU 训练中通常使用 `DistributedDataParallel`。
- `CrossMapLRN2d` 与 `NLLLoss2d` 主要为旧代码兼容而保留；新模型分别使用 `LocalResponseNorm` 和 `NLLLoss`。
- PyTorch 2.0.1 的 `LayerNorm` 没有单独的 `bias=` 构造参数；`elementwise_affine=False` 会同时移除 `weight` 和 `bias`。阅读较新版本文档时，应先核对本地函数签名。
- 若较新版本文档中出现本仓库 2.0.1 没有的归一化模块，应以当前环境的 `hasattr(torch.nn, name)` 与本地 API 为准，再决定是否升级。
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
