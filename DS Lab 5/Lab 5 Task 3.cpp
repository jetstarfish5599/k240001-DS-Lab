#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int n) : data(n), next(NULL) {}
};

// Tail recursive function to find length
int length(Node* head, int count = 0) {
    if (head == NULL) 
        return count;          // base case
    return length(head->next, count + 1); // tail call
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Length of list: " << length(head) << endl;
    return 0;
}
