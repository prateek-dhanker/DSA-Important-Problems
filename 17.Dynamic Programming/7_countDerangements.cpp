const int MOD = 1e9 + 7;
long long int countDerangements(int n) {
    // Write your code here.

    if(n==1)
        return 0;

    if(n == 2)
        return 1;

    return ((n-1)*((countDerangements(n-1)%MOD) + (countDerangements(n-2)%MOD)))%MOD;
}


#include <vector>
const int MOD = 1e9 + 7;
long long int solveMem(int n , vector<long long int> &dp){
    if(n==1)
        return 0;

    if(n == 2)
        return 1;

    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n] =  ((n-1)*((solveMem(n-1 , dp)%MOD) + (solveMem(n-2 , dp)%MOD)))%MOD;

}
long long int countDerangements(int n) {
    // Write your code here.
    vector<long long int> dp(n+1,-1);

    return solveMem(n , dp);
}

long long int countDerangements(int n) {
    // Write your code here.
    vector<long long int> dp(n+1,0);

    dp[1] = 0;
    dp[2] = 1;

    for(int i=3;i<=n;i++){
        dp[i] = ((i-1) * (dp[i-1] + dp[i-2]))%MOD;
    }
    return dp[n];
}

long long int countDerangements(int n) {
    // Write your code here.
    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i=3;i<=n;i++){
        int ans = ((i-1) * (prev1+prev2))%MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}