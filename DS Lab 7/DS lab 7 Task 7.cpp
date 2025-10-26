#include <iostream>
using namespace std;

int comparisons = 0;

//swap two elements
void swapValues(int &a, int &b) {
int temp = a;
a = b;
b = temp;
}

//partition function
int partition(int a[], int start, int end, int pivotIndex) {
int pivot = a[pivotIndex];
swapValues(a[pivotIndex], a[end]); //to end
int i = start - 1;

for (int j = start; j < end; j++) {
comparisons++;
if (a[j] <= pivot) {
i++;
swapValues(a[i], a[j]);
}
}
swapValues(a[i + 1], a[end]); //pivot to req place
return i + 1;
}

//quick sort function
void quickSort(int a[], int start, int end, int pivotType) {
if (start < end) {
int pivotIndex;

//select pivot type
if (pivotType == 1) //first element
pivotIndex = start;
else if (pivotType == 2) //mid element
pivotIndex = (start + end) / 2;
else if (pivotType == 3) { //median of three
int mid = (start + end) / 2;
int x = a[start], y = a[mid], z = a[end];
if ((x > y && x < z) || (x < y && x > z))
pivotIndex = start;
else if ((y > x && y < z) || (y < x && y > z))
pivotIndex = mid;
else
pivotIndex = end;
}
else //last element
pivotIndex = end;

int p = partition(a, start, end, pivotIndex);
quickSort(a, start, p - 1, pivotType);
quickSort(a, p + 1, end, pivotType);
}
}

//print array
void printArray(int a[], int n) {
for (int i = 0; i < n; i++)
cout << a[i] << " ";
cout << endl;
}

//copy array
void copyArray(int src[], int dest[], int n) {
for (int i = 0; i < n; i++)
dest[i] = src[i];
}

int main() {
int original[] = {10, 7, 8, 9, 1, 5, 3};
int n = sizeof(original) / sizeof(original[0]);
int arr[20];

cout << "original array: ";
printArray(original, n);
cout << endl;

//first pivot
copyArray(original, arr, n);
comparisons = 0;
quickSort(arr, 0, n - 1, 1);
cout << "after sorting (first element pivot): ";
printArray(arr, n);
cout << "comparisons: " << comparisons << endl << endl;

//middle pivot
copyArray(original, arr, n);
comparisons = 0;
quickSort(arr, 0, n - 1, 2);
cout << "after sorting (middle element pivot): ";
printArray(arr, n);
cout << "comparisons: " << comparisons << endl << endl;

//median pivot
copyArray(original, arr, n);
comparisons = 0;
quickSort(arr, 0, n - 1, 3);
cout << "after sorting (median pivot): ";
printArray(arr, n);
cout << "comparisons: " << comparisons << endl << endl;

//last pivot
copyArray(original, arr, n);
comparisons = 0;
quickSort(arr, 0, n - 1, 4);
cout << "after sorting (last element pivot): ";
printArray(arr, n);
cout << "comparisons: " << comparisons << endl;

return 0;
}
