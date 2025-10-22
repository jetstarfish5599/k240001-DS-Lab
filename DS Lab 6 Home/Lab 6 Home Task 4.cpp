#include <iostream>
using namespace std;

//node
struct Node {
    string data;
    Node* next;
    Node(string d) : data(d), next(NULL) {}
};

//stack via linked list
class Stack {
    Node* topNode;
public:
    Stack() { topNode = NULL; }
    bool empty() { return topNode == NULL; }
    void push(string v) { Node* t = new Node(v); t->next = topNode; topNode = t; } //push head
    string pop() {
        if (empty()) return "";
        string x = topNode->data;
        Node* t = topNode;
        topNode = topNode->next;
        delete t;
        return x;
    }
    string top() { return empty() ? "" : topNode->data; }
    void show() {
        Node* t = topNode;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

//manual eval
float evalExpr() {
    float ans = 12 + 13 - 5 * (0.5 + 0.5) + 1;
    return ans;
}

int main() {
    Stack s;
    //push expr
    s.push("x");
    s.push("=");
    s.push("12");
    s.push("+");
    s.push("13");
    s.push("-");
    s.push("5");
    s.push("*");
    s.push("(0.5+0.5)");
    s.push("+");
    s.push("1");

    cout << "Before pushing result:\n";
    s.show();

    float r = evalExpr();
    s.push(to_string((int)r)); //push 20

    cout << "\nAfter pushing result:\n";
    s.show();

    cout << "\nTop of stack (result): " << s.top() << endl;
    return 0;
}
