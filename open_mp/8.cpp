#include <omp.h>
#include <iostream>
#include <windows.h>
#include <iomanip>

int main() {
	int k = 4;
	int N;
	std::cout << "Enter N: ";
	std::cin >> N;
	double pi = 0;
#pragma omp parallel reduction(+:pi) num_threads(k)
	{
#pragma omp for schedule(guided, 2)
		for (int i = 0; i < N; ++i) {
			double x = (i + 0.5) / N;
			pi += 4 / (1 + x * x) / N;
		}
	}
	std::cout.precision(9);
	std::cout << "Sum: " << pi;
}