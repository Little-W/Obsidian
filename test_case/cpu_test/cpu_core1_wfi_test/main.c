// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

int core0_main(unsigned long hartid);
int core1_main(unsigned long hartid);
int main(void);

// volatile required
volatile uint32_t lock_ready = 0;
unsigned long tmr_hartid = 0;

// timer interrupt handler
// non-vector mode interrupt
void eclic_mtip_handler(void)
{
    static uint32_t int_t_cnt = 0;    /* timer interrupt counter */
    cpu_info("[IN TIMER INTERRUPT]  timer interrupt hit\n");

    send_label(0xabababab);
    SysTick_Reload(20000);

    cpu_info("[IN TIMER INTERRUPT]timer interrupt end\r\n");
}

/* Reimplementation of smp_main for multi-harts */
int smp_main(void)
{
    return main();
}


int main(void)
{
    int ret;
    // get hart id in current cluster
    unsigned long hartid = __get_hart_id();

    set_uncache_region(0x401ff000, 0xfffff000);

    if (hartid == BOOT_HARTID) { // boot hart
        cpu_info("boot_hart_main: Hello world from hart %lu\n", hartid);
        lock_ready = 1;
        ret = core0_main(hartid);
    } else { // other harts
        scpu_info("other_harts_main: Hello world from hart %lu, hartid = %0d\n", hartid, lock_ready);
        // wait for lock initialized
        while (lock_ready == 1);
        ret = core1_main(hartid);
    }
    return ret;
}

int core0_main(unsigned long hartid)
{
    volatile unsigned long waitcnt = 0;
    uint32_t rdata;
    uint32_t rval;

    crg_init();

    cpu_info(" core0_main boot hart: Hello world from hart %lu\n", hartid);
    
    wait(1000);
    lock_ready = 0;
    wait(1000);
    while(1);
}

int core1_main(unsigned long hartid)
{
    uint32_t returnCode;

    scpu_info("core1_main second harts: Hello world from hart %lu\n", hartid);
    //first sleep
    scpu_info("ux900 core1 first sleep !!!\n");

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
    scpu_info("ux900 wfi test done !!!\n");
    
    simend();
    while(1);
}

