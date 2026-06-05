
/**
 * Abstract:
 * axi_master_wr_rd_reorder_sequence is used by test to provide initiator scenario
 * information to the Master agent present in the System agent.  This class
 * defines a sequence in which AXI WRITE sequence and READ sequence
 * is generated using `uvm_do_with macros.
 *
 * Execution phase: main_phase
 * Sequencer: Master agent sequencer
 */

`ifndef GUARD_AXI_MASTER_WR_RD_REORDER_SEQUENCE_SV
`define GUARD_AXI_MASTER_WR_RD_REORDER_SEQUENCE_SV

class axi_master_wr_rd_reorder_sequence extends svt_axi_master_base_sequence;

  /** Parameter that controls the number of transactions that will be generated */
  int unsigned sequence_length = 4;
  rand  bit [39:0] waddr;
  /** Constrain the sequence length to a reasonable value */
  constraint reasonable_sequence_length {
    sequence_length <= 100;
  }

  /** UVM Object Utility macro */
  `uvm_object_utils(axi_master_wr_rd_reorder_sequence)

  svt_axi_master_transaction write_tran[$],read_tran[$];

  /** Class Constructor */
  function new(string name="axi_master_wr_rd_reorder_sequence");
    super.new(name);
  endfunction

  virtual task body();
    bit status;
    `uvm_info("body", "Entered ...", UVM_LOW)

    super.body();

    status = uvm_config_db #(int unsigned)::get(null, get_full_name(), "sequence_length", sequence_length);
    `uvm_info("body", $sformatf("sequence_length is %0d as a result of %0s.", sequence_length, status ? "config DB" : "randomization"), UVM_LOW);

    fork
    forever begin
      get_response(rsp);
    end
    join_none

    for (int i = 0;i < sequence_length;i++) begin
      `ifndef SVT_UVM_1800_2_2017_OR_HIGHER
        `uvm_do_with(write_tran[i],
        {
          xact_type == svt_axi_transaction::WRITE;

          id == i%4 ;
          addr dist {[40'h0008:40'hF_0000]};
          //addr < 36'hfffff;
          addr_valid_delay == 0;
          data_before_addr == 0;
          burst_type   == svt_axi_transaction::INCR;
          bready_delay == 0;
          foreach(wvalid_delay[ix]) {
            wvalid_delay[ix] == 0;
          }
        })
      `else
        `uvm_do(write_tran[i],,,
        {
          xact_type == svt_axi_transaction::WRITE;
          if (i == 0) {
            id == 0;
          }
          else {
            id == 1;
          }
          addr_valid_delay == 0;
          data_before_addr == 0;
          burst_type   == svt_axi_transaction::INCR;
          bready_delay == 0;
          foreach(wvalid_delay[ix]) {
            wvalid_delay[ix] == 0;
          }
        })
      `endif
    end
    for (int i = 0;i <sequence_length;i++) begin
      write_tran[i].wait_for_transaction_end();
    end

      for (int x = 0;x < sequence_length;x++) begin
      `ifndef SVT_UVM_1800_2_2017_OR_HIGHER
        `uvm_do_with(read_tran[x],
        {
          //addr < 36'hfffff;
           addr dist {[40'h0008:40'hF_0000]};
          xact_type == svt_axi_transaction::READ;
          id == x%4+4;
          addr_valid_delay == 0;
          data_before_addr == 0;
          foreach(rready_delay[i]) {
            rready_delay[i] == 0;
          }
        })
      `else
        `uvm_do(read_tran[x],,,
        {
          xact_type == svt_axi_transaction::READ;
          if (x == 0) {
            id == 10;
          }
          else {
            id == 20;
          }
          addr_valid_delay == 0;
          data_before_addr == 0;
          foreach(rready_delay[i]) {
            rready_delay[i] == 0;
          }
        })
      `endif
    end
    for (int x = 0;x <sequence_length;x++) begin
      read_tran[x].wait_for_transaction_end();
    end

    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass: axi_master_wr_rd_reorder_sequence

class axi_master_wr_reorder_sequence extends svt_axi_master_base_sequence;
    bit [39:0]  waddr;
    bit [63:0]  wdata[];
    bit [1:0]   bur_sel;
    bit [1:0]   id_sel;
  /** Parameter that controls the number of transactions that will be generated */
   int unsigned sequence_length = 1;

  /** Constrain the sequence length to a reasonable value */
  constraint reasonable_sequence_length {
    sequence_length <= 100;
  }

  /** UVM Object Utility macro */
  `uvm_object_utils(axi_master_wr_reorder_sequence)


  /** Class Constructor */
  function new(string name="axi_master_wr_reorder_sequence");
    super.new(name);
  endfunction

  virtual task body();
    svt_axi_master_transaction write_tran;
    svt_configuration get_cfg;
    bit status;
    `uvm_info("body", "Entered ...", UVM_LOW)

    super.body();

    p_sequencer.get_cfg(get_cfg);
    if (!$cast(cfg, get_cfg)) begin
      `uvm_fatal("body", "Unable to $cast the configuration to a svt_axi_port_configuration class");
    end

    fork
    forever begin
      get_response(rsp);
           `uvm_info("body", "get rsp ...", UVM_LOW)
    end
    join_none

    for (int i = 0;i < sequence_length;i++) begin
            `uvm_create(write_tran)
           `uvm_info("body", "create tr ...", UVM_LOW)
            write_tran.addr      = waddr;
            write_tran.port_cfg     = cfg;
            write_tran.xact_type = svt_axi_transaction::WRITE;
            write_tran.burst_size = svt_axi_transaction::BURST_SIZE_64BIT;
            write_tran.atomic_type  = svt_axi_transaction::NORMAL;
            if(bur_sel == 2'b00)
                write_tran.burst_type = svt_axi_transaction::FIXED;
            else if(bur_sel == 2'b01)
                write_tran.burst_type = svt_axi_transaction::INCR;
            else if(bur_sel == 2'b10)
                write_tran.burst_type = svt_axi_transaction::WRAP;
            else
                write_tran.burst_type = svt_axi_transaction::INCR;
            write_tran.id = id_sel;
            write_tran.data         = new[write_tran.burst_length];
            write_tran.wstrb        = new[write_tran.burst_length];
            write_tran.wvalid_delay = new[write_tran.burst_length];
            write_tran.data_user    = new[write_tran.burst_length];

            foreach(write_tran.data[i]) begin
                  write_tran.data[i] = wdata[i];
            end
            foreach(write_tran.wstrb[i]) begin
                  write_tran.wstrb[i] = 8'hff;
            end
            foreach(write_tran.wvalid_delay[i]) begin
                  write_tran.wvalid_delay[i] = 0;
            end
            `uvm_send(write_tran);
           `uvm_info("body", "postsend tr ...", UVM_LOW)
           get_response(rsp);
    end
  //  for (int i = 0;i <sequence_length;i++) begin
  //    write_tran.wait_for_transaction_end();
  //  end

    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass: axi_master_wr_reorder_sequence

class axi_master_rd_reorder_sequence extends svt_axi_master_base_sequence;
    bit [1:0]   bur_sel;
    bit [1:0]   id_sel;
    bit [39:0] raddr;
    bit [63:0] rdata[];
  /** Parameter that controls the number of transactions that will be generated */
   int unsigned sequence_length = 1;

  /** Constrain the sequence length to a reasonable value */
  constraint reasonable_sequence_length {
    sequence_length <= 100;
  }

  /** UVM Object Utility macro */
  `uvm_object_utils(axi_master_rd_reorder_sequence)

  svt_axi_master_transaction read_tran;

  /** Class Constructor */
  function new(string name="axi_master_rd_reorder_sequence");
    super.new(name);
  endfunction

  virtual task body();
    bit status;
    `uvm_info("body", "Entered ...", UVM_LOW)

    super.body();

    fork
    forever begin
      get_response(rsp);
      //rdata=rsp.data;
    end
    join_none

    for (int i = 0;i < sequence_length;i++) begin
          `uvm_create(read_tran)
          read_tran.burst_length = 4;
          read_tran.rresp        = new[read_tran.burst_length];
          read_tran.data         = new[read_tran.burst_length];
          read_tran.addr         = raddr;
          read_tran.xact_type    = svt_axi_transaction::READ;
          read_tran.burst_size   = svt_axi_transaction::BURST_SIZE_64BIT;
          read_tran.atomic_type  = svt_axi_transaction::NORMAL;
          if(bur_sel == 2'b00)
              read_tran.burst_type = svt_axi_transaction::FIXED;
          else if(bur_sel == 2'b01)
              read_tran.burst_type = svt_axi_transaction::INCR;
          else if(bur_sel == 2'b10)
              read_tran.burst_type = svt_axi_transaction::WRAP;
          else
              read_tran.burst_type = svt_axi_transaction::INCR;
          read_tran.id = id_sel;
          read_tran.addr_valid_delay= 0;
          read_tran.data_before_addr = 0;
        read_tran.rready_delay = new[read_tran.burst_length];
        foreach(read_tran.rready_delay[ix])begin
            read_tran.rready_delay[ix] = 0;
        end
        `uvm_send(read_tran);
    end
   // for (int i = 0;i <sequence_length;i++) begin
   //   read_tran.wait_for_transaction_end();
   // end

    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass: axi_master_rd_reorder_sequence
`endif // GUARD_AXI_MASTER_WR_RD_REORDER_SEQUENCE_SV
