#include <bits/stdc++.h>
using namespace std;


void bitManipulation(int num, int i) {
        // your code here
        i--; //1based indexing
        
        //Get ithBit
        int ithBit = num&(1<<i) ? 1 : 0;
        
        //Set ithBit
        int set = num|(1<<i);
        
        //Clear ithBit
        int clear = num&(~(1<<i));
        
        cout<<ithBit<<" "<<set<<" "<<clear;
}