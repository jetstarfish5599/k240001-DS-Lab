#include <iostream>
using namespace std;

//get max val
int getMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

//count sort
void countSort(int a[], int n, int place) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / place) % 10] - 1] = a[i];
        count[(a[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

//radix sort
void radixSort(int a[], int n) {
    int max = getMax(a, n);
    for (int place = 1; max / place > 0; place *= 10)
        countSort(a, n, place);
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

    radixSort(combined, 20);

    cout << "\nAfter Radix sort:\n";
    printArr(combined, 20);
    return 0;
}
