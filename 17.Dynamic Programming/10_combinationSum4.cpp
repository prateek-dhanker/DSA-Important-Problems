int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += combinationSum4(nums,target - nums[i]);
        }

        return ans;
    }


    int solveMem(vector<int>& nums, int target , vector<int> &dp){
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;

        if(dp[target] != -1)
            return dp[target];

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += solveMem(nums,target - nums[i] , dp);
        }

        return dp[target] = ans;

    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solveMem(nums , target , dp);
    }



    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1; 

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i - num >= 0) {
                    if (dp[i] > LLONG_MAX - dp[i - num]) {
                        dp[i] = 0;
                        break; 
                    }
                    dp[i] += dp[i - num];
                }
            }
        }

        // Ensure the result fits in an int before returning, as the problem guarantees
        if (dp[target] > INT_MAX) {
            return 0; 
        }

        return static_cast<int>(dp[target]);
        }