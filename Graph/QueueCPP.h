#ifndef QUEUECPP_H
#define QUEUECPP_H
#endif

#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node *next;
};

class Queue{
    private:
        Node *front;
        Node *rear;
    public:
        Queue(){front = NULL; rear = NULL;};
        void EnQueue(int x);
        int DeQueue();
        void Display();
        int isEmpty();
};

void Queue::EnQueue(int x){
    Node *temp = new Node;
    if(temp == NULL)
        cout<<"Queue is Full"<<endl;
    else{
        temp->data = x;
        temp->next = NULL;
        if(front == NULL)
            front=rear=temp;
        else
        {
            rear->next = temp;
            rear = temp;
        }
        
    }
}

int Queue::DeQueue(){
    Node *temp;
    int x=-1;
    if(front == NULL)
        cout<<"Queue is Empty"<<endl;
    else{
        x = front->data;
        temp = front;
        front = front->next;
        delete temp;
    }
    return x;
}
int Queue::isEmpty(){
    return front==NULL;
}

void Queue::Display(){
    Node *p = front;
    while(p){
        cout<<p->data<<""<<endl;
        p = p->next;
    } 
}