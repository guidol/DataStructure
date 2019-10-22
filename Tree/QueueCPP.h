#ifndef QUEUECPP_H
#define QUEUECPP_H
#endif

#include<iostream>
using namespace std;

//using namespace std;
class Node{
    public:
        Node *leftchild;
        int data;
        Node *rightchild;
};
class Queue{
    private:
        int size;
        int front;
        int rear;
        Node **q;
    public:
        Queue(){size=10;front=rear=-1;q = new Node*[size];};
        Queue(int size){front=rear=-1; this->size=size; q =  new Node*[this->size];};
        void enqueue(Node *x);
        Node* dequeue();
        void display();
        int isEmpty(){return front==rear;}
};
void Queue::enqueue(Node *x){
    if(rear == size-1)
        cout<<"Queue is Full"<<endl;
    else{
        rear++;
        q[rear] = x;
        //cout<<"rear value is: "<<rear<<endl;
    }
}

Node* Queue::dequeue(){
    Node* x =  NULL;
    if(front == rear)
        cout<<"Queue is Empty"<<endl;
    else{
        x = q[front+1];
        front++;
    }
    return x;
}

void Queue::display(){
    for(int i=front+1; i <= rear; i++){
        cout<<q[i]<<" "<<endl;
        //cout<<"i value : "<<i<<endl;
    }

}
