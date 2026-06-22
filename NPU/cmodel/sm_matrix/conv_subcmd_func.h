#ifndef _conv_subcmd_func_h
#define _conv_subcmd_func_h

#include "matrix_mul.h"
#include "matrix_opcode.h"
#include <vector>
#include <cstdint>
#include <iostream>
#include "matrix_struct.h"

namespace operators {

// using Matrix3D = std::vector<std::vector<std::vector<uint64_t>>>;
template <typename T> class MATRIX_4D;

bool convert_to_4d(uint64_t **mat_c, uint16_t o_tile_h, uint16_t o_tile_w,
                   uint16_t o_tile_c, DataType datatype,
                   MATRIX_4D<uint64_t> &result);

// void conv_subcmd(uint64_t conv_opcode, uint16_t mat_a_m, uint16_t mat_b_n,
// uint16_t common_k,
//                  uint16_t **mat_a, uint16_t **mat_b, uint64_t **mat_c,
//                  DataType datatype, MATRIX_4D<uint64_t> &result_4d);
// void conv_subcmd(matrix_opcode *matrix_opcode, uint8_t mat_a_m, uint8_t
// mat_b_n, uint16_t common_k,
//                  uint16_t **mat_a, uint16_t **mat_b, uint64_t **mat_c,
//                  DataType datatype, MATRIX_4D<uint64_t> &result_4d) ;
void conv_subcmd(uint64_t conv_opcode, uint16_t mat_a_m, uint16_t mat_b_n,
                 uint16_t common_k, uint16_t **mat_a, uint16_t **mat_b,
                 uint64_t **mat_reshape, DataType datatype);
/**
 * @brief 详细打印 MATRIX_4D 对象
 *
 * @param matrix 要打印的 MATRIX_4D 对象
 * @param name 矩阵名称（用于标识）
 * @param max_batches 最大打印的批次数量
 * @param max_channels 最大打印的通道数量
 * @param max_rows 最大打印的行数
 * @param max_cols 最大打印的列数
 */
void print_matrix_4d_detail(const MATRIX_4D<uint64_t> &matrix,
                            const char *name = "Matrix4D",
                            uint16_t max_batches = 2, uint16_t max_channels = 3,
                            uint16_t max_rows = 5, uint16_t max_cols = 5);

/**
 * @brief 详细打印二维矩阵
 *
 * @param matrix 要打印的二维矩阵
 * @param name 矩阵名称
 * @param rows 矩阵行数
 * @param cols 矩阵列数
 * @param max_rows 最大打印行数
 * @param max_cols 最大打印列数
 */
void print_matrix_2d_detail(uint64_t **matrix, const char *name, uint16_t rows,
                            uint16_t cols, uint16_t max_rows = 10,
                            uint16_t max_cols = 10);

void print_matrix_partial(uint16_t **matrix, const char *name, uint16_t rows,
                          uint16_t cols, uint16_t max_rows = 5,
                          uint16_t max_cols = 5);

void compare_matrices(uint64_t **mat_c, const MATRIX_4D<uint64_t> &result_4d,
                      uint16_t o_tile_h, uint16_t o_tile_w, uint16_t o_tile_c);

} // namespace operators

#endif