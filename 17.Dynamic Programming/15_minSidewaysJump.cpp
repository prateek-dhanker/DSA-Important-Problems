int solverec(vector<int>& obstacles , int currpos , int currlane){
        int n = obstacles.size() - 1;
        if(currpos == n)
            return 0;

        if(obstacles[currpos + 1] != currlane)
            return solverec(obstacles , currpos+1 , currlane);
        else{
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(i != currlane && obstacles[currpos] !=i){
                    ans = min(ans , 1 + solverec(obstacles , currpos , i));
                }
            }
            return ans;
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        return solverec(obstacles , 0 , 2);
    }



    class Solution {
public:
    int solvemem(vector<int>& obstacles , int currpos , int currlane, vector<vector<int> > &dp){
        int n = obstacles.size()-1;
        if(currpos == n)
            return 0;

        if(dp[currlane][currpos] !=-1)
            return dp[currlane][currpos];

        if(obstacles[currpos + 1] != currlane)
            return dp[currlane][currpos] = solvemem(obstacles , currpos+1 , currlane , dp);
        else{
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(i != currlane && obstacles[currpos] !=i){
                    dp[currlane][currpos] = ans = min(ans , 1 + solvemem(obstacles , currpos , i , dp));
                }
            }
            return ans;
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<vector<int> > dp(4 , vector<int>(n+1, -1));
        return solvemem(obstacles , 0 , 2 , dp);
    }
};


int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<vector<int> > dp(4 , vector<int>(n+1, INT_MAX));

        dp[0][n] = dp[1][n] = dp[2][n] = dp[3][n] = 0;

        for(int currpos = n-1; currpos >=0 ;currpos--){
            for(int currlane = 1 ; currlane <=3;currlane++){
                if(obstacles[currpos+1] != currlane)
                    dp[currlane][currpos] = dp[currlane][currpos+1];
                else{
                    for(int i=1;i<=3;i++){
                        if(i!=currlane && obstacles[currpos]!=i)
                            dp[currlane][currpos] = min(dp[currlane][currpos] ,1 + dp[i][currpos+1]);
                    }
                }
            }
        }
        return min(dp[2][0] , min(dp[1][0]+1 , dp[3][0]+1)); 
    }



    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<int> curr(4 , INT_MAX) , next(4 , INT_MAX);

        next[0] = next[1] = next[2] = next[3] = 0;

        for(int currpos = n-1; currpos >=0 ;currpos--){
            for(int currlane = 1 ; currlane <=3;currlane++){
                if(obstacles[currpos+1] != currlane)
                    curr[currlane] = next[currlane];
                else{
                    int ans = INT_MAX;
                    for(int i=1;i<=3;i++){
                        if(i!=currlane && obstacles[currpos]!=i)
                            ans = min(ans ,1 + next[i]);
                    }
                    curr[currlane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2] , min(next[1]+1 , next[3]+1)); 
    }