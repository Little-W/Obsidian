// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

int main(void)
{
    uint32_t rdata;
    uint32_t rval;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    //first sleep
    cpu_info("ux600 first sleep !!!\n");
    __disable_irq();
    // need to adapt the tick according to your SoC
    SysTick_Config(2000);
    SysTimer_Start();
    //cpu will enter lowpower mode, notify sv checking core0_core_clock go low 
    send_label(0x12345678);
    // Should not enter interrupt handler due to irq disabled
    __WFI();

    send_label(0xabcd1111);
    wait_label(0x44556677);

    //second sleep(not success due to gate bypass )
    cpu_info("ux600 second sleep !!!\n");
    SysTick_Config(2000);
    SysTimer_Start();
    //cpu will enter lowpower mode, notify sv checking core0_core_clock go low 
    send_label(0x2547a9b3);
    // Should not enter interrupt handler due to irq disabled
    __WFI();
    
    cpu_info("ux600 test done !!!\n");
    
    simend();
    while(1);
}

