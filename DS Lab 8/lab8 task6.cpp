#include <iostream>
using namespace std;

//Node
struct Node {
    int productID;
    int quantity;
    Node* left;
    Node* right;

    Node(int id, int qty) {
        productID = id;
        quantity = qty;
        left = right = NULL;
    }
};

//BST class for inventory
class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    //Insert new product or update quantity 
    Node* insert(Node* node, int id, int qty) {
        if (node == NULL) {
            return new Node(id, qty);
        }
        if (id < node->productID) {
            node->left = insert(node->left, id, qty);
        } else if (id > node->productID) {
            node->right = insert(node->right, id, qty);
        } else {
            //if alredy there:update
            node->quantity += qty;
        }
        return node;
    }

    void insert(int id, int qty) {
        root = insert(root, id, qty);
    }

    //find by ID
    Node* search(Node* node, int id) {
        if (node == NULL || node->productID == id)
            return node;
        if (id < node->productID)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    Node* search(int id) {
        return search(root, id);
    }

    //Inorder traversal
    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << "ID: " << node->productID << ", Qty: " << node->quantity << endl;
            inorder(node->right);
        }
    }

    void display() {
        inorder(root);
    }

    //Find max product 
    Node* maxQuantity(Node* node) {
        if (node == NULL)
            return NULL;
        Node* leftMax = maxQuantity(node->left);
        Node* rightMax = maxQuantity(node->right);
        Node* maxNode = node;

        if (leftMax != NULL && leftMax->quantity > maxNode->quantity)
            maxNode = leftMax;
        if (rightMax != NULL && rightMax->quantity > maxNode->quantity)
            maxNode = rightMax;

        return maxNode;
    }

    Node* maxQuantity() {
        return maxQuantity(root);
    }
};

//main
int main() {
    BST inventory;

    //Insert products
    inventory.insert(101, 50);
    inventory.insert(102, 20);
    inventory.insert(103, 80);
    inventory.insert(104, 10);
    inventory.insert(102, 15);

    cout << "Inventory List:" << endl;
    inventory.display();

    //search product
    int searchID = 103;
    Node* found = inventory.search(searchID);
    if (found != NULL)
        cout << "\nProduct found: ID " << found->productID << ", Qty " << found->quantity << endl;
    else
        cout << "\nProduct ID " << searchID << " not found." << endl;

    //product with max quantity
    Node* maxProd = inventory.maxQuantity();
    if (maxProd != NULL)
        cout << "\nProduct with max quantity: ID " << maxProd->productID << ", Qty " << maxProd->quantity << endl;

    return 0;
}
