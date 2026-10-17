# FPV：功能属性验证应用完整指南

> **第 5 册 · 专用应用**　Functional Property Verification。依据 User Guide 第 17 章（第 686～713 页），并结合第 3～8、18～20 章及 Quick Reference Guide 的 FPV 部分。提供带设计、断言和 Tcl 的可复现教学工程，见 [案例工程](案例工程/README.md)。

## 1. 定位、能力与不适用范围

FPV 通过数学证明验证 RTL 和 SVA 所描述的设计规则。输入包括：待验证 RTL、用户断言、Assertion IP（AIP）断言、环境假设、时钟复位和初始化状态；输出为证明状态、反例、覆盖轨迹和分析报告。它适合局部协议、状态机、控制面、缓冲区、寄存器副作用、异常控制等，可在传统 testbench 完成前投入使用。

FPV 不会自动理解芯片规格，也不自动生成所有应该证明的规则。只有对**已经编写并启用**的属性进行了证明才有相应结论，且环境约束必须可信。若设计缺少软件配置顺序或外部协议模型，可能出现不实际的反例；若过度约束，则可能出现空洞证明。

## 2. 标准流程与输入输出

![FPV 工作流程](插图/06_FPV工作流程.svg)

| 阶段 | 任务 | 命令或文件 | 核查点 |
|---|---|---|---|
| 选择应用 | 设置 FPV | `set_fml_appmode FPV` | 模式是否正确 |
| 编译 | 读入 RTL、属性和 bind 文件 | `read_file` 或 `analyze/elaborate` | 顶层、参数、属性数量 |
| 初始化 | 时钟、复位、常量、初始状态 | `create_clock`、`create_reset`、`sim_save_reset` | 与真实启动一致 |
| 环境审查 | 检查黑盒和模型问题 | `report_blackbox`、`check_fv_setup` | 不存在关键环境缺陷 |
| 运行 | 执行验证 | `check_fv -block` | 任务真正结束 |
| 分析 | 输出证明状态和反例 | `report_fv`、`view_trace` | 性质与前提一致 |
| 回归 | 保存可复现结果 | `save_session`、日志/manifest | 版本与运行资源可追踪 |

## 3. 最小脚本：单时钟计数器

以下示例以 `案例工程/` 为根目录运行；复位序列需按你的 DUT 实际建立，脚本重点展示 FPV 的正确调用顺序。教学 RTL 参见 `案例工程/rtl/counter.sv`，属性参见 `案例工程/formal/counter_props.sv`。

```tcl
# 文件：案例工程/scripts/fpv_counter.tcl
set_fml_appmode FPV
read_file -top counter -sva -format sverilog -vcs {-f filelist_counter.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
check_fv_setup
report_fv -list
set_fml_var fml_max_time 1H
set_fml_var fml_max_memory 8GB
check_fv -block
report_fv -list
report_fv -verbose
```

这是面向具有明确复位模型的教学模板。工程中应先检查 `sim_save_reset` 所保存的状态是否符合真实上电要求；**不能仅仅因为脚本中有 `create_reset` 就认定初始状态已正确设置**。可使用 `sim_force`、`sim_run N -clk clk`、`view_trace -reset` 辅助构造、检查启动过程。文件路径按照脚本执行的工作目录解析。

## 4. 如何组织断言

建议把每条属性归入四个类别：初始化（复位值和复位后输出）；协议（有效应答、授权、稳定性）；内部安全性（计数范围、状态合法、资源互斥）；进展性（最大等待时间、错误响应）。每个类别不仅包含断言，还要有能触发关键规则的覆盖目标。可将大型属性拆成“输入合法 → 请求被接受 → 内部状态变化 → 输出响应”的小性质，降低定位和求解难度。

### 4.1 它真正验证了什么

```systemverilog
ap_range: assert property (@(posedge clk) disable iff(!rst_n)
  count <= 4'd9);

cp_wrap: cover property (@(posedge clk) disable iff(!rst_n)
  count == 4'd9 ##1 count == 4'd0);
```

