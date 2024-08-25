class Solution {
public:
    bool possible(vector<int> &piles, int h,int speed){
        long long hours = 0;
        for(auto b:piles)
            hours += (b+speed-1)/speed;

        return hours<=h*1LL;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1 , e = *max_element(piles.begin() , piles.end());

        int speed = 0;
        while(s<=e){
            int mid = (e-s)/2 + s;

            if(possible(piles,h,mid)){
                speed = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return speed;
    }
};