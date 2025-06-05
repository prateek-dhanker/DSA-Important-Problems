#include <bits/stdc++.h> 
using namespace std;

//top-down approach
int multiply(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
    if(i == j)
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mini = 1e9;
    for(int k=i;k<j;k++){
        int ops = arr[i-1]*arr[k]*arr[j] + multiply(arr,i,k,dp) + multiply(arr,k+1,j,dp);

        mini = min(mini,ops);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return multiply(arr,1,N-1,dp);
}

//bottom-up approach
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N,vector<int>(N));
    
    for(int i=1;i<N;i++)
        dp[i][i] = 0;
    
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            int mini = 1e9;
            for(int k=i;k<j;k++){
                int ops = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];

                mini = min(mini,ops);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N-1];
}