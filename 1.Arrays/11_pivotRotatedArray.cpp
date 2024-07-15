#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0 , e = nums.size()-1;

        // If the array is not rotated (or has only one element)
        if(nums[s] <= nums[e])
            return nums[s];

        while(s <= e) {
            int mid = s + (e - s) / 2;

            // Ensure mid is not out of bounds
            if(mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];
            if(mid < nums.size() - 1 && nums[mid] > nums[mid + 1])
                return nums[mid + 1];

            // Narrow down the search
            if(nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;  // This line should never be reached
    }
};
