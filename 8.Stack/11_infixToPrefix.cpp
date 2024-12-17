#include <bits/stdc++.h>
using namespace std;


string infixToPostfix(string s) {
        // Your code here
        string postfix = "";
        
        stack<char> st;
        st.push('(');
        
        for(char ch : s){
            if(ch == '('){
                st.push('(');
            }
            else if(ch == ')'){
                while(st.top() != '('){
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else if(ch == '+' || ch == '-'){
                while(st.top() != '('){
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
            else if(ch == '*' || ch == '/'){
                while(st.top() != '(' && st.top()!='+' && st.top()!='-'){
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
            else if(ch == '^'){
                while(st.top() == '^'){
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
            else{
                postfix.push_back(ch);
            }
        }
        
        while(st.top() != '('){
            postfix.push_back(st.top());
            st.pop();
        }
        
        return postfix;
    }