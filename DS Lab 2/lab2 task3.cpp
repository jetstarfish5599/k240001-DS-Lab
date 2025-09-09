#include <iostream>
using namespace std;

int main() {
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;

    //students in department
    int* students = new int[departments];
    for (int i = 0; i < departments; i++) {
        cout << "Enter number of students in Department " << i + 1 << ": ";
        cin >> students[i];
    }

    //3D arrray
    int** marks[departments];
    for (int d = 0; d < departments; d++) {
        marks[d] = new int*[students[d]];
        for (int s = 0; s < students[d]; s++)
            marks[d][s] = new int[5];
    }

    // input
    for (int d = 0; d < departments; d++) {
        cout << "\nDepartment " << d + 1 << ":\n";
        for (int s = 0; s < students[d]; s++) {
            cout << " Student " << s + 1 << " marks:\n";
            for (int sub = 0; sub < 5; sub++) {
                cout << "  Subject " << sub + 1 << ": ";
                cin >> marks[d][s][sub];
            }
        }
    }

    cout << "\n--- Department Results ---\n";

    //departments
    for (int d = 0; d < departments; d++) {
        int highest = -1e9, lowest = 1e9, total = 0, count = 0;

        for (int s = 0; s < students[d]; s++) {
            int sum = 0;
            for (int sub = 0; sub < 5; sub++) {
                sum += marks[d][s][sub];
            }
            if (sum > highest) highest = sum;
            if (sum < lowest) lowest = sum;
            total += sum;
            count++;
        }

        double avg = (double)total / count;
        cout << "Department " << d + 1 << " -> "
             << "Highest: " << highest
             << "  Lowest: " << lowest
             << "  Average: " << avg << endl;
    }

    //free memory
    for (int d = 0; d < departments; d++) {
        for (int s = 0; s < students[d]; s++)
            delete[] marks[d][s];
        delete[] marks[d];
    }
    delete[] students;

    return 0;
}