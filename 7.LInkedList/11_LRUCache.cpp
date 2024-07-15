#include <bits/stdc++.h>
using namespace std;


class LRUCache {
    int capacity , size;
    list<int> l;
    unordered_map<int,int> keyval;
    unordered_map<int,list<int>::iterator> address;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(keyval.find(key) == keyval.end())
            return -1;
        
        l.erase(address[key]);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        return keyval[key];
    }
    
    void put(int key, int value) {
        if(keyval.find(key) != keyval.end()){
            l.erase(address[key]);
            address.erase(key);
            size--;
        }
        if(size == capacity){
            int last = l.back();
            l.pop_back();
            address.erase(last);
            keyval.erase(last);
            size--;
        }

        keyval[key] = value;
        
        l.push_front(key);
        address[key] = l.begin();
        size++;
    }
};