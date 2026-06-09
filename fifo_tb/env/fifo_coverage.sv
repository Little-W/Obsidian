class fifo_coverage extends uvm_subscriber#(fifo_item);
  `uvm_component_utils(fifo_coverage)

  fifo_item tr;

  covergroup fifo_cg;
    option.per_instance = 1;
    cp_op: coverpoint tr.op;
    cp_level: coverpoint tr.level {
      bins empty = {0};
      bins low = {[1:3]};
      bins mid = {[4:12]};
      bins high = {[13:15]};
      bins full = {16};
    }
    cp_flags: coverpoint {tr.full, tr.empty, tr.overflow, tr.underflow};
    cross cp_op, cp_level;
  endgroup

  function new(string name = "fifo_coverage", uvm_component parent = null);
    super.new(name, parent);
    fifo_cg = new();
  endfunction

  function void write(fifo_item t);
    tr = t;
    fifo_cg.sample();
  endfunction
endclass
