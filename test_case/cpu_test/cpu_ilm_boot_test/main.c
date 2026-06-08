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

    write32(0x401f0000,0x12345678);
    rdata = read32(0x401f0000);

    if(rdata != 0x12345678){
        while(1);
    }
    send_label(1);
    cpu_info("c code ilm boot send_label 1 success !!!\n");

    wait_label(2);
    cpu_info("c code ilm boot wait_label 2 success !!!\n");

    cpu_info("ilm boot success !!!\n");

    simend();
    while(1);
}

