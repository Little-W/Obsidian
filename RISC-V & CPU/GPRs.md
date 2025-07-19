RISC-V 架构中共有 32 个通用寄存器（x0 \~ x31），每个寄存器有一个别名（ABI 名称），用于汇编编程的可读性。以下是完整的寄存器别名汇总表：

| 寄存器名 | 别名（ABI 名称） | 描述                             | 作用说明           |
| ---- | ---------- | ------------------------------ | -------------- |
| x0   | zero       | 常数 0                           | 永远为 0，写入无效     |
| x1   | ra         | return address                 | 函数返回地址         |
| x2   | sp         | stack pointer                  | 栈顶指针           |
| x3   | gp         | global pointer                 | 全局指针           |
| x4   | tp         | thread pointer                 | 线程局部存储指针       |
| x5   | t0         | temporary                      | 临时寄存器（调用者保存）   |
| x6   | t1         | temporary                      | 临时寄存器（调用者保存）   |
| x7   | t2         | temporary                      | 临时寄存器（调用者保存）   |
| x8   | s0 / fp    | saved register / frame pointer | 被保存寄存器/帧指针     |
| x9   | s1         | saved register                 | 被保存寄存器（被调用者保存） |
| x10  | a0         | argument / return value        | 函数参数或返回值 0     |
| x11  | a1         | argument / return value        | 函数参数或返回值 1     |
| x12  | a2         | argument                       | 函数参数           |
| x13  | a3         | argument                       | 函数参数           |
| x14  | a4         | argument                       | 函数参数           |
| x15  | a5         | argument                       | 函数参数           |
| x16  | a6         | argument                       | 函数参数           |
| x17  | a7         | argument                       | 函数参数           |
| x18  | s2         | saved register                 | 被保存寄存器（被调用者保存） |
| x19  | s3         | saved register                 | 被保存寄存器（被调用者保存） |
| x20  | s4         | saved register                 | 被保存寄存器（被调用者保存） |
| x21  | s5         | saved register                 | 被保存寄存器（被调用者保存） |
| x22  | s6         | saved register                 | 被保存寄存器（被调用者保存） |
| x23  | s7         | saved register                 | 被保存寄存器（被调用者保存） |
| x24  | s8         | saved register                 | 被保存寄存器（被调用者保存） |
| x25  | s9         | saved register                 | 被保存寄存器（被调用者保存） |
| x26  | s10        | saved register                 | 被保存寄存器（被调用者保存） |
| x27  | s11        | saved register                 | 被保存寄存器（被调用者保存） |
| x28  | t3         | temporary                      | 临时寄存器（调用者保存）   |
| x29  | t4         | temporary                      | 临时寄存器（调用者保存）   |
| x30  | t5         | temporary                      | 临时寄存器（调用者保存）   |
| x31  | t6         | temporary                      | 临时寄存器（调用者保存）   |

### 简要分类总结：

* **zero**：只读常数 0；
* **ra**：保存函数返回地址；
* **sp/gp/tp**：栈、全局、线程指针；
* **t0 \~ t6**：调用者保存的临时寄存器；
* **s0 \~ s11**：被调用者保存的寄存器；
* **a0 \~ a7**：函数参数与返回值寄存器。
