#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(string s , int i,int j){
        while(i<j){
            if(s[i] != s[j])
                return false;
            
            i++;j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int  i=0, j = s.length()-1;

        while(i<=j){
            if(s[i] != s[j]){
                return solve(s , i+1 , j) || solve(s , i,j-1);
            }
            i++;j--;
        }
        return true;
    }
};