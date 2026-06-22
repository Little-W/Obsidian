set _hector_comp_use_new_flow true
set _hector_softfloat_version custom

set_fml_appmode DPV
set_hector_sym_maxstackdepth 200
set_hector_sym_maxiter_partial 400


## comiple sfu model
proc compile_spec_sfu {} {
    create_design -name spec -top hector_wrapper

    set cPath "../cmodel"

    set includes [list "$cPath/sm_model_common" "$cPath/softfloat" "$cPath/sm_sfu"]
    foreach in_dir $includes {
        set Ifolder "-I$in_dir"
        lappend in_files {*}$Ifolder
    }
    puts "all include files :  $in_files"


    set directories [list "$cPath/" "$cPath/sm_model_common" "$cPath/sm_sfu"]
    foreach dir $directories {
        set files [glob -nocomplain -directory $dir *.cc]
        lappend cpp_files {*}$files
    }
    puts "final filtered c files : $cpp_files"

    set softfp_file [list "$cPath/softfloat/"]
    foreach sf_file $softfp_file {
        set sfs [glob -nocomplain -directory $sf_file *.c]
        lappend sf_c_files {*}$sfs
    }
    puts "final softfloat c files : $sf_c_files"


    cppan -v -Wno-narrowing -m64 -lstdc++ $in_files $sf_c_files $cpp_files -lm

    compile_design spec

    puts "compile_design spec done"
}

## comiple all cmodel
proc compile_spec {} {
    create_design -name spec -top hector_wrapper

    set cPath "../cmodel"

    set includes [list "$cPath/sm_model_common" "$cPath/softfloat" "$cPath/sm_sfu" "$cPath/sm_export" "$cPath/sm_matrix" "$cPath/sm_vae"]
    foreach in_dir $includes {
        set Ifolder "-I$in_dir"
        lappend in_files {*}$Ifolder
    }
    puts "all include files :  $in_files"


    set directories [list "$cPath/" "$cPath/sm_model_common" "$cPath/sm_sfu" "$cPath/sm_export" "$cPath/sm_matrix" "$cPath/sm_vae"]
    foreach dir $directories {
        set files [glob -nocomplain -directory $dir *.cc]
        lappend cpp_files {*}$files
    }
    puts "final filtered c files : $cpp_files"

    set softfp_file [list "$cPath/softfloat/"]
    foreach sf_file $softfp_file {
        set sfs [glob -nocomplain -directory $sf_file *.c]
        lappend sf_c_files {*}$sfs
    }
    puts "final softfloat c files : $sf_c_files"


    cppan -v -Wno-narrowing -m64 -lstdc++ $in_files $sf_c_files $cpp_files -lm

    compile_design spec

    puts "compile_design spec done"
}

proc compile_impl {} {

#   create_design -name impl -top muladd -clock clock -reset resetN -negReset
    create_design -name impl -top zcnpu_alu_sfu_rcp_fp32i_fp32o -clock clk -reset rst_n -negReset


#    set_cutpoint muladd.mpier_mantissa_0a
#    set_cutpoint muladd.mpcand_mantissa_0a


#    vcs -sverilog -pvalue+SIZE=16 -f ../rtl/files_muladda
    ########################################## update rtl
    vcs -sverilog -pvalue+SIZE=16 -f /projects/platform/temp/javy/dpv/sim_env/sfu_rcp_debias/04_RTL/FileList/dut_filelist.f

    compile_design impl
}

proc ual {} {
#    assume impl.go(1) == 1

    map_by_name -inputs -specphase 1 -implphase 1

#   assume spec.rounding_mode(1) < 4
#   assume impl.product_mantissa_0(3) == impl.mpier_mantissa_0a(3) * impl.mpcand_mantissa_0a(3)

    set_resource_limit 36000
    set_hector_multiple_solve_scripts true
#    set_hector_multiple_solve_scripts_list [list orch_multipliers]
    set_hector_multiple_solve_scripts_list [list \ "orch_multipliers" \ "orch_expensive_solve1" \ "orch_abo_sat" \]

#    lemma rslt = spec.result(1) == impl.result(7)
#    lemma ex = spec.exceptions(1) == impl.exceptions(7)

    lemma rslt = spec.result(1) == impl.res(4)
##########################################result is 4 or 3 phase????################3

#    lemma ex   = spec.res_valid(1)  == imp.res_valid(4)

}

#proc hdps_ual {} {
#    cutpoint mpier = impl.mpier_mantissa_0a(1)
#    cutpoint mpcand = impl.mpcand_mantissa_0a(1)
#    lemma check_mul = impl.product_mantissa_0(1) == mpier * mpcand
#}

proc case_split_16 {} {
    caseSplitStrategy basic

    caseBegin zero_16
    caseAssume (spec.x(1)[30:0]  == 31'h0)

    caseBegin Inf_16
    caseAssume (spec.x(1)[30:23]  == 8'hff)
    caseAssume (spec.x(1)[22:0 ]  == 23'h000)

    caseBegin Nan_16
    caseAssume (spec.x(1)[30:23]  ==  8'hff)
    caseAssume (spec.x(1)[22:0 ]  != 23'h000000)

    caseBegin norm_16
    caseAssume (spec.x(1)[30:23] != 8'h00)
    caseAssume (spec.x(1)[30:23] != 8'hff)

    caseBegin dnorm_16
    caseAssume (spec.x(1)[30:23] == 8'h00)
    caseAssume (spec.x(1)[22:0 ] != 23'h000000)


}

proc make {} {
    compile_spec
    #compile_impl
    #compose
}

#set_host_file "host.qsub"

proc run_hdps {} {
#set_user_assumes_lemmas_procedure "hdps_ual"

set_custom_solve_script "orch_custom_bit_operations"
set_hector_rew_use_dps_engine true
set_hector_rew_dps_solve_script __hector_orch_custom_dps2
set_resource_limit 200
set_hector_rew_dps_resource_limit 1200

    run_all_hdps_options -encoding [list radix4booth] hdps -modes 0 -rrtypes false -abstypes no_abstraction
    #proofwait
}

proc run_main {} {
    puts "1111111111111111111111111"
    set_user_assumes_lemmas_procedure "ual"
    puts "2222222222222222222222222"
    set_hector_case_splitting_procedure "case_split_16"
    puts "3333333333333333333333333"
    solveNB p

}
