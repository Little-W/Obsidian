# fe 系统 bms / fe_bms 使用说明

来源：

- 原始说明：`C:\Users\yusen\Downloads\fe_system.html`
- 当前脚本：`C:\Users\yusen\Documents\Obsidian Vault\i2c_tb\fe_bms.py`

## 一句话概览

`fe_bms.py` 是前端仿真与回归编排脚本，用于按 `test_lib` 用例解析 `vcs_com` 与多层 `cfg`，组织 `vlogan` / `vcs` 编译、`simv` 运行，并支持 LSF 单例提交、EMAN 回归、覆盖率、波形、可复用编译库和错误规则判定。

## 运行模式

| 模式 | 命令形态 | 说明 |
| --- | --- | --- |
| 单例仿真，默认 LSF | `bms <case>` | 非 `-eman` 且不加 `-local` 时，脚本会把本地命令包装后提交 LSF |
| 单例本地运行 | `bms <case> -local` | 不提交 LSF，直接在当前机器编译和运行 |
| EMAN 回归 | `bms -eman <case_or_dir> ...` | 生成 `.emc`，由 EMAN build/test 调度编译和仿真 |
| 直跑已有 EMC | `bms --emc xxx.emc` 或 `bms -eman xxx.emc` | 不经过 bms 编译流程，直接执行已有 `.emc` |
| 清理当前目录 | `bms clean` | 删除当前目录下波形、日志、`simv*`、`csrc`、DTL 目录等临时文件 |

> 说明：这里写 `bms` 是实际部署时常用入口名；仓库中文件名为 `fe_bms.py`。

## 用例与工程路径

用例路径必须位于包含 `test_lib` 的目录树下，并且命令中传入不带 `.tc` 后缀的路径。

示例：

```bash
bms .../test_lib/.../my_case
```

脚本要求同目录下存在同名 `.tc`：

```text
.../test_lib/.../my_case/my_case.tc
```

路径推导规则：

- `test_lib` 的上一级为工程根目录 `<proj>`。
- 编译控制目录优先使用 `<proj>/vcs_com`。
- 若 `<proj>/vcs_com` 不存在，兼容使用 `<proj>/Makefile` 目录。
- `vcs_com` 文件必须位于上述编译控制目录内。
- 当前脚本不支持直接传入 `.tc` 文件。

## `vcs_com` 文件

`vcs_com` 用于提供基础编译与 elaboration 参数，支持英文方括号和中文标题形式。

必须存在以下三段，且内容不能为空：

| 分段 | 用途 |
| --- | --- |
| `[VLOGAN]` / `【VLOGAN】` | 提供 `vlogan` 基础参数 |
| `[VCS_RTL_ELAB]` / `【VCS_RTL_ELAB】` | 提供 RTL/base elaboration 参数 |
| `[VCS_TEST_ELAB]` / `【VCS_TEST_ELAB】` | 提供 testbench/final elaboration 参数 |

脚本会按段收集非空行，去掉行尾反斜杠后拼接为命令参数。

## `cfg` 叠加规则

脚本会读取：

- `test_lib/cfg`
- 当前 case 路径中离 `.tc` 最近的最多两层目录下的 `cfg`
- 用例自身 `.tc`

这些内容按顺序累积，再解析加选项、减选项和 filelist 设置。注意：不是从 `test_lib` 到 case 的所有目录层级都会读取，当前实现只取全局 `cfg` 加最近两层目录 `cfg`。

### 加选项

`+...+` 用于追加参数。追加内容会按 shell 规则拆分为 token。

| 指令 | 累积到 |
| --- | --- |
| `+COMP+ ...` | 共用编译 / `vlogan` 参数 |
| `+VIP+ ...` | VIP 编译参数 |
| `+COV_COMP+ ...` | 覆盖率编译侧参数，开启 `-cov` 后加到 elaboration 阶段 |
| `+COV_SIM+ ...` | 覆盖率仿真侧参数，开启 `-cov` 后加到 sim 参数 |
| `+RTL_ELAB+ ...` | RTL elaboration 追加参数 |
| `+TEST_ELAB+ ...` | test elaboration 追加参数 |
| `+SIM+ ...` | 仿真 argv |
| `+RTL_FILE+ ...` | 指定 RTL filelist |
| `+VERIF_FILE+ ...` | 指定验证 filelist |
| `rtl_file=...` | 指定 RTL filelist |
| `verif_file=...` | 指定验证 filelist |

`+SIM+` 还支持：

```text
+SIM+ +PRE_SIM=<cmd>
+SIM+ +POST_SIM=<cmd>
```

当前实现中，多个 `PRE_SIM` 会用 `&&` 串接；多个 `POST_SIM` 只保留最后一个。

### 减选项

`-...-` 用于从已经累积的同类参数中按 token 删除。删除时必须与此前加入的 token 完全一致。

| 减选项 | 从哪类参数删除 |
| --- | --- |
| `-COMP- ...` | `comp` |
| `-VIP- ...` | `vip` |
| `-COV_COMP- ...` | `cov_comp` |
| `-COV_SIM- ...` | `cov_sim` |
| `-RTL_ELAB- ...` | `rtl_elab` |
| `-TEST_ELAB- ...` | `test_elab` |
| `-SIM- ...` | `sim`，不含 `PRE_SIM` / `POST_SIM` |

正式写法是大写关键字并在两侧带减号，例如 `-COMP-`。

## 命令行参数

| 参数 | 说明 |
| --- | --- |
| `tc` | 用例路径；非 EMAN 只支持一个，EMAN 支持多个或目录 |
| `--rtl-file <file>` | 指定 RTL filelist，可为绝对路径或相对 `vcs_com` 的路径 |
| `-rtl` | 强制重编 RTL/VIP；EMAN build 和 `--compile-only` 也保持该语义 |
| `-f` / `-fast` | 快速模式，非 EMAN 下复用已编译 RTL/VIP |
| `-c` | 非 EMAN 下先清理目标运行目录再跑 |
| `-genlib <name>` | 生成可复用编译库，目录位于 `test_lib/debug/<name>` |
| `-lib <name>` | 复用已有编译库，目录位于 `test_lib/debug/<name>` |
| `-d` / `-dump` | 开启波形，使用 `wave.tcl` |
| `-cov` | 覆盖率模式；EMAN 下会参与 merge，单跑时为单 case 覆盖率仿真 |
| `-R` / `--run-suffix <suffix>` | 运行目录后缀 |
| `-q` / `--queue <queue>` | LSF 队列，默认 `normal` |
| `--ncore <N>` | LSF 申请核数，默认由 `BMS_NCORE` 或 `1` 决定 |
| `-m` / `--mem <GB>` | LSF 申请内存，单位 GB |
| `-local` | 本地运行，不提交 LSF |
| `-eman` | 生成并提交 EMAN 回归 |
| `-debug` | 仅与 `-eman` 同用，在生成的 `.emc` 中写 debug rerun 字段 |
| `-num <N[,N...]>` | EMAN 每个 test 的 count；单值对所有 case 生效，逗号值与 case 顺序对齐 |
| `-j <N>` | EMAN build/test nodes，默认 50 |
| `-s` / `--seed <seed>` | 单例仿真随机种子 |
| `--emc` / `-emc <file>` | 直接执行已有 `.emc` |
| `--eman-make-dir <dir>` | 与 `--emc` 连用，指定 `vcs_com` 目录，便于拼 EMAN 参数 |

隐藏/内部参数：

- `--compile-only`：EMAN build 节点内部使用，只编译不仿真。
- `--eman-workdir`：EMAN build 节点内部使用，指定已展开的工作目录。

## 单例仿真流程

基本命令：

```bash
bms <case> [-local] [options]
```

非 EMAN 默认行为：

- 不加 `-local` 时，将命令包装成 `python3 fe_bms.py ... -local` 并通过 `bsub -Is` 提交。
- 默认强制重编；只有 `-f` / `-fast` 才复用已编译产物。
- `-f` 与 `-rtl` 在非 EMAN 下互斥。
- `-c` 会清理目标运行目录或指定编译库目录。

传统编译顺序：

1. 预编译 UVM：若存在 `UVM_HOME`，或可从 `VCS_HOME/etc/uvm-1.2` 推导。
2. 编译 VIP：默认读取 `vip.f`，可通过 `BMS_VIP_F` 覆盖。
3. 编译 RTL：默认读取 `rtl.f`，可由 `--rtl-file` 或 `cfg` 中 `RTL_FILE` 覆盖。
4. 编译 testbench：默认读取 `verif.f`，可由 `cfg` 中 `VERIF_FILE` 覆盖。
5. 运行 `simv`，写 `<tc_name>.log`。

运行目录：

- 普通单例：`test_lib/debug/<case_path>/<tc_name>[_suffix]`
- `-genlib/-lib`：`test_lib/debug/<lib_name>`
- 若 `test_lib/debug` 不存在，脚本会尝试创建到 `/tmpdata/zc_data/<user>/debug/it` 的软链接。

## 波形

加 `-d` / `-dump` 后，仿真命令会追加：

```bash
-ucli -do <wave.tcl>
```

`wave.tcl` 查找优先级：

1. `test_lib/<case...>/wave.tcl`，从 case 目录向上回溯。
2. `<proj>/common/script/wave.tcl`。

如果开启波形但找不到 `wave.tcl`，脚本会报错退出。

## 覆盖率

加 `-cov` 后：

- `+COV_COMP+` 内容加到 RTL/test elaboration 参数。
- `+COV_SIM+` 内容加到仿真参数。
- EMAN 下会额外为每个 test 设置覆盖率目录：

```text
<run_dir>/$$EMAN_TESTCASE/coverage
```

- EMAN 命令默认会带 merge 相关参数，merge 目录可通过 `BMS_EMAN_MERGE_DIR` 覆盖。

## 可复用编译库

`-genlib <name>`：

- 在 `test_lib/debug/<name>` 下生成或刷新编译库。
- 若同名目录存在，非 EMAN 单例中会在该目录内重编并刷新 manifest。

`-lib <name>`：

- 复用 `test_lib/debug/<name>`。
- 快速复用时会检查 `.bms_lib_manifest.json`。
- manifest 会记录 `vcs_com`、filelist、VIP、RTL/test elaboration、`BMS_VLOGAN_EXTRA`、`BMS_VCS_EXTRA` 等上下文。
- 若签名不一致或缺少 `simv`，脚本会报错，提示改用 `-genlib` 重新生成。

限制：

- 多 case EMAN 禁止使用 `-lib` / `-genlib`，因为每个 case 必须独立编译。

## EMAN 回归

基本命令：

```bash
bms -eman <case_or_dir> [-num 10] [-j 50] [-cov] [-d] [-debug]
```

输入规则：

- 可以传一个或多个 case。
- 可以传目录。
- 若目录本身符合 `<dir>/<leaf>.tc`，视为单 case。
- 否则递归收集目录下所有 `.tc`，并映射成不带 `.tc` 的 case 路径。

`-num`：

- 单值：所有 case 共用该 count。
- 多值：用逗号分隔，必须与展开后的 case 数量一致。
- 目录递归模式下只支持单个 `-num` 值。

生成 `.emc`：

- 输出目录：

```text
<debug_base>/eman/eman_regression/emc_dir
```

- 单 case 文件名：

```text
<tc_name>_YYYYMMDD_HHMMSS.emc
```

- 多 case 文件名：

```text
bms_eman_<N>cases_YYYYMMDD_HHMMSS.emc
```

模板查找顺序：

1. `BMS_EMAN_TEMPLATE`
2. `<proj>/regr/eman_template.emc`
3. `<proj>/vcs_com/eman_template.emc`
4. 与 `fe_bms.py` 同目录下的 `eman_template.emc`

模板必须包含独立占位行：

```text
__BMS_EMC_BUILDS__
__BMS_EMC_TESTS__
```

可选占位行：

```text
__BMS_EMC_TOP__
```

该占位行会展开为 EMAN Web 手动 rerun 可用的 `env`、`variables`、`modes`，包括 `fsdb` 和 `cov` 模式。

EMAN build/test 逻辑：

- 本机不编译，`.emc` 的 build `run_cmd` 会调用：

```bash
python3 fe_bms.py <case> --compile-only --eman-workdir <run_dir_expr>
```

