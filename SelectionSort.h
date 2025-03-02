#pragma once
#include <iostream>
using namespace std;

/*Function that performs selecting sort on a given array*/
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {        //for loop to iterate through the array
        int min = i;                            //sets min variable to current element index
        for (int j = i + 1; j < size; j++) {    //for loop to itetated through the remaining array
            if (arr[j] < arr[min]) {            //compares current min element with remaining array elements to find the smallest element index
                min = j;
            }
        }
        int temp = 0;
        if (min != i) {                         //if the current element index was found not to hold the smallest element then it swaps its element with the smallest element found
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}