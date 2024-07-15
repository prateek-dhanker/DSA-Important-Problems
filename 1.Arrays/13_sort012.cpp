#include <bits/stdc++.h>
using namespace std;

//solution 1

void sortColors(vector<int>& nums) {
        int n = nums.size();

        int i=0 , j=1;
        while(i<n && j<n){
            if(nums[i] == 0){
                i++;
                j = i+1;
            }
            else{
                while( j<n && nums[j] != 0)
                    j++;

                if(j<n)
                    swap(nums[i] , nums[j]);
            }            
        }
        j = i+1;
        while(i<n && j<n){
            if(nums[i] == 1){
                i++;
                j = i+1;
            }
            else{
                while( j<n && nums[j] != 1)
                    j++;

                if(j<n)
                    swap(nums[i] , nums[j]);
            }  
        }        
    }

//soluton 2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n=nums.size();

        int count0=0;
        int count1=0;
        int count2=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            count0++;
            else if(nums[i]==1)
            count1++;
            else
            count2++;
        }

        

        for(int i=0;i<count0;i++)
        nums[i]=0;

        for(int i=count0;i<count0+count1;i++)
       nums[i]=1;

        for(int i=count0+count1;i<count0+count1+count2;i++)
        nums[i]=2;

        
    }
};