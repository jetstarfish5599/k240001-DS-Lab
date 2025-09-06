#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* studentName;
    char* examDate;
    int score;

public:
    // Constructor
    Exam() : studentName(nullptr), examDate(nullptr), score(0) {}

    //Destructor
    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }

    //deep copy
    void setDetails(const char* name, const char* date, int s) {
        //delete
        delete[] studentName;
        delete[] examDate;

        //copy new data
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);

        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);

        score = s;
    }

    // Display function
    void display() const {
        cout << "Student Name: " << (studentName ? studentName : "N/A") << endl;
        cout << "Exam Date: " << (examDate ? examDate : "N/A") << endl;
        cout << "Score: " << score << endl;
    }
    
 
};

int main() {
    //objects
    Exam exam1;
    exam1.setDetails("masoom", "3/9/25", 95);

    cout << "Exam Object (exam1):" << endl;
    exam1.display();
    cout << endl;

    //shallow copy
    Exam exam2 = exam1;

    cout << "Shallow copied Exam Object (exam2):" << endl;
    exam2.display();
    cout << endl;

    //changing dets
    exam2.setDetails("ali", "5/9/25", 85);

    cout << "After modifying exam2:" << endl;
    cout << "exam1:" << endl;
    exam1.display();

    cout << "exam2:" << endl;
    exam2.display();

    return 0;
}
