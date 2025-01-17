#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int,int>> &arr,int p,int q,int ri,vector<int>& nge){
        vector<pair<int,int>> left , right;
        
        for(int i=p;i<=q;i++)
            left.push_back(arr[i]);
            
        for(int i=q+1;i<=ri;i++)
            right.push_back(arr[i]);
        
        int l=0,r=0,k=p;
        
        while(l<left.size() && r<right.size()){
            if(left[l].first<right[r].first){
                nge[left[l].second] += right.size()-r;
                arr[k++] = left[l++];
            }
            else
                arr[k++] = right[r++];
        }
        while(l<left.size())
            arr[k++] = left[l++];
        
        
        while(r<right.size())
            arr[k++] = right[r++];
    }
    void mergeSort(vector<pair<int,int>> &arr,int p,int r,vector<int>& nge){
        if(p>=r)
            return ;
        
        int q = (p+r)/2;
        mergeSort(arr,p,q,nge);
        mergeSort(arr,q+1,r,nge);
        merge(arr,p,q,r,nge);
    }
    vector<int> count_NGE(int n, vector<int> &arr, int q, vector<int> &indices){
        //write your code here
        vector<pair<int,int>> nums;
       
        for(int i=0;i<n;i++)
            nums.push_back({arr[i],i});
        
        vector<int> nge(n,0);
        
        mergeSort(nums,0,n-1,nge);
        
        vector<int> res(q);
        for(int i=0;i<q;i++)
            res[i] = nge[indices[i]];
        
        return res;
    }