---
title: 开源 DFT 实验准备
type: lab-guide
tags:
  - DFT
  - ATPG
  - 开源工具
updated: 2026-08-12
---

# 开源 DFT 实验准备

本目录提供开源预习材料，用于完成组合逻辑 ATPG、故障仿真和扫描插入的基础训练。主实验使用本机的 Synopsys 工具；与 DFTC Lab 3 至 Lab 9 对应的设计资料见 [[实验配套资料/README]] 和 [[商业工具实验准备]]。

## 已获取资源

| 资源 | 提交编号 | 许可证 | 适用内容 |
| --- | --- | --- | --- |
| `Fault/` | `cf5509f` | Apache-2.0 | Verilog 网表的 ATPG、故障仿真和扫描链拼接。 |
| `FAN_ATPG/` | `26b2b36` | MIT | FAN（fan-out-oriented）ATPG、故障仿真、静态压缩和动态压缩。 |

资源地址：

- [AUCOHL/Fault](https://github.com/AUCOHL/Fault)
- [NTU-LaDS-II/FAN_ATPG](https://github.com/NTU-LaDS-II/FAN_ATPG)

## FAN_ATPG：可直接运行的组合逻辑 ATPG

已在 `FAN_ATPG/bin/opt/fan` 准备可执行文件，并使用 ISCAS-85 `s27` 示例完成检查：故障覆盖率（Fault Coverage）为 `94.55%`，生成 `5` 个测试向量。

```bash
cd "/home/yusen/Obsidian Vault/DFT/开源实验资源/FAN_ATPG"
./bin/opt/fan -f script/fanScripts/atpg_s27.script
sed -n '1,120p' rpt/FAN_s27.rpt
```

本项目的源代码构建要求 C++11、Bison 和 Flex。当前目录名含空格，直接执行 `make` 会受旧版 Makefile 的目录处理方式影响；日常实验可直接使用已准备的 `bin/opt/fan`。如需重新编译，请在不含空格的临时目录中复制 `FAN_ATPG` 后执行 `make`，再将生成的 `bin/opt/fan` 放回本目录。

## Fault：扫描插入与 ATPG

Fault 支持扫描链拼接（scan chain stitching）、测试向量生成和故障仿真。当前已获取源代码；本机尚未安装 Swift 或 Nix，但 Docker 已可用。建议通过容器运行，避免手工安装 Swift、Icarus Verilog、Yosys 和其他依赖。

```bash
cd "/home/yusen/Obsidian Vault/DFT/开源实验资源/Fault"
docker pull ghcr.io/aucohl/fault:latest
docker run --rm -it -v "$PWD:$PWD" -w "$PWD" \
  ghcr.io/aucohl/fault:latest fault --version
```

阅读顺序：

1. `docs/Source/usage.md`：从网表准备、ATPG 到扫描链插入的完整示例。
2. `docs/Source/installation.md`：Docker、Nix 和手工安装方式。
3. `Tests/`：可运行的测试用例和 Verilog 测试平台。

> [!note] 许可证提示
> Fault 本体使用 Apache-2.0。其部分发行配置可调用 Atalanta 或 PODEM；这些附带工具的许可条款与 Fault 本体不同。开展商业用途前，应逐项检查所调用工具的许可证。

## 推荐训练顺序

1. 使用 FAN_ATPG 在 `s27`、`s208` 等基准电路上生成固定型故障测试向量。
2. 读取 `rpt/` 中的测试覆盖率（Test Coverage）、故障覆盖率（Fault Coverage）和向量数。
3. 使用 Fault 的示例完成扫描链插入，再检查生成网表中的 `ScanIn`、`ScanOut` 和 `ScanEnable`。
4. 回到 DFTC Lab 3 至 Lab 9，将相同概念应用到测试协议、DFT 设计规则检查和层次化扫描插入。
