#include <bits/stdc++.h>
using namespace std;

#include <map>
void bfs(int node , int n ,vector<vector<int>> &adj,    unordered_map<int  ,  bool> &visited, vector<int> &ans){
    queue<int>q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int currnode = q.front();
        q.pop();

        ans.push_back(currnode);
        
        for(int i : adj[currnode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.

    unordered_map<int  ,  bool> visited;
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(!visited[i])
            bfs(i,n,adj,visited,ans);
    }

    return ans;
}