# 通用 NPU 模型编译器

`npu_compile.py` 把规范化 JSON IR 编译为单核 NPU 可加载文件。它与已有
Keras 工具各自独立：Keras 工具负责训练、TFLite 导出和参考结果检查；本工具
负责低层算子、张量地址、依赖事件、128-bit CMD 和 Descriptor 的生成。

## 支持范围

本工具当前处理五类执行单元的规范化算子：

- Control：`NOP`、事件操作和 `GLOBAL_FENCE`；
- DMA：一维或多维复制、填充、二维转置、PACK 和 SPLIT；
- Matrix：GEMM、BMM、GEMM_ACCUM 和 GEMM_ZERO；
- Vector：ADD、SUB、MUL、FMA、比较、选择、CLAMP 和 ReLU；
- Complex：激活函数、Softmax、Norm、统计、倒数和 ADD_RESCALE。

数据类型编码包含 INT4、INT8、INT16 和 INT32。输入 IR 直接描述已经被前端
接受的算子，不会把任意框架模型自动变成设备程序。若要接入 ONNX、Keras、
PyTorch 或 TFLite，应由对应前端先完成图检查、常量处理、算子选择和张量地址
分配，再生成这里定义的 JSON IR。这样可以明确指出不支持的节点，避免输出看似
成功但设备无法执行的文件。

## 生成文件

假设输入为 `model.json`，命令会生成：

| 文件 | 内容 |
|---|---|
| `model.cmd.bin` | CMD128 数组；每项 16B，先保存 low 64-bit，再保存 high 64-bit，均为小端字节序 |
| `model.desc.bin` | 64B 对齐的 Descriptor 连续区 |
| `model.manifest.json` | 地址、偏移、事件、命令值和 SHA-256 |
| `model.npu.h` | 可选的 C 字节数组 |

CMD128 使用以下格式：

- `low[47:0]`：Descriptor 地址；
- `low[59:48]`：`command_id`；
- `low[63:60]`：执行单元；
- `high[7:0]`：opcode；
- `high[19:8]`：`header_flags`；
- `high[31:20]`、`high[43:32]`：两个等待事件；
- `high[55:44]`：完成事件；
- `high[63:56]`：`header_version=1`。

64-bit 主总线提交时先发送 low，控制位取 `first=1,last=0`；随后发送 high，
控制位取 `first=0,last=1`。

## 运行

```bash
cd "/home/yusen/Obsidian Vault/NPU/compiler"
python3 npu_compile.py examples/int16_regression.json \
  --output-dir build/int16-regression \
  --emit-c-header
python3 npu_compile.py examples/int16_regression.json \
  --output-dir build/int16-regression \
  --emit-c-header --check
python3 -m unittest discover -s tests -v
```

`--check` 不修改文件，它重新编译并逐字节检查已有文件，适合持续集成。

## IR 主要字段

顶层字段如下：

```json
{
  "schema_version": 1,
  "target": {
    "command_format": "cmd128-v1",
    "descriptor_base": "0x100000",
    "mt": 8,
    "kt": 16,
    "nt": 8
  },
  "tensors": {},
  "operations": []
}
```

每个张量至少给出 `addr`、`space` 和 `dtype`。`space` 为 `l1` 或 `ddr`，
`dtype` 为 `int4`、`int8`、`int16` 或 `int32`。建议同时填写
`region_bytes`，DMA Descriptor 会优先使用它。

每个算子至少给出：

```json
{
  "name": "load_input",
  "command_id": 1,
  "engine": "dma",
  "opcode": "COPY_1D",
  "descriptor": {
    "common": {},
    "dma": {}
  }
}
```

`descriptor.common` 中的 `src0`、`src1`、`src2`、`dst`、`aux0` 和
`aux1` 可以引用顶层张量名，也可以内嵌地址对象。工具据此写入地址、类型编码和
L1/DDR 地址类型位。每类执行单元的专有字段放在同名对象中。

`depends_on` 可引用前面最多两个算子。编译器会给生产者分配事件，并把事件写入
消费者的两个等待字段。也可以显式填写 `wait_events` 和 `signal_event`：

```json
{
  "wait_events": [
    {"id": 3, "generation": 0},
    "none"
  ],
  "signal_event": {"id": 4, "generation": 0}
}
```

显式事件和自动依赖不可同时用于同一消费者。一个事件引用由 8-bit ID 和 4-bit
generation 组成；`0xFFF` 表示没有事件。

不在结构化字段中的后续扩展可使用 `descriptor.raw_hex` 提供完整 Descriptor。
该字段必须恰好包含对应执行单元规定的字节数。使用此方式时，调用方承担字段
合法性检查责任。

示例 `int16_regression.json` 展示 INT16 输入复制和 INT16 权重 GEMM。偏置仍
建议使用 INT32，乘加中间值也应保留较宽精度，最终结果按 Descriptor 的缩放
参数和饱和模式写为 INT16。
