// See LICENSE for license details.
#include <stdio.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

//int flag_wake;

int main(void)
{
    uint32_t returnCode;
    uint32_t wdata;
    uint32_t rdata;
    uint64_t rdata_64;

    set_uncache_region(0x401ff000, 0xfffff000);
    crg_init();
/*read only reg
    wdata = 0x7ff ; // bit 10 sp_tmod
    write32(MCU_SUB_SCU_BASE_ADDR + 0x480, wdata);    
    rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x488);
    if(rdata != 0x7ff)
        cpu_error("read data fail for sp_tmod\n");

    wdata = 0x0 ; // bit 10 sp_tmod
    write32(MCU_SUB_SCU_BASE_ADDR + 0x480, wdata);    
    rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x488);
    if(rdata != 0x0)
        cpu_error("read data fail for sp_tmod\n");
*/

   // MCU_SUB_SRAM_BASE_ADDR  for mem_aradd   
       
   //  MCU_SUB_SRAM_BASE_ADDR = 0x0008200000; //0x00083FFFFF
    //    16 - 2 /32 - 4 /64 - 8 / 128 -c / 256 -f
/*        write64(0x00083FFFF0,0xffffffffffffffff);
        rdata_64 = read64(0x00083FFFF0);
        cpu_info("read data for mem_aradd radta_64 == 0x%x\n", rdata_64);

        write64(0xFFFFFFFFF0,0xffffffffffffffff);
        rdata_64 = read64(0x00083FFFF0);
        cpu_info("read data for add_end radta_64 == 0x%x\n", rdata_64);
        
    //TXEVT 0x812
    __RV_CSR_SET(CSR_TXEVT, 0x1);
    wait(100);
    __RV_CSR_SET(CSR_TXEVT, 0x0);
*/
    //dbg_sec_enable
    wdata &= ~(1<<15);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_disable rdata == 0x%x\n", rdata);

    wdata |= 1<<15;
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_enable  rdata == 0x%x\n", rdata);
    //dm_map_enable
    wdata |= 1<<0;
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_enable  rdata == 0x%x\n", rdata);

    wdata &= ~(1<<0);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_disable rdata == 0x%x\n", rdata);

    //core0_dcache_disable_init
    wdata |= 1<<3;
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_enable  rdata == 0x%x\n", rdata);

    wdata &= ~(1<<3);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_disable rdata == 0x%x\n", rdata);


    //core0/1_icache_disable_init
    wdata |= (1<<2) | (1<<5);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_enable  rdata == 0x%x\n", rdata);

    wdata &= ~((1<<2) | (1<<5));
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_disable rdata == 0x%x\n", rdata);


    //core0/1_dcache_disable_init
    wdata |= (1<<0) | (1<<6);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_enable  rdata == 0x%x\n", rdata);

    wdata &= ~((1<<0)|(1<<6));
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_disable rdata == 0x%x\n", rdata);

    //core0/1_mmu_tlb_disable_init
    wdata |= 1<<16 | 1<<17;
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_enable  rdata == 0x%x\n", rdata);

    wdata &= ~((1<<16) |(1<<17));
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_disable rdata == 0x%x\n", rdata);

    //core0/1_bpu_disable_init
    wdata |= (1<<1) | (1<<4);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_enable  rdata == 0x%x\n", rdata);

    wdata &= ~((1<<1) | (1<<4));
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_sec_disable rdata == 0x%x\n", rdata);

    //core0 i_dbg_stop
    wdata |= (1<<14);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for i_dbg_stop  rdata == 0x%x\n", rdata);

    wdata &= ~(1<<14);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for i_dbg_stop rdata == 0x%x\n", rdata);

    //core0 halt_id
    wdata = 0x3ff; // bit 0->9
    write32(MCU_SUB_SCU_BASE_ADDR + 0x4 ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x4);
    cpu_info("core0 halt_id  wdata == 0x%x\n", rdata);

    wdata = 0x0;
    write32(MCU_SUB_SCU_BASE_ADDR + 0x4,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x4);
    cpu_info("core0 halt_id rdata == 0x%x\n", rdata);
//========================================================================tan
    // wdata = 0x0;
    // write32(MCU_SUB_SCU_BASE_ADDR + 0x480,wdata);
    // rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x480);
    // cpu_info("aptmod rdata == 0x%x\n", rdata);

    // wdata = 0x7ff;
    // write32(MCU_SUB_SCU_BASE_ADDR + 0x480,wdata);
    // rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x480);
    // cpu_info("aptmod rdata == 0x%x\n", rdata);

    // wdata = 0x0;
    // write32(MCU_SUB_SCU_BASE_ADDR + 0x480,wdata);
    // rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x480);
    // cpu_info("aptmod rdata == 0x%x\n", rdata);


    // wdata = 0x0;
    // write32(MCU_SUB_SCU_BASE_ADDR + 0x4,wdata);
    // rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x4);
    // cpu_info("aptmod rdata == 0x%x\n", rdata);

    // wdata = 0xfffff000;
    // write32(MCU_SUB_SCU_BASE_ADDR + 0x4,wdata);
    // rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x4);
    // cpu_info("aptmod rdata == 0x%x\n", rdata);

    // wdata = 0x0;
    // write32(MCU_SUB_SCU_BASE_ADDR + 0x4,wdata);
    // rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x4);
    // cpu_info("aptmod rdata == 0x%x\n", rdata);

//========================================================================


    //core0 EVT_0 -->
    //
    wdata = 0x7f; // bit 0->6
    for(int i=0; i<6;i++){
    write32(MCU_SUB_SCU_BASE_ADDR + 0x8 + i*4 ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x8 + i*4);
    cpu_info("core0 EVT_0-5  wdata[0x%x] == 0x%x\n", i, rdata);

    wdata = 0x0;
    write32(MCU_SUB_SCU_BASE_ADDR + 0x8 + i*4 ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR + 0x8 + i*4);
    cpu_info("core0 EVT_0-5  wdata[0x%x] == 0x%x\n", i, rdata);
    }


    //core0 cc_disable_init
    wdata |= (1<<18);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for cc_disable_init  rdata == 0x%x\n", rdata);

    wdata &= ~(1<<18);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for cc_disable_init rdata == 0x%x\n", rdata);

    //core0 cc_enable_init_dram
    wdata |= (1<<19);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for cc_disable_init  rdata == 0x%x\n", rdata);

    wdata &= ~(1<<19);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for cc_disable_init rdata == 0x%x\n", rdata);

    //core0_stop_on_reset
    wdata |= (1<<7);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for cc_disable_init  rdata == 0x%x\n", rdata);

    wdata &= ~(1<<7);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for cc_disable_init rdata == 0x%x\n", rdata);

    //core1_stop_on_reset
    wdata |= (1<<8);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for cc_disable_init  rdata == 0x%x\n", rdata);

    wdata &= ~(1<<8);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for cc_disable_init rdata == 0x%x\n", rdata);


    //override dm sleep
    wdata |= (1<<20);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for override dm sleep  rdata == 0x%x\n", rdata);

    wdata &= ~(1<<20);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for override dm sleep rdata == 0x%x\n", rdata);

    //dbg_stop_at_boot
    wdata |= (1<<13);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_stop_at_boot  rdata == 0x%x\n", rdata);

    wdata &= ~(1<<13);
    write32(MCU_SUB_SCU_BASE_ADDR ,wdata);
    rdata = read32(MCU_SUB_SCU_BASE_ADDR);
    cpu_info("read data for dbg_stop_at_boot rdata == 0x%x\n", rdata);

    simend();
    while(1);
    //return 0;
}

