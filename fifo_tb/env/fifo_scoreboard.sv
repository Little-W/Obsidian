class fifo_scoreboard extends uvm_component;
  `uvm_component_utils(fifo_scoreboard)

  localparam int DEPTH = 16;
  uvm_analysis_imp#(fifo_item, fifo_scoreboard) imp;
  bit [7:0] exp_q[$];

  function new(string name = "fifo_scoreboard", uvm_component parent = null);
    super.new(name, parent);
    imp = new("imp", this);
  endfunction

  function void write(fifo_item tr);
    bit exp_full;
    bit exp_empty;
    bit exp_do_read;
    bit exp_do_write;
    bit [7:0] exp_rdata;

    exp_full = (exp_q.size() == DEPTH);
    exp_empty = (exp_q.size() == 0);
    exp_do_read = tr.rd_en && !exp_empty;
    exp_do_write = tr.wr_en && (!exp_full || exp_do_read);

    if ((tr.overflow !== (tr.wr_en && exp_full && !exp_do_read))) begin
      `uvm_error("FIFO_OVF", $sformatf("overflow mismatch wr=%0b rd=%0b size=%0d got=%0b",
                                       tr.wr_en, tr.rd_en, exp_q.size(), tr.overflow))
    end
    if ((tr.underflow !== (tr.rd_en && exp_empty))) begin
      `uvm_error("FIFO_UDF", $sformatf("underflow mismatch wr=%0b rd=%0b size=%0d got=%0b",
                                       tr.wr_en, tr.rd_en, exp_q.size(), tr.underflow))
    end

    if (exp_do_read) begin
      exp_rdata = exp_q.pop_front();
      if (tr.rdata !== exp_rdata) begin
        `uvm_error("FIFO_DATA", $sformatf("read data mismatch exp=0x%02h got=0x%02h",
                                          exp_rdata, tr.rdata))
      end
    end

    if (exp_do_write) begin
      exp_q.push_back(tr.data);
    end

    if (tr.level != exp_q.size()) begin
      `uvm_error("FIFO_LEVEL", $sformatf("level mismatch exp=%0d got=%0d", exp_q.size(), tr.level))
    end
    if (tr.full !== (exp_q.size() == DEPTH)) begin
      `uvm_error("FIFO_FULL", $sformatf("full mismatch exp=%0b got=%0b", exp_q.size() == DEPTH, tr.full))
    end
    if (tr.empty !== (exp_q.size() == 0)) begin
      `uvm_error("FIFO_EMPTY", $sformatf("empty mismatch exp=%0b got=%0b", exp_q.size() == 0, tr.empty))
    end
  endfunction
endclass
