# Keras Transformer 自然语言分类端到端测试

本目录提供一个可重复训练的自然语言命令分类示例。测试不是给网络手工填写固定权重，也不是把预期输出写入设备内存。`build_model.py` 调用 Keras `model.fit()` 训练模型，保存 `.keras` 文件；通用模型编译器读取该文件并生成 C 配置、CMD128、Descriptor 和权重数组；C 程序通过 NPU 驱动提交命令，再从 CModel 的系统内存输出地址读取结果。

## 1. 分类任务

输入是一条由 4 个英文单词组成的房间设备命令：

```text
[动作, 设备, 状态, 执行说明]
```

词表和每个词的含义如下：

| 单词 | 含义 |
| --- | --- |
| `turn` | 执行设备开关命令 |
| `set` | 设置设备状态 |
| `light` | 房间灯 |
| `fan` | 房间风扇 |
| `on` | 打开 |
| `off` | 关闭 |
| `now` | 立即执行 |
| `room` | 对当前房间执行 |

模型把句子分为 4 种意图：

| 类别编号 | 类别名 | 例句 |
| ---: | --- | --- |
| 0 | `light_on` | `turn light on now` |
| 1 | `light_off` | `set light off room` |
| 2 | `fan_on` | `turn fan on room` |
| 3 | `fan_off` | `set fan off now` |

动作有 2 种，设备有 2 种，状态有 2 种，执行说明有 2 种，因此完整语料共有

$$
2\times2\times2\times2=16
$$

条命令。训练脚本把其中 12 条送入 `model.fit()`，下面 4 条只用于训练后的检查：

```text
turn light on room  -> light_on
set light off now   -> light_off
turn fan on now     -> fan_on
set fan off room    -> fan_off
```

> [!note] 为什么保留训练时未使用的句子
> 如果训练和检查使用完全相同的句子，只能说明模型记住了训练数据。本示例为每个类别保留一条没有传给 `fit()` 的组合，用它检查模型能否忽略动作词和执行说明的变化，正确识别“设备 + 状态”所决定的意图。

## 2. 输入如何表示

词表包含 8 个词，每个词使用长度为 8 的 one-hot 向量。例如词表顺序为：

```text
[turn, set, light, fan, on, off, now, room]
```

那么 `light` 的浮点输入是：

```text
[0, 0, 1, 0, 0, 0, 0, 0]
```

NPU 使用 Q5 INT8，实数 1 对应整数 32，因此 `light` 在设备内存中的真实字节数值是：

```text
[0, 0, 32, 0, 0, 0, 0, 0]
```

一条句子有 4 个词，所以单次推理的输入形状为 `[1, 4, 8]`，共 32 个 INT8 元素。运行程序会打印每个位置的单词、含义、INT8 one-hot 数组和按 `q/32` 还原的数值，便于逐项确认输入。

## 3. 模型结构与训练

模型结构为：

```text
Input [1,4,8]
  -> MultiHeadAttention(2 heads, use_bias=False)
  -> Add
  -> LayerNormalization
  -> Dense(16, GELU)
  -> Dense(8)
  -> Add
  -> LayerNormalization
  -> Dense(4, Tanh)
  -> token logits [1,4,4]
```

注意力层不使用 projection bias，是因为当前高层 Transformer 导入程序支持 Q、K、V 和输出投影权重，但该节点尚未接收这四组 bias。两个普通 Dense 层和最终分类层都带有 bias，并由编译器分别生成矩阵乘法和 bias 加法任务。

训练时，同一句话的类别会复制到 4 个 token 位置。每个位置都必须输出句子类别，因此某个位置不能只依赖当前位置的单词。例如位置 0 只有 `turn` 或 `set`，它必须通过自注意力读取 `light/fan` 与 `on/off` 才能判断类别。

句子的 4 组 token 得分分别记为 $\boldsymbol{z}_0$、$\boldsymbol{z}_1$、$\boldsymbol{z}_2$ 和 $\boldsymbol{z}_3$。Keras 和 C 程序都使用下面的平均值选取整句类别：

$$
\bar{\boldsymbol{z}}
=
\frac{
\boldsymbol{z}_0+\boldsymbol{z}_1+
\boldsymbol{z}_2+\boldsymbol{z}_3
}{4}.
$$

$\bar{\boldsymbol{z}}$ 有 4 个分量，分别对应 `light_on`、`light_off`、`fan_on` 和 `fan_off`。最大分量所在位置就是预测类别。

训练使用固定随机种子 `20260726`、Adam 优化器、学习率 `0.004`、batch size 1 和 240 个 epoch。当前实测结果为：

| 项目 | 结果 |
| --- | ---: |
| 训练前 loss | 1.5465407 |
| 训练前逐 token accuracy | 0.2916667 |
| 训练后 loss | 0.3409346 |
| 训练后逐 token accuracy | 1.0000000 |
| 训练语句整句 accuracy | 12 / 12 |
| 未参与训练的语句 loss | 0.3409491 |
| 未参与训练的语句逐 token accuracy | 1.0000000 |
| 未参与训练的语句整句 accuracy | 4 / 4 |
| 训练后全部参数范围 | `[-1.2484962, 1.8534964]` |

