// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"


int main(void)
{
    uint32_t result;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    //32/64
    __ASM volatile("expd80 %0, %1" : "=r"(result) : "r"(0x12345678));

    if(result != 0x78787878){
        cpu_error("EXPD80 Fail: result = 0x%0x, golden_val = 0x%0x\n", result, 0x78787878);
    }
    else{
        cpu_info("EXPD80 Pass: result = golden_val = 0x%0x\n", result);
    }

    //64
    __ASM volatile("expd87 %0, %1" : "=r"(result) : "r"(0x12345678abcdef5d));

    if(result != 0x12121212){
        cpu_error("EXPD87 Fail: result = 0x%0x, golden_val = 0x%0x\n", result, 0x12121212);
    }
    else{
        cpu_info("EXPD87 Pass: result = golden_val = 0x%0x\n", result);
    }

    simend();
    while(1);
}

