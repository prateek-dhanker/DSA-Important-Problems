#include <iostream>
#include <limits.h>
using namespace std;

int maximum(int arr[],int size)
{
    int maxi = INT_MIN;
    for(int i=0; i<size; i++)
    {
        maxi = max(maxi,arr[i]);
        // if(arr[i]>maxi)
        //     maxi = arr[i];
    }
    
    return maxi;

}
int minimum(int arr[],int size)
{
    int mini = INT_MAX;
    for(int i=0; i<size; i++)
    {
        mini = min(mini,arr[i]);
        // if(arr[i]<mini)
        //     mini = arr[i];
    }

    return mini;

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
    
    int max = maximum(arr,size);
    int min = minimum(arr,size);

    cout<<"Max element of the array : "<<max<<endl<<"Min element of the array : "<<min<<endl;

    return 0;
}