#include <omp.h>
#include <iostream>
#include <windows.h>
#include <iomanip>

int main() {
	double start, end;
	int k = 4;
	int N;
	std::cout << "Enter N: ";
	std::cin >> N;
	double pi = 0;
	start = omp_get_wtime();
	#pragma omp parallel shared(pi) num_threads(k)
	{
		#pragma omp for
		for (int i = 0; i < N; ++i) {
			#pragma omp critical
			{
				double x = (i + 0.5) / N;
				pi += 4 / (1 + x * x) / N;
			}
		}
	}
	std::cout.precision(9);
	std::cout << "Sum: " << pi << '\n';
	end = omp_get_wtime();
	std::cout << "Time: " << end - start << '\n';
}