#include <cstdio>
#include <vector>
#include <numeric>
#include <random>
#include <chrono>
#include "quickSort.h"
#include "SelectionSort.h"
#include <algorithm>
using namespace std;
using namespace chrono;

//Benchmarking:
template <typename T>
void RunTimedTest(const string& test_name, T&& function) {
    auto start = high_resolution_clock::now();
    function();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end-start);
    cout << "[TIME] " << test_name << ": " << duration.count() << "\n";
}

int main() {
    vector<int> testVec(10000);
    iota(testVec.begin(), testVec.end(), 1);

    std::random_device rd;
    std::mt19937 r(rd());

    RunTimedTest("Selection Sort", [&]() {
        vector<int> copyTest = testVec;
        shuffle(copyTest.begin(), copyTest.end(), r);
        selectionSort(copyTest.data(), testVec.size()-1);
    });

    return 0;
}
