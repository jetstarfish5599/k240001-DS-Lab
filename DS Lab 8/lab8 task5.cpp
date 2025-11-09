#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
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

class BinaryTree {
    Node* root;

    //check BST for min-max vals
    bool isBSTUtil(Node* node, int minVal, int maxVal) {
        if (node == NULL)
            return true;
        if (node->data <= minVal || node->data >= maxVal)
            return false;
        if (!isBSTUtil(node->left, minVal, node->data))
            return false;
        if (!isBSTUtil(node->right, node->data, maxVal))
            return false;
        return true;
    }

public:
    BinaryTree() { root = NULL; }

    void setRoot(Node* r) { root = r; }

    bool isBST() {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};

//main
int main() {
    //valid BST node
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    BinaryTree tree1;
    tree1.setRoot(root1);
    if (tree1.isBST()) {
        cout << "Tree1 is a BST" << endl;
    } else {
        cout << "Tree1 is not a BST" << endl;
    }

    //not a BST node
    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(7);
    root2->left->left = new Node(2);
    root2->left->right = new Node(6);

    BinaryTree tree2;
    tree2.setRoot(root2);
    if (tree2.isBST()) {
        cout << "Tree2 is a BST" << endl;
    } else {
        cout << "Tree2 is not a BST" << endl;
    }

    return 0;
}
