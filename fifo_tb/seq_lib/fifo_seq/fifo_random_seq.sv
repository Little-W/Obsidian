class fifo_random_seq extends uvm_sequence#(fifo_item);
  `uvm_object_utils(fifo_random_seq)

  rand int unsigned item_num;
  constraint c_item_num { item_num inside {[100:300]}; }

  function new(string name = "fifo_random_seq");
    super.new(name);
  endfunction

  task body();
    fifo_item req;
    if (!randomize()) begin
      `uvm_fatal("RAND", "fifo_random_seq randomize failed")
    end
    void'($value$plusargs("ITEM_NUM=%d", item_num));
    repeat (item_num) begin
      req = fifo_item::type_id::create("req");
      start_item(req);
      if (!req.randomize() with {
        op dist {
          FIFO_WRITE := 45,
          FIFO_READ := 35,
          FIFO_WRITE_READ := 15,
          FIFO_IDLE := 5
        };
      }) begin
        `uvm_fatal("RAND", "fifo_item randomize failed")
      end
      finish_item(req);
    end
  endtask
endclass