`ap_range` 证明占用值不超过上界；`cp_wrap` 搜索一次从 9 到 0 的回绕。两者不能互相替代。若设计从未能到达 9，`ap_range` 仍可能通过，但回绕规则并未真正被验证。对错误 RTL，前者应给出反例，后者是否能够覆盖取决于更新条件。

### 4.2 使用 `bind` 与外部属性模块

推荐把待验证 RTL 与检查器分离，方便调试和提交代码：

```systemverilog
module interface_checker (
  input logic clk, rst_n,
  input logic valid, ready,
  input logic [7:0] data
);
  ap_stable: assert property (@(posedge clk) disable iff(!rst_n)
     valid && !ready |=> valid && $stable(data));
  cp_transfer: cover property (@(posedge clk) disable iff(!rst_n)
     valid && ready);
endmodule
```

在 `formal/bind.sv` 内写 `bind <DUT_type> interface_checker ...`，然后使绑定文件编译进入 `-sva` 的设计。必须确认属性端口与 DUT 的实际时序一致，不要仅凭属性能被编译就认为建模正确。

## 5. 常用 Tcl 命令逐项讲解

| 命令 | 作用 | 使用时机及注意事项 |
|---|---|---|
| `set_fml_appmode FPV` | 选择 FPV | 在编译前执行；可用 `get_fml_appmode` 核对 |
| `read_file -top ... -sva ...` | 编译并展开含断言设计 | 源文件列表和模块顶层必须正确 |
| `analyze ...; elaborate ... -sva` | 将编译与展开拆开 | 不与 `read_file` 任意重复 |
| `aip_load -protocol "AHB AXI5"` | 加载受支持的协议断言 IP | 需要协议适配及正确的 AIP 连接配置 |
| `create_clock` | 定义逻辑时钟 | 多域设计要分别核查 |
| `create_reset` | 定义复位极性 | 必须与实际 RTL 相符 |
| `set_constant` | 将稳定控制输入限制为给定值 | 确保该假设对目标应用合理 |
| `sim_run` / `sim_save_reset` | 建立并保存初始状态 | 应审查复位波形和寄存器值 |
| `check_fv_setup` | 检查形式模型和环境 | 在长时间证明前运行 |
| `fvassert` | 在 Tcl 创建或设定断言属性 | 复杂时序属性推荐 SVA 源文件 |
| `fvassume` | 添加或调整形式假设 | 必须给出规格来源 |
| `fvcover` | 添加覆盖目标 | 应覆盖关键协议触发条件 |
| `fvdisable` / `fvenable` | 关闭 / 启用属性 | 禁用不能隐瞒，需报告 |
| `set_fml_var fml_vacuity_on true` | 配置空洞性分析 | 仍需结合触发覆盖审查 |
| `check_fv -block` | 阻塞执行求解 | 适合批处理脚本 |
| `report_fv -list/-verbose` | 列表和详细报告 | 根据状态区分已证明、失败和未完成 |
| `view_trace -property ...` | 打开特定属性反例 | 对照 SVA 触发周期观察 |
| `save_session -session ...` | 保存工具工作会话 | 保留关联数据库以便恢复 |

`fvassert <name> -expr {<expression>}`、`fvassume <name> -expr {...}` 和 `fvcover <name> -expr {...}` 适合短属性或自动生成规则。Tcl 的 `{}`、`""` 会影响转义与 `$` 替换，例如使用 `$past` 时推荐外层花括号包围语句或直接写到 SV 中。

## 6. 四个逐步进阶的用例

### 用例 A：复位后状态正确

规格：复位退出后，状态机应进入空闲状态。首先明确同步或异步复位和断言采样时刻：

```systemverilog
ap_reset_release: assert property (
  @(posedge clk) $rose(rst_n) |-> state == IDLE);
```

这段规则只适用于状态在第一次采样到复位高电平的时刻应该已经是 `IDLE` 的实现。若模块采用同步释放后的一个周期才进入有效状态，则必须调整响应周期。为复位前提单独建立初始化流程，不能只靠 `disable iff` 回避复位检查。

### 用例 B：握手停止期间数据不变

