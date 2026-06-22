    This is CMODEL code of ZC self-developed AI core.  
    All cmodel functions are defined in namespace operators.  
    We used tests/main.cpp to test the cmodel code for simulator team.  
    For DV team, you need to use the function interface below cmodel.h.  


Folders description:  
.vscode: for vscode debug  
tests: main.cpp, for self-test  
sm_model_common: usefull cmodel headers  
sm_matrix: matrix related operators, such as dop32 multiplication and addition operator  
sm_sfu: such as sqrt,rcp,rcp_sqrt,tanh,exp, and so on operators  
sm_vae: such as softmax, rmsnorm, rope, and so on operators  
sm_export: external interface functions  
softfloat: external softfloat library  
....other operators will have seperate folders...  


BUILD cmodel:  
make -j 8 

TEST cmodel:  
./test.elf

CLEAN cmodel:  
make clean (make distclean)