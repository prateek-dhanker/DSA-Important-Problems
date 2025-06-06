#include <bits/stdc++.h> 
using namespace std;


// Implement class for minStack.

//first best way
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else
            st.push({val , min(st.top().second , val)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

//2nd way
class minStack
{
	// Write your code here.
	stack<int> st;
    int mini ;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int val)
		{
			// Write your code here.
			if(st.empty()){
				st.push(val);
				mini = val;
				return;
			}
			if(val>=mini)
				st.push(val);
			else{
				st.push(val*2 - mini);
				mini = val;
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(st.empty())
				return -1;
			if(st.top()>=mini){
				int val = st.top();
				st.pop();
				return val;
			}
			else{
				int val = mini;
				mini = 2*mini - st.top();
				st.pop();
				return val;
			}
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(st.empty())
				return -1;
			if(st.top()>=mini)
				return st.top();
			return mini;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(st.empty())
				return -1;
			return mini;
		}
};