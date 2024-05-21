#include <omp.h>
#include <iostream>
#include <windows.h>

int main() {
	int k = 4;
	std::cout << "k: ";
	std::cin >> k;
	int N = 10;
	std::cout << "N: ";
	std::cin >> N;
	int sum = 0;
#pragma omp parallel reduction(+:sum) num_threads(k)
	{
#pragma omp for
		for (int i = 1; i <= N; ++i) {
#pragma omp atomic
			sum += i;
		}
	}
	std::cout << sum;
}