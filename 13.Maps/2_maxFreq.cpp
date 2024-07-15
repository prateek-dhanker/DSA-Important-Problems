#include<map>
int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int,int> count;
    int maxCount = 0;
    for(int i=0;i<n ; i++){
        count[arr[i]]++;
        maxCount = max(maxCount , count[arr[i]]);
    }

    for(int i=0 ;i < n ; i++){
        if(count[arr[i]] == maxCount)
            return arr[i];
    }
}