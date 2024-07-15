#include <iostream>
using namespace std;

char maxOccurChar(string name){
    // int *arr = new int[26];
    int arr[26] = {0},index;

    for(int i=0; i < name.length();i++){
        if(name[i]<='z' && name[i]>='a')
            index = name[i] - 'a';
        else
            index = name[i] - 'A';

        arr[index]++;
    }
    int maxi = -1 ,maxindex;
    for(int i=0;i<26;i++){
        if(arr[i] > maxi){
            maxi = arr[i];
            maxindex = i;
        }
    }
    return maxindex+'a';
}

int main()
{
    string name;
    while(1){

    cout<<"Enter the input string : ";
    getline(cin,name);

    cout<<"The max occuring char is "<<maxOccurChar(name)<<endl;
    }

    return 0;
}