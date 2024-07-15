int solve(vector<int>& nums , int curr, int prev){
        if(curr == nums.size())
            return 0;

        int inc = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            inc = 1 + solve(nums , curr+1,curr);
        
        int exc = 0 + solve(nums , curr+1 , prev);

        return max(inc, exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums , 0 ,-1);
    }



    int solve(vector<int>& nums , int curr, int prev , vector<vector<int> > dp){
        if(curr == nums.size())
            return 0;

        if(dp[curr][prev+1] !=-1)
            return dp[curr][prev+1];

        int inc = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            inc = 1 + solve(nums , curr+1,curr ,dp);
        
        int exc = 0 + solve(nums , curr+1 , prev ,dp);

        return dp[curr][prev+1] = max(inc, exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
        return solve(nums , 0 ,-1 ,dp);
    }


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n+1,vector<int>(n+1,0));
        
        for(int curr = n-1;curr>=0 ;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                int inc = 0;
                if(prev == -1 || nums[curr] > nums[prev])
                    inc = 1 + dp[curr+1][curr+1];
                
                int exc = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(inc , exc);
            }
        }
        return dp[0][0];
    }



    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>currArr(n+1,0) , next(n+1,0);
        
        for(int curr = n-1;curr>=0 ;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                int inc = 0;
                if(prev == -1 || nums[curr] > nums[prev])
                    inc = 1 + next[curr+1];
                
                int exc = 0 + next[prev+1];

                currArr[prev+1] = max(inc , exc);
            }
            next = currArr;
        }
        return next[0];
    }


int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            if(ans[ans.size()-1] < nums[i])
                ans.push_back(nums[i]);

            else{
                int index = lower_bound(ans.begin() , ans.end() , nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
        
    }
        