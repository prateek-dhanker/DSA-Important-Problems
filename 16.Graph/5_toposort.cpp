#include <bits/stdc++.h> 
using namespace std;

void dfstopoSort(int currnode , vector<vector<int> > &adjList , unordered_map<int , bool> &visited , stack<int> &st){
    visited[currnode] = true;

    vector<int> tmp = adjList[currnode];

    for(auto i:tmp){
        if(!visited[i])
            dfstopoSort(i , adjList , visited , st);
    }
    st.push(currnode);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int> > adjList(v);
    for(int i=0;i<e;i++){
        int u = edges[i][0] , v = edges[i][1];

        adjList[u].push_back(v);
    }
    unordered_map<int , bool> visited;
    stack<int> st;

    for(int i=0 ; i<v ; i++){
        if(!visited[i]){
            dfstopoSort(i , adjList , visited , st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        ans.push_back(node);
    }
    return ans;
}


//  Using BFS : Kahn's Algo  //


#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    vector<vector<int> > adjList(nodes);
    vector<int> indegree(nodes);

    for(int i=0;i<edges;i++){
        int u = graph[i][0] , v = graph[i][1];

        adjList[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for(int i =0 ; i< nodes ;i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    while(!q.empty()){
        int currnode = q.front();
        q.pop();

        ans.push_back(currnode);

        for(int i : adjList[currnode]){
            indegree[i]--;
            if(!indegree[i]){
                q.push(i);
            }
        }
    }

    return ans;

}
