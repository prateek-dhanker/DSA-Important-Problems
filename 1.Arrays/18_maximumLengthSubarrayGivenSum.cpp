#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int arr[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int,int> map;
        map[0] = -1;
        int len =0;
        
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += arr[i];
            
            if(map.find(sum-K) != map.end())
                len = max(len , i-map[sum-K]);
            
            if(map.find(sum) == map.end())
                map[sum] =i;    //update with sum of total appearance of "sum" when need to find "no of subarrays with given sum"
        }
        
        return len;
} 

//subarray of sum k
int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = 1;

        int sum = 0 , cnt = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            if(map.find(sum-k) != map.end()){
                cnt += map[sum-k];
            }

            map[sum]++;
        }
        return cnt;
    }