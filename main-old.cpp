#include <iostream>
#include "Insertion Sort.h"
#include "Selection Sort.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include "quickSort.h"
#include "HeapSort.h"
#include "CountingSort.h"
#include "RadixSort.h"
#include <chrono>
#include <cstdlib>
using namespace std;

/*Function fills three arrays with elements that are unsorted, sorted, and half sorted*/
void filling_Arrays(int sorted[], int unsorted[], int half[], int size) {
    int value = 1;                              //initialize value variable to 1 
    for (int i = 0; i < size; ++i) {            //using a for loop to iterate through the first array and filling it with increasing values form 1 to array size 
        sorted[i] = value;
        value++;
    }

    value = value - 1;                          //subtracting 1 from value so that it equals size of the array
    for (int j = 0; j < size; ++j) {            //using a for loop to iterate through the second array and filling it with decreasing values form array size to 1 
        unsorted[j] = value;
        value--;
    }

    value = value + 1;                          //adding 1 to value so that it equals 1 (resetting value)
    for (int k = 0; k < (size / 2); ++k) {      //using a for loop to iterate through the thrid array and filling half of it with increasing values form 1 to (array size / 2) 
        half[k] = value;
        value++;
    }

    value = (value - 1) * 2;                    //resetting value so that it equals size of the array
    for (int k = (size / 2); k < size; ++k) {   //using a for loop to iterate through the thrid array and filling remaining half with decreasing values form array size to (array size / 2) + 1 
        half[k] = value;
        value--;
    }
}

/*Function that fills an array with random numbers*/
void array_Rand(int arr[], int size) {
    //srand(time(0));
    for (int i = 0; i < size; i++) {            //using a for loop to iterate through an array and fill it with random values ranging from 0 to array size
        arr[i] = rand() % size+1;
    }
}

/*Fuction that fills three arrays with values to cause the worst, average, and best cases for counting sort*/
void count_arr(int count_best[], int count_avg[], int count_worst[], int size) {
    //srand(time(0));
    for (int i = 0; i < size; i++) {
        count_worst[i] = (rand() % (size * 10) + 1); // large range of values
    }

    //srand(time(0));
    for (int j = 0; j < size; j++) {
        count_best[j] = rand() % size + 1; // small range of values
    }

    //srand(time(0));
    for (int k = 0; k < size; k++) {
        count_avg[k] = (rand() % (size * 5) + 1); // moderate range of values
    }
}

/*Fuction that fills three arrays with values to cause the worst, average, and best cases for radix sort*/
void radix_arr(int radix_best[], int radix_avg[], int radix_worst[], int size) {
    int value = 0;
    for (int i = 0; i < size; i++) {            //using a for loop to iterate through the first array and filling it with increasing values form 1 to array size 
        radix_best[i] = value;
        value++;
    }

    //srand(time(0));
    for (int j = 0; j < size; j++) {
        radix_avg[j] = rand() % 100000;         //Generate random numbers up to 99999
    }

    for (int k = 0; k < size; k++) {
        radix_worst[k] = 100000;                //fills an array with the value 100000
    }
}


