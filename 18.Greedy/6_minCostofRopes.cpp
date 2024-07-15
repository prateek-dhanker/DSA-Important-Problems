#include <bits/stdc++.h>
using namespace std;
long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long , vector<long long> , greater<long long> > pq;
        
        for(long long i=0;i<n;i++)
            pq.push(arr[i]);
            
        long long cost = 0;
        while(pq.size() > 1){
            long long rope1 = pq.top();
            pq.pop();
            
            long long rope2 = pq.top();
            pq.pop();
            
            long long sum = rope1 + rope2;
            cost += sum;
            pq.push(sum);
        }
        return cost;
        
    }