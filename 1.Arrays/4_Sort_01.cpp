// An array contains only 0,1 sort them with complexity O(n)
// note: complexity for sort function = O(nlogn)


#include <iostream>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0 ; i<size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void sort01(int arr[],int size)
{
    int i = 0, j = size - 1;
    while (i <= j) {
        while (arr[i] == 0 && i <= j)
            i++;
        while (arr[j] == 1 && i <= j)
            j--;
        if (i <= j) {
            arr[i] = 0;
            arr[j] = 1;
            i++;
            j--;
        }
    }
}



int main()
{
    int arr[] = {1,0,1,0,0,1,0,0,1,1};
    printArray(arr,10);
    sort01(arr,10);
    printArray(arr,10);

    return 0;
}