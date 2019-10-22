#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};
class LinkedList{
    private:
        Node *first;
        
        // for testing Private function.
    public:
        LinkedList(){first=NULL;}
        LinkedList(int A[], int n);
        ~LinkedList();
        void Display();
        void Rdisplay(Node *p);
        void Callfunction();
        void ReverseLinkedList(Node *p);
        void RecursiveReverseLinkedList(Node *p,Node *q);
        void CountingNode(Node *p);
        void SumOfLists(Node *p);
        void FindingMax(Node *p);
        Node* Search(Node *p, int key);
        void Insert(Node *p,int input);
        void Delete(Node *p,int index);
        void FindingDuplicate(Node *p);
};
LinkedList::LinkedList(int A[], int n){
    Node *last,*temp;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
        for(int i=1;i < n; i++){
            temp = new Node;
            temp->data = A[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
}
LinkedList::~LinkedList(){
    Node *p = first;
    while(first){
        first = first->next; 
        delete p;
        p = first;
    }
}
void LinkedList::Display(){
    Node *p = first;
    while(p != NULL){
        cout<< p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
Node* LinkedList::Search(Node *p, int key){
    while(p != NULL){
        if(p->data == key)
            return p;
        p = p->next;
    }return NULL;   
    cout<<"Node  is : "<<p<<endl;
}
void LinkedList::Rdisplay(Node *p){
    if(p != NULL){
       // Rdisplay(p->next); //->>> Reverse Order; 
        cout<<p->data<<" ";
        Rdisplay(p->next); 
        //cout<<endl;
        
    }   
}
void LinkedList::CountingNode(Node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    cout<<"Count of Node : " <<count<<" ";
    cout<<endl;
}
void LinkedList::Insert(Node *p, int input){
    Node *temp = new Node;
    temp->data = input;
    for(int i=0; i < 4; i++){
        p = p->next;
    }  
    temp->next = p->next;
    p->next = temp;    
}
void LinkedList::Delete(Node *p, int index){
    Node *q = NULL; 
    int x = 0;
    for(int i=0; i < index ; i++){
        q = p;
        p = p->next;
    }
        x = p->data;
        q->next = p->next;
        delete p;
}
void LinkedList::Callfunction(){
     //LinkedList::Rdisplay(first);
    // LinkedList::ReverseLinkedList(first);
    // LinkedList::RecursiveReverseLinkedList(NULL,first);
     LinkedList::CountingNode(first);
     LinkedList::SumOfLists(first);
     LinkedList::FindingMax(first);
    // LinkedList::Search(first, 10);
    //LinkedList::Insert(first,8);
    //LinkedList::Delete(first,6);
    LinkedList::FindingDuplicate(first);
}

void LinkedList::FindingMax(Node *p){
    int min = -3567;
    while(p){
        if(p->data >= min){
            min = p->data;
        }
        p=p->next;
    }
    cout<<"Max is : "<<min<<endl;
}
void LinkedList::ReverseLinkedList(Node *p){
    Node *q = NULL;
    Node *r = NULL;
        while(p != NULL){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }first = q;    
} // using three pointers for Reverse Linkedlist
void LinkedList::RecursiveReverseLinkedList(Node *q,Node *p){
    if(p){
        RecursiveReverseLinkedList(p,p->next);
        p->next = q;
    }
    else
        first = q;
}
void LinkedList::SumOfLists(Node *p){
    int sum=0;
    while(p != NULL){
        sum += p->data;
        p = p->next;
    }
    cout<<"Sum of the Lists is : "<<sum;
    cout<<endl;
}
void LinkedList::FindingDuplicate(Node *p){
    Node *q = p->next;
    while(q){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q-> next;
            delete q;
            q = p->next;
        }
    }
}
int main(){
    
    int A[]={0,1,2,3,3,5,6,6,7};
    LinkedList linkl(A,9);
    linkl.Callfunction();
    linkl.Display();

    return 0;
}
