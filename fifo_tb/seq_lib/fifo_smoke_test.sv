class fifo_smoke_test extends fifo_base_test;
  `uvm_component_utils(fifo_smoke_test)

  function new(string name = "fifo_smoke_test", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  task run_phase(uvm_phase phase);
    string seq_name;
    uvm_object seq_obj;
    uvm_sequence_base seq_base;

    phase.raise_objection(this);
    if (!$value$plusargs("SEQ=%s", seq_name)) begin
      seq_name = "fifo_basic_seq";
    end

    seq_obj = uvm_factory::get().create_object_by_name(seq_name, get_full_name(), "seq_obj");
    if (seq_obj == null) begin
      `uvm_fatal("SEQ_NF", $sformatf("Cannot create sequence: %s", seq_name))
    end
    if (!$cast(seq_base, seq_obj)) begin
      `uvm_fatal("SEQ_BAD", $sformatf("Object is not a sequence: %s", seq_name))
    end

    `uvm_info("FIFO_TEST", $sformatf("Starting %s", seq_name), UVM_LOW)
    seq_base.start(m_env.agt.sqr);
    repeat (10) @(posedge vif.clk);
    phase.drop_objection(this);
  endtask
endclass
