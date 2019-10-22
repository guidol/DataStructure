#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class CircularLinkedList{
    private:
        Node *head;
    public:
        CircularLinkedList(){head = NULL;}
        CircularLinkedList(int A[], int value);
        ~CircularLinkedList();
        void Display();
};
CircularLinkedList::CircularLinkedList(int A[], int value){
    Node *temp,*last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;

    for(int i=1; i < value; i++){
        Node *temp = new Node;
        temp->data=A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    
}
CircularLinkedList::~CircularLinkedList(){
    Node *p = head;
    while(head){
        head=head->next;
        delete p;
        p = head;
    }
}
void CircularLinkedList::Display(){
    Node *p = head;
    do{
        
        cout<<p->data<<" ";
        p = p->next;
    }while(head != p);
    cout<<endl;
}
int main(){
    int A[]={0,1,2,3,4,5,6,7,8};
    CircularLinkedList Circle(A,9);
    Circle.Display();

    return 0;
}