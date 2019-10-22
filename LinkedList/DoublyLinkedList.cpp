#include<iostream>
using namespace std;
class Node {
    public:
        Node *prev;
        int data;
        Node *next;
};
class DoublyLinkedList{
    private:
        Node *first;
    public:
        DoublyLinkedList();
        DoublyLinkedList(int A[],int input);
        ~DoublyLinkedList();
        void Display();
        void FunctionCaller();
        void FunctionCaller2();
        void Insert(Node *p,int index, int value);
        int Delete(Node *p,int index);
        void Reverse(Node *p);
};
DoublyLinkedList::DoublyLinkedList(int A[], int input){
    Node *temp,*last;
    first = new Node;
    first->prev = first->next=NULL;
    first->data = A[0];
    last = first;
    for(int i=1; i < input ; i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}
DoublyLinkedList::~DoublyLinkedList(){
    Node *p = first;
    while(first){
        first = first->next; 
        delete p;
        p = first;
    }
}
void DoublyLinkedList::FunctionCaller(){
    DoublyLinkedList::Insert(first,5,13);
    //DoublyLinkedList::Delete(first,5);
}
void DoublyLinkedList::FunctionCaller2(){
    //DoublyLinkedList::Delete(first,5);
    DoublyLinkedList::Reverse(first);
}
void DoublyLinkedList::Insert(Node *p,int index, int value){
    Node *temp = new Node;
    temp->data = value;
    for(int i=0; i < index; i++){
        p = p->next;
    }
    temp->next = p->next;
    temp->prev = p;
    if(p->next)
        p->next->prev = temp;
    p->next = temp;
}
int DoublyLinkedList::Delete(Node *p,int index){
    int x = -1;
    for(int i=0; i < index ; i++)
        p = p->next;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;   
            x = p->data;
            delete p;
    return x;
}
void DoublyLinkedList::Reverse(Node *p){
    Node *temp;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p != NULL && p->next == NULL)
            first = p;
    }
}
void DoublyLinkedList::Display(){
    Node *p = first;
    while(p != NULL){
        cout<< p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    int A[] = {0,1,2,3,4,5,6,7,8,9};
    DoublyLinkedList Dll(A,10);
    
    //Dll.Display();
    Dll.FunctionCaller();
    Dll.Display();
    Dll.FunctionCaller2();
    Dll.Display();
    
    return 0;
}