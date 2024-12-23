#include <bits/stdc++.h>
using namespace std;

// minimum number of swaps sort
int cycleSort(vector<int> &arr){
        vector<int> sorted = arr;
        sort(sorted.begin(),sorted.end());

        unordered_map<int,int> pos;
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]] = i;
        }

        int swaps = 0;
        for(int i=0;i<arr.size();i++){
            if(sorted[i]!=arr[i])
                swaps++;
            
            int currPos = pos[sorted[i]];
            pos[arr[i]] = currPos;
            swap(arr[i],arr[currPos]);
        }
        return swaps;
    }