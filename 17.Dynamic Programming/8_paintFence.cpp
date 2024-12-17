#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int numberOfWays(int n, int k) {
    // Write your code here.

    vector<int> dp(n+1,0);

    if(n==1)
        return k;


    dp[1] = k;
    dp[2] = ( 1LL*k*k ) % MOD;

    for(int i=3; i<=n;i++){
        int same =( 1LL*(k-1)*dp[i-2] ) % MOD;
        int diff = ( 1LL*(k-1)*dp[i-1] ) %MOD;

        dp[i] = ( same+diff )%MOD;

    }
    return dp[n];
}