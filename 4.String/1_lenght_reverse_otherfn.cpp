//Length of a string,reverse a string,toUpper,toLower

#include <iostream>
#include <string>
using namespace std;

int strlen(string name){
    int count; 
    for(count = 0; name[count]!='\0';count++);

    return count;
}
void reve(string &name){
    int n = name.length();
    int a = 0 , b = n-1;
    while(a<=b){
        swap(name[a++],name[b--]);
    }
}
char toupper(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 'A';
    }
    return ch;
}

char tolower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}
void toupperStr(string &name){
    for(int i = 0;i<name.length();i++){
        name[i] = toupper(name[i]);
    }
}
void tolowerStr(string &name){
    for(int i = 0;i<name.length();i++){
        name[i] = tolower(name[i]);
    }
}
int main()
{
    string name;
    cout<<"Enter your name: ";
    getline(cin,name);
    int len = strlen(name);
    cout<<"The length of this name is : "<<len<<endl;

    reve(name);
    cout<<"The reversed name is : "<<name<<endl;
    reve(name);

    tolowerStr(name);
    cout<<"The reversed name is : "<<name<<endl;
    toupperStr(name);
    cout<<"The reversed name is : "<<name<<endl;

    return 0;
}