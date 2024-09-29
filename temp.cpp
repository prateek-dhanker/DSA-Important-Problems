#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


map<int,int> fillMap(int n){
    map<int,int> m;
    while(n){
        m[n%10]++;
        n /= 10;
    }
    return m;
}
int solution(vector<int>& numbers) {
    int count = 0;
    int n = numbers.size();

    vector<map<int, int>> m(n);

    // Convert each number to string
    vector<string> num_strs;
    for (int i=0;i<n;i++) {
        m[i] = fillMap(numbers[i]);
    }
    
    // Check all pairs (i, j) where i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (m[i] == m[j]) {
                ++count;
            }
        }
    }
    
    return count;
}

int main() {
    vector<int> numbers = {1,23,156,1650,651,165,32};
    cout<<"Result: " << solution(numbers) << endl;  // Output: 3
    return 0;
}

// ios_base::sync_with_stdio(0);
// cin.tie(0);
// cout.tie(0);

//Cyclic Increase
// i = (i+1)%n;
//Cyclic Decrease
// i = (i+n-1)%n;
//Ceil Divide
// div = (a+b-1)/b;