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

//70
__INTERRUPT void t2_uee_ras_irpt_handler      (void) {cpu_info("[INT]t2_uee_ras_irpt_handler       hit\n"); send_label(T2_UEE_RAS_INTR_IRQn           );
            scu_clear_intr_raw(1u << 12);
 int_flg++;}
__INTERRUPT void hs_eth_intr_handler          (void) {cpu_info("[INT]hs_eth_intr_handler           hit\n"); send_label(HS_ETH_INTR_IRQn               ); int_flg++;}
__INTERRUPT void hs_emmc_wakeup_intr_handler  (void) {cpu_info("[INT]hs_emmc_wakeup_intr_handler   hit\n"); send_label(HS_EMMC_WAKEUP_INTR_IRQn       ); int_flg++;}
__INTERRUPT void hs_emmc_intr_handler              (void) {  cpu_info("[INT] HS_EMMC_INTR_IRQn            \n") ;send_label(HS_EMMC_INTR_IRQn            ); int_flg++;}
__INTERRUPT void hs_usb_tca_intr_handler           (void) {  cpu_info("[INT] HS_USB_TCA_INTR_IRQn         \n") ;send_label(HS_USB_TCA_INTR_IRQn         ); int_flg++;}
__INTERRUPT void hs_usb_intr1_handler              (void) {  cpu_info("[INT] HS_USB_INTR1_IRQn            \n") ;send_label(HS_USB_INTR1_IRQn            ); int_flg++;}
__INTERRUPT void hs_usb_intr0_handler              (void) {  cpu_info("[INT] HS_USB_INTR0_IRQn            \n") ;send_label(HS_USB_INTR0_IRQn            ); int_flg++;}
__INTERRUPT void hs_nvme_intr_handler              (void) {  cpu_info("[INT] HS_NVME_INTR_IRQn            \n") ;send_label(HS_NVME_INTR_IRQn           ); int_flg++;}
__INTERRUPT void hs_dma_pmu_irpt_handler           (void) {  cpu_info("[INT] HS_DMA_PMU_IRPT_IRQn         \n") ;send_label(HS_DMA_PMU_INTR_IRQn         );
            scu_clear_intr_raw(1u << 9);
 int_flg++;}
__INTERRUPT void hs_dma_ras_irpt_handler           (void) {  cpu_info("[INT] HS_DMA_RAS_IRPT_IRQn         \n") ;send_label(HS_DMA_RAS_INTR_IRQn         );
            scu_clear_intr_raw(1u << 10);
 int_flg++;}
__INTERRUPT void hs_dma_ch3_intr_handler           (void) {  cpu_info("[INT] HS_DMA_CH3_INTR_IRQn         \n") ;send_label(HS_DMA_CH3_INTR_IRQn         ); int_flg++;}
__INTERRUPT void hs_dma_ch2_intr_handler           (void) {  cpu_info("[INT] HS_DMA_CH2_INTR_IRQn         \n") ;send_label(HS_DMA_CH2_INTR_IRQn         ); int_flg++;}
__INTERRUPT void hs_dma_ch1_intr_handler           (void) {  cpu_info("[INT] HS_DMA_CH1_INTR_IRQn         \n") ;send_label(HS_DMA_CH1_INTR_IRQn         ); int_flg++;}
__INTERRUPT void hs_dma_ch0_intr_handler           (void) {  cpu_info("[INT] HS_DMA_CH0_INTR_IRQn         \n") ;send_label(HS_DMA_CH0_INTR_IRQn         ); int_flg++;}
__INTERRUPT void hs_pciess01_pmu_irpt_handler      (void) {  cpu_info("[INT] HS_PCIESS01_PMU_IRPT_IRQn    \n") ;send_label(HS_PCIESS01_PMU_INTR_IRQn    );
            scu_clear_intr_raw(1u << 13);
 int_flg++;}
__INTERRUPT void hs_pciess01_ras_irpt_handler      (void) {  cpu_info("[INT] HS_PCIESS01_RAS_IRPT_IRQn    \n") ;send_label(HS_PCIESS01_RAS_INTR_IRQn    );
            scu_clear_intr_raw(1u << 14);
 int_flg++;}
