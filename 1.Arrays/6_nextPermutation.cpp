#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());

        int brindex = -1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                brindex = i;
                break;
            }
        }
        if(brindex == -1){
            reverse(nums.begin() , nums.end());
            return;
        }
        for(int i=nums.size()-1;i>brindex;i--){
            if(nums[i] > nums[brindex]){
                swap(nums[i] , nums[brindex]);
                break;
            }
        }
        reverse(nums.begin()+brindex+1 , nums.end());
    }
};