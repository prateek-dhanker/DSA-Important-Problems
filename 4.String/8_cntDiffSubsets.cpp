#include <bits/stdc++.h>
using namespace std;

long long count(string& s){
        int n = s.length();
        
        vector<long long> dp(n+1);
        dp[0] = 1;
        
        vector<int> last(26,-1);
        
        for(int i=0;i<n;i++){
            dp[i+1] = 2*dp[i];
            
            if(last[s[i]-'a']!=-1){
                dp[i+1] -= dp[last[s[i]-'a']];
            }
            last[s[i]-'a'] = i;
        }
        
        return dp[n];
    }