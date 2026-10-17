# DPV：数据路径验证与 C/C++—RTL 事务等价完整指南

> **第 15 册 · 专用应用**　Data Path Validation。依据 User Guide 第 25 章（第 1066～1080 页）和 Quick Reference Guide DPV 部分；深度用法需参考单独出版的 *VC Formal Data Path Validation User Guide*（该文件未包含在此次上传材料中）。

## 1. 解决的问题与 SEQ 的区别

高性能加法器、乘法器、DSP、编码器和浮点运算单元通常先建立不含硬件周期细节的 C/C++ 算法参考模型，后将其实现为多级流水 RTL。DPV 使用 HECTOR 技术对照高层事务模型和硬件实现的结果，目标是证明相同事务输入产生正确的输出结果，即便两边的执行阶段不同。

**SEQ** 一般比较两个顺序设计及其相关状态；**DPV** 强调事务级数据变换的对照，例如参考模型在一个函数中完成计算，RTL 则经过 4 个周期才输出。它并不把两个模型天真地逐拍对齐，而是需要声明输入与输出的**事务阶段关系**。

![DPV 的事务阶段对照](插图/13_DPV阶段.svg)

## 2. 典型应用示例：8 位加法器

参考 C++ 函数计算 `uint8_t y = (uint8_t)(a+b)`；RTL 可能有两拍流水线：第 1 拍接收 `a,b`，第 2 拍计算，第 3 拍向输出寄存器提交。若直接比较参考函数返回值与 RTL 每拍 `out`，即使算法正确也可能失败，因为没有处理有效标志和延迟。

需要定义：哪个事件接受一个输入事务；何时读取参考模型参数；RTL 在哪个 phase 输出结果；是否允许同时在流水线中有多个事务；操作是模 256 加法还是需要保留进位位。输入位宽、C++ 整数提升和有符号规则都必须统一。

## 3. C++ 事务接口的结构

User Guide 第 1067 页示例提到 `Hector::registerInput`、`Hector::registerOutput` 以及 `Hector::beginCapture`、`Hector::endCapture` 用于定义事务输入输出及捕获范围。实际完整 C++ 包装代码需要适配安装提供的 HECTOR 头文件与编译前端；**本教程不会凭空编写一个未经验证的完整 HECTOR API 程序并声称可执行**。下列伪接口表达数学规格，而非可直接编译的 HECTOR wrapper：

```cpp
#include <cstdint>
uint8_t add_mod256(uint8_t a, uint8_t b) {
    return static_cast<uint8_t>(a + b);
}
```

编写正式 DPV C++ spec 时还应处理整型符号、移位、未定义行为、数组访问和宿主编译器的优化规则，否则会出现“高层规范自身就不精确”的问题。

## 4. 创建双设计环境

User Guide §25.3 给出基本过程：创建设计、分析源代码、可选展开、编译数据流图。下面分别展示这两个阶段的命令（具体接口及参数仍需按现有工程修改）：

```tcl
set_fml_appmode DPV

proc compile_spec {} {
  create_design -name spec -top hector_wrapper
  cppan model.cc
  compile_design spec
}

proc compile_impl {} {
  create_design -name impl -top alu_pipe -clock clk -reset rst_n -negReset
  vcs -sverilog alu_pipe.sv
  compile_design impl
}

compile_spec
compile_impl
```

`create_design` 将 C++ 包装函数与 RTL 顶层分别定义成可比较的设计。`cppan` 分析 C++，`vcs`/`vlogan`/`vhdlan` 处理 RTL，`compile_design` 构造工具所需的内部结构。不能把 `compile_design` 与普通 FPV 的 `read_file` 混为一谈。

### 4.1 软件版本差异：C++11 前端开关

上传的快速参考稿写了 `set_hector_comp_use_new_flow true`，但 User Guide 第 1069 页给出的 Tcl 示例是：

```tcl
set _hector_comp_use_new_flow true
```

