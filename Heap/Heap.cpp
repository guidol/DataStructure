#include<iostream>
using namespace std;

class Heap{
        
        public:
            void InsertHeap(int h[], int n);
            int DeleteHeap(int h[],int n);
};

void Heap::InsertHeap(int a[], int n){
    int temp;
    int i = n;
    temp = a[i];
        while(i > 1 && temp > a[i/2]){ // temp가 parent가 크면,
            a[i] = a[i/2]; // a[i/2] means parent
            i = i/2;
        }
        a[i] = temp;
}
int Heap::DeleteHeap(int a[], int n){
    int x,i,j,temp,val;
    val = a[1];
    //x = a[n];
    a[1] = a[n];
    a[n] = val;
    i = 1; j = i*2; //j is left child;
    while(j < n-1){
        if(a[j+1] > a[j]) // right child > left child;
            j = j+1;     // move to next location.
        if(a[i] < a[j]){  // parent < left child;
            temp = a[i]; // value of parent <=>  value of left child;
            a[i] = a[j];
            a[j] = temp;
            i = j;       //i move to j's position.
            j = j*2;     // j move to children's position.
        }
        else
            break;
    }
    return val;
}
int main(){
    
    Heap hp;

    int h[8]= {0,10,20,30,25,5,40,35};
           
    for(int i=2; i <= 7 ; i++)
        hp.InsertHeap(h,i);
    for(int i=1; i <=7 ; i++)
        cout<<h[i]<<" ";
    for(int i=7; i >=1 ; i--)   //Heap Sort
        hp.DeleteHeap(h,i);     //Heap Sort;
        cout<<endl;
    for(int i=1; i <=7 ; i++)
        cout<<h[i]<<" "; 
    return 0;
}