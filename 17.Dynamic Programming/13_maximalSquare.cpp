int solve(vector<vector<char>>& matrix , int i , int j , int &maxi){
        if(i >= matrix.size() || j >= matrix[0].size())
            return 0;

        int right = solve(matrix , i , j+1 , maxi);
        int down = solve(matrix , i+1 , j , maxi);
        int dig = solve(matrix , i+1 ,j+1 , maxi);

        if(matrix[i][j] == '1'){
            int ans = 1+min(right , min(down , dig));
            maxi = max(maxi , ans);
            return ans;
        }
        else
            return 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        solve(matrix , 0 , 0 ,maxi);
        return maxi*maxi;
    }



int solve(vector<vector<char>>& matrix , int i , int j , int &maxi , vector<vector<int>> &dp){
        if(i >= matrix.size() || j >= matrix[0].size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = solve(matrix , i , j+1 , maxi, dp);
        int down = solve(matrix , i+1 , j , maxi, dp);
        int dig = solve(matrix , i+1 ,j+1 , maxi, dp);

        if(matrix[i][j] == '1'){
            int ans = 1+min(right , min(down , dig));
            maxi = max(maxi , ans);
            return dp[i][j] = ans;
        }
        else
            return dp[i][j] = 0;
    }


        int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n= matrix.size();
        int m= matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=n-1 ; i>=0 ; i--){
            for(int j=m-1;j>=0;j--){
                int right = dp[i][j+1];
                int down = dp[i+1][j];
                int dig = dp[i+1][j+1];
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1+min(right , min(down , dig));
                    maxi = max(maxi , dp[i][j]);
                }
                else
                    dp[i][j] =0;
            }
        }
        return maxi*maxi;        
    }
};

//space optimasation
//1 Love babbar
//2 Change int he given matrix SC = O(n)