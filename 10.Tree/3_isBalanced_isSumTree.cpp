class Solution {
public:
    int heightOfBinaryTree(TreeNode *root)
    {
        // Write your code here.

        if(root == NULL){
            return 0;
        }

        int left = heightOfBinaryTree(root->left);
        int right = heightOfBinaryTree(root->right);

        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        bool leftB = isBalanced(root->left);
        bool rightB = isBalanced(root->right);

        bool op3 = abs(heightOfBinaryTree(root->left) - heightOfBinaryTree(root->right)) <=1 ;

        if(leftB && rightB && op3)
            return true;

        return false;

    }
};

//approach2 
class Solution {
public:
    pair<bool,int> fastBalanced(TreeNode* root){
        if(root == NULL)
            return make_pair(true ,0);

        pair<bool ,int> leftPair = fastBalanced(root->left);
        pair<bool ,int> rightPair = fastBalanced(root->right);

        pair<bool , int>ans;
        ans.second = max(leftPair.second , rightPair.second) + 1;

        bool op3 = abs(leftPair.second - rightPair.second) <=1 ;

        if(leftPair.first && rightPair.first && op3)
            ans.first = true;
        else
            ans.first = false;

        return ans;

    }
    bool isBalanced(TreeNode* root) {
        return fastBalanced(root).first;

    }
};
pair<bool,int> isSumTreeFast(TreeNode<int> *root){
    if(root == NULL)
        return make_pair(true ,0);
    
    if(root->left == NULL && root->right ==NULL)
        return make_pair(true , root->val);
    
    pair<bool,int> leftPair = isSumTreeFast(root->left);
    pair<bool,int> rightPair = isSumTreeFast(root->right);

    bool op3 = root->val == (leftPair.second + rightPair.second);

    pair<bool , int> ans;
    ans.second = 2*root->val ;
    if(leftPair.first && rightPair.first && op3)
        ans.first = true;
    else
        ans.first = false;

    return ans;
}