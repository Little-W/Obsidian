typedef enum bit [1:0] {
  FIFO_IDLE,
  FIFO_WRITE,
  FIFO_READ,
  FIFO_WRITE_READ
} fifo_op_e;

class fifo_item extends uvm_sequence_item;
  rand fifo_op_e op;
  rand bit [7:0] data;
  rand int unsigned idle_cycles;

  bit wr_en;
  bit rd_en;
  bit [7:0] rdata;
  bit full;
  bit empty;
  bit almost_full;
  bit almost_empty;
  bit overflow;
  bit underflow;
  int unsigned level;

  constraint c_idle_cycles { idle_cycles inside {[0:3]}; }

  `uvm_object_utils_begin(fifo_item)
    `uvm_field_enum(fifo_op_e, op, UVM_DEFAULT)
    `uvm_field_int(data, UVM_DEFAULT)
    `uvm_field_int(idle_cycles, UVM_DEFAULT)
    `uvm_field_int(wr_en, UVM_DEFAULT)
    `uvm_field_int(rd_en, UVM_DEFAULT)
    `uvm_field_int(rdata, UVM_DEFAULT)
    `uvm_field_int(full, UVM_DEFAULT)
    `uvm_field_int(empty, UVM_DEFAULT)
    `uvm_field_int(almost_full, UVM_DEFAULT)
    `uvm_field_int(almost_empty, UVM_DEFAULT)
    `uvm_field_int(overflow, UVM_DEFAULT)
    `uvm_field_int(underflow, UVM_DEFAULT)
    `uvm_field_int(level, UVM_DEFAULT)
  `uvm_object_utils_end

  function new(string name = "fifo_item");
    super.new(name);
  endfunction
endclass
