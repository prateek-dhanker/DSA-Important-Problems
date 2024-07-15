pair<int,int> solve(Node *root){
        if(root == NULL)
            return make_pair(0,0);
        
        pair<int,int> lefty = solve(root->left);
        pair<int,int> righty = solve(root->right);
        
        pair<int,int> ans;
        ans.first = lefty.second + righty.second + root->data;
        ans.second = max(lefty.first , lefty.second) + max(righty.first , righty.second) ;
        
        return ans;
        
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans = solve(root);
        // include exclude
        return max(ans.first , ans.second);
    }