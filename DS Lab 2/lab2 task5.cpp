#include <iostream>
using namespace std;

int main() {
    //courses in department
    int courses[4] = {3,4,2,1};

    //jagged array
    float* gpa[4];
    for (int i = 0; i < 4; i++)
        gpa[i] = new float[courses[i]];

    //input
    cout << "Enter GPAs for courses:\n";
    for (int d = 0; d < 4; d++) {
        cout << "Department " << d + 1 << ":\n";
        for (int c = 0; c < courses[d]; c++) {
            cout << "  Course " << c + 1 << ": ";
            cin >> gpa[d][c];
        }
    }

    //output
    cout << "\n--- GPA Data ---\n";
    for (int d = 0; d < 4; d++) {
        cout << "Department " << d + 1 << ": ";
        for (int c = 0; c < courses[d]; c++)
            cout << gpa[d][c] << " ";
        cout << endl;
    }

    //free memory
    for (int i = 0; i < 4; i++) delete[] gpa[i];

    return 0;
}