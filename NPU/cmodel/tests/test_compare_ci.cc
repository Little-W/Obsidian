#include "test_compare_ci.h"
#include "cmodel.h"
#include "test_head.h"
#include "test_framework.h"
#include "test_vae.h"
#include <vector>
/*========================================
Function: input data to size align
Information:Author is ZC, 2025/11/6. by qingyan
============================================*/
void fun_align_MK_input(test_matrix_t &bPara, test_matrix_t &outPara) {
  uint32_t k_align = 1, m_align = 1;
  if ((bPara.itype == BF16) || (bPara.itype == FP16)) { // fp16 and bf16
    k_align = 16; // align according to 32 bytes
    m_align = 16; // align according to 16 rows
    if ((bPara.row % m_align) != 0 && (bPara.row != 1)) {
      outPara.row = bPara.row + (m_align - outPara.row % m_align) % m_align;
    } else {
      outPara.row = bPara.row;
    }
    if ((bPara.col % m_align) != 0 && (bPara.col != 1)) {
      outPara.col = bPara.col + (m_align - outPara.col % m_align) % m_align;
    } else {
      outPara.col = bPara.col;
    }
  }
}

void printHex(unsigned char byte) {
  cout << setw(2) << setfill('0') << hex << static_cast<int>(byte) << " ";
}
void printHex(uint64_t bytes) {
  cout << setw(8) << setfill('0') << hex << static_cast<int>(bytes) << " ";
}

int getDataBits(DataType type) {
  int eleBits = 16;
  switch (type) {
  case FP32:
  case UINT32:
  case SINT32:
    eleBits = 32;
    break;
  case FP24:
    eleBits = 24;
    break;
  case UINT4:
  case SINT4:
    eleBits = 4;
    break;
  case UINT8:
  case SINT8:
  case FP8E4:
  case FP8E5:
    eleBits = 8;
    break;
  default:
    break;
  }
  return eleBits;
}

uint64_t *readBinData(string &filename, int num, DataType type) {
  string line;
  ifstream file(filename, ios::binary | ios::ate);
  if (!file.is_open()) {
    cerr << "Error opening file: " << filename << endl;
    return nullptr;
  }
  streamsize size = file.tellg();
  file.seekg(0, ios::beg);
  vector<char> buffer(size);
  if (!file.read(buffer.data(), size)) {
    cerr << "Error reading file" << endl;
    return nullptr;
  }
  int eleBits = getDataBits(type);
  int dataNum = (eleBits == 4) ? size * 2 : (size * 8 / eleBits);
  if (dataNum != num) {
    cerr << "Data num dismatch: " << dataNum << "!=" << num << endl;
    return nullptr;
  }
  cout << "File: " << filename << ", size: " << size
       << " bytes, data num: " << dataNum << endl;

  uint64_t *out = new uint64_t[dataNum];
  int index = 0;
  if (eleBits == 4) {
    for (int i = 0; i < size; i++) {
      unsigned char byte = static_cast<unsigned char>(buffer[i]);
      out[index] = static_cast<uint64_t>(byte & 0xf);
      out[index + 1] = static_cast<uint64_t>((byte >> 4) & 0xf);
      index += 2;
    }
  } else if (eleBits == 8) {
    for (int i = 0; i < size; i++) {
      unsigned char byte = static_cast<unsigned char>(buffer[i]);
      out[index] = static_cast<uint64_t>(byte);
      index++;
    }
  } else if (eleBits == 16) {
    for (int i = 0; i < size; i += 2) {
      unsigned char byte0 = static_cast<unsigned char>(buffer[i]);
      unsigned char byte1 = static_cast<unsigned char>(buffer[i + 1]);
      out[index] =
          (static_cast<uint64_t>(byte1) << 8) + (static_cast<uint64_t>(byte0));
      index++;
    }
  } else if (eleBits == 32) {
    for (int i = 0; i < size; i += 4) {
      unsigned char byte0 = static_cast<unsigned char>(buffer[i]);
      unsigned char byte1 = static_cast<unsigned char>(buffer[i + 1]);
      unsigned char byte2 = static_cast<unsigned char>(buffer[i + 2]);
      unsigned char byte3 = static_cast<unsigned char>(buffer[i + 3]);
      out[index] = (static_cast<uint64_t>(byte3) << 24) +
                   (static_cast<uint64_t>(byte2) << 16) +
                   (static_cast<uint64_t>(byte1) << 8) +
                   (static_cast<uint64_t>(byte0));
      index++;
    }
  }

  file.close();
  return out;
}

