
/**
 * Abstract:
 * ahb_master_wr_rd_sequence is used by test to provide initiator scenario
 * information to the Master agent present in the System agent.  This class
 * defines a sequence in which a random AHB WRITE followed by a random AHB READ
 * sequence is generated using `uvm_do_with macros.
 *
 * Execution phase: main_phase
 * Sequencer: Master agent sequencer
 */

`ifndef GUARD_AHB_MASTER_WR_RD_SEQUENCE_SV
`define GUARD_AHB_MASTER_WR_RD_SEQUENCE_SV

class ahb_master_wr_sequence extends svt_ahb_master_transaction_base_sequence;

  /** Parameter that controls the number of transactions that will be generated */
  rand int unsigned sequence_length = 10;
    bit [63:0] wdata;
    bit [35:0] waddr;
  /** Constrain the sequence length to a reasonable value */
  constraint reasonable_sequence_length {
    sequence_length <= 100;
  }

  /** UVM Object Utility macro */
  `uvm_object_utils(ahb_master_wr_sequence)

  /** Class Constructor */
  function new(string name="ahb_master_wr_sequence");
    super.new(name);
  endfunction

  virtual task body();
    bit status;
    `uvm_info("body", "Entered ...", UVM_LOW)

    super.body();

    status = uvm_config_db #(int unsigned)::get(null, get_full_name(), "sequence_length", sequence_length);
    `uvm_info("body", $sformatf("sequence_length is %0d as a result of %0s.", sequence_length, status ? "config DB" : "randomization"), UVM_LOW);

        `uvm_do_with(req,
        {
          xact_type == svt_ahb_transaction::WRITE;burst_type== svt_ahb_transaction::SINGLE;data[0]==wdata;burst_size==1;addr==waddr;
        })
      req.print();
      get_response(rsp);

    `uvm_info("body", "AHB WRITE transaction completed", UVM_LOW);
    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass: ahb_master_wr_sequence



class ahb_master_rd_sequence extends svt_ahb_master_transaction_base_sequence;

  /** Parameter that controls the number of transactions that will be generated */
  rand int unsigned sequence_length = 10;
  bit [63:0] rdata;
  bit [35:0] raddr;
  /** Constrain the sequence length to a reasonable value */
  constraint reasonable_sequence_length {
    sequence_length <= 100;
  }

  /** UVM Object Utility macro */
  `uvm_object_utils(ahb_master_rd_sequence)

  /** Class Constructor */
  function new(string name="ahb_master_rd_sequence");
    super.new(name);
  endfunction

  virtual task body();
    bit status;
    `uvm_info("body", "Entered ...", UVM_LOW)

    super.body();

    status = uvm_config_db #(int unsigned)::get(null, get_full_name(), "sequence_length", sequence_length);
    `uvm_info("body", $sformatf("sequence_length is %0d as a result of %0s.", sequence_length, status ? "config DB" : "randomization"), UVM_LOW);

        `uvm_do_with(req,
        {
          xact_type == svt_ahb_transaction::READ;burst_type== svt_ahb_transaction::SINGLE;addr==raddr;burst_size==1;
        })

      get_response(rsp);

      req.print();
      rdata=rsp.data[0];

      //foreach(rsp.data[i])begin
      //  rdata[i]=rsp.data[i];
      //end


      $display("33333 %h",rdata );
      //$display(rsp );


    `uvm_info("body", "AHB READ transaction completed", UVM_LOW);
    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass: ahb_master_rd_sequence





