#include <bits/stdc++.h>
using namespace std;

//infix to postfix
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

//infix to prefix
string infixToPrefix(string s) {
        // Your code here
        reverse(s.begin(),s.end());

        string prefix = "";
        
        stack<char> st;
        st.push('(');
        
        for(char ch : s){
            if(ch == ')'){
                st.push('(');
            }
            else if(ch == '('){
                while(st.top() != '('){
                    prefix.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else if(ch == '+' || ch == '-'){
                while(st.top() != '(' && st.top()!='+' && st.top()!='-'){
                    prefix.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
            else if(ch == '*' || ch == '/'){
                while(st.top() == '^'){
                    prefix.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
            else if(ch == '^'){
                while(st.top() == '^'){
                    prefix.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
            else{
                prefix.push_back(ch);
            }
        }
        
        while(st.top() != '('){
            prefix.push_back(st.top());
            st.pop();
        }
        reverse(prefix.begin(),prefix.end());
        return prefix;
}
bool isOperator(char ch){
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ;
    }
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        
        for(char ch:exp){
            if(isOperator(ch)){
                auto top1 = st.top();
                st.pop();
                
                auto top2 = st.top();
                st.pop();
                
                st.push("(" + top2 + ch + top1 + ")");
            }
            else{
                string conv = "";
                conv.push_back(ch);
                st.push(conv);
            }
        }
        return st.top();
    }

string preToInfix(string exp) {
        // Write your code here
        stack<string> st;
        
        for(int i=exp.length()-1;i>=0;i--){
            char ch = exp[i];
            if(isOperator(ch)){
                auto top1 = st.top();
                st.pop();
                
                auto top2 = st.top();
                st.pop();
                
                st.push("(" + top1 + ch + top2 + ")");
            }
            else{
                string conv = "";
                conv.push_back(ch);
                st.push(conv);
            }
        }
        return st.top();
    }

int main(){
    cout<<infixToPrefix("(a+b)*c-d+f");
    return 0;
}