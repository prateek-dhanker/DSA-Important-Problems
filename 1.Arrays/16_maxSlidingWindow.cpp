class cmp{
        public:
            bool operator()(pair<int,int> &a , pair<int,int> &b){
                return a.first < b.first;
            }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;

        vector<int> ans;

        priority_queue<pair<int,int> , vector<pair<int,int>>, cmp> pq;
        
        for(int i=0;i<k-1;i++)
            pq.push({nums[i],i});
        
        for(int i=k-1;i<nums.size();i++){
            pq.push({nums[i],i});

            while(pq.top().second < i-k+1)
                pq.pop();
            
            ans.push_back(pq.top().first);
        }
        return ans;
    }


    // O(nlog(k))

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            while(dq.size() && dq.front() <= i-k)
                dq.pop_front();
            while(dq.size() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }