#pragma once
#include <iostream>
using namespace std;


void BubbleSort(int* arr, int n) {
    int i;
    int j;
    int temp;
    //loops from the beginning of the vector to the second to last element
    for (i = 0; i < n - 1; ++i) {
        //loop iterates from the beginning to the element i positions from the end of the vector.
        for (j = 0; j < n - i - 1; ++j) {
            //swaps elements if the current element is greater than the next
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }


}
