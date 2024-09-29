
// Following is the class structure of the Node class:
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class cmp{
    public:
        bool operator()(pair<int,Node *> &a , pair<int,Node *> &b){
            return a.first > b.first;
        }
};

Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    priority_queue<pair<int,Node *> , vector<pair<int,Node *>>,cmp> pq;

    for(auto node : listArray)
        pq.push({node->data, node});

    Node dummy(-1);
    Node *temp = &dummy;

    while(pq.size()){
        auto top = pq.top();
        pq.pop();

        temp->next = top.second;
        temp = temp->next;

        if(top.second->next){
            pq.push({top.second->next->data,top.second->next});
        }
    }

    return dummy.next;

}







