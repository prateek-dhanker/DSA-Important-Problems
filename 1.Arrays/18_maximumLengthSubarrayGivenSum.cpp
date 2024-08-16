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