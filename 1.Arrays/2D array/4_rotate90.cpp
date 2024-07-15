//rotate a 2D array by 90 degrees clockwise
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

void reverseRow(vector<vector<int>>& matrix,int i,int ncols){
    int a = 0 , b = ncols-1;
    while(a<b)
        swap(matrix[i][a++],matrix[i][b--]);

}

void rotate(vector<vector<int>>& matrix) {
    int nrows = matrix.size();
    int ncols = matrix[0].size();
        
    for(int i=0 ; i<nrows ; i++){
        for(int j=i+1 ; j<ncols ; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //reverse rows
    for(int i=0 ; i<nrows ; i++){
        reverseRow(matrix,i,ncols);
    }

}

int main()
{
    

    return 0;
}