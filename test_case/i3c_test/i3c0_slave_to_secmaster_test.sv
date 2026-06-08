`ifndef I3C0_SLAVE_TO_SECMASTER_TEST__SV
`define I3C0_SLAVE_TO_SECMASTER_TEST__SV
class i3c0_slave_to_secmaster_test extends i3c_base_test;
   `uvm_component_utils(i3c0_slave_to_secmaster_test)
   i3c_vip_secmst_ibi_sequence secmst_seq;

   extern function new(string name = "i3c0_slave_to_secmaster_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

endclass: i3c0_slave_to_secmaster_test
//-------------------------------------------------------------------------
function i3c0_slave_to_secmaster_test::new(string name = "i3c0_slave_to_secmaster_test", uvm_component parent = null);
    super.new(name, parent);
       
endfunction: new
//-------------------------------------------------------------------------
function void i3c0_slave_to_secmaster_test::build_phase(uvm_phase phase);
    super.build_phase(phase);
    
    cfg.master_cfg[0].is_active = 1;
    cfg.master_cfg[1].is_active = 0;
    cfg.master_cfg[1].device_static_address = 'h31;
    cfg.master_cfg[1].device_dynamic_address = 'h34;
    m_i3c_intf.i3c_scb_ctrl = 3'h2;
    m_i3c_intf.i3c_num_ctrl = 0;
    
    
endfunction: build_phase
//-------------------------------------------------------------------------
task i3c0_slave_to_secmaster_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[7:0] tx_data_q[$];
    bit [6:0] dev_addr = 7'h30;
    phase.raise_objection(this);
    super.main_phase(phase);
    
    wdata=0;
        wdata[18]='h1;
        wdata[17:11]='h31;
        noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_STAT, wdata ); 
            
        //1.0 set tx buf thld     
        noc_reg_read(`I3C0_BASE+`DATA_BUFFER_THLD_CTRL, rdata );
        rdata[2:0] = 'h0;
        rdata[18:16] = 'h0;
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
//        wdata[22:16]='h34;//dynamic_addr
//        wdata[31]='h1;
        noc_reg_write(`I3C0_BASE+`DEVICE_ADDR, wdata);            

        //5. en i3c ctrl
        noc_reg_read(`I3C0_BASE+`DEVICE_CTRL, rdata );
        rdata[31]='h1;
        noc_reg_write(`I3C0_BASE+`DEVICE_CTRL, rdata);
        
    fork
      begin       
        //-----------------------------------------------------------------------------
        #50;
        //wait setdasa done
        noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);       
        while(rdata[8] != 1'b1) begin 
          noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
          `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1117] dynamic addr sts = 0x%h", rdata), UVM_LOW)
        end
        // MR        
        noc_reg_read(`I3C0_BASE+`SLV_EVENT_STATUS, rdata );
        `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1105] mr_en data = 0x%h", rdata), UVM_LOW)

        if(rdata[1] == 1'b1) begin
          //set mr 
          noc_reg_read(`I3C0_BASE+`SLV_INTR_REQ, rdata );
          rdata[3]='h1;
          noc_reg_write(`I3C0_BASE+`SLV_INTR_REQ, rdata );

          //wait ibi_update_stat
          noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata );
          while(rdata[12] !=1'b1) begin
            noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata );
          end 
          
          #5;
          // read ibi_sts
          noc_reg_read(`I3C0_BASE+`SLV_INTR_REQ, rdata );
          
         
          if(rdata[9:8]==2'b01)
            `uvm_info(get_type_name(), "==MR ACK== ", UVM_LOW)
          else
            `uvm_error(get_type_name(), "==MR NACK== ")

        end 

        else begin
          `uvm_error(get_type_name(), "==Need To the Current Master Send ENEC CCC!!!==")
        end 
        
        //wait busowner update sts
        noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata );
        while(rdata[13] !=1'b1) begin
          noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata );
        end

        //set device ctrl[resume=1]
        noc_reg_read(`I3C0_BASE+`DEVICE_CTRL, rdata );
        rdata[30]='h1;
        noc_reg_write(`I3C0_BASE+`DEVICE_CTRL, rdata);

        // set dev addr table
        wdata=0;
        wdata[23:16]= 'hb0;// dev dynamic_addr
//      wdata[6:0]  = static_addr; //dev static addr 
        noc_reg_write(`I3C0_BASE+`DEV_ADDR_TABLE_LOC1, wdata);
 
        //3.set transfer arg [@--0:i3c_num 1:data_lenth --@]
        noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
        while(rdata[3] != 1'b1) begin
            noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
        end
        //4.
        i3c_set_transfer_arg(0,4);

        //5.
        noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
        while(rdata[3] != 1'b1) begin
            noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
        end
        //6.set transfer command  ( 0:i3c_num, 1:bit[2:0] speed, 2:bit iscp, 3:bit[7:0] cmd, 4: bit isshortarg, 5: bit isread)
        i3c_set_transfer_cmd(0,0,0,0,0,0,2,1);//speed:sdr0:0

        //7.write data to txffifo
        // @@@### 0: i3c_num, 1:data_lenth, 2:tx_thld ###
        i3c_wirte_data_to_txfifo(0, 1, 1, tx_data_q);  
        i3c_secmaster_txdata_to_vip_master_pre_tr(0,tx_data_q);
      end
      begin
 //       #2us;
        secmst_seq = new("secmst_seq");
        $display("[HURY0917] -----start master seq-----\n");
        secmst_seq.start(m_soc_env.i3c_env.sequencer.master_sequencer[0]);
        $display("[HURY0917] -----start master seq end-----\n");
          
      end
  join  
 
    #20us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------
`endif //I3C0_SLAVE_TO_SECMASTER_TEST__SV
