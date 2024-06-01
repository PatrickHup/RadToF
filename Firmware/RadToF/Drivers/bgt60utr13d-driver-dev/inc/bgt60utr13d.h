/*
 * BGT60UTR13D Driver
 *
 * Andrea Ronco
 * Tim Distel
 * PBL D-ITET ETHZ
 */

/*! \file bgt60utr13d.h
    \brief Main driver header.
*/

#ifndef BGT60UTR13D_H_
#define BGT60UTR13D_H_

#include <stdbool.h>
#include <stdint.h>
#include "bgt60utr13d_enums.h"

// ======== General Definitions ================================================

#define TODO_ENUM uint8_t // Change to POTENTIAL_ENUM

#define BGT60UTR13D_BURST_MODE_ADDRESS (0x7F)
#define BGT60UTR13D_FIFO_ADDRESS (0x63)
#define BGT60UTR13D_FIFO_SIZE (0x1 << 13) // Number of 24-bit words

#define BGT60UTR13D_READ_ADDRESS(reg_adr) ((reg_adr << 1) | 0x0)
#define BGT60UTR13D_WRITE_ADDRESS(reg_adr) ((reg_adr << 1) | 0x1)

/**
 * @brief Driver error codes
 */
typedef enum {
  E_BGT60UTR13D_SUCCESS     = 0,        //!< Success
  E_BGT60UTR13D_NULLPTR_ERR = (1 << 0), //!< Nullpointer error
  E_BGT60UTR13D_COM_ERR     = (1 << 1), //!< Communication error
  E_BGT60UTR13D_CONFIG_ERR  = (1 << 2), //!< Configuration error
  E_BGT60UTR13D_ERR         = (1 << 3), //!< Other error
} bgt60utr13d_err_t;

/**
 * @brief Global status register (GSR0) errors
 */
typedef enum {
  BGT60UTR13D_GLOBAL_STATUS_OK              = 0,        //!< Global status is ok
  BGT60UTR13D_GLOBAL_STATUS_CLK_NUM_ERROR   = (1 << 0), //!< Clock number error
  BGT60UTR13D_GLOBAL_STATUS_SPI_BURST_ERROR = (1 << 1), //!< SPI burst error
  BGT60UTR13D_GLOBAL_STATUS_MISO_HS_READ    = (1 << 2), //!< SPI MISO highspeed read enabled
  BGT60UTR13D_GLOBAL_STATUS_FOU_ERROR       = (1 << 3), //!< FIFO Under-/Overflow error
} bgt60utr13d_global_status_t;

// ======== Configuration ======================================================

// High-level configuration structs

/** 
 * @brief Global configuration. 
 *        Contains configurations for: 
 *        SFCTL, CLK_IN, ADC0, Sensor ADC.
*/
struct bgt60utr13d_global_conf
{
  // *** SFCTL ***
  /** @brief Enables the SPI High Speed Read Mode */
  bool spi_high_speed_read_en;

  /** @brief Enables the FIFO prefix. See DS section 5.1 */
  bool fifo_prefix_en;

  /** 
   * @brief Sets the compare register to trigger the FIFO interrupt. 
   *        An interrupt is generated as soon as the FIFO holds (fifo_comp_ref + 1) words of 24 bits.
   *        One sample contains 12 bits: 2 samples per 24-bit word.
   *        0 <= fifo_comp_ref <= 8191
  */
  uint16_t fifo_comp_ref;

  // *** CLK_IN ***
  /** @brief Decides wheter to use frequency doubler (40 MHz oscillator) or not (80 MHz oscillator). */
  enum bgt60utr13d_clk_in_clk_sel clk_select;

  /** @brief Selects the IRQ mode. Use other than FIFO interrupt only for debug. */
  enum bgt60utr13d_clk_in_irq_fd_sel irq_mode;

  // *** ADCO ***
  /** 
   * @brief Sets the divider for the MADC.
   *        f_adc_samp = f_sys_clk / madc_div.
   *        20 <= madc_div <= 1023.
  */
  uint16_t madc_div;

