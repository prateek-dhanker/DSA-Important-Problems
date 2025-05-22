#include <bits/stdc++.h> 
int ninjaGarden(vector<int> &flowers, int n, int k) 
{
	//write your code here
	vector<int> days(n);
	for(int i=0;i<n;i++)
		days[flowers[i]-1] = i+1;

	int res = INT_MAX;
	
	if(k==0){
		for(int i=1;i<n;i++){
			res = min(res,max(days[i],days[i-1]));
		}

		return res;
	}
	

	int left = 0, right = k+1;

	for(int i=1;right<n;i++){
		if(days[i]<days[left] || days[i]<days[right]){
			left = i;
			right = k+i+1;
		}
		else if(i == right-1){
			res = min(res, max(days[left],days[right]));
			left = i;
			right = k+i+1;
		}
	}

	if(res==INT_MAX)
		return -1;
	return res;
}
