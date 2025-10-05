#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(NULL) {}
};

//search
bool search(Node* head, int key) {
     //base case
    if (head == NULL)
        return false;
//found        
    if (head->data == key)
        return true;                 
    // recursion
    return search(head->next, key);  
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (search(head, key))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
