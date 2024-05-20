#include <omp.h>
#include <iostream>

int main() {
	#pragma omp parallel num_threads(4)
	printf("I am %d thread from %d threads!\n",
		omp_get_thread_num(),
		omp_get_num_threads()
	);
}