两者不是同一条 Tcl 命令，且 User Guide 指出 C++11 前端可能需要额外许可证。因此本教程以 User Guide 形式提示版本差异，正式脚本应在实际安装环境核验支持的变量及其配置方式，避免照抄未经核实的快速笔记。

## 5. 通过阶段对应建立事务关系

```tcl
proc ual {} {
  map_by_name -inputs  -specphase 1 -implphase 1
  map_by_name -outputs -specphase 1 -implphase 3
}
set_user_assumes_lemmas_procedure "ual"
```

示例将参考模型输入第 1 阶段与 RTL 第 1 阶段相匹配，同时将参考模型输出第 1 阶段与 RTL 第 3 阶段相匹配。两边所使用的相位编号由实际 C++ wrapper/RTL 捕获和阶段定义决定；“第 3 阶段”只是这个例子的合法约定，不能机械用于所有流水线。

`map_by_name` 根据名称批量形成输入假设及输出对照关系；名称不同的信号需要显式指定。处理加法器输出时还要确保 C++ 与 SystemVerilog 的截断规则、运算宽度及溢出处理相同。

## 6. 证明与报告

```tcl
# 在属性已经创建、设计已经编译的前提下运行
check_fv
proofwait
listproofs
listassumes
listlemmas
listcovers
```

对于特定证明对象，DPV 也支持 `solveNB proofName`、`solveNB_init proofName` 等命令；在工程中需要先明确 proof 的名称。调试可以查看对应的反例及 `simcex`，但 C++ 参考模型和 RTL 的相位关系必须正确才能解释差异。

## 7. 完整可验证事务的六个核对项

1. 输入采集的条件是什么，例如 `in_valid && in_ready`。
2. 每个输入事务是否有唯一的 ID 或输出顺序保证。
3. 参考模型与 RTL 对同一个事务使用完全一致的参数。
4. 输出可比较时的有效标志和阶段编号是否正确。
5. 输出整数截断、饱和、舍入和异常处理是否一致。
6. 复位、气泡、停顿、反压、流水线冲刷等情况是否定义在两边的行为中。

若第 1 阶段输入有效但后续遇到 `stall`，事务完成时间可能不是固定三拍，那么应进一步建模阶段条件或使用其他机制，不能持续使用不成立的固定延迟前提。

## 8. 常用命令及作用

| 指令 | 作用 |
|---|---|
| `create_design` | 建立 spec 或 impl 设计以及顶层接口信息 |
| `cppan` / `scdtan` | 分析高层语言模型（具体支持参照安装文档） |
| `vcs` / `vlogan` / `vhdlan` | 分析 RTL |
| `compile_design` | 将设计编译为可比较的内部模型 |
| `set_user_assumes_lemmas_procedure` | 指定生成输入关系与输出比较规则的 Tcl 过程 |
| `map_by_name -inputs/-outputs` | 按命名对应自动创建比较关系 |
| `report_dpv_mappings` | 查看输入输出对应关系 |
| `set_hector_case_splitting_procedure` | 为困难数据路径选择分情况策略 |
| `solveNB` / `proofwait` | 启动与等待证明任务 |
| `listproofs` / `listlemmas` | 查询当前证明对象和结论 |
| `simcex` | 复现及分析比较失败的事务输入 |

## 9. 数据路径证明困难时的策略

分清是**规格定义错误**（C++ 的有符号性/未定义行为）、**阶段设置错误**（错误的输入输出相位）、**RTL 功能错误**，还是**求解规模困难**（乘法/除法/浮点运算）。先用较小位宽和少量操作码验证模型，再推广到完整位宽。必要时按指令类别切分证明目标，或利用 DPV 特有的重写与求解脚本；引擎调优应晚于正确的事务接口设置。

## 10. 官方参考

User Guide §25（1066～1080 页）、Quick Reference Guide DPV 部分。更深入的 HECTOR 包装函数、内部 phase、定制求解策略应以单独的 *VC Formal Data Path Validation User Guide* 为准，不能由通用 UG 的十余页简介替代。
