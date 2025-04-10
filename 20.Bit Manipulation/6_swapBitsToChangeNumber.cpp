class Solution {
    public:
        int minBitFlips(int start, int goal) {
            int xori = start^goal;
    
            int cnt = 0;
            while(xori){
                cnt += (xori&1);
                xori = xori>>1;
            }
    
            return cnt;
        }
    };