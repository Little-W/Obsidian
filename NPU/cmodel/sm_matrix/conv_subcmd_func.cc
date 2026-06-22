#include "conv_subcmd_func.h"

namespace operators {
// 2d to 3d
bool convert_to_4d(uint64_t **mat_c, uint16_t o_tile_h, uint16_t o_tile_w,
                   uint16_t o_tile_c, DataType datatype,
                   MATRIX_4D<uint64_t> &result) {

  result.release();
  result.reset(1, o_tile_c, o_tile_h, o_tile_w, datatype);

  if (mat_c == nullptr) {
    std::cerr << "Error: Input matrix is null" << std::endl;
    return false;
  }
  if (o_tile_h == 0 || o_tile_w == 0 || o_tile_c == 0) {
    std::cerr << "Error: Invalid dimensions" << std::endl;
    return false;
  }
  // traverse each element in the 2D matrix
  for (uint16_t row = 0; row < o_tile_h * o_tile_w; row++) {
    // calculate the position of current element in 3D matrix
    uint16_t h = row / o_tile_w; // h index
    uint16_t w = row % o_tile_w; // w index

    for (uint16_t c = 0; c < o_tile_c; c++) {
      result.data[0][c][h][w] = mat_c[row][c];
      //   std::cout << std::setw(8) << result.data[0][c][h][w];
    }
  }

  std::cout << std::setw(8) << result.data[0][1][1][2];
  return true;
}

void print_matrix_4d_detail(const MATRIX_4D<uint64_t> &matrix, const char *name,
                            uint16_t max_batches, uint16_t max_channels,
                            uint16_t max_rows, uint16_t max_cols) {
  std::cout << "\n=== " << name << " Detailed View ===" << std::endl;
  std::cout << "Dimensions: batch=" << matrix.bz << ", channels=" << matrix.ch
            << ", height=" << matrix.nr << ", width=" << matrix.nc << std::endl;

  // if (matrix.empty()) {
  //     std::cout << "Matrix is empty!" << std::endl;
  //     return;
  // }

  // 限制打印的数量
  uint16_t b_print = std::min(static_cast<uint16_t>(matrix.bz), max_batches);
  uint16_t c_print = std::min(static_cast<uint16_t>(matrix.ch), max_channels);
  uint16_t h_print = std::min(static_cast<uint16_t>(matrix.nr), max_rows);
  uint16_t w_print = std::min(static_cast<uint16_t>(matrix.nc), max_cols);

  // 打印统计信息
  std::cout << "Printing: " << b_print << "/" << matrix.bz << " batches, "
            << c_print << "/" << matrix.ch << " channels, " << h_print << "/"
            << matrix.nr << " rows, " << w_print << "/" << matrix.nc
            << " columns" << std::endl;

  // 打印每个批次和通道
  for (uint16_t b = 0; b < b_print; ++b) {
    std::cout << "\n--- Batch " << b << " ---" << std::endl;

    for (uint16_t c = 0; c < c_print; ++c) {
      std::cout << "Channel " << c << ":" << std::endl;

      // 打印表头（列索引）
      std::cout << "      ";
      for (uint16_t w = 0; w < w_print; ++w) {
        std::cout << std::setw(8) << w << " ";
      }
      if (w_print < matrix.nc) {
        std::cout << " ...";
      }
      std::cout << std::endl;

      // 打印分隔线
      std::cout << "      ";
      for (uint16_t w = 0; w < w_print; ++w) {
        std::cout << "---------";
      }
      std::cout << std::endl;

      // 打印数据行
      for (uint16_t h = 0; h < h_print; ++h) {
        std::cout << std::setw(3) << h << " | ";
        for (uint16_t w = 0; w < w_print; ++w) {
          std::cout << std::setw(8) << matrix.data[b][c][h][w] << " ";
        }
        if (w_print < matrix.nc) {
          std::cout << " ...";
        }
        std::cout << std::endl;
      }

      if (h_print < matrix.nr) {
        std::cout << " ... | ";
        for (uint16_t w = 0; w < w_print; ++w) {
          std::cout << "   ...   ";
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }

    if (c_print < matrix.ch) {
      std::cout << "... (and " << (matrix.ch - c_print) << " more channels)"
                << std::endl;
    }
  }

  if (b_print < matrix.bz) {
    std::cout << "... (and " << (matrix.bz - b_print) << " more batches)"
              << std::endl;
  }
  /*
  // 打印统计信息
  std::cout << "Matrix statistics:" << std::endl;

  // 计算最小值、最大值和平均值
  uint64_t min_val = UINT32_MAX;
  uint64_t max_val = 0;
  uint64_t sum_val = 0;
  size_t total_elements = matrix.bz * matrix.ch * matrix.nr * matrix.nc;

  for (uint16_t b = 0; b < matrix.bz; ++b) {
      for (uint16_t c = 0; c < matrix.ch; ++c) {
          for (uint16_t h = 0; h < matrix.nr; ++h) {
              for (uint16_t w = 0; w < matrix.nc; ++w) {
                  uint64_t val = matrix.data[b][c][h][w];
                  if (val < min_val) min_val = val;
                  if (val > max_val) max_val = val;
                  sum_val += val;
              }
          }
      }
  }

  double avg_val = static_cast<double>(sum_val) / total_elements;

  std::cout << "  Min: " << min_val << std::endl;
  std::cout << "  Max: " << max_val << std::endl;
  std::cout << "  Avg: " << std::fixed << std::setprecision(2) << avg_val <<
  std::endl; std::cout << "  Total elements: " << total_elements << std::endl;
  */
}

// print mat_a mat_b
void print_matrix_partial(uint16_t **matrix, const char *name, uint16_t rows,
                          uint16_t cols, uint16_t max_rows, uint16_t max_cols) {
  std::cout << "\nMatrix " << name << " (" << rows << "x" << cols
            << "):" << std::endl;

  if (matrix == nullptr) {
    std::cout << "  Matrix is null" << std::endl;
    return;
  }

  // 限制打印的行数和列数
  uint16_t print_rows = std::min(rows, max_rows);
  uint16_t print_cols = std::min(cols, max_cols);

  for (uint16_t i = 0; i < print_rows; i++) {
    if (matrix[i] == nullptr) {
      std::cout << "  Row " << i << ": null pointer" << std::endl;
      continue;
    }

    std::cout << "  Row " << i << ": ";
    for (uint16_t j = 0; j < print_cols; j++) {
      std::cout << std::setw(6) << matrix[i][j] << " ";
    }
    if (print_cols < cols) {
      std::cout << "...";
    }
    std::cout << std::endl;
  }
  if (print_rows < rows) {
    std::cout << "  ... (and " << (rows - print_rows) << " more rows)"
              << std::endl;
  }
}
// print mat_c
void print_matrix_2d_detail(uint64_t **matrix, const char *name, uint16_t rows,
                            uint16_t cols, uint16_t max_rows,
                            uint16_t max_cols) {
  std::cout << "\n=== " << name << " Detailed View ===" << std::endl;
  std::cout << "Dimensions: " << rows << " x " << cols << std::endl;

  if (matrix == nullptr) {
    std::cout << "Matrix is null!" << std::endl;
    return;
  }

  // 检查第一行是否有效
  if (matrix[0] == nullptr) {
    std::cout << "Matrix data is null!" << std::endl;
    return;
  }

  // 限制打印的数量
  uint16_t r_print = std::min(rows, max_rows);
  uint16_t c_print = std::min(cols, max_cols);

  std::cout << "Printing: " << r_print << "/" << rows << " rows, " << c_print
            << "/" << cols << " columns" << std::endl;

  // 打印表头（列索引）
  std::cout << "     ";
  for (uint16_t c = 0; c < c_print; ++c) {
    std::cout << std::setw(8) << c << " ";
  }
  if (c_print < cols) {
    std::cout << " ...";
  }
  std::cout << std::endl;

  // 打印分隔线
  std::cout << "     ";
  for (uint16_t c = 0; c < c_print; ++c) {
    std::cout << "---------";
  }
  std::cout << std::endl;

  // 打印数据行
  for (uint16_t r = 0; r < r_print; ++r) {
    if (matrix[r] == nullptr) {
      std::cout << std::setw(3) << r << " | [NULL ROW]" << std::endl;
      continue;
    }

    std::cout << std::setw(3) << r << " | ";
    for (uint16_t c = 0; c < c_print; ++c) {
      std::cout << std::setw(8) << matrix[r][c] << " ";
    }
    if (c_print < cols) {
      std::cout << " ...";
    }
    std::cout << std::endl;
  }

  if (r_print < rows) {
    std::cout << " ... | ";
    for (uint16_t c = 0; c < c_print; ++c) {
      std::cout << "   ...   ";
    }
    std::cout << std::endl;
  }

  // 打印统计信息
  std::cout << "\nMatrix statistics:" << std::endl;
  /*
  // 计算最小值、最大值和平均值
  uint64_t min_val = UINT32_MAX;
  uint64_t max_val = 0;
  uint64_t sum_val = 0;
  size_t valid_rows = 0;

  for (uint16_t r = 0; r < rows; ++r) {
      if (matrix[r] == nullptr) {
          continue;
      }
      valid_rows++;

      for (uint16_t c = 0; c < cols; ++c) {
          uint64_t val = matrix[r][c];
          if (val < min_val) min_val = val;
          if (val > max_val) max_val = val;
          sum_val += val;
      }
  }
  size_t total_elements = valid_rows * cols;
  double avg_val = total_elements > 0 ? static_cast<double>(sum_val) /
  total_elements : 0;

  // std::cout << "  Min: " << min_val << std::endl;
  // std::cout << "  Max: " << max_val << std::endl;
  // std::cout << "  Avg: " << std::fixed << std::setprecision(2) << avg_val <<
  std::endl; std::cout << "  Total elements: " << total_elements << std::endl;
  std::cout << "  Valid rows: " << valid_rows << "/" << rows << std::endl;

  */
}

void compare_matrices(uint64_t **mat_c, const MATRIX_4D<uint64_t> &result_4d,
                      uint16_t o_tile_h, uint16_t o_tile_w, uint16_t o_tile_c) {
  std::cout << "\n=== Matrix Comparison ===" << std::endl;
  std::cout << "Comparing original 2D matrix with converted 4D matrix"
            << std::endl;

  uint16_t total_rows = o_tile_h * o_tile_w;
  bool all_match = true;
  int mismatch_count = 0;
  const int max_mismatches_to_show = 10;

  // 检查维度是否匹配
  if (result_4d.bz != 1 || result_4d.ch != o_tile_c ||
      result_4d.nr != o_tile_h || result_4d.nc != o_tile_w) {
    std::cout << "ERROR: Dimension mismatch!" << std::endl;
    std::cout << "Expected: (1, " << o_tile_c << ", " << o_tile_h << ", "
              << o_tile_w << ")" << std::endl;
    std::cout << "Actual: (" << result_4d.bz << ", " << result_4d.ch << ", "
              << result_4d.nr << ", " << result_4d.nc << ")" << std::endl;
    return;
  }

  // 比较每个元素
  for (uint16_t row = 0; row < total_rows; row++) {
    uint16_t h = row / o_tile_w;
    uint16_t w = row % o_tile_w;

    for (uint16_t c = 0; c < o_tile_c; c++) {
      uint64_t original_val = mat_c[row][c];
      uint64_t converted_val = result_4d.data[0][c][h][w];

      if (original_val != converted_val) {
        all_match = false;
        mismatch_count++;

        if (mismatch_count <= max_mismatches_to_show) {
          std::cout << "Mismatch at [row=" << row << ", col=" << c
                    << "] -> [b=0, c=" << c << ", h=" << h << ", w=" << w
                    << "]: "
                    << "original=" << original_val
                    << ", converted=" << converted_val << std::endl;
        }
      }
    }
  }

  if (all_match) {
    std::cout << "SUCCESS: All values match perfectly!" << std::endl;
  } else {
    std::cout << "FAILURE: Found " << mismatch_count << " mismatches"
              << std::endl;
    if (mismatch_count > max_mismatches_to_show) {
      std::cout << "(Showing first " << max_mismatches_to_show << " mismatches)"
                << std::endl;
    }
  }
}

void swap_32_rows(uint64_t **mat_c, uint64_t **mat_reshape, int mat_col,
                  int start_row) {
  for (int i = 0; i < 8; i++) {
    int row8_15 = start_row + 8 + i;
    int row16_23 = start_row + 16 + i;

    for (int j = 0; j < mat_col; j++) {
      mat_reshape[row8_15][j] = mat_c[row16_23][j];
      mat_reshape[row16_23][j] = mat_c[row8_15][j];
    }
  }

  for (int i = 0; i < 8; i++) {
    int row0_7 = start_row + i;
    int row24_31 = start_row + 24 + i;

    for (int j = 0; j < mat_col; j++) {
      mat_reshape[row0_7][j] = mat_c[row0_7][j];
      mat_reshape[row24_31][j] = mat_c[row24_31][j];
    }
  }
}

void reshape_matrix(uint64_t **mat_c, uint64_t **mat_reshape, int mat_row,
                    int mat_col, uint16_t w) {
  if (mat_row % 8 != 0 || mat_col % 8 != 0) {
    cerr << "Error: mat_row and mat_col must be multiples of 8" << endl;
    exit(1);
  }

  if (w <= 8) {
    // 当w<=8时，矩阵保持不变
    for (int i = 0; i < mat_row; i++) {
      for (int j = 0; j < mat_col; j++) {
        mat_reshape[i][j] = mat_c[i][j];
      }
    }
    return;
  }

  if (mat_row % 16 != 0) {
    cerr << "Error: mat_row must be multiple of 16 when w > 8" << endl;
    exit(1);
  }

  if (mat_row % 32 == 0) {
    // mat_row是32的整数倍：对整个矩阵进行32行内互换
    for (int group = 0; group < mat_row / 32; group++) {
      swap_32_rows(mat_c, mat_reshape, mat_col, group * 32);
    }
  } else {
    // mat_row不是32的整数倍：最后一个16行保持不变，其余每32行进行互换
    int full_32_groups = (mat_row - 16) / 32;

    // 处理前面的完整32行组
    for (int group = 0; group < full_32_groups; group++) {
      swap_32_rows(mat_c, mat_reshape, mat_col, group * 32);
    }

    // 复制最后一个16行保持不变
    int last_16_start = mat_row - 16;
    for (int i = 0; i < 16; i++) {
      int src_row = last_16_start + i;
      for (int j = 0; j < mat_col; j++) {
        mat_reshape[src_row][j] = mat_c[src_row][j];
      }
    }
  }
}
// 释放矩阵内存
void free_matrix(uint64_t **mat, int mat_row) {
  for (int i = 0; i < mat_row; i++) {
    delete[] mat[i];
  }
  delete[] mat;
}

uint64_t **allocate_matrix(int mat_row, int mat_col) {
  uint64_t **mat = new uint64_t *[mat_row];
  for (int i = 0; i < mat_row; i++) {
    mat[i] = new uint64_t[mat_col];
    for (int j = 0; j < mat_col; j++) {
      mat[i][j] = 0;
    }
  }
  return mat;
}

//--
// void conv_subcmd(matrix_opcode *matrix_opcode, uint8_t mat_a_m, uint8_t
// mat_b_n, uint16_t common_k,
//                  uint16_t **mat_a, uint16_t **mat_b, uint64_t **mat_c,
//                  DataType datatype, MATRIX_4D<uint64_t> &result_4d) {
//--
void conv_subcmd(uint64_t conv_opcode, uint16_t mat_a_m, uint16_t mat_b_n,
                 uint16_t common_k, uint16_t **mat_a, uint16_t **mat_b,
                 uint64_t **mat_reshape, DataType datatype) {
  // std::cout << "Data type: " << static_cast<int>(datatype) << std::endl;

  // matrix_opcode_conv *temp_opcode = dynamic_cast<matrix_opcode_conv
  // *>(matrix_opcode); uint8_t o_tile_h = temp_opcode->o_tile_h; uint8_t
  // o_tile_w = temp_opcode->o_tile_w; uint8_t o_tile_c = temp_opcode->o_tile_c;
  // 从 opcode 中获取卷积参数
  // matrix_opcode_conv opcode(conv_opcode);
  // bool op_mode = opcode.op_mode;
  // bool subcmd_bc_id = opcode.subcmd_bc_id;
  // uint8_t o_tile_h = opcode.o_tile_h;
  // uint8_t o_tile_w = opcode.o_tile_w;
  // uint8_t o_tile_c = opcode.o_tile_c;

  std::cout << " conv_opcode = " << std::hex << conv_opcode << std::endl;

  if (mat_a == nullptr || mat_b == nullptr || mat_reshape == nullptr) {
    std::cerr << "Error: One or more matrix pointers are null" << std::endl;
    return;
  }

  uint8_t o_tile_w = (conv_opcode >>= 2) & 0b11111;
  uint8_t o_tile_h = (conv_opcode >>= 5) & 0b1111;
  uint8_t o_tile_c = (conv_opcode >>= 4) & 0b11111111;
  std::cout << " o_tile_w = " << static_cast<int>(o_tile_w) << std::endl;
  std::cout << " o_tile_h = " << static_cast<int>(o_tile_h) << std::endl;
  std::cout << " o_tile_c = " << static_cast<int>(o_tile_c) << std::endl;
  uint16_t mat_a_rows = mat_a_m;
  uint16_t mat_b_cols = mat_b_n;

  uint64_t **mat_c = allocate_matrix(mat_a_rows, mat_b_cols);
  // matrix mul
  matmul_subcmd_128_k(mat_a, mat_b, mat_c, common_k, mat_a_rows, mat_b_cols,
                      datatype);

  // uint64_t** mat_reshape = reshape_matrix(mat_c, mat_row, mat_col, w);
  reshape_matrix(mat_c, mat_reshape, mat_a_rows, mat_b_cols, o_tile_w);

  // 2d to 3d
  // bool conv_ok =  convert_to_4d(mat_c, o_tile_h, o_tile_w, o_tile_c,
  // datatype, result_4d);
  free_matrix(mat_c, mat_a_rows);
}

} // namespace operators
