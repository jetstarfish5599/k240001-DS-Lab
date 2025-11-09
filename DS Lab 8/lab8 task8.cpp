#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val){
		data = val;
		left = right = NULL;
	}
};

class BST {
	Node* root;

	Node* insert(Node* node, int val){
		if(node == NULL){
			return new Node(val);
		}
		if(val < node->data){
			node->left = insert(node->left, val);
		}
		else if(val > node->data){
			node->right = insert(node->right, val);
		}
		return node;
	}

	void inorder(Node* node){
		if(node != NULL){
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
	}

	//count nodes in range [a,b]
	int countRange(Node* node, int a, int b){
		if(node == NULL)
			return 0;

		if(node->data >= a && node->data <= b)
			return 1 + countRange(node->left, a, b) + countRange(node->right, a, b);

		else if(node->data < a)
			return countRange(node->right, a, b);

		else
			return countRange(node->left, a, b);
	}

	public:
	BST(){
		root = NULL;
	}

	void insert(int val){
		root = insert(root, val);
	}

	void display(){
		inorder(root);
		cout << endl;
	}

	int countInRange(int a, int b){
		return countRange(root, a, b);
	}
};

int main(){
	BST tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(50);
	tree.insert(1);
	tree.insert(40);
	tree.insert(100);

	cout << "Inorder traversal: ";
	tree.display();

	int a = 5, b = 45;
	cout << "Range [" << a << ", " << b << "]" << endl;
	cout << "Nodes in range = " << tree.countInRange(a, b) << endl;

	return 0;
}