> [!important] 参数范围检查
> Q5 INT8 能表示的实数范围是 `[-4, 3.96875]`。保存模型前，脚本会检查所有训练参数是否落在该范围内；超出范围会直接报错，而不会悄悄截断参数。

## 4. 编译后的任务序列

编译器把 18 个高层算子展开为 57 条 CMD128。每组最多提交 8 条命令，因此单次推理包含 8 个 FIXED burst：

| 批次 | 命令编号 | 本批主要工作 |
| ---: | --- | --- |
| 0 | 0～7 | 装入常量和输入；移除大小为 1 的 batch 维度；执行 Q、K、V 投影；开始准备 head 0 |
| 1 | 8～15 | 准备两个 head 的 Q、K、V；等待所需 event；计算 $QK^\mathsf{T}$；执行 Softmax |
| 2 | 16～23 | 计算注意力权重与 V 的乘积；合并两个 head；执行输出投影；完成第一次残差相加 |
| 3 | 24～31 | 等待残差数据和 LayerNorm 参数；执行第一次 LayerNorm；执行 FFN 扩展、bias 加法和 GELU |
| 4 | 32～39 | 执行 FFN 收缩矩阵乘法、bias 加法和输出整理 |
| 5 | 40～47 | 完成第二次残差相加与第二次 LayerNorm；开始最终 4 类 Dense 计算 |
| 6 | 48～55 | 完成分类层 bias 加法、输出整理和 Tanh；恢复大小为 1 的 batch 维度 |
| 7 | 56 | 把 `[1,4,4]` 输出写回系统内存 |

第一条测试语句会打印全部任务记录：

```text
submit ... op=任务名 command_id=命令编号
wait=[第一个事件,第二个事件] signal=完成事件
complete ... status=0
ack ... command_id=命令编号
```

`wait` 表示当前任务开始前必须已经成功的 event，`signal` 表示当前任务成功后更新的 event。`complete` 表示执行已结束，`ack` 表示软件读取状态后回收任务项。其余三条语句执行相同的 57 条命令，为避免终端重复数百行，只打印输入和推理结果。

## 5. 系统内存内容与 C 驱动

当前编译结果声明的系统内存内容如下：

| 内容 | 起始地址 | 字节数 |
| --- | ---: | ---: |
| Descriptor | `0x10000` | 10048 B |
| 权重 | `0x20000` | 2240 B |
| 单条输入 | `0x208c0` | 32 B |
| 单条输出 | `0x20900` | 16 B |

每条语句执行前，runner 会清空 L1 和系统内存，再复制 Descriptor、训练得到的权重以及当前语句的 one-hot 输入。随后依次调用：

```text
npu_drv_sync_for_device()
npu_drv_submit_batch()
npu_drv_wait_task()
npu_drv_query_status()
npu_drv_ack_task()
npu_drv_fence()
npu_drv_sync_for_cpu()
```

最后一个同步操作完成后，runner 从编译器声明的输出地址读取 16 个 INT8 元素。测试头文件中的 Keras 结果只用于比较，不会被复制到输出地址。

## 6. 运行方法

TensorFlow 和 Keras 使用 Conda 环境 `tf_2_18`：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel/examples/transformer"
make clean
make test
```

也可以分步执行：

```bash
make model
make compile
make check
make test
```

其中：

- `make model`：调用 `model.fit()`、保存 `.keras`、生成固定测试头文件和训练报告；
- `make compile`：生成 C 配置、CMD128、Descriptor、权重和 manifest；
- `make check`：再次生成并比较文件摘要，同时检查生成 C 源码；
- `make test`：编译 runner，并执行 4 条未参与训练的语句。

## 7. 当前端到端结果

当前固定随机种子的实测结果如下：

| 项目 | 单条语句 | 4 条语句合计 |
| --- | ---: | ---: |
| CMD128 | 57 | 228 |
| 64-bit command beat | 114 | 456 |
| 提交批次 | 8 | 32 |
| 完成响应 | 57 | 228 |
| CModel 周期 | 3052 | 12208 |
| cache clean | 3 | 12 |
| cache invalidate | 1 | 4 |

分类和数值比较结果为：

| 项目 | 结果 |
| --- | ---: |
| Keras 整句 accuracy | 4 / 4 = 1.0000000 |
| CModel 整句 accuracy | 4 / 4 = 1.0000000 |
| CModel 与 Keras 类别一致 | 4 / 4 = 1.0000000 |
| INT8 输出完全相同 | 64 / 64 |
| 最大绝对误差 | 0 LSB |
| 平均绝对误差 | 0 LSB |
| 均方误差 | 0 LSB² |

末尾成功信息为：

```text
classification_metrics CModel_accuracy=4/4=1.0000000 Keras_accuracy=4/4=1.0000000 agreement=4/4=1.0000000
CModel_vs_Keras exact=64/64 ... max_abs_error_lsb=0 mae_lsb=0.0000000 mse_lsb2=0.0000000
PASS model=keras_transformer_intent_classifier commands_per_sample=57 cmd_bits=128 batches_per_sample=8 samples=4
```

## 8. 其他模型

RNN、GRU、LSTM 和 CNN 的训练、编译、C 驱动与 CModel 测试见
[`../README.md`](../README.md)。
