#include <iostream>
#include <stdio/c++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode *>q;
        q.push(root);
        int leftToRight = 1; 

        while(!q.empty()){
            int qsize = q.size();
            vector<int> level(qsize);
            for(int i=0;i<qsize;i++){
                TreeNode * currentNode = q.front();
                q.pop();

                int index;
                if(leftToRight)
                    index = i;
                else
                    index = qsize-i-1;
                
                level[index] = currentNode->val;

                if(currentNode->left)
                    q.push(currentNode->left);
                if(currentNode->right)
                    q.push(currentNode->right);

            }
            ans.push_back(level);
            leftToRight = !(leftToRight);
        }
        return ans;
    }
};
void leftSubTree(TreeNode<int> *root , vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;
    ans.push_back(root->data);
    if(root->left)
        leftSubTree(root->left,ans);
    else
        leftSubTree(root->right,ans);
}
void rightSubTree(TreeNode<int> *root , vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if(root->right)
        rightSubTree(root->right,ans);
    else
        rightSubTree(root->left,ans);
    ans.push_back(root->data);
}
void leafNodes(TreeNode<int> *root , vector<int> &ans){
    if(root!=NULL){
        if(root->left == NULL && root->right == NULL)
            ans.push_back(root->data);
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);

    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    ans.push_back(root->data);
    leftSubTree(root->left , ans);
    leafNodes(root , ans);
    rightSubTree(root->right , ans);
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        
        map<int,map<int,vector<int> > >nodes;
        queue<pair<TreeNode * ,pair<int,int> > > q;
        
        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty()){
            pair<TreeNode * ,pair<int,int> >temp = q.front();
            q.pop();

            TreeNode * node = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            nodes[hd][level].push_back(node->val);

            if(node->left)
                q.push(make_pair(node->left,make_pair(hd-1,level+1))) ;
            if(node->right)
                q.push(make_pair(node->right,make_pair(hd+1,level+1))) ;
        }

        for(auto i : nodes){
            vector<int> verticalLevel;
            for(auto j : i.second) {
                vector<int>& values = j.second;
                sort(values.begin(), values.end()); // Sorting nodes at the same level and hd
                for(int val : values) {
                    verticalLevel.push_back(val);
                }
            }
            ans.push_back(verticalLevel);
        }
        return ans;
    }
};
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    map<int,int> m;
    queue<pair<TreeNode<int> * , int> > q;
    q.push(make_pair(root , 0));

    while(!q.empty()){
        pair<TreeNode<int> * ,int> temp = q.front();
        q.pop();

        TreeNode<int> *node = temp.first;
        int hd = temp.second;

        if(!m[hd])//or if(m.find(hd) == m.end())
            m[hd] = node->data;

        if(node->left)
            q.push(make_pair(node->left , hd-1));
        if(node->right)
            q.push(make_pair(node->right , hd+1));
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}
void leftView(BinaryTreeNode<int>* root , vector<int> &ans , int level){
    if(root == NULL)
        return ;
    
    if(ans.size() == level)
        ans.push_back(root->data);

    leftView(root->left , ans , level+1);
    leftView(root->right , ans , level+1);   
}

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;
    leftView(root , ans , 0);
    return ans;
}
vector<int> bottomView(TreeNode<int> * root){
    // Write your code here.
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    map<int,int> m;
    queue<pair<TreeNode<int> * , int> > q;
    q.push(make_pair(root , 0));

    while(!q.empty()){
        pair<TreeNode<int> * ,int> temp = q.front();
        q.pop();

        TreeNode<int> *node = temp.first;
        int hd = temp.second;

        m[hd] = node->data;

        if(node->left)
            q.push(make_pair(node->left , hd-1));
        if(node->right)
            q.push(make_pair(node->right , hd+1));
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        map<int,int> nodes;
        queue<pair<TreeNode *,int> > q;

        q.push(make_pair(root , 0));

        while(!q.empty()){
            pair<TreeNode *,int> temp  = q.front();
            q.pop();

            TreeNode * currentNode = temp.first;
            int level = temp.second;

            nodes[level] = currentNode->val;

            if(currentNode->left)
                q.push(make_pair(currentNode->left , level+1));
            if(currentNode->right)
                q.push(make_pair(currentNode->right , level+1));
        }
        for(auto i:nodes){
            ans.push_back(i.second);
        }
        return ans;
    }
};