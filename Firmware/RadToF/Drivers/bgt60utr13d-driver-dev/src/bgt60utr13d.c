#include <stdint.h>
#include <string.h>

#include "bgt60utr13d.h"
#include "bgt60utr13d_regs.h"
#include "bgt60utr13d_reg_utils.h"
#include "bgt60utr13d_enums.h"

// ======== Macro Quick Access =================================================================

#define DRVR_LOG(msg)                                                                                                  \
  if (h != 0 && h->log != 0) {                                                                                         \
    h->log(msg, false, false, 0);                                                                                      \
  }

#define DRVR_LOG_VAR(msg, val)                                                                                         \
  if (h != 0 && h->log != 0) {                                                                                         \
    h->log(msg, false, true, val);                                                                                     \
  }

#define DRVR_ERR(msg)                                                                                                  \
  if (h != 0 && h->log != 0) {                                                                                         \
    h->log(msg, true, false, 0);                                                                                       \
  }

#define DRVR_ERR_VAR(msg, val)                                                                                         \
  if (h != 0 && h->log != 0) {                                                                                         \
    h->log(msg, true, true, val);                                                                                      \
  }


// *** General ***

#define T_SYS_CLK ( (float)0.0125 ) // In us ; 8 * T_SYS_CLK = 0.1 us ; Use f_sys_clk = 80 MHz only

#define MAX_ABB_CHANNELS 3
#define MAX_SHAPE_GROUPS 4

#define SINGLE_REG_MODE 0

// *** Register conversions ***

// Timings: 
#define T_START_FROM_TR(tr) ( (tr * 8 + 10) * T_SYS_CLK ) // In us
#define T_SSTART_FROM_TR(tr) ( (tr * 8 + 1) * T_SYS_CLK ) // In us
#define T_PAEN_FROM_TR(tr) ( (tr * 8) * T_SYS_CLK ) // In us


// *** Endian ***
// Warning: Don't read directly from uint32 as uint8 arr (Endian) --> Use the following transmit and receive defines!
// TRANSMIT
#define PUT_IN_TRANSMIT_BUF(uint32_24b, uint8_arr) \
  uint8_arr[0] = (uint8_t)(uint32_24b >> 16); \
  uint8_arr[1] = (uint8_t)(uint32_24b >> 8); \
  uint8_arr[2] = (uint8_t)(uint32_24b); 

// RECEIVE
#define EXTRACT_GLOBAL_STATUS(arr) \
  ((uint8_t)(arr[0]))
  
#define EXTRACT_REGISTER(arr) \
  ((uint32_t)((arr[1] << 16) | (arr[2] << 8) | (arr[3])))


// *** Defines for single register operations ***
#define GET_SINGLE_REG(reg_struct_ptr, reg_adr, unpack_func_ptr, receive_buff_ptr) \
  err |= read_regs(h, reg_adr, SINGLE_REG_MODE, (uint8_t *)receive_buff_ptr); \
  if(err) return err; \
  unpack_func_ptr(reg_struct_ptr, EXTRACT_REGISTER(receive_buff_ptr)) 

#define SET_SINGLE_REG(reg_struct_ptr, reg_adr, pack_func_ptr, packed_reg_buf, transmit_buff_ptr) \
  packed_reg_buf = pack_func_ptr(reg_struct_ptr); \
  PUT_IN_TRANSMIT_BUF(packed_reg_buf, transmit_buff_ptr); \
  err |= write_regs(h, reg_adr, SINGLE_REG_MODE, (uint8_t *)transmit_buff_ptr); \
  if (err) return err; 


// *** DEBUG ***
#define UINT8_ARR_TO_UINT32(arr) ( \
  (arr[0] << 24) | (arr[1] << 16) | (arr[2] << 8) | (arr[3]) )


// ======== Private Prototypes =================================================================

// General functions

/**
 * @brief Validates the device specific handle struct.
 * 
 * @param h Pointer to the device-specific handle struct.
 *            
 * @return @ref E_BGT60UTR13D_SUCCESS if valid handle struct, otherwise @ref E_BGT60UTR13D_NULLPTR_ERR.
*/
static bgt60utr13d_err_t validate_handle(const struct bgt60utr13d_h *h);

/**
 * @brief Checks the SPI connection by reading the CHIP_Version register and 
 *        disabling the high speed read mode in the SFCTL register.
 * 
 * @param h Pointer to the device-specific handle struct.
 *            
 * @return @ref E_BGT60UTR13D_SUCCESS if read was succesful, otherwise @ref E_BGT60UTR13D_COM_ERR.
*/
static bgt60utr13d_err_t check_connection(const struct bgt60utr13d_h *h);

/**
 * @brief Extracts the content of the global status register (GSR0) and prints potential errors and warnings.
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param glob_stat Contains the value of the GSR0 register.
 *            
 * @return @ref E_BGT60UTR13D_SUCCESS if successful, otherwise an error code from @ref bgt60utr13d_err_t.
*/
static bgt60utr13d_err_t check_global_status(const struct bgt60utr13d_h *h, uint8_t glob_stat);

// R/W wrapper functions

/**
 * @brief Wraps the read function and checks the global status from GSR0.
 * 
 * @param reg_adr Register address at which to start reading. Not including R-bit!
 * @param n Use n = 0 (= SINGLE_REG_MODE) for single-register read.
 *          Use n > 0 for burst read: n <= 127.
 *          n refers to the number of 24-bit packages to be read.
 *          Not including the first 32 bits, used to initiate burst mode.
 * @param buf Buffer to store results.
 *            The provided buffer should have size 4 + 3*n.
 * @return @ref E_BGT60UTR13D_SUCCESS if read was successful, otherwise @ref E_BGT60UTR13D_COM_ERR.
 */
static bgt60utr13d_err_t read_regs(const struct bgt60utr13d_h *h, uint8_t reg_adr, uint32_t n, uint8_t *buf);

/**
 * @brief Wraps the write function.
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param reg_adr Register address at which to start writing. Not including W-bit!
 * @param n Use n = 0 (= SINGLE_REG_MODE) for single-register write.
 *          Use n > 0 for burst write: n <= 127.
 *          n refers to the number of 24-bit packages to be written.
 *          Not including the first 32 bits, used to initiate burst mode.
 * @param buf Buffer of data to hold. 
 *            The provided buffer should have size:
 *              - 3 for single-register mode (n = 0)
 *              - 3*n for burst-mode
 *            
 * @return @ref E_BGT60UTR13D_SUCCESS if write was successful, otherwise @ref E_BGT60UTR13D_COM_ERR.
*/
static bgt60utr13d_err_t write_regs(const struct bgt60utr13d_h *h, uint8_t reg_adr, uint32_t n, const uint8_t *buf);

// High-level to low-level helper functions

/**
 * @brief Handles the high-to-low-level conversion of the shape_group configuration.
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to the high-level shape_group configuration.
 * @param c_t Pointer to the high-level chirp_timings configuration.
 * @param fast_down_chirp Indicates if fast down chirp is enabled.
 * @param _c Pointer to the low-level configuration to generate.

 * @return @ref E_BGT60UTR13D_SUCCESS if reads and writes were successful, otherwise @ref E_BGT60UTR13D_COM_ERR.
 */
static bgt60utr13d_err_t shape_group_active_high_to_low(const struct bgt60utr13d_h *h, const struct bgt60utr13d_shape_group *c, const struct bgt60utr13d_chirp_timings *c_t, bool fast_down_chirp, struct _bgt60utr13d_shape_group *_c);

/**
 * @brief Handles the high-to-low-level conversion of the chirp and channel_set configuration.
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to the high-level chirp configuration.
 * @param c_t Pointer to the high-level chirp_timings configuration.
 * @param _cs Pointer to the low-level channel_set configuration to generate.
 * @param _chirp Pointer to the low-level chirp configuration to generate.

 * @return @ref E_BGT60UTR13D_SUCCESS if reads and writes were successful, otherwise @ref E_BGT60UTR13D_COM_ERR.
 */
static bgt60utr13d_err_t chirp_cs_high_to_low(const struct bgt60utr13d_h *h, const struct bgt60utr13d_chirp *c, const struct bgt60utr13d_chirp_timings *c_t, struct _bgt60utr13d_channel_set *_cs, struct _bgt60utr13d_chirp *_chirp);

/**
 * @brief Writes the tr_wkup values from the init_timings configurations to the main register. 
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to the high-level init_timings configuration.

 * @return @ref E_BGT60UTR13D_SUCCESS if reads and writes were successful, otherwise @ref E_BGT60UTR13D_COM_ERR.
 */
