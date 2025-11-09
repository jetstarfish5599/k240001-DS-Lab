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

	Node* find_min(Node* node){
		while(node && node->left != NULL)
			node = node->left;
		return node;
	}

	Node* delete_node(Node* node, int val){
		if(node == NULL){
			return node;
		}
		if(val < node->data){
			node->left = delete_node(node->left, val);
		}
		else if(val > node->data){
			node->right = delete_node(node->right, val);
		}
		else{
			if(node->left == NULL && node->right == NULL){
				delete node;
				return NULL;
			}
			else if(node->left == NULL){
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if(node->right == NULL){
				Node* temp = node->left;
				delete node;
				return temp;
			}
			else{
				Node* temp = find_min(node->right);
				node->data = temp->data;
				node->right = delete_node(node->right, temp->data);
			}
		}
		return node;
	}

	void inorder(Node* node) const{
		if(node != NULL){
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
	}

	//store inorder traversal in array
	void storeInorder(Node* node, int arr[], int &index){
		if(node == NULL) return;
		storeInorder(node->left, arr, index);
		arr[index++] = node->data;
		storeInorder(node->right, arr, index);
	}

	int countNodes(Node* node){
		if(node == NULL) return 0;
		return 1 + countNodes(node->left) + countNodes(node->right);
	}

	public:
	BST(){
		root = NULL;
	}

	void insert(int val){
		root = insert(root, val);
	}

	void remove(int val){
		root = delete_node(root, val);
	}

	void display(){
		inorder(root);
		cout << endl;
	}

	//find median
	double findMedian(){
		int n = countNodes(root);
		if(n == 0) return 0;

		int *arr = new int[n];
		int index = 0;
		storeInorder(root, arr, index);

		double median;
		if(n % 2 == 1){
			median = arr[n/2];
		}
		else{
			median = (arr[(n/2) - 1] + arr[n/2]) / 2.0;
		}

		delete[] arr;
		return median;
	}
};

int main(){
	BST tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(4);
	tree.insert(2);
	tree.insert(8);
	tree.insert(7);
	tree.insert(9);

	cout << "Inorder traversal: ";
	tree.display();

	cout << "Median of BST = " << tree.findMedian() << endl;

	return 0;
}