bool compareBinFiles(const string &file1, const string &file2) {
  ifstream f1(file1, ios::binary);
  ifstream f2(file2, ios::binary);
  if (!f1.is_open()) {
    cerr << "cannt open: " << file1 << endl;
    return false;
  }
  if (!f2.is_open()) {
    cerr << "cannt open: " << file2 << endl;
    return false;
  }

  f1.seekg(0, ios::end);
  size_t size1 = static_cast<size_t>(f1.tellg());
  f1.seekg(0, ios::beg);

  f2.seekg(0, ios::end);
  size_t size2 = static_cast<size_t>(f2.tellg());
  f2.seekg(0, ios::beg);

  if (size1 != size2) {
    cout << "different file size :" << file1 << " size: " << size1 << " Bytes, "
         << file2 << " size: " << size2 << " Bytes" << endl;
  }

  size_t compareSize = min(size1, size2);
  bool filesAreIdentical = true;
  unsigned char b1, b2;
  int differentFound = 0;

  cout << "\nDifferent position(offset):\n" << endl;
  cout << "offset    | " << file1 << "        | " << file2 << endl;
  cout << "------------------------------------------------" << endl;
  for (size_t i = 0; i < compareSize; ++i) {
    f1.read(reinterpret_cast<char *>(&b1), 1);
    f2.read(reinterpret_cast<char *>(&b2), 1);
    if (b1 != b2) {
      filesAreIdentical = false;
      differentFound++;
      cout << dec << i << " 0x(" << hex << i << ") | ";
      printHex(b1);
      cout << "        | ";
      printHex(b2);
      cout << dec << endl;
    }
  }

  if (filesAreIdentical && size1 == size2) {
    cout << "\nTwo files are same." << endl;
    return true;
  } else {
    if (differentFound > 0) {
      cout << "\nTotal " << differentFound << " differences." << endl;
    }
    return false;
  }
}

bool compareHexData(uint64_t *out1, uint64_t *out2, size_t size,
                    test_matrix_t &cfg, uint64_t ulp) {
  if (out1 == nullptr) {
    cerr << "out1 empty" << endl;
    return false;
  }
  if (out2 == nullptr) {
    cerr << "out2 empty" << endl;
    return false;
  }
  if (size != cfg.row * cfg.col) {
    cerr << "size dismatch" << endl;
    return false;
  }
  bool filesAreIdentical = true;
  int differentFound = 0;

  cout << "\nDifferent position(offset):\n" << endl;
  cout << "offset     | out1                 | out2" << endl;
  cout << "------------------------------------------------" << endl;
  for (int i = 0; i < cfg.row; i++) {
    for (int j = 0; j < cfg.col; j++) {
      int idx = i * cfg.col + j;
      uint64_t diff = abs_diff(out1[idx], out2[idx]);
      if (diff > ulp) {
        filesAreIdentical = false;
        differentFound++;
        cout << idx << "(" << i << "," << j << ")     | ";
        printHex(out1[idx]);
        cout << "              | ";
        printHex(out2[idx]);
        cout << dec << endl;
      }
    }
  }

  delete[] out1;
  delete[] out2;

  if (filesAreIdentical) {
    cout << "\n✅ Result and out file are same." << endl;
    return true;
  } else {
    if (differentFound > 0) {
      cout << "\n❌ Total " << differentFound << " differences." << endl;
    }
    return false;
  }
}

bool test_matmul_compare(string &input, string &wgt, string &gout,
                         test_matrix_t &a_cfg, test_matrix_t &b_cfg) {
  cout << "======================Test MATMUL "
          "FUNCTION============================="
       << endl;
  uint64_t *bin_in1, *bin_in2, *g_out;
  int dnum = a_cfg.row * b_cfg.col;
  bin_in1 = readBinData(input, a_cfg.row * a_cfg.col, a_cfg.itype);
  bin_in2 = readBinData(wgt, b_cfg.row * b_cfg.col, b_cfg.itype);
  g_out = readBinData(gout, dnum, a_cfg.otype);

  if ((!bin_in1) || (!bin_in2) || (!g_out)) {
    return false;
  }

  uint16_t **in1 = new uint16_t *[a_cfg.row];
  uint16_t **in2 = new uint16_t *[b_cfg.col];
  uint64_t **rlt = new uint64_t *[a_cfg.row];
  uint64_t *u64_rlt = new uint64_t[dnum];
  for (int i = 0; i < a_cfg.row; i++) {
    in1[i] = new uint16_t[a_cfg.col];
    for (int j = 0; j < a_cfg.col; j++) {
      in1[i][j] = static_cast<uint16_t>(bin_in1[i * a_cfg.col + j]);
    }
  }
  // tranposed
  for (int i = 0; i < b_cfg.col; i++) {
    in2[i] = new uint16_t[b_cfg.row];
    for (int j = 0; j < b_cfg.row; j++) {
      in2[i][j] = static_cast<uint16_t>(bin_in2[i * b_cfg.row + j]);
    }
  }
  for (int i = 0; i < a_cfg.row; i++) {
    rlt[i] = new uint64_t[b_cfg.col];
    for (int j = 0; j < b_cfg.col; j++) {
      rlt[i][j] = 0;
    }
  }

  operators::matrix_opcode *matrix_opcode =
      operators::matrix_opcode::generate(0x0);
  operators::matmul_subcmd_T_sym_quant(in1, in2, rlt, nullptr, nullptr,
                                       a_cfg.col, a_cfg.row, b_cfg.col,
                                       a_cfg.itype, matrix_opcode);
  // pproc enable:fp32->bf16
  for (int i = 0; i < a_cfg.row; i++) {
    for (int j = 0; j < b_cfg.col; j++) {
      u64_rlt[i * b_cfg.col + j] = fp32_to_bf16(rlt[i][j]);
    }
  }

  delete matrix_opcode;
  delete[] bin_in1;
  delete[] bin_in2;
  for (int i = 0; i < a_cfg.row; i++) {
    delete[] in1[i];
    delete[] rlt[i];
  }
  delete[] in1;
  delete[] rlt;
  for (int i = 0; i < b_cfg.col; i++) {
    delete[] in2[i];
  }
  delete[] in2;

  test_matrix_t cfg;
  cfg.row = a_cfg.row;
  cfg.col = b_cfg.col;
  cfg.itype = a_cfg.otype;
  return compareHexData(u64_rlt, g_out, dnum, cfg);

  cout
      << "======================Test FUNCTION DONE============================="
      << endl;
  return true;
}

TESTCASE(DOP) { test_dop(); }

TESTCASE(SELFTEST_MATMUL) { test_matmul(); }

TESTCASE(MAMTUL) {
  // 17*17 BF16 mamtmul
  string inputFile = TESTCASE_PATH "cmodel/TestCase/bf16_matmul/input.bin";
  string wgtFile = TESTCASE_PATH "cmodel/TestCase/bf16_matmul/weight.bin";
  string goutFile = TESTCASE_PATH "cmodel/TestCase/bf16_matmul/out.bin";
  test_matrix_t cfg;
  cfg.row = 17;
  cfg.col = 17;
  ASSERT_TRUE(test_matmul_compare(inputFile, wgtFile, goutFile, cfg, cfg));
}

TESTCASE(PPROC) { test_pproc(); }

TESTCASE(DATA_CONVERT) { test_data_convert(); }

TESTCASE(SFU) {
  for (uint8_t i = 0; i < 10; i++) {
    test_sfu(i);
  }
}

TESTCASE(CONV_SUBCMD) { test_conv_subcmd(); }

TESTCASE(FP4_CONVERT) { tb_fp4(); }

TESTCASE(FP32TOFP8_CONVERT) { tb_f32tof8_1(); }

TESTCASE(IM2COL) { ASSERT_TRUE(test_conv()); }

