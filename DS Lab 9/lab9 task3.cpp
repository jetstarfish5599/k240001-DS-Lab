#include<iostream>
using namespace std;

//Node
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val) {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
    Node* root;

    //height of node
    int get_h(Node* n){
        if(n == NULL) return 0;
        return n->height;
    }

    //update height
    void upd_h(Node* n){
        int lh = get_h(n->left);
        int rh = get_h(n->right);
        n->height = 1 + max(lh, rh);
    }

    //right rotate
    Node* r_rot(Node* y){
        Node* x = y->left;
        Node* t2 = x->right;
        x->right = y;
        y->left = t2;
        upd_h(y);
        upd_h(x);
        return x;
    }

    //left rotate
    Node* l_rot(Node* x){
        Node* y = x->right;
        Node* t2 = y->left;
        y->left = x;
        x->right = t2;
        upd_h(x);
        upd_h(y);
        return y;
    }

    //get balance factor
    int get_b(Node* n){
        return get_h(n->left) - get_h(n->right);
    }

    //insert
    Node* insert(Node* n, int val){
        if(n == NULL) return new Node(val);
        if(val < n->data) n->left = insert(n->left, val);
        else if(val > n->data) n->right = insert(n->right, val);

        upd_h(n);

        int bal = get_b(n);
        if(bal > 1 && val < n->left->data) return r_rot(n);
        if(bal < -1 && val > n->right->data) return l_rot(n);
        if(bal > 1 && val > n->left->data){
            n->left = l_rot(n->left);
            return r_rot(n);
        }
        if(bal < -1 && val < n->right->data){
            n->right = r_rot(n->right);
            return l_rot(n);
        }
        return n;
    }

    //inorder
    void inorder(Node* n){
        if(n != NULL){
            inorder(n->left);
            cout<<n->data<<" ";
            inorder(n->right);
        }
    }

public:
    AVLTree(){
        root = NULL;
    }

    void insert(int val){
        root = insert(root, val);
    }

    void left_rotate_root(){
        root = l_rot(root); //specifically rotate the root
    }

    void display(){
        inorder(root);
        cout<<endl;
    }
};

int main(){
    AVLTree tree;

    //given data
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    //insert new value
    tree.insert(55);

    //left rotation on root
    tree.left_rotate_root();

    //display
    cout<<"Inorder traversal after left rotation on root:"<<endl;
    tree.display();

    return 0;
}
