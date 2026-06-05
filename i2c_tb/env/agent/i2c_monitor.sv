class i2c_monitor extends uvm_component;
  `uvm_component_utils(i2c_monitor)
  virtual i2c_if vif;
  uvm_analysis_port#(i2c_item) ap;

  function new(string name = "i2c_monitor", uvm_component parent = null);
    super.new(name, parent);
    ap = new("ap", this);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual i2c_if)::get(this, "", "vif", vif)) begin
      `uvm_fatal("NOVIF", "i2c_if is not set for monitor")
    end
  endfunction

  task run_phase(uvm_phase phase);
    i2c_item tr;
    forever begin
      @(posedge vif.clk);
      if (vif.rst_n) begin
        tr = i2c_item::type_id::create("tr");
        tr.data = {6'h0, vif.ic_clk_in_a, vif.ic_data_in_a};
        ap.write(tr);
      end
    end
  endtask
endclass
