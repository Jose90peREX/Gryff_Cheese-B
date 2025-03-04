#include "gtest/include/gtest/gtest.h"

#include <vector>
#include "RadixSort.h"

TEST(RadixSort, UnsortedVector) {
    std::vector<int> unsorted = {2, 1, 5, 3, 4};
    std::vector<int> sorted = {1, 2, 3, 4, 5};
    
    radixSort(unsorted.data(), unsorted.size());

    ASSERT_EQ(unsorted, sorted);
}
