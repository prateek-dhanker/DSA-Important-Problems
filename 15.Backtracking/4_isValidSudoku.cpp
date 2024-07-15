#include <bits/stdc++.h>
using namespace std;  

class Solution {
public:
    bool isSafe(int row , int col , vector<vector<char>>& board , char ch){
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
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0 ; row<9;row++){
            for(int col = 0; col <9 ; col++){
                if(board[row][col] != '.'){
                    char ch = board[row][col];
                    board[row][col] = '.';
                    if(!isSafe(row , col , board , ch))
                        return false;
                    board[row][col] = ch;
                }
            }
        }
        return true;
    }
};