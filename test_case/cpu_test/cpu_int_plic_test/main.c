// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

volatile int int_flg = 0;
volatile int  irq_num = 0;
// timer interrupt handler
// vector mode interrupt

void mcu_gpio_intr31_handler      (void) {cpu_info("[INT]mcu_gpio_intr31_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR31_IRQn           ); int_flg++;}
void mcu_gpio_intr30_handler      (void) {cpu_info("[INT]mcu_gpio_intr30_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR30_IRQn           ); int_flg++;}
void mcu_gpio_intr29_handler      (void) {cpu_info("[INT]mcu_gpio_intr29_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR29_IRQn           ); int_flg++;}
void mcu_gpio_intr28_handler      (void) {cpu_info("[INT]mcu_gpio_intr28_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR28_IRQn           ); int_flg++;}
void mcu_gpio_intr27_handler      (void) {cpu_info("[INT]mcu_gpio_intr27_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR27_IRQn           ); int_flg++;}
void mcu_gpio_intr26_handler      (void) {cpu_info("[INT]mcu_gpio_intr26_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR26_IRQn           ); int_flg++;}
void mcu_gpio_intr25_handler      (void) {cpu_info("[INT]mcu_gpio_intr25_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR25_IRQn           ); int_flg++;}
void mcu_gpio_intr24_handler      (void) {cpu_info("[INT]mcu_gpio_intr24_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR24_IRQn           ); int_flg++;}
void mcu_gpio_intr23_handler      (void) {cpu_info("[INT]mcu_gpio_intr23_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR23_IRQn           ); int_flg++;}
void mcu_gpio_intr22_handler      (void) {cpu_info("[INT]mcu_gpio_intr22_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR22_IRQn           ); int_flg++;}
void mcu_gpio_intr21_handler      (void) {cpu_info("[INT]mcu_gpio_intr21_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR21_IRQn           ); int_flg++;}
void mcu_gpio_intr20_handler      (void) {cpu_info("[INT]mcu_gpio_intr20_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR20_IRQn           ); int_flg++;}
void mcu_gpio_intr19_handler      (void) {cpu_info("[INT]mcu_gpio_intr19_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR19_IRQn           ); int_flg++;}
void mcu_gpio_intr18_handler      (void) {cpu_info("[INT]mcu_gpio_intr18_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR18_IRQn           ); int_flg++;}
void mcu_gpio_intr17_handler      (void) {cpu_info("[INT]mcu_gpio_intr17_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR17_IRQn           ); int_flg++;}
void mcu_gpio_intr16_handler      (void) {cpu_info("[INT]mcu_gpio_intr16_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR16_IRQn           ); int_flg++;}
void mcu_gpio_intr15_handler      (void) {cpu_info("[INT]mcu_gpio_intr15_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR15_IRQn           ); int_flg++;}
void mcu_gpio_intr14_handler      (void) {cpu_info("[INT]mcu_gpio_intr14_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR14_IRQn           ); int_flg++;}
void mcu_gpio_intr13_handler      (void) {cpu_info("[INT]mcu_gpio_intr13_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR13_IRQn           ); int_flg++;}
void mcu_gpio_intr12_handler      (void) {cpu_info("[INT]mcu_gpio_intr12_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR12_IRQn           ); int_flg++;}
void mcu_gpio_intr11_handler      (void) {cpu_info("[INT]mcu_gpio_intr11_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR11_IRQn           ); int_flg++;}
void mcu_gpio_intr10_handler      (void) {cpu_info("[INT]mcu_gpio_intr10_handler       hit\n"); send_label(Ext_MCU_GPIO_INTR10_IRQn           ); int_flg++;}
void mcu_gpio_intr9_handler       (void) {cpu_info("[INT]mcu_gpio_intr9_handler        hit\n"); send_label(Ext_MCU_GPIO_INTR9_IRQn            ); int_flg++;}
void mcu_gpio_intr8_handler       (void) {cpu_info("[INT]mcu_gpio_intr8_handler        hit\n"); send_label(Ext_MCU_GPIO_INTR8_IRQn            ); int_flg++;}
void aon_gpio_intr31_handler      (void) {cpu_info("[INT]aon_gpio_intr31_handler       hit\n"); send_label(Ext_AON_GPIO_INTR31_IRQn           ); int_flg++;}
void aon_gpio_intr30_handler      (void) {cpu_info("[INT]aon_gpio_intr30_handler       hit\n"); send_label(Ext_AON_GPIO_INTR30_IRQn           ); int_flg++;}
void aon_gpio_intr29_handler      (void) {cpu_info("[INT]aon_gpio_intr29_handler       hit\n"); send_label(Ext_AON_GPIO_INTR29_IRQn           ); int_flg++;}
void aon_gpio_intr28_handler      (void) {cpu_info("[INT]aon_gpio_intr28_handler       hit\n"); send_label(Ext_AON_GPIO_INTR28_IRQn           ); int_flg++;}
void aon_gpio_intr27_handler      (void) {cpu_info("[INT]aon_gpio_intr27_handler       hit\n"); send_label(Ext_AON_GPIO_INTR27_IRQn           ); int_flg++;}
void aon_gpio_intr26_handler      (void) {cpu_info("[INT]aon_gpio_intr26_handler       hit\n"); send_label(Ext_AON_GPIO_INTR26_IRQn           ); int_flg++;}
void aon_gpio_intr25_handler      (void) {cpu_info("[INT]aon_gpio_intr25_handler       hit\n"); send_label(Ext_AON_GPIO_INTR25_IRQn           ); int_flg++;}
void aon_gpio_intr24_handler      (void) {cpu_info("[INT]aon_gpio_intr24_handler       hit\n"); send_label(Ext_AON_GPIO_INTR24_IRQn           ); int_flg++;}
void aon_gpio_intr23_handler      (void) {cpu_info("[INT]aon_gpio_intr23_handler       hit\n"); send_label(Ext_AON_GPIO_INTR23_IRQn           ); int_flg++;}
void aon_gpio_intr22_handler      (void) {cpu_info("[INT]aon_gpio_intr22_handler       hit\n"); send_label(Ext_AON_GPIO_INTR22_IRQn           ); int_flg++;}
void aon_gpio_intr21_handler      (void) {cpu_info("[INT]aon_gpio_intr21_handler       hit\n"); send_label(Ext_AON_GPIO_INTR21_IRQn           ); int_flg++;}
void aon_gpio_intr20_handler      (void) {cpu_info("[INT]aon_gpio_intr20_handler       hit\n"); send_label(Ext_AON_GPIO_INTR20_IRQn           ); int_flg++;}
void aon_gpio_intr19_handler      (void) {cpu_info("[INT]aon_gpio_intr19_handler       hit\n"); send_label(Ext_AON_GPIO_INTR19_IRQn           ); int_flg++;}
void aon_gpio_intr18_handler      (void) {cpu_info("[INT]aon_gpio_intr18_handler       hit\n"); send_label(Ext_AON_GPIO_INTR18_IRQn           ); int_flg++;}
void aon_gpio_intr17_handler      (void) {cpu_info("[INT]aon_gpio_intr17_handler       hit\n"); send_label(Ext_AON_GPIO_INTR17_IRQn           ); int_flg++;}
void aon_gpio_intr16_handler      (void) {cpu_info("[INT]aon_gpio_intr16_handler       hit\n"); send_label(Ext_AON_GPIO_INTR16_IRQn           ); int_flg++;}
void aon_gpio_intr15_handler      (void) {cpu_info("[INT]aon_gpio_intr15_handler       hit\n"); send_label(Ext_AON_GPIO_INTR15_IRQn           ); int_flg++;}
void aon_gpio_intr14_handler      (void) {cpu_info("[INT]aon_gpio_intr14_handler       hit\n"); send_label(Ext_AON_GPIO_INTR14_IRQn           ); int_flg++;}
void aon_gpio_intr13_handler      (void) {cpu_info("[INT]aon_gpio_intr13_handler       hit\n"); send_label(Ext_AON_GPIO_INTR13_IRQn           ); int_flg++;}
void aon_gpio_intr12_handler      (void) {cpu_info("[INT]aon_gpio_intr12_handler       hit\n"); send_label(Ext_AON_GPIO_INTR12_IRQn           ); int_flg++;}
void aon_gpio_intr11_handler      (void) {cpu_info("[INT]aon_gpio_intr11_handler       hit\n"); send_label(Ext_AON_GPIO_INTR11_IRQn           ); int_flg++;}
void aon_gpio_intr10_handler      (void) {cpu_info("[INT]aon_gpio_intr10_handler       hit\n"); send_label(Ext_AON_GPIO_INTR10_IRQn           ); int_flg++;}
void aon_gpio_intr9_handler       (void) {cpu_info("[INT]aon_gpio_intr9_handler        hit\n"); send_label(Ext_AON_GPIO_INTR9_IRQn            ); int_flg++;}
void aon_gpio_intr8_handler       (void) {cpu_info("[INT]aon_gpio_intr8_handler        hit\n"); send_label(Ext_AON_GPIO_INTR8_IRQn            ); int_flg++;}
void mcu_mailbox_intr15_handler   (void) {cpu_info("[INT]mcu_mailbox_intr15_handler    hit\n"); send_label(Ext_MCU_MAILBOX_INTR15_IRQn        ); int_flg++;}
void mcu_mailbox_intr14_handler   (void) {cpu_info("[INT]mcu_mailbox_intr14_handler    hit\n"); send_label(Ext_MCU_MAILBOX_INTR14_IRQn        ); int_flg++;}
void mcu_mailbox_intr13_handler   (void) {cpu_info("[INT]mcu_mailbox_intr13_handler    hit\n"); send_label(Ext_MCU_MAILBOX_INTR13_IRQn        ); int_flg++;}
void mcu_mailbox_intr12_handler   (void) {cpu_info("[INT]mcu_mailbox_intr12_handler    hit\n"); send_label(Ext_MCU_MAILBOX_INTR12_IRQn        ); int_flg++;}
void mcu_mailbox_intr11_handler   (void) {cpu_info("[INT]mcu_mailbox_intr11_handler    hit\n"); send_label(Ext_MCU_MAILBOX_INTR11_IRQn        ); int_flg++;}
void mcu_mailbox_intr10_handler   (void) {cpu_info("[INT]mcu_mailbox_intr10_handler    hit\n"); send_label(Ext_MCU_MAILBOX_INTR10_IRQn        ); int_flg++;}
void mcu_mailbox_intr9_handler    (void) {cpu_info("[INT]mcu_mailbox_intr9_handler     hit\n"); send_label(Ext_MCU_MAILBOX_INTR9_IRQn         ); int_flg++;}
void mcu_mailbox_intr8_handler    (void) {cpu_info("[INT]mcu_mailbox_intr8_handler     hit\n"); send_label(Ext_MCU_MAILBOX_INTR8_IRQn         ); int_flg++;}
void mcu_dma_ch7_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch7_intr_handler      hit\n"); send_label(Ext_MCU_DMA_CH7_INTR_IRQn          ); int_flg++;}
void mcu_dma_ch6_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch6_intr_handler      hit\n"); send_label(Ext_MCU_DMA_CH6_INTR_IRQn          ); int_flg++;}
void mcu_dma_ch5_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch5_intr_handler      hit\n"); send_label(Ext_MCU_DMA_CH5_INTR_IRQn          ); int_flg++;}
void mcu_dma_ch4_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch4_intr_handler      hit\n"); send_label(Ext_MCU_DMA_CH4_INTR_IRQn          ); int_flg++;}
void mcu_dma_ch3_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch3_intr_handler      hit\n"); send_label(Ext_MCU_DMA_CH3_INTR_IRQn          ); int_flg++;}
void mcu_dma_ch2_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch2_intr_handler      hit\n"); send_label(Ext_MCU_DMA_CH2_INTR_IRQn          ); int_flg++;}
void mcu_dma_ch1_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch1_intr_handler      hit\n"); send_label(Ext_MCU_DMA_CH1_INTR_IRQn          ); int_flg++;}
void mcu_dma_ch0_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch0_intr_handler      hit\n"); send_label(Ext_MCU_DMA_CH0_INTR_IRQn          ); int_flg++;}
//64
void ucie1_mcu_db2soc_irq_handler (void) {cpu_info("[INT]ucie1_mcu_db2soc_irq_handler  hit\n"); send_label(Ext_UCIE1_MCU_DB2SOC_IRQ_IRQn      ); int_flg++;}
void ucie1_dbg_irq_handler        (void) {cpu_info("[INT]ucie1_dbg_irq_handler         hit\n"); send_label(Ext_UCIE1_DBG_IRQ_IRQn             ); int_flg++;}


void ucie0_mcu_db2soc_irq_handler (void) {cpu_info("[INT]ucie0_mcu_db2soc_irq_handler  hit\n"); send_label(Ext_UCIE0_MCU_DB2SOC_IRQ_IRQn      ); int_flg++;}

void ucie0_dbg_irq_handler        (void) {cpu_info("[INT]ucie0_dbg_irq_handler         hit\n"); send_label(Ext_UCIE0_DBG_IRQ_IRQn             ); int_flg++;}

//70
void t2_uee_ras_irpt_handler      (void) {cpu_info("[INT]t2_uee_ras_irpt_handler       hit\n"); send_label(Ext_T2_UEE_RAS_INTR_IRQn           );
            scu_clear_intr_raw(1u << 12);
 int_flg++;}
void hs_eth_intr_handler          (void) {cpu_info("[INT]hs_eth_intr_handler           hit\n"); send_label(Ext_HS_ETH_INTR_IRQn               ); int_flg++;}
void hs_emmc_wakeup_intr_handler  (void) {cpu_info("[INT]hs_emmc_wakeup_intr_handler   hit\n"); send_label(Ext_HS_EMMC_WAKEUP_INTR_IRQn       ); int_flg++;}

void hs_emmc_intr_handler              (void) {  cpu_info("[INT] HS_EMMC_INTR_IRQn            \n") ;send_label(Ext_HS_EMMC_INTR_IRQn            ); int_flg++;}
void hs_usb_tca_intr_handler           (void) {  cpu_info("[INT] HS_USB_TCA_INTR_IRQn         \n") ;send_label(Ext_HS_USB_TCA_INTR_IRQn         ); int_flg++;}
void hs_usb_intr1_handler              (void) {  cpu_info("[INT] HS_USB_INTR1_IRQn            \n") ;send_label(Ext_HS_USB_INTR1_IRQn            ); int_flg++;}
void hs_usb_intr0_handler              (void) {  cpu_info("[INT] HS_USB_INTR0_IRQn            \n") ;send_label(Ext_HS_USB_INTR0_IRQn            ); int_flg++;}
void hs_nvme_intr_handler              (void) {  cpu_info("[INT] HS_NVME_INTR_IRQn            \n") ;send_label(Ext_HS_NVME_INTR_IRQn           ); int_flg++;}
void hs_dma_pmu_irpt_handler           (void) {  cpu_info("[INT] HS_DMA_PMU_IRPT_IRQn         \n") ;send_label(Ext_HS_DMA_PMU_INTR_IRQn         ); 
            scu_clear_intr_raw(1u << 9);
int_flg++;}
void hs_dma_ras_irpt_handler           (void) {  cpu_info("[INT] HS_DMA_RAS_IRPT_IRQn         \n") ;send_label(Ext_HS_DMA_RAS_INTR_IRQn         );
            scu_clear_intr_raw(1u << 10);
int_flg++;}
void hs_dma_ch3_intr_handler           (void) {  cpu_info("[INT] HS_DMA_CH3_INTR_IRQn         \n") ;send_label(Ext_HS_DMA_CH3_INTR_IRQn         ); int_flg++;}
void hs_dma_ch2_intr_handler           (void) {  cpu_info("[INT] HS_DMA_CH2_INTR_IRQn         \n") ;send_label(Ext_HS_DMA_CH2_INTR_IRQn         ); int_flg++;}
void hs_dma_ch1_intr_handler           (void) {  cpu_info("[INT] HS_DMA_CH1_INTR_IRQn         \n") ;send_label(Ext_HS_DMA_CH1_INTR_IRQn         ); int_flg++;}
void hs_dma_ch0_intr_handler           (void) {  cpu_info("[INT] HS_DMA_CH0_INTR_IRQn         \n") ;send_label(Ext_HS_DMA_CH0_INTR_IRQn         ); int_flg++;}
void hs_pciess01_pmu_irpt_handler      (void) {  cpu_info("[INT] HS_PCIESS01_PMU_IRPT_IRQn    \n") ;send_label(Ext_HS_PCIESS01_PMU_INTR_IRQn    ); 
            scu_clear_intr_raw(1u << 13);
int_flg++;}
void hs_pciess01_ras_irpt_handler      (void) {  cpu_info("[INT] HS_PCIESS01_RAS_IRPT_IRQn    \n") ;send_label(Ext_HS_PCIESS01_RAS_INTR_IRQn    );
            scu_clear_intr_raw(1u << 14);
 int_flg++;}
void hs_pciess01_msi_intr_handler      (void) {  cpu_info("[INT] HS_PCIESS01_MSI_INTR_IRQn    \n") ;send_label(Ext_HS_PCIESS01_MSI_INTR_IRQn    ); int_flg++;}
void hs_pciess01_msidone_intr_handler  (void) {  cpu_info("[INT] HS_PCIESS01_MSIDONE_INTR_IRQn\n") ;send_label(Ext_HS_PCIESS01_MSIDONE_INTR_IRQn); int_flg++;}
void hs_pciess01_intx_intr_handler     (void) {  cpu_info("[INT] HS_PCIESS01_INTX_INTR_IRQn   \n") ;send_label(Ext_HS_PCIESS01_INTX_INTR_IRQn   ); int_flg++;}
void hs_pciess01_status_intr_handler   (void) {  cpu_info("[INT] HS_PCIESS01_STATUS_INTR_IRQn \n") ;send_label(Ext_HS_PCIESS01_STATUS_INTR_IRQn ); int_flg++;}
void hs_pciess00_pmu_irpt_handler      (void) {  cpu_info("[INT] HS_PCIESS00_PMU_IRPT_IRQn    \n") ;send_label(Ext_HS_PCIESS00_PMU_INTR_IRQn    );
            scu_clear_intr_raw(1u << 15);
 int_flg++;}
void hs_pciess00_ras_irpt_handler      (void) {  cpu_info("[INT] HS_PCIESS00_RAS_IRPT_IRQn    \n") ;send_label(Ext_HS_PCIESS00_RAS_INTR_IRQn    ); 
            scu_clear_intr_raw(1u << 16);
int_flg++;}
void hs_pciess00_msi_intr_handler      (void) {  cpu_info("[INT] HS_PCIESS00_MSI_INTR_IRQn    \n") ;send_label(Ext_HS_PCIESS00_MSI_INTR_IRQn    ); int_flg++;}
void hs_pciess00_msidone_intr_handler  (void) {  cpu_info("[INT] HS_PCIESS00_MSIDONE_INTR_IRQn\n") ;send_label(Ext_HS_PCIESS00_MSIDONE_INTR_IRQn); int_flg++;}
void hs_pciess00_intx_intr_handler     (void) {  cpu_info("[INT] HS_PCIESS00_INTX_INTR_IRQn   \n") ;send_label(Ext_HS_PCIESS00_INTX_INTR_IRQn   ); int_flg++;}
void hs_pciess00_status_intr_handler   (void) {  cpu_info("[INT] HS_PCIESS00_STATUS_INTR_IRQn \n") ;send_label(Ext_HS_PCIESS00_STATUS_INTR_IRQn ); int_flg++;}

void lp3_ddr_int_handler           (void) {  cpu_info("[INT] LP3_DDR_INT_IRQn         \n") ;send_label(Ext_LP3_DDR_INT_IRQn         ); int_flg++;}
void lp2_ddr_int_handler           (void) {  cpu_info("[INT] LP2_DDR_INT_IRQn         \n") ;send_label(Ext_LP2_DDR_INT_IRQn         ); int_flg++;}
void lp1_ddr_int_handler           (void) {  cpu_info("[INT] LP1_DDR_INT_IRQn         \n") ;send_label(Ext_LP1_DDR_INT_IRQn         ); int_flg++;}
void lp0_ddr_int_handler           (void) {  cpu_info("[INT] LP0_DDR_INT_IRQn         \n") ;send_label(Ext_LP0_DDR_INT_IRQn         ); int_flg++;}
void media_sub_dpu_intr_handler    (void) {  cpu_info("[INT] MEDIA_SUB_DPU_INTR_IRQn  \n") ;send_label(Ext_MEDIA_SUB_DPU_INTR_IRQn  ); int_flg++;}
void media_sub_gpu_intr_handler    (void) {  cpu_info("[INT] MEDIA_SUB_GPU_INTR_IRQn  \n") ;send_label(Ext_MEDIA_SUB_GPU_INTR_IRQn  ); int_flg++;}
void media_sub_jpu_intr_handler    (void) {  cpu_info("[INT] MEDIA_SUB_JPU_INTR_IRQn  \n") ;send_label(Ext_MEDIA_SUB_JPU_INTR_IRQn  ); int_flg++;}
void media_sub_vpu_intr_3_handler  (void) {  cpu_info("[INT] MEDIA_SUB_VPU_INTR_3_IRQn\n") ;send_label(Ext_MEDIA_SUB_VPU_INTR_3_IRQn); int_flg++;}
void media_sub_vpu_intr_2_handler  (void) {  cpu_info("[INT] MEDIA_SUB_VPU_INTR_2_IRQn\n") ;send_label(Ext_MEDIA_SUB_VPU_INTR_2_IRQn); int_flg++;}
void media_sub_vpu_intr_1_handler  (void) {  cpu_info("[INT] MEDIA_SUB_VPU_INTR_1_IRQn\n") ;send_label(Ext_MEDIA_SUB_VPU_INTR_1_IRQn); int_flg++;}
void media_sub_vpu_intr_0_handler  (void) {  cpu_info("[INT] MEDIA_SUB_VPU_INTR_0_IRQn\n") ;send_label(Ext_MEDIA_SUB_VPU_INTR_0_IRQn); int_flg++;}

void mcu_i2s1_intr_handler         (void) {  cpu_info("[INT] MCU_I2S1_INTR_IRQn       \n") ;send_label(Ext_MCU_I2S1_INTR_IRQn       ); int_flg++;}
void mcu_i3c1_intr_handler         (void) {  cpu_info("[INT] MCU_I2S1_INTR_IRQn       \n") ;send_label(Ext_MCU_I3C1_INTR_IRQn       ); int_flg++;}
void mcu_i2c3_intr_handler         (void) {  cpu_info("[INT] MCU_I2C3_INTR_IRQn       \n") ;send_label(Ext_MCU_I2C3_INTR_IRQn       ); int_flg++;}

void mcu_i2c2_intr_handler         (void) {  cpu_info("[INT] MCU_I2C2_INTR_IRQn       \n") ;send_label(Ext_MCU_I2C2_INTR_IRQn       ); int_flg++;}     //111

void mcu_xspi1_intr_handler         (void){  cpu_info("[INT] MCU_XSPI1_INTR_IRQn       \n") ;send_label(Ext_MCU_XSPI1_INTR_IRQn       ); int_flg++;}  
void mcu_spi1_intr_handler         (void) {  cpu_info("[INT] MCU_SPI1_INTR_IRQn       \n") ;send_label(Ext_MCU_SPI1_INTR_IRQn       ); int_flg++;}    
void mcu_uart3_intr_handler         (void) {  cpu_info("[INT] MCU_UART3_INTR_IRQn       \n") ;send_label(Ext_MCU_UART3_INTR_IRQn       ); int_flg++;}  
void mcu_uart2_intr_handler         (void) {  cpu_info("[INT] MCU_UART2_INTR_IRQn       \n") ;send_label(Ext_MCU_UART2_INTR_IRQn       ); int_flg++;}    
void mcu_timer1_intr_handler         (void) {  cpu_info("[INT] MCU_TIMER1_INTR_IRQn       \n") ;send_label(Ext_MCU_TIMER1_INTR_IRQn       ); int_flg++;}  
void mcu_timer0_intr_handler         (void) {  cpu_info("[INT] MCU_TIMER0_INTR_IRQn       \n") ;send_label(Ext_MCU_TIMER0_INTR_IRQn       ); int_flg++;


    irq_num = Ext_MCU_TIMER0_INTR_IRQn;
} //andyf

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

    cpu_info("PLIC_Interrupt_Init start 1111111\n");
    // Initialize interrupt mode to clint/plic mode
    PLIC_Interrupt_Init();
    cpu_info("PLIC_Interrupt_Init finish \n");

    // inital timer interrupt as non-vector interrupt

    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR31_IRQn                 ,    1, (void*)mcu_gpio_intr31_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR30_IRQn                 ,    1, (void*)mcu_gpio_intr30_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR29_IRQn                 ,    1, (void*)mcu_gpio_intr29_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR28_IRQn                 ,    1, (void*)mcu_gpio_intr28_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR27_IRQn                 ,    1, (void*)mcu_gpio_intr27_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR26_IRQn                 ,    1, (void*)mcu_gpio_intr26_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR25_IRQn                 ,    1, (void*)mcu_gpio_intr25_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR24_IRQn                 ,    1, (void*)mcu_gpio_intr24_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR23_IRQn                 ,    1, (void*)mcu_gpio_intr23_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR22_IRQn                 ,    1, (void*)mcu_gpio_intr22_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR21_IRQn                 ,    1, (void*)mcu_gpio_intr21_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR20_IRQn                 ,    1, (void*)mcu_gpio_intr20_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR19_IRQn                 ,    1, (void*)mcu_gpio_intr19_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR18_IRQn                 ,    1, (void*)mcu_gpio_intr18_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR17_IRQn                 ,    1, (void*)mcu_gpio_intr17_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR16_IRQn                 ,    1, (void*)mcu_gpio_intr16_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR15_IRQn                 ,    1, (void*)mcu_gpio_intr15_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR14_IRQn                 ,    1, (void*)mcu_gpio_intr14_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR13_IRQn                 ,    1, (void*)mcu_gpio_intr13_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR12_IRQn                 ,    1, (void*)mcu_gpio_intr12_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR11_IRQn                 ,    1, (void*)mcu_gpio_intr11_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR10_IRQn                 ,    1, (void*)mcu_gpio_intr10_handler              );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR9_IRQn                  ,    1, (void*)mcu_gpio_intr9_handler               );
    returnCode = PLIC_Register_IRQ(Ext_MCU_GPIO_INTR8_IRQn                  ,    1, (void*)mcu_gpio_intr8_handler               );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR31_IRQn                 ,    1, (void*)aon_gpio_intr31_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR30_IRQn                 ,    1, (void*)aon_gpio_intr30_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR29_IRQn                 ,    1, (void*)aon_gpio_intr29_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR28_IRQn                 ,    1, (void*)aon_gpio_intr28_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR27_IRQn                 ,    1, (void*)aon_gpio_intr27_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR26_IRQn                 ,    1, (void*)aon_gpio_intr26_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR25_IRQn                 ,    1, (void*)aon_gpio_intr25_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR24_IRQn                 ,    1, (void*)aon_gpio_intr24_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR23_IRQn                 ,    1, (void*)aon_gpio_intr23_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR22_IRQn                 ,    1, (void*)aon_gpio_intr22_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR21_IRQn                 ,    1, (void*)aon_gpio_intr21_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR20_IRQn                 ,    1, (void*)aon_gpio_intr20_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR19_IRQn                 ,    1, (void*)aon_gpio_intr19_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR18_IRQn                 ,    1, (void*)aon_gpio_intr18_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR17_IRQn                 ,    1, (void*)aon_gpio_intr17_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR16_IRQn                 ,    1, (void*)aon_gpio_intr16_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR15_IRQn                 ,    1, (void*)aon_gpio_intr15_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR14_IRQn                 ,    1, (void*)aon_gpio_intr14_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR13_IRQn                 ,    1, (void*)aon_gpio_intr13_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR12_IRQn                 ,    1, (void*)aon_gpio_intr12_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR11_IRQn                 ,    1, (void*)aon_gpio_intr11_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR10_IRQn                 ,    1, (void*)aon_gpio_intr10_handler              );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR9_IRQn                  ,    1, (void*)aon_gpio_intr9_handler               );
    returnCode = PLIC_Register_IRQ(Ext_AON_GPIO_INTR8_IRQn                  ,    1, (void*)aon_gpio_intr8_handler               );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR15_IRQn              ,    1, (void*)mcu_mailbox_intr15_handler           );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR14_IRQn              ,    1, (void*)mcu_mailbox_intr14_handler           );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR13_IRQn              ,    1, (void*)mcu_mailbox_intr13_handler           );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR12_IRQn              ,    1, (void*)mcu_mailbox_intr12_handler           );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR11_IRQn              ,    1, (void*)mcu_mailbox_intr11_handler           );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR10_IRQn              ,    1, (void*)mcu_mailbox_intr10_handler           );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR9_IRQn               ,    1, (void*)mcu_mailbox_intr9_handler            );
    returnCode = PLIC_Register_IRQ(Ext_MCU_MAILBOX_INTR8_IRQn               ,    1, (void*)mcu_mailbox_intr8_handler            );
    returnCode = PLIC_Register_IRQ(Ext_MCU_DMA_CH7_INTR_IRQn                ,    1, (void*)mcu_dma_ch7_intr_handler             );
    returnCode = PLIC_Register_IRQ(Ext_MCU_DMA_CH6_INTR_IRQn                ,    1, (void*)mcu_dma_ch6_intr_handler             );
    returnCode = PLIC_Register_IRQ(Ext_MCU_DMA_CH5_INTR_IRQn                ,    1, (void*)mcu_dma_ch5_intr_handler             );
    returnCode = PLIC_Register_IRQ(Ext_MCU_DMA_CH4_INTR_IRQn                ,    1, (void*)mcu_dma_ch4_intr_handler             );
    returnCode = PLIC_Register_IRQ(Ext_MCU_DMA_CH3_INTR_IRQn                ,    1, (void*)mcu_dma_ch3_intr_handler             );
    returnCode = PLIC_Register_IRQ(Ext_MCU_DMA_CH2_INTR_IRQn                ,    1, (void*)mcu_dma_ch2_intr_handler             );
    returnCode = PLIC_Register_IRQ(Ext_MCU_DMA_CH1_INTR_IRQn                ,    1, (void*)mcu_dma_ch1_intr_handler             );
    returnCode = PLIC_Register_IRQ(Ext_MCU_DMA_CH0_INTR_IRQn                ,    1, (void*)mcu_dma_ch0_intr_handler             );

    returnCode = PLIC_Register_IRQ(Ext_UCIE1_MCU_DB2SOC_IRQ_IRQn            ,    1, (void*)ucie1_mcu_db2soc_irq_handler         );
    returnCode = PLIC_Register_IRQ(Ext_UCIE1_DBG_IRQ_IRQn                   ,    1, (void*)ucie1_dbg_irq_handler                );

    returnCode = PLIC_Register_IRQ(Ext_UCIE0_MCU_DB2SOC_IRQ_IRQn            ,    1, (void*)ucie0_mcu_db2soc_irq_handler         );

    returnCode = PLIC_Register_IRQ(Ext_UCIE0_DBG_IRQ_IRQn                   ,    1, (void*)ucie0_dbg_irq_handler                );

    returnCode = PLIC_Register_IRQ(Ext_T2_UEE_RAS_INTR_IRQn                 ,    1, (void*)t2_uee_ras_irpt_handler              );
    returnCode = PLIC_Register_IRQ(Ext_HS_ETH_INTR_IRQn                     ,    1, (void*)hs_eth_intr_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_HS_EMMC_WAKEUP_INTR_IRQn             ,    1, (void*)hs_emmc_wakeup_intr_handler          );
    returnCode = PLIC_Register_IRQ(Ext_HS_EMMC_INTR_IRQn                    ,    1, (void*)hs_emmc_intr_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_HS_USB_TCA_INTR_IRQn                 ,    1, (void*)hs_usb_tca_intr_handler              );
    returnCode = PLIC_Register_IRQ(Ext_HS_USB_INTR1_IRQn                    ,    1, (void*)hs_usb_intr1_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_HS_USB_INTR0_IRQn                    ,    1, (void*)hs_usb_intr0_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_HS_NVME_INTR_IRQn                    ,    1, (void*)hs_nvme_intr_handler                 );
    returnCode = PLIC_Register_IRQ(Ext_HS_DMA_PMU_INTR_IRQn                 ,    1, (void*)hs_dma_pmu_irpt_handler              );
    returnCode = PLIC_Register_IRQ(Ext_HS_DMA_RAS_INTR_IRQn                 ,    1, (void*)hs_dma_ras_irpt_handler              );
    returnCode = PLIC_Register_IRQ(Ext_HS_DMA_CH3_INTR_IRQn                 ,    1, (void*)hs_dma_ch3_intr_handler              );
    returnCode = PLIC_Register_IRQ(Ext_HS_DMA_CH2_INTR_IRQn                 ,    1, (void*)hs_dma_ch2_intr_handler              );
    returnCode = PLIC_Register_IRQ(Ext_HS_DMA_CH1_INTR_IRQn                 ,    1, (void*)hs_dma_ch1_intr_handler              );
    returnCode = PLIC_Register_IRQ(Ext_HS_DMA_CH0_INTR_IRQn                 ,    1, (void*)hs_dma_ch0_intr_handler              );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS01_PMU_INTR_IRQn            ,    1, (void*)hs_pciess01_pmu_irpt_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS01_RAS_INTR_IRQn            ,    1, (void*)hs_pciess01_ras_irpt_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS01_MSI_INTR_IRQn            ,    1, (void*)hs_pciess01_msi_intr_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS01_MSIDONE_INTR_IRQn        ,    1, (void*)hs_pciess01_msidone_intr_handler     );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS01_INTX_INTR_IRQn           ,    1, (void*)hs_pciess01_intx_intr_handler        );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS01_STATUS_INTR_IRQn         ,    1, (void*)hs_pciess01_status_intr_handler      );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS00_PMU_INTR_IRQn            ,    1, (void*)hs_pciess00_pmu_irpt_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS00_RAS_INTR_IRQn            ,    1, (void*)hs_pciess00_ras_irpt_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS00_MSI_INTR_IRQn            ,    1, (void*)hs_pciess00_msi_intr_handler         );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS00_MSIDONE_INTR_IRQn        ,    1, (void*)hs_pciess00_msidone_intr_handler     );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS00_INTX_INTR_IRQn           ,    1, (void*)hs_pciess00_intx_intr_handler        );
    returnCode = PLIC_Register_IRQ(Ext_HS_PCIESS00_STATUS_INTR_IRQn         ,    1, (void*)hs_pciess00_status_intr_handler      );

    returnCode = PLIC_Register_IRQ(Ext_LP3_DDR_INT_IRQn                     ,    1, (void*)lp3_ddr_int_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_LP2_DDR_INT_IRQn                     ,    1, (void*)lp2_ddr_int_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_LP1_DDR_INT_IRQn                     ,    1, (void*)lp1_ddr_int_handler                  );
    returnCode = PLIC_Register_IRQ(Ext_LP0_DDR_INT_IRQn                     ,    1, (void*)lp0_ddr_int_handler                  );

    returnCode = PLIC_Register_IRQ(Ext_MEDIA_SUB_DPU_INTR_IRQn              ,    1, (void*)media_sub_dpu_intr_handler           );
    returnCode = PLIC_Register_IRQ(Ext_MEDIA_SUB_GPU_INTR_IRQn              ,    1, (void*)media_sub_gpu_intr_handler           );
    returnCode = PLIC_Register_IRQ(Ext_MEDIA_SUB_JPU_INTR_IRQn              ,    1, (void*)media_sub_jpu_intr_handler           );
    returnCode = PLIC_Register_IRQ(Ext_MEDIA_SUB_VPU_INTR_3_IRQn            ,    1, (void*)media_sub_vpu_intr_3_handler         );
    returnCode = PLIC_Register_IRQ(Ext_MEDIA_SUB_VPU_INTR_2_IRQn            ,    1, (void*)media_sub_vpu_intr_2_handler         );
    returnCode = PLIC_Register_IRQ(Ext_MEDIA_SUB_VPU_INTR_1_IRQn            ,    1, (void*)media_sub_vpu_intr_1_handler         );
    returnCode = PLIC_Register_IRQ(Ext_MEDIA_SUB_VPU_INTR_0_IRQn            ,    1, (void*)media_sub_vpu_intr_0_handler         );

    returnCode = PLIC_Register_IRQ(Ext_MCU_I2S1_INTR_IRQn                   ,    1, (void*)mcu_i2s1_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_MCU_I3C1_INTR_IRQn                   ,    1, (void*)mcu_i3c1_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_MCU_I2C3_INTR_IRQn                   ,    1, (void*)mcu_i2c3_intr_handler                );

    returnCode = PLIC_Register_IRQ(Ext_MCU_I2C2_INTR_IRQn                   ,    1, (void*)mcu_i2c2_intr_handler                );

    returnCode = PLIC_Register_IRQ(Ext_MCU_XSPI1_INTR_IRQn                   ,    1, (void*)mcu_xspi1_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_MCU_SPI1_INTR_IRQn                   ,    1, (void*)mcu_spi1_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_MCU_UART3_INTR_IRQn                   ,    1, (void*)mcu_uart3_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_MCU_UART2_INTR_IRQn                   ,    1, (void*)mcu_uart2_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_MCU_TIMER1_INTR_IRQn                   ,    1, (void*)mcu_timer1_intr_handler                );
    returnCode = PLIC_Register_IRQ(Ext_MCU_TIMER0_INTR_IRQn                   ,    1, (void*)mcu_timer0_intr_handler                );
//117
//

    __enable_irq();

    send_label(0x12345678);

    while(irq_num != Ext_MCU_TIMER0_INTR_IRQn);
    cpu_info("cpu test done !!!\n");

    simend();
    while(1);
}
