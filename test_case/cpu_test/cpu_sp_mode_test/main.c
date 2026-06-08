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
    uint32_t wdata;
    
    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x47c);
    /*if(rdata != 0x360){
            cpu_error("sp_tmod rdata == 0x%x\n", rdata);
    }*/

    wdata = 0x7ff;
    write32(MCU_SUB_SCU_BASE_ADDR + 0x47c,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x47c);
    //cpu_info("sp_tmod rdata == 0x%x\n", rdata);

    
    //send_label(1);
    //cpu_info("c code ilm boot send_label 1 success !!!\n");

    //simend();
    
    while(1);
}

