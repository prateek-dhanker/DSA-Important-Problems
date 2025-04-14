#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
    private:
        void insertAtEnd(Node* &head , Node* &tail , int data){
            Node* newNode = new  Node(data);
            if(head){
                tail->next = newNode;
                tail = newNode; 
            }
            else
                head = tail = newNode; 
        }
    public:
        Node* copyRandomList(Node* head) {
            Node* cloneHead = NULL , *cloneTail = NULL , *temp = head;
            while(temp){
                insertAtEnd(cloneHead , cloneTail , temp->val);
                temp = temp->next;
            }
            temp = head;
            Node* cloneTemp = cloneHead;
            map<Node* , Node*>match;
            while(temp){
                match[temp] = cloneTemp;
                temp = temp->next;
                cloneTemp = cloneTemp->next;
            }
            temp = head;
            cloneTemp = cloneHead;
            while(temp){
                cloneTemp->random = match[temp->random];
                temp = temp->next;
                cloneTemp = cloneTemp->next;
            }
            return cloneHead;
        }
    };