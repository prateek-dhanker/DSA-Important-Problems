// Search in a rotated array.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getPivot(int arr[],int size)
{
    int start = 0 , end = size-1;
    // cout<<"in getPivot";
    while(start < end)
    {
        int mid  = start + (end - start)/2;
        if(arr[mid] >= arr[0])
            start = mid+1;
        else
            end = mid;
    }
    return start;//or return end;
}
int binSearch(int arr[],int size,int key,int low,int high)
{
    // cout<<"In binSearch";
    int start = low , end = high;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        
        if(arr[mid] == key)
            return mid;
        
        else if(arr[mid] > key)
            end = mid-1;

        else 
            start = mid +1;
    }
    return -1;
}
int searchRotated(int arr[],int size,int key)
{
    // cout<<"In searchRotated";
    int pivot = getPivot(arr,size);

    if(key>=arr[pivot] && key<=arr[size-1])
        return binSearch(arr,size,key,pivot,size-1);
    else
        return binSearch(arr,size,key,0,pivot-1);
}

int main()
{
    int arr[] = {7,9,1,2,3};
    cout<<"index of 10 is "<<searchRotated(arr,5,10);

    return 0;
}


int search(vector<int>& nums, int k) {
        int s = 0 , e = nums.size()-1;

        while(s<=e){
            int mid = (s+e)/2;

            if(nums[mid] == k)
                return mid;

            //in case of duplicates
            if(nums[s]==nums[mid] && nums[e]==nums[mid]){
                s++;
                e--;
                continue;
            }
            
            if(nums[s]<=nums[mid]){
                if(nums[s]<=k && nums[mid]>=k)
                    e = mid-1;
                
                else
                    s = mid+1;
            }
            else{
                if(nums[mid]<=k && nums[e]>=k)
                    s = mid+1;
                else
                    e = mid-1;
            }
        }
        return -1;
    }