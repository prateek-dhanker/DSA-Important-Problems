#include <bits/stdc++.h>
using namespace std;

string toBinary(int n){
    if(n==0)
        return "0";
    string bin = "";

    while(n){
        bin += n%2 ? "1" : "0";
        n /= 2;
    }

    reverse(bin.begin(),bin.end());

    return bin;
}

int toDecimal(string bin){
    int n = 0 , p2 = 1;

    for(int i=bin.length()-1;i>=0;i--){
        if(bin[i]=='1')
            n += p2;
        
        p2 *= 2;
    }

    return n;
}

int main()
{
    int n;
    do{
        cin>>n;
        cout<<toBinary(n)<<endl;
    }while(n!=0);

    string bin;
    do{
        cin>>bin;
        cout<<toDecimal(bin)<<endl;
    }while(bin!="-1");

    return 0;
}