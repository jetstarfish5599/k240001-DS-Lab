#include <iostream>
using namespace std;

//struct BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BST class
class BST {
private:
    Node* root;

    //Rec insertion
    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);

        return node;
    }

    //Rec search
    bool search(Node* node, int val) {
        if (node == nullptr)
            return false;
        if (node->data == val)
            return true;
        else if (val < node->data)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    //Find min node
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    //Recursive del
    Node* deleteNode(Node* node, int val) {
        if (node == nullptr)
            return node;

        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        } else {
            //Node found: handle all cases
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    //Recursive traversals
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    //Recursively free memory
    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    //Constructor
    BST() : root(nullptr) {}

    //Destructor
    ~BST() {
        destroy(root);
    }

    //Public functions
    void insert(int val) {
        root = insert(root, val);
    }

    void remove(int val) {
        root = deleteNode(root, val);
    }

    bool search(int val) {
        return search(root, val);
    }

    void inorder() {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }

    void preorder() {
        cout << "Preorder traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder traversal: ";
        postorder(root);
        cout << endl;
    }
};


//Main

int main() {
    BST tree;

    //insertion
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "\nTraversals after insertion:\n";
    tree.inorder();
    tree.preorder();
    tree.postorder();

    //seearch
    cout << "\nSearching for 4: " << (tree.search(4) ? "Found" : "Not Found") << endl;
    cout << "Searching for 10: " << (tree.search(10) ? "Found" : "Not Found") << endl;

    //deletion
    cout << "\nDeleting 2\n";
    tree.remove(2);
    tree.inorder();

    cout << "\nDeleting 3\n";
    tree.remove(3);
    tree.inorder();

    cout << "\nDeleting 5\n";
    tree.remove(5);
    tree.inorder();

    cout << endl;
    return 0;
}
