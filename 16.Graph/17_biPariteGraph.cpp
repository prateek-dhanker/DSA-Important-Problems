// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that
//  every edge in the graph connects a node in set A and a node in set B.

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool dfs(vector<vector<int>>& graph,int node,vector<int>& grp){
            for(int nbr:graph[node]){
                if(grp[nbr]==0){
                    grp[nbr] = grp[node]==1 ? 2 : 1;
                    bool bp = dfs(graph,nbr,grp);
                    if(bp)
                        return true;
                }
                else{
                    if(grp[nbr]==grp[node])
                        return true;
                }
            }
            return false;
        }
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
    
            vector<int> grp(n,0);
    
            for(int i=0;i<n;i++){
                if(!grp[i]){
                    grp[i] = 1;
    
                    if(dfs(graph,i,grp))
                        return false;
                }
            }
            return true;
        }
    };