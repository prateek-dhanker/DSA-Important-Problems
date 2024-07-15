#include <bits/stdc++.h> 
int solverec(vector<int> &nums , int i){
    if(i <0)
        return 0;
    if(i == 0)
        return nums[0];

    int include = solverec(nums , i-2) + nums[i];
    int exclude = solverec(nums, i-1);

    return max(include , exclude);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    int n = nums.size();
    return solverec(nums , n-1);
}




int solvedp(vector<int> &nums , int i , vector<int> &dp){
    if(i <0)
        return 0;
    if(i == 0)
        return nums[0];

    if(dp[i] != -1)
        return dp[i];

    int include = solvedp(nums , i-2 , dp) + nums[i];
    int exclude = solvedp(nums, i-1 , dp);

    return dp[i] = max(include , exclude);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    int n = nums.size();
    vector<int> dp(n,-1);
    return solvedp(nums , n-1 , dp);
}



int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    dp[1] = max(dp[0] , nums[1]);
    for(int i=2;i<n;i++){
        int include = dp[i-2] + nums[i];
        int exclude = dp[i-1];

        dp[i] = max(include , exclude);
    }
    return dp[n-1];
}



int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    for(int i=1;i<n;i++){
        int include = prev2 + nums[i];
        int exclude = prev1;

        int ans = max(include , exclude);

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}