/* case1: AON + MCU + CRG 测试 */
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

void test_crg_array(const PhyRegTypeDef_t* array, size_t num_elements, const char* array_name) {
    for(size_t i = 0; i < num_elements; i++) {
        uint64_t addr = array[i].soc_base + array[i].reg_offset;
        uint32_t addr_hi = (uint32_t)(addr >> 32);
        uint32_t addr_lo = (uint32_t)(addr & 0xFFFFFFFFu);

        // 1. Initial/Reset Value Check
        uint32_t rdata = read32(addr);
        if (rdata != array[i].reset_value) {
            cpu_error("%s %s Index=%u: ResetValue Error! addr=0x%x%x, exp=0x%x, act=0x%x\n",
                      array_name, array[i].ip_name, (unsigned int)array[i].index, addr_hi, addr_lo, array[i].reset_value, rdata);
        }

        // 2. Write Mask Test
        uint32_t test_vals[2] = {0x55555555, 0xAAAAAAAA};
        for(int j = 0; j < 2; j++) {
            write32(addr, test_vals[j]);
            rdata = read32(addr);
            uint32_t exp_data = (test_vals[j] & array[i].wr_mask) | (array[i].reset_value & ~array[i].wr_mask);
            if (rdata != exp_data) {
                cpu_error("%s %s Index=%u: Mask Write Error! addr=0x%x%x, write=0x%x, exp=0x%x, act=0x%x\n",
                          array_name, array[i].ip_name, (unsigned int)array[i].index, addr_hi, addr_lo, test_vals[j], exp_data, rdata);
            }
        }
        cpu_info("%s %s Index=%u: Initial & Mask Test Pass !!!\n", 
                 array_name, array[i].ip_name, (unsigned int)array[i].index);
    }
}

int main(void)
{
    uint32_t rdata;
    uint32_t rval;
    set_uncache_region(0x401ff000, 0xffff000);

    crg_init();
    cpu_info("Single-core memory test starting\n");
    
    write32(AON_SUB_PMU_BASE_ADDR+0x40,0x7ff);
    rdata = read32(UCIE_SUB_UCIE0_LSC_BASE_ADDR+0x1c);
    rdata &= 0xfffffffc;
    write32(UCIE_SUB_UCIE0_LSC_BASE_ADDR+0x1c,rdata);

    rdata = read32(UCIE_SUB_UCIE1_LSC_BASE_ADDR+0x1c);
    rdata &= 0xfffffffc;
    write32(UCIE_SUB_UCIE1_LSC_BASE_ADDR+0x1c,rdata);
    
    // perform memory test
    cpu_info("write&read test");

    test_memory_array(jtag_ap_mcu0_sub_addr, sizeof(jtag_ap_mcu0_sub_addr)/sizeof(MemTypeDef_t), "jtag_ap_mcu0_sub_addr");
    test_memory_array(jtag_ap_ucie_sub_addr, sizeof(jtag_ap_ucie_sub_addr)/sizeof(MemTypeDef_t), "jtag_ap_ucie_sub_addr");

    // CRG Dedicated Tests
    // test_crg_array(jtag_ap_aoncrg_sub_reg, sizeof(jtag_ap_aoncrg_sub_reg)/sizeof(PhyRegTypeDef_t), "jtag_ap_aoncrg_sub_reg");
    // test_crg_array(jtag_ap_mculcrg_sub_reg, sizeof(jtag_ap_mculcrg_sub_reg)/sizeof(PhyRegTypeDef_t), "jtag_ap_mculcrg_sub_reg");
    // test_crg_array(jtag_ap_hscrg_sub_cfg4_reg, sizeof(jtag_ap_hscrg_sub_cfg4_reg)/sizeof(PhyRegTypeDef_t), "jtag_ap_hscrg_sub_cfg4_reg");

    cpu_info("axi access device reg done !!!\n");
    simend();
    while(1);
}