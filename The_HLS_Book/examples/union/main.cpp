#include "unionKernels.h"

int main() {

	ABCVal original{.val = 0};
	ABCVal dup{.val = 0};

	ap_uint<1> result = 0;
	for(int i = 0; i < 6400; i++) {
		unionTest(i, &result);
		assert(result == 1);

	}

	return 0;
}
