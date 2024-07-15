class Solution{
  public:
    void inorder(Node* root , vector<int> &v){
        if(root == NULL)
            return ;
            
        inorder(root->left , v);
        v.push_back(root->data);
        inorder(root->right , v);
    }
    Node* convert(Node* root , int &i , vector<int> &v){
        if(root==NULL)
            return NULL;
            
        root->left = convert(root->left , i , v);
        root->right = convert(root->right , i , v);
        root->data = v[i];
        i++;
        
        return root;
    }
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        vector<int> v;
        inorder(root , v);
        int i=0;
        
        root = convert(root , i , v);
        
    }    
};