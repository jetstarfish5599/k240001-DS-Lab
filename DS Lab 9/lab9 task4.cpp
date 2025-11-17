#include <iostream>
using namespace std;

struct Node {
    int key, height;
    Node* left;
    Node* right;
    Node(int k) : key(k), height(1), left(NULL), right(NULL) {}
};

int height(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    else return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key) return rightRotate(root);
    if (balance < -1 && key > root->right->key) return leftRotate(root);
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

//find smalllest k term
Node* kthSmallest(Node* root, int& k) {
    if (!root) return NULL;

    Node* left = kthSmallest(root->left, k);
    if (left) return left;

    if (--k == 0) return root;

    return kthSmallest(root->right, k);
}

// FIND Kth LARGEST
Node* kthLargest(Node* root, int& k) {
    if (!root) return NULL;

    Node* right = kthLargest(root->right, k);
    if (right) return right;

    if (--k == 0) return root;

    return kthLargest(root->left, k);
}

//PRINT HEIGHTS OF LEFT AND RIGHT trees
void printRootHeights(Node* root) {
    cout << "Left subtree height: " << height(root->left) << endl;
    cout << "Right subtree height: " << height(root->right) << endl;
}

int main() {
    Node* root = NULL;
    int elements[] = {50, 30, 70, 20, 40, 60, 80, 55};

    for (int x : elements) root = insert(root, x);

    int k = 3;

    Node* kthSmall = kthSmallest(root, k);
    k = 3;
    Node* kthLarge = kthLargest(root, k);

    cout << "3rd smallest element: " << kthSmall->key << endl;
    cout << "3rd largest element: " << kthLarge->key << endl;

    printRootHeights(root);

    return 0;
}
