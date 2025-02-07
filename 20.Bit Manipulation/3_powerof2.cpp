#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;

        int res = n&(n-1);
        return (res == 0);
    }
};