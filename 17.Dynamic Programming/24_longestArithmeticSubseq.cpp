int solve(vector<int>& nums , int index , int j,int diff){
        if(index < 0 || j<0)
            return 0;

        if(nums[index] - nums[j] == diff)
            return 1 + solve(nums , j , j-1 , diff);
        
        else
            return solve(nums , index , j-1 , diff);
        
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i=0; i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int diff = nums[j] - nums[i];
                ans = max(ans , 2+solve(nums , i , i-1 ,diff));
            }
        }
        return ans;
    }




    int solve(vector<int>& nums , int index , int j,int diff ,vector<unordered_map<int , int>> &dp){
        if(index < 0 || j<0)
            return 0;
    
        if(dp[index].count(diff))
            return dp[index][diff];

        if(nums[index] - nums[j] == diff)
            return 1 + solve(nums , j , j-1 , diff ,dp);
        
        else
            return dp[index][diff] = solve(nums , index , j-1 , diff ,dp);
        
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<unordered_map<int , int>> dp(n+1);//diff , len
        for(int i=0; i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int diff = nums[j] - nums[i];
                ans = max(ans , 2+solve(nums , i , i-1 ,diff , dp));
            }
        }
        return ans;
    }




    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<unordered_map<int , int>> dp(n+1);//diff , len
        for(int i=1; i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j];
                int cnt= 1; 
                if(dp[j].count(diff))
                    cnt = dp[j][diff];
                
                dp[i][diff] = 1+cnt;
                ans = max(ans , dp[i][diff]);
            }
        }
        return ans;
    }




    // Longest arithmetic Subsequence with given diffffff
    class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int , int> dp;
        int ans = 0;

        for(int index=0;index<arr.size();index++){
            dp[arr[index]] = 1 + dp[arr[index]-difference];
            ans = max(dp[arr[index]] , ans);
        }
        return ans;
    }
};
