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

//For Max at middle
void maxmid(int arr[], int n) {
    int maxVal = arr[n - 1];
    //shift to middle
    for (int i = n - 1; i > n / 2; i--) {
        arr[i] = arr[i - 1];
    }
//Place at miid
    arr[n / 2] = maxVal; 
}

//Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[9] = {20, 12, 15, 2, 10, 1, 13, 9, 5};
    int n = 9;

    cout << "Original Array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    maxmid(arr, n);

    cout<<"Modified Array: ";
    printArray(arr, n);

    return 0;
}
