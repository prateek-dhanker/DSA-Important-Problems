#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
class Solution {
    public:
        Node* merge(Node* root1,Node* root2){
            Node* dummy = new Node(-1);
            
            Node* temp = dummy;
            while(root1 && root2){
                if(root1->data<root2->data){
                    temp->bottom = root1;
                    temp = root1;
                    root1 = root1->bottom;
                }
                else{
                    temp->bottom = root2;
                    temp = root2;
                    root2 = root2->bottom;
                }
                
                temp->next = NULL;
            }
            
            if(root1)
                temp->bottom = root1;
            else
                temp->bottom = root2;
            
            return dummy->bottom;
        }
        Node *flatten(Node *root)
        {
            // Your code here
            if(root==NULL || root->next == NULL)
                return root;
            
            Node *mergedHead = flatten(root->next);
            return merge(root,mergedHead);
        }
    };