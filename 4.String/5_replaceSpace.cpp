// Replace the space in string by @40. An inplace solution is required.
#include <iostream>
using namespace std;

void replaceSpace(string &name){
    int spaceCount = 0;
    for (char c : name) {
        if (c == ' ') {
            spaceCount++;
        }
    }
    int oldLen = name.length();
    int newLen = oldLen + 2*spaceCount;
    name.resize(newLen);

    for (int i = oldLen - 1, j = newLen - 1; i >= 0; --i) {
        if (name[i] == ' ') {
            name[j--] = '0';
            name[j--] = '4';
            name[j--] = '@';
        } else {
            name[j--] = name[i];
        }
    }
}

int main()
{
    string name;
    while(1){

    cout<<"Enter the input string : ";
    getline(cin,name);


    replaceSpace(name);
    cout<<"Result : "<<name<<endl;
    }

    return 0;
}