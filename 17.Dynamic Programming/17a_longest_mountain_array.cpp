class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Compute the LIS ending at each index
        vector<int> left(n, 1);  // left[i] = length of LIS ending at i
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    left[i] = max(left[i], left[j] + 1);
                }
            }
        }
        
        // Step 2: Compute the LDS starting at each index
        vector<int> right(n, 1); // right[i] = length of LDS starting at i
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[i]) {
                    right[i] = max(right[i], right[j] + 1);
                }
            }
        }
        
        // Step 3: Find the longest mountain
        int maxLengthMountain = 0;
        for (int i = 1; i < n - 1; ++i) { // Peaks can't be the first or last element
            if (left[i] > 1 && right[i] > 1) { // Must be a valid mountain peak
                maxLengthMountain = max(maxLengthMountain, left[i] + right[i] - 1);
            }
        }
        
        // Step 4: Calculate minimum removals
        return n - maxLengthMountain;
    }
};
