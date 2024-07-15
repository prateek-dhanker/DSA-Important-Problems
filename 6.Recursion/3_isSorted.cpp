#include <iostream>
using namespace std;

bool isSorted(int *arr , int size){
    if(size<=1)
        return true;
    if(arr[0]>arr[1])
        return false;
    return isSorted(arr+1,size-1);
}

int main()
{
    int arr[] = {11,25,65,65,14};
    cout<<isSorted(arr,5)<<endl;
    int arr1[] = {11,25,65,65,114};
    cout<<isSorted(arr1,5)<<endl;
    int arr2[] = {11,25,65,65,141,54};
    cout<<isSorted(arr2,6)<<endl;
    return 0;
}