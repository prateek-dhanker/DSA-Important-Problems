#include <iostream>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int maxele = max(arr1[n-1],arr2[m-1]) + 1;
            
            int i=0 , j=0 , k= 0;
            int first = 1;
            
            while(i<n && j<m){
                if(k==n && first) {
                    k=0;
                    first = 0;
                }
                if(arr1[i]%maxele <= arr2[j]%maxele){
                    if(first){
                        arr1[k] = arr1[k] + (arr1[i]%maxele)*maxele;
                        k++;i++;
                    }
                    else{
                        arr2[k] = arr2[k] + (arr1[i]%maxele)*maxele;
                        k++;i++; 
                    }
                }
                else{
                    if(first){
                        arr1[k] = arr1[k] + (arr2[j]%maxele)*maxele;
                        k++;j++;
                    }
                    else{
                        arr2[k] = arr2[k] + (arr2[j]%maxele)*maxele;
                        k++;j++; 
                    }
                }
            }
            while(i<n){
                if(k==n && first) {
                    k=0;
                    first = 0;
                }
                if(first){
                    arr1[k] = arr1[k] + (arr1[i]%maxele)*maxele;
                    k++;i++;
                }
                else{
                    arr2[k] = arr2[k] + (arr1[i]%maxele)*maxele;
                    k++;i++; 
                }
            }
            while(j<m){
                if(k==n && first) {
                    k=0;
                    first = 0;
                }
                if(first){
                    arr1[k] = arr1[k] + (arr2[j]%maxele)*maxele;
                    k++;j++;
                }
                else{
                    arr2[k] = arr2[k] + (arr2[j]%maxele)*maxele;
                    k++;j++; 
                }
            }
            
            
            for(int i=0;i<n;i++)
                arr1[i] /= maxele;
            for(int i=0;i<m;i++)
                arr2[i] /= maxele;
        } 