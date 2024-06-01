/*!
 * \file bgt60utr13d_reg_utils.h
 * \brief BGT60UTR13D Registers Utilities.
 * \note Do not edit: Generated using Reginald.
 */


#ifndef BGT60UTR13D_REG_UTILS_H_
#define BGT60UTR13D_REG_UTILS_H_

#include <stdint.h>
#include "bgt60utr13d_enums.h"
#include "bgt60utr13d_regs.h"

/**
 * @brief Lookup a register's reset value
 * @param adr register address
 * @param val buffer to store reset value. invalid if function returns 0.
 * @return 1 if a register exists at this address and has a resetval, 0 otherwise.
 */
static inline int bgt60utr13d_lookup_resetval(uint8_t adr, uint32_t *val){
  switch(adr) {
    case BGT60UTR13D_REG_MAIN:
      *val = BGT60UTR13D_REG_MAIN__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_ADC0:
      *val = BGT60UTR13D_REG_ADC0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CHIP_VERSION:
      *val = BGT60UTR13D_REG_CHIP_VERSION__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_STAT1:
      *val = BGT60UTR13D_REG_STAT1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PACR1:
      *val = BGT60UTR13D_REG_PACR1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PACR2:
      *val = BGT60UTR13D_REG_PACR2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_SFCTL:
      *val = BGT60UTR13D_REG_SFCTL__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_SADC_CTRL:
      *val = BGT60UTR13D_REG_SADC_CTRL__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSI_0:
      *val = BGT60UTR13D_REG_CS__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSI_1:
      *val = BGT60UTR13D_REG_CS__1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSI_2:
      *val = BGT60UTR13D_REG_CS__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSDS_0:
      *val = BGT60UTR13D_REG_CS__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSDS_1:
      *val = BGT60UTR13D_REG_CS__1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSDS_2:
      *val = BGT60UTR13D_REG_CS__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU1_0:
      *val = BGT60UTR13D_REG_CS__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU1_1:
      *val = BGT60UTR13D_REG_CS__1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU1_2:
      *val = BGT60UTR13D_REG_CS__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD1_0:
      *val = BGT60UTR13D_REG_CS__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD1_1:
      *val = BGT60UTR13D_REG_CS__1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD1_2:
      *val = BGT60UTR13D_REG_CS__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU2_0:
      *val = BGT60UTR13D_REG_CS__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU2_1:
      *val = BGT60UTR13D_REG_CS__1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU2_2:
      *val = BGT60UTR13D_REG_CS__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD2_0:
      *val = BGT60UTR13D_REG_CS__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD2_1:
      *val = BGT60UTR13D_REG_CS__1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD2_2:
      *val = BGT60UTR13D_REG_CS__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU3_0:
      *val = BGT60UTR13D_REG_CS__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU3_1:
      *val = BGT60UTR13D_REG_CS__1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU3_2:
      *val = BGT60UTR13D_REG_CS__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD3_0:
      *val = BGT60UTR13D_REG_CS__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD3_1:
      *val = BGT60UTR13D_REG_CS__1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD3_2:
      *val = BGT60UTR13D_REG_CS__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU4_0:
      *val = BGT60UTR13D_REG_CS__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU4_1:
      *val = BGT60UTR13D_REG_CS__1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSU4_2:
      *val = BGT60UTR13D_REG_CS__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD4_0:
      *val = BGT60UTR13D_REG_CS__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD4_1:
      *val = BGT60UTR13D_REG_CS__1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSD4_2:
      *val = BGT60UTR13D_REG_CS__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSCI:
      *val = BGT60UTR13D_REG_CSC___RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSCDS:
      *val = BGT60UTR13D_REG_CSC___RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSC1:
      *val = BGT60UTR13D_REG_CSC___RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSC2:
      *val = BGT60UTR13D_REG_CSC___RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSC3:
      *val = BGT60UTR13D_REG_CSC___RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CSC4:
      *val = BGT60UTR13D_REG_CSC___RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CCR0:
      *val = BGT60UTR13D_REG_CCR0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CCR1:
      *val = BGT60UTR13D_REG_CCR1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CCR2:
      *val = BGT60UTR13D_REG_CCR2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CCR3:
      *val = BGT60UTR13D_REG_CCR3__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL1_0:
      *val = BGT60UTR13D_REG_PLL__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL1_2:
      *val = BGT60UTR13D_REG_PLL__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL1_3:
      *val = BGT60UTR13D_REG_PLL__3__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL1_4:
      *val = BGT60UTR13D_REG_PLL__4__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL1_5:
      *val = BGT60UTR13D_REG_PLL__5__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL1_6:
      *val = BGT60UTR13D_REG_PLL__6__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL1_7:
      *val = BGT60UTR13D_REG_PLL__7__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL2_0:
      *val = BGT60UTR13D_REG_PLL__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL2_2:
      *val = BGT60UTR13D_REG_PLL__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL2_3:
      *val = BGT60UTR13D_REG_PLL__3__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL2_4:
      *val = BGT60UTR13D_REG_PLL__4__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL2_5:
      *val = BGT60UTR13D_REG_PLL__5__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL2_6:
      *val = BGT60UTR13D_REG_PLL__6__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL2_7:
      *val = BGT60UTR13D_REG_PLL__7__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL3_0:
      *val = BGT60UTR13D_REG_PLL__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL3_2:
      *val = BGT60UTR13D_REG_PLL__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL3_3:
      *val = BGT60UTR13D_REG_PLL__3__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL3_4:
      *val = BGT60UTR13D_REG_PLL__4__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL3_5:
      *val = BGT60UTR13D_REG_PLL__5__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL3_6:
      *val = BGT60UTR13D_REG_PLL__6__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL3_7:
      *val = BGT60UTR13D_REG_PLL__7__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL4_0:
      *val = BGT60UTR13D_REG_PLL__0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL4_2:
      *val = BGT60UTR13D_REG_PLL__2__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL4_3:
      *val = BGT60UTR13D_REG_PLL__3__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL4_4:
      *val = BGT60UTR13D_REG_PLL__4__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL4_5:
      *val = BGT60UTR13D_REG_PLL__5__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL4_6:
      *val = BGT60UTR13D_REG_PLL__6__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PLL4_7:
      *val = BGT60UTR13D_REG_PLL__7__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_RFT0:
      *val = BGT60UTR13D_REG_RFT0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_EFUSE0:
      *val = BGT60UTR13D_REG_EFUSE0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_EFUSE1:
      *val = BGT60UTR13D_REG_EFUSE1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_PDFT0:
      *val = BGT60UTR13D_REG_PDFT0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_STAT0:
      *val = BGT60UTR13D_REG_STAT0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_SADC_RESULT:
      *val = BGT60UTR13D_REG_SADC_RESULT__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_FSTAT:
      *val = BGT60UTR13D_REG_FSTAT__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CHIP_ID0:
      *val = BGT60UTR13D_REG_CHIP_ID0__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CHIP_ID1:
      *val = BGT60UTR13D_REG_CHIP_ID1__RESETVAL;
      return 1;
    case BGT60UTR13D_REG_CLK_IN:
      *val = BGT60UTR13D_REG_CLK_IN__RESETVAL;
      return 1;
   default:
     return 0;
  }
}

/**
 * \defgroup BGT60UTR13D_GENERICFUNCS Generic register modify/pack/unpack utilities.
 * @{
 */

// Disable clang-format for this section, since _Generic formatting is buggy up to v14 and
// v15 is too new to require.
// clang-format off

/**
 * @brief Modify a register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @note This is a generic macro that picks the correct function based on _struct_ptr_'s type.
 * @param _struct_ptr_ struct holding register fields
 * @param _val_ current binary register representation
 * @return packed register representation
 */
#define BGT60UTR13D_MODIFY(_struct_ptr_, _val_) _Generic((_struct_ptr_), \
    struct bgt60utr13d_reg_main* : bgt60utr13d_modify_main,  \
    struct bgt60utr13d_reg_adc0* : bgt60utr13d_modify_adc0,  \
    struct bgt60utr13d_reg_chip_version* : bgt60utr13d_modify_chip_version,  \
    struct bgt60utr13d_reg_stat1* : bgt60utr13d_modify_stat1,  \
    struct bgt60utr13d_reg_pacr1* : bgt60utr13d_modify_pacr1,  \
    struct bgt60utr13d_reg_pacr2* : bgt60utr13d_modify_pacr2,  \
    struct bgt60utr13d_reg_sfctl* : bgt60utr13d_modify_sfctl,  \
    struct bgt60utr13d_reg_sadc_ctrl* : bgt60utr13d_modify_sadc_ctrl,  \
    struct bgt60utr13d_reg_ccr0* : bgt60utr13d_modify_ccr0,  \
    struct bgt60utr13d_reg_ccr1* : bgt60utr13d_modify_ccr1,  \
    struct bgt60utr13d_reg_ccr2* : bgt60utr13d_modify_ccr2,  \
    struct bgt60utr13d_reg_ccr3* : bgt60utr13d_modify_ccr3,  \
    struct bgt60utr13d_reg_rft0* : bgt60utr13d_modify_rft0,  \
    struct bgt60utr13d_reg_efuse0* : bgt60utr13d_modify_efuse0,  \
    struct bgt60utr13d_reg_efuse1* : bgt60utr13d_modify_efuse1,  \
    struct bgt60utr13d_reg_pdft0* : bgt60utr13d_modify_pdft0,  \
    struct bgt60utr13d_reg_stat0* : bgt60utr13d_modify_stat0,  \
    struct bgt60utr13d_reg_sadc_result* : bgt60utr13d_modify_sadc_result,  \
    struct bgt60utr13d_reg_fstat* : bgt60utr13d_modify_fstat,  \
    struct bgt60utr13d_reg_chip_id0* : bgt60utr13d_modify_chip_id0,  \
    struct bgt60utr13d_reg_chip_id1* : bgt60utr13d_modify_chip_id1,  \
    struct bgt60utr13d_reg_clk_in* : bgt60utr13d_modify_clk_in,  \
    struct bgt60utr13d_reg_cs__0* : bgt60utr13d_modify_cs__0,  \
    struct bgt60utr13d_reg_cs__1* : bgt60utr13d_modify_cs__1,  \
    struct bgt60utr13d_reg_cs__2* : bgt60utr13d_modify_cs__2,  \
    struct bgt60utr13d_reg_csc_* : bgt60utr13d_modify_csc_,  \
    struct bgt60utr13d_reg_pll__0* : bgt60utr13d_modify_pll__0,  \
    struct bgt60utr13d_reg_pll__1* : bgt60utr13d_modify_pll__1,  \
    struct bgt60utr13d_reg_pll__2* : bgt60utr13d_modify_pll__2,  \
    struct bgt60utr13d_reg_pll__3* : bgt60utr13d_modify_pll__3,  \
    struct bgt60utr13d_reg_pll__4* : bgt60utr13d_modify_pll__4,  \
    struct bgt60utr13d_reg_pll__5* : bgt60utr13d_modify_pll__5,  \
    struct bgt60utr13d_reg_pll__6* : bgt60utr13d_modify_pll__6,  \
    struct bgt60utr13d_reg_pll__7* : bgt60utr13d_modify_pll__7  \
  )(_struct_ptr_, _val_)

/**
 * @brief Pack a register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @note This is a generic macro that picks the correct function based on _struct_ptr_'s type.
 * @param _struct_ptr_r struct holding register fields
 * @return packed register representation
 */
