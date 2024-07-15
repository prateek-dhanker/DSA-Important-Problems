#include <iostream>
using namespace std;

bool palindrome(string name){
    int n= name.length();
    int a = 0 ,b = n-1;
    while(a<b){
        if(name[a]!=name[b])
            return 0;
        else{
            a++;b--;
        }
    }
    return 1;

}

int main()
{
    string name;
    cout<<"Enter the input string : ";
    getline(cin,name);

    cout<<"Is palindrome :"<<palindrome(name)<<endl;

    return 0;
}