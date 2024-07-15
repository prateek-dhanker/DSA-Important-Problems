int solve(string &word1, string &word2 , int i,int j){
        if(i == word1.length())
            return word2.length()-j;
        if(j == word2.length())
            return word1.length()-i;

        int ans;
        if(word1[i] == word2[j])
            ans = solve(word1 , word2 , i+1,j+1);
        else{
            int insert = 1 + solve(word1 , word2 , i , j+1);
            int del = 1 + solve(word1 , word2 , i+1 , j);
            int replace = 1 + solve(word1 , word2, i+1, j+1);

            ans = min(insert , min(del , replace));
        }

        return ans;
    }
    int minDistance(string word1, string word2) {
        return solve(word1 , word2 , 0 ,0);
    }



    int solve(string &word1, string &word2 , int i,int j , vector<vector<int>> &dp){
        if(i == word1.length())
            return word2.length()-j;
        if(j == word2.length())
            return word1.length()-i;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans;
        if(word1[i] == word2[j])
            ans = solve(word1 , word2 , i+1,j+1 , dp);
        else{
            int insert = 1 + solve(word1 , word2 , i , j+1 , dp);
            int del = 1 + solve(word1 , word2 , i+1 , j , dp);
            int replace = 1 + solve(word1 , word2, i+1, j+1 , dp);

            ans = min(insert , min(del , replace));
        }

        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() , vector<int>(word2.length() , -1));
        return solve(word1 , word2 , 0 ,0 , dp);
    }




    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1 , vector<int>(word2.length()+1 , 0));
        
        for(int j = 0;j<word2.length();j++)
            dp[word1.length()][j] = word2.length()-j;
        for(int i = 0;i<word1.length();i++)
            dp[i][word2.length()] = word1.length()-i;

        for(int i= word1.length()-1;i>=0;i--){
            for(int j=word2.length()-1 ; j>=0 ;j--){
                int ans;
                if(word1[i] == word2[j])
                    ans = dp[i+1][j+1];
                else{
                    int insert = 1+ dp[i][j+1];
                    int del = 1+ dp[i+1][j];
                    int replace = 1+ dp[i+1][j+1];

                    ans = min(insert , min(del , replace));
                }

                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }



    class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.length() == 0)
            return word2.length();
        if(word2.length() == 0)
            return word1.length();
        vector<int> next(word2.length()+1 , 0) , curr(word2.length()+1 , 0);
        
        for(int j = 0;j<word2.length();j++)
            next[j] = word2.length()-j;
            
        for(int i= word1.length()-1;i>=0;i--){
            for(int j=word2.length()-1 ; j>=0 ;j--){

                curr[word2.length()] = word1.length()-i;
                int ans;
                if(word1[i] == word2[j])
                    ans = next[j+1];
                else{
                    int insert = 1+ curr[j+1];
                    int del = 1+ next[j];
                    int replace = 1+ next[j+1];

                    ans = min(insert , min(del , replace));
                }

                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
};

