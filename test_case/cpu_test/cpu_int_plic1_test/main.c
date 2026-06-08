// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

volatile int  int_flg = 0;
volatile int  irq_num = 0;

void mcu_mailbox_intr7_handler        (void) {cpu_info("[INT]mcu_mailbox_intr7_handler        hit\n"); send_label(Ext_MCU_MAILBOX_INTR7_IRQn        ); int_flg++;}
void mcu_mailbox_intr6_handler        (void) {cpu_info("[INT]mcu_mailbox_intr6_handler        hit\n"); send_label(Ext_MCU_MAILBOX_INTR6_IRQn        ); int_flg++;}
void mcu_mailbox_intr5_handler        (void) {cpu_info("[INT]mcu_mailbox_intr5_handler        hit\n"); send_label(Ext_MCU_MAILBOX_INTR5_IRQn        ); int_flg++;}
void mcu_mailbox_intr4_handler        (void) {cpu_info("[INT]mcu_mailbox_intr4_handler        hit\n"); send_label(Ext_MCU_MAILBOX_INTR4_IRQn        ); int_flg++;}
void mcu_mailbox_intr3_handler        (void) {cpu_info("[INT]mcu_mailbox_intr3_handler        hit\n"); send_label(Ext_MCU_MAILBOX_INTR3_IRQn        ); int_flg++;}
void mcu_mailbox_intr2_handler        (void) {cpu_info("[INT]mcu_mailbox_intr2_handler        hit\n"); send_label(Ext_MCU_MAILBOX_INTR2_IRQn        ); int_flg++;}
void mcu_mailbox_intr1_handler        (void) {cpu_info("[INT]mcu_mailbox_intr1_handler        hit\n"); send_label(Ext_MCU_MAILBOX_INTR1_IRQn        ); int_flg++;}
void mcu_mailbox_intr0_handler        (void) {cpu_info("[INT]mcu_mailbox_intr0_handler        hit\n"); send_label(Ext_MCU_MAILBOX_INTR0_IRQn        ); int_flg++;}
void mcu_gpio1_intr7_handler          (void) {cpu_info("[INT]mcu_gpio1_intr7_handler          hit\n"); send_label(Ext_MCU_GPIO1_INTR7_IRQn          ); int_flg++;}
void mcu_gpio1_intr6_handler          (void) {cpu_info("[INT]mcu_gpio1_intr6_handler          hit\n"); send_label(Ext_MCU_GPIO1_INTR6_IRQn          ); int_flg++;}
void mcu_gpio1_intr5_handler          (void) {cpu_info("[INT]mcu_gpio1_intr5_handler          hit\n"); send_label(Ext_MCU_GPIO1_INTR5_IRQn          ); int_flg++;}
void mcu_gpio1_intr4_handler          (void) {cpu_info("[INT]mcu_gpio1_intr4_handler          hit\n"); send_label(Ext_MCU_GPIO1_INTR4_IRQn          ); int_flg++;}
void mcu_gpio1_intr3_handler          (void) {cpu_info("[INT]mcu_gpio1_intr3_handler          hit\n"); send_label(Ext_MCU_GPIO1_INTR3_IRQn          ); int_flg++;}
void mcu_gpio1_intr2_handler          (void) {cpu_info("[INT]mcu_gpio1_intr2_handler          hit\n"); send_label(Ext_MCU_GPIO1_INTR2_IRQn          ); int_flg++;}
void mcu_gpio1_intr1_handler          (void) {cpu_info("[INT]mcu_gpio1_intr1_handler          hit\n"); send_label(Ext_MCU_GPIO1_INTR1_IRQn          ); int_flg++;}
void mcu_gpio1_intr0_handler          (void) {cpu_info("[INT]mcu_gpio1_intr0_handler          hit\n"); send_label(Ext_MCU_GPIO1_INTR0_IRQn          ); int_flg++;}

