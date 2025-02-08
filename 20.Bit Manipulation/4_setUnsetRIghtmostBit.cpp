#include <bits/stdc++.h>
using namespace std;

int setRightmostUnsetBit(int n){
    return n|(n+1);
}

int unsetRightmostSetBit(int n){
    return n&(n-1);
}

int main()
{
    int n = 10;
    cout<<setRightmostUnsetBit(n)<<" "<<unsetRightmostSetBit(n);

    return 0;
}