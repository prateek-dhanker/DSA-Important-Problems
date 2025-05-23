int solve(vector<int>& nums1, vector<int>& nums2 , int index , int swapped){
        if(index >= nums1.size())
            return 0;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swapped)
            swap(prev1 , prev2);

        int ans = INT_MAX;
        //noswap
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1 , nums2 , index+1 , 0);

        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans , 1 + solve(nums1 , nums2 , index+1 , 1));

        return ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin() , -1);
        nums2.insert(nums2.begin() , -1);
        return solve(nums1 , nums2 , 1 , 0);
    }



    class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2 , int index , int swapped , vector<vector<int>> &dp){
        if(index >= nums1.size())
            return 0;

        if(dp[index][swapped] != -1)
            return dp[index][swapped];
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swapped)
            swap(prev1 , prev2);

        int ans = INT_MAX;
        //noswap
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1 , nums2 , index+1 , 0 , dp);

        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans , 1 + solve(nums1 , nums2 , index+1 , 1 ,dp));

        return dp[index][swapped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin() , -1);
        nums2.insert(nums2.begin() , -1);
        int n = nums1.size(); 
        vector<vector<int>> dp(n+1 , vector<int>(2,-1));
        return solve(nums1 , nums2 , 1 , 0 , dp);
    }
};


int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin() , -1);
        nums2.insert(nums2.begin() , -1);
        int n = nums1.size(); 
        vector<vector<int>> dp(n+1 , vector<int>(2,0));

        for(int index =n-1 ; index>=1;index--){
            for(int swapped= 1;swapped >=0 ; swapped--){
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swapped)
                    swap(prev1 , prev2);

                int ans = INT_MAX;
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index+1][0];
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans , 1 + dp[index+1][1]);

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }


    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin() , -1);
        nums2.insert(nums2.begin() , -1);
        int n = nums1.size(); 
        int swapvar = 0,nonSwapvar = 0,currSwapvar = 0,currNonSwapvar = 0;

        for(int index =n-1 ; index>=1;index--){
            for(int swapped= 1;swapped >=0 ; swapped--){
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swapped)
                    swap(prev1 , prev2);

                int ans = INT_MAX;
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = nonSwapvar;
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans , 1 + swapvar);

                if(swapped)
                    currSwapvar = ans;
                else
                    currNonSwapvar = ans;
            }
            swapvar = currSwapvar;
            nonSwapvar = currNonSwapvar;
        }
        return nonSwapvar;
    }