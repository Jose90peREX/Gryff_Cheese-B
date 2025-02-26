# CSCI-115
This is the algorithm code for the CSCI-115 Team project

Part 1 (main.cpp):
Running this code is straightfoward. First the user needs to ensure that main.cpp and all its
included header files are in the same directory or complier. Once this is done the user just needs to run 
main.cpp they will first be asked the size of the array being used for testing. Then a menu will appear asking which 
sorting algorithm the user wishs to test, the user as the options of 1 to 8. Once an algorithm is chosen the run times
for its best, average, and worst cases given the array inputted into the algorithm will be displayed. All the user needs to do from 
here is contuine testing keeping track of the times. 

*Warning:If user is using Microsoft Visual Stuidos to run this code an issue will appear when running the Quicksort algorithm
         with an array size 3000 or greater. It will cause a stack issue to occur but only for the worst case for Quicksort. 
         This can be avoid by using another compiler such as online gdb. 

Part 2 (Csci 115 Project Part 2.cpp):
This code consists of three functions with main having all the function calls so all you need to run this is the Csci 115 Project Part 2.cpp file. The way this program works is by having a list of random numbers. Each function has a different way of searching through the list to find a pair that equals our target values. In the function calls, we have set values to demonstrate an instance where a target is found and when a target is not found for each function. The three functions that were made were bruteforce, MergeSortSearch, and pair_Sum. Bruteforce checks every pair of values in the array giving it a time complexity of O(n^2). MergeSortSearch uses the Merge Sort algorithm to sort the list and then uses the two pointer search technique, two indexes named "left" and "right" are used to check pairs slowly iterating through the array if current conditions are met. This algorithm has a time complexity of O(nlogn). Lastly, pair_Sum