  // *** Sensor ADC ***
  /** @brief Selects the input of the Sensor ADC. */
  enum bgt60utr13d_sadc_ctrl_sadc_chsel sadc_mode;
};

/**
 * @brief Configuration for the IDLE power mode. See DS section 3.3.
*/
struct bgt60utr13d_idle_conf
{
  /** @brief Enables the isolation of the ABB. */
  bool abb_isopd_en;

  /** @brief Enables the isolation of the RF module. */
  bool rf_isopd_en;

  /** @brief Enables the isolation of the PLL. */
  bool pll_isopd_en;

  /** @brief Enables the isolation of the MADC. */
  bool madc_isopd_en;

  /** @brief Enables the isolation of the SADC. */
  bool sadc_isopd_en;

  /** @brief Enables the temperature sensor. */
  bool temp_sens_en;
  
  /** @brief Enables the bandgap of the MADC. */
  bool madc_bg_en; 
};

/**
 * @brief Configuration for chirp timings. See DS sections 3.3.2 and 3.4.
*/
struct bgt60utr13d_chirp_timings
{
  /** 
   * @brief Delay after down chirp.
   *        0: t_end = 5 * t_sys_clk.
   *        1..511: t_end = (t_end_tr * 8 + 5) * t_sys_clk.
  */
  uint16_t t_end_tr;

  /** 
   * @brief Ramp start delay.
   *        t_start < t_paen + t_sstart.
   *        0..511: t_start = (t_start_tr * 8 + 10) * t_sys_clk.   
  */
  uint16_t t_start_tr; 

  /** 
   * @brief Delay after PLL start and power amplifier enable.
   *        0: Reserved.
   *        1..511: t_paen = tr_paen * 8 * t_sys_clk.
  */
  uint16_t t_paen_tr;

  /** 
   * @brief Delay after power amplifier enable and first trigger to ADC.
   *        0..31: t_sstart = (t_sstart_tr * 8 + 1) * t_sys_clk
  */
  uint8_t t_sstart_tr;
};

/**
 * @brief Configuration for initialization timings. See DS sections 3.3.2 and 3.4.
*/
struct bgt60utr13d_init_timings
{ 
  // *** MAIN ***

  /** 
   * @brief Timer for wake-up time after deep sleep.
   *        Typical: 1 ms
   *        0: t_wu = t_sys_clk.
   *        1..255: t_wu = (t_wkup_tr * 2^t_wkup_tr_mul * 8 + t_wkup_tr_mul + 5) * t_sys_clk.
  */
  uint8_t t_wkup_tr; 
  /** 
   * @brief Multiplicator for wake-up time after deep sleep.
   *        Typical: 1 ms
   *        1..15: t_wu = (t_wkup_tr * 2^t_wkup_tr_mul * 8 + t_wkup_tr_mul + 5) * t_sys_clk.
  */
  uint8_t t_wkup_tr_mul; 

  // *** CCR ***

  /** 
   * @brief Timer for init0 phase.
   *        t_init0 > t_pll_isopd and t_init0 > t_madcen.
   *        0: t_init0 = t_sys_clk.
   *        1..255: t_init0 = (t_init0_tr * 2^t_init0_tr_mul * 8 + t_init0_tr_mul + 3) * t_sys_clk.
  */
  uint8_t t_init0_tr; 
  /** 
   * @brief Multiplicator for init0 phase.
   *        t_init0 > t_pll_isopd and t_init0 > t_madcen.
   *        0..3: t_init0 = (t_init0_tr * 2^t_init0_tr_mul * 8 + t_init0_tr_mul + 3) * t_sys_clk.
  */ 
  uint8_t t_init0_tr_mul;

