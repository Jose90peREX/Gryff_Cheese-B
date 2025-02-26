#pragma once
#include <iostream>
using namespace std;

/*Function that merges two sorted subarrays back into one*/
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;    //calculating the size of the first subarray
    int n2 = right - mid;       //calculating the size of the second subarray

    //creating two temporary subarrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    //using for loops to fill up each temporary subarray
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int indL = 0;   //initial index for the first subarray
    int indR = 0;   //initial index for the first subarray

    //using a for loop to sort and merge the two subarrays back into the given array
    for (int k = left; k <= right; k++) {
        if (indL < n1 && indR < n2) {               //checks to see if either of the subarrays have been fully iterated through
            if (leftArr[indL] <= rightArr[indR]) {  //if not sorts the values back into the orignial array
                arr[k] = leftArr[indL];
                indL++;
            }
            else {
                arr[k] = rightArr[indR];
                indR++;
            }
        }
        else if (indL < n1) {                        //fills the orignial array with the remaining elements in the left subarray
            arr[k] = leftArr[indL];
            indL++;
        }
        else {                                       //fills the orignial array with the remaining elements in the right subarray
            arr[k] = rightArr[indR];
            indR++;
        }
    }

}

/*Function that performs mergesort on a given array*/
void mergeSort(int arr[], int left, int right) {
    if (left < right) {                     //checks thats the given array is not empty
        int mid = (left + right) / 2;       //finding the mid point of the array
        mergeSort(arr, left, mid);          //recursively calling itself for the first half of the array
        mergeSort(arr, mid + 1, right);     //recursively calling itself for the second hald of the array
        merge(arr, left, mid, right);       //calling the merge function
    }
}
