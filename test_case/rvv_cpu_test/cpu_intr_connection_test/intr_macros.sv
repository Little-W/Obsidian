`ifndef INTR_MACROS_SV
`define INTR_MACROS_SV

// Macro definitions for hierarchical paths
// TCU module
`define TCU_EVENT_Q_INTR_S_PATH  "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SCU_WRAPPER_0.tcu_event_q_s_intr"
`define TCU_EVENT_Q_INTR_NS_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SCU_WRAPPER_0.tcu_event_q_ns_intr"
`define TCU_PRI_Q_INTR_NS_PATH   "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SCU_WRAPPER_0.tcu_pri_q_ns_intr"
`define TCU_CMD_SYNC_INTR_NS_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SCU_WRAPPER_0.tcu_cmd_sync_ns_intr"
`define TCU_CMD_SYNC_INTR_S_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SCU_WRAPPER_0.tcu_cmd_sync_s_intr"
`define TCU_GLOBAL_INTR_NS_PATH  "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SCU_WRAPPER_0.tcu_global_ns_intr"
`define TCU_GLOBAL_INTR_S_PATH   "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SCU_WRAPPER_0.tcu_global_s_intr"
`define TCU_RAS_INTR_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SCU_WRAPPER_0.tcu_ras_intr"
`define TCU_PMU_INTR_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SCU_WRAPPER_0.tcu_pmu_intr"

// AON module
// AON GPIO31~8
`define AON_GPIO_INTR31_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[31]"
`define AON_GPIO_INTR30_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[30]"
`define AON_GPIO_INTR29_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[29]"
`define AON_GPIO_INTR28_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[28]"
`define AON_GPIO_INTR27_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[27]"
`define AON_GPIO_INTR26_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[26]"
`define AON_GPIO_INTR25_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[25]"
`define AON_GPIO_INTR24_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[24]"
`define AON_GPIO_INTR23_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[23]"
`define AON_GPIO_INTR22_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[22]"
`define AON_GPIO_INTR21_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[21]"
`define AON_GPIO_INTR20_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[20]"
`define AON_GPIO_INTR19_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[19]"
`define AON_GPIO_INTR18_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[18]"
`define AON_GPIO_INTR17_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[17]"
`define AON_GPIO_INTR16_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[16]"
`define AON_GPIO_INTR15_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[15]"
`define AON_GPIO_INTR14_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[14]"
`define AON_GPIO_INTR13_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[13]"
`define AON_GPIO_INTR12_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[12]"
`define AON_GPIO_INTR11_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[11]"
`define AON_GPIO_INTR10_PATH     "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[10]"
`define AON_GPIO_INTR9_PATH      "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[9]"
`define AON_GPIO_INTR8_PATH      "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[8]"
// AON GPIO7~0
`define AON_GPIO_INTR7_PATH      "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[7]"
`define AON_GPIO_INTR6_PATH      "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[6]"
`define AON_GPIO_INTR5_PATH      "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[5]"
`define AON_GPIO_INTR4_PATH      "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[4]"
`define AON_GPIO_INTR3_PATH      "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[3]"
`define AON_GPIO_INTR2_PATH      "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[2]"
`define AON_GPIO_INTR1_PATH      "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[1]"
`define AON_GPIO_INTR0_PATH      "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_GPIO_WRAPPER_0.U_AON_DW_apb_gpio.gpio_intr[0]"

`define AON_CRG_INTR_PATH        "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_CRG_0.aon_crg_intr"
`define AON_PVTC_INTR_PATH       "hdl_top.T100_TOP_u.PD_AON_SUB_0.U_PVT_CONTROLLER_WRAP.irq"
`define AON_RTC_INTR_PATH        "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_RTC_WRAPPER_0.aon_rtc_intr"
`define AON_I2C0_INTR_PATH       "hdl_top.T100_TOP_u.PD_AON_SUB_0.MCU_I2C_WRAPPER_0.ic_intr"
`define AON_I2C1_INTR_PATH       "hdl_top.T100_TOP_u.PD_AON_SUB_0.I2C_WRAPPER_1.ic_intr"

// PD_DDR_SUB module
`define LP0_DDR_INT_PATH         "hdl_top.T100_TOP_u.PD_DDR_SUB_01.LPDDR_SUB_0.lpddr_sub_int"
`define LP1_DDR_INT_PATH         "hdl_top.T100_TOP_u.PD_DDR_SUB_01.LPDDR_SUB_1.lpddr_sub_int"
`define LP2_DDR_INT_PATH         "hdl_top.T100_TOP_u.PD_DDR_SUB_23.LPDDR_SUB_0.lpddr_sub_int"
`define LP3_DDR_INT_PATH         "hdl_top.T100_TOP_u.PD_DDR_SUB_23.LPDDR_SUB_1.lpddr_sub_int"

