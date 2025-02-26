#pragma once
#include <iostream>
using namespace std;

class Heap {
private:

public:
    int* Arr;
    Heap() {
        Arr = new int[0];
    }

    void printArray(int Arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }

    //Max heap
    void modifyValMax(int Arr[], int n, int i, int val) { //Modify value 
        Arr[i] = val;
        for (i; i >= 0; i--) {
            if (Arr[i] > Arr[i / 2]) {
                swap(Arr[i], Arr[i / 2]);
                i = i / 2;
            }
        }
    }

    void insert_value_maxHeap(int Arr[], int val, int& n) { //Adds value at the end of array and calls max_heapify
        n = n + 1;
        Arr[n - 1] = val;
        int i = n - 1;
        for (i; i >= 0; i--) {
            if (Arr[i] > Arr[(i / 2)]) {
                swap(Arr[i], Arr[i / 2]);
                i = (i / 2) + 1;
            }
        }
    }

    void max_heapify(int Arr[], int i, int n) { //Maintains the max heap property
        int lNode = (2 * i) + 1;
        int rNode = (2 * i) + 2;
        int largest = i;

        if (lNode < n && Arr[lNode] > Arr[i]) {
            largest = lNode;
        }
        if (rNode < n && Arr[rNode] > Arr[largest]) {
            largest = rNode;
        }
        if (largest != i) {
            swap(Arr[i], Arr[largest]);
            max_heapify(Arr, largest, n);
        }
    }

    int extract_maximum(int Arr[], int& n) { //Return the maximum element in heap and swap last element with first element
        buildMaxHeap(Arr, n);

        int max = Arr[0];
        Arr[0] = Arr[n - 1];
        n = n - 1;
        max_heapify(Arr, 0, n);
        return max;
    }

    void ascendingHeapSort(int Arr[], int n) { //Prints the array in ascending 
        buildMaxHeap(Arr, n);

        for (int i = n - 1; i >= 0; i--) {
            swap(Arr[0], Arr[i]);
            max_heapify(Arr, 0, i);
        }
    }

    void buildMaxHeap(int Arr[], int n) { //Heapifies entire list
        int startidx = (n / 2) - 1;
        for (int i = startidx; i >= 0; i--) {
            max_heapify(Arr, i, n);
        }
    }
};
