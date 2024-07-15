#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<double,Item> &a , pair<double,Item> &b){
        return a.first > b.first;
    }
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        vector<pair<double,Item>>v;
        for(int i=0;i<n;i++){
            double perval = (1.0 * arr[i].value)/arr[i].weight;
            v.push_back({perval,arr[i]});
        }
        
        sort(v.begin() , v.end() , cmp);
        
        double ans = 0;
        for(auto p : v){
            if(p.second.weight > w){
                ans += w*p.first;
                break;
            }
            else{
                ans += p.second.value;
                w -= p.second.weight;
            }
        }
        return ans;
    }