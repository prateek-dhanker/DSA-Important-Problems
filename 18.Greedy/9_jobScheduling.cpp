class Solution 
{
    public:
    static bool cmp(Job &a , Job& b){
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr , arr+n, cmp);
        
        int jobDone=0 , maxProfit = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi , arr[i].dead);
        }
        vector<bool> schedule(maxi+1 , false);
        
        for(int i=0;i<n;i++){
            for(int k=arr[i].dead ; k>0;k--){
                if(schedule[k] == false){
                    jobDone++;
                    maxProfit += arr[i].profit;
                    schedule[k] = true;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(jobDone);
        ans.push_back(maxProfit);
        
        return ans;
    } 
};



class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job &a , Job &b){
        return a.dead<b.dead;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr , arr+n , cmp);
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        int cnt = 0 , prof = 0 , curr = 1;
        for(int i=0;i<n;i++){
            if(arr[i].dead >= curr){
                pq.push(arr[i].profit);
                prof += arr[i].profit;
                cnt++;
                curr++;
            }
            else if(arr[i].profit > pq.top()){
                prof += arr[i].profit - pq.top();
                pq.push(arr[i].profit);
                pq.pop();
            }
        }
        return {cnt , prof};
    } 
};