bool test_mxfp4_compare(string &input, string &out, string &outScale,
                        test_matrix_t &cfg) {
  cout << "======================Test mxfp4 "
          "FUNCTION============================="
       << endl;
  test_matrix_t alignPara;
  fun_align_MK_input(cfg, alignPara); // size align.
  uint32_t intNum = cfg.row * alignPara.col;
  uint32_t scale_k =
      ceil(cfg.col / 32.0); // 32 is quant block num. for per group.
  uint32_t scaleNum = cfg.row * scale_k;
  printf("cfg.row  = %d \n", cfg.row);
  printf("cfg.col  = %d \n", cfg.col);
  printf("scale_k  = %d \n", scale_k);
  printf("alignPara.col  = %d \n", alignPara.col);
  printf("cfg.row * alignPara.col  = %d \n", cfg.row * alignPara.col);

  uint16_t *intDataGolden = new uint16_t[intNum];
  uint8_t *outScaleGoLden = new uint8_t[scaleNum];
  uint8_t *outGoLden = new uint8_t[intNum];
  uint64_t *in16, *out8, *scale;
  uint32_t inputDataGoldenNumByte = cfg.row * alignPara.col;    // byteNum
  uint32_t inputOutGoldenNumByte = cfg.row * alignPara.col / 2; // byteNum

  in16 = readBinData(input, inputDataGoldenNumByte, cfg.itype);
  out8 = readBinData(out, inputOutGoldenNumByte, cfg.otype);
  scale = readBinData(outScale, scaleNum, cfg.otype);
  printf("ok\n");

  if ((!in16) || (!out8) || (!scale)) {
    return false;
  }
  for (int i = 0; i < intNum; i++) {
    intDataGolden[i] = static_cast<uint16_t>(in16[i]);
  }
  for (int i = 0; i < scaleNum; i++) {
    outGoLden[i] = static_cast<uint8_t>(out8[i]);
  }
  for (int i = 0; i < scaleNum; i++) {
    outScaleGoLden[i] = static_cast<uint16_t>(scale[i]);
  }

  uint16_t mxfp4_fp8_flag = 0; // mxfp4
  uint8_t *outDataCm = new uint8_t[intNum];
  uint8_t *outScaleCm = new uint8_t[scaleNum];
  operators::vae_quant_perGroup_mxfp4_mxfp8(
      outDataCm, intDataGolden, outScaleCm, cfg.row, cfg.col, cfg.itype,
      cfg.itype, mxfp4_fp8_flag);

  uint8_t *outDataCmath = new uint8_t[intNum];
  uint8_t *outScaleCmath = new uint8_t[scaleNum];
  operators::quant_group_mxfp4_cmath(intDataGolden, outDataCmath, outScaleCmath,
                                     cfg.row, cfg.col, cfg.itype);
  delete[] intDataGolden;
  delete[] outScaleGoLden;
  delete[] outGoLden;
  delete[] outDataCm;
  delete[] outScaleCm;
  delete[] outDataCmath;
  delete[] outScaleCmath;
  delete[] in16;
  delete[] out8;
  delete[] scale;
  return 0;
}
// TESTCASE(MXFP4) {
//    string inputFile =
//        TESTCASE_PATH "cmodel/TestCase/vae_quant/group_mxfp4/input.bin";
//    string outFile =
//        TESTCASE_PATH "cmodel/TestCase/vae_quant/group_mxfp4/out.bin";
//    string outScaleFile =
//        TESTCASE_PATH "cmodel/TestCase/vae_quant/group_mxfp4/outScale.bin";
//    test_matrix_t cfg;
//    cfg.row = 128;
//    cfg.col = 2048;
//    cfg.itype = BF16;
//    cfg.otype = UINT8;
//    ASSERT_TRUE(test_mxfp4_compare(inputFile, outFile, outScaleFile, cfg));
//  }
TESTCASE(VAE_RAND) { test_vae(); }
// ADD TEST CASE
TESTCASE(VAE_RMSNORM_128_2048_bf16) {
  // 128*2048
  string inputFile = TESTCASE_PATH
      "cmodel/TestCase/vae_rmsnorm/rmsnorm_128_2048_bf16/input.bin";
  string wgtFile = TESTCASE_PATH
      "cmodel/TestCase/vae_rmsnorm/rmsnorm_128_2048_bf16/weight.bin"; // gamma
  string goutFile =
      TESTCASE_PATH "cmodel/TestCase/vae_rmsnorm/rmsnorm_128_2048_bf16/out.bin";
  test_matrix_t cfg; // row=128,col=2048;i_type=BF16;o_type=BF16.
  int flagGamma = 1;
  uint64_t ulp = 0;
  ASSERT_TRUE(
      test_rmsnorm_compare(inputFile, wgtFile, goutFile, cfg, flagGamma, ulp));
}
TESTCASE(VAE_RMSNORM_128_2048_fp16) {
  // 128*2048
  string inputFile =
      TESTCASE_PATH "cmodel/TestCase/vae_rmsnorm/rmsnorm_128_2048_fp16/"
                    "rmsnorm_input_128_2048_fp16.bin";
  string wgtFile =
      TESTCASE_PATH "cmodel/TestCase/vae_rmsnorm/rmsnorm_128_2048_fp16/"
                    "rmsnorm_weight_128_2048_fp16.bin"; // gamma
  string goutFile =
      TESTCASE_PATH "cmodel/TestCase/vae_rmsnorm/rmsnorm_128_2048_fp16/"
                    "rmsnorm_output_128_2048_fp16.bin";
  test_matrix_t cfg; // row=128,col=2048;i_type=BF16;o_type=BF16.
  cfg.itype = FP16;
  cfg.otype = FP16;
  int flagGamma = 1;
  uint64_t ulp = 5;
  ASSERT_TRUE(
      test_rmsnorm_compare(inputFile, wgtFile, goutFile, cfg, flagGamma, ulp));
}