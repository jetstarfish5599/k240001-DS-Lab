#include <iostream>
using namespace std;

//Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//Binary Search
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

//Insert value into sorted array
int insertSorted(int arr[], int n, int value) {
    int i;
    for (i = n - 1; (i >= 0 && arr[i] > value); i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = value;
    return n + 1;
}

//Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[20] = {2, 4, 6, 8, 3, 5, 7, 9, 1};
    int n = 9;

    cout << "Original Array: ";
    printArray(arr, n);

    insertionSort(arr, n);
    cout << "Sorted Array: ";
    printArray(arr, n);

    int rollDigits;
    cout << "Enter last two digits of roll number: ";
    cin >> rollDigits;

    int index = binarySearch(arr, n, rollDigits);

    if (index == -1) {
        cout << rollDigits << " not found, inserting..." << endl;
        n = insertSorted(arr, n, rollDigits);
        cout << "Array after insertion: ";
        printArray(arr, n);
        index = binarySearch(arr, n, rollDigits);
    }

    cout << "Value " << rollDigits << " found at  " << index << endl;

    return 0;
}

