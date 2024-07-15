#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {1,2,3,4};
    a.push_back(2);
    for(auto i:a){
        cout<<i;
    }

    return 0;
}