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

    uint32_t addr;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();


    addr = 0x18042000 + 0x68c;      //MCU_SUB_SCU_BASE_ADDR;
    write32(addr,0x3);              // rrep --> cpu
    rdata = read32(addr);
    cpu_info("c code mem rresp rdata1 == 0x%x\n", rdata);


    addr = 0x40000000;              // sram addr
    write32(addr,0xffff); 
    rdata = read32(addr);
    cpu_info("c code mem error addr rresp1 rdata == 0x%x\n", rdata);   // rresp = 0 

    addr = 0x14000000;              // error addr
    write32(addr,0xffff); 
    rdata = read32(addr);
    cpu_info("c code mem error addr rresp2 rdata == 0x%x\n", rdata);   //rresp = 0


    addr = 0x18042000 + 0x68c;      //MCU_SUB_SCU_BASE_ADDR;
    write32(addr,0x0);              // rrep --> cpu
    rdata = read32(addr);
    cpu_info("c code mem rresp rdata2 == 0x%x\n", rdata);            //rresp = 0

    send_label(1);
    cpu_info("c code mem rresp start 123 !!!\n");

    addr = 0x14000000;              // error addr
    write32(addr,0xffff); 
    rdata = read32(addr);
    cpu_info("c code mem error addr rresp3 rdata == 0x%x\n", rdata); //rresp =3



    


   simend();
    while(1);
}

