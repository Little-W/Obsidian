// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"
//-----------------------------------------
void wr8(uint64_t addr, uint8_t wdata){
    *(volatile uint8_t *)(addr) = wdata;
}
void wr16(uint64_t addr, uint16_t wdata){
    *(volatile uint16_t *)(addr) = wdata;
}
void wr32(uint64_t addr, uint32_t wdata){
    *(volatile uint32_t *)(addr) = wdata;
}
void wr64(uint64_t addr, uint64_t wdata){
    *(volatile uint64_t *)(addr) = wdata;
}

int main(void)
{
    uint64_t rdata;
    uint32_t range = 64;

    set_uncache_region(0x401ff000, 0xfffff000);
    
    crg_init();
    cpu_info("config crg done\n");
    
    //access sram
    for(int i = 0; i < range; i++){
        wr8(MCU_SUB_SRAM_BASE_ADDR + i, i);
    }
    for(int i = 0; i < range; i++){
        rdata = read8(MCU_SUB_SRAM_BASE_ADDR + i);
        cmp_data(i, rdata, MCU_SUB_SRAM_BASE_ADDR + i, 0);
    }

    for(int i = range; i < range*2; i++){
        wr16(MCU_SUB_SRAM_BASE_ADDR + i*2, i);
    }
    for(int i = range; i < range*2; i++){
        rdata = read16(MCU_SUB_SRAM_BASE_ADDR + i*2);
        cmp_data(i, rdata, MCU_SUB_SRAM_BASE_ADDR + i*2, 0);
    }
    
    for(int i = range*3; i < range*4; i++){
        wr32(MCU_SUB_SRAM_BASE_ADDR + i*4, i);
    }
    for(int i = range*3; i < range*4; i++){
        rdata = read32(MCU_SUB_SRAM_BASE_ADDR + i*4);
        cmp_data(i, rdata, MCU_SUB_SRAM_BASE_ADDR + i*4, 0);
    }
    
    for(int i = range*7; i < range*8; i++){
        wr64(MCU_SUB_SRAM_BASE_ADDR + i*8, i);
    }
    for(int i = range*7; i < range*8; i++){
        rdata = read64(MCU_SUB_SRAM_BASE_ADDR + i*8);
        cmp_data(i, rdata, MCU_SUB_SRAM_BASE_ADDR + i*8, 0);
    }

    //disabel dcache & access sram
    set_dcache(0);
    cpu_info("disable dcache done\n");

    for(int i = 0; i < range; i++){
        wr8(MCU_SUB_SRAM_BASE_ADDR + i, i);
    }
    for(int i = 0; i < range; i++){
        rdata = read8(MCU_SUB_SRAM_BASE_ADDR + i);
        cmp_data(i, rdata, MCU_SUB_SRAM_BASE_ADDR + i, 0);
    }

    for(int i = range; i < range*2; i++){
        wr16(MCU_SUB_SRAM_BASE_ADDR + i*2, i);
    }
    for(int i = range; i < range*2; i++){
        rdata = read16(MCU_SUB_SRAM_BASE_ADDR + i*2);
        cmp_data(i, rdata, MCU_SUB_SRAM_BASE_ADDR + i*2, 0);
    }
    
    for(int i = range*3; i < range*4; i++){
        wr32(MCU_SUB_SRAM_BASE_ADDR + i*4, i);
    }
    for(int i = range*3; i < range*4; i++){
        rdata = read32(MCU_SUB_SRAM_BASE_ADDR + i*4);
        cmp_data(i, rdata, MCU_SUB_SRAM_BASE_ADDR + i*4, 0);
    }
    
    for(int i = range*7; i < range*8; i++){
        wr64(MCU_SUB_SRAM_BASE_ADDR + i*8, i);
    }
    for(int i = range*7; i < range*8; i++){
        rdata = read64(MCU_SUB_SRAM_BASE_ADDR + i*8);
        cmp_data(i, rdata, MCU_SUB_SRAM_BASE_ADDR + i*8, 0);
    }

    cpu_info("write&read sram done !!!\n");
    
    simend();
    while(1);
}

