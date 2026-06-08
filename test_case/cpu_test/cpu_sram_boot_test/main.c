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

    cpu_info("sram boot success !!!\n");
    
    simend();
    while(1);
}

