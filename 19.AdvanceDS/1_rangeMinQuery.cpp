#include <bits/stdc++.h>
using namespace std;


void buildTree(int *stree , int *arr , int index , int s , int e){
    if(s>e) return ;
    
    if(s == e){
        stree[index] = arr[s];
        return;
    } 
    int mid = (s+e)/2;
    
    buildTree(stree , arr , 2*index , s,mid);
    buildTree(stree , arr , 2*index+1 , mid+1 , e);
    stree[index] = min(stree[2*index] , stree[2*index+1]);
}
int *constructST(int arr[],int n)
{
  //Your code here
  int *stree = new int[4*n+1];
  
  buildTree(stree , arr, 1 , 0 , n-1);
  
  return stree;
  
}