- test `run_cmd` 会调用 build 目录下的 `simv`。
- `PRE_SIM` 会并入每个 EMAN test 的 `run_cmd` 前缀。
- 当前 `POST_SIM` 不会并入每个 EMAN test，而是在提交 EMAN 后由提交机执行一次。

Session 与运行目录：

- `-session_name` 由脚本生成。
- 单 case 形如：

```text
build_<tc_name>_session_<user>_<timestamp>
```

- 多 case 形如：

```text
<N>builds_session_<user>_<timestamp>
```

- `-top_run_dir` 形如：

```text
<debug_base>/eman/eman_regression/eman_rundir/eman_rundir_YYYYMMDD_HHMMSS
```

- 默认 build/test 工作目录表达式为：

```text
<debug_base>/eman/eman_regression/$$EMAN_SESSION_NAME/<tc_name>
```

- 可用 `BMS_EMAN_RUNDIR_EXPR` 覆盖为自定义表达式。

`-debug`：

- 只影响生成的 `.emc`。
- 会写入 `options.debug_rerun_count`、每个 test 的 `debug_run_cmd`、`debug_run_dir`。
- `debug_run_cmd` 等同开启 dump。
- 不会自动向 `eman` 命令行加 `-debug`；若需要，设置 `BMS_EMAN_REGR_DEBUG=1` 或 `BMS_EMAN_REGR_DEBUG_FLAGS`。

## 直跑已有 `.emc`

命令：

```bash
bms --emc /path/to/run.emc [-cov]
```

或：

```bash
bms -eman /path/to/run.emc
```

行为：

- 不经过 bms 编译流程。
- 不由 bms 生成 `-session_name` 或 `-top_run_dir`。
- 执行时工作目录会切到 `.emc` 所在目录。
- 仍会由脚本拼接 EMAN 命令参数，例如 `-project`、`-config`、`-error_pattern_file`、`-rules_file`、`-merge_dir` 等。
- 可用 `--eman-make-dir` 或 `BMS_EMAN_MAKE_DIR` 指定 `vcs_com` 目录，帮助推导 error pattern 与默认 config。

## 错误判定与日志

脚本会记录：

- 仿真日志：`<tc_name>.log`
- 编译日志：从命令中的 `-l <log>` 自动抓取
- 当前运行目录

非 EMAN 本地仿真后会打印 PASS/FAIL banner。

错误规则文件查找：

- 本地模式优先 `BMS_LOCAL_ERROR_PATTERN`
- EMAN 模式优先 `BMS_EMAN_ERROR_PATTERN`
- case 目录向上回溯查找 `vcs_error_patterns.eme` / `.emc`
- `<proj>/regr/vcs_error_patterns.eme` / `.emc`

规则格式类似：

```text
<regex>:::<status>:::<tag>:::<priority>
```

其中 `status` 为 `fail`、`error`、`fatal` 等时判失败；`pass`、`warn`、`info` 不判失败。

日志保护：

- 默认监控仿真日志大小。
- 超过 10 GB 时停止仿真。

## 环境变量

### 通用

| 环境变量 | 说明 |
| --- | --- |
| `BMS_NCORE` | 默认 LSF 核数 |
| `UVM_HOME` | UVM 目录 |
| `VCS_HOME` | 用于推导 bundled UVM，并拼接 VCS library path |
| `BMS_VLOGAN_EXTRA` | 追加到所有 `vlogan` 命令 |
| `BMS_VCS_EXTRA` | 追加到所有 `vcs` 命令 |
| `BMS_NO_COLOR` | 关闭 ANSI 彩色输出 |

### VIP / DTL

| 环境变量 | 说明 |
| --- | --- |
| `BMS_VIP_F` | VIP filelist 名称，默认 `vip.f` |
| `BMS_FORCE_VIP` | 强制 VIP 缓存失效 |
| `BMS_VIP_COMBINED_VLOGAN` | VIP 与 verif 合并编译 |
| `BMS_USE_DTL` | DTL 开关变量，脚本中定义为默认 `1`，但当前主流程未真正接入 |
| `BMS_DTL_BASE_PKG` | DTL base package，默认 `base_test_pkg` |
| `BMS_DTL_BASE_DIR` | DTL base 目录，默认 `BASE_IP` |
| `BMS_DTL_TEST_PKG_FMT` | DTL test package 格式，默认 `npu_core_test_pkg` |
| `BMS_DTL_TEST_DIR_FMT` | DTL test 目录格式，默认 `TEST_PKG` |
| `BMS_DTL_REUSE_BASE` | DTL base 复用控制 |
| `BMS_DTL_REUSE_TEST_PKG` | DTL test package 复用控制 |

