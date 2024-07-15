#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countNodes(struct Node* tree){
        if(tree == NULL)
            return 0;
            
        int left = countNodes(tree->left);
        int right = countNodes(tree->right);
        
        return left + right+1;
    }
    bool isCBT(struct Node* tree, int i ,int n){
        if(tree == NULL)
            return true;
            
        if(i > n)
            return false;
        
        return isCBT(tree->left , 2*i , n) &&isCBT(tree->right , 2*i+1 , n);
        
    }
    bool isMaxOrder(struct Node* tree){
        if(tree->left == NULL && tree->right == NULL)
            return true;
        else if(tree->right == NULL)
            return tree->data > tree->left->data;
        else
            return tree->data > tree->left->data && tree->data > tree->right->data && isMaxOrder(tree->left) && isMaxOrder(tree->right);
    }
    bool isHeap(struct Node* tree) {
        // code here
        int n = countNodes(tree);
        return isCBT(tree , 1 ,n) && isMaxOrder(tree);
    }
};