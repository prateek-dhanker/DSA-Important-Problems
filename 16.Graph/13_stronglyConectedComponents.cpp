#include <bits/stdc++.h>
using namespace std;


void dfs(int node , unordered_map<int , list<int> > &adjList , unordered_map<int , bool> &visited , stack<int> &st){
	visited[node] = true;

	for(auto nbr:adjList[node]){
		if(!visited[nbr])
			dfs(nbr , adjList , visited , st);
	}

	st.push(node);
}
void revdfs(int node , unordered_map<int , list<int> > &transpose , unordered_map<int , bool> &visited){
	visited[node] = true;

	for(auto nbr:transpose[node]){
		if(!visited[nbr])
			revdfs(nbr , transpose , visited );
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	unordered_map<int , list<int> > adjList;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0] , v=edges[i][1];

		adjList[u].push_back(v);
	}

	unordered_map<int , bool> visited;
	stack<int> st;

	for(int i=0 ; i<v ; i++){
		if(!visited[i])
			dfs(i , adjList,visited , st);
	}

	unordered_map<int , list<int> > transpose;
	for(int i=0;i<v;i++){
		visited[i] = false;

		for(auto nbr : adjList[i])
			transpose[nbr].push_back(i);
	}
	int count =0;
	while(!st.empty()){
		int node = st.top();
		st.pop();

		if(!visited[node]){
			count++;
			revdfs(node , transpose , visited);
		}
	}

	return count;

}