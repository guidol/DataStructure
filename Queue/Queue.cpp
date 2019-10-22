#include<iostream>
using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int *q;
    public:
        Queue(){size=10;front=rear=-1;q = new int[size];};
        Queue(int size){front=rear=-1; this->size=size; q =  new int[this->size];};
        void enqueue(int x);
        void dequeue();
        void display();
};
void Queue::enqueue(int x){
    if(rear == size-1)
        cout<<"Queue is Full"<<endl;
    else{
        rear++;
        q[rear] = x;
        //cout<<"rear value is: "<<rear<<endl;
    }
}

void Queue::dequeue(){
    if(front == rear)
        cout<<"Queue is Empty"<<endl;
    else{
        q[front+1];
        front++;
    }
}

void Queue::display(){
    for(int i=front+1; i <= rear; i++){
        cout<<q[i]<<" "<<endl;
        //cout<<"i value : "<<i<<endl;
    }
        
}

int main(){
    
    Queue que(5);
    que.enqueue(10);
    que.enqueue(9);
    que.enqueue(8);
    que.enqueue(7);
    que.enqueue(6);
   
    que.display();
    que.dequeue();
    que.dequeue();

    return 0;
}