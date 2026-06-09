class fifo_boundary_seq extends uvm_sequence#(fifo_item);
  `uvm_object_utils(fifo_boundary_seq)

  function new(string name = "fifo_boundary_seq");
    super.new(name);
  endfunction

  task body();
    fifo_item req;

    for (int i = 0; i < 20; i++) begin
      req = fifo_item::type_id::create($sformatf("fill_%0d", i));
      start_item(req);
      req.op = FIFO_WRITE;
      req.data = 8'(i);
      req.idle_cycles = 0;
      finish_item(req);
    end

    repeat (4) begin
      req = fifo_item::type_id::create("simul_on_full");
      start_item(req);
      req.op = FIFO_WRITE_READ;
      req.data = $urandom();
      req.idle_cycles = 0;
      finish_item(req);
    end

    for (int i = 0; i < 24; i++) begin
      req = fifo_item::type_id::create($sformatf("drain_%0d", i));
      start_item(req);
      req.op = FIFO_READ;
      req.data = '0;
      req.idle_cycles = 0;
      finish_item(req);
    end
  endtask
endclass
