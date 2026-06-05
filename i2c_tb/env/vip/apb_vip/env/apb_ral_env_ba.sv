
/**
 * Abstract:
 * class 'apb_ral_env_ba' is extended from uvm_env base class.  It implements
 * the build phase to construct the structural elements of this environment.
 *
 * apb_ral_env_ba is the testbench environment, which constructs two APB System
 * ENVs in the build_phase method using the UVM factory service.  The APB System
 * ENV  is the top level component provided by the APB VIP. The APB System ENV
 * in turn, instantiates constructs the APB Master and Slave agents.
 *
 * apb_ral env also constructs the virtual sequencer. This virtual sequencer
 * in the testbench environment obtains a handle to the reset interface using
 * the config db.  This allows reset sequences to be written for this virtual
 * sequencer.
 *
 * The simulation ends after all the objections are dropped.  This is done by
 * using objections provided by phase arguments.
 */
`ifndef GUARD_APB_RAL_ENV_BA_SV1
`define GUARD_APB_RAL_ENV_BA_SV1
//`include "ral_apb_svt_uvm_basic_slave.sv"

`include "apb_virtual_sequencer.sv"
`include "apb_shared_cfg.sv"

class apb_ral_env_ba extends uvm_env;

  /** APB VIP Master ENV */
  svt_apb_system_env apb_master_env;

  /** APB VIP Slave  ENV */
  svt_apb_system_env apb_slave_env;

  /** Virtual Sequencer */
  apb_virtual_sequencer sequencer;

  /** APB System Configuration */
  apb_shared_cfg cfg;

  // Declare RAL model.


   npu_barrier_rgm regmodel_ba ;



  // HDL path to RAL register model
  string hdl_path;

  /** UVM Component Utility macro */
  `uvm_component_utils_begin(apb_ral_env_ba)
   `uvm_field_string(hdl_path, UVM_DEFAULT)
  `uvm_component_utils_end

  /** Class Constructor */
  function new (string name="apb_ral_env_ba", uvm_component parent=null);
    super.new (name, parent);
  endfunction

  /** Build the APB System ENV */
  virtual function void build_phase(uvm_phase phase);
    `uvm_info("build_phase", "Entered...",UVM_LOW)







    super.build_phase(phase);



    /**
     * Check if the configuration is passed to the environment.
     * If not then create the configuration and pass it to the VIP ENV.
     */
    if (!uvm_config_db#(apb_shared_cfg)::get(this, "", "cfg", cfg)) begin
      `uvm_fatal("apb_env","cannot get cfg")

      //cfg = apb_shared_cfg::type_id::create("cfg", this);
    end


  //  if(!uvm_config_db#(i2c_rgm)::get(this,"","rgm",regmodel))
  //    `uvm_fatal("apb_env","cannot get regmodel")

    cfg.master_cfg.apb5_enable = 0;
    cfg.master_cfg.slave_cfg[0].pauser_width = 4;

    cfg.slave_cfg.apb5_enable = 0;
    cfg.slave_cfg.slave_cfg[0].pauser_width = 4;
    cfg.slave_cfg.is_active = 0;
    cfg.slave_cfg.slave_cfg[0].is_active = 1;
    if($test$plusargs("ba_ack_delay"))
    cfg.slave_cfg.slave_cfg[0].default_pready = 0;

//    cfg.slave_cfg.protocol_checks_enable = 0;  //TODO
    //cfg.slave_cfg.slave_cfg[0].protocol_checks_enable = 0;  //TODO

    /** Apply the configuration to the Master ENV */
    uvm_config_db#(svt_apb_system_configuration)::set(this, "apb_master_env", "cfg", cfg.master_cfg);

    /** Apply the configuration to the Slave ENV */
    uvm_config_db#(svt_apb_system_configuration)::set(this, "apb_slave_env", "cfg", cfg.slave_cfg);

    /** Configure the master and slave agents as UVM_ACTIVE or UVM_PASSIVE */
    uvm_config_db#(uvm_active_passive_enum)::set(this, "apb_master_env.master", "is_active", UVM_ACTIVE);
    uvm_config_db#(uvm_active_passive_enum)::set(this, "apb_master_env.slave[0]", "is_active", UVM_PASSIVE);


//    uvm_config_db#(uvm_active_passive_enum)::set(this, "apb_slave_env.master", "is_active", UVM_PASSIVE);
//      for (int i=0;i<`APB_SLAVES_NUM;i++) begin
//        uvm_config_db#(uvm_active_passive_enum)::set(this, "apb_slave_env.slave[i]", "is_active", UVM_ACTIVE);
//      end


    /** Configure the master and slave agents as UVM_ACTIVE or UVM_PASSIVE */


    /** For the backdoor HDL path to the RTL slave registers */
    if (!uvm_config_db#(string)::get(this, "", "hdl_path", hdl_path))
      hdl_path = "test_top";

    /** Construct the system agents */
    apb_master_env = svt_apb_system_env::type_id::create("apb_master_env", this);
    apb_slave_env = svt_apb_system_env::type_id::create("apb_slave_env", this);

    /** Construct the virtual sequencer */
    sequencer = apb_virtual_sequencer::type_id::create("sequencer", this);
    //sequencer_ba = apb_virtual_sequencer::type_id::create("sequencer_ba", this);







    /** Check if regmodel is passed to env if not then create and lock it. */
   // if (regmodel == null) begin
   //     regmodel = i2c_rgm::type_id::create("regmodel");
   //    regmodel.build();
   //     regmodel.set_hdl_path_root(hdl_path);
   //     `uvm_info("build_phase", "Reg Model created", UVM_LOW)
   //     regmodel.lock_model();
   // end

    uvm_config_db#(uvm_reg_block)::set(this,"apb_master_env.master", "apb_regmodel", regmodel_ba);

    `uvm_info("build_phase", "Exiting...", UVM_LOW)
  endfunction

  function void connect_phase(uvm_phase phase);
    `uvm_info("connect_phase", "Entered...",UVM_LOW)
    /**
      * Set the location of the slave[0] so the reg model can use it for backdoor access
      */
   // uvm_resource_db#(svt_apb_slave_agent)::set("env", "slave0", apb_slave_env.slave[0], this);

    `uvm_info("connect_phase", "Exiting...", UVM_LOW)
  endfunction : connect_phase

  // Reset the register model
  task reset_phase(uvm_phase phase);
    phase.raise_objection(this, "Resetting regmodel");
    //regmodel.reset();
    phase.drop_objection(this);
  endtask


endclass

`endif // GUARD_APB_RAL_ENV_SV
