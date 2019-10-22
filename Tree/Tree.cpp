#include<iostream>
#include"QueueCPP.h"
using namespace std;

class Tree{
    public:
        Node *root;
        Tree(){root = NULL;}
        void CreateTree();
        void PreOrder(Node *p);
        void PostOrder(Node *p);
        void InOrder(Node *p);
        void LevelOrder(Node *p);
       // int Height(Node *root);
};

void Tree::CreateTree(){
        Node *p,*t;
        int x;
        Queue q(100);
        cout<<"Enter Root Value"<<endl;
        cin>> x;
        root = new Node;
        root->data = x;
        root->leftchild = root->rightchild = NULL;
        q.enqueue(root);

        while(!q.isEmpty()){
            p = q.dequeue();
            cout<<"Enter the Left Child of "<<p->data<<" "<<endl;
            cin>>x;
            if(x != -1){
                t = new Node;
                t->data = x;
                t->leftchild = t->rightchild = NULL;
                p->leftchild = t;
                q.enqueue(t);
            }
            cout<<"Enter the Right Child of "<<p->data<<" "<<endl;
            cin>>x;
            if(x != -1){
                t = new Node;
                t->data = x;
                t->leftchild = t->rightchild = NULL;
                p->rightchild = t;
                q.enqueue(t);
            }

        }
}
void Tree::PreOrder(Node* p){
    if(p){
        cout<<p->data<<" "<<endl;
        PreOrder(p->leftchild);
        PreOrder(p->rightchild);
    }
}
void Tree::PostOrder(Node *p){
    if(p){
        PostOrder(p->leftchild);
        PostOrder(p->rightchild);
        cout<<p->data<<" "<<endl;
    }
}
void Tree::InOrder(Node *p){
    if(p){
        InOrder(p->leftchild);
        cout<<p->data<<" "<<endl;
        InOrder(p->rightchild);
    }
}
void Tree::LevelOrder(Node* p){
    
    Queue q(100);
    cout<<p->data<<endl;
    q.enqueue(p);
    while(!q.isEmpty()){
       p = q.dequeue();
        if(p->leftchild){
            cout<<p->leftchild->data<<endl;
            q.enqueue(p->leftchild);
        }
        if(p->rightchild){
            cout<<p->rightchild->data<<endl;
            q.enqueue(p->rightchild);
        }
    }
}
// void Tree::Height(Node* p){
//     //make it later
// }
int main(){
    Tree t;
    t.CreateTree();
    cout<<"Preorder "<<endl;;
    t.PreOrder(t.root);
    cout<<endl;
    cout<<"Inorder "<<endl;
    t.InOrder(t.root);
    cout<<endl<<endl;
    cout<<"PostOrder "<<endl;
    t.PostOrder(t.root);
    cout<<endl<<endl;
    cout<<"LevelOrder "<<endl;
    t.LevelOrder(t.root);
    cout<<endl<<endl;

    return 0;
}