#include <iostream>
using namespace std;

void reverseString(string &name , int a , int b){
    if(a>=b)
        return;
    swap(name[a],name[b]);
    
    return reverseString(name,a+1,b-1);
}

bool checkPalindrome(string name , int a ,int b){
    if(a>=b)
        return true;

    if(name[a] != name[b])
        return false;
    
    return checkPalindrome(name,a+1,b-1);
}

int main()
{
    string name = "abcdcba";
    reverseString(name,0,name.length()-1);
    cout<<name<<'\t'<<checkPalindrome(name,0,name.length()-1);

    return 0;
}