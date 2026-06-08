// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

volatile int  int_flg = 0;
volatile int  irq_num = 0;

__INTERRUPT void mcu_mailbox_intr7_handler        (void) {cpu_info("[INT]mcu_mailbox_intr7_handler        hit\n"); send_label(MCU_MAILBOX_INTR7_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr6_handler        (void) {cpu_info("[INT]mcu_mailbox_intr6_handler        hit\n"); send_label(MCU_MAILBOX_INTR6_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr5_handler        (void) {cpu_info("[INT]mcu_mailbox_intr5_handler        hit\n"); send_label(MCU_MAILBOX_INTR5_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr4_handler        (void) {cpu_info("[INT]mcu_mailbox_intr4_handler        hit\n"); send_label(MCU_MAILBOX_INTR4_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr3_handler        (void) {cpu_info("[INT]mcu_mailbox_intr3_handler        hit\n"); send_label(MCU_MAILBOX_INTR3_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr2_handler        (void) {cpu_info("[INT]mcu_mailbox_intr2_handler        hit\n"); send_label(MCU_MAILBOX_INTR2_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr1_handler        (void) {cpu_info("[INT]mcu_mailbox_intr1_handler        hit\n"); send_label(MCU_MAILBOX_INTR1_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr0_handler        (void) {cpu_info("[INT]mcu_mailbox_intr0_handler        hit\n"); send_label(MCU_MAILBOX_INTR0_IRQn        ); int_flg++;}
__INTERRUPT void mcu_gpio1_intr7_handler          (void) {cpu_info("[INT]mcu_gpio1_intr7_handler          hit\n"); send_label(MCU_GPIO1_INTR7_IRQn          ); int_flg++;}
__INTERRUPT void mcu_gpio1_intr6_handler          (void) {cpu_info("[INT]mcu_gpio1_intr6_handler          hit\n"); send_label(MCU_GPIO1_INTR6_IRQn          ); int_flg++;}
__INTERRUPT void mcu_gpio1_intr5_handler          (void) {cpu_info("[INT]mcu_gpio1_intr5_handler          hit\n"); send_label(MCU_GPIO1_INTR5_IRQn          ); int_flg++;}
__INTERRUPT void mcu_gpio1_intr4_handler          (void) {cpu_info("[INT]mcu_gpio1_intr4_handler          hit\n"); send_label(MCU_GPIO1_INTR4_IRQn          ); int_flg++;}
__INTERRUPT void mcu_gpio1_intr3_handler          (void) {cpu_info("[INT]mcu_gpio1_intr3_handler          hit\n"); send_label(MCU_GPIO1_INTR3_IRQn          ); int_flg++;}
__INTERRUPT void mcu_gpio1_intr2_handler          (void) {cpu_info("[INT]mcu_gpio1_intr2_handler          hit\n"); send_label(MCU_GPIO1_INTR2_IRQn          ); int_flg++;}
__INTERRUPT void mcu_gpio1_intr1_handler          (void) {cpu_info("[INT]mcu_gpio1_intr1_handler          hit\n"); send_label(MCU_GPIO1_INTR1_IRQn          ); int_flg++;}
__INTERRUPT void mcu_gpio1_intr0_handler          (void) {cpu_info("[INT]mcu_gpio1_intr0_handler          hit\n"); send_label(MCU_GPIO1_INTR0_IRQn          ); int_flg++;}
__INTERRUPT void aon_gpio7_intr_handler           (void) {cpu_info("[INT]aon_gpio7_intr_handler           hit\n"); send_label(AON_GPIO7_INTR_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio6_intr_handler           (void) {cpu_info("[INT]aon_gpio6_intr_handler           hit\n"); send_label(AON_GPIO6_INTR_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio5_intr_handler           (void) {cpu_info("[INT]aon_gpio5_intr_handler           hit\n"); send_label(AON_GPIO5_INTR_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio4_intr_handler           (void) {cpu_info("[INT]aon_gpio4_intr_handler           hit\n"); send_label(AON_GPIO4_INTR_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio3_intr_handler           (void) {cpu_info("[INT]aon_gpio3_intr_handler           hit\n"); send_label(AON_GPIO3_INTR_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio2_intr_handler           (void) {cpu_info("[INT]aon_gpio2_intr_handler           hit\n"); send_label(AON_GPIO2_INTR_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio1_intr_handler           (void) {cpu_info("[INT]aon_gpio1_intr_handler           hit\n"); send_label(AON_GPIO1_INTR_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio0_intr_handler           (void) {cpu_info("[INT]aon_gpio0_intr_handler           hit\n"); send_label(AON_GPIO0_INTR_IRQn           ); int_flg++;}
__INTERRUPT void aon_i2c1_intr_handler            (void) {cpu_info("[INT]aon_i2c1_intr_handler            hit\n"); send_label(AON_I2C1_INTR_IRQn            ); int_flg++;}
__INTERRUPT void aon_i2c0_intr_handler            (void) {cpu_info("[INT]aon_i2c0_intr_handler            hit\n"); send_label(AON_I2C0_INTR_IRQn            ); int_flg++;}
__INTERRUPT void aon_rtc_intr_handler             (void) {cpu_info("[INT]aon_rtc_intr_handler             hit\n"); send_label(AON_RTC_INTR_IRQn             ); int_flg++;}
__INTERRUPT void aon_pvtc_intr_handler            (void) {cpu_info("[INT]aon_pvtc_intr_handler            hit\n"); send_label(AON_PVTC_INTR_IRQn            ); int_flg++;}
__INTERRUPT void hsm_mailbox_host_intr_handler    (void) {cpu_info("[INT]hsm_mailbox_host_intr_handler    hit\n"); send_label(HSM_MAILBOX_HOST_0_INTR_IRQn  ); int_flg++;}
__INTERRUPT void hsm_mailbox_intr_handler         (void) {cpu_info("[INT]hsm_mailbox_intr_handler         hit\n"); send_label(HSM_MAILBOX_INTERNEAL_INTR_IRQn ); int_flg++;}
__INTERRUPT void hsm_trng0_intr_handler           (void) {cpu_info("[INT]hsm_trng0_intr_handler           hit\n"); send_label(HSM_TRNG0_TRNG_INTR_IRQn      ); int_flg++;}
__INTERRUPT void hsm_hash0_intr_handler           (void) {cpu_info("[INT]hsm_hash0_intr_handler           hit\n"); send_label(HSM_HASH0_INTR_IRQn           ); int_flg++;}
__INTERRUPT void hsm_cryp0_intr_handler           (void) {cpu_info("[INT]hsm_cryp0_intr_handler           hit\n"); send_label(HSM_CRYP0_INTR_IRQn           ); int_flg++;}
__INTERRUPT void hsm_acryp0_intr_handler          (void) {cpu_info("[INT]hsm_acryp0_intr_handler          hit\n"); send_label(HSM_ACRYP0_INTR_IRQn          ); int_flg++;}
__INTERRUPT void hsm_rtc0_rtc_intr_handler        (void) {cpu_info("[INT]hsm_rtc0_rtc_intr_handler        hit\n"); send_label(HSM_RTC0_RTC_INTR_IRQn        ); int_flg++;}
__INTERRUPT void hsm_basic_timer0_bsc_tim_intr_handler  (void) {cpu_info("[INT]hsm_basic_timer0_bsc_tim_intr_handler  hit\n"); send_label(HSM_BASIC_TIMER0_BSC_TIM_INTR_IRQn ); int_flg++;}
__INTERRUPT void hsm_usart0_uart_intr_handler     (void) {cpu_info("[INT]hsm_usart0_uart_intr_handler     hit\n"); send_label(HSM_USART0_UART_INTR_IRQn     ); int_flg++;}
__INTERRUPT void hsm_udma0_udma_intr_handler      (void) {cpu_info("[INT]hsm_udma0_udma_intr_handler      hit\n"); send_label(HSM_UDMA0_UDMA_INTR_IRQn      ); int_flg++;}
__INTERRUPT void mcu_can1_intr_handler            (void) {cpu_info("[INT]mcu_can1_intr_handler            hit\n"); send_label(MCU_CAN1_INTR_IRQn            ); int_flg++;}
__INTERRUPT void mcu_can0_intr_handler            (void) {cpu_info("[INT]mcu_can0_intr_handler            hit\n"); send_label(MCU_CAN0_INTR_IRQn            ); int_flg++;}
__INTERRUPT void mcu_atb2axi_intr_handler         (void) {cpu_info("[INT]mcu_atb2axi_intr_handler         hit\n"); send_label(MCU_ATB2AXI_INTR_IRQn         ); int_flg++;}
__INTERRUPT void mcu_sdio_intr_handler            (void) {cpu_info("[INT]mcu_sdio_intr_handler            hit\n"); send_label(MCU_SDIO_INTR_IRQn            ); int_flg++;}
__INTERRUPT void mcu_i2s0_intr_handler            (void) {cpu_info("[INT]mcu_i2s0_intr_handler            hit\n"); send_label(MCU_I2S0_INTR_IRQn            ); int_flg++;}
__INTERRUPT void mcu_i3c0_intr_handler            (void) {cpu_info("[INT]mcu_i3c0_intr_handler            hit\n"); send_label(MCU_I3C0_INTR_IRQn            ); int_flg++;}
__INTERRUPT void mcu_xspi0_intr_handler           (void) {cpu_info("[INT]mcu_xspi0_intr_handler           hit\n"); send_label(MCU_XSPI0_INTR_IRQn           ); int_flg++;}
__INTERRUPT void mcu_spi0_intr_handler            (void) {cpu_info("[INT]mcu_spi0_intr_handler            hit\n"); send_label(MCU_SPI0_INTR_IRQn            ); int_flg++;}
__INTERRUPT void mcu_i2c1_intr_handler            (void) {cpu_info("[INT]mcu_i2c1_intr_handler            hit\n"); send_label(MCU_I2C1_INTR_IRQn            ); int_flg++;}
__INTERRUPT void mcu_i2c0_intr_handler            (void) {cpu_info("[INT]mcu_i2c0_intr_handler            hit\n"); send_label(MCU_I2C0_INTR_IRQn            ); int_flg++;}
__INTERRUPT void mcu_uart1_intr_handler           (void) {cpu_info("[INT]mcu_uart1_intr_handler           hit\n"); send_label(MCU_UART1_INTR_IRQn           ); int_flg++;}
__INTERRUPT void mcu_uart0_intr_handler           (void) {cpu_info("[INT]mcu_uart0_intr_handler           hit\n"); send_label(MCU_UART0_INTR_IRQn           ); int_flg++;}
__INTERRUPT void mcu_noc_intr_handler             (void) {cpu_info("[INT]mcu_noc_intr_handler             hit\n"); send_label(MCU_NOC_INTR_IRQn             ); int_flg++;}
__INTERRUPT void hs_data_noc_intr_handler         (void) {cpu_info("[INT]hs_data_noc_intr_handler         hit\n"); send_label(HS_DATA_NOC_INTR_IRQn         ); int_flg++;}
__INTERRUPT void hs_reg_noc_intr_handler          (void) {cpu_info("[INT]hs_reg_noc_intr_handler          hit\n"); send_label(HS_REG_NOC_INTR_IRQn          ); int_flg++;}
__INTERRUPT void top_crg_ipll_intr_handler        (void) {cpu_info("[INT]top_crg_ipll_intr_handler        hit\n"); send_label(TOP_CRG_PLL_INTR_IRQn         ); int_flg++;}
__INTERRUPT void soc_noc_intr_handler             (void) {cpu_info("[INT]soc_noc_intr_handler             hit\n"); send_label(SOC_NOC_INTR_IRQn             ); int_flg++;}
__INTERRUPT void media_subgpu_syserr_intr_handler (void) {cpu_info("[INT]media_subgpu_syserr_intr_handler hit\n"); send_label(MEDIA_SUB_GPU_SYSERR_INTR_IRQn); int_flg++;}
__INTERRUPT void aon_crg_intr_handler             (void) {cpu_info("[INT]aon_crg_intr_handler             hit\n"); send_label(AON_CRG_INTR_IRQn             ); int_flg++;}
__INTERRUPT void t2_uee_pmu_intr_handler          (void) {cpu_info("[INT]t2_uee_pmu_intr_handler          hit\n"); send_label(T2_UEE_PMU_INTR_IRQn          );
            scu_clear_intr_raw(1u << 11);
 int_flg++;}
__INTERRUPT void hs_usb_host_sys_err_intr_handler (void) {cpu_info("[INT]hs_usb_host_sys_err_intr_handler hit\n"); send_label(HS_USB_HOST_SYS_ERR_INTR_IRQn ); int_flg++;}
__INTERRUPT void hs_dma_intr_handler              (void) {cpu_info("[INT]hs_dma_intr_handler              hit\n"); send_label(HS_DMA_INTR_IRQn              ); int_flg++;}
__INTERRUPT void hs_pricess01_atu_intr_handler    (void) {cpu_info("[INT]hs_pricess01_atu_intr_handler    hit\n"); send_label(HS_PCIESS01_ATU_INTR_IRQn     ); int_flg++;}
__INTERRUPT void hs_pricess01_err_intr_handler    (void) {cpu_info("[INT]hs_pricess01_err_intr_handler    hit\n"); send_label(HS_PCIESS01_ERR_INTR_IRQn     ); int_flg++;}
__INTERRUPT void hs_pricess01_dma_intr_handler    (void) {cpu_info("[INT]hs_pricess01_dma_intr_handler    hit\n"); send_label(HS_PCIESS01_DMA_INTR_IRQn     ); int_flg++;}
__INTERRUPT void hs_pricess00_atu_intr_handler    (void) {cpu_info("[INT]hs_pricess00_atu_intr_handler    hit\n"); send_label(HS_PCIESS00_ATU_INTR_IRQn     ); int_flg++;}
__INTERRUPT void hs_pricess00_err_intr_handler    (void) {cpu_info("[INT]hs_pricess00_err_intr_handler    hit\n"); send_label(HS_PCIESS00_ERR_INTR_IRQn     ); int_flg++;}
__INTERRUPT void hs_pricess00_dma_intr_handler    (void) {cpu_info("[INT]hs_pricess00_dma_intr_handler    hit\n"); send_label(HS_PCIESS00_DMA_INTR_IRQn     ); int_flg++;}
__INTERRUPT void mcu_dma_intr_handler             (void) {cpu_info("[INT]mcu_dma_intr_handler             hit\n"); send_label(MCU_DMA_INTR_IRQn             ); int_flg++;}
__INTERRUPT void tbu_pmu_evt_wakeup_intr_handler  (void) {cpu_info("[INT]tbu_pmu_evt_wakeup_intr_handler  hit\n"); send_label(PMU_EVT_WAKEUP_INTR_IRQn      ); int_flg++;}
__INTERRUPT void npu_core3_tbu1_pmu_intr_handler  (void) {cpu_info("[INT]npu_core3_tbu1_pmu_intr          hit\n"); send_label(NPU_CORE3_TBU1_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core3_tbu1_ras_intr_handler  (void) {cpu_info("[INT]npu_core3_tbu1_ras_intr          hit\n"); send_label(NPU_CORE3_TBU1_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core3_tbu0_pmu_intr_handler  (void) {cpu_info("[INT]npu_core3_tbu0_pmu_intr          hit\n"); send_label(NPU_CORE3_TBU0_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core3_tbu0_ras_intr_handler  (void) {cpu_info("[INT]npu_core3_tbu0_ras_intr          hit\n"); send_label(NPU_CORE3_TBU0_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core2_tbu1_pmu_intr_handler  (void) {cpu_info("[INT]npu_core2_tbu1_pmu_intr          hit\n"); send_label(NPU_CORE2_TBU1_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core2_tbu1_ras_intr_handler  (void) {cpu_info("[INT]npu_core2_tbu1_ras_intr          hit\n"); send_label(NPU_CORE2_TBU1_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core2_tbu0_pmu_intr_handler  (void) {cpu_info("[INT]npu_core2_tbu0_pmu_intr          hit\n"); send_label(NPU_CORE2_TBU0_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core2_tbu0_ras_intr_handler  (void) {cpu_info("[INT]npu_core2_tbu0_ras_intr          hit\n"); send_label(NPU_CORE2_TBU0_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core1_tbu1_pmu_intr_handler  (void) {cpu_info("[INT]npu_core1_tbu1_pmu_intr          hit\n"); send_label(NPU_CORE1_TBU1_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core1_tbu1_ras_intr_handler  (void) {cpu_info("[INT]npu_core1_tbu1_ras_intr          hit\n"); send_label(NPU_CORE1_TBU1_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core1_tbu0_pmu_intr_handler  (void) {cpu_info("[INT]npu_core1_tbu0_pmu_intr          hit\n"); send_label(NPU_CORE1_TBU0_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core1_tbu0_ras_intr_handler  (void) {cpu_info("[INT]npu_core1_tbu0_ras_intr          hit\n"); send_label(NPU_CORE1_TBU0_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core0_tbu1_pmu_intr_handler  (void) {cpu_info("[INT]npu_core0_tbu1_pmu_intr          hit\n"); send_label(NPU_CORE0_TBU1_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core0_tbu1_ras_intr_handler  (void) {cpu_info("[INT]npu_core0_tbu1_ras_intr          hit\n"); send_label(NPU_CORE0_TBU1_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core0_tbu0_pmu_intr_handler  (void) {cpu_info("[INT]npu_core0_tbu0_pmu_intr          hit\n"); send_label(NPU_CORE0_TBU0_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void npu_core0_tbu0_ras_intr_handler  (void) {cpu_info("[INT]npu_core0_tbu0_ras_intr          hit\n"); send_label(NPU_CORE0_TBU0_RAS_INTR_IRQn  ); int_flg++;
    irq_num = NPU_CORE0_TBU0_RAS_INTR_IRQn;
}


int main(void)
{
    uint32_t returnCode;
    CSR_MCFGINFO_Type mcfg;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    cpu_info("ECLIC_Interrupt_Test start 1111111\n");

    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR7_IRQn               ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr7_handler            );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR6_IRQn               ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr6_handler            );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR5_IRQn               ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr5_handler            );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR4_IRQn               ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr4_handler            );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR3_IRQn               ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr3_handler            );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR2_IRQn               ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr2_handler            );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR1_IRQn               ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr1_handler            );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR0_IRQn               ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr0_handler            );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO1_INTR7_IRQn                 ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio1_intr7_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO1_INTR6_IRQn                 ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio1_intr6_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO1_INTR5_IRQn                 ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio1_intr5_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO1_INTR4_IRQn                 ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio1_intr4_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO1_INTR3_IRQn                 ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio1_intr3_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO1_INTR2_IRQn                 ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio1_intr2_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO1_INTR1_IRQn                 ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio1_intr1_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO1_INTR0_IRQn                 ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio1_intr0_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO7_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio7_intr_handler               );
    returnCode = ECLIC_Register_IRQ(AON_GPIO6_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio6_intr_handler               );
    returnCode = ECLIC_Register_IRQ(AON_GPIO5_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio5_intr_handler               );
    returnCode = ECLIC_Register_IRQ(AON_GPIO4_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio4_intr_handler               );
    returnCode = ECLIC_Register_IRQ(AON_GPIO3_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio3_intr_handler               );
    returnCode = ECLIC_Register_IRQ(AON_GPIO2_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio2_intr_handler               );
    returnCode = ECLIC_Register_IRQ(AON_GPIO1_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio1_intr_handler               );
    returnCode = ECLIC_Register_IRQ(AON_GPIO0_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio0_intr_handler               );
    returnCode = ECLIC_Register_IRQ(AON_I2C1_INTR_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_i2c1_intr_handler                );
    returnCode = ECLIC_Register_IRQ(AON_I2C0_INTR_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_i2c0_intr_handler                );
    returnCode = ECLIC_Register_IRQ(AON_RTC_INTR_IRQn                    ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_rtc_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(AON_PVTC_INTR_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_pvtc_intr_handler                );
    returnCode = ECLIC_Register_IRQ(HSM_MAILBOX_HOST_0_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hsm_mailbox_host_intr_handler         );
    returnCode = ECLIC_Register_IRQ(HSM_MAILBOX_INTERNEAL_INTR_IRQn      ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hsm_mailbox_intr_handler              );
    returnCode = ECLIC_Register_IRQ(HSM_TRNG0_TRNG_INTR_IRQn             ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hsm_trng0_intr_handler                );
    returnCode = ECLIC_Register_IRQ(HSM_HASH0_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hsm_hash0_intr_handler                );
    returnCode = ECLIC_Register_IRQ(HSM_CRYP0_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hsm_cryp0_intr_handler                );
    returnCode = ECLIC_Register_IRQ(HSM_ACRYP0_INTR_IRQn                 ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hsm_acryp0_intr_handler               );
    returnCode = ECLIC_Register_IRQ(HSM_RTC0_RTC_INTR_IRQn               ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hsm_rtc0_rtc_intr_handler             );
    returnCode = ECLIC_Register_IRQ(HSM_BASIC_TIMER0_BSC_TIM_INTR_IRQn   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hsm_basic_timer0_bsc_tim_intr_handler );
    returnCode = ECLIC_Register_IRQ(HSM_USART0_UART_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hsm_usart0_uart_intr_handler          );
    returnCode = ECLIC_Register_IRQ(HSM_UDMA0_UDMA_INTR_IRQn             ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hsm_udma0_udma_intr_handler           );
    returnCode = ECLIC_Register_IRQ(MCU_CAN1_INTR_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_can1_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(MCU_CAN0_INTR_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_can0_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(MCU_ATB2AXI_INTR_IRQn                ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_atb2axi_intr_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_SDIO_INTR_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_sdio_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(MCU_I2S0_INTR_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_i2s0_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(MCU_I3C0_INTR_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_i3c0_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(MCU_XSPI0_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_xspi0_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_SPI0_INTR_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_spi0_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(MCU_I2C1_INTR_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_i2c1_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(MCU_I2C0_INTR_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_i2c0_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(MCU_UART1_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_uart1_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_UART0_INTR_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_uart0_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_NOC_INTR_IRQn                    ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_noc_intr_handler                  );
    returnCode = ECLIC_Register_IRQ(HS_DATA_NOC_INTR_IRQn                ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_data_noc_intr_handler              );
    returnCode = ECLIC_Register_IRQ(HS_REG_NOC_INTR_IRQn                 ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_reg_noc_intr_handler               );
    returnCode = ECLIC_Register_IRQ(TOP_CRG_PLL_INTR_IRQn                ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)top_crg_ipll_intr_handler             );
    returnCode = ECLIC_Register_IRQ(SOC_NOC_INTR_IRQn                    ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)soc_noc_intr_handler                  );
    returnCode = ECLIC_Register_IRQ(MEDIA_SUB_GPU_SYSERR_INTR_IRQn       ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)media_subgpu_syserr_intr_handler      );
    returnCode = ECLIC_Register_IRQ(AON_CRG_INTR_IRQn                    ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_crg_intr_handler                  );
    returnCode = ECLIC_Register_IRQ(T2_UEE_PMU_INTR_IRQn                 ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)t2_uee_pmu_intr_handler               );
    returnCode = ECLIC_Register_IRQ(HS_USB_HOST_SYS_ERR_INTR_IRQn        ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_usb_host_sys_err_intr_handler      );
    returnCode = ECLIC_Register_IRQ(HS_DMA_INTR_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_dma_intr_handler                   );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS01_ATU_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pricess01_atu_intr_handler         );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS01_ERR_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pricess01_err_intr_handler         );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS01_DMA_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pricess01_dma_intr_handler         );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS00_ATU_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pricess00_atu_intr_handler         );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS00_ERR_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pricess00_err_intr_handler         );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS00_DMA_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pricess00_dma_intr_handler         );
    returnCode = ECLIC_Register_IRQ(MCU_DMA_INTR_IRQn                    ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_dma_intr_handler                  );
    returnCode = ECLIC_Register_IRQ(PMU_EVT_WAKEUP_INTR_IRQn             ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)tbu_pmu_evt_wakeup_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU1_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core3_tbu1_pmu_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU1_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core3_tbu1_ras_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU0_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core3_tbu0_pmu_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU0_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core3_tbu0_ras_intr_handler      );   

    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU1_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core3_tbu1_pmu_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU1_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core3_tbu1_ras_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU0_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core3_tbu0_pmu_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU0_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core3_tbu0_ras_intr_handler      ); 

    returnCode = ECLIC_Register_IRQ(NPU_CORE2_TBU1_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core2_tbu1_pmu_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE2_TBU1_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core2_tbu1_ras_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE2_TBU0_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core2_tbu0_pmu_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE2_TBU0_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core2_tbu0_ras_intr_handler      );   

    returnCode = ECLIC_Register_IRQ(NPU_CORE1_TBU1_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core1_tbu1_pmu_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE1_TBU1_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core1_tbu1_ras_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE1_TBU0_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core1_tbu0_pmu_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE1_TBU0_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core1_tbu0_ras_intr_handler      );   

    returnCode = ECLIC_Register_IRQ(NPU_CORE0_TBU1_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core0_tbu1_pmu_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE0_TBU1_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core0_tbu1_ras_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE0_TBU0_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core0_tbu0_pmu_intr_handler      );
    returnCode = ECLIC_Register_IRQ(NPU_CORE0_TBU0_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_core0_tbu0_ras_intr_handler      );       

    
    __enable_irq();

    send_label(0x12345678);

    while(irq_num != NPU_CORE0_TBU0_RAS_INTR_IRQn);{
        cpu_info("wait all int done !!!\n");
    }

    
    cpu_info("cpu test done !!!\n");

    simend();
    while(1);
}


