#include <iostream>
using namespace std;

struct Pair {
    int a;
    int b;
    bool used;
};

const int TABLE_SIZE = 100;
Pair hashTable[TABLE_SIZE];

//simple hash function
int hashFunc(int sum) {
    return sum % TABLE_SIZE;
}

//initialize table
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].used = false;
    }
}

//insert sum→pair
void insertSum(int sum, int a, int b) {
    int index = hashFunc(sum);

    while (hashTable[index].used) {
        index = (index + 1) % TABLE_SIZE;  //linear probing
    }

    hashTable[index].a = a;
    hashTable[index].b = b;
    hashTable[index].used = true;
}

//search sum in table
bool findSum(int sum, int& a, int& b) {
    int index = hashFunc(sum);

    while (hashTable[index].used) {
        if ((hashTable[index].a + hashTable[index].b) == sum) {
            a = hashTable[index].a;
            b = hashTable[index].b;
            return true;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return false;
}

//find two distinct pairs
bool findPairs(int arr[], int n) {
    initTable();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int sum = arr[i] + arr[j];
            int a, b;

            if (findSum(sum, a, b)) {
                if (a != arr[i] && a != arr[j] && b != arr[i] && b != arr[j]) {
                    cout << "(" << a << ", " << b << ") and ("
                         << arr[i] << ", " << arr[j] << ")\n";
                    return true;
                }
            }

            insertSum(sum, arr[i], arr[j]);
        }
    }

    cout << "No pairs found\n";
    return false;
}

int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int arr2[] = {3, 4, 7, 1, 12, 9};
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    cout << "Input 1: ";
    findPairs(arr1, 7);
    cout << "Input 2: ";
    findPairs(arr2, 6);
    cout << "Input 3: ";
    findPairs(arr3, 7);
    return 0;
}
