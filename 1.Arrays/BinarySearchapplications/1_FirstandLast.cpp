//Find the first and last occerance of an element ina an sorted array.(return -1 if not found)
// eg- 1 2 3 3 3 4 5 
// first occerance--> 2 last occerance-->4

#include <iostream>
using namespace std;

int firstOccerance(int arr[],int size,int key)
{
    int low = 0 , high = size-1;
    int ans = -1 ;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == key)
        {
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid] > key)
            high = mid-1;
        else
            low = mid +1;
    }

    return ans;
}
int lastOccerance(int arr[],int size,int key)
{
    int low = 0 , high = size-1;
    int ans = -1 ;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == key)
        {
            ans = mid;
            low = mid+1;
        }
        else if(arr[mid] > key)
            high = mid-1;
        else
            low = mid +1;
    }

    return ans;
}

int main()
{
    int arr[] = {1,2,3,3,3,4,5};
    cout<<"First occerence of 3 is "<<firstOccerance(arr,7,3)<<endl;
    cout<<"Last occerence of 3 is "<<lastOccerance(arr,7,3)<<endl;
    // Note : Total no. of occerance = last - first + 1

    return 0;
}