#include <iostream>
#include <string>
using namespace std;

//Node for student
struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int s) {
        name = n;
        score = s;
        next = nullptr;
    }
};

//Add node to head
void addNode(Node*& head, string name, int score) {
    Node* newNode = new Node(name, score);
    newNode->next = head;
    head = newNode;
}

//print list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->name << " " << current->score << endl;
        current = current->next;
    }
}

//maximum score
int getMax(Node* head) {
    int max = 0;
    Node* temp = head;
    while (temp) {
        if (temp->score > max)
            max = temp->score;
        temp = temp->next;
    }
    return max;
}

//Radix sort
void radixSort(Node*& head) {
    Node* buckets[10] = {nullptr};
    Node* bucketTails[10] = {nullptr};

    int maxScore = getMax(head);

    for (int exp = 1; maxScore / exp > 0; exp *= 10) {
        // Reset
        for (int i = 0; i < 10; ++i) {
            buckets[i] = nullptr;
            bucketTails[i] = nullptr;
        }

        Node* current = head;

        while (current) {
            int index = (current->score / exp) % 10;
            Node* nextNode = current->next;
            current->next = nullptr;

            if (!buckets[index]) {
                buckets[index] = bucketTails[index] = current;
            } else {
                bucketTails[index]->next = current;
                bucketTails[index] = current;
            }
            current = nextNode;
        }

        //Reassemble list
        head = nullptr;
        Node* tail = nullptr;
        for (int i = 0; i < 10; ++i) {
            if (buckets[i]) {
                if (!head) {
                    head = buckets[i];
                    tail = bucketTails[i];
                } else {
                    tail->next = buckets[i];
                    tail = bucketTails[i];
                }
            }
        }
    }
}

//length of list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

//node at given index
Node* getNodeAt(Node* head, int index) {
    for (int i = 0; i < index && head; ++i)
        head = head->next;
    return head;
}

//Binary search
Node* binarySearch(Node* head, string name, int score) {
    int left = 0;
    int right = getLength(head) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);
        if (midNode->score == score && midNode->name == name) {
            return midNode;
        } else if (midNode->score < score ||
                  (midNode->score == score && midNode->name < name)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return nullptr;
}

//Delete node
void deleteNode(Node*& head, string name, int score) {
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->name == name && current->score == score) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            cout << "\nRecord deleted successfully.\n";
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "\nRecord not found.\n";
}

int main() {
    Node* head = nullptr;

    // Add initial student records
    addNode(head, "Ayan", 90);
    addNode(head, "Zameer", 60);
    addNode(head, "Sara", 70);
    addNode(head, "Sohail", 50);
    addNode(head, "Ahmed", 80);

    cout << "Original List:\n";
    printList(head);

    radixSort(head);

    cout << "\nSorted List:\n";
    printList(head);

    //enter a name and score
    string searchName;
    int searchScore;

    cout << "\nEnter name and score to delete: ";
    cin >> searchName >> searchScore;

    Node* found = binarySearch(head, searchName, searchScore);
    if (found) {
        deleteNode(head, searchName, searchScore);
    } else {
        cout << "\nRecord not found.\n";
    }

    cout << "\nUpdated List:\n";
    printList(head);

    return 0;
}
