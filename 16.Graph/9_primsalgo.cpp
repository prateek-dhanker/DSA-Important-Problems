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

// ElogE using min_heap
int spanningTree(int V, vector<vector<int>> adj[]){
    // code here ElogE
    vector<bool> vis(V,false);
    vector<vector<int>> mstEdges; //not requires if only need to find wt
    
    int mstWt = 0;
    
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    // wt, node, parent   --parent not req if only need to find to wt
    pq.push({0,0,-1}); 
    
    while(pq.size()){
        auto top = pq.top();
        pq.pop();
    
        int w = top[0], node=top[1], parent=top[2];
        
        if(vis[node])
            continue;
        
        vis[node] = true;
        mstWt += w;
        
        if(parent!=-1)
            mstEdges.push_back({node,parent});
        
        for(auto nbr : adj[node]){
            int nbrNode = nbr[0], edgeWt = nbr[1];
            
            if(!vis[nbrNode])
                pq.push({edgeWt, nbrNode, node});
        }
    }
    
    return mstWt;
}