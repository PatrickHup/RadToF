/*!
 * \file bgt60utr13d_regs.h
 * \brief BGT60UTR13D Registers.
 * \note Do not edit: Generated using Reginald.
 */


#ifndef BGT60UTR13D_REGS_H_
#define BGT60UTR13D_REGS_H_

#include <stdint.h>
#include "bgt60utr13d_enums.h"

// ==== Register Addresses =====================================================
#define BGT60UTR13D_REG_MAIN (0x0U) //!< MAIN Address (Main register)
#define BGT60UTR13D_REG_ADC0 (0x1U) //!< ADC0 Address (Multi ADC control register)
#define BGT60UTR13D_REG_CHIP_VERSION (0x2U) //!< CHIP_VERSION Address (Digital and RF version register)
#define BGT60UTR13D_REG_STAT1 (0x3U) //!< STAT1 Address (Status register 1)
#define BGT60UTR13D_REG_PACR1 (0x4U) //!< PACR1 Address (PLL analog control register 1)
#define BGT60UTR13D_REG_PACR2 (0x5U) //!< PACR2 Address (PLL analog control register 2)
#define BGT60UTR13D_REG_SFCTL (0x6U) //!< SFCTL Address (SPI and FIFO control register)
#define BGT60UTR13D_REG_SADC_CTRL (0x7U) //!< SADC_CTRL Address (Sensor ADC control register)
#define BGT60UTR13D_REG_CSI_0 (0x8U) //!< CSI_0 Address (Channel set idle register 0)
#define BGT60UTR13D_REG_CSI_1 (0x9U) //!< CSI_1 Address (Channel set idle register 1)
#define BGT60UTR13D_REG_CSI_2 (0xAU) //!< CSI_2 Address (Channel set idle register 2)
#define BGT60UTR13D_REG_CSDS_0 (0xCU) //!< CSDS_0 Address (Channel set idle register 0)
#define BGT60UTR13D_REG_CSDS_1 (0xDU) //!< CSDS_1 Address (Channel set idle register 1)
#define BGT60UTR13D_REG_CSDS_2 (0xEU) //!< CSDS_2 Address (Channel set idle register 2)
#define BGT60UTR13D_REG_CSU1_0 (0x10U) //!< CSU1_0 Address (Channel set idle register 0)
#define BGT60UTR13D_REG_CSU1_1 (0x11U) //!< CSU1_1 Address (Channel set idle register 1)
#define BGT60UTR13D_REG_CSU1_2 (0x12U) //!< CSU1_2 Address (Channel set idle register 2)
#define BGT60UTR13D_REG_CSD1_0 (0x13U) //!< CSD1_0 Address (Channel set idle register 0)
#define BGT60UTR13D_REG_CSD1_1 (0x14U) //!< CSD1_1 Address (Channel set idle register 1)
#define BGT60UTR13D_REG_CSD1_2 (0x15U) //!< CSD1_2 Address (Channel set idle register 2)
#define BGT60UTR13D_REG_CSU2_0 (0x17U) //!< CSU2_0 Address (Channel set idle register 0)
#define BGT60UTR13D_REG_CSU2_1 (0x18U) //!< CSU2_1 Address (Channel set idle register 1)
#define BGT60UTR13D_REG_CSU2_2 (0x19U) //!< CSU2_2 Address (Channel set idle register 2)
#define BGT60UTR13D_REG_CSD2_0 (0x1AU) //!< CSD2_0 Address (Channel set idle register 0)
#define BGT60UTR13D_REG_CSD2_1 (0x1BU) //!< CSD2_1 Address (Channel set idle register 1)
#define BGT60UTR13D_REG_CSD2_2 (0x1CU) //!< CSD2_2 Address (Channel set idle register 2)
#define BGT60UTR13D_REG_CSU3_0 (0x1EU) //!< CSU3_0 Address (Channel set idle register 0)
#define BGT60UTR13D_REG_CSU3_1 (0x1FU) //!< CSU3_1 Address (Channel set idle register 1)
#define BGT60UTR13D_REG_CSU3_2 (0x20U) //!< CSU3_2 Address (Channel set idle register 2)
#define BGT60UTR13D_REG_CSD3_0 (0x21U) //!< CSD3_0 Address (Channel set idle register 0)
#define BGT60UTR13D_REG_CSD3_1 (0x22U) //!< CSD3_1 Address (Channel set idle register 1)
#define BGT60UTR13D_REG_CSD3_2 (0x23U) //!< CSD3_2 Address (Channel set idle register 2)
#define BGT60UTR13D_REG_CSU4_0 (0x25U) //!< CSU4_0 Address (Channel set idle register 0)
#define BGT60UTR13D_REG_CSU4_1 (0x26U) //!< CSU4_1 Address (Channel set idle register 1)
#define BGT60UTR13D_REG_CSU4_2 (0x27U) //!< CSU4_2 Address (Channel set idle register 2)
#define BGT60UTR13D_REG_CSD4_0 (0x28U) //!< CSD4_0 Address (Channel set idle register 0)
#define BGT60UTR13D_REG_CSD4_1 (0x29U) //!< CSD4_1 Address (Channel set idle register 1)
#define BGT60UTR13D_REG_CSD4_2 (0x2AU) //!< CSD4_2 Address (Channel set idle register 2)
#define BGT60UTR13D_REG_CSCI (0xBU) //!< CSCI Address (Channel set control idle register)
#define BGT60UTR13D_REG_CSCDS (0xFU) //!< CSCDS Address (Channel set control idle register)
#define BGT60UTR13D_REG_CSC1 (0x16U) //!< CSC1 Address (Channel set control idle register)
#define BGT60UTR13D_REG_CSC2 (0x1DU) //!< CSC2 Address (Channel set control idle register)
#define BGT60UTR13D_REG_CSC3 (0x24U) //!< CSC3 Address (Channel set control idle register)
#define BGT60UTR13D_REG_CSC4 (0x2BU) //!< CSC4 Address (Channel set control idle register)
#define BGT60UTR13D_REG_CCR0 (0x2CU) //!< CCR0 Address (Chirp control register 0)
#define BGT60UTR13D_REG_CCR1 (0x2DU) //!< CCR1 Address (Chirp control register 1)
#define BGT60UTR13D_REG_CCR2 (0x2EU) //!< CCR2 Address (Chirp control register 2)
#define BGT60UTR13D_REG_CCR3 (0x2FU) //!< CCR3 Address (Chirp control register 3)
#define BGT60UTR13D_REG_PLL1_0 (0x30U) //!< PLL1_0 Address (PLL shape x register 0)
#define BGT60UTR13D_REG_PLL1_1 (0x31U) //!< PLL1_1 Address (PLL shape x register 1)
#define BGT60UTR13D_REG_PLL1_2 (0x32U) //!< PLL1_2 Address (PLL shape x register 2)
#define BGT60UTR13D_REG_PLL1_3 (0x33U) //!< PLL1_3 Address (PLL shape x register 3)
#define BGT60UTR13D_REG_PLL1_4 (0x34U) //!< PLL1_4 Address (PLL shape x register 4)
#define BGT60UTR13D_REG_PLL1_5 (0x35U) //!< PLL1_5 Address (PLL shape x register 5)
#define BGT60UTR13D_REG_PLL1_6 (0x36U) //!< PLL1_6 Address (PLL shape x register 6)
#define BGT60UTR13D_REG_PLL1_7 (0x37U) //!< PLL1_7 Address (PLL shape x register 7)
#define BGT60UTR13D_REG_PLL2_0 (0x38U) //!< PLL2_0 Address (PLL shape x register 0)
#define BGT60UTR13D_REG_PLL2_1 (0x39U) //!< PLL2_1 Address (PLL shape x register 1)
#define BGT60UTR13D_REG_PLL2_2 (0x3AU) //!< PLL2_2 Address (PLL shape x register 2)
#define BGT60UTR13D_REG_PLL2_3 (0x3BU) //!< PLL2_3 Address (PLL shape x register 3)
#define BGT60UTR13D_REG_PLL2_4 (0x3CU) //!< PLL2_4 Address (PLL shape x register 4)
#define BGT60UTR13D_REG_PLL2_5 (0x3DU) //!< PLL2_5 Address (PLL shape x register 5)
#define BGT60UTR13D_REG_PLL2_6 (0x3EU) //!< PLL2_6 Address (PLL shape x register 6)
#define BGT60UTR13D_REG_PLL2_7 (0x3FU) //!< PLL2_7 Address (PLL shape x register 7)
#define BGT60UTR13D_REG_PLL3_0 (0x40U) //!< PLL3_0 Address (PLL shape x register 0)
#define BGT60UTR13D_REG_PLL3_1 (0x41U) //!< PLL3_1 Address (PLL shape x register 1)
#define BGT60UTR13D_REG_PLL3_2 (0x42U) //!< PLL3_2 Address (PLL shape x register 2)
#define BGT60UTR13D_REG_PLL3_3 (0x43U) //!< PLL3_3 Address (PLL shape x register 3)
#define BGT60UTR13D_REG_PLL3_4 (0x44U) //!< PLL3_4 Address (PLL shape x register 4)
#define BGT60UTR13D_REG_PLL3_5 (0x45U) //!< PLL3_5 Address (PLL shape x register 5)
#define BGT60UTR13D_REG_PLL3_6 (0x46U) //!< PLL3_6 Address (PLL shape x register 6)
#define BGT60UTR13D_REG_PLL3_7 (0x47U) //!< PLL3_7 Address (PLL shape x register 7)
#define BGT60UTR13D_REG_PLL4_0 (0x48U) //!< PLL4_0 Address (PLL shape x register 0)
#define BGT60UTR13D_REG_PLL4_1 (0x49U) //!< PLL4_1 Address (PLL shape x register 1)
#define BGT60UTR13D_REG_PLL4_2 (0x4AU) //!< PLL4_2 Address (PLL shape x register 2)
#define BGT60UTR13D_REG_PLL4_3 (0x4BU) //!< PLL4_3 Address (PLL shape x register 3)
#define BGT60UTR13D_REG_PLL4_4 (0x4CU) //!< PLL4_4 Address (PLL shape x register 4)
#define BGT60UTR13D_REG_PLL4_5 (0x4DU) //!< PLL4_5 Address (PLL shape x register 5)
#define BGT60UTR13D_REG_PLL4_6 (0x4EU) //!< PLL4_6 Address (PLL shape x register 6)
#define BGT60UTR13D_REG_PLL4_7 (0x4FU) //!< PLL4_7 Address (PLL shape x register 7)
#define BGT60UTR13D_REG_RFT0 (0x55U) //!< RFT0 Address (RF test register 0)
#define BGT60UTR13D_REG_EFUSE0 (0x57U) //!< EFUSE0 Address (EFUSE register 0)
#define BGT60UTR13D_REG_EFUSE1 (0x58U) //!< EFUSE1 Address (EFUSE register 1)
#define BGT60UTR13D_REG_PDFT0 (0x59U) //!< PDFT0 Address (PLL test register 0)
#define BGT60UTR13D_REG_STAT0 (0x5DU) //!< STAT0 Address (Status register 0)
#define BGT60UTR13D_REG_SADC_RESULT (0x5EU) //!< SADC_RESULT Address (Sensor ADC result register)
#define BGT60UTR13D_REG_FSTAT (0x5FU) //!< FSTAT Address (FIFO status register)
#define BGT60UTR13D_REG_CHIP_ID0 (0x60U) //!< CHIP_ID0 Address (Chip ID register 0)
#define BGT60UTR13D_REG_CHIP_ID1 (0x61U) //!< CHIP_ID1 Address (Chip ID register 1)
#define BGT60UTR13D_REG_CLK_IN (0x62U) //!< CLK_IN Address (Clock input register)

