class fifo_monitor extends uvm_component;
  `uvm_component_utils(fifo_monitor)

  virtual fifo_if vif;
  uvm_analysis_port#(fifo_item) ap;

  function new(string name = "fifo_monitor", uvm_component parent = null);
    super.new(name, parent);
    ap = new("ap", this);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual fifo_if)::get(this, "", "vif", vif)) begin
      `uvm_fatal("NOVIF", "fifo_if is not set for monitor")
    end
  endfunction

  task run_phase(uvm_phase phase);
    fifo_item tr;
    wait (vif.rst_n === 1'b1);
    forever begin
      @(posedge vif.clk);
      #1;
      tr = fifo_item::type_id::create("tr");
      tr.wr_en = vif.wr_en;
      tr.rd_en = vif.rd_en;
      tr.data = vif.wdata;
      tr.rdata = vif.rdata;
      tr.full = vif.full;
      tr.empty = vif.empty;
      tr.almost_full = vif.almost_full;
      tr.almost_empty = vif.almost_empty;
      tr.overflow = vif.overflow;
      tr.underflow = vif.underflow;
      tr.level = vif.level;
      if (vif.wr_en && vif.rd_en) begin
        tr.op = FIFO_WRITE_READ;
      end else if (vif.wr_en) begin
        tr.op = FIFO_WRITE;
      end else if (vif.rd_en) begin
        tr.op = FIFO_READ;
      end else begin
        tr.op = FIFO_IDLE;
      end
      ap.write(tr);
    end
  endtask
endclass