// PD_HS_SUB module
// HS DMA channel interrupts
`define HS_DMA_CH3_INTR_PATH     "hdl_top.T100_TOP_u.PD_HS_SUB_0.hs_dma_wrapper_0.hs_dma_intr_ch[3]"
`define HS_DMA_CH2_INTR_PATH     "hdl_top.T100_TOP_u.PD_HS_SUB_0.hs_dma_wrapper_0.hs_dma_intr_ch[2]"
`define HS_DMA_CH1_INTR_PATH     "hdl_top.T100_TOP_u.PD_HS_SUB_0.hs_dma_wrapper_0.hs_dma_intr_ch[1]"
`define HS_DMA_CH0_INTR_PATH     "hdl_top.T100_TOP_u.PD_HS_SUB_0.hs_dma_wrapper_0.hs_dma_intr_ch[0]"
`define HS_DMA_RAS_IRPT_PATH     "hdl_top.T100_TOP_u.PD_HS_SUB_0.hs_dma_wrapper_0.hs_dma_ras_irpt"
`define HS_DMA_PMU_IRPT_PATH     "hdl_top.T100_TOP_u.PD_HS_SUB_0.hs_dma_wrapper_0.hs_dma_pmu_irpt"
// HS USB basic interrupts
`define HS_USB_INTR1_PATH        "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_UEE_0.U_HS_USB_WRAPPER_0.usb_interrupt[1]"
`define HS_USB_INTR0_PATH        "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_UEE_0.U_HS_USB_WRAPPER_0.usb_interrupt[0]"
`define HS_USB_BCA_INTR_PATH     "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_UEE_0.U_HS_USB_WRAPPER_0.usb_tca_intr"
`define HS_USB_HOST_SYS_ERR_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_UEE_0.U_HS_USB_WRAPPER_0.usb_host_sys_err_intr"
`define HS_EMMC_INTR_PATH        "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_UEE_0.HS_EMMC_WRAPPER_0.intr"
`define HS_EMMC_WAKEUP_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_UEE_0.HS_EMMC_WRAPPER_0.wakeup_intr"
`define HS_NVME_INTR_PATH        "hdl_top.T100_TOP_u.PD_HS_SUB_0.hs_nvme_wrapper_0.ha_interrupt"
`define HS_ETH_INTR_PATH         "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_UEE_0.U_HS_ETH_WRAPPER_0.hs_eth_wrap_intr_out"

// PD_MEDIA_SUB module
`define MEDIA_SUB_GPU_SYSERR_INTR_PATH "hdl_top.T100_TOP_u.U_PD_MEDIA_SUB.U_MEDIA_SUB.media_sub_irq[6]"
`define MEDIA_SUB_GPU_INTR_PATH       "hdl_top.T100_TOP_u.U_PD_MEDIA_SUB.U_MEDIA_SUB.media_sub_irq[5]"
`define MEDIA_SUB_JPU_INTR_PATH       "hdl_top.T100_TOP_u.U_PD_MEDIA_SUB.U_MEDIA_SUB.media_sub_irq[4]"
`define MEDIA_SUB_DPU_INTR_PATH       "hdl_top.T100_TOP_u.U_PD_MEDIA_SUB.U_MEDIA_SUB.media_sub_irq[7]"
`define MEDIA_TBU_RAS_INTR_PATH       "hdl_top.T100_TOP_u.U_PD_MEDIA_SUB.U_MEDIA_SUB.media_tbu_ras_irq"
`define MEDIA_TBU_PMU_INTR_PATH       "hdl_top.T100_TOP_u.U_PD_MEDIA_SUB.U_MEDIA_SUB.media_tbu_pmu_irq"
`define MEDIA_SUB_VPU_INTR_0_PATH     "hdl_top.T100_TOP_u.U_PD_MEDIA_SUB.U_MEDIA_SUB.media_sub_irq[0]"
`define MEDIA_SUB_VPU_INTR_1_PATH     "hdl_top.T100_TOP_u.U_PD_MEDIA_SUB.U_MEDIA_SUB.media_sub_irq[1]"
`define MEDIA_SUB_VPU_INTR_2_PATH     "hdl_top.T100_TOP_u.U_PD_MEDIA_SUB.U_MEDIA_SUB.media_sub_irq[2]"
`define MEDIA_SUB_VPU_INTR_3_PATH     "hdl_top.T100_TOP_u.U_PD_MEDIA_SUB.U_MEDIA_SUB.media_sub_irq[3]"

// MCU GPIO
`define MCU_GPIO_INTR31_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[31]"
`define MCU_GPIO_INTR30_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[30]"
`define MCU_GPIO_INTR29_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[29]"
`define MCU_GPIO_INTR28_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[28]"
`define MCU_GPIO_INTR27_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[27]"
`define MCU_GPIO_INTR26_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[26]"
`define MCU_GPIO_INTR25_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[25]"
`define MCU_GPIO_INTR24_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[24]"
`define MCU_GPIO_INTR23_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[23]"
`define MCU_GPIO_INTR22_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[22]"
`define MCU_GPIO_INTR21_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[21]"
`define MCU_GPIO_INTR20_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[20]"
`define MCU_GPIO_INTR19_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[19]"
`define MCU_GPIO_INTR18_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[18]"
`define MCU_GPIO_INTR17_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[17]"
`define MCU_GPIO_INTR16_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[16]"
`define MCU_GPIO_INTR15_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[15]"
`define MCU_GPIO_INTR14_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[14]"
`define MCU_GPIO_INTR13_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[13]"
`define MCU_GPIO_INTR12_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[12]"
`define MCU_GPIO_INTR11_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[11]"
`define MCU_GPIO_INTR10_PATH          "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[10]"
`define MCU_GPIO_INTR9_PATH           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[9]"
`define MCU_GPIO_INTR8_PATH           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[8]"
`define MCU_GPIO_INTR7_PATH           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[7]"
`define MCU_GPIO_INTR6_PATH           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[6]"
`define MCU_GPIO_INTR5_PATH           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[5]"
`define MCU_GPIO_INTR4_PATH           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[4]"
`define MCU_GPIO_INTR3_PATH           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[3]"
`define MCU_GPIO_INTR2_PATH           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[2]"
`define MCU_GPIO_INTR1_PATH           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[1]"
`define MCU_GPIO_INTR0_PATH           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GPIO_WRAPPER_0.mcu_gpio_intr[0]"

