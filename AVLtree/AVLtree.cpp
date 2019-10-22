#include<iostream> 
using namespace std;

class Node{
    public:
        Node *rightchild;
        int data;
        int height;
        Node *leftchild;
};

class BinarySearchTree{
    public:
        Node *root;
        BinarySearchTree(){root = NULL;}
        Node * Insert(Node *p,int key);
        int NodeHeight(Node *p);
        int BalanceFactor(Node *p);
        Node * LLRotation(Node *p);
        Node * LRRotation(Node *p);
        Node * RLRotation(Node *p);
        Node * RRRotation(Node *p);
        
};
Node * BinarySearchTree::LLRotation(Node *p){
    Node * pl = p->leftchild;
    Node *plr = pl->rightchild;
    
    pl->rightchild = p;
    p->leftchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
   // plr->height = NodeHeight(plr); Height of plr is the same as before.
    if(root == p)
        root = pl;
    return pl;
}
Node * BinarySearchTree::LRRotation(Node *p){
    Node *pl = p->leftchild;
    Node *plr = pl->rightchild;
    
    pl->rightchild = plr->leftchild;
    p->leftchild = plr->rightchild;
    
    plr->leftchild = pl;
    plr->rightchild = p;
    
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);
    pl->height = NodeHeight(pl);
    
    if(root == p)
        root = plr;
    return plr;
}
Node * BinarySearchTree::RLRotation(Node *p){
    Node * pr = p->rightchild;
    Node * prl = pr->leftchild;
    
    p->rightchild = prl->leftchild;
    pr->leftchild = prl->rightchild;
    
    prl->leftchild = p;
    prl->rightchild = pr;
    
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);
    
    if(root == p)
        root = prl;
    return prl;
}
Node * BinarySearchTree::RRRotation(Node *p){
    Node * pr = p->rightchild;
    Node * prl = pr->leftchild;
    
    pr->leftchild = p;
    p->rightchild = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    
    if(root == p)
        root =pr;
    return pr;
}

int BinarySearchTree::BalanceFactor(Node *p){
    int heightOfRight,heightOfLeft = 0;
    heightOfLeft = p && p->leftchild ? p->leftchild->height : 0;
    heightOfRight = p && p->rightchild ? p->rightchild->height : 0;
    
    return heightOfLeft - heightOfRight;
}
Node * BinarySearchTree::Insert(Node *p, int key){
    Node *r = NULL;
    Node *t = NULL;
    if(!p){
        t = new Node;
        t->data = key;
        t->height = 1;
        t->rightchild = t->leftchild = NULL;
        root = t;
        return t; //root가 첫번째 노드가 되는 경우
    }
    while(p){
        r = p;
        if(p->data < key)
            p = p->rightchild;
        else if(p->data > key)
            p = p->leftchild;
        else
            return p;
            // tail pointer r을 사용하여 현재값을 저장하고 계속 아래로 탐색. 
            // NULL이 되는 순간이 되면, 그 곳이 값을 저장할 위치이다. return으로 while문을
            // 탈출하고 저장된 r값을 사용하여, 새로운 노드 P를 생성하여 r에 있는 값으로 연결하여 노드를 완성.
    }
        t = new Node;
        t->data = key;
        t->rightchild = t->leftchild = NULL;
        if(key < r->data)
            r->leftchild = t;
        else
            r->rightchild = t;
        p->height = NodeHeight(p);

        if(BalanceFactor(p) ==2 && BalanceFactor(p->leftchild) == -1)
            return LRRotation(p);
        if(BalanceFactor(p) ==2 && BalanceFactor(p->leftchild) == 1)
            return LLRotation(p);
        if(BalanceFactor(p) ==-2 && BalanceFactor(p->leftchild) == 1)
            return RLRotation(p);
       if(BalanceFactor(p) ==-2 && BalanceFactor(p->leftchild) == -1)
            return RRRotation(p);
        return p;
}

int BinarySearchTree::NodeHeight(Node *p){
    int heightOfRight,heightOfLeft = 0;
    heightOfLeft = p && p->leftchild ? p->leftchild->height : 0;
    heightOfRight = p && p->rightchild ? p->rightchild->height : 0;
    
    return heightOfLeft > heightOfRight ? heightOfLeft + 1 : heightOfRight + 1;
}

int main(void){
    
    BinarySearchTree bst;
    bst.Insert(bst.root,50);
    bst.Insert(bst.root,10);
    bst.Insert(bst.root,20);
    
    
   // cout<<" "<<endl;
    return 0;
}