  /** 
   * @brief Timer for init1 phase.
   *        0: t_init1 = t_sys_clk.
   *        1..255: t_init1 = (t_init1_tr * 2^t_init1_tr_mul * 8 + t_init1_tr_mul + 3) * t_sys_clk.
  */
  uint8_t t_init1_tr;
  /** 
   * @brief Multiplicator for init0 phase.
   *        0..3: t_init1 = (t_init1_tr * 2^t_init1_tr_mul * 8 + t_init1_tr_mul + 3) * t_sys_clk.
  */ 
  uint8_t t_init1_tr_mul;

  // *** PACR ***

  /** 
   * @brief Timer for t_diven
   *        0..7: t_diven = (t_diven_tr * 32 + 1) * t_sys_clk
  */
  uint8_t t_diven_tr; 

  // *** CSCI ***

  /** 
   * @brief Timer for delay pll enable after idle state.
   *        0: t_pll_isopd = t_sys_clk
   *        1..63: t_pll_isopd = (t_pll_isopd_tr * 64 + 2) * t_sys_clk
  */
  uint8_t t_pll_isopd_tr;

  /** 
   * @brief Timer for delay madc enable after idle state.
   *        Typical: 0.8 us
   *        0: No delay
   *        1..7: t_madcen = (t_madcen_tr * 64 + 1) * t_sys_clk
  */
  uint8_t t_madcen_tr;

  /** 
   * @brief Timer for delay bandgap enable after idle state.
   *        Typical: 0.8 us
   *        0: t_bgen = t_sys_clk
   *        1..7: t_bgen = (t_madcen_tr * 64 + 2) * t_sys_clk
  */
  uint8_t t_bgen_tr;
};

/**
 * @brief Configuration for one abb channel.
*/
struct bgt60utr13d_abb_channel
{
  /** @brief Sets the anti-aliasing filter cutoff frequency. */
  enum bgt60utr13d_cs__0_abb1_aaf_ctrl aaf_freq;

  /** @brief Sets the high-pass filter gain. */
  enum bgt60utr13d_cs__1_hp1_gain hpf_gain;
  /** @brief Sets the high-pass filter cutoff frequency. */
  enum bgt60utr13d_cs__2_hpf_sel1 hpf_freq;

  /** @brief Sets the VGA gain. */
  enum bgt60utr13d_cs__2_vga_gain1 vga_gain;
};

/**
 * @brief Configuration for one up or down chirp. 
*/
struct bgt60utr13d_chirp
{ 
  /**
   * @brief In GHz. Start frequency of the chirp. 
   *        58.0f <= rf_start <= 63.5f GHz.
  */
  float rf_start;

  /** 
   * @brief In GHz. End frequency of the chirp. 
   *        58.0f <= rf_end <= 63.5f GHz.
  */
  float rf_end;

  /** 
   * @brief Number of samples per chirp by the MADC.
   *        0 <= n_samples <= 4095.
  */
  uint16_t n_samples; 
  
  /**
   * @brief Sets the power mode of TX1 during this chirp.
   *        0 = Minimum Power.
   *        31 = Maximum Power.
  */
  uint8_t tx1_power_mode;

  /** @brief Enables the temperatur sensor during this chirp. */
  bool temp_sens_en; // TODO: Remove?

  /**
   * @brief Timer for end of chirp delay.
   *        0: t_ed = 2 * t_sys_clk.
   *        1..255: t_ed = (t_ed_tr * 8 + 5) * t_sys_clk.
  */
  uint8_t t_ed_tr;

  /**
   * @brief Number of used abb channels. 
   *        1 <= n_abb_channels <= 3.
  */
  uint8_t n_abb_channels;
  /** @brief A pointer to an array of size n_abb_channels of pointers to abb_channel structs. */
  struct bgt60utr13d_abb_channel **abb;
};

/**
 * @brief Configuration for one shape group. See DS section 3.1.
*/
struct bgt60utr13d_shape_group
{
  /**
  * @brief Repetition factor for a single shape. See DS section 3.1.
  *        rs = 2^reps.
  *        0 <= reps <= 15.
  */
  uint8_t reps;