void aon_gpio7_intr_handler           (void) {cpu_info("[INT]aon_gpio7_intr_handler           hit\n"); send_label(Ext_AON_GPIO7_INTR_IRQn           ); int_flg++;}
void aon_gpio6_intr_handler           (void) {cpu_info("[INT]aon_gpio6_intr_handler           hit\n"); send_label(Ext_AON_GPIO6_INTR_IRQn           ); int_flg++;}
void aon_gpio5_intr_handler           (void) {cpu_info("[INT]aon_gpio5_intr_handler           hit\n"); send_label(Ext_AON_GPIO5_INTR_IRQn           ); int_flg++;}
void aon_gpio4_intr_handler           (void) {cpu_info("[INT]aon_gpio4_intr_handler           hit\n"); send_label(Ext_AON_GPIO4_INTR_IRQn           ); int_flg++;}
void aon_gpio3_intr_handler           (void) {cpu_info("[INT]aon_gpio3_intr_handler           hit\n"); send_label(Ext_AON_GPIO3_INTR_IRQn           ); int_flg++;}
void aon_gpio2_intr_handler           (void) {cpu_info("[INT]aon_gpio2_intr_handler           hit\n"); send_label(Ext_AON_GPIO2_INTR_IRQn           ); int_flg++;}
void aon_gpio1_intr_handler           (void) {cpu_info("[INT]aon_gpio1_intr_handler           hit\n"); send_label(Ext_AON_GPIO1_INTR_IRQn           ); int_flg++;}
void aon_gpio0_intr_handler           (void) {cpu_info("[INT]aon_gpio0_intr_handler           hit\n"); send_label(Ext_AON_GPIO0_INTR_IRQn           ); int_flg++;}
void aon_i2c1_intr_handler            (void) {cpu_info("[INT]aon_i2c1_intr_handler            hit\n"); send_label(Ext_AON_I2C1_INTR_IRQn            ); int_flg++;}
void aon_i2c0_intr_handler            (void) {cpu_info("[INT]aon_i2c0_intr_handler            hit\n"); send_label(Ext_AON_I2C0_INTR_IRQn            ); int_flg++;}
void aon_rtc_intr_handler             (void) {cpu_info("[INT]aon_rtc_intr_handler             hit\n"); send_label(Ext_AON_RTC_INTR_IRQn             ); int_flg++;}
void aon_pvtc_intr_handler            (void) {cpu_info("[INT]aon_pvtc_intr_handler            hit\n"); send_label(Ext_AON_PVTC_INTR_IRQn            ); int_flg++;}
void hsm_mailbox_host_intr_handler    (void) {cpu_info("[INT]hsm_mailbox_host_intr_handler    hit\n"); send_label(Ext_HSM_MAILBOX_HOST_0_INTR_IRQn  ); int_flg++;}
void hsm_mailbox_intr_handler         (void) {cpu_info("[INT]hsm_mailbox_intr_handler         hit\n"); send_label(Ext_HSM_MAILBOX_INTERNEAL_INTR_IRQn ); int_flg++;}
void hsm_trng0_intr_handler           (void) {cpu_info("[INT]hsm_trng0_intr_handler           hit\n"); send_label(Ext_HSM_TRNG0_TRNG_INTR_IRQn      ); int_flg++;}
void hsm_hash0_intr_handler           (void) {cpu_info("[INT]hsm_hash0_intr_handler           hit\n"); send_label(Ext_HSM_HASH0_INTR_IRQn           ); int_flg++;}
void hsm_cryp0_intr_handler           (void) {cpu_info("[INT]hsm_cryp0_intr_handler           hit\n"); send_label(Ext_HSM_CRYP0_INTR_IRQn           ); int_flg++;}
void hsm_acryp0_intr_handler          (void) {cpu_info("[INT]hsm_acryp0_intr_handler          hit\n"); send_label(Ext_HSM_ACRYP0_INTR_IRQn          ); int_flg++;}
void hsm_rtc0_rtc_intr_handler        (void) {cpu_info("[INT]hsm_rtc0_rtc_intr_handler        hit\n"); send_label(Ext_HSM_RTC0_RTC_INTR_IRQn        ); int_flg++;}
void hsm_basic_timer0_bsc_tim_intr_handler  (void) {cpu_info("[INT]hsm_basic_timer0_bsc_tim_intr_handler  hit\n"); send_label(Ext_HSM_BASIC_TIMER0_BSC_TIM_INTR_IRQn ); int_flg++;}
void hsm_usart0_uart_intr_handler     (void) {cpu_info("[INT]hsm_usart0_uart_intr_handler     hit\n"); send_label(Ext_HSM_USART0_UART_INTR_IRQn     ); int_flg++;}
void hsm_udma0_udma_intr_handler      (void) {cpu_info("[INT]hsm_udma0_udma_intr_handler      hit\n"); send_label(Ext_HSM_UDMA0_UDMA_INTR_IRQn      ); int_flg++;}
void mcu_can1_intr_handler            (void) {cpu_info("[INT]mcu_can1_intr_handler            hit\n"); send_label(Ext_MCU_CAN1_INTR_IRQn            ); int_flg++;}
void mcu_can0_intr_handler            (void) {cpu_info("[INT]mcu_can0_intr_handler            hit\n"); send_label(Ext_MCU_CAN0_INTR_IRQn            ); int_flg++;}
void mcu_atb2axi_intr_handler         (void) {cpu_info("[INT]mcu_atb2axi_intr_handler         hit\n"); send_label(Ext_MCU_ATB2AXI_INTR_IRQn         ); int_flg++;}
void mcu_sdio_intr_handler            (void) {cpu_info("[INT]mcu_sdio_intr_handler            hit\n"); send_label(Ext_MCU_SDIO_INTR_IRQn            ); int_flg++;}
void mcu_i2s0_intr_handler            (void) {cpu_info("[INT]mcu_i2s0_intr_handler            hit\n"); send_label(Ext_MCU_I2S0_INTR_IRQn            ); int_flg++;}
void mcu_i3c0_intr_handler            (void) {cpu_info("[INT]mcu_i3c0_intr_handler            hit\n"); send_label(Ext_MCU_I3C0_INTR_IRQn            ); int_flg++;}
void mcu_xspi0_intr_handler           (void) {cpu_info("[INT]mcu_xspi0_intr_handler           hit\n"); send_label(Ext_MCU_XSPI0_INTR_IRQn           ); int_flg++;}
void mcu_spi0_intr_handler            (void) {cpu_info("[INT]mcu_spi0_intr_handler            hit\n"); send_label(Ext_MCU_SPI0_INTR_IRQn            ); int_flg++;}
void mcu_i2c1_intr_handler            (void) {cpu_info("[INT]mcu_i2c1_intr_handler            hit\n"); send_label(Ext_MCU_I2C1_INTR_IRQn            ); int_flg++;}
void mcu_i2c0_intr_handler            (void) {cpu_info("[INT]mcu_i2c0_intr_handler            hit\n"); send_label(Ext_MCU_I2C0_INTR_IRQn            ); int_flg++;}
void mcu_uart1_intr_handler           (void) {cpu_info("[INT]mcu_uart1_intr_handler           hit\n"); send_label(Ext_MCU_UART1_INTR_IRQn           ); int_flg++;}
void mcu_uart0_intr_handler           (void) {cpu_info("[INT]mcu_uart0_intr_handler           hit\n"); send_label(Ext_MCU_UART0_INTR_IRQn           ); int_flg++;}
void mcu_noc_intr_handler             (void) {cpu_info("[INT]mcu_noc_intr_handler             hit\n"); send_label(Ext_MCU_NOC_INTR_IRQn             ); int_flg++;}
void hs_data_noc_intr_handler         (void) {cpu_info("[INT]hs_data_noc_intr_handler         hit\n"); send_label(Ext_HS_DATA_NOC_INTR_IRQn         ); int_flg++;}
void hs_reg_noc_intr_handler          (void) {cpu_info("[INT]hs_reg_noc_intr_handler          hit\n"); send_label(Ext_HS_REG_NOC_INTR_IRQn          ); int_flg++;}
void top_crg_ipll_intr_handler        (void) {cpu_info("[INT]top_crg_ipll_intr_handler        hit\n"); send_label(Ext_TOP_CRG_PLL_INTR_IRQn         ); int_flg++;}
void soc_noc_intr_handler             (void) {cpu_info("[INT]soc_noc_intr_handler             hit\n"); send_label(Ext_SOC_NOC_INTR_IRQn             ); int_flg++;}
void media_subgpu_syserr_intr_handler (void) {cpu_info("[INT]media_subgpu_syserr_intr_handler hit\n"); send_label(Ext_MEDIA_SUB_GPU_SYSERR_INTR_IRQn); int_flg++;}
void aon_crg_intr_handler             (void) {cpu_info("[INT]aon_crg_intr_handler             hit\n"); send_label(Ext_AON_CRG_INTR_IRQn             ); int_flg++;}
void t2_uee_pmu_intr_handler          (void) {cpu_info("[INT]t2_uee_pmu_intr_handler          hit\n"); send_label(Ext_T2_UEE_PMU_INTR_IRQn          ); 
            scu_clear_intr_raw(1u << 11);
int_flg++;}
void hs_usb_host_sys_err_intr_handler (void) {cpu_info("[INT]hs_usb_host_sys_err_intr_handler hit\n"); send_label(Ext_HS_USB_HOST_SYS_ERR_INTR_IRQn ); int_flg++;}
void hs_dma_intr_handler              (void) {cpu_info("[INT]hs_dma_intr_handler              hit\n"); send_label(Ext_HS_DMA_INTR_IRQn              ); int_flg++;}
void hs_pricess01_atu_intr_handler    (void) {cpu_info("[INT]hs_pricess01_atu_intr_handler    hit\n"); send_label(Ext_HS_PCIESS01_ATU_INTR_IRQn     ); int_flg++;}
void hs_pricess01_err_intr_handler    (void) {cpu_info("[INT]hs_pricess01_err_intr_handler    hit\n"); send_label(Ext_HS_PCIESS01_ERR_INTR_IRQn     ); int_flg++;}
void hs_pricess01_dma_intr_handler    (void) {cpu_info("[INT]hs_pricess01_dma_intr_handler    hit\n"); send_label(Ext_HS_PCIESS01_DMA_INTR_IRQn     ); int_flg++;}
void hs_pricess00_atu_intr_handler    (void) {cpu_info("[INT]hs_pricess00_atu_intr_handler    hit\n"); send_label(Ext_HS_PCIESS00_ATU_INTR_IRQn     ); int_flg++;}
void hs_pricess00_err_intr_handler    (void) {cpu_info("[INT]hs_pricess00_err_intr_handler    hit\n"); send_label(Ext_HS_PCIESS00_ERR_INTR_IRQn     ); int_flg++;}
void hs_pricess00_dma_intr_handler    (void) {cpu_info("[INT]hs_pricess00_dma_intr_handler    hit\n"); send_label(Ext_HS_PCIESS00_DMA_INTR_IRQn     ); int_flg++;}
void mcu_dma_intr_handler             (void) {cpu_info("[INT]mcu_dma_intr_handler             hit\n"); send_label(Ext_MCU_DMA_INTR_IRQn             ); int_flg++;}

