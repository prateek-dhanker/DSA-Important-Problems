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

//Doubly-LL implementation
class Node{
public:
    int key, val;
    Node *prev, *next;

    Node(int key, int val){
        this->val = val;
        this->key = key;
        this->next = this->prev = NULL;
    }
};
class LRUCache {
public:
    int capacity;
    Node *head, *tail;
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        
        Node* node = m[key];
        //remove node
        node->prev->next = node->next;
        node->next->prev = node->prev;
        //add after head
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;

        return node->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            //remove node
            node->prev->next = node->next;
            node->next->prev = node->prev;
            //add after head
            node->prev = head;
            node->next = head->next;
            head->next->prev = node;
            head->next = node;

            //update val and return
            node->val = value;
            return;
        }
        if(m.size() == capacity){
            // remove the least recently used node
            Node *delNode = tail->prev;

            delNode->prev->next = tail;
            tail->prev = delNode->prev;

            m.erase(delNode->key);
        }

        Node* newNode = new Node(key,value);

        //add after head
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;

        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */