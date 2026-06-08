// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"
#include "reg_struct_def.h"

int main(void)
{
    uint32_t rdata;
    uint32_t rdata_tmp;
    uint32_t wdata;

    crg_init();

    cpu_info("test default value");
    for(int i = 0; i< sizeof(sys_reg)/sizeof(SYS_REG_t); i++){
        rdata = read32(sys_reg[i].base_addr+sys_reg[i].offset);
        if(rdata != sys_reg[i].default_val){
            cpu_error("Error: addr = 0x%0x, exp = 0x%0x, act = 0x%0x\n", sys_reg[i].base_addr+sys_reg[i].offset, sys_reg[i].default_val, rdata);
        }
        else{
            cpu_info("Check Default val Pass !!!");
        }
    }

    cpu_info("write&read test");
    for(int j = 0; j < 3; j++){
        for(int i = 0; i< sizeof(sys_reg)/sizeof(SYS_REG_t); i++){
            rdata_tmp = read32(sys_reg[i].base_addr+sys_reg[i].offset);
            write32(sys_reg[i].base_addr+sys_reg[i].offset, test_val[j]);
            rdata = read32(sys_reg[i].base_addr+sys_reg[i].offset);
            if(rdata != test_val[j] & sys_reg[i].rw_mask){
                cpu_error("Error: addr = 0x%0x, exp = 0x%0x, act = 0x%0x\n", sys_reg[i].base_addr+sys_reg[i].offset, test_val[j] & sys_reg[i].rw_mask, rdata);
            }
            else{
                cpu_info("Check Write&read val Pass !!!");
            }
        }
    }

    cpu_info("axi access device reg done !!!\n");

    simend();
    while(1);
}

