// quick sort project edition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

void swapQ(int* a, int* b) // function used to swap
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) // function used in quick sort to use the swap function
{
    int pivot = arr[high]; // pivot, choosing the last element
    int pindex = (low - 1); // partition index
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            pindex++;
            swapQ(&arr[pindex], &arr[j]);
        }
    }
    swapQ(&arr[pindex + 1], &arr[high]);
    return (pindex + 1);
}

/*Function used to choose a random values as the pivot for quciksort*/
int partition_Rand(int arr[], int low, int high) {
    //srand(time(0));
    int random = low + rand() % (high - low);
    swapQ(&arr[high], &arr[random]);
    return partition(arr, low, high);
}

/*Function used to find the median value of the array and choose it as the pivot*/
int partition_Median(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) {
        swapQ(&arr[low], &arr[mid]);
    }
    if (arr[mid] > arr[high]) {
        swapQ(&arr[mid], &arr[high]);
    }
    if (arr[low] > arr[mid]) {
        swapQ(&arr[low], &arr[mid]);
    }
    swapQ(&arr[high], &arr[mid]);
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high, int choice) // actual quicksort function which combines all the other quicksort functions
{
    int pindex = 0;
    if (low < high)
    {
        if (choice == 1) {
            pindex = partition(arr, low, high);
        }
        else if (choice == 2) {
            pindex = partition_Rand(arr, low, high);
        }
        else {
            pindex = partition_Median(arr, low, high);
        }

        quickSort(arr, low, pindex - 1, choice);
        quickSort(arr, pindex + 1, high, choice);
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
