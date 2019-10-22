#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};
class Stack{
    private:
        Node *top;
    public:
        Stack(){top = NULL;}
        //Stack(){temp = new Node; top = new Node; top->data = -1;}
        void Push(int x);
        void Pop();
        void Display();
        int CountingNode(Node *p);
        //int Peek(int index);
        //int StackTop();
};
void Stack::Push(int x){
    Node *t = new Node;
    if(t == NULL)
        cout<<"Stack is Overflow"<<endl;
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}
void Stack::Pop(){
    
Node *p = top;
    int backup=-1;
    if(top == NULL){
        cout<<"Stack is empty"<<" "<<endl;
    }
    else{            
            backup = p->data;
            Node *t = p;
            p = p->next;
            
            delete t;    
        }
        
}
void Stack::Display(){
    Node *p = top;
    for(int i=0; i < CountingNode(top); i++){
        cout<<p->data<<" "<<endl;
        p = p->next;
    }
}
int Stack::CountingNode(Node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    //cout<<"Count of Node : " <<count<<" ";
    return count;
    
}
int main(){
    
    Stack stk;
    stk.Push(5);
    stk.Push(4);
    stk.Push(3);
    stk.Push(2);
    stk.Push(1);

    stk.Display();
    stk.Pop();
    stk.Pop();
    stk.Display();

    return 0;
}