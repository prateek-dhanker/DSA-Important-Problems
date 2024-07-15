#include <bits/stdc++.h>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin() , a.end());
        
        long long i = m-1 , ans = LLONG_MAX;
        
        while(i<n){
            long long diff = a[i] - a[i-m+1];
            if(diff < ans)
                ans = diff;
            i++;
        }
        return ans;
    }  