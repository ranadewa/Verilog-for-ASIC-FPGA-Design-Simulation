
#include "unionKernels.h"

extern "C" void unionTest(int i,  ap_uint<1>* val) {

	ABCVal original{.val = 0};
	original.abc.a = i % 8;
	original.abc.b = i % 16;
	original.abc.c = i % 256;

	cout << "input: " << i << ", created val: " << original.val << endl;
	cout << "a: " << original.abc.a << " b: " << original.abc.b << " c: " << original.abc.c << endl;

	ABCVal dup{.val = 0};
	dup.val = original.val;

	cout << "a: " << dup.abc.a << " b: " << dup.abc.b << " c: " << dup.abc.c << endl;

	if(original.abc.a == dup.abc.a &&
	   original.abc.b == dup.abc.b &&
	   original.abc.c == dup.abc.c ) {
		*val = 1;
	} else {
		*val  = 0;
	}
}
