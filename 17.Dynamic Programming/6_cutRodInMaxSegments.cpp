#include<limits.h>
int solverec(int n , int x , int y , int z){
	if(n==0)
		return 0;
	if(n<0)
		return INT_MIN;

	int ansx = solverec(n-x , x , y , z)+1;
	int ansy = solverec(n-y , x , y , z)+1;
	int ansz = solverec(n-z , x , y , z)+1;

	return max(ansx , max(ansy , ansz));

}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.

	int ans = solverec(n , x, y , z);

	if(ans < 0)
		return 0;
	return ans;
}


int solvemem(int n , int x , int y , int z , vector<int> &dp){
	if(n==0)
		return 0;
	if(n<0)
		return INT_MIN;

	if(dp[n]!=-1)
		return dp[n];

	int ansx = solvemem(n-x , x , y , z , dp)+1;
	int ansy = solvemem(n-y , x , y , z , dp)+1;
	int ansz = solvemem(n-z , x , y , z , dp)+1;

	return dp[n] =  max(ansx , max(ansy , ansz));

}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.

	vector<int> dp(n+1 , -1);
	int ans = solvemem(n , x, y , z , dp);


	if(ans < 0)
		return 0;
	return ans;
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.

	vector<int> dp(n+1 , -1);

	dp[0] = 0;

	for(int i=1;i<=n;i++){
		if(i-x >=0 && dp[i-x]!=-1)
			dp[i] = max(dp[i] , dp[i-x]+1);
		if(i-y >=0 && dp[i-y]!=-1)
			dp[i] = max(dp[i] , dp[i-y]+1);
		if(i-z >=0 && dp[i-z]!=-1)
			dp[i] = max(dp[i] , dp[i-z]+1);
	}


	if(dp[n] < 0)
		return 0;
	return dp[n];
}