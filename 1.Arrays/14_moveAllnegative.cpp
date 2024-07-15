#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0 , j=0;
        while(i<n && j<n){
            while(i<n && nums[i] !=0)
                i++;
       
            j=i+1;

            while(j<n && nums[j] == 0)
                j++;

            if(j<n)
                swap(nums[i] , nums[j]);
            
        }
    }

//use similar approach for -ve elems