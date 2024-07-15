#include <iostream>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0 ; i<size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void moveZero(int arr[],int n)
{
    int i=0;
    for(int j = 0 ; j < n ; j++)
    {
        if(!arr[j])
            swap(arr[i++],arr[j++]);
    }
}

int main()
{
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    
    int arr[20];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0 ; i<size ; i++)
    {
        cin>>arr[i];
    }
    moveZero(arr,size);
    printArray(arr,size);
    return 0;
}