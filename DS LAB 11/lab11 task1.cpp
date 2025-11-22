#include<iostream>
#include<cstring>
using namespace std;

struct Node {
    string key;
    string value;
    Node* next;

    Node(string k, string v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable {
    Node** arr;
    int capacity;
    int numOfElements;

    int hashFunction(string key) {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
            sum += key[i];
        return sum % capacity;
    }

public:
    HashTable() {
        capacity = 100;
        numOfElements = 0;

        arr = new Node*[capacity];
        for (int i = 0; i < capacity; i++)
            arr[i] = NULL;
    }

    //Insert key
    void insert(string key, string value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);

        //Insert at head
        newNode->next = arr[index];
        arr[index] = newNode;

        numOfElements++;
    }

    //Search for key
    string search(string key) {
        int index = hashFunction(key);
        Node* curr = arr[index];

        while (curr != NULL) {
            if (curr->key == key)
                return curr->value;
            curr = curr->next;
        }

        return "Key Not Found";
    }

    //Delete key
    void remove(string key) {
        int index = hashFunction(key);
        Node* curr = arr[index];
        Node* prev = NULL;

        while (curr != NULL) {
            if (curr->key == key) {
                if (prev == NULL) {
                    arr[index] = curr->next;    //head deletion
                } 
                else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Print the entire table
    void print() {
        cout << "\nHash Table\n";
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != NULL) {
                cout << "Bucket " << i << ": ";
                Node* curr = arr[i];
                while (curr != NULL) {
                    cout << "[Key: " << curr->key 
                         << ", Value: " << curr->value << "] -> ";
                    curr = curr->next;
                }
                cout << "NULL\n";
            }
        }
        cout << "\n";
    }
};

int main() {

    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    myhash.print();

    cout << "Search A: " << myhash.search("A") << endl;

    cout << "\nAfter deleting B:\n";
    myhash.remove("B");
    myhash.print();

    return 0;
}
