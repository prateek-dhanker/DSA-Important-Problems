#include <bits/stdc++.h>
using namespace std;

int startStation(vector<int> &gas, vector<int> &cost) {
    // Your code here
    int n = gas.size();
    
    int startIdx = 0,currgas = 0;
    for(int i=0;i<n;i++){
        currgas += gas[i]-cost[i];
        
        if(currgas<0){
            startIdx = (i+1)%n;
            currgas = 0;
        }
    }
    
    currgas = 0;
    for(int i=0;i<n;i++){
        int station = (startIdx+i)%n;
        
        currgas += gas[station]-cost[station];
        
        if(currgas<0)
            return -1;
    }
    
    return startIdx;
}