### EMAN

| 环境变量 | 说明 |
| --- | --- |
| `BMS_EMAN_TEMPLATE` | 指定 `.emc` 模板 |
| `BMS_EMAN_DEBUG_DIR` | 指定 debug 根目录，可使用 `{user}` 或 `%u` |
| `BMS_EMAN_RUNDIR_EXPR` | 覆盖 EMAN build/test 工作目录表达式 |
| `BMS_EMAN_PROJECT` / `EMAN_PROJECT` | 指定 EMAN project；默认当前登录用户 |
| `BMS_EMAN_CONFIG` | 指定 EMAN config；默认 `test_lib` 父目录名 |
| `BMS_EMAN_ERROR_PATTERN` | 指定 EMAN error pattern 文件 |
| `BMS_EMAN_RULES_FILE` | 指定 EMAN rules file |
| `BMS_EMAN_AUTO_CLEANUP` | 控制是否加 `-auto_cleanup`，默认开启 |
| `BMS_EMAN_NO_AUTO_CLEANUP` | 设为真时不加 `-auto_cleanup` |
| `BMS_EMAN_OVERWRITE` | 设为真时加 `-overwrite` |
| `BMS_EMAN_BUILD_TIMEOUT` | EMAN build timeout，默认 86400 |
| `BMS_EMAN_DEBUG_RERUN_COUNT` | `-eman -debug` 时写入的 debug rerun 次数，默认 2 |
| `BMS_EMAN_REGR_DEBUG` | 设为真时向 EMAN 命令行加 `-debug` |
| `BMS_EMAN_REGR_DEBUG_FLAGS` | 自定义 EMAN debug 命令行参数 |
| `BMS_EMAN_MERGE_DIR` | 覆盖 EMAN 覆盖率 merge 目录 |
| `BMS_EMAN_URG_OPTS` | 传给 EMAN merge 的 URG 参数 |
| `BMS_EMAN_EXTRA` | 额外 EMAN 命令行参数 |
| `BMS_EMAN_MAKE_DIR` | 直跑 `.emc` 时辅助指定 `vcs_com` 目录 |
| `BMS_EMAN_MERGE` | 覆盖率模式下控制是否执行 merge，默认开启 |

## 当前实现注意事项

- `BMS_USE_DTL` 和 DTL 相关函数已经存在，但当前主流程仍走传统编译路径；不要仅凭 `BMS_USE_DTL=1` 判断 DTL 已生效。
- 单例仿真中，脚本会打印 FAIL banner，但当前实现没有在 `has_err=True` 后显式 `sys.exit(1)`；若外层依赖退出码，需要修正。
- error pattern 扫描当前遇到第一条匹配行就返回结果，可能被前面的 pass/warn 规则提前截断。
- `POST_SIM` 在 EMAN 模式下不是每个 test 的后处理，而是在提交 EMAN 后由提交机执行一次。
- 顶部 `os.system("unset LD_PRELOAD")` 只影响临时 shell，不会真正清理当前 Python 进程环境；若依赖该行为，应改为修改 `os.environ`。

## 推荐使用方式

单例本地验证：

```bash
bms <case> -local -d -s 1
```

单例提交 LSF：

```bash
bms <case> -q normal --ncore 1 -m 30
```

快速复用编译结果：

```bash
bms <case> -local -f
```

生成可复用编译库：

```bash
bms <case> -local -genlib compile_lib
```

复用编译库：

```bash
bms <case> -local -f -lib compile_lib
```

EMAN 多用例回归：

```bash
bms -eman <case_or_dir> -num 10 -j 50 -cov
```

EMAN debug rerun：

```bash
bms -eman <case_or_dir> -debug -d
```

直跑已有 `.emc`：

```bash
bms --emc /path/to/run.emc --eman-make-dir /path/to/vcs_com
```

