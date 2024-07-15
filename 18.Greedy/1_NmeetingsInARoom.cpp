#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int , int> & a,pair<int , int> & b){
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> meet;
        for(int i=0;i<n;i++){
            meet.push_back({start[i] , end[i]});
        }
        
        sort(meet.begin() , meet.end() , cmp);
        int count = 1;
        int ansend = meet[0].second;
        
        for(int i=1;i<n;i++){
            if(meet[i].first > ansend){
                count++;
                ansend = meet[i].second;
            }
        }
        return count;
    }