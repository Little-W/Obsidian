// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

// timer interrupt handler
// non-vector mode interrupt
// volatile required
volatile uint32_t lock_ready = 0;
unsigned long tmr_hartid = 0;

int core0_main(unsigned long hartid);
int core1_main(unsigned long hartid);
int main(void);

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
        cpu_info("core0_main: Hello world from hart %lu\n", hartid);
        lock_ready = 1;
        ret = core0_main(hartid);
    } else { // other harts
        scpu_info("core1_main: Hello world from hart %lu, hartid = %0d\n", hartid, lock_ready);
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

    cpu_info("core0_main: Hello world from hart %lu\n", hartid);
    wait(50);
    lock_ready = 0;
    
    while(1);
}

int core1_main(unsigned long hartid)
{
    scpu_info("core1_main: Hello world from hart %lu\n", hartid);


    send_label(55);

    __RV_CSR_WRITE(CSR_SLEEPVALUE, 1);   
    __WFI();

    simend();
    while(1);
}



