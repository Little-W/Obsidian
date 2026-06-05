
/**
 * Abstract:
 * class 'ahb_ral_env' is extended from uvm_env base class.  It implements
 * the build phase to construct the structural elements of this environment.
 *
 * ahb_ral_env is the testbench environment, which constructs the AHB System
 * ENV in the build_phase method using the UVM factory service.  The AHB System
 * ENV  is the top level component provided by the AHB VIP. The AHB System ENV
 * in turn, instantiates constructs the AHB Master and Slave agents.
 *
 * ahb_ral_env also constructs the virtual sequencer. This virtual sequencer
 * in the testbench environment obtains a handle to the reset interface using
 * the config db.  This allows reset sequences to be written for this virtual
 * sequencer.
 *
 * The simulation ends after all the objections are dropped.  This is done by
 * using objections provided by phase arguments.
 */
`ifndef GUARD_AHB_RAL_ENV_SV
`define GUARD_AHB_RAL_ENV_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
import svt_ahb_uvm_pkg::*;





`include "ahb_virtual_sequencer.sv"
`include "cust_svt_ahb_system_configuration.sv"

// UVM Environment class with RAL extensions
class ahb_ral_env extends uvm_env;

  /** AHB System ENV */
  svt_ahb_system_env   ahb_system_env;

  /** Virtual Sequencer */
  ahb_virtual_sequencer sequencer;

  /** AHB System Configuration */
  cust_svt_ahb_system_configuration cfg;

  // Declare RAL model.

   // HDL path to RAL register model
   string hdl_path;

  /** UVM Component Utility macro */
  `uvm_component_utils_begin(ahb_ral_env)
    `uvm_field_string(hdl_path, UVM_DEFAULT)
  `uvm_component_utils_end

  /** Class Constructor */
  function new (string name="ahb_ral_env", uvm_component parent=null);
    super.new (name, parent);
  endfunction

  /** Build the AHB System ENV */
  virtual function void build_phase(uvm_phase phase);
    `uvm_info("build_phase", "Entered...",UVM_LOW)

    super.build_phase(phase);

    /**
     * Check if the configuration is passed to the environment.
     * If not then create the configuration and pass it to the agent.
     */
    if (!uvm_config_db#(cust_svt_ahb_system_configuration)::get(this, "", "cfg", cfg)) begin
      cfg = cust_svt_ahb_system_configuration::type_id::create("cfg");
    end

    /** Apply the configuration to the System ENV */
    uvm_config_db#(svt_ahb_system_configuration)::set(this, "ahb_system_env", "cfg", cfg);

     /** For the backdoor HDL path to the RTL slave registers */
     if (!uvm_config_db#(string)::get(this, "", "hdl_path", hdl_path))
       hdl_path = "test_top";

    /** Construct the system agent */
    ahb_system_env = svt_ahb_system_env::type_id::create("ahb_system_env", this);

    /** Construct the virtual sequencer */
    sequencer = ahb_virtual_sequencer::type_id::create("sequencer", this);


    /** Check if regmodel is passed to env if not then create and lock it. */
   // if (regmodel == null) begin
   //    regmodel = i2c_rgm::type_id::create("regmodel");
   //    regmodel.build();
   //    regmodel.set_hdl_path_root(hdl_path);
   //    `uvm_info("build_phase", "Reg Model created", UVM_LOW)
   //    regmodel.lock_model();
   // end

   // uvm_config_db#(uvm_reg_block)::set(this,"ahb_system_env.master[0]", "ahb_regmodel", regmodel);

    `uvm_info("build_phase", "Exiting...", UVM_LOW)
  endfunction

  /** Connect additional components to the AHB System ENV */
  virtual function void connect_phase(uvm_phase phase);
    super.connect_phase(phase);

    /**
      * Set the location of the slave[0] so the reg model can use it for backdoor access
      */
    //uvm_resource_db#(svt_ahb_slave_agent)::set("env", "slave0", ahb_system_env.slave[0], this);

  endfunction

   // Reset the register model
   task reset_phase(uvm_phase phase);
      phase.raise_objection(this, "Resetting regmodel");
      //regmodel.reset();
      `uvm_info("reset_phase", "Reg Model reset", UVM_LOW)
      phase.drop_objection(this);
   endtask
endclass

`endif // GUARD_AHB_RAL_ENV_SV
