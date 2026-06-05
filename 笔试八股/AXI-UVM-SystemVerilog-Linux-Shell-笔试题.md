# AXI / UVM / SystemVerilog / Linux / Shell 笔试题

## 一、多选题

### 1. 下面属于 AXI 定义的传输通道的是

- A. AW 通道
- B. D 通道
- C. B 通道
- D. AR 通道

答案：A、C、D

解析：AXI 定义了 5 个独立通道：AW、W、B、AR、R。没有 D 通道。

### 2. 在 SystemVerilog 语言中，如果想要约束随机变量 x 在 a 和 b 之间，以下代码中正确的是

- A. `a <= x <= b;`
- B. `x <= b; x >= a;`
- C. `b >= x; a <= X;`
- D. `b >= X >= a`

答案：B

解析：SystemVerilog 不应使用数学式链式比较来表达范围约束，应拆成两个关系表达式：`x >= a; x <= b;`。注意 SystemVerilog 大小写敏感，`x` 和 `X` 不是同一个标识符。

### 3. UVM 的通信接口类型包括哪些

- A. port
- B. fifo
- C. export
- D. imp

答案：A、C、D

解析：UVM TLM 接口连接常见类型包括 `port`、`export`、`imp`。`fifo` 是通信组件/通道，不是接口端口类型。

### 4. 常见的代码覆盖率收集包括哪些

- A. 表达式覆盖（Condition Coverage）
- B. 分支覆盖（Branch Coverage）
- C. 状态机覆盖（FSM Coverage）
- D. 语句覆盖（Statement Coverage）

答案：A、B、C、D

解析：常见代码覆盖率包括语句、分支、条件/表达式、翻转、FSM 等。

### 5. 关于 Linux 和 Windows 操作系统的使用，以下说法正确的是

- A. Linux 和 Windows 下的工具安装包一般都是 exe 格式
- B. Linux 下的软件工具一般可以在 cmd/GUI 方式下运行
- C. Linux 下更容易进行分组权限控制
- D. Linux 下无法打开工具的 GUI 界面

答案：B、C

解析：`.exe` 主要是 Windows 可执行文件格式；Linux 工具可以命令行或 GUI 运行；Linux 的用户、组、权限模型便于权限控制；Linux 可以运行 GUI 程序。

### 6. 关于功能覆盖率，以下说法正确的是

- A. 功能覆盖率达到 100%，说明验证已经完备
- B. 功能覆盖率仅针对 transaction 内的变量才能收集
- C. 可以通过功能覆盖率检查激励是否正确覆盖模块某一功能
- D. 功能覆盖率的收集可以通过 DUT 内部特定信号控制

答案：C、D

解析：功能覆盖率 100% 不等于验证完备，只说明已定义覆盖点被命中。功能覆盖率可以覆盖 transaction 字段，也可以采样接口信号、DUT 内部信号或用特定信号控制采样。

### 7. 关于 shell 脚本的语法，下面说法正确的是

- A. shell 中可以调用类似 `sleep` 这样的操作系统命令
- B. shell 中可以使用 `if` 语句来实现条件判断
- C. shell 中可以定义函数
- D. shell 中支持 `for` 循环

答案：A、B、C、D

解析：shell 脚本支持命令调用、条件判断、函数定义和循环。

### 8. 以下关于定向测试说法错误的有

- A. 一般发生在验证早期阶段
- B. 能有效缩短验证时间，驱动覆盖率快速达到 100%
- C. 能有效避免用例之间的覆盖率重复
- D. 需要构造复杂的随机约束程序

答案：B、C、D

解析：定向测试常用于验证早期冒烟、基本功能和关键场景检查，但不适合依赖它快速达到完整覆盖率，也不能天然避免覆盖重复。复杂随机约束程序通常属于约束随机验证，不是定向测试的特点。

## 二、单选题

### 1. sequence 执行 start 程序时，会回调哪个函数

- A. print
- B. start
- C. body
- D. phase

答案：C

解析：UVM sequence 调用 `start()` 后，核心执行逻辑在 `body()` 任务中。

### 2. 处理器中，开发存储器层次结构是基于什么原理

- A. Amdahl 定律
- B. 数据级并行
- C. 存储一致性
- D. 局部性原理

答案：D

解析：Cache 和存储层次结构主要基于时间局部性和空间局部性。

### 3. 以下属于代码检查工具的是

- A. Modelsim
- B. Lint
- C. DesignCompiler
- D. VCS

答案：B

解析：Lint 用于静态代码检查；Modelsim 和 VCS 主要是仿真工具，Design Compiler 是综合工具。

### 4. 在 Python 语法中，以下代码的输出是

```python
x = list("the sky is blue")
y = x.index("s", 5, 10)
print(y)
```

- A. 5
- B. 10
- C. 4
- D. 9

答案：D

解析：`list.index(value, start, stop)` 搜索区间是 `[start, stop)`。字符串中 `s` 的位置有 4 和 9，从索引 5 到 10 搜索会找到索引 9。

### 5. 在 SystemVerilog 语言中，函数 `Foo` 定义如下，那么执行其他代码后，`x` 和 `y` 的取值是多少

```systemverilog
function int Foo(ref int x);
  return x++;
endfunction

x = 5;
y = Foo(x);
```

- A. x = 5, y = 5
- B. x = 5, y = 6
- C. x = 6, y = 5
- D. x = 6, y = 6

答案：C

解析：`x++` 是后自增，表达式返回自增前的值 5，然后 `x` 自增为 6。由于参数是 `ref`，函数内修改会作用到外部变量。

### 6. 如果芯片的一个输入管脚在应用时没有连线，保持悬空。此时该信号经过 PAD 中的 BUF 到达内部逻辑电路时，观察到的该信号的值是什么

- A. 1
- B. 0 或者 1
- C. 高阻态 `1'bz`
- D. 0

答案：B

解析：悬空输入经过输入缓冲后，内部逻辑通常会被解析为不确定的 0 或 1，而不是继续保持高阻态。

### 7. 以下哪个可以实现 UVM callback 机制

- A. `uvm_sequence`
- B. `uvm_sequence_item`
- C. `uvm_tlm`
- D. `uvm_driver`

答案：D

解析：UVM callback 常用于 driver、monitor 等组件中预留前后处理钩子，典型实现位置是 `uvm_driver`。

### 8. 假设输入信号 a、b、c 的位宽分别是 10 bit、5 bit、14 bit，输出 `result = a * b + c`，如果要实现不损失精度的输出，则输出需要定义为多少 bit

- A. 16
- B. 24
- C. 15
- D. 29

答案：A

解析：`a * b` 最大需要 `10 + 5 = 15` bit，15 bit 结果再加 14 bit 的 `c`，为避免进位损失，需要 `max(15, 14) + 1 = 16` bit。

### 9. 验证结束的衡量标准描述错误的是

- A. RTL 开发完成
- B. 多轮随机测试完成
- C. 覆盖率达到 100%
- D. 缺陷曲线收敛

答案：A

解析：RTL 开发完成是进入充分验证的前提之一，不是验证结束的衡量标准。验证结束通常综合考虑回归结果、覆盖率、缺陷收敛和风险评估。

### 10. 在 SystemVerilog 语言中，x 的 y 次方以下表达式正确的是

- A. `x ^ y`
- B. `x ^^ y`
- C. 其他选项均不正确
- D. `x % y`

答案：C

解析：SystemVerilog 中幂运算符是 `**`，即 `x ** y`。`^` 是按位异或，`%` 是取模。