class ahb_master_burst_wr_sequence extends svt_ahb_master_transaction_base_sequence;

    bit [31:0] wdata[];
    bit [35:0] waddr;
    bit [2:0]  bur_sel;
    rand int unsigned sequence_length = 10;

    constraint reasonable_sequence_length {
        sequence_length <= 100;
    }

    `uvm_object_utils(ahb_master_burst_wr_sequence)

    function new(string name="ahb_master_burst_wr_sequence");
        super.new(name);
    endfunction

    virtual task body();
        bit status;
        super.body();

        status = uvm_config_db #(int unsigned)::get(null, get_full_name(), "sequence_length", sequence_length);
        `uvm_info("body", $sformatf("sequence_length is %0d as a result of %0s.", sequence_length, status ? "config DB" : "randomization"), UVM_LOW);

        `uvm_do_with(req, {
                            xact_type  == svt_ahb_transaction::WRITE;
                            if(bur_sel == 3'b000)
                                {burst_type == svt_ahb_transaction::INCR4;
                                 data.size == 4;}
                            else if(bur_sel == 3'b001)
                                {burst_type == svt_ahb_transaction::WRAP4;
                                 data.size == 4;}
                            else if(bur_sel == 3'b010)
                                {burst_type == svt_ahb_transaction::INCR8;
                                 data.size == 8;}
                            else if(bur_sel == 3'b011)
                                {burst_type == svt_ahb_transaction::WRAP8;
                                 data.size == 8;}
                            else if(bur_sel == 3'b100)
                                {burst_type == svt_ahb_transaction::INCR16;
                                 data.size == 16;}
                            else if(bur_sel == 3'b101)
                                {burst_type == svt_ahb_transaction::WRAP16;
                                 data.size == 16;}
                            else
                                {burst_type == svt_ahb_transaction::INCR4;
                                 data.size == 4;}
                            foreach(data[i]) data[i] == wdata[i];
                            burst_size == 3;  // 64-bit
                            addr == waddr;
                          })

        req.print();
        get_response(rsp);
    endtask

endclass: ahb_master_burst_wr_sequence




class ahb_master_burst_rd_sequence extends svt_ahb_master_transaction_base_sequence;

    bit [31:0] rdata[];
    bit [35:0] raddr;
    bit [2:0]  bur_sel;
    rand int unsigned sequence_length = 10;

    constraint reasonable_sequence_length {
      sequence_length <= 100;
    }

    `uvm_object_utils(ahb_master_burst_rd_sequence)

    function new(string name="ahb_master_burst_rd_sequence");
      super.new(name);
    endfunction

    virtual task body();
        bit status;
        super.body();

        status = uvm_config_db #(int unsigned)::get(null, get_full_name(), "sequence_length", sequence_length);
        `uvm_info("body", $sformatf("sequence_length is %0d as a result of %0s.", sequence_length, status ? "config DB" : "randomization"), UVM_LOW);

        `uvm_do_with(req, {
                            xact_type  == svt_ahb_transaction::READ;
                            if(bur_sel == 3'b000)
                                {burst_type == svt_ahb_transaction::INCR4;
                                 data.size == 4;}
                            else if(bur_sel == 3'b001)
                                {burst_type == svt_ahb_transaction::WRAP4;
                                 data.size == 4;}
                            else if(bur_sel == 3'b010)
                                {burst_type == svt_ahb_transaction::INCR8;
                                 data.size == 8;}
                            else if(bur_sel == 3'b011)
                                {burst_type == svt_ahb_transaction::WRAP8;
                                 data.size == 8;}
                            else if(bur_sel == 3'b100)
                                {burst_type == svt_ahb_transaction::INCR16;
                                 data.size == 16;}
                            else if(bur_sel == 3'b101)
                                {burst_type == svt_ahb_transaction::WRAP16;
                                 data.size == 16;}
                            else
                                {burst_type == svt_ahb_transaction::INCR4;
                                 data.size == 4;}
                            addr == raddr;
                            burst_size == 3; // 64-bit
                          })

        get_response(rsp);
        req.print();

        rdata=rsp.data;

    endtask

endclass: ahb_master_burst_rd_sequence

class ahb_master_wr_single_sequence extends svt_ahb_master_transaction_base_sequence;

  /** Parameter that controls the number of transactions that will be generated */
  rand int unsigned sequence_length = 10;
    bit [63:0] wdata;
    bit [35:0] waddr;
    bit [3:0]  size=3;
  /** Constrain the sequence length to a reasonable value */
  constraint reasonable_sequence_length {
    sequence_length <= 100;
  }

  /** UVM Object Utility macro */
  `uvm_object_utils(ahb_master_wr_single_sequence)

  /** Class Constructor */
  function new(string name="ahb_master_wr_single_sequence");
    super.new(name);
  endfunction

  virtual task body();
    bit status;
    `uvm_info("body", "Entered ...", UVM_LOW)

    super.body();

    status = uvm_config_db #(int unsigned)::get(null, get_full_name(), "sequence_length", sequence_length);
    `uvm_info("body", $sformatf("sequence_length is %0d as a result of %0s.", sequence_length, status ? "config DB" : "randomization"), UVM_LOW);

        `uvm_do_with(req,
        {
          xact_type == svt_ahb_transaction::WRITE;
          burst_type== svt_ahb_transaction::SINGLE;
          data[0]==wdata;
          burst_size==size;
          addr==waddr;
        })
      req.print();
      get_response(rsp);

    `uvm_info("body", "AHB WRITE transaction completed", UVM_LOW);
    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass: ahb_master_wr_single_sequence

class ahb_master_rd_single_sequence extends svt_ahb_master_transaction_base_sequence;

  /** Parameter that controls the number of transactions that will be generated */
  rand int unsigned sequence_length = 10;
  bit [63:0] rdata;
  bit [35:0] raddr;
  bit [3:0]  size =3;
  /** Constrain the sequence length to a reasonable value */
  constraint reasonable_sequence_length {
    sequence_length <= 100;
  }

  /** UVM Object Utility macro */
  `uvm_object_utils(ahb_master_rd_single_sequence)

  /** Class Constructor */
  function new(string name="ahb_master_rd_single_sequence");
    super.new(name);
  endfunction

  virtual task body();
    bit status;
    `uvm_info("body", "Entered ...", UVM_LOW)

    super.body();

    status = uvm_config_db #(int unsigned)::get(null, get_full_name(), "sequence_length", sequence_length);
    `uvm_info("body", $sformatf("sequence_length is %0d as a result of %0s.", sequence_length, status ? "config DB" : "randomization"), UVM_LOW);

        `uvm_do_with(req,
        {
          xact_type == svt_ahb_transaction::READ;
          burst_type== svt_ahb_transaction::SINGLE;
          addr==raddr;
          burst_size==size;
        })

      get_response(rsp);

      req.print();
      rdata=rsp.data[0];

      //foreach(rsp.data[i])begin
      //  rdata[i]=rsp.data[i];
      //end


      $display("33333 %h",rdata );
      //$display(rsp );


    `uvm_info("body", "AHB READ transaction completed", UVM_LOW);
    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body
endclass: ahb_master_rd_single_sequence
`endif // GUARD_AHB_MASTER_WR_RD_SEQUENCE_SV
