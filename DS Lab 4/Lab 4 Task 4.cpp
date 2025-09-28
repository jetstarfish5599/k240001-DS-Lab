#include <iostream>
using namespace std;

//Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Function to check duplicates
bool Duplicates(int arr[], int n) {
    bubbleSort(arr, n);
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (Duplicates(arr, n))
        cout << "Array hass duplicates" << endl;
    else
        cout << "Array doesn't have duplicates" << endl;

    return 0;
}
