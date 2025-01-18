//jump game 1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;

        for(int i=0;i<n;i++){
            if(i>maxReach)
                return false;

            maxReach = max(maxReach,nums[i]+i);
        }
        return true;
    }
};
//jump game 2
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l=0,r=0;

        while(r<nums.size()-1){
            int farthest = 0;
            for(int i=l;i<=r;i++)
                farthest = max(farthest,i+nums[i]);
            
            l = r+1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};