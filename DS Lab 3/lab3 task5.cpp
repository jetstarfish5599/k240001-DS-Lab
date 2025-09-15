#include <iostream>
using namespace std;

//Node
struct Node {
    char data; 
    Node* next;
    Node(char val) : data(val), next(nullptr) {}
};

//Insert at end
void insertAtEnd(Node*& head, char val) {
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

//Reverse linked list
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

// Check if palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    //Finding middle 
    Node* single = head;
    Node* doublePtr = head;
    while (doublePtr->next && doublePtr->next->next) {
        single = single->next;
        doublePtr = doublePtr->next->next;
    }

    //Reverse second half
    single->next = reverseList(single->next);
    Node* secondHalf = single->next;
    Node* firstHalf = head;

    //Compare halfes
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

int main() {
    Node* head1 = nullptr;
    int arr1[] = {1,0,2,0,1};
    for (int val : arr1) insertAtEnd(head1, val + '0');

    cout << "List 1: ";
    printList(head1);
    cout << (isPalindrome(head1) ? "Linked List is a Palindrome\n" 
                                 : "Linked List is NOT a Palindrome\n");

    Node* head2 = nullptr;
    string str = "MAADAAM";
    for (char c : str) insertAtEnd(head2, c);

    cout << "List 2: ";
    printList(head2);
    cout << (isPalindrome(head2) ? "Linked List is a Palindrome\n" 
                                 : "Linked List is NOT a Palindrome\n");

    return 0;
}
