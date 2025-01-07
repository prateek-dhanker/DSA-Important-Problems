#include <bits/stdc++.h>
using namespace std;


void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low>=high)
            return;
        
        int q = partition(arr,low,high);
        quickSort(arr,low,q-1);
        quickSort(arr,q+1,high);
    }
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
int partition(vector<int>& arr, int low, int high) {
        // code here
        swap(arr[low],arr[high]);
        
        int pivot = arr[low];
        int i=low,j=high;
        
        while(i<j){
            while(i<=high && arr[i]<=pivot)
                i++;
            while(j>=low && arr[j]>arr[low])
                j--;
            
            if(i<j)
                swap(arr[i],arr[j]);
        }
        swap(arr[low],arr[j]);
        return j;
    }