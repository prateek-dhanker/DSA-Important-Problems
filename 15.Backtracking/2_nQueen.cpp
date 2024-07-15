#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int row , int col ,int n , unordered_map<int , bool> &rowCheck,unordered_map<int , bool> &digCheck1 ,unordered_map<int , bool> &digCheck2){
        bool res = rowCheck[row] || digCheck1[row+col] || digCheck2[n-1+col-row];
        return !res;
    }
    void solve(int col , int n, vector<vector<string>> &ans,vector<string> &board , unordered_map<int , bool> &rowCheck,unordered_map<int , bool> &digCheck1 ,unordered_map<int , bool> &digCheck2){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n;row++){
            if(isSafe(row,col, n, rowCheck , digCheck1 , digCheck2)){
                board[row][col] = 'Q';
                rowCheck[row] = true;
                digCheck1[row+col] = true;
                digCheck2[n-1+col-row] = true;
                solve(col+1 , n,ans , board ,rowCheck , digCheck1 , digCheck2);
                board[row][col] = '.';
                rowCheck[row] = false;
                digCheck1[row+col] = false;
                digCheck2[n-1+col-row] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> board;
        string s = "";
        for(int j=0;j<n;j++){
            s+=".";
        }
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        unordered_map<int , bool> rowCheck, digCheck1 , digCheck2;

        solve(0,n,ans ,board , rowCheck , digCheck1 , digCheck2);

        return ans;
    }
};