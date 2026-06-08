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

__INTERRUPT void mcu_gpio_intr31_handler      (void) {cpu_info("[INT]mcu_gpio_intr31_handler       hit\n"); send_label(MCU_GPIO_INTR31_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr30_handler      (void) {cpu_info("[INT]mcu_gpio_intr30_handler       hit\n"); send_label(MCU_GPIO_INTR30_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr29_handler      (void) {cpu_info("[INT]mcu_gpio_intr29_handler       hit\n"); send_label(MCU_GPIO_INTR29_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr28_handler      (void) {cpu_info("[INT]mcu_gpio_intr28_handler       hit\n"); send_label(MCU_GPIO_INTR28_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr27_handler      (void) {cpu_info("[INT]mcu_gpio_intr27_handler       hit\n"); send_label(MCU_GPIO_INTR27_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr26_handler      (void) {cpu_info("[INT]mcu_gpio_intr26_handler       hit\n"); send_label(MCU_GPIO_INTR26_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr25_handler      (void) {cpu_info("[INT]mcu_gpio_intr25_handler       hit\n"); send_label(MCU_GPIO_INTR25_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr24_handler      (void) {cpu_info("[INT]mcu_gpio_intr24_handler       hit\n"); send_label(MCU_GPIO_INTR24_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr23_handler      (void) {cpu_info("[INT]mcu_gpio_intr23_handler       hit\n"); send_label(MCU_GPIO_INTR23_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr22_handler      (void) {cpu_info("[INT]mcu_gpio_intr22_handler       hit\n"); send_label(MCU_GPIO_INTR22_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr21_handler      (void) {cpu_info("[INT]mcu_gpio_intr21_handler       hit\n"); send_label(MCU_GPIO_INTR21_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr20_handler      (void) {cpu_info("[INT]mcu_gpio_intr20_handler       hit\n"); send_label(MCU_GPIO_INTR20_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr19_handler      (void) {cpu_info("[INT]mcu_gpio_intr19_handler       hit\n"); send_label(MCU_GPIO_INTR19_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr18_handler      (void) {cpu_info("[INT]mcu_gpio_intr18_handler       hit\n"); send_label(MCU_GPIO_INTR18_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr17_handler      (void) {cpu_info("[INT]mcu_gpio_intr17_handler       hit\n"); send_label(MCU_GPIO_INTR17_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr16_handler      (void) {cpu_info("[INT]mcu_gpio_intr16_handler       hit\n"); send_label(MCU_GPIO_INTR16_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr15_handler      (void) {cpu_info("[INT]mcu_gpio_intr15_handler       hit\n"); send_label(MCU_GPIO_INTR15_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr14_handler      (void) {cpu_info("[INT]mcu_gpio_intr14_handler       hit\n"); send_label(MCU_GPIO_INTR14_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr13_handler      (void) {cpu_info("[INT]mcu_gpio_intr13_handler       hit\n"); send_label(MCU_GPIO_INTR13_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr12_handler      (void) {cpu_info("[INT]mcu_gpio_intr12_handler       hit\n"); send_label(MCU_GPIO_INTR12_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr11_handler      (void) {cpu_info("[INT]mcu_gpio_intr11_handler       hit\n"); send_label(MCU_GPIO_INTR11_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr10_handler      (void) {cpu_info("[INT]mcu_gpio_intr10_handler       hit\n"); send_label(MCU_GPIO_INTR10_IRQn           ); int_flg++;}
__INTERRUPT void mcu_gpio_intr9_handler       (void) {cpu_info("[INT]mcu_gpio_intr9_handler        hit\n"); send_label(MCU_GPIO_INTR9_IRQn            ); int_flg++;}
__INTERRUPT void mcu_gpio_intr8_handler       (void) {cpu_info("[INT]mcu_gpio_intr8_handler        hit\n"); send_label(MCU_GPIO_INTR8_IRQn            ); int_flg++;}
__INTERRUPT void aon_gpio_intr31_handler      (void) {cpu_info("[INT]aon_gpio_intr31_handler       hit\n"); send_label(AON_GPIO_INTR31_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr30_handler      (void) {cpu_info("[INT]aon_gpio_intr30_handler       hit\n"); send_label(AON_GPIO_INTR30_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr29_handler      (void) {cpu_info("[INT]aon_gpio_intr29_handler       hit\n"); send_label(AON_GPIO_INTR29_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr28_handler      (void) {cpu_info("[INT]aon_gpio_intr28_handler       hit\n"); send_label(AON_GPIO_INTR28_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr27_handler      (void) {cpu_info("[INT]aon_gpio_intr27_handler       hit\n"); send_label(AON_GPIO_INTR27_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr26_handler      (void) {cpu_info("[INT]aon_gpio_intr26_handler       hit\n"); send_label(AON_GPIO_INTR26_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr25_handler      (void) {cpu_info("[INT]aon_gpio_intr25_handler       hit\n"); send_label(AON_GPIO_INTR25_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr24_handler      (void) {cpu_info("[INT]aon_gpio_intr24_handler       hit\n"); send_label(AON_GPIO_INTR24_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr23_handler      (void) {cpu_info("[INT]aon_gpio_intr23_handler       hit\n"); send_label(AON_GPIO_INTR23_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr22_handler      (void) {cpu_info("[INT]aon_gpio_intr22_handler       hit\n"); send_label(AON_GPIO_INTR22_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr21_handler      (void) {cpu_info("[INT]aon_gpio_intr21_handler       hit\n"); send_label(AON_GPIO_INTR21_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr20_handler      (void) {cpu_info("[INT]aon_gpio_intr20_handler       hit\n"); send_label(AON_GPIO_INTR20_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr19_handler      (void) {cpu_info("[INT]aon_gpio_intr19_handler       hit\n"); send_label(AON_GPIO_INTR19_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr18_handler      (void) {cpu_info("[INT]aon_gpio_intr18_handler       hit\n"); send_label(AON_GPIO_INTR18_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr17_handler      (void) {cpu_info("[INT]aon_gpio_intr17_handler       hit\n"); send_label(AON_GPIO_INTR17_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr16_handler      (void) {cpu_info("[INT]aon_gpio_intr16_handler       hit\n"); send_label(AON_GPIO_INTR16_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr15_handler      (void) {cpu_info("[INT]aon_gpio_intr15_handler       hit\n"); send_label(AON_GPIO_INTR15_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr14_handler      (void) {cpu_info("[INT]aon_gpio_intr14_handler       hit\n"); send_label(AON_GPIO_INTR14_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr13_handler      (void) {cpu_info("[INT]aon_gpio_intr13_handler       hit\n"); send_label(AON_GPIO_INTR13_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr12_handler      (void) {cpu_info("[INT]aon_gpio_intr12_handler       hit\n"); send_label(AON_GPIO_INTR12_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr11_handler      (void) {cpu_info("[INT]aon_gpio_intr11_handler       hit\n"); send_label(AON_GPIO_INTR11_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr10_handler      (void) {cpu_info("[INT]aon_gpio_intr10_handler       hit\n"); send_label(AON_GPIO_INTR10_IRQn           ); int_flg++;}
__INTERRUPT void aon_gpio_intr9_handler       (void) {cpu_info("[INT]aon_gpio_intr9_handler        hit\n"); send_label(AON_GPIO_INTR9_IRQn            ); int_flg++;}
__INTERRUPT void aon_gpio_intr8_handler       (void) {cpu_info("[INT]aon_gpio_intr8_handler        hit\n"); send_label(AON_GPIO_INTR8_IRQn            ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr15_handler   (void) {cpu_info("[INT]mcu_mailbox_intr15_handler    hit\n"); send_label(MCU_MAILBOX_INTR15_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr14_handler   (void) {cpu_info("[INT]mcu_mailbox_intr14_handler    hit\n"); send_label(MCU_MAILBOX_INTR14_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr13_handler   (void) {cpu_info("[INT]mcu_mailbox_intr13_handler    hit\n"); send_label(MCU_MAILBOX_INTR13_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr12_handler   (void) {cpu_info("[INT]mcu_mailbox_intr12_handler    hit\n"); send_label(MCU_MAILBOX_INTR12_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr11_handler   (void) {cpu_info("[INT]mcu_mailbox_intr11_handler    hit\n"); send_label(MCU_MAILBOX_INTR11_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr10_handler   (void) {cpu_info("[INT]mcu_mailbox_intr10_handler    hit\n"); send_label(MCU_MAILBOX_INTR10_IRQn        ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr9_handler    (void) {cpu_info("[INT]mcu_mailbox_intr9_handler     hit\n"); send_label(MCU_MAILBOX_INTR9_IRQn         ); int_flg++;}
__INTERRUPT void mcu_mailbox_intr8_handler    (void) {cpu_info("[INT]mcu_mailbox_intr8_handler     hit\n"); send_label(MCU_MAILBOX_INTR8_IRQn         ); int_flg++;}
__INTERRUPT void mcu_dma_ch7_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch7_intr_handler      hit\n"); send_label(MCU_DMA_CH7_INTR_IRQn          ); int_flg++;}
__INTERRUPT void mcu_dma_ch6_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch6_intr_handler      hit\n"); send_label(MCU_DMA_CH6_INTR_IRQn          ); int_flg++;}
__INTERRUPT void mcu_dma_ch5_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch5_intr_handler      hit\n"); send_label(MCU_DMA_CH5_INTR_IRQn          ); int_flg++;}
__INTERRUPT void mcu_dma_ch4_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch4_intr_handler      hit\n"); send_label(MCU_DMA_CH4_INTR_IRQn          ); int_flg++;}
__INTERRUPT void mcu_dma_ch3_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch3_intr_handler      hit\n"); send_label(MCU_DMA_CH3_INTR_IRQn          ); int_flg++;}
__INTERRUPT void mcu_dma_ch2_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch2_intr_handler      hit\n"); send_label(MCU_DMA_CH2_INTR_IRQn          ); int_flg++;}
__INTERRUPT void mcu_dma_ch1_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch1_intr_handler      hit\n"); send_label(MCU_DMA_CH1_INTR_IRQn          ); int_flg++;}
__INTERRUPT void mcu_dma_ch0_intr_handler     (void) {cpu_info("[INT]mcu_dma_ch0_intr_handler      hit\n"); send_label(MCU_DMA_CH0_INTR_IRQn          ); int_flg++;}
//64
__INTERRUPT void ucie1_mcu_db2soc_irq_handler (void) {cpu_info("[INT]ucie1_mcu_db2soc_irq_handler  hit\n"); send_label(UCIE1_MCU_DB2SOC_IRQ_IRQn      ); int_flg++;}
__INTERRUPT void ucie1_dbg_irq_handler        (void) {cpu_info("[INT]ucie1_dbg_irq_handler         hit\n"); send_label(UCIE1_DBG_IRQ_IRQn             ); int_flg++;}

__INTERRUPT void ucie0_dbg_irq_handler        (void) {cpu_info("[INT]ucie0_dbg_irq_handler         hit\n"); send_label(UCIE0_DBG_IRQ_IRQn             ); int_flg++;}

__INTERRUPT void ucie0_mcu_db2soc_irq_handler (void) {cpu_info("[INT]ucie0_mcu_db2soc_irq_handler  hit\n"); send_label(UCIE0_MCU_DB2SOC_IRQ_IRQn      ); int_flg++;
                irq_num = UCIE0_MCU_DB2SOC_IRQ_IRQn;
}




int main(void)
{
    uint32_t returnCode;
    CSR_MCFGINFO_Type mcfg;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    cpu_info("ECLIC_Interrupt_Test start 1111111\n");
    

    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR31_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr31_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR30_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr30_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR29_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr29_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR28_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr28_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR27_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr27_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR26_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr26_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR25_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr25_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR24_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr24_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR23_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr23_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR22_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr22_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR21_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr21_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR20_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr20_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR19_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr19_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR18_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr18_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR17_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr17_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR16_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr16_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR15_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr15_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR14_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr14_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR13_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr13_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR12_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr12_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR11_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr11_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR10_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr10_handler              );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR9_IRQn           ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr9_handler               );
    returnCode = ECLIC_Register_IRQ(MCU_GPIO_INTR8_IRQn           ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_gpio_intr8_handler               );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR31_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr31_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR30_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr30_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR29_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr29_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR28_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr28_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR27_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr27_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR26_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr26_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR25_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr25_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR24_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr24_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR23_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr23_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR22_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr22_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR21_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr21_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR20_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr20_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR19_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr19_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR18_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr18_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR17_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr17_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR16_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr16_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR15_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr15_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR14_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr14_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR13_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr13_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR12_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr12_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR11_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr11_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR10_IRQn          ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr10_handler              );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR9_IRQn           ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr9_handler               );
    returnCode = ECLIC_Register_IRQ(AON_GPIO_INTR8_IRQn           ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)aon_gpio_intr8_handler               );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR15_IRQn       ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr15_handler           );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR14_IRQn       ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr14_handler           );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR13_IRQn       ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr13_handler           );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR12_IRQn       ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr12_handler           );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR11_IRQn       ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr11_handler           );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR10_IRQn       ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr10_handler           );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR9_IRQn        ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr9_handler            );
    returnCode = ECLIC_Register_IRQ(MCU_MAILBOX_INTR8_IRQn        ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_mailbox_intr8_handler            );
    returnCode = ECLIC_Register_IRQ(MCU_DMA_CH7_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_dma_ch7_intr_handler             );
    returnCode = ECLIC_Register_IRQ(MCU_DMA_CH6_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_dma_ch6_intr_handler             );
    returnCode = ECLIC_Register_IRQ(MCU_DMA_CH5_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_dma_ch5_intr_handler             );
    returnCode = ECLIC_Register_IRQ(MCU_DMA_CH4_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_dma_ch4_intr_handler             );
    returnCode = ECLIC_Register_IRQ(MCU_DMA_CH3_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_dma_ch3_intr_handler             );
    returnCode = ECLIC_Register_IRQ(MCU_DMA_CH2_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_dma_ch2_intr_handler             );
    returnCode = ECLIC_Register_IRQ(MCU_DMA_CH1_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_dma_ch1_intr_handler             );
    returnCode = ECLIC_Register_IRQ(MCU_DMA_CH0_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_dma_ch0_intr_handler             );
    returnCode = ECLIC_Register_IRQ(UCIE1_MCU_DB2SOC_IRQ_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)ucie1_mcu_db2soc_irq_handler         );
    returnCode = ECLIC_Register_IRQ(UCIE1_DBG_IRQ_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)ucie1_dbg_irq_handler                );
    returnCode = ECLIC_Register_IRQ(UCIE0_MCU_DB2SOC_IRQ_IRQn     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)ucie0_mcu_db2soc_irq_handler         );
    returnCode = ECLIC_Register_IRQ(UCIE0_DBG_IRQ_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)ucie0_dbg_irq_handler                );

    __enable_irq();

    send_label(0x12345678);

    while(irq_num != UCIE0_MCU_DB2SOC_IRQ_IRQn);
    cpu_info("cpu test done !!!\n");

    simend();
    while(1);
}
