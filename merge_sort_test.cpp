#include "gtest/include/gtest/gtest.h"

#include <vector>
#include "MergeSort.h"

TEST(MergeSort, UnsortedVector) {
    std::vector<int> unsorted = {2, 1, 5, 3, 4};
    std::vector<int> sorted = {1, 2, 3, 4, 5};
    
    mergeSort(unsorted.data(), 0, unsorted.size() - 1);

    ASSERT_EQ(unsorted, sorted);
}
