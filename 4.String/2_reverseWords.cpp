#include <iostream>
using namespace std;

void reve(string &name,int a,int b){
    while(a<=b){
        swap(name[a++],name[b--]);
    }
}

void reverseWords(string &name){
    int prev = 0;
    for(int i = 0; i <= name.length();i++){
        if(name[i] == ' ' || name[i] == '\0'){
            reve(name ,prev, i-1);
            prev = i+1;
        }
    }
}

int main()
{
    string name;
    cout<<"Enter the input string : ";
    getline(cin,name);

    reverseWords(name);
    cout<<name;

    return 0;
}