#include <omp.h>
#include <iostream>
#include <windows.h>

int main() {
	int rank;
#pragma omp parallel private(rank) num_threads(4)
	{
		rank = omp_get_thread_num();
		Sleep(100); // Имитация длительных вычислений
		printf("I am %d thread.\n", rank);
	}
}