#include <iostream>
#include <vector>
using namespace std;

void printMatrix(int arr[][4] , int rows , int cols){
    cout<<"The elements :\n";
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
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
int maxRowSum(vector<vector<int>> arr){
    int nrows = arr.size();
    int ncols = arr[0].size();
    int maxSum = 0 , maxRow =0;
    for(int i=0;i<nrows;i++){
        int sum = 0;
        for(int j=0;j<ncols;j++){
            sum += arr[i][j];
        }
        if(sum>maxSum){
            maxSum = sum;
            maxRow = i;
        }
    }
    cout<<"Row "<<maxRow+1<<"has max sum"<<endl;
    return maxSum;
}

int main()
{
    // int arr[3][4];

    // printMatrix(arr,3,4);
    vector<vector<int>>arr (3,vector<int>(4));
    cout<<"Enter the elements :";
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<4 ; j++){
            cin>>arr[i][j];
        }
    }
    printMatrixVector(arr,3,4);

    int maxSum = maxRowSum(arr);
    cout<<"And the max row sum = "<<maxSum;

    return 0;
}