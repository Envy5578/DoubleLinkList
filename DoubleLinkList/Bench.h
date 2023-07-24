#pragma once
#include <chrono>
#include "Double.h"

namespace Benchmark {
		/*template <typename Type>*/
	long long test_push_and_pop(long long push)
	{
		DataStructure::Double<int> list;

		auto begin = std::chrono::steady_clock::now();

		for (size_t i = 0; i < push; i++)
		{
			list.push_back(rand() % 100);
		}
		for (size_t i = 0; i < push; i++)
		{
			list.pop_back();	
		}

		auto end = std::chrono::steady_clock::now();
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		/*std::cout << list;*/
		return ms.count();

	}
	long long test_sortSel(DataStructure::Double<int> list) {
		auto begin = std::chrono::steady_clock::now();
		
		DataStructure::Sort(list);
		auto end = std::chrono::steady_clock::now();
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		return ms.count();
	}
	long long test_sortBub(DataStructure::Double<int> list) {
		
		auto begin = std::chrono::steady_clock::now();

		DataStructure::SortBub(list);
		auto end = std::chrono::steady_clock::now();
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		return ms.count();
	}
}