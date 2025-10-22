#include <iostream>
#include <string>
using namespace std;

//node for stack
struct Node {
    char data;
    Node* next;
    Node(char c) : data(c), next(NULL) {}
};

//stack using linked list
class Stack {
    Node* topNode;
public:
    Stack() { topNode = NULL; }
    bool isEmpty() { return topNode == NULL; }
    void push(char c) {
        Node* t = new Node(c);
        t->next = topNode;
        topNode = t;
    }
    char pop() {
        if (isEmpty()) return '\0';
        char x = topNode->data;
        Node* t = topNode;
        topNode = topNode->next;
        delete t;
        return x;
    }
    char top() {
        return isEmpty() ? '\0' : topNode->data;
    }
};

//precedence check
int prec(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

//main conversion
string infixToPostfix(string infix) {
    Stack s;
    string post = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c)) post += c;  //operand
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.top() != '(')
                post += s.pop();
            s.pop(); //remove '('
        } else { //operator
            while (!s.isEmpty() && prec(c) <= prec(s.top()))
                post += s.pop();
            s.push(c);
        }
    }
    while (!s.isEmpty())
        post += s.pop();
    return post;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
