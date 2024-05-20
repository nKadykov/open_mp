#include <omp.h>
#include <iostream>

int main() {
	omp_set_num_threads(4);
	#pragma omp parallel
	{
		std::cout << "Hello World!\n";
	}
}