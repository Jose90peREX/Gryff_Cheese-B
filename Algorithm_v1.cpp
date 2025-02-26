#include <iostream>
using namespace std;

/*Funtion that finds the pairs in an array whomse sum is x*/
bool pair_Found(int arr[], int size, int x) {
    int num1 = 0;
    int num2 = 1;
    int found = 0;

    //nested loops that iterate through the array checking each pair of elements
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < (size - 1); j++) {
            if (arr[i] + arr[j] == x) {
                found = found + 1;
            }
        }

    }

    //if at least one pair was found then true is return else false
    if (found > 0) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = 10;
    int x; 
    bool found = false;

    cout << "Enter a value for x to find addends for." << endl;
    cin >> x;

    found = pair_Found(arr, size, x);

    if (found == true) {
        cout << "A pair that adds up to " << x << " was found." << endl;
    }
    else {
        cout << "A pair that adds up to " << x << " was not found." << endl;
    }
    return 0;
}

