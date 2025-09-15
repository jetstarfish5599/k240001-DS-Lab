#include <iostream>
using namespace std;
//Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* tail = nullptr;

//Insert at end
void insertEnd(int val) {
    Node* newNode = new Node(val);
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

//Insert at beginning
void insertBegin(int val) {
    Node* newNode = new Node(val);
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

//Insert at given position
void insertAtPos(int val, int pos) {
    if (!tail) {
        cout << "List empty, inserting at beginning\n";
        insertBegin(val);
        return;
    }
    Node* temp = tail->next;
    Node* newNode = new Node(val);
    for (int i = 1; i < pos - 1 && temp != tail; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == tail) tail = newNode;
}

//Delete a node
void deleteNode(int val) {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }
    Node* curr = tail->next;
    Node* prev = tail;

    do {
        if (curr->data == val) {
            if (curr == prev) {
                delete curr;
                tail = nullptr;
            } else {
                prev->next = curr->next;
                if (curr == tail) tail = prev;
                delete curr;
            }
            cout << "Deleted " << val << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    cout << "Value " << val << " not found\n";
}

//Print circular linked list
void printCircular() {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

int main() {
    //empty circular list
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    cout << "Initial list: ";
    printCircular();

    insertBegin(5);
    cout << "After inserting 5 at beginning: ";
    printCircular();

    insertAtPos(15, 3);
    cout << "After inserting 15 at position 3: ";
    printCircular();

    deleteNode(20);
    cout << "After deleting 20: ";
    printCircular();

    return 0;
}