`define MCU_MAILBOX_INTR15_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[15]"
`define MCU_MAILBOX_INTR14_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[14]"
`define MCU_MAILBOX_INTR13_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[13]"
`define MCU_MAILBOX_INTR12_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[12]"
`define MCU_MAILBOX_INTR11_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[11]"
`define MCU_MAILBOX_INTR10_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[10]"
`define MCU_MAILBOX_INTR9_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[9]"
`define MCU_MAILBOX_INTR8_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[8]"
`define MCU_MAILBOX_INTR7_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[7]"
`define MCU_MAILBOX_INTR6_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[6]"
`define MCU_MAILBOX_INTR5_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[5]"
`define MCU_MAILBOX_INTR4_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[4]"
`define MCU_MAILBOX_INTR3_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[3]"
`define MCU_MAILBOX_INTR2_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[2]"
`define MCU_MAILBOX_INTR1_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[1]"
`define MCU_MAILBOX_INTR0_PATH        "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[0]"
`define MCU_DMA_CH7_INTR_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_DMAC_WRAPPER_0.mcu_dma_channel_intr[7]"
`define MCU_DMA_CH6_INTR_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_DMAC_WRAPPER_0.mcu_dma_channel_intr[6]"
`define MCU_DMA_CH5_INTR_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_DMAC_WRAPPER_0.mcu_dma_channel_intr[5]"
`define MCU_DMA_CH4_INTR_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_DMAC_WRAPPER_0.mcu_dma_channel_intr[4]"
`define MCU_DMA_CH3_INTR_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_DMAC_WRAPPER_0.mcu_dma_channel_intr[3]"
`define MCU_DMA_CH2_INTR_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_DMAC_WRAPPER_0.mcu_dma_channel_intr[2]"
`define MCU_DMA_CH1_INTR_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_DMAC_WRAPPER_0.mcu_dma_channel_intr[1]"
`define MCU_DMA_CH0_INTR_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_DMAC_WRAPPER_0.mcu_dma_channel_intr[0]"


`define UCIE0_DBG_INTR_PATH           "hdl_top.T100_TOP_u.U_PD_UCIE_SUB_0.U_UCIE_WRAPPER.ucie_dbg_irq"
`define UCIE0_MCU_DB2SOC_INTR_PATH    "hdl_top.T100_TOP_u.U_PD_UCIE_SUB_0.U_UCIE_WRAPPER.ucie_mcu_db2soc_irq"
`define UCIE1_DBG_INTR_PATH           "hdl_top.T100_TOP_u.U_PD_UCIE_SUB_1.U_UCIE_WRAPPER.ucie_dbg_irq"
`define UCIE1_MCU_DB2SOC_INTR_PATH    "hdl_top.T100_TOP_u.U_PD_UCIE_SUB_1.U_UCIE_WRAPPER.ucie_mcu_db2soc_irq"

`define T2_UEE_RAS_IRPT_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_UEE_0.smmu_ras_irpt"

`define HS_PCIESS00_MSI_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x8_intr_out[6]"
`define HS_PCIESS00_PMU_IRPT_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x8_pmu_irpt"
`define HS_PCIESS00_RAS_IRPT_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x8_ras_irpt"

