#include <omp.h>
#include <iostream>
#include <windows.h>

int main() {
	int k = 4;
	int N = 10;
	int sum = 0;
#pragma omp parallel reduction(+:sum) num_threads(k)
	{
#pragma omp for schedule(guided, 2)
		for (int i = 1; i <= N; ++i) {
			sum += i;
			printf("[%d]: calculation of the iteration number <%d> Sum: %d\n", omp_get_thread_num(), i, sum);
		}
	}
	std::cout << "Sum: " << sum;
}