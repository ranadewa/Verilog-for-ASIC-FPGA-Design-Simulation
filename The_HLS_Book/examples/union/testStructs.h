#pragma once
#include "ap_int.h"


struct ABC {
	ap_uint<3> a = 0;
	ap_uint<4> b = 0;
	ap_uint<64> c = 0;
};

union ABCVal{
	ap_uint<71> val =0;
	ABC abc;

} ;
