bool solve(vector<int>& nums , int index, int target){
        if(target == 0)
            return true;
        if(target < 0)
            return false;
        if(index >= nums.size())
            return false;

        int inc = solve(nums , index+1,target-nums[index]);
        int exc = solve(nums , index+1 , target);

        return inc || exc;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num : nums)
            total += num;

        if(total & 1)
            return 0;

        return solve(nums , 0 , total/2);
    }



    bool solve(vector<int>& nums , int index, int target , vector<vector<int>> &dp){
        if(target == 0)
            return true;
        if(target < 0)
            return false;
        if(index >= nums.size())
            return false;

        if(dp[index][target] != -1)
            return dp[index][target];

        int inc = solve(nums , index+1,target-nums[index],dp);
        int exc = solve(nums , index+1 , target,dp);

        return dp[index][target] = inc || exc;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num : nums)
            total += num;

        if(total & 1)
            return 0;

        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(total/2 +1 , -1));
        return solve(nums , 0 , total/2,dp);
    }


    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num : nums)
            total += num;

        if(total & 1)
            return 0;

        int n = nums.size();
        vector<vector<bool>> dp(n+1 , vector<bool>(total/2 +1 , false));
        
        for(int index = 0;index<=n;index++)
            dp[index][0] = true;
        
        for(int index = n-1;index>=0;index--){
            for(int target = 0 ; target <= total/2 ; target++){
                int inc = 0;
                if(target-nums[index] >= 0)
                    inc = dp[index+1][target-nums[index]];
                
                int exc = dp[index+1][target];

                dp[index][target] = inc || exc;
            }
        }
        return dp[0][total/2];
        
    }



    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num : nums)
            total += num;

        if(total & 1)
            return 0;

        int n = nums.size();
        vector<bool> next(total/2 +1 , false) , curr(total/2 +1 , false);
        
        next[0] = curr[0] = true;
        
        for(int index = n-1;index>=0;index--){
            for(int target = 0 ; target <= total/2 ; target++){
                int inc = 0;
                if(target-nums[index] >= 0)
                    inc = next[target-nums[index]];
                
                int exc = next[target];

                curr[target] = inc || exc;
            }
            next = curr;
        }
        return next[total/2];
        
    }