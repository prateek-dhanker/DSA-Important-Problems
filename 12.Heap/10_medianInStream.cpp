#include <queue>
int signum(int a , int b){
	if( a == b)
		return 0;

	else if(a > b)
		return 1;
	return-1;
}
void solve(priority_queue<int , vector<int> , greater<int> > &minh , priority_queue<int> &maxh , vector<int> &ans , int &median , int elem){
	switch(signum(minh.size() ,  maxh.size())){
		case 0:
			if(elem > median){
				minh.push(elem);
				median = minh.top();
			}
			else{
				maxh.push(elem);
				median = maxh.top();
			}
			ans.push_back(median);
			break;

		case 1:
			if(elem > median){
				maxh.push(minh.top());
				minh.pop();
				minh.push(elem);
				median = (minh.top() + maxh.top())/2;
			}
			else{
				maxh.push(elem);
				median = (minh.top() + maxh.top())/2;
			}
			ans.push_back(median);
			break;

		case -1:
			if(elem > median){
				minh.push(elem);
			}
			else{
				minh.push(maxh.top());
				maxh.pop();
				maxh.push(elem);

			}
			median = (minh.top() + maxh.top())/2;
			ans.push_back(median);
			break;
	}
}
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	priority_queue<int , vector<int> , greater<int> > minh;
	priority_queue<int> maxh;

	int median = 0;
	vector<int> ans;

	for(int i=0;i<n ;i++){
		solve(minh , maxh , ans , median , arr[i]);
	}
	return ans;
}