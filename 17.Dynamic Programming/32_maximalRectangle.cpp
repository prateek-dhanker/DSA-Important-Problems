#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextSmallerElemIndex(vector<int> &histogram){
        stack<int> st;
        st.push(-1);

        vector<int> ans(histogram.size());
        for(int i = histogram.size()-1 ; i>=0;i--){
            if(st.top() == -1 || histogram[st.top()] < histogram[i]){
                ans[i] = st.top();
                st.push(i);
            }
            else{
                while(st.top() != -1 && histogram[st.top()] >= histogram[i]){
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);
            }           
        }
        return ans;
    }
    vector<int> prevSmallerElemIndex(vector<int> &histogram){
        stack<int> st;
        st.push(-1);

        vector<int> ans(histogram.size());
        for(int i =0;i< histogram.size() ;i++){
            if(st.top() == -1 || histogram[st.top()] < histogram[i]){
                ans[i] = st.top();
                st.push(i);
            }
            else{
                while(st.top() != -1 && histogram[st.top()] >= histogram[i]){
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);
            }           
        }
        return ans;
    }
    int largestAreaInHistogram(vector<int> &histogram){
        vector<int> next = nextSmallerElemIndex(histogram);
        vector<int> prev = prevSmallerElemIndex(histogram);

        int ans = INT_MIN;
        for(int i = 0;i<histogram.size();i++){
            if(next[i] == -1)
                next[i] = histogram.size();
            int length = histogram[i];
            int bredth = next[i] - prev[i] -1;

            int area = length * bredth;

            ans = max(ans, area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = INT_MIN;

        vector<int> histogram(matrix[0].size() , 0);
        for(int row = 0; row<matrix.size();row++){
            //for each row
            for(int col = 0;col<matrix[0].size();col++){
                if(matrix[row][col] == '1')
                    histogram[col]++;
                else
                    histogram[col] = 0;
            }
            ans = max(ans , largestAreaInHistogram(histogram));
        }
        return ans;
    }
};