#include <iostream>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0 ; i<size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void selectionSort(int arr[] , int n)
{
    for(int i=0 ; i < n-1 ; i++)
    {
        int minIndex = i;
        for(int j=i+1 ; j < n ; j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        if(minIndex > i)
            swap(arr[i],arr[minIndex]);
    }
}

int main()
{
    int arr[] = {1,22,34,14,5};
    selectionSort(arr,5);
    printArray(arr,5);
    return 0;
}