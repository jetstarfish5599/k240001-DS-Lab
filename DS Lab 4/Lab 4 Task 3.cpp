#include <iostream>
#include <string>
using namespace std;

//Function Bubble Sort
void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                //Swap
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    //array
    string arr[] = {"banana", "apple", "cherry", "date","pineapple", "grape"};
    int n = sizeof(arr) / sizeof(arr[0]);

    //function call
    bubbleSort(arr, n);

    //display the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
