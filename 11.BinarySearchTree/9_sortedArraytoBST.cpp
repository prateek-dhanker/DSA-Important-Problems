class Solution {
public:
    TreeNode* solve(vector<int>& nums , int s , int e){
        if(s>e)
            return NULL;

        int mid = (s+e)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = solve(nums , s ,mid-1);
        root->right = solve( nums , mid+1 , e);
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s=0 , e = nums.size()-1;
        return solve( nums , s , e);
    }
};