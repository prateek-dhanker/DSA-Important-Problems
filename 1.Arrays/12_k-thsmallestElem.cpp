#include <bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> maxheap;
        
        for(int i=l;i<l+k;i++)
            maxheap.push(arr[i]);
            
        for(int i = l+k;i<=r;i++){
            if(maxheap.top() > arr[i]){
                maxheap.pop();
                maxheap.push(arr[i]);
            }
        }
        
        return maxheap.top();
    }