#include <bits/stdc++.h>
using namespace std;


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int , list<int> > adjList(n);

	for(int i=0;i<m;i++){
		int u=edges[i].first , v = edges[i].second ;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	unordered_map<int , bool>visited;
	unordered_map<int , int> parent;
	parent[s] = -1;

	queue<int> q;
	q.push(s);
	visited[s] = true;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(int i: adjList[front]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	vector<int>	path;
	int node = t;
	path.push_back(t);

	while(node!=s){
		node = parent[node];
		path.push_back(node);
	}

	reverse(path.begin() , path.end());

	return path;

}

//better and easy
vector<int> shortestPath(vector<vector<int>>& adj, int src) {
	// code here
	int n = adj.size();
	
	vector<int> dist(n,-1);
	dist[src] = 0;
	
	queue<int> q;
	q.push(src);
	
	while(q.size()){
		int node = q.front();
		q.pop();
		
		for(int nbr:adj[node]){
			if(dist[nbr]==-1){
				dist[nbr] = dist[node]+1;
				q.push(nbr);
			}
		}
	}
	
	return dist;
}
