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
    send_label(0x12345678);
    wait_label(0x12121235);
    
    wdata |= 1<<2;
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+TOP_CRG_CLK_SEL0_OFFSET,wdata);  //disable clk
    wdata &= 0xfffffffe;                                                                   
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+TOP_CRG_CLK_SEL0_OFFSET,wdata);

    //switch to 400M
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+PLL_MCU_CFG0_OFFSET,0x703E834);
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+PLL_MCU_CFG1_OFFSET,0x00);
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+PLL_MCU_CFG2_OFFSET,0x01);
    
    wait(5);
    wdata = 0;
    wdata |= 1<<0;
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+TOP_CRG_CLK_SEL0_OFFSET,wdata); //enable clk
    wdata &= 0xfffffffb;
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+TOP_CRG_CLK_SEL0_OFFSET,wdata); //enable clk


    send_label(0x12345678);
    wait_label(0x12121235);
    
    wdata |= 1<<2;
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+TOP_CRG_CLK_SEL0_OFFSET,wdata);  //disable clk
    wdata &= 0xfffffffe;                                                                   
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+TOP_CRG_CLK_SEL0_OFFSET,wdata);


    //switch to 200M

    write32(SOC_NOC_TOP_CRG_BASE_ADDR+PLL_MCU_CFG0_OFFSET,0xB03E834);
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+PLL_MCU_CFG1_OFFSET,0x00);
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+PLL_MCU_CFG2_OFFSET,0x01);
    
    wait(5);
    wdata = 0;
    wdata |= 1<<0;
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+TOP_CRG_CLK_SEL0_OFFSET,wdata); //enable clk
    wdata &= 0xfffffffb;
    write32(SOC_NOC_TOP_CRG_BASE_ADDR+TOP_CRG_CLK_SEL0_OFFSET,wdata); //enable clk

    send_label(0x12345678);

    cpu_info("ux900 test done !!!\n");
    
    simend();
    while(1);
}

