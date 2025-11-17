#include <iostream>
using namespace std;

#define MAX 100

class MaxHeap {
    int arr[MAX];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

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

    // update_key(i,newvalue)
    void update_key(int i, int new_val) {
        if (i < 0 || i >= size) return;

        arr[i] = new_val;

        // Heapify up if increased
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }

        // Otherwise heapify down if decreased
        heapifyDown(i);
    }

    // delete a specific index
    void deleteKey(int i) {
        if (i < 0 || i >= size) return;

        arr[i] = arr[size - 1];
        size--;
        heapifyDown(i);
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap H;
    H.insert(8);
    H.insert(7);
    H.insert(6);
    H.insert(5);
    H.insert(4);
    cout << "Max Heap: ";
    H.printHeap();
    H.update_key(3, 10); //update
    cout << "After update: ";
    H.printHeap();
    H.deleteKey(1); // delete arr[1]
    cout << "After delete: ";
    H.printHeap();
}
