#include <iostream>
#include <string>
#include <cstdlib> //rand()
using namespace std;


//Student class
class Student {
public:
    string name;
    int roll;
    float score;

    Student() {}
    Student(string n, int r, float s) {
        name = n;
        roll = r;
        score = s;
    }

    void display() const {
        cout << "Name: " << name << ", Roll: " << roll << ", Score: " << score << endl;
    }
};


//BST node struct
struct Node {
    Student data;
    Node* left;
    Node* right;

    Node(Student s) {
        data = s;
        left = right = nullptr;
    }
};


//BST Class
class BST {
private:
    Node* root;

    //insert by name
    Node* insert(Node* node, const Student& s) {
        if (node == nullptr)
            return new Node(s);

        if (s.name < node->data.name)
            node->left = insert(node->left, s);
        else if (s.name > node->data.name)
            node->right = insert(node->right, s);
        //ignore same name
        return node;
    }

    //search by name
    Node* search(Node* node, const string& name) {
        if (node == nullptr)
            return nullptr;
        if (node->data.name == name)
            return node;
        else if (name < node->data.name)
            return search(node->left, name);
        else
            return search(node->right, name);
    }

    //Del score < 10
    Node* deleteLowScorers(Node* node) {
        if (node == nullptr)
            return nullptr;

        node->left = deleteLowScorers(node->left);
        node->right = deleteLowScorers(node->right);

        if (node->data.score < 10) {
            Node* temp;
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            } else if (!node->left) {
                temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                temp = node->left;
                delete node;
                return temp;
            } else {
                Node* succ = findMin(node->right);
                node->data = succ->data;
                node->right = deleteNodeByName(node->right, succ->data.name);
            }
        }

        return node;
    }

    //Find min node by name
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    //delete by name
    Node* deleteNodeByName(Node* node, const string& name) {
        if (node == nullptr)
            return nullptr;

        if (name < node->data.name)
            node->left = deleteNodeByName(node->left, name);
        else if (name > node->data.name)
            node->right = deleteNodeByName(node->right, name);
        else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            } else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNodeByName(node->right, temp->data.name);
            }
        }
        return node;
    }

    //inorder traversal
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            node->data.display();
            inorder(node->right);
        }
    }

    //max score student
    void findMaxScore(Node* node, Student& maxStudent) {
        if (node == nullptr)
            return;
        if (node->data.score > maxStudent.score)
            maxStudent = node->data;

        findMaxScore(node->left, maxStudent);
        findMaxScore(node->right, maxStudent);
    }

    //Free space
    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroy(root);
    }

    //public functs
    void insert(const Student& s) {
        root = insert(root, s);
    }

    void searchByName(const string& name) {
        Node* res = search(root, name);
        if (res)
            res->data.display();
        else
            cout << "Student with name \"" << name << "\" not found.\n";
    }

    void deleteLowScorers() {
        root = deleteLowScorers(root);
    }

    void getMaxScoreStudent() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }
        Student maxStudent = root->data;
        findMaxScore(root, maxStudent);
        cout << "\nStudent with Maximum Score:\n";
        maxStudent.display();
    }

    void displayInorder() {
        cout << "\nInorder traversal by name:\n";
        inorder(root);
    }
};

//start main
int main() {
    BST tree;

    //Create students
    Student students[10] = {
        {"masoom", 1, 95},
        {"ahmed", 2, 8},
        {"dev", 3, 88},
        {"salman", 4, 45},
        {"saeed", 5, 99},
        {"saad", 6, 5},
        {"sahil", 7, 72},
        {"zain", 8, 12},
        {"salman", 9, 64}, 
        {"babar", 10, 3}
    };

    cout <<"Inserting 7 random students...\n";
    bool inserted[10] = {false};

    int count = 0;
    while (count < 7) {
        int index = rand() % 10; // random student index
        if (!inserted[index]) {
            tree.insert(students[index]);
            inserted[index] = true;
            count++;
        }
    }

    // Display BST
    tree.displayInorder();

    // Search students
    cout << "\nSearching for 'salman':\n";
    tree.searchByName("salman");

    cout << "\nSearching for 'ali':\n";
    tree.searchByName("ali");

    // Delete low scorers (<10)
    cout << "\nDeleting students with score < 10...\n";
    tree.deleteLowScorers();
    tree.displayInorder();

    // Find student with max score
    tree.getMaxScoreStudent();

    return 0;
}
