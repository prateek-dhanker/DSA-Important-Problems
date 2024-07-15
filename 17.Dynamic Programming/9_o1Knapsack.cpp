int solve(vector<int> &values, vector<int> &weights, int n, int capacity , int index){
	if(index == 0){
		if(weights[0] <= capacity)
			return values[0];
		else
			return 0;
	}

	int include = 0;
	if(weights[index] <= capacity)
		include = values[index] + solve(values , weights , n , capacity-weights[index] , index-1);

	int exclude = solve(values , weights , n , capacity , index-1);

	return max(include , exclude);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	return solve(values , weights , n,w , n-1);

}




int solvemem(vector<int> &values, vector<int> &weights, int n, int capacity , int index , vector<vector<int> > &dp){
	if(index == 0){
		if(weights[0] <= capacity)
			return values[0];
		else
			return 0;
	}

	if(dp[index][capacity] != -1)
		return dp[index][capacity];

	int include = 0;
	if(weights[index] <= capacity)
		include = values[index] + solvemem(values , weights , n , capacity-weights[index] , index-1 , dp);

	int exclude = solvemem(values , weights , n , capacity , index-1 , dp);

	return dp[index][capacity] =  max(include , exclude);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector< vector<int> > dp(n,vector<int>(w+1,-1));
	return solvemem(values , weights , n,w , n-1 , dp);

}




int maxProfit(vector<int> &values, vector<int> &weights, int n, int capacity)
{
	// Write your code here
	vector< vector<int> > dp(n,vector<int>(capacity+1,0));
	
	for(int i=weights[0] ; i<=capacity;i++){
		dp[0][i] = values[0];
	}

	for(int index = 1 ;index<n;index++){
		for(int w = 0; w<= capacity;w++){
			int include = 0;
			if(weights[index] <= w)
				include = values[index] + dp[index-1][w-weights[index]];

			int exclude = dp[index-1][w];

			dp[index][w] = max(include , exclude);
		}
	}
		return dp[n-1][capacity];
}



int maxProfit(vector<int> &values, vector<int> &weights, int n, int capacity)
{
	// Write your code here
	vector<int> prev(capacity+1);
	vector<int> curr(capacity+1);
	
	for(int i=weights[0] ; i<=capacity;i++){
		prev[i] = values[0];
	}

	for(int index = 1 ;index<n;index++){
		for(int w = 0; w<= capacity;w++){
			int include = 0;
			if(weights[index] <= w)
				include = values[index] + prev[w-weights[index]];

			int exclude = prev[w];

			curr[w] = max(include , exclude);
		}
		prev = curr;
	}
		return prev[capacity];
}


int maxProfit(vector<int> &values, vector<int> &weights, int n, int capacity)
{
	vector<int> curr(capacity+1);
	
	for(int i=weights[0] ; i<=capacity;i++){
		curr[i] = values[0];
	}

	for(int index = 1 ;index<n;index++){
		for(int w = capacity; w>=0;w--){
			int include = 0;
			if(weights[index] <= w)
				include = values[index] + curr[w-weights[index]];

			int exclude = curr[w];

			curr[w] = max(include , exclude);
		}
	}
		return curr[capacity];
}