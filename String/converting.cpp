#include<iostream>
using namespace std;

class strings{
    private:
        char *str;
        //int *hash;
    public:
        strings(){
            // str = new char[size];
            // for(int i =0; i<size; i++){
            //     str[i]=0;
            // }
        }
        ~strings(){
            //delete []str;
        }
        void Input(char *c);
        void print();
        void LengthOfString();
        void ChangeCase();
};


void strings::Input(char *cha){
       // stringstr *str = new char[10];
        str = cha; 
}
void strings::print(){
    for(int i=0; i < 10; i++)
        cout<<str[i]; 
}
void strings::LengthOfString(){
     int i=0;
     while(str[i]!='\0')
        i++; 
        cout<<"LengthOfString:" <<i<<" "; 
        cout<<endl;
}
void strings::ChangeCase(){
    char *result;
     for(int i=0; str[i]!='\0';i++){
         if(str[i]>=65 && str[i]<=90)
             str[i]+=32;
         else if(str[i]>='a' && str[i]<=122)
             str[i]-=32;
        
        cout<<str[i]<<",";
      
    }  
}
int main(){
    
    strings s;
    s.Input("WELCOME");
    s.LengthOfString();
    s.ChangeCase();
    //s.print();
    

    return 0;
}