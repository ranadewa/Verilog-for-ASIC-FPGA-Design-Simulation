#include "fir_top.h"
#include <iostream>

int main() {

	for (size_t i = 0; i < 10; i++)
	{
		data_t y1, y2, y3, y4;
		fir(&y1, i%2);
		fir_code_hoist(&y2, i%2);
		fir_loop_fission(&y3, i%2);
		fir_loop_unroling(&y4, i%2);

		assert(y1 == y2);
		assert(y1 == y3);
		assert(y1 == y4);

		std::cout << "input: " << std::dec << i << ", y1: " << y1 << ", y2: " << y2 << std::endl;
	}
	
	return 0;
}
