// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

#ifndef CFG_SIMULATION
#define RUN_LOOPS   20
#else
#define RUN_LOOPS   5
#endif

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
        cpu_info("boot_hart_main: Hello world from hart %lu\n", hartid);
        lock_ready = 1;            
        ret = core0_main(hartid);
    } else { // other harts
        scpu_info("other_harts_main: Hello world from hart %lu, lock_ready = %0d\n", hartid, lock_ready);        
        
        // wait for lock initialized
        while (lock_ready == 1);
        ret = core1_main(hartid);
    }
    return ret;
}

int core0_main(unsigned long hartid)
{
    uint32_t rdata;
    
    crg_init();

    cpu_info("core0_main: Hello world 1111 from hart %lu\n", hartid);
    lock_ready = 0;
    
    wait_label(55);
    cpu_info("core0_main: Hello world 2222 from hart %lu\n", hartid);
     
    // wait(1000);
    
    //wake up core1
    // write32(MCU_SUB_SCU_BASE_ADDR+0x08, 0x02); //core0
    write32(MCU_SUB_SCU_BASE_ADDR+0x0c, 0x01);
    wait(150);
    __RV_CSR_WRITE(CSR_TXEVT, 1);

    cpu_info("ux900 core wfe test done !!!\n");

    send_label(11);


    while(1);
}


int core1_main(unsigned long hartid)
{
    volatile unsigned long waitcnt = 0;
    uint32_t rdata;
    uint32_t rval;
    uint32_t returnCode;


    //first sleep
    scpu_info("core1_main enter hart%0d main !!!\n", hartid);
    lock_ready = 0;
    //cpu will enter lowpower mode, notify sv checking core0_core_clock go low 
    send_label(0x12345678);
    
    // send_label(55);
    // Should not enter interrupt handler due to irq disabled
   // __RV_CSR_WRITE(CSR_SLEEPVALUE, 1); 
    __WFE();
          

    simend();   
    while(1);

}


