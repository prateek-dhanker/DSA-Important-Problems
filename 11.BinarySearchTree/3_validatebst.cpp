class Solution {
public:
    bool solve(TreeNode* root , int min , int max ,int &flag){
        if(root == NULL)
            return true;
        
        if( flag && ((root->val == INT_MIN && min == INT_MIN) || (root->val == INT_MAX && max == INT_MAX))){
            flag = 0;
             bool left = solve(root->left , min , root->val,flag);
            bool right = solve(root->right , root->val , max,flag);

            return left && right;
        }

        if((root->val > min && root->val < max)){
            bool left = solve(root->left , min , root->val,flag);
            bool right = solve(root->right , root->val , max,flag);

            return left && right;
        }
        else return false;
    }
    void inorderTraversal(TreeNode* root , vector<int> &v){
        if(root == NULL)
            return ;

        inorderTraversal(root->left , v);

        v.push_back(root->val);

        inorderTraversal(root->right , v);
    }
    bool isSort(vector<int> v){
        for(int i = 0 ;i<v.size()-1;i++){
            if(v[i] >= v[i+1])
                return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        // int flag = 1;
        // return solve(root , INT_MIN , INT_MAX , flag);
        vector<int> v;
        inorderTraversal(root , v);
        return isSort(v);
    }
};