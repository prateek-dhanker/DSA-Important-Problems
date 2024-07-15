/* Find the peak of mountain array. 
*/

#include <iostream>
using namespace std;

int peak(int arr[],int size)
{
    int start = 0 , end = size-1;
    while(start < end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid] < arr[mid+1])
            start = mid+1;
        else
        {
            end = mid;
        }
    }
    return arr[start];
}

int main()
{
    int arr[] = {3,4,5,6,1,-3};
    cout<<"Peak of the given array : "<<peak(arr,6);

    return 0;
}