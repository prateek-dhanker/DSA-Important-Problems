#include <bits/stdc++.h> 

//approach 1 recursive O(2^n)
int fibonacciNumber(int n){
    // Write your code here.
    if(n<=1){
        return n;
    }
    return fibonacciNumber(n-1) + fibonacciNumber(n-2);
}

//DP approach1
int solve(int n , vector<int> &dist){
    if(n<=1)
        return n;

    if(dist[n] != -1)
        return dist[n];

    dist[n] = solve(n-1 , dist) + solve(n-2 , dist);
    return dist[n];
}

int main()
{
       int n;
       cin>>n;

    // Write your code here.
    vector<int> dist(n+1 , -1);
    int ans =  solve(n , dist);

   cout<<ans;
}

int main()
{
       int n;
       cin>>n;

    // Write your code here.
    vector<int> dp(n+1 , -1);
    dp[0] =0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

   cout<<dp[n];
}

int main()
{
       int n;
       cin>>n;

    int prev2 =0;
    int prev1 = 1;

    for(int i=2;i<=n;i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

   cout<<prev1;
}