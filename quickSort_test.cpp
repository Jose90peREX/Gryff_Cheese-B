#include "gtest/include/gtest/gtest.h"
#include "quickSort.h"
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>
using namespace std;

//Unsorted
TEST(UnsortedQuick, QuickSortTest) {
    vector<int> vec(1000000); //Vector sized 1,000,000
    iota(vec.begin(), vec.end(), 1);
    vector<int> sorted_vec = vec; //Copy vector "sorted_vec" to another vector, "vec" to retain 

    std::random_device rd;
    unsigned seed = rd();
    std::mt19937 r(seed);
    shuffle(vec.begin(), vec.end(), r);

    quickSort(vec.data(), 0, vec.size()-1, 0);
    ASSERT_EQ(vec, sorted_vec);
}

//Reversed
TEST(ReversedQuick, QuickSortTest) {
   vector<int> vec(1000000);
   iota(vec.begin(), vec.end(), 1);
   vector<int> sorted_vec = vec;

   reverse(vec.begin(), vec.end());
   quickSort(vec.data(), 0, vec.size()-1, 0);
   ASSERT_EQ(vec, sorted_vec); 
}

//Sorted
TEST(SortedQuick, QuickSortTest) {
    vector<int> vec(1000000);
    iota(vec.begin(), vec.end(), 1);
    vector<int> sorted_vec = vec;
    quickSort(vec.data(), 0, vec.size()-1, 0);
    ASSERT_EQ(vec, sorted_vec);
}

//Small Vector
TEST(SmallQuick, QuickSortTest) {
    vector<int> vec(10);
    iota(vec.begin(), vec.end(), 1);
    vector<int> sorted_vec = vec;

    std::random_device rd;
    unsigned seed = rd();
    std::mt19937 r(seed);

    shuffle(vec.begin(), vec.end(), r);
    quickSort(vec.data(), 0, vec.size()-1, 0);
    ASSERT_EQ(vec, sorted_vec);
}

//Negative Vector
TEST(NegativeQuick, QuickSortTest) {
    vector<int> vec(1000000);
    for (int i = 0; i < vec.size(); i++) { vec[i] = i - 500000; }
    vector<int> sorted_vec = vec;
    sort(sorted_vec.begin(), sorted_vec.end());

    std::random_device rd;
    unsigned seed = rd();
    std::mt19937 r(seed);
    shuffle(vec.begin(), vec.end(), r);
    quickSort(vec.data(), 0, vec.size()-1, 0);
    ASSERT_EQ(vec, sorted_vec);
}

//Partially Sorted
TEST(PartialQuick, QuickSortTest) {
    vector<int> vec(1000000);
    iota(vec.begin(), vec.end(), 1);
    vector<int> sorted_vec = vec;
    
    std::random_device rd;
    unsigned seed = rd();
    std::mt19937 r(seed);
    shuffle(vec.begin(), vec.begin() + vec.size()/2, r); //Shuffles the first half
    quickSort(vec.data(), 0, vec.size()-1, 0);
    ASSERT_EQ(vec, sorted_vec);
}

