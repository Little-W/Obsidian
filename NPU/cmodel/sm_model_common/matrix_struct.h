#ifndef _matrix_struct_h
#define _matrix_struct_h

#include "sfu_common.h"
#include "sm_datatype_utils.h"
#include "softfloat.h"
#include <assert.h>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

// YHG ==>
#define ENABLE_OPENMP 1
#if ENABLE_OPENMP
#define NUM_THREADS_OPENMP 32 // 4:4.567s
#define OPENMP_SCH schedule(dynamic, 1)
#endif
// YHG <==

namespace operators {
#define DOP_16_BLOCKSIZE 16
#define DOP_32_BLOCKSIZE 32
#define DOP_64_BLOCKSIZE 64

inline float ui16_to_float(uint16_t u) {
  float f;
  float16_t f16;
  f16.v = u;
  float32_t f32 = f16_to_f32(f16);
  f = float32_to_float(f32);
  return f;
}
inline uint16_t float_to_ui16(float f) {
  uint16_t u;
  float16_t f16;
  float32_t vf;
  memcpy(&vf.v, &f, sizeof(float));
  f16 = f32_to_f16(vf);
  u = f16.v;
  return u;
}

struct conv_stride {
  uint32_t stride_h = 1;
  uint32_t stride_w = 1;
  void set(uint32_t h, uint32_t w) {
    if (h == 0)
      stride_h = 1;
    if (w == 0)
      stride_w = 1;
    stride_h = h;
    stride_w = w;
  }
};
struct conv_dilation {
  uint32_t h_rate = 1;
  uint32_t w_rate = 1;
  void set(uint32_t h, uint32_t w) {
    if (h == 0)
      h_rate = 1;
    if (w == 0)
      w_rate = 1;
    h_rate = h;
    w_rate = w;
  }
};
struct conv_padding {
  uint32_t padding_mode = 0;
  uint16_t padding_value = 0; // pading_mode=1
  uint32_t padding_top = 0;
  uint32_t padding_bottom = 0;
  uint32_t padding_left = 0;
  uint32_t padding_right = 0;
  void set_mode(uint32_t m) { padding_mode = m; } // support 0,1
  void set_padv(uint16_t v) { padding_value = v; }
  void set(uint32_t pt, uint32_t pb, uint32_t pl, uint32_t pr) {
    padding_top = pt;
    padding_bottom = pb;
    padding_left = pl;
    padding_right = pr;
  }
  bool is_pad() {
    return (padding_bottom || padding_top || padding_left || padding_right);
  }
};

template <typename T = uint16_t> class MATRIX_2D {
public:
  int nr;        // numbers of row
  int nc;        // numbers of column
  T **data;      // data type
  DataType type; // FP16,FP32

  MATRIX_2D(int row, int col, DataType t) {
    type = t;
    nr = row;
    nc = col;
    data = new T *[nr];
    for (int i = 0; i < nr; i++) {
      data[i] = new T[nc]();
    }
  }
  MATRIX_2D() {
    nr = 0;
    nc = 0;
    data = nullptr;
    type = FP16;
  }
  ~MATRIX_2D() { release(); }
  MATRIX_2D(MATRIX_2D &&other) {
    type = other.type;
    nr = other.nr;
    nc = other.nc;
    data = other.data;
    other.data = nullptr;
  }
  MATRIX_2D &operator=(MATRIX_2D &&other) {
    type = other.type;
    nr = other.nr;
    nc = other.nc;
    release();
    data = other.data;
    other.data = nullptr;
    return *this;
  }
  void release() {
    if (data == nullptr)
      return;
    for (int i = 0; i < nr; i++)
      if (data[i]) {
        delete[] data[i];
        data[i] = nullptr;
      }
    delete[] data;
    data = nullptr;
  }
  void reset_for_lowbit(uint8_t Ebits) {
    if (Ebits == 16)
      return;
    uint32_t mask = (1 << Ebits) - 1;
    uint8_t block_num = 16 / Ebits;
    size_t new_nc = nc * block_num;
    T **data_new = new T *[nr];
#if ENABLE_OPENMP
    size_t j;
#pragma omp parallel for OPENMP_SCH private(j) shared(nr, nc, data_new, data)  \
    num_threads(NUM_THREADS_OPENMP)
#endif
    for (size_t i = 0; i < nr; i++) {
      data_new[i] = new T[new_nc]();
#if ENABLE_OPENMP
      for (j = 0; j < nc; j += 1) {
#else
      for (size_t j = 0; j < nc; j += 1) {
#endif
        // cout << hex << static_cast<int>(data[i][j]) << " ";
        for (size_t block_id = 0; block_id < block_num; block_id++)
          data_new[i][j * block_num + block_id] =
              data[i][j] >> (block_id * Ebits) & mask;
      }
    }
    release();
    nc = new_nc;
    data = data_new;
    data_new = nullptr;
  }
  void reset(int row, int col, DataType t) {
    if (data)
      release();
    type = t;
    nr = row;
    nc = col;
    data = new T *[nr];
    for (int i = 0; i < nr; i++) {
      data[i] = new T[nc]();
    }
  }

  void print_mt() {
    cout << "row_num:" << nr << ",col_num:" << nc << endl;
    for (int i = 0; i < nr; i++) {
      for (int j = 0; j < nc; j++) {
        if (type == FP16 || type == UINT16) {
          cout << ui16_to_float(data[i][j]) << " ";
        } else if (type == FP32) {
          cout << ui32_to_float(data[i][j]) << " ";
        }
      }
      cout << endl;
    }
  }
  void print_mt_hex() {
    cout << "row_num:" << nr << ",col_num:" << nc << endl;
    for (int i = 0; i < nr; i++) {
      cout << "row_num:" << i << endl;
      for (int j = 0; j < nc; j++) {
        if (type == UINT8 || type == SINT8)
          cout << hex << static_cast<int>(data[i][j]) << " ";
        else
          cout << hex << data[i][j] << " ";
      }
      cout << dec << endl;
    }
  }
  void mat_padding(MATRIX_2D &result, conv_padding &pad) {
    int row = nr + pad.padding_top + pad.padding_bottom;
    int col = nc + pad.padding_left + pad.padding_right;
    result.reset(row, col, type);
    for (int h = 0; h < row; h++) {
      for (int w = 0; w < col; w++) {
        result.data[h][w] = pad.padding_value;
      }
    }
    // copy original data
    for (int i = 0; i < nr; i++) {
      for (int j = 0; j < nc; j++) {
        result.data[i + pad.padding_top][j + pad.padding_left] = data[i][j];
      }
    }
  }

  void self_padding_32(const int padding_dim) {
    if (padding_dim == 0) {
      if (nr % 32) {
        reset(nr + 32 - nr % 32, nc, type);
      }
      return;
    }
    if (padding_dim == 1) {
      if (nc % 32) {
        reset(nr, nc + 32 - nc % 32, type);
      }
      return;
    }
  }

  void transpose(T **src, int row, int col, DataType t) {
    reset(row, col, t);
    for (int i = 0; i < nr; i++) {
      for (int j = 0; j < nc; j++) {
        data[i][j] = src[j][i];
      }
    }
  }
};

template <typename T = uint16_t> class MATRIX_4D {
public:
  int bz;        // batch size,input bz=1,kernel bz used as c_out
  int ch;        // channels of matrix
  int nr;        // rows per channel
  int nc;        // cols per channel
  T ****data;    // data type fp16
  DataType type; // FP16,FP32

  MATRIX_4D() {
    bz = 0;
    ch = 0;
    nr = 0;
    nc = 0;
    data = nullptr;
    type = FP16;
  }
  MATRIX_4D(int b, int c, int row, int col, DataType t) {
    reset(b, c, row, col, t);
  }
  ~MATRIX_4D() { release(); }
  void reset(int b, int c, int row, int col, DataType t) {
    if (data)
      release();
    type = t;
    bz = b;
    ch = c;
    nr = row;
    nc = col;
    data = new T ***[b];
    for (int bi = 0; bi < b; bi++) {
      data[bi] = new T **[ch];
      for (int ci = 0; ci < ch; ci++) {
        data[bi][ci] = new T *[nr];
        for (int ri = 0; ri < nr; ri++) {
          data[bi][ci][ri] = new T[nc];
        }
      }
    }
  }
  void release() {
    if (data == nullptr)
      return;
    for (int bi = 0; bi < bz; bi++) {
      if (data[bi] == nullptr)
        return;
      for (int ci = 0; ci < ch; ci++) {
        if (data[bi][ci] == nullptr)
          return;
        for (int ri = 0; ri < nr; ri++) {
          if (data[bi][ci][ri] == nullptr)
            return;
          delete[] data[bi][ci][ri];
          data[bi][ci][ri] = nullptr;
        }
        delete[] data[bi][ci];
        data[bi][ci] = nullptr;
      }
      delete[] data[bi];
      data[bi] = nullptr;
    }
    delete[] data;
    data = nullptr;
  }

  void set_data(uint8_t *bytes, int type, uint8_t Ebits, bool wr_back) {
    // act [b,c,H,W], batch_size==1
    int KBytes = Ebits / 8;
    int cBytes = ((ch * KBytes - 1) / 32 + 1) * 32;
    int wBytes = nc * cBytes;
    int hBytes = nr * wBytes;
    for (int b = 0; b < bz; b++) {
      for (int c = 0; c < ch; c++) {
        for (int r = 0; r < nr; r++) {
          for (int n = 0; n < nc; n++) {
            uint8_t *ptr =
                bytes + b * hBytes + r * wBytes + n * cBytes + c * KBytes;
            if (wr_back) {
              memcpy(ptr, &data[b][c][r][n], KBytes);
            } else {
              memcpy(&data[b][c][r][n], ptr, KBytes);
            }
          }
        }
      }
    }
  }

  void print_mt() {
    cout << "batch size:" << bz << ", channel_num:" << ch << ", row_num:" << nr
         << ",col_num:" << nc << endl;
    for (int bi = 0; bi < bz; bi++) {
      for (int ci = 0; ci < ch; ci++) {
        cout << dec << "N=" << bi << ", C=" << ci << endl;
        for (int ri = 0; ri < nr; ri++) {
          for (int cli = 0; cli < nc; cli++) {
            if (type == FP16 || type == UINT16) {
              cout << ui16_to_float(data[bi][ci][ri][cli]) << " ";
            } else if (type == FP32) {
              cout << ui32_to_float(data[bi][ci][ri][cli]) << " ";
            }
          }
          cout << endl;
        }
        cout << endl;
      }
      cout << endl;
    }
    cout << endl;
  }
  void print_mt_hex() {
    cout << "batch size:" << bz << ", channel_num:" << ch << ", row_num:" << nr
         << ",col_num:" << nc << endl;
    for (int bi = 0; bi < bz; bi++) {
      for (int ci = 0; ci < ch; ci++) {
        cout << dec << "N=" << bi << ", C=" << ci << endl;
        for (int ri = 0; ri < nr; ri++) {
          for (int cli = 0; cli < nc; cli++) {
            cout << hex << setfill('0') << setw(4) << data[bi][ci][ri][cli]
                 << " ";
          }
          cout << endl;
        }
        cout << endl;
      }
      cout << endl;
    }
    cout << dec << endl;
  }

  void mat_padding(MATRIX_4D &result, conv_padding &pad) {
    int row = nr + pad.padding_top + pad.padding_bottom;
    int col = nc + pad.padding_left + pad.padding_right;
    result.reset(bz, ch, row, col, type);
    for (int b = 0; b < bz; b++) {
      for (int c = 0; c < ch; c++) {
        for (int h = 0; h < row; h++) {
          for (int w = 0; w < col; w++) {
            result.data[b][c][h][w] = pad.padding_value;
          }
        }
        // copy original data
        for (int i = 0; i < nr; i++) {
          for (int j = 0; j < nc; j++) {
            result.data[b][c][i + pad.padding_top][j + pad.padding_left] =
                data[b][c][i][j];
          }
        }
      }
    }
  }
};

// array data -> matrix data
void set_data(MATRIX_2D<uint16_t> &dat, uint16_t arr[], DataType type, int row,
              int col);
void set_data(MATRIX_4D<uint16_t> &dat, uint16_t arr[], DataType type,
              int batchz, int channel, int row, int col);
// matrix_data -> array_data
void set_data(uint64_t arr[], MATRIX_2D<uint64_t> &dat, int row, int col);
void set_data(uint64_t arr[], MATRIX_4D<uint64_t> &dat, int batchz, int channel,
              int row, int col);

typedef struct {
  DataType data_type;
  size_t M_tile_count;
  size_t K_tile_count;
  size_t N_tile_count;
  size_t M_tile_size;
  size_t K_tile_size;
  size_t N_tile_size;
  size_t M_block_size = 8;
  size_t N_block_size = 8;
  size_t m_size;
  size_t k_size;
  size_t n_size;
  size_t otile_count;
  size_t otile_inner_i;
  size_t otile_inner_j;
  size_t m;
  size_t n;
  size_t k;
} otile_location_t;
} // namespace operators
#endif