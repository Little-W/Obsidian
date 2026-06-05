class i2c_driver extends uvm_driver#(i2c_item);
  `uvm_component_utils(i2c_driver)
  virtual i2c_if vif;

  function new(string name = "i2c_driver", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual i2c_if)::get(this, "", "vif", vif)) begin
      `uvm_fatal("NOVIF", "i2c_if is not set for driver")
    end
  endfunction

  task run_phase(uvm_phase phase);
    i2c_item req;
    forever begin
      seq_item_port.get_next_item(req);
      @(posedge vif.clk);
      seq_item_port.item_done();
    end
  endtask
endclass