#define BGT60UTR13D_PACK(_struct_ptr_) _Generic((_struct_ptr_), \
    struct bgt60utr13d_reg_main* : bgt60utr13d_pack_main,  \
    struct bgt60utr13d_reg_adc0* : bgt60utr13d_pack_adc0,  \
    struct bgt60utr13d_reg_chip_version* : bgt60utr13d_pack_chip_version,  \
    struct bgt60utr13d_reg_stat1* : bgt60utr13d_pack_stat1,  \
    struct bgt60utr13d_reg_pacr1* : bgt60utr13d_pack_pacr1,  \
    struct bgt60utr13d_reg_pacr2* : bgt60utr13d_pack_pacr2,  \
    struct bgt60utr13d_reg_sfctl* : bgt60utr13d_pack_sfctl,  \
    struct bgt60utr13d_reg_sadc_ctrl* : bgt60utr13d_pack_sadc_ctrl,  \
    struct bgt60utr13d_reg_ccr0* : bgt60utr13d_pack_ccr0,  \
    struct bgt60utr13d_reg_ccr1* : bgt60utr13d_pack_ccr1,  \
    struct bgt60utr13d_reg_ccr2* : bgt60utr13d_pack_ccr2,  \
    struct bgt60utr13d_reg_ccr3* : bgt60utr13d_pack_ccr3,  \
    struct bgt60utr13d_reg_rft0* : bgt60utr13d_pack_rft0,  \
    struct bgt60utr13d_reg_efuse0* : bgt60utr13d_pack_efuse0,  \
    struct bgt60utr13d_reg_efuse1* : bgt60utr13d_pack_efuse1,  \
    struct bgt60utr13d_reg_pdft0* : bgt60utr13d_pack_pdft0,  \
    struct bgt60utr13d_reg_stat0* : bgt60utr13d_pack_stat0,  \
    struct bgt60utr13d_reg_sadc_result* : bgt60utr13d_pack_sadc_result,  \
    struct bgt60utr13d_reg_fstat* : bgt60utr13d_pack_fstat,  \
    struct bgt60utr13d_reg_chip_id0* : bgt60utr13d_pack_chip_id0,  \
    struct bgt60utr13d_reg_chip_id1* : bgt60utr13d_pack_chip_id1,  \
    struct bgt60utr13d_reg_clk_in* : bgt60utr13d_pack_clk_in,  \
    struct bgt60utr13d_reg_cs__0* : bgt60utr13d_pack_cs__0,  \
    struct bgt60utr13d_reg_cs__1* : bgt60utr13d_pack_cs__1,  \
    struct bgt60utr13d_reg_cs__2* : bgt60utr13d_pack_cs__2,  \
    struct bgt60utr13d_reg_csc_* : bgt60utr13d_pack_csc_,  \
    struct bgt60utr13d_reg_pll__0* : bgt60utr13d_pack_pll__0,  \
    struct bgt60utr13d_reg_pll__1* : bgt60utr13d_pack_pll__1,  \
    struct bgt60utr13d_reg_pll__2* : bgt60utr13d_pack_pll__2,  \
    struct bgt60utr13d_reg_pll__3* : bgt60utr13d_pack_pll__3,  \
    struct bgt60utr13d_reg_pll__4* : bgt60utr13d_pack_pll__4,  \
    struct bgt60utr13d_reg_pll__5* : bgt60utr13d_pack_pll__5,  \
    struct bgt60utr13d_reg_pll__6* : bgt60utr13d_pack_pll__6,  \
    struct bgt60utr13d_reg_pll__7* : bgt60utr13d_pack_pll__7  \
  )(_struct_ptr_)

/**
 * @brief Unpack a register's binary representation into seperate fields
 * @note This is a generic macro that picks the correct function based on _struct_ptr_'s type.
 * @param _struct_ptr_ buffer to store the unpacked fields
 * @param _val_ packed register representation
 */
#define BGT60UTR13D_UNPACK(_struct_ptr_, _val_) _Generic((_struct_ptr_), \
    struct bgt60utr13d_reg_main* : bgt60utr13d_unpack_main,  \
    struct bgt60utr13d_reg_adc0* : bgt60utr13d_unpack_adc0,  \
    struct bgt60utr13d_reg_chip_version* : bgt60utr13d_unpack_chip_version,  \
    struct bgt60utr13d_reg_stat1* : bgt60utr13d_unpack_stat1,  \
    struct bgt60utr13d_reg_pacr1* : bgt60utr13d_unpack_pacr1,  \
    struct bgt60utr13d_reg_pacr2* : bgt60utr13d_unpack_pacr2,  \
    struct bgt60utr13d_reg_sfctl* : bgt60utr13d_unpack_sfctl,  \
    struct bgt60utr13d_reg_sadc_ctrl* : bgt60utr13d_unpack_sadc_ctrl,  \
    struct bgt60utr13d_reg_ccr0* : bgt60utr13d_unpack_ccr0,  \
    struct bgt60utr13d_reg_ccr1* : bgt60utr13d_unpack_ccr1,  \
    struct bgt60utr13d_reg_ccr2* : bgt60utr13d_unpack_ccr2,  \
    struct bgt60utr13d_reg_ccr3* : bgt60utr13d_unpack_ccr3,  \
    struct bgt60utr13d_reg_rft0* : bgt60utr13d_unpack_rft0,  \
    struct bgt60utr13d_reg_efuse0* : bgt60utr13d_unpack_efuse0,  \
    struct bgt60utr13d_reg_efuse1* : bgt60utr13d_unpack_efuse1,  \
    struct bgt60utr13d_reg_pdft0* : bgt60utr13d_unpack_pdft0,  \
    struct bgt60utr13d_reg_stat0* : bgt60utr13d_unpack_stat0,  \
    struct bgt60utr13d_reg_sadc_result* : bgt60utr13d_unpack_sadc_result,  \
    struct bgt60utr13d_reg_fstat* : bgt60utr13d_unpack_fstat,  \
    struct bgt60utr13d_reg_chip_id0* : bgt60utr13d_unpack_chip_id0,  \
    struct bgt60utr13d_reg_chip_id1* : bgt60utr13d_unpack_chip_id1,  \
    struct bgt60utr13d_reg_clk_in* : bgt60utr13d_unpack_clk_in,  \
    struct bgt60utr13d_reg_cs__0* : bgt60utr13d_unpack_cs__0,  \
    struct bgt60utr13d_reg_cs__1* : bgt60utr13d_unpack_cs__1,  \
    struct bgt60utr13d_reg_cs__2* : bgt60utr13d_unpack_cs__2,  \
    struct bgt60utr13d_reg_csc_* : bgt60utr13d_unpack_csc_,  \
    struct bgt60utr13d_reg_pll__0* : bgt60utr13d_unpack_pll__0,  \
    struct bgt60utr13d_reg_pll__1* : bgt60utr13d_unpack_pll__1,  \
    struct bgt60utr13d_reg_pll__2* : bgt60utr13d_unpack_pll__2,  \
    struct bgt60utr13d_reg_pll__3* : bgt60utr13d_unpack_pll__3,  \
    struct bgt60utr13d_reg_pll__4* : bgt60utr13d_unpack_pll__4,  \
    struct bgt60utr13d_reg_pll__5* : bgt60utr13d_unpack_pll__5,  \
    struct bgt60utr13d_reg_pll__6* : bgt60utr13d_unpack_pll__6,  \
    struct bgt60utr13d_reg_pll__7* : bgt60utr13d_unpack_pll__7  \
  )(_struct_ptr_, _val_)

// clang-format on

/** @} */

