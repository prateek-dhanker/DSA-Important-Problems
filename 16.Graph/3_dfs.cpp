#include <bits/stdc++.h>
using namespace std;

#include<map>
#include<list>

void dfs(int node,int V, unordered_map<int , list<int> > &adjList, vector<int> &component, unordered_map<int, bool> &visited){
    visited[node] = true;
    component.push_back(node);

    for(int i:adjList[node]){
        if(!visited[i])
            dfs(i,V,adjList,component,visited);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int , list<int> > adjList;
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for(int i=0;i<E;i++){
        int u = edges[i][0] , v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=0; i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,V,adjList,component ,visited );
            ans.push_back(component);
        }
    }
    return ans;

}