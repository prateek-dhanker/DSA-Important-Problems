#include <bits/stdc++.h>
using namespace std;

//inorder
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traverse;

        while(root){
            if(root->left == NULL){
                traverse.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode *pred = root->left;
                while(pred->right && pred->right != root)
                    pred = pred->right;
                
                if(pred->right == NULL){
                    pred->right = root;
                    root = root->left;
                }
                else{
                    pred->right = NULL;
                    traverse.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return traverse;
    }


//preorder
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traverse;

        while(root){
            if(root->left == NULL){
                traverse.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode *pred = root->left;
                while(pred->right && pred->right != root)
                    pred = pred->right;
                
                if(pred->right == NULL){
                    pred->right = root;
                    
                    traverse.push_back(root->val);
                    root = root->left;
                }
                else{
                    pred->right = NULL;
                    root = root->right;
                }
            }
        }
        return traverse;
    }
};