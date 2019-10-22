#include<iostream>
using namespace std;

class Node{
    public:
        Node *rightchild;
        int data;
        Node *leftchild;
};

class BinarySearchTree{
    public:
        Node *root;
        BinarySearchTree(){root = NULL;}
        void Insert(Node *p,int key);
        void InOrder(Node *p);
        Node * Search(Node *p,int key);
        Node * Delete(Node *p,int key);
        Node * InPre(Node *p);
        Node * InSucc(Node *p);
        int Height(Node *p);
        
};

void BinarySearchTree::Insert(Node *t, int key){
    Node *r = NULL;
    if(!t){
        Node *p = new Node;
        p->data = key;
        p->rightchild = p->leftchild = NULL;
        root = p;
        return; //root가 첫번째 노드가 되는 경우
    }
    while(t){
        r = t;
        if(t->data < key)
            t = t->rightchild;
        else if(t->data > key)
            t = t->leftchild;
        else
            return; 
            // tail pointer r을 사용하여 현재값을 저장하고 계속 아래로 탐색. 
            // NULL이 되는 순간이 되면, 그 곳이 값을 저장할 위치이다. return으로 while문을
            // 탈출하고 저장된 r값을 사용하여, 새로운 노드 P를 생성하여 r에 있는 값으로 연결하여 노드를 완성.
    }
        Node *p = new Node;
        p->data = key;
        p->rightchild = p->leftchild = NULL;
        if(key < r->data)
            r->leftchild = p;
        else
            r->rightchild = p;
}

void BinarySearchTree::InOrder(Node *p){
    if(p){
        InOrder(p->leftchild);
        cout<<p->data<<" "<<endl;
        InOrder(p->rightchild);
    }
}

Node * BinarySearchTree::Search(Node *p,int key){
    while(p){
        if(p->data == key)
            return p;
        else if(p->data < key)
            p = p->leftchild;
        else
            p = p->rightchild;
    }
    return NULL;
}
int BinarySearchTree::Height(Node *p){
    if(!p) return 0;
        int x = 0;
        int y = 0;
        x = Height(p->leftchild);
        y = Height(p->rightchild);
        return x > y ? x+1 : y+1;
}
Node * BinarySearchTree::InPre(Node *p){
    while(p && p->leftchild)
        p = p->leftchild;
        return p;
}
Node * BinarySearchTree::InSucc(Node *p){
    while(p && p->rightchild)
        p = p->rightchild;
        return p;
}
Node * BinarySearchTree::Delete(Node *p,int key){
    Node *q;
    if(p == NULL)
        return NULL;
    if(p->leftchild == NULL && p->rightchild == NULL){
         if(p == root)
            root = NULL;
        delete p; // left child 와 rightchild가 없으면 삭제; 
        return NULL;
    }
       
    if(key < p->data)
        p->leftchild = Delete(p->leftchild,key);
    else if(key > p->data)
        p->rightchild = Delete(p->rightchild,key);
    else{
        if(Height(p->leftchild) > Height(p->rightchild)){
            q = InPre(p->leftchild);
            p->data = q->data;
            p->leftchild = Delete(p->leftchild,q->data);
        }
        else{
            q = InSucc(p->rightchild);
            p->data = q->data;
            p->rightchild = Delete(p->rightchild,q->data);
        }
    
    }
        return p;
}

int main(void){
    
    BinarySearchTree bst;
    bst.Insert(bst.root,10);
    bst.Insert(bst.root,5);
    bst.Insert(bst.root,20);
    bst.Insert(bst.root,8);
    bst.Insert(bst.root,30);
    bst.Delete(bst.root,30);
    bst.InOrder(bst.root);
    
    cout<<" "<<endl;
    return 0;
}