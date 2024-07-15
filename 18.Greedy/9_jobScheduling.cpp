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