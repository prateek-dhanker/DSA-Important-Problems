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



// update(l, r, val) : Add (val + i) to arr[l + i] where, 0 <= i <= r - l.
#include <bits/stdc++.h> 
class NumArray
{
public:

    // Initialize here.
    vector<long long> stree;
    vector<int> arr;
    int n;
    void buildTree(vector<long long> &stree , vector<int> &arr , int index, int s ,int e){
        if(s>e)
            return;
        
        if(s == e){
            stree[index] = arr[s]*1LL;
            return;
        }

        int mid = (s+e)/2;
        buildTree(stree , arr , 2*index ,s,mid);
        buildTree(stree,arr,2*index+1,mid+1,e);

        long long leftVal = stree[2*index] , rightVal = stree[2*index+1];

        stree[index] = leftVal + rightVal;
    }
    NumArray(vector<int> &arr, int n)
    {
        // Write your code here.
        this->arr = arr;
        this->n = n;
        stree.resize(4*n+1);
        buildTree(stree,arr , 1 ,0,n-1);
    }

    // Update operation.
    void updateUtil(int index,int l,int r,int s,int e,int val){
        if(r<s || l>e)
            return;
        
        if(s == e){
            int i = s-l;
            stree[index] += val+i;
            return;
        }

        int mid = (s+e)/2;
        updateUtil(2*index , l,r,s,mid,val);
        updateUtil(2*index+1,l,r,mid+1,e,val);

        int leftVal = stree[2*index] , rightVal = stree[2*index+1];
        stree[index] = leftVal + rightVal;
    }
    void update(int l, int r, int val)
    {
        // Write your code here.
        updateUtil(1,l-1,r-1,0,n-1,val);
    }

    // Return the sum of subarray arr[l..r].
    long long rangeSumUtil(int index,int l,int r,int s,int e){
        //non-overlap
        if(r<s || l>e)
            return 0;
        
        //completeOverlap
        if(s>=l && e<=r)
            return stree[index];
        
        int mid = (s+e)/2;
        long long leftVal = rangeSumUtil(2*index , l , r,s,mid);
        long long rightVal = rangeSumUtil(2*index+1 , l ,r ,mid+1 ,e);

        return leftVal + rightVal;
    }
    long long rangeSum(int l, int r)
    {
        // Write your code here.
        return rangeSumUtil(1,l-1,r-1,0,n-1);
    }
};