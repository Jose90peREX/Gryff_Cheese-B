#pragma once

#include <iostream>
using namespace std;

/*Function that performs counting sort on a given array but for each decimal place of the given elements*/
void radix_count(int* arr, int size, int decP) {
    int count[10] = { 0 };                  //creating a temporary array of size 10

    for (int i = 0; i < size; i++) {        //count the frequency of each value in the given decimal place 
        count[(arr[i] / decP) % 10]++;      //put these value into their respective indexes in the count array
    }

    for (int i = 1; i < 10; i++) {          //Store the cummulative count of the count array
        count[i] += count[i - 1];
    }

    int* output = new int[size];            //creating a temporary output array to hold the sorted values
    for (int i = size - 1; i >= 0; i--) {   //Find the index of each element of the original array in count array, and place the elements in output array
        output[count[(arr[i] / decP) % 10] - 1] = arr[i];
        count[(arr[i] / decP) % 10]--;
    }

    for (int i = 0; i < size; i++) {        //Copy the sorted elements back into the original array                                                      
        arr[i] = output[i];
    }
}

/*Function that performs radixsort on a given array*/
void radixSort(int* arr, int size) {
    int max = arr[0];

    //finding maximum
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    //using a for loop to call the radix's counting sort method to sort the array for each decimal place of its elements
    for (int decP = 1; (max / decP) > 0; decP *= 10) {
        radix_count(arr, size, decP);
    }
}
