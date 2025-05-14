#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp(n,false);
        dp[0] = true;

        for(int partition=1;partition<=n;partition++){
            for(string& word:wordDict){
                int start = partition - word.length();

                if(start>=0 && dp[start] && s.substr(start,word.length()) == word)
                    dp[partition] = true; 
            }
        }

        return dp[n];
    }
};