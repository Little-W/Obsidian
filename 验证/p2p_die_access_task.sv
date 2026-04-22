`ifndef P2P_DIE_ACCESS_TASK_SV
`define P2P_DIE_ACCESS_TASK_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

class noc_reg_access_if;
  virtual task noc_reg_blocked_write(bit [40:0] addr, bit [31:0] data);
  endtask

  virtual task noc_reg_read(bit [40:0] addr, output bit [31:0] data);
  endtask
endclass

task automatic p2p_do_access_once(
    noc_reg_access_if chip_noc_base_test[2],
    int cur_die,
    int dst_die,
    bit [38:0] access_addr,
    bit [31:0] m_data
);
  bit [31:0] rd_data;
  bit [40:0] noc_addr;
  bit        dst_die_bit;

  if (chip_noc_base_test[cur_die] == null) begin
    `uvm_error("p2p_die_access_task", $sformatf("cur_die %0d handle is null", cur_die))
    return;
  end

  dst_die_bit = dst_die[0];
  noc_addr = {1'b0, dst_die_bit, access_addr};

  chip_noc_base_test[cur_die].noc_reg_blocked_write(noc_addr, m_data);
  #500ns;
  chip_noc_base_test[cur_die].noc_reg_read(noc_addr, rd_data);

  `uvm_info("p2p_die_access_task",
            $sformatf("p2p data test, cur_die=%0d dst_die=%0d addr=0x%0h write data:0x%0x read data:0x%0x",
                      cur_die, dst_die, access_addr, m_data, rd_data),
            UVM_LOW)

  if (m_data != rd_data) begin
    `uvm_error("p2p_die_access_task",
               $sformatf("p2p data err : from cur_die: %0d, to dst_die_id: %0d, data compare fail",
                         cur_die, dst_die))
  end
endtask

task automatic run_p2p_die_access_matrix(noc_reg_access_if chip_noc_base_test[2]);
  bit [31:0] data_vec [2] = '{32'h5a5a, 32'h1234};
  bit [38:0] addr_vec [2] = '{39'h4000000000, 39'h4000000010};

  for (int cur_die = 0; cur_die < 2; cur_die++) begin
    for (int dst_die = 0; dst_die < 2; dst_die++) begin
      foreach (data_vec[vec_idx]) begin
        p2p_do_access_once(chip_noc_base_test, cur_die, dst_die, addr_vec[vec_idx], data_vec[vec_idx]);
      end
    end
  end
endtask

`endif