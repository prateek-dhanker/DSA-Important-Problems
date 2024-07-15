#include <iostream>
#include <vector>
using namespace std;

void printMatrixVector(vector<vector<int>> arr,  int rows , int cols){
    cout<<"The elements :\n";
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int nrows = matrix.size();
    int ncols = matrix[0].size();

    int a = 0, b = nrows*ncols-1;

    int mid = (a+b)/2;
    while(a<=b){
        int elem = matrix[mid/ncols][mid%ncols];
        if(elem == target)
            return 1;
        else if(elem > target)
            b = mid-1;
        else
            a = mid+1;

        mid = (a+b)/2;
    }
    return 0;
}


int main()
{
    vector<vector<int>>arr (3,vector<int>(4));//3*4 matrix
    cout<<"Enter the elements :";
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<4 ; j++){
            cin>>arr[i][j];
        }
    }
    printMatrixVector(arr,3,4);
    cout<<"Element found : "<<searchMatrix(arr,3);


    return 0;
}