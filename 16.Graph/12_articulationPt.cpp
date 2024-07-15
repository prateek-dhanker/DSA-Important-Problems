#include <bits/stdc++.h>
using namespace std;

class GraphL{
    public :
        unordered_map<int , list<int> > adjList;
        int nodesCount;

        GraphL(int n = 0){
            this->nodesCount = n;
        }

        void addEdge(int u , int v , bool direction){
            adjList[u].push_back(v);

            if(direction == false)
                adjList[v].push_back(u);

        }

        void printList(){
            for(auto i : adjList){
                cout<<i.first<<" -> ";
                for(auto j:i.second){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
        void dfs(int node , int parent ,int &timer , vector<int> &disc , vector<int> &low , unordered_map<int , bool> &visited , vector<int> &artipoint){
            visited[node] = true;
            disc[node] = low[node] = timer++;
            int child = 0; 

            for(auto nbr : adjList[node]){
                if(nbr == parent)
                    continue;
                if(!visited[nbr]){
                    dfs(nbr , node , timer , disc , low , visited , artipoint);
                    low[node] = min(low[node] , low[nbr]);

                    if(low[nbr] >= disc[node] && parent!=-1)
                        artipoint.push_back(node);

                    child++;
                }
                else{
                    //backedge
                    low[node] = min(low[node] , disc[nbr]);
                }
                if(parent == -1 && child >1)
                    artipoint.push_back(node);
            }
        }
        void findArticulationPoints(vector<int> &artipoint){
            vector<int> disc(nodesCount , -1);
            vector<int> low(nodesCount , -1);
            unordered_map<int , bool> visited;
            int timer = 0;

            for(int i=0;i<nodesCount;i++){
                if(!visited[i]){
                    dfs(i , -1 ,timer, disc , low , visited , artipoint);
                }
            }
        }

};

int main()
{
    GraphL g(5);

    g.addEdge(0,3,false);
    g.addEdge(0,4,false);
    g.addEdge(0,1,false);
    g.addEdge(3,4,false);
    g.addEdge(1,2,false);

    // g.printList();
    vector<int> artipoint;

    g.findArticulationPoints(artipoint);

    if(artipoint.empty()){
        cout<<"No articulation point exist";
    }
    else{
        for(int i : artipoint)
            cout<<i<<" ";
    }

    return 0;
}