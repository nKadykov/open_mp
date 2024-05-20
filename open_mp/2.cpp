#include <omp.h>
#include <iostream>

int main() {
	#pragma omp parallel num_threads(4)
	{
		printf("Hello World!\n");
	}
}