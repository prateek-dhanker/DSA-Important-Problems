#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        string st = to_string(x);
        int b = st.length()-1 , a;
        if(st[0] == '-')
            a = 1;
        else
            a = 0;
        
        while(a<b)
            swap(st[a++] , st[b--]);
        
        try{
            x = stoi(st);
            return x;
        }
        catch(const out_of_range &oor){
            return 0;
        }
    }
};