`define HS_PCIESS01_MSI_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x4_intr_out[6]"
`define HS_PCIESS01_PMU_IRPT_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x4_pmu_irpt"
`define HS_PCIESS01_RAS_IRPT_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x4_ras_irpt"

`define MCU_I2C0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I2C_WRAPPER_0.ic_intr"
`define MCU_I2C1_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I2C_WRAPPER_1.ic_intr"
`define MCU_I2C2_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I2C_WRAPPER_2.ic_intr"
`define MCU_I2C3_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I2C_WRAPPER_3.ic_intr"
`define MCU_I2S0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I2S_WRAPPER_0.intr"
`define MCU_I2S1_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I2S_WRAPPER_1.intr"
`define MCU_I3C0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.ic_intr"
`define MCU_I3C1_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_1.ic_intr"
`define MCU_SPI0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SPI_WRAPPER_0.ssi_intr"
`define MCU_SPI1_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SPI_WRAPPER_1.ssi_intr"

`define MCU_XSPI0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SSI_XIP_WRAPPER_0.ssi_intr"
`define MCU_XSPI1_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_SSI_WRAPPER_0.ssi_intr"

`define MCU_UART0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_UART_WRAPPER_0.uart_intr"
`define MCU_UART1_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_UART_WRAPPER_1.uart_intr"
`define MCU_UART2_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_UART_WRAPPER_2.uart_intr"
`define MCU_UART3_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_UART_WRAPPER_3.uart_intr"

`define MCU_TIMER0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_TIMER_WRAPPER_0.timer_intr"
`define MCU_TIMER1_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_TIMER_WRAPPER_1.timer_intr"

`define MCU_MAILBOX_INTR7_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[7]"
`define MCU_MAILBOX_INTR6_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[6]"
`define MCU_MAILBOX_INTR5_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[5]"
`define MCU_MAILBOX_INTR4_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[4]"
`define MCU_MAILBOX_INTR3_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[3]"
`define MCU_MAILBOX_INTR2_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[2]"
`define MCU_MAILBOX_INTR1_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[1]"
`define MCU_MAILBOX_INTR0_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_MAILBOX_WRAPPER_0.mailbox_irq[0]"

`define HSM_MAILBOX_HOST_0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.HSM_SUB_WRAPPER_0.mailbox_host_0_irq"
`define HSM_MAILBOX_INTERNAL_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.HSM_SUB_WRAPPER_0.mailbox_internal_intr_irq"
`define HSM_TRNG0_TRNG_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.HSM_SUB_WRAPPER_0.trng0_trng_int"
`define HSM_HASH0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.HSM_SUB_WRAPPER_0.hash0_intr_o"
`define HSM_CRYP0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.HSM_SUB_WRAPPER_0.cryp0_intr_o"
`define HSM_ACRYP0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.HSM_SUB_WRAPPER_0.acryp0_interrupt_o"
`define HSM_RTC0_RTC_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.HSM_SUB_WRAPPER_0.rtc0_rtc_irq_o"
`define HSM_BASIC_TIMER0_BSC_TIM_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.HSM_SUB_WRAPPER_0.basic_timer0_bsc_tim_int"
`define HSM_USART0_UART_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.HSM_SUB_WRAPPER_0.usart0_uart_interrupt_o"
`define HSM_UDMA0_UDMA_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.HSM_SUB_WRAPPER_0.udma0_udma_irq"

`define MCU_CAN0_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.U_MCU_CAN_WRAPPER_0.can_intr"
`define MCU_CAN1_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.U_MCU_CAN_WRAPPER_1.can_intr"

`define MCU_ATB2AXI_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_mcu_atb2axi_top.atb2axi_irq"

`define MCU_DMA_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_DMAC_WRAPPER_0.mcu_dma_cmnreg_intr"

`define MCU_NOC_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_NOC_WRAPPER_0.mcu_interrupt"

`define T2_UEE_PMU_IRPT_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_UEE_0.smmu_pmu_irpt"

`define BARRIER_INTR_PATH "hdl_top.T100_TOP_u.u_zcnpu_barrier_wrapper.barrier_intr"
`define NPU_INTR3_0_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_3.int_ncore[0]"
`define NPU_INTR3_1_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_3.int_ncore[1]"
`define NPU_INTR3_2_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_3.int_ncore[2]"
`define NPU_INTR3_3_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_3.int_ncore[3]"
`define NPU_INTR3_4_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_3.int_ncore[4]"
`define NPU_INTR3_5_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_3.int_ncore[5]"
`define NPU_INTR3_6_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_3.int_ncore[6]"
`define NPU_INTR3_7_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_3.int_ncore[7]"

`define NPU_INTR2_0_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_2.int_ncore[0]"
`define NPU_INTR2_1_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_2.int_ncore[1]"
`define NPU_INTR2_2_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_2.int_ncore[2]"
`define NPU_INTR2_3_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_2.int_ncore[3]"
`define NPU_INTR2_4_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_2.int_ncore[4]"
`define NPU_INTR2_5_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_2.int_ncore[5]"
`define NPU_INTR2_6_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_2.int_ncore[6]"
`define NPU_INTR2_7_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_2.int_ncore[7]"

`define NPU_INTR1_0_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_1.int_ncore[0]"
`define NPU_INTR1_1_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_1.int_ncore[1]"
`define NPU_INTR1_2_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_1.int_ncore[2]"
`define NPU_INTR1_3_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_1.int_ncore[3]"
`define NPU_INTR1_4_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_1.int_ncore[4]"
`define NPU_INTR1_5_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_1.int_ncore[5]"
`define NPU_INTR1_6_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_1.int_ncore[6]"
`define NPU_INTR1_7_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_1.int_ncore[7]"

`define NPU_INTR0_0_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_0.int_ncore[0]"
`define NPU_INTR0_1_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_0.int_ncore[1]"
`define NPU_INTR0_2_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_0.int_ncore[2]"
`define NPU_INTR0_3_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_0.int_ncore[3]"
`define NPU_INTR0_4_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_0.int_ncore[4]"
`define NPU_INTR0_5_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_0.int_ncore[5]"
`define NPU_INTR0_6_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_0.int_ncore[6]"
`define NPU_INTR0_7_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_0.int_ncore[7]"

`define NPU_WDT_INTR3_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_3.wdt_intr"
`define NPU_WDT_INTR2_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_2.wdt_intr"
`define NPU_WDT_INTR1_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_1.wdt_intr"
`define NPU_WDT_INTR0_PATH "hdl_top.T100_TOP_u.T1_NPU_CORE_0.wdt_intr"

