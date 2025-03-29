#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int v = mat.size();
        
        for(int via=0;via<v;via++){
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    if(mat[i][via]==-1 || mat[via][j]==-1)
                        continue;
                    if(mat[i][j]==-1)
                        mat[i][j] = mat[i][via]+mat[via][j];
                    else
                        mat[i][j] = min(mat[i][j] , mat[i][via]+mat[via][j]);
                }
            }
        }
        
    }
    vector<vector<int>> floydWarshall(int n,vector<vector<int>> &adjMatrix){
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n,vector<int>(n,INT_MAX)));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                    dp[0][i][j] = 0;
                else if(adjMatrix[i][j])
                    dp[0][i][j] = adjMatrix[i][j];
            }
        }

        for(int k=1;k<=n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp[k-1][k-1][j]==INT_MAX || dp[k-1][i][k-1]== INT_MAX)
                        dp[k][i][j] = dp[k-1][i][j];
                    else
                        dp[k][i][j] = min(dp[k-1][i][j] , dp[k-1][k-1][j]+dp[k-1][i][k-1]);
                }
            }
        }

        return dp[n];
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMatrix(n,vector<int>(n,0));
        for(auto &edge:edges){
            int u=edge[0] , v=edge[1] ,w=edge[2];
            adjMatrix[u][v] = adjMatrix[v][u] = w;
        }
        vector<vector<int>> minDist = floydWarshall(n,adjMatrix);

        int mini = INT_MAX,minInd = 0;
        for(int node=0;node<n;node++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(minDist[node][j] <= distanceThreshold)
                    cnt++;
            }
            if(cnt<=mini){
                mini = cnt;
                minInd = node;
            }
        }
        return minInd;
    }
};