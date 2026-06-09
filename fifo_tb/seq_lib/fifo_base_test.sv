class fifo_base_test extends uvm_test;
  `uvm_component_utils(fifo_base_test)

  virtual fifo_if vif;
  fifo_env m_env;

  function new(string name = "fifo_base_test", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual fifo_if)::get(this, "", "vif", vif)) begin
      `uvm_fatal("NOVIF", "virtual interface fifo_if is not set")
    end
    uvm_config_db#(virtual fifo_if)::set(this, "m_env*", "vif", vif);
    m_env = fifo_env::type_id::create("m_env", this);
  endfunction
endclass
