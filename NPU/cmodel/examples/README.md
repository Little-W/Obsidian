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
    ├─ CMD128 和 Descriptor 生成
    └─ C 配置、命令、Descriptor、权重和输入输出信息
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
| `transformer/` | 把 4 个英文单词组成的房间设备命令分为开灯、关灯、开风扇和关风扇 | `MultiHeadAttention(2 heads) → Add → LayerNorm → Dense(GELU) → Dense → Add → LayerNorm → Dense(4, Tanh)` | 4 条未参与训练的命令，每条 4 个 token | `.keras` |

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

Transformer 使用 8 个英文词组成 16 条房间设备命令。构建脚本把 12 条命令送入 Keras `model.fit()`，把其余 4 条留作训练后检查。输入形状为 `[1,4,8]`，每个 token 用 8 元 one-hot 向量表示。详细语料、词义和类别定义见 [`transformer/README.md`](transformer/README.md)。

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

## 3. 软件与 NPU 的工作划分

### 3.1 SimpleRNN

一个时刻的 SimpleRNN 计算为：

$$
h_t
=
\tanh
\left(
x_tW_x+h_{t-1}W_h+b
\right).
$$

NPU 执行两个矩阵乘法、bias 加法、两个结果相加和 Tanh。C 侧只把上一时刻输出作为下一时刻的 `h_prev` 输入，不替代单元内部计算。

### 3.2 GRU

GRU 的主要计算为：

$$
z_t
=
\sigma
\left(
x_tW_z+h_{t-1}U_z+b_z
\right),
$$

$$
r_t
=
\sigma
\left(
x_tW_r+h_{t-1}U_r+b_r
\right),
$$

$$
\tilde{h}_t
=
\tanh
\left(
x_tW_h+r_t\odot(h_{t-1}U_h)
\right),
$$

$$
h_t
=
z_t\odot h_{t-1}
+(1-z_t)\odot\tilde{h}_t.
$$

$z_t$ 是更新门，$r_t$ 是重置门，$\sigma$ 是 Sigmoid，$\odot$ 表示同一位置元素相乘。

NPU 计算两个门的矩阵乘法、加法和 Sigmoid，并计算 $x_tW_h$、$h_{t-1}U_h$ 两个候选状态投影。当前 Vector `MUL` 的结果类型为 INT32，不能直接作为下一个时刻要求的 INT8 隐状态，因此 C 侧暂时用 FP32 完成门控乘法和状态更新，再按 Q5 编回 INT8。终端输出会明确打印两个门的 INT8 数值。

### 3.3 LSTM

LSTM 的四组门值为：

$$
i_t=\sigma(x_tW_i+h_{t-1}U_i+b_i),
$$

$$
f_t=\sigma(x_tW_f+h_{t-1}U_f+b_f),
$$

$$
g_t=\tanh(x_tW_g+h_{t-1}U_g+b_g),
$$

$$
o_t=\sigma(x_tW_o+h_{t-1}U_o+b_o).
$$

状态更新为：

$$
c_t=f_t\odot c_{t-1}+i_t\odot g_t,
$$

$$
h_t=o_t\odot\tanh(c_t).
$$

NPU 计算 $i_t$、$f_t$、$g_t$、$o_t$ 的矩阵乘法、bias 加法、结果相加和激活函数。C 侧用 FP32 临时值完成 $c_t$ 与 $h_t$ 的元素乘法和加法，再把 $h_t$ 编回 INT8，供下一个时刻使用。

### 3.4 CNN

CNN 的 3×3 卷积不要求底层已经具有专用卷积指令。编译器把卷积拆为：

```text
输入图像
  → 9 个 COPY_ND，组成 im2col 数据
  → GEMM
  → ReLU
  → COPY_1D 完成 Flatten
  → Dense GEMM
  → bias Add
  → Tanh
```

因此，CNN 示例同时检查 Keras 前端、Conv2D 的 im2col 拆分、Matrix、Vector、Complex 和 DMA。C 侧只准备输入、提交命令并读取结果，不计算卷积或全连接层。

> [!important] CNN 如何经过 C 驱动执行
> `cnn/build_model.py` 先训练并导出 Keras 模型，通用编译器再生成 Descriptor、权重、32 条 CMD128 和 4 个提交批次。公共 backend 位于 `common/cmodel_driver_backend.c`，它服务所有模型，不再依赖已删除的旧示例目录。CNN runner 按编译器给出的系统内存地址复制 Descriptor、权重和当前输入，调用 `npu_drv_sync_for_device()`，再通过 `npu_drv_submit_batch()` 提交每组命令。每条任务完成后执行 WAIT、QUERY 和 ACK。输出读取前调用 `npu_drv_sync_for_cpu()`，随后从编译器声明的输出地址读取 3 个 INT8 分数。Keras 参考分数和类别只用于结果比较，不会写入 CModel 输出区域。

> [!note] 为什么循环层不直接把 `.keras` 交给编译器
> 当前 Keras 前端可以直接处理本示例的 CNN，但尚未直接展开 Keras 的 SimpleRNN、GRU 和 LSTM 层。构建脚本会读取训练完成后的循环层权重，并生成只含 MatMul、Add、Sigmoid 和 Tanh 的高层 JSON 模型。这个 JSON 仍由同一个 `npu_model_compiler.py` 完成后续编译。

### 3.5 Transformer

