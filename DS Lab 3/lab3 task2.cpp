#include <iostream>
using namespace std;

//Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

//Insert at end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//Rotate list
void rotateList(Node*& head, int k) {
    if (head == nullptr || k == 0) return;

    //Count nodes
    Node* temp = head;
    int length = 1;
    while (temp->next != nullptr) {
        temp = temp->next;
        length++;
    }

    // If k >= length, reduce it
    k = k % length;
    if (k == 0) return;

    //circular list
    temp->next = head;

    //travel between node
    Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    //Switch head with tail
    head = newTail->next;
    newTail->next = nullptr;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 5; i++) insertAtEnd(head, i);

    cout << "Original List: ";
    printList(head);

    int k;
    cout << "Enter the number of elements to move: ";
    cin >> k;

    rotateList(head, k);

    cout << "After rotation: ";
    printList(head);

    return 0;
}
