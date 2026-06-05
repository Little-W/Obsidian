
/**
 * Abstract:
 * class 'apb_ral_env' is extended from uvm_env base class.  It implements
 * the build phase to construct the structural elements of this environment.
 *
 * apb_ral_env is the testbench environment, which constructs two APB System
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
`ifndef GUARD_APB_RAL_ENV_SV1
`define GUARD_APB_RAL_ENV_SV1
//`include "ral_apb_svt_uvm_basic_slave.sv"



import uvm_pkg::*;
`include "uvm_macros.svh"

`include "svt_apb.uvm.pkg"
import svt_apb_uvm_pkg::*;



`include "apb_virtual_sequencer.sv"
`include "apb_shared_cfg.sv"






class apb_ral_env extends uvm_env;

  /** APB VIP Master ENV */
  svt_apb_system_env apb_master_env;

  /** APB VIP Slave  ENV */
  svt_apb_system_env apb_slave_env;

  /** Virtual Sequencer */
  apb_virtual_sequencer sequencer;

  /** APB System Configuration */
  apb_shared_cfg cfg;

  // Declare RAL model.

  // HDL path to RAL register model
  string hdl_path;

  /** UVM Component Utility macro */
  `uvm_component_utils_begin(apb_ral_env)
   `uvm_field_string(hdl_path, UVM_DEFAULT)
  `uvm_component_utils_end

  /** Class Constructor */
  function new (string name="apb_ral_env", uvm_component parent=null);
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



    /** Apply the configuration to the Master ENV */
    uvm_config_db#(svt_apb_system_configuration)::set(this, "apb_master_env", "cfg", cfg.master_cfg);

    /** Apply the configuration to the Slave ENV */


    /** Configure the master and slave agents as UVM_ACTIVE or UVM_PASSIVE */
    uvm_config_db#(uvm_active_passive_enum)::set(this, "apb_master_env.master", "is_active", UVM_ACTIVE);
 
    //uvm_config_db#(uvm_active_passive_enum)::set(this, "apb_master_env.slave[0]", "is_active", UVM_ACTIVE);
    uvm_config_db#(uvm_active_passive_enum)::set(this, "apb_master_env.slave[0]", "is_active", UVM_PASSIVE);





    /** Configure the master and slave agents as UVM_ACTIVE or UVM_PASSIVE */

    /** For the backdoor HDL path to the RTL slave registers */
    if (!uvm_config_db#(string)::get(this, "", "hdl_path", hdl_path))
      hdl_path = "test_top";

    /** Construct the system agents */
    apb_master_env = svt_apb_system_env::type_id::create("apb_master_env", this);


    /** Construct the virtual sequencer */
    sequencer = apb_virtual_sequencer::type_id::create("sequencer", this);
    //sequencer_ba = apb_virtual_sequencer::type_id::create("sequencer_ba", this);










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
