#include <bits/stdc++.h> 
using namespace std;

int longestMountain(int *arr, int n)
{
    // Write your code here.
    int maxi = 0;
    int l=0,pivot = -1;
    bool mt = false;

    for(int i=1;i<n;i++){
        if(arr[i] > arr[i-1] && pivot!=-1){
            if(pivot != i-1)
                maxi = max(maxi,i-l);
            l = i-1;
            pivot = -1;
        }

        else if(arr[i] < arr[i-1] && pivot==-1){
            if(l != i-1)
                pivot = i-1;
            else
                l = i;
        }
        else if(arr[i]==arr[i-1]){
            if(pivot!=-1 && pivot!=i-1)
                maxi = max(maxi,i-l);
            l = i;
        }
    }
    if(pivot != -1 && pivot!=n-1)
        maxi = max(maxi,n-l);

    return maxi;
}