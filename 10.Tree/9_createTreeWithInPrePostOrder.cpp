class Solution {
public:
    void fillMap(map<int,int> &indexMap , vector<int>& inorder){
        for(int i=0 ; i<inorder.size() ; i++){
            indexMap[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder , map<int,int> &indexMap , int & index , int startInorder , int endInorder , int &n){
        if(index >= n || startInorder > endInorder){
            return NULL;
        }
        int pos = indexMap[preorder[index]];
        TreeNode * root = new TreeNode(preorder[index++]);


        root->left = solve(preorder, inorder , indexMap , index , startInorder , pos-1 , n);
        root->right = solve(preorder, inorder , indexMap , index , pos+1 , endInorder , n);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> indexMap;
        fillMap(indexMap , inorder);
        int n = preorder.size();
        int index = 0;

        TreeNode* root = solve(preorder, inorder , indexMap , index , 0 , n-1 , n);
        return root;
    }
};



class Solution {
public:
    void fillMap(map<int,int> &indexMap , vector<int>& inorder){
        for(int i=0 ; i<inorder.size() ; i++){
            indexMap[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder , map<int,int> &indexMap , int & index , int startInorder , int endInorder , int &n){
        if(index < 0 || startInorder > endInorder){
            return NULL;
        }
        int pos = indexMap[postorder[index]];
        TreeNode * root = new TreeNode(postorder[index--]);


        root->right = solve(postorder, inorder , indexMap , index , pos+1 , endInorder , n);
        root->left = solve(postorder, inorder , indexMap , index , startInorder , pos-1 , n);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int,int> indexMap;
        fillMap(indexMap , inorder);
        int n = postorder.size();
        int index = n-1;

        TreeNode* root = solve(postorder, inorder , indexMap , index , 0 , n-1 , n);
        return root;
    }
};
