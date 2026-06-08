// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"


int main(void)
{
    uint64_t rdata;

    set_uncache_region(0x401ff000, 0xfffff000);
    
    crg_init();

    //scan middle addr
    for(int i = 0; i < 64; i++){
        rdata = read64(CORE_PRIVATE_ROM_BASE_ADDR+0x20000+i*8);
        if(rdata != CORE_PRIVATE_ROM_BASE_ADDR+0x20000+i*8){
            cpu_error("compare fail: addr=0x%0x, rdata=0x%lx\n", CORE_PRIVATE_ROM_BASE_ADDR+0x20000+i*8, rdata);
        }
    }
    //scan high addr
    for(int i = 0; i < 64; i++){
        rdata = read64(CORE_PRIVATE_ROM_BASE_ADDR+0x3fe00+i*8);
        if(rdata != CORE_PRIVATE_ROM_BASE_ADDR+0x3fe00+i*8){
            cpu_error("compare fail: addr=0x%0x, rdata=0x%lx\n", CORE_PRIVATE_ROM_BASE_ADDR+0x3fe00+i*8, rdata);
        }
    }
    cpu_info("rom boot & read test done !!!\n");

    simend();
    while(1);
}

