`ifndef I3C_SMOKE_TEST__SV
`define I3C_SMOKE_TEST__SV
class i3c_smoke_test extends i3c_base_test;
   `uvm_component_utils(i3c_smoke_test)

//   i3c_default_slv_sequence slv_seq;
   i3c_main_mst_daa_setdasa_entdaa_sequence mst_seq;
//   i3c_default_mst_sequence mst_seq;

   extern function new(string name = "i3c_smoke_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

endclass: i3c_smoke_test
//-------------------------------------------------------------------------
function i3c_smoke_test::new(string name = "i3c_smoke_test", uvm_component parent = null);
    super.new(name, parent);
       
endfunction: new
//-------------------------------------------------------------------------
function void i3c_smoke_test::build_phase(uvm_phase phase);
    super.build_phase(phase);
   
 
endfunction: build_phase
//-------------------------------------------------------------------------
task i3c_smoke_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[7:0] rx_data_q[$];
    phase.raise_objection(this);
    super.main_phase(phase);
/*
    fork
        begin
            //1.set master
            wdata=32'h0;
            noc_reg_write(`I3C0_BASE+`DEVICE_CTRL_EXTENDED, wdata );
            //2. enable intr 
            wdata = 32'hffff;
            noc_reg_write(`I3C0_BASE+`INTR_STATUS_EN, wdata );
            
            //3. set dev_addr
            wdata =0;
            wdata[22:16]='h1;//dynamic_addr
            wdata[31]='h1;
            noc_reg_write(`I3C0_BASE+`DEVICE_ADDR, wdata);

            //4.set DAT
            wdata =0;
            wdata[23:16]='hb5;// dynamic_addr
            wdata[6:0]='h0; //device static add
            noc_reg_write(`I3C0_BASE+`DEV_ADDR_TABLE_LOC1, wdata);

            //5. en i3c ctrl
            wdata =0;
            wdata=32'h1 << 31;
            noc_reg_write(`I3C0_BASE+`DEVICE_CTRL, wdata );


            //6.set broadcast ccc "setdasa 0x87"
            wdata =0;
            wdata[2:0]='h3;
            wdata[6:3]='hf;
            wdata[14:7]='h87; //ccc 0x87
            wdata[20:16]='h0;
            wdata[25:21]='h1;
            wdata[26]='h1;
            wdata[30]='h1;
            noc_reg_write(`I3C0_BASE+`COMMAND_QUEUE_PORT, wdata );    
            #10us;
            //5.
            noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
            `uvm_info(get_type_name(), $sformatf("[HURYDEBUG]intr_status data = 0x%h", rdata), UVM_LOW)
            //6.
            noc_reg_read(`I3C0_BASE+`RESPONSE_QUEUE_PORT, rdata);
            `uvm_info(get_type_name(), $sformatf("[HURYDEBUG] response queue port  data = 0x%h", rdata), UVM_LOW)
    end
     begin
            slv_seq = new("slv_seq");
            $display("[HURY0917] -----start slave seq-----\n");
            slv_seq.start(m_soc_env.i3c_env.sequencer.slave_sequencer[0]);   
            $display("[HURY0917] -----start slave seq end-----\n");

    end */
// join 
//
// -------------------------------------------------------------------------------------
// -------------------------------------dut as slave-----------------------------------------------
    fork
        begin
           //0.set static addrcfg.slave_cfg[1].i3c_od_pp_bus_speed  = 1;cfg.slave_cfg[1].i3c_od_pp_bus_speed  = 1;cfg.slave_cfg[1].i3c_od_pp_bus_speed  = 1;
            wdata=0;
            wdata[18]='h1;
            wdata[17:11]='h31;
            noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+32'h400, wdata ); 
//           uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.static_addr_en" , 1'b1);
//           uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.static_addr[6:0]" , 7'h61);

          
            //1.0 set rx buf thld     
            noc_reg_read(`I3C0_BASE+`DATA_BUFFER_THLD_CTRL, rdata );
            rdata[10:8] = 'h0;
            noc_reg_write(`I3C0_BASE+`DATA_BUFFER_THLD_CTRL, rdata );
            
            //1.set slave
            wdata=32'h1;
            noc_reg_write(`I3C0_BASE+`DEVICE_CTRL_EXTENDED, wdata );
            //2. enable intr 
            wdata = 32'hffff;
            noc_reg_write(`I3C0_BASE+`INTR_STATUS_EN, wdata );
//            noc_reg_write(`I3C0_BASE+`INTR_STATUS_EN, wdata );
            //3.set dev_ctrl
            wdata=0;
            wdata[27]='h1;
            noc_reg_write(`I3C0_BASE+`DEVICE_CTRL, wdata );
            
            //4. set dev_addr
            wdata =0;
            wdata[6:0]='h31;//static_addr
            wdata[15]='h1; 
//            wdata[22:16]='h62;//dynamic_addr
//            wdata[31]='h1; 
            noc_reg_write(`I3C0_BASE+`DEVICE_ADDR, wdata);            

            //5. en i3c ctrl
            noc_reg_read(`I3C0_BASE+`DEVICE_CTRL, rdata );
            $display("[HURY0924] -----device ctrl data :0x%h-----\n", rdata);
            rdata[31]='h1;
            noc_reg_write(`I3C0_BASE+`DEVICE_CTRL, rdata);

            // 6. wait dda
/*            noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
            `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1009]111intr_status data = 0x%h", rdata), UVM_LOW)
            while(rdata[8] != 1'b1) begin 
                noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
                `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1009]222intr_status data = 0x%h", rdata), UVM_LOW)
            end 

            `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1010]33333  ENTER i3c_read_data_from_rxfifo TASK 11111"), UVM_LOW) 
*/

            // 7. recive data
            i3c_read_data_from_rxfifo(0,2,1,rx_data_q);

        end
        begin
            #10us;
            mst_seq = new("mst_seq");
            $display("[HURY0917] -----start master seq-----\n");
//            mst_seq.start(m_soc_env.i3c_env.sequencer.master_sequencer[0]);   
            mst_seq.start(m_soc_env.i3c_env.sequencer.master_sequencer[0]);
            $display("[HURY0917] -----start master seq end-----\n");
        end 

    join


//    noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
//    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1009]intr_status data = 0x%h", rdata), UVM_LOW)



//     noc_reg_read(`I3C0_BASE+`DEV_ADDR_TABLE_LOC1, rdata);
//   `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1009] dev addr data = 0x%h", rdata), UVM_LOW)



/*    //5.
    noc_reg_read(`I3C0_BASE+`SLV_EVENT_STATUS, rdata);
    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG0923]slv_event_status data = 0x%h", rdata), UVM_LOW)

    noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG0923]intr_status data = 0x%h", rdata), UVM_LOW)

    //6.
    noc_reg_read(`I3C0_BASE+`RESPONSE_QUEUE_PORT, rdata);
    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG0923] response queue port  data = 0x%h", rdata), UVM_LOW) */

    #1us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------
`endif //I3C_SMOKE_TEST__SV
