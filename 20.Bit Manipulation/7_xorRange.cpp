#include <bits/stdc++.h>
using namespace std;

int xor1N(int n){
    if(n == 0)
        return 0;
    
    if(n%4 == 1)
        return n;
    
    if(n%4 == 2)
        return n+1;
    
    if(n%4 == 3)
        return 1;
    
    return 0;
}

int main(){
    int l,r;
    cin >>l>>r;

    int res = xor1N(l-1)^xor1N(r);
    cout<<res;
    
    return 0;
}