```systemverilog
ap_stall_hold: assert property (@(posedge clk) disable iff(!rst_n)
  valid && !ready |=> valid && $stable(data));
cp_backpressure: cover property (@(posedge clk) disable iff(!rst_n)
  valid && !ready ##1 ready);
```

如 `ready` 为外部驱动，禁止假设 `ready` 始终为 1；否则背压规则可能很容易被证明，却没有真正触发的测试场景。

### 用例 C：深层计数器溢出

使用参数化深度为 10 的计数器，故意把最大值条件写错。预期安全性 `count <= 9` 会失败；反例提供每拍 `enable`，可从逐周期变化找到第一次非法值。修复后重新运行，与更早的报告比较应以 RTL 的校验值为前提。

### 用例 D：多端口仲裁

```systemverilog
ap_mutex: assert property (@(posedge clk) disable iff(!rst_n)
  $onehot0(grant));
cp_contend: cover property (@(posedge clk) disable iff(!rst_n)
  req == 2'b11);
```

这是最基础的安全性和触发覆盖。若想证明“等待不超过 8 拍”，必须明确持续请求和仲裁器能否接收新请求，并对每一个端口分别写属性。状态空间复杂时，可先证明互斥与请求合法，再证明有界公平性。

## 7. 如何分析结果

`Proven`：属性在该模型和假设下成立。需要查触发是否可达与约束是否合理。`Falsified`：工具给出违反路径，首先检查输入是否符合环境规格与时钟复位是否正确。`Inconclusive`：目前未完成，不能当作通过。`Covered`：存在一条满足覆盖目标的路径。`Uncoverable`：该目标在当前模型不可达，需要区分真实死逻辑与过度约束。详见 [验证工程与结果判读](验证工程与结果判读.md)。

## 8. 优化证明效率而不损害结论

1. 缩小模块验证范围，必要时划分不同 `fvtask`；不要先大面积假设内部值。
2. 将复杂的一条断言拆成可解释的若干不变量与阶段性结果。
3. 分析影响锥，确认算术、RAM、时钟域和不必要的外围逻辑是否进入证明。
4. 再考虑 `set_fml_var fml_effort high`、资源限制、`set_abstractions`、`snip_driver` 等进阶优化；新抽象可能引入虚假反例。
5. 对长期回归使用符合条件的 `fvlearn_config -local_dir ...`，并区分继承的缓存与新运行获得的真实结果。
6. 使用 `report_fml_engines`、`report_fml_jobs`、`report_fml_hosts` 定位瓶颈。

## 9. 常见故障与排查

| 现象 | 优先检查 | 不应做的事 |
|---|---|---|
| 所有断言都轻松通过 | 触发覆盖、空洞性和假设 | 直接宣布完整验证通过 |
| 许多断言在第 0 拍失败 | 初始化状态与 `$past` | 假设所有寄存器为预期值 |
| 证明几乎没有进展 | 影响锥、参数和 RAM | 无审查地增加内部假设 |
| 只有有界深度结论 | 是否真正 `Proven` | 把展开深度当作无限证明 |
| Verdi 中找不到信号 | 优化、层级、会话版本 | 在不知影响的情况下关掉全部优化 |
| 频繁得到非法请求反例 | 环境模型与协议规范 | 把所有 DUT 失败行为都排除 |

## 10. 进阶主题

FPV 可以与 AIP、覆盖质量评估（FCA）、FTA 的形式测试平台突变分析、Proof Architect 的组合式证明方法等配合。有关无法快速证明的属性，阅读 [调试与证明性能](调试与证明性能.md)；有关交付报告，阅读 [覆盖与验证验收](覆盖与验证验收.md)。FPV 的物理规模限制随属性影响锥、状态空间及引擎而变化，没有一个对所有设计都有效的固定门数门槛。

## 11. 参考定位

User Guide §17（FPV，686 页起），§3（SVA/属性，66 页起），§4（初始化，115 页起），§6～7（运行与调试，183～312 页），§18～20（性能、组合式证明与验收）。Quick Reference Guide 的 FPV 页面提供命令速览，但不是全部参数说明。
