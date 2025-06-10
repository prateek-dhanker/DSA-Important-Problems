//  Eratosthenes
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;

        vector<bool> isPrime(n,true);
        isPrime[0] = isPrime[1] = false;

        for(int i=2;i*i<n;i++){
            if(isPrime[i]){
                for(long long j=i*i;j<n;j+=i)
                    isPrime[j] = false;
            }
        }

        return count(isPrime.begin(),isPrime.end(),true);
    }
};