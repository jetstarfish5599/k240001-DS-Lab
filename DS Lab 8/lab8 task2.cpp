#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//combatant struct
struct Combatant {
    string name;
    int hp;
    int attack;

    Combatant() {}
    Combatant(string n, int h, int a) {
        name = n;
        hp = h;
        attack = a;
    }
};

//node struct
struct Node {
    Combatant data;
    Node* left;
    Node* right;

    Node(Combatant c) {
        data = c;
        left = right = nullptr;
    }
};

//bst class
class BST {
private:
    Node* root;

    //rec insertion
    Node* insert(Node* node, Combatant c) {
        if (node == nullptr)
            return new Node(c);

        if (c.name < node->data.name)
            node->left = insert(node->left, c);
        else if (c.name > node->data.name)
            node->right = insert(node->right, c);

        return node;
    }

    //find min node
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    //rec delete
    Node* deleteNode(Node* node, string name) {
        if (node == nullptr)
            return node;

        if (name < node->data.name)
            node->left = deleteNode(node->left, name);
        else if (name > node->data.name)
            node->right = deleteNode(node->right, name);
        else {
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
                node->right = deleteNode(node->right, temp->data.name);
            }
        }
        return node;
    }

    //inorder traversal
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data.name << "(" << node->data.hp << "hp) ";
            inorder(node->right);
        }
    }

    //rec destroy
    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    //constructor
    BST() {
        root = nullptr;
    }

    //destructor
    ~BST() {
        destroy(root);
    }

    //insert combatant
    void insert(Combatant c) {
        root = insert(root, c);
    }

    //remove by name
    void remove(string name) {
        root = deleteNode(root, name);
    }

    //print bst
    void display() {
        inorder(root);
        cout << endl;
    }

    //get front combatant
    Combatant* getFront() {
        Node* temp = findMin(root);
        if (temp == nullptr)
            return nullptr;
        return &temp->data;
    }

    //update hp
    void updHP(string name, int newHP) {
        Node* node = root;
        while (node != nullptr) {
            if (name == node->data.name) {
                node->data.hp = newHP;
                return;
            } else if (name < node->data.name)
                node = node->left;
            else
                node = node->right;
        }
    }

    //check if empty
    bool isEmpty() {
        return root == nullptr;
    }
};

//main game
int main() {
    BST playerTeam;
    BST enemyTeam;

    //initialize heroes
    playerTeam.insert(Combatant("hero1", 30, 6));
    playerTeam.insert(Combatant("hero2", 25, 7));
    playerTeam.insert(Combatant("hero3", 28, 5));
    playerTeam.insert(Combatant("hero4", 22, 8));
    playerTeam.insert(Combatant("hero5", 26, 6));

    //initialize enemies
    enemyTeam.insert(Combatant("enemyA", 27, 5));
    enemyTeam.insert(Combatant("enemyB", 24, 6));
    enemyTeam.insert(Combatant("enemyC", 29, 5));
    enemyTeam.insert(Combatant("enemyD", 20, 7));
    enemyTeam.insert(Combatant("enemyE", 26, 6));

    cout << "<-----BattleQuest: BST Arena------>\n";
    int round = 1;

    while (!playerTeam.isEmpty() && !enemyTeam.isEmpty()) {
        cout << "\n   Round " << round << " ---\n";
        cout << "Heroes: ";
        playerTeam.display();
        cout << "Enemies: ";
        enemyTeam.display();

        Combatant* hero = playerTeam.getFront();
        Combatant* enemy = enemyTeam.getFront();

        if (hero == nullptr || enemy == nullptr)
            break;

        cout << "\nPlayer's turn:\n";
        int heroDamage = hero->attack + (rand() % 5);
        cout << hero->name << " attacks" << enemy->name << " for " << heroDamage << "damage!\n";
        int newEnemyHP = enemy->hp - heroDamage;
        enemyTeam.updHP(enemy->name, newEnemyHP);
        if (newEnemyHP <= 0) {
            cout << enemy->name << "defeated!\n";
            enemyTeam.remove(enemy->name);
        }

        if (enemyTeam.isEmpty()) break;

        cout << "\nEnemy's turn:\n";
        hero = playerTeam.getFront();
        enemy = enemyTeam.getFront();
        int enemyDamage = enemy->attack + (rand() % 5);
        cout << enemy->name << "attacks " << hero->name << "for " << enemyDamage << "damage!\n";
        int newHeroHP = hero->hp - enemyDamage;
        playerTeam.updHP(hero->name, newHeroHP);
        if (newHeroHP <= 0) {
            cout << hero->name << "defeated!\n";
            playerTeam.remove(hero->name);
        }

        round++;
    }

    if (playerTeam.isEmpty())
        cout << "\nYou lost! Enemies win!\n";
    else
        cout << "\nAll enemies defeated! Heroes win!\n";

    return 0;
}
