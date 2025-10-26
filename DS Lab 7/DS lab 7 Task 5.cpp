#include <iostream>
using namespace std;

//Node struct
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

//print linked list
void printList(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//geet tail function
Node* getTail(Node* cur) {
    while (cur && cur->next)
        cur = cur->next;
    return cur;
}

// Function to swap data between two nodes
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

//Partition with last node as pivot
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* cur = head;
    Node* tail = pivot;

    // During partition, newHead and newEnd will be updated
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == nullptr)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;

            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == nullptr)
        (*newHead) = pivot;

    (*newEnd) = tail;
    return pivot;
}

//QuickSort function
Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;

    Node *newHead = nullptr, *newEnd = nullptr;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = nullptr;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

//quick sort call
void quickSort(Node** headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
}

//new node at head
void push(Node** headRef, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

//main Function
int main() {
    Node* head = nullptr;

    //linked list: 10, 7, 8, 9, 1, 5, 3
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = n - 1; i >= 0; i--)
        push(&head, arr[i]);

    cout << "Before Sporting:\n";
    printList(head);

    quickSort(&head);

    cout << "\nAfter Sorting:\n";
    printList(head);

    return 0;
}
