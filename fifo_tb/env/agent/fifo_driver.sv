class fifo_driver extends uvm_driver#(fifo_item);
  `uvm_component_utils(fifo_driver)

  virtual fifo_if vif;

  function new(string name = "fifo_driver", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual fifo_if)::get(this, "", "vif", vif)) begin
      `uvm_fatal("NOVIF", "fifo_if is not set for driver")
    end
  endfunction

  task run_phase(uvm_phase phase);
    fifo_item req;
    vif.wr_en <= 1'b0;
    vif.rd_en <= 1'b0;
    vif.wdata <= '0;
    wait (vif.rst_n === 1'b1);
    forever begin
      seq_item_port.get_next_item(req);
      repeat (req.idle_cycles) drive_idle();
      drive_one(req);
      seq_item_port.item_done();
    end
  endtask

  task drive_idle();
    @(negedge vif.clk);
    vif.wr_en <= 1'b0;
    vif.rd_en <= 1'b0;
    vif.wdata <= '0;
  endtask

  task drive_one(fifo_item req);
    @(negedge vif.clk);
    vif.wr_en <= (req.op == FIFO_WRITE) || (req.op == FIFO_WRITE_READ);
    vif.rd_en <= (req.op == FIFO_READ) || (req.op == FIFO_WRITE_READ);
    vif.wdata <= req.data;
    @(negedge vif.clk);
    vif.wr_en <= 1'b0;
    vif.rd_en <= 1'b0;
    vif.wdata <= '0;
  endtask
endclass