// ==== CS# Register Block =====================================================
#define BGT60UTR13D_CS__0__OFFSET (0U)
#define BGT60UTR13D_CS__1__OFFSET (1U)
#define BGT60UTR13D_CS__2__OFFSET (2U)

#define BGT60UTR13D_CS__CSI__START (0x8U)
#define BGT60UTR13D_CS__CSDS__START (0xCU)
#define BGT60UTR13D_CS__CSU1__START (0x10U)
#define BGT60UTR13D_CS__CSD1__START (0x13U)
#define BGT60UTR13D_CS__CSU2__START (0x17U)
#define BGT60UTR13D_CS__CSD2__START (0x1AU)
#define BGT60UTR13D_CS__CSU3__START (0x1EU)
#define BGT60UTR13D_CS__CSD3__START (0x21U)
#define BGT60UTR13D_CS__CSU4__START (0x25U)
#define BGT60UTR13D_CS__CSD4__START (0x28U)
// ==== CSC# Register Block ====================================================
#define BGT60UTR13D_CSC___OFFSET (0U)

#define BGT60UTR13D_CSC__CSCI__START (0xBU)
#define BGT60UTR13D_CSC__CSCDS__START (0xFU)
#define BGT60UTR13D_CSC__CSC1__START (0x16U)
#define BGT60UTR13D_CSC__CSC2__START (0x1DU)
#define BGT60UTR13D_CSC__CSC3__START (0x24U)
#define BGT60UTR13D_CSC__CSC4__START (0x2BU)
// ==== PLL# Register Block ====================================================
#define BGT60UTR13D_PLL__0__OFFSET (0U)
#define BGT60UTR13D_PLL__1__OFFSET (1U)
#define BGT60UTR13D_PLL__2__OFFSET (2U)
#define BGT60UTR13D_PLL__3__OFFSET (3U)
#define BGT60UTR13D_PLL__4__OFFSET (4U)
#define BGT60UTR13D_PLL__5__OFFSET (5U)
#define BGT60UTR13D_PLL__6__OFFSET (6U)
#define BGT60UTR13D_PLL__7__OFFSET (7U)

#define BGT60UTR13D_PLL__PLL1__START (0x30U)
#define BGT60UTR13D_PLL__PLL2__START (0x38U)
#define BGT60UTR13D_PLL__PLL3__START (0x40U)
#define BGT60UTR13D_PLL__PLL4__START (0x48U)

// ==== MAIN ===================================================================

#define BGT60UTR13D_REG_MAIN__RESETVAL (0x1C0000U) //!< MAIN Reset Value

/**
 * @brief MAIN Register Struct
 * Address: 0x0.
 * Use \ref BGT60UTR13D_MAIN_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Main register
 */
struct bgt60utr13d_reg_main {
  /** @brief Executes a frame start and clears the bit */
  uint8_t frame_start : 1;
  /** @brief Resets the device and clears the bit */
  uint8_t sw_reset : 1;
  /** @brief Resets the FSM and clears the bit */
  uint8_t fsm_reset : 1;
  /** @brief Resets the FIFO and clears the bit */
  uint8_t fifo_rst : 1;
  /**
   * @brief Timer for T_WU
   * Timer for T_WU:
   * 0 ... TSYS_CLK
   * 1..255 ... T_WU = (TR_WKUP * 2TR_WKUP_MUL * 8 + TR_WKUP_MUL + 3) * TSYS_CLK
   * Note: T_WUTYP = 1 ms
   */
  uint8_t tr_twkup : 8;
  /**
   * @brief Timer multiplication factor for T_WU
   * Timer multiplier factor for T_WU:
   * 0..15 ... 2^TR_WKUP_MUL
   */
  uint8_t tr_twkup_mul : 4;
  /** @brief Continuous wave mode */
  uint8_t cw_mode : 1;
  /**
   * @brief SADC bandgap clock frequency divider
   * SADC bandgap clock frequency divider:
   * 0: off
   * 1: Divider is 1
   * 2: Divider is 2
   * 3: Divider is 4
   */
  uint8_t sadc_bg_clk_div : 2;
  /**
   * @brief MADC bandgap clock frequency divider
   * MADC bandgap clock frequency divider:
   * 0: off
   * 1: Divider is 1
   * 2: Divider is 2
   * 3: Divider is 4
   */
  uint8_t madc_bg_clk_div : 2;
  /**
   * @brief LDO dummy load to smoor current peaks
   * Load strength:
   * 0: Disabled
   * 1: 100uA
   * 2: 200uA
   * 3: 400uA
   */
  uint8_t load_strenth : 2;
  /**
   * @brief LDO mode
   * LDO mode:
   * 0: Low power (50uA), slow setting time
   * 1: High power (100uA), fast setting time
   */
  uint8_t ldo_mode : 1;
};

// ==== ADC0 ===================================================================

#define BGT60UTR13D_REG_ADC0__RESETVAL (0xA2240U) //!< ADC0 Reset Value

/**
 * @brief ADC0 Register Struct
 * Address: 0x1.
 * Use \ref BGT60UTR13D_ADC0_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Multi ADC control register
 */
struct bgt60utr13d_reg_adc0 {
  /**
   * @brief ADC oversampling configuration
   * ADC oversampling configuration:
   * 0D: No oversampling (standard 11 bits conversion)
   * 1D: Reserved
   * 2D: Reserved
   * 3D: Reserved
   */
  uint8_t adc_overs_cfg : 2;
  /**
   * @brief Temperature coefficient trimming (static)
   * Temperature coefficient trimming (static):
   * 0D: Minimum value
   * 7D: Maximum value
   */
  uint8_t bg_tc_trim : 3;
  /**
   * @brief Enables chopping within the bandgap
   * Enables chopping within the bandgap:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t bg_chop_en : 1;
  /**
   * @brief Sample time control
   * Sample time control:
   * 0D: 50 ns
   * 1D: 100 ns
   * 2D: 200 ns
   * 3D: 400 ns
   */
  uint8_t stc : 2;
  /**
   * @brief Disables startup calibration
   * Disables startup calibration:
   * 0B: Enabled
   * 1B: Disabled
   */
  uint8_t dscal : 1;
  /**
   * @brief Tracking conversion configuration bits
   * Tracking conversion configuration bits:
   * 0D: No sub conversion
   * 1D: 1 sub conversion
   * 2D: 3 sub conversions
   * 3D: 7 sub conversions
   * Note: Sub conversions are executed and averaged.
   */
  uint8_t track_cfg : 2;
  /**
   * @brief MSB decision time selection during calibration and conversion
   * MSB decision time selection during calibration and conversion:
   * 0B: Single MSB decision time
   * 1B: Double MSB decision time
   */
  uint8_t msb_ctrl : 1;
  /**
   * @brief Trigger for manual ADC conversion
   * Trigger for manual ADC conversion:
   * 0B: No effect
   * 1B: Executes a single ADC conversion and clears this bit
   */
  uint8_t trig_madc : 1;
  /** @brief Reserved */
  uint8_t rsvd : 1;
  /**
   * @brief ADC sampling frequency divider value
   * ADC sampling frequency divider value. The actual sampling frequency will be fADC_SAMP = fADC_CLK / ADC_DIV:
   * 0D..19D: Reserved
   * 20D: Minimum divider value
   * 1023D: Maximum divider value
   * Note: A typical value is 33D resulting in fADC_SAMP = 2.42 MS/s (@fSYS_CLK = 80 MHz)
   */
  uint16_t adc_div : 10;
};

