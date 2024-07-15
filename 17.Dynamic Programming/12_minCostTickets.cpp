class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs , int index){
        if(index >= days.size())
            return 0;
        
        int op1 = costs[0] + solve(days , costs , index+1);

        int i;
        for(i=index ; i<days.size() && days[index] + 7 > days[i]; i++);
        int op2 = costs[1] + solve(days , costs , i);
       
        int j;
        for(j=index ; j<days.size() && days[index] + 7 > days[j]; j++);
        int op3 = costs[2] + solve(days , costs , j);

        return min(op1 , min(op2 , op3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solve(days , costs , 0);
    }
};


class Solution {
public:
    int solveMem(vector<int>& days, vector<int>& costs , int index, vector<int> &dp){
        if(index >= days.size())
            return 0;

        if(dp[index] != -1)
            return dp[index];
        
        int op1 = costs[0] + solveMem(days , costs , index+1, dp);

        int i;
        for(i=index ; i<days.size() && days[index] + 7 > days[i]; i++);
        int op2 = costs[1] + solveMem(days , costs , i , dp);
       
        int j;
        for(j=index ; j<days.size() && days[index] + 7 > days[j]; j++);
        int op3 = costs[2] + solveMem(days , costs , j , dp);

        return dp[index] = min(op1 , min(op2 , op3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1 , -1);
        return solveMem(days , costs , 0 , dp);
    }
};


int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1 , INT_MAX);
        dp[n] = 0;

        for(int k=n-1 ; k>=0 ; k--){
            int op1 = costs[0] + dp[k+1];

            int i;
            for(i=k ; i<days.size() && days[k] + 7 > days[i]; i++);
            int op2 = costs[1] + dp[i];

            for(i=k ; i<days.size() && days[k] + 30 > days[i]; i++);
            int op3 = costs[2] + dp[i];

            dp[k] = min(op1 , min(op2 , op3));

        }
        return dp[0];
    }


    class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        queue<pair<int , int> > weekly , monthly;

        int ans = 0;
        for(auto day : days){
            //remove expired days
            while(weekly.size() && weekly.front().first+7 <= day)
                weekly.pop();
            while(monthly.size() && monthly.front().first+30 <= day)
                monthly.pop();

            //push current day in queue
            weekly.push({day , ans + costs[1]});
            monthly.push({day , ans + costs[2]});

            ans = min(ans+costs[0] , min(weekly.front().second , monthly.front().second));

        }
        return ans;
    }
};