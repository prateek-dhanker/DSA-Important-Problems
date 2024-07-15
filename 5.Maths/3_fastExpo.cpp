#include <iostream>
using namespace std;
//x^n = (x^(n/2))^2   if n is even
//    = (x^(n/2))^2*x if n is odd
int fastExpo(int x , int n){

    if(n==0){
        return 1;
    }
    int temp = fastExpo(x,n/2);
    if(n&1)
        return temp * temp * x;

    else
        return temp*temp;
}

int main()
{
    int x,n;

    cout<<"Enter the no. : ";
    cin>>x;
    cout<<"Enter the exponent : ";
    cin>>n;
    cout<<x<<"^"<<n<<" = "<<fastExpo(x,n);


    return 0;
}