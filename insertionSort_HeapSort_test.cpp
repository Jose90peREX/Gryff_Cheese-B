#include "gtest/include/gtest/gtest.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

vector<int>generateRandomNumber(int size, int minVal = 1, int maxVal = 100){
 
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(minVal, maxVal);

	vector<int> v(size);
	generate(v.begin(), v.end(), [&]() {return dist(gen);});
	return v;

}

TEST(HeapSortTest, RandomNumbersTest){
   int size = 10;
   vector<int> v = generateRandomNumber(size);
   vector<int> expected = v;
   
   Heap heap;
   heap.ascendingHeapSort(v.data(), v.size());
   sort(expected.begin(), expected.end());
   ASSERT_EQ(v, expected);
}



