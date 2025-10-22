#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full! Cannot add Customer ID: " << value << endl;
            return;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        cout << "Customer ID " << value << " entered the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No customers left in queue." << endl;
            return;
        }

        cout << "Customer ID " << arr[front] << " checked out." << endl;

        if (front == rear) {
            front = rear = -1; // queue becomes empty
        }
        else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    // Enqueue customers
    int customers[] = {13, 7, 4, 1, 6, 8, 10};
    int total = sizeof(customers) / sizeof(customers[0]);

    cout << "=== Customers entering queue ===" << endl;
    for (int i = 0; i < total; i++) {
        q.enqueue(customers[i]);
    }

    cout << endl;
    q.display();

    cout << "\n=== Checkout Process ===" << endl;
    // Dequeue all customers
    while (!q.isEmpty()) {
        q.dequeue();
        q.display();
    }

    return 0;
}