`define MCU_WDT_INTR_PATH "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_WDT_WRAPPER_0.wdt_intr"

`define TOP_CRG_PLL_INTR_PATH "hdl_top.T100_TOP_u.U_TOP_CRG.top_crg_pll_intr"

`define HS_DATA_NOC_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.hs_data_noc_wrapper_0.hs_data_noc_intr"
`define HS_REG_NOC_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.HS_REG_NOC_WRAPPER_0.u_hs_reg_noc.noc_intr"
`define HS_HS_DMA_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.hs_dma_wrapper_0.hs_dma_intr_cmnreg"
`define SOC_NOC_INTR_PATH "hdl_top.T100_TOP_u.T1_SOC_NOC_0.main_noc_intr"

`define HS_PCIESS00_MSIDONE_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x8_intr_out[5]"
`define HS_PCIESS00_INTX_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x8_intr_out[4]"
`define HS_PCIESS00_STATUS_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x8_intr_out[3]"
`define HS_PCIESS00_ATU_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x8_intr_out[2]"
`define HS_PCIESS00_ERR_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x8_intr_out[1]"
`define HS_PCIESS00_DMA_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x8_intr_out[0]"

`define HS_PCIESS01_MSIDONE_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x4_intr_out[5]"
`define HS_PCIESS01_INTX_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x4_intr_out[4]"
`define HS_PCIESS01_STATUS_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x4_intr_out[3]"
`define HS_PCIESS01_ATU_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x4_intr_out[2]"
`define HS_PCIESS01_ERR_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x4_intr_out[1]"
`define HS_PCIESS01_DMA_INTR_PATH "hdl_top.T100_TOP_u.PD_HS_SUB_0.U_T2_PCIESS_0.pcie_x4_intr_out[0]"

`define PMU_EVT_WAKEUP_INTR_PATH      "hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_PMU_0.pmu_evt_wakeup_intr"
`define NPU_CORE0_TBU0_RAS_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_0.tbu0_ras_irpt"
`define NPU_CORE0_TBU0_PMU_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_0.tbu0_pmu_irpt"
`define NPU_CORE0_TBU1_RAS_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_0.tbu1_ras_irpt"
`define NPU_CORE0_TBU1_PMU_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_0.tbu1_pmu_irpt"
`define NPU_CORE1_TBU0_RAS_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_1.tbu0_ras_irpt"
`define NPU_CORE1_TBU0_PMU_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_1.tbu0_pmu_irpt"
`define NPU_CORE1_TBU1_RAS_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_1.tbu1_ras_irpt"
`define NPU_CORE1_TBU1_PMU_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_1.tbu1_pmu_irpt"
`define NPU_CORE2_TBU0_RAS_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_2.tbu0_ras_irpt"
`define NPU_CORE2_TBU0_PMU_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_2.tbu0_pmu_irpt"
`define NPU_CORE2_TBU1_RAS_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_2.tbu1_ras_irpt"
`define NPU_CORE2_TBU1_PMU_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_2.tbu1_pmu_irpt"
`define NPU_CORE3_TBU0_RAS_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_3.tbu0_ras_irpt"
`define NPU_CORE3_TBU0_PMU_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_3.tbu0_pmu_irpt"
`define NPU_CORE3_TBU1_RAS_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_3.tbu1_ras_irpt"
`define NPU_CORE3_TBU1_PMU_INTR_PATH  "hdl_top.T100_TOP_u.T1_NPU_CORE_3.tbu1_pmu_irpt"

// Path for receiving signals on the other end
`define INTR_SYNC_OUT_PATH       "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.irq_i"


