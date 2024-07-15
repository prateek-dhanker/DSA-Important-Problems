int solve(string &text1, string &text2 , int i , int j){
        if(i==text1.length() || j== text2.length())
            return 0;

        if(text1[i] == text2[j])
            return 1 + solve(text1 , text2 , i+1 , j+1);
        
        else
            return max(solve(text1 , text2 , i+1 ,j) , solve(text1 , text2 , i , j+1));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1 , text2 , 0 , 0);
    }


    int solve(string &text1, string &text2 , int i , int j , vector<vector<int>> &dp){
        if(i==text1.length() || j== text2.length())
            return 0;

        if(dp[i][j] !=-1)
            return dp[i][j];

        if(text1[i] == text2[j])
            return dp[i][j] = 1 + solve(text1 , text2 , i+1 , j+1 , dp);
        
        else
            return dp[i][j] = max(solve(text1 , text2 , i+1 ,j , dp) , solve(text1 , text2 , i , j+1 , dp));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() , vector<int>(text2.size() , -1));
        return solve(text1 , text2 , 0 , 0 , dp);
    }


    class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1 , vector<int>(text2.size()+1 , 0));
        
        for(int i=text1.size()-1 ; i>=0;i--){
            for(int j=text2.size()-1; j>=0;j--){
                int ans;
                if(text1[i] == text2[j])
                    ans = 1+dp[i+1][j+1];
                else
                    ans = max(dp[i][j+1] , dp[i+1][j]);
                
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> curr(text2.size()+1 , 0) , next(text2.size()+1 , 0);
        
        for(int i=text1.size()-1 ; i>=0;i--){
            for(int j=text2.size()-1; j>=0;j--){
                int ans;
                if(text1[i] == text2[j])
                    ans = 1+next[j+1];
                else
                    ans = max(curr[j+1] , next[j]);
                
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0]; // next[0]
    }
};