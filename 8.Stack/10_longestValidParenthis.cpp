#include <bits/stdc++.h>
using namespace std;


int maxLength(string str) {
        // code here
        
        stack<int> st;
        st.push(-1);
        
        int maxLen = 0;
        for(int i=0;i<str.length();i++){
            if(str[i] == '(')
                st.push(i);
            
            else{
                st.pop();
                if(st.empty())  
                    st.push(i);
                else
                    maxLen = max(maxLen , i-st.top());
            }
            
            
        }
        return maxLen;
    }