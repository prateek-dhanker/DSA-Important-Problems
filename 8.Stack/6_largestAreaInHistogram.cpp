class Solution {
private:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=n-1; i>=0 ;i--){
            while(st.top()!=-1 && arr[st.top()] >= arr[i])
                st.pop();
            if(st.top() == -1)
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int> &arr, int n)
    {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=0; i<n ;i++){
            while(st.top()!=-1 && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next(heights.size());
        vector<int> prev(heights.size());

        next = nextSmallerElement(heights , heights.size());
        prev = prevSmallerElement(heights , heights.size());

        int maxArea = INT_MIN;
        for(int i=0 ; i<heights.size();i++){
            int len = heights[i];
            int bredth = next[i] - prev[i] -1;
            int area = len*bredth;
            maxArea = max(area , maxArea);
        }
        return maxArea;
    }
};