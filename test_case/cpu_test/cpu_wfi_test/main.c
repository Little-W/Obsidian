// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

// timer interrupt handler
// non-vector mode interrupt
void eclic_mtip_handler(void)
{
    static uint32_t int_t_cnt = 0;    /* timer interrupt counter */
    cpu_info("[IN TIMER INTERRUPT]timer interrupt hit\n");

    send_label(0xabababab);
    SysTick_Reload(20000);

    cpu_info("[IN TIMER INTERRUPT]timer interrupt end\r\n");
}

int main(void)
{
    uint32_t returnCode;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();
    // write32(MCU_SUB_MCU_CRG_BASE_ADDR+MCU_CRG_CLK_SEL0_OFFSET,0x1);

    //first sleep
    cpu_info("ux900 first sleep !!!\n");

    // need to adapt the tick according to your SoC
    SysTick_Config(20000);
    SysTimer_Start();

    // inital timer interrupt as non-vector interrupt
    returnCode = ECLIC_Register_IRQ(SysTimer_IRQn, ECLIC_NON_VECTOR_INTERRUPT,
                                    ECLIC_LEVEL_TRIGGER, 1, 0, (void*)eclic_mtip_handler);

    //cpu will enter lowpower mode, notify sv checking core0_core_clock go low 
    send_label(0x12345678);
    __enable_irq();
    // Should not enter interrupt handler due to irq disabled


    __WFI();

    __disable_irq();
    cpu_info("ux600 test done !!!\n");
    
    simend();
    while(1);
}

