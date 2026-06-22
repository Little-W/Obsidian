#include "sm_data_struct.h"

namespace operators {
int bit_width_dop_fdp16 = 34;  //与硬件一致
int bit_width_dop_mdp32 = 28;  //与硬件一致
int bit_width_dop_f4dp64 = 36; //与硬件一致
int bit_width_dop_idp = 40;    //与硬件一致
bool denormal_out_en = true;   //供验证用
bool denormal_in_en = true;    //供验证用
bool matrix_dp_en = false;     //与硬件一致
uint_fast8_t cmodel_exceptionFlags = 0;
} // namespace operators