void tbu_pmu_evt_wakeup_intr_handler  (void) {cpu_info("[INT]tbu_pmu_evt_wakeup_intr_handler  hit\n"); send_label(Ext_PMU_EVT_WAKEUP_INTR_IRQn      ); int_flg++;}
void npu_core3_tbu1_pmu_intr_handler  (void) {cpu_info("[INT]npu_core3_tbu1_pmu_intr_handler  hit\n"); send_label(Ext_NPU_CORE3_TBU1_PMU_INTR_IRQn  ); int_flg++;}
void npu_core3_tbu1_ras_intr_handler  (void) {cpu_info("[INT]npu_core3_tbu1_ras_intr_handler  hit\n"); send_label(Ext_NPU_CORE3_TBU1_RAS_INTR_IRQn  ); int_flg++;}
void npu_core3_tbu0_pmu_intr_handler  (void) {cpu_info("[INT]npu_core3_tbu0_pmu_intr_handler  hit\n"); send_label(Ext_NPU_CORE3_TBU0_PMU_INTR_IRQn  ); int_flg++;}
void npu_core3_tbu0_ras_intr_handler  (void) {cpu_info("[INT]npu_core3_tbu0_ras_intr_handler  hit\n"); send_label(Ext_NPU_CORE3_TBU0_RAS_INTR_IRQn  ); int_flg++;}
void npu_core2_tbu1_pmu_intr_handler  (void) {cpu_info("[INT]npu_core2_tbu1_pmu_intr_handler  hit\n"); send_label(Ext_NPU_CORE2_TBU1_PMU_INTR_IRQn  ); int_flg++;}
void npu_core2_tbu1_ras_intr_handler  (void) {cpu_info("[INT]npu_core2_tbu1_ras_intr_handler  hit\n"); send_label(Ext_NPU_CORE2_TBU1_RAS_INTR_IRQn  ); int_flg++;}
void npu_core2_tbu0_pmu_intr_handler  (void) {cpu_info("[INT]npu_core2_tbu0_pmu_intr_handler  hit\n"); send_label(Ext_NPU_CORE2_TBU0_PMU_INTR_IRQn  ); int_flg++;}
void npu_core2_tbu0_ras_intr_handler  (void) {cpu_info("[INT]npu_core2_tbu0_ras_intr_handler  hit\n"); send_label(Ext_NPU_CORE2_TBU0_RAS_INTR_IRQn  ); int_flg++;}
void npu_core1_tbu1_pmu_intr_handler  (void) {cpu_info("[INT]npu_core1_tbu1_pmu_intr_handler  hit\n"); send_label(Ext_NPU_CORE1_TBU1_PMU_INTR_IRQn  ); int_flg++;}
void npu_core1_tbu1_ras_intr_handler  (void) {cpu_info("[INT]npu_core1_tbu1_ras_intr_handler  hit\n"); send_label(Ext_NPU_CORE1_TBU1_RAS_INTR_IRQn  ); int_flg++;}
void npu_core1_tbu0_pmu_intr_handler  (void) {cpu_info("[INT]npu_core1_tbu0_pmu_intr_handler  hit\n"); send_label(Ext_NPU_CORE1_TBU0_PMU_INTR_IRQn  ); int_flg++;}
void npu_core1_tbu0_ras_intr_handler  (void) {cpu_info("[INT]npu_core1_tbu0_ras_intr_handler  hit\n"); send_label(Ext_NPU_CORE1_TBU0_RAS_INTR_IRQn  ); int_flg++;}
void npu_core0_tbu1_pmu_intr_handler  (void) {cpu_info("[INT]npu_core0_tbu1_pmu_intr_handler  hit\n"); send_label(Ext_NPU_CORE0_TBU1_PMU_INTR_IRQn  ); int_flg++;}
void npu_core0_tbu1_ras_intr_handler  (void) {cpu_info("[INT]npu_core0_tbu1_ras_intr_handler  hit\n"); send_label(Ext_NPU_CORE0_TBU1_RAS_INTR_IRQn  ); int_flg++;}
void npu_core0_tbu0_pmu_intr_handler  (void) {cpu_info("[INT]npu_core0_tbu0_pmu_intr_handler  hit\n"); send_label(Ext_NPU_CORE0_TBU0_PMU_INTR_IRQn  ); int_flg++;}
void npu_core0_tbu0_ras_intr_handler  (void) {cpu_info("[INT]npu_core0_tbu0_ras_intr_handler  hit\n"); send_label(Ext_NPU_CORE0_TBU0_RAS_INTR_IRQn  ); int_flg++;}
void core3_tbu1_pmu_intr_handler      (void) {cpu_info("[INT]core3_tbu1_pmu_intr_handler      hit\n"); send_label(Ext_NPU_CORE3_TBU1_PMU_INTR_IRQn  ); int_flg++;}
void core3_tbu1_ras_intr_handler      (void) {cpu_info("[INT]core3_tbu1_ras_intr_handler      hit\n"); send_label(Ext_NPU_CORE3_TBU1_RAS_INTR_IRQn  ); int_flg++;}
void core3_tbu0_pmu_intr_handler      (void) {cpu_info("[INT]core3_tbu0_pmu_intr_handler      hit\n"); send_label(Ext_NPU_CORE3_TBU0_PMU_INTR_IRQn  ); int_flg++;}
void core3_tbu0_ras_intr_handler      (void) {cpu_info("[INT]core3_tbu0_ras_intr_handler      hit\n"); send_label(Ext_NPU_CORE3_TBU0_RAS_INTR_IRQn  ); int_flg++;}
void core2_tbu1_pmu_intr_handler      (void) {cpu_info("[INT]core2_tbu1_pmu_intr_handler      hit\n"); send_label(Ext_NPU_CORE2_TBU1_PMU_INTR_IRQn  ); int_flg++;}
void core2_tbu1_ras_intr_handler      (void) {cpu_info("[INT]core2_tbu1_ras_intr_handler      hit\n"); send_label(Ext_NPU_CORE2_TBU1_RAS_INTR_IRQn  ); int_flg++;}
void core2_tbu0_pmu_intr_handler      (void) {cpu_info("[INT]core2_tbu0_pmu_intr_handler      hit\n"); send_label(Ext_NPU_CORE2_TBU0_PMU_INTR_IRQn  ); int_flg++;}
void core2_tbu0_ras_intr_handler      (void) {cpu_info("[INT]core2_tbu0_ras_intr_handler      hit\n"); send_label(Ext_NPU_CORE2_TBU0_RAS_INTR_IRQn  ); int_flg++;}
void core1_tbu1_pmu_intr_handler      (void) {cpu_info("[INT]core1_tbu1_pmu_intr_handler      hit\n"); send_label(Ext_NPU_CORE1_TBU1_PMU_INTR_IRQn  ); int_flg++;}
void core1_tbu1_ras_intr_handler      (void) {cpu_info("[INT]core1_tbu1_ras_intr_handler      hit\n"); send_label(Ext_NPU_CORE1_TBU1_RAS_INTR_IRQn  ); int_flg++;}
void core1_tbu0_pmu_intr_handler      (void) {cpu_info("[INT]core1_tbu0_pmu_intr_handler      hit\n"); send_label(Ext_NPU_CORE1_TBU0_PMU_INTR_IRQn  ); int_flg++;}
void core1_tbu0_ras_intr_handler      (void) {cpu_info("[INT]core1_tbu0_ras_intr_handler      hit\n"); send_label(Ext_NPU_CORE1_TBU0_RAS_INTR_IRQn  ); int_flg++;}
void core0_tbu1_pmu_intr_handler      (void) {cpu_info("[INT]core0_tbu1_pmu_intr_handler      hit\n"); send_label(Ext_NPU_CORE0_TBU1_PMU_INTR_IRQn  ); int_flg++;}
void core0_tbu1_ras_intr_handler      (void) {cpu_info("[INT]core0_tbu1_ras_intr_handler      hit\n"); send_label(Ext_NPU_CORE0_TBU1_RAS_INTR_IRQn  ); int_flg++;}
void core0_tbu0_pmu_intr_handler      (void) {cpu_info("[INT]core0_tbu0_pmu_intr_handler      hit\n"); send_label(Ext_NPU_CORE0_TBU0_PMU_INTR_IRQn  ); int_flg++;}
void core0_tbu0_ras_intr_handler      (void) {cpu_info("[INT]core0_tbu0_ras_intr_handler      hit\n"); send_label(Ext_NPU_CORE0_TBU0_RAS_INTR_IRQn  ); int_flg++;}

