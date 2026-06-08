#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"
#include "memmap_test_struct.h"

void test_memory_array(const MemTypeDef_t* array, size_t num_elements, const char* array_name) {
    cpu_info("Start testing array: %s\n", array_name);
    uint32_t test_val[2] = {0, 0xffffffff};
    uint32_t addr_hi;
    uint32_t addr_lo;
    for(int j = 0; j < 4; j++) {
        for(size_t i = 0; i < num_elements; i++) {
            uint64_t addr = array[i].soc_base + array[i].reg_offset;
            write32(addr, test_val[j]);
            uint32_t rdata = read32(addr);
            uint32_t rdata_exp = test_val[j];
            addr_hi = (uint32_t)(addr >> 32);
            addr_lo = (uint32_t)(addr & 0xFFFFFFFFu);
            if(rdata != rdata_exp) {
                cpu_error("%s %s ID=%u: addr=0x%x%x, exp=0x%x, act=0x%x, test_val[%d]=0x%x\n",
                          array_name, array[i].ip_name, (unsigned int)i, addr_hi, addr_lo, rdata_exp, rdata, j, test_val[j]);
            } else {
                cpu_info("%s %s addr=0x%x%x, ID=%u: Check Write&read val Pass !!!\n", 
                          array_name, array[i].ip_name, addr_hi, addr_lo, (unsigned int)i);
            }
        }
    }
}

int main(void)
{
    uint32_t rdata;
    uint32_t rval;
    set_uncache_region(0x401ff000, 0xffff000);   
    crg_init();
    
    write32(AON_SUB_PMU_BASE_ADDR+0x40,0x7ff);
    rdata = read32(UCIE_SUB_UCIE0_LSC_BASE_ADDR+0x1c);
    rdata = rdata & 0xfffffffc;
    write32(UCIE_SUB_UCIE0_LSC_BASE_ADDR+0x1c,rdata);

    rdata = read32(UCIE_SUB_UCIE1_LSC_BASE_ADDR+0x1c);
    rdata = rdata & 0xfffffffc;
    write32(UCIE_SUB_UCIE1_LSC_BASE_ADDR+0x1c,rdata);

    write32(HS_SUB_PCIESS0_PCIE0_REG_BASE_ADDR,0x1);     //release rst
    write32(HS_SUB_PCIESS0_PCIE1_REG_BASE_ADDR,0x1);

    cpu_info("Case4 memory test starting (UCIE/DDR/HS/new regions)\n");

    test_memory_array(jtag_ap_npu_sub_addr, sizeof(jtag_ap_npu_sub_addr)/sizeof(MemTypeDef_t), "jtag_ap_npu_sub_addr");
    test_memory_array(new_memory_regions, sizeof(new_memory_regions)/sizeof(MemTypeDef_t), "new_memory_regions");

    cpu_info("Case3 done !!!\n");
    simend();
    while(1);
}