// Generate all binary strings without consecutive 1’s
#include <bits/stdc++.h>
using namespace std;

void binString(int n,string s,int prev,vector<string> &res){
    if(s.length()==n){
        res.push_back(s);
        return;
    }

    s.push_back('0');
    binString(n,s,0,res);

    if(prev==0){
        s.pop_back();
        s.push_back('1');
        binString(n,s,1,res);
    }
}

void generateBinaryStrings(int n){
    vector<string> res;
    binString(n,"",0,res);

    for(auto s:res)
        cout<<s<<" ";
}

int main()
{
    int n;
    cin>>n;

    generateBinaryStrings(n);

    return 0;
}