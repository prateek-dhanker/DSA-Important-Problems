#include <iostream>
using namespace std;

int linearSearch(int arr[],int size,int key)
{
    for(int i=0 ; i<size ; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
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

    int key;
    cout<<"Enter the element to search : ";
    cin>>key;
    if(!(linearSearch(arr,size,key)+1))
        cout<<"Element absent"<<endl;
    else
    {
        cout<<"element is present at "<<linearSearch(arr,size,key)<<endl; 
    }

    return 0;
}