  /** @brief Configuration for up chirp. */
  struct bgt60utr13d_chirp *chirp_up;

  /**
  * @brief Configuration for down chirp.
  *        Set to null pointer if fast down chirp is used.
  */
  struct bgt60utr13d_chirp *chirp_down;

  /** @brief Enables the temperature sensor for this shape group. */
  bool temp_sens_en;

  /**
  * @brief Enables the isolation for the Sensor ADC during this shape group.
  *        Needs to be disabled if using the temperature sensor.
  */
  bool sadc_isopd_en;

  /** @brief Selects the power mode to be entered after a shape group during t_sed. */
  enum bgt60utr13d_pll__7_pd_mode t_sed_power_mode;

  /** 
   * @brief Timer for t_sed.
   *        0: t_sed = t_sys_clk.
   *        1..255: t_sed = (t_sed_tr * 2^t_sed_tr_mul * 8 + t_sed_tr_mul + 3) * t_sys_clk.
  */
  uint8_t t_sed_tr;
  /** 
   * @brief Multiplicator for t_sed.
   *        0..31: t_sed = (t_sed_tr * 2^t_sed_tr_mul * 8 + t_sed_tr_mul + 3) * t_sys_clk.
  */ 
  uint8_t t_sed_tr_mul;
};

/**
 * @brief Configuration for a frame.
*/
struct bgt60utr13d_frame_conf
{
  /**
   * @brief Maximum number of frames. 
   *        Device goes to deep sleep mode after (max_frame_cnt + 1) frames and needs to be triggered again.
   *        Set to 0x0 for unlimited frame generation.
   *        0 <= max_frame_cnt <= 4095.
  */
  uint16_t max_frame_cnt; 

  /**
  * @brief Number of shape groups per frame. 
  *        A frame contains (frame_len + 1) shape groups.
  *        (frame_len + 1) should be a multiple of n_shape_groups for complete sets.
  *        0 <= frame_len <= 4095.
 */
  uint16_t frame_len; 

  /**
   * @brief Enables fast down chirp.
   *        When enabled, no down chirps must be configured (Set to null pointer).
  */
  bool fast_down_chirp_en; 

  /**
   * @brief Sets the initialization timings.
   *        Set to null pointer for default values.
   *        Default timings work for high-level only configurations.
   *        If low-level configurations, especially _madc or _pll,
   *        or a custom idle config are used,
   *        consider adjusting the timings.
  */
  struct bgt60utr13d_init_timings *timings_init;
  /**
   * @brief Sets the chirp timings.
   *        Set to null pointer for default values.
   *        Default timings work for high-level only configurations.
   *        If low-level configurations especially _madc or _pll are used,
   *        consider adjusting the timings.
  */
  struct bgt60utr13d_chirp_timings *timings_chirp;

  /**
   * @brief Configuration for the idle power mode.
   *        Set to null pointer for default configuration.
  */
  struct bgt60utr13d_idle_conf *idle;

  /**
   * @brief Number of used shape groups. 
   *        1 <= n_shape_groups <= 4.
  */
  uint8_t n_shape_groups;
  /**
   * @brief A pointer to an array of size n_shape_groups of pointers to shape_groups structs
  */
  struct bgt60utr13d_shape_group **shape_groups; 


  /**
   * @brief Specifies the power mode that is entered after last shape group of the frame during t_fed.
   *        See DS section 3.1.
  */
  enum bgt60utr13d_ccr1_pd_mode t_fed_power_mode;

  /** 
   * @brief Timer for t_fed.
   *        0: t_fed = t_sys_clk.
   *        1..255: t_fed = (t_fed_tr * 2^t_fed_tr_mul * 8 + t_fed_tr_mul + 3) * t_sys_clk.
  */
  uint8_t t_fed_tr;
  /** 
   * @brief Multiplicator for t_fed.
   *        0..31: t_fed = (t_fed_tr * 2^t_fed_tr_mul * 8 + t_fed_tr_mul + 3) * t_sys_clk.
  */ 
  uint8_t t_fed_tr_mul;
};


