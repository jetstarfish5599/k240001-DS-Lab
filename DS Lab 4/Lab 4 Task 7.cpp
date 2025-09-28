#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Linear Search function
int linearSearch(string arr[], int n, string key, int &steps) {
    steps = 0;
    for (int i = 0; i < n; i++) {
        steps++;
        if (arr[i] == key) return i;
    }
    return -1;
}

//Binary Search function
int binarySearch(string arr[], int n, string key, int &steps) {
    int low = 0, high = n - 1;
    steps = 0;
    while (low <= high) {
        steps++;
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (key < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    //Array
    string arr[10] = {"Ahmed","Ali","Basit","Karim","Rizwan",
                      "Sarwar","Tariq","Taufiq","Yasin","Zulfiqar"};
    
    //Sor for Binary Search
    sort(arr, arr + 10);

    //Required
    string targets[3] = {"Aftab", "Rizwan", "Tariq"};
    
    int n = 10;

    //Search for required
    for (string t : targets) {
        int stepsL, stepsB;
        int indexL = linearSearch(arr, n, t, stepsL);
        int indexB = binarySearch(arr, n, t, stepsB);

        cout << "\nSearching for: " << t << endl;
        cout << "Linear Search = Index: " << indexL<<"\n" << "Steps: " << stepsL << endl;
        cout << "Binary Search = Index: " << indexB <<"\n" <<  "Steps: " << stepsB << endl;
    }
    
    return 0;
}
