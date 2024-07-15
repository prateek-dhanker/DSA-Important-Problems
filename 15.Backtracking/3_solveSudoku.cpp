#include <bits/stdc++.h>
using namespace std;  
class Solution {
public:
    bool isSafe(char ch , int row , int col , vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[row][i] == ch)
                return false;
            if(board[i][col] == ch)
                return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch)
                return false;
        }
        return true;
    }
    pair<vector<vector<char> > , bool> solve(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for (int col=0;col<9;col++){
                if(board[row][col] == '.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isSafe(ch , row , col , board)){
                            board[row][col] = ch;
                            pair<vector<vector<char> > , bool> b = solve(board);
                            if(b.second)
                                return b;
                            else                    
                                board[row][col] = '.';
                        }
                    }
                    return {board,false};
                }
            }
        }
        return {board,true};
    }

    void solveSudoku(vector<vector<char>>& board) {
        board = solve(board).first;
    }
};