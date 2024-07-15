#include <bits/stdc++.h>
using namespace std;
int minimumDays(int S, int N, int M){
        // code here
        int sundays = S/7;
        int buyDays = S-sundays;
        
        int ans;
        if((M*S)%N)
            ans = (M*S)/N + 1;
        else
            ans = (M*S)/N;
            
        if(ans <= buyDays)
            return ans;
        return -1;
    }