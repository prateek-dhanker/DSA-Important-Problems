queue<int> rev(queue<int> q)
    {
        // add code here.
        //approach 1
        // stack<int> st;
        
        // while(!q.empty()){
        //     st.push(q.front());
        //     q.pop();
        // }
        // while(!st.empty()){
        //     q.push(st.top());
        //     st.pop();
        // }
        // return q;
        
        //approach2
        if(q.size()<=1)
            return q;
        
        int val = q.front();
        q.pop();
        q = rev(q);
        q.push(val);
        return q;
    }

    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int>st;
        int i=0;
        while(i<k){
            st.push(q.front());
            q.pop();
            i++;
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        for(int i=0;i<q.size()-k;i++){
            int val = q.front();
            q.pop();
            q.push(val);
        }
        return q;
    }