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

    //config core register
    __RV_CSR_WRITE(mtvec, 0x8203000);
    rdata = __RV_CSR_READ(mtvec);
    if(rdata != 0x8203000){
        cpu_fatal("compare value of mtvec fail");
    }
    //config component register
    write32(0x50000+0xc09c, 0x1);
    rdata = read32(0x50000+0xc09c);
    if(rdata != 0x01){
        cpu_fatal("compare value of CIDU_SRW_CTRL fail");
    }

    send_label(0x12345678);
    wait_label(0x11112222);

    send_label(0x41526311);
    //gen rst req, but rst should be bypass in core
    write32(0x30000+0xff0, 0x80000a5f);
    wait(800);

    wait_label(0xadf57c8e);

    //check if the register values have been restored to their default values
    rdata = __RV_CSR_READ(mtvec);
    if(rdata != 0x8203000){
        cpu_fatal("compare value of mtvec fail");
    }
    rdata = read32(0x50000+0xc09c);
    if(rdata != 0x01){
        cpu_fatal("compare value of CIDU_SRW_CTRL fail");
    }

    send_label(0x5555);

    cpu_info("cpu test done !!!\n");

    simend();
    while(1);
}

