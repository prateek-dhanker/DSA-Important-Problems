/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
class info{
    public :
    int mini ;
    int maxi ;
    int size;
    bool isBST;
};

info solve(TreeNode * root , int &maxSize){
    if(root == NULL){
        return {INT_MAX , INT_MIN , 0 , true};
    }
    info left = solve(root->left , maxSize);
    info right = solve(root->right , maxSize);

    info curr;
    curr.mini = min(left.mini , root->data);
    curr.maxi = max(right.maxi , root->data);
    curr.size = right.size + left.size +1;

    if(left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini){
        curr.isBST = true;
        maxSize = max(maxSize , curr.size); 
    }
    else
        curr.isBST = false;

    return curr;
}
int largestBST(TreeNode * root){
    // Write your code here.
    int maxSize = 0;
    return solve(root , maxSize).size;
}