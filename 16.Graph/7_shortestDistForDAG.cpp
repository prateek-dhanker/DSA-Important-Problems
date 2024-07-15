#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int , list<pair<int,int> > > adjList;
        int nodesCount;

        Graph(int n = 0){
            this->nodesCount = n;
        }

        void addEdge(int u , int v , int weight){
            adjList[u].push_back({v,weight});
        }

        void printList(){
            for(auto i : adjList){
                cout<<i.first<<" -> ";
                for(auto j:i.second){
                    cout<<"["<<j.first<<","<<j.second<<"]";
                }
                cout<<endl;
            }
        }
        void dfstopo(int i , unordered_map<int , bool> &visited , stack<int> &st){
            visited[i] = true;

            for(auto j : adjList[i]){
                if(!visited[j.first]){
                    dfstopo(j.first , visited , st);
                }
            }
            st.push(i);
        }
        stack<int> toposort(){
            unordered_map<int , bool> visited;
            stack<int> st;
            for(int i=0;i<nodesCount;i++){
                if(!visited[i])
                    dfstopo(i , visited , st);
            }
            return st;
        }
        vector<int> shortestDist(int source){
            stack<int> st = toposort();

            vector<int> dist(nodesCount,INT_MAX);
            dist[source] = 0;

            while(!st.empty()){
                int curr = st.top();
                st.pop();

                if(dist[curr]!=INT_MAX){
                    for(auto j : adjList[curr]){
                        dist[j.first] = min(dist[j.first] , dist[curr] + j.second);
                    }
                }
            }
            return dist;
        }
};

int main()
{
    Graph g(6);
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    // g.printList();
    
    vector<int>dist = g.shortestDist(1);

    for(int i:dist){
        if(i==INT_MAX)
            cout<<"infinite ";
        else
            cout<<i<<" ";
    }

    return 0;
}