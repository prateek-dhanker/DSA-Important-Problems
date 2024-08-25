#include <bits/stdc++.h>
using namespace std;

//find pairs where {x^y > y^x | xEarr & yEbrr}
long long count(int a, vector<int> &brr , int n, vector<int> &v){
        if(a==0)
            return 0LL;
        
        if(a==1)
            return v[0];
         
        long long ans = 0;   
        int idx = upper_bound(brr.begin() , brr.end() , a) - brr.begin();
        
        ans = (n-idx) + v[0] + v[1];
        
        if(a==2)
            ans -= (v[3] + v[4]);
        
        if(a==3)
            ans += v[2];
        
        return ans;
    }
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        sort(brr.begin() , brr.end());
        
        vector<int> v(5,0);
        for(int b:brr){
            if(b<=4)
                v[b]++;
        }
        
        long long ans = 0;
        
        for(int a:arr){
            ans += count(a,brr,brr.size(),v);
        }
        return ans;
        
    }