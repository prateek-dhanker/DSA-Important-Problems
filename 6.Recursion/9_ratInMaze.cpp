#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool allowed(int x , int y , vector<vector<int>> &visited , int n , vector<vector<int>> &m){
        if(x<n &&y<n && x>=0 && y>=0 && visited[x][y] == 0 && m[x][y] == 1)
            return true;
        return false;
    }
    void solve(vector<vector<int>> &m, int n , vector<string> &ans , string &path , int x ,int y,vector<vector<int>> &visited){
        if(x == n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;
        
        if(allowed(x+1,y , visited , n ,m)){
            path.push_back('D');
            solve(m , n ,ans, path , x+1 , y , visited );
            path.pop_back();
        }
            
        if(allowed(x,y -1, visited , n,m)){
            path.push_back('L');
            solve(m , n , ans , path , x , y-1 , visited);
            path.pop_back();
        }
            
        if(allowed(x,y+1 , visited , n,m)){
            path.push_back('R');
            solve(m , n , ans , path , x , y+1 , visited);
            path.pop_back();
        }
        if(allowed(x-1,y , visited , n,m)){
            path.push_back('U');
            solve(m , n , ans , path , x-1 , y , visited);
            path.pop_back();
        }
        visited[x][y] = 0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] == 0)
            return ans;
            
        string path = "";
        int x = 0 , y=0;
        
        vector<vector<int>> visited(n,vector<int>(n,0));
        
        solve(m , n , ans , path , x , y , visited);
        sort(ans.begin() , ans.end());
        return ans;
    }
};