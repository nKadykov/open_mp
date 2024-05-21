#include <omp.h>
#include <iostream>
#include <windows.h>

int main() {
	const int N = 10;
	int sum = 0;
#pragma omp parallel reduction(+:sum) num_threads(2)
	{
		if (omp_get_thread_num() == 0) {
			for (int i = 1; i < N / 2; ++i) {
				sum += i;
			}
		}
		else {
			for (int i = N / 2; i < N; ++i) {
				sum += i;
			}
		}
	}
	std::cout << sum;
}