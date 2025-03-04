#include "gtest/include/gtest/gtest.h"
#include "SelectionSort.h"
#include <vector>
#include <random>
#include <numeric> 
#include <algorithm>
using namespace std;

//Sorted
TEST(SelectionTest, SortedSelection) {
    vector<int> vec(1000);
    iota(vec.begin(), vec.end(), 1);
    vector<int> sorted_vec = vec;
    selectionSort(vec.data(), vec.size());
    ASSERT_EQ(vec, sorted_vec);
}

//Unsorted
TEST(SelectionTest, UnsortedSelection) {
    vector<int> vec(1000);
    iota(vec.begin(), vec.end(), 1);
    vector<int> sorted_vec = vec;

    std::random_device rd;
    unsigned seed = rd();
    std::mt19937 r(seed);
    shuffle(vec.begin(), vec.end(), r);

    selectionSort(vec.data(), vec.size());
    ASSERT_EQ(vec, sorted_vec);
}


//Reversed
TEST(SelectionTest, ReversedSelection) {
   vector<int> vec(1000);
   iota(vec.begin(), vec.end(), 1);
   vector<int> sorted_vec = vec;
   reverse(vec.begin(), vec.end());
   selectionSort(vec.data(), vec.size());
   ASSERT_EQ(vec, sorted_vec);
}

//Small Vector
TEST(SelectionTest, SmallSelection) {
   vector<int> vec(10);
   iota(vec.begin(), vec.end(), 1);
   vector<int> sorted_vec = vec;
   std::random_device rd;
   unsigned seed = rd();
   std::mt19937 r(seed);
   shuffle(vec.begin(), vec.end(), r);
   selectionSort(vec.data(), vec.size());
   ASSERT_EQ(vec, sorted_vec);
}

//Negative Vector
TEST(SelectionTest, NegativeSelection) {
    vector<int> vec(1000);
    for (int i = 0; i < vec.size(); i++) { vec[i] = i - 500; }
    vector<int> sorted_vec = vec;
    sort(sorted_vec.begin(), sorted_vec.end());

    std::random_device rd;
    unsigned seed = rd();
    std::mt19937 r(seed);
    shuffle(vec.begin(), vec.end(), r);
    selectionSort(vec.data(), vec.size());
    ASSERT_EQ(vec, sorted_vec);
}

//Partially Sorted
TEST(SelectionTest, PartialSelection) {
    vector<int> vec(1000);
    iota(vec.begin(), vec.end(), 1);
    vector<int> sorted_vec = vec;
    
    std::random_device rd;
    unsigned seed = rd();
    std::mt19937 r(seed);

    shuffle(vec.begin(), vec.begin() + vec.size()/2, r);
    selectionSort(vec.data(), vec.size());
    ASSERT_EQ(vec, sorted_vec);
}

