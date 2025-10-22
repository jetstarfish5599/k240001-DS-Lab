#include <iostream>
#include <string>
using namespace std;

#define SIZE 5

class MessageQueue {
private:
    string arr[SIZE];
    int front, rear;

public:
    MessageQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string msg) {
        if (isFull()) {
            cout << "Message queue is full!: " << msg << endl;
            return;
        }

        if (front == -1) front = 0;
        arr[++rear] = msg;
        cout << "New message added: \"" << msg << "\"" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No messages left to process." << endl;
            return;
        }

        cout << "Processing message: \"" << arr[front] << "\"" << endl;
        front++;

        if (front > rear) {
            front = rear = -1; // Reset when empty
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending messages." << endl;
            return;
        }
        cout << "Pending messages: ";
        for (int i = front; i <= rear; i++) {
            cout << "\"" << arr[i] << "\" ";
        }
        cout << endl;
    }
};

int main() {
    MessageQueue mq;

    cout << " Messaging System Simulated" << endl;

    mq.enqueue("Hello!");
    mq.enqueue("How are you?");
    mq.enqueue("Meeting at 3 PM");
    mq.enqueue("\"Don't forget to send report\"");
    mq.enqueue("Lunch?");

    cout << endl;
    mq.display();

    cout << "\nMessage in Process" << endl;
    while (!mq.isEmpty()) {
        mq.dequeue();
        mq.display();
    }

    return 0;
}