__INTERRUPT void hs_pciess01_msi_intr_handler      (void) {  cpu_info("[INT] HS_PCIESS01_MSI_INTR_IRQn    \n") ;send_label(HS_PCIESS01_MSI_INTR_IRQn    ); int_flg++;}
__INTERRUPT void hs_pciess01_msidone_intr_handler  (void) {  cpu_info("[INT] HS_PCIESS01_MSIDONE_INTR_IRQn\n") ;send_label(HS_PCIESS01_MSIDONE_INTR_IRQn); int_flg++;}
__INTERRUPT void hs_pciess01_intx_intr_handler     (void) {  cpu_info("[INT] HS_PCIESS01_INTX_INTR_IRQn   \n") ;send_label(HS_PCIESS01_INTX_INTR_IRQn   ); int_flg++;}
__INTERRUPT void hs_pciess01_status_intr_handler   (void) {  cpu_info("[INT] HS_PCIESS01_STATUS_INTR_IRQn \n") ;send_label(HS_PCIESS01_STATUS_INTR_IRQn ); int_flg++;}
__INTERRUPT void hs_pciess00_pmu_irpt_handler      (void) {  cpu_info("[INT] HS_PCIESS00_PMU_IRPT_IRQn    \n") ;send_label(HS_PCIESS00_PMU_INTR_IRQn    );
            scu_clear_intr_raw(1u << 15);
 int_flg++;}
__INTERRUPT void hs_pciess00_ras_irpt_handler      (void) {  cpu_info("[INT] HS_PCIESS00_RAS_IRPT_IRQn    \n") ;send_label(HS_PCIESS00_RAS_INTR_IRQn    );
            scu_clear_intr_raw(1u << 16);
 int_flg++;}