static bgt60utr13d_err_t main_handle_timings(const struct bgt60utr13d_h *h, const struct bgt60utr13d_init_timings *c);

/**
 * @brief Reads the madc divider value from the ADC0 register.
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to a buffer for the madc divider value.

 * @return @ref E_BGT60UTR13D_SUCCESS if read was successful, otherwise @ref E_BGT60UTR13D_COM_ERR.
 */
static bgt60utr13d_err_t get_madc_div(const struct bgt60utr13d_h *h, uint16_t *madc_div);

// Low-level helper functions

/**
 * @brief Low-Level Helper function to generalize the channel set (CSx) procedure.
 * 
 * @param h Pointer to the device-specific handle struct.
 * @param c Pointer to the low-level channel_set configuration. Set to nullpointer for all 0s.
 * @param reg_addr_cs__0 Address of the first channel-set register to set.

 * @return @ref E_BGT60UTR13D_SUCCESS if reads and writes were successful, otherwise @ref E_BGT60UTR13D_COM_ERR.
 */
static bgt60utr13d_err_t set_channel_set(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_channel_set *c, uint8_t reg_addr_cs__0);

// ======== Public Functions =================================================================

// Init

bgt60utr13d_err_t bgt60utr13d_init(const struct bgt60utr13d_h *h) 
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  DRVR_LOG("[INIT] Started");

  err |= validate_handle(h);
  if (err) {
    DRVR_LOG("[INIT] Check handle: Failed");
    return err;
  }
  DRVR_LOG("[INIT] Check handle: Success");

  err |= bgt60utr13d_hard_reset(h);
  if (err) {
    DRVR_LOG("[INIT] Hardware reset: Failed");
    return err;
  }
  DRVR_LOG("[INIT] Hardware reset: Success");
  
  err |= check_connection(h);
  if (err) {
    DRVR_LOG("[INIT] Read/Write test: Failed");
    return err;
  }
  DRVR_LOG("[INIT] Read/Write test: Success");

  DRVR_LOG("[Init] Success");

  return err;
}


// Resets

bgt60utr13d_err_t bgt60utr13d_hard_reset(const struct bgt60utr13d_h *h)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle
  err |= validate_handle(h);
  if(err) return err;

  err |= h->hard_reset();
  if(err) {
    DRVR_ERR("Hardware reset failed");
    return err;
  }

  DRVR_LOG("Performed hardware reset");

  return err;
}

bgt60utr13d_err_t bgt60utr13d_soft_reset(const struct bgt60utr13d_h *h)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle
  err |= validate_handle(h);
  if(err) return err;

  // Buffer
  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;

  struct bgt60utr13d_reg_main reg_main;
  GET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_unpack_main, receive_buff);
  reg_main.sw_reset = 1;
  SET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_pack_main, packed_reg_buf, transmit_buff);

  DRVR_LOG("Performed software reset");

  return err;
}

bgt60utr13d_err_t bgt60utr13d_fifo_reset(const struct bgt60utr13d_h *h)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle
  err |= validate_handle(h);
  if(err) return err;

  // Buffer
  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;

  struct bgt60utr13d_reg_main reg_main;
  GET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_unpack_main, receive_buff);
  reg_main.fifo_rst = 1;
  SET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_pack_main, packed_reg_buf, transmit_buff);

  DRVR_LOG("Performed FIFO reset");

  return err;
}

bgt60utr13d_err_t bgt60utr13d_fsm_reset(const struct bgt60utr13d_h *h)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle
  err |= validate_handle(h);
  if(err) return err;

  // Buffer
  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;

  struct bgt60utr13d_reg_main reg_main;
  GET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_unpack_main, receive_buff);
  reg_main.fsm_reset = 1;
  SET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_pack_main, packed_reg_buf, transmit_buff);

  DRVR_LOG("Performed FSM reset");

  return err;
}


// High-level configs

