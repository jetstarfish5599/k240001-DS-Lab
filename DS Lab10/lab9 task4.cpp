#include <iostream>
#include <algorithm>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    if (L < n && arr[L] > arr[largest]) largest = L;
    if (R < n && arr[R] > arr[largest]) largest = R;

    if (largest != i) {
        swap(arr[i], arr[largest]);   //swap
        maxHeapify(arr, n, largest);
    }
}

void convertMinToMax(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "min heap: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    convertMinToMax(arr, n);

    cout << "Converted max heap: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
