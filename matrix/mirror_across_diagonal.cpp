#include<iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int A[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>A[i][j];
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            swap(A[i][j], A[j][i]);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout<<A[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
