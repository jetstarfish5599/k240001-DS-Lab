#include <iostream>
using namespace std;

//nodedef
struct Node {
    string data;
    Node* next;
};

//stackclass
class Stack {
    Node* top;
public:
    Stack() { top = NULL; }

    //addtohead
    void push(string val) {
        Node* n = new Node;
        n->data = val;
        n->next = top;
        top = n;
        cout << val << " added\n";
    }

    //removehead
    void pop() {
        if (top == NULL) {
            cout << "Stackempty\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " removed\n";
        top = top->next;
        delete temp;
    }

    //checkempty
    bool empty() { return top == NULL; }

    //showtop
    void peek() {
        if (top) cout << "Top:" << top->data << endl;
        else cout << "Nodata\n";
    }
};

int main() {
    Stack s;
    s.push("Finishreport");
    s.push("Replyemails");
    s.push("Attendmeeting");

    s.peek();
    s.pop();
    s.peek();

    return 0;
}
