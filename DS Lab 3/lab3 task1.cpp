#include <iostream>
using namespace std;

//Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

//Print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//Inserting end
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

//Insert at front
void insertAtFront(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

//insert given location
void insertAtPos(Node*& head, int pos, int val) {
    if (pos == 1) {
        insertAtFront(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) temp = temp->next;
    if (temp == nullptr) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

//Delete by value
void deleteByValue(Node*& head, int val) {
    if (head == nullptr) return;
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != val) temp = temp->next;
    if (temp->next == nullptr) return;
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

int main() {
    //Print array
    int arr[5] = {3, 1, 2, 5, 8};
    cout << "Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;

    //Requierd linked list
    Node* head = nullptr;
    for (int i = 0; i < 5; i++) insertAtEnd(head, arr[i]);

    cout << "Initial Linked List: ";
    printList(head);

    // Insert values
    insertAtEnd(head, 9);
    insertAtPos(head, 3, 11);
    insertAtFront(head, 4);

    cout << "Linked List after insertions: ";
    printList(head);

    //Delete values
    deleteByValue(head, 1);
    deleteByValue(head, 2);
    deleteByValue(head, 5);

    //New list
    cout << "Final Linked List after deletions: ";
    printList(head);

    return 0;
}
