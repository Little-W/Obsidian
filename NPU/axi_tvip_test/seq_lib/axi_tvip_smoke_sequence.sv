class axi_tvip_smoke_sequence extends tvip_axi_master_sequence_base;
  function new(string name = "axi_tvip_smoke_sequence");
    super.new(name);
    set_automatic_phase_objection(1);
  endfunction

  task body();
    do_write_read(6'h00, 32'h1234_5678);
    do_write_read(6'h04, 32'hcafe_5eed);
  endtask

  task do_write_read(tvip_axi_address address, bit [31:0] expected_data);
    tvip_axi_master_write_sequence write_sequence;
    tvip_axi_master_read_sequence  read_sequence;

    `tue_do_with(write_sequence, {
      id           == 0;
      address      == local::address;
      burst_length == 1;
      burst_size   == 4;
      burst_type   == TVIP_AXI_INCREMENTING_BURST;
      memory_type  == TVIP_AXI_DEVICE_NON_BUFFERABLE;
      protection   == '0;
      qos          == '0;
      data.size()  == 1;
      data[0]      == local::expected_data;
      strobe.size() == 1;
      strobe[0]    == 4'hf;
    })

    if ((write_sequence.response.size() == 0) ||
        (write_sequence.response[0] != TVIP_AXI_OKAY)) begin
      `uvm_error("AXI_TVIP", $sformatf("write response is not OKAY at 0x%0h", address))
    end

    `tue_do_with(read_sequence, {
      id           == 0;
      address      == local::address;
      burst_length == 1;
      burst_size   == 4;
      burst_type   == TVIP_AXI_INCREMENTING_BURST;
      memory_type  == TVIP_AXI_DEVICE_NON_BUFFERABLE;
      protection   == '0;
      qos          == '0;
    })

    if ((read_sequence.response.size() == 0) ||
        (read_sequence.response[0] != TVIP_AXI_OKAY)) begin
      `uvm_error("AXI_TVIP", $sformatf("read response is not OKAY at 0x%0h", address))
    end
    else if (read_sequence.data[0][31:0] != expected_data) begin
      `uvm_error(
        "AXI_TVIP",
        $sformatf(
          "read data mismatch at 0x%0h: exp=0x%08x got=0x%08x",
          address, expected_data, read_sequence.data[0][31:0]
        )
      )
    end
    else begin
      `uvm_info(
        "AXI_TVIP",
        $sformatf("write/read passed: addr=0x%0h data=0x%08x", address, expected_data),
        UVM_LOW
      )
    end
  endtask

  `uvm_object_utils(axi_tvip_smoke_sequence)
endclass
