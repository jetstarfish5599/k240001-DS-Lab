#include <iostream>
using namespace std;

//Max size
#define MAX_SIZE 12

//max in array
int getMax(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

//Counting Sort
void countingSort(int arr[], int n, int exp, int mode) {
    int output[MAX_SIZE];
    int count[10] = {0};

    //Count
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    //Calculate positions
    if (mode == 1) {
        //Asc
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
    } else {
        //Des
        for (int i = 8; i >= 0; i--) {
            count[i] += count[i + 1];
        }
    }

    //Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    //Copy to array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

//Radix Sort
void radixSort(int arr[], int n, int mode) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, n, exp, mode);
    }
}

void printArray(int arr[], int n, const char* title) {
    cout << "\n     " << title << "    " << endl;
    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    //array 
    int original_arr[MAX_SIZE] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
    int n = MAX_SIZE;

    int arr_asc[MAX_SIZE];
    int arr_desc[MAX_SIZE];

    for (int i = 0; i < n; ++i) {
        arr_asc[i] = original_arr[i];
        arr_desc[i] = original_arr[i];
    }

    printArray(original_arr, n, "Original Array");

    //Sort Asc
    radixSort(arr_asc, n, 1);
    printArray(arr_asc, n, "Radix Sort Result (Asc)");

    //Sort Des
    radixSort(arr_desc, n, -1);
    printArray(arr_desc, n, "Radix Sort Result (Des)");

    return 0;
}
