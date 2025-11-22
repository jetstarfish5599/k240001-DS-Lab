#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Node {
    int key;
    string value;
    Node* next;

    Node(int k, const string& v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class Hash {
private:
    Node* table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    Hash() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void insert(int key, const string& value) {
        int index = hashFunction(key);

        //check if key exists update it
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                temp->value = value;
                return;
            }
            temp = temp->next;
        }

        //insert new node at head
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    string search(int key) {
        int index = hashFunction(key);

        //search in chain
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }

        return "NOT FOUND";
    }

    void del(int key) {
        int index = hashFunction(key);

        Node* temp = table[index];
        Node* prev = nullptr;

        //search for key
        while (temp != nullptr && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "key " << key << " not found\n";
            return;
        }

        //delete node
        if (prev == nullptr) {
            table[index] = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "key " << key << " deleted\n";
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "index " << i << ": ";
            Node* temp = table[i];

            if (!temp) {
                cout << "EMPTY";
            }

            while (temp != nullptr) {
                cout << "(" << temp->key << ", " << temp->value << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ~Hash() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* temp = table[i];
            while (temp != nullptr) {
                Node* delNode = temp;
                temp = temp->next;
                delete delNode;
            }
        }
    }
};

int main() {
    Hash h;

    h.insert(101, "Zain");
    h.insert(205, "Zara");
    h.insert(309, "Raza");
    h.insert(105, "Taha");

    cout << "search 205 = " << h.search(205) << endl;
    cout << "search 555 = " << h.search(555) << endl;

    cout << "\nbefore delete:\n";
    h.display();

    h.del(205);

    cout << "\nafter delete:\n";
    h.display();

    return 0;
}