// ==== CHIP_VERSION ===========================================================

#define BGT60UTR13D_REG_CHIP_VERSION__RESETVAL (0x606U) //!< CHIP_VERSION Reset Value

/**
 * @brief CHIP_VERSION Register Struct
 * Address: 0x2.
 * Use \ref BGT60UTR13D_CHIP_VERSION_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Digital and RF version register
 */
struct bgt60utr13d_reg_chip_version {
  /**
   * @brief Revision of analog logic
   * Revision of analog logic:
   * 6D: BGT60TR13D
   */
  uint8_t rf_id : 8;
  /**
   * @brief Revision of digital control logic
   * Revision of digital control logic:
   * 6D: BGT60TR13D
   */
  uint8_t digital_id : 8;
  /** @brief Reserved */
  uint8_t rsvd : 8;
};

// ==== STAT1 ==================================================================

#define BGT60UTR13D_REG_STAT1__RESETVAL (0x0U) //!< STAT1 Reset Value

/**
 * @brief STAT1 Register Struct
 * Address: 0x3.
 * Use \ref BGT60UTR13D_STAT1_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Status register 1
 */
struct bgt60utr13d_reg_stat1 {
  /**
   * @brief Shape group counter
   * Shape group counter:
   * 0D: Reset value / rollover value after maximum value reached
   * 4095D: Maximum value
   */
  uint16_t shape_grp_cnt : 12;
  /**
   * @brief Frame counter
   * Frame counter:
   * 0D: Reset value / rollover value after maximum value reached
   * 4095D: Maximum value
   * Note: This field is for debug only. FRAME_CNT info should not be used when endless mode enabled (please check CCR2:MAX_FRAME_CNT).
   */
  uint16_t frame_cnt : 12;
};

// ==== PACR1 ==================================================================

#define BGT60UTR13D_REG_PACR1__RESETVAL (0x196524U) //!< PACR1 Reset Value

/**
 * @brief PACR1 Register Struct
 * Address: 0x4.
 * Use \ref BGT60UTR13D_PACR1_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * PLL analog control register 1
 */
struct bgt60utr13d_reg_pacr1 {
  /**
   * @brief Enables the power of the analog regulator
   * Enables the power of the analog regulator:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t anapon : 1;
  /**
   * @brief Selects the output voltage of the analog regulator
   * Selects the output voltage of the analog regulator:
   * 0D: 1.44 V
   * 1D: 1.50 V
   * 2D: 1.55 V
   * 3D: 1.60 V (@Vbg = 1.2 V)
   */
  uint8_t vanareg : 2;
  /**
   * @brief Enables the power of the digital regulator
   * Enables the power of the digital regulator:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t digpon : 1;
  /**
   * @brief Selects the output voltage of the digital regulator
   * Selects the output voltage of the digital regulator:
   * 0D: 1.44 V
   * 1D: 1.50 V
   * 2D: 1.55 V
   * 3D: 1.60 V (@Vbg = 1.2 V)
   */
  uint8_t vdigreg : 2;
  /**
   * @brief Enables bandgap reference
   * Enables bandgap reference:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t bgapen : 1;
  /**
   * @brief Enables voltage-to-current converter
   * Enables voltage-to-current converter:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t u2ien : 1;
  /**
   * @brief Selects the reference voltage/common mode level of loop filter
   * Selects the reference voltage/common mode level of loop filter:
   * 0D: 433 mV
   * 1D: 506 mV
   * 2D: 578 mV
   * 3D: 650 mV
   */
  uint8_t vrefsel : 2;
  /**
   * @brief Selects the resistance Rfilt of the reference filter
   * Selects the resistance Rfilt of the reference filter:
   * 0B: Rfilt = 100 kΩ
   * 1B: Rfilt = 1 MΩ
   */
  uint8_t rfiltsel : 1;
  /**
   * @brief Selects the resistance Rlf inside the loop filter
   * Selects the resistance Rlf inside the loop filter:
   * 0B: Rlf = 5 kΩ
   * 1B: Rlf = 7 kΩ
   */
  uint8_t rlfsel : 1;
  /**
   * @brief Selects the lock detection window
   * Selects the lock detection window:
   * 0D: 0.265 ns
   * 1D: 0.5 ns
   * 2D: 1.0 ns
   * 3D: 1.5 ns
   * 4D: 2.0 ns
   * 5D: 2.8 ns
   * 6D: 3.8 ns
   * 7D: 4.6 ns
   */
  uint8_t locksel : 3;
  /**
   * @brief Forces the lock signal
   * Forces the lock signal:
   * 0B: Lock not forced
   * 1B: Lock forced (to high)
   */
  uint8_t lockforc : 1;
  /**
   * @brief Selects the charge pump current
   * Selects the charge pump current:
   * 0B: 40 µA
   * 1B: 80 µA
   * 2B: 120 µA
   * 3B: 160 µA
   * 4B: 200 µA
   * 5B: 240 µA
   * 6B: 280 µA
   * 7B: 280 µA
   */
  uint8_t icpsel : 3;
  /**
   * @brief Enables fixed biasing inside charge pump
   * Enables fixed biasing inside charge pump:
   * 0B: Disabled (Bias regulation loop active)
   * 1B: Enabled (Bias regulation loop deactivated)
   */
  uint8_t biasforc : 1;
  /**
   * @brief Enables charge pump
   * Enables charge pump:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t cpen : 1;
  /**
   * @brief Enables loop filter
   * Enables loop filter:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t lfen : 1;
  /**
   * @brief Enables system clock (SYS_CLK)
   * Enables system clock (SYS_CLK):
   * 0B: Disabled
   * 1B: Enabled
   * Note: This bit is controlled by FSM during operation. After deep sleep, this bit should be enabled by the host. Before the MAIN:FRAME_START is raised, the OSCCLKEN must be enabled!
   */
  uint8_t oscclken : 1;
};

// ==== PACR2 ==================================================================

#define BGT60UTR13D_REG_PACR2__RESETVAL (0x40014U) //!< PACR2 Reset Value

/**
 * @brief PACR2 Register Struct
 * Address: 0x5.
 * Use \ref BGT60UTR13D_PACR2_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * PLL analog control register 2
 */
struct bgt60utr13d_reg_pacr2 {
  /**
   * @brief Set fixed part of integer division factor
   * Set fixed part of integer division factor:
   * 0D..19D: Reserved
   * 20D: Valid for 80 MHz system clock
   * 21D: Valid for 76.8 MHz or 38.4 MHz system clock
   * 22D..31D: Reserved
   * Note: Consider offset of |2|
   */
  uint8_t divset : 5;
  /**
   * @brief Enables divider
   * Enables divider:
   * 0B: Disabled (input clock of divider gated)
   * 1B: Enabled
   */
  uint8_t diven : 1;
  /**
   * @brief Enables fast down chirp
   * Enables fast down chirp:
   * 0D: Disabled
   * 1D: Reserved
   * 2D: Enabled fast down chirp
   * 3D: Reserved
   */
  uint8_t fstdnen : 2;
  /**
   * @brief Defines the time for the PLL loop filter discharge during fast down chirp operation
   * Defines the time for the PLL loop filter discharge during fast down chirp operation.
   * When FSTDNTMR = 0D and FSTDNEN ≠ 0D, the fast down chirp length is internally assigned to a default value (@typ fSYS_CLK):
   * T_FSTDN = (FSTDNTMR + 1) * TSYS_CLK
   * 0D..4D: Reserved
   * 5D: 75 ns
   * 6D..511D: Reserved
   */
  uint16_t fsdntmr : 9;
  /**
   * @brief Set regulator off state to tristate
   * Set regulator off state to tristate (for both analog and digital regulator):
   * 0B: Off state is 0.0 V
   * 1B: Off state is tristate
   * Note: Setting active for digital regulator if DIGPON = 0B or ANAPON = 0B.
   */
  uint8_t trivreg : 1;
  /**
   * @brief Select PFD dead time / dead zone
   * Select PFD dead time / dead zone:
   * 0D: 180 ps to 350 ps
   * 1D: 270 ps to 510 ps
   * 2D: 360 ps to 680 ps
   * 3D: 450 ps to 840 ps
   */
  uint8_t dtsel : 2;
  /** @brief Reserved */
  uint8_t rsvd : 1;
  /**
   * @brief Time for T_DIVEN
   * Time for T_DIVEN. Defines the delay after PACR2:DIVEN is handed over to PLL and pll_rst_n is released. Running in parallel to T_INIT1.
   * T_DIVEN = (TR_DIVEN * 32 + 1) * TSYS_CLK:
   * 0D: Minimum value
   * 7D: Maximum value
   */
  uint8_t tr_diven : 3;
};

// ==== SFCTL ==================================================================

#define BGT60UTR13D_REG_SFCTL__RESETVAL (0x796000U) //!< SFCTL Reset Value

