#ifndef TEST_COMMON_VAE_H
#define TEST_COMMON_VAE_H
#include "sm_datatype_utils.h"
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>

#if defined(USE_EXTERN_C)
std::vector<uint16_t> extractHexNumbers(const std::string &input);
std::vector<uint16_t> readDataFromTxt(std::string filename);
std::vector<float> oneDimMatrixRand(int col, int row, int low, int high);
void printVectorUint16(std::vector<uint16_t> data, std::string format);
void printVectoFloat(std::vector<float> data, std::string format);
void copyDataUint16(std::vector<float> inputData, uint16_t *outData);
void copyDataFloat(std::vector<float> inputData, float *outData);
void printFloat(const float *data, int num);
void printUint24(const uint24_t *data, int num);
void printUint16(const uint16_t *data, int num);
void test_softmax_online(int row, int col, DataType i_type, DataType o_type);
void test_add2(int row, int col, DataType i_type, DataType o_type);
void fun_test_vae(int row, int col, DataType i_type, DataType o_type,
                  int functionNumber);
double bf16_to_double(uint16_t val);

#endif
#endif