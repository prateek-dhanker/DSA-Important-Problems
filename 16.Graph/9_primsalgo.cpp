#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int , list<pair<int , int> > > adjList;
    for(int i=0;i<g.size();i++){
        int u = g[i].first.first , v = g[i].first.second , w = g[i].second;

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});       
    }

    vector<bool> mst(n+1 , false);
    vector<int> parent(n+1 , -1) , key(n+1, INT_MAX);

    int source = 1;
    key[source] = 0;

    for(int i=0; i< n-1;i++){
        int mini = INT_MAX;
        int u;

        for(int j = 1 ; j<=n ; j++){
            
            if(mst[j] == false && key[j]<mini){
                mini = key[j];
                u=j;
            }
        }
        mst[u] = true;

        for(auto neighbour : adjList[u]){
            int neighbourNode = neighbour.first , edgeweight = neighbour.second;

            if(!mst[neighbourNode] && edgeweight < key[neighbourNode]){
                parent[neighbourNode] = u;
                key[neighbourNode] = edgeweight;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    
    for(int i=2 ; i<=n ; i++){
        ans.push_back({{i,parent[i]} , key[i]});
    }
    return ans;

}
