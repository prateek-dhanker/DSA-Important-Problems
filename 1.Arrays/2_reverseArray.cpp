#include <iostream>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0 ; i<size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void reverseArray(int arr[],int size)
{
    int start = 0 , end = size-1;

    while(start < end)
    {
        swap(arr[end],arr[start]);
        end--;
        start++;
    }
}

void reverseArrayAfterIndex(int arr[],int size,int m)
{
    int start = m+1 , end = size-1;

    while(start < end)
        swap(arr[end--],arr[start++]);
        
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
    reverseArrayAfterIndex(arr,size,1);
    printArray(arr,size);

    return 0;
}