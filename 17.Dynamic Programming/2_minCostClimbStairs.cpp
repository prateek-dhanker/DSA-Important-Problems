int climbStairs(int n) {
        vector<int> dp(n+1 , 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }








int solve(int k , vector<int> &cost){
    if(k == 0 || k== 1)
        return cost[k];

    return cost[k] + min(solve(k-1 , cost) , solve(k-2 , cost));
}
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    return min(solve(n-1 , cost) , solve(n-2 , cost));
}


int solve2(int k , vector<int> &cost , vector<int> &dp){
        if(k == 0 || k== 1)
            return cost[k];

        if(dp[k] != -1)
            return dp[k];

        return dp[k] = cost[k] + min(solve2(k-1 , cost , dp) , solve2(k-2 , cost , dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1 , -1);
        return min(solve2(n-1 , cost , dp) , solve2(n-2 , cost , dp));
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1 , -1);
        
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2 ; i<n;i++)
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);

        return min(dp[n-1], dp[n-2]);
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1 , -1);
        
        int prev1 = cost[0];
        int prev2 = cost[1];

        for(int i=2 ; i<n;i++){

            int curr = cost[i] + min(prev1 , prev2);
            prev1 = prev2;
            prev2 = curr;

        }
        return min(prev1 , prev2);
    }