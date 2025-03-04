#include "gtest/include/gtest/gtest.h"
#include "quickSort.h"
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>
using namespace std;

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



