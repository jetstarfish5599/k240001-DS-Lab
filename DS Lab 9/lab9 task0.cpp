/*First convert the BST to a sorted doubly linked list using inorder (left = prev, right = next).
Then convert the list to a balanced AVL tree by picking the middle node as root, 
left half as left subtree, and right half as right subtree.
This mimics AVL rotations automatically without writing rotate functions.
x, y, t2 correspond to:
x = left child,y = pivot/root,t2 = subtree moved for new creation
The middle node is returned as root because it balances both sides.
Entire process is O(n) and height-balanced like real AVL, but simpler, no insertion needed.*/
//convert BST to sorted DLL (inorder)
void bstToDLL(Node* node, Node*& head, Node*& prev) {
    if (!node) return;
    bstToDLL(node->left, head, prev);
    if (prev == NULL) {
        head = node;       //1st head
    } else {
        prev->right = node; 
        node->left = prev;  
    }
    prev = node;           //move prev forward
    bstToDLL(node->right, head, prev);
}

//count nodes in DLL starting from head
int countList(Node* head) {
    int c = 0;
    Node* t = head;
    while (t) { c++; t = t->right; }
    return c;
}

//build balanced tree in dll, head is moved
Node* sortedListToBST(int n, Node*& head) {
    if (n <= 0 || head == NULL) return NULL;

    //left subtree
    Node* left = sortedListToBST(n/2, head);

    // head now points to left root
    Node* root = head;

    //separate left links
    root->left = left;

    //move head to next
    head = head->right;

    //right subtree with remaining nodes
    root->right = sortedListToBST(n - n/2 - 1, head);

    //update height
    int lh = root->left ? root->left->height : 0;
    int rh = root->right ? root->right->height : 0;
    root->height = 1 + (lh > rh ? lh : rh);

    // ensure shape of tree
    return root;
}

//main conversion 
Node* convertBSTtoAVL(Node* bstRoot) {
    if (bstRoot == NULL) return NULL;

    // 1) convert BST to DLL
    Node* head = NULL;
    Node* prev = NULL;
    bstToDLL(bstRoot, head, prev);

    // 2) count nodes in DLL
    int n = countList(head);

    // 3) build balanced BST from DLL (consumes first n nodes, moves head)
    Node* curHead = head;
    Node* avlRoot = sortedListToBST(n, curHead);

    return avlRoot;
}