/**
 * \defgroup BGT60UTR13D_MAIN_FUNCS MAIN register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'MAIN' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_main(const struct bgt60utr13d_reg_main *r, uint32_t val){
  val = (val & ~0x1U) | (uint32_t) ((r->frame_start & 0x1U) << 0U);
  val = (val & ~0x2U) | (uint32_t) ((r->sw_reset & 0x1U) << 1U);
  val = (val & ~0x4U) | (uint32_t) ((r->fsm_reset & 0x1U) << 2U);
  val = (val & ~0x8U) | (uint32_t) ((r->fifo_rst & 0x1U) << 3U);
  val = (val & ~0xFF0U) | (uint32_t) ((r->tr_twkup & 0xFFU) << 4U);
  val = (val & ~0xF000U) | (uint32_t) ((r->tr_twkup_mul & 0xFU) << 12U);
  val = (val & ~0x10000U) | (uint32_t) ((r->cw_mode & 0x1U) << 16U);
  val = (val & ~0x60000U) | (uint32_t) ((r->sadc_bg_clk_div & 0x3U) << 17U);
  val = (val & ~0x180000U) | (uint32_t) ((r->madc_bg_clk_div & 0x3U) << 19U);
  val = (val & ~0x600000U) | (uint32_t) ((r->load_strenth & 0x3U) << 21U);
  val = (val & ~0x800000U) | (uint32_t) ((r->ldo_mode & 0x1U) << 23U);
 return val;
}

/**
 * @brief Pack the 'MAIN' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_main(const struct bgt60utr13d_reg_main *r){
  return bgt60utr13d_modify_main(r, 0);
}

/**
 * @brief Unpack the 'MAIN' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_main(struct bgt60utr13d_reg_main *r, uint32_t val){
  r->frame_start = (uint8_t) ((val & 0x1U) >> 0U);
  r->sw_reset = (uint8_t) ((val & 0x2U) >> 1U);
  r->fsm_reset = (uint8_t) ((val & 0x4U) >> 2U);
  r->fifo_rst = (uint8_t) ((val & 0x8U) >> 3U);
  r->tr_twkup = (uint8_t) ((val & 0xFF0U) >> 4U);
  r->tr_twkup_mul = (uint8_t) ((val & 0xF000U) >> 12U);
  r->cw_mode = (uint8_t) ((val & 0x10000U) >> 16U);
  r->sadc_bg_clk_div = (uint8_t) ((val & 0x60000U) >> 17U);
  r->madc_bg_clk_div = (uint8_t) ((val & 0x180000U) >> 19U);
  r->load_strenth = (uint8_t) ((val & 0x600000U) >> 21U);
  r->ldo_mode = (uint8_t) ((val & 0x800000U) >> 23U);
}

/**
 * @brief Unpack the 'MAIN' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_main() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_main reg = BGT60UTR13D_UNPACK_MAIN(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_MAIN(_VAL_) { \
  .frame_start = (uint8_t) (((_VAL_) & 0x1U) >> 0U), \
  .sw_reset = (uint8_t) (((_VAL_) & 0x2U) >> 1U), \
  .fsm_reset = (uint8_t) (((_VAL_) & 0x4U) >> 2U), \
  .fifo_rst = (uint8_t) (((_VAL_) & 0x8U) >> 3U), \
  .tr_twkup = (uint8_t) (((_VAL_) & 0xFF0U) >> 4U), \
  .tr_twkup_mul = (uint8_t) (((_VAL_) & 0xF000U) >> 12U), \
  .cw_mode = (uint8_t) (((_VAL_) & 0x10000U) >> 16U), \
  .sadc_bg_clk_div = (uint8_t) (((_VAL_) & 0x60000U) >> 17U), \
  .madc_bg_clk_div = (uint8_t) (((_VAL_) & 0x180000U) >> 19U), \
  .load_strenth = (uint8_t) (((_VAL_) & 0x600000U) >> 21U), \
  .ldo_mode = (uint8_t) (((_VAL_) & 0x800000U) >> 23U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_ADC0_FUNCS ADC0 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'ADC0' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_adc0(const struct bgt60utr13d_reg_adc0 *r, uint32_t val){
  val = (val & ~0x3U) | (uint32_t) ((r->adc_overs_cfg & 0x3U) << 0U);
  val = (val & ~0x1CU) | (uint32_t) ((r->bg_tc_trim & 0x7U) << 2U);
  val = (val & ~0x20U) | (uint32_t) ((r->bg_chop_en & 0x1U) << 5U);
  val = (val & ~0xC0U) | (uint32_t) ((r->stc & 0x3U) << 6U);
  val = (val & ~0x100U) | (uint32_t) ((r->dscal & 0x1U) << 8U);
  val = (val & ~0x600U) | (uint32_t) ((r->track_cfg & 0x3U) << 9U);
  val = (val & ~0x800U) | (uint32_t) ((r->msb_ctrl & 0x1U) << 11U);
  val = (val & ~0x1000U) | (uint32_t) ((r->trig_madc & 0x1U) << 12U);
  val = (val & ~0x2000U) | (uint32_t) ((r->rsvd & 0x1U) << 13U);
  val = (val & ~0xFFC000U) | (uint32_t) ((r->adc_div & 0x3FFU) << 14U);
 return val;
}

/**
 * @brief Pack the 'ADC0' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_adc0(const struct bgt60utr13d_reg_adc0 *r){
  return bgt60utr13d_modify_adc0(r, 0);
}

/**
 * @brief Unpack the 'ADC0' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_adc0(struct bgt60utr13d_reg_adc0 *r, uint32_t val){
  r->adc_overs_cfg = (uint8_t) ((val & 0x3U) >> 0U);
  r->bg_tc_trim = (uint8_t) ((val & 0x1CU) >> 2U);
  r->bg_chop_en = (uint8_t) ((val & 0x20U) >> 5U);
  r->stc = (uint8_t) ((val & 0xC0U) >> 6U);
  r->dscal = (uint8_t) ((val & 0x100U) >> 8U);
  r->track_cfg = (uint8_t) ((val & 0x600U) >> 9U);
  r->msb_ctrl = (uint8_t) ((val & 0x800U) >> 11U);
  r->trig_madc = (uint8_t) ((val & 0x1000U) >> 12U);
  r->rsvd = (uint8_t) ((val & 0x2000U) >> 13U);
  r->adc_div = (uint16_t) ((val & 0xFFC000U) >> 14U);
}

/**
 * @brief Unpack the 'ADC0' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_adc0() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_adc0 reg = BGT60UTR13D_UNPACK_ADC0(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_ADC0(_VAL_) { \
  .adc_overs_cfg = (uint8_t) (((_VAL_) & 0x3U) >> 0U), \
  .bg_tc_trim = (uint8_t) (((_VAL_) & 0x1CU) >> 2U), \
  .bg_chop_en = (uint8_t) (((_VAL_) & 0x20U) >> 5U), \
  .stc = (uint8_t) (((_VAL_) & 0xC0U) >> 6U), \
  .dscal = (uint8_t) (((_VAL_) & 0x100U) >> 8U), \
  .track_cfg = (uint8_t) (((_VAL_) & 0x600U) >> 9U), \
  .msb_ctrl = (uint8_t) (((_VAL_) & 0x800U) >> 11U), \
  .trig_madc = (uint8_t) (((_VAL_) & 0x1000U) >> 12U), \
  .rsvd = (uint8_t) (((_VAL_) & 0x2000U) >> 13U), \
  .adc_div = (uint16_t) (((_VAL_) & 0xFFC000U) >> 14U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CHIP_VERSION_FUNCS CHIP_VERSION register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CHIP_VERSION' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_chip_version(const struct bgt60utr13d_reg_chip_version *r, uint32_t val){
  val = (val & ~0xFFU) | (uint32_t) ((r->rf_id & 0xFFU) << 0U);
  val = (val & ~0xFF00U) | (uint32_t) ((r->digital_id & 0xFFU) << 8U);
  val = (val & ~0xFF0000U) | (uint32_t) ((r->rsvd & 0xFFU) << 16U);
 return val;
}

/**
 * @brief Pack the 'CHIP_VERSION' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_chip_version(const struct bgt60utr13d_reg_chip_version *r){
  return bgt60utr13d_modify_chip_version(r, 0);
}

/**
 * @brief Unpack the 'CHIP_VERSION' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_chip_version(struct bgt60utr13d_reg_chip_version *r, uint32_t val){
  r->rf_id = (uint8_t) ((val & 0xFFU) >> 0U);
  r->digital_id = (uint8_t) ((val & 0xFF00U) >> 8U);
  r->rsvd = (uint8_t) ((val & 0xFF0000U) >> 16U);
}

/**
 * @brief Unpack the 'CHIP_VERSION' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_chip_version() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_chip_version reg = BGT60UTR13D_UNPACK_CHIP_VERSION(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CHIP_VERSION(_VAL_) { \
  .rf_id = (uint8_t) (((_VAL_) & 0xFFU) >> 0U), \
  .digital_id = (uint8_t) (((_VAL_) & 0xFF00U) >> 8U), \
  .rsvd = (uint8_t) (((_VAL_) & 0xFF0000U) >> 16U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_STAT1_FUNCS STAT1 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'STAT1' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_stat1(const struct bgt60utr13d_reg_stat1 *r, uint32_t val){
  val = (val & ~0xFFFU) | (uint32_t) ((r->shape_grp_cnt & 0xFFFU) << 0U);
  val = (val & ~0xFFF000U) | (uint32_t) ((r->frame_cnt & 0xFFFU) << 12U);
 return val;
}

/**
 * @brief Pack the 'STAT1' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_stat1(const struct bgt60utr13d_reg_stat1 *r){
  return bgt60utr13d_modify_stat1(r, 0);
}

/**
 * @brief Unpack the 'STAT1' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_stat1(struct bgt60utr13d_reg_stat1 *r, uint32_t val){
  r->shape_grp_cnt = (uint16_t) ((val & 0xFFFU) >> 0U);
  r->frame_cnt = (uint16_t) ((val & 0xFFF000U) >> 12U);
}

/**
 * @brief Unpack the 'STAT1' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_stat1() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_stat1 reg = BGT60UTR13D_UNPACK_STAT1(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_STAT1(_VAL_) { \
  .shape_grp_cnt = (uint16_t) (((_VAL_) & 0xFFFU) >> 0U), \
  .frame_cnt = (uint16_t) (((_VAL_) & 0xFFF000U) >> 12U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_PACR1_FUNCS PACR1 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'PACR1' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_pacr1(const struct bgt60utr13d_reg_pacr1 *r, uint32_t val){
  val = (val & ~0x1U) | (uint32_t) ((r->anapon & 0x1U) << 0U);
  val = (val & ~0x6U) | (uint32_t) ((r->vanareg & 0x3U) << 1U);
  val = (val & ~0x8U) | (uint32_t) ((r->digpon & 0x1U) << 3U);
  val = (val & ~0x30U) | (uint32_t) ((r->vdigreg & 0x3U) << 4U);
  val = (val & ~0x40U) | (uint32_t) ((r->bgapen & 0x1U) << 6U);
  val = (val & ~0x80U) | (uint32_t) ((r->u2ien & 0x1U) << 7U);
  val = (val & ~0x300U) | (uint32_t) ((r->vrefsel & 0x3U) << 8U);
  val = (val & ~0x400U) | (uint32_t) ((r->rfiltsel & 0x1U) << 10U);
  val = (val & ~0x800U) | (uint32_t) ((r->rlfsel & 0x1U) << 11U);
  val = (val & ~0xE000U) | (uint32_t) ((r->locksel & 0x7U) << 13U);
  val = (val & ~0x10000U) | (uint32_t) ((r->lockforc & 0x1U) << 16U);
  val = (val & ~0xE0000U) | (uint32_t) ((r->icpsel & 0x7U) << 17U);
  val = (val & ~0x100000U) | (uint32_t) ((r->biasforc & 0x1U) << 20U);
  val = (val & ~0x200000U) | (uint32_t) ((r->cpen & 0x1U) << 21U);
  val = (val & ~0x400000U) | (uint32_t) ((r->lfen & 0x1U) << 22U);
  val = (val & ~0x800000U) | (uint32_t) ((r->oscclken & 0x1U) << 23U);
 return val;
}

/**
 * @brief Pack the 'PACR1' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_pacr1(const struct bgt60utr13d_reg_pacr1 *r){
  return bgt60utr13d_modify_pacr1(r, 0);
}

/**
 * @brief Unpack the 'PACR1' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_pacr1(struct bgt60utr13d_reg_pacr1 *r, uint32_t val){
  r->anapon = (uint8_t) ((val & 0x1U) >> 0U);
  r->vanareg = (uint8_t) ((val & 0x6U) >> 1U);
  r->digpon = (uint8_t) ((val & 0x8U) >> 3U);
  r->vdigreg = (uint8_t) ((val & 0x30U) >> 4U);
  r->bgapen = (uint8_t) ((val & 0x40U) >> 6U);
  r->u2ien = (uint8_t) ((val & 0x80U) >> 7U);
  r->vrefsel = (uint8_t) ((val & 0x300U) >> 8U);
  r->rfiltsel = (uint8_t) ((val & 0x400U) >> 10U);
  r->rlfsel = (uint8_t) ((val & 0x800U) >> 11U);
  r->locksel = (uint8_t) ((val & 0xE000U) >> 13U);
  r->lockforc = (uint8_t) ((val & 0x10000U) >> 16U);
  r->icpsel = (uint8_t) ((val & 0xE0000U) >> 17U);
  r->biasforc = (uint8_t) ((val & 0x100000U) >> 20U);
  r->cpen = (uint8_t) ((val & 0x200000U) >> 21U);
  r->lfen = (uint8_t) ((val & 0x400000U) >> 22U);
  r->oscclken = (uint8_t) ((val & 0x800000U) >> 23U);
}

/**
 * @brief Unpack the 'PACR1' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_pacr1() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_pacr1 reg = BGT60UTR13D_UNPACK_PACR1(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_PACR1(_VAL_) { \
  .anapon = (uint8_t) (((_VAL_) & 0x1U) >> 0U), \
  .vanareg = (uint8_t) (((_VAL_) & 0x6U) >> 1U), \
  .digpon = (uint8_t) (((_VAL_) & 0x8U) >> 3U), \
  .vdigreg = (uint8_t) (((_VAL_) & 0x30U) >> 4U), \
  .bgapen = (uint8_t) (((_VAL_) & 0x40U) >> 6U), \
  .u2ien = (uint8_t) (((_VAL_) & 0x80U) >> 7U), \
  .vrefsel = (uint8_t) (((_VAL_) & 0x300U) >> 8U), \
  .rfiltsel = (uint8_t) (((_VAL_) & 0x400U) >> 10U), \
  .rlfsel = (uint8_t) (((_VAL_) & 0x800U) >> 11U), \
  .locksel = (uint8_t) (((_VAL_) & 0xE000U) >> 13U), \
  .lockforc = (uint8_t) (((_VAL_) & 0x10000U) >> 16U), \
  .icpsel = (uint8_t) (((_VAL_) & 0xE0000U) >> 17U), \
  .biasforc = (uint8_t) (((_VAL_) & 0x100000U) >> 20U), \
  .cpen = (uint8_t) (((_VAL_) & 0x200000U) >> 21U), \
  .lfen = (uint8_t) (((_VAL_) & 0x400000U) >> 22U), \
  .oscclken = (uint8_t) (((_VAL_) & 0x800000U) >> 23U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_PACR2_FUNCS PACR2 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'PACR2' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_pacr2(const struct bgt60utr13d_reg_pacr2 *r, uint32_t val){
  val = (val & ~0x1FU) | (uint32_t) ((r->divset & 0x1FU) << 0U);
  val = (val & ~0x20U) | (uint32_t) ((r->diven & 0x1U) << 5U);
  val = (val & ~0xC0U) | (uint32_t) ((r->fstdnen & 0x3U) << 6U);
  val = (val & ~0x1FF00U) | (uint32_t) ((r->fsdntmr & 0x1FFU) << 8U);
  val = (val & ~0x20000U) | (uint32_t) ((r->trivreg & 0x1U) << 17U);
  val = (val & ~0xC0000U) | (uint32_t) ((r->dtsel & 0x3U) << 18U);
  val = (val & ~0x100000U) | (uint32_t) ((r->rsvd & 0x1U) << 20U);
  val = (val & ~0xE00000U) | (uint32_t) ((r->tr_diven & 0x7U) << 21U);
 return val;
}

/**
 * @brief Pack the 'PACR2' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_pacr2(const struct bgt60utr13d_reg_pacr2 *r){
  return bgt60utr13d_modify_pacr2(r, 0);
}

/**
 * @brief Unpack the 'PACR2' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_pacr2(struct bgt60utr13d_reg_pacr2 *r, uint32_t val){
  r->divset = (uint8_t) ((val & 0x1FU) >> 0U);
  r->diven = (uint8_t) ((val & 0x20U) >> 5U);
  r->fstdnen = (uint8_t) ((val & 0xC0U) >> 6U);
  r->fsdntmr = (uint16_t) ((val & 0x1FF00U) >> 8U);
  r->trivreg = (uint8_t) ((val & 0x20000U) >> 17U);
  r->dtsel = (uint8_t) ((val & 0xC0000U) >> 18U);
  r->rsvd = (uint8_t) ((val & 0x100000U) >> 20U);
  r->tr_diven = (uint8_t) ((val & 0xE00000U) >> 21U);
}

/**
 * @brief Unpack the 'PACR2' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_pacr2() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_pacr2 reg = BGT60UTR13D_UNPACK_PACR2(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_PACR2(_VAL_) { \
  .divset = (uint8_t) (((_VAL_) & 0x1FU) >> 0U), \
  .diven = (uint8_t) (((_VAL_) & 0x20U) >> 5U), \
  .fstdnen = (uint8_t) (((_VAL_) & 0xC0U) >> 6U), \
  .fsdntmr = (uint16_t) (((_VAL_) & 0x1FF00U) >> 8U), \
  .trivreg = (uint8_t) (((_VAL_) & 0x20000U) >> 17U), \
  .dtsel = (uint8_t) (((_VAL_) & 0xC0000U) >> 18U), \
  .rsvd = (uint8_t) (((_VAL_) & 0x100000U) >> 20U), \
  .tr_diven = (uint8_t) (((_VAL_) & 0xE00000U) >> 21U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_SFCTL_FUNCS SFCTL register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'SFCTL' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_sfctl(const struct bgt60utr13d_reg_sfctl *r, uint32_t val){
  val = (val & ~0x1FFFU) | (uint32_t) ((r->fifo_cref & 0x1FFFU) << 0U);
  val = (val & ~0xC000U) | (uint32_t) ((r->fifo_pd_mode & 0x3U) << 14U);
  val = (val & ~0x10000U) | (uint32_t) ((r->miso_hs_read & 0x1U) << 16U);
  val = (val & ~0x20000U) | (uint32_t) ((r->lfsr_en & 0x1U) << 17U);
  val = (val & ~0x40000U) | (uint32_t) ((r->prefix_en & 0x1U) << 18U);
  val = (val & ~0x80000U) | (uint32_t) ((r->pad_mode & 0x1U) << 19U);
 return val;
}

/**
 * @brief Pack the 'SFCTL' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_sfctl(const struct bgt60utr13d_reg_sfctl *r){
  return bgt60utr13d_modify_sfctl(r, 0);
}

/**
 * @brief Unpack the 'SFCTL' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_sfctl(struct bgt60utr13d_reg_sfctl *r, uint32_t val){
  r->fifo_cref = (uint16_t) ((val & 0x1FFFU) >> 0U);
  r->fifo_pd_mode = (uint8_t) ((val & 0xC000U) >> 14U);
  r->miso_hs_read = (uint8_t) ((val & 0x10000U) >> 16U);
  r->lfsr_en = (uint8_t) ((val & 0x20000U) >> 17U);
  r->prefix_en = (uint8_t) ((val & 0x40000U) >> 18U);
  r->pad_mode = (uint8_t) ((val & 0x80000U) >> 19U);
}

/**
 * @brief Unpack the 'SFCTL' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_sfctl() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_sfctl reg = BGT60UTR13D_UNPACK_SFCTL(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_SFCTL(_VAL_) { \
  .fifo_cref = (uint16_t) (((_VAL_) & 0x1FFFU) >> 0U), \
  .fifo_pd_mode = (uint8_t) (((_VAL_) & 0xC000U) >> 14U), \
  .miso_hs_read = (uint8_t) (((_VAL_) & 0x10000U) >> 16U), \
  .lfsr_en = (uint8_t) (((_VAL_) & 0x20000U) >> 17U), \
  .prefix_en = (uint8_t) (((_VAL_) & 0x40000U) >> 18U), \
  .pad_mode = (uint8_t) (((_VAL_) & 0x80000U) >> 19U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_SADC_CTRL_FUNCS SADC_CTRL register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'SADC_CTRL' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_sadc_ctrl(const struct bgt60utr13d_reg_sadc_ctrl *r, uint32_t val){
  val = (val & ~0xFU) | (uint32_t) ((r->sadc_chsel & 0xFU) << 0U);
  val = (val & ~0x10U) | (uint32_t) ((r->start_sadc & 0x1U) << 4U);
  val = (val & ~0xC0U) | (uint32_t) ((r->sadc_clk_div & 0x3U) << 6U);
  val = (val & ~0x100U) | (uint32_t) ((r->sd_en & 0x1U) << 8U);
  val = (val & ~0x600U) | (uint32_t) ((r->overs_cfg & 0x3U) << 9U);
  val = (val & ~0x800U) | (uint32_t) ((r->sesp & 0x1U) << 11U);
  val = (val & ~0x1000U) | (uint32_t) ((r->lvgain & 0x1U) << 12U);
  val = (val & ~0x2000U) | (uint32_t) ((r->dscal & 0x1U) << 13U);
  val = (val & ~0x1C000U) | (uint32_t) ((r->tc_trim & 0x7U) << 14U);
 return val;
}

/**
 * @brief Pack the 'SADC_CTRL' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_sadc_ctrl(const struct bgt60utr13d_reg_sadc_ctrl *r){
  return bgt60utr13d_modify_sadc_ctrl(r, 0);
}

/**
 * @brief Unpack the 'SADC_CTRL' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_sadc_ctrl(struct bgt60utr13d_reg_sadc_ctrl *r, uint32_t val){
  r->sadc_chsel = (enum bgt60utr13d_sadc_ctrl_sadc_chsel) ((val & 0xFU) >> 0U);
  r->start_sadc = (uint8_t) ((val & 0x10U) >> 4U);
  r->sadc_clk_div = (enum bgt60utr13d_sadc_ctrl_sadc_clk_div) ((val & 0xC0U) >> 6U);
  r->sd_en = (uint8_t) ((val & 0x100U) >> 8U);
  r->overs_cfg = (uint8_t) ((val & 0x600U) >> 9U);
  r->sesp = (uint8_t) ((val & 0x800U) >> 11U);
  r->lvgain = (uint8_t) ((val & 0x1000U) >> 12U);
  r->dscal = (uint8_t) ((val & 0x2000U) >> 13U);
  r->tc_trim = (uint8_t) ((val & 0x1C000U) >> 14U);
}

/**
 * @brief Unpack the 'SADC_CTRL' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_sadc_ctrl() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_sadc_ctrl reg = BGT60UTR13D_UNPACK_SADC_CTRL(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_SADC_CTRL(_VAL_) { \
  .sadc_chsel = (enum bgt60utr13d_sadc_ctrl_sadc_chsel) (((_VAL_) & 0xFU) >> 0U), \
  .start_sadc = (uint8_t) (((_VAL_) & 0x10U) >> 4U), \
  .sadc_clk_div = (enum bgt60utr13d_sadc_ctrl_sadc_clk_div) (((_VAL_) & 0xC0U) >> 6U), \
  .sd_en = (uint8_t) (((_VAL_) & 0x100U) >> 8U), \
  .overs_cfg = (uint8_t) (((_VAL_) & 0x600U) >> 9U), \
  .sesp = (uint8_t) (((_VAL_) & 0x800U) >> 11U), \
  .lvgain = (uint8_t) (((_VAL_) & 0x1000U) >> 12U), \
  .dscal = (uint8_t) (((_VAL_) & 0x2000U) >> 13U), \
  .tc_trim = (uint8_t) (((_VAL_) & 0x1C000U) >> 14U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CCR0_FUNCS CCR0 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CCR0' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_ccr0(const struct bgt60utr13d_reg_ccr0 *r, uint32_t val){
  val = (val & ~0x1FFU) | (uint32_t) ((r->tr_end & 0x1FFU) << 0U);
  val = (val & ~0x200U) | (uint32_t) ((r->cont_mode & 0x1U) << 9U);
  val = (val & ~0x3C00U) | (uint32_t) ((r->rept & 0xFU) << 10U);
  val = (val & ~0x3FC000U) | (uint32_t) ((r->tr_init1 & 0xFFU) << 14U);
  val = (val & ~0xC00000U) | (uint32_t) ((r->tr_init1_mul & 0x3U) << 22U);
 return val;
}

/**
 * @brief Pack the 'CCR0' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_ccr0(const struct bgt60utr13d_reg_ccr0 *r){
  return bgt60utr13d_modify_ccr0(r, 0);
}

/**
 * @brief Unpack the 'CCR0' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_ccr0(struct bgt60utr13d_reg_ccr0 *r, uint32_t val){
  r->tr_end = (uint16_t) ((val & 0x1FFU) >> 0U);
  r->cont_mode = (uint8_t) ((val & 0x200U) >> 9U);
  r->rept = (uint8_t) ((val & 0x3C00U) >> 10U);
  r->tr_init1 = (uint8_t) ((val & 0x3FC000U) >> 14U);
  r->tr_init1_mul = (uint8_t) ((val & 0xC00000U) >> 22U);
}

/**
 * @brief Unpack the 'CCR0' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_ccr0() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_ccr0 reg = BGT60UTR13D_UNPACK_CCR0(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CCR0(_VAL_) { \
  .tr_end = (uint16_t) (((_VAL_) & 0x1FFU) >> 0U), \
  .cont_mode = (uint8_t) (((_VAL_) & 0x200U) >> 9U), \
  .rept = (uint8_t) (((_VAL_) & 0x3C00U) >> 10U), \
  .tr_init1 = (uint8_t) (((_VAL_) & 0x3FC000U) >> 14U), \
  .tr_init1_mul = (uint8_t) (((_VAL_) & 0xC00000U) >> 22U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CCR1_FUNCS CCR1 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CCR1' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_ccr1(const struct bgt60utr13d_reg_ccr1 *r, uint32_t val){
  val = (val & ~0x1FFU) | (uint32_t) ((r->tr_start & 0x1FFU) << 0U);
  val = (val & ~0x600U) | (uint32_t) ((r->pd_mode & 0x3U) << 9U);
  val = (val & ~0x7F800U) | (uint32_t) ((r->tr_fed & 0xFFU) << 11U);
  val = (val & ~0xF80000U) | (uint32_t) ((r->tr_fed_mul & 0x1FU) << 19U);
 return val;
}

/**
 * @brief Pack the 'CCR1' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_ccr1(const struct bgt60utr13d_reg_ccr1 *r){
  return bgt60utr13d_modify_ccr1(r, 0);
}

/**
 * @brief Unpack the 'CCR1' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_ccr1(struct bgt60utr13d_reg_ccr1 *r, uint32_t val){
  r->tr_start = (uint16_t) ((val & 0x1FFU) >> 0U);
  r->pd_mode = (enum bgt60utr13d_ccr1_pd_mode) ((val & 0x600U) >> 9U);
  r->tr_fed = (uint8_t) ((val & 0x7F800U) >> 11U);
  r->tr_fed_mul = (uint8_t) ((val & 0xF80000U) >> 19U);
}

/**
 * @brief Unpack the 'CCR1' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_ccr1() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_ccr1 reg = BGT60UTR13D_UNPACK_CCR1(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CCR1(_VAL_) { \
  .tr_start = (uint16_t) (((_VAL_) & 0x1FFU) >> 0U), \
  .pd_mode = (enum bgt60utr13d_ccr1_pd_mode) (((_VAL_) & 0x600U) >> 9U), \
  .tr_fed = (uint8_t) (((_VAL_) & 0x7F800U) >> 11U), \
  .tr_fed_mul = (uint8_t) (((_VAL_) & 0xF80000U) >> 19U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CCR2_FUNCS CCR2 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CCR2' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_ccr2(const struct bgt60utr13d_reg_ccr2 *r, uint32_t val){
  val = (val & ~0xFFFU) | (uint32_t) ((r->max_frame_cnt & 0xFFFU) << 0U);
  val = (val & ~0xFFF000U) | (uint32_t) ((r->frame_len & 0xFFFU) << 12U);
 return val;
}

/**
 * @brief Pack the 'CCR2' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_ccr2(const struct bgt60utr13d_reg_ccr2 *r){
  return bgt60utr13d_modify_ccr2(r, 0);
}

/**
 * @brief Unpack the 'CCR2' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_ccr2(struct bgt60utr13d_reg_ccr2 *r, uint32_t val){
  r->max_frame_cnt = (uint16_t) ((val & 0xFFFU) >> 0U);
  r->frame_len = (uint16_t) ((val & 0xFFF000U) >> 12U);
}

/**
 * @brief Unpack the 'CCR2' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_ccr2() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_ccr2 reg = BGT60UTR13D_UNPACK_CCR2(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CCR2(_VAL_) { \
  .max_frame_cnt = (uint16_t) (((_VAL_) & 0xFFFU) >> 0U), \
  .frame_len = (uint16_t) (((_VAL_) & 0xFFF000U) >> 12U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CCR3_FUNCS CCR3 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CCR3' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_ccr3(const struct bgt60utr13d_reg_ccr3 *r, uint32_t val){
  val = (val & ~0x1FFU) | (uint32_t) ((r->tr_paen & 0x1FFU) << 0U);
  val = (val & ~0x3E00U) | (uint32_t) ((r->tr_sstart & 0x1FU) << 9U);
  val = (val & ~0x3FC000U) | (uint32_t) ((r->tr_init0 & 0xFFU) << 14U);
  val = (val & ~0xC00000U) | (uint32_t) ((r->tr_init0_mul & 0x3U) << 22U);
 return val;
}

/**
 * @brief Pack the 'CCR3' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_ccr3(const struct bgt60utr13d_reg_ccr3 *r){
  return bgt60utr13d_modify_ccr3(r, 0);
}

/**
 * @brief Unpack the 'CCR3' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_ccr3(struct bgt60utr13d_reg_ccr3 *r, uint32_t val){
  r->tr_paen = (uint16_t) ((val & 0x1FFU) >> 0U);
  r->tr_sstart = (uint8_t) ((val & 0x3E00U) >> 9U);
  r->tr_init0 = (uint8_t) ((val & 0x3FC000U) >> 14U);
  r->tr_init0_mul = (uint8_t) ((val & 0xC00000U) >> 22U);
}

/**
 * @brief Unpack the 'CCR3' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_ccr3() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_ccr3 reg = BGT60UTR13D_UNPACK_CCR3(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CCR3(_VAL_) { \
  .tr_paen = (uint16_t) (((_VAL_) & 0x1FFU) >> 0U), \
  .tr_sstart = (uint8_t) (((_VAL_) & 0x3E00U) >> 9U), \
  .tr_init0 = (uint8_t) (((_VAL_) & 0x3FC000U) >> 14U), \
  .tr_init0_mul = (uint8_t) (((_VAL_) & 0xC00000U) >> 22U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_RFT0_FUNCS RFT0 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'RFT0' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_rft0(const struct bgt60utr13d_reg_rft0 *r, uint32_t val){
  val = (val & ~0x1FFFU) | (uint32_t) ((r->rftsigclk_div & 0x1FFFU) << 0U);
  val = (val & ~0x2000U) | (uint32_t) ((r->rftsigclk_div_en & 0x1U) << 13U);
  val = (val & ~0x4000U) | (uint32_t) ((r->test_sig_rf1_en & 0x1U) << 14U);
  val = (val & ~0x40000U) | (uint32_t) ((r->test_sig_if1_en & 0x1U) << 18U);
  val = (val & ~0x80000U) | (uint32_t) ((r->test_sig_if2_en & 0x1U) << 19U);
  val = (val & ~0x100000U) | (uint32_t) ((r->test_sig_if3_en & 0x1U) << 20U);
  val = (val & ~0xC00000U) | (uint32_t) ((r->rf_test_mode & 0x3U) << 22U);
 return val;
}

/**
 * @brief Pack the 'RFT0' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_rft0(const struct bgt60utr13d_reg_rft0 *r){
  return bgt60utr13d_modify_rft0(r, 0);
}

/**
 * @brief Unpack the 'RFT0' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_rft0(struct bgt60utr13d_reg_rft0 *r, uint32_t val){
  r->rftsigclk_div = (uint16_t) ((val & 0x1FFFU) >> 0U);
  r->rftsigclk_div_en = (uint8_t) ((val & 0x2000U) >> 13U);
  r->test_sig_rf1_en = (uint8_t) ((val & 0x4000U) >> 14U);
  r->test_sig_if1_en = (uint8_t) ((val & 0x40000U) >> 18U);
  r->test_sig_if2_en = (uint8_t) ((val & 0x80000U) >> 19U);
  r->test_sig_if3_en = (uint8_t) ((val & 0x100000U) >> 20U);
  r->rf_test_mode = (uint8_t) ((val & 0xC00000U) >> 22U);
}

/**
 * @brief Unpack the 'RFT0' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_rft0() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_rft0 reg = BGT60UTR13D_UNPACK_RFT0(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_RFT0(_VAL_) { \
  .rftsigclk_div = (uint16_t) (((_VAL_) & 0x1FFFU) >> 0U), \
  .rftsigclk_div_en = (uint8_t) (((_VAL_) & 0x2000U) >> 13U), \
  .test_sig_rf1_en = (uint8_t) (((_VAL_) & 0x4000U) >> 14U), \
  .test_sig_if1_en = (uint8_t) (((_VAL_) & 0x40000U) >> 18U), \
  .test_sig_if2_en = (uint8_t) (((_VAL_) & 0x80000U) >> 19U), \
  .test_sig_if3_en = (uint8_t) (((_VAL_) & 0x100000U) >> 20U), \
  .rf_test_mode = (uint8_t) (((_VAL_) & 0xC00000U) >> 22U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_EFUSE0_FUNCS EFUSE0 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'EFUSE0' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_efuse0(const struct bgt60utr13d_reg_efuse0 *r, uint32_t val){
  val = (val & ~0x10U) | (uint32_t) ((r->efuse_en & 0x1U) << 4U);
  val = (val & ~0x4000U) | (uint32_t) ((r->efuse_sense & 0x1U) << 14U);
 return val;
}

/**
 * @brief Pack the 'EFUSE0' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_efuse0(const struct bgt60utr13d_reg_efuse0 *r){
  return bgt60utr13d_modify_efuse0(r, 0);
}

/**
 * @brief Unpack the 'EFUSE0' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_efuse0(struct bgt60utr13d_reg_efuse0 *r, uint32_t val){
  r->efuse_en = (uint8_t) ((val & 0x10U) >> 4U);
  r->efuse_sense = (uint8_t) ((val & 0x4000U) >> 14U);
}

/**
 * @brief Unpack the 'EFUSE0' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_efuse0() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_efuse0 reg = BGT60UTR13D_UNPACK_EFUSE0(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_EFUSE0(_VAL_) { \
  .efuse_en = (uint8_t) (((_VAL_) & 0x10U) >> 4U), \
  .efuse_sense = (uint8_t) (((_VAL_) & 0x4000U) >> 14U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_EFUSE1_FUNCS EFUSE1 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'EFUSE1' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_efuse1(const struct bgt60utr13d_reg_efuse1 *r, uint32_t val){
  val = (val & ~0x200U) | (uint32_t) ((r->efuse_ready & 0x1U) << 9U);
 return val;
}

/**
 * @brief Pack the 'EFUSE1' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_efuse1(const struct bgt60utr13d_reg_efuse1 *r){
  return bgt60utr13d_modify_efuse1(r, 0);
}

/**
 * @brief Unpack the 'EFUSE1' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_efuse1(struct bgt60utr13d_reg_efuse1 *r, uint32_t val){
  r->efuse_ready = (uint8_t) ((val & 0x200U) >> 9U);
}

/**
 * @brief Unpack the 'EFUSE1' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_efuse1() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_efuse1 reg = BGT60UTR13D_UNPACK_EFUSE1(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_EFUSE1(_VAL_) { \
  .efuse_ready = (uint8_t) (((_VAL_) & 0x200U) >> 9U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_PDFT0_FUNCS PDFT0 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'PDFT0' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_pdft0(const struct bgt60utr13d_reg_pdft0 *r, uint32_t val){
  val = (val & ~0x1U) | (uint32_t) ((r->byprmpen & 0x1U) << 0U);
  val = (val & ~0x2U) | (uint32_t) ((r->bypsdmen & 0x1U) << 1U);
  val = (val & ~0x3CU) | (uint32_t) ((r->bypsdm & 0xFU) << 2U);
 return val;
}

/**
 * @brief Pack the 'PDFT0' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_pdft0(const struct bgt60utr13d_reg_pdft0 *r){
  return bgt60utr13d_modify_pdft0(r, 0);
}

/**
 * @brief Unpack the 'PDFT0' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_pdft0(struct bgt60utr13d_reg_pdft0 *r, uint32_t val){
  r->byprmpen = (uint8_t) ((val & 0x1U) >> 0U);
  r->bypsdmen = (uint8_t) ((val & 0x2U) >> 1U);
  r->bypsdm = (uint8_t) ((val & 0x3CU) >> 2U);
}

/**
 * @brief Unpack the 'PDFT0' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_pdft0() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_pdft0 reg = BGT60UTR13D_UNPACK_PDFT0(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_PDFT0(_VAL_) { \
  .byprmpen = (uint8_t) (((_VAL_) & 0x1U) >> 0U), \
  .bypsdmen = (uint8_t) (((_VAL_) & 0x2U) >> 1U), \
  .bypsdm = (uint8_t) (((_VAL_) & 0x3CU) >> 2U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_STAT0_FUNCS STAT0 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'STAT0' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_stat0(const struct bgt60utr13d_reg_stat0 *r, uint32_t val){
  val = (val & ~0x1U) | (uint32_t) ((r->sadc_rdy & 0x1U) << 0U);
  val = (val & ~0x2U) | (uint32_t) ((r->madc_rdy & 0x1U) << 1U);
  val = (val & ~0x4U) | (uint32_t) ((r->madc_bgup & 0x1U) << 2U);
  val = (val & ~0x8U) | (uint32_t) ((r->ldo_rdy & 0x1U) << 3U);
  val = (val & ~0xE0U) | (uint32_t) ((r->pm & 0x7U) << 5U);
  val = (val & ~0x700U) | (uint32_t) ((r->ch_idx & 0x7U) << 8U);
  val = (val & ~0x3800U) | (uint32_t) ((r->sh_idx & 0x7U) << 11U);
 return val;
}

/**
 * @brief Pack the 'STAT0' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_stat0(const struct bgt60utr13d_reg_stat0 *r){
  return bgt60utr13d_modify_stat0(r, 0);
}

/**
 * @brief Unpack the 'STAT0' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_stat0(struct bgt60utr13d_reg_stat0 *r, uint32_t val){
  r->sadc_rdy = (uint8_t) ((val & 0x1U) >> 0U);
  r->madc_rdy = (uint8_t) ((val & 0x2U) >> 1U);
  r->madc_bgup = (uint8_t) ((val & 0x4U) >> 2U);
  r->ldo_rdy = (uint8_t) ((val & 0x8U) >> 3U);
  r->pm = (uint8_t) ((val & 0xE0U) >> 5U);
  r->ch_idx = (uint8_t) ((val & 0x700U) >> 8U);
  r->sh_idx = (uint8_t) ((val & 0x3800U) >> 11U);
}

/**
 * @brief Unpack the 'STAT0' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_stat0() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_stat0 reg = BGT60UTR13D_UNPACK_STAT0(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_STAT0(_VAL_) { \
  .sadc_rdy = (uint8_t) (((_VAL_) & 0x1U) >> 0U), \
  .madc_rdy = (uint8_t) (((_VAL_) & 0x2U) >> 1U), \
  .madc_bgup = (uint8_t) (((_VAL_) & 0x4U) >> 2U), \
  .ldo_rdy = (uint8_t) (((_VAL_) & 0x8U) >> 3U), \
  .pm = (uint8_t) (((_VAL_) & 0xE0U) >> 5U), \
  .ch_idx = (uint8_t) (((_VAL_) & 0x700U) >> 8U), \
  .sh_idx = (uint8_t) (((_VAL_) & 0x3800U) >> 11U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_SADC_RESULT_FUNCS SADC_RESULT register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'SADC_RESULT' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_sadc_result(const struct bgt60utr13d_reg_sadc_result *r, uint32_t val){
  val = (val & ~0x3FFU) | (uint32_t) ((r->sadc_result & 0x3FFU) << 0U);
  val = (val & ~0x400U) | (uint32_t) ((r->sadc_busy & 0x1U) << 10U);
  val = (val & ~0x3FF000U) | (uint32_t) ((r->sadc_raw & 0x3FFU) << 12U);
 return val;
}

/**
 * @brief Pack the 'SADC_RESULT' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_sadc_result(const struct bgt60utr13d_reg_sadc_result *r){
  return bgt60utr13d_modify_sadc_result(r, 0);
}

/**
 * @brief Unpack the 'SADC_RESULT' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_sadc_result(struct bgt60utr13d_reg_sadc_result *r, uint32_t val){
  r->sadc_result = (uint16_t) ((val & 0x3FFU) >> 0U);
  r->sadc_busy = (uint8_t) ((val & 0x400U) >> 10U);
  r->sadc_raw = (uint16_t) ((val & 0x3FF000U) >> 12U);
}

/**
 * @brief Unpack the 'SADC_RESULT' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_sadc_result() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_sadc_result reg = BGT60UTR13D_UNPACK_SADC_RESULT(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_SADC_RESULT(_VAL_) { \
  .sadc_result = (uint16_t) (((_VAL_) & 0x3FFU) >> 0U), \
  .sadc_busy = (uint8_t) (((_VAL_) & 0x400U) >> 10U), \
  .sadc_raw = (uint16_t) (((_VAL_) & 0x3FF000U) >> 12U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_FSTAT_FUNCS FSTAT register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'FSTAT' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_fstat(const struct bgt60utr13d_reg_fstat *r, uint32_t val){
  val = (val & ~0x3FFFU) | (uint32_t) ((r->fill_status & 0x3FFFU) << 0U);
  val = (val & ~0x4000U) | (uint32_t) ((r->ram_pwr_down & 0x1U) << 14U);
  val = (val & ~0x20000U) | (uint32_t) ((r->clk_num_err & 0x1U) << 17U);
  val = (val & ~0x40000U) | (uint32_t) ((r->burst_err & 0x1U) << 18U);
  val = (val & ~0x80000U) | (uint32_t) ((r->fuf_err & 0x1U) << 19U);
  val = (val & ~0x100000U) | (uint32_t) ((r->empty & 0x1U) << 20U);
  val = (val & ~0x200000U) | (uint32_t) ((r->cref & 0x1U) << 21U);
  val = (val & ~0x400000U) | (uint32_t) ((r->full & 0x1U) << 22U);
  val = (val & ~0x800000U) | (uint32_t) ((r->fof_err & 0x1U) << 23U);
 return val;
}

/**
 * @brief Pack the 'FSTAT' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_fstat(const struct bgt60utr13d_reg_fstat *r){
  return bgt60utr13d_modify_fstat(r, 0);
}

/**
 * @brief Unpack the 'FSTAT' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_fstat(struct bgt60utr13d_reg_fstat *r, uint32_t val){
  r->fill_status = (uint16_t) ((val & 0x3FFFU) >> 0U);
  r->ram_pwr_down = (uint8_t) ((val & 0x4000U) >> 14U);
  r->clk_num_err = (uint8_t) ((val & 0x20000U) >> 17U);
  r->burst_err = (uint8_t) ((val & 0x40000U) >> 18U);
  r->fuf_err = (uint8_t) ((val & 0x80000U) >> 19U);
  r->empty = (uint8_t) ((val & 0x100000U) >> 20U);
  r->cref = (uint8_t) ((val & 0x200000U) >> 21U);
  r->full = (uint8_t) ((val & 0x400000U) >> 22U);
  r->fof_err = (uint8_t) ((val & 0x800000U) >> 23U);
}

/**
 * @brief Unpack the 'FSTAT' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_fstat() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_fstat reg = BGT60UTR13D_UNPACK_FSTAT(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_FSTAT(_VAL_) { \
  .fill_status = (uint16_t) (((_VAL_) & 0x3FFFU) >> 0U), \
  .ram_pwr_down = (uint8_t) (((_VAL_) & 0x4000U) >> 14U), \
  .clk_num_err = (uint8_t) (((_VAL_) & 0x20000U) >> 17U), \
  .burst_err = (uint8_t) (((_VAL_) & 0x40000U) >> 18U), \
  .fuf_err = (uint8_t) (((_VAL_) & 0x80000U) >> 19U), \
  .empty = (uint8_t) (((_VAL_) & 0x100000U) >> 20U), \
  .cref = (uint8_t) (((_VAL_) & 0x200000U) >> 21U), \
  .full = (uint8_t) (((_VAL_) & 0x400000U) >> 22U), \
  .fof_err = (uint8_t) (((_VAL_) & 0x800000U) >> 23U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CHIP_ID0_FUNCS CHIP_ID0 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CHIP_ID0' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_chip_id0(const struct bgt60utr13d_reg_chip_id0 *r, uint32_t val){
  val = (val & ~0xFFFFFFU) | (uint32_t) ((r->chip_id & 0xFFFFFFU) << 0U);
 return val;
}

/**
 * @brief Pack the 'CHIP_ID0' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_chip_id0(const struct bgt60utr13d_reg_chip_id0 *r){
  return bgt60utr13d_modify_chip_id0(r, 0);
}

/**
 * @brief Unpack the 'CHIP_ID0' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_chip_id0(struct bgt60utr13d_reg_chip_id0 *r, uint32_t val){
  r->chip_id = (uint32_t) ((val & 0xFFFFFFU) >> 0U);
}

/**
 * @brief Unpack the 'CHIP_ID0' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_chip_id0() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_chip_id0 reg = BGT60UTR13D_UNPACK_CHIP_ID0(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CHIP_ID0(_VAL_) { \
  .chip_id = (uint32_t) (((_VAL_) & 0xFFFFFFU) >> 0U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CHIP_ID1_FUNCS CHIP_ID1 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CHIP_ID1' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_chip_id1(const struct bgt60utr13d_reg_chip_id1 *r, uint32_t val){
  val = (val & ~0xFFFFFFU) | (uint32_t) ((r->chip_id & 0xFFFFFFU) << 0U);
 return val;
}

/**
 * @brief Pack the 'CHIP_ID1' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_chip_id1(const struct bgt60utr13d_reg_chip_id1 *r){
  return bgt60utr13d_modify_chip_id1(r, 0);
}

/**
 * @brief Unpack the 'CHIP_ID1' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_chip_id1(struct bgt60utr13d_reg_chip_id1 *r, uint32_t val){
  r->chip_id = (uint32_t) ((val & 0xFFFFFFU) >> 0U);
}

/**
 * @brief Unpack the 'CHIP_ID1' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_chip_id1() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_chip_id1 reg = BGT60UTR13D_UNPACK_CHIP_ID1(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CHIP_ID1(_VAL_) { \
  .chip_id = (uint32_t) (((_VAL_) & 0xFFFFFFU) >> 0U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CLK_IN_FUNCS CLK_IN register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CLK_IN' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_clk_in(const struct bgt60utr13d_reg_clk_in *r, uint32_t val){
  val = (val & ~0x3U) | (uint32_t) ((r->clk_sel & 0x3U) << 0U);
  val = (val & ~0x7CU) | (uint32_t) ((r->dc_in_adj & 0x1FU) << 2U);
  val = (val & ~0x780U) | (uint32_t) ((r->dc_out_adj & 0xFU) << 7U);
  val = (val & ~0x800U) | (uint32_t) ((r->irq_fd_sel & 0x1U) << 11U);
 return val;
}

/**
 * @brief Pack the 'CLK_IN' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_clk_in(const struct bgt60utr13d_reg_clk_in *r){
  return bgt60utr13d_modify_clk_in(r, 0);
}

/**
 * @brief Unpack the 'CLK_IN' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_clk_in(struct bgt60utr13d_reg_clk_in *r, uint32_t val){
  r->clk_sel = (enum bgt60utr13d_clk_in_clk_sel) ((val & 0x3U) >> 0U);
  r->dc_in_adj = (uint8_t) ((val & 0x7CU) >> 2U);
  r->dc_out_adj = (uint8_t) ((val & 0x780U) >> 7U);
  r->irq_fd_sel = (enum bgt60utr13d_clk_in_irq_fd_sel) ((val & 0x800U) >> 11U);
}

/**
 * @brief Unpack the 'CLK_IN' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_clk_in() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_clk_in reg = BGT60UTR13D_UNPACK_CLK_IN(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CLK_IN(_VAL_) { \
  .clk_sel = (enum bgt60utr13d_clk_in_clk_sel) (((_VAL_) & 0x3U) >> 0U), \
  .dc_in_adj = (uint8_t) (((_VAL_) & 0x7CU) >> 2U), \
  .dc_out_adj = (uint8_t) (((_VAL_) & 0x780U) >> 7U), \
  .irq_fd_sel = (enum bgt60utr13d_clk_in_irq_fd_sel) (((_VAL_) & 0x800U) >> 11U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CS__0_FUNCS CS#_0 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CS#_0' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_cs__0(const struct bgt60utr13d_reg_cs__0 *r, uint32_t val){
  val = (val & ~0x1U) | (uint32_t) ((r->tx1_en & 0x1U) << 0U);
  val = (val & ~0x2U) | (uint32_t) ((r->pd1_en & 0x1U) << 1U);
  val = (val & ~0x10U) | (uint32_t) ((r->vco_en & 0x1U) << 4U);
  val = (val & ~0x20U) | (uint32_t) ((r->temp_meas_en & 0x1U) << 5U);
  val = (val & ~0x40U) | (uint32_t) ((r->fdiv_en & 0x1U) << 6U);
  val = (val & ~0x400U) | (uint32_t) ((r->lo_dist2_en & 0x1U) << 10U);
  val = (val & ~0x800U) | (uint32_t) ((r->lo_dist1_en & 0x1U) << 11U);
  val = (val & ~0x1000U) | (uint32_t) ((r->rx1lobuf_en & 0x1U) << 12U);
  val = (val & ~0x2000U) | (uint32_t) ((r->rx1mix_en & 0x1U) << 13U);
  val = (val & ~0x4000U) | (uint32_t) ((r->rx2lobuf_en & 0x1U) << 14U);
  val = (val & ~0x8000U) | (uint32_t) ((r->rx2mix_en & 0x1U) << 15U);
  val = (val & ~0x10000U) | (uint32_t) ((r->rx3lobuf_en & 0x1U) << 16U);
  val = (val & ~0x20000U) | (uint32_t) ((r->rx3mix_en & 0x1U) << 17U);
  val = (val & ~0x100000U) | (uint32_t) ((r->abb1_aaf_ctrl & 0x1U) << 20U);
  val = (val & ~0x200000U) | (uint32_t) ((r->abb2_aaf_ctrl & 0x1U) << 21U);
  val = (val & ~0x400000U) | (uint32_t) ((r->abb3_aaf_ctrl & 0x1U) << 22U);
 return val;
}

/**
 * @brief Pack the 'CS#_0' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_cs__0(const struct bgt60utr13d_reg_cs__0 *r){
  return bgt60utr13d_modify_cs__0(r, 0);
}

/**
 * @brief Unpack the 'CS#_0' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_cs__0(struct bgt60utr13d_reg_cs__0 *r, uint32_t val){
  r->tx1_en = (uint8_t) ((val & 0x1U) >> 0U);
  r->pd1_en = (uint8_t) ((val & 0x2U) >> 1U);
  r->vco_en = (uint8_t) ((val & 0x10U) >> 4U);
  r->temp_meas_en = (uint8_t) ((val & 0x20U) >> 5U);
  r->fdiv_en = (uint8_t) ((val & 0x40U) >> 6U);
  r->lo_dist2_en = (uint8_t) ((val & 0x400U) >> 10U);
  r->lo_dist1_en = (uint8_t) ((val & 0x800U) >> 11U);
  r->rx1lobuf_en = (uint8_t) ((val & 0x1000U) >> 12U);
  r->rx1mix_en = (uint8_t) ((val & 0x2000U) >> 13U);
  r->rx2lobuf_en = (uint8_t) ((val & 0x4000U) >> 14U);
  r->rx2mix_en = (uint8_t) ((val & 0x8000U) >> 15U);
  r->rx3lobuf_en = (uint8_t) ((val & 0x10000U) >> 16U);
  r->rx3mix_en = (uint8_t) ((val & 0x20000U) >> 17U);
  r->abb1_aaf_ctrl = (enum bgt60utr13d_cs__0_abb1_aaf_ctrl) ((val & 0x100000U) >> 20U);
  r->abb2_aaf_ctrl = (uint8_t) ((val & 0x200000U) >> 21U);
  r->abb3_aaf_ctrl = (uint8_t) ((val & 0x400000U) >> 22U);
}

/**
 * @brief Unpack the 'CS#_0' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_cs__0() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_cs__0 reg = BGT60UTR13D_UNPACK_CS__0(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CS__0(_VAL_) { \
  .tx1_en = (uint8_t) (((_VAL_) & 0x1U) >> 0U), \
  .pd1_en = (uint8_t) (((_VAL_) & 0x2U) >> 1U), \
  .vco_en = (uint8_t) (((_VAL_) & 0x10U) >> 4U), \
  .temp_meas_en = (uint8_t) (((_VAL_) & 0x20U) >> 5U), \
  .fdiv_en = (uint8_t) (((_VAL_) & 0x40U) >> 6U), \
  .lo_dist2_en = (uint8_t) (((_VAL_) & 0x400U) >> 10U), \
  .lo_dist1_en = (uint8_t) (((_VAL_) & 0x800U) >> 11U), \
  .rx1lobuf_en = (uint8_t) (((_VAL_) & 0x1000U) >> 12U), \
  .rx1mix_en = (uint8_t) (((_VAL_) & 0x2000U) >> 13U), \
  .rx2lobuf_en = (uint8_t) (((_VAL_) & 0x4000U) >> 14U), \
  .rx2mix_en = (uint8_t) (((_VAL_) & 0x8000U) >> 15U), \
  .rx3lobuf_en = (uint8_t) (((_VAL_) & 0x10000U) >> 16U), \
  .rx3mix_en = (uint8_t) (((_VAL_) & 0x20000U) >> 17U), \
  .abb1_aaf_ctrl = (enum bgt60utr13d_cs__0_abb1_aaf_ctrl) (((_VAL_) & 0x100000U) >> 20U), \
  .abb2_aaf_ctrl = (uint8_t) (((_VAL_) & 0x200000U) >> 21U), \
  .abb3_aaf_ctrl = (uint8_t) (((_VAL_) & 0x400000U) >> 22U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CS__1_FUNCS CS#_1 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CS#_1' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_cs__1(const struct bgt60utr13d_reg_cs__1 *r, uint32_t val){
  val = (val & ~0x1FU) | (uint32_t) ((r->tx1_dac & 0x1FU) << 0U);
  val = (val & ~0x400U) | (uint32_t) ((r->hp1_gain & 0x1U) << 10U);
  val = (val & ~0x800U) | (uint32_t) ((r->hp2_gain & 0x1U) << 11U);
  val = (val & ~0x1000U) | (uint32_t) ((r->hp3_gain & 0x1U) << 12U);
  val = (val & ~0xFC000U) | (uint32_t) ((r->bb_rstcnt & 0x3FU) << 14U);
  val = (val & ~0x100000U) | (uint32_t) ((r->madc_bbch1_en & 0x1U) << 20U);
  val = (val & ~0x200000U) | (uint32_t) ((r->madc_bbch2_en & 0x1U) << 21U);
  val = (val & ~0x400000U) | (uint32_t) ((r->madc_bbch3_en & 0x1U) << 22U);
 return val;
}

/**
 * @brief Pack the 'CS#_1' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_cs__1(const struct bgt60utr13d_reg_cs__1 *r){
  return bgt60utr13d_modify_cs__1(r, 0);
}

/**
 * @brief Unpack the 'CS#_1' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_cs__1(struct bgt60utr13d_reg_cs__1 *r, uint32_t val){
  r->tx1_dac = (uint8_t) ((val & 0x1FU) >> 0U);
  r->hp1_gain = (enum bgt60utr13d_cs__1_hp1_gain) ((val & 0x400U) >> 10U);
  r->hp2_gain = (uint8_t) ((val & 0x800U) >> 11U);
  r->hp3_gain = (uint8_t) ((val & 0x1000U) >> 12U);
  r->bb_rstcnt = (uint8_t) ((val & 0xFC000U) >> 14U);
  r->madc_bbch1_en = (uint8_t) ((val & 0x100000U) >> 20U);
  r->madc_bbch2_en = (uint8_t) ((val & 0x200000U) >> 21U);
  r->madc_bbch3_en = (uint8_t) ((val & 0x400000U) >> 22U);
}

/**
 * @brief Unpack the 'CS#_1' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_cs__1() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_cs__1 reg = BGT60UTR13D_UNPACK_CS__1(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CS__1(_VAL_) { \
  .tx1_dac = (uint8_t) (((_VAL_) & 0x1FU) >> 0U), \
  .hp1_gain = (enum bgt60utr13d_cs__1_hp1_gain) (((_VAL_) & 0x400U) >> 10U), \
  .hp2_gain = (uint8_t) (((_VAL_) & 0x800U) >> 11U), \
  .hp3_gain = (uint8_t) (((_VAL_) & 0x1000U) >> 12U), \
  .bb_rstcnt = (uint8_t) (((_VAL_) & 0xFC000U) >> 14U), \
  .madc_bbch1_en = (uint8_t) (((_VAL_) & 0x100000U) >> 20U), \
  .madc_bbch2_en = (uint8_t) (((_VAL_) & 0x200000U) >> 21U), \
  .madc_bbch3_en = (uint8_t) (((_VAL_) & 0x400000U) >> 22U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CS__2_FUNCS CS#_2 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CS#_2' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_cs__2(const struct bgt60utr13d_reg_cs__2 *r, uint32_t val){
  val = (val & ~0x7U) | (uint32_t) ((r->hpf_sel1 & 0x7U) << 0U);
  val = (val & ~0x38U) | (uint32_t) ((r->vga_gain1 & 0x7U) << 3U);
  val = (val & ~0x1C0U) | (uint32_t) ((r->hpf_sel2 & 0x7U) << 6U);
  val = (val & ~0xE00U) | (uint32_t) ((r->vga_gain2 & 0x7U) << 9U);
  val = (val & ~0x7000U) | (uint32_t) ((r->hpf_sel3 & 0x7U) << 12U);
  val = (val & ~0x38000U) | (uint32_t) ((r->vga_gain3 & 0x7U) << 15U);
 return val;
}

/**
 * @brief Pack the 'CS#_2' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_cs__2(const struct bgt60utr13d_reg_cs__2 *r){
  return bgt60utr13d_modify_cs__2(r, 0);
}

/**
 * @brief Unpack the 'CS#_2' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_cs__2(struct bgt60utr13d_reg_cs__2 *r, uint32_t val){
  r->hpf_sel1 = (enum bgt60utr13d_cs__2_hpf_sel1) ((val & 0x7U) >> 0U);
  r->vga_gain1 = (enum bgt60utr13d_cs__2_vga_gain1) ((val & 0x38U) >> 3U);
  r->hpf_sel2 = (uint8_t) ((val & 0x1C0U) >> 6U);
  r->vga_gain2 = (uint8_t) ((val & 0xE00U) >> 9U);
  r->hpf_sel3 = (uint8_t) ((val & 0x7000U) >> 12U);
  r->vga_gain3 = (uint8_t) ((val & 0x38000U) >> 15U);
}

/**
 * @brief Unpack the 'CS#_2' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_cs__2() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_cs__2 reg = BGT60UTR13D_UNPACK_CS__2(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CS__2(_VAL_) { \
  .hpf_sel1 = (enum bgt60utr13d_cs__2_hpf_sel1) (((_VAL_) & 0x7U) >> 0U), \
  .vga_gain1 = (enum bgt60utr13d_cs__2_vga_gain1) (((_VAL_) & 0x38U) >> 3U), \
  .hpf_sel2 = (uint8_t) (((_VAL_) & 0x1C0U) >> 6U), \
  .vga_gain2 = (uint8_t) (((_VAL_) & 0xE00U) >> 9U), \
  .hpf_sel3 = (uint8_t) (((_VAL_) & 0x7000U) >> 12U), \
  .vga_gain3 = (uint8_t) (((_VAL_) & 0x38000U) >> 15U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_CSC__FUNCS CSC# register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'CSC#' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_csc_(const struct bgt60utr13d_reg_csc_ *r, uint32_t val){
  val = (val & ~0x10U) | (uint32_t) ((r->repcs & 0x1U) << 4U);
  val = (val & ~0x2U) | (uint32_t) ((r->cs_en & 0x1U) << 1U);
  val = (val & ~0x20U) | (uint32_t) ((r->abb_isopd & 0x1U) << 5U);
  val = (val & ~0x40U) | (uint32_t) ((r->rf_isopd & 0x1U) << 6U);
  val = (val & ~0x80U) | (uint32_t) ((r->madc_bg_en & 0x1U) << 7U);
  val = (val & ~0x100U) | (uint32_t) ((r->madc_isopd & 0x1U) << 8U);
  val = (val & ~0x200U) | (uint32_t) ((r->sadc_isopd & 0x1U) << 9U);
  val = (val & ~0x400U) | (uint32_t) ((r->bg_tmrf_en & 0x1U) << 10U);
  val = (val & ~0x800U) | (uint32_t) ((r->pll_isopd & 0x1U) << 11U);
  val = (val & ~0x3F000U) | (uint32_t) ((r->tr_pll_isopd & 0x3FU) << 12U);
  val = (val & ~0x1C0000U) | (uint32_t) ((r->tr_madcen & 0x7U) << 18U);
  val = (val & ~0xE00000U) | (uint32_t) ((r->tr_bgen & 0x7U) << 21U);
 return val;
}

/**
 * @brief Pack the 'CSC#' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_csc_(const struct bgt60utr13d_reg_csc_ *r){
  return bgt60utr13d_modify_csc_(r, 0);
}

/**
 * @brief Unpack the 'CSC#' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_csc_(struct bgt60utr13d_reg_csc_ *r, uint32_t val){
  r->repcs = (uint8_t) ((val & 0x10U) >> 4U);
  r->cs_en = (uint8_t) ((val & 0x2U) >> 1U);
  r->abb_isopd = (uint8_t) ((val & 0x20U) >> 5U);
  r->rf_isopd = (uint8_t) ((val & 0x40U) >> 6U);
  r->madc_bg_en = (uint8_t) ((val & 0x80U) >> 7U);
  r->madc_isopd = (uint8_t) ((val & 0x100U) >> 8U);
  r->sadc_isopd = (uint8_t) ((val & 0x200U) >> 9U);
  r->bg_tmrf_en = (uint8_t) ((val & 0x400U) >> 10U);
  r->pll_isopd = (uint8_t) ((val & 0x800U) >> 11U);
  r->tr_pll_isopd = (uint8_t) ((val & 0x3F000U) >> 12U);
  r->tr_madcen = (uint8_t) ((val & 0x1C0000U) >> 18U);
  r->tr_bgen = (uint8_t) ((val & 0xE00000U) >> 21U);
}

/**
 * @brief Unpack the 'CSC#' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_csc_() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_csc_ reg = BGT60UTR13D_UNPACK_CSC_(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_CSC_(_VAL_) { \
  .repcs = (uint8_t) (((_VAL_) & 0x10U) >> 4U), \
  .cs_en = (uint8_t) (((_VAL_) & 0x2U) >> 1U), \
  .abb_isopd = (uint8_t) (((_VAL_) & 0x20U) >> 5U), \
  .rf_isopd = (uint8_t) (((_VAL_) & 0x40U) >> 6U), \
  .madc_bg_en = (uint8_t) (((_VAL_) & 0x80U) >> 7U), \
  .madc_isopd = (uint8_t) (((_VAL_) & 0x100U) >> 8U), \
  .sadc_isopd = (uint8_t) (((_VAL_) & 0x200U) >> 9U), \
  .bg_tmrf_en = (uint8_t) (((_VAL_) & 0x400U) >> 10U), \
  .pll_isopd = (uint8_t) (((_VAL_) & 0x800U) >> 11U), \
  .tr_pll_isopd = (uint8_t) (((_VAL_) & 0x3F000U) >> 12U), \
  .tr_madcen = (uint8_t) (((_VAL_) & 0x1C0000U) >> 18U), \
  .tr_bgen = (uint8_t) (((_VAL_) & 0xE00000U) >> 21U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_PLL__0_FUNCS PLL#_0 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'PLL#_0' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_pll__0(const struct bgt60utr13d_reg_pll__0 *r, uint32_t val){
  val = (val & ~0xFFFFFFU) | (uint32_t) ((r->fsu & 0xFFFFFFU) << 0U);
 return val;
}

/**
 * @brief Pack the 'PLL#_0' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_pll__0(const struct bgt60utr13d_reg_pll__0 *r){
  return bgt60utr13d_modify_pll__0(r, 0);
}

/**
 * @brief Unpack the 'PLL#_0' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_pll__0(struct bgt60utr13d_reg_pll__0 *r, uint32_t val){
  r->fsu = (uint32_t) ((val & 0xFFFFFFU) >> 0U);
}

/**
 * @brief Unpack the 'PLL#_0' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_pll__0() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_pll__0 reg = BGT60UTR13D_UNPACK_PLL__0(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_PLL__0(_VAL_) { \
  .fsu = (uint32_t) (((_VAL_) & 0xFFFFFFU) >> 0U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_PLL__1_FUNCS PLL#_1 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'PLL#_1' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_pll__1(const struct bgt60utr13d_reg_pll__1 *r, uint32_t val){
  val = (val & ~0xFFFFFFU) | (uint32_t) ((r->rsu & 0xFFFFFFU) << 0U);
 return val;
}

/**
 * @brief Pack the 'PLL#_1' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_pll__1(const struct bgt60utr13d_reg_pll__1 *r){
  return bgt60utr13d_modify_pll__1(r, 0);
}

/**
 * @brief Unpack the 'PLL#_1' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_pll__1(struct bgt60utr13d_reg_pll__1 *r, uint32_t val){
  r->rsu = (uint32_t) ((val & 0xFFFFFFU) >> 0U);
}

/**
 * @brief Unpack the 'PLL#_1' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_pll__1() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_pll__1 reg = BGT60UTR13D_UNPACK_PLL__1(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_PLL__1(_VAL_) { \
  .rsu = (uint32_t) (((_VAL_) & 0xFFFFFFU) >> 0U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_PLL__2_FUNCS PLL#_2 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'PLL#_2' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_pll__2(const struct bgt60utr13d_reg_pll__2 *r, uint32_t val){
  val = (val & ~0x3FFFU) | (uint32_t) ((r->rtu & 0x3FFFU) << 0U);
  val = (val & ~0xFF0000U) | (uint32_t) ((r->tr_edu & 0xFFU) << 16U);
 return val;
}

/**
 * @brief Pack the 'PLL#_2' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_pll__2(const struct bgt60utr13d_reg_pll__2 *r){
  return bgt60utr13d_modify_pll__2(r, 0);
}

/**
 * @brief Unpack the 'PLL#_2' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_pll__2(struct bgt60utr13d_reg_pll__2 *r, uint32_t val){
  r->rtu = (uint16_t) ((val & 0x3FFFU) >> 0U);
  r->tr_edu = (uint8_t) ((val & 0xFF0000U) >> 16U);
}

/**
 * @brief Unpack the 'PLL#_2' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_pll__2() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_pll__2 reg = BGT60UTR13D_UNPACK_PLL__2(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_PLL__2(_VAL_) { \
  .rtu = (uint16_t) (((_VAL_) & 0x3FFFU) >> 0U), \
  .tr_edu = (uint8_t) (((_VAL_) & 0xFF0000U) >> 16U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_PLL__3_FUNCS PLL#_3 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'PLL#_3' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_pll__3(const struct bgt60utr13d_reg_pll__3 *r, uint32_t val){
  val = (val & ~0xFFFU) | (uint32_t) ((r->apu & 0xFFFU) << 0U);
  val = (val & ~0xFFF000U) | (uint32_t) ((r->apd & 0xFFFU) << 12U);
 return val;
}

/**
 * @brief Pack the 'PLL#_3' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_pll__3(const struct bgt60utr13d_reg_pll__3 *r){
  return bgt60utr13d_modify_pll__3(r, 0);
}

/**
 * @brief Unpack the 'PLL#_3' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_pll__3(struct bgt60utr13d_reg_pll__3 *r, uint32_t val){
  r->apu = (uint16_t) ((val & 0xFFFU) >> 0U);
  r->apd = (uint16_t) ((val & 0xFFF000U) >> 12U);
}

/**
 * @brief Unpack the 'PLL#_3' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_pll__3() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_pll__3 reg = BGT60UTR13D_UNPACK_PLL__3(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_PLL__3(_VAL_) { \
  .apu = (uint16_t) (((_VAL_) & 0xFFFU) >> 0U), \
  .apd = (uint16_t) (((_VAL_) & 0xFFF000U) >> 12U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_PLL__4_FUNCS PLL#_4 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'PLL#_4' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_pll__4(const struct bgt60utr13d_reg_pll__4 *r, uint32_t val){
  val = (val & ~0xFFFFFFU) | (uint32_t) ((r->fsd & 0xFFFFFFU) << 0U);
 return val;
}

/**
 * @brief Pack the 'PLL#_4' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_pll__4(const struct bgt60utr13d_reg_pll__4 *r){
  return bgt60utr13d_modify_pll__4(r, 0);
}

/**
 * @brief Unpack the 'PLL#_4' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_pll__4(struct bgt60utr13d_reg_pll__4 *r, uint32_t val){
  r->fsd = (uint32_t) ((val & 0xFFFFFFU) >> 0U);
}

/**
 * @brief Unpack the 'PLL#_4' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_pll__4() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_pll__4 reg = BGT60UTR13D_UNPACK_PLL__4(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_PLL__4(_VAL_) { \
  .fsd = (uint32_t) (((_VAL_) & 0xFFFFFFU) >> 0U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_PLL__5_FUNCS PLL#_5 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'PLL#_5' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_pll__5(const struct bgt60utr13d_reg_pll__5 *r, uint32_t val){
  val = (val & ~0xFFFFFFU) | (uint32_t) ((r->rsd & 0xFFFFFFU) << 0U);
 return val;
}

/**
 * @brief Pack the 'PLL#_5' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_pll__5(const struct bgt60utr13d_reg_pll__5 *r){
  return bgt60utr13d_modify_pll__5(r, 0);
}

/**
 * @brief Unpack the 'PLL#_5' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_pll__5(struct bgt60utr13d_reg_pll__5 *r, uint32_t val){
  r->rsd = (uint32_t) ((val & 0xFFFFFFU) >> 0U);
}

/**
 * @brief Unpack the 'PLL#_5' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_pll__5() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_pll__5 reg = BGT60UTR13D_UNPACK_PLL__5(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_PLL__5(_VAL_) { \
  .rsd = (uint32_t) (((_VAL_) & 0xFFFFFFU) >> 0U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_PLL__6_FUNCS PLL#_6 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'PLL#_6' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_pll__6(const struct bgt60utr13d_reg_pll__6 *r, uint32_t val){
  val = (val & ~0x3FFFU) | (uint32_t) ((r->rtd & 0x3FFFU) << 0U);
  val = (val & ~0xFF0000U) | (uint32_t) ((r->tr_edd & 0xFFU) << 16U);
 return val;
}

/**
 * @brief Pack the 'PLL#_6' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_pll__6(const struct bgt60utr13d_reg_pll__6 *r){
  return bgt60utr13d_modify_pll__6(r, 0);
}

/**
 * @brief Unpack the 'PLL#_6' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_pll__6(struct bgt60utr13d_reg_pll__6 *r, uint32_t val){
  r->rtd = (uint16_t) ((val & 0x3FFFU) >> 0U);
  r->tr_edd = (uint8_t) ((val & 0xFF0000U) >> 16U);
}

/**
 * @brief Unpack the 'PLL#_6' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_pll__6() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_pll__6 reg = BGT60UTR13D_UNPACK_PLL__6(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_PLL__6(_VAL_) { \
  .rtd = (uint16_t) (((_VAL_) & 0x3FFFU) >> 0U), \
  .tr_edd = (uint8_t) (((_VAL_) & 0xFF0000U) >> 16U), \
}

/** @} */

