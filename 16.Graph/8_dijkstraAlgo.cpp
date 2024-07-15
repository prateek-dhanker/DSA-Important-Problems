#include <bits/stdc++.h> 
using namespace std;    

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int , list<pair<int , int> > > adjList;

    for(int i=0 ; i<edges;i++){
        int u = vec[i][0] , v = vec[i][1] , w = vec[i][2];

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    vector<int> dist(vertices);
    for(int i=0 ;i<vertices;i++){
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    set<pair<int,int> > s;//distance , node
    s.insert({0,source});

    while(!s.empty()){
        auto top = *(s.begin());
        s.erase(s.begin());

        int node = top.second , nodedist = top.first;

        for(auto neighbour : adjList[node]){
            if(nodedist + neighbour.second < dist[neighbour.first]){
                auto record = s.find({ dist[neighbour.first] , neighbour.first});

                //record found
                if(record != s.end()){
                    s.erase(record);
                }
                dist[neighbour.first] = nodedist + neighbour.second;
                s.insert({dist[neighbour.first] , neighbour.first});
            }
        }
    }
    return dist;
}
