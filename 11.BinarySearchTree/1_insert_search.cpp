#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
    public :
        int val;
        TreeNode *left , *right;

        TreeNode(int data){
            this->val = data;
            this->left = this->right = NULL;
        }
        
};
TreeNode *insert(TreeNode *root , int val){
    if(root == NULL){
        TreeNode * node = new TreeNode(val);
        return node;
    }
    if(root->val > val)
        root->left = insert(root->left , val);
    else
        root->right = insert(root->right , val);

    return root;
}
TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *temp = root;
        while(temp){
            if(temp->val == val)
                return temp;

            else if(temp->val > val)
                temp = temp->left;

            else
                temp = temp->right;
        }
        return NULL;
}
void levelOrderTraversal(TreeNode * root){
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{

        cout<<temp->val<<" ";
        if(temp->left)
            q.push(temp->left);
            
        if(temp->right)
            q.push(temp->right);
        }
    }

}

int main()
{
    int a = 0;
    TreeNode * root = NULL;
    while(a!= -1){
        cout<<"Enter key";
        cin>>a;
        if(a != -1)
            root = insert(root , a);
    }
    levelOrderTraversal(root);

    return 0;
}