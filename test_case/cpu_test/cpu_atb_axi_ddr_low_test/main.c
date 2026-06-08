// See LICENSE for license details.
#include <stdio.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "check_cpufeature.h"

#include <string.h>
#include "system.h"
#include "sysdef.h"


// use to save the memory base address to save the etrace pakcage data

// void * trace_pack_addr;
 uint64_t trace_pack_addr;

int test() {
    char *a = (char *)malloc(100);
    if (a == NULL) {
        cpu_info("malloc a failed, please make sure the malloc function bas been implemented or heap size is not enough\n");
        return 1;
    }
    char *b = (char *)malloc(100);
    if (b == NULL) {
        cpu_info("malloc b failed, please make sure the malloc function bas been implemented or heap size is not enough\n");
        return 1;
    }

    memset(a, 1, 100);
    memcpy(b, a, 100);

    free(a);
    free(b);
    return 1;
}

void set_trace_enable(int trig_num, uintptr_t addr) {
    __RV_CSR_WRITE(CSR_TSELECT, trig_num);
#if __riscv_xlen == 64 
    __RV_CSR_WRITE(CSR_TDATA1, 0x200000000000205c);
#else
    __RV_CSR_WRITE(CSR_TDATA1, 0x2000205c);
#endif
    __RV_CSR_WRITE(CSR_TDATA2, addr);

    cpu_info("c code atb to set_trace_enable  !!!\n");
}

void set_trace_disable(int trig_num, uintptr_t addr) {
    __RV_CSR_WRITE(CSR_TSELECT, trig_num);
#if __riscv_xlen == 64 
    __RV_CSR_WRITE(CSR_TDATA1, 0x200000000000305c);
#else
    __RV_CSR_WRITE(CSR_TDATA1, 0x2000305c);
#endif
    __RV_CSR_WRITE(CSR_TDATA2, addr);

    cpu_info("c code atb to set_trace_disable  !!!\n");
}


typedef struct  {
    uint32_t base_hi;
    uint32_t base_lo;
    uint32_t wlen;    // the region size
    uint32_t enable;
    uint32_t irq;
    uint32_t maxtime;
    uint32_t early;
    uint32_t atovf;

} atb2axi_ip_reg_e;

//#define NUCLEI_ATB2AXI_IP_BASE (EVALSOC_PERIPS_BASE)

#define NUCLEI_ATB2AXI_IP_BASE 0x18021000 //0x0A212FF0

void set_atb2axi_enable() {
    atb2axi_ip_reg_e *reg = (atb2axi_ip_reg_e *)NUCLEI_ATB2AXI_IP_BASE;
    // alloc 4M space and the address is aligned to 4M
//andyf   trace_pack_addr = aligned_alloc(4 * 1024 * 1024, 4 * 1024 * 1024);
    trace_pack_addr = 0x4000000000;

#if __riscv_xlen == 64
    reg->base_hi = ((uint64_t)trace_pack_addr >> 32);
    reg->base_lo = (uint64_t)trace_pack_addr & 0xffffffff;
#else
    reg->base_hi = 0;
    reg->base_lo = (uint32_t)trace_pack_addr;
#endif
    reg->wlen = 4 * 1024;   //4 * 1024 * 1024
//andyf add                                   
    reg->maxtime = 1;   
    reg->early = 1;  
    reg->irq = 1;
    reg->atovf =1;
    reg->enable = 1;   
    


    cpu_info("c code atb to set_atb2axi_enable  !!!\n");
}

int main(void)
{

    uint32_t rdata;
    uint32_t wdata;
    uint32_t rval;

    set_uncache_region(0x000400000000, 0x80000000); // 覆盖 cacheable_memory_regions 所在范围

    crg_init();

    cpu_info("c code atb to axi test 1111 !!!\n");

    set_trace_enable(0, (uintptr_t)&test);
    cpu_info("c code atb to axi test 2222 !!!\n");

/*
//add timeout
    rdata = read32(NUCLEI_ATB2AXI_IP_BASE+0x2c);
    if (rdata !=0xffffffff)
        cpu_error("atb 2 axi timeout defaul fail rdata ==  0x%0x\n",rdata);
    
    wdata = 0;
    write32(NUCLEI_ATB2AXI_IP_BASE+0x2c,wdata);
    rdata = read32(NUCLEI_ATB2AXI_IP_BASE+0x2c);
    if (rdata !=0)
        cpu_error("atb 2 axi timeout set test fail rdata ==  0x%0x\n",rdata);
//inter
    rdata = read32(NUCLEI_ATB2AXI_IP_BASE+0x10);
    if (rdata !=0x0)
        cpu_error("atb 2 axi interrupt defaul fail rdata ==  0x%0x\n",rdata);
    
    wdata = 0xffffffff;
    write32(NUCLEI_ATB2AXI_IP_BASE+0x10,wdata);
    rdata = read32(NUCLEI_ATB2AXI_IP_BASE+0x10);
    if (rdata !=0xffffffff)
        cpu_error("atb 2 axi interrput 0xffff_ffff set test fail rdata ==  0x%0x\n",rdata);

    wdata = 0x0;
    write32(NUCLEI_ATB2AXI_IP_BASE+0x10,wdata);
    rdata = read32(NUCLEI_ATB2AXI_IP_BASE+0x10);
    if (rdata !=0x0)
        cpu_error("atb 2 axi interrput 0x0 set test fail rdata ==  0x%0x\n",rdata);
*/

//    
//    cpu_info("c code atb to axi test 3333 !!!\n");

    set_atb2axi_enable();
    cpu_info("c code atb to axi test 4444 !!!\n");
//andyf ++
    write32(NUCLEI_ATB2AXI_IP_BASE+0x2c,0x1);       //timeout

  
    test();

    rdata = read32(NUCLEI_ATB2AXI_IP_BASE+0x14);    //maxtime
    if (rdata !=0x1)
        cpu_error("atb 2 axi interrput 0x0 set test fail rdata ==  0x%0x\n",rdata);


    write32(NUCLEI_ATB2AXI_IP_BASE+0x2c,0x0);

    set_trace_disable(1, (uintptr_t)&&finish);

    cpu_info("Execute test finish\n");

finish:
    cpu_info("NUCLEI_TEST_PASS\n");
       
    simend();
    while(1);
}


