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
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

//Print list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << "->NULL\n";
}

//Delete value
void deleteValue(Node*& head, int val) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    //Search value
    while (temp && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Value " << val << " not present in the list\n";
        return;
    }

    //Deleting node
    if (!prev) { 
        cout << "First node cannot be deleted by this operation\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Value " << val << " deleted\n";
}

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 5; i++) insertAtEnd(head, i);

    cout << "Original List: ";
    printList(head);

    deleteValue(head, 3);
    printList(head);

    deleteValue(head, 10);

    return 0;
}
