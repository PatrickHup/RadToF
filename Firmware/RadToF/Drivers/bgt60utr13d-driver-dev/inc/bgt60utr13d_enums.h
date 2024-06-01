/*!
 * \file bgt60utr13d_enums.h
 * \brief BGT60UTR13D Register Enums.
 * \note Do not edit: Generated using Reginald.
 */


#ifndef BGT60UTR13D_ENUMS_H_
#define BGT60UTR13D_ENUMS_H_

// ==== Shared Enums ===========================================================


// ==== SADC_CTRL Enums ========================================================

/**
 * @brief Analog multiplexer input for channel selection to the SADC
 * Analog multiplexer input for channel selection to the SADC:
 * 0D: Temperature sensor
 * 1D: Reserved
 * 2D: Temperature sensor reference
 * 3D: pd_outx
 * 4D: pd_out
 * 5D: Reserved
 * 6D: Reserved
 * 7D: ifx_mix3
 * 8D: if_mix3
 * 9D: ifx_mix2
 * 10D: if_mix2
 * 11D: ifx_mix1
 * 12D: if_mix1
 * 13D-15D: Reserved
 */
enum bgt60utr13d_sadc_ctrl_sadc_chsel{
  BGT60UTR13D_SADC_CTRL_SADC_CHSEL_TEMP_SENS = 0x0U,
  BGT60UTR13D_SADC_CTRL_SADC_CHSEL_TEMP_SENS_REF = 0x2U,
  BGT60UTR13D_SADC_CTRL_SADC_CHSEL_PD_OUTX = 0x3U,
  BGT60UTR13D_SADC_CTRL_SADC_CHSEL_PD_OUT = 0x4U,
  BGT60UTR13D_SADC_CTRL_SADC_CHSEL_IFX_MIX3 = 0x7U,
  BGT60UTR13D_SADC_CTRL_SADC_CHSEL_IF_MIX3 = 0x8U,
  BGT60UTR13D_SADC_CTRL_SADC_CHSEL_IFX_MIX2 = 0x9U,
  BGT60UTR13D_SADC_CTRL_SADC_CHSEL_IF_MIX2 = 0xAU,
  BGT60UTR13D_SADC_CTRL_SADC_CHSEL_IFX_MIX1 = 0xBU,
  BGT60UTR13D_SADC_CTRL_SADC_CHSEL_IF_MIX = 0xCU,
};

/**
 * @brief SADC clock divider provides the system clock for the sensor ADC
 * SADC clock divider provides the system clock for the sensor ADC. SADC clock frequency divider value. fSADC_CLK = fSYS_CLK / SADC_CLK_DIV:
 * 0D: Divider value is 1
 * 1D: Divider value is 2
 * 2D: Divider value is 3
 * 3D: Divider value is 4
 */
enum bgt60utr13d_sadc_ctrl_sadc_clk_div{
  BGT60UTR13D_SADC_CTRL_SADC_CLK_DIV_1 = 0x0U,
  BGT60UTR13D_SADC_CTRL_SADC_CLK_DIV_2 = 0x1U,
  BGT60UTR13D_SADC_CTRL_SADC_CLK_DIV_3 = 0x2U,
  BGT60UTR13D_SADC_CTRL_SADC_CLK_DIV_4 = 0x3U,
};


// ==== CCR1 Enums =============================================================

/**
 * @brief Power down mode
 * Power down mode. After the last repetition RT, the chip enters the defined power mode (during T_FED):
 * 0D: Keep the same power mode (CSx + CSCx)
 * 1D: Change to IDLE power mode (CSI + CSCI)
 * 2D: Change to DS power mode (CSDS + CSCDS)
 * 3D: Reserved
 */
enum bgt60utr13d_ccr1_pd_mode{
  BGT60UTR13D_CCR1_PD_MODE_T_FED_PM_STAY_SAME = 0x0U,
  BGT60UTR13D_CCR1_PD_MODE_T_FED_PM_IDLE = 0x1U,
  BGT60UTR13D_CCR1_PD_MODE_T_FED_PM_DEEP_SLEEP = 0x2U,
};


// ==== CLK_IN Enums ===========================================================

/**
 * Selection of input clock frequency and clock path:
 * 0 - Direct use of external OSC_CLK
 * 1 - Frequency doubler without DC_IN
 * 2 - Frequency doubler with DC_IN
 * 3 - Frequency doubler with DC calibration for system clock and without DC calibration for PLL clock
 * Note: It is important to program FD register first and enable the system clock afterwards by programming PACR2(23) register.
 */
enum bgt60utr13d_clk_in_clk_sel{
  BGT60UTR13D_CLK_IN_CLK_SEL_FREQUENCY_DOUBLER_DISABLED = 0x0U,
  BGT60UTR13D_CLK_IN_CLK_SEL_FREQUENCY_DOUBLER_ENABLED = 0x1U,
  BGT60UTR13D_CLK_IN_CLK_SEL_FREQUENCY_DOUBLER_ENABLED_DC_IN = 0x2U,
  BGT60UTR13D_CLK_IN_CLK_SEL_FREQUENCY_DOUBLER_ENABLED_SYS_CLK_CAL_ONLY = 0x3U,
};

