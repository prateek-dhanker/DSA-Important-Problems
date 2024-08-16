class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n = grid.size() , m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }
        int maxTime = 0;
        vector<vector<int>> dir = {{-1,0} , {1,0} , {0,1}, {0,-1}};
        while(q.size()){
            int i=q.front().first.first , j=q.front().first.second , ctime = q.front().second;
            q.pop();
            maxTime = max(maxTime , ctime);
            for(auto d : dir){
                int x = i + d[0] , y=j+d[1];
                if(x>=0 && y>=0 && x<n && y<m && grid[x][y] == 1 ){
                    q.push({{x,y},ctime+1});
                    grid[x][y] = 2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 )
                    return -1;
            }
        }
        return maxTime;
    }
};