void media_tbu_pmu_intr_handler       (void) {cpu_info("[INT]media_tbu_pmu_intr               hit\n"); send_label(Ext_MEDIA_TBU_PMU_INTR_IRQn       );
            scu_clear_intr_raw(1u << 17);
 int_flg++;}//1209
void media_tbu_ras_intr_handler       (void) {cpu_info("[INT]media_tbu_ras_intr               hit\n"); send_label(Ext_MEDIA_TBU_RAS_INTR_IRQn       ); 
            scu_clear_intr_raw(1u << 18);
int_flg++;}//1209
void tcu_global_intr_s_handler        (void) {cpu_info("[INT]tcu_global_intr_s_handler        hit\n"); send_label(Ext_TCU_GLOBAL_INTR_S_IRQn        );
            scu_clear_intr_raw(1u << 0);
int_flg++;}//1209
void tcu_pri_q_intr_ns_handler        (void) {cpu_info("[INT]tcu_pri_q_intr_ns_handler        hit\n"); send_label(Ext_TCU_PRI_Q_INTR_NS_IRQn        ); 
            scu_clear_intr_raw(1u << 1);
int_flg++;}//1209

void tcu_global_intr_ns_handler       (void) {cpu_info("[INT]tcu_global_intr_ns_handler       hit\n"); send_label(Ext_TCU_GLOBAL_INTR_NS_IRQn       );
            scu_clear_intr_raw(1u << 2);
 int_flg++;}
void tcu_cmd_sync_intr_ns_handler     (void) {cpu_info("[INT]tcu_cmd_sync_intr_ns_handler     hit\n"); send_label(Ext_TCU_CMD_SYNC_INTR_NS_IRQn     );
            scu_clear_intr_raw(1u << 3);
 int_flg++;}
void tcu_cmd_sync_intr_s_handler      (void) {cpu_info("[INT]tcu_cmd_sync_intr_s_handler      hit\n"); send_label(Ext_TCU_CMD_SYNC_INTR_S_IRQn      );
            scu_clear_intr_raw(1u << 4);
 int_flg++;}
void tcu_event_q_intr_ns_handler      (void) {cpu_info("[INT]tcu_event_q_intr_ns_handler      hit\n"); send_label(Ext_TCU_EVENT_Q_INTR_NS_IRQn      );
            scu_clear_intr_raw(1u << 5);
 int_flg++;}
