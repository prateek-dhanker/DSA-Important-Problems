#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapify(vector<int>& nums , int i , int heapsize){
        int left = 2*i + 1 , right = 2*i+2 , greatest;

        if(left < heapsize && nums[left]>nums[i]){
            greatest = left;
        }
        else 
            greatest = i;

        if(right < heapsize && nums[right]>nums[greatest])
            greatest = right;

        if(greatest != i){
            swap(nums[greatest] , nums[i]);
            heapify(nums , greatest , heapsize);
        }
    }
    void buildMaxHeap(vector<int>& nums){
        for(int i = nums.size()/2 -1 ; i>=0 ; i--){
            heapify(nums , i , nums.size());
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        buildMaxHeap(nums);
        int heapsize = nums.size();
        for(int i = nums.size()-1 ; i>0 ; i--){
            swap(nums[i] , nums[0]);
            heapsize--;
            heapify(nums , 0 , heapsize);
        }
        return nums;
    }
};