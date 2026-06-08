

`ifndef CPU_CLK_TEST_SV
`define CPU_CLK_TEST_SV

class cpu_clk_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_clk_test)
    extern function new(string name = "cpu_clk_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_clk_test::new(string name = "cpu_clk_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_clk_test::main_phase(uvm_phase phase);
    bit[7:0] clk_flg = 0;
    int start_time;
    int end_time;
    int freq = 0;

    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    fork:detect_clk
        forever begin
            `uvm_info("cpu_clk_test", $sformatf("wait notice to detect clock"), UVM_LOW)
            wait_label('h12345678);
            start_time = $time;
            repeat(500) begin
                @(posedge chip_top_vif.mon_clk);
            end
            end_time = $time;

            //freq = 500*10**6/(end_time-start_time);
            freq = 500*10**3/(end_time-start_time);            
            `uvm_info("cpu_clk_test", $sformatf("cal frequency = %0dM", freq), UVM_LOW)
            //400M/600M/800M
            if(freq < 204 && freq > 196)begin
                clk_flg[0] = 1'b1;
            end
            else if(freq < 406 && freq > 394)begin
                clk_flg[1] = 1'b1;
            end
            else if(freq < 808 && freq > 792)begin
                clk_flg[2] = 1'b1;
            end
            send_label('h12121235);
            if(clk_flg == 7) break;
        end

        begin
            #10ms;
            clk_flg[3] = 1'b1;
            `uvm_fatal("cpu_clk_test", $sformatf("detect clock timeout !!!"))
        end
    join_any
    disable detect_clk;

    if(clk_flg[3] == 0)
        check_simend();

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
