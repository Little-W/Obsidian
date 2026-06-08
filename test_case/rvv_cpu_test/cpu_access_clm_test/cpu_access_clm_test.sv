

`ifndef CPU_ACCESS_CLM_TEST_SV
`define CPU_ACCESS_CLM_TEST_SV

class cpu_access_clm_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_access_clm_test)
    extern function new(string name = "cpu_access_clm_test", uvm_component parent = null);
    extern task dma_reg_write(bit [39:0] addr, bit [31:0] reg_data);
    extern task dma_reg_read(bit [39:0] addr, output bit [31:0] reg_data);

    extern task dma_reg_write_64b(bit [39:0] addr, bit [63:0] reg_data);
    extern task dma_reg_read_64b(bit [39:0] addr, output bit [63:0] reg_data);

    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_access_clm_test::new(string name = "cpu_access_clm_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_access_clm_test::dma_reg_write(bit [39:0] addr, bit [31:0] reg_data);
    axi_master_directed_write_sequence axi_wr_seq;
    axi_wr_seq = new("axi_wr_seq");
    axi_wr_seq.waddr = addr;
    axi_wr_seq.wdata = reg_data;
    axi_wr_seq.enable_get_response = 1;
    axi_wr_seq.start(m_env.m_amba_sys_env.axi_system[0].master[1].sequencer);
endtask: dma_reg_write

task cpu_access_clm_test::dma_reg_read(bit [39:0] addr, output bit [31:0] reg_data);
  axi_master_directed_read_sequence axi_rd_seq;
  axi_rd_seq = new("axi_rd_seq");
  axi_rd_seq.raddr = addr;
  axi_rd_seq.start(m_env.m_amba_sys_env.axi_system[0].master[1].sequencer);
  reg_data = axi_rd_seq.rdata;
endtask: dma_reg_read

//andyf
task cpu_access_clm_test::dma_reg_write_64b(bit [39:0] addr, bit [63:0] reg_data);
    axi_master_directed_write_64b_sequence axi_wr_seq_64b;
    axi_wr_seq_64b = new("axi_wr_seq_64b");
    axi_wr_seq_64b.waddr = addr;
    axi_wr_seq_64b.wdata = reg_data;

    axi_wr_seq_64b.start(m_env.m_amba_sys_env.axi_system[0].master[1].sequencer);
endtask: dma_reg_write_64b

task cpu_access_clm_test::dma_reg_read_64b(bit [39:0] addr, output bit [63:0] reg_data);
  axi_master_directed_read_64b_sequence axi_rd_seq_64b;
  axi_rd_seq_64b = new("axi_rd_seq_64b");
  axi_rd_seq_64b.raddr = addr;
  axi_rd_seq_64b.start(m_env.m_amba_sys_env.axi_system[0].master[1].sequencer);
  reg_data = axi_rd_seq_64b.rdata;
endtask: dma_reg_read_64b


task cpu_access_clm_test::main_phase(uvm_phase phase);
    int rdata;
    bit [63:0] rdata_64;
    
    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

   // uvm_hdl_force("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top.clm_base_addr", 'h908_0000);

    //wait_label('h12345678);
    //dma_reg_read(`SCU_BASE_ADDR+'h04, rdata);
    //rdata[27:12] = 'hffff;
    //dma_reg_write(`SCU_BASE_ADDR+'h04, rdata);
    //send_label('h14253647);

    wait_label('h11112222);
    $display("write&read clm first resgion");
    for(int i = 0; i < 64; i++)begin
        dma_reg_write(`RISCV_CLM_ADDR+i*4, `RISCV_CLM_ADDR+i*4);
    end
    for(int i = 0; i < 64; i++)begin
        dma_reg_read(`RISCV_CLM_ADDR+i*4, rdata);
        if(rdata != `RISCV_CLM_ADDR+i*4)begin
            `uvm_error(get_type_name(), $sformatf("Compare Fail:: addr = 0x%h, actdata = 0x%h, expdata = 0x%h", `RISCV_CLM_ADDR+i*4, rdata, `RISCV_CLM_ADDR+i*4))
        end
    end

    $display("write&read clm last resgion");
    //0x8000(Dcache=64K=0x1_0000, cache_way=16, use_way=8, so max addr = 0x10000/16 *8 = 0x8000)
    for(int i = 64; i > 0; i--)begin
        dma_reg_write(`RISCV_CLM_ADDR+'h80000-i*4, `RISCV_CLM_ADDR+'h80000-i*4);
    end
    for(int i = 64; i > 0; i--)begin
        dma_reg_read(`RISCV_CLM_ADDR+'h80000-i*4, rdata);
        if(rdata != `RISCV_CLM_ADDR+'h80000-i*4)begin
            `uvm_error(get_type_name(), $sformatf("Compare Fail:: addr = 0x%h, actdata = 0x%h, expdata = 0x%h", `RISCV_CLM_ADDR+'h80000-i*4, rdata, `RISCV_CLM_ADDR+'h80000-i*4))
        end
    end
    
    for(int i = 0; i < 8; i++)begin
        dma_reg_write_64b(`RISCV_CLM_ADDR+'h4000+8*i,64'h0);
    end

    rdata_64 = 64'h0;
    for(int i = 0; i < 8; i++)begin
        dma_reg_write_64b(`RISCV_CLM_ADDR+'h4000+8*i,64'hffff_ffff_ffff_ffff);
        dma_reg_read_64b(`RISCV_CLM_ADDR+'h4000+8*i,rdata_64);
        $display("write&read clm 64 bit 0xff rdata_64[%d] == 0x%0h",i,rdata_64);
    end

    rdata_64 = 64'h0;
    for(int i = 0; i < 8; i++)begin
        dma_reg_write_64b(`RISCV_CLM_ADDR+'h4000+8*i,64'h0);
        dma_reg_read_64b(`RISCV_CLM_ADDR+'h4000+8*i,rdata_64);
        $display("write&read clm 64 bit 0x0  rdata_64[%d] == 0x%0h",i,rdata_64);
    end
    

    check_simend();
    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
