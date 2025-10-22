#include <iostream>
using namespace std;

//nodedef
struct Node {
    string site;
    Node* next;
};

//stackclass
class Stack {
    Node* top;
public:
    Stack() { top = NULL; }

    //addtop
    void push(string val) {
        Node* n = new Node;
        n->site = val;
        n->next = top;
        top = n;
    }

    //removetop
    void pop() {
        if (top == NULL) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    //showtop
    string peek() {
        if (top) return top->site;
        return "None";
    }

    //checkempty
    bool empty() { return top == NULL; }
};

//historyclass
class History {
    Node* head;
    Stack backStack;
public:
    History() { head = NULL; }

    //visitnewsite
    void visit(string url) {
        Node* n = new Node;
        n->site = url;
        n->next = head;
        head = n;
        backStack.push(url);
        cout << "Visit:" << url << endl;
    }

    //goback
    void back(int n) {
        cout << "Back" << n << "times\n";
        for (int i = 0; i < n; i++) {
            if (head && !backStack.empty()) {
                cout << "Leaving:" << backStack.peek() << endl;
                backStack.pop();
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
        cout << "Nowat:" << backStack.peek() << endl;
    }

    //showlist
    void show() {
        Node* t = head;
        cout << "List:";
        while (t) {
            cout << t->site << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    History h;
    h.visit("Google");
    h.visit("Facebook");
    h.visit("Twitter");
    h.visit("LinkedIn");
    h.visit("Instagram");

    h.show();
    h.back(2);
    h.show();

    return 0;
}
