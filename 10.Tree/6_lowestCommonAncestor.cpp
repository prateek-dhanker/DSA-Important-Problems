class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;

        if(root->val == p->val || root->val == q->val)
            return root;

        TreeNode * leftRet = lowestCommonAncestor(root->left , p ,q);
        TreeNode * rightRet = lowestCommonAncestor(root->right , p , q);

        if(leftRet !=NULL && rightRet != NULL)
            return root;
        if(leftRet ==NULL && rightRet != NULL)
            return rightRet;
        if(leftRet !=NULL && rightRet == NULL)
            return leftRet;
        return NULL;
    }
};