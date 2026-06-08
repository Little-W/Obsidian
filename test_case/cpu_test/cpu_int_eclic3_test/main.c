// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

volatile int  int_flg = 0;
volatile int  irq_num = 0;

__INTERRUPT void core3_tbu1_pmu_intr_handler      (void) {cpu_info("[INT]core3_tbu1_pmu_intr_handler      hit\n"); send_label(NPU_CORE3_TBU1_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core3_tbu1_ras_intr_handler      (void) {cpu_info("[INT]core3_tbu1_ras_intr_handler      hit\n"); send_label(NPU_CORE3_TBU1_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core3_tbu0_pmu_intr_handler      (void) {cpu_info("[INT]core3_tbu0_pmu_intr_handler      hit\n"); send_label(NPU_CORE3_TBU0_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core3_tbu0_ras_intr_handler      (void) {cpu_info("[INT]core3_tbu0_ras_intr_handler      hit\n"); send_label(NPU_CORE3_TBU0_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core2_tbu1_pmu_intr_handler      (void) {cpu_info("[INT]core2_tbu1_pmu_intr_handler      hit\n"); send_label(NPU_CORE2_TBU1_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core2_tbu1_ras_intr_handler      (void) {cpu_info("[INT]core2_tbu1_ras_intr_handler      hit\n"); send_label(NPU_CORE2_TBU1_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core2_tbu0_pmu_intr_handler      (void) {cpu_info("[INT]core2_tbu0_pmu_intr_handler      hit\n"); send_label(NPU_CORE2_TBU0_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core2_tbu0_ras_intr_handler      (void) {cpu_info("[INT]core2_tbu0_ras_intr_handler      hit\n"); send_label(NPU_CORE2_TBU0_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core1_tbu1_pmu_intr_handler      (void) {cpu_info("[INT]core1_tbu1_pmu_intr_handler      hit\n"); send_label(NPU_CORE1_TBU1_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core1_tbu1_ras_intr_handler      (void) {cpu_info("[INT]core1_tbu1_ras_intr_handler      hit\n"); send_label(NPU_CORE1_TBU1_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core1_tbu0_pmu_intr_handler      (void) {cpu_info("[INT]core1_tbu0_pmu_intr_handler      hit\n"); send_label(NPU_CORE1_TBU0_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core1_tbu0_ras_intr_handler      (void) {cpu_info("[INT]core1_tbu0_ras_intr_handler      hit\n"); send_label(NPU_CORE1_TBU0_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core0_tbu1_pmu_intr_handler      (void) {cpu_info("[INT]core0_tbu1_pmu_intr_handler      hit\n"); send_label(NPU_CORE0_TBU1_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core0_tbu1_ras_intr_handler      (void) {cpu_info("[INT]core0_tbu1_ras_intr_handler      hit\n"); send_label(NPU_CORE0_TBU1_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core0_tbu0_pmu_intr_handler      (void) {cpu_info("[INT]core0_tbu0_pmu_intr_handler      hit\n"); send_label(NPU_CORE0_TBU0_PMU_INTR_IRQn  ); int_flg++;}
__INTERRUPT void core0_tbu0_ras_intr_handler      (void) {cpu_info("[INT]core0_tbu0_ras_intr_handler      hit\n"); send_label(NPU_CORE0_TBU0_RAS_INTR_IRQn  ); int_flg++;}
__INTERRUPT void media_tbu_pmu_intr_handler       (void) {cpu_info("[INT]media_tbu_pmu_intr               hit\n"); send_label(MEDIA_TBU_PMU_INTR_IRQn       );
            scu_clear_intr_raw(1u << 17);
 int_flg++;}//1209
__INTERRUPT void media_tbu_ras_intr_handler       (void) {cpu_info("[INT]media_tbu_ras_intr               hit\n"); send_label(MEDIA_TBU_RAS_INTR_IRQn       );
            scu_clear_intr_raw(1u << 18);
 int_flg++;}//1209
__INTERRUPT void tcu_global_intr_s_handler        (void) {cpu_info("[INT]tcu_global_intr_s_handler        hit\n"); send_label(TCU_GLOBAL_INTR_S_IRQn        ); 
            scu_clear_intr_raw(1u << 0);
int_flg++;}//1209
__INTERRUPT void tcu_pri_q_intr_ns_handler        (void) {cpu_info("[INT]tcu_pri_q_intr_ns_handler        hit\n"); send_label(TCU_PRI_Q_INTR_NS_IRQn        ); 
            scu_clear_intr_raw(1u << 1);
int_flg++;}//1209
__INTERRUPT void tcu_global_intr_ns_handler       (void) {cpu_info("[INT]tcu_global_intr_ns_handler       hit\n"); send_label(TCU_GLOBAL_INTR_NS_IRQn       );
            scu_clear_intr_raw(1u << 2);
 int_flg++;}
__INTERRUPT void tcu_cmd_sync_intr_ns_handler     (void) {cpu_info("[INT]tcu_cmd_sync_intr_ns_handler     hit\n"); send_label(TCU_CMD_SYNC_INTR_NS_IRQn     );
            scu_clear_intr_raw(1u << 3);
 int_flg++;}
__INTERRUPT void tcu_cmd_sync_intr_s_handler      (void) {cpu_info("[INT]tcu_cmd_sync_intr_s_handler      hit\n"); send_label(TCU_CMD_SYNC_INTR_S_IRQn      );
            scu_clear_intr_raw(1u << 4);
int_flg++;}
__INTERRUPT void tcu_event_q_intr_ns_handler      (void) {cpu_info("[INT]tcu_event_q_intr_ns_handler      hit\n"); send_label(TCU_EVENT_Q_INTR_NS_IRQn      ); 
            scu_clear_intr_raw(1u << 5);
int_flg++;}
__INTERRUPT void tcu_event_q_intr_s_handler       (void) {cpu_info("[INT]tcu_event_q_intr_s_handler       hit\n"); send_label(TCU_EVENT_Q_INTR_S_IRQn       );
            scu_clear_intr_raw(1u << 6);
 int_flg++;}
__INTERRUPT void tcu_pmu_intr_handler             (void) {cpu_info("[INT]tcu_pmu_intr_handler             hit\n"); send_label(TCU_PMU_INTR_IRQn             );
            scu_clear_intr_raw(1u << 7);
 int_flg++;}
__INTERRUPT void tcu_ras_intr_handler             (void) {cpu_info("[INT]tcu_ras_intr_handler             hit\n"); send_label(TCU_RAS_INTR_0_IRQn           ); 
            scu_clear_intr_raw(1u << 8);
int_flg++;}
__INTERRUPT void barrier_intr_handler             (void) {cpu_info("[INT]barrier_intr_handler             hit\n"); send_label(BARRIER_INTR_0_IRQn           ); int_flg++;}
__INTERRUPT void npu_intr3_0_handler              (void) {cpu_info("[INT]npu_intr3_0_handler              hit\n"); send_label(NPU_INTR3_0_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr3_1_handler              (void) {cpu_info("[INT]npu_intr3_1_handler              hit\n"); send_label(NPU_INTR3_1_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr3_2_handler              (void) {cpu_info("[INT]npu_intr3_2_handler              hit\n"); send_label(NPU_INTR3_2_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr3_3_handler              (void) {cpu_info("[INT]npu_intr3_3_handler              hit\n"); send_label(NPU_INTR3_3_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr3_4_handler              (void) {cpu_info("[INT]npu_intr3_4_handler              hit\n"); send_label(NPU_INTR3_4_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr3_5_handler              (void) {cpu_info("[INT]npu_intr3_5_handler              hit\n"); send_label(NPU_INTR3_5_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr3_6_handler              (void) {cpu_info("[INT]npu_intr3_6_handler              hit\n"); send_label(NPU_INTR3_6_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr3_7_handler              (void) {cpu_info("[INT]npu_intr3_7_handler              hit\n"); send_label(NPU_INTR3_7_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr2_0_handler              (void) {cpu_info("[INT]npu_intr2_0_handler              hit\n"); send_label(NPU_INTR2_0_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr2_1_handler              (void) {cpu_info("[INT]npu_intr2_1_handler              hit\n"); send_label(NPU_INTR2_1_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr2_2_handler              (void) {cpu_info("[INT]npu_intr2_2_handler              hit\n"); send_label(NPU_INTR2_2_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr2_3_handler              (void) {cpu_info("[INT]npu_intr2_3_handler              hit\n"); send_label(NPU_INTR2_3_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr2_4_handler              (void) {cpu_info("[INT]npu_intr2_4_handler              hit\n"); send_label(NPU_INTR2_4_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr2_5_handler              (void) {cpu_info("[INT]npu_intr2_5_handler              hit\n"); send_label(NPU_INTR2_5_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr2_6_handler              (void) {cpu_info("[INT]npu_intr2_6_handler              hit\n"); send_label(NPU_INTR2_6_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr2_7_handler              (void) {cpu_info("[INT]npu_intr2_7_handler              hit\n"); send_label(NPU_INTR2_7_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr1_0_handler              (void) {cpu_info("[INT]npu_intr1_0_handler              hit\n"); send_label(NPU_INTR1_0_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr1_1_handler              (void) {cpu_info("[INT]npu_intr1_1_handler              hit\n"); send_label(NPU_INTR1_1_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr1_2_handler              (void) {cpu_info("[INT]npu_intr1_2_handler              hit\n"); send_label(NPU_INTR1_2_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr1_3_handler              (void) {cpu_info("[INT]npu_intr1_3_handler              hit\n"); send_label(NPU_INTR1_3_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr1_4_handler              (void) {cpu_info("[INT]npu_intr1_4_handler              hit\n"); send_label(NPU_INTR1_4_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr1_5_handler              (void) {cpu_info("[INT]npu_intr1_5_handler              hit\n"); send_label(NPU_INTR1_5_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr1_6_handler              (void) {cpu_info("[INT]npu_intr1_6_handler              hit\n"); send_label(NPU_INTR1_6_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr1_7_handler              (void) {cpu_info("[INT]npu_intr1_7_handler              hit\n"); send_label(NPU_INTR1_7_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr0_0_handler              (void) {cpu_info("[INT]npu_intr0_0_handler              hit\n"); send_label(NPU_INTR0_0_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr0_1_handler              (void) {cpu_info("[INT]npu_intr0_1_handler              hit\n"); send_label(NPU_INTR0_1_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr0_2_handler              (void) {cpu_info("[INT]npu_intr0_2_handler              hit\n"); send_label(NPU_INTR0_2_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr0_3_handler              (void) {cpu_info("[INT]npu_intr0_3_handler              hit\n"); send_label(NPU_INTR0_3_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr0_4_handler              (void) {cpu_info("[INT]npu_intr0_4_handler              hit\n"); send_label(NPU_INTR0_4_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr0_5_handler              (void) {cpu_info("[INT]npu_intr0_5_handler              hit\n"); send_label(NPU_INTR0_5_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr0_6_handler              (void) {cpu_info("[INT]npu_intr0_6_handler              hit\n"); send_label(NPU_INTR0_6_IRQn              ); int_flg++;}
__INTERRUPT void npu_intr0_7_handler              (void) {cpu_info("[INT]npu_intr0_7_handler              hit\n"); send_label(NPU_INTR0_7_IRQn              ); int_flg++;}
__INTERRUPT void npu_wdt_intr3_handler            (void) {cpu_info("[INT]npu_wdt_intr3_handler            hit\n"); send_label(NPU_WDT_INTR3_IRQn            ); int_flg++;}
__INTERRUPT void npu_wdt_intr2_handler            (void) {cpu_info("[INT]npu_wdt_intr2_handler            hit\n"); send_label(NPU_WDT_INTR2_IRQn            ); int_flg++;}
__INTERRUPT void npu_wdt_intr1_handler            (void) {cpu_info("[INT]npu_wdt_intr1_handler            hit\n"); send_label(NPU_WDT_INTR1_IRQn            ); int_flg++;}
__INTERRUPT void npu_wdt_intr0_handler            (void) {cpu_info("[INT]npu_wdt_intr0_handler            hit\n"); send_label(NPU_WDT_INTR0_IRQn            ); int_flg++;}
__INTERRUPT void mcu_wdt_intr_handler             (void) {cpu_info("[INT]mcu_wdt_intr_handler             hit\n"); send_label(MCU_WDT_INTR_IRQn             ); int_flg++;
irq_num = MCU_WDT_INTR_IRQn;
}

int main(void)
{
    uint32_t returnCode;
    CSR_MCFGINFO_Type mcfg;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    cpu_info("ECLIC_Interrupt_Test start 1111111\n");

    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU1_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core3_tbu1_pmu_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU1_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core3_tbu1_ras_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU0_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core3_tbu0_pmu_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE3_TBU0_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core3_tbu0_ras_intr_handler          );   
    returnCode = ECLIC_Register_IRQ(NPU_CORE2_TBU1_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core2_tbu1_pmu_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE2_TBU1_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core2_tbu1_ras_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE2_TBU0_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core2_tbu0_pmu_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE2_TBU0_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core2_tbu0_ras_intr_handler          );   
    returnCode = ECLIC_Register_IRQ(NPU_CORE1_TBU1_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core1_tbu1_pmu_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE1_TBU1_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core1_tbu1_ras_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE1_TBU0_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core1_tbu0_pmu_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE1_TBU0_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core1_tbu0_ras_intr_handler          );   
    returnCode = ECLIC_Register_IRQ(NPU_CORE0_TBU1_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core0_tbu1_pmu_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE0_TBU1_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core0_tbu1_ras_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE0_TBU0_PMU_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core0_tbu0_pmu_intr_handler          );
    returnCode = ECLIC_Register_IRQ(NPU_CORE0_TBU0_RAS_INTR_IRQn         ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)core0_tbu0_ras_intr_handler          );   
    returnCode = ECLIC_Register_IRQ(MEDIA_TBU_PMU_INTR_IRQn              ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)media_tbu_pmu_intr_handler           );
    returnCode = ECLIC_Register_IRQ(MEDIA_TBU_RAS_INTR_IRQn              ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)media_tbu_ras_intr_handler           );
    returnCode = ECLIC_Register_IRQ(TCU_GLOBAL_INTR_S_IRQn               ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)tcu_global_intr_s_handler            );
    returnCode = ECLIC_Register_IRQ(TCU_PRI_Q_INTR_NS_IRQn               ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)tcu_pri_q_intr_ns_handler            );
    returnCode = ECLIC_Register_IRQ(TCU_GLOBAL_INTR_NS_IRQn              ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)tcu_global_intr_ns_handler           );
    returnCode = ECLIC_Register_IRQ(TCU_CMD_SYNC_INTR_NS_IRQn            ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)tcu_cmd_sync_intr_ns_handler         );
    returnCode = ECLIC_Register_IRQ(TCU_CMD_SYNC_INTR_S_IRQn             ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)tcu_cmd_sync_intr_s_handler          );
    returnCode = ECLIC_Register_IRQ(TCU_EVENT_Q_INTR_NS_IRQn             ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)tcu_event_q_intr_ns_handler          );
    returnCode = ECLIC_Register_IRQ(TCU_EVENT_Q_INTR_S_IRQn              ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)tcu_event_q_intr_s_handler           );
    returnCode = ECLIC_Register_IRQ(TCU_PMU_INTR_IRQn                    ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)tcu_pmu_intr_handler                 );
    returnCode = ECLIC_Register_IRQ(TCU_RAS_INTR_0_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)tcu_ras_intr_handler                 ); //1209
    returnCode = ECLIC_Register_IRQ(BARRIER_INTR_0_IRQn                  ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)barrier_intr_handler                 ); //1209
    returnCode = ECLIC_Register_IRQ(NPU_INTR3_0_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr3_0_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR3_1_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr3_1_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR3_2_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr3_2_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR3_3_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr3_3_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR3_4_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr3_4_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR3_5_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr3_5_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR3_6_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr3_6_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR3_7_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr3_7_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR2_0_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr2_0_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR2_1_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr2_1_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR2_2_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr2_2_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR2_3_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr2_3_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR2_4_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr2_4_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR2_5_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr2_5_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR2_6_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr2_6_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR2_7_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr2_7_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR1_0_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr1_0_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR1_1_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr1_1_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR1_2_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr1_2_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR1_3_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr1_3_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR1_4_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr1_4_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR1_5_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr1_5_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR1_6_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr1_6_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR1_7_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr1_7_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR0_0_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr0_0_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR0_1_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr0_1_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR0_2_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr0_2_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR0_3_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr0_3_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR0_4_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr0_4_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR0_5_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr0_5_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR0_6_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr0_6_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_INTR0_7_IRQn                     ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_intr0_7_handler                  );
    returnCode = ECLIC_Register_IRQ(NPU_WDT_INTR3_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_wdt_intr3_handler                );
    returnCode = ECLIC_Register_IRQ(NPU_WDT_INTR2_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_wdt_intr2_handler                );
    returnCode = ECLIC_Register_IRQ(NPU_WDT_INTR1_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_wdt_intr1_handler                );
    returnCode = ECLIC_Register_IRQ(NPU_WDT_INTR0_IRQn                   ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)npu_wdt_intr0_handler                );
    returnCode = ECLIC_Register_IRQ(MCU_WDT_INTR_IRQn                    ,   ECLIC_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0, (void*)mcu_wdt_intr_handler                 );

    __enable_irq();

    send_label(0x12345678);

    while(irq_num != MCU_WDT_INTR_IRQn);{
        cpu_info("wait all int done !!!\n");
    }

    
    cpu_info("cpu test done !!!\n");

    simend();
    while(1);
}


