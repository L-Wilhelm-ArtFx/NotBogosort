#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <random>
#include <vector>

typedef unsigned int el_t;

const el_t EL_MIN = 0;
const el_t EL_MAX = UINT_MAX;
const size_t COUNT = 10000ULL;

void populateRandomly(std::vector<el_t> &vec)
{
	vec.clear();
	vec.resize(COUNT);

	std::default_random_engine gen;
	std::uniform_int_distribution<el_t> distr(EL_MIN, EL_MAX);

	printf("Populating %lld elements\n", COUNT);
	std::flush(std::cout);
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		*it = distr(gen);
	}

	printf("\tDone\n");
	std::flush(std::cout);
}

void bubbleSort(std::vector<el_t> &elements)
{
	// printf("Bubble sort...\n");

	bool sorted;
	do
	{
		sorted = true;

		el_t last = elements[0];
		for (size_t i = 1; i < elements.size(); ++i)
		{
			el_t curr = elements[i];
			if (last > curr)
			{
				// SWAP
				elements[i - 1] = curr;
				elements[i] = last;
				sorted = false;
			}
			last = elements[i];
		}

	} while (!sorted);
}

void selectionSort(std::vector<el_t> &elements)
{
	// printf("Selection sort...\n");

	for (auto it = elements.begin(); it != --elements.end(); ++it)
	{
		auto it2 = it + 1;
		auto it3 = it2;
		el_t compare = *it3;
		while (it2 != elements.end())
		{
			if (*it2 < compare)
			{
				compare = *it2;
				it3 = it2;
			}
			++it2;
		}
		if (compare < *it)
		{
			auto swap = *it3;
			*it3 = *it;
			*it = swap;
		}
	}
}

int main(int argc, char const *argv[])
{

	std::vector<el_t> elements;

	// ====

	// BUBBLE SORT
	{
		printf("> Bubble sort:\n");
		std::flush(std::cout);
		populateRandomly(elements);

		auto tStart{std::chrono::high_resolution_clock::now()};

		bubbleSort(elements);

		auto tEnd{std::chrono::high_resolution_clock::now()};
		auto elapsedNs{std::chrono::duration_cast<std::chrono::microseconds>(tEnd - tStart).count()};

		printf("Bubblesort finished in %lld microseconds\n", elapsedNs);
	}

	// SELECTION SORT
	{
		printf("> Selection sort:\n");
		std::flush(std::cout);
		populateRandomly(elements);

		auto tStart{std::chrono::high_resolution_clock::now()};

		selectionSort(elements);

		auto tEnd{std::chrono::high_resolution_clock::now()};
		auto elapsedNs{std::chrono::duration_cast<std::chrono::microseconds>(tEnd - tStart).count()};

		printf("Selectionsort finished in %lld microseconds\n", elapsedNs);
	}

	// ====

	// printf("Writing result to sorted.txt\n");
	// std::ofstream file;
	// file.open(argv[2]);

	// for (auto it = elements.begin(); it != elements.end(); ++it)
	// {
	// 	file << std::format("{}\n", *it);
	// }

	// file.flush();
	// file.close();
	// printf("\tDone\n");

	return 0;
}