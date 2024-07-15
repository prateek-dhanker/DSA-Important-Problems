/* Find pivot in a ratoated sorted array.

Rotated Array:
 1 2 3 4 5  --->   4 5 1 2 3
Pivot :
 least element (in most cases)
*/

#include <iostream>
using namespace std;

int getPivot(int arr[],int size)
{
    int start = 0 , end = size-1;

    while(start < end)
    {
        int mid  = start + (end - start)/2;
        if(arr[mid] >= arr[0])
            start = mid+1;
        else
            end = mid;
    }
    return start;//or return end;
}

int main()
{
    int arr[] = {7,9,10,2,3};
    cout<<"Pivot is index no. "<<getPivot(arr,5);

    return 0;
}