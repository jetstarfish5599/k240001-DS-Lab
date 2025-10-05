#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim) {
    //base case
    if (dim == 1) { 
        int sum = 0;
        for (int i = 0; i < sizes[0]; i++)
            sum += arr[0][i];
        return sum;
    }

    int sum = 0;
    for (int i = 0; i < sizes[0]; i++) {
        for (int j = 0; j < sizes[i + 1]; j++)
            sum += arr[i][j];
    }
    return sum;
}

int main() {
    int a1[] = {1, 2, 3};
    int a2[] = {4, 5};
    int a3[] = {6, 7, 8, 9};

    int* arr[] = {a1, a2, a3};
    int sizes[] = {3, 3, 2, 4};

    cout << "Sum: " << recursiveArraySum(arr, sizes, 2);
    return 0;
}
