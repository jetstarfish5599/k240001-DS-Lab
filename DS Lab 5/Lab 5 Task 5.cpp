#include <iostream>
#include <vector>
using namespace std;

//Recursive jagged function
int sumJagged(const vector<vector<int>>& arr) {
    int total = 0;
    for (const auto& row : arr)
        for (int val : row)
            total += val;
    return total;
}

int main() {
    //Jagged array 
    vector<vector<int>> data = {
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9}
    };

    cout << "Sum of all elements: " << sumJagged(data) << endl;
    return 0;
}
