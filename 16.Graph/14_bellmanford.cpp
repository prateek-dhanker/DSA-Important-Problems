#include <bits/stdc++.h>
using namespace std;


vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1 , 1e8);
    dist[src] = 0;

    for(int i=0; i<n-1; i++){
        for(int j = 0;j<m;j++){
            int u = edges[j][0] , v = edges[j][1] , w = edges[j][2];

            if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    // check for -ve edges if asked for   


    return dist;
}