#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == NULL)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    bool search(Node* node, int val) {
        if (node == NULL)
            return false;
        if (node->data == val)
            return true;
        else if (val < node->data)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BST() { root = NULL; }

    void insert(int val) { root = insert(root, val); }

    bool search(int val) { return search(root, val); }

    void display() { inorder(root); cout << endl; }
};

int main() {
    BST tree;

    //Insert vals
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(2);

    cout << "Initial BST (inorder): ";
    tree.display();

    int value;
    cout << "Enter a value to search: ";
    cin >> value;

    if (tree.search(value))
        cout << "Value " << value << " found in BST." << endl;
    else {
        cout << "Value " << value << " not found. Inserting into BST..." << endl;
        tree.insert(value);
    }

    cout << "Updated BST (inorder): ";
    tree.display();

    return 0;
}
