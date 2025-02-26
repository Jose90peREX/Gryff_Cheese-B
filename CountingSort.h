#pragma once
#include <iostream>
using namespace std;

/*Function that performs counting sort on a given array*/
void countSort(int arr[], int size) {
    int max = arr[0];

    //finding maximum
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int* count = new int[max + 1];
    //filling count array w/ 0
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    //Mapping each element of inputArray[] as an index of countArray[] array
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    //Store the cummulative count of the count array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    int* output = new int[size];

    //Find the index of each element of the original array in count array, and place the elements in output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    //Copy the sorted elements back into the original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}