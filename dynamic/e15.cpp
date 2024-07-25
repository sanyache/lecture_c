#include<iostream>

using namespace std;

int main(){
    int n,m;
    string path;
    cin>>m>>n;
    int A[m][n], val[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>A[i][j];
        }
    }
    val[m-1][0] = A[m-1][0];
    for(int i=m-2; i>=0; i--){
        val[i][0] = val[i+1][0] + A[i][0];
    }
    for(int j=1; j<n; j++){
        val[m-1][j] = val[m-1][j-1] + A[m-1][j];
    }
    for(int i=m-2; i>=0; i--){
        for(int j=1; j<n; j++){
            val[i][j] = max(val[i+1][j], val[i][j-1]) + A[i][j];
        }
    }
    int row = 0;
    int column = n-1;
    while(row != m-1 and column != 0){
        if(val[row][column-1] > val[row+1][column]){
            path = "R" + path;
            column--;
        } else {
            path = "F" + path;
            row++;
        }
    }
    if(row == m-1){
        for(int j=column-1; j>=0; j--) path = "R" + path;
    }
    if (column == 0) {
        for(int i=row+1; i<m; i++) path = "F" + path;
    }
    cout<<path;
    return 0;
}