/**
 * Select frequency doubler output at the IRQ pin:
 * 0 - Normal irq functionality at IRQ pin
 * 1 - Frequency doubler output at IRQ pin
 * Note: Frequency doubler has higher priority as interrupt.
 */
enum bgt60utr13d_clk_in_irq_fd_sel{
  BGT60UTR13D_CLK_IN_IRQ_FD_SEL_NORMAL_FIFO_IRQ = 0x0U,
  BGT60UTR13D_CLK_IN_IRQ_FD_SEL_FREQUENCY_DOUBLER_OUTPUT = 0x1U,
};


// ==== CS#_0 Enums ============================================================

/**
 * @brief Selection of analog base band anti-aliasing filter frequency on channel 1
 * Selection of analog base band anti-aliasing filter frequency on channel 1:
 * 0B: 600 kHz
 * 1B: 1 MHz
 */
enum bgt60utr13d_cs__0_abb1_aaf_ctrl{
  BGT60UTR13D_CS__0_ABB1_AAF_CTRL_600KHZ = 0x0U,
  BGT60UTR13D_CS__0_ABB1_AAF_CTRL_1MHZ = 0x1U,
};


// ==== CS#_1 Enums ============================================================

/**
 * @brief Gain setting of the first stage of the high pass filter of channel 1
 * Gain setting of the first stage of the high pass filter of channel 1:
 * 0B: 30 dB
 * 1B: 18 dB
 */
enum bgt60utr13d_cs__1_hp1_gain{
  BGT60UTR13D_CS__1_HP1_GAIN_30DB = 0x0U,
  BGT60UTR13D_CS__1_HP1_GAIN_18DB = 0x1U,
};


// ==== CS#_2 Enums ============================================================

/**
 * @brief High pass filter cutoff frequency setting of channel 1
 * High pass filter cutoff frequency setting of channel 1:
 * 0D: 20 kHz
 * 1D: 40 kHz
 * 2D: 80 kHz
 * 3D: 140 kHz
 * 4D: 160 kHz
 * 5D: Reserved
 * 6D: Reserved
 * 7D: Reserved
 */
enum bgt60utr13d_cs__2_hpf_sel1{
  BGT60UTR13D_CS__2_HPF_SEL1_20KHZ = 0x0U,
  BGT60UTR13D_CS__2_HPF_SEL1_40KHZ = 0x1U,
  BGT60UTR13D_CS__2_HPF_SEL1_80KHZ = 0x2U,
  BGT60UTR13D_CS__2_HPF_SEL1_140KHZ = 0x3U,
  BGT60UTR13D_CS__2_HPF_SEL1_160KHZ = 0x4U,
};

/**
 * @brief VGA gain setting of channel 1
 * VGA gain setting of channel 1:
 * 0D: 0 dB
 * 1D: 5 dB
 * 2D: 10 dB
 * 3D: 15 dB
 * 4D: 20 dB
 * 5D: 25 dB
 * 6D: 30 dB
 * 7D: Reserved
 */
enum bgt60utr13d_cs__2_vga_gain1{
  BGT60UTR13D_CS__2_VGA_GAIN1_0DB = 0x0U,
  BGT60UTR13D_CS__2_VGA_GAIN1_5DB = 0x1U,
  BGT60UTR13D_CS__2_VGA_GAIN1_10DB = 0x2U,
  BGT60UTR13D_CS__2_VGA_GAIN1_15DB = 0x3U,
  BGT60UTR13D_CS__2_VGA_GAIN1_20DB = 0x4U,
  BGT60UTR13D_CS__2_VGA_GAIN1_25DB = 0x5U,
  BGT60UTR13D_CS__2_VGA_GAIN1_30DB = 0x6U,
};


// ==== PLL#_7 Enums ===========================================================

/**
 * @brief Power down mode. After the last repetition RS, the chip enters the defined power mode (during T_SED)
 * PD_MODE 10:9 rw Power down mode. After the last repetition RS the chip enters the defined power mode (during T_SED): 0D ... Keep the same power mode (CSx + CSCx) 1D ... Change to IDLE power mode (CSI + CSCI) 2D ... Change to DS power mode (CSDS + CSCDS) 3D ... Reserved
 */
enum bgt60utr13d_pll__7_pd_mode{
  BGT60UTR13D_PLL__7_PD_MODE_T_SED_PM_STAY_SAME = 0x0U,
  BGT60UTR13D_PLL__7_PD_MODE_T_SED_PM_IDLE = 0x1U,
  BGT60UTR13D_PLL__7_PD_MODE_T_SED_PM_DEEP_SLEEP = 0x2U,
};

#endif /* BGT60UTR13D_ENUMS_H_ */
