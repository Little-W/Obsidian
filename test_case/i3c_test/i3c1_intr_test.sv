`ifndef I3C1_INTR_TEST__SV
`define I3C1_INTR_TEST__SV

class i3c1_intr_test extends i3c_base_test;
   `uvm_component_utils(i3c1_intr_test)
   i3c_vip_mst_write_sequence mst_seq;

   extern function new(string name = "i3c1_intr_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

endclass: i3c1_intr_test
//-------------------------------------------------------------------------
function i3c1_intr_test::new(string name = "i3c1_intr_test", uvm_component parent = null);
    super.new(name, parent);

endfunction: new
//-------------------------------------------------------------------------
function void i3c1_intr_test::build_phase(uvm_phase phase);
    super.build_phase(phase);
    m_i3c_intf.i3c_scb_ctrl =3'h6;
    m_i3c_intf.i3c_num_ctrl = 'h4;

endfunction: build_phase
//-------------------------------------------------------------------------

 //---------------------------------------------------------------------------------------------
task i3c1_intr_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata_h ;
    bit[31:0] rdata_l ;
    phase.raise_objection(this);
    super.main_phase(phase);

    wait_label('h12345678);

    mst_seq = new("mst_seq");
    $display("[HURY0917] -----start master seq-----\n");
    mst_seq.start(m_soc_env.i3c_env.sequencer.master_sequencer[0]);
    $display("[HURY0917] -----start master seq end-----\n");
    #10us;
    check_simend();
    #1us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------


`endif //I3C1_INTR_TEST__SV
