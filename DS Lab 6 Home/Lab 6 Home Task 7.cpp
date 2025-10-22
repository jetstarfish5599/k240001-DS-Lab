#include <iostream>
#include <string>
using namespace std;

#define SIZE 10 //max patrons

class LibraryQueue {
private:
    string patrons[SIZE];
    int front, rear;

public:
    LibraryQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue full! Patron " << name << " must wait.\n";
            return;
        }
        if (front == -1) front = 0; //first entry
        patrons[++rear] = name;
        cout << name << " joined the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No patrons left.\n";
            return;
        }
        cout << patrons[front] << " completed transaction.\n";
        front++;
        if (front > rear) front = rear = -1; //reset
    }

    void display() {
        if (isEmpty()) {
            cout << "No patrons waiting.\n";
            return;
        }
        cout << "Current queue: ";
        for (int i = front; i <= rear; i++) {
            cout << patrons[i];
            if (i < rear) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    LibraryQueue q;
    int choice;
    string name;

    cout << "Library Queue Simulated\n";

    while (true) {
        cout << "\n1. Patron Arrives\n2. Complete Transaction\n3. Show Queue\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patron name: ";
            cin >> name;
            q.enqueue(name);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Simulation ended.\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
