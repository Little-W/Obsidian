总结如下，编译安装支持32位（RV32GC）RISC-V GCC 工具链的步骤：

1. **安装依赖（以 Ubuntu 为例）**  
   ```zsh
   sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip python3-tomli libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev
   ```

2. **获取源码**  
   ```zsh
   git clone https://github.com/riscv/riscv-gnu-toolchain
   cd riscv-gnu-toolchain
   ```

3. **配置编译参数（支持32位 RV32GC）**  
   选择安装路径（如 `/opt/riscv`），并配置为支持32位架构：
   ```zsh
   ./configure --prefix=/opt/riscv --with-arch=rv32gc --with-abi=ilp32d
   ```
   如果需要同时支持32/64位（多架构），可用：
   ```zsh
   ./configure --prefix=/opt/riscv --enable-multilib
   ```

4. **编译安装**  
   - 编译 newlib 工具链（裸机/嵌入式）：
     ```zsh
     make
     ```
   - 编译 Linux 工具链（glibc）：
     ```zsh
     make linux
     ```

5. **添加环境变量**  
   将工具链路径加入 `PATH`，如：
   ```zsh
   export PATH=/opt/riscv/bin:$PATH
   ```

6. **验证**  
   检查 32 位支持：
   ```zsh
   riscv64-unknown-elf-gcc --print-multi-lib
   ```
   或
   ```zsh
   riscv64-unknown-linux-gnu-gcc --print-multi-lib
   ```
   输出应包含 32 位相关选项（如 `rv32gc/ilp32d`）。

**注意事项：**
- 推荐使用 `--enable-multilib`，可同时支持 32/64 位编译。
- 安装路径需有写权限，且建议为空目录。
- 编译过程需较大磁盘空间（约 8GB）。

如需更复杂的多架构支持，可用 `--with-multilib-generator` 选项自定义。