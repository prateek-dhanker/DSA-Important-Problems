class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;

        if(p==NULL && q!=NULL)
            return false;

        if(p!=NULL && q==NULL)
            return false;

        bool checkLeft = isSameTree(p->left , q->left);
        bool checkRight = isSameTree(p->right , q->right);

        bool checkVal = p->val == q->val;

        if(checkLeft && checkRight && checkVal)
            return true;
        return false;

    }
};