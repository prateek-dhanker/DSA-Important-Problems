#include <bits/stdc++.h>
using namespace std;

template <typename T>

class GraphL{
    public :
        unordered_map<T , list<T> > adjList;
        int nodesCount;

        GraphL(int n = 0){
            this->nodesCount = n;
        }

        void addEdge(T u , T v , bool direction){
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

};
class GraphM{
    public:
        vector<vector<int> > adjMatrix;  
        int n;

        GraphM(int n){
            this->n = n;
            for(int i=0;i<n;i++){
                vector<int> v;
                for(int j=0 ; j< n;j++){
                    v.push_back(0);
                }
                adjMatrix.push_back(v);
            }
        }

        void addEdge(int u , int v, bool direction){
            adjMatrix[u][v] = 1;

            if(direction == 0)
                adjMatrix[v][u] = 1;
        }

        void printMatrix(){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    cout<<adjMatrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};

int main()
{
    // GraphL<int> G;

    int n,m;
    cout<<"Enter the no. of nodes : ";
    cin>>n;
    cout<<"Enter the no. of edges : ";
    cin>>m;
    GraphM G(n);

    for(int i=0 ; i<m ; i++){
        int u,v;
        cin>>u>>v;

        G.addEdge(u,v,false);
    }
    G.printMatrix();

    return 0;
}