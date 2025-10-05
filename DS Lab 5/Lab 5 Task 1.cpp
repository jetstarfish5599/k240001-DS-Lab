#include <iostream>
using namespace std;

//insert at end  and reverse list
struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(NULL) {}
};

void insertEnd(Node*& head, int v) {
    if (!head) { head = new Node(v); return; }
    insertEnd(head->next, v);
}

void displayRev(Node* head) {
    if (!head) return;
    displayRev(head->next);
    cout << head->data << " ";
}

//insert and delete dlist
struct DNode {
    int data;
    DNode *prev, *next;
    DNode(int v) : data(v), prev(NULL), next(NULL) {}
};

void insertPos(DNode*& head, int pos, int v) {
    DNode* n = new DNode(v);
    if (pos == 1) {
        n->next = head;
        if (head) head->prev = n;
        head = n;
        return;
    }
    DNode* t = head;
    for (int i = 1; t && i < pos - 1; i++) t = t->next;
    if (!t) return;
    n->next = t->next;
    if (t->next) t->next->prev = n;
    t->next = n;
    n->prev = t;
}

void delPos(DNode*& head, int pos) {
    if (!head) return;
    DNode* t = head;
    if (pos == 1) {
        head = head->next;
        if (head) head->prev = NULL;
        delete t;
        return;
    }
    for (int i = 1; t && i < pos; i++) t = t->next;
    if (!t) return;
    if (t->next) t->next->prev = t->prev;
    if (t->prev) t->prev->next = t->next;
    delete t;
}

void show(DNode* h) {
    while (h) { cout << h->data << " "; h = h->next; }
    cout << endl;
}

// Backtracking for 2,0
#define N 4
int maze[N][N] = {
    {1,1,1,1},
    {0,0,0,1},
    {1,1,0,1},
    {1,1,1,1}
};
int sol[N][N];

bool safe(int x,int y){ return x>=0&&y>=0&&x<N&&y<N&&maze[x][y]==1; }

bool solve(int x,int y,int tx,int ty){
    if(x==tx&&y==ty){ sol[x][y]=1; return true; }
    if(safe(x,y)){
        sol[x][y]=1;
        if(solve(x,y+1,tx,ty)) return true;
        if(solve(x+1,y,tx,ty)) return true;
        if(solve(x,y-1,tx,ty)) return true;
        if(solve(x-1,y,tx,ty)) return true;
        sol[x][y]=0;
    }
    return false;
}

void printSol(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cout<<sol[i][j]<<" ";
        cout<<endl;
    }
}

//main
int main() {
    //a
    Node* h=NULL;
    insertEnd(h,10); insertEnd(h,20); insertEnd(h,30);
    cout<<"Reverse List: "; displayRev(h); cout<<endl;

    //b
    DNode* dh=NULL;
    insertPos(dh,1,10); insertPos(dh,2,20); insertPos(dh,3,30);
    cout<<"Doubly After Insert: "; show(dh);
    delPos(dh,2);
    cout<<"After Delete: "; show(dh);

    //c
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) sol[i][j]=0;
    cout<<"Maze Path:"<<endl;
    if(solve(0,0,2,0)) printSol();
    else cout<<"No path"<<endl;
}
