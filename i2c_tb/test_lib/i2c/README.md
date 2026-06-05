# i2c case set

## smoke
目的：验证 `MCU_I2C_WRAPPER` 作为 I2C master 的最小写后读闭环。
关键激励：APB 配置 DUT 为 standard mode，目标地址 `0x55`；DUT 写 `{0x12,0x34,0xa5,0x5a}`，VIP 将 `0x12` 作为寄存器地址并存储后续数据。
期望检查点：DUT 读回 `{0x34,0xa5,0x5a}`；无 `TX_ABRT`。
覆盖点：APB 配置路径、I2C 地址 ACK、数据 ACK、寄存器指针写入、连续读回。
运行命令：`cd $ZC_NPU_VERIF_ROOT/2_verf/it && python3 bms.py i2c_tb/test_lib/i2c/smoke -c`

## basic
目的：与 smoke 相同的基础功能 case，保留给回归中的 basic bucket。
关键激励：`+SEQ=i2c_basic_sequence`，standard mode，VIP generic slave register model。
期望检查点：写后读数据一致；`IC_CON/IC_TAR/IC_ENABLE` 配置读回符合 mask；无 `TX_ABRT`。
覆盖点：DUT master transmit、receive command、STOP、RX FIFO 读取。
运行命令：`cd $ZC_NPU_VERIF_ROOT/2_verf/it && python3 bms.py i2c_tb/test_lib/i2c/basic -c`

## speed_fast
目的：验证 DUT fast mode 时钟配置和 I2C 访问完成。
关键激励：`+I2C_SPEED_MODE=fast`，写 `{0x22,0xc3,0x3c,0x5e}` 后读回。
期望检查点：读回 `{0xc3,0x3c,0x5e}`；等待超时按 fast SCL 计数计算；无 `TX_ABRT`。
覆盖点：`IC_FS_SCL_HCNT/IC_FS_SCL_LCNT` 配置路径、fast mode transfer。
运行命令：`cd $ZC_NPU_VERIF_ROOT/2_verf/it && python3 bms.py i2c_tb/test_lib/i2c/speed_fast -c`

## speed_high
目的：验证 DUT high speed mode 配置路径和高速超时尺度。
关键激励：`+I2C_SPEED_MODE=high +I2C_TIMEOUT_SCALE=8`，写 `{0x33,0x96,0x69,0xf0}` 后读回。
期望检查点：读回 `{0x96,0x69,0xf0}`；无 `TX_ABRT`。
覆盖点：`IC_HS_SCL_HCNT/IC_HS_SCL_LCNT` 配置路径、high speed transfer。
运行命令：`cd $ZC_NPU_VERIF_ROOT/2_verf/it && python3 bms.py i2c_tb/test_lib/i2c/speed_high -c`

## boundary
目的：覆盖 VIP register model 的 DUT 可见寄存器地址边界。
关键激励：先写 `0x00` 起始寄存器并读回，再写 `0xff` 起始寄存器并读回。
期望检查点：`reg[0x00]` 读回 `{0x11,0x22}`；`reg[0xff]` 读回 `{0xee}`；无 `TX_ABRT`。
覆盖点：8-bit register pointer `0x00`、`0xff`，连续地址自增。
运行命令：`cd $ZC_NPU_VERIF_ROOT/2_verf/it && python3 bms.py i2c_tb/test_lib/i2c/boundary -c`

## reg_boundary
目的：与 boundary 相同的显式 feature case 名称，便于单独加入 feature regression。
关键激励：`+SEQ=i2c_reg_boundary_seq`。
期望检查点：同 boundary。
覆盖点：同 boundary。
运行命令：`cd $ZC_NPU_VERIF_ROOT/2_verf/it && python3 bms.py i2c_tb/test_lib/i2c/reg_boundary -c`

## random
目的：验证随机长度寄存器写后读回，不依赖 VIP 随机 slave 行为。
关键激励：随机生成 2 到 8 byte payload，第 0 byte 为寄存器地址，后续 byte 为写入数据。
期望检查点：读回数据与随机写入数据一致；无 `TX_ABRT`；无 `randomize failed`。
覆盖点：不同 payload 长度、不同 register pointer、不同数据组合。
运行命令：`cd $ZC_NPU_VERIF_ROOT/2_verf/it && python3 bms.py i2c_tb/test_lib/i2c/random -c`

## random_reg
目的：fast mode 下的随机长度寄存器写后读回。
关键激励：`+SEQ=i2c_random_reg_seq +I2C_SPEED_MODE=fast`。
期望检查点：读回数据与随机写入数据一致；无 `TX_ABRT`。
覆盖点：fast mode 与随机 payload 组合。
运行命令：`cd $ZC_NPU_VERIF_ROOT/2_verf/it && python3 bms.py i2c_tb/test_lib/i2c/random_reg -c`

## error
目的：验证 DUT 对 I2C 地址 NACK 的 abort 响应。
关键激励：VIP slave 使用 `i2c_slv_nack_sequence`，DUT 发起写访问。
期望检查点：DUT 置位 `IC_RAW_INTR_STAT[6]` 或 `IC_TX_ABRT_SOURCE[20:0]` 非 0；case 主动清除 abort。
覆盖点：address NACK、TX_ABRT interrupt/source。
运行命令：`cd $ZC_NPU_VERIF_ROOT/2_verf/it && python3 bms.py i2c_tb/test_lib/i2c/error -c`

## data_nack
目的：验证 DUT 对 I2C data byte NACK 的 abort 响应。
关键激励：VIP slave 使用 `i2c_slv_nack_data_sequence`，DUT 写 `{0x55,0xbe,0xef}`。
期望检查点：DUT 置位 `IC_RAW_INTR_STAT[6]` 或 `IC_TX_ABRT_SOURCE[20:0]` 非 0；case 主动清除 abort。
覆盖点：data NACK、TX_ABRT interrupt/source。
运行命令：`cd $ZC_NPU_VERIF_ROOT/2_verf/it && python3 bms.py i2c_tb/test_lib/i2c/data_nack -c`