/**
 * @brief SFCTL Register Struct
 * Address: 0x6.
 * Use \ref BGT60UTR13D_SFCTL_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * SPI and FIFO control register
 */
struct bgt60utr13d_reg_sfctl {
  /**
   * @brief FIFO compare reference
   * FIFO compare reference defines the compare filling status for interrupt and CREF reporting. When filling status is > FIFO_CREF, an interrupt is issued.
   * 0D: Minimum value is 0, interrupt generated in case first sample is written into FIFO
   * 8191D: Maximum value in case FIFO is full with 8192 memory locations
   */
  uint16_t fifo_cref : 13;
  /**
   * @brief RAM power mode for power saving
   * RAM power mode for power saving (power switch):
   * 0D: FIFO RAM always powered up
   * 1D: FIFO RAM powered down during Deepsleep
   * 2D: FIFO RAM powered down during Deepsleep + Idle
   * 3D: Reserved
   * Note: RAM is only powered down when FIFO is empty.
   */
  uint8_t fifo_pd_mode : 2;
  /**
   * @brief Change working edge of SPI DO (MISO) to enable higher SPI frequencies
   * Change working edge of SPI DO (MISO) to enable higher SPI frequencies (>= 25 MHz):
   * 0B: MISO data is sent with falling edge of SPI_CLK
   * 1B: MISO data is sent with rising edge of SPI_CLK
   * Note: HS_RD = 0B can only be used for an fSPI_CLK less than 25 MHz. For high-speed transfer, please check the timing of the SPI master and adjust settings accordingly. The setting becomes active when the last bit of FSCTL is clocked out and it affects MISO immediately.
   */
  uint8_t miso_hs_read : 1;
  /**
   * @brief Enable LFSR data generation
   * Enable LFSR data generation:
   * 0B: Disabled
   * 1B: Enabled
   * Note: LFSR should be enabled after a FIFO reset to ensure an empty FIFO.
   */
  uint8_t lfsr_en : 1;
  /**
   * @brief Enables the prefix data header written into the FIFO prior to the sampling data of each chirp
   * Enables the prefix data header written into the FIFO prior to the sampling data of each chirp:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t prefix_en : 1;
  /**
   * @brief SPI pad driver mode to control the slew rate
   * SPI pad driver mode to control the slew rate:
   * 0B: Normal mode
   * 1B: Strong mode
   */
  uint8_t pad_mode : 1;
};

// ==== SADC_CTRL ==============================================================

#define BGT60UTR13D_REG_SADC_CTRL__RESETVAL (0xC0U) //!< SADC_CTRL Reset Value

/**
 * @brief SADC_CTRL Register Struct
 * Address: 0x7.
 * Use \ref BGT60UTR13D_SADC_CTRL_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Sensor ADC control register
 */
struct bgt60utr13d_reg_sadc_ctrl {
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
  enum bgt60utr13d_sadc_ctrl_sadc_chsel sadc_chsel : 4;
  /**
   * @brief Trigger for manual sensor ADC conversion
   * Trigger for manual sensor ADC conversion:
   * 0B: No effect
   * 1B: Executes a single sensor ADC conversion and clears this bit
   */
  uint8_t start_sadc : 1;
  /**
   * @brief SADC clock divider provides the system clock for the sensor ADC
   * SADC clock divider provides the system clock for the sensor ADC. SADC clock frequency divider value. fSADC_CLK = fSYS_CLK / SADC_CLK_DIV:
   * 0D: Divider value is 1
   * 1D: Divider value is 2
   * 2D: Divider value is 3
   * 3D: Divider value is 4
   */
  enum bgt60utr13d_sadc_ctrl_sadc_clk_div sadc_clk_div : 2;
  /**
   * @brief Enables sigma delta loop
   * Enables sigma delta loop:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t sd_en : 1;
  /**
   * @brief Oversampling configuration
   * Oversampling configuration:
   * 0D: No oversampling (8 bits resolution)
   * 1D: Oversampling x2
   * 2D: Oversampling x4 (9 bits resolution)
   * 3D: Oversampling x32 (10 bits resolution)
   */
  uint8_t overs_cfg : 2;
  /**
   * @brief Spreaded early sampling point enable
   * Spreaded early sampling point enable:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t sesp : 1;
  /**
   * @brief Sample configuration for LV channels
   * Sample configuration for LV channels:
   * 0B: Gain = 1.0
   * 1B: Gain = 0.75
   */
  uint8_t lvgain : 1;
  /**
   * @brief Disables startup calibration
   * Disables startup calibration:
   * 0B: Enabled
   * 1B: Disabled
   */
  uint8_t dscal : 1;
  /**
   * @brief Bandgap trimming value
   * Bandgap trimming value:
   * 0D: Minimum trimming value
   * 7D: Maximum trimming value
   */
  uint8_t tc_trim : 3;
};

// ==== CCR0 ===================================================================

#define BGT60UTR13D_REG_CCR0__RESETVAL (0x0U) //!< CCR0 Reset Value

/**
 * @brief CCR0 Register Struct
 * Address: 0x2C.
 * Use \ref BGT60UTR13D_CCR0_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Chirp control register 0
 */
struct bgt60utr13d_reg_ccr0 {
  /**
   * @brief Timer for T_END. Waiting time after the generation of a ramp
   * Timer for T_END. Waiting time after the generation of a ramp:
   * 0D: T_END = 5 * TSYS_CLK
   * 1D - 511D: T_END = (TR_END * 8 + 5) * TSYS_CLK
   */
  uint16_t tr_end : 9;
  /**
   * @brief Continuous mode
   * Continuous mode. After the last channel set repetition RT, the specified
   * power mode (CCR1:PD_MODE) is applied and:
   * 0B: The FSM stops immediately
   * 1B: After T_FED, the next channel set is applied
   * Note: In case DS power mode (CCR1:PD_MODE = 2D) is selected and the continuous mode is not active, the system clock is disabled internally.
   */
  uint8_t cont_mode : 1;
  /**
   * @brief Repetition factor for a channel set in a frame
   * Repetition factor for a channel set in a frame:
   * 0D - 15D: RT = 2^REPT
   * Note: The host should program the maximum value 15D as default.
   */
  uint8_t rept : 4;
  /**
   * @brief Timer for T_INIT1
   * Timer for T_INIT1:
   * 0D: TSYS_CLK
   * 1D - 255D: T_INIT1 = (TR_INIT1 * 2^TR_INIT1_MUL * 8 + TR_INIT1_MUL + 3) * TSYS_CLK
   * Note: These values are used for every up and every down-ramp.
   * Note: After the wake-up period, the timer for T_INIT1 should be at least 15 µs according to the typical ADC calibration time.
   */
  uint8_t tr_init1 : 8;
  /**
   * @brief Timer multiplier factor for T_INIT1
   * Timer multiplier factor for T_INIT1:
   * 0D - 3D: 2^TR_INIT1_MUL
   */
  uint8_t tr_init1_mul : 2;
};

// ==== CCR1 ===================================================================

#define BGT60UTR13D_REG_CCR1__RESETVAL (0x0U) //!< CCR1 Reset Value

/**
 * @brief CCR1 Register Struct
 * Address: 0x2D.
 * Use \ref BGT60UTR13D_CCR1_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Chirp control register 1
 */
struct bgt60utr13d_reg_ccr1 {
  /**
   * @brief Timer for T_START
   * Timer for T_START. Ramp start delay defines the delay before generating the ramp:
   * 0D - 511D: T_START = (TR_START * 8 + 10) * TSYS_CLK
   */
  uint16_t tr_start : 9;
  /**
   * @brief Power down mode
   * Power down mode. After the last repetition RT, the chip enters the defined power mode (during T_FED):
   * 0D: Keep the same power mode (CSx + CSCx)
   * 1D: Change to IDLE power mode (CSI + CSCI)
   * 2D: Change to DS power mode (CSDS + CSCDS)
   * 3D: Reserved
   */
  enum bgt60utr13d_ccr1_pd_mode pd_mode : 2;
  /**
   * @brief Timer for T_FED
   * Timer for T_FED:
   * 0D: TSYS_CLK
   * 1D - 255D: T_FED = (TR_FED * 2^TR_FED_MUL * 8 + TR_FED_MUL + 3) * TSYS_CLK
   */
  uint8_t tr_fed : 8;
  /**
   * @brief Timer multiplier factor for T_FED
   * Timer multiplier factor for T_FED:
   * 0D - 31D: 2^TR_FED_MUL
   */
  uint8_t tr_fed_mul : 5;
};

// ==== CCR2 ===================================================================

#define BGT60UTR13D_REG_CCR2__RESETVAL (0x0U) //!< CCR2 Reset Value

/**
 * @brief CCR2 Register Struct
 * Address: 0x2E.
 * Use \ref BGT60UTR13D_CCR2_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Chirp control register 2
 */
struct bgt60utr13d_reg_ccr2 {
  /**
   * @brief Maximum number of frames to be executed
   * Maximum number of frames to be executed. When MAX_FRAME_CNT is reached, the shape generation is stopped and the chip is set to deep sleep power mode. The next frame can be triggered only after a reset (e.g. FSM_RESET). The frame generation can be stopped at any time by resetting the FSM (see MAIN:FSM_RESET).
   * 0D: Endless frame generation
   * 1D: 1 frame is generated
   * 4095D: 4095 frames are generated
   */
  uint16_t max_frame_cnt : 12;
  /**
   * @brief Frame Length
   * Frame Length specifies the number of shape groups in a frame. When the specified frame length is reached, the frame counter is incremented, and the shape group counter is reset:
   * 0D: Minimum value (1 shape group)
   * 4095D: Maximum value (4096 shape groups)
   */
  uint16_t frame_len : 12;
};

