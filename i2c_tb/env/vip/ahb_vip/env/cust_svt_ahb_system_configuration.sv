
/**
 * Abstract:
 * Class cust_svt_ahb_system_configuration is used to encapsulate all the
 * configuration information.  It extends the system configuration and
 * set the appropriate fields like number of masters/slaves, create
 * master/slave configurations etc..., which are required by System agent.
 */

`ifndef GUARD_CUST_SVT_AHB_SYSTEM_CONFIGURATION_SV
`define GUARD_CUST_SVT_AHB_SYSTEM_CONFIGURATION_SV


class cust_svt_ahb_system_configuration extends svt_ahb_system_configuration;

  /** UVM Object Utility macro */
  `uvm_object_utils (cust_svt_ahb_system_configuration)

  /** Class Constructor */
  function new (string name = "cust_svt_ahb_system_configuration");

    super.new(name);

    /** Assign the necessary configuration parameters. This example uses single
      * master and single slave configuration.
      */
    this.num_masters = `AHB_MASTERS_NUM;
    this.num_slaves  = `AHB_SLAVES_NUM;
    /** Create port configurations */
    this.create_sub_cfgs(this.num_masters,this.num_slaves);
    /** enbale ahb_lite_mulilayer**/
    this.ahb_lite_multilayer = 1;
    this.ahb_lite = 1;

    for(int i=0; i< `AHB_MASTERS_NUM; i++) begin
        this.master_cfg[i].transaction_coverage_enable = 1;
        this.master_cfg[i].data_width = 32;
        this.master_cfg[i].addr_width = 36;
        this.master_cfg[i].enable_xml_gen = 1;
        this.master_cfg[i].is_active = 1;
        this.master_cfg[i].uvm_reg_enable= 0;
    end
    for(int i=0; i< `AHB_SLAVES_NUM; i++) begin
        this.slave_cfg[i].transaction_coverage_enable = 1;
        this.slave_cfg[i].addr_width = 36;
        this.slave_cfg[i].enable_xml_gen = 1;
        this.slave_cfg[i].is_active = 1;
        this.slave_cfg[0].data_width = 32;
    end
       // this.slave_cfg[0].data_width = 32;
       // this.slave_cfg[1].data_width = 32;
       // this.slave_cfg[2].data_width = 64;
       // this.slave_cfg[3].data_width = 64;
       // this.slave_cfg[4].data_width = 32;
       // this.slave_cfg[5].data_width = 64;

    this.set_addr_range(0,36'h0000_0000,36'hF_FFFF_FFFF);


	this.common_clock_mode=0;
	this.common_reset_mode=0;


  endfunction

endclass
`endif //GUARD_CUST_SVT_AHB_SYSTEM_CONFIGURATION_SV
