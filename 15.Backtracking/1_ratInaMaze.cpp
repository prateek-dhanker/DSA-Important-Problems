#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x , int y , vector<vector<int> > &arr , vector<vector<int> > &visited, int n){
  return x>=0 && y>=0 && x<n && y<n && arr[x][y] && !visited[x][y];
}
void solve(int x, int y, vector<vector<int> > &arr, int n ,vector<string > &ans, vector<vector<int> > &visited, string path){
    if(x == n-1 && y == n-1){
      ans.push_back(path);
      return;
    }

    if(isSafe(x+1,y,arr , visited,n)){
        visited[x][y] = 1;
        solve(x+1,y,arr, n,ans,visited,path+'D');
        visited[x][y] = 0;
    }
    if(isSafe(x,y-1,arr , visited,n)){
        visited[x][y] = 1;
        solve(x,y-1,arr, n,ans,visited,path+'L');
        visited[x][y] = 0;
    }
    if(isSafe(x,y+1,arr , visited,n)){
        visited[x][y] = 1;
        solve(x,y+1,arr, n,ans,visited,path+'R');
        visited[x][y] = 0;
    }
    if(isSafe(x-1,y,arr , visited,n)){
        visited[x][y] = 1;
        solve(x-1,y,arr, n,ans,visited,path+'U');
        visited[x][y] = 0;
    }
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
  // Write your code here.
  vector<string > ans;
  vector<vector<int> >visited(n,vector<int>(n,0));
  string path = "";

  if(arr[0][0] == 0)
    return ans;
  solve(0,0,arr , n , ans, visited , path);
  return ans;

}