// Low-level configuration structs

/** @brief Global configuration (See DS. MAIN, SFCTL, CLK_IN) */
struct _bgt60utr13d_global_conf
{
  // *** MAIN ***
  uint8_t t_wkup_tr;
  uint8_t t_wkup_tr_mul;

  TODO_ENUM sadc_bg_div_val;
  TODO_ENUM madc_bg_div_val;

  TODO_ENUM ldo_dummy_load;
  TODO_ENUM ldo_power_mode;

  // *** SFCTL ***
  // SPI
  bool spi_high_speed_read_en;
  bool prefix_en;
  TODO_ENUM spi_pad_mode;

  //FIFO
  uint16_t fifo_comp_ref;
  TODO_ENUM fifo_power_mode;
  bool lfsr_en;

  // *** CLK_IN ***
  TODO_ENUM clk_select;
  TODO_ENUM clk_dc_in_duty_cycle_adj;
  TODO_ENUM clk_dc_out_duty_cycle_adj;
  bool clk_irq_sel;
};

/** @brief PLL configuration (See DS. PACR) */
struct _bgt60utr13d_pll_conf
{
  // *** PACR 1 ***
  TODO_ENUM v_analog_reg;
  TODO_ENUM v_digital_reg;
  TODO_ENUM v_ref;
  
  TODO_ENUM r_filt;
  TODO_ENUM r_lf;

  TODO_ENUM c_cp;

  TODO_ENUM lock_sel;
  bool lock_force_en;
  bool bias_force_en;

  // *** PACR 2 ****
  TODO_ENUM div_set;

  /** @brief Set to 0x2 to enable fast down chirp. */
  TODO_ENUM fast_down_chirp_en;

  TODO_ENUM regul_off_state;
  TODO_ENUM pfd_dead_time;

  uint8_t t_diven_tr;
};

/** @brief Multi-ADC configuration (See DS. ADC0) */
struct _bgt60utr13d_madc_conf
{ 
  // *** ADCO ***

  /** @brief Needs to be bigger than N_ADC_CONV = N_SAMPLE + N_CONV + N_TRACK. See DS. section 8.5. */
  uint16_t adc_div;

  /** @brief N_SAMPLE = 4, 8, 16, 32 (in clock cycles). See DS. section 8.5. */
  TODO_ENUM sample_time;

  /** @brief N_CONV = 13 + 2 + (msb_decision_tim = 1..2). See DS. section 8.5. */
  TODO_ENUM msb_decision_time;

  /** @brief N_TRACK = 8 * tracking_conv. See DS. section 8.5. */
  TODO_ENUM tracking_conv;


  bool bg_chopping_en;
  TODO_ENUM bg_temp_coef_trim;
  bool startup_cal_dis;
};

/** @brief Sensor-ADC configuration (See DS. Sensor ADC) */
struct _bgt60utr13d_sadc_conf
{
  // *** Sensor ADC ***

  TODO_ENUM input_sel;
  TODO_ENUM clk_div;
  TODO_ENUM over_samp_conf;

  bool sigma_delta_en;
  bool sesp_en;
  TODO_ENUM lv_gain;
  bool startup_cal_dis;
  uint8_t tc_trim;
};

/** @brief ABB-Channel configuration (See DS. CS) */
struct _bgt60utr13d_abb_channel
{
  bool ch_en; 
  bool rx_mix_en;
  bool rx_lobuf_en;

  // ABB settings
  TODO_ENUM aaf_freq;

  TODO_ENUM hpf_gain;
  TODO_ENUM hpf_freq;

  TODO_ENUM vga_gain;
};

/** @brief Defines a single up or down chirp (See DS. PLLx) */
struct _bgt60utr13d_chirp
{
  // *** PLLx_0..6 ***

  /** @brief N_FS(U/D) */
  uint32_t freq_start;

  /** @brief N_RS(sU/D) */
  uint32_t delta_freq_per_clk;

