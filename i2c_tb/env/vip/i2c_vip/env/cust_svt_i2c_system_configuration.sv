
`ifndef GUARD_CUST_SVT_I2C_SYSTEM_CONFIGURATION_SV
  `define GUARD_CUST_SVT_I2C_SYSTEM_CONFIGURATION_SV

/**
 * Abstract:
 * Class cust_svt_i2c_system_configuration is basically used to encapsulate all
 * the configuration information.  It extends system configuration and set the
 * appropriate fields like number of master/slaves, create master/slave
 * configurations etc..., which are required by System Env.
 */

class cust_svt_i2c_system_configuration extends svt_i2c_system_configuration;

  //Utility macro
  `uvm_object_utils(cust_svt_i2c_system_configuration)

  function new (string str="cust_svt_i2c_system_configuration");
    super.new(str);

    /** Assign the necessary configuration parameters. This example uses single
     * master and single slave configuration.
     */
    this.num_masters = 1;
    this.num_slaves  = 1;

    /** Create port configurations */
    this.create_sub_cfgs(this.num_masters, this.num_slaves);

    /** Set mode */
    this.master_cfg[0].is_active = 0;
    this.slave_cfg[0].is_active = 1;
    this.slave_cfg[0].slave_address = 10'h055;
    this.slave_cfg[0].enable_10bit_addr = 0;
    this.slave_cfg[0].slave_type = `SVT_I2C_GENERIC;
    this.slave_cfg[0].enable_cci_8bit = 0;
    this.slave_cfg[0].enable_eeprom_32bit = 0;
    this.enable_chk_for_xz_sda_at_time0 = 1'b0;
    this.enable_chk_for_xz_scl_at_time0 = 1'b0;

  endfunction : new

endclass : cust_svt_i2c_system_configuration

`endif // GUARD_CUST_SVT_I2C_SYSTEM_CONFIGURATION_SV

//------------------------------------------------------------------------
//-----------------------END OF FILE--------------------------------------
//------------------------------------------------------------------------
