# axi_tvip_test 使用说明

本文档说明 `/home/yusen/opt/axi_tvip_test` 这版 AXI 验证环境的用法。该环境使用 `/library/tvip-axi` 的 TVIP AXI VIP，验证对象是一个简易 AXI slave DUT。

## 1. 环境位置

工程目录：

```bash
/home/yusen/opt/axi_tvip_test
```

主要目录：

```text
hdl/                  DUT RTL
tb/                   top、DUT wrapper、TVIP interface 连接
seq_lib/              UVM test 和 sequence
vcs_com/              BMS 编译配置和 filelist
test_lib/             BMS case 目录
vendor/tvip-axi/      TVIP AXI 及依赖
doc/                  使用文档
```

注意：容器内不能直接访问 `/library`，所以本工程把 `/library/tvip-axi` 复制到了 `vendor/tvip-axi`。编译和仿真实际使用的是：

```bash
/home/yusen/opt/axi_tvip_test/vendor/tvip-axi
```

## 2. 快速运行

进入工程目录：

```bash
cd /home/yusen/opt/axi_tvip_test
```

编译并运行 smoke case：

```bash
bms /home/yusen/opt/axi_tvip_test/test_lib/axi/smoke/smoke --lxc-run -c -s 1
```

只重新运行仿真，不重新编译：

```bash
bms /home/yusen/opt/axi_tvip_test/test_lib/axi/smoke/smoke --lxc-run -s 1
```

指定运行目录名：

```bash
bms /home/yusen/opt/axi_tvip_test/test_lib/axi/smoke/smoke --lxc-run -w smoke_tvip -c -s 1
```

运行完成后的默认目录：

```bash
/home/yusen/opt/axi_tvip_test/test_lib/debug/smoke
```

主要日志：

```text
smoke.log      仿真日志
vlogan.log     编译日志
vcs_elb.log    elaboration 日志
```

## 3. 当前已验证结果

当前 smoke case 做了两组 AXI write/read：

```text
addr=0x00 data=0x12345678
addr=0x04 data=0xcafe5eed
```

通过标志：

```text
TvipAxiTestEpilog: Passed
UVM_ERROR : 0
UVM_FATAL : 0
```

可以用下面命令快速确认：

```bash
rg -n "TvipAxiTestEpilog|write/read passed|UVM_ERROR|UVM_FATAL" \
  /home/yusen/opt/axi_tvip_test/test_lib/debug/smoke/smoke.log
```

## 4. BMS case 配置

顶层 case 列表：

```bash
/home/yusen/opt/axi_tvip_test/test_lib/cfg
```

当前内容：

```text
axi
```

AXI case 列表：

```bash
/home/yusen/opt/axi_tvip_test/test_lib/axi/cfg
```

当前内容：

```text
smoke
cov_metrics = line+toggle
```

单个 case：

```bash
/home/yusen/opt/axi_tvip_test/test_lib/axi/smoke/smoke.tc
```

当前指定的 UVM test：

```text
+UVM_TESTNAME=axi_tvip_smoke_test
```

## 5. 编译配置

编译配置入口：

```bash
/home/yusen/opt/axi_tvip_test/vcs_com/vcs_com
```

RTL filelist：

```bash
/home/yusen/opt/axi_tvip_test/vcs_com/rtl.f
```

Testbench filelist：

```bash
/home/yusen/opt/axi_tvip_test/vcs_com/verif.f
```

`verif.f` 中的关键编译顺序：

```text
uvm_pkg.sv
tue_pkg.sv
tvip_common_pkg.sv
tvip_axi_pkg.sv
tvip_axi_if.sv
axi_tvip_myip_wrapper.sv
axi_tvip_tb.sv
```

TVIP AXI 依赖的 include 路径：

```text
vendor/tvip-axi/tue/src
vendor/tvip-axi/tvip-common/src
vendor/tvip-axi/src
```

## 6. TVIP 接入结构

当前 testbench top：

```bash
/home/yusen/opt/axi_tvip_test/tb/axi_tvip_tb.sv
```

主要动作：

1. 实例化 `tvip_axi_if axi_if(clk, reset_n)`。
2. 实例化 `axi_tvip_myip_wrapper dut_wrapper(axi_if)`。
3. 通过 `uvm_config_db#(tvip_axi_vif)` 把 interface 传给 UVM test。
4. 调用 `run_test()`。

DUT wrapper：

```bash
/home/yusen/opt/axi_tvip_test/tb/axi_tvip_myip_wrapper.sv
```

wrapper 负责把 TVIP AXI interface 信号连接到 DUT AXI slave 端口。DUT 输出信号先接到本地 wire/logic，再用 `always @(*)` 回写到 `axi_if`，这样可以避免 interface 和 DUT 输出之间形成不合法的多驱动。

## 7. TVIP AXI 配置

当前配置在：

```bash
/home/yusen/opt/axi_tvip_test/seq_lib/axi_tvip_smoke_test.sv
```

核心配置：

```systemverilog
protocol == TVIP_AXI4;
id_width == 1;
address_width == 6;
data_width == 32;
max_burst_length == 1;
response_ordering == TVIP_AXI_IN_ORDER;
outstanding_responses == 0;
enable_response_interleaving == 0;
reset_by_agent == 0;
```

这些参数需要和 DUT 端口保持一致。当前 DUT 是 32-bit data、6-bit address、1-bit id 的简易 AXI slave。

## 8. 写一个新 case

建议按下面步骤添加新 case。

1. 新建 sequence，例如：

```bash
/home/yusen/opt/axi_tvip_test/seq_lib/axi_tvip_xxx_sequence.sv
```

sequence 可以继承：

