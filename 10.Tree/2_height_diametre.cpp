int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.

    if(root == NULL){
        return 0;
    }

    int left = heightOfBinaryTree(root->left);
    int right = heightOfBinaryTree(root->right);

    return max(left,right)+1;
}
int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.
    if(root == NULL)
        return 0;

    int dmLeft = diameterOfBinaryTree(root->left);
    int dmRight = diameterOfBinaryTree(root->right);

    int hmax = heightOfBinaryTree(root->left) + heightOfBinaryTree(root->right)+1 ;//for finding diamter as distance dont add1 but for diamter as nodes add 1

    return max(dmLeft , max(dmRight , hmax));

}
pair<int,int> diameterFast(TreeNode<int> *root){
    if(root == NULL)
        return make_pair(0,0);

    pair<int , int > leftPair = diameterFast(root->left);
    pair<int , int > rightPair = diameterFast(root->right);
    int op3 = leftPair.second + rightPair.second +1;//again same for +1
    pair<int , int> ans;
    ans.second = max(leftPair.second , rightPair.second)+1;
    ans.first = max(leftPair.first , max(rightPair.first ,op3 ));

    return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.
    return diameterFast(root).first;

}