__INTERRUPT void hs_pciess00_msi_intr_handler      (void) {  cpu_info("[INT] HS_PCIESS00_MSI_INTR_IRQn    \n") ;send_label(HS_PCIESS00_MSI_INTR_IRQn    ); int_flg++;}
__INTERRUPT void hs_pciess00_msidone_intr_handler  (void) {  cpu_info("[INT] HS_PCIESS00_MSIDONE_INTR_IRQn\n") ;send_label(HS_PCIESS00_MSIDONE_INTR_IRQn); int_flg++;}
__INTERRUPT void hs_pciess00_intx_intr_handler     (void) {  cpu_info("[INT] HS_PCIESS00_INTX_INTR_IRQn   \n") ;send_label(HS_PCIESS00_INTX_INTR_IRQn   ); int_flg++;}
__INTERRUPT void hs_pciess00_status_intr_handler   (void) {  cpu_info("[INT] HS_PCIESS00_STATUS_INTR_IRQn \n") ;send_label(HS_PCIESS00_STATUS_INTR_IRQn ); int_flg++;}
__INTERRUPT void lp3_ddr_int_handler           (void) {  cpu_info("[INT] LP3_DDR_INT_IRQn         \n") ;send_label(LP3_DDR_INT_IRQn         ); int_flg++;}
__INTERRUPT void lp2_ddr_int_handler           (void) {  cpu_info("[INT] LP2_DDR_INT_IRQn         \n") ;send_label(LP2_DDR_INT_IRQn         ); int_flg++;}
__INTERRUPT void lp1_ddr_int_handler           (void) {  cpu_info("[INT] LP1_DDR_INT_IRQn         \n") ;send_label(LP1_DDR_INT_IRQn         ); int_flg++;}
__INTERRUPT void lp0_ddr_int_handler           (void) {  cpu_info("[INT] LP0_DDR_INT_IRQn         \n") ;send_label(LP0_DDR_INT_IRQn         ); int_flg++;}
__INTERRUPT void media_sub_dpu_intr_handler    (void) {  cpu_info("[INT] MEDIA_SUB_DPU_INTR_IRQn  \n") ;send_label(MEDIA_SUB_DPU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void media_sub_gpu_intr_handler    (void) {  cpu_info("[INT] MEDIA_SUB_GPU_INTR_IRQn  \n") ;send_label(MEDIA_SUB_GPU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void media_sub_jpu_intr_handler    (void) {  cpu_info("[INT] MEDIA_SUB_JPU_INTR_IRQn  \n") ;send_label(MEDIA_SUB_JPU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void media_sub_vpu_intr_3_handler  (void) {  cpu_info("[INT] MEDIA_SUB_VPU_INTR_3_IRQn\n") ;send_label(MEDIA_SUB_VPU_INTR_3_IRQn); int_flg++;}
__INTERRUPT void media_sub_vpu_intr_2_handler  (void) {  cpu_info("[INT] MEDIA_SUB_VPU_INTR_2_IRQn\n") ;send_label(MEDIA_SUB_VPU_INTR_2_IRQn); int_flg++;}
__INTERRUPT void media_sub_vpu_intr_1_handler  (void) {  cpu_info("[INT] MEDIA_SUB_VPU_INTR_1_IRQn\n") ;send_label(MEDIA_SUB_VPU_INTR_1_IRQn); int_flg++;}
__INTERRUPT void media_sub_vpu_intr_0_handler  (void) {  cpu_info("[INT] MEDIA_SUB_VPU_INTR_0_IRQn\n") ;send_label(MEDIA_SUB_VPU_INTR_0_IRQn); int_flg++;}
__INTERRUPT void mcu_i2s1_intr_handler         (void) {  cpu_info("[INT] MCU_I2S1_INTR_IRQn       \n") ;send_label(MCU_I2S1_INTR_IRQn       ); int_flg++;}
__INTERRUPT void mcu_i3c1_intr_handler         (void) {  cpu_info("[INT] MCU_I2S1_INTR_IRQn       \n") ;send_label(MCU_I3C1_INTR_IRQn       ); int_flg++;}
__INTERRUPT void mcu_i2c3_intr_handler         (void) {  cpu_info("[INT] MCU_I2C3_INTR_IRQn       \n") ;send_label(MCU_I2C3_INTR_IRQn       ); int_flg++;}
__INTERRUPT void mcu_i2c2_intr_handler         (void) {  cpu_info("[INT] MCU_I2C2_INTR_IRQn       \n") ;send_label(MCU_I2C2_INTR_IRQn       ); int_flg++;}     //111
__INTERRUPT void mcu_xspi1_intr_handler         (void){  cpu_info("[INT] MCU_XSPI1_INTR_IRQn       \n") ;send_label(MCU_XSPI1_INTR_IRQn       ); int_flg++;}  
__INTERRUPT void mcu_spi1_intr_handler         (void) {  cpu_info("[INT] MCU_SPI1_INTR_IRQn       \n") ;send_label(MCU_SPI1_INTR_IRQn       ); int_flg++;}    
__INTERRUPT void ucie0_dbg_irq_handler         (void) {  cpu_info("[INT]UCIE0_DBG_IRQ_IRQn          \n"); send_label(UCIE0_DBG_IRQ_IRQn     ); int_flg++;}
__INTERRUPT void mcu_uart3_intr_handler         (void) {  cpu_info("[INT] MCU_UART3_INTR_IRQn       \n") ;send_label(MCU_UART3_INTR_IRQn       ); int_flg++;}  
__INTERRUPT void mcu_uart2_intr_handler         (void) {  cpu_info("[INT] MCU_UART2_INTR_IRQn       \n") ;send_label(MCU_UART2_INTR_IRQn       ); int_flg++;}    
__INTERRUPT void mcu_timer1_intr_handler         (void) {  cpu_info("[INT] MCU_TIMER1_INTR_IRQn       \n") ;send_label(MCU_TIMER1_INTR_IRQn       ); int_flg++;}  
__INTERRUPT void mcu_timer0_intr_handler         (void) {  cpu_info("[INT] MCU_TIMER0_INTR_IRQn       \n") ;send_label(MCU_TIMER0_INTR_IRQn       ); int_flg++;


    irq_num = MCU_TIMER0_INTR_IRQn;
} //andyf

int main(void)
{
    uint32_t returnCode;
    CSR_MCFGINFO_Type mcfg;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    cpu_info("ECLIC_Interrupt_Test start 1111111\n");
    
    returnCode = ECLIC_Register_IRQ(UCIE0_DBG_IRQ_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)ucie0_dbg_irq_handler                );
    returnCode = ECLIC_Register_IRQ(T2_UEE_RAS_INTR_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)t2_uee_ras_irpt_handler              );
    returnCode = ECLIC_Register_IRQ(HS_ETH_INTR_IRQn              ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_eth_intr_handler                  );
    returnCode = ECLIC_Register_IRQ(HS_EMMC_WAKEUP_INTR_IRQn      ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_emmc_wakeup_intr_handler          );
    returnCode = ECLIC_Register_IRQ(HS_EMMC_INTR_IRQn             ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_emmc_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(HS_USB_TCA_INTR_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_usb_tca_intr_handler              );
    returnCode = ECLIC_Register_IRQ(HS_USB_INTR1_IRQn             ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_usb_intr1_handler                 );
    returnCode = ECLIC_Register_IRQ(HS_USB_INTR0_IRQn             ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_usb_intr0_handler                 );
    returnCode = ECLIC_Register_IRQ(HS_NVME_INTR_IRQn             ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_nvme_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(HS_DMA_PMU_INTR_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_dma_pmu_irpt_handler              );
    returnCode = ECLIC_Register_IRQ(HS_DMA_RAS_INTR_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_dma_ras_irpt_handler              );
    returnCode = ECLIC_Register_IRQ(HS_DMA_CH3_INTR_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_dma_ch3_intr_handler              );
    returnCode = ECLIC_Register_IRQ(HS_DMA_CH2_INTR_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_dma_ch2_intr_handler              );
    returnCode = ECLIC_Register_IRQ(HS_DMA_CH1_INTR_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_dma_ch1_intr_handler              );
    returnCode = ECLIC_Register_IRQ(HS_DMA_CH0_INTR_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_dma_ch0_intr_handler              );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS01_PMU_INTR_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess01_pmu_irpt_handler         );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS01_RAS_INTR_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess01_ras_irpt_handler         );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS01_MSI_INTR_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess01_msi_intr_handler         );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS01_MSIDONE_INTR_IRQn ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess01_msidone_intr_handler     );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS01_INTX_INTR_IRQn    ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess01_intx_intr_handler        );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS01_STATUS_INTR_IRQn  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess01_status_intr_handler      );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS00_PMU_INTR_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess00_pmu_irpt_handler         );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS00_RAS_INTR_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess00_ras_irpt_handler         );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS00_MSI_INTR_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess00_msi_intr_handler         );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS00_MSIDONE_INTR_IRQn ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess00_msidone_intr_handler     );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS00_INTX_INTR_IRQn    ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess00_intx_intr_handler        );
    returnCode = ECLIC_Register_IRQ(HS_PCIESS00_STATUS_INTR_IRQn  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)hs_pciess00_status_intr_handler      );
    returnCode = ECLIC_Register_IRQ(LP3_DDR_INT_IRQn              ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)lp3_ddr_int_handler                  );
    returnCode = ECLIC_Register_IRQ(LP2_DDR_INT_IRQn              ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)lp2_ddr_int_handler                  );
    returnCode = ECLIC_Register_IRQ(LP1_DDR_INT_IRQn              ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)lp1_ddr_int_handler                  );
    returnCode = ECLIC_Register_IRQ(LP0_DDR_INT_IRQn              ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)lp0_ddr_int_handler                  );
    returnCode = ECLIC_Register_IRQ(MEDIA_SUB_DPU_INTR_IRQn       ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)media_sub_dpu_intr_handler           );
    returnCode = ECLIC_Register_IRQ(MEDIA_SUB_GPU_INTR_IRQn       ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)media_sub_gpu_intr_handler           );
    returnCode = ECLIC_Register_IRQ(MEDIA_SUB_JPU_INTR_IRQn       ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)media_sub_jpu_intr_handler           );
    returnCode = ECLIC_Register_IRQ(MEDIA_SUB_VPU_INTR_3_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)media_sub_vpu_intr_3_handler         );
    returnCode = ECLIC_Register_IRQ(MEDIA_SUB_VPU_INTR_2_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)media_sub_vpu_intr_2_handler         );
    returnCode = ECLIC_Register_IRQ(MEDIA_SUB_VPU_INTR_1_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)media_sub_vpu_intr_1_handler         );
    returnCode = ECLIC_Register_IRQ(MEDIA_SUB_VPU_INTR_0_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)media_sub_vpu_intr_0_handler         );
    returnCode = ECLIC_Register_IRQ(MCU_I2S1_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_i2s1_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_I3C1_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_i3c1_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_I2C3_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_i2c3_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_I2C2_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_i2c2_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_XSPI1_INTR_IRQn           ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_xspi1_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_SPI1_INTR_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_spi1_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_UART3_INTR_IRQn           ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_uart3_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_UART2_INTR_IRQn           ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_uart2_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_TIMER1_INTR_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_timer1_intr_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_TIMER0_INTR_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_timer0_intr_handler                );
//117
//

    __enable_irq();

    send_label(0x12345678);

    while(irq_num != MCU_TIMER0_INTR_IRQn);
    cpu_info("cpu test done !!!\n");

    simend();
    while(1);
}
