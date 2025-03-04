#pragma once
#include <iostream>
using namespace std;

/*Function that performs insertion sort on a given array*/
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {               //iterateing through the array starting from the second element
        key = arr[i];                       //storing the current element to be compared
        j = i - 1;                          //setting j to previous element index

        while (j >= 0 && arr[j] > key) {    //checking if j is >= to 0 and if the element at that index is greater then key
            arr[j + 1] = arr[j];            //if so it shifts the element at j right one
            j = j - 1;                      //and moves j to the index of the previous element
        }
        arr[j + 1] = key;                   //places key in the correct sorted position
    }
}
