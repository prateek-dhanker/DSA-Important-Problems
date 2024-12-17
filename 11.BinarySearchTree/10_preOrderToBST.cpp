Node *preToBst(int pre[], int size,int &index,int maxi,int mini){
        if(index >= size)
            return NULL;
        
        int key = pre[index];
        
        if(key<=mini || key>=maxi)
            return NULL;
                
        index++;
        
        Node* root = newNode(key);
        
        root->left = preToBst(pre , size , index , key ,mini);
        root->right = preToBst(pre , size , index , maxi ,key);
        
        return root;
            
    }
    Node* Bst(int pre[], int size) {
        // code here
        int index = 0;
        return preToBst(pre,size,index,INT_MAX,INT_MIN);
    }