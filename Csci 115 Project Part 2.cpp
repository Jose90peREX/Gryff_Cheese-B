// Csci 115 Project Part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
using namespace std;

// Define the array 'S' to search for pairs that add up to 'x'.
const int n = 10;
int S[n] = {3,5,2,8,4,0,3,7,6,1};

// The bruteForce function searches for two elements in the array that add up to val.
bool bruteForce(int arr[], int val) {
    // Calculate the size of the array passed in.
    int x = val;
    cout << "Searching for pair that sums to " << x << " in list..." << endl;
    // Iterate over the array with two pointers, i and j.
    // Loop from the first element to the second to last
    for (int i = 0; i < n - 2; i++) {
        // Start j from the element after i and loop to the last element
        for (int j = i + 1; j < n - 1; j++) {
            // Check if the current pair adds up to the target value 'val'
            if (arr[i] + arr[j] == val) {
                // If a pair is found, print the pair and return true
                cout << "Pair found " << "(" << arr[i] << ", " << arr[j] << ")" << " -> x " << "(" << x << ")" << endl;
                return true;
            }
        }
    }
    // If no pair adds up to 'val', print "Pair not found" and return false.
    cout << "Pair not found" << endl;
    return false;
}

// Function to merge two halves of an array
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    // Number of elements in the first half
    int temp1 = middle - left + 1;
    // Number of elements in the second half
    int temp2 = right - middle;

    // Dynamically allocate temporary arrays for the two halves
    int* Left = new int[temp1];
    int* Right = new int[temp2];

    // Copy data to temporary arrays from the main array
    for (i = 0; i < temp1; i++)
        Left[i] = arr[left + i];
    for (j = 0; j < temp2; j++)
        Right[j] = arr[middle + 1 + j];

    // Initial index of the first subarray, second subarray and the start point in the merged array
    i = 0;
    j = 0;
    k = left;
    // Merge the temp arrays back into array
    while (i < temp1 && j < temp2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    // Copy the any remaining elements of Left[]
    while (i < temp1) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    // Copy the any remaining elements of Right[]
    while (j < temp2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

//Function to sort an array using mergeSort 
void mergeSort(int arr[], int left, int right) {
    // Calculate middle of the array
    if (left < right) {
        int middleIdx = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middleIdx);
        mergeSort(arr, middleIdx + 1, right);

        // Merge the sorted halves
        merge(arr, left, middleIdx, right);
    }
}
// Function to search for two elements in the array to find their sum is equal to x after using merge and mergeSort
bool MergeSortSearch(int arr[], int n, int x) {
    cout << "Searching for pair that sums to " << x << " in list..." << endl;
    //Sorts the array first
    mergeSort(arr, 0, n - 1);

    // Start pointer for the leftmost and rightmost element
    int left = 0;
    int right = n - 1;

    // Check if there is a pair with a given sum
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == x) {
            cout << "Pair found " << "(" << arr[left] << ", " << arr[right] << ")" << " -> x " << "(" << x << ")" << endl;
            return true;
        }
        // Move left pointer to the right to increase sum
        else if (sum < x) {
            left++;
        }
        // Move left pointer to the right to decrease sum
        else {
            right--;
        }
    }
    cout << "Pair not found" << endl;
    return false;
}

// Function to check if there exists a pair of elements in the array that sums to 'x'
bool pair_Sum(int arr[], int n, int x) {
    unordered_set<int> seen;
    cout << "Searching for pair that sums to " << x << " in list..." << endl;
    // Iterate over each element of the array
    for (int i = 0; i < n; ++i) {
        // Check if the complement of the current element (x - arr[i]) has already been seen
        if (seen.find(x - arr[i]) != seen.end()) {
            // If the complement is found, it means we have found a pair that sums to 'x' and returns true
            cout << "Pair found " << "(" << x-arr[i] << ", " << arr[i] << ")" << " -> x " << "(" << x << ")" << endl;
            return true;
        }
        // If the complement is not found the it gets added the current element to the set of seen elements
        seen.insert(arr[i]);
    }
    cout << "Pair not found" << endl;
    return false;
}

int main()
{

    cout << "List : 3, 5, 2, 8, 4, 0, 3, 7, 6, 1" << endl << endl;

    cout << "BruteForce (O(n^2)): " << endl;
    //Bruteforce when a pair that sums up to 'x' (12) is found 
    bruteForce(S, 12);
    //BruteForce when a pair that sums up to 'x' (17) is not found
    bruteForce(S, 17);

    cout << endl << endl;
    
    cout << "MergeSortSearch (O(nlogn)): " << endl;
    //MergeSortSearch when a pair that sums up to 'x' (12) is found
    MergeSortSearch(S, n, 12);
    //MergeSortSearch when a pair that sums up to 'x' (12) is not found
    MergeSortSearch(S, n, 17);

    cout << endl << endl;

    cout << "QuickSum (O(n)): " << endl;
    //QuickSum when a pair that sums up to 'x' (12) is found
    pair_Sum(S, n, 12);
    //QuickSum when a pair that sums up to 'x' (17) is not found
    pair_Sum(S, n, 17);
}
