#include<iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *s;
    public:
        Stack(){size=10;top=-1;s=new int[size];};
        Stack(int capacity){
            this->size = capacity; 
            top = -1;
            s = new int[this->size];
        };
        ~Stack(){ delete [] s;}
        void Push(int x);
        int Pop();
        void Display();
        int isFull();
        int isEmpty();
};
void Stack::Push(int x){
    if(isFull())
        cout<<"Stack Overflow"<<endl;
    else{
        top++;
        s[top]=x;
    }
}
int Stack::Pop(){
    int x=0;
    if(isEmpty())
        cout<<"Stack is Empty"<<endl;
    else{
        x = s[top];
        top--;
    }
    return x;
}
void Stack::Display(){
    for(int i=top; i>=0 ; i--){
        cout<<s[i]<<" "<<endl;
    }
}
int Stack::isFull(){
    return top == size-1;
}
int Stack::isEmpty(){
    return top == -1;
}
int main(){
    Stack stk(5);
    stk.Push(5);
    stk.Push(4);
    stk.Push(3);
    stk.Push(2);
    stk.Push(1);
    stk.Pop();
    stk.Pop();

    stk.Display();

    return 0;
}