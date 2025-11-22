#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 15;

class StudentHashTable {
private:
    int roll[TABLE_SIZE];
    string name[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    StudentHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            roll[i] = 0;
            name[i] = "";
            occupied[i] = false;
        }
    }

    void InsertRecord(int r, const string& n) {
        int hash = hashFunction(r);
        int index;
        int i = 0;

        //quadratic probing
        while (i < TABLE_SIZE) {
            index = (hash + i * i) % TABLE_SIZE;

            if (!occupied[index] || roll[index] == r) {
                roll[index] = r;
                name[index] = n;
                occupied[index] = true;
                return;
            }

            i++;
        }

        cout << "Table full. Cannot insert roll " << r << endl;
    }

    void SearchRecord(int r) {
        int hash = hashFunction(r);
        int index;
        int i = 0;

        //quadratic probing search
        while (i < TABLE_SIZE) {
            index = (hash + i * i) % TABLE_SIZE;

            if (!occupied[index]) {
                cout << "Record not found\n";
                return;
            }

            if (roll[index] == r) {
                cout << "Student Name: " << name[index] << endl;
                return;
            }

            i++;
        }

        cout << "Record not found\n";
    }

    void Display() {
        cout << "Index\tRoll\tName\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (occupied[i])
                cout << i << "\t" << roll[i] << "\t" << name[i] << endl;
            else
                cout << i << "\t-\t-\n";
        }
    }
};

int main() {
    StudentHashTable t;

    t.InsertRecord(10, "Ali");
    t.InsertRecord(25, "zara");
    t.InsertRecord(40, "Hassan");
    t.InsertRecord(12, "Taha");

    cout << "\nSearching roll 25:\n";
    t.SearchRecord(25);

    cout << "\nSearching roll 50:\n";
    t.SearchRecord(50);

    cout << "\nHash Table:\n";
    t.Display();

    return 0;
}