Transformer 示例先用 Keras `model.fit()` 训练一个四分类自然语言命令模型，再把训练后的双头自注意力展开为 Q、K、V 投影，两个 head 的数据整理，$QK^\mathsf{T}$，Softmax，注意力结果与 V 的矩阵乘法，head 合并和输出投影。随后执行第一次残差相加与 LayerNorm、前馈网络、第二次残差相加与 LayerNorm，以及输出 4 个意图分数的 Dense 和 Tanh。

模型为每个 token 输出 4 个分类分数，输出形状是 `[1,4,4]`。C 程序对 4 个 token 的同类分数取平均值，再选择平均分最大的类别。编译器共生成 57 条 CMD128，按 8、8、8、8、8、8、8、1 条分为 8 个提交批次。任务通过 wait event 声明输入依赖，通过 signal event 通知后续任务。运行程序会为第一条语句逐条打印任务名、命令编号、wait event、signal event、完成状态和回收操作，详细说明见 [`transformer/README.md`](transformer/README.md)。

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

## 7. 生成文件

每个模型的 `build/` 都是可删除的生成目录。主要文件如下：

| 文件 | 内容 |
| --- | --- |
| `build/model.keras` | RNN、GRU、LSTM、CNN 训练完成的 Keras 模型 |
| `build/model.json` | RNN、GRU、LSTM 的单时刻高层模型；CNN 没有此文件 |
| `build/generated/model_model.h` | C 类型、尺寸、地址、输入输出和数组声明 |
| `build/generated/model_model.c` | C 配置、CMD128 数组、Descriptor 字节数组、权重数组和命令分组 |
| `build/generated/model.manifest.json` | 算子、指令数、Descriptor 字节数、权重字节数和生成文件摘要 |
| `build/generated/model_fixture.h` | 固定输入、目标值和 Keras 参考输出 |
| `build/generated/model_report.json` | TensorFlow/Keras 版本、训练配置和训练指标 |
| `build/model_infer` | C 驱动加 CModel 推理程序 |

Transformer 的同类文件位于 `transformer/build/generated/`，文件名前缀为 `keras_transformer`；其可执行程序是 `transformer/build/transformer_runner`。

生成的 C 包含这些核心对象：

```c
model_model_config
model_model_commands
model_model_descriptors
model_model_weights
model_model_inputs
model_model_outputs
model_model_command_batches
model_model_batch_command_ids
```

`model_model_commands` 的每个元素包含 `low` 和 `high` 两个 64-bit word。`model_model_command_batches` 把命令分为每组不超过 8 条，以满足一次 FIXED burst 最多 16 个 64-bit beat 的限制。

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

每次运行都会打印：

```text
command_batch[0]: commands=8 beats=16 responses=8 rc=0
```

字段含义如下：

- `commands`：本次提交的 CMD128 数量；
- `beats`：64-bit beat 数量，恒等于 `2 × commands`；
- `responses`：收到的命令响应数量；
- `rc=0`：本次提交和所有响应均成功。

如果设备返回错误，程序还会打印命令编号、设备状态、FIFO 空闲项数和原始响应值。

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

Transformer 会逐个打印命令中的单词和含义、8 元 one-hot 输入、每个 token 的 4 个 Keras 分数、4 个 CModel 分数、逐项误差以及整句平均分。例如：

```text
result sample=0 sentence="turn light on room" true_intent=light_on
token_position=1 word=light meaning="the room light"
  input_one_hot_INT8=[0,0,32,0,0,0,0,0]
  Keras_reference_INT8=[32,-32,-32,-32]
  CModel_output_INT8=[32,-32,-32,-32]
  absolute_error_lsb=[0,0,0,0]
Keras_prediction=light_on CModel_prediction=light_on true_intent=light_on
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
| Transformer | loss 1.5465407，accuracy 0.2916667 | loss 0.3409346，accuracy 1.0 | 未参与训练的 4 条语句 loss 0.3409491，accuracy 1.0 | 整句 accuracy 4/4 |

### 10.2 CModel 结果

| 模型 | CModel 对目标 | CModel 对 Keras | 其他结果 |
| --- | --- | --- | --- |
| RNN | MSE 0.000336368，MAE 0.0152961，R² 0.990780 | MSE 0.000309134，最大绝对误差 0.0486806 | 12 次单时刻运行全部通过 |
| GRU | MSE 0.000248849，MAE 0.0132689，R² 0.993179 | MSE 0.000234086，最大绝对误差 0.0352441 | 12 次单时刻运行全部通过 |
| LSTM | MSE 0.000175715，MAE 0.0105138，R² 0.995183 | MSE 0.000145138，最大绝对误差 0.0361390 | 12 次单时刻运行全部通过 |
| CNN | 6/6 分类正确，accuracy 1.0 | 6/6 类别一致，MSE 0.0000244733 | 三个类别各检查 2 张图 |
| Transformer | 4/4 条未参与训练的语句分类正确，accuracy 1.0 | 4/4 类别一致；64/64 个 INT8 输出相同；最大误差、MAE 和 MSE 均为 0 | 每条语句对 4 个 token 的分类分数取平均 |

### 10.3 编译产物规模

| 模型 | CMD128 数量 | 命令组数 | Descriptor | 权重 |
| --- | ---: | ---: | ---: | ---: |
| RNN | 13 | 2 | 2432 B | 448 B |
| GRU | 43 | 6 | 6656 B | 1472 B |
| LSTM | 55 | 7 | 8192 B | 1984 B |
| CNN | 32 | 4 | 5568 B | 832 B |
| Transformer | 57 | 8 | 10048 B | 2240 B |

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
