#include<iostream>
#include<vector>

using namespace std;
#define MAX_LEN 100000
class MyHashMap{
    private:
        vector<pair<int,int>> map[MAX_LEN];
        int getIndex(int key);
        int getPosition(int key, int index);
    public:
        MyHashMap(){}
    void Put(int key, int value);
    void remove(int key);
    int get(int key);
   
};

int MyHashMap::getIndex(int key){
            return key % MAX_LEN;
}

int MyHashMap::getPosition(int key, int index){
    
    for(int i=0; i < map[index].size(); i++){
        if(map[index][i].first == key){
            return i;
        }
    }
    return -1;
}

void MyHashMap::Put(int key,int value){
    int index = getIndex(key);
    int position = getPosition(key, index);
        if(position < 0)
            map[index].push_back(make_pair(key, value));
        else
            map[index][position].second = value;
}

int MyHashMap::get(int key){
    int index = getIndex(key);
    int position = getPosition(key, index);
        if(position < 0)
            return -1;
        else
            return map[index][position].second;
}

void MyHashMap::remove(int key){
    int index = getIndex(key);
    int position = getPosition(key,index);
        if(position >=0 )
            map[index].erase(map[index].begin() + position);
}

int main(){
    
    return 0;
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
