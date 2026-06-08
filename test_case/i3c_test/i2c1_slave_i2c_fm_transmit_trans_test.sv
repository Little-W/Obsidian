`ifndef I2C1_SLAVE_I2C_FM_TRANSMIT_TRANS_TEST__SV
`define I2C1_SLAVE_I2C_FM_TRANSMIT_TRANS_TEST__SV

class i2c1_slave_i2c_fm_transmit_trans_test extends i3c_base_test;
   `uvm_component_utils(i2c1_slave_i2c_fm_transmit_trans_test)

   i3c_vip_i2c_mst_read_sequence mst_seq;

   extern function new(string name = "i2c1_slave_i2c_fm_transmit_trans_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

endclass: i2c1_slave_i2c_fm_transmit_trans_test
//-------------------------------------------------------------------------
function i2c1_slave_i2c_fm_transmit_trans_test::new(string name = "i2c1_slave_i2c_fm_transmit_trans_test", uvm_component parent = null);
    super.new(name, parent);
       
endfunction: new
//-------------------------------------------------------------------------
function void i2c1_slave_i2c_fm_transmit_trans_test::build_phase(uvm_phase phase);
    super.build_phase(phase);
    m_i3c_intf.i3c_scb_ctrl = 3'h2;  
    m_i3c_intf.i3c_num_ctrl = 1;
 
endfunction: build_phase
//-------------------------------------------------------------------------
task i2c1_slave_i2c_fm_transmit_trans_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[7:0] tx_data_q[$];
    phase.raise_objection(this);
    super.main_phase(phase);

// -------------------------------------dut as slave-----------------------------------------------
    fork
        begin         
            wdata=0;
            wdata[25]='h1; //i2c_mode
            wdata[18]='h1;
            wdata[17:11]='h31;
            noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C1_STAT, wdata ); 
            
            //1.00 set tx buf thld     
            noc_reg_read(`I3C1_BASE+`DATA_BUFFER_THLD_CTRL, rdata );
            rdata[2:0] = 'h0;
            rdata[18:16] = 'h0;
            noc_reg_write(`I3C1_BASE+`DATA_BUFFER_THLD_CTRL, rdata );
           //1.set slave
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

            noc_reg_read(`I3C1_BASE+`INTR_STATUS, rdata);            
            while(rdata[3] != 1'b1) begin 
                noc_reg_read(`I3C1_BASE+`INTR_STATUS, rdata);                
            end 
          
            //@@@  bit i3c_num, input bit[2:0] speed, input bit iscp, input bit[7:0] cmd,input bit isshortarg, input bit isread
            i3c_set_transfer_cmd(1, 0, 1, 8'h87, 0, 0,1,1);

            //---------------------------------------------------
            //6.write  data
            //@@@ 0:i3c_num, 1:data_lenth, 2:tx_thld
            i3c_wirte_data_to_txfifo(1, 1, 1, tx_data_q); 
           //-----------------------------------------------------------
           i3c_slave_txdata_to_vip_master_pre_tr(0, tx_data_q);
            
        end
        begin
            #10us;
            mst_seq = new("mst_seq");
            $display("[HURY0917] -----start master seq-----\n");  
            mst_seq.start(m_soc_env.i3c_env.sequencer.master_sequencer[0]);
            $display("[HURY0917] -----start master seq end-----\n");
        end 

    join

    #1us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------
`endif //I2C1_SLAVE_I2C_FM_TRANSMIT_TRANS_TEST__SV