```systemverilog
class axi_tvip_xxx_sequence extends tvip_axi_master_sequence_base;
```

2. 新建 test，例如：

```bash
/home/yusen/opt/axi_tvip_test/seq_lib/axi_tvip_xxx_test.sv
```

test 可以参考 `axi_tvip_smoke_test`，替换 default sequence。

3. 在 top 中 include 新文件：

```systemverilog
`include "axi_tvip_xxx_sequence.sv"
`include "axi_tvip_xxx_test.sv"
```

4. 新建 case 目录：

```bash
mkdir -p /home/yusen/opt/axi_tvip_test/test_lib/axi/xxx
```

5. 新建 tc 文件：

```bash
/home/yusen/opt/axi_tvip_test/test_lib/axi/xxx/xxx.tc
```

内容示例：

```text
+UVM_TESTNAME=axi_tvip_xxx_test
```

6. 把 case 名加入：

```bash
/home/yusen/opt/axi_tvip_test/test_lib/axi/cfg
```

示例：

```text
smoke
xxx
cov_metrics = line+toggle
```

7. 运行新 case：

```bash
bms /home/yusen/opt/axi_tvip_test/test_lib/axi/xxx/xxx --lxc-run -c -s 1
```

## 9. AXI write/read sequence 写法

当前 smoke sequence：

```bash
/home/yusen/opt/axi_tvip_test/seq_lib/axi_tvip_smoke_sequence.sv
```

写事务使用：

```systemverilog
`tue_do_with(write_sequence, {
  id           == 0;
  address      == local::address;
  burst_length == 1;
  burst_size   == 4;
  burst_type   == TVIP_AXI_INCREMENTING_BURST;
  memory_type  == TVIP_AXI_DEVICE_NON_BUFFERABLE;
  protection   == '0;
  qos          == '0;
  data.size()  == 1;
  data[0]      == local::expected_data;
  strobe.size() == 1;
  strobe[0]    == 4'hf;
})
```

读事务使用：

```systemverilog
`tue_do_with(read_sequence, {
  id           == 0;
  address      == local::address;
  burst_length == 1;
  burst_size   == 4;
  burst_type   == TVIP_AXI_INCREMENTING_BURST;
  memory_type  == TVIP_AXI_DEVICE_NON_BUFFERABLE;
  protection   == '0;
  qos          == '0;
})
```

当前 DUT 只适合单 beat 访问，所以 `burst_length` 固定为 1。后续如果要测 burst，需要先确认 DUT 对 burst 的实际支持情况。

## 10. 覆盖率

当前 AXI 配置中的覆盖率对象：

```text
cov_metrics = line+toggle
```

单 case 覆盖率运行：

```bash
bms /home/yusen/opt/axi_tvip_test/test_lib/axi/smoke/smoke --lxc-run -c -s 1 -cov
```

回归覆盖率运行：

```bash
bms -regr /home/yusen/opt/axi_tvip_test/test_lib/axi \
  --lxc-run -c -s 1 -cov
```

如果指定回归目录名：

```bash
bms -regr /home/yusen/opt/axi_tvip_test/test_lib/axi \
  --lxc-run -w axi_tvip_cov -c -s 1 -cov
```

## 11. 波形

普通运行后，进入 case 运行目录：

```bash
cd /home/yusen/opt/axi_tvip_test/test_lib/debug/smoke
```

如果生成了 `run_verdi`，可直接运行：

```bash
./run_verdi
```

也可以手动打开：

```bash
verdi -ssf inter.fsdb &
```

波形脚本位置：

```bash
/home/yusen/opt/axi_tvip_test/common/script/wave.tcl
```

## 12. 常见问题

### 12.1 容器找不到 /library/tvip-axi

这是预期行为。当前容器不能直接访问 `/library`，所以本工程使用 `vendor/tvip-axi` 中的副本。

### 12.2 编译输出 Can't locate Env.pm

这是 VCS `ctstats_report.pl` 的 Perl 环境 warning，目前不影响编译、elaboration 和仿真结果。判断仿真是否通过，以 `smoke.log` 中的 UVM summary 和 `TvipAxiTestEpilog: Passed` 为准。

### 12.3 修改 DUT 位宽后编译或仿真异常

需要同步修改三处：

1. DUT parameter 和 wrapper 端口连接。
2. `axi_tvip_smoke_test.sv` 中的 `id_width/address_width/data_width`。
3. sequence 中访问地址、数据宽度和 strobe 宽度。

### 12.4 出现 interface 多驱动

不要把 DUT output 直接连到 interface 变量后再由其他地方驱动。当前 wrapper 的做法是 DUT output 先接本地 logic，再在 `always @(*)` 中赋值给 `axi_if`。

## 13. 当前推荐命令汇总

单 case 编译运行：

```bash
cd /home/yusen/opt/axi_tvip_test
bms /home/yusen/opt/axi_tvip_test/test_lib/axi/smoke/smoke --lxc-run -c -s 1
```

单 case 快速重跑：

```bash
cd /home/yusen/opt/axi_tvip_test
bms /home/yusen/opt/axi_tvip_test/test_lib/axi/smoke/smoke --lxc-run -s 1
```

单 case 带覆盖率：

```bash
cd /home/yusen/opt/axi_tvip_test
bms /home/yusen/opt/axi_tvip_test/test_lib/axi/smoke/smoke --lxc-run -c -s 1 -cov
```

回归：

```bash
cd /home/yusen/opt/axi_tvip_test
bms -regr /home/yusen/opt/axi_tvip_test/test_lib/axi --lxc-run -c -s 1
```

清理：

```bash
cd /home/yusen/opt/axi_tvip_test
bms clean
```
