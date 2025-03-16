#include <bits/stdc++.h>
using namespace std;


vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector<int> dist(V,1e8);
    dist[src] = 0;
    
    for(int i=0;i<V-1;i++){
        for(auto edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            
            //relax-edge
            if(dist[u]!=1e8 && dist[v]>dist[u]+w)
                dist[v] = dist[u] + w;
        }
    }
    
    for(auto edge : edges){
        int u = edge[0], v = edge[1], w = edge[2];
        
        //relax-edge
        if(dist[u]!=1e8 && dist[v]>dist[u]+w)
            return {-1};
    }
    
    return dist;
}