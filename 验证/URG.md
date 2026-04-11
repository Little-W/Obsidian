# URG 覆盖报告流程

URG（Unified Report Generator）常用于汇总仿真覆盖和形式覆盖结果，把不同来源的数据统一成最终覆盖报告。它在 VC Formal 和 VCS 的覆盖收敛流程里很常见，尤其适合把 merged.vdb、vcst_rtdb、exclusion file 等结果统一处理。

## 1. URG 是做什么的

URG 的核心作用是把分散的覆盖数据合并、过滤、统计和展示，帮助你判断验证是否已经收敛。

- 合并多个测试运行产生的覆盖数据。
- 汇总仿真覆盖和形式覆盖。
- 根据排除文件过滤不需要统计的目标。
- 生成最终的覆盖报告，便于查看命中情况和遗漏项。

## 2. 图里的数据流

图中展示的是两条来源不同、但最终会汇到 URG 的流程。

### 2.1 VCS Coverage flow

VCS 侧的流程更偏仿真覆盖：

```text
VCS Compile
<coverage_options>
<compile_options> DUT + TB
    |
simv
<coverage_options>
<multiple_tests>
    |
Merged .vdb
```

这条路径的特点是：先编译 DUT 和 TB，再运行多个测试，最后把结果合并成 merged.vdb。

### 2.2 Formal Coverage Analyzer flow

形式覆盖侧的流程更偏形式化分析：

```text
TCL
read, clock/reset,
grid opts, res limits etc.
    |
vcf shell
    |
Exclusion file + vcst_rtdb
```

这条路径的特点是：先用 Tcl 读取设计和环境配置，再进入 vcf shell 运行分析，最后输出形式覆盖相关数据。

### 2.3 汇总到 URG

两边的数据最终都可以汇入 URG：

```text
Merged .vdb  ----->
                    URG  ----->  Coverage Reports
Exclusion file ---->
vcst_rtdb     ---->
```

URG 负责把这些数据统一成最终报告，方便你从一个地方看全局覆盖情况。

## 3. 常见输入

- merged.vdb：仿真覆盖合并后的数据库。
- vcst_rtdb：形式覆盖或相关验证产生的数据。
- exclusion file：排除项文件，用来过滤不需要统计的内容。
- 测试结果：多个仿真或形式验证运行的输出。

## 4. 常见输出

- Coverage reports：最终覆盖报告。
- 命中统计：哪些目标已覆盖，哪些未覆盖。
- 收敛视图：帮助判断验证是否已经接近完成。

## 5. 使用时的理解

- VCS 覆盖更偏“跑测试得到覆盖”。
- Formal 覆盖更偏“用约束和证明补全盲区”。
- URG 是把两边结果统一起来的汇总工具。
- 如果报告里还有很多未覆盖项，通常说明验证还没有完全收敛，或者约束和排除规则需要再检查。

## 6. 一句话总结

URG 的作用就是把仿真覆盖和形式覆盖的结果整合成最终报告，让你知道验证还差多少。