/**
 * \defgroup BGT60UTR13D_PLL__7_FUNCS PLL#_7 register modify/pack/unpack utilities.
 * @{
 */
/**
 * @brief Modify the 'PLL#_7' register's binary representation
 * All fields are replaced with the struct's values.
 * All 'always_write' bits (if any) are forced to the correct value.
 * All other bits are kept the same.
 * @param r struct holding register fields
 * @param val current binary register representation
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_modify_pll__7(const struct bgt60utr13d_reg_pll__7 *r, uint32_t val){
  val = (val & ~0xFU) | (uint32_t) ((r->reps & 0xFU) << 0U);
  val = (val & ~0x10U) | (uint32_t) ((r->sh_en & 0x1U) << 4U);
  val = (val & ~0x100U) | (uint32_t) ((r->cont_mode & 0x1U) << 8U);
  val = (val & ~0x600U) | (uint32_t) ((r->pd_mode & 0x3U) << 9U);
  val = (val & ~0x7F800U) | (uint32_t) ((r->tr_sed & 0xFFU) << 11U);
  val = (val & ~0xF80000U) | (uint32_t) ((r->tr_sed_mul & 0x1FU) << 19U);
 return val;
}

/**
 * @brief Pack the 'PLL#_7' register's fields into their binary representation
 * All fields are set to the struct's values.
 * All 'always_write' bits (if any) are set to the correct value.
 * All other bits are are set to 0.
 * @param r struct holding register fields
 * @return packed register representation
 */
