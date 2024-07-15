class Solution {
public:
    bool solve(string s, string p , int i, int j){
        if(i<0 && j<0)
            return true;
        
        if(i>=0 && j<0)
            return false;

        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k] != '*')
                    return false;
            }
            return true;
        }

        if(s[i]==p[j] || p[j] == '?')
            return solve(s,p,i-1,j-1);
        
        else if(p[j] == '*')
            return solve(s,p,i,j-1) || solve(s,p , i-1,j);
        else
            return false;
        
    }
    bool isMatch(string s, string p) {
        return solve(s,p , s.length()-1 ,p.length()-1);
    }
};

class Solution {
public:
    bool solve(string s, string p , int i, int j, vector<vector<int>> &dp){
        if(i<0 && j<0)
            return true;
        
        if(i>=0 && j<0)
            return false;

        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k] != '*')
                    return false;
            }
            return true;
        }

        if(dp[i][j] !=-1)
            return dp[i][j] ;

        if(s[i]==p[j] || p[j] == '?')
            return dp[i][j] = solve(s,p,i-1,j-1 ,dp);
        
        else if(p[j] == '*')
            return dp[i][j] = solve(s,p,i,j-1 , dp) || solve(s,p , i-1,j , dp);
        else
            return dp[i][j] = false;
        
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() , vector<int>(p.length() , -1));
        return solve(s,p , s.length()-1 ,p.length()-1 , dp);
    }
};



bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length()+1 , vector<bool>(p.length()+1 , false));
        
        dp[0][0] = true;
        for(int j=1;j<= p.length();j++){
            int flag = true;
            for(int k=0;k<j;k++){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i = 1;i<=s.length();i++){
            for(int j=1;j<=p.length();j++){
                bool ans;
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    ans = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    ans = dp[i-1][j] || dp[i][j-1];
                else
                    ans = false;
                
                dp[i][j] = ans;
            }
        }
        return dp[s.length()][p.length()];
        
    }



    class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> curr(p.length()+1 , false) , prev(p.length()+1 , false);
        
        prev[0] = true;
        for(int j=1;j<= p.length();j++){
            int flag = true;
            for(int k=0;k<j;k++){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i = 1;i<=s.length();i++){
            for(int j=1;j<=p.length();j++){
                bool ans;
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    ans = prev[j-1];
                else if(p[j-1] == '*')
                    ans = prev[j] || curr[j-1];
                else
                    ans = false;
                
                curr[j] = ans;
            }
            prev = curr;
        }
        return prev[p.length()];
        
    }