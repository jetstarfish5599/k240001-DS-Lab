#include <iostream>
using namespace std;
//Node
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

struct DoublyList {
    Node* head;
    Node* tail;
    DoublyList() : head(nullptr), tail(nullptr) {}
};

//Insert at end
void insertEnd(DoublyList& L, int val) {
    Node* newNode = new Node(val);
    if (!L.head) {
        L.head = L.tail = newNode;
    } else {
        L.tail->next = newNode;
        newNode->prev = L.tail;
        L.tail = newNode;
    }
}

//Print list
void printList(DoublyList L) {
    Node* temp = L.head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//Concatenate lists
DoublyList concatenate(DoublyList A, DoublyList B) {
    if (!A.head) return B;
    if (!B.head) return A;

    A.tail->next = B.head;
    B.head->prev = A.tail;

    DoublyList result;
    result.head = A.head;
    result.tail = B.tail;
    return result;
}

int main() {
    DoublyList A, B;

    //List A
    insertEnd(A, 1);
    insertEnd(A, 2);
    insertEnd(A, 3);

    //List B
    insertEnd(B, 4);
    insertEnd(B, 5);
    insertEnd(B, 6);

    cout << "List A: ";
    printList(A);
    cout << "List B: ";
    printList(B);

    DoublyList C = concatenate(A, B);

    cout << "Concatenated List: ";
    printList(C);

    return 0;
}