/*Function to print out a given array*/
void print_Arr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {            //using a for loop to iterate through an array and print out its elements
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 0;                               //setting a variable for the size of the array
    int option = -1;                            //setting a variable for the user's option in the given menu 
    Heap test;                                  //declaring object of the heap class

    //asking the user for the size of the array being tested
    cout << "Enter the size of the array being tested?" << endl;
    cin >> size;
    while (size < 0) {
        cout << "Invalid Input! Try Again." << endl;
        cin >> size;
    }

    int left = 0;                               //declaring a variable for that holds the left most index of the array
    int right = size - 1;                       //declaring a variable for that holds the right most index of the array


    int* sorted_Arr = new int[size];                                //delcaring dynamic array for a sorted array
    int* half_Arr = new int[size];                                  //delcaring dynamic array for a half sorted array
    int* unsorted_Arr = new int[size];                              //delcaring dynamic array for a unsorted array
    int* rand_Arr = new int[size];
    int* count_best = new int[size];
    int* count_avg = new int[size];
    int* count_worst = new int[size];
    int* radix_best = new int[size];
    int* radix_avg = new int[size];
    int* radix_worst = new int[size];

    
    /*
    filling_Arrays(sorted_Arr, unsorted_Arr, half_Arr, size);
    int right2 = sizeof(sorted_Arr) / sizeof(sorted_Arr[0]);        //calculating the right most index of the sorted array
    int right3 = sizeof(unsorted_Arr) / sizeof(unsorted_Arr[0]);    //calculating the right most index of the unsorted array
    int right4 = sizeof(half_Arr) / sizeof(half_Arr[0]);            //calculating the right most index of the half sorted array
    */

    //menu for user to choose what sorting function to test
    cout << "\n--------Test--------\n";
    cout << "1: Insertion Sort" << endl;
    cout << "2: Selection Sort" << endl;
    cout << "3: Bubble Sort" << endl;
    cout << "4: Merge Sort" << endl;
    cout << "5: QuickSort" << endl;
    cout << "6: HeapSort" << endl;
    cout << "7: Counting Sort" << endl;
    cout << "8: Radix Sort" << endl;
    cin >> option;
    while ((option < 1) || (option > 8)) {
        cout << "Invalid Input! Try Again." << endl;
        cin >> option;
    }

    //using if and else if statments to test the choosen sorting function
    if (option == 1) {
        cout << "Testing Insertion Sort." << endl;
        filling_Arrays(sorted_Arr, unsorted_Arr, half_Arr, size);
        array_Rand(rand_Arr, size);
        //print_Arr(rand_Arr, size);

        auto start1 = chrono::steady_clock::now();                                  //starting to record function execution time for sorted array
        insertionSort(sorted_Arr, size);
        auto stop1 = chrono::steady_clock::now();                                   //stoping the recording 
        auto time1 = chrono::duration_cast<chrono::nanoseconds>(stop1 - start1);    //calculating the execution time
        cout << "Time taken (best): " << time1.count() << " nanoseconds" << endl;

        auto start2 = chrono::steady_clock::now();                                  //starting to record function execution time for half sorted array
        insertionSort(rand_Arr, size);
        auto stop2 = chrono::steady_clock::now();                                   //stoping the recording
        auto time2 = chrono::duration_cast<chrono::nanoseconds>(stop2 - start2);    //calculating the execution time
        cout << "Time taken (average): " << time2.count() << " nanoseconds" << endl;

        auto start3 = chrono::steady_clock::now();                                  //starting to record function execution time for unsorted array
        insertionSort(unsorted_Arr, size);
        auto stop3 = chrono::steady_clock::now();                                   //stoping the recording
        auto time3 = chrono::duration_cast<chrono::nanoseconds>(stop3 - start3);    //calculating the execution time
        cout << "Time taken (worst): " << time3.count() << " nanoseconds" << endl;
    }
    else if (option == 2) {
        cout << "Testing Selection Sort." << endl;
        filling_Arrays(sorted_Arr, unsorted_Arr, half_Arr, size);
        array_Rand(rand_Arr, size);
        //print_Arr(rand_Arr, size);

        auto start4 = chrono::steady_clock::now();                                  //starting to record function execution time for sorted array
        selectionSort(sorted_Arr, size);
        auto stop4 = chrono::steady_clock::now();                                   //stoping the recording
        auto time4 = chrono::duration_cast<chrono::nanoseconds>(stop4 - start4);    //calculating the execution time
        cout << "Time taken (best): " << time4.count() << " nanoseconds" << endl;

        auto start5 = chrono::steady_clock::now();                                  //starting to record function execution time for half sorted array
        selectionSort(rand_Arr, size);
        auto stop5 = chrono::steady_clock::now();                                   //stoping the recording
        auto time5 = chrono::duration_cast<chrono::nanoseconds>(stop5 - start5);    //calculating the execution time
        cout << "Time taken (average): " << time5.count() << " nanoseconds" << endl;

        auto start6 = chrono::steady_clock::now();                                  //starting to record function execution time for unsorted array
        selectionSort(unsorted_Arr, size);
        auto stop6 = chrono::steady_clock::now();                                   //stoping the recording
        auto time6 = chrono::duration_cast<chrono::nanoseconds>(stop6 - start6);    //calculating the execution time
        cout << "Time taken (worst): " << time6.count() << " nanoseconds" << endl;
    }
    else if (option == 3) {
        cout << "Testing Bubble Sort." << endl;
        filling_Arrays(sorted_Arr, unsorted_Arr, half_Arr, size);
        array_Rand(rand_Arr, size);
        //print_Arr(rand_Arr, size);

        auto start7 = chrono::steady_clock::now();                                  //starting to record function execution time for sorted array
        BubbleSort(sorted_Arr, size);
        auto stop7 = chrono::steady_clock::now();                                   //stoping the recording
        auto time7 = chrono::duration_cast<chrono::nanoseconds>(stop7 - start7);    //calculating the execution time
        cout << "Time taken (best): " << time7.count() << " nanoseconds" << endl;

        auto start8 = chrono::steady_clock::now();                                  //starting to record function execution time for half sorted array
        BubbleSort(rand_Arr, size);
        auto stop8 = chrono::steady_clock::now();                                   //stoping the recording
        auto time8 = chrono::duration_cast<chrono::nanoseconds>(stop8 - start8);    //calculating the execution time
        cout << "Time taken (average): " << time8.count() << " nanoseconds" << endl;

        auto start9 = chrono::steady_clock::now();                                  //starting to record function execution time for unsorted array
        BubbleSort(unsorted_Arr, size);
        auto stop9 = chrono::steady_clock::now();                                   //stoping the recording
        auto time9 = chrono::duration_cast<chrono::nanoseconds>(stop9 - start9);    //calculating the execution time
        cout << "Time taken (worst): " << time9.count() << " nanoseconds" << endl;
    }
    else if (option == 4) {
        cout << "Testing Merge Sort." << endl;
        filling_Arrays(sorted_Arr, unsorted_Arr, half_Arr, size);
        array_Rand(rand_Arr, size);
        //print_Arr(rand_Arr, size);

        auto start10 = chrono::steady_clock::now();                                  //starting to record function execution time for sorted array
        mergeSort(sorted_Arr, left, right);
        auto stop10 = chrono::steady_clock::now();                                   //stoping the recording
        auto time10 = chrono::duration_cast<chrono::nanoseconds>(stop10 - start10);  //calculating the execution time
        cout << "Time taken (best): " << time10.count() << " nanoseconds" << endl;

        auto start11 = chrono::steady_clock::now();                                  //starting to record function execution time for half sorted array
        mergeSort(rand_Arr, left, right);
        auto stop11 = chrono::steady_clock::now();                                   //stoping the recording
        auto time11 = chrono::duration_cast<chrono::nanoseconds>(stop11 - start11);  //calculating the execution time
        cout << "Time taken (average): " << time11.count() << " nanoseconds" << endl;

        auto start12 = chrono::steady_clock::now();                                  //starting to record function execution time for unsorted array
        mergeSort(unsorted_Arr, left, right);
        auto stop12 = chrono::steady_clock::now();                                   //stoping the recording
        auto time12 = chrono::duration_cast<chrono::nanoseconds>(stop12 - start12);  //calculating the execution time
        cout << "Time taken (worst): " << time12.count() << " nanoseconds" << endl;
    }
    else if (option == 5) {
        cout << "Testing QuickSort." << endl;
        filling_Arrays(sorted_Arr, unsorted_Arr, half_Arr, size);
        array_Rand(rand_Arr, size);
        //print_Arr(rand_Arr, size);

        auto start13 = chrono::steady_clock::now();                                  //starting to record function execution time for sorted array
        quickSort(sorted_Arr, left, right, 3);
        auto stop13 = chrono::steady_clock::now();                                   //stoping the recording
        auto time13 = chrono::duration_cast<chrono::nanoseconds>(stop13 - start13);  //calculating the execution time
        cout << "Time taken (best): " << time13.count() << " nanoseconds" << endl;

        auto start14 = chrono::steady_clock::now();                                  //starting to record function execution time for half sorted array
        quickSort(rand_Arr, left, right, 2);
        auto stop14 = chrono::steady_clock::now();                                   //stoping the recording
        auto time14 = chrono::duration_cast<chrono::nanoseconds>(stop14 - start14);  //calculating the execution time
        cout << "Time taken (average): " << time14.count() << " nanoseconds" << endl;

        auto start15 = chrono::steady_clock::now();                                  //starting to record function execution time for unsorted array
        quickSort(unsorted_Arr, left, right, 1);
        auto stop15 = chrono::steady_clock::now();                                   //stoping the recording
        auto time15 = chrono::duration_cast<chrono::nanoseconds>(stop15 - start15);  //calculating the execution time
        cout << "Time taken (worst): " << time15.count() << " nanoseconds" << endl;
    }
    else if (option == 6) {
        cout << "Testing HeapSort." << endl;
        filling_Arrays(sorted_Arr, unsorted_Arr, half_Arr, size);
        array_Rand(rand_Arr, size);
        //print_Arr(rand_Arr, size);

        auto start16 = chrono::steady_clock::now();                                  //starting to record function execution time for sorted array
        test.ascendingHeapSort(sorted_Arr, size);
        auto stop16 = chrono::steady_clock::now();                                   //stoping the recording
        auto time16 = chrono::duration_cast<chrono::nanoseconds>(stop16 - start16);  //calculating the execution time
        cout << "Time taken (best): " << time16.count() << " nanoseconds" << endl;

        auto start17 = chrono::steady_clock::now();                                  //starting to record function execution time for half sorted array
        test.ascendingHeapSort(rand_Arr, size);
        auto stop17 = chrono::steady_clock::now();                                   //stoping the recording
        auto time17 = chrono::duration_cast<chrono::nanoseconds>(stop17 - start17);  //calculating the execution time
        cout << "Time taken (average): " << time17.count() << " nanoseconds" << endl;

        auto start18 = chrono::steady_clock::now();                                  //starting to record function execution time for unsorted array
        test.ascendingHeapSort(unsorted_Arr, size);
        auto stop18 = chrono::steady_clock::now();                                   //stoping the recording
        auto time18 = chrono::duration_cast<chrono::nanoseconds>(stop18 - start18);  //calculating the execution time
        cout << "Time taken (worst): " << time18.count() << " nanoseconds" << endl;
    }
    else if (option == 7) {
        cout << "Testing Counting Sort." << endl;
        count_arr(count_best, count_avg, count_worst, size);
        
        /*
        print_Arr(count_best, size);
        print_Arr(count_avg, size);
        print_Arr(count_worst, size);
        */

        auto start19 = chrono::steady_clock::now();                                  //starting to record function execution time for sorted array
        countSort(count_best, size);
        auto stop19 = chrono::steady_clock::now();                                   //stoping the recording
        auto time19 = chrono::duration_cast<chrono::nanoseconds>(stop19 - start19);  //calculating the execution time
        cout << "Time taken (best): " << time19.count() << " nanoseconds" << endl;

        auto start20 = chrono::steady_clock::now();                                  //starting to record function execution time for half sorted array
        countSort(count_avg, size);
        auto stop20 = chrono::steady_clock::now();                                   //stoping the recording
        auto time20 = chrono::duration_cast<chrono::nanoseconds>(stop20 - start20);  //calculating the execution time
        cout << "Time taken (average): " << time20.count() << " nanoseconds" << endl;

        auto start21 = chrono::steady_clock::now();                                  //starting to record function execution time for unsorted array
        countSort(count_worst, size);
        auto stop21 = chrono::steady_clock::now();                                   //stoping the recording
        auto time21 = chrono::duration_cast<chrono::nanoseconds>(stop21 - start21);  //calculating the execution time
        cout << "Time taken (worst): " << time21.count() << " nanoseconds" << endl;
    }
    else if (option == 8) {
        cout << "Testing Radix Sort." << endl;
        radix_arr(radix_best, radix_avg, radix_worst, size);

        /*
        print_Arr(radix_best, size);
        print_Arr(radix_avg, size);
        print_Arr(radix_worst, size);
        */

        auto start22 = chrono::steady_clock::now();                                  //starting to record function execution time for sorted array
        radixSort(radix_best, size);
        auto stop22 = chrono::steady_clock::now();                                   //stoping the recording
        auto time22 = chrono::duration_cast<chrono::nanoseconds>(stop22 - start22);  //calculating the execution time
        cout << "Time taken (best): " << time22.count() << " nanoseconds" << endl;

        auto start23 = chrono::steady_clock::now();                                  //starting to record function execution time for half sorted array
        radixSort(radix_avg, size);
        auto stop23 = chrono::steady_clock::now();                                   //stoping the recording
        auto time23 = chrono::duration_cast<chrono::nanoseconds>(stop23 - start23);  //calculating the execution time
        cout << "Time taken (average): " << time23.count() << " nanoseconds" << endl;

        auto start24 = chrono::steady_clock::now();                                  //starting to record function execution time for unsorted array
        radixSort(radix_worst, size);
        auto stop24 = chrono::steady_clock::now();                                   //stoping the recording
        auto time24 = chrono::duration_cast<chrono::nanoseconds>(stop24 - start24);  //calculating the execution time
        cout << "Time taken (worst): " << time24.count() << " nanoseconds" << endl;
    }
   
    /*
    print_Arr(sorted_Arr, size);
    print_Arr(rand_Arr, size);
    print_Arr(unsorted_Arr, size);
    */

    /*
    print_Arr(count_best, size);
    print_Arr(count_avg, size);
    print_Arr(count_worst, size);
    */

    /*
    print_Arr(radix_best, size);
    print_Arr(radix_avg, size);
    print_Arr(radix_worst, size);
    */

    return 0;
}
