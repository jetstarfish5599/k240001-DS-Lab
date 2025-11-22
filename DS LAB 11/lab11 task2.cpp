#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 35;

struct Node {
    string key;        //key
    string value;      //meaning/value
    Node* next;

    Node(string k, string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class Dictionary {
private:
    Node* table[TABLE_SIZE];

    //hash=sum ASCII%100
    int hashFunc(const string& s) {
        int sum = 0;
        for (char c : s) {
            sum += int(c);
        }
        return sum % TABLE_SIZE;
    }

public:
    Dictionary() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void Add_Record(const string& key, const string& value) {
        int index = hashFunc(key);

        Node* temp = table[index];

        // update if exists
        while (temp != nullptr) {
            if (temp->key == key) {
                temp->value = value;
                return;
            }
            temp = temp->next;
        }

        //insert
        Node* n = new Node(key, value);
        n->next = table[index];
        table[index] = n;
    }

    string Word_Search(const string& key) {
        int index = hashFunc(key);

        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key) return temp->value;
            temp = temp->next;
        }

        return "ERROR! Word not found";
    }

    void Delete_Record(const string& key) {
        int index = hashFunc(key);

        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Key " << key << " NOT found\n";
            return;
        }

        if (prev == nullptr) {
            table[index] = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Key " << key << " deleted successfully !\n";
    }

    void Print_Dictionary() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "index " << i << ": ";

            Node* temp = table[i];

            if (temp == nullptr) {
                cout << "EMPTY";
            }

            while (temp != nullptr) {
                cout << "(" << temp->key << ", " << temp->value << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Dictionary d;

    //insertions
    d.Add_Record("AB", "FASTNUCES");
    d.Add_Record("EF", "Deleted Sample");
    d.Add_Record("CD", "CS");

    //search
    cout << "search key AB: " << d.Word_Search("AB") << endl;

    //delete
    d.Delete_Record("EF");

    //print
    cout << "\nDictionary Table:\n";
    d.Print_Dictionary();

    return 0;
}
