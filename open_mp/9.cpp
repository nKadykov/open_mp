#include <omp.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <iomanip>

int main() {
	int k = 4;
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;
	std::cout << "Enter " << n * n * 2 << " numbers:";
	std::vector<std::vector<double>> vector_a(n, std::vector<double>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> vector_a[i][j];
		}
	}
	std::vector<std::vector<double>> vector_b(n, std::vector<double>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> vector_b[i][j];
		}
	}
	std::vector<std::vector<double>> vector_c(n, std::vector<double>(n));
#pragma omp parallel num_threads(k)
	{
#pragma omp for schedule(guided, 2)
		for (int i = 0; i < n; ++i) {
			for (int m = 0; m < n; ++m) {
				for (int j = 0; j < n; ++j) {
					vector_c[i][m] += vector_a[i][j] * vector_b[j][m];
				}
			}
		}
	}
	std::cout << "Result:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << vector_c[i][j] << ' ';
		}
		std::cout << '\n';
	}
}