  /** @brief N_RT(U/D) */
  uint16_t n_steps;

  /** @brief N_AP(U/D) */
  uint16_t n_samples;

  /** @brief T_ED(U/D): End of chirp delay (Up or down) */
  uint8_t t_ed_tr;
};

/** @brief Channel set control configuration (See DS. CSCDS, CSCI, CSCx)*/
struct _bgt60utr13d_channel_set_control
{
  // Active, idle, deep sleep (CSCDS, CSCI, CSCx)
  bool abb_isopd_en;
  bool rf_isopd_en;
  bool pll_isopd_en;
  bool madc_isopd_en;

  bool sadc_isopd_en;
  bool temp_sens_en;
  
  bool madc_bg_en;

  // Active only (CSCx)
  uint8_t repc; // Should be equal to PLLx_7:reps
  bool cs_en;

  // Idle only (CSCI)
  uint8_t t_pll_isopd_tr;
  uint8_t t_madcen_tr;
  uint8_t t_bgen_tr;
};

/** @brief Channel set configurations (See DS. CS) */
struct _bgt60utr13d_channel_set
{
  // *** CS__0 ***
  bool tx1_en;
  bool pd1_en;
  bool vco_en;
  bool temp_meas_en;
  bool fdiv_en;
  bool lo_dist2_en;
  bool lo_dist1_en;

  // *** CS__1 ***
  TODO_ENUM tx1_power_mode;
  uint8_t abb_rstcnt;

  /** @brief Pointer to an array of size 3 filled with pointers to _abb_channel structs */
  struct _bgt60utr13d_abb_channel **abb;
};

/** @brief Defines one of the shape groups x = 1..4 (See DS. CSCx, CSx, PLLx)*/
struct _bgt60utr13d_shape_group
{
  // *** CSCx ***
  struct _bgt60utr13d_channel_set_control *csc;
 
  // *** CS(U/D)x_0..2 ***
  struct _bgt60utr13d_channel_set *cs_up;
  struct _bgt60utr13d_channel_set *cs_down;

  // *** PLLx_1..6 ***
  struct _bgt60utr13d_chirp *chirp_up;
  struct _bgt60utr13d_chirp *chirp_down;
  
  // *** PLLx_7 ***
  bool sh_en;
  uint8_t reps;

  TODO_ENUM t_sed_power_mode;
  uint8_t t_sed_tr;
  uint8_t t_sed_tr_mul;
};

/** @brief: Configuration for a frame (See DS. CCR) */
struct _bgt60utr13d_frame_conf
{
  // *** CCR_0..3 ***

  /** @brief Maximum number of frames. Set to 0x0 for unlimited frame generation. */
  uint16_t max_frame_cnt; 

  /** @brief frame_len + 1 = Number of shape groups per frame. */
  uint16_t frame_len; 
  
  // Timings
  TODO_ENUM t_fed_power_mode;
  uint8_t t_fed_tr;
  uint8_t t_fed_tr_mul;
  
  uint8_t t_init0_tr;
  uint8_t t_init0_tr_mul;

  uint8_t t_init1_tr;
  uint8_t t_init1_tr_mul;

  uint16_t t_end_tr;
  uint16_t t_start_tr; 
  uint16_t t_paen_tr; 
  uint8_t t_sstart_tr; 


  // *** CSCI ***
  struct _bgt60utr13d_channel_set_control *csc_idle;

  // *** CSCDS ***
  struct _bgt60utr13d_channel_set_control *csc_deep_sleep;

  // *** CS(I/DS)_0..2 ***
  struct _bgt60utr13d_channel_set *cs_idle;
  struct _bgt60utr13d_channel_set *cs_deep_sleep;

  
  // *** x (Active) ***
  /** @brief Pointer to an array of size 4, filled with pointers to _shape_group structs */
  struct _bgt60utr13d_shape_group **shape_groups;
};


// ======== Handle Definition ==================================================

