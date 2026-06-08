`ifndef I3C0_SLAVE_RECEIVE_TRANS_TEST__SV
`define I3C0_SLAVE_RECEIVE_TRANS_TEST__SV

//`include "i3c_vip_mst_write_sequence.sv"

class i3c0_slave_receive_trans_test extends i3c_base_test;
    `uvm_component_utils(i3c0_slave_receive_trans_test)
   

//   i3c_default_slv_sequence slv_seq;
//   i3c_main_mst_daa_setdasa_entdaa_sequence mst_seq;
     i3c_vip_mst_write_sequence mst_seq;

   extern function new(string name = "i3c0_slave_receive_trans_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

endclass: i3c0_slave_receive_trans_test
//-------------------------------------------------------------------------
function i3c0_slave_receive_trans_test::new(string name = "i3c0_slave_receive_trans_test", uvm_component parent = null);
    super.new(name, parent);

       
endfunction: new
//-------------------------------------------------------------------------
function void i3c0_slave_receive_trans_test::build_phase(uvm_phase phase);
    super.build_phase(phase);
     m_i3c_intf.i3c_scb_ctrl =3'h1;
     m_i3c_intf.i3c_num_ctrl = 0;
   
endfunction: build_phase
//-------------------------------------------------------------------------
task i3c0_slave_receive_trans_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[7:0]  rx_data_q[$];
    phase.raise_objection(this);
    super.main_phase(phase);
    
    
// -------------------------------------dut as slave-----------------------------------------------
    fork
        begin          
            wdata=0;
            wdata[18]='h1;
            wdata[17:11]='h31;
            noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_STAT, wdata ); 
               
            //1.0 set rx buf thld     
            noc_reg_read(`I3C0_BASE+`DATA_BUFFER_THLD_CTRL, rdata );
            rdata[10:8] = 'h0;
            noc_reg_write(`I3C0_BASE+`DATA_BUFFER_THLD_CTRL, rdata );
            
            //1.1 set slave
            wdata=32'h1;
            noc_reg_write(`I3C0_BASE+`DEVICE_CTRL_EXTENDED, wdata );
            //2. enable intr 
            wdata = 32'hffff;
            noc_reg_write(`I3C0_BASE+`INTR_STATUS_EN, wdata );

            //3.set dev_ctrl
            wdata=0;
            wdata[27]='h1;
            noc_reg_write(`I3C0_BASE+`DEVICE_CTRL, wdata );
            
            //4. set dev_addr
            wdata =0;
            wdata[6:0]='h31;//static_addr
            wdata[15]='h1;  
            noc_reg_write(`I3C0_BASE+`DEVICE_ADDR, wdata);            

            //5. en i3c ctrl
            noc_reg_read(`I3C0_BASE+`DEVICE_CTRL, rdata );
            $display("[HURY0924] -----device ctrl data :0x%h-----\n", rdata);
            rdata[31]='h1;
            noc_reg_write(`I3C0_BASE+`DEVICE_CTRL, rdata);

            // 7. recive data
            i3c_read_data_from_rxfifo(0,2,1,rx_data_q);
            i3c_slave_rxdata_to_vip_master_post_tr(0,rx_data_q);

        end
        begin
            #10us;
            mst_seq = new("mst_seq");
            $display("[HURY0917] -----start master seq-----\n");
            mst_seq.start(m_soc_env.i3c_env.sequencer.master_sequencer[0]);
            $display("[HURY0917] -----start master seq end-----\n");
        end 

    join

    #5us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------
`endif //I3C0_SLAVE_RECEIVE_TRANS_TEST__SV