void tcu_event_q_intr_s_handler       (void) {cpu_info("[INT]tcu_event_q_intr_s_handler       hit\n"); send_label(Ext_TCU_EVENT_Q_INTR_S_IRQn       );
            scu_clear_intr_raw(1u << 6);
 int_flg++;}
void tcu_pmu_intr_handler             (void) {cpu_info("[INT]tcu_pmu_intr_handler             hit\n"); send_label(Ext_TCU_PMU_INTR_IRQn             );
            scu_clear_intr_raw(1u << 7);
 int_flg++;}
void tcu_ras_intr_handler             (void) {cpu_info("[INT]tcu_ras_intr_handler             hit\n"); send_label(Ext_TCU_RAS_INTR_0_IRQn           );
            scu_clear_intr_raw(1u << 8);
 int_flg++;}
void barrier_intr_handler             (void) {cpu_info("[INT]barrier_intr_handler             hit\n"); send_label(Ext_BARRIER_INTR_0_IRQn           ); int_flg++;}
void npu_intr3_0_handler              (void) {cpu_info("[INT]npu_intr3_0_handler              hit\n"); send_label(Ext_NPU_INTR3_0_IRQn              ); int_flg++;}
void npu_intr3_1_handler              (void) {cpu_info("[INT]npu_intr3_1_handler              hit\n"); send_label(Ext_NPU_INTR3_1_IRQn              ); int_flg++;}
void npu_intr3_2_handler              (void) {cpu_info("[INT]npu_intr3_2_handler              hit\n"); send_label(Ext_NPU_INTR3_2_IRQn              ); int_flg++;}
void npu_intr3_3_handler              (void) {cpu_info("[INT]npu_intr3_3_handler              hit\n"); send_label(Ext_NPU_INTR3_3_IRQn              ); int_flg++;}
void npu_intr3_4_handler              (void) {cpu_info("[INT]npu_intr3_4_handler              hit\n"); send_label(Ext_NPU_INTR3_4_IRQn              ); int_flg++;}
void npu_intr3_5_handler              (void) {cpu_info("[INT]npu_intr3_5_handler              hit\n"); send_label(Ext_NPU_INTR3_5_IRQn              ); int_flg++;}
void npu_intr3_6_handler              (void) {cpu_info("[INT]npu_intr3_6_handler              hit\n"); send_label(Ext_NPU_INTR3_6_IRQn              ); int_flg++;}
void npu_intr3_7_handler              (void) {cpu_info("[INT]npu_intr3_7_handler              hit\n"); send_label(Ext_NPU_INTR3_7_IRQn              ); int_flg++;}
void npu_intr2_0_handler              (void) {cpu_info("[INT]npu_intr2_0_handler              hit\n"); send_label(Ext_NPU_INTR2_0_IRQn              ); int_flg++;}
void npu_intr2_1_handler              (void) {cpu_info("[INT]npu_intr2_1_handler              hit\n"); send_label(Ext_NPU_INTR2_1_IRQn              ); int_flg++;}
void npu_intr2_2_handler              (void) {cpu_info("[INT]npu_intr2_2_handler              hit\n"); send_label(Ext_NPU_INTR2_2_IRQn              ); int_flg++;}
void npu_intr2_3_handler              (void) {cpu_info("[INT]npu_intr2_3_handler              hit\n"); send_label(Ext_NPU_INTR2_3_IRQn              ); int_flg++;}
void npu_intr2_4_handler              (void) {cpu_info("[INT]npu_intr2_4_handler              hit\n"); send_label(Ext_NPU_INTR2_4_IRQn              ); int_flg++;}
void npu_intr2_5_handler              (void) {cpu_info("[INT]npu_intr2_5_handler              hit\n"); send_label(Ext_NPU_INTR2_5_IRQn              ); int_flg++;}
void npu_intr2_6_handler              (void) {cpu_info("[INT]npu_intr2_6_handler              hit\n"); send_label(Ext_NPU_INTR2_6_IRQn              ); int_flg++;}
void npu_intr2_7_handler              (void) {cpu_info("[INT]npu_intr2_7_handler              hit\n"); send_label(Ext_NPU_INTR2_7_IRQn              ); int_flg++;}
void npu_intr1_0_handler              (void) {cpu_info("[INT]npu_intr1_0_handler              hit\n"); send_label(Ext_NPU_INTR1_0_IRQn              ); int_flg++;}
void npu_intr1_1_handler              (void) {cpu_info("[INT]npu_intr1_1_handler              hit\n"); send_label(Ext_NPU_INTR1_1_IRQn              ); int_flg++;}
void npu_intr1_2_handler              (void) {cpu_info("[INT]npu_intr1_2_handler              hit\n"); send_label(Ext_NPU_INTR1_2_IRQn              ); int_flg++;}
void npu_intr1_3_handler              (void) {cpu_info("[INT]npu_intr1_3_handler              hit\n"); send_label(Ext_NPU_INTR1_3_IRQn              ); int_flg++;}
void npu_intr1_4_handler              (void) {cpu_info("[INT]npu_intr1_4_handler              hit\n"); send_label(Ext_NPU_INTR1_4_IRQn              ); int_flg++;}
void npu_intr1_5_handler              (void) {cpu_info("[INT]npu_intr1_5_handler              hit\n"); send_label(Ext_NPU_INTR1_5_IRQn              ); int_flg++;}
void npu_intr1_6_handler              (void) {cpu_info("[INT]npu_intr1_6_handler              hit\n"); send_label(Ext_NPU_INTR1_6_IRQn              ); int_flg++;}
void npu_intr1_7_handler              (void) {cpu_info("[INT]npu_intr1_7_handler              hit\n"); send_label(Ext_NPU_INTR1_7_IRQn              ); int_flg++;}
void npu_intr0_0_handler              (void) {cpu_info("[INT]npu_intr0_0_handler              hit\n"); send_label(Ext_NPU_INTR0_0_IRQn              ); int_flg++;}
void npu_intr0_1_handler              (void) {cpu_info("[INT]npu_intr0_1_handler              hit\n"); send_label(Ext_NPU_INTR0_1_IRQn              ); int_flg++;}
void npu_intr0_2_handler              (void) {cpu_info("[INT]npu_intr0_2_handler              hit\n"); send_label(Ext_NPU_INTR0_2_IRQn              ); int_flg++;}
void npu_intr0_3_handler              (void) {cpu_info("[INT]npu_intr0_3_handler              hit\n"); send_label(Ext_NPU_INTR0_3_IRQn              ); int_flg++;}
void npu_intr0_4_handler              (void) {cpu_info("[INT]npu_intr0_4_handler              hit\n"); send_label(Ext_NPU_INTR0_4_IRQn              ); int_flg++;}
void npu_intr0_5_handler              (void) {cpu_info("[INT]npu_intr0_5_handler              hit\n"); send_label(Ext_NPU_INTR0_5_IRQn              ); int_flg++;}
void npu_intr0_6_handler              (void) {cpu_info("[INT]npu_intr0_6_handler              hit\n"); send_label(Ext_NPU_INTR0_6_IRQn              ); int_flg++;}
void npu_intr0_7_handler              (void) {cpu_info("[INT]npu_intr0_7_handler              hit\n"); send_label(Ext_NPU_INTR0_7_IRQn              ); int_flg++;}
void npu_wdt_intr3_handler            (void) {cpu_info("[INT]npu_wdt_intr3_handler            hit\n"); send_label(Ext_NPU_WDT_INTR3_IRQn            ); int_flg++;}
void npu_wdt_intr2_handler            (void) {cpu_info("[INT]npu_wdt_intr2_handler            hit\n"); send_label(Ext_NPU_WDT_INTR2_IRQn            ); int_flg++;}
void npu_wdt_intr1_handler            (void) {cpu_info("[INT]npu_wdt_intr1_handler            hit\n"); send_label(Ext_NPU_WDT_INTR1_IRQn            ); int_flg++;}
void npu_wdt_intr0_handler            (void) {cpu_info("[INT]npu_wdt_intr0_handler            hit\n"); send_label(Ext_NPU_WDT_INTR0_IRQn            ); int_flg++;}
void mcu_wdt_intr_handler             (void) {cpu_info("[INT]mcu_wdt_intr_handler             hit\n"); send_label(Ext_MCU_WDT_INTR_IRQn             ); int_flg++;
    irq_num = Ext_MCU_WDT_INTR_IRQn;
}



