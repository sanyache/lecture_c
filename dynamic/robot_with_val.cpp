#include<iostream>

using namespace std;

int main(){
    int const n = 5;
    int A[][n] = {{3,7,9,2,7},
                 {9,8,3,5,5},
                 {1,7,9,8,5},
                 {3,8,6,4,10},
                 {6,3,9,7,8}};
    int val[n][n];
    val[0][0] = A[0][0];
    for(int i=1; i<n; i++){
        val[i][0] = val[i-1][0] + A[i][0];
        val[0][i] = val[0][i-1] + A[0][i];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            val[i][j] = max(val[i-1][j], val[i][j-1]) + A[i][j];
        }
    }
    cout<<val[n-1][n-1]<<'\n';             
    return 0;
}