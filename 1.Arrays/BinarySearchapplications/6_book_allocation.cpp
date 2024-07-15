/* Book allocation problem (Problem is similar to Painters Partion Problem and Aggressive Cow problem)
    (there is ss for aggressive cow problem)

    Given an array of integer no.,where arr[i] represent the no. of pages in i-th book.
    There are m no. of students & the task is to allocate all books to the student.
    Allocate books in such a way that :
    1.Each student get atleast one book.
    2.Each book must be allocated to a student.
    3.Book allocation must be in a contiguous manner.
    Allocation is to be done such that max no. of pages assigned to a student is min.
    Return this max no. of pages.
*/

#include <iostream>
using namespace std;

bool possibleSol(int arr[],int n,int m,int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n ;i++)
    {
        if(pageSum + arr[i] <= mid)
            pageSum += arr[i];
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid)
                return false;

            pageSum = arr[i];
        }
    }
    return true;
}

int bookAllocation(int arr[],int n,int m)//m is no. of students and n is no. of books
{
    int sum = 0;
    for(int i=0 ; i<n ; i++)
        sum += arr[i];
    int start = 0 , end = sum;
    int ans = -1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(possibleSol(arr,n,m,mid))
        {
            ans = mid;
            end = mid-1;
        }
        else
            start = mid+1;
    }
    return ans;
}
int main()
{
    int arr[] = {10,20,30,40};   
    cout<<"Max no. of pages for a student "<<bookAllocation(arr,4,2);

    return 0;
}
// follow same approach for both painter's partition problem and aggressive cow problem
// there is a ss for aggressive cow problem