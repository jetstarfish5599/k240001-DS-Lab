#include <iostream>
using namespace std;

//Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

//Insert end
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

//Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << "->NULL\n";
}

//evens before odds
Node* evenOddList(Node* head) {
    if (!head || !head->next) return head;

    Node* evenHead = nullptr, *evenTail = nullptr;
    Node* oddHead = nullptr, *oddTail = nullptr;
    Node* curr = head;

    //Separate even and odd lists
    while (curr) {
        if (curr->data % 2 == 0) {
            if (!evenHead) evenHead = evenTail = curr;
            else {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
        } else {
            if (!oddHead) oddHead = oddTail = curr;
            else {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
        }
        curr = curr->next;
    }

    //for null or one list
    if (!evenHead || !oddHead) return head;

    //Merge lists
    evenTail->next = oddHead;
    oddTail->next = nullptr;

    return evenHead;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 10; i++) insertAtEnd(head, i);

    cout << "Original List: ";
    printList(head);

    head = evenOddList(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