/**
 * @brief Device Handle struct.
 *        Represents a single physical device. Holds the hardware-specific interface functions.
 */
struct bgt60utr13d_h {
  // === Interface function pointers. Required. ===
  /**
   * @brief Pointer to the device-specific read-register functions
   * @warning Required!
   * 
   * @param send_buf Buffer which contains the commands to send.
   * @param n Number of bytes to send and receive.
   * @param buf Buffer to store results.
   * 
   * @return @ref E_BGT60UTR13D_SUCCESS if read was successful, otherwise @ref E_BGT60UTR13D_COM_ERR.
   */
  bgt60utr13d_err_t (*read_regs)(const uint8_t *send_buf, uint32_t n, uint8_t *buf);

  /**
   * @brief Pointer to the device-specific write-register functions
   * @warning Required!
   *
   * @param send_buf Buffer to send (including reg_adr etc.)
   * @param n Number of bytes to write.
   * 
   * @return @ref E_BGT60UTR13D_SUCCESS if write was successful, otherwise @ref E_BGT60UTR13D_COM_ERR.
   */
  bgt60utr13d_err_t (*write_regs)(const uint8_t *buf, uint32_t n);

  /**
   * @brief Pointer to the device-specific hardware-reset sequence function.
   *        See DS section 5.4.
   * @warning Required!
   *
   * @param send_buf Buffer to send (including reg_adr etc.)
   * @param n Number of bytes to write.
   * 
   * @return @ref E_BGT60UTR13D_SUCCESS if hardware reset sequence successful, otherwise @ref E_BGT60UTR13D_ERR.
   */
  bgt60utr13d_err_t (*hard_reset)(void);

  // === Interface function pointers. Optional. ===
  /**
   * @brief Pointer to logging function.
   *        Called by the driver to log status and error messages, with an optional integer
   *        variable to log. Note that the string does not contain any formatting specifiers,
   *        and should be logged as follows (if has_int_arg is true):
   *
   *        printf("%s: %s %i", is_err ? "ERR" : "LOG", msg, arg);
   *
   * @param msg the log message
   * @param is_err indicates if this is an error message
   * @param has_int_arg indicates if this message is accompanied by an integer variable to log.
   * @param arg the integer variable to log if has_int_arg is true.
   */
  void (*log)(char *msg, bool is_err, bool has_int_arg, uint32_t arg);
};

// ======== Function Prototypes ================================================

// Init