bgt60utr13d_err_t bgt60utr13d_global_conf(const struct bgt60utr13d_h *h, const struct bgt60utr13d_global_conf *c)
{
  DRVR_LOG("****** GLOBAL CONF ******");

  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle and config
  err |= validate_handle(h);
  err |= (c == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  // *** Prepare low-level configs ***
  struct _bgt60utr13d_global_conf _global = {
    // MAIN
    // TR_WU is done in frame_conf via init_timings
    .sadc_bg_div_val = 2,
    .madc_bg_div_val = 3,
    .ldo_dummy_load = 0,
    .ldo_power_mode = 0,

    // SFCTL
    .spi_high_speed_read_en = c->spi_high_speed_read_en,
    .prefix_en = c->fifo_prefix_en,
    .fifo_comp_ref = c->fifo_comp_ref,
    .spi_pad_mode = 0,
    .fifo_power_mode = 2,
    .lfsr_en = 0,

    // CLK_IN
    .clk_select = c->clk_select,
    .clk_irq_sel = c->irq_mode,
    .clk_dc_in_duty_cycle_adj = 0,
    .clk_dc_out_duty_cycle_adj = 4
  };

  struct _bgt60utr13d_madc_conf _madc = {
    .adc_div = c->madc_div,

    .msb_decision_time = 0,
    .sample_time = 0,
    .tracking_conv = 1,
    .bg_chopping_en = 0,
    .bg_temp_coef_trim = 4,
    .startup_cal_dis = 0,
  };

  struct _bgt60utr13d_sadc_conf _sadc = {
    .input_sel = c->sadc_mode,

    .clk_div = 3,
    .over_samp_conf = 3,
    .tc_trim = 4,
    .lv_gain = 0,
    .sesp_en = 1,
    .sigma_delta_en = 1,
    .startup_cal_dis = 0,
  };

  // *** Apply low-level configs ***
  err |= _bgt60utr13d_global_conf(h, &_global);
  err |= _bgt60utr13d_madc_conf(h, &_madc);
  err |= _bgt60utr13d_sadc_conf(h, &_sadc);
  
  return err;
}

bgt60utr13d_err_t bgt60utr13d_frame_conf(const struct bgt60utr13d_h *h, const struct bgt60utr13d_frame_conf *c)
{  
  DRVR_LOG("****** FRAME CONF ******");

  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle and config
  err |= validate_handle(h);
  err |= (c == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  err |= (c->shape_groups == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  // *** Prepare Timings ***
  struct bgt60utr13d_init_timings *timings_init = c->timings_init;
  struct bgt60utr13d_chirp_timings *timings_chirp = c->timings_chirp;

  struct bgt60utr13d_init_timings default_timings_init = {
      // TODO: Check values
      // MAIN
      .t_wkup_tr = 39,
      .t_wkup_tr_mul = 8,

      // CCR
      .t_init0_tr = 252, // AS GUI
      .t_init0_tr_mul = 2, // AS GUI

      .t_init1_tr = 70, // AS GUI
      .t_init1_tr_mul = 0, // AS GUI

      // PACR
      .t_diven_tr = 2,

      // IDLE
      .t_pll_isopd_tr = 13,
      .t_madcen_tr = 4,
      .t_bgen_tr = 6
    };

  struct bgt60utr13d_chirp_timings default_timings_chirp = {
      // TODO: Check values
      .t_end_tr = 14, // AS GUI
      .t_paen_tr = 30, // AS GUI
      .t_sstart_tr = 31, // AS GUI
      .t_start_tr = 10 // AS GUI 1.125 us 
    };

  if(timings_init == 0) {
    timings_init = &default_timings_init;
  }

  if(timings_chirp == 0) {
    timings_chirp = &default_timings_chirp;
  }


  // *** Prepare Idle ***
  struct bgt60utr13d_idle_conf *idle = c->idle;

  struct bgt60utr13d_idle_conf default_idle = {
    // TODO: Check values
    .abb_isopd_en = 1, // AS GUI
    .rf_isopd_en = 1, // AS GUI
    .madc_isopd_en = 1, // AS GUI

    .sadc_isopd_en = 1, // AS GUI
    .temp_sens_en = 0, // AS GUI

    .madc_bg_en = 1, // AS GUI

    .pll_isopd_en = 1 // AS GUI
  };

  if(idle == 0) {
    idle = &default_idle;
  }


  // *** Prepare Shape Groups ***
  // * Structs for active groups *
  // The active structs for the low-level configs are stored on the stacks in arrays.
  // Therefore the needed array sizes need to be determined.
  uint8_t n_active_abb_total = 0;
  uint8_t index_cnt_active_abb = 0;

  for(uint8_t i = 0; i < c->n_shape_groups; ++i)
  {
    // Check config
    err |= (c->shape_groups[i] == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
    if(err) return err;

    // Check config and get total number of abb configs
    // Up (Always)
    err |= (c->shape_groups[i]->chirp_up == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
    if(err) return err;
    n_active_abb_total += c->shape_groups[i]->chirp_up->n_abb_channels;

    if(!(c->fast_down_chirp_en)){
      // Down (Only if fast_down disabled)
      err |= (c->shape_groups[i]->chirp_down == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
      if(err) return err;
      n_active_abb_total += c->shape_groups[i]->chirp_down->n_abb_channels;
    }
  }

  uint8_t n_active_cs_total = (c->fast_down_chirp_en) ? c->n_shape_groups : 2 * c->n_shape_groups;
  uint8_t index_cnt_active_cs = 0;

  struct _bgt60utr13d_shape_group *_shape_groups[4]; // Low level config needs all 4 groups

  struct _bgt60utr13d_shape_group _groups_arr[c->n_shape_groups];
  struct _bgt60utr13d_channel_set_control _csc_arr[c->n_shape_groups];

  struct _bgt60utr13d_chirp _chirps_arr[n_active_cs_total];
  struct _bgt60utr13d_channel_set _cs_arr[n_active_cs_total];
  struct _bgt60utr13d_abb_channel *_abb_arr_arr[n_active_cs_total][3]; // Two dimensional since each one  
                                                                       // holds an abb arr of size 3.
  struct _bgt60utr13d_abb_channel _abb_arr[n_active_abb_total];

  
  // * Structs for disabled groups (all 0s) *
  struct _bgt60utr13d_abb_channel _abb_channel_off = {};

  struct _bgt60utr13d_abb_channel *_abb_all_off[3]  = {&_abb_channel_off, &_abb_channel_off, &_abb_channel_off};

  struct _bgt60utr13d_chirp _chirp_off = {};

  struct _bgt60utr13d_channel_set _csx_off = {
    .abb = _abb_all_off
  };

  struct _bgt60utr13d_channel_set_control _cscx_off = {};

  struct _bgt60utr13d_shape_group _shape_group_off = {
    .csc = &_cscx_off,

    .cs_up = &_csx_off,
    .cs_down = &_csx_off,

    .chirp_down = &_chirp_off,
    .chirp_up = &_chirp_off
  };


  // *** Power Modes ***
  // * Deep Sleep * 
  struct _bgt60utr13d_channel_set_control _csc_deep_sleep = {
    // Isolate all, diable bandgap and temperature sensor
    .abb_isopd_en = 1,
    .rf_isopd_en = 1,
    .madc_bg_en = 0,
    .madc_isopd_en = 1,
    .sadc_isopd_en = 1,
    .temp_sens_en = 0,
    .pll_isopd_en = 1
  };

  struct _bgt60utr13d_channel_set _cs_deep_sleep = {
    // All off
    .abb = _abb_all_off,

    .fdiv_en = 0,
    .lo_dist1_en = 0,
    .lo_dist2_en = 0,
    .pd1_en = 0,
    .temp_meas_en = 0,
    .tx1_en = 0,
    .vco_en = 0
  };

  // * Idle *
  struct _bgt60utr13d_channel_set_control _csc_idle = {
    .madc_bg_en = idle->madc_bg_en,

    .abb_isopd_en = idle->abb_isopd_en,
    .madc_isopd_en = idle->madc_isopd_en,
    .pll_isopd_en = idle->pll_isopd_en,
    .rf_isopd_en = idle->rf_isopd_en,
    .sadc_isopd_en = idle->sadc_isopd_en,

    .temp_sens_en = idle->temp_sens_en,

    .t_pll_isopd_tr = timings_init->t_pll_isopd_tr,
    .t_bgen_tr = timings_init->t_bgen_tr,
    .t_madcen_tr = timings_init->t_madcen_tr,
  };

  struct _bgt60utr13d_channel_set _cs_idle = {
    // All off
    .abb = _abb_all_off,

    .fdiv_en = 0,
    .lo_dist1_en = 0,
    .lo_dist2_en = 0,
    .pd1_en = 0,
    .temp_meas_en = 0,
    .tx1_en = 0,
    .vco_en = 0
  };


  // *** Frame Conf ***
  struct _bgt60utr13d_frame_conf _c = {
    .max_frame_cnt = c->max_frame_cnt,
    .frame_len = c->frame_len,

    // Power Modes
    .csc_deep_sleep = &_csc_deep_sleep,
    .cs_deep_sleep = &_cs_deep_sleep,

    .csc_idle = &_csc_idle,
    .cs_idle = &_cs_idle,

    // Shape groups
    .shape_groups = _shape_groups,

    // Timings
    .t_fed_power_mode = c->t_fed_power_mode,
    .t_fed_tr = c->t_fed_tr,
    .t_fed_tr_mul = c->t_fed_tr_mul,

    .t_init0_tr = timings_init->t_init0_tr,
    .t_init0_tr_mul = timings_init->t_init0_tr_mul,
    .t_init1_tr = timings_init->t_init1_tr,
    .t_init1_tr_mul = timings_init->t_init1_tr_mul,

    .t_end_tr = timings_chirp->t_end_tr,
    .t_paen_tr = timings_chirp->t_paen_tr,
    .t_sstart_tr = timings_chirp->t_sstart_tr,
    .t_start_tr = timings_chirp->t_start_tr
  };

  // * Active shape groups *
  // Essentially sets active configs to the pointers of the active arrays from above.
  // They are then filled in shape_group_active_high_to_low().
  // The disabled configs are set to the off structs defined above.
  for(uint8_t i = 0; i < c->n_shape_groups; ++i)
  {
    struct _bgt60utr13d_shape_group *_curr_group = &_groups_arr[i];
    _c.shape_groups[i] = _curr_group;
    _curr_group->csc = &_csc_arr[i];

    // Up
    _curr_group->cs_up = &_cs_arr[index_cnt_active_cs];
    _curr_group->chirp_up = &_chirps_arr[index_cnt_active_cs];
    _curr_group->cs_up->abb = _abb_arr_arr[index_cnt_active_cs];
    ++index_cnt_active_cs;
     
    uint8_t n_abb_channels_up = c->shape_groups[i]->chirp_up->n_abb_channels;
    for(uint8_t j = 0; j < n_abb_channels_up; ++j)
    {
      _curr_group->cs_up->abb[j] = &_abb_arr[index_cnt_active_abb];
      ++index_cnt_active_abb;
    }
    for(uint8_t j = n_abb_channels_up; j < MAX_ABB_CHANNELS; ++j)
    {
      _curr_group->cs_up->abb[j] = &_abb_channel_off;
    }

    // DOWN
    if(c->fast_down_chirp_en)
    {
      _curr_group->chirp_down = &_chirp_off;
      _curr_group->cs_down = &_csx_off;
    }
    else
    {
      _curr_group->cs_down = &_cs_arr[index_cnt_active_cs];
      _curr_group->chirp_down = &_chirps_arr[index_cnt_active_cs];
      _curr_group->cs_down->abb = _abb_arr_arr[index_cnt_active_cs];
      ++index_cnt_active_cs;

      uint8_t n_abb_channels_down = c->shape_groups[i]->chirp_down->n_abb_channels;
      for(uint8_t j = 0; j < n_abb_channels_down; ++j)
      {
        _curr_group->cs_down->abb[j] = &_abb_arr[index_cnt_active_abb];
        ++index_cnt_active_abb;
      }
      for(uint8_t j = n_abb_channels_down; j < MAX_ABB_CHANNELS; ++j)
      {
        _curr_group->cs_down->abb[j] = &_abb_channel_off;
      }
    }

    err |= shape_group_active_high_to_low(h, c->shape_groups[i], timings_chirp, c->fast_down_chirp_en, _curr_group);
    if(err) return err;
  }

  // * Disabled shape groups *
  for(uint8_t i = c->n_shape_groups; i < MAX_SHAPE_GROUPS; ++i)
  {
    _c.shape_groups[i] = &_shape_group_off;
  }


  // *** PLL Config ***
  struct _bgt60utr13d_pll_conf _pll_conf = { 
    // PACR 1
    .v_analog_reg = 2,
    .v_digital_reg = 3,
    .v_ref = 3,
    .r_filt = 1,
    .r_lf = 0,
    .lock_sel = 3,
    .lock_force_en = 1,
    .c_cp = 4,
    .bias_force_en = 0,

    // PACR 2
    .fast_down_chirp_en = (c->fast_down_chirp_en) ? 2 : 0, // Attention: Enable is 2!
    .t_diven_tr = timings_init->t_diven_tr,

    .div_set = 20,
    .regul_off_state = 0,
    .pfd_dead_time = 2,
  };


  // *** Set tr_wkup in MAIN ***
  err |= main_handle_timings(h, timings_init);

  // *** Apply low-level configs ***
  err |= _bgt60utr13d_pll_conf(h, &_pll_conf);
  err |= _bgt60utr13d_frame_conf(h, &_c);

  return err;
}


// Other

bgt60utr13d_err_t bgt60utr13d_start_frame(const struct bgt60utr13d_h *h)
{
  DRVR_LOG("****** STARTING FRAME ******");

  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle
  err |= validate_handle(h);
  if(err) return err;

  // Buffer
  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;

  // Enable OSCCLK in PACR1 
  struct bgt60utr13d_reg_pacr1 reg_pacr1;
  GET_SINGLE_REG(&reg_pacr1, BGT60UTR13D_REG_PACR1, bgt60utr13d_unpack_pacr1, receive_buff);
  reg_pacr1.oscclken = 1;
  SET_SINGLE_REG(&reg_pacr1, BGT60UTR13D_REG_PACR1, bgt60utr13d_pack_pacr1, packed_reg_buf, transmit_buff);

  // Set Start_frame in MAIN to 1
  struct bgt60utr13d_reg_main reg_main;
  GET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_unpack_main, receive_buff);
  reg_main.frame_start = 1;
  SET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_pack_main, packed_reg_buf, transmit_buff);

  return err;
}

bgt60utr13d_err_t bgt60utr13d_fifo_read(const struct bgt60utr13d_h *h, uint32_t n, uint8_t *buf)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle
  err |= validate_handle(h);
  if(err) return err;

  // Read FIFO
  err |= read_regs(h, BGT60UTR13D_FIFO_ADDRESS, n, buf);

  // Read FSTAT register to check if FIFO is empty
  uint8_t receive_buff[4];
  struct  bgt60utr13d_reg_fstat reg_fstat;
  GET_SINGLE_REG(&reg_fstat, BGT60UTR13D_REG_FSTAT, bgt60utr13d_unpack_fstat, receive_buff);

  if(!(reg_fstat.empty)){
    DRVR_LOG("[FIFO read] Warning: FIFO is not empty after read.")
  }

  return err;
}

bgt60utr13d_err_t bgt60utr13d_sadc_read(const struct bgt60utr13d_h *h, uint16_t *sadc_result)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle
  err |= validate_handle(h);
  if(err) return err;

  // Read SADC_RESULT
  uint8_t receive_buff[4];
  struct  bgt60utr13d_reg_sadc_result reg_sadc_result;
  GET_SINGLE_REG(&reg_sadc_result, BGT60UTR13D_REG_SADC_RESULT, bgt60utr13d_unpack_sadc_result, receive_buff);

  // Write to sadc_result
  *sadc_result = reg_sadc_result.sadc_result;

  return err;
}


// Low-level configs

bgt60utr13d_err_t _bgt60utr13d_global_conf(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_global_conf *c)
{
  DRVR_LOG("*** _GLOBAL CONF ***");

  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle and config
  err |= validate_handle(h);
  err |= (c == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  // Buffer
  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;

  // *** MAIN ***
  DRVR_LOG("* MAIN *");
  struct bgt60utr13d_reg_main reg_main;
  GET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_unpack_main, receive_buff);
  reg_main.tr_twkup = c->t_wkup_tr;
  reg_main.tr_twkup_mul = c->t_wkup_tr_mul;
  reg_main.sadc_bg_clk_div = c->sadc_bg_div_val;
  reg_main.madc_bg_clk_div = c->madc_bg_div_val;
  reg_main.load_strenth = c->ldo_dummy_load;
  reg_main.ldo_mode = c->ldo_power_mode;
  // No config
  reg_main.cw_mode = 0; // Disable the cw test-mode
  SET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_pack_main, packed_reg_buf, transmit_buff);

  // *** SFCTL ***
  DRVR_LOG("* SFCTL *");
  struct bgt60utr13d_reg_sfctl reg_sfctl;
  GET_SINGLE_REG(&reg_sfctl, BGT60UTR13D_REG_SFCTL, bgt60utr13d_unpack_sfctl, receive_buff);
  // SPI
  reg_sfctl.miso_hs_read = c->spi_high_speed_read_en;
  reg_sfctl.prefix_en = c->prefix_en;
  reg_sfctl.pad_mode = c->spi_pad_mode;
  // FIFO
  reg_sfctl.fifo_cref = c->fifo_comp_ref;
  reg_sfctl.fifo_pd_mode = c->fifo_power_mode;
  reg_sfctl.lfsr_en = c->lfsr_en;
  SET_SINGLE_REG(&reg_sfctl, BGT60UTR13D_REG_SFCTL, bgt60utr13d_pack_sfctl, packed_reg_buf, transmit_buff);
  
  // *** CLK_IN ***
  DRVR_LOG("* CLK_IN *");
  struct bgt60utr13d_reg_clk_in reg_clk_in;
  GET_SINGLE_REG(&reg_clk_in, BGT60UTR13D_REG_CLK_IN, bgt60utr13d_unpack_clk_in, receive_buff);
  reg_clk_in.clk_sel = c->clk_select;
  reg_clk_in.dc_in_adj = c->clk_dc_in_duty_cycle_adj;
  reg_clk_in.dc_out_adj = c->clk_dc_out_duty_cycle_adj;
  reg_clk_in.irq_fd_sel = c->clk_irq_sel;
  SET_SINGLE_REG(&reg_clk_in, BGT60UTR13D_REG_CLK_IN, bgt60utr13d_pack_clk_in, packed_reg_buf, transmit_buff);

  // *** RF-TEST ***
  DRVR_LOG("* RF TEST *");
  uint32_t rf_test = 0; // Set RF-TEST register to 0x0
  PUT_IN_TRANSMIT_BUF(rf_test, transmit_buff);
  err |= write_regs(h, BGT60UTR13D_REG_RFT0, SINGLE_REG_MODE, (uint8_t *)transmit_buff);
  if(err) return err; 

  return err;
}

bgt60utr13d_err_t _bgt60utr13d_pll_conf(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_pll_conf *c)
{
  DRVR_LOG("*** _PLL CONF ***");

  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle and config
  err |= validate_handle(h);
  err |= (c == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  // Buffer
  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;

  // *** PACR1..2 ***
  DRVR_LOG("* PACR *");
  struct bgt60utr13d_reg_pacr1 reg_pacr1;
  GET_SINGLE_REG(&reg_pacr1, BGT60UTR13D_REG_PACR1, bgt60utr13d_unpack_pacr1, receive_buff);
  reg_pacr1.vanareg = c->v_analog_reg;
  reg_pacr1.vdigreg = c->v_digital_reg;
  reg_pacr1.vrefsel = c->v_ref;
  reg_pacr1.rfiltsel = c->r_filt;
  reg_pacr1.rlfsel = c->r_lf;
  reg_pacr1.locksel = c->lock_sel;
  reg_pacr1.lockforc = c->lock_force_en;
  reg_pacr1.icpsel = c->c_cp;
  reg_pacr1.biasforc = c->bias_force_en;
  // No config
  reg_pacr1.anapon = 1;
  reg_pacr1.digpon = 1;
  reg_pacr1.bgapen = 1;
  reg_pacr1.u2ien = 1;
  reg_pacr1.cpen = 1;
  reg_pacr1.lfen = 1;
  SET_SINGLE_REG(&reg_pacr1, BGT60UTR13D_REG_PACR1, bgt60utr13d_pack_pacr1, packed_reg_buf, transmit_buff);

  struct bgt60utr13d_reg_pacr2 reg_pacr2;
  GET_SINGLE_REG(&reg_pacr2, BGT60UTR13D_REG_PACR2, bgt60utr13d_unpack_pacr2, receive_buff);
  reg_pacr2.fstdnen = c->fast_down_chirp_en;
  reg_pacr2.tr_diven = c->t_diven_tr;
  reg_pacr2.divset = c->div_set;
  reg_pacr2.trivreg = c->regul_off_state;
  reg_pacr2.dtsel = c->pfd_dead_time;
  // No Config
  reg_pacr2.diven = 1;
  reg_pacr2.fsdntmr = 5; // Only value allowed (= 75 ns)
  SET_SINGLE_REG(&reg_pacr2, BGT60UTR13D_REG_PACR2, bgt60utr13d_pack_pacr2, packed_reg_buf, transmit_buff);
  
  return err;
}

bgt60utr13d_err_t _bgt60utr13d_madc_conf(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_madc_conf *c)
{
  DRVR_LOG("*** _MADC CONF ***");

  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle and config
  err |= validate_handle(h);
  err |= (c == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  // Buffer
  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;

  // *** ADC0 ***
  DRVR_LOG("* ADC0 *");
  struct bgt60utr13d_reg_adc0 reg_adc0;
  GET_SINGLE_REG(&reg_adc0, BGT60UTR13D_REG_ADC0, bgt60utr13d_unpack_adc0, receive_buff);
  reg_adc0.adc_div = c->adc_div;
  reg_adc0.stc = c->sample_time;
  reg_adc0.msb_ctrl = c->msb_decision_time;
  reg_adc0.track_cfg = c->tracking_conv;
  reg_adc0.bg_tc_trim = c->bg_temp_coef_trim;
  reg_adc0.bg_chop_en = c->bg_chopping_en;
  reg_adc0.dscal = c->startup_cal_dis;
  // No config
  reg_adc0.adc_overs_cfg = 0; // Only value allowed (=11 bits conversion)
  reg_adc0.trig_madc = 0;
  SET_SINGLE_REG(&reg_adc0, BGT60UTR13D_REG_ADC0, bgt60utr13d_pack_adc0, packed_reg_buf, transmit_buff);

  return err;
}

bgt60utr13d_err_t _bgt60utr13d_sadc_conf(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_sadc_conf *c)
{
  DRVR_LOG("*** _SADC CONF ***");

  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle and config
  err |= validate_handle(h);
  err |= (c == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  // Buffer
  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;

  DRVR_LOG("* Sensor ADC *");
  struct bgt60utr13d_reg_sadc_ctrl reg_sadc;
  GET_SINGLE_REG(&reg_sadc, BGT60UTR13D_REG_SADC_CTRL, bgt60utr13d_unpack_sadc_ctrl, receive_buff);
  reg_sadc.sadc_chsel = c->input_sel;
  reg_sadc.sadc_clk_div = c->clk_div;
  reg_sadc.overs_cfg = c->over_samp_conf;
  reg_sadc.dscal = c->startup_cal_dis;
  reg_sadc.lvgain = c->lv_gain;
  reg_sadc.sd_en = c->sigma_delta_en;
  reg_sadc.sesp = c->sesp_en;
  reg_sadc.tc_trim = c->tc_trim;
  // No config
  reg_sadc.start_sadc = 0;
  SET_SINGLE_REG(&reg_sadc, BGT60UTR13D_REG_SADC_CTRL, bgt60utr13d_pack_sadc_ctrl, packed_reg_buf, transmit_buff);

  return err;
}

bgt60utr13d_err_t _bgt60utr13d_frame_conf(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_frame_conf *c)
{  
  DRVR_LOG("*** _FRAME CONF ***");

  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check handle and config
  err |= validate_handle(h);
  err |= (c == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  err |= (c->csc_deep_sleep == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  err |= (c->cs_deep_sleep == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  err |= (c->csc_idle == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  err |= (c->cs_idle == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  err |= (c->shape_groups == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  // Buffer
  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;


  // *** Chirp Control ***
  // * CCR_0..3 *
  DRVR_LOG("* CCR *");
  struct bgt60utr13d_reg_ccr0 reg_ccr0;
  GET_SINGLE_REG(&reg_ccr0, BGT60UTR13D_REG_CCR0, bgt60utr13d_unpack_ccr0, receive_buff);
  reg_ccr0.tr_end = c->t_end_tr;
  reg_ccr0.tr_init1 = c->t_init1_tr;
  reg_ccr0.tr_init1_mul = c->t_init1_tr_mul;
  // No config
  reg_ccr0.cont_mode = 1; // Next CS after T_FED
  reg_ccr0.rept = 15; // Set 15 as default --> Config via frame_len. See DS. section 4.26
  SET_SINGLE_REG(&reg_ccr0, BGT60UTR13D_REG_CCR0, bgt60utr13d_pack_ccr0, packed_reg_buf, transmit_buff);

  struct bgt60utr13d_reg_ccr1 reg_ccr1;
  GET_SINGLE_REG(&reg_ccr1, BGT60UTR13D_REG_CCR1, bgt60utr13d_unpack_ccr1, receive_buff);
  reg_ccr1.tr_start = c->t_start_tr;
  reg_ccr1.pd_mode = c->t_fed_power_mode;
  reg_ccr1.tr_fed = c->t_fed_tr;
  reg_ccr1.tr_fed_mul = c->t_fed_tr_mul;
  SET_SINGLE_REG(&reg_ccr1, BGT60UTR13D_REG_CCR1, bgt60utr13d_pack_ccr1, packed_reg_buf, transmit_buff);

  struct bgt60utr13d_reg_ccr2 reg_ccr2;
  GET_SINGLE_REG(&reg_ccr2, BGT60UTR13D_REG_CCR2, bgt60utr13d_unpack_ccr2, receive_buff);
  reg_ccr2.max_frame_cnt = c->max_frame_cnt;
  reg_ccr2.frame_len = c->frame_len;
  SET_SINGLE_REG(&reg_ccr2, BGT60UTR13D_REG_CCR2, bgt60utr13d_pack_ccr2, packed_reg_buf, transmit_buff);

  struct bgt60utr13d_reg_ccr3 reg_ccr3;
  GET_SINGLE_REG(&reg_ccr3, BGT60UTR13D_REG_CCR3, bgt60utr13d_unpack_ccr3, receive_buff);
  reg_ccr3.tr_paen = c->t_paen_tr;
  reg_ccr3.tr_sstart = c->t_sstart_tr;
  reg_ccr3.tr_init0 = c->t_init0_tr;
  reg_ccr3.tr_init0_mul = c->t_init0_tr_mul;
  SET_SINGLE_REG(&reg_ccr3, BGT60UTR13D_REG_CCR3, bgt60utr13d_pack_ccr3, packed_reg_buf, transmit_buff);

  // *** Idle power mode ***
  // * CSCI *
  DRVR_LOG("* CSCI, CSI_0..2 *");
  struct bgt60utr13d_reg_csc_ reg_csci;
  GET_SINGLE_REG(&reg_csci, BGT60UTR13D_REG_CSCI, bgt60utr13d_unpack_csc_, receive_buff);
  reg_csci.abb_isopd = c->csc_idle->abb_isopd_en;
  reg_csci.rf_isopd = c->csc_idle->rf_isopd_en;
  reg_csci.madc_bg_en = c->csc_idle->madc_bg_en;
  reg_csci.madc_isopd = c->csc_idle->madc_isopd_en;
  reg_csci.sadc_isopd = c->csc_idle->sadc_isopd_en;
  reg_csci.bg_tmrf_en = c->csc_idle->temp_sens_en;
  reg_csci.pll_isopd = c->csc_idle->pll_isopd_en;
  reg_csci.tr_pll_isopd = c->csc_idle->t_pll_isopd_tr;
  reg_csci.tr_madcen = c->csc_idle->t_madcen_tr;
  reg_csci.tr_bgen = c->csc_idle->t_bgen_tr;
  SET_SINGLE_REG(&reg_csci, BGT60UTR13D_REG_CSCI, bgt60utr13d_pack_csc_, packed_reg_buf, transmit_buff);

  // * CSI_0..2 *
  set_channel_set(h, c->cs_idle, BGT60UTR13D_REG_CSI_0);

  // *** Deep sleep power mode ***
  // * CSCDS *
  DRVR_LOG("* CSDS, CSDS_0..2 *");
  struct bgt60utr13d_reg_csc_ reg_cscds;
  GET_SINGLE_REG(&reg_cscds, BGT60UTR13D_REG_CSCDS, bgt60utr13d_unpack_csc_, receive_buff);
  reg_cscds.abb_isopd = c->csc_deep_sleep->abb_isopd_en;
  reg_cscds.rf_isopd = c->csc_deep_sleep->rf_isopd_en;
  reg_cscds.madc_bg_en = c->csc_deep_sleep->madc_bg_en;
  reg_cscds.madc_isopd = c->csc_deep_sleep->madc_isopd_en;
  reg_cscds.sadc_isopd = c->csc_deep_sleep->sadc_isopd_en;
  reg_cscds.bg_tmrf_en = c->csc_deep_sleep->temp_sens_en;
  reg_cscds.pll_isopd = c->csc_deep_sleep->pll_isopd_en;
  SET_SINGLE_REG(&reg_cscds, BGT60UTR13D_REG_CSCDS, bgt60utr13d_pack_csc_, packed_reg_buf, transmit_buff);

  // * CSDS_0..2 *
  set_channel_set(h, c->cs_deep_sleep, BGT60UTR13D_REG_CSDS_0);


  // *** SHAPE GROUPS X ***
  DRVR_LOG("* SHAPE GROUPS X *");
  for(uint32_t x = 0; x < 4; ++x)
  {
    DRVR_LOG_VAR("Setting Group x = ", x + 1);
    const struct _bgt60utr13d_shape_group *curr_group = c->shape_groups[x];

    // Check config
    err |= (curr_group == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
    if(err) return err;

    err |= (curr_group->csc == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
    err |= (curr_group->cs_up == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
    err |= (curr_group->cs_down == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
    err |= (curr_group->chirp_up == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
    err |= (curr_group->chirp_down == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
    if(err) return err;

    // Check if same amount of groups in pll and active channel sets
    if(curr_group->csc->cs_en != curr_group->sh_en)
    {
      DRVR_LOG("Warning: PLLx_7:SH_EN and CSCx:CS_EN are not the same");
    }

    // * CSCx *
    DRVR_LOG("* CSCx, CS(U&D)x_0..2 *");
    struct bgt60utr13d_reg_csc_ reg_csc;
    GET_SINGLE_REG(&reg_csc, BGT60UTR13D_REG_CSC1 + x*7, bgt60utr13d_unpack_csc_, receive_buff);
    reg_csc.abb_isopd = curr_group->csc->abb_isopd_en;
    reg_csc.rf_isopd = curr_group->csc->rf_isopd_en;
    reg_csc.madc_bg_en = curr_group->csc->madc_bg_en;
    reg_csc.madc_isopd = curr_group->csc->madc_isopd_en;
    reg_csc.sadc_isopd = curr_group->csc->sadc_isopd_en;
    reg_csc.bg_tmrf_en = curr_group->csc->temp_sens_en;
    reg_csc.pll_isopd = curr_group->csc->pll_isopd_en;
    reg_csc.repcs = curr_group->csc->repc;
    reg_csc.cs_en = curr_group->csc->cs_en;
    SET_SINGLE_REG(&reg_csc, BGT60UTR13D_REG_CSC1 + x*7, bgt60utr13d_pack_csc_, packed_reg_buf, transmit_buff);

    // * CSx_0..2 Up and Down *
    set_channel_set(h, curr_group->cs_up, BGT60UTR13D_REG_CSU1_0 + x*7); // Up
    set_channel_set(h, curr_group->cs_down, BGT60UTR13D_REG_CSD1_0 + x*7); // Down
  

    // * PLLx_0..7 *
    DRVR_LOG("* PLLx_0..7 * ");
    struct bgt60utr13d_reg_pll__0 reg_pll_0;
    GET_SINGLE_REG(&reg_pll_0, BGT60UTR13D_REG_PLL1_0 + x*8, bgt60utr13d_unpack_pll__0, receive_buff);
    reg_pll_0.fsu = curr_group->chirp_up->freq_start;
    SET_SINGLE_REG(&reg_pll_0, BGT60UTR13D_REG_PLL1_0 + x*8, bgt60utr13d_pack_pll__0, packed_reg_buf, transmit_buff);

    struct bgt60utr13d_reg_pll__1 reg_pll_1;
    GET_SINGLE_REG(&reg_pll_1, BGT60UTR13D_REG_PLL1_1 + x*8, bgt60utr13d_unpack_pll__1, receive_buff);
    reg_pll_1.rsu = curr_group->chirp_up->delta_freq_per_clk;
    SET_SINGLE_REG(&reg_pll_1, BGT60UTR13D_REG_PLL1_1 + x*8, bgt60utr13d_pack_pll__1, packed_reg_buf, transmit_buff);

    struct bgt60utr13d_reg_pll__2 reg_pll_2;
    GET_SINGLE_REG(&reg_pll_2, BGT60UTR13D_REG_PLL1_2+ x*8, bgt60utr13d_unpack_pll__2, receive_buff);
    reg_pll_2.rtu = curr_group->chirp_up->n_steps;
    reg_pll_2.tr_edu = curr_group->chirp_up->t_ed_tr;
    SET_SINGLE_REG(&reg_pll_2, BGT60UTR13D_REG_PLL1_2 + x*8, bgt60utr13d_pack_pll__2, packed_reg_buf, transmit_buff);

    struct bgt60utr13d_reg_pll__3 reg_pll_3;
    GET_SINGLE_REG(&reg_pll_3, BGT60UTR13D_REG_PLL1_3 + x*8, bgt60utr13d_unpack_pll__3, receive_buff);
    reg_pll_3.apu = curr_group->chirp_up->n_samples;
    reg_pll_3.apd = curr_group->chirp_down->n_samples;
    SET_SINGLE_REG(&reg_pll_3, BGT60UTR13D_REG_PLL1_3 + x*8, bgt60utr13d_pack_pll__3, packed_reg_buf, transmit_buff);

    struct bgt60utr13d_reg_pll__4 reg_pll_4;
    GET_SINGLE_REG(&reg_pll_4, BGT60UTR13D_REG_PLL1_4 + x*8, bgt60utr13d_unpack_pll__4, receive_buff);
    reg_pll_4.fsd = curr_group->chirp_down->freq_start;
    SET_SINGLE_REG(&reg_pll_4, BGT60UTR13D_REG_PLL1_4 + x*8, bgt60utr13d_pack_pll__4, packed_reg_buf, transmit_buff);

    struct bgt60utr13d_reg_pll__5 reg_pll_5;
    GET_SINGLE_REG(&reg_pll_5, BGT60UTR13D_REG_PLL1_5 + x*8, bgt60utr13d_unpack_pll__5, receive_buff);
    reg_pll_5.rsd = curr_group->chirp_down->delta_freq_per_clk;
    SET_SINGLE_REG(&reg_pll_5, BGT60UTR13D_REG_PLL1_5 + x*8, bgt60utr13d_pack_pll__5, packed_reg_buf, transmit_buff);

    struct bgt60utr13d_reg_pll__6 reg_pll_6;
    GET_SINGLE_REG(&reg_pll_6, BGT60UTR13D_REG_PLL1_6 + x*8, bgt60utr13d_unpack_pll__6, receive_buff);
    reg_pll_6.rtd = curr_group->chirp_down->n_steps;
    reg_pll_6.tr_edd = curr_group->chirp_down->t_ed_tr;
    SET_SINGLE_REG(&reg_pll_6, BGT60UTR13D_REG_PLL1_6 + x*8, bgt60utr13d_pack_pll__6, packed_reg_buf, transmit_buff);

    struct bgt60utr13d_reg_pll__7 reg_pll_7;
    GET_SINGLE_REG(&reg_pll_7, BGT60UTR13D_REG_PLL1_7 + x*8, bgt60utr13d_unpack_pll__7, receive_buff);
    reg_pll_7.reps = curr_group->reps;
    reg_pll_7.sh_en = curr_group->sh_en;
    reg_pll_7.pd_mode = curr_group->t_sed_power_mode;
    reg_pll_7.tr_sed = curr_group->t_sed_tr;
    reg_pll_7.tr_sed_mul = curr_group->t_sed_tr_mul;
    //No config
    reg_pll_7.cont_mode = 1;
    SET_SINGLE_REG(&reg_pll_7, BGT60UTR13D_REG_PLL1_7 + x*8, bgt60utr13d_pack_pll__7, packed_reg_buf, transmit_buff);
  }

  return err;
}


// Debug

bgt60utr13d_err_t bgt60utr13d_debug_read_regs(const struct bgt60utr13d_h *h, uint8_t reg_adr, uint32_t n, uint8_t *buf)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  err |= validate_handle(h);
  if(err) return err;

  err |= read_regs(h, reg_adr, n, buf);

  return err;
}

bgt60utr13d_err_t bgt60utr13d_debug_write_regs(const struct bgt60utr13d_h *h, uint8_t reg_adr, uint32_t n, const uint8_t *buf)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  err |= validate_handle(h);
  if(err) return err;

  err |= write_regs(h, reg_adr, n, buf);

  return err;
}

bgt60utr13d_err_t bgt60utr13d_debug_write_all_regs(const struct bgt60utr13d_h *h, uint32_t *data)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  err |= validate_handle(h);
  if(err) return err;

  uint8_t transmit_buff[3];

  for(uint8_t i = 0; i < 0x63; ++i)
  {
    PUT_IN_TRANSMIT_BUF(data[i], transmit_buff);
    err |= write_regs(h, i, SINGLE_REG_MODE, (uint8_t *)transmit_buff);
    if(err) return err;
  }

  return err;
}


// ======== Private Functions =================================================================

// General functions

bgt60utr13d_err_t validate_handle(const struct bgt60utr13d_h *h) 
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  if (h == 0) {
    DRVR_ERR("Handle is nullptr!")
    return E_BGT60UTR13D_NULLPTR_ERR;
  }

  if (h->read_regs == 0) {
    DRVR_ERR("Read_regs is nullptr!")
    err |= E_BGT60UTR13D_NULLPTR_ERR;
  }

  if (h->write_regs == 0) {
    DRVR_ERR("Write_regs is nullptr!")
    err |= E_BGT60UTR13D_NULLPTR_ERR;
  }

  if (h->hard_reset == 0) {
    DRVR_ERR("Hard_reset is nullptr!")
    err |= E_BGT60UTR13D_NULLPTR_ERR;
  }

  return err;
}

bgt60utr13d_err_t check_connection(const struct bgt60utr13d_h *h) 
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;

  // *** Check implemented read function ***
  // Read CHIP_Version register:
  err |= read_regs(h, BGT60UTR13D_REG_CHIP_VERSION, SINGLE_REG_MODE, (uint8_t *) receive_buff);
  if(err){
    DRVR_ERR("Failed to read CHIP_Version register!");
    return err;
  }

  // Check WHO_AM_I (CHIP_Version:DIGITAL_ID and CHIP_Version:RF_ID) value
  uint32_t who_am_i = EXTRACT_REGISTER(receive_buff) & 0xffff; // Only last 16 bits
  if(who_am_i != (BGT60UTR13D_REG_CHIP_VERSION__RESETVAL & 0xffff)){
    DRVR_ERR_VAR("Wrong CHIP_Version value: ", who_am_i);
    DRVR_ERR_VAR("Expected CHIP_Version value: ", (BGT60UTR13D_REG_CHIP_VERSION__RESETVAL & 0xffff));
    return E_BGT60UTR13D_COM_ERR;
  }
  DRVR_LOG("Correct CHIP_Version value");

  // *** Check implemented write function *** 
  // Disable high_speed_read in SFCTL, reset value is enabled
  struct bgt60utr13d_reg_sfctl reg_sfctl;
  GET_SINGLE_REG(&reg_sfctl, BGT60UTR13D_REG_SFCTL, bgt60utr13d_unpack_sfctl, receive_buff);
  reg_sfctl.miso_hs_read = 0;
  SET_SINGLE_REG(&reg_sfctl, BGT60UTR13D_REG_SFCTL, bgt60utr13d_pack_sfctl, packed_reg_buf, transmit_buff);

  // Read SFCTL:MISO_HS_READ to check if changes applied
  struct bgt60utr13d_reg_sfctl reg_sfctl_test;
  GET_SINGLE_REG(&reg_sfctl_test, BGT60UTR13D_REG_SFCTL, bgt60utr13d_unpack_sfctl, receive_buff);
  if(reg_sfctl.miso_hs_read != 0)
  {
    DRVR_ERR("Write to SFCTL failed!")
    return E_BGT60UTR13D_COM_ERR;
  }
  DRVR_LOG("Disabled high speed read");

  return err;
}

bgt60utr13d_err_t check_global_status(const struct bgt60utr13d_h *h, uint8_t glob_stat)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  glob_stat &= 0x0f; // Mask to ignore the reserved parts of GSR0

  if(glob_stat != BGT60UTR13D_GLOBAL_STATUS_OK)
  {
    // Warnings:
    if((glob_stat & BGT60UTR13D_GLOBAL_STATUS_MISO_HS_READ) != 0){
      DRVR_LOG("[GLOBAL STATUS] Warning: MISO High Speed Read enabled");
    }
    
    // Errors:
    if((glob_stat & BGT60UTR13D_GLOBAL_STATUS_CLK_NUM_ERROR) != 0){
      DRVR_ERR("[GLOBAL STATUS] Clock number error");
      err |= E_BGT60UTR13D_ERR;
    }

    if((glob_stat & BGT60UTR13D_GLOBAL_STATUS_SPI_BURST_ERROR) != 0){
      DRVR_ERR("[GLOBAL STATUS] SPI burst error");
      err |= E_BGT60UTR13D_ERR;
    }

    if((glob_stat & BGT60UTR13D_GLOBAL_STATUS_FOU_ERROR) != 0){
      DRVR_ERR("[GLOBAL STATUS] FIFO Under-/Overflow error");
      err |= E_BGT60UTR13D_ERR;
    }
  }
  else
  {
    DRVR_LOG("[GLOBAL STATUS] OK");
  }

  return err;
}


// R/W wrapper functions

bgt60utr13d_err_t read_regs(const struct bgt60utr13d_h *h, uint8_t reg_adr, uint32_t n, uint8_t *buf) 
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  uint8_t send_buf[4];

  if(n == SINGLE_REG_MODE){ 
    // Single-register read
    send_buf[0] = BGT60UTR13D_READ_ADDRESS(reg_adr);
    send_buf[1] = 0;
    send_buf[2] = 0;
    send_buf[3] = 0;

    DRVR_LOG_VAR("[READ WRAPPER] Single read, reg_adr: ", reg_adr);
  }
  else{ 
    // Burst read
    send_buf[0] = BGT60UTR13D_WRITE_ADDRESS(BGT60UTR13D_BURST_MODE_ADDRESS);
    send_buf[1] = BGT60UTR13D_READ_ADDRESS(reg_adr);
    send_buf[2] = (reg_adr == BGT60UTR13D_FIFO_ADDRESS) ? 0 : (n << 1); // Don't use n for FIFO access --> 0 = "unlimited read"
    send_buf[3] = 0;

    DRVR_LOG_VAR("[READ WRAPPER] Burst read, starting at reg_adr: ", reg_adr);
  }
  
  err |= h->read_regs((uint8_t *)send_buf, 4 + 3*n, buf);
  if(err) return err;

  err |= check_global_status(h, EXTRACT_GLOBAL_STATUS(buf));

  return err;
}

bgt60utr13d_err_t write_regs(const struct bgt60utr13d_h *h, uint8_t reg_adr, uint32_t n, const uint8_t *buf) 
{
  uint32_t n_bytes = 4 + 3*n;
  uint8_t send_buf[n_bytes];

  if(n == SINGLE_REG_MODE){ 
    // Single-register write
    send_buf[0] = BGT60UTR13D_WRITE_ADDRESS(reg_adr);
    send_buf[1] = buf[0];
    send_buf[2] = buf[1];
    send_buf[3] = buf[2];

    DRVR_LOG_VAR("[WRITE WRAPPER] Single write, send buf: ", UINT8_ARR_TO_UINT32(send_buf));
  }
  else{ 
    // Burst write
    send_buf[0] = BGT60UTR13D_WRITE_ADDRESS(BGT60UTR13D_BURST_MODE_ADDRESS);
    send_buf[1] = BGT60UTR13D_WRITE_ADDRESS(reg_adr);
    send_buf[2] = n << 1;
    send_buf[3] = 0;

    memcpy(&send_buf[4], buf, 3*n);

    DRVR_LOG_VAR("[WRITE WRAPPER] Burst write, starting at reg_adr: ", reg_adr);
  }

  return h->write_regs((uint8_t *)send_buf, n_bytes);
}


// High-level to low-level helper functions

bgt60utr13d_err_t shape_group_active_high_to_low(const struct bgt60utr13d_h *h, const struct bgt60utr13d_shape_group *c, const struct bgt60utr13d_chirp_timings *c_t, bool fast_down_chirp, struct _bgt60utr13d_shape_group *_c)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check config
  err |= (c == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  // *** PLLx_7 ***
  _c->sh_en = 1;
  _c->reps = c->reps;

  _c->t_sed_power_mode = c->t_sed_power_mode;
  _c->t_sed_tr = c->t_sed_tr;
  _c->t_sed_tr_mul = c->t_sed_tr_mul;
 
  // *** CSC ***
  _c->csc->cs_en = 1;
  _c->csc->madc_bg_en = 1;
  _c->csc->repc = c->reps;

  // No isolation
  _c->csc->abb_isopd_en = 0;
  _c->csc->madc_isopd_en = 0;
  _c->csc->pll_isopd_en = 0;
  _c->csc->rf_isopd_en = 0;

  // Temperature sensor and SADC
  _c->csc->temp_sens_en = c->temp_sens_en;
  _c->csc->sadc_isopd_en = c->sadc_isopd_en;
  
  // *** UP (= cs_up, chirp_up) ***
  err |= chirp_cs_high_to_low(h, c->chirp_up, c_t, _c->cs_up, _c->chirp_up);
  if(err) return err;

  // *** DOWN (= cs_down, chirp_down) ***
  if(!fast_down_chirp)
  {
    err |= chirp_cs_high_to_low(h, c->chirp_down, c_t, _c->cs_down, _c->chirp_down);
    if(err) return err;
  }

  return err;
}

bgt60utr13d_err_t chirp_cs_high_to_low(const struct bgt60utr13d_h *h, const struct bgt60utr13d_chirp *c, const struct bgt60utr13d_chirp_timings *c_t, struct _bgt60utr13d_channel_set *_cs, struct _bgt60utr13d_chirp *_chirp)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check config
  err |= (c == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  err |= (c->abb == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  // *** _cs ***
  _cs->lo_dist1_en = 1;
  _cs->lo_dist2_en = 1;
  _cs->vco_en = 1;
  _cs->tx1_en = 1;
  _cs->fdiv_en = 1;
  _cs->pd1_en = 0;
  _cs->abb_rstcnt = 15;

  _cs->temp_meas_en = c->temp_sens_en;
  _cs->tx1_power_mode = c->tx1_power_mode;

  // Active channels
  for(uint8_t i = 0; i < c->n_abb_channels; ++i)
  {
    // Check config
    err |= (c->abb[i] == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
    if(err) return err;

    _cs->abb[i]->ch_en = 1;
    _cs->abb[i]->rx_lobuf_en = 1;
    _cs->abb[i]->rx_mix_en = 1;

    _cs->abb[i]->aaf_freq = c->abb[i]->aaf_freq;
    _cs->abb[i]->hpf_freq = c->abb[i]->hpf_freq;
    _cs->abb[i]->hpf_gain = c->abb[i]->hpf_gain;
    _cs->abb[i]->vga_gain = c->abb[i]->vga_gain;
  }


  // *** _chirp ***
  _chirp->t_ed_tr = c->t_ed_tr;

  // * Given freq_start (--> FS(U/D)) and n_samples (--> AP(U/D)) *
  _chirp->freq_start = (uint32_t) ((int32_t) ((c->rf_start / 0.640f - 96) * (1 << 20))); 
  _chirp->n_samples = c->n_samples;

  // * Calculations: Only supported for f_sys_clk = 80 MHz *

  // Read madc_div from ADC0
  uint16_t madc_div;
  err |= get_madc_div(h, &madc_div);
  if(err) return err;

  // Calculate n_steps (--> RT(U/D))
  float t_acqu = c->n_samples * T_SYS_CLK * madc_div;
  float t_ramp = t_acqu + T_PAEN_FROM_TR(c_t->t_paen_tr) + T_SSTART_FROM_TR(c_t->t_sstart_tr) - T_START_FROM_TR(c_t->t_start_tr) + 2; // #TODO: Assume T_ECM = 2 us
  _chirp->n_steps = (uint16_t) (t_ramp * 10); 

  // Calculate delta_freq_per_clk (--> RS(U/D))
  float bandwidth = c->rf_end - c->rf_start;
  float delta_f = bandwidth / (8 * _chirp->n_steps);
  _chirp->delta_freq_per_clk = (uint32_t) ((int32_t) ((delta_f / 0.640f) * (1 << 20)));

  // Print chirp configurations:
  DRVR_LOG("--- Chirp configuration (register values) ---");
  DRVR_LOG_VAR("freq_start (FS_)         : ", _chirp->freq_start);
  DRVR_LOG_VAR("n_samples (AP_)          : ", _chirp->n_samples);
  DRVR_LOG_VAR("n_steps (RT_)            : ", _chirp->n_steps);
  DRVR_LOG_VAR("delta_freq_per_clk (RS_) : ", _chirp->delta_freq_per_clk);
  DRVR_LOG("---------------------------------------------");

  return err;
}

bgt60utr13d_err_t main_handle_timings(const struct bgt60utr13d_h *h, const struct bgt60utr13d_init_timings *c)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Buffer
  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;

  // MAIN
  DRVR_LOG("* MAIN * Set t_wkup")
  struct bgt60utr13d_reg_main reg_main;
  GET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_unpack_main, receive_buff);
  reg_main.tr_twkup = c->t_wkup_tr;
  reg_main.tr_twkup_mul = c->t_wkup_tr_mul;
  SET_SINGLE_REG(&reg_main, BGT60UTR13D_REG_MAIN, bgt60utr13d_pack_main, packed_reg_buf, transmit_buff);

  return err;
}

bgt60utr13d_err_t get_madc_div(const struct bgt60utr13d_h *h, uint16_t *madc_div)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Buffer
  uint8_t receive_buff[4];

  // ADC0
  struct bgt60utr13d_reg_adc0 reg_adc0;
  GET_SINGLE_REG(&reg_adc0, BGT60UTR13D_REG_ADC0, bgt60utr13d_unpack_adc0, receive_buff);
  *madc_div = reg_adc0.adc_div;

  return err;
}


// Low-level helper functions

bgt60utr13d_err_t set_channel_set(const struct bgt60utr13d_h *h, const struct _bgt60utr13d_channel_set *c, uint8_t reg_addr_cs__0)
{
  bgt60utr13d_err_t err = E_BGT60UTR13D_SUCCESS;

  // Check config
  err |= (c == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  err |= (c->abb == 0) ? E_BGT60UTR13D_CONFIG_ERR : 0;
  if(err) return err;

  uint8_t receive_buff[4];
  uint8_t transmit_buff[3];
  uint32_t packed_reg_buf;

  // Set config
  DRVR_LOG("CSx active");
  struct bgt60utr13d_reg_cs__0 reg_cs0;
  GET_SINGLE_REG(&reg_cs0, reg_addr_cs__0, bgt60utr13d_unpack_cs__0, receive_buff);
  reg_cs0.tx1_en = c->tx1_en;
  reg_cs0.pd1_en = c->pd1_en;
  reg_cs0.vco_en = c->vco_en;
  reg_cs0.temp_meas_en = c->temp_meas_en;
  reg_cs0.fdiv_en = c->fdiv_en;
  reg_cs0.lo_dist2_en = c->lo_dist2_en;
  reg_cs0.lo_dist1_en = c->lo_dist1_en;
  reg_cs0.rx1lobuf_en = c->abb[0]->rx_lobuf_en;
  reg_cs0.rx1mix_en = c->abb[0]->rx_mix_en;
  reg_cs0.rx2lobuf_en = c->abb[1]->rx_lobuf_en;
  reg_cs0.rx2mix_en = c->abb[1]->rx_mix_en;
  reg_cs0.rx3lobuf_en = c->abb[2]->rx_lobuf_en;
  reg_cs0.rx3mix_en = c->abb[2]->rx_mix_en;
  reg_cs0.abb1_aaf_ctrl = c->abb[0]->aaf_freq;
  reg_cs0.abb2_aaf_ctrl = c->abb[1]->aaf_freq;
  reg_cs0.abb3_aaf_ctrl = c->abb[2]->aaf_freq;
  SET_SINGLE_REG(&reg_cs0, reg_addr_cs__0, bgt60utr13d_pack_cs__0, packed_reg_buf, transmit_buff);

  struct bgt60utr13d_reg_cs__1 reg_cs1;
  GET_SINGLE_REG(&reg_cs1, reg_addr_cs__0 + 1, bgt60utr13d_unpack_cs__1, receive_buff);
  reg_cs1.tx1_dac = c->tx1_power_mode;
  reg_cs1.bb_rstcnt = c->abb_rstcnt;
  reg_cs1.hp1_gain = c->abb[0]->hpf_gain;
  reg_cs1.hp2_gain = c->abb[1]->hpf_gain;
  reg_cs1.hp3_gain = c->abb[2]->hpf_gain;
  reg_cs1.madc_bbch1_en = c->abb[0]->ch_en;
  reg_cs1.madc_bbch2_en = c->abb[1]->ch_en;
  reg_cs1.madc_bbch3_en = c->abb[2]->ch_en;
  SET_SINGLE_REG(&reg_cs1, reg_addr_cs__0 + 1, bgt60utr13d_pack_cs__1, packed_reg_buf, transmit_buff);

  struct bgt60utr13d_reg_cs__2 reg_cs2;
  GET_SINGLE_REG(&reg_cs2, reg_addr_cs__0 + 2, bgt60utr13d_unpack_cs__2, receive_buff);
  reg_cs2.hpf_sel1 = c->abb[0]->hpf_freq;
  reg_cs2.hpf_sel2 = c->abb[1]->hpf_freq;
  reg_cs2.hpf_sel3 = c->abb[2]->hpf_freq;
  reg_cs2.vga_gain1 = c->abb[0]->vga_gain;
  reg_cs2.vga_gain2 = c->abb[1]->vga_gain;
  reg_cs2.vga_gain3 = c->abb[2]->vga_gain;
  SET_SINGLE_REG(&reg_cs2, reg_addr_cs__0 + 2, bgt60utr13d_pack_cs__2, packed_reg_buf, transmit_buff);

  return err;
}
