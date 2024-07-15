#include <bits/stdc++.h> 
vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{

    //Write your code here
    queue<int> q;
    for(int i=0;i<k-1;i++){
        if(arr[i]<0)
            q.push(i);
    }
    vector<int> ans;

    for(int i=k-1;i<n;i++){
        if(arr[i]<0)
            q.push(i);
        if(q.empty())
            ans.push_back(0);
        else{
            if(q.front() == i-k+1){
                ans.push_back(arr[q.front()]);
                q.pop();
            }
            else
                ans.push_back(arr[q.front()]);
        }
    }
    return ans;

}