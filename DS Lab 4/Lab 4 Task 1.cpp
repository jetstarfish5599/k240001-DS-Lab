#include <iostream>

void selectionSort(int arr[], int n, int k) {
    for (int i = 0; i < k; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    std::cout << "Enter 10 elements:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i];
    }


    const int min = 4;
    selectionSort(arr, SIZE, min);

    // Print the 4 mins
    std::cout << "\nThe 4 minimum elements are: ";
    for (int i = 0; i < min; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
