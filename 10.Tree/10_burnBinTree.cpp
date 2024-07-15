TreeNode* fillMap(TreeNode* root, int start , map<TreeNode * , TreeNode *> &parent){
        parent[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *res = NULL;
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();

            if(node->val == start)
                res = node;

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int infectTree(TreeNode* node ,  map<TreeNode * , TreeNode *> &parent){
        map<TreeNode * , bool> infected;
        queue<TreeNode * >q;

        int time = 0;

        q.push(node);
        infected[node] = true;

        while(!q.empty()){
            int qsize = q.size();
            int flag =0;
            for(int i=0 ;i<qsize;i++){
                TreeNode * current = q.front();
                q.pop();

                if(current->left && !infected[current->left]){
                    infected[current->left] = true;
                    q.push(current->left); 
                    flag = 1;
                }
                if(current->right && !infected[current->right]){
                    infected[current->right] = true;
                    q.push(current->right); 
                    flag = 1;
                }
                
                if(parent[current] && !infected[parent[current]]){
                    infected[parent[current]] = true;
                    q.push(parent[current]); 
                    flag = 1;
                }
            }
            if(flag)
                time++;

        }
        return time;

    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode * , TreeNode *>parent;
        TreeNode * target = fillMap(root , start , parent);

        return infectTree(target , parent);
    }