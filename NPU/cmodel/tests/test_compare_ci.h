#ifndef _TEST_COMPARE_CI_H
#define _TEST_COMPARE_CI_H
#include "sm_datatype_utils.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define EPS 0x358637bd

struct test_matrix_t {
  int row;
  int col;
  DataType itype;
  DataType otype;

  test_matrix_t() { reset(); }

  void reset() {
    row = 128;
    col = 2048;
    itype = BF16;
    otype = BF16;
  }
};

int getDataBits(DataType type);

inline uint64_t abs_diff(uint64_t a, uint64_t b) {
  return (a > b) ? (a - b) : (b - a);
}

void printHex(unsigned char byte);
void printHex(uint64_t bytes);
uint64_t *readBinData(string &filename, int num, DataType type);
bool compareBinFiles(const string &file1, const string &file2);
bool compareHexData(uint64_t *out1, uint64_t *out2, size_t size,
                    test_matrix_t &cfg, uint64_t ulp = 0);

// ci test function

bool test_matmul_compare(string &input, string &wgt, string &gout,
                         test_matrix_t &a_cfg, test_matrix_t &b_cfg);
void fun_align_MK_input(test_matrix_t &bPara, test_matrix_t &outPara);
bool test_mxfp4_compare(string &input, string &out, string &outScale,
                        test_matrix_t &cfg);
#endif