/**
 * @brief Initialize the device.
 *        Validates the driver handle, 
 *        performs a hardware reset 
 *        and tests the connection to the device.
 *
 * @note This function should be called before any other driver functions are called.
 *
 * @param h Pointer to the device-specific handle struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t bgt60utr13d_init(const struct bgt60utr13d_h *h);


// Resets

/**
 * @brief Performs a hardware reset.
 *
 * @param h Pointer to the device-specific handle struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t bgt60utr13d_hard_reset(const struct bgt60utr13d_h *h);

/**
 * @brief Performs a software reset.
 *
 * @param h Pointer to the device-specific handle struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t bgt60utr13d_soft_reset(const struct bgt60utr13d_h *h);

/**
 * @brief Performs a FIFO reset.
 *
 * @param h Pointer to the device-specific handle struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t bgt60utr13d_fifo_reset(const struct bgt60utr13d_h *h);

/**
 * @brief Performs a FSM reset.
 *
 * @param h Pointer to the device-specific handle struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t bgt60utr13d_fsm_reset(const struct bgt60utr13d_h *h);


// High-level configurations

/**
 * @brief Applies the high-level global configuration.
 *        Generates low-level _global_conf, _madc_conf and _sadc_conf and applies them.
 *
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to the config struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t bgt60utr13d_global_conf(const struct bgt60utr13d_h *h, const struct bgt60utr13d_global_conf *c);

/**
 * @brief Applies the high-level frame configuration.
 *        Generates low-level _frame_conf and _pll_conf and applies them.
 *        Additionally sets T_WU in MAIN register.
 *
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to the frame config struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t bgt60utr13d_frame_conf(const struct bgt60utr13d_h *h, const struct bgt60utr13d_frame_conf *c);


// Other

/**
 * @brief Enables the SYS_CLK and starts the frame generation with the pre-defined configurations.
 *
 * @param h Pointer to the device-specific handle struct.
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t bgt60utr13d_start_frame(const struct bgt60utr13d_h *h);

/** 
 * @brief Reads out the FIFO in burst mode. Checks if FIFO is empty after read in FSTAT register.
 *        The first 4 bytes of the message are header bits and do not contain measurement values.
 *        One sample contains 12 bits i.e. a 24-bit package contains 2 samples.
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param n Number of 24-bit packages to read. n = n_samples / 2.
 * @param buf Buffer to store FIFO values. Needs to have size 4 + 3*n.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t bgt60utr13d_fifo_read(const struct bgt60utr13d_h *h, uint32_t n, uint8_t *buf);

/** 
 * @brief Reads out the SADC result from SADC_RESULT:SADC_RESULT. SADC_RESULT contains 10 bits.
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param sadc_result Buffer to store SADC result (10 bits).
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t bgt60utr13d_sadc_read(const struct bgt60utr13d_h *h, uint16_t *sadc_result);


// Low-level configurations

/**
 * @brief Sets the low-level global configuration.
 *        Additionally sets the RF-Test register to 0x0.
 *        
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to the global config struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t _bgt60utr13d_global_conf(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_global_conf *c);

/**
 * @brief Sets the low-level pll configuration.
 *
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to the pll config struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t _bgt60utr13d_pll_conf(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_pll_conf *c);

/**
 * @brief Sets the low-level madc configuration.
 *
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to the madc config struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t _bgt60utr13d_madc_conf(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_madc_conf *c);

/**
 * @brief Sets the low-level sensor adc configuration.
 *
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to the sensor adc config struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t _bgt60utr13d_sadc_conf(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_sadc_conf *c);

/**
 * @brief Sets the low-level frame configuration.
 *
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to the frame config struct.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t _bgt60utr13d_frame_conf(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_frame_conf *c);


// Debug

/**
 * @brief Debug read function. Checks global status (GSR0 register) of the device.
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param reg_adr Register address at which to start reading. Not including R-bit!
 * @param n Use n = 0 for single-register read.
 *          Use n > 0 for burst read: n <= 127.
 *          n refers to the number of 24-bit packages to be read.
 *          Not including the first 32 bits, used to initiate burst mode.
 * @param buf Buffer to store the results.
 *            The provided buffer should have size 4 + 3*n.
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
 */
bgt60utr13d_err_t bgt60utr13d_debug_read_regs(const struct bgt60utr13d_h *h, uint8_t reg_adr, uint32_t n, uint8_t *buf);

/**
 * @brief Debug write function.
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param reg_adr Register address at which to start writing. Not including W-bit!
 * @param n Use n = 0 for single-register write.
 *          Use n > 0 for burst write: n <= 127.
 *          n refers to the number of 24-bit packages to be written.
 *          Not including the first 32 bits, used to initiate burst mode.
 * @param buf Buffer of data to hold. 
 *            The provided buffer should have size:
 *              - 3 for single-register mode (n = 0)
 *              - 3*n for burst-mode
 * 
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
*/
bgt60utr13d_err_t bgt60utr13d_debug_write_regs(const struct bgt60utr13d_h *h, uint8_t reg_adr, uint32_t n, const uint8_t *buf);

/**
 * @brief Debug function to write a pre-defined register configuration.
 *        This function provides a buffer of uint32_t, 
 *        which need to be filled with the 24-bit register values.
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param data An array of size 0x63 that contains the desired values of all registers.
 *            
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
*/
bgt60utr13d_err_t bgt60utr13d_debug_write_all_regs(const struct bgt60utr13d_h *h, uint32_t *data);


#endif /* BGT60UTR13D_H_ */