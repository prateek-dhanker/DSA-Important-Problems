// Given an array arr[] denoting heights of N towers and a positive integer K.

// For each tower, you must perform exactly one of the following operations exactly once.

// Increase the height of the tower by K
// Decrease the height of the tower by K
// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

// You can find a slight modification of the problem here.
// Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.


#include <bits/stdc++.h>
using namespace std;



int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n =arr.size();
        sort(arr.begin() , arr.end());
        
        int diff = arr[n-1] - arr[0];
        
        for(int i=1;i<arr.size();i++){
            //increase left part by k and decreasee right part by k
            
            if(arr[i]<k)
                continue;
            
            int minh = min(arr[0]+k , arr[i]-k);
            int maxh = max(arr[i-1]+k , arr[n-1]-k);
            
            diff = min(diff , maxh-minh);
        }
        return diff;
        
    }