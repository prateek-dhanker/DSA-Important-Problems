#include <bits/stdc++.h>
using namespace std;
#include<unordered_map>
#include<list>
#include<queue>

//undirected graphs
bool bfsCycleDetect(int currnode,unordered_map<int , list<int> > &adjList ,unordered_map<int , bool> &visited ){
    unordered_map<int , int> parent;
    parent[currnode] = -1;

    queue<int> q;

    q.push(currnode);
    visited[currnode] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i:adjList[node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = node;
            }
            else if(parent[node] != i)
                return true;
        }
    }
    return false;

}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    unordered_map<int , list<int> > adjList;

    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    unordered_map<int , bool> visited;

    for(int i=0 ; i<n ;i++){
        if(!visited[i]){
            bool cycle = bfsCycleDetect(i,adjList,visited);

            if(cycle)
                return "Yes";
        }
    }

    return "No";
}
bool dfsCycleDetect(int currnode,int parent,unordered_map<int , list<int> > &adjList ,unordered_map<int , bool> &visited ){
    visited[currnode] = true;

    for(int i: adjList[currnode]){
        if(!visited[i]){
            bool cycle = dfsCycleDetect(i , currnode , adjList , visited);

            if(cycle)
                return true;
        }
        else if(i != parent)
            return true;
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    unordered_map<int , list<int> > adjList;

    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }
    unordered_map<int , bool> visited;
    for(int i=0 ; i<n ;i++){
        if(!visited[i]){
            bool cycle = dfsCycleDetect(i,-1,adjList,visited);

            if(cycle)
                return "Yes";
        }
    }

    return "No";
}




// UNDIRECTED GRAPH //




bool dfsDirected(int currnode , unordered_map<int , list<int> > &adjList , unordered_map<int , bool> &visited ,  unordered_map<int , bool> &dfsvisited){
  visited[currnode] = true;
  dfsvisited[currnode] = true;

  for(int i: adjList[currnode]){
    if(!visited[i]){
      bool cycle  =  dfsDirected(i , adjList , visited , dfsvisited);

      if(cycle)
        return true;
    }
    else if( dfsvisited[i])
      return true;
  }

  dfsvisited[currnode] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  int m = edges.size();

  unordered_map<int , list<int> > adjList;

  for(int i=0;i<m;i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adjList[u].push_back(v);
  }

  unordered_map<int , bool> visited , dfsvisited;

  for(int i=1 ; i<=n ;i++){
    if(!visited[i]){
      bool cycle = dfsDirected(i,adjList,visited,dfsvisited);

      if(cycle)
        return true;
    }
  }
  return false;
}





bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
	vector<vector<int>> adjList(v);
	vector<int> indegree(v);

	for(int i=0;i<e;i++){
		int u=edges[i][0] , v= edges[i][1];

		adjList[u].push_back(v);
		indegree[v]++;
	}

	queue<int> q;

	for(int i=0;i<v;i++){
		if(indegree[i] == 0)
			q.push(i);
	}
	int cnt = 0;

	while(!q.empty()){
		int node = q.front();
		q.pop();

		cnt++;

		for(auto i : adjList[node]){
			indegree[i]--;
			if(indegree[i] == 0){
				q.push(i);
			}
		}
	}

	if(cnt == v)
		return false;

	return true;
}
