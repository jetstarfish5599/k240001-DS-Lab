#include <iostream>
#include <cstring>  // for strlen

using namespace std;

#define SIZE 10

class palindrom {
    char arr[SIZE];
    int top;
public:
    palindrom() { top = -1; }

    bool push(char c) {
        if (top >= SIZE - 1) {
            cout << "Stack overflow\n";
            return false;
        }
        arr[++top] = c;
        return true;
    }

    char pop() {
        if (top < 0) {
            cout << "Stack underflow\n";
            return '\0'; 
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    char str[] = "BORROWROB";
    int length = strlen(str);

    palindrom palindrom;
//string borrowbob
    for (int i = 0; i < length; i++) {
        palindrom.push(str[i]);
    }

    char reversed[SIZE];
    int index = 0;
//reversed string
    while (!palindrom.isEmpty()) {
        reversed[index++] = palindrom.pop();
    }
    reversed[index] = '\0'; 
//Compare
    if (strcmp(str, reversed) == 0) {
        cout << "     " << str << "   is a palindrome." << endl;
    } else {
        cout << "    " << str << "    is not a palindrome." << endl;
    }

    return 0;
}
