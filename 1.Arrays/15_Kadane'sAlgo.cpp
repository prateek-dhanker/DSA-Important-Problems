#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        long long ans = arr[0] , curr = arr[0];
        
        for(int i=1;i<arr.size();i++){
            curr = max(arr[i]*1LL , curr+arr[i]);
            
            ans = max(ans , curr);
        }
        return ans;
        
        
    }
};