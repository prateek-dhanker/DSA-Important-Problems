#include <bits/stdc++.h> 
using namespace std;
int firstCircularTour(vector<int>& petrol, vector<int>& distance, int N)
{
	// write your code here
	long int balance = 0;
	long int deficit = 0;
	int start = 0;
	for(int i=0 ; i<N ;i++){
		balance += petrol[i] - distance[i];

		if(balance < 0){
			start = i+1;
			deficit += balance;
			balance = 0;
		}
	}

	if(balance + deficit >=0)
		return start;
	return -1;
	
}