static inline  uint32_t bgt60utr13d_pack_pll__7(const struct bgt60utr13d_reg_pll__7 *r){
  return bgt60utr13d_modify_pll__7(r, 0);
}

/**
 * @brief Unpack the 'PLL#_7' register's binary representation into seperate fields
 * @param r buffer to store the unpacked fields
 * @param val packed register representation
 */
static inline void bgt60utr13d_unpack_pll__7(struct bgt60utr13d_reg_pll__7 *r, uint32_t val){
  r->reps = (uint8_t) ((val & 0xFU) >> 0U);
  r->sh_en = (uint8_t) ((val & 0x10U) >> 4U);
  r->cont_mode = (uint8_t) ((val & 0x100U) >> 8U);
  r->pd_mode = (enum bgt60utr13d_pll__7_pd_mode) ((val & 0x600U) >> 9U);
  r->tr_sed = (uint8_t) ((val & 0x7F800U) >> 11U);
  r->tr_sed_mul = (uint8_t) ((val & 0xF80000U) >> 19U);
}

/**
 * @brief Unpack the 'PLL#_7' register's binary representation into a struct initialiser.
 * @note use static bgt60utr13d_unpack_pll__7() to unpack into an exsisting struct.
 * Example:
 *   `struct bgt60utr13d_reg_pll__7 reg = BGT60UTR13D_UNPACK_PLL__7(0xAB);`
 * 
 * @param _VAL_ packed register representation
 */
#define BGT60UTR13D_UNPACK_PLL__7(_VAL_) { \
  .reps = (uint8_t) (((_VAL_) & 0xFU) >> 0U), \
  .sh_en = (uint8_t) (((_VAL_) & 0x10U) >> 4U), \
  .cont_mode = (uint8_t) (((_VAL_) & 0x100U) >> 8U), \
  .pd_mode = (enum bgt60utr13d_pll__7_pd_mode) (((_VAL_) & 0x600U) >> 9U), \
  .tr_sed = (uint8_t) (((_VAL_) & 0x7F800U) >> 11U), \
  .tr_sed_mul = (uint8_t) (((_VAL_) & 0xF80000U) >> 19U), \
}

/** @} */

#endif /* BGT60UTR13D_REG_UTILS_H_ */

