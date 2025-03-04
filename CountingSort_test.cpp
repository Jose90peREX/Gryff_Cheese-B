#include "gtest/include/gtest/gtest.h" 
#include "CountingSort.h"
#include <vector> 
using namespace std;

TEST(CountingSortedTest, IdenticalNumbersVector) {
	vector<int> v = {1, 1, 1, 1};
	vector<int> expected = {1, 1, 1, 1};
	countSort(v.data(), v.size());
	ASSERT_EQ(v, expected);
 }

TEST(CountingSortedTest, SmallRangeVector) {
	vector<int> v = {1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 3, 3, 1};
	vector<int> expected = {1, 1, 1, 1, 1, 2, 2, 2, 3, 3 ,3, 3, 3, 3};
	countSort(v.data(), v.size());
	ASSERT_EQ(v, expected);
 }

TEST(CountingSortedTest, LargeRangeVector) {
	vector<int> v = {2, 3, 54, 32, 13, 213, 1, 233};
	vector<int> expected = {1, 2, 3, 13, 32, 54, 213, 233};
    countSort(v.data(), v.size());
	ASSERT_EQ(v, expected);
 }

TEST(CountingSortedTest, OneNumberVector) {
    vector<int> v = {3};
    vector<int> expected = {3};
    countSort(v.data(), v.size());
	ASSERT_EQ(v, expected);
 }
TEST(CountingSortedTest, EmptyVector) {
	vector<int> v = {};
	vector<int> expected = {};
	countSort(v.data(), v.size());
	ASSERT_EQ(v, expected);
 }
