//Part I

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size() , profit = 0;
        
        int mini = prices[0];
        for(int i=1; i<n;i++){
            profit = max(profit , prices[i]-mini);
            mini = min(mini , prices[i]);
        }
        return profit;
    }
};




//part 2
int solve(vector<int>& prices , int index , int buy , vector<vector<int>> &dp){
        if(index >= prices.size())
            return 0;

        if(dp[index][buy] !=-1)
            return dp[index][buy];

        int profit = 0;
        if(buy){
            int bought = -prices[index] + solve(prices , index+1 , 0 , dp);
            int ignored = 0 + solve(prices , index+1 , 1 , dp);

            profit = max(bought , ignored);
        }
        else{
            int sold = prices[index] + solve(prices , index+1, 1 , dp);
            int ignored = 0 + solve(prices , index+1, 0 , dp);

            profit = max(sold , ignored);
        }
        return dp[index][buy] =profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n , vector<int>(2,-1));
        return solve(prices , 0 , 1 , dp);
    }


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        
        for(int index = n-1;index>=0;index--){
            for(int buy = 0 ; buy<=1;buy++){
                int profit = 0;
                if(buy){
                    int bought = -prices[index] + dp[index+1][0];
                    int ignored = 0 + dp[index+1][1];

                    profit = max(bought , ignored);
                }
                else{
                    int sold = prices[index] + dp[index+1][1];
                    int ignored = 0 + dp[index+1][0];

                    profit = max(sold , ignored);
                }
                dp[index][buy] =profit;
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(2,0), next(2,0);
        
        for(int index = n-1;index>=0;index--){
            for(int buy = 0 ; buy<=1;buy++){
                int profit = 0;
                if(buy){
                    int bought = -prices[index] + next[0];
                    int ignored = 0 + next[1];

                    profit = max(bought , ignored);
                }
                else{
                    int sold = prices[index] + next[1];
                    int ignored = 0 + next[0];

                    profit = max(sold , ignored);
                }
                curr[buy] =profit;
            }
            next = curr;
        }
        return next[1];
    }



    //Part III
    int solve(vector<int>& prices , int index , int buy ,  int limit){
        if(index == prices.size())
            return 0;
        if(limit == 0)
            return 0;

        int profit = 0;
        if(buy){
            int bought = -prices[index] + solve(prices , index+1 , 0 , limit);
            int ignored = 0 + solve(prices , index+1 , 1,limit);
            profit = max(bought , ignored);
        }
        else{
            int sold = +prices[index] + solve(prices , index+1 , 1 , limit-1);
            int ignored = 0 + solve(prices , index+1 , 0,limit);
            profit = max(sold , ignored);
        }
        return profit ;
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices , 0 , 1 , 2);
    }




    int solve(vector<int>& prices , int index , int buy ,  int limit, vector<vector<vector<int>>> &dp){
        if(index == prices.size())
            return 0;
        if(limit == 0)
            return 0;

        if(dp[index][buy][limit] !=-1)
            return dp[index][buy][limit];

        int profit = 0;
        if(buy){
            int bought = -prices[index] + solve(prices , index+1 , 0 , limit,dp);
            int ignored = 0 + solve(prices , index+1 , 1,limit,dp);
            profit = max(bought , ignored);
        }
        else{
            int sold = +prices[index] + solve(prices , index+1 , 1 , limit-1,dp);
            int ignored = 0 + solve(prices , index+1 , 0,limit,dp);
            profit = max(sold , ignored);
        }
        return dp[index][buy][limit] = profit ;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(3,-1)));
        return solve(prices , 0 , 1 , 2,dp);
    }



    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 , vector<int>(3,0)));
        
        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int limit = 1;limit<=2;limit++){
                    int profit = 0;
                    if(buy){
                        int bought = -prices[index] + dp[index+1][0][limit];
                        int ignored = 0 + dp[index+1][1][limit];
                        profit = max(bought , ignored);
                    }
                    else{
                        int sold = +prices[index] + dp[index+1][1][limit-1];
                        int ignored = 0 + dp[index+1][0][limit];
                        profit = max(sold , ignored);
                    }
                    dp[index][buy][limit] = profit ;
                }
            }
        }
        return dp[0][1][2];
    }

    class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> curr(2 , vector<int>(3,0)) , next(2 , vector<int>(3,0));
        
        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int limit = 1;limit<=2;limit++){
                    int profit = 0;
                    if(buy){
                        int bought = -prices[index] + next[0][limit];
                        int ignored = 0 + next[1][limit];
                        profit = max(bought , ignored);
                    }
                    else{
                        int sold = +prices[index] + next[1][limit-1];
                        int ignored = 0 + next[0][limit];
                        profit = max(sold , ignored);
                    }
                    curr[buy][limit] = profit ;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
};






//Part IV
int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> curr(2 , vector<int>(k+1,0)) , next(2 , vector<int>(k+1,0));
        
        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int limit = 1;limit<=k;limit++){
                    int profit = 0;
                    if(buy){
                        int bought = -prices[index] + next[0][limit];
                        int ignored = 0 + next[1][limit];
                        profit = max(bought , ignored);
                    }
                    else{
                        int sold = +prices[index] + next[1][limit-1];
                        int ignored = 0 + next[0][limit];
                        profit = max(sold , ignored);
                    }
                    curr[buy][limit] = profit ;
                }
            }
            next = curr;
        }
        return next[1][k];
    }




    int solve(int k, vector<int>& prices , int index , int oper){
        if(index == prices.size())
            return 0;
        if(oper == 2*k)
            return 0;

        if(oper%2 == 0){
            
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(k,prices , 0 , 0);
    }

    // with Transaction fee
    class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2,0) , next(2,0);
    
        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    int bought = -prices[index] + next[0];
                    int ignored = 0+next[1];

                    profit = max(bought , ignored);
                }
                else{
                    int sold = prices[index] - fee + next[1];
                    int ignored = 0+ next[0];

                    profit = max(sold , ignored);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};



//cooldown time of 1 day after selling stock
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        for(int index = n-1; index>=0; index--){
            for(int buy = 0; buy<=1;buy++){
                int profit = 0;
                if(buy){
                    int bought = -prices[index] + dp[index+1][0];
                    int ignored = dp[index+1][1];

                    profit = max(bought , ignored);
                }
                else{
                    int sold = prices[index] + dp[index+2][1];
                    int ignored = dp[index+1][0];

                    profit = max(sold , ignored);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }