#include <bits/stdc++.h> 
using namespace std;
void solve(stack<int>& st , int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int num = st.top();
    st.pop();

    solve(st,x);
    st.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack , x);

    return myStack;
}
