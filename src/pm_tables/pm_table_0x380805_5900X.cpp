#include <pm_tables.h>
#include "macros.h"

void pm_table_0x380805(pm_table *pmt, unsigned char* base_addr)
{
    // Tested with:
    // Ryzen 5900X on Gigabyte B55M AORUS Pro-P, Bios V13i, SMU FW v56.50.0, AGESA ComboV2 1.2.0.2

    pmt->version = 0x380805;
    pmt->max_cores = 16; //Number of cores supported by this PM table version
    pmt->max_l3 = 2; //Number of L3 caches supported by this PM table version
    pmt->zen_version = 3; //Zen3

    /* Legend for notes in comments:
     * o = ok. I'm confident this is the right value.
     * s = static. Does not change unter load.
     * z = always zero
     * c = changes under load. Don't know if the value is correct.
     */

    pmt->PPT_LIMIT                  = pm_element( 0); //o
    pmt->PPT_VALUE                  = pm_element( 1); //o
    pmt->TDC_LIMIT                  = pm_element( 2); //o
    pmt->TDC_VALUE                  = pm_element( 3); //o
    pmt->THM_LIMIT                  = pm_element( 4); //o
    pmt->THM_VALUE                  = pm_element( 5); //o
    pmt->FIT_LIMIT                  = pm_element( 6); //o
    pmt->FIT_VALUE                  = pm_element( 7); //o
    pmt->EDC_LIMIT                  = pm_element( 8); //o
    pmt->EDC_VALUE                  = pm_element( 9); //o
    pmt->VID_LIMIT                  = pm_element(10); //o
    pmt->VID_VALUE                  = pm_element(11); //o

    pmt->PPT_WC                     = pm_element(12);
    pmt->PPT_ACTUAL                 = pm_element(13); //o
    pmt->TDC_WC                     = pm_element(14);
    pmt->TDC_ACTUAL                 = pm_element(15); //o
    pmt->THM_WC                     = pm_element(16);
    pmt->THM_ACTUAL                 = pm_element(17); //o
    pmt->FIT_WC                     = pm_element(18);
    pmt->FIT_ACTUAL                 = pm_element(19); //o
    pmt->EDC_WC                     = pm_element(20);
    pmt->EDC_ACTUAL                 = pm_element(21); //o
    pmt->VID_WC                     = pm_element(22);
    pmt->VID_ACTUAL                 = pm_element(23); //o

    pmt->VDDCR_CPU_POWER            = pm_element(24); //o
    pmt->VDDCR_SOC_POWER            = pm_element(25); //o
    pmt->VDDIO_MEM_POWER            = pm_element(26); //o
    pmt->VDD18_POWER                = pm_element(27); //o
    pmt->ROC_POWER                  = pm_element(28); //s
    pmt->SOCKET_POWER               = pm_element(29); //o

    pmt->PPT_FREQUENCY              = pm_element(30);
    pmt->TDC_FREQUENCY              = pm_element(31);
    pmt->THM_FREQUENCY              = pm_element(32);
    pmt->PROCHOT_FREQUENCY          = pm_element(33);
    pmt->VOLTAGE_FREQUENCY          = pm_element(34);
    pmt->CCA_FREQUENCY              = pm_element(35);

    pmt->FIT_VOLTAGE                = pm_element(36);
    pmt->FIT_PRE_VOLTAGE            = pm_element(37);
    pmt->LATCHUP_VOLTAGE            = pm_element(38);
    pmt->CPU_SET_VOLTAGE            = pm_element(39); //os6
    pmt->CPU_TELEMETRY_VOLTAGE      = pm_element(40);
    pmt->CPU_TELEMETRY_VOLTAGE2     = pm_element(41);
    pmt->CPU_TELEMETRY_CURRENT      = pm_element(42); //o
    pmt->CPU_TELEMETRY_POWER        = pm_element(43); //o
    pmt->SOC_SET_VOLTAGE            = pm_element(44); //os
    pmt->SOC_TELEMETRY_VOLTAGE      = pm_element(45); //o
    pmt->SOC_TELEMETRY_CURRENT      = pm_element(46); //o
    pmt->SOC_TELEMETRY_POWER        = pm_element(47); //o

    pmt->FCLK_FREQ                  = pm_element(48); //o
    pmt->FCLK_FREQ_EFF              = pm_element(49); //o
    pmt->UCLK_FREQ                  = pm_element(50); //o
    pmt->MEMCLK_FREQ                = pm_element(51); //o
    pmt->FCLK_DRAM_SETPOINT         = pm_element(52);
    pmt->FCLK_DRAM_BUSY             = pm_element(53);
    pmt->FCLK_GMI_SETPOINT          = pm_element(54);
    pmt->FCLK_GMI_BUSY              = pm_element(55);
    pmt->FCLK_IOHC_SETPOINT         = pm_element(56);
    pmt->FCLK_IOHC_BUSY             = pm_element(57);
    pmt->FCLK_MEM_LATENCY_SETPOINT  = pm_element(58);
    pmt->FCLK_MEM_LATENCY           = pm_element(59);
    pmt->FCLK_CCLK_SETPOINT         = pm_element(60);
    pmt->FCLK_CCLK_FREQ             = pm_element(61);
    pmt->FCLK_XGMI_SETPOINT         = pm_element(62);
    pmt->FCLK_XGMI_BUSY             = pm_element(63);

    pmt->CCM_READS                  = pm_element(64);
    pmt->CCM_WRITES                 = pm_element(65);
    pmt->IOMS                       = pm_element(66);
    pmt->XGMI                       = pm_element(67);
    pmt->CS_UMC_READS               = pm_element(68);
    pmt->CS_UMC_WRITES              = pm_element(69);

    assign_pm_elements_4(pmt->FCLK_RESIDENCY,     70,  71,  72,  73);
    assign_pm_elements_4(pmt->FCLK_FREQ_TABLE,    74,  75,  76,  77);
    assign_pm_elements_4(pmt->UCLK_FREQ_TABLE,    78,  79,  80,  81);
    assign_pm_elements_4(pmt->MEMCLK_FREQ_TABLE,  82,  83,  84,  85);
    assign_pm_elements_4(pmt->FCLK_VOLTAGE,       86,  87,  88,  89);

    assign_pm_elements_4(pmt->LCLK_SETPOINT,      90,  98, 106, 114);
    assign_pm_elements_4(pmt->LCLK_BUSY,          91,  99, 107, 115);
    assign_pm_elements_4(pmt->LCLK_FREQ,          92, 100, 108, 116);
    assign_pm_elements_4(pmt->LCLK_FREQ_EFF,      93, 101, 109, 117);
    assign_pm_elements_4(pmt->LCLK_MAX_DPM,       94, 102, 110, 118);
    assign_pm_elements_4(pmt->LCLK_MIN_DPM,       95, 103, 111, 119);
    assign_pm_elements_4(pmt->SOCCLK_FREQ_EFF,    96, 104, 112, 120);
    assign_pm_elements_4(pmt->SHUBCLK_FREQ_EFF,   97, 105, 113, 121);

    pmt->XGMI_SETPOINT              = pm_element(122);
    pmt->XGMI_BUSY                  = pm_element(123);
    pmt->XGMI_LANE_WIDTH            = pm_element(124);
    pmt->XGMI_DATA_RATE             = pm_element(125);

    pmt->SOC_POWER                  = pm_element(126); //x
    pmt->SOC_TEMP                   = pm_element(127); //o?
    pmt->DDR_VDDP_POWER             = pm_element(128);
    pmt->DDR_VDDIO_MEM_POWER        = pm_element(129);
    pmt->GMI2_VDDG_POWER            = pm_element(130);
    pmt->IO_VDDCR_SOC_POWER         = pm_element(131);
    pmt->IOD_VDDIO_MEM_POWER        = pm_element(132);
    pmt->IO_VDD18_POWER             = pm_element(133);
    pmt->TDP                        = pm_element(134);
    pmt->DETERMINISM                = pm_element(135);
    pmt->V_VDDM                     = pm_element(136);
    pmt->V_VDDP                     = pm_element(137);
    pmt->V_VDDG_IOD                 = pm_element(138);
    pmt->V_VDDG_CCD                 = pm_element(139);

    pmt->PEAK_TEMP                  = pm_element(140); //??
    pmt->PEAK_VOLTAGE               = pm_element(141); //o
    pmt->PEAK_CCLK_FREQ             = pm_element(142); //o
    //143 peak (requested?) voltage?
    //144 temp? power? 34->58
    //145 temp? power? 49->65
    pmt->AVG_CORE_COUNT             = pm_element(146); //o
    pmt->CCLK_LIMIT                 = pm_element(147); //o
    pmt->MAX_SOC_VOLTAGE            = pm_element(148); //o
    pmt->DVO_VOLTAGE                = pm_element(149);
    pmt->APML_POWER                 = pm_element(150); //? some power at least. 22->86 in 64W eco mode. PPT maybe?
    pmt->CPU_DC_BTC                 = pm_element(151);
    pmt->SOC_DC_BTC                 = pm_element(152);
    pmt->CSTATE_BOOST               = pm_element(153);
    pmt->PROCHOT                    = pm_element(154);
    pmt->PC6                        = pm_element(155); //o
    pmt->SELF_REFRESH               = pm_element(156); //?
    pmt->PWM                        = pm_element(157); //?
    pmt->SOCCLK                     = pm_element(158);
    pmt->SHUBCLK                    = pm_element(159);
    pmt->SMNCLK                     = pm_element(160);
    pmt->SMNCLK_EFF                 = pm_element(161);
    pmt->MP0CLK                     = pm_element(162);
    pmt->MP0CLK_EFF                 = pm_element(163);
    pmt->MP1CLK                     = pm_element(164);
    pmt->MP1CLK_EFF                 = pm_element(165);
    pmt->MP5CLK                     = pm_element(166);
    pmt->TWIXCLK                    = pm_element(167);
    pmt->WAFLCLK                    = pm_element(168); //0 in https://chart-studio.plotly.com/~brettdram/16/
    pmt->DPM_BUSY                   = pm_element(169);
    pmt->MP1_BUSY                   = pm_element(170);
    pmt->DPM_Skipped                = pm_element(171);

    assign_pm_elements_16_consec(pmt->CORE_POWER       , 172); //o
    assign_pm_elements_16_consec(pmt->CORE_VOLTAGE     , 188); //o
    assign_pm_elements_16_consec(pmt->CORE_TEMP        , 204); //o 37->65
    assign_pm_elements_16_consec(pmt->CORE_FIT         , 220); //o
    assign_pm_elements_16_consec(pmt->CORE_IDDMAX      , 236); //o
    assign_pm_elements_16_consec(pmt->CORE_FREQ        , 252); //o
    assign_pm_elements_16_consec(pmt->CORE_FREQEFF     , 268); //o
    assign_pm_elements_16_consec(pmt->CORE_C0          , 284); //o
    assign_pm_elements_16_consec(pmt->CORE_CC1         , 300); //o
    assign_pm_elements_16_consec(pmt->CORE_CC6         , 316); //o
    assign_pm_elements_16_consec(pmt->CORE_CKS_FDD     , 332); //z
    assign_pm_elements_16_consec(pmt->CORE_CI_FDD      , 348); //z
    assign_pm_elements_16_consec(pmt->CORE_IRM         , 364); //o
    assign_pm_elements_16_consec(pmt->CORE_PSTATE      , 380); //o
    assign_pm_elements_16_consec(pmt->CORE_FREQ_LIM_MAX, 396); //o
    assign_pm_elements_16_consec(pmt->CORE_FREQ_LIM_MIN, 412); //o
    assign_pm_elements_16_consec(pmt->CORE_unk         , 428); //z
    assign_pm_elements_16_consec(pmt->CORE_SC_LIMIT    , 444); //55->21
    assign_pm_elements_16_consec(pmt->CORE_SC_CAC      , 460); //0->13
    assign_pm_elements_16_consec(pmt->CORE_SC_RESIDENCY, 476); //z
    assign_pm_elements_16_consec(pmt->CORE_UOPS_CLK    , 492); //0->6
    assign_pm_elements_16_consec(pmt->CORE_UOPS        , 508); //200->12000
    assign_pm_elements_16_consec(pmt->CORE_MEM_LATECY  , 524); //15->350

    assign_pm_elements_2(pmt->L3_LOGIC_POWER   , 540, 541);
    assign_pm_elements_2(pmt->L3_VDDM_POWER    , 542, 543);
    assign_pm_elements_2(pmt->L3_TEMP          , 544, 545);
    assign_pm_elements_2(pmt->L3_FIT           , 546, 547);
    assign_pm_elements_2(pmt->L3_IDDMAX        , 548, 549);
    assign_pm_elements_2(pmt->L3_FREQ          , 550, 551);
    assign_pm_elements_2(pmt->L3_FREQ_EFF      , 552, 553);
    assign_pm_elements_2(pmt->L3_CKS_FDD       , 554, 555);
    assign_pm_elements_2(pmt->L3_CCA_THRESHOLD , 556, 557);
    assign_pm_elements_2(pmt->L3_CCA_CAC       , 558, 559);
    assign_pm_elements_2(pmt->L3_CCA_ACTIVATION, 560, 561);
    assign_pm_elements_2(pmt->L3_EDC_LIMIT     , 562, 563);
    assign_pm_elements_2(pmt->L3_EDC_CAC       , 564, 565);
    assign_pm_elements_2(pmt->L3_EDC_RESIDENCY , 566, 567);
    assign_pm_elements_2(pmt->L3_FLL_BTC       , 568, 569);
    assign_pm_elements_2(pmt->MP5_BUSY         , 570, 571);

    pmt->min_size = 572*4; //(Highest element we access + 1)*4.
        //Needed to avoid illegal memory access
}
