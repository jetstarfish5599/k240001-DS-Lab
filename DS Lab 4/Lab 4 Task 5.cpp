#include <iostream>
using namespace std;

void sortBirthYears(int arr[], int n) {
    int count2022 = 0, count2023 = 0, count2024 = 0;

    //for each year
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2022) count2022++;
        else if (arr[i] == 2023) count2023++;
        else if (arr[i] == 2024) count2024++;
    }

    //New array
    int index = 0;
    while (count2022--) arr[index++] = 2022;
    while (count2023--) arr[index++] = 2023;
    while (count2024--) arr[index++] = 2024;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2022, 2023, 2024, 2022, 2023, 2024};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    sortBirthYears(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
