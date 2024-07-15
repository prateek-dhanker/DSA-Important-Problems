#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
        string ans = "" , temp = "";
        int i = s.length()-1;

        while(i>=0){
            if(s[i] == ' '){
                if(temp != ""){
                    ans += temp + " ";
                    temp = "";
                }
                while(i>=0 && s[i] == ' ')
                    i--;
            }
            else{
                temp = s[i] + temp;
                i--;
            }   
        }
        if(temp != "")
            ans += temp + " ";
        
        return ans.substr(0,ans.length()-1);
        
    }