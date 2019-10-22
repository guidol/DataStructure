#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};
class LinkedList{
    private:
        Node *first,*second,*third;
        
        // for testing Private function.
    public:
        LinkedList(){first=NULL,second=NULL,third=NULL;}
        LinkedList(int A[], int n, int B[], int m);
        ~LinkedList();
        void Display();
        void DisplayforMerge();
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
        void Mergetwolists(Node *p, Node *q);
};
LinkedList::LinkedList(int A[], int n, int B[], int m){
    Node *last,*temp,*last1,*temp1;
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
    
    second = new Node;
    second->data = B[0];
    second->next = NULL;
    last1 = second;
        for(int i=1;i < m; i++){
            temp1 = new Node;
            temp1->data = B[i];
            temp1->next = NULL;
            last1->next = temp1;
            last1 = temp1;
        }
    third = new Node;
}

LinkedList::~LinkedList(){
    Node *p = first;
    while(first){
        first = first->next; 
        delete p;
        p = first;
    }
    Node *p1 = second;
    while(second){
        second = second->next; 
        delete p1;
        p1 = second;
    }
}
void LinkedList::Display(){
    Node *p = first;
    while(p != NULL){
        cout<< p->data<<" ";
        p = p->next;
    }
    cout<<endl;
    Node *p1 = second;
    while(p1 != NULL){
        cout<< p1->data<<" ";
        p1 = p1->next;
    }
    cout<<endl;
}
void LinkedList::DisplayforMerge(){
    Node *p = third;
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
     //LinkedList::CountingNode(first);
     //LinkedList::SumOfLists(first);
    // LinkedList::FindingMax(first);
    // LinkedList::Search(first, 10);
    //LinkedList::Insert(first,8);
    //LinkedList::Delete(first,6);
    //LinkedList::FindingDuplicate(first);
    LinkedList::Mergetwolists(first,second);
}
void LinkedList::Mergetwolists(Node *first, Node *second){
    Node *last;

    if((first->data) < (second->data)){
        last=first;
        first = first->next;
        last->next = NULL;
    }
    else{
        last = third = second;
        second = second->next;
        last->next = NULL;
    }
        

    while(first && second){
        if(first->data < second->data){
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else{
            second->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    } if(first)
        last->next = first;
      else
        last->next = second;
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
    
    int A[]={8,11,15,21,22,24,25,26,27};
    int B[]={10,13,17,19,23,28};
    LinkedList linkl(A,9,B,6);
    
    
    linkl.Display();
    
    linkl.Callfunction();
    linkl.DisplayforMerge();
    return 0;
}
