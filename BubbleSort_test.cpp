   #include "gtest/include/gtest/gtest.h"
   #include "BubbleSort.h"
   #include <vector>
   using namespace std;
     

  

  TEST(UnsortedVector, BubbleSortedTest) {
    vector<int> v = {2, 1, 5, 3, 4};
    vector<int> expected = {1, 2, 3, 4, 5};
    BubbleSort(v.data(), v.size());
    ASSERT_EQ(v, expected);
  }


