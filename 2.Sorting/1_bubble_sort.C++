#include <iostream>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0 ; i<size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void bubbleSort(int arr[],int n)
{
    for(int i=0 ; i < n-1 ; i++)
    {
        // cout<<"pass"<<endl;
        for(int j=1 ; j < n-1-i ; j++)
        {
            // cout<<"Compare"<<j<<"in"<<i<<endl;
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

int main()
{
    int arr[] = {1,22,34,14,5};
    bubbleSort(arr,5);
    printArray(arr,5);
    return 0;
}