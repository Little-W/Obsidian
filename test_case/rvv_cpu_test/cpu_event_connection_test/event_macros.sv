`ifndef EVENT_MACROS_SV
`define EVENT_MACROS_SV

// CPU NPU events - source module ports connected to MCU_GLUE_0
`define CPU_CORE0_TX_EVT_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top.core0_tx_evt"
`define CPU_CORE1_TX_EVT_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top.core1_tx_evt"
`define NPU_CORE0_TX_EVT_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_0.tx_evt"
`define NPU_CORE1_TX_EVT_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_1.tx_evt"
`define NPU_CORE2_TX_EVT_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_2.tx_evt"
`define NPU_CORE3_TX_EVT_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_3.tx_evt"
`define HSM_CORE0_TX_EVT_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.HSM_SUB_WRAPPER_0.core0_tx_evt"
`define PMU_EVT_PATH "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_PMU_0.pmu_wakeup_evt"

// GLUE paths for connectivity check

`define CPU_CORE0_TX_EVT_GLUE_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.cpu_core0_tx_evt"
`define CPU_CORE1_TX_EVT_GLUE_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.cpu_core1_tx_evt"
`define NPU_CORE0_TX_EVT_GLUE_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_core0_tx_evt"
`define NPU_CORE1_TX_EVT_GLUE_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_core1_tx_evt"
`define NPU_CORE2_TX_EVT_GLUE_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_core2_tx_evt"
`define NPU_CORE3_TX_EVT_GLUE_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_core3_tx_evt"
`define HSM_CORE0_TX_EVT_GLUE_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_core0_tx_evt"
`define PMU_EVT_GLUE_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.pmu_evt"

// RX event paths
`define CPU_CORE0_RX_EVT_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.cpu_core0_rx_evt"
`define CPU_CORE1_RX_EVT_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.cpu_core1_rx_evt"
`define NPU_CORE0_RX_EVT_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_core0_rx_evt_rr"
`define NPU_CORE1_RX_EVT_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_core1_rx_evt_rr"
`define NPU_CORE2_RX_EVT_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_core2_rx_evt_rr"
`define NPU_CORE3_RX_EVT_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_core3_rx_evt_rr"
`define HSM_CORE0_RX_EVT_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_core0_rx_evt"

// TX_EVTC register offsets in MCU_SUB_SCU
`define CPU_CORE0_TX_EVTC_OFFSET 32'h008
`define CPU_CORE1_TX_EVTC_OFFSET 32'h00C
`define NPU_CORE0_TX_EVTC_OFFSET 32'h010
`define NPU_CORE1_TX_EVTC_OFFSET 32'h014
`define NPU_CORE2_TX_EVTC_OFFSET 32'h018
`define NPU_CORE3_TX_EVTC_OFFSET 32'h01C
`define HSM_CORE0_TX_EVTC_OFFSET 32'h038

// core_tx_evt bit order:
// bit[7]=hsm_core0_tx_evt, bit[6]=pmu_evt, bit[5]=npu_core3_tx_evt,
// bit[4]=npu_core2_tx_evt, bit[3]=npu_core1_tx_evt, bit[2]=npu_core0_tx_evt,
// bit[1]=cpu_core1_tx_evt, bit[0]=cpu_core0_tx_evt
`define CPU_CORE0_TX_EVT_MASK 8'h01
`define CPU_CORE1_TX_EVT_MASK 8'h02
`define NPU_CORE0_TX_EVT_MASK 8'h04
`define NPU_CORE1_TX_EVT_MASK 8'h08
`define NPU_CORE2_TX_EVT_MASK 8'h10
`define NPU_CORE3_TX_EVT_MASK 8'h20
`define PMU_EVT_MASK          8'h40
`define HSM_CORE0_TX_EVT_MASK 8'h80
`define EVT_MASK_CLEAR        8'h00

// TX_EVT_UP registers used to manually clear/pulse SCU-side event receive state
`define NPU_CORE3_TX_EVT_UP_OFFSET 32'h03C
`define NPU_CORE2_TX_EVT_UP_OFFSET 32'h040
`define NPU_CORE1_TX_EVT_UP_OFFSET 32'h044
`define NPU_CORE0_TX_EVT_UP_OFFSET 32'h048
`define CPU_CORE1_TX_EVT_UP_OFFSET 32'h04C
`define CPU_CORE0_TX_EVT_UP_OFFSET 32'h050
`define HSM_CORE0_TX_EVT_UP_OFFSET 32'h054

`define TEST_RELAY_MODE 1
`define TEST_DIREC_MODE 0


`endif