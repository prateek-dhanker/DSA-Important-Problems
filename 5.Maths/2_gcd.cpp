#include <iostream>
using namespace std;
//gcd(a,b) = gcd(a-b,b) when a>b
//         = gcd(a,b-a) when b>a
int gcd(int a,int b){

    if(a==0 )
        return b;
    if(b==0)
        return a;
    if(a>=b)
        gcd(a-b,b);
    else 
        gcd(a,b-a);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int main()
{
    int a,b;
    while(1)
    {cout<<"Enter 2 no. : ";
    cin>>a>>b;
    int gc = gcd(a,b);
    cout<<"GCD of "<<a<<" & "<<b<<" = "<<gc<<endl;
    cout<<"LCM of "<<a<<" & "<<b<<" = "<<lcm(a,b)<<endl;
    }

    return 0;
}