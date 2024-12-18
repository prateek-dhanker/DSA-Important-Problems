#include <bits/stdc++.h>
using namespace std;


bool possible(vector<int> &stalls , int dist,int k) {
        int prev = stalls[0];
        k--;
        for(int i=1;i<stalls.size() && k>0;i++){
            if(stalls[i]-prev >= dist){
                k--;
                prev = stalls[i];
            }
        }
        return k==0;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int maxDist = 0;
        int s =1 , e = stalls[stalls.size()-1]-stalls[0];
        
        while(s<=e){
            int mid = (s+e)/2;
            
            if(possible(stalls,mid,k)){
                maxDist = mid;
                s = mid+1;
            }
            else
                e = mid-1;
        }
        return maxDist;
    }