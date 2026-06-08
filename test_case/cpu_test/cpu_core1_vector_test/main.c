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

//    crg_init();

    write32(0x401f0000,0x12345678);
    rdata = read32(0x401f0000);

    if(rdata != 0x12345678){
        while(1);
    }

    cpu_info("core1 vector start !!!\n");

    write32(MCU_SUB_SCU_BASE_ADDR + 0x28, 0xffffffff);  //core1 addr
    rdata = read32(MCU_SUB_SCU_BASE_ADDR +0x28);
    cpu_info("core1 vector high addr rdata1  == 0x%x\n", rdata);

    if(rdata != 0x1ffff)
        cpu_error("read data fail for core1 vector high addr \n");


    write32(MCU_SUB_SCU_BASE_ADDR + 0x28, 0x0);         //core1 addr
    rdata = read32(MCU_SUB_SCU_BASE_ADDR +0x28);
    cpu_info("core1 vector high addr rdata2  == 0x%x\n", rdata);

    if(rdata != 0x0)
        cpu_error("read data fail for core1 vector high addr not clean \n");




    write32(MCU_SUB_SCU_BASE_ADDR + 0x2c, 0xffffffff);  //core1 addr
    rdata = read32(MCU_SUB_SCU_BASE_ADDR +0x2c);
    cpu_info("core1 vector low addr rdata1  == 0x%x\n", rdata);
    if(rdata != 0xffffffff)
        cpu_error("read data fail for core1 vector low addr \n");


    write32(MCU_SUB_SCU_BASE_ADDR + 0x2c, 0x0);         //core1 addr
    rdata = read32(MCU_SUB_SCU_BASE_ADDR +0x2c);
    cpu_info("core1 vector low addr rdata2  == 0x%x\n", rdata);
        
    if(rdata != 0x0)
        cpu_error("read data fail for core1 vector low addr not clean \n");


    send_label(1);
    cpu_info("core1 vector success !!!\n");

 

    simend();
    while(1);
}

