int solve(vector<int>& slices , int index , int n, int end){
        if(n == 0 || index > end)
            return 0;

        int inc = slices[index] + solve(slices , index+2 , n-1 , end);
        int exc = 0 + solve(slices , index+1 , n , end);

        return max(inc , exc);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int case1 = solve(slices , 0 , k/3 , k-2);
        int case2 = solve(slices , 1 , k/3 , k-1);

        return max(case1 , case2);
    }



    int solve(vector<int>& slices , int index , int n, int end , vector<vector<int>> &dp){
        if(n == 0 || index > end)
            return 0;

        if(dp[index][n] != -1)
            return dp[index][n];

        int inc = slices[index] + solve(slices , index+2 , n-1 , end , dp);
        int exc = 0 + solve(slices , index+1 , n , end ,dp);

        return dp[index][n] = max(inc , exc);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k+1 , vector<int>(k , -1)) ,dp2(k+1 , vector<int>(k , -1));
        int case1 = solve(slices , 0 , k/3 , k-2 , dp1);
        int case2 = solve(slices , 1 , k/3 , k-1 , dp2);

        return max(case1 , case2);
    }






    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k+2 , vector<int>(k , 0));

        for(int index = k-2 ; index >=0 ;index--){
            for(int n= 1;n<=k/3;n++){
                int inc = slices[index] + dp1[index+2][n-1];
                int exc = dp1[index+1][n];
                
                dp1[index][n] = max(inc , exc);
            }
        }
        int case1 = dp1[0][k/3];

        vector<vector<int>> dp2(k+2 , vector<int>(k , 0));

        for(int index = k-1 ; index >=1 ;index--){
            for(int n= 1;n<=k/3;n++){
                int inc = slices[index] + dp2[index+2][n-1];
                int exc = dp2[index+1][n];
                
                dp2[index][n] = max(inc , exc);
            }
        }
        int case2 = dp2[1][k/3];  


        return max(case1 , case2);
    }



    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<int> curr1(k, 0) ,prev1(k,0) , next1(k,0);

        for(int index = k-2 ; index >=0 ;index--){
            for(int n= 1;n<=k/3;n++){
                int inc = slices[index] + next1[n-1];
                int exc = curr1[n];
                
                prev1[n] = max(inc , exc);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[k/3];

        vector<int> curr2(k, 0) ,prev2(k,0) , next2(k,0);

        for(int index = k-1 ; index >=1 ;index--){
            for(int n= 1;n<=k/3;n++){
                int inc = slices[index] + next2[n-1];
                int exc = curr2[n];
                
                prev2[n] = max(inc , exc);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k/3];


        return max(case1 , case2);
    }