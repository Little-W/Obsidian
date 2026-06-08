// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

// timer interrupt handler
// non-vector mode interrupt

volatile uint32_t flag = 0;

int main(void)
{
    uint32_t returnCode;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    //first sleep
    cpu_info("ux900 first 111 sleep !!!\n");

    while(flag==0){

    cpu_info("ux900 first 222 sleep !!!\n");
    flag = 1;  

    send_label(55);

    __RV_CSR_WRITE(CSR_SLEEPVALUE, 1);   
    __WFI();
    }

    cpu_info("ux900 test done !!!\n");
    
    simend();
    while(1);
}

