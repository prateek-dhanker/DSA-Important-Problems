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
    void inorder(TreeNode* root , vector<int> &v){
        if(root == NULL)
            return ;

        inorder(root->left , v);
        v.push_back(root->val);
        inorder(root->right , v);
    }
    TreeNode* createBST(vector<int> &v, int s , int e){
        if(s > e)
            return NULL;

        int mid = (s+e)/2;
        TreeNode * newroot = new TreeNode(v[mid]);

        newroot->left = createBST(v , s , mid-1);
        newroot->right = createBST(v , mid+1 ,e);

        return newroot;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root , v);

        int s=0 , e = v.size()-1;
        return createBST(v , s , e);
    }
};