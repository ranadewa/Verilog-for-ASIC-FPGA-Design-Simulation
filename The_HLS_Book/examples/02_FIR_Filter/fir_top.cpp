#include "fir_top.h"
#include "iostream"

extern "C" void fir(data_t *y, data_t x){

	coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};

	static data_t shif_reg[N];
	acc_t acc;
	int i;

	acc = 0;

	Shift_Acc_Loop:

	for (i = N-1; i >= 0; i--)
	{
		if(i == 0) {
			acc += x * c[0];
			shif_reg[0] = x;
		} else {
			shif_reg[i] = shif_reg[i-1];
			acc += shif_reg[i] * c[i];
		}
	}

	*y = acc;
}

extern "C" void fir_code_hoist(data_t *y, data_t x){

	coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};

	static data_t shif_reg[N];
	acc_t acc;
	int i;

	acc = 0;

	Shift_Acc_Loop:

	for (i = N-1; i > 0; i--)
	{
		shif_reg[i] = shif_reg[i-1];
		acc += shif_reg[i] * c[i];
	//	std::cout << "shif_reg[" << i << "] * c[" <<i << "]: " << shif_reg[i] * c[i] << ", acc: " << acc << std::endl;
	}

	acc += x * c[0];
	shif_reg[0] = x;
	//std::cout << "shif_reg[0] * c[0]: " << shif_reg[0] * c[0] << ", acc: " << acc << std::endl;

	*y = acc;
}


extern "C"  void fir_loop_fission(data_t *y, data_t x) {
	coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};

	static data_t shif_reg[N];
	acc_t acc;
	int i;

	acc = 0;

	Tapped_delay_line:
	for (i = N-1; i > 0; i--)
	{
		shif_reg[i] = shif_reg[i-1];
	}

	shif_reg[0] = x;

	Multiply_and_accumulate:


	for (i = N-1; i >= 0; i--)
	{
		acc += shif_reg[i] * c[i];
	}

	*y = acc;
}


extern "C"  void fir_loop_unroling(data_t *y, data_t x) {
	coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};

	static data_t shif_reg[N];
#pragma HLS ARRAY_PARTITION dim=1 type=complete variable=shif_reg
	acc_t acc;
	int i;

	acc = 0;

	Tapped_delay_line:
#pragma HLS unroll //factor=2
//#pragma HLS array partition variable=shift reg complete
	for (i = N-1; i > 0; i--)
	{
		shif_reg[i] = shif_reg[i-1];
	}

	shif_reg[0] = x;

	Multiply_and_accumulate:

#pragma HLS unroll
	for (i = N-1; i >= 0; i--)
	{
		acc += shif_reg[i] * c[i];
	}

	*y = acc;
}







