//either (, ) or *
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open , star;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                open.push(i);
            
            else if(s[i]==')'){
                if(open.size())
                    open.pop();
                
                else if(star.size())
                    star.pop();
                
                else
                    return false;
            }
            else
                star.push(i);
        }
        if(open.empty())
            return true;
        
        while(open.size() && star.size() && open.top()<star.top()){
            open.pop();
            star.pop();
        }

        return open.empty();
    }
};
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length()-1,open = 0 , closed = 0;

        for(int i=0;i<=n;i++){
            if(s[i]==')')
                open--;
            else
                open++;
            

            if(s[n-i]=='(')
                closed--;
            else
                closed++;
            

            if(open<0 || closed<0)
                return false;
        }
        return true;
    }
};