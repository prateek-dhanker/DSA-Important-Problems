struct pair_hash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;  // Combine the two hash values
        }
    };
    int solve(vector<int>& arr , unordered_map<pair<int,int> , int , pair_hash> &maxi , int start , int end , vector<vector<int>> &dp){
        if(start == end)
            return 0;

        if(dp[start][end] !=-1)
            return dp[start][end];
        
        int ans = INT_MAX;
        for(int k=start; k<end; k++){
            ans = min(ans, maxi[{start,k}]*maxi[{k+1,end}] + solve(arr , maxi , start , k , dp) + solve(arr , maxi , k+1,end , dp));
        }
        return dp[start][end] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        unordered_map <pair<int,int> , int , pair_hash> maxi;

        int n = arr.size();
        for(int i=0;i<n;i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1;j<n;j++){
                maxi[{i,j}] = max(arr[j] , maxi[{i,j-1}]);
            }
        }
        vector<vector<int>> dp(n+1 , vector<int>(n+1,-1));
        return solve(arr , maxi , 0,n-1,dp);
    }