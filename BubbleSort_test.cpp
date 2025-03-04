   #include "gtest/include/gtest/gtest.h"
   #include "BubbleSort.h"
   #include <vector>
   using namespace std; 

  TEST(BubbleSortedTest, UnsortedVector) {
    vector<int> v = {2, 1, 5, 3, 4};
    vector<int> expected = {1, 2, 3, 4, 5};
    BubbleSort(v.data(), v.size());
    ASSERT_EQ(v, expected);
  }
  
  TEST(BubbleSortedTest, NegativeVector) {
	 vector<int> v = {-2, -1, -5, -3, -4}; 
	 vector<int> expected = {-5, -4, -3, -2, -1};
	 BubbleSort(v.data(), v.size());
	 ASSERT_EQ(v, expected);
  }
 
  TEST(BubbleSortedTest, MixedVector) {
	  vector<int> v = {2, -1, 5, -3, 4};
	  vector<int> expected = {-3, -1, 2, 4, 5};
	  BubbleSort(v.data(), v.size());
	  ASSERT_EQ(v, expected);
  }
  
  TEST(BubbleSortedTest, LargeNumbersVector) {
	  vector<int> v = {200, 100, 500, 300, 400};
	  vector<int> expected = {100, 200, 300, 400, 500};
	  BubbleSort(v.data(), v.size());
	  ASSERT_EQ(v, expected);
  }

  TEST(BubbleSortedTest, RepeatingNumbersVector) {
	  vector<int> v = {1, 2, 1, 2, 3};
	  vector<int> expected = {1, 1, 2, 2, 3};
	  BubbleSort(v.data(), v.size());
	  ASSERT_EQ(v, expected);
  }
 
  TEST(BubbleSortedTest, LargerSizeVector) {
	  vector<int> v = {10, 4, 6, 8, 3, 9, 2, 5, 1, 7};
	  vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	  BubbleSort(v.data(), v.size());
	  ASSERT_EQ(v, expected);
  }
