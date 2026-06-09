class fifo_basic_seq extends uvm_sequence#(fifo_item);
  `uvm_object_utils(fifo_basic_seq)

  function new(string name = "fifo_basic_seq");
    super.new(name);
  endfunction

  task body();
    fifo_item req;
    for (int i = 0; i < 8; i++) begin
      req = fifo_item::type_id::create($sformatf("wr_%0d", i));
      start_item(req);
      req.op = FIFO_WRITE;
      req.data = 8'(i + 8'h10);
      req.idle_cycles = 0;
      finish_item(req);
    end
    for (int i = 0; i < 8; i++) begin
      req = fifo_item::type_id::create($sformatf("rd_%0d", i));
      start_item(req);
      req.op = FIFO_READ;
      req.data = '0;
      req.idle_cycles = 0;
      finish_item(req);
    end
  endtask
endclass