// Macro definitions for core_irq indices
`define MCU_GPIO_INTR31_IRQ_ID 0//
`define MCU_GPIO_INTR30_IRQ_ID 1//
`define MCU_GPIO_INTR29_IRQ_ID 2//
`define MCU_GPIO_INTR28_IRQ_ID 3//
`define MCU_GPIO_INTR27_IRQ_ID 4//
`define MCU_GPIO_INTR26_IRQ_ID 5//
`define MCU_GPIO_INTR25_IRQ_ID 6//
`define MCU_GPIO_INTR24_IRQ_ID 7//
`define MCU_GPIO_INTR23_IRQ_ID 8//
`define MCU_GPIO_INTR22_IRQ_ID 9//
`define MCU_GPIO_INTR21_IRQ_ID 10//
`define MCU_GPIO_INTR20_IRQ_ID 11//
`define MCU_GPIO_INTR19_IRQ_ID 12//
`define MCU_GPIO_INTR18_IRQ_ID 13//
`define MCU_GPIO_INTR17_IRQ_ID 14//
`define MCU_GPIO_INTR16_IRQ_ID 15//
`define MCU_GPIO_INTR15_IRQ_ID 16//
`define MCU_GPIO_INTR14_IRQ_ID 17//
`define MCU_GPIO_INTR13_IRQ_ID 18//
`define MCU_GPIO_INTR12_IRQ_ID 19//
`define MCU_GPIO_INTR11_IRQ_ID 20//
`define MCU_GPIO_INTR10_IRQ_ID 21//
`define MCU_GPIO_INTR9_IRQ_ID 22//
`define MCU_GPIO_INTR8_IRQ_ID 23//
`define AON_GPIO_INTR31_IRQ_ID 24//
`define AON_GPIO_INTR30_IRQ_ID 25//
`define AON_GPIO_INTR29_IRQ_ID 26//
`define AON_GPIO_INTR28_IRQ_ID 27//
`define AON_GPIO_INTR27_IRQ_ID 28//
`define AON_GPIO_INTR26_IRQ_ID 29//
`define AON_GPIO_INTR25_IRQ_ID 30//
`define AON_GPIO_INTR24_IRQ_ID 31//
`define AON_GPIO_INTR23_IRQ_ID 32//
`define AON_GPIO_INTR22_IRQ_ID 33//
`define AON_GPIO_INTR21_IRQ_ID 34//
`define AON_GPIO_INTR20_IRQ_ID 35//
`define AON_GPIO_INTR19_IRQ_ID 36//
`define AON_GPIO_INTR18_IRQ_ID 37//
`define AON_GPIO_INTR17_IRQ_ID 38//
`define AON_GPIO_INTR16_IRQ_ID 39//
`define AON_GPIO_INTR15_IRQ_ID 40//
`define AON_GPIO_INTR14_IRQ_ID 41//
`define AON_GPIO_INTR13_IRQ_ID 42//
`define AON_GPIO_INTR12_IRQ_ID 43//
`define AON_GPIO_INTR11_IRQ_ID 44//
`define AON_GPIO_INTR10_IRQ_ID 45//
`define AON_GPIO_INTR9_IRQ_ID 46//
`define AON_GPIO_INTR8_IRQ_ID 47//
`define MCU_MAILBOX_INTR15_IRQ_ID 48//
`define MCU_MAILBOX_INTR14_IRQ_ID 49//
`define MCU_MAILBOX_INTR13_IRQ_ID 50//
`define MCU_MAILBOX_INTR12_IRQ_ID 51//
`define MCU_MAILBOX_INTR11_IRQ_ID 52//
`define MCU_MAILBOX_INTR10_IRQ_ID 53//
`define MCU_MAILBOX_INTR9_IRQ_ID 54//
`define MCU_MAILBOX_INTR8_IRQ_ID 55//
`define MCU_DMA_CH7_INTR_IRQ_ID 56//
`define MCU_DMA_CH6_INTR_IRQ_ID 57//
`define MCU_DMA_CH5_INTR_IRQ_ID 58//
`define MCU_DMA_CH4_INTR_IRQ_ID 59//
`define MCU_DMA_CH3_INTR_IRQ_ID 60//
`define MCU_DMA_CH2_INTR_IRQ_ID 61//
`define MCU_DMA_CH1_INTR_IRQ_ID 62//
`define MCU_DMA_CH0_INTR_IRQ_ID 63//
`define UCIE1_P2P_INTR_IRQ_ID 64 // unused
`define UCIE1_MCU_DB2SOC_INTR_IRQ_ID 65//
`define UCIE1_DBG_INTR_IRQ_ID 66 //
`define UCIE0_P2P_INTR_IRQ_ID 67 // unused
`define UCIE0_MCU_DB2SOC_INTR_IRQ_ID 68//
`define UCIE0_DBG_INTR_IRQ_ID 69//
`define HS_P2P_BRIDGE_INTR_IRQ_ID 70 // unused
`define T2_UEE_RAS_IRPT_IRQ_ID 71
`define HS_ETH_INTR_IRQ_ID 72//
`define HS_EMMC_WAKEUP_INTR_IRQ_ID 73//
`define HS_EMMC_INTR_IRQ_ID 74//
`define HS_USB_BCA_INTR_IRQ_ID 75//
`define HS_USB_INTR1_IRQ_ID 76//
`define HS_USB_INTR0_IRQ_ID 77//
`define HS_NVME_INTR_IRQ_ID 78//
`define HS_DMA_PMU_IRPT_IRQ_ID 79//
`define HS_DMA_RAS_IRPT_IRQ_ID 80//
`define HS_DMA_CH3_INTR_IRQ_ID 81//
`define HS_DMA_CH2_INTR_IRQ_ID 82//
`define HS_DMA_CH1_INTR_IRQ_ID 83//
`define HS_DMA_CH0_INTR_IRQ_ID 84//
`define HS_PCIESS01_PMU_IRPT_IRQ_ID 85//
`define HS_PCIESS01_RAS_IRPT_IRQ_ID 86//
`define HS_PCIESS01_MSI_INTR_IRQ_ID 87//
`define HS_PCIESS01_MSIDONE_INTR_IRQ_ID 88 //
`define HS_PCIESS01_INTX_INTR_IRQ_ID 89 //
`define HS_PCIESS01_STATUS_INTR_IRQ_ID 90 //
`define HS_PCIESS00_PMU_IRPT_IRQ_ID 91//
`define HS_PCIESS00_RAS_IRPT_IRQ_ID 92//
`define HS_PCIESS00_MSI_INTR_IRQ_ID 93//
`define HS_PCIESS00_MSIDONE_INTR_IRQ_ID 94 //
`define HS_PCIESS00_INTX_INTR_IRQ_ID 95 //
`define HS_PCIESS00_STATUS_INTR_IRQ_ID 96 //
`define LP3_DDR_INT_IRQ_ID 97//
`define LP2_DDR_INT_IRQ_ID 98//
`define LP1_DDR_INT_IRQ_ID 99//
`define LP0_DDR_INT_IRQ_ID 100//
`define MEDIA_SUB_DPU_INTR_IRQ_ID 101//
`define MEDIA_SUB_GPU_INTR_IRQ_ID 102//
`define MEDIA_SUB_JPU_INTR_IRQ_ID 103
`define MEDIA_SUB_VPU_INTR_3_IRQ_ID 104//
`define MEDIA_SUB_VPU_INTR_2_IRQ_ID 105//
`define MEDIA_SUB_VPU_INTR_1_IRQ_ID 106//
`define MEDIA_SUB_VPU_INTR_0_IRQ_ID 107//
`define MCU_I2S1_INTR_IRQ_ID 108 //
`define MCU_I3C1_INTR_IRQ_ID 109//
`define MCU_I2C3_INTR_IRQ_ID 110//
`define MCU_I2C2_INTR_IRQ_ID 111//
`define MCU_XSPI1_INTR_IRQ_ID 112//
`define MCU_SPI1_INTR_IRQ_ID 113//
`define MCU_UART3_INTR_IRQ_ID 114//
`define MCU_UART2_INTR_IRQ_ID 115//
`define MCU_TIMER1_INTR_IRQ_ID 116//
`define MCU_TIMER0_INTR_IRQ_ID 117//
`define MCU_MAILBOX_INTR7_IRQ_ID 118//
`define MCU_MAILBOX_INTR6_IRQ_ID 119//
`define MCU_MAILBOX_INTR5_IRQ_ID 120//
`define MCU_MAILBOX_INTR4_IRQ_ID 121//
`define MCU_MAILBOX_INTR3_IRQ_ID 122//
`define MCU_MAILBOX_INTR2_IRQ_ID 123//
`define MCU_MAILBOX_INTR1_IRQ_ID 124//
`define MCU_MAILBOX_INTR0_IRQ_ID 125//
`define MCU_GPIO_INTR7_IRQ_ID 126//
`define MCU_GPIO_INTR6_IRQ_ID 127//
`define MCU_GPIO_INTR5_IRQ_ID 128//
`define MCU_GPIO_INTR4_IRQ_ID 129//
`define MCU_GPIO_INTR3_IRQ_ID 130//
`define MCU_GPIO_INTR2_IRQ_ID 131//
`define MCU_GPIO_INTR1_IRQ_ID 132//
`define MCU_GPIO_INTR0_IRQ_ID 133//
`define AON_GPIO_INTR7_IRQ_ID 134//
`define AON_GPIO_INTR6_IRQ_ID 135//
`define AON_GPIO_INTR5_IRQ_ID 136//
`define AON_GPIO_INTR4_IRQ_ID 137//
`define AON_GPIO_INTR3_IRQ_ID 138//
`define AON_GPIO_INTR2_IRQ_ID 139//
`define AON_GPIO_INTR1_IRQ_ID 140//
`define AON_GPIO_INTR0_IRQ_ID 141//
`define AON_I2C1_INTR_IRQ_ID 142//
`define AON_I2C0_INTR_IRQ_ID 143//
`define AON_RTC_INTR_IRQ_ID 144//
`define AON_PVTC_INTR_IRQ_ID 145//
`define HSM_MAILBOX_HOST_0_INTR_IRQ_ID 146//
`define HSM_MAILBOX_INTERNAL_INTR_IRQ_ID 147//
`define HSM_TRNG0_TRNG_INTR_IRQ_ID 148//
`define HSM_HASH0_INTR_IRQ_ID 149//
`define HSM_CRYP0_INTR_IRQ_ID 150//
`define HSM_ACRYP0_INTR_IRQ_ID 151//
`define HSM_RTC0_RTC_INTR_IRQ_ID 152//
`define HSM_BASIC_TIMER0_BSC_TIM_INTR_IRQ_ID 153//
`define HSM_USART0_UART_INTR_IRQ_ID 154//
`define HSM_UDMA0_UDMA_INTR_IRQ_ID 155//
`define MCU_CAN1_INTR_IRQ_ID 156//
`define MCU_CAN0_INTR_IRQ_ID 157//
`define MCU_ATB2AXI_INTR_IRQ_ID 158//
`define MCU_SDIO_INTR_IRQ_ID 159 // reserved
`define MCU_I2S0_INTR_IRQ_ID 160//
`define MCU_I3C0_INTR_IRQ_ID 161//
`define MCU_XSPI0_INTR_IRQ_ID 162//
`define MCU_SPI0_INTR_IRQ_ID 163//
`define MCU_I2C1_INTR_IRQ_ID 164//
`define MCU_I2C0_INTR_IRQ_ID 165//
`define MCU_UART1_INTR_IRQ_ID 166//
`define MCU_UART0_INTR_IRQ_ID 167//
`define MCU_NOC_INTR_IRQ_ID 168//
`define HS_DATA_NOC_INTR_IRQ_ID 169 //
`define HS_REG_NOC_INTR_IRQ_ID 170 //
`define TOP_CRG_PLL_INTR_IRQ_ID 171 //
`define SOC_NOC_INTR_IRQ_ID 172 //
`define MEDIA_SUB_GPU_SYSERR_INTR_IRQ_ID 173//
`define AON_CRG_INTR_IRQ_ID 174//
`define T2_UEE_PMU_IRPT_IRQ_ID 175//
`define HS_USB_HOST_SYS_ERR_INTR_IRQ_ID 176//
`define HS_HS_DMA_INTR_IRQ_ID 177 //
`define HS_PCIESS01_ATU_INTR_IRQ_ID 178 //
`define HS_PCIESS01_ERR_INTR_IRQ_ID 179 //
`define HS_PCIESS01_DMA_INTR_IRQ_ID 180 //
`define HS_PCIESS00_ATU_INTR_IRQ_ID 181 //
`define HS_PCIESS00_ERR_INTR_IRQ_ID 182 //
`define HS_PCIESS00_DMA_INTR_IRQ_ID 183 //
`define MCU_DMA_INTR_IRQ_ID 184 //
`define PMU_EVT_WAKEUP_INTR_IRQ_ID 185
`define NPU_CORE3_TBU1_PMU_INTR_IRQ_ID 186
`define NPU_CORE3_TBU1_RAS_INTR_IRQ_ID 187
`define NPU_CORE3_TBU0_PMU_INTR_IRQ_ID 188
`define NPU_CORE3_TBU0_RAS_INTR_IRQ_ID 189
`define NPU_CORE2_TBU1_PMU_INTR_IRQ_ID 190
`define NPU_CORE2_TBU1_RAS_INTR_IRQ_ID 191
`define NPU_CORE2_TBU0_PMU_INTR_IRQ_ID 192
`define NPU_CORE2_TBU0_RAS_INTR_IRQ_ID 193
`define NPU_CORE1_TBU1_PMU_INTR_IRQ_ID 194
`define NPU_CORE1_TBU1_RAS_INTR_IRQ_ID 195
`define NPU_CORE1_TBU0_PMU_INTR_IRQ_ID 196
`define NPU_CORE1_TBU0_RAS_INTR_IRQ_ID 197
`define NPU_CORE0_TBU1_PMU_INTR_IRQ_ID 198
`define NPU_CORE0_TBU1_RAS_INTR_IRQ_ID 199
`define NPU_CORE0_TBU0_PMU_INTR_IRQ_ID 200
`define NPU_CORE0_TBU0_RAS_INTR_IRQ_ID 201
`define MEDIA_TBU_PMU_INTR_IRQ_ID 213//
`define MEDIA_TBU_RAS_INTR_IRQ_ID 214//
`define TCU_GLOBAL_INTR_S_IRQ_ID 215//
`define TCU_PRI_Q_INTR_NS_IRQ_ID 216//
`define TCU_GLOBAL_INTR_NS_IRQ_ID 217
`define TCU_CMD_SYNC_INTR_NS_IRQ_ID 218//
`define TCU_CMD_SYNC_INTR_S_IRQ_ID 219//
`define TCU_EVENT_Q_INTR_NS_IRQ_ID 220//
`define TCU_EVENT_Q_INTR_S_IRQ_ID 221//
`define TCU_PMU_INTR_IRQ_ID 222//
`define TCU_RAS_INTR_IRQ_ID 223//
`define BARRIER_INTR_IRQ_ID 224//
`define NPU_INTR3_0_IRQ_ID 225//
`define NPU_INTR3_1_IRQ_ID 226//
`define NPU_INTR3_2_IRQ_ID 227//
`define NPU_INTR3_3_IRQ_ID 228//
`define NPU_INTR3_4_IRQ_ID 229//
`define NPU_INTR3_5_IRQ_ID 230//
`define NPU_INTR3_6_IRQ_ID 231//
`define NPU_INTR3_7_IRQ_ID 232//
`define NPU_INTR2_0_IRQ_ID 233//
`define NPU_INTR2_1_IRQ_ID 234//
`define NPU_INTR2_2_IRQ_ID 235//
`define NPU_INTR2_3_IRQ_ID 236//
`define NPU_INTR2_4_IRQ_ID 237//
`define NPU_INTR2_5_IRQ_ID 238//
`define NPU_INTR2_6_IRQ_ID 239//
`define NPU_INTR2_7_IRQ_ID 240//
`define NPU_INTR1_0_IRQ_ID 241//
`define NPU_INTR1_1_IRQ_ID 242//
`define NPU_INTR1_2_IRQ_ID 243//
`define NPU_INTR1_3_IRQ_ID 244//
`define NPU_INTR1_4_IRQ_ID 245//
`define NPU_INTR1_5_IRQ_ID 246//
`define NPU_INTR1_6_IRQ_ID 247//
`define NPU_INTR1_7_IRQ_ID 248//
`define NPU_INTR0_0_IRQ_ID 249//
`define NPU_INTR0_1_IRQ_ID 250//
`define NPU_INTR0_2_IRQ_ID 251//
`define NPU_INTR0_3_IRQ_ID 252//
`define NPU_INTR0_4_IRQ_ID 253//
`define NPU_INTR0_5_IRQ_ID 254//
`define NPU_INTR0_6_IRQ_ID 255//
`define NPU_INTR0_7_IRQ_ID 256//
`define NPU_WDT_INTR3_IRQ_ID 257//
`define NPU_WDT_INTR2_IRQ_ID 258//
`define NPU_WDT_INTR1_IRQ_ID 259//
`define NPU_WDT_INTR0_IRQ_ID 260//
`define MCU_WDT_INTR_IRQ_ID 261//

`endif