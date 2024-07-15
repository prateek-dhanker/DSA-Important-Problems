bool check(vector<int> &curr , vector<int> &base){
        return curr[0]<=base[0] && curr[1]<=base[1] && curr[2]<=base[2];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& c : cuboids){
            sort(c.begin() , c.end());
        }
        sort(cuboids.begin() , cuboids.end());
        
        
        int n = cuboids.size();
        vector<int> dp(n, 0);
        int maxHeight = 0;

        for (int i = 0; i < n; ++i) {
            dp[i] = cuboids[i][2]; // Initialize with the height of the current cuboid
            for (int j = 0; j < i; ++j) {
                if (check(cuboids[j], cuboids[i])) { // Check if j-th cuboid can be below i-th cuboid
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            maxHeight = max(maxHeight, dp[i]);
        }

        return maxHeight;
        
//         for(int curr = n-1;curr>=0 ;curr--){
//             for(int prev = curr-1 ; prev>=-1 ; prev--){
//                 int take = 0;
//                 if(prev == -1 || check(cuboids[curr] , cuboids[prev]))
//                     take = cuboids[curr][2] + next[curr+1];
                
//                 int notTake = next[prev+1];
                
//                 currRow[prev+1] = max(take , notTake);
//             }
//             next = currRow;
//         }
//         return next[0];
        
    }