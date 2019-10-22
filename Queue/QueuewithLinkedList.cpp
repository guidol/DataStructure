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
        void DeQueue();
        void Display();
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

void Queue::DeQueue(){
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
    //return x;
}

void Queue::Display(){
    Node *p = front;
    while(p){
        cout<<p->data<<""<<endl;
        p = p->next;
    } 
}

int main(){

    Queue que;
    que.EnQueue(1);
    que.EnQueue(2);
    que.EnQueue(3);
    que.EnQueue(4);
    que.EnQueue(5);

    que.Display();
    cout<<"The End of Enqueue"<<endl;
    que.DeQueue();
    que.DeQueue();
    que.Display();

    return 0;
}