int main(void)
{
    uint32_t returnCode;
    CSR_MCFGINFO_Type mcfg;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    // Do PLIC present check via CSR MCFGINFO register
    // Just to confirm whether PLIC really present
    mcfg.d = __RV_CSR_READ(CSR_MCFG_INFO);
    if (mcfg.b.plic == 0) {
        cpu_error("PLIC is not present in this CPU, please check!\n");
        return 0;
    }

    // Initialize interrupt mode to clint/plic mode
    PLIC_Interrupt_Init();

    // inital timer interrupt as non-vector interrupt

    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR7_IRQn               ,    1, (void*)mcu_mailbox_intr7_handler            );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR6_IRQn               ,    1, (void*)mcu_mailbox_intr6_handler            );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR5_IRQn               ,    1, (void*)mcu_mailbox_intr5_handler            );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR4_IRQn               ,    1, (void*)mcu_mailbox_intr4_handler            );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR3_IRQn               ,    1, (void*)mcu_mailbox_intr3_handler            );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR2_IRQn               ,    1, (void*)mcu_mailbox_intr2_handler            );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR1_IRQn               ,    1, (void*)mcu_mailbox_intr1_handler            );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR0_IRQn               ,    1, (void*)mcu_mailbox_intr0_handler            );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO1_INTR7_IRQn                 ,    1, (void*)mcu_gpio1_intr7_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO1_INTR6_IRQn                 ,    1, (void*)mcu_gpio1_intr6_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO1_INTR5_IRQn                 ,    1, (void*)mcu_gpio1_intr5_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO1_INTR4_IRQn                 ,    1, (void*)mcu_gpio1_intr4_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO1_INTR3_IRQn                 ,    1, (void*)mcu_gpio1_intr3_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO1_INTR2_IRQn                 ,    1, (void*)mcu_gpio1_intr2_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO1_INTR1_IRQn                 ,    1, (void*)mcu_gpio1_intr1_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO1_INTR0_IRQn                 ,    1, (void*)mcu_gpio1_intr0_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO7_INTR_IRQn                  ,    1, (void*)aon_gpio7_intr_handler               );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO6_INTR_IRQn                  ,    1, (void*)aon_gpio6_intr_handler               );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO5_INTR_IRQn                  ,    1, (void*)aon_gpio5_intr_handler               );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO4_INTR_IRQn                  ,    1, (void*)aon_gpio4_intr_handler               );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO3_INTR_IRQn                  ,    1, (void*)aon_gpio3_intr_handler               );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO2_INTR_IRQn                  ,    1, (void*)aon_gpio2_intr_handler               );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO1_INTR_IRQn                  ,    1, (void*)aon_gpio1_intr_handler               );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO0_INTR_IRQn                  ,    1, (void*)aon_gpio0_intr_handler               );
    returnCode = PLIC_Register_IRQ(Ext_AON_I2C1_INTR_IRQn                   ,    1, (void*)aon_i2c1_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_AON_I2C0_INTR_IRQn                   ,    1, (void*)aon_i2c0_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_AON_RTC_INTR_IRQn                    ,    1, (void*)aon_rtc_intr_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_AON_PVTC_INTR_IRQn                   ,    1, (void*)aon_pvtc_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_HSM_MAILBOX_HOST_0_INTR_IRQn         ,    1, (void*)hsm_mailbox_host_intr_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HSM_MAILBOX_INTERNEAL_INTR_IRQn      ,    1, (void*)hsm_mailbox_intr_handler              );
    returnCode = PLIC_Register_IRQ(Ext_HSM_TRNG0_TRNG_INTR_IRQn             ,    1, (void*)hsm_trng0_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_HSM_HASH0_INTR_IRQn                  ,    1, (void*)hsm_hash0_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_HSM_CRYP0_INTR_IRQn                  ,    1, (void*)hsm_cryp0_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_HSM_ACRYP0_INTR_IRQn                 ,    1, (void*)hsm_acryp0_intr_handler               );
    returnCode = PLIC_Register_IRQ(Ext_HSM_RTC0_RTC_INTR_IRQn               ,    1, (void*)hsm_rtc0_rtc_intr_handler             );
    returnCode = PLIC_Register_IRQ(Ext_HSM_BASIC_TIMER0_BSC_TIM_INTR_IRQn   ,    1, (void*)hsm_basic_timer0_bsc_tim_intr_handler );
    returnCode = PLIC_Register_IRQ(Ext_HSM_USART0_UART_INTR_IRQn            ,    1, (void*)hsm_usart0_uart_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_HSM_UDMA0_UDMA_INTR_IRQn             ,    1, (void*)hsm_udma0_udma_intr_handler           );
    returnCode = PLIC_Register_IRQ(Ext_MCU_CAN1_INTR_IRQn                   ,    1, (void*)mcu_can1_intr_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_MCU_CAN0_INTR_IRQn                   ,    1, (void*)mcu_can0_intr_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_MCU_ATB2AXI_INTR_IRQn                ,    1, (void*)mcu_atb2axi_intr_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_SDIO_INTR_IRQn                   ,    1, (void*)mcu_sdio_intr_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_MCU_I2S0_INTR_IRQn                   ,    1, (void*)mcu_i2s0_intr_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_MCU_I3C0_INTR_IRQn                   ,    1, (void*)mcu_i3c0_intr_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_MCU_XSPI0_INTR_IRQn                  ,    1, (void*)mcu_xspi0_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_MCU_SPI0_INTR_IRQn                   ,    1, (void*)mcu_spi0_intr_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_MCU_I2C1_INTR_IRQn                   ,    1, (void*)mcu_i2c1_intr_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_MCU_I2C0_INTR_IRQn                   ,    1, (void*)mcu_i2c0_intr_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_MCU_UART1_INTR_IRQn                  ,    1, (void*)mcu_uart1_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_MCU_UART0_INTR_IRQn                  ,    1, (void*)mcu_uart0_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_MCU_NOC_INTR_IRQn                    ,    1, (void*)mcu_noc_intr_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_HS_DATA_NOC_INTR_IRQn                ,    1, (void*)hs_data_noc_intr_handler              );
    returnCode = PLIC_Register_IRQ(Ext_HS_REG_NOC_INTR_IRQn                 ,    1, (void*)hs_reg_noc_intr_handler               );
    returnCode = PLIC_Register_IRQ(Ext_TOP_CRG_PLL_INTR_IRQn                ,    1, (void*)top_crg_ipll_intr_handler             );
    returnCode = PLIC_Register_IRQ(Ext_SOC_NOC_INTR_IRQn                    ,    1, (void*)soc_noc_intr_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_MEDIA_SUB_GPU_SYSERR_INTR_IRQn       ,    1, (void*)media_subgpu_syserr_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_AON_CRG_INTR_IRQn                    ,    1, (void*)aon_crg_intr_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_T2_UEE_PMU_INTR_IRQn                 ,    1, (void*)t2_uee_pmu_intr_handler               );
    returnCode = PLIC_Register_IRQ(Ext_HS_USB_HOST_SYS_ERR_INTR_IRQn        ,    1, (void*)hs_usb_host_sys_err_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_HS_DMA_INTR_IRQn                     ,    1, (void*)hs_dma_intr_handler                   );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS01_ATU_INTR_IRQn            ,    1, (void*)hs_pricess01_atu_intr_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS01_ERR_INTR_IRQn            ,    1, (void*)hs_pricess01_err_intr_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS01_DMA_INTR_IRQn            ,    1, (void*)hs_pricess01_dma_intr_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS00_ATU_INTR_IRQn            ,    1, (void*)hs_pricess00_atu_intr_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS00_ERR_INTR_IRQn            ,    1, (void*)hs_pricess00_err_intr_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS00_DMA_INTR_IRQn            ,    1, (void*)hs_pricess00_dma_intr_handler         );
    returnCode = PLIC_Register_IRQ(Ext_MCU_DMA_INTR_IRQn                    ,    1, (void*)mcu_dma_intr_handler                  );

    returnCode = PLIC_Register_IRQ(Ext_PMU_EVT_WAKEUP_INTR_IRQn             ,    1, (void*)tbu_pmu_evt_wakeup_intr_handler      );

    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU1_PMU_INTR_IRQn         ,  1, (void*)npu_core3_tbu1_pmu_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU1_RAS_INTR_IRQn         ,  1, (void*)npu_core3_tbu1_ras_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU0_PMU_INTR_IRQn         ,  1, (void*)npu_core3_tbu0_pmu_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU0_RAS_INTR_IRQn         ,  1, (void*)npu_core3_tbu0_ras_intr_handler      );   
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU1_PMU_INTR_IRQn         ,  1, (void*)npu_core3_tbu1_pmu_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU1_RAS_INTR_IRQn         ,  1, (void*)npu_core3_tbu1_ras_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU0_PMU_INTR_IRQn         ,  1, (void*)npu_core3_tbu0_pmu_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU0_RAS_INTR_IRQn         ,  1, (void*)npu_core3_tbu0_ras_intr_handler      ); 
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE2_TBU1_PMU_INTR_IRQn         ,  1, (void*)npu_core2_tbu1_pmu_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE2_TBU1_RAS_INTR_IRQn         ,  1, (void*)npu_core2_tbu1_ras_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE2_TBU0_PMU_INTR_IRQn         ,  1, (void*)npu_core2_tbu0_pmu_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE2_TBU0_RAS_INTR_IRQn         ,  1, (void*)npu_core2_tbu0_ras_intr_handler      );   
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE1_TBU1_PMU_INTR_IRQn         ,  1, (void*)npu_core1_tbu1_pmu_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE1_TBU1_RAS_INTR_IRQn         ,  1, (void*)npu_core1_tbu1_ras_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE1_TBU0_PMU_INTR_IRQn         ,  1, (void*)npu_core1_tbu0_pmu_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE1_TBU0_RAS_INTR_IRQn         ,  1, (void*)npu_core1_tbu0_ras_intr_handler      );   
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE0_TBU1_PMU_INTR_IRQn         ,  1, (void*)npu_core0_tbu1_pmu_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE0_TBU1_RAS_INTR_IRQn         ,  1, (void*)npu_core0_tbu1_ras_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE0_TBU0_PMU_INTR_IRQn         ,  1, (void*)npu_core0_tbu0_pmu_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE0_TBU0_RAS_INTR_IRQn         ,  1, (void*)npu_core0_tbu0_ras_intr_handler      );       


    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU1_PMU_INTR_IRQn         ,    1, (void*)core3_tbu1_pmu_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU1_RAS_INTR_IRQn         ,    1, (void*)core3_tbu1_ras_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU0_PMU_INTR_IRQn         ,    1, (void*)core3_tbu0_pmu_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE3_TBU0_RAS_INTR_IRQn         ,    1, (void*)core3_tbu0_ras_intr_handler          );   
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE2_TBU1_PMU_INTR_IRQn         ,    1, (void*)core2_tbu1_pmu_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE2_TBU1_RAS_INTR_IRQn         ,    1, (void*)core2_tbu1_ras_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE2_TBU0_PMU_INTR_IRQn         ,    1, (void*)core2_tbu0_pmu_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE2_TBU0_RAS_INTR_IRQn         ,    1, (void*)core2_tbu0_ras_intr_handler          );   
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE1_TBU1_PMU_INTR_IRQn         ,    1, (void*)core1_tbu1_pmu_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE1_TBU1_RAS_INTR_IRQn         ,    1, (void*)core1_tbu1_ras_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE1_TBU0_PMU_INTR_IRQn         ,    1, (void*)core1_tbu0_pmu_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE1_TBU0_RAS_INTR_IRQn         ,    1, (void*)core1_tbu0_ras_intr_handler          );   
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE0_TBU1_PMU_INTR_IRQn         ,    1, (void*)core0_tbu1_pmu_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE0_TBU1_RAS_INTR_IRQn         ,    1, (void*)core0_tbu1_ras_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE0_TBU0_PMU_INTR_IRQn         ,    1, (void*)core0_tbu0_pmu_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_NPU_CORE0_TBU0_RAS_INTR_IRQn         ,    1, (void*)core0_tbu0_ras_intr_handler          );   
    returnCode = PLIC_Register_IRQ(Ext_MEDIA_TBU_PMU_INTR_IRQn              ,    1, (void*)media_tbu_pmu_intr_handler           );
    returnCode = PLIC_Register_IRQ(Ext_MEDIA_TBU_RAS_INTR_IRQn              ,    1, (void*)media_tbu_ras_intr_handler           );
    
    returnCode = PLIC_Register_IRQ(Ext_TCU_GLOBAL_INTR_S_IRQn               ,    1, (void*)tcu_global_intr_s_handler            );
    returnCode = PLIC_Register_IRQ(Ext_TCU_PRI_Q_INTR_NS_IRQn               ,    1, (void*)tcu_pri_q_intr_ns_handler            );
                                                                                                                                    //
    returnCode = PLIC_Register_IRQ(Ext_TCU_GLOBAL_INTR_NS_IRQn              ,    1, (void*)tcu_global_intr_ns_handler           );
    returnCode = PLIC_Register_IRQ(Ext_TCU_CMD_SYNC_INTR_NS_IRQn            ,    1, (void*)tcu_cmd_sync_intr_ns_handler         );
    returnCode = PLIC_Register_IRQ(Ext_TCU_CMD_SYNC_INTR_S_IRQn             ,    1, (void*)tcu_cmd_sync_intr_s_handler          );
    returnCode = PLIC_Register_IRQ(Ext_TCU_EVENT_Q_INTR_NS_IRQn             ,    1, (void*)tcu_event_q_intr_ns_handler          );
    returnCode = PLIC_Register_IRQ(Ext_TCU_EVENT_Q_INTR_S_IRQn              ,    1, (void*)tcu_event_q_intr_s_handler           );
    returnCode = PLIC_Register_IRQ(Ext_TCU_PMU_INTR_IRQn                    ,    1, (void*)tcu_pmu_intr_handler                 );
    
    returnCode = PLIC_Register_IRQ(Ext_TCU_RAS_INTR_0_IRQn                    ,  1, (void*)tcu_ras_intr_handler                 ); //1209
    returnCode = PLIC_Register_IRQ(Ext_BARRIER_INTR_0_IRQn                    ,  1, (void*)barrier_intr_handler                 ); //1209
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR3_0_IRQn                     ,    1, (void*)npu_intr3_0_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR3_1_IRQn                     ,    1, (void*)npu_intr3_1_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR3_2_IRQn                     ,    1, (void*)npu_intr3_2_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR3_3_IRQn                     ,    1, (void*)npu_intr3_3_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR3_4_IRQn                     ,    1, (void*)npu_intr3_4_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR3_5_IRQn                     ,    1, (void*)npu_intr3_5_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR3_6_IRQn                     ,    1, (void*)npu_intr3_6_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR3_7_IRQn                     ,    1, (void*)npu_intr3_7_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR2_0_IRQn                     ,    1, (void*)npu_intr2_0_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR2_1_IRQn                     ,    1, (void*)npu_intr2_1_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR2_2_IRQn                     ,    1, (void*)npu_intr2_2_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR2_3_IRQn                     ,    1, (void*)npu_intr2_3_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR2_4_IRQn                     ,    1, (void*)npu_intr2_4_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR2_5_IRQn                     ,    1, (void*)npu_intr2_5_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR2_6_IRQn                     ,    1, (void*)npu_intr2_6_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR2_7_IRQn                     ,    1, (void*)npu_intr2_7_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR1_0_IRQn                     ,    1, (void*)npu_intr1_0_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR1_1_IRQn                     ,    1, (void*)npu_intr1_1_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR1_2_IRQn                     ,    1, (void*)npu_intr1_2_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR1_3_IRQn                     ,    1, (void*)npu_intr1_3_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR1_4_IRQn                     ,    1, (void*)npu_intr1_4_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR1_5_IRQn                     ,    1, (void*)npu_intr1_5_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR1_6_IRQn                     ,    1, (void*)npu_intr1_6_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR1_7_IRQn                     ,    1, (void*)npu_intr1_7_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR0_0_IRQn                     ,    1, (void*)npu_intr0_0_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR0_1_IRQn                     ,    1, (void*)npu_intr0_1_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR0_2_IRQn                     ,    1, (void*)npu_intr0_2_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR0_3_IRQn                     ,    1, (void*)npu_intr0_3_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR0_4_IRQn                     ,    1, (void*)npu_intr0_4_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR0_5_IRQn                     ,    1, (void*)npu_intr0_5_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR0_6_IRQn                     ,    1, (void*)npu_intr0_6_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_INTR0_7_IRQn                     ,    1, (void*)npu_intr0_7_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_NPU_WDT_INTR3_IRQn                   ,    1, (void*)npu_wdt_intr3_handler                );
    returnCode = PLIC_Register_IRQ(Ext_NPU_WDT_INTR2_IRQn                   ,    1, (void*)npu_wdt_intr2_handler                );
    returnCode = PLIC_Register_IRQ(Ext_NPU_WDT_INTR1_IRQn                   ,    1, (void*)npu_wdt_intr1_handler                );
    returnCode = PLIC_Register_IRQ(Ext_NPU_WDT_INTR0_IRQn                   ,    1, (void*)npu_wdt_intr0_handler                );
    returnCode = PLIC_Register_IRQ(Ext_MCU_WDT_INTR_IRQn                    ,    1, (void*)mcu_wdt_intr_handler                 );

    __enable_irq();

    send_label(0x12345678);

    while(irq_num != Ext_MCU_WDT_INTR_IRQn);{
        cpu_info("wait all int done !!!\n");
    }

    
    cpu_info("cpu test done !!!\n");

    simend();
    while(1);
}


