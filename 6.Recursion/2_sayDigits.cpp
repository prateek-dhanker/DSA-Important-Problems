#include <iostream>
using namespace std;

string arr[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void sayDigits(int n){
    if(n==0){
        return;
    }
    sayDigits(n/10);
    cout<<arr[n%10]<<' ';
}

int main()
{
    sayDigits(1001);

    return 0;
}