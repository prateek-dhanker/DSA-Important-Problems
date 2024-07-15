// Find square root.

#include <iostream>
using namespace std;

int sqrtInteger(int n)
{
    int start = 0 , end = n;
    int ans = -1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        long long int square = mid*mid; 
        if(square == n)
            return mid;
        else if(square < n)
        {
            ans = mid;
            start = mid+1;
        }
        else
            end = mid-1;
    }
    return ans;
}

double morePrecision(int n,int precision,int tempSol)
{
    double ans = tempSol;
    double factor = 1;
    for(int i = 0;i<precision;i++)
    {
        factor /= 10;
        for(double j = ans ; j*j < n ; j += factor)
        {
            ans = j;
        } 
    }
    return ans;
}

int main()
{   
    int n;
    cout<<"Enter the no. ";
    cin>>n;
    cout<<"Square root of "<<n<<" = "<<morePrecision(n,5,sqrtInteger(n));

    return 0;
}