   #include "gtest/include/gtest/gtest.h"
   #include "BubbleSort.h"
   #include <vector>
   using namespace std;
     
  TEST(UnsortedVector, BubbleSortedTest) {

    vector<int> v = {2, 1, 5, 3, 4};
    BubbleSort(v);   
     
    vector<int> result = {1, 2, 3, 4, 5};
    BubbleSort(result);
              
    EXPECT_EQ(v, result);
  }

   int main(int argc, char **argv) {
     testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
   }
