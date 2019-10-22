#include<iostream>
#include<vector>

using namespace std;
#define MAX_LEN 100000
class HashSet{
    private:
        vector<int> set[MAX_LEN]; 
        int getIndex(int key);
        int getPosition(int key, int index);
    public:
        HashSet(){}
    void add(int key);
    void remove(int key);
    bool contains(int key);
};

int HashSet::getIndex(int key){
            return key % MAX_LEN;
}

int HashSet::getPosition(int key, int index){
            
            for(int i = 0; i < set[index].size(); i++){
                if(set[index][i] == key)
                    return i;
            }
            return -1;
}

int main(){

    return 0;
}