#include "cmodel.h"
#include "pproc_func.h"

void pproc_subcmd(uint16_t *params, uint64_t enmode, uint64_t datainfo,
                  uint64_t maskinfo, uint64_t **res, uint16_t **elw,
                  uint32_t **des, uint32_t row, uint32_t column) {
  uint64_t data_instruct[] = {datainfo, 0x0};
  operators::pproc_en_mode *en_mode =
      operators::pproc_en_mode::generate(enmode);
  operators::pproc_datatype *data_info =
      operators::pproc_datatype::generate(data_instruct);
  operators::pproc_tile_mask *mask =
      operators::pproc_tile_mask::generate(maskinfo);
  operators::pproc_base_stream_alpha(params, *en_mode, *data_info, *mask, res,
                                     elw, des, row, column);
  delete en_mode;
  delete data_info;
  delete mask;
}

void pproc_base_stream_alpha(uint16_t *params,
                             operators::pproc_en_mode &en_mode,
                             operators::pproc_datatype &data_info,
                             operators::pproc_tile_mask &mask, uint64_t **res,
                             uint16_t **elw, uint32_t **des, uint32_t row,
                             uint32_t column) {
  operators::pproc_base_stream_alpha(params, en_mode, data_info, mask, res, elw,
                                     des, row, column);
}
