#include <omp.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <iomanip>

int main() {
	int k = 4;
	#pragma omp parallel num_threads(k)
	{
		#pragma omp sections
		{
			#pragma omp section
			{
				int section = 1;
				printf("[<%d>]: came in section <%d>\n", omp_get_thread_num() + 1, section);
			}
			#pragma omp section
			{
				int section = 2;
				printf("[<%d>]: came in section <%d>\n", omp_get_thread_num() + 1, section);
			}
			#pragma omp section
			{
				int section = 3;
				printf("[<%d>]: came in section <%d>\n", omp_get_thread_num() + 1, section);
			}
			#pragma omp section
			{
				int section = 4;
				printf("[<%d>]: came in section <%d>\n", omp_get_thread_num() + 1, section);
			}
		}
	}
}