#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	    class TreeNode{
	        public:
	        int data;
	        TreeNode * left , *right;
	        
	        TreeNode(int data){
	            this->data = data;
	            left = right = NULL;
	        }
	        
	    };
	    class cmp{
	        public:
	            bool operator()(TreeNode *a , TreeNode *b){
        	        return a->data > b->data; 
        	    }
	    };

	    void solveTree(TreeNode* root , vector<string> &ans,string temp){
	        if(root->left == NULL && root->right == NULL){
	            ans.push_back(temp);
	            return;
	        }
	        
	        if(root->left)
	            solveTree(root->left , ans , temp+'0');
	        if(root->right)
	            solveTree(root->right , ans , temp+'1');
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<TreeNode* , vector<TreeNode *> , cmp > pq;
		    
		    for(int i=0; i< N;i++)
		        pq.push(new TreeNode(f[i]));
		        
	        while(pq.size() > 1){
	            TreeNode * left = pq.top();
	            pq.pop();
	            
	            TreeNode * right = pq.top();
	            pq.pop();
	            
	            TreeNode * t = new TreeNode(left->data + right->data);
	            
	            t->left = left;
	            t->right = right;
	            
	            pq.push(t);
	        }
	        
	        TreeNode* root = pq.top();
	        
	        vector<string> ans;
	        string temp = "";
	        solveTree(root , ans , temp);
	        return ans;
	        
		}
};