
#ifndef _datatype_utils_h_
#define _datatype_utils_h_

#include <stdint.h>
typedef enum {
  FP16,
  FP24,
  FP32,
  BF16,
  FP8E5,
  FP8E4,
  FP8E5FP6E3,
  FP8E5FP6E2,
  FP8E4FP6E3,
  FP8E4FP6E2,
  NVFP4E2,
  FP6E2,
  FP6E3,

  UINT4,
  SINT4,
  UINT8,
  SINT8,
  UINT16,
  SINT16,
  SINT8UINT8,
  UINT8SINT8,
  SINT16SINT8,
  UINT16SINT8,
  SINT16SINT4,
  SINT16UINT4,
  UINT16SINT4,
  UINT16UINT4,

  FP16UINT4,
  BF16UINT4,
  FP16SINT4,
  BF16SINT4,
  BF16MXFP4,
  FP8INT4,

  MXFP8MXFP8,
  MXFP4MXFP4,

  // for pproc
  SINT40,
  UINT32,
  SINT32
} DataType;

typedef uint64_t fp_general_t;
typedef uint32_t uint24_t;
typedef struct {
  uint32_t v;
} float24_t;

#endif