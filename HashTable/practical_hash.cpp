#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
	unordered_map<int, int> hashmap;// init hashmap
	hashmap.insert(make_pair(0, 0));//insert keys.
	hashmap.insert(make_pair(2, 3));

	hashmap[1] = 1;//insert serperately with key and value.
	hashmap[1] = 2; // update value.
	
	cout<<"the value of key 1 is:"<<hashmap[1]<<endl;
	//get the specific value.

	hashmap.erase(2); // delete the key.

	if(hashmap.count(2) <= 0){
		cout<<"the key 2 was not in the hashmap"<<endl;
	}

	cout<<"the size of hashmap is :"<<hashmap.size()<<endl;
	//get the size of hashmap.

	for(auto it = hashmap.begin(); it != hashmap.end(); it++){
		cout<<"("<<it->first<<","<<it->second<<")"<<endl;
	}// iterate the whole hashmap.
	cout<<"are in the hashmap"<<endl;

	hashmap.clear();//clear the hashmap.

	if(hashmap.empty())
		cout<<"the hashmap is empty"<<endl;

	return 0;
}
