// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

//#define CLM_BASE_ADDR          _AC(0x9080000,UL)
#define CLM_BASE_ADDR          _AC(0x40400000,UL) //andyf

#define CLUSTER_WAY_EN         _AC(0xffff,UL)

#define TYPE int

#define SMP_CTRLREG(base, ofs)      (*(volatile uint32_t *)((uintptr_t)((base) + (ofs))))
#define INITIAL_ADDR(addr)          (*(volatile uint32_t *)((uintptr_t)(addr)))

// test byte size
#define MEM_TEST_SIZE 256

void clm_init()
{
    unsigned long smp_base;
    //smp_base = SystemIRegionInfo.smp_base;
    smp_base = CFG_IREGION_BASE_ADDR + 0x40000;
    // Client Way Mask all off by default
	// Enable clm_way_en
	SMP_CTRLREG(smp_base,0xd8) = CLUSTER_WAY_EN;
	//Set clm_base_addr
	SMP_CTRLREG(smp_base,0xd0) = CLM_BASE_ADDR;
}

void flush_L2()
{
    // Flush L2
    // wait until all transaction finished
    unsigned long smp_base, pl2_base;
    volatile uint32_t *CC_mCMD;

    //smp_base = SystemIRegionInfo.smp_base;
    smp_base = CFG_IREGION_BASE_ADDR + 0x40000;

    //CC_TranPend = (uint32_t *)(SystemIRegionInfo.smp_base + 0xCC);
    // wait TRANS_PENDING == 0
    while ((0xffff & ((uint32_t)SMP_CTRLREG(smp_base, 0xCC))) != 0){

    }
    //CC_mCMD = (uint32_t *)(SystemIRegionInfo.smp_base + 0x14);

    //WBINVAL_ALL
    SMP_CTRLREG(smp_base, 0x14) = 0x06;
    // wait complete
    while (((1<<31) & ((uint32_t)SMP_CTRLREG(smp_base, 0x14))) != (1<<31)){

    }
}

//write
void write_mrge32(uintptr_t addr, uint32_t value)
{
	*(volatile uint32_t *)addr = value;
}

//read
uint32_t read_mreg32(uintptr_t addr)
{
	return *((volatile uint32_t *)(uintptr_t)addr);
}



int main(void)
{
    uint32_t rdata;
    uint32_t rdata32;
    uint64_t rdata64;
    
    uint32_t rval;
    char ret = 0;
	uintptr_t clm_addr;
	uint32_t orig;
	int count;

    volatile uint32_t mcfg_info, smp_cfg, cc_cfg;
    unsigned long smp_base;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    if (ICachePresent()) { // Check whether icache real present or not
        EnableICache();
    }
    if (DCachePresent()) { // Check whether dcache real present or not
        EnableDCache();
    }

    //smp_base = SystemIRegionInfo.smp_base;
    smp_base = CFG_IREGION_BASE_ADDR + 0x40000;
    mcfg_info = __RV_CSR_READ(CSR_MCFG_INFO);
    if (mcfg_info & BIT(11)) {
        smp_cfg = *(uint32_t *)(smp_base + 0x4);
        // smp all enabled
        SMP_CTRLREG(smp_base, 0xc) = 0xFFFFFFFF;

        // wheter L2 exist
        if (smp_cfg & BIT(0)) {
           // enable L2
           SMP_CTRLREG(smp_base, 0x10) = 0x1;
        }else{
            cpu_info("error : L2 not exists\n");
            return 1;
        }
    }else {
        cpu_info("error : smp not exists\n");
        return 1;
    }
    //flush dcache
    MFlushInvalDCache();
    //flush l2
    flush_L2();

    clm_init();
    //initial clm memory
	clm_addr = CLM_BASE_ADDR;
    for(int i = 0; i < MEM_TEST_SIZE/4; i+=4){
		INITIAL_ADDR(clm_addr + i) = clm_addr + i;
	}


    write32(CLM_BASE_ADDR,0xffffffff);
    rdata32=read32(CLM_BASE_ADDR);

    write32(CLM_BASE_ADDR,0x0);
    rdata32=read32(CLM_BASE_ADDR);

    write64(CLM_BASE_ADDR,0xffffffffffffffff);
    rdata64=read64(CLM_BASE_ADDR);

    write64(CLM_BASE_ADDR,0x0);
    rdata64=read64(CLM_BASE_ADDR);



    send_label(0x11112222);
    cpu_info("access clm done !!!\n");

    simend();
    while(1);
}

