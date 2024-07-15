TreeNode* inorderSucc(TreeNode* root){
        TreeNode* curr = root->right;
        while(curr->left)
            curr = curr->left;

        return curr;
    }
    TreeNode* deleteBSTNode(TreeNode* root, int k){
        if(root == NULL)
            return NULL;
        
        if(root->val == k){
            //c1
            if(root->left == NULL && root->right == NULL)
                return NULL;

            //c2
            if(root->left != NULL && root->right == NULL){
                return root->left;
            }
            if(root->left == NULL && root->right != NULL){
                return root->right;
            }

            else{
                TreeNode* temp = inorderSucc(root);
                root->val = temp->val;
                root->right = deleteBSTNode(root->right , temp->val);
                return root;
            }

            //c3
        }
        else if(root->val > k){
            root->left = deleteBSTNode(root->left , k);
            return root;
        }
        else{
            root->right = deleteBSTNode(root->right , k);
            return root;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteBSTNode(root , key);
    }