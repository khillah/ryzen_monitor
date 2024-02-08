#include <pm_tables.h>
#include "macros.h"

void pm_table_0x400005(pm_table *pmt, unsigned char* base_addr)
{
    // Ryzen 5700G. Mapping kindly provided by PJVol

    pmt->version = 0x400005;
    pmt->max_cores = 8; //Number of cores supported by this PM table version
    pmt->max_l3 = 1; //Number of L3 caches supported by this PM table version
    pmt->zen_version = 3; //Zen3
    pmt->experimental = 0; //Print experimental note
    pmt->powersum_unclear = 1; //No idea how to calculate the total power
    pmt->has_graphics = 1; //Print GFX information


    pmt->STAPM_LIMIT                = pm_element(0);
    pmt->STAPM_VALUE                = pm_element(1);
    pmt->PPT_LIMIT_FAST             = pm_element(2);
    pmt->PPT_VALUE_FAST             = pm_element(3);
    pmt->PPT_LIMIT                  = pm_element(4); //Slow
    pmt->PPT_VALUE                  = pm_element(5); //Slow
    pmt->PPT_LIMIT_APU              = pm_element(6);
    pmt->PPT_VALUE_APU              = pm_element(7);
    pmt->TDC_LIMIT                  = pm_element(8); //VDD
    pmt->TDC_VALUE                  = pm_element(9); //VDD
    pmt->TDC_LIMIT_SOC              = pm_element(10);
    pmt->TDC_VALUE_SOC              = pm_element(11);
    pmt->EDC_LIMIT                  = pm_element(12); //Core
    pmt->EDC_VALUE                  = pm_element(13); //Core
    pmt->EDC_LIMIT_SOC              = pm_element(14);
    pmt->EDC_VALUE_SOC              = pm_element(15);
    pmt->THM_LIMIT                  = pm_element(16); //Core
    pmt->THM_VALUE                  = pm_element(17); //Core
    pmt->THM_LIMIT_GFX              = pm_element(18);
    pmt->THM_VALUE_GFX              = pm_element(19);
    pmt->THM_LIMIT_SOC              = pm_element(20);
    pmt->THM_VALUE_SOC              = pm_element(21);
    pmt->STT_LIMIT_APU              = pm_element(22);
    pmt->STT_VALUE_APU              = pm_element(23);
    pmt->STT_LIMIT_DGPU             = pm_element(24);
    pmt->STT_VALUE_DGPU             = pm_element(25);
    pmt->FIT_LIMIT                  = pm_element(26);
    pmt->FIT_VALUE                  = pm_element(27);
    pmt->VID_LIMIT                  = pm_element(28);
    pmt->VID_VALUE                  = pm_element(29);
    pmt->PSI0_LIMIT_VDD             = pm_element(30);
    pmt->PSI0_RESIDENCY_VDD         = pm_element(31);
    pmt->PSI0_LIMIT_SOC             = pm_element(32);
    pmt->PSI0_RESIDENCY_SOC         = pm_element(33);


    pmt->VDDCR_CPU_POWER            = pm_element(34);
    pmt->VDDCR_SOC_POWER            = pm_element(35);
    pmt->VDDIO_MEM_POWER            = pm_element(36);
    pmt->ROC_POWER                  = pm_element(37);
    pmt->SOCKET_POWER               = pm_element(38);
    pmt->TDP                        = pm_element(38); //Don't know where to get TDP from. Set equal to socket power for now
    pmt->PACKAGE_POWER              = pm_element(38); //Doesn't seem to have package power. Use socket power instead.
    pmt->GLOB_FREQUENCY             = pm_element(39);
    pmt->STAPM_FREQUENCY            = pm_element(40);
    pmt->PPT_FREQUENCY_FAST         = pm_element(41);
    pmt->PPT_FREQUENCY              = pm_element(42); //PPT_FREQUENCY_SLOW
    pmt->PPT_FREQUENCY_APU          = pm_element(43);
    pmt->TDC_FREQUENCY              = pm_element(44);
    pmt->THM_FREQUENCY              = pm_element(45);
    pmt->HTFMAX_FREQUENCY           = pm_element(46);
    pmt->PROCHOT_FREQUENCY          = pm_element(47);
    pmt->VOLTAGE_FREQUENCY          = pm_element(48);
    pmt->CCA_FREQUENCY              = pm_element(49);
    pmt->GFX_GLOB_FREQUENCY         = pm_element(50);
    pmt->GFX_STAPM_FREQUENCY        = pm_element(51);
    pmt->GFX_PPT_FREQUENCY_FAST     = pm_element(52);
    pmt->GFX_PPT_FREQUENCY          = pm_element(53);
    pmt->GFX_PPT_FREQUENCY_APU      = pm_element(54);
    pmt->GFX_TDC_FREQUENCY          = pm_element(55);
    pmt->GFX_THM_FREQUENCY          = pm_element(56);
    pmt->GFX_HTFMAX_FREQUENCY       = pm_element(57);
    pmt->GFX_PROCHOT_FREQUENCY      = pm_element(58);
    pmt->GFX_VOLTAGE_FREQUENCY      = pm_element(59);
    pmt->GFX_CCA_FREQUENCY          = pm_element(60);
    pmt->GFX_DEM_FREQUENCY          = pm_element(61);

    pmt->FIT_VOLTAGE                = pm_element(62);
    pmt->LATCHUP_VOLTAGE            = pm_element(63);
    pmt->CORE_SETPOINT              = pm_element(64);
    pmt->CORE_BUSY                  = pm_element(65);
    pmt->GFX_SETPOINT               = pm_element(66);
    pmt->GFX_BUSY                   = pm_element(67);
    pmt->FCLK_CCLK_SETPOINT         = pm_element(68);
    pmt->FCLK_CCLK_FREQ             = pm_element(69);
    pmt->FCLK_GFX_SETPOINT          = pm_element(70);
    pmt->FCLK_GFX_BUSY              = pm_element(71);
    pmt->FCLK_IOHC_SETPOINT         = pm_element(72);
    pmt->FCLK_IOHC_BUSY             = pm_element(73);
    pmt->FCLK_DRAM_SETPOINT         = pm_element(74);
    pmt->FCLK_DRAM_BUSY             = pm_element(75);
    pmt->LCLK_SETPOINT[0]           = pm_element(76);
    pmt->LCLK_BUSY[0]               = pm_element(77);

    assign_pm_elements_4(pmt->FCLK_RESIDENCY,     78,  79,  80,  81);
    assign_pm_elements_4(pmt->FCLK_FREQ_TABLE,    82,  83,  84,  85);
    assign_pm_elements_4(pmt->UCLK_FREQ_TABLE,    86,  87,  88,  89);
    assign_pm_elements_4(pmt->MEMCLK_FREQ_TABLE,  90,  91,  92,  93);
    assign_pm_elements_4(pmt->FCLK_VOLTAGE,       94,  95,  96,  97);

    pmt->CPU_SET_VOLTAGE            = pm_element(98);
    pmt->CPU_TELEMETRY_VOLTAGE      = pm_element(99);
    pmt->CPU_TELEMETRY_CURRENT      = pm_element(100);
    pmt->CPU_TELEMETRY_POWER        = pm_element(101);
    pmt->SOC_SET_VOLTAGE            = pm_element(102);
    pmt->SOC_TELEMETRY_VOLTAGE      = pm_element(103);
    pmt->SOC_TELEMETRY_CURRENT      = pm_element(104);
    pmt->SOC_TELEMETRY_POWER        = pm_element(105);

    //Bunch of zeros

    pmt->DF_BUSY                    = pm_element(166);
    pmt->VCN_BUSY                   = pm_element(167);
    pmt->IOHC_BUSY	                = pm_element(168);
    pmt->MMHUB_BUSY                 = pm_element(169);
    pmt->ATHUB_BUSY                 = pm_element(170);
    pmt->OSSSYS_BUSY                = pm_element(171);
    pmt->HDP_BUSY                   = pm_element(172);
    pmt->SDMA_BUSY                  = pm_element(173);
    pmt->SHUB_BUSY                  = pm_element(174);
    pmt->BIF_BUSY                   = pm_element(175);
    pmt->ACP_BUSY                   = pm_element(176);
    pmt->SST0_BUSY                  = pm_element(177);
    pmt->SST1_BUSY                  = pm_element(178);
    pmt->USB0_BUSY                  = pm_element(179);
    pmt->USB1_BUSY                  = pm_element(180);
    pmt->CCM_READS                  = pm_element(181);
    pmt->CCM_WRITES                 = pm_element(182);
    pmt->GCM_64B_READS              = pm_element(183);
    pmt->GCM_64B_WRITES             = pm_element(184);
    pmt->GCM_32B_READS_WRITES       = pm_element(185);
    pmt->MMHUB_READS                = pm_element(186);
    pmt->MMHUB_WRITES               = pm_element(187);
    pmt->DCE_READS                  = pm_element(188);
    pmt->IO_READS_WRITES            = pm_element(189);
    pmt->CS_UMC_READS               = pm_element(190);
    pmt->CS_UMC_WRITES              = pm_element(191);
    pmt->MAX_DRAM_BANDWIDTH         = pm_element(192);
    pmt->VCN_BUSY                   = pm_element(193);
    pmt->VCN_DECODE                 = pm_element(194);
    pmt->VCN_ENCODE_GEN             = pm_element(195);
    pmt->VCN_ENCODE_LOW             = pm_element(196);
    pmt->VCN_ENCODE_REAL            = pm_element(197);
    pmt->VCN_PG                     = pm_element(198);
    pmt->VCN_JPEG                   = pm_element(199);

    assign_pm_elements_8_consec(pmt->CORE_POWER         , 200);
    assign_pm_elements_8_consec(pmt->CORE_VOLTAGE       , 208);
    assign_pm_elements_8_consec(pmt->CORE_TEMP          , 216);
    assign_pm_elements_8_consec(pmt->CORE_FIT           , 224);
    assign_pm_elements_8_consec(pmt->CORE_IDDMAX        , 232);
    assign_pm_elements_8_consec(pmt->CORE_FREQ          , 240);
    assign_pm_elements_8_consec(pmt->CORE_FREQEFF       , 248);
    assign_pm_elements_8_consec(pmt->CORE_C0            , 256);
    assign_pm_elements_8_consec(pmt->CORE_CC1           , 264);
    assign_pm_elements_8_consec(pmt->CORE_CC6           , 272);
    assign_pm_elements_8_consec(pmt->CORE_CKS_FDD       , 280);
    assign_pm_elements_8_consec(pmt->CORE_CI_FDD        , 288);
    assign_pm_elements_8_consec(pmt->CORE_IRM           , 296);
    assign_pm_elements_8_consec(pmt->CORE_PSTATE        , 304);
    assign_pm_elements_8_consec(pmt->CORE_CPPC_MAX      , 312);
    assign_pm_elements_8_consec(pmt->CORE_CPPC_MIN      , 320);
    assign_pm_elements_8_consec(pmt->CORE_CPPC_EPP      , 328);
    assign_pm_elements_8_consec(pmt->CORE_SC_LIMIT      , 336);
    assign_pm_elements_8_consec(pmt->CORE_SC_CAC        , 344);
    assign_pm_elements_8_consec(pmt->CORE_SC_RESIDENCY  , 352);
    assign_pm_elements_8_consec(pmt->CORE_UOPS_CLK      , 360);
    assign_pm_elements_8_consec(pmt->CORE_UOPS          , 368);
    assign_pm_elements_8_consec(pmt->CORE_MEM_LATECY    , 376);

    pmt->L3_LOGIC_POWER[0]          = pm_element(384);
    pmt->L3_VDDM_POWER[0]           = pm_element(385);
    pmt->L3_TEMP[0]                 = pm_element(386);
    pmt->L3_FIT[0]                  = pm_element(387);
    pmt->L3_IDDMAX[0]               = pm_element(388);
    pmt->L3_FREQ[0]                 = pm_element(389);
    pmt->L3_FREQ_EFF[0]             = pm_element(390);
    pmt->L3_CKS_FDD[0]              = pm_element(391);
    pmt->L3_CCA_THRESHOLD[0]        = pm_element(392);
    pmt->L3_CCA_CAC[0]              = pm_element(393);
    pmt->L3_CCA_ACTIVATION[0]       = pm_element(394);
    pmt->L3_EDC_LIMIT[0]            = pm_element(395);
    pmt->L3_EDC_CAC[0]              = pm_element(396);
    pmt->L3_EDC_RESIDENCY[0]        = pm_element(397);
    pmt->L3_FLL_BTC[0]              = pm_element(398);

    pmt->GFX_VOLTAGE                = pm_element(399);
    pmt->GFX_TEMP                   = pm_element(400);
    pmt->GFX_IDDMAX                 = pm_element(401);
    pmt->GFX_FREQ                   = pm_element(402);
    pmt->GFX_FREQEFF                = pm_element(403);
    pmt->GFX_BUSY                   = pm_element(404);
    pmt->GFX_CGPG                   = pm_element(405);
    pmt->GFX_EDC_LIM                = pm_element(406);
    pmt->GFX_EDC_RESIDENCY          = pm_element(407);
    pmt->GFX_DEM_RESIDENCY          = pm_element(408);

    pmt->FCLK_FREQ                  = pm_element(409);
    pmt->UCLK_FREQ                  = pm_element(410);
    pmt->MEMCLK_FREQ                = pm_element(411);
    pmt->VCLK_FREQ                  = pm_element(412);
    pmt->DCLK_FREQ                  = pm_element(413);
    pmt->SOCCLK                     = pm_element(414);
    pmt->LCLK_FREQ[0]               = pm_element(415);
    pmt->SHUBCLK                    = pm_element(416);
    pmt->MP0CLK                     = pm_element(417);
    pmt->DCF_FREQ                   = pm_element(418);
    pmt->FCLK_FREQ_EFF              = pm_element(419);
    pmt->UCLK_FREQ_EFF              = pm_element(420);
    pmt->MEMCLK_FREQ_EFF            = pm_element(421);
    pmt->VCLK_FREQ_EFF              = pm_element(422);
    pmt->DCLK_FREQ_EFF              = pm_element(423);
    pmt->SOCCLK_FREQ_EFF[0]         = pm_element(424);
    pmt->LCLK_FREQ_EFF[0]           = pm_element(425);
    pmt->SHUBCLK_FREQ_EFF[0]        = pm_element(426);
    pmt->MP0CLK_EFF                 = pm_element(427);
    pmt->DCF_FREQ_EFF               = pm_element(428);

    assign_pm_elements_8_consec(pmt->VCLK_STATE            , 429);
    assign_pm_elements_8_consec(pmt->DCLK_STATE            , 437);
    assign_pm_elements_8_consec(pmt->SOCCLK_STATE          , 445);
    assign_pm_elements_8_consec(pmt->LCLK_STATE            , 453);
    assign_pm_elements_8_consec(pmt->SHUB_STATE            , 461);
    assign_pm_elements_8_consec(pmt->MP0_STATE             , 469);
    assign_pm_elements_8_consec(pmt->DCFCLK_STATE          , 477);
    assign_pm_elements_8_consec(pmt->VCN_STATE_RESIDENCY   , 485);
    assign_pm_elements_8_consec(pmt->SOCCLK_STATE_RESIDENCY, 493);
    assign_pm_elements_8_consec(pmt->LCLK_STATE_RESIDENCY  , 501);
    assign_pm_elements_8_consec(pmt->SHUB_STATE_RESIDENCY  , 509);
    assign_pm_elements_8_consec(pmt->MP0CLK_STATE_RESIDENCY, 517);
    assign_pm_elements_8_consec(pmt->DCFCLK_STATE_RESIDENCY, 525);
    assign_pm_elements_8_consec(pmt->VDDCR_SOC_VOLTAGE     , 533);

    pmt->CPUOFF                     = pm_element(541);
    pmt->CPUOFF_CNT                 = pm_element(542);
    pmt->GFXOFF                     = pm_element(543);
    pmt->GFXOFF_CNT                 = pm_element(544);
    pmt->VDDOFF                     = pm_element(545);
    pmt->VDDOFF_CNT                 = pm_element(546);
    pmt->ULV                        = pm_element(547);
    pmt->ULV_CNT                    = pm_element(548);
    pmt->S0i2                       = pm_element(549);
    pmt->S0i2_CNT                   = pm_element(550);
    pmt->WHISPER                    = pm_element(551);
    pmt->WHISPER_CNT                = pm_element(552);
    pmt->SELFREFRESH0               = pm_element(553);
    pmt->SELFREFRESH1               = pm_element(554);
    pmt->PLL_POWERDOWN_0            = pm_element(555);
    pmt->PLL_POWERDOWN_1            = pm_element(556);
    pmt->PLL_POWERDOWN_2            = pm_element(557);
    pmt->PLL_POWERDOWN_3            = pm_element(558);
    pmt->PLL_POWERDOWN_4            = pm_element(559);
    //pmt->POWER_SOURCE               = pm_element(560);
    pmt->DGPU_POWER                 = pm_element(561);
    pmt->DGPU_GFX_BUSY              = pm_element(562);
    pmt->DGPU_FREQ_TARGET           = pm_element(563);
    pmt->V_VDDM                     = pm_element(564); //CLDO_VDDM
    pmt->V_VDDP                     = pm_element(565); //CLDO_VDDP
    pmt->DDR_PHY_POWER              = pm_element(566);
    pmt->IOD_VDDIO_MEM_POWER        = pm_element(567);
    pmt->IO_VDD18_POWER             = pm_element(568);
    pmt->IO_DISPLAY_POWER           = pm_element(569);
    pmt->IO_USB_POWER               = pm_element(570);
    pmt->ULV_VOLTAGE                = pm_element(571);
    pmt->PEAK_TEMP                  = pm_element(572);
    pmt->PEAK_VOLTAGE               = pm_element(573);
    pmt->AVG_CORE_COUNT             = pm_element(574);
    pmt->MAX_CORE_VOLTAGE           = pm_element(575);
    pmt->DC_BTC                     = pm_element(576);
    pmt->CSTATE_BOOST               = pm_element(577);
    pmt->PROCHOT                    = pm_element(578);
    pmt->PWM                        = pm_element(579);
    pmt->FPS                        = pm_element(580);
    pmt->DISPLAY_COUNT              = pm_element(581);
    pmt->StapmTimeConstant          = pm_element(582);
    pmt->SlowPPTTimeConstant        = pm_element(583);
    pmt->MP1CLK                     = pm_element(584);
    pmt->MP2CLK                     = pm_element(585);
    pmt->SMNCLK                     = pm_element(586);
    pmt->ACLK                       = pm_element(587);
    pmt->DISPCLK                    = pm_element(588);
    pmt->DPREFCLK                   = pm_element(589);
    pmt->DPPCLK                     = pm_element(590);
    pmt->SMU_BUSY                   = pm_element(591);
    pmt->SMU_SKIP_COUNTER           = pm_element(592);

    pmt->min_size = 593*4; //(Highest element we access + 1)*4.
    //Needed to avoid illegal memory access
}
