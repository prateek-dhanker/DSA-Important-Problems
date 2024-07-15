#include <bits/stdc++.h>
using namespace std;  

void dfs(int node , int parent , vector<int> &disc , vector<int> &low , unordered_map<int , bool> &visited,int &timer , vector<vector<int> > &ans,unordered_map<int , list<int> > &adjList){
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto nbr : adjList[node]){
        if(nbr == parent)
            continue;

        if(!visited[nbr]){
            dfs(nbr , node , disc , low , visited , timer , ans , adjList);
            low[node] = min(low[node] , low[nbr]);

            if(low[nbr] > disc[node]){
                vector<int> tmp;
                tmp.push_back(node);
                tmp.push_back(nbr);
                ans.push_back(tmp);
            }
        }
        else{
            low[node] = min(low[node] , disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int , list<int> > adjList;
    for(int i=0;i<e;i++){
        int u=edges[i][0] , v= edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    unordered_map<int , bool> visited;
    vector<vector<int>> ans;
    int timer = 0;

    for(int i=0;i<v ;i++){
        if(!visited[i])
            dfs( i , -1 , disc , low , visited , timer , ans , adjList);
    }
    return ans;
}