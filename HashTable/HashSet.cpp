#include<iostream>
#include<vector>

using namespace std;
#define MAX_LEN 100000
class MyHashSet{
    private:
        vector<int> set[MAX_LEN];
        int getIndex(int key);
        int getPosition(int key, int index);
    public:
        MyHashSet(){}
    void add(int key);
    void remove(int key);
    bool contains(int key);
    void disPlay(int key);
};

int MyHashSet::getIndex(int key){
            return key % MAX_LEN;
}

int MyHashSet::getPosition(int key, int index){
            
            for(int i = 0; i < set[index].size(); i++){
                if(set[index][i] == key)
                    return i;
            }
            return -1;
}

void MyHashSet::add(int key){
    int index = getIndex(key);
    int position = getPosition(key, index);
    if(position < 0)
        set[index].push_back(key);
}

void MyHashSet::remove(int key){
    int index = getIndex(key);
    int position = getPosition(key, index);
    if(position >= 0)
        set[index].erase(set[index].begin()+position);
}

bool MyHashSet::contains(int key){
    int index = getIndex(key);
    int position = getPosition(key, index);
    return position >=0;
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
