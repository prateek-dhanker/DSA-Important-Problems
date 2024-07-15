#include <iostream>
using namespace std;

int binarySearch(int arr[],int size,int key)
{
    int low = 0 , high = size-1;

    while(low<=high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == key)
            return mid;
        
        else if(arr[mid] > key)
            high = mid-1;

        else 
            low = mid +1;
    }
    return -1;
}
int binary_search_recursive(int arr[],int size,int key,int low,int high)
{
    int mid = (low + high)/2;
    if(low < high)
    {
    if(arr[mid] == key)
        return mid;
    
    else if(arr[mid] > key)
        return binary_search_recursive(arr,size,key,low,mid-1);

    else
        return binary_search_recursive(arr,size,key,mid+1,high);
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

    if(!(binary_search_recursive(arr,size,key,0,size-1)+1))
        cout<<"Element absent"<<endl;
    else
    {
        cout<<"element is present at "<<binary_search_recursive(arr,size,key,0,size-1)<<endl; 
    }

    return 0;
}