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

void printWave(vector<vector<int>> arr){
    int nrows = arr.size();
    int ncols = arr[0].size();

    cout<<"The elements in wave form :\n";
    for(int cols = 0 ; cols < ncols ; cols++){
        if(cols&1){
            //Odd col : traverse from bottom to top
            for(int rows = nrows-1 ; rows>=0 ; rows--)
                cout<<arr[rows][cols]<<" ";
        }
        else{
            //Even col : traverse from top to bottom
            for(int rows = 0 ; rows < nrows ; rows++){
                cout<<arr[rows][cols]<<" ";
            }
        }
    }
}

void printSpiral(vector<vector<int>>arr){
    int nrows = arr.size();
    int ncols = arr[0].size();

    int startRow = 0 , startCol = 0 , endRow = nrows-1 , endCol = ncols-1;
    int count = 0 , total = nrows*ncols;

    while(count<total){
        for(int i = startCol ; i<=endCol && count<total ;i++){
            cout<<arr[startRow][i]<<" ";
            count++;
        }
        startRow++;
        for(int i = startRow ; i<=endRow && count<total ;i++){
            cout<<arr[i][endCol]<<" ";
            count++;
        }
        endCol--;
        for(int i = endCol ; i>=startCol && count<total ;i--){
            cout<<arr[endRow][i]<<" ";
            count++;
        }
        endRow--;
        for(int i = endCol ; i>=startRow && count<total ;i--){
            cout<<arr[i][startCol]<<" ";
            count++;
        }
        startCol++;
    }
    
}
int main()
{
    vector<vector<int>>arr (4,vector<int>(4));
    cout<<"Enter the elements :";
    for(int i=0 ; i<4 ; i++){
        for(int j=0 ; j<4 ; j++){
            cin>>arr[i][j];
        }
    }
    printMatrixVector(arr,4,4);
    // printWave(arr);
    printSpiral(arr);

    return 0;
}