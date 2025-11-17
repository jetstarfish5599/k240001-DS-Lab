#include <iostream>
using namespace std;

#define MAX 100

class MaxHeap {
    int arr[MAX];
    int size;

public:
    MaxHeap() { size = 0; }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }

    void insert(int val) {
        arr[size] = val;
        int i = size;
        size++;

        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int extractMax() {
        if (size <= 0) return -1;

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return root;
    }

    void heapifyDown(int i) {
        int largest = i;
        int L = left(i);
        int R = right(i);

        if (L < size && arr[L] > arr[largest]) largest = L;
        if (R < size && arr[R] > arr[largest]) largest = R;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

    int getSize() { return size; }
};

int kthLargest(int arr[], int n, int k) {
    MaxHeap H;

    for (int i = 0; i < n; i++)
        H.insert(arr[i]);

    int ans = -1;
    for (int i = 1; i <= k; i++)
        ans = H.extractMax();

    return ans;
}

int main() {
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
    int n = 7;

    cout << "term Largest k = " << kthLargest(arr, n, k) << endl;
    return 0;
}
