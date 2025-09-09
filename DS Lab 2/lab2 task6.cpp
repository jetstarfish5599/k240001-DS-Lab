#include <iostream>
#include <string>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    //capacity of each row
    int* capacity = new int[rows];
    for (int i = 0; i < rows; i++) {
        cout << "Enter seats in row " << i + 1 << ": ";
        cin >> capacity[i];
    }

    //jagged seating
    string* seats[rows];
    for (int i = 0; i < rows; i++)
        seats[i] = new string[capacity[i]];

    //input names
    for (int i = 0; i < rows; i++) {
        cout << "\nRow " << i + 1 << ":\n";
        for (int j = 0; j < capacity[i]; j++) {
            cout << "  Seat " << j + 1 << ": ";
            cin >> seats[i][j];
        }
    }

    //display chart
    cout << "\n--- Seating Chart ---\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < capacity[i]; j++)
            cout << seats[i][j] << " ";
        cout << endl;
    }

    // free memory
    for (int i = 0; i < rows; i++) delete[] seats[i];
    delete[] capacity;

    return 0;
}