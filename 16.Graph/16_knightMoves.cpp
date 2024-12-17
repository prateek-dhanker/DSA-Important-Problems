#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
{
    // Code here
    int tx = TargetPos[0] , ty = TargetPos[1];
    
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{KnightPos[0],KnightPos[1]}});
    
    vector<vector<int>> moves = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    vector<vector<bool>> vis(n+1,vector<bool>(n+1,false));
    vis[KnightPos[0]][KnightPos[1]] = true;
    
    while(q.size()){
        auto x = q.front();
        q.pop();
        
        int currx = x.second.first , curry = x.second.second;
        int currMoves = x.first;
        
        if(currx == tx && curry == ty)
            return currMoves;
            
        
        for(auto move : moves){
            int newx = currx + move[0] , newy = curry + move[1];
            
            if(newx>0 && newy>0 && newx<=n && newy<=n && !vis[newx][newy]){
                vis[newx][newy] = true;
                q.push({currMoves+1,{newx,newy}});
            }
        }
        
        
        
    }
    
    return -1;
    
}