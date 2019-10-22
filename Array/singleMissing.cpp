#include<iostream>
using namespace std;
template<class T>
class Array{
    private:
        T *A;
        T *Hash;
        int size;
        int length;
    public:
    Array(){
        size = 10;
        A = new T[size];
        length = 0;
    }
    Array(int sz){
        size = sz;
        A = new T[sz];
        Hash = new T[21];
        for(int i=0; i < 21; i++){
            Hash[i]=0;
            length = 0;
        }
        
    }
    ~Array(){
        delete []A;
        delete []Hash;
    }
    void Display();
    void Insert(int index, T x);
    T Delete(int index);
    void FindDuplicate();
};
template<class T>
 void Array<T>::Display(){
     for(int i=0; i < length; i++)
        cout<< A[i] << " ";
        cout<<endl;     
 }
 template<class T>
 void Array<T>::Insert(int index, T x){
     //if( index >= 0 && index < length)
     for(int i=length-1 ; i >=index ; i--)
            A[i+1]=A[i];
     A[index] = x;
     length++;
 }
 template<class T>
 T Array<T>::Delete(int index){
     T x = 0;
     if(index >=0 && index < length){
         x = A[index];
         for(int i = index; i < length-1 ; i++)
             A[i] = A[i+1];
         length--;         
     }
     return x;
 }
 template<class T>
 void Array<T>::FindDuplicate(){
     for(int i=0; i<length ; i++){
         Hash[A[i]]++;
         //cout<< A[i];
     }
     for(int i=0; i<=20 ; i++){
        if(Hash[i] > 1){
            cout<< i <<":";
            cout<< Hash[i] << " ";     
        }                 
      }
 }

 int main(){
        Array<int> arr(10);
        arr.Insert(0,3);
        arr.Insert(1,6);
        arr.Insert(2,8);
        arr.Insert(3,8);
        arr.Insert(4,10);
        arr.Insert(5,12);
        arr.Insert(6,15);
        arr.Insert(7,15);
        arr.Insert(8,15);
        arr.Insert(9,20);
        
        arr.Display();
        
        //cout<<arr.Delete(0)<<endl;
        arr.FindDuplicate();
        //arr.Display();
    
    return 0;
 }
