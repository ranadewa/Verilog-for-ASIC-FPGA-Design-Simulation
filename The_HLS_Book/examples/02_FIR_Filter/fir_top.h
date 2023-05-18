#define N 11
#include "ap_int.h"

using coef_t = int;
using data_t = int;
using acc_t = int;

extern "C"  void fir(data_t *y, data_t x);
extern "C"  void fir_code_hoist(data_t *y, data_t x);
extern "C"  void fir_loop_fission(data_t *y, data_t x);
extern "C"  void fir_loop_unroling(data_t *y, data_t x);
extern "C"  void fir_loop_pipelining(data_t *y, data_t x);

