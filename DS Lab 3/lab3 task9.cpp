#include <iostream>
using namespace std;
//Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

//Insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

//Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//Reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//rearranged Function
void rearrangeList(Node*& head) {
    if (!head || !head->next) return;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    //Split into odd and even
    while (odd->next && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    //Reverse the even list
    evenHead = reverseList(evenHead);

    //Append new even with odd list
    odd->next = evenHead;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 10; i++) {
        insertEnd(head, i);
    }

    cout << "Original List: ";
    printList(head);

    rearrangeList(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
