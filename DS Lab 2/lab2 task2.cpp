#include <iostream>
using namespace std;

int main() {
    int students = 5, subjects = 4;

    //dynamic 2D array
    int **marks = new int*[students];
    for (int i = 0; i < students; i++)
        marks[i] = new int[subjects];

    //user input
    cout << "Enter marks:\n";
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ":\n";
        for (int j = 0; j < subjects; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    //total
    int *totals = new int[students];
    for (int i = 0; i < students; i++) {
        totals[i] = 0;
        for (int j = 0; j < subjects; j++)
            totals[i] += marks[i][j];
        cout << "Total marks of Student " << i + 1 << " = " << totals[i] << endl;
    }

    //average
    for (int j = 0; j < subjects; j++) {
        int sum = 0;
        for (int i = 0; i < students; i++)
            sum += marks[i][j];
        cout << "Average marks of Subject " << j + 1 << " = " 
             << (double)sum / students << endl;
    }

    //topper
    int topper = 0;
    for (int i = 1; i < students; i++)
        if (totals[i] > totals[topper]) topper = i;

    cout << "Topper is Student " << topper + 1 
         << " with " << totals[topper] << " marks.\n";

    //free memory
    for (int i = 0; i < students; i++) delete[] marks[i];
    delete[] marks;
    delete[] totals;

    return 0;
}
