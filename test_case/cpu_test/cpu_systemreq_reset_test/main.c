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
    uint32_t addr_t;
    uint32_t rval;

    set_uncache_region(0x401ff000, 0xfffff000);
//    crg_init();

    rdata = read32(LABEL_ADDR);
    if(rdata != 0x12345678){
        cpu_info("cpu first boot !!!\n");

        //write a flag to sram for sv first detecting
        send_label(0x12345678);
        //gen system reset request
        //1.write data 0x80000a5f to timer reg(0xffc)
        //2.gen reset request
        write32(0x30000+0xff0, 0x80000a5f);
        while(1);
    }

    cpu_info("cpu second boot !!!\n");

    addr_t = 0x40001000;
    for(int i = 0; i < 16; i++){
        write32(addr_t+i*4, i*4);
        rdata = read32(addr_t+i*4);
        if(rdata != i*4){
            cpu_error("check fail: wdata = 0x%0x, rdata = 0x%0x", i*4, rdata);
        }
    }

    //write a flag to sram for sv second detecting
    send_label(0x11aa55bb);

    simend();
    while(1);
}

