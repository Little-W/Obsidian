`ifndef I3C1_SLAVE_TEST_MODE_TEST__SV
`define I3C1_SLAVE_TEST_MODE_TEST__SV


class i3c1_slave_test_mode_test extends i3c_base_test;
    `uvm_component_utils(i3c1_slave_test_mode_test)

     i3c_vip_mst_write_sequence mst_seq;

   extern function new(string name = "i3c1_slave_test_mode_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

endclass: i3c1_slave_test_mode_test
//-------------------------------------------------------------------------
function i3c1_slave_test_mode_test::new(string name = "i3c1_slave_test_mode_test", uvm_component parent = null);
    super.new(name, parent);


endfunction: new
//-------------------------------------------------------------------------
function void i3c1_slave_test_mode_test::build_phase(uvm_phase phase);
    super.build_phase(phase);
     m_i3c_intf.i3c_scb_ctrl =3'h1;
     m_i3c_intf.i3c_num_ctrl = 1;

endfunction: build_phase
//-------------------------------------------------------------------------
task i3c1_slave_test_mode_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[7:0]  rx_data_q[$];
    phase.raise_objection(this);
    super.main_phase(phase);


// -------------------------------------dut as slave-----------------------------------------------

            wdata=0;
            wdata[18]='h1;
            wdata[17:11]='h31;
            noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C1_STAT, wdata );

            //1.0 set rx buf thld
            noc_reg_read(`I3C1_BASE+`DATA_BUFFER_THLD_CTRL, rdata );
            rdata[10:8] = 'h0;
            noc_reg_write(`I3C1_BASE+`DATA_BUFFER_THLD_CTRL, rdata );

            //1.1 set slave
            wdata=32'h1;
            noc_reg_write(`I3C1_BASE+`DEVICE_CTRL_EXTENDED, wdata );
            //2. enable intr
            wdata = 32'hffff;
            noc_reg_write(`I3C1_BASE+`INTR_STATUS_EN, wdata );

            //3.set dev_ctrl
            wdata=0;
            wdata[27]='h1;
            noc_reg_write(`I3C1_BASE+`DEVICE_CTRL, wdata );

            //4. set dev_addr
            wdata =0;
            wdata[6:0]='h31;//static_addr
            wdata[15]='h1;
            noc_reg_write(`I3C1_BASE+`DEVICE_ADDR, wdata);

            //5. en i3c ctrl
            noc_reg_read(`I3C1_BASE+`DEVICE_CTRL, rdata );
            $display("[HURY0924] -----device ctrl data :0x%h-----\n", rdata);
            rdata[31]='h1;
            noc_reg_write(`I3C1_BASE+`DEVICE_CTRL, rdata);

            uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.slv_test_mode", 1'b1);
            #1us;
            uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.slv_test_mode", 1'b0);
    #5us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------
`endif //I3C1_SLAVE_TEST_MODE_TEST__SV
