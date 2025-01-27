void insertBottom(stack<int> &st,int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int top = st.top();
        st.pop();
        
        insertBottom(st,x);
        
        st.push(top);
    }
    void Reverse(stack<int> &st){
        if(st.size()==0)
            return;
        
        int top = st.top();
        st.pop();
        
        Reverse(st);
        
        insertBottom(st,top);
    }