// ==== CCR3 ===================================================================

#define BGT60UTR13D_REG_CCR3__RESETVAL (0x0U) //!< CCR3 Reset Value

/**
 * @brief CCR3 Register Struct
 * Address: 0x2F.
 * Use \ref BGT60UTR13D_CCR3_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Chirp control register 3
 */
struct bgt60utr13d_reg_ccr3 {
  /**
   * @brief Timer for T_PAEN
   * Timer for T_PAEN. Delay time after PLL start and power amplifier enable:
   * 0D: Reserved
   * 1D..511D: T_PAEN = TR_PAEN * 8 * TSYS_CLK
   */
  uint16_t tr_paen : 9;
  /**
   * @brief Timer for T_SSTART
   * Timer for T_SSTART. Delay time after power amplifier enable and the first trigger to ADC:
   * 0D..31D: T_SSTART = (TR_SSTART * 8 + 1) * TSYS_CLK
   */
  uint8_t tr_sstart : 5;
  /**
   * @brief Timer for T_INIT0
   * Timer for T_INIT0:
   * 0D: TSYS_CLK
   * 1D..255D: T_INIT0 = (TR_INIT0 * 2TR_INIT0_MUL * 8 + TR_INIT0_MUL + 3) * TSYS_CLK
   * Note: After the wake-up period, the timer for T_INIT0 should be at least 70 µs according to the typical ADC calibration time.
   */
  uint8_t tr_init0 : 8;
  /**
   * @brief Timer multiplier for T_INIT0
   * Timer multiplier for T_INIT0:
   * 0D..3D: 2TR_INIT0_MUL
   */
  uint8_t tr_init0_mul : 2;
};

// ==== RFT0 ===================================================================

#define BGT60UTR13D_REG_RFT0__RESETVAL (0x1F40U) //!< RFT0 Reset Value

/**
 * @brief RFT0 Register Struct
 * Address: 0x55.
 * Use \ref BGT60UTR13D_RFT0_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * RF test register 0
 */
struct bgt60utr13d_reg_rft0 {
  /**
   * @brief RF test tone signal divider value
   * RF test tone signal divider value. fRFTST = fSYS_CLK / RFTSIGCLK_DIV: 0D ... Reserved 1D ... Reserved 2D ... Minimum value 8191D ... Maximum value
   */
  uint16_t rftsigclk_div : 13;
  /**
   * @brief Enable the RF test tone signal output to the baseband
   * Enable the RF test tone signal output to the baseband: 0B ... Disabled 1B ... Enabled
   */
  uint8_t rftsigclk_div_en : 1;
  /**
   * @brief Enable test signal for receiver RF1
   * Enable test signal for receiver RF1: 0B ... Disabled 1B ... Enabled
   */
  uint8_t test_sig_rf1_en : 1;
  /**
   * @brief Enable test signal for IF channel 1
   * Enable test signal for IF channel 1: 0B ... Disabled 1B ... Enabled
   */
  uint8_t test_sig_if1_en : 1;
  /**
   * @brief Enable test signal for IF channel 2
   * Enable test signal for IF channel 2: 0B ... Disabled 1B ... Enabled
   */
  uint8_t test_sig_if2_en : 1;
  /**
   * @brief Enable test signal for IF channel 3
   * Enable test signal for IF channel 3: 0B ... Disabled 1B ... Enabled
   */
  uint8_t test_sig_if3_en : 1;
  /**
   * @brief RF test mode
   * RF test mode. 0B ... Test mode disabled 1B ... Mode 1: rf_bb:tx1_en toggles between 0B and CSx:TX1_EN with fRFTST 2B ... Mode 2: rf_bb:tx1_dac toggles between 0B and CSx:TX1_DAC with fRFTST 3B ... Mode 3: rf_bb:test_sig_rf1 toggles between 0B and RFT0:TEST_SIG_RF1_EN with fRFTST Note: RF test mode is only active for MAIN:CW_MODE = 1B. Note: RFTSIGCLK_DIV must be programmed and RFTSIGCLK_DIV_EN must be enabled.
   */
  uint8_t rf_test_mode : 2;
};

// ==== EFUSE0 =================================================================

#define BGT60UTR13D_REG_EFUSE0__RESETVAL (0x200U) //!< EFUSE0 Reset Value

/**
 * @brief EFUSE0 Register Struct
 * Address: 0x57.
 * Use \ref BGT60UTR13D_EFUSE0_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * EFUSE register 0
 */
struct bgt60utr13d_reg_efuse0 {
  /**
   * Enable EFUSE:
   * 0B ... Enabled
   * 1B ... Disabled
   */
  uint8_t efuse_en : 1;
  /**
   * Start EFUSE read sequence:
   * 0B ... No effect
   * 1B ... Executes EFUSE reading and clears this bit
   */
  uint8_t efuse_sense : 1;
};

// ==== EFUSE1 =================================================================

#define BGT60UTR13D_REG_EFUSE1__RESETVAL (0x300U) //!< EFUSE1 Reset Value

/**
 * @brief EFUSE1 Register Struct
 * Address: 0x58.
 * Use \ref BGT60UTR13D_EFUSE1_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * EFUSE register 1
 */
struct bgt60utr13d_reg_efuse1 {
  /**
   * EFUSE ready:
   * 0B ... Not ready
   * 1B ... Ready
   * Note: Only valid after EFUSE_SENSE was executed! Result stored in CHIP_ID0 and CHIP_ID1.
   */
  uint8_t efuse_ready : 1;
};

// ==== PDFT0 ==================================================================

#define BGT60UTR13D_REG_PDFT0__RESETVAL (0x0U) //!< PDFT0 Reset Value

/**
 * @brief PDFT0 Register Struct
 * Address: 0x59.
 * Use \ref BGT60UTR13D_PDFT0_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * PLL test register 0
 */
struct bgt60utr13d_reg_pdft0 {
  /**
   * Enable bypass ramp generator:
   * 0B ... Ramp generator enabled
   * 1B ... Ramp generator disabled (bypassed)
   */
  uint8_t byprmpen : 1;
  /**
   * Enable bypass for sigma delta modulator:
   * 0B ... Disabled
   * 1B ... Enabled
   */
  uint8_t bypsdmen : 1;
  /**
   * Value used for bypassed sigma delta modulator:
   * 0D ... Minimum value
   * 15D ... Maximum value
   */
  uint8_t bypsdm : 4;
};

// ==== STAT0 ==================================================================

#define BGT60UTR13D_REG_STAT0__RESETVAL (0x8U) //!< STAT0 Reset Value

/**
 * @brief STAT0 Register Struct
 * Address: 0x5D.
 * Use \ref BGT60UTR13D_STAT0_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Status register 0
 */
struct bgt60utr13d_reg_stat0 {
  /**
   * SADC status:
   *   0B ... Not ready
   *   1B ... Ready
   */
  uint8_t sadc_rdy : 1;
  /**
   * MADC status:
   *   0B ... Not ready
   *   1B ... Ready
   */
  uint8_t madc_rdy : 1;
  /**
   * MADC bandgap reference power up status:
   *   0B ... Not ready
   *   1B ... Ready
   */
  uint8_t madc_bgup : 1;
  /**
   * LDO status (VDDC above the threshold):
   *   0B ... Not ready
   *   1B ... Ready
   */
  uint8_t ldo_rdy : 1;
  /**
   * Power mode of the FSM:
   *   0D ... Deep sleep mode (after reset)
   *   1D ... Active mode
   *   2D ... Interchirp mode
   *   3D ... Idle mode
   *   4D ... Reserved
   *   5D ... Deep sleep mode
   *   6D ... Reserved
   *   7D ... Reserved
   */
  uint8_t pm : 3;
  /**
   * Channel set index enabled by the FSM:
   *   0D ... CSU1
   *   1D ... CSD1
   *   2D ... CSU2
   *   3D ... CSD2
   *   4D ... CSU3
   *   5D ... CSD3
   *   6D ... CSU4
   *   7D ... CSD4
   */
  uint8_t ch_idx : 3;
  /**
   * Shape index enabled by the FSM:
   *   0D ... PLLU1
   *   1D ... PLLD1
   *   2D ... PLLU2
   *   3D ... PLLD2
   *   4D ... PLLU3
   *   5D ... PLLD3
   *   6D ... PLLU4
   *   7D ... PLLD4
   */
  uint8_t sh_idx : 3;
};

// ==== SADC_RESULT ============================================================

#define BGT60UTR13D_REG_SADC_RESULT__RESETVAL (0x0U) //!< SADC_RESULT Reset Value

/**
 * @brief SADC_RESULT Register Struct
 * Address: 0x5E.
 * Use \ref BGT60UTR13D_SADC_RESULT_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Sensor ADC result register
 */
struct bgt60utr13d_reg_sadc_result {
  /**
   * SADC measurement result (10bit). Note: In case 8 bits are converted, the 8-bit value is left-shifted by two (multiplied by 4). In case 9 bits are converted, the 9-bit result is left-shifted by one (multiplied by 2).
   */
  uint16_t sadc_result : 10;
  /**
   * Shows the SADC busy status:
   *   0B ... Not busy
   *   1B ... Busy
   */
  uint8_t sadc_busy : 1;
  /**
   * SADC raw data. Note: Should only be used for test.
   */
  uint16_t sadc_raw : 10;
};

// ==== FSTAT ==================================================================

#define BGT60UTR13D_REG_FSTAT__RESETVAL (0x1000U) //!< FSTAT Reset Value

/**
 * @brief FSTAT Register Struct
 * Address: 0x5F.
 * Use \ref BGT60UTR13D_FSTAT_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * FIFO status register
 * The global status register FSTAT is used to monitor the FIFO. It should be mentioned that for all status registers,
 * STAT0, STAT1, and FSTAT, with the exception of the FIFO status and error flags, updates to each status register
 * field can happen on different timing events relative to FSM states and the field content should be treated
 * independently from one-another. In CW mode the status bits can be read properly after e.g. 100 µs.
 */
struct bgt60utr13d_reg_fstat {
  /**
   * FIFO fill status:
   * 0000H ... FIFO is empty
   * 1000H ... FIFO is 50% filled
   * 2000H ... FIFO is full
   * Note: This bit field is for debugging only. It should not be evaluated
   * while the MADC is sampling and filling up the FIFO as the data are not
   * stable. Can be evaluated when the FSM status is held, for example, after
   * an FSM reset or in a specific power mode, Deep Sleep mode.
   */
  uint16_t fill_status : 14;
  /**
   * RAM power down state:
   * 0B ... RAM powered up
   * 1B ... RAM powered down
   */
  uint8_t ram_pwr_down : 1;
  /**
   * Clock number error bit is set when the SPI clock number does not match
   * the expected number of clock cycles:
   * 0B ... No error
   * 1B ... Clock number error
   * Note: Bit will be reset after HW or SW reset.
   */
  uint8_t clk_num_err : 1;
  /**
   * In case of burst error, this bit is set:
   * 0B ... No error
   * 1B ... Burst error
   * Note: Bit will be reset after HW or SW reset.
   */
  uint8_t burst_err : 1;
  /**
   * FIFO underflow error shows if the host was reading more sampling data
   * from the FIFO than available. The flag is also shown in GSR0 as a part of
   * FIFO over or underflow error bit FOU_ERR:
   * 0B ... No FIFO underflow
   * 1B ... FIFO underflow
   * Note: Bit will be reset after HW, SW, or FIFO reset.
   */
  uint8_t fuf_err : 1;
  /**
   * FIFO empty status:
   * 0B ... FIFO not empty
   * 1B ... FIFO empty
   */
  uint8_t empty : 1;
  /**
   * FIFO fill status exceeds compare reference:
   * 0B ... Fill status below reference
   * 1B ... Fill status above reference
   */
  uint8_t cref : 1;
  /**
   * FIFO full status:
   * 0B ... FIFO not full
   * 1B ... FIFO full
   */
  uint8_t full : 1;
  /**
   * FIFO overflow error bit shows if more sample data is transferred to the
   * FIFO than FIFO memory locations are available to store the data. The
   * flag is also shown in GSR0 as a part of FIFO over or underflow error bit
   * FOU_ERR:
   * 0B ... No FIFO overflow
   * 1B ... FIFO overflow
   * Note: Bit will be reset after HW, SW, or FIFO reset.
   */
  uint8_t fof_err : 1;
};

// ==== CHIP_ID0 ===============================================================

#define BGT60UTR13D_REG_CHIP_ID0__RESETVAL (0xFFFFFFU) //!< CHIP_ID0 Reset Value

/**
 * @brief CHIP_ID0 Register Struct
 * Address: 0x60.
 * Use \ref BGT60UTR13D_CHIP_ID0_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Chip ID register 0
 */
struct bgt60utr13d_reg_chip_id0 {
  /**
   * Chip ID[23:0].
   * Note: Valid after EFUSE_SENSE was executed.
   */
  uint32_t chip_id : 24;
};

// ==== CHIP_ID1 ===============================================================

#define BGT60UTR13D_REG_CHIP_ID1__RESETVAL (0xFFFFFFU) //!< CHIP_ID1 Reset Value

/**
 * @brief CHIP_ID1 Register Struct
 * Address: 0x61.
 * Use \ref BGT60UTR13D_CHIP_ID1_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Chip ID register 1
 */
struct bgt60utr13d_reg_chip_id1 {
  /**
   * Chip ID[47:24].
   * Note: Valid after EFUSE_SENSE was executed.
   */
  uint32_t chip_id : 24;
};

// ==== CLK_IN =================================================================

#define BGT60UTR13D_REG_CLK_IN__RESETVAL (0x400U) //!< CLK_IN Reset Value

/**
 * @brief CLK_IN Register Struct
 * Address: 0x62.
 * Use \ref BGT60UTR13D_CLK_IN_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Clock input register
 */
struct bgt60utr13d_reg_clk_in {
  /**
   * Selection of input clock frequency and clock path:
   * 0 - Direct use of external OSC_CLK
   * 1 - Frequency doubler without DC_IN
   * 2 - Frequency doubler with DC_IN
   * 3 - Frequency doubler with DC calibration for system clock and without DC calibration for PLL clock
   * Note: It is important to program FD register first and enable the system clock afterwards by programming PACR2(23) register.
   */
  enum bgt60utr13d_clk_in_clk_sel clk_sel : 2;
  /**
   * Duty cycle of input clock can be adjusted before entering the internal clock doublers.
   * This adjustment can be used for equalizing the input clock to a DC of 50 % by applying a positive or negative clock delay time to the input clock (from OSC_CLK pin).
   * In case if MSB of DC_IN_ADJ = 0, a positive delay is used, while a MSB of DC_IN_ADJ = 1 applies a negative delay.
   * Delay times are in steps of 125 ps.
   * Range: +0.23 ns (minimal positive adjustment) to -2.1 ns (maximal negative adjustment).
   */
  uint8_t dc_in_adj : 5;
  /**
   * Duty cycle adjustment of clock doubler for the system clock. The system clock pulse width can be adjusted by 15 delay cells, starting from 4.3 ns up to 4.3 ns + 15 * 0.45 ns.
   * The duty cycle then is DCSYS_CLK = (4.3 ns + DC_OUT_ADJ * 0.4 ns) / TSYS_CLK.
   * Range: 4.3 ns to 11.05 ns.
   */
  uint8_t dc_out_adj : 4;
  /**
   * Select frequency doubler output at the IRQ pin:
   * 0 - Normal irq functionality at IRQ pin
   * 1 - Frequency doubler output at IRQ pin
   * Note: Frequency doubler has higher priority as interrupt.
   */
  enum bgt60utr13d_clk_in_irq_fd_sel irq_fd_sel : 1;
};

// ==== CS#_0 ==================================================================

#define BGT60UTR13D_REG_CS__0__RESETVAL (0x0U) //!< CS#_0 Reset Value

/**
 * @brief CS#_0 Register Struct
 * Part of register block CS#, at offset 0x0.
 * Use \ref BGT60UTR13D_CS__0_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Channel set idle register 0
 */
struct bgt60utr13d_reg_cs__0 {
  /**
   * @brief Enables the DAC and power amplifier of TX1
   * Enables the DAC and power amplifier of TX1:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t tx1_en : 1;
  /**
   * @brief Enables the power detector of TX1
   * Enables the power detector of TX1:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t pd1_en : 1;
  /**
   * @brief Enables the VCO
   * Enables the VCO:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t vco_en : 1;
  /**
   * @brief Enables the temperature sensor
   * Enables the temperature sensor:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t temp_meas_en : 1;
  /**
   * @brief Enables the VCO frequency divider
   * Enables the VCO frequency divider:
   * 0B: Disabled
   * 1B: Enabled
   * Note: DIV output
   */
  uint8_t fdiv_en : 1;
  /**
   * @brief Enables the local oscillator distribution buffer to RX1 and RX3 channels
   * Enables the local oscillator distribution buffer to RX1 and RX3 channels:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t lo_dist2_en : 1;
  /**
   * @brief Enables the local oscillator distribution buffer to RX2 and TX channels
   * Enables the local oscillator distribution buffer to RX2 and TX channels:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t lo_dist1_en : 1;
  /**
   * @brief Enables the local oscillator buffer to the mixer on channel 1
   * Enables the local oscillator buffer to the mixer on channel 1:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t rx1lobuf_en : 1;
  /**
   * @brief Enables the mixer on channel 1
   * Enables the mixer on channel 1:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t rx1mix_en : 1;
  /**
   * @brief Enables the local oscillator buffer to the mixer on channel 2
   * Enables the local oscillator buffer to the mixer on channel 2:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t rx2lobuf_en : 1;
  /**
   * @brief Enables the mixer on channel 2
   * Enables the mixer on channel 2:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t rx2mix_en : 1;
  /**
   * @brief Enables the local oscillator buffer to the mixer on channel 3
   * Enables the local oscillator buffer to the mixer on channel 3:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t rx3lobuf_en : 1;
  /**
   * @brief Enables the mixer on channel 3
   * Enables the mixer on channel 3:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t rx3mix_en : 1;
  /**
   * @brief Selection of analog base band anti-aliasing filter frequency on channel 1
   * Selection of analog base band anti-aliasing filter frequency on channel 1:
   * 0B: 600 kHz
   * 1B: 1 MHz
   */
  enum bgt60utr13d_cs__0_abb1_aaf_ctrl abb1_aaf_ctrl : 1;
  /**
   * @brief Selection of analog base band anti-aliasing filter frequency on channel 2
   * Selection of analog base band anti-aliasing filter frequency on channel 2:
   * 0B: 600 kHz
   * 1B: 1 MHz
   */
  uint8_t abb2_aaf_ctrl : 1;
  /**
   * @brief Selection of analog base band anti-aliasing filter frequency on channel 3
   * Selection of analog base band anti-aliasing filter frequency on channel 3:
   * 0B: 600 kHz
   * 1B: 1 MHz
   */
  uint8_t abb3_aaf_ctrl : 1;
};

// ==== CS#_1 ==================================================================

#define BGT60UTR13D_REG_CS__1__RESETVAL (0x0U) //!< CS#_1 Reset Value

/**
 * @brief CS#_1 Register Struct
 * Part of register block CS#, at offset 0x1.
 * Use \ref BGT60UTR13D_CS__1_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Channel set idle register 1
 */
struct bgt60utr13d_reg_cs__1 {
  /**
   * @brief TX1 output power setting
   * TX1 output power setting:
   * 0D: Minimum output power
   * 31D: Maximum output power
   */
  uint8_t tx1_dac : 5;
  /**
   * @brief Gain setting of the first stage of the high pass filter of channel 1
   * Gain setting of the first stage of the high pass filter of channel 1:
   * 0B: 30 dB
   * 1B: 18 dB
   */
  enum bgt60utr13d_cs__1_hp1_gain hp1_gain : 1;
  /**
   * @brief Gain setting of the first stage of the high pass filter of channel 2
   * Gain setting of the first stage of the high pass filter of channel 2:
   * 0B: 30 dB
   * 1B: 18 dB
   */
  uint8_t hp2_gain : 1;
  /**
   * @brief Gain setting of the first stage of the high pass filter of channel 3
   * Gain setting of the first stage of the high pass filter of channel 3:
   * 0B: 30 dB
   * 1B: 18 dB
   */
  uint8_t hp3_gain : 1;
  /**
   * @brief Baseband reset timer counter value for the analog baseband amplifiers
   * Baseband reset timer counter value for the analog baseband amplifiers. The reset counter will start together with the PAON signal after the T_PAEN timer. TBBRST = BB_RSTCNT * 8 * TSYS_CLK:
   * 0D: No analog baseband reset
   * 1D: Minimum value
   * 127D: Maximum value
   */
  uint8_t bb_rstcnt : 6;
  /**
   * @brief Enables the baseband filters, baseband amplifiers, and ADC on channel 1
   * Enables the baseband filters, baseband amplifiers, and ADC on channel 1:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t madc_bbch1_en : 1;
  /**
   * @brief Enables the baseband filters, baseband amplifiers, and ADC on channel 2
   * Enables the baseband filters, baseband amplifiers, and ADC on channel 2:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t madc_bbch2_en : 1;
  /**
   * @brief Enables the baseband filters, baseband amplifiers, and ADC on channel 3
   * Enables the baseband filters, baseband amplifiers, and ADC on channel 3:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t madc_bbch3_en : 1;
};

// ==== CS#_2 ==================================================================

#define BGT60UTR13D_REG_CS__2__RESETVAL (0x0U) //!< CS#_2 Reset Value

/**
 * @brief CS#_2 Register Struct
 * Part of register block CS#, at offset 0x2.
 * Use \ref BGT60UTR13D_CS__2_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Channel set idle register 2
 */
struct bgt60utr13d_reg_cs__2 {
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
  enum bgt60utr13d_cs__2_hpf_sel1 hpf_sel1 : 3;
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
  enum bgt60utr13d_cs__2_vga_gain1 vga_gain1 : 3;
  /**
   * @brief High pass filter cutoff frequency setting of channel 2
   * High pass filter cutoff frequency setting of channel 2:
   * 0D: 20 kHz
   * 1D: 40 kHz
   * 2D: 80 kHz
   * 3D: 140 kHz
   * 4D: 160 kHz
   * 5D: Reserved
   * 6D: Reserved
   * 7D: Reserved
   */
  uint8_t hpf_sel2 : 3;
  /**
   * @brief VGA gain setting of channel 2
   * VGA gain setting of channel 2:
   * 0D: 0 dB
   * 1D: 5 dB
   * 2D: 10 dB
   * 3D: 15 dB
   * 4D: 20 dB
   * 5D: 25 dB
   * 6D: 30 dB
   * 7D: Reserved
   */
  uint8_t vga_gain2 : 3;
  /**
   * @brief High pass filter cutoff frequency setting of channel 3
   * High pass filter cutoff frequency setting of channel 3:
   * 0D: 20 kHz
   * 1D: 40 kHz
   * 2D: 80 kHz
   * 3D: 140 kHz
   * 4D: 160 kHz
   * 5D: Reserved
   * 6D: Reserved
   * 7D: Reserved
   */
  uint8_t hpf_sel3 : 3;
  /**
   * @brief VGA gain setting of channel 3
   * VGA gain setting of channel 3:
   * 0D: 0 dB
   * 1D: 5 dB
   * 2D: 10 dB
   * 3D: 15 dB
   * 4D: 20 dB
   * 5D: 25 dB
   * 6D: 30 dB
   * 7D: Reserved
   */
  uint8_t vga_gain3 : 3;
};

// ==== CSC# ===================================================================

#define BGT60UTR13D_REG_CSC___RESETVAL (0x240B60U) //!< CSC# Reset Value

/**
 * @brief CSC# Register Struct
 * Part of register block CSC#, at offset 0x0.
 * Use \ref BGT60UTR13D_CSC__FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * Channel set control idle register
 */
struct bgt60utr13d_reg_csc_ {
  /**
   * @brief Repetition factor of channel set (active only)
   * Repetition factor of channel set (active only)
   * REPC = 0..15.
   * RC = 2 ^ REPC.
   */
  uint8_t repcs : 1;
  /**
   * @brief Enables channel set (CS)
   * Enables channel set (CS)
   * 0B: Disabled
   * 1B: Enabled
   * Note: At least the first channel set should be used (CSC1:CS_EN = 1B)
   */
  uint8_t cs_en : 1;
  /**
   * @brief Enables isolation of all control signals to the ABB
   * Enables the isolation of all control signals to the ABB:
   * 0B: Disabled
   * 1B: Enabled
   * Note: In case the isolation is enabled, all control signals are connected to 0B.
   */
  uint8_t abb_isopd : 1;
  /**
   * @brief Enables isolation of all control signals to the RF
   * Enables the isolation of all control signals to the RF:
   * 0B: Disabled
   * 1B: Enabled
   * Note: In case the isolation is enabled, all control signals are connected to 0B.
   */
  uint8_t rf_isopd : 1;
  /**
   * @brief Enables the bandgap of the MADC
   * Enables the bandgap of the MADC:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t madc_bg_en : 1;
  /**
   * @brief Enables isolation of all control signals to the MADC
   * Enables the isolation of all control signals to the MADC:
   * 0B: Disabled
   * 1B: Enabled
   * Note: In case the isolation is enabled, all control signals are connected to 0B.
   */
  uint8_t madc_isopd : 1;
  /**
   * @brief Enables isolation of all control signals to the SADC
   * Enables the isolation of all control signals to the SADC:
   * 0B: Disabled
   * 1B: Enabled
   * Note: In case the isolation is enabled, all control signals are connected to 0B.
   */
  uint8_t sadc_isopd : 1;
  /**
   * @brief Enables the temperature sensor
   * Enables the temperature sensor:
   * 0B: Disabled
   * 1B: Enabled
   */
  uint8_t bg_tmrf_en : 1;
  /**
   * @brief Enables isolation of all control signals to the PLL
   * Enables the isolation of all control signals to the PLL:
   * 0B: Disabled
   * 1B: Enabled
   * Note: In case the isolation is enabled, all control signals are connected to 0B.
   */
  uint8_t pll_isopd : 1;
  /**
   * @brief Timer for T_PLL_ISOPD
   * Timer for T_PLL_ISOPD. Delay PLL isolation after IDLE state:
   * 0D: T_PLL_ISOPD = TSYS_CLK
   * 1D-63D: T_PLL_ISOPD = (TR_PLL_ISOPD * 64 + 2) * TSYS_CLK
   * Note: if TR_PLL_ISOPD > 0D then CSCI:PLL_ISOPD should be 1B and T_INIT0 must be larger than T_PLL_ISOPD.
   */
  uint8_t tr_pll_isopd : 6;
  /**
   * @brief Timer for T_MADCEN
   * Timer for T_MADCEN. Delay MADC enable after IDLE state:
   * 0D: No delay
   * 1D-7D: T_MADCEN = (TR_MADCEN * 64 + 1) * TSYS_CLK
   * Note: T_INIT0 must be larger than T_MADCEN. Typical T_MADCEN = 0.8 µs.
   */
  uint8_t tr_madcen : 3;
  /**
   * @brief Timer for T_BGEN
   * Timer for T_BGEN. Delay bandgap enable after IDLE state (coming from DS or DS_CONT):
   * 0D: T_BGEN = TSYS_CLK
   * 1D-7D: T_BGEN = (TR_BGEN * 64 + 2) * TSYS_CLK
   * Note: T_WU must be larger than T_BGEN. Typical T_BGEN = 0.8 µs.
   */
  uint8_t tr_bgen : 3;
};

// ==== PLL#_0 =================================================================

#define BGT60UTR13D_REG_PLL__0__RESETVAL (0x0U) //!< PLL#_0 Reset Value

/**
 * @brief PLL#_0 Register Struct
 * Part of register block PLL#, at offset 0x0.
 * Use \ref BGT60UTR13D_PLL__0_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * PLL shape x register 0
 */
struct bgt60utr13d_reg_pll__0 {
  /**
   * @brief Chirp start frequency for up chirp
   * Chirp start frequency for up chirp. Sigma delta start frequency for the ramp generator:
   * 0D: Sawtooth shape
   * Note: In case FSD = 0D, RSD = 0D, and RTD = 0D, the fast sawtooth shape is enabled.
   * In all other cases, the triangular shape is enabled.
   */
  uint32_t fsu : 24;
};

// ==== PLL#_1 =================================================================

/**
 * @brief PLL#_1 Register Struct
 * Part of register block PLL#, at offset 0x1.
 * Use \ref BGT60UTR13D_PLL__1_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * PLL shape x register 1
 */
struct bgt60utr13d_reg_pll__1 {
  /**
   * @brief Ramp step up chirp
   * Ramp step up chirp. A ramp step is the RF frequency difference added to the actual frequency during
   * a single clock cycle time of TSYS_CLK. In case the value is zero, the RF frequency will be almost constant during
   * the RTU time.
   * Bit(23) represents the sign for the ramp:
   * 0D: Up chirp
   * 1D: Down chirp
   */
  uint32_t rsu : 24;
};

// ==== PLL#_2 =================================================================

#define BGT60UTR13D_REG_PLL__2__RESETVAL (0x0U) //!< PLL#_2 Reset Value

/**
 * @brief PLL#_2 Register Struct
 * Part of register block PLL#, at offset 0x2.
 * Use \ref BGT60UTR13D_PLL__2_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * PLL shape x register 2
 */
struct bgt60utr13d_reg_pll__2 {
  /**
   * @brief Ramp time for up chirp. RTU defines the number of clock cycles for the up chirp.
   * RTU 13:0 rw Ramp time for up chirp. RTU defines the number of clock cycles for the up chirp.
   * The actual ramp time is:
   * 0D: Timer disabled (needed for fast down chirp)
   * 1D..16383D: T_RAMP = RTU * 8 * TSYS_CLK
   */
  uint16_t rtu : 14;
  /**
   * @brief Timer for T_EDU. End of chirp delay applied after every up chirp
   * TR_EDU 23:16 rw Timer for T_EDU. End of chirp delay applied after every up chirp:
   * 0D: T_EDU = 2 * TSYS_CLK
   * 1D..255D: T_EDU = (TR_EDU * 8 + 5) * TSYS_CLK
   */
  uint8_t tr_edu : 8;
};

// ==== PLL#_3 =================================================================

#define BGT60UTR13D_REG_PLL__3__RESETVAL (0x0U) //!< PLL#_3 Reset Value

/**
 * @brief PLL#_3 Register Struct
 * Part of register block PLL#, at offset 0x3.
 * Use \ref BGT60UTR13D_PLL__3_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * PLL shape x register 3
 */
struct bgt60utr13d_reg_pll__3 {
  /**
   * @brief Number of samples for an up chirp of a single ADC
   * APU 11:0 rw Number of samples for an up chirp of a single ADC: 0D..4095D ... Number of samples
   */
  uint16_t apu : 12;
  /**
   * @brief Number of samples for a down chirp of a single ADC
   * APD 23:12 rw Number of samples for a down chirp of a single ADC: 0D..4095D ... Number of samples
   */
  uint16_t apd : 12;
};

// ==== PLL#_4 =================================================================

#define BGT60UTR13D_REG_PLL__4__RESETVAL (0x0U) //!< PLL#_4 Reset Value

/**
 * @brief PLL#_4 Register Struct
 * Part of register block PLL#, at offset 0x4.
 * Use \ref BGT60UTR13D_PLL__4_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * PLL shape x register 4
 */
struct bgt60utr13d_reg_pll__4 {
  /**
   * @brief Chirp start frequency for down chirp.
   * FSD 23:0 rw Chirp start frequency for down chirp. Sigma delta start frequency for the ramp generator: 0D ... Sawtooth shape
   * Note: In case FSD = 0D, RSD = 0D, and RTD = 0D, the fast sawtooth shape is enabled. In all other cases the triangular shape is enabled.
   */
  uint32_t fsd : 24;
};

// ==== PLL#_5 =================================================================

#define BGT60UTR13D_REG_PLL__5__RESETVAL (0x0U) //!< PLL#_5 Reset Value

/**
 * @brief PLL#_5 Register Struct
 * Part of register block PLL#, at offset 0x5.
 * Use \ref BGT60UTR13D_PLL__5_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * PLL shape x register 5
 */
struct bgt60utr13d_reg_pll__5 {
  /**
   * @brief Ramp step down chirp.
   * RSD 23:0 rw Ramp step down chirp. A ramp step is the RF frequency difference added to the actual frequency during single clock cycle time of TSYS_CLK. In case the value is zero the RF frequency will be almost constant during the RTD time. Bit(23) represents the sign for the ramp: 0D ... Up chirp
   * 1D ... Down chirp
   */
  uint32_t rsd : 24;
};

// ==== PLL#_6 =================================================================

#define BGT60UTR13D_REG_PLL__6__RESETVAL (0x0U) //!< PLL#_6 Reset Value

/**
 * @brief PLL#_6 Register Struct
 * Part of register block PLL#, at offset 0x6.
 * Use \ref BGT60UTR13D_PLL__6_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * PLL shape x register 6
 */
struct bgt60utr13d_reg_pll__6 {
  /**
   * @brief Ramp time for down chirp.
   * RTD 13:0 rw Ramp time for down chirp. RTD defines the number of clock cycles for the down chirp. The actual ramp time is: 0D ... Timer disabled (needed for fast down chirp) 1D..16383D ... T_RAMP = RTD * 8 * TSYS_CLK
   */
  uint16_t rtd : 14;
  /**
   * @brief Timer for T_EDD. End of chirp delay applied after every down chirp.
   * TR_EDD 23:16 rw Timer for T_EDD. End of chirp delay applied after every down chirp: 0D ... T_EDD = 2 * TSYS_CLK 1D..255D ... T_EDD = (TR_EDD * 8 + 5) * TSYS_CLK
   */
  uint8_t tr_edd : 8;
};

// ==== PLL#_7 =================================================================

#define BGT60UTR13D_REG_PLL__7__RESETVAL (0x0U) //!< PLL#_7 Reset Value

/**
 * @brief PLL#_7 Register Struct
 * Part of register block PLL#, at offset 0x7.
 * Use \ref BGT60UTR13D_PLL__7_FUNCS or \ref BGT60UTR13D_GENERICFUNCS to convert this struct to and from it's packed binary form.
 * PLL shape x register 7
 */
struct bgt60utr13d_reg_pll__7 {
  /**
   * @brief Repetition factor for a single shape
   * REPS 3:0 rw Repetition factor for a single shape: 0D..15D ... RS = 2REPS
   */
  uint8_t reps : 4;
  /**
   * @brief Enable shape
   * SH_EN 4 rw Enable shape: 0B ... Disabled 1B ... Enabled Note: Values for disabled shapes are ignored. At least the first shape needs to be enabled (PLL1_7:SH_EN = 1B). Fields for unused shapes must be programmed to its default reset value.
   */
  uint8_t sh_en : 1;
  /**
   * @brief Continuous mode. After last shape repetition RS, the specified power mode (PLLy_7:PD_MODE) is applied
   * CONT_MODE 8 rw Continuous mode. After last shape repetition RS, the specified power mode (PLLy_7:PD_MODE) is applied and 0B ... the FSM stops immediately 1B ... after T_SED the next shape set is applied
   */
  uint8_t cont_mode : 1;
  /**
   * @brief Power down mode. After the last repetition RS, the chip enters the defined power mode (during T_SED)
   * PD_MODE 10:9 rw Power down mode. After the last repetition RS the chip enters the defined power mode (during T_SED): 0D ... Keep the same power mode (CSx + CSCx) 1D ... Change to IDLE power mode (CSI + CSCI) 2D ... Change to DS power mode (CSDS + CSCDS) 3D ... Reserved
   */
  enum bgt60utr13d_pll__7_pd_mode pd_mode : 2;
  /**
   * @brief Timer for T_SED
   * TR_SED 18:11 rw Timer for T_SED: 0D ... TSYS_CLK 1D..255D ... T_SED = (TR_SED * 2TR_SED_MUL * 8 + TR_SED_MUL + 3) * TSYS_CLK
   */
  uint8_t tr_sed : 8;
  /**
   * @brief Timer multiplier for T_SED
   * TR_SED_MUL 23:19 rw Timer multiplier for T_SED: 0D..31D ... 2TR_SED_MUL
   */
  uint8_t tr_sed_mul : 5;
};


#endif /* BGT60UTR13D_REGS_H_ */
