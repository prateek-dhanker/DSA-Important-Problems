#include <bits/stdc++.h>
using namespace std;


class NumArray {
public:
    int *segTree;
    int n;
    vector<int> nums;
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        segTree = new int[4*n + 1];
        buildTree(segTree,1 , nums,0,n-1);
    }

    void buildTree(int *segTree ,int index, vector<int> &nums,int s, int e){
        if(s>e)
            return;
        
        if(s==e){
            segTree[index] = nums[s];
            return;
        }
        int mid = (s+e)/2;
        buildTree(segTree , 2*index , nums,s,mid);
        buildTree(segTree, 2*index+1 , nums,mid+1,e);

        segTree[index] = segTree[2*index] + segTree[2*index+1];       

    }
    
    void updateInit(int *segTree,int index,int node , int val,int s,int e){
        if(node<s || node>e)
            return;
        
        if(s==e){
            segTree[index] = val;
            return;
        }
        int mid = (s+e)/2;
        updateInit(segTree , 2*index, node,val,s,mid);
        updateInit(segTree , 2*index+1, node,val,mid+1,e);

        segTree[index] = segTree[2*index] + segTree[2*index+1];
    }

    void update(int index, int val) {
        updateInit(segTree,1,index,val,0,n-1);
    }
    
    int rangeInit(int *segTree , int index , int left,int right , int s, int e){
        if(left>e || right<s)
            return 0;
        
        if(s>=left && e<=right)
            return segTree[index];
        
        int mid = (s+e)/2;
        return rangeInit(segTree,2*index,left,right,s,mid) + rangeInit(segTree,2*index+1,left,right ,mid+1,e);
    }

    int sumRange(int left, int right) {
        return rangeInit(segTree , 1 , left , right , 0 , n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */