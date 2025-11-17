#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n-2)/2; i++) {
        if (arr[i] < arr[2*i+1]) return false;
        if (2*i+2 < n && arr[i] < arr[2*i+2]) return false;
    }
    return true;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int L = 2*i + 1;
    int R = 2*i + 2;

    if (L < n && arr[L] > arr[largest]) largest = L;
    if (R < n && arr[R] > arr[largest]) largest = R;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n) {
    //max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr,n,i);

    //Extract elements
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

int main() {
    int arr[] = {8,7,6,5,4};
    int n = 5;
    cout << "Array: ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;

    if(isMaxHeap(arr,n))
        cout << "It is a Max Heap" << endl;
    else
        cout << "It is not a Max Heap" << endl;
    heapSort(arr,n);
    cout << "Sorted (ascending): ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}
