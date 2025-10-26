#include <iostream>
using namespace std;

//merge step
void merge(int a[], int beg, int mid, int end) {
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[beg + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = beg;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

//recursive merge sort
void mergeSort(int a[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

//print arr
void printArr(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int arr1[10] = {121, 23, 45, 12, 500, 321, 67, 89, 3, 15};
    int arr2[10] = {78, 54, 23, 999, 102, 65, 8, 120, 35, 1};
    int combined[20];

    //combine arrs
    for (int i = 0; i < 10; i++) combined[i] = arr1[i];
    for (int i = 0; i < 10; i++) combined[10 + i] = arr2[i];

    cout << "Before sort:\n";
    printArr(combined, 20);

    mergeSort(combined, 0, 19);

    cout << "\nAfter Merge sort:\n";
    printArr(combined, 20);
    return 0;
}
