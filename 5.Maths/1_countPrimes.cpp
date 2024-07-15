//Seive of Eratosthenes
//Count no of prime no.s less than equal to n
#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    vector<int>prime(n,1);
    int count = 0;

    if(n<=1)
        return 0;

    for(int i=2 ; i<n ; i++){
        if(prime[i]){
            count++;
            for(int j=2*i ; j<n ; j += i)
                prime[j] = 0;
        }
    }
    return count;